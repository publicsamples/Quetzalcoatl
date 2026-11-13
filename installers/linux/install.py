#!/usr/bin/env python3
"""Install Quetzalcoatl and its content for the current Linux user."""
import argparse
from pathlib import Path
import shutil
import tempfile
import urllib.request


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


def install_samples(samples, target, sample_dir):
    if not samples.is_dir() or not any(samples.rglob('*.ch1')):
        raise SystemExit('The sample library does not contain any .ch1 files.')
    merge(samples, sample_dir)
    target.mkdir(parents=True, exist_ok=True)
    (target / 'LinkLinux').write_text(str(sample_dir), encoding='utf-8')
    print(f'Installed samples to {sample_dir}')


parser = argparse.ArgumentParser(description=__doc__)
choice = parser.add_mutually_exclusive_group()
choice.add_argument('--samples', action='store_true', help='download and install the factory sample library (the default; about 720 MB)')
choice.add_argument('--no-samples', action='store_true', help='skip the sample download and preserve any existing sample link')
choice.add_argument('--samples-from', type=Path, metavar='DIR', help='install sample files from an existing extracted directory')
args = parser.parse_args()
root = Path(__file__).resolve().parent
source = root / 'content'
plugin = root / 'Quetzalcoatl.vst3'
target = juce_user_dir('XDG_CONFIG_HOME', '.config') / 'modularsamples' / 'Quetzalcoatl'
sample_dir = juce_user_dir('XDG_MUSIC_DIR', 'Music') / 'modularsamples' / 'Quetzalcoatl' / 'Samples'
if not source.is_dir() or not plugin.exists():
    raise SystemExit('Plugin or content folder missing from this archive.')
merge(source, target, preserve_settings=True)
vst3 = Path.home() / '.vst3'
vst3.mkdir(parents=True, exist_ok=True)
dest = vst3 / plugin.name
if plugin.is_dir():
    shutil.copytree(plugin, dest, dirs_exist_ok=True)
else:
    shutil.copy2(plugin, dest)
print(f'Installed plugin to {dest} and content to {target}')
if args.samples_from:
    install_samples(args.samples_from, target, sample_dir)
elif not args.no_samples:
    from stage_samples import stage
    url = 'https://github.com/publicsamples/Quetzalcoatl/releases/download/1.0.0/Samples.zip'
    with tempfile.TemporaryDirectory(prefix='quetzalcoatl-samples-') as d:
        archive = Path(d) / 'Samples.zip'
        print('Downloading optional sample library (about 720 MB)...', flush=True)
        with urllib.request.urlopen(url, timeout=60) as response, archive.open('wb') as output:
            shutil.copyfileobj(response, output, 1024 * 1024)
        staged = Path(d) / 'samples'
        stage(archive, staged)
        install_samples(staged, target, sample_dir)
