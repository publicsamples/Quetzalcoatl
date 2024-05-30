Content.makeFrontInterface(600, 600);

const var AudioLoopPlayer1 = Synth.getChildSynth("Audio Loop Player1");
const var Loop1 = Synth.getAudioSampleProcessor("Audio Loop Player1");
const var FileSelect = Content.getComponent("FileSelect");


 const var Viewport1 = Content.getComponent("Viewport1");
 


 
 //select folder
    

    inline function onFolderSelectControl(component, value)
    {
      
  FileSystem.browseForDirectory(FileSystem.Downloads, function(folder)
		{
		   if(isDefined(folder) && folder.isDirectory())
				{			
				  var folderArray = FileSystem.findFiles(folder, "*.wav", false);
				  	
	              for(file in folderArray)
	              	{
		              	file = file.toString(1);  
	              	}; 
	              Viewport1.set("items", folderArray.join("\n"));
	              FileSelect.set("items", folderArray.join("\n"));
				}	
		});		
};
    
    Content.getComponent("FolderSelect").setControlCallback(onFolderSelectControl);
    
    
    inline function onFileSelectControl(component, value)
    {
    Loop1.setFile(FileSelect.get("items").split("\n")[value-1]);
    };
    
    Content.getComponent("FileSelect").setControlCallback(onFileSelectControl);
    
    

    
    inline function onViewport1Control(component, value)
    {
    	//Add your custom logic here...
    };
    
    Content.getComponent("Viewport1").setControlCallback(onViewport1Control);
    
  
 
    

 
 // This loads all files from the project folder and returns a list of references
 

 


   
    
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
 