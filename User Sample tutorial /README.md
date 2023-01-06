
# Quetzalcoatl User Samples expansion

To get the most out of Quetzalcoatl and have a broader set of sounds, some users may wish to import their own samples. This can easily be achieved by creating your own expansion.

# Requirements 

To begin with, you will need to [download](https://github.com/christophhart/HISE/releases/tag/3.0.1) or [build](https://github.com/christophhart/HISE/tree/develop) a recent copy of HISE.  After you have HISE up and running, the process looks something like this:

# Guide

1. Download, or clone this repository

2. Open HISE and when prompted create a new project 

3. From the module tree click on the pen icon, then click the + button to create a new sampler

![Create Sampler](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl-User-Samples-expansion/main/Guide%20images/0-create-sampler.png)

4. Click on the Sampler to open and then drag your samples into the mapping editor

![Mapping Editor](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl-User-Samples-expansion/main/Guide%20images/1-HISE-Sample-Window.png) 

5. A diaglogue with some import settings will be displayed, the options your choose here will depend on how your samples are formatted (for more info see the notes below). Generally speaking it's best to use the File name token parser and have "Extract metadata for mapping" enabled to include any loop points the samples might have.

![import settings](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl-User-Samples-expansion/main/Guide%20images/2-ImportSettings.png)

6. if you selected the token parser this will be the next dialogue. This will automatically map the samples based on information contained in the samples file name. As we can see in the image below our files contain several pieces of information. Trumpet-A1-127-FKDO. 

![enter image description here](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl-User-Samples-expansion/main/Guide%20images/3-TokenParser.png)

- Trumpet is the name of the sample. 
- A1 is the note that the file should be mapped too.
- 127 is the maximum velocity value.
- FKDO is a unique identifier. 

In this example, the only part we care about is the note information, we'll use this to map our samples by setting the property to "Single key" and the Data type to "note name".  To proceed press "OK".

7. If everything worked you'll see that your samples are correctly mapped in the editor.

![mapped](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl-User-Samples-expansion/main/Guide%20images/5-Mapped.png)

8. If your samples have loop, or mapping information stored in metadata, we can now apply this by selecting the samples, right clicking and choosing "Automap using metadata" from the tools menu.

9. At this point, we can make any final adjustments,  a full discussion of all the options here is out of the scope of this tutorial, however it is at this point that I will check that the loops work correctly, normalise the samples and then drop the volume down by -6db.

![editor](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl-User-Samples-expansion/main/Guide%20images/6-Editor.png) 

10. Once finished editing, we need to save the sample map by clicking on the disk icon in the mapping area and converting our samples to an "HLAC monolith" this converts the audio files into a single, compressed file. 

![save](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl-User-Samples-expansion/main/Guide%20images/7b.png)

11. Repeat the process above for any additional sample maps you wish to create

12. Now that we've finished creating sample maps it's time to add them to Quetzalcoatl. Open the project folder that you created in step 3 and copy the contents of the SampleMaps and Samples folders to their counterparts in this repository.

![folders](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl-User-Samples-expansion/main/Guide%20images/8-ProjectFiles.png)

13. You should now copy the folder "User Samples" to the Quetzalcoatl expansion folder. 

Mac: Users/YourUserName/Library/Application Support/Modularsamples/Quetzalcoatl/Expansions

Windows: C:\Users/YourUserName/AppData/Roaming/Modularsamples/Quetzalcoatl/Expansions

The next time you open Quetzalcoatl, you'll be able to load your samples by clicking on the expansion menu and selecting "User samples"

![expansion](https://raw.githubusercontent.com/publicsamples/Quetzalcoatl-User-Samples-expansion/main/Guide%20images/expmenu.png)

# More information 

For a detailed look at HISE's folder structure see:
https://docs.hise.audio/working-with-hise/project-management/index.html

More info on the HISE sampler:
https://docs.hise.audio/hise-modules/sound-generators/list/streamingsampler.html

You can rename your expansion pack by editing the expansion_info.xml file in the repository. 


# Best practices  

Generally speaking, it's best to work with samples that are already well formatted and looped. Ideally they will include loop points in the metadata and mapping information in the file name. 

The samples that ship with Quetzalcoatl are all looped, given the nature of the instrument I think this is best but it's not a requirement. 

# Licensing 

HISE, and by extension Quetzalcoatl & it's expansion packs, use the GPL3 license. If you plan on releasing your expansion to the public you must abide by the terms of this license. 
