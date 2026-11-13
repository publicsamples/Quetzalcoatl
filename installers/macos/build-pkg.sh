#!/bin/bash
# Build a package with bundled plugins/content and an optional sample download.
set -euo pipefail
plugins=${1:?plugin build directory required}
content=${2:?staged content directory required}
output=${3:?output package path required}
scriptdir=$(cd "$(dirname "$0")" && pwd)
work=$(mktemp -d "${TMPDIR:-/tmp}/quetzalcoatl-pkg.XXXXXXXX")
trap 'rm -rf "$work"' EXIT
stageid="com.modularsamples.quetzalcoatl.$(uuidgen)"
mkdir -p "$work/root/private/tmp/$stageid/content" "$work/root/Library/Audio/Plug-Ins/Components" "$work/root/Library/Audio/Plug-Ins/VST3" "$work/core-scripts" "$work/sample-scripts"
cp -pR "$content/." "$work/root/private/tmp/$stageid/content/"
cp -pR "$plugins/Quetzalcoatl.component" "$work/root/Library/Audio/Plug-Ins/Components/"
cp -pR "$plugins/Quetzalcoatl.vst3" "$work/root/Library/Audio/Plug-Ins/VST3/"
cp "$scriptdir/merge-content.sh" "$work/root/private/tmp/$stageid/merge-content.sh"
cat > "$work/core-scripts/postinstall" <<SCRIPT
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
rm -rf "\$stage"
SCRIPT
cp "$scriptdir/merge-content.sh" "$scriptdir/install-samples.sh" "$scriptdir/download-samples.sh" "$work/sample-scripts/"
cat > "$work/sample-scripts/postinstall" <<'SCRIPT'
#!/bin/bash
set -euo pipefail
user=$(stat -f '%Su' /dev/console)
if [[ -z "$user" || "$user" == root || "$user" == loginwindow ]]; then
    echo 'No logged-in desktop user found for sample download.' >&2
    exit 1
fi
home=$(dscl . -read "/Users/$user" NFSHomeDirectory | cut -d ' ' -f 2-)
[[ -d "$home" ]] || { echo 'Cannot locate user home directory.' >&2; exit 1; }
tmp=$(mktemp -d /private/tmp/quetzalcoatl-sample-scripts.XXXXXXXX)
trap 'rm -rf "$tmp"' EXIT
cp "$(dirname "$0")/merge-content.sh" "$(dirname "$0")/install-samples.sh" "$(dirname "$0")/download-samples.sh" "$tmp/"
chown -R "$user" "$tmp"
/usr/bin/sudo -u "$user" /bin/bash "$tmp/download-samples.sh" \
  "$home/Library/Application Support/modularsamples/Quetzalcoatl" \
  "$home/Music/modularsamples/Quetzalcoatl/Samples"
SCRIPT
chmod 755 "$work/core-scripts/postinstall" "$work/root/private/tmp/$stageid/merge-content.sh" "$work/sample-scripts/"*.sh "$work/sample-scripts/postinstall"
pkgbuild --root "$work/root" --scripts "$work/core-scripts" --identifier com.modularsamples.quetzalcoatl.v1 --version 1.0.0 --install-location / "$work/Core.pkg"
pkgbuild --nopayload --scripts "$work/sample-scripts" --identifier com.modularsamples.quetzalcoatl.v1.samples --version 1.0.0 "$work/Samples.pkg"
cat > "$work/Distribution.xml" <<'XML'
<?xml version="1.0" encoding="utf-8"?>
<installer-gui-script minSpecVersion="1">
  <title>Quetzalcoatl 1.0.0</title>
  <options customize="always" hostArchitectures="arm64,x86_64"/>
  <domains enable_anywhere="false" enable_currentUserHome="false" enable_localSystem="true"/>
  <choices-outline><line choice="core"/><line choice="samples"/></choices-outline>
  <choice id="core" title="Quetzalcoatl plugins and content" enabled="false" selected="true"><pkg-ref id="com.modularsamples.quetzalcoatl.v1"/></choice>
  <choice id="samples" title="Download factory samples (about 720 MB)" selected="true"><pkg-ref id="com.modularsamples.quetzalcoatl.v1.samples"/></choice>
  <pkg-ref id="com.modularsamples.quetzalcoatl.v1" version="1.0.0">Core.pkg</pkg-ref>
  <pkg-ref id="com.modularsamples.quetzalcoatl.v1.samples" version="1.0.0">Samples.pkg</pkg-ref>
</installer-gui-script>
XML
mkdir -p "$(dirname "$output")"
productbuild --distribution "$work/Distribution.xml" --package-path "$work" "$output"
