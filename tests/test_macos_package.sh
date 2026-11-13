#!/bin/bash
set -euo pipefail
root=$(mktemp -d)
trap 'rm -rf "$root"' EXIT
mkdir -p "$root/plugins/Quetzalcoatl.component" "$root/plugins/Quetzalcoatl.vst3" "$root/content/User Presets"
printf data > "$root/content/AudioResources.dat"
printf preset > "$root/content/User Presets/test.preset"
touch -t 202001010000 "$root/content/AudioResources.dat"
installers/macos/build-pkg.sh "$root/plugins" "$root/content" "$root/test.pkg"
pkgutil --expand-full "$root/test.pkg" "$root/expanded"
staged=$(find "$root/expanded" -path '*/content/AudioResources.dat' -type f -print -quit)
[[ -n "$staged" ]]
[[ $(cat "$staged") == data ]]
[[ $(stat -f '%m' "$staged") == $(stat -f '%m' "$root/content/AudioResources.dat") ]]
[[ -f "$root/expanded/Core.pkg/Scripts/postinstall" ]]
[[ -f "$root/expanded/Samples.pkg/Scripts/postinstall" ]]
python3 - "$root/expanded/Distribution" <<'PYXML'
import sys, xml.etree.ElementTree as ET
root=ET.parse(sys.argv[1]).getroot()
choice=root.find("./choice[@id='samples']")
assert choice is not None and choice.get('selected') == 'true'
PYXML
echo 'macOS package structure and timestamps verified'
