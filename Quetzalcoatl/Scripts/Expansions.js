const var expHandler = Engine.createExpansionHandler();
const var expansions = expHandler.getExpansionList();
const var expansionList = expHandler.getExpansionList();
const var ExpAudio = expHandler.getExpansionList();


const var WtAll = Content.getComponent("WtAll");

const var WtBanks = [Content.getComponent("WtLoad1"),
                     Content.getComponent("WtLoad2"),
                     Content.getComponent("WtLoad3"),
                     Content.getComponent("WtLoad4"),
                     Content.getComponent("WtLoad5"),
                     Content.getComponent("WtLoad6"),
                     Content.getComponent("WtLoad7"),
                     Content.getComponent("WtLoad8")];

const var LpAllBanks = [Content.getComponent("LpLoadInt1"),
                   Content.getComponent("LpLoadInt2"),
                   Content.getComponent("LpLoadInt3"),
                   Content.getComponent("LpLoadInt4"),
                   Content.getComponent("LpLoadInt5"),
                   Content.getComponent("LpLoadInt6"),
                   Content.getComponent("LpLoadInt7"),
                   Content.getComponent("LpLoadInt8")];

const var LoadAllInternals = Content.getComponent("LoadAllInternal");




       inline function onExpansionSelectorControl(component, value)
       {
       	local expansionToLoad = component.getItemText();
       	
       
       
       	if(expansionToLoad == expansionNames[0])
               expansionToLoad = "";
           
       	expHandler.setCurrentExpansion(expansionToLoad);
       	
       	
       		ExpansionSelector2.setValue(value);
       		
       		expansionList.getAudioFileList();
       
       	
       };
       
       Content.getComponent("ExpansionSelector").setControlCallback(onExpansionSelectorControl);
       
       

const var ExpansionSelector = Content.getComponent("ExpansionSelector");
const var ExpansionSelector2 = Content.getComponent("ExpansionSelector2");


expHandler.setAllowedExpansionTypes([expHandler.FileBased, 
                                     expHandler.Intermediate, 
                                     expHandler.Encrypted]);

                                     


inline function onLoadExpControl(component, value)
{
   FileSystem.browse(FileSystem.Downloads, false, "*.hr1", function(result)
	{
		if(isDefined(result) && result.isFile())
		{
			var expNameInstall = expHandler.getExpansionForInstallPackage(result).getProperties().Name;
			expHandler.installExpansionFromPackage(result, FileSystem.Samples);

		};
	});

};

Content.getComponent("LoadExp").setControlCallback(onLoadExpControl);

const var expansionNames = [];

expansionNames.push("Factory");

for(e in expHandler.getExpansionList())
    expansionNames.push(e.getProperties().Name);

ExpansionSelector.set("items", expansionNames.join("\n"));
ExpansionSelector2.set("items", expansionNames.join("\n"));



inline function onExpansionSelectorControl(component, value)
{
	local expansionToLoad = component.getItemText();
	

	if(expansionToLoad == expansionNames[0])
        expansionToLoad = "";
    
	expHandler.setCurrentExpansion(expansionToLoad);
	
	
		ExpansionSelector2.setValue(value);

	
};

Content.getComponent("ExpansionSelector").setControlCallback(onExpansionSelectorControl);

inline function onExpansionSelector2Control(component, value)
{
	
	ExpansionSelector.setValue(value);
	ExpansionSelector2.setValue(value);
	ExpansionSelector.changed();
};

Content.getComponent("ExpansionSelector2").setControlCallback(onExpansionSelector2Control);



 
var sampleMaps = Sampler.getSampleMapList();
var sampleMapsed = Sampler.getSampleMapList();

var wtList = Engine.getWavetableList();
var wtListed = Engine.getWavetableList();



inline function newcombobox(newExpansion)
{

       if(isDefined(newExpansion))
        
       
    {
        local cx = expHandler.getCurrentExpansion();
        
     ///   local ex = expHandler.getSampleMapList();
        sampleMaps = cx.getSampleMapList();
        sampleMapsed = cx.getSampleMapList();
        
       
     
   //   wtList = cx.getWavetableList();
    //    wtListed = cx.getWavetableList();

        local expansionProps = cx.getProperties();
        local expName = expansionProps.Name;
        
  
        
        for (i = 0; i < sampleMapsed.length; i++)
               {
               sampleMapsed[i] = sampleMapsed[i].replace("{EXP::");
              sampleMapsed[i] = sampleMapsed[i].replace("}");
              sampleMapsed[i] = sampleMapsed[i].replace(expName);
        
               }
        
        for (i = 0; i < wtListed.length; i++)
               {
               wtListed[i] = wtListed[i].replace("{EXP::");
              wtListed[i] = wtListed[i].replace("}");
			 wtListed[i] = wtListed[i].replace(expName);
        
               }
        
 

        BankA1.set("items", "");
        BankA1.set("items", sampleMapsed.join("\n"));
        BankA2.set("items", "");
       	BankA2.set("items", sampleMapsed.join("\n"));
       	BankA3.set("items", "");
       	BankA3.set("items", sampleMapsed.join("\n"));
        BankA4.set("items", "");
      	BankA4.set("items", sampleMapsed.join("\n"));
      	BankA5.set("items", "");
      	BankA5.set("items", sampleMapsed.join("\n"));
      	BankA6.set("items", "");
      	BankA6.set("items", sampleMapsed.join("\n"));
      	BankA7.set("items", "");
      	BankA7.set("items", sampleMapsed.join("\n"));
      	BankA8.set("items", "");
        BankA8.set("items", sampleMapsed.join("\n"));
		BankA11.set("items", "");
        BankA11.set("items", sampleMapsed.join("\n"));  
          
     	WtAll.set("items", Engine.getWavetableList().join("\n").replace("Fac_"));
   		for(s in WtBanks) s.set("items", Engine.getWavetableList().join("\n"));
      
   }
    
    else
    
    {
	

        sampleMaps = Sampler.getSampleMapList();
        
     //   wtList = Engine.getWavetableList();
        

        BankA1.set("items", "");
        BankA1.set("items", sampleMaps.join("\n"));
        BankA2.set("items", "");
       	BankA2.set("items", sampleMaps.join("\n"));
       	BankA3.set("items", "");
       	BankA3.set("items", sampleMaps.join("\n"));
        BankA4.set("items", "");
      	BankA4.set("items", sampleMaps.join("\n"));
      	BankA5.set("items", "");
      	BankA5.set("items", sampleMaps.join("\n"));
      	BankA6.set("items", "");
      	BankA6.set("items", sampleMaps.join("\n"));
      	BankA7.set("items", "");
      	BankA7.set("items", sampleMaps.join("\n"));
      	BankA8.set("items", "");
        BankA8.set("items", sampleMaps.join("\n"));
 	    BankA11.set("items", "");
        BankA11.set("items", sampleMaps.join("\n"));     
        
   	WtAll.set("items", Engine.getWavetableList().join("\n").replace("Fac_"));
   	for(s in WtBanks) s.set("items",  Engine.getWavetableList().join("\n").replace("Fac_"));
   	
  
    }
    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);