#!/usr/bin/env python3
"""Install Quetzalcoatl and its content for the current Linux user."""
from pathlib import Path
import shutil


def juce_user_dir(name, fallback):
    # Match this HISE build's JUCE Linux special-location lookup.
    settings = Path.home() / '.config/user-dirs.dirs'
    if settings.is_file():
        for line in settings.read_text(encoding='utf-8').splitlines():
            line = line.lstrip()
            if line.startswith(name) and '=' in line:
                value = line.split('=', 1)[1].strip().strip('"').replace('$HOME', str(Path.home()))
                candidate = Path(value)
                if candidate.is_absolute() and candidate.is_dir():
                    return candidate
    return Path.home() / fallback


def merge(source, target, preserve_settings=False):
    for item in source.rglob('*'):
        if not item.is_file():
            continue
        relative = item.relative_to(source)
        dest = target / relative
        if dest.exists():
            if not dest.is_file():
                raise SystemExit(f'Cannot replace non-file: {dest}')
            if preserve_settings and relative.as_posix() in ('GeneralSettings.xml', 'User Presets/db.json'):
                continue
            if item.stat().st_mtime_ns <= dest.stat().st_mtime_ns:
                continue
        dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(item, dest)


root = Path(__file__).resolve().parent
source = root / 'content'
samples = root / 'samples'
plugin = root / 'Quetzalcoatl.vst3'
target = juce_user_dir('XDG_CONFIG_HOME', '.config') / 'modularsamples' / 'Quetzalcoatl'
sample_dir = juce_user_dir('XDG_MUSIC_DIR', 'Music') / 'modularsamples' / 'Quetzalcoatl' / 'Samples'
if not source.is_dir() or not samples.is_dir() or not any(samples.rglob('*.ch1')) or not plugin.exists():
    raise SystemExit('Plugin, content or sample files missing from this archive.')
merge(source, target, preserve_settings=True)
merge(samples, sample_dir)
target.mkdir(parents=True, exist_ok=True)
(target / 'LinkLinux').write_text(str(sample_dir), encoding='utf-8')
vst3 = Path.home() / '.vst3'
vst3.mkdir(parents=True, exist_ok=True)
dest = vst3 / plugin.name
if plugin.is_dir():
    shutil.copytree(plugin, dest, dirs_exist_ok=True)
else:
    shutil.copy2(plugin, dest)
print(f'Installed plugin to {dest}, content to {target}, and samples to {sample_dir}')
