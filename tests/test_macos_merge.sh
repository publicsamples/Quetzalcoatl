#!/bin/bash
set -euo pipefail
root=$(mktemp -d)
trap 'rm -rf "$root"' EXIT
src="$root/src"
dst="$root/dst"
mkdir -p "$src/User Presets" "$dst/User Presets"
printf old > "$dst/newer"
printf new > "$src/newer"
printf kept > "$dst/equal"
printf replaced > "$src/equal"
printf kept > "$dst/user"
printf settings > "$dst/GeneralSettings.xml"
printf factory > "$src/GeneralSettings.xml"
printf favorites > "$dst/User Presets/db.json"
printf factory > "$src/User Presets/db.json"
printf add > "$src/User Presets/new.preset"
touch -t 202001010000 "$dst/newer" "$dst/equal" "$src/equal"
touch -t 202401010000 "$src/newer" "$src/GeneralSettings.xml" "$src/User Presets/db.json"
installers/macos/merge-content.sh "$src" "$dst"
[ "$(cat "$dst/newer")" = new ]
[ "$(cat "$dst/equal")" = kept ]
[ "$(cat "$dst/user")" = kept ]
[ "$(cat "$dst/GeneralSettings.xml")" = settings ]
[ "$(cat "$dst/User Presets/db.json")" = favorites ]
[ "$(cat "$dst/User Presets/new.preset")" = add ]
printf 'macOS content merge checks passed\n'
