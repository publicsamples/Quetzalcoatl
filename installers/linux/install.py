#!/usr/bin/env python3
"""Install Quetzalcoatl and merge its content for the current Linux user."""
import os
from pathlib import Path
import shutil

root = Path(__file__).resolve().parent
source = root / 'content'
plugin = root / 'Quetzalcoatl.vst3'
config = Path(os.environ.get('XDG_CONFIG_HOME') or Path.home() / '.config')
if not config.is_absolute():
    config = Path.home() / '.config'
target = config / 'modularsamples' / 'Quetzalcoatl'
if not source.is_dir() or not plugin.exists():
    raise SystemExit('Plugin or content folder missing from this archive.')
for item in source.rglob('*'):
    if not item.is_file():
        continue
    relative = item.relative_to(source)
    dest = target / relative
    if dest.exists():
        if not dest.is_file():
            raise SystemExit(f'Cannot replace non-file: {dest}')
        if relative.as_posix() in ('GeneralSettings.xml', 'User Presets/db.json'):
            continue
        if item.stat().st_mtime_ns <= dest.stat().st_mtime_ns:
            continue
    dest.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(item, dest)
vst3 = Path.home() / '.vst3'
vst3.mkdir(parents=True, exist_ok=True)
dest = vst3 / plugin.name
if plugin.is_dir():
    shutil.copytree(plugin, dest, dirs_exist_ok=True)
else:
    shutil.copy2(plugin, dest)
print(f'Installed plugin to {dest} and content to {target}')
