#!/usr/bin/env python3
"""Make HISE's generated macOS plugin build target both supported CPUs."""
import sys
from pathlib import Path

if len(sys.argv) != 2:
    sys.exit('Usage: force_universal_macos.py PATH_TO_HISE_BUILD_SCRIPT')
path = Path(sys.argv[1])
text = path.read_text(encoding='utf-8')
needle = 'xcodebuild -project '
if text.count(needle) != 1:
    sys.exit(f'Unexpected HISE build script; cannot set architectures: {path}')
text = text.replace(needle, 'xcodebuild ARCHS="arm64 x86_64" ONLY_ACTIVE_ARCH=NO -project ', 1)
path.write_text(text, encoding='utf-8')
