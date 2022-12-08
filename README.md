# Quetzalcoatl

A Vector Morphing Rompler Thing with FM and serpent gods, plugins are available for Mac OS and Windows (Linux as soon as I can get it working).

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

Or something like that anyway, if you have any problems just get in touch.  

Windows

1. Download the plugin and factory content (Quetzalcoatl_0_1_0_Samples.hr1) from the releases page.
2. Copy Quetzalcoatl.vst3 to C:\Program Files\Common Files\VST3
3. Wait for any additional files to download
4. On loading Quetzalcoatl you will be asked for the factory content file you downloaded earlier. Open this and the restart the plugin.
5. You should now be ready to use the plugin. If you wish to install any of the additional sample packs, click on the "Load expansion" button and select the file (as with the factory content, you'll need to restart the plugin for the content to appear).


# Building from source

Currently the project will crash HISE unless the sample files are included, before opening the project download the factory content from the releases page and select "import archived samples" from the tools menu.

