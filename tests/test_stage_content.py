#!/usr/bin/env python3
"""Exercise installer staging and preservation of ZIP UTC timestamps."""
import hashlib
import struct
import sys
import tempfile
from pathlib import Path
from zipfile import ZipFile, ZipInfo

sys.path.insert(0, str(Path('scripts').resolve()))
import check_content
import stage_content


def item(name, stamp):
    info = ZipInfo(name)
    info.extra = struct.pack('<HHBI', 0x5455, 5, 1, stamp)
    return info


with tempfile.TemporaryDirectory() as tmp:
    root = Path(tmp)
    archive = root / 'content.zip'
    with ZipFile(archive, 'w') as z:
        z.writestr(item('Quetzalcoatl/AudioResources.dat', 1577836800), b'audio')
        z.writestr(item('Quetzalcoatl/User Presets/test.preset', 1577836801), b'preset')
        z.writestr(item('__MACOSX/Quetzalcoatl/._test', 1577836800), b'metadata')
    check_content.EXPECTED_SHA256 = hashlib.sha256(archive.read_bytes()).hexdigest()
    stage_content.stage(archive, root / 'output')
    assert (root / 'output/AudioResources.dat').stat().st_mtime == 1577836800
    assert (root / 'output/User Presets/test.preset').stat().st_mtime == 1577836801
    assert not (root / 'output/__MACOSX').exists()
    try:
        stage_content.stage(archive, root / 'output')
    except ValueError:
        pass
    else:
        raise AssertionError('Non-empty staging directory was accepted')
print('Content staging and UTC timestamps verified')
