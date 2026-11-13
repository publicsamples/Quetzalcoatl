#!/usr/bin/env python3
import os
from pathlib import Path
import shutil
import subprocess
import tempfile

with tempfile.TemporaryDirectory() as tmp:
    root = Path(tmp)
    package, home, config = root / 'package', root / 'home', root / 'config'
    (package / 'content/User Presets').mkdir(parents=True)
    home.mkdir()
    shutil.copy2('installers/linux/install.py', package / 'install.py')
    (package / 'Quetzalcoatl.vst3').write_text('plugin')
    destination = config / 'modularsamples/Quetzalcoatl'
    (destination / 'User Presets').mkdir(parents=True)
    for name in ['newer', 'equal', 'GeneralSettings.xml', 'User Presets/db.json']:
        (package / 'content' / name).write_text('factory')
        (destination / name).write_text('existing')
    for path in [destination / 'newer', destination / 'equal', package / 'content/equal']:
        os.utime(path, (1000000000, 1000000000))
    os.utime(package / 'content/newer', (1100000000, 1100000000))
    subprocess.run(['python3', str(package / 'install.py')], check=True,
                   env={**os.environ, 'HOME': str(home), 'XDG_CONFIG_HOME': str(config)})
    assert (destination / 'newer').read_text() == 'factory'
    for name in ['equal', 'GeneralSettings.xml', 'User Presets/db.json']:
        assert (destination / name).read_text() == 'existing'
    assert (home / '.vst3/Quetzalcoatl.vst3').read_text() == 'plugin'
print('Linux install checks passed')
