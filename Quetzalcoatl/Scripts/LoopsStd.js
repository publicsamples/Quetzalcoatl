///// Loop Player Internal

const var LoadAllInternal = Content.getComponent("LoadAllInternal");
//const var expansionList = expHandler.getExpansionList();

var Bank;
const var LpBank1 = Content.getComponent("LpBank1");
var aFile;

const var Roots = [Content.getComponent("root1"),
                   Content.getComponent("root2"),
                   Content.getComponent("root3"),
                   Content.getComponent("root4"),
                   Content.getComponent("root5"),
                   Content.getComponent("root6"),
                   Content.getComponent("root7"),
                   Content.getComponent("root8"),
                   Content.getComponent("root9"),
                   Content.getComponent("root10"),
                   Content.getComponent("root11"),
                   Content.getComponent("root12"),
                   Content.getComponent("root13"),
                   Content.getComponent("root14"),
                   Content.getComponent("root15"),
                   Content.getComponent("root16")];


const var LpFilePath =[];

for (i = 0; i < 8; i++)
{
    LpFilePath[i] = Content.getComponent("LpPath"+(i+1));

}  

const var LpLoaders =[];

for (i = 0; i < 8; i++)
{
    LpLoaders[i] = Content.getComponent("LpLoad"+(i+1));

}    


const var LpLoadInternal =[];

for (i = 0; i < 8; i++)
{
    LpLoadInternal[i] = Content.getComponent("LpLoadInt"+(i+1));

}   

const var SampleIntLabel =[];

for (i = 0; i < 8; i++)
{
    SampleIntLabel[i] = Content.getComponent("SampleInt"+(i+1));

}  



const var SampleUserLabel =[];

for (i = 0; i < 8; i++)
{
    SampleUserLabel[i] = Content.getComponent("SampleUser"+(i+1));

}                        

const var Loopers =[];

for (i = 0; i < 8; i++)
{
    Loopers[i] = Synth.getAudioSampleProcessor("LoopA"+(i+1));

}

const var allList = [];
const var allIds = [];

const var AudioList = Engine.loadAudioFilesIntoPool();

allList.push("no file");
allIds.push("");


for(r in AudioList)
{
    allList.push(r.split("}")[1]);
    allIds.push(r);
}


	    
       // LoadAllInternal.set("items", allList.join("\n").replace(".wav").replace(".aif").replace(".aiff"));




inline function onLpLoadInternalControl(component, value)
{

   local index = LpLoadInternal.indexOf(component);

   
    if(value != 0)
    {

	aFile = parseInt(value-1);

    Loopers[index].setFile("{PROJECT_FOLDER}"+folders[Bank]+"/"+sorted[Bank][aFile]);

	SampleIntLabel[index].set("text",LpLoadInternal[index].get("items").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("Modular").split("\n")[value-1]);

	for(s in Roots)
    s.setValue(64);
    for(s in Roots)
        s.changed();
        
  
}
};



for(s in LpLoadInternal)
    s.setControlCallback(onLpLoadInternalControl);
    
const folders = [];
const sorted = [];
const empty = ["thing"];




inline function sortAudioFilesList()
{



	for (x in AudioList)
	{
		local folder = x.substring(x.indexOf("}") + 1, x.indexOf("/"));
		local file = x.substring(x.indexOf("/") + 1, x.length);
		
	
		
		if (folders.indexOf(folder) == -1)
		{
			folders.push(folder);
	
				


			sorted.push(["no file"]);
	//	folders.push(["empty"]);

		
		}
		
		
					
		sorted[folders.indexOf(folder)].push(file);
	//	LpBank1.set("items", folders.join("\n").replace("a-").replace("b-").replace("c-").replace("d-").replace("e-").replace("f-").replace("g-").replace("h-"));
		
	}

}

sortAudioFilesList();



//sorted.push();


inline function onLpBank1Control(component, value)
{
	if (value == 1)
{
	Bank = parseInt(0); 

	for(s in LpLoadInternal)
    s.set("items", sorted[0].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));
	LoadAllInternal.set("items", sorted[0].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));

}

if (value == 2)
{
Bank = parseInt(1); 

for(s in LpLoadInternal)
    s.set("items", sorted[1].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));
LoadAllInternal.set("items", sorted[1].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));

}

if (value == 3)
{
Bank = parseInt(2);

for(s in LpLoadInternal)
    s.set("items", sorted[2].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));
LoadAllInternal.set("items", sorted[2].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));

}
if (value == 4)
{
Bank = parseInt(3); 

for(s in LpLoadInternal)
    s.set("items", sorted[3].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));
LoadAllInternal.set("items", sorted[3].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));

}

if (value == 5)
{
Bank = parseInt(4); 

for(s in LpLoadInternal)
    s.set("items", sorted[4].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));
LoadAllInternal.set("items", sorted[4].join("\n").replace(".wav").replace(".aif").replace(".aiff").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("MODULAR"));

}



};

Content.getComponent("LpBank1").setControlCallback(onLpBank1Control);






inline function onLoadAllInternalControl(component, value)
{
for(s in LpLoadInternal)
    s.setValue(value);
for(s in LpLoadInternal)
    s.changed();
};

Content.getComponent("LoadAllInternal").setControlCallback(onLoadAllInternalControl);

const var User1 = Synth.getAudioSampleProcessor("User1");
const var User2 = Synth.getAudioSampleProcessor("User2");
const var User3 = Synth.getAudioSampleProcessor("User3");
const var User4 = Synth.getAudioSampleProcessor("User4");
const var User5 = Synth.getAudioSampleProcessor("User5");
const var User6 = Synth.getAudioSampleProcessor("User6");
const var User7 = Synth.getAudioSampleProcessor("User7");
const var User8 = Synth.getAudioSampleProcessor("User8");

const var LpPath1 = Content.getComponent("LpPath1");
const var LpPath2 = Content.getComponent("LpPath2");
const var LpPath3 = Content.getComponent("LpPath3");
const var LpPath4 = Content.getComponent("LpPath4");
const var LpPath5 = Content.getComponent("LpPath5");
const var LpPath6 = Content.getComponent("LpPath6");
const var LpPath7 = Content.getComponent("LpPath7");
const var LpPath8 = Content.getComponent("LpPath8");


const var LpLoad1 = Content.getComponent("LpLoad1");
const var LpLoad2 = Content.getComponent("LpLoad2");
const var LpLoad3 = Content.getComponent("LpLoad3");
const var LpLoad4 = Content.getComponent("LpLoad4");
const var LpLoad5 = Content.getComponent("LpLoad5");
const var LpLoad6 = Content.getComponent("LpLoad6");
const var LpLoad7 = Content.getComponent("LpLoad7");
const var LpLoad8 = Content.getComponent("LpLoad8");


const var UserLoopers =[];

for (i = 0; i < 8; i++)
{
    UserLoopers[i] = Synth.getAudioSampleProcessor("User"+(i+1));

}




///// Loop Player Internal


//Store folder path

const FolderPath = [];

// Choose a folder to load samples from. 

inline function onFolderSelectControl(component, value) {

//Select a folder

if (value == 1)

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
            
         LpPath1.set("items", folderArray.join("\n"));
         LpLoad1.set("items", folderArray2.join("\n"));
         LpPath2.set("items", folderArray.join("\n"));
         LpLoad2.set("items", folderArray2.join("\n"));
         LpPath3.set("items", folderArray.join("\n"));
         LpLoad3.set("items", folderArray2.join("\n"));
 		 LpPath4.set("items", folderArray.join("\n"));
         LpLoad4.set("items", folderArray2.join("\n"));
         LpPath5.set("items", folderArray.join("\n"));
         LpLoad5.set("items", folderArray2.join("\n"));    
		 LpPath6.set("items", folderArray.join("\n"));
         LpLoad6.set("items", folderArray2.join("\n"));
 		 LpPath7.set("items", folderArray.join("\n"));
         LpLoad7.set("items", folderArray2.join("\n"));
         LpPath8.set("items", folderArray.join("\n"));
         LpLoad8.set("items", folderArray2.join("\n"));      
          LoadAllUser.set("items", folderArray2.join("\n")); 
         
}

        }
    });
};

Content.getComponent("FolderSelect").setControlCallback(onFolderSelectControl);

//Loads the samples


inline function onLpPath1Control(component, value)
{
	   User1.setFile(LpPath1.get("items").split("\n")[value - 1]);
	   SampleUserLabel[0].set("text", LpLoad1.get("items").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("Modular").replace(".wav").replace(".aif").replace(".aiff").split("\n")[value-1]);
	   for(s in Roots)
	       s.setValue(64);
	       for(s in Roots)
	           s.changed();
	  
};

Content.getComponent("LpPath1").setControlCallback(onLpPath1Control);


inline function onLpLoad1Control(component, value)
{
	LpPath1.setValue(value);
	LpPath1.changed();
};

Content.getComponent("LpLoad1").setControlCallback(onLpLoad1Control);

inline function onLpPath2Control(component, value)
{
	   User2.setFile(LpPath2.get("items").split("\n")[value - 1]);
	   SampleUserLabel[1].set("text", LpLoad2.get("items").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("Modular").replace(".wav").replace(".aif").replace(".aiff").split("\n")[value-1]);
	for(s in Roots)
    s.setValue(64);
    for(s in Roots)
        s.changed();
	  
};

Content.getComponent("LpPath2").setControlCallback(onLpPath2Control);


inline function onLpLoad2Control(component, value)
{
	LpPath2.setValue(value);
	LpPath2.changed();
};

Content.getComponent("LpLoad2").setControlCallback(onLpLoad2Control);

inline function onLpPath3Control(component, value)
{
	   User3.setFile(LpPath3.get("items").split("\n")[value - 1]);
	   SampleUserLabel[2].set("text", LpLoad3.get("items").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("Modular").replace(".wav").replace(".aif").replace(".aiff").split("\n")[value-1]);
	for(s in Roots)
    s.setValue(64);
    for(s in Roots)
        s.changed();
	  
};

Content.getComponent("LpPath3").setControlCallback(onLpPath3Control);


inline function onLpLoad3Control(component, value)
{
	LpPath3.setValue(value);
	LpPath3.changed();
};

Content.getComponent("LpLoad3").setControlCallback(onLpLoad3Control);

inline function onLpPath4Control(component, value)
{
	   User4.setFile(LpPath4.get("items").split("\n")[value - 1]);
	   SampleUserLabel[3].set("text", LpLoad4.get("items").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 4").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("Modular").replace(".wav").replace(".aif").replace(".aiff").split("\n")[value-1]);
	for(s in Roots)
    s.setValue(64);
    for(s in Roots)
        s.changed();
	  
};

Content.getComponent("LpPath4").setControlCallback(onLpPath4Control);


inline function onLpLoad4Control(component, value)
{
	LpPath4.setValue(value);
	LpPath4.changed();
};

Content.getComponent("LpLoad4").setControlCallback(onLpLoad4Control);

inline function onLpPath5Control(component, value)
{
	   User5.setFile(LpPath5.get("items").split("\n")[value - 1]);
	   SampleUserLabel[4].set("text", LpLoad5.get("items").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 5").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("Modular").replace(".wav").replace(".aif").replace(".aiff").split("\n")[value-1]);
	for(s in Roots)
    s.setValue(64);
    for(s in Roots)
        s.changed();
	  
};

Content.getComponent("LpPath5").setControlCallback(onLpPath5Control);


inline function onLpLoad5Control(component, value)
{
	LpPath5.setValue(value);
	LpPath5.changed();
};

Content.getComponent("LpLoad5").setControlCallback(onLpLoad5Control);

inline function onLpPath6Control(component, value)
{
	   User6.setFile(LpPath6.get("items").split("\n")[value - 1]);
	   SampleUserLabel[5].set("text", LpLoad6.get("items").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 6").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("Modular").replace(".wav").replace(".aif").replace(".aiff").split("\n")[value-1]);
	for(s in Roots)
    s.setValue(64);
    for(s in Roots)
        s.changed();
	  
};

Content.getComponent("LpPath6").setControlCallback(onLpPath6Control);


inline function onLpLoad6Control(component, value)
{
	LpPath6.setValue(value);
	LpPath6.changed();
};

Content.getComponent("LpLoad6").setControlCallback(onLpLoad6Control);

inline function onLpPath7Control(component, value)
{
	   User7.setFile(LpPath7.get("items").split("\n")[value - 1]);
	   SampleUserLabel[6].set("text", LpLoad7.get("items").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 7").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("Modular").replace(".wav").replace(".aif").replace(".aiff").split("\n")[value-1]);
	for(s in Roots)
    s.setValue(64);
    for(s in Roots)
        s.changed();
	  
};

Content.getComponent("LpPath7").setControlCallback(onLpPath7Control);


inline function onLpLoad7Control(component, value)
{
	LpPath7.setValue(value);
	LpPath7.changed();
};

Content.getComponent("LpLoad7").setControlCallback(onLpLoad7Control);

inline function onLpPath8Control(component, value)
{
	   User8.setFile(LpPath8.get("items").split("\n")[value - 1]);
	   SampleUserLabel[7].set("text", LpLoad8.get("items").replace("DronesChords").replace("SingleCycle").replace("/").replace("Jupiter 8").replace("XPFM_").replace("XPMisc_").replace("Misc").replace("AkaiAX80").replace("Modular").replace(".wav").replace(".aif").replace(".aiff").split("\n")[value-1]);
	  	for(s in Roots)
    s.setValue(64);
    for(s in Roots)
        s.changed();
	  
};

Content.getComponent("LpPath8").setControlCallback(onLpPath8Control);


inline function onLpLoad8Control(component, value)
{
	LpPath8.setValue(value);
	LpPath8.changed();
};

Content.getComponent("LpLoad8").setControlCallback(onLpLoad8Control);




inline function onLoadAllUserControl(component, value)
{
	LpPath1.setValue(value);
	LpPath1.changed();
	LpPath2.setValue(value);
	LpPath2.changed();
	LpPath3.setValue(value);
	LpPath3.changed();
	LpPath4.setValue(value);
	LpPath4.changed();
	LpPath5.setValue(value);
	LpPath5.changed();
	LpPath6.setValue(value);
	LpPath6.changed();
	LpPath7.setValue(value);
	LpPath7.changed();
	LpPath8.setValue(value);
	LpPath8.changed();
	LpLoad1.setValue(value);
	LpLoad2.setValue(value);
	LpLoad3.setValue(value);
	LpLoad4.setValue(value);
	LpLoad5.setValue(value);
	LpLoad6.setValue(value);
	LpLoad7.setValue(value);
	LpLoad8.setValue(value);
	
};

Content.getComponent("LoadAllUser").setControlCallback(onLoadAllUserControl);












