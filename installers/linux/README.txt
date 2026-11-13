Quetzalcoatl 1.0.0 for Linux (x86-64)

Run the included installer from a terminal:

    python3 install.py

It installs the VST3 to ~/.vst3, the content to
~/.config/modularsamples/Quetzalcoatl, and the sample library to
~/Music/modularsamples/Quetzalcoatl/Samples. If your desktop has a custom
Music directory configured in ~/.config/user-dirs.dirs, that folder is used.
The installer creates LinkLinux in the application-data folder pointing to the
sample directory. Existing files are replaced only if the supplied copy is
newer. Existing GeneralSettings.xml and User Presets/db.json are preserved.

Restart your DAW and rescan plugins if necessary. To uninstall, remove
Quetzalcoatl.vst3 from ~/.vst3. Your content, samples and presets remain.
