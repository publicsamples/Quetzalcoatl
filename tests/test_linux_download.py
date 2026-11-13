#!/usr/bin/env python3
"""Exercise the optional download path without making a network request."""
import hashlib
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import tempfile
from zipfile import ZipFile, ZipInfo

with tempfile.TemporaryDirectory() as d:
    root = Path(d)
    package = root / 'package'
    home = root / 'home'
    (package / 'content').mkdir(parents=True)
    home.mkdir()
    for file in ('stage_samples.py', 'stage_content.py', 'check_content.py'):
        shutil.copy2(Path('scripts') / file, package / file)
    shutil.copy2('installers/linux/install.py', package / 'install.py')
    (package / 'content/AudioResources.dat').write_text('audio')
    (package / 'Quetzalcoatl.vst3').write_text('plugin')
    archive = root / 'samples.zip'
    info = ZipInfo('Samples/test.ch1')
    info.extra = struct.pack('<HHBI', 0x5455, 5, 1, 1577836800)
    with ZipFile(archive, 'w') as z:
        z.writestr(info, b'sample')
    digest = hashlib.sha256(archive.read_bytes()).hexdigest()
    code = '''import runpy, sys, urllib.request
from unittest.mock import patch
import stage_samples
stage_samples.SAMPLES_SHA256 = sys.argv[3]
script, archive = sys.argv[1:3]
sys.argv = [script]
with patch.object(urllib.request, 'urlopen', side_effect=lambda *a, **k: open(archive, 'rb')):
    runpy.run_path(script, run_name='__main__')
'''
    env = {**os.environ, 'HOME': str(home), 'PYTHONPATH': str(package)}
    subprocess.run([sys.executable, '-c', code, str(package / 'install.py'), str(archive), digest], env=env, check=True)
    sample_dir = home / 'Music/modularsamples/Quetzalcoatl/Samples'
    assert (sample_dir / 'test.ch1').read_bytes() == b'sample'
    assert (sample_dir / 'test.ch1').stat().st_mtime == 1577836800
    assert (home / '.config/modularsamples/Quetzalcoatl/LinkLinux').read_text() == str(sample_dir)
print('Linux optional sample download verified')
