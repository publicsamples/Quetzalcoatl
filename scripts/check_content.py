#!/usr/bin/env python3
"""Verify the pinned release content archive before using it in CI."""
import hashlib
import sys
from pathlib import Path, PurePosixPath
from zipfile import BadZipFile, ZipFile

EXPECTED_SHA256 = "8c3ff6b981f8a481702ae3af175cb6c4520688dbbfd412e87364febe19ab8743"


def check(path):
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(chunk)
    if digest.hexdigest() != EXPECTED_SHA256:
        raise ValueError("Content archive SHA-256 does not match the pinned release asset")
    with ZipFile(path) as archive:
        files = [item for item in archive.infolist() if not item.is_dir()]
        if not files:
            raise ValueError("Content archive is empty")
        for item in files:
            name = item.filename
            parts = PurePosixPath(name).parts
            if name.startswith(("/", "\\")) or "\\" in name or ".." in parts:
                raise ValueError(f"Unsafe archive path: {name}")
            if (item.external_attr >> 16) & 0o170000 == 0o120000:
                raise ValueError(f"Archive contains a symbolic link: {name}")
        if not any(PurePosixPath(item.filename).name == "AudioResources.dat" for item in files):
            raise ValueError("AudioResources.dat was not found in the archive")
        print(f"Verified SHA-256 and inspected {len(files)} files in {path}")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        sys.exit("Usage: python3 scripts/check_content.py PATH_TO_ZIP")
    try:
        check(Path(sys.argv[1]))
    except (OSError, ValueError, BadZipFile) as exc:
        sys.exit(str(exc))
