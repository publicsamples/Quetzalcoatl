Quetzalcoatl 1.0.0 for Linux (x86-64)

Open a terminal in this folder. Run as your normal user; Python 3 is required.

Install the plugin, app data and factory samples (downloads about 720 MB):

    python3 install.py

Install without downloading samples (keeps any existing sample link):

    python3 install.py --no-samples

Install samples from an extracted folder containing .ch1 files:

    python3 install.py --samples-from "/path/to/Samples"

The plugin is installed in ~/.vst3. Restart your DAW and rescan plugins.
Without samples, sample-based sounds may not play. To add samples later, run
one of the sample installation commands above.
