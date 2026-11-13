#!/usr/bin/env python3
"""Verify and stage the release's sample library without macOS metadata."""
import argparse
import hashlib
import os
from pathlib import Path, PurePosixPath
import shutil
from zipfile import ZipFile
from stage_content import timestamp

SAMPLES_SHA256 = '84ec2a7db78e30d0eac84dbf2488b8586d62b7380b6b051ecbec46ac5e040afc'


def stage(archive, destination):
    digest = hashlib.sha256()
    with archive.open('rb') as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b''):
            digest.update(chunk)
    if digest.hexdigest() != SAMPLES_SHA256:
        raise ValueError('Sample archive SHA-256 does not match the pinned release')
    if destination.exists() and any(destination.iterdir()):
        raise ValueError(f'Staging directory must be empty: {destination}')
    with ZipFile(archive) as z:
        entries = []
        seen = set()
        for info in z.infolist():
            if info.is_dir():
                continue
            name = info.filename
            parts = PurePosixPath(name).parts
            if name.startswith(('/', '\\')) or '\\' in name or '..' in parts:
                raise ValueError(f'Unsafe archive path: {name}')
            if parts and parts[0] == '__MACOSX':
                continue
            if len(parts) < 2 or parts[0] != 'Samples' or PurePosixPath(name).suffix.lower() != '.ch1':
                raise ValueError(f'Unexpected sample archive file: {name}')
            if (info.external_attr >> 16) & 0o170000 == 0o120000:
                raise ValueError(f'Symbolic link in sample archive: {name}')
            relative = PurePosixPath(*parts[1:])
            if str(relative).casefold() in seen:
                raise ValueError(f'Conflicting sample paths: {relative}')
            seen.add(str(relative).casefold())
            entries.append((info, relative, timestamp(info)))
        if not entries:
            raise ValueError('Sample archive has no .ch1 files')
        destination.mkdir(parents=True, exist_ok=True)
        for info, relative, mtime in entries:
            target = destination.joinpath(*relative.parts)
            target.parent.mkdir(parents=True, exist_ok=True)
            with z.open(info) as source, target.open('xb') as output:
                shutil.copyfileobj(source, output, 1024 * 1024)
            os.utime(target, (mtime, mtime))
    print(f'Verified and staged {len(entries)} sample files in {destination}')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('archive', type=Path)
    parser.add_argument('destination', type=Path)
    args = parser.parse_args()
    stage(args.archive, args.destination)
