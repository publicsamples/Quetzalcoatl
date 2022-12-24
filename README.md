# Quetzalcoatl

A Vector Morphing Rompler Thing with FM and serpent gods, VST3 and Audio Unit plugins are available for Mac OS, Windows & Linux. 

![Quetzalcoatl](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl/main/Quetzalcoatl.png)

Quetzalcoatl is built with [HISE](http://hise.audio), an open source framework for sample based instruments. 

# Features 

- An 8 layer vector oscillator with pitch, volume and pan controls for each layer
- A second "utility" oscillator that can be routed to oscillator 1's pitch for FM
- Multiple crossfade techniques
- Extensive modulation controls 
- A growing sound library featuring sounds from vintage and modular synthesisers 
- Multi-mode filter 
- Simple arpeggiator
- Bizarro chorus effect


# Demo

https://www.youtube.com/watch?v=gIRgUi0J35Y

# Install

Mac

1. Download the plugin and factory content (Quetzalcoatl_0_1_0_Samples.hr1) from the releases page.
2. Copy Quetzalcoatl.component to Library/Audio/Plugins/Components/
3. Wait for any additional files to download
4. Start your DAW. You'll probably get a message saying “the developer cannot be verified” to fix this open System Preferences → Security and Privacy. On the general tab click ‘Open anyway’. You may have to do this several times (i know, it's stupid)
5. On loading Quetzalcoatl you will be asked for the factory content file you downloaded earlier. Open this and the restart the plugin.
6. You should now be ready to use the plugin. If you wish to install any of the additional sample packs, click on the "Load expansion" button and select the file (as with the factory content, you'll need to restart the plugin for hte content to appear).


Windows

1. Download the plugin and factory content (Quetzalcoatl_0_1_0_Samples.hr1) from the releases page.
2. Copy Quetzalcoatl.vst3 to C:\Program Files\Common Files\VST3
3. Wait for any additional files to download
4. On loading Quetzalcoatl you will be asked for the factory content file you downloaded earlier. Open this and the restart the plugin.
5. You should now be ready to use the plugin. If you wish to install any of the additional sample packs, click on the "Load expansion" button and select the file (as with the factory content, you'll need to restart the plugin for the content to appear).

Linux

1. Download the plugin and factory content (Quetzalcoatl_0_1_0_Samples.hr1) from the releases page.
2. Copy Quetzalcoatl.vst3 to User/Home/.vst3
3. Wait for any additional files to download
4. On loading Quetzalcoatl you will be asked for the factory content file you downloaded earlier. Open this and the restart the plugin.
5. You should now be ready to use the plugin. If you wish to install any of the additional sample packs, click on the "Load expansion" button and select the file (as with the factory content, you'll need to restart the plugin for the content to appear).


# Expansion Packs

Quetzalcoatl "ships" with a limited number of factory samples. To get the most out of the synth download additional sample packs here:

https://github.com/publicsamples/Quetzalcoatl/releases/tag/0.1.3-exp

# Adding custom samples

With a bit of effort it is possible to add your own samples to Quetzalcoatl. For a detailed guide and an example repository see:
  
https://github.com/publicsamples/Quetzalcoatl/tree/main/User%20Sample%20tutorial%20

# Building from source

Currently the project will crash HISE unless the sample files are included, before opening the project download the factory content from the releases page and select "import archived samples" from the tools menu. This has only been minimally tested, so expect to do some troubleshooting..

