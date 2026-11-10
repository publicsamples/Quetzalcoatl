#!/usr/bin/env python3
"""Stage the verified release archive for platform-specific installers."""
import argparse
import os
from pathlib import Path, PurePosixPath
import shutil
import struct
from zipfile import ZipFile

from check_content import check


def timestamp(item):
    # ZIP DOS dates have no timezone. The release archive also provides Info-ZIP
    # extended UTC modification times; require those for reliable comparisons.
    extra = item.extra
    while len(extra) >= 4:
        field, size = struct.unpack_from('<HH', extra)
        data, extra = extra[4:4 + size], extra[4 + size:]
        if len(data) != size:
            raise ValueError(f'Malformed ZIP metadata: {item.filename}')
        if field == 0x5455 and len(data) >= 5 and data[0] & 1:
            return struct.unpack_from('<I', data, 1)[0]
    raise ValueError(f'No UTC modification time in ZIP metadata: {item.filename}')


def stage(archive_path, destination):
    check(archive_path)
    if destination.exists() and any(destination.iterdir()):
        raise ValueError(f'Staging directory must be empty: {destination}')
    destination.mkdir(parents=True, exist_ok=True)
    with ZipFile(archive_path) as archive:
        entries = []
        seen = set()
        for item in archive.infolist():
            if item.is_dir():
                continue
            parts = PurePosixPath(item.filename).parts
            if parts[0] == '__MACOSX':
                continue
            if parts[0] != 'Quetzalcoatl' or len(parts) < 2:
                raise ValueError(f'Unexpected content path: {item.filename}')
            relative = PurePosixPath(*parts[1:])
            if any(p == '.DS_Store' or p.startswith('._') for p in relative.parts):
                continue
            key = str(relative).casefold()
            if key in seen:
                raise ValueError(f'Content paths conflict on Windows: {relative}')
            seen.add(key)
            entries.append((item, relative, timestamp(item)))
        for item, relative, mtime in entries:
            output = destination.joinpath(*relative.parts)
            output.parent.mkdir(parents=True, exist_ok=True)
            with archive.open(item) as source, output.open('xb') as target:
                shutil.copyfileobj(source, target, 1024 * 1024)
            os.utime(output, (mtime, mtime))
    print(f'Staged {len(entries)} files in {destination}')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('archive', type=Path)
    parser.add_argument('destination', type=Path)
    args = parser.parse_args()
    stage(args.archive, args.destination)
