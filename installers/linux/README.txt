Quetzalcoatl 1.0.0 for Linux (x86-64)

Extract the whole ZIP, open a terminal in the extracted folder containing
install.py, and choose one of the following installation options. Python 3 is
required. Run the commands as the user who will use the plugin, without sudo.
Each option installs the VST3 and bundled app data (including presets,
wavetables and AudioResources.dat).

1. Install with the factory samples (default)

    python3 install.py

This downloads the factory sample library (about 720 MB), verifies it, and
installs it. An internet connection and space for the download and extracted
samples are required. You can also use python3 install.py --samples.

2. Install without downloading samples

    python3 install.py --no-samples

Use this if you already have a sample library linked, or do not want samples
right now. Any existing LinkLinux and sample files are left untouched. Without
a usable sample library, sample-based sounds may not play and HISE may prompt
for a sample location. To add the factory samples later, run option 1.

3. Install from an already extracted sample library

    python3 install.py --samples-from "/path/to/Samples"

Replace the path with the directory containing the .ch1 files. The script
copies them into your Music folder and updates LinkLinux; it does not download
samples. Quote the path if it contains spaces. You can also use this option to
add samples later.

Locations and upgrades

The plugin is installed in ~/.vst3/Quetzalcoatl.vst3. App data is normally in
~/.config/modularsamples/Quetzalcoatl. Samples installed by options 1 and 3 go
in ~/Music/modularsamples/Quetzalcoatl/Samples. If this HISE build finds a
configured Music or config folder in ~/.config/user-dirs.dirs, it uses that
folder instead. LinkLinux in the app-data folder contains the absolute sample
path; installing samples updates it to the installed library.

Existing app data and sample files are replaced only when the supplied file is
newer. Existing GeneralSettings.xml and User Presets/db.json are always kept;
other user-added files are retained. Restart your DAW and rescan plugins if
necessary. To uninstall the plugin, remove Quetzalcoatl.vst3 from ~/.vst3;
app data, samples and presets remain.

If the download fails, check your connection and rerun option 1. The plugin and
app data may already have been installed; an existing sample link is not changed
until the sample library has been downloaded and installed.
