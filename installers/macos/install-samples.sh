#!/bin/bash
# Install sample monoliths and write the HISE link for this user.
set -euo pipefail
source_dir=${1:?missing sample source}
data_dir=${2:?missing application data directory}
sample_dir=${3:?missing destination sample directory}
scriptdir=$(cd "$(dirname "$0")" && pwd)
/bin/bash "$scriptdir/merge-content.sh" "$source_dir" "$sample_dir"
mkdir -p "$data_dir"
tmp=$(mktemp "$data_dir/.LinkOSX.XXXXXXXX")
trap 'rm -f "$tmp"' EXIT
printf '%s' "$sample_dir" > "$tmp"
mv -f "$tmp" "$data_dir/LinkOSX"
