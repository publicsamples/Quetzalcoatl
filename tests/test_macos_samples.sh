#!/bin/bash
set -euo pipefail
root=$(mktemp -d)
trap 'rm -rf "$root"' EXIT
mkdir -p "$root/source" "$root/data" "$root/My Music/modularsamples/Quetzalcoatl/Samples"
printf sample > "$root/source/test.ch1"
printf newer > "$root/My Music/modularsamples/Quetzalcoatl/Samples/existing.ch1"
printf old > "$root/source/existing.ch1"
touch -t 202001010000 "$root/source/existing.ch1"
touch -t 202401010000 "$root/My Music/modularsamples/Quetzalcoatl/Samples/existing.ch1"
sample_dir="$root/My Music/modularsamples/Quetzalcoatl/Samples"
bash installers/macos/install-samples.sh "$root/source" "$root/data" "$sample_dir"
[[ $(cat "$sample_dir/test.ch1") == sample ]]
[[ $(cat "$sample_dir/existing.ch1") == newer ]]
[[ $(cat "$root/data/LinkOSX") == "$sample_dir" ]]
echo 'macOS sample installation checks passed'
