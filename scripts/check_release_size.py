#!/usr/bin/env python3
"""Report whether a package fits GitHub's per-release-asset limit."""
from pathlib import Path
import sys

LIMIT = 2 * 1024 ** 3
MARGIN = 16 * 1024 ** 2
if len(sys.argv) != 2:
    sys.exit('Usage: check_release_size.py PACKAGE')
path = Path(sys.argv[1])
size = path.stat().st_size
print(f'{path.name}: {size:,} bytes; GitHub release limit: below {LIMIT:,} bytes')
if size >= LIMIT:
    print(f'::warning::{path.name} exceeds the GitHub release asset limit by {size - LIMIT + 1:,} bytes')
elif LIMIT - size < MARGIN:
    print(f'::warning::{path.name} is within {LIMIT - size:,} bytes of the GitHub release asset limit')
