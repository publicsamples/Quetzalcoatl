Quetzalcoatl 1.0.0 for Linux (x86-64)

Run the included installer from a terminal:

    python3 install.py

It installs the VST3 to ~/.vst3 and the content to
${XDG_CONFIG_HOME:-~/.config}/modularsamples/Quetzalcoatl. Existing content
is merged: files are replaced only when the supplied file is newer. Existing
GeneralSettings.xml and User Presets/db.json are preserved. Your separately
supplied sample library is not included in this archive.

Restart your DAW and rescan plugins if necessary. This build is tested against
its CI runner environment; compatibility with every Linux distribution is not
guaranteed. To uninstall, remove Quetzalcoatl.vst3 from ~/.vst3. Your content
and presets remain in the application data directory.
