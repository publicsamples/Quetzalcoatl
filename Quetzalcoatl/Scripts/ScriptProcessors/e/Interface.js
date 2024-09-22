Content.makeFrontInterface(490, 300);

const var SlotSelectors = [Content.getComponent("Sel1"),
                           Content.getComponent("Sel2")];

const var AudioLoopPlayers = [Synth.getAudioSampleProcessor("Audio Loop Player1"),
                              Synth.getAudioSampleProcessor("Audio Loop Player2")]


const var AudioLoopPlayer1 = Synth.getChildSynth("Audio Loop Player1");
const var Loop1 = Synth.getAudioSampleProcessor("Audio Loop Player1");
const var FileSelect = Content.getComponent("FileSelect");
const var FileSelect1 = Content.getComponent("FileSelect1");
const var FolderLabel = Content.getComponent("FolderLabel");


const var allList = [];
const var allIds = [];

// This loads all files from the project folder and returns a list of references
const var rootList = Engine.loadAudioFilesIntoPool();

// We'll keep a list of "nice names" and a list of valid references
allList.push("no file");
allIds.push("");

for(r in rootList)
{
    allList.push(r.split("}")[1]);
    allIds.push(r);
}


for(s in SlotSelectors)
    s.set("items", allList.join("\n"));

inline function onSlotSelectorControl(component, value)
{
    local index = SlotSelectors.indexOf(component);
    
    if(value != 0)
    {
	AudioLoopPlayers[index].setFile(allIds[value-1]);
    }
};

const var numbers = [64, 48];
const var ids = [-1, -1];

for(s in SlotSelectors)
    s.setControlCallback(onSlotSelectorControl);



//Store folder path

const FolderPath = [];


// Choose a folder to load samples from. 

inline function onFolderSelectControl(component, value) {

//Select a folder

    FileSystem.browseForDirectory(FileSystem.Downloads, function(folder) {
        if (isDefined(folder) && folder.isDirectory()) {
         
         //find files in selected folder
         
            var folderArray = FileSystem.findFiles(folder, "*.wav, *.aif", false);

            for (file in folderArray) {
                file = file.toString(0);
                
                var folderArray2 = FileSystem.findFiles(folder, "*.wav, *.aif", false);
                            
                            for (file1 in folderArray2) {
                                        file1 = file1.toString(3);        
                
         //Populate the Folder Label
              
                FolderLabel.set("text", folder.toString(0));
                FolderPath.push(folder);
                
            };
            
            
            
            //send items to hidden ComboBox
            
            FileSelect.set("items", folderArray.join("\n"));
            FileSelect1.set("items", folderArray2.join("\n"));
            
}

        }
    });
};

Content.getComponent("FolderSelect").setControlCallback(onFolderSelectControl);

//Select a file at random



//Loads the samples

inline function onFileSelectControl(component, value) {

    Loop1.setFile(FileSelect.get("items").split("\n")[value - 1]);

};

Content.getComponent("FileSelect").setControlCallback(onFileSelectControl);


inline function onFileSelect1Control(component, value)
{
	FileSelect.setValue(value);
	FileSelect.changed();
};

Content.getComponent("FileSelect1").setControlCallback(onFileSelect1Control);
function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 