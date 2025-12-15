const var Sz1 = Synth.getSampler("Sfz1");
const var Sz2 = Synth.getSampler("Sfz2");
const var Sz3 = Synth.getSampler("Sfz3");
const var Sz4 = Synth.getSampler("Sfz4");
const var Sz5 = Synth.getSampler("Sfz5");
const var Sz6 = Synth.getSampler("Sfz6");
const var Sz7 = Synth.getSampler("Sfz7");
const var Sz8 = Synth.getSampler("Sfz8");


const var Sfz1 = Synth.getChildSynth("Sfz1");
const var Sfz2 = Synth.getChildSynth("Sfz2");
const var Sfz3 = Synth.getChildSynth("Sfz3");
const var Sfz4 = Synth.getChildSynth("Sfz4");
const var Sfz5 = Synth.getChildSynth("Sfz5");
const var Sfz6 = Synth.getChildSynth("Sfz6");
const var Sfz7 = Synth.getChildSynth("Sfz7");
const var Sfz8 = Synth.getChildSynth("Sfz8");

const var SfzLoad1 = Content.getComponent("SfzLoad1");

const var LabelsSfz1 = [];

LabelsSfz1[0] = Content.getComponent("SfzLabelStore1");
LabelsSfz1[1] = Content.getComponent("SfzLabelStore2");
LabelsSfz1[2] = Content.getComponent("SfzLabelStore3");
LabelsSfz1[3] = Content.getComponent("SfzLabelStore4");
LabelsSfz1[4] = Content.getComponent("SfzLabelStore5");
LabelsSfz1[5] = Content.getComponent("SfzLabelStore6");
LabelsSfz1[6] = Content.getComponent("SfzLabelStore7");
LabelsSfz1[7] = Content.getComponent("SfzLabelStore8");

const var Sf1 = Synth.getSampler("Sfz1");
const var Sf2 = Synth.getSampler("Sfz2");
const var Sf3 = Synth.getSampler("Sfz3");
const var Sf4 = Synth.getSampler("Sfz4");
const var Sf5 = Synth.getSampler("Sfz5");
const var Sf6 = Synth.getSampler("Sfz6");
const var Sf7 = Synth.getSampler("Sfz7");
const var Sf8 = Synth.getSampler("Sfz8");

///SFZ
const var SampleSfz1 = Content.getComponent("SampleSfz1");
const var SampleSfz2 = Content.getComponent("SampleSfz2");
const var SampleSfz3 = Content.getComponent("SampleSfz3");
const var SampleSfz4 = Content.getComponent("SampleSfz4");
const var SampleSfz5 = Content.getComponent("SampleSfz5");
const var SampleSfz6 = Content.getComponent("SampleSfz6");
const var SampleSfz7 = Content.getComponent("SampleSfz7");
const var SampleSfz8 = Content.getComponent("SampleSfz8");

const var SfzLabelStore1 = Content.getComponent("SfzLabelStore1");
const var SfzLabelStore2 = Content.getComponent("SfzLabelStore2");
const var SfzLabelStore3 = Content.getComponent("SfzLabelStore3");
const var SfzLabelStore4 = Content.getComponent("SfzLabelStore4");
const var SfzLabelStore5 = Content.getComponent("SfzLabelStore5");
const var SfzLabelStore6 = Content.getComponent("SfzLabelStore6");
const var SfzLabelStore7 = Content.getComponent("SfzLabelStore7");
const var SfzLabelStore8 = Content.getComponent("SfzLabelStore8");


Sf1.loadSfzFile(SfzLabelStore1.get("text"));
Sf2.loadSfzFile(SfzLabelStore2.get("text"));
Sf3.loadSfzFile(SfzLabelStore3.get("text"));
Sf4.loadSfzFile(SfzLabelStore4.get("text"));
Sf5.loadSfzFile(SfzLabelStore5.get("text"));
Sf6.loadSfzFile(SfzLabelStore6.get("text"));
Sf7.loadSfzFile(SfzLabelStore7.get("text"));
Sf8.loadSfzFile(SfzLabelStore8.get("text"));





inline function onSfzLabelStore1Control(component, value)
{
	
Sf1.loadSfzFile(value);
};

Content.getComponent("SfzLabelStore1").setControlCallback(onSfzLabelStore1Control);


    inline function onSfzLabelStore2Control(component, value)
    {
    	
    Sf2.loadSfzFile(value);
    };
    
    Content.getComponent("SfzLabelStore2").setControlCallback(onSfzLabelStore2Control);
    
    
    	
  
  inline function onSfzLabelStore3Control(component, value)
  {
  	
  Sf3.loadSfzFile(value);
  };
  
  Content.getComponent("SfzLabelStore3").setControlCallback(onSfzLabelStore3Control);
  
  
  
  
      
      inline function onSfzLabelStore4Control(component, value)
      {
      	
      Sf4.loadSfzFile(value);
      };
      
      Content.getComponent("SfzLabelStore4").setControlCallback(onSfzLabelStore4Control);
      
     
    
       inline function onSfzLabelStore5Control(component, value)
       {
       	
       Sf5.loadSfzFile(value);
       };
       
       Content.getComponent("SfzLabelStore5").setControlCallback(onSfzLabelStore5Control);
       
       
    	   
    	   inline function onSfzLabelStore6Control(component, value)
    	   {
    	   	
    	   Sf6.loadSfzFile(value);
    	   };
    	   
    	   Content.getComponent("SfzLabelStore6").setControlCallback(onSfzLabelStore6Control);
    	   
    	   
     
           inline function onSfzLabelStore7Control(component, value)
           {
           	
           Sf7.loadSfzFile(value);
           };
           
           Content.getComponent("SfzLabelStore7").setControlCallback(onSfzLabelStore7Control);
           
           
    	  
          inline function onSfzLabelStore8Control(component, value)
          {
          	
          Sf8.loadSfzFile(value);
          };
          
          Content.getComponent("SfzLabelStore8").setControlCallback(onSfzLabelStore8Control);
          
          
          const var FolderLabel = Content.getComponent("FolderLabel");
          
        
        
        //Store folder path
        
      
        
        const var SfzPath1 = Content.getComponent("SfzPath1");
        const var SfzPath2 = Content.getComponent("SfzPath2");
        const var SfzPath3 = Content.getComponent("SfzPath3");
        const var SfzPath4 = Content.getComponent("SfzPath4");
        const var SfzPath5 = Content.getComponent("SfzPath5");
        const var SfzPath6 = Content.getComponent("SfzPath6");
        const var SfzPath7 = Content.getComponent("SfzPath7");
        const var SfzPath8 = Content.getComponent("SfzPath8");
        
        const var SfzLoadMenu1 = Content.getComponent("SfzLoadMenu1");
        const var SfzLoadMenu2 = Content.getComponent("SfzLoadMenu2");
        const var SfzLoadMenu3 = Content.getComponent("SfzLoadMenu3");
        const var SfzLoadMenu4 = Content.getComponent("SfzLoadMenu4");
        const var SfzLoadMenu5 = Content.getComponent("SfzLoadMenu5");
        const var SfzLoadMenu6 = Content.getComponent("SfzLoadMenu6");
        const var SfzLoadMenu7 = Content.getComponent("SfzLoadMenu7");
        const var SfzLoadMenu8 = Content.getComponent("SfzLoadMenu8");
        
        
        const var SampleSfzFolder = Content.getComponent("SampleSfzFolder");
        
 
//Store folder path
  const FolderPathSfz = [];

// Choose a folder to load samples from. 

inline function onFolderSelectSfzControl(component, value) {

//Select a folder

if (value == 1)

    FileSystem.browseForDirectory(FileSystem.Downloads, function(folder) {
        if (isDefined(folder) && folder.isDirectory()) {
         
         //find files in selected folder
         
            var folderArray = FileSystem.findFiles(folder, "*.sfz", false);

            for (file in folderArray) {
                file = file.toString(0);
                
                var folderArray2 = FileSystem.findFiles(folder, "*.sfz", false);
                            
                            for (file1 in folderArray2) {
                                        file1 = file1.toString(3);        
                
         //Populate the Folder Label
              
              	
                SampleSfzFolder.set("text", folder.toString(0));
                FolderPathSfz.push(folder);
              
            };
            
            
            
            //send items to hidden ComboBox
            
         SfzPath1.set("items", folderArray.join("\n"));
        SfzPath2.set("items", folderArray.join("\n"));
        SfzPath3.set("items", folderArray.join("\n"));
        SfzPath4.set("items", folderArray.join("\n"));
        SfzPath5.set("items", folderArray.join("\n"));
        SfzPath6.set("items", folderArray.join("\n"));
        SfzPath7.set("items", folderArray.join("\n"));
        SfzPath8.set("items", folderArray.join("\n"));
         SfzLoadMenu1.set("items", folderArray2.join("\n").replace(".sfz"));
       SfzLoadMenu2.set("items", folderArray2.join("\n").replace(".sfz"));
       SfzLoadMenu3.set("items", folderArray2.join("\n").replace(".sfz"));
       SfzLoadMenu4.set("items", folderArray2.join("\n").replace(".sfz"));
       SfzLoadMenu5.set("items", folderArray2.join("\n").replace(".sfz"));
       SfzLoadMenu6.set("items", folderArray2.join("\n").replace(".sfz"));
       SfzLoadMenu7.set("items", folderArray2.join("\n").replace(".sfz"));
       SfzLoadMenu8.set("items", folderArray2.join("\n").replace(".sfz"));
       LoadAllUserSf.set("items", folderArray2.join("\n").replace(".sfz"));
}

        }
    });
};

Content.getComponent("FolderSelectSfz").setControlCallback(onFolderSelectSfzControl);


inline function onSfzPath1Control(component, value)

{
	
	Sf1.loadSfzFile(SfzPath1.get("items").split("\n")[value - 1]);
	 LabelsSfz1[0].set("text", SfzLoadMenu1.get("items").replace(".sfz").split("\n")[value-1]);
	SampleSfz1.set("text", SfzLoadMenu1.get("items").replace(".sfz").split("\n")[value-1]);
	
};

Content.getComponent("SfzPath1").setControlCallback(onSfzPath1Control);


inline function onSfzPath2Control(component, value)

{
	
	Sf2.loadSfzFile(SfzPath2.get("items").split("\n")[value - 1]);
	 LabelsSfz1[1].set("text", SfzLoadMenu2.get("items").replace(".sfz").split("\n")[value-1]);
	SampleSfz2.set("text", SfzLoadMenu2.get("items").replace(".sfz").split("\n")[value-1]);
	
};

Content.getComponent("SfzPath2").setControlCallback(onSfzPath2Control);
   
inline function onSfzPath3Control(component, value)

{
	
	Sf3.loadSfzFile(SfzPath3.get("items").split("\n")[value - 1]);
	 LabelsSfz1[2].set("text", SfzLoadMenu3.get("items").replace(".sfz").split("\n")[value-1]);
	SampleSfz3.set("text", SfzLoadMenu3.get("items").replace(".sfz").split("\n")[value-1]);
	
};

Content.getComponent("SfzPath3").setControlCallback(onSfzPath3Control);
 
 inline function onSfzPath4Control(component, value)
 
 {
 	
 	Sf4.loadSfzFile(SfzPath4.get("items").split("\n")[value - 1]);
 	 LabelsSfz1[3].set("text", SfzLoadMenu4.get("items").replace(".sfz").split("\n")[value-1]);
 	SampleSfz4.set("text", SfzLoadMenu4.get("items").replace(".sfz").split("\n")[value-1]);
 	
 };
 
 Content.getComponent("SfzPath4").setControlCallback(onSfzPath4Control);
   
inline function onSfzPath5Control(component, value)

{
	
	Sf5.loadSfzFile(SfzPath5.get("items").split("\n")[value - 1]);
	 LabelsSfz1[4].set("text", SfzLoadMenu5.get("items").replace(".sfz").split("\n")[value-1]);
	SampleSfz5.set("text", SfzLoadMenu5.get("items").replace(".sfz").split("\n")[value-1]);
	
};

Content.getComponent("SfzPath5").setControlCallback(onSfzPath5Control);
                
inline function onSfzPath6Control(component, value)

{
	
	Sf6.loadSfzFile(SfzPath6.get("items").split("\n")[value - 1]);
	 LabelsSfz1[5].set("text", SfzLoadMenu6.get("items").replace(".sfz").split("\n")[value-1]);
	SampleSfz6.set("text", SfzLoadMenu6.get("items").replace(".sfz").split("\n")[value-1]);
	
};

Content.getComponent("SfzPath6").setControlCallback(onSfzPath6Control);

inline function onSfzPath7Control(component, value)

{
	
	Sf7.loadSfzFile(SfzPath7.get("items").split("\n")[value - 1]);
	 LabelsSfz1[6].set("text", SfzLoadMenu7.get("items").replace(".sfz").split("\n")[value-1]);
	SampleSfz7.set("text", SfzLoadMenu7.get("items").replace(".sfz").split("\n")[value-1]);
	
};

Content.getComponent("SfzPath7").setControlCallback(onSfzPath7Control);

inline function onSfzPath8Control(component, value)

{
	
	Sf8.loadSfzFile(SfzPath8.get("items").split("\n")[value - 1]);
	 LabelsSfz1[7].set("text", SfzLoadMenu8.get("items").replace(".sfz").split("\n")[value-1]);
	SampleSfz8.set("text", SfzLoadMenu8.get("items").replace(".sfz").split("\n")[value-1]);
	
};

Content.getComponent("SfzPath8").setControlCallback(onSfzPath8Control);
               
    
  
  
  inline function onSfzLoadMenu1Control(component, value)
  {
  	SfzPath1.setValue(value);
  	SfzPath1.changed();
  };
  
  Content.getComponent("SfzLoadMenu1").setControlCallback(onSfzLoadMenu1Control);
  
  inline function onSfzLoadMenu2Control(component, value)
  {
  	SfzPath2.setValue(value);
  	SfzPath2.changed();
  };
  
  Content.getComponent("SfzLoadMenu2").setControlCallback(onSfzLoadMenu2Control);
  
  inline function onSfzLoadMenu3Control(component, value)
   {
   	SfzPath3.setValue(value);
   	SfzPath3.changed();
   };
   
   Content.getComponent("SfzLoadMenu3").setControlCallback(onSfzLoadMenu3Control);
   
   inline function onSfzLoadMenu4Control(component, value)
     {
     	SfzPath4.setValue(value);
     	SfzPath4.changed();
     };
     
     Content.getComponent("SfzLoadMenu4").setControlCallback(onSfzLoadMenu4Control);
  
  inline function onSfzLoadMenu5Control(component, value)
      {
      	SfzPath5.setValue(value);
      	SfzPath5.changed();
      };
      
      Content.getComponent("SfzLoadMenu5").setControlCallback(onSfzLoadMenu5Control);
    
    inline function onSfzLoadMenu6Control(component, value)
        {
        	SfzPath6.setValue(value);
        	SfzPath6.changed();
        };
        
        Content.getComponent("SfzLoadMenu6").setControlCallback(onSfzLoadMenu6Control);
      
      inline function onSfzLoadMenu7Control(component, value)
          {
          	SfzPath7.setValue(value);
          	SfzPath7.changed();
          };
          
          Content.getComponent("SfzLoadMenu7").setControlCallback(onSfzLoadMenu7Control);
        
        
              inline function onSfzLoadMenu8Control(component, value)
                  {
                  	SfzPath8.setValue(value);
                  	SfzPath8.changed();
                  };
                  
                  Content.getComponent("SfzLoadMenu8").setControlCallback(onSfzLoadMenu8Control);
                
                

inline function onLoadAllUserSfControl(component, value)
{
	SfzPath1.setValue(value);
	SfzPath1.changed();
	SfzPath2.setValue(value);
	SfzPath2.changed();
	SfzPath3.setValue(value);
	SfzPath3.changed();
	SfzPath4.setValue(value);
	SfzPath4.changed();
	SfzPath5.setValue(value);
	SfzPath5.changed();
	SfzPath6.setValue(value);
	SfzPath6.changed();
	SfzPath7.setValue(value);
	SfzPath7.changed();
	SfzPath8.setValue(value);
	SfzPath8.changed();
	SfzLoadMenu1.setValue(value);
	SfzLoadMenu2.setValue(value);
	SfzLoadMenu3.setValue(value);
	SfzLoadMenu4.setValue(value);
	SfzLoadMenu5.setValue(value);
	SfzLoadMenu6.setValue(value);
	SfzLoadMenu7.setValue(value);
	SfzLoadMenu8.setValue(value);
};

Content.getComponent("LoadAllUserSf").setControlCallback(onLoadAllUserSfControl);

  