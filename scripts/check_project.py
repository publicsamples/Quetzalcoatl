#!/usr/bin/env python3
"""Check tracked HISE project structure without requiring HISE."""
from pathlib import Path
import re
import sys
import xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[1]
PROJECT = ROOT / "Quetzalcoatl" / "Quetzalcoatl"
errors = []
required = [PROJECT / "project_info.xml", PROJECT / "Presets/Quetzalcoatl.hip",
            PROJECT / "Scripts/ScriptProcessors/Quetzalcoatl/Interface.js"]
for path in required:
    if not path.is_file() or path.stat().st_size == 0:
        errors.append(f"Missing or empty required file: {path.relative_to(ROOT)}")

xml_files = [PROJECT / "project_info.xml"]
for directory, pattern in [("DspNetworks/Networks", "*.xml"),
                           ("SampleMaps", "*.xml"), ("UserPresets", "*.preset")]:
    files = sorted(p for p in (PROJECT / directory).rglob(pattern)
                   if not any(part.startswith(".") for part in p.relative_to(PROJECT).parts))
    if not files:
        errors.append(f"No {pattern} files found in {directory}")
    xml_files.extend(files)
for path in xml_files:
    if not path.is_file():
        continue
    try:
        root = ET.parse(path).getroot()
        if path.parent == PROJECT / "DspNetworks/Networks":
            if root.tag != "Network" or not root.get("ID", "").strip():
                errors.append(f"Network needs a nonempty ID: {path.relative_to(ROOT)}")
    except (ET.ParseError, OSError) as exc:
        errors.append(f"Invalid XML in {path.relative_to(ROOT)}: {exc}")

interface = required[2]
if interface.is_file():
    for line in interface.read_text(encoding="utf-8").splitlines():
        match = re.match(r'^\s*include\("([^"\\]+)"\)\s*;', line)
        if match and not (PROJECT / "Scripts" / match.group(1)).is_file():
            errors.append(f"Missing interface script: {match.group(1)}")

if errors:
    print("\n".join(errors), file=sys.stderr)
    sys.exit(1)
print(f"Project structure OK; parsed {len(xml_files)} XML files and checked interface includes.")
