#!/bin/bash
# Build an unsigned installer from already built plugin bundles and staged data.
set -euo pipefail
plugins=${1:?plugin build directory required}
content=${2:?staged content directory required}
output=${3:?output package path required}
samples=${4:?staged sample directory required}
scriptdir=$(cd "$(dirname "$0")" && pwd)
work=$(mktemp -d "${TMPDIR:-/tmp}/quetzalcoatl-pkg.XXXXXXXX")
trap 'rm -rf "$work"' EXIT
# The unique staging name prevents collisions with unrelated installer files.
stageid="com.modularsamples.quetzalcoatl.$(uuidgen)"
mkdir -p "$work/root/private/tmp/$stageid/content" "$work/root/private/tmp/$stageid/samples" "$work/root/Library/Audio/Plug-Ins/Components" "$work/root/Library/Audio/Plug-Ins/VST3" "$work/scripts"
cp -pR "$content/." "$work/root/private/tmp/$stageid/content/"
cp -pR "$samples/." "$work/root/private/tmp/$stageid/samples/"
cp -pR "$plugins/Quetzalcoatl.component" "$work/root/Library/Audio/Plug-Ins/Components/"
cp -pR "$plugins/Quetzalcoatl.vst3" "$work/root/Library/Audio/Plug-Ins/VST3/"
cp "$scriptdir/merge-content.sh" "$scriptdir/install-samples.sh" "$work/root/private/tmp/$stageid/"
cat > "$work/scripts/postinstall" <<SCRIPT
#!/bin/bash
set -euo pipefail
stage="/private/tmp/$stageid"
user=\$(stat -f '%Su' /dev/console)
if [[ -z "\$user" || "\$user" == root || "\$user" == loginwindow ]]; then
    echo 'No logged-in desktop user found for application content.' >&2
    exit 1
fi
home=\$(dscl . -read "/Users/\$user" NFSHomeDirectory | cut -d ' ' -f 2-)
[[ -d "\$home" ]] || { echo 'Cannot locate user home directory.' >&2; exit 1; }
/usr/bin/sudo -u "\$user" /bin/bash "\$stage/merge-content.sh" "\$stage/content" "\$home/Library/Application Support/modularsamples/Quetzalcoatl"
/usr/bin/sudo -u "\$user" /bin/bash "\$stage/install-samples.sh" "\$stage/samples" "\$home/Library/Application Support/modularsamples/Quetzalcoatl" "\$home/Music/modularsamples/Quetzalcoatl/Samples"
rm -rf "\$stage"
SCRIPT
chmod 755 "$work/scripts/postinstall" "$work/root/private/tmp/$stageid/merge-content.sh" "$work/root/private/tmp/$stageid/install-samples.sh"
mkdir -p "$(dirname "$output")"
pkgbuild --root "$work/root" --scripts "$work/scripts" --identifier com.modularsamples.quetzalcoatl.v1 --version 1.0.0 --install-location / "$output"
