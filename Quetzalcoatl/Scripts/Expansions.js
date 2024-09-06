const var expHandler = Engine.createExpansionHandler();
const var expansions = expHandler.getExpansionList();

const var ExpansionSelector = Content.getComponent("ExpansionSelector");
const var ExpansionSelector2 = Content.getComponent("ExpansionSelector2");
const var ExpansionSelector3 = Content.getComponent("ExpansionSelector3");

expHandler.setAllowedExpansionTypes([expHandler.FileBased, 
                                     expHandler.Intermediate, 
                                     expHandler.Encrypted]);

                                     
const var expansionNames = [];

expansionNames.push("FACTORY");

for(e in expHandler.getExpansionList())
    expansionNames.push(e.getProperties().Name);

ExpansionSelector.set("items", expansionNames.join("\n"));
ExpansionSelector2.set("items", expansionNames.join("\n"));



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

inline function onExpansionSelectorControl(component, value)
{
	local expansionToLoad = component.getItemText();
	

	if(expansionToLoad == expansionNames[0])
        expansionToLoad = "";
    
	expHandler.setCurrentExpansion(expansionToLoad);
	
	
		ExpansionSelector2.setValue(value);
		ExpansionSelector3.setValue(value);
	
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

inline function newcombobox(newExpansion)
{

       if(isDefined(newExpansion))
        
       
    {
        local cx = expHandler.getCurrentExpansion();
        
        
        sampleMaps = cx.getSampleMapList();
        sampleMapsed = cx.getSampleMapList();

        local expansionProps = cx.getProperties();
        local expName = expansionProps.Name;
        
        
        for (i = 0; i < sampleMapsed.length; i++)
        {
        sampleMapsed[i] = sampleMapsed[i].replace("{EXP::");
       sampleMapsed[i] = sampleMapsed[i].replace("}");
       sampleMapsed[i] = sampleMapsed[i].replace(expName);

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
    }
    
    else
    
    {
	

        sampleMaps = Sampler.getSampleMapList();
        

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

    }
    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);