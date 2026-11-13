#!/usr/bin/env python3
"""Verify Windows sample timestamps against the pinned release archive."""
import hashlib
import json
from pathlib import Path
import sys
from zipfile import ZipFile

from stage_content import timestamp
from stage_samples import SAMPLES_SHA256

if len(sys.argv) != 3:
    sys.exit('Usage: verify_samples_manifest.py SAMPLES.zip MANIFEST.json')
archive, manifest = map(Path, sys.argv[1:])
hash_value = hashlib.sha256()
with archive.open('rb') as f:
    for chunk in iter(lambda: f.read(1024 * 1024), b''):
        hash_value.update(chunk)
if hash_value.hexdigest() != SAMPLES_SHA256:
    sys.exit('Sample archive checksum mismatch')
with ZipFile(archive) as z:
    expected = {item.filename[len('Samples/'):]: timestamp(item)
                for item in z.infolist() if not item.is_dir()
                and item.filename.startswith('Samples/') and item.filename.lower().endswith('.ch1')}
if not expected or json.loads(manifest.read_text(encoding='utf-8')) != expected:
    sys.exit('Windows sample timestamp manifest does not match the release archive')
print(f'Windows sample timestamp manifest matches {len(expected)} sample files')
