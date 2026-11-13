#!/usr/bin/env python3
import hashlib
from pathlib import Path
import struct
import sys
import tempfile
from zipfile import ZipFile, ZipInfo

sys.path.insert(0, str(Path('scripts').resolve()))
import stage_samples

with tempfile.TemporaryDirectory() as d:
    root = Path(d)
    archive = root / 'samples.zip'
    entry = ZipInfo('Samples/test.ch1')
    entry.extra = struct.pack('<HHBI', 0x5455, 5, 1, 1577836800)
    with ZipFile(archive, 'w') as z:
        z.writestr(entry, b'sample')
        z.writestr('__MACOSX/Samples/._test.ch1', b'metadata')
    stage_samples.SAMPLES_SHA256 = hashlib.sha256(archive.read_bytes()).hexdigest()
    stage_samples.stage(archive, root / 'staged')
    assert (root / 'staged/test.ch1').read_bytes() == b'sample'
    assert (root / 'staged/test.ch1').stat().st_mtime == 1577836800
    assert len(list((root / 'staged').iterdir())) == 1
print('Sample staging and timestamps verified')
