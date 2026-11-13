#!/bin/bash
# Download the optional factory library as the logged-in user.
set -euo pipefail
data_dir=${1:?missing application data directory}
sample_dir=${2:?missing sample destination}
scriptdir=$(cd "$(dirname "$0")" && pwd)
work=$(mktemp -d /private/tmp/quetzalcoatl-samples.XXXXXXXX)
trap 'rm -rf "$work"' EXIT
archive="$work/Samples.zip"
curl --fail --location --retry 2 --connect-timeout 30 --output "$archive" 'https://github.com/publicsamples/Quetzalcoatl/releases/download/1.0.0/Samples.zip'
expected=84ec2a7db78e30d0eac84dbf2488b8586d62b7380b6b051ecbec46ac5e040afc
actual=$(shasum -a 256 "$archive" | awk '{print $1}')
[[ "$actual" == "$expected" ]] || { echo 'Sample download checksum mismatch' >&2; exit 1; }
unzip -q "$archive" 'Samples/*' -d "$work/extracted"
[[ -n $(find "$work/extracted/Samples" -type f -name '*.ch1' -print -quit) ]] || { echo 'Sample library is empty' >&2; exit 1; }
/bin/bash "$scriptdir/install-samples.sh" "$work/extracted/Samples" "$data_dir" "$sample_dir"
