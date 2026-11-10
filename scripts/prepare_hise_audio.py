#!/usr/bin/env python3
"""Preserve the supplied audio pool during a CI-only HISE export."""
import argparse
import hashlib
from pathlib import Path
import shutil
from zipfile import ZipFile

from check_content import check

POOL_SHA256 = '122ac0a35055f9b99402d41ce664badcf777a64b4b1032fe03c8dc7b79612466'


def replace_once(path, old, new):
    text = path.read_text(encoding='utf-8')
    if text.count(old) != 1:
        raise ValueError(f'Unexpected HISE source; cannot safely patch {path}')
    path.write_text(text.replace(old, new, 1), encoding='utf-8')


def patch_hise(root):
    exporter = root / 'hi_backend/backend/CompileExporter.cpp'
    pools = root / 'hi_core/hi_core/PresetHandler.cpp'
    tests = root / 'hi_backend/backend/ai_tools/tests/ServerUnitTests.cpp'
    test_source = tests.read_text(encoding='utf-8')
    if test_source.count('RestServer::POST') != 2:
        raise ValueError(f'Unexpected HISE test source; cannot safely patch {tests}')
    tests.write_text(test_source.replace('RestServer::POST', 'RestServer::Method::Post'), encoding='utf-8')
    replace_once(exporter,
                 'if (rawMode || !alreadyExported || data.getSetting(HiseSettings::Compiler::RebuildPoolFiles))',
                 'if (true) /* CI: rebuild non-audio pools using project assets. */')
    replace_once(exporter, 'sof.deleteFile();',
                 '/* CI: retain the supplied AudioResources.dat. */')
    old = '''sampleOutputFile.deleteFile();
    
\tif (logData != nullptr) logData->logFunction("Export audio files");
\tchain->getMainController()->getCurrentAudioSampleBufferPool()->getDataProvider()->writePool(new FileOutputStream(sampleOutputFile), progress);'''
    replace_once(pools, old, '/* CI: do not regenerate AudioResources.dat. */')


def verify(pool):
    with pool.open('rb') as f:
        digest = hashlib.file_digest(f, 'sha256').hexdigest()
    if digest != POOL_SHA256:
        raise ValueError(f'Audio pool missing or changed: {pool}')
    print(f'Audio pool verified: {pool}')


def prepare(archive, project):
    check(archive)
    pool = project / 'PooledResources/AudioResources.dat'
    pool.parent.mkdir(parents=True, exist_ok=True)
    with ZipFile(archive) as z, z.open('Quetzalcoatl/AudioResources.dat') as src, pool.open('wb') as dst:
        shutil.copyfileobj(src, dst, 1024 * 1024)
    verify(pool)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='action', required=True)
    patch = sub.add_parser('patch-hise'); patch.add_argument('hise', type=Path)
    prep = sub.add_parser('prepare'); prep.add_argument('archive', type=Path); prep.add_argument('project', type=Path)
    verify_parser = sub.add_parser('verify'); verify_parser.add_argument('pool', type=Path)
    args = parser.parse_args()
    if args.action == 'patch-hise': patch_hise(args.hise)
    elif args.action == 'prepare': prepare(args.archive, args.project)
    else: verify(args.pool)
