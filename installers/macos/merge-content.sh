#!/bin/bash
# Merge installer content into one user's application-data directory.
# Arguments: source directory, destination directory.
set -euo pipefail
src=${1:?missing source directory}
dst=${2:?missing destination directory}
[ -d "$src" ] || { echo "Content directory missing: $src" >&2; exit 1; }
mkdir -p "$dst"
while IFS= read -r -d '' file; do
    rel=${file#"$src"/}
    case "$rel" in
        .DS_Store|*/.DS_Store|__MACOSX/*) continue ;;
    esac
    target="$dst/$rel"
    if [ -e "$target" ]; then
        [ -f "$target" ] || { echo "Not a file: $target" >&2; exit 1; }
        case "$rel" in
            GeneralSettings.xml|'User Presets/db.json') continue ;;
        esac
        src_time=$(stat -f '%m' "$file")
        dst_time=$(stat -f '%m' "$target")
        [ "$src_time" -gt "$dst_time" ] || continue
    fi
    mkdir -p "$(dirname "$target")"
    cp -p "$file" "$target"
done < <(find "$src" -type f -print0)
