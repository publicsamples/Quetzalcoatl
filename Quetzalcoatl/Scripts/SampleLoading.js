
const var BankA = Content.getComponent("BankA");
const var BankA2 = Content.getComponent("BankA2");
const var BankA3 = Content.getComponent("BankA3");
const var BankA4 = Content.getComponent("BankA4");
const var BankA5 = Content.getComponent("BankA5");
const var BankA6 = Content.getComponent("BankA6");
const var BankA7 = Content.getComponent("BankA7");
const var BankA8 = Content.getComponent("BankA8");
const var BankA9 = Content.getComponent("BankA9");

const var ExpansionSelector = Content.getComponent("ExpansionSelector");

const var expHandler = Engine.createExpansionHandler();

const var expansions = expHandler.getExpansionList();

expHandler.setAllowedExpansionTypes([expHandler.FileBased, 
                                     expHandler.Intermediate, 
                                     expHandler.Encrypted]);
                                     
const var expansionNames = [];

expansionNames.push("FACTORY");

for(e in expHandler.getExpansionList())
    expansionNames.push(e.getProperties().Name);

//const var ExpansionSelector = Content.getComponent("ExpansionSelector");
ExpansionSelector.set("items", expansionNames.join("\n"));

// Implement the expansion switch

inline function onExpansionSelectorControl(component, value)
{
	local expansionToLoad = component.getItemText();
	
	// We want the first item to reset the current expansion
	// so we need to change it to an empty string
	if(expansionToLoad == expansionNames[0])
        expansionToLoad = "";
    
	expHandler.setCurrentExpansion(expansionToLoad);
};

Content.getComponent("ExpansionSelector").setControlCallback(onExpansionSelectorControl);

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
       
        BankA.set("items", "");
        BankA.set("items", sampleMapsed.join("\n"));
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
       
       
       

    }
    
    else
    
    {
        sampleMaps = Sampler.getSampleMapList();
        BankA.set("items", "");
        BankA.set("items", sampleMaps.join("\n"));
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
        BankA9.set("items", "");
                BankA9.set("items", sampleMaps.join("\n"));
        

    }
    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);


inline function onBankAControl(component, value)
{

   Sampler1.loadSampleMap(sampleMaps[value-1]);
    Sampler10.loadSampleMap(sampleMaps[value-1]);
    Sampler19.loadSampleMap(sampleMaps[value-1]);
    Sampler28.loadSampleMap(sampleMaps[value-1]);
    Sampler37.loadSampleMap(sampleMaps[value-1]);
    Sampler46.loadSampleMap(sampleMaps[value-1]);
  
};

Content.getComponent("BankA").setControlCallback(onBankAControl);

inline function onBankA2Control(component, value)
{

   Sampler2.loadSampleMap(sampleMaps[value-1]);
    Sampler11.loadSampleMap(sampleMaps[value-1]);
    Sampler20.loadSampleMap(sampleMaps[value-1]);
    Sampler29.loadSampleMap(sampleMaps[value-1]);
    Sampler38.loadSampleMap(sampleMaps[value-1]);
    Sampler47.loadSampleMap(sampleMaps[value-1]);
  

};

Content.getComponent("BankA2").setControlCallback(onBankA2Control);

inline function onBankA3Control(component, value)
{

   Sampler3.loadSampleMap(sampleMaps[value-1]);
    Sampler12.loadSampleMap(sampleMaps[value-1]);
    Sampler21.loadSampleMap(sampleMaps[value-1]);
    Sampler30.loadSampleMap(sampleMaps[value-1]);
    Sampler39.loadSampleMap(sampleMaps[value-1]);
    Sampler48.loadSampleMap(sampleMaps[value-1]);
  

};

Content.getComponent("BankA3").setControlCallback(onBankA3Control);

inline function onBankA4Control(component, value)
{

   Sampler4.loadSampleMap(sampleMaps[value-1]);
    Sampler13.loadSampleMap(sampleMaps[value-1]);
    Sampler22.loadSampleMap(sampleMaps[value-1]);
    Sampler31.loadSampleMap(sampleMaps[value-1]);
    Sampler40.loadSampleMap(sampleMaps[value-1]);
    Sampler49.loadSampleMap(sampleMaps[value-1]);
  

};

Content.getComponent("BankA4").setControlCallback(onBankA4Control);

inline function onBankA5Control(component, value)
{

   Sampler5.loadSampleMap(sampleMaps[value-1]);
    Sampler14.loadSampleMap(sampleMaps[value-1]);
    Sampler23.loadSampleMap(sampleMaps[value-1]);
    Sampler32.loadSampleMap(sampleMaps[value-1]);
    Sampler41.loadSampleMap(sampleMaps[value-1]);
    Sampler50.loadSampleMap(sampleMaps[value-1]);
  

};

Content.getComponent("BankA5").setControlCallback(onBankA5Control);

inline function onBankA6Control(component, value)
{

   Sampler6.loadSampleMap(sampleMaps[value-1]);
    Sampler15.loadSampleMap(sampleMaps[value-1]);
    Sampler24.loadSampleMap(sampleMaps[value-1]);
    Sampler33.loadSampleMap(sampleMaps[value-1]);
    Sampler42.loadSampleMap(sampleMaps[value-1]);
    Sampler51.loadSampleMap(sampleMaps[value-1]);

};

Content.getComponent("BankA6").setControlCallback(onBankA6Control);

inline function onBankA7Control(component, value)
{

   Sampler7.loadSampleMap(sampleMaps[value-1]);
    Sampler16.loadSampleMap(sampleMaps[value-1]);
    Sampler25.loadSampleMap(sampleMaps[value-1]);
    Sampler34.loadSampleMap(sampleMaps[value-1]);
    Sampler43.loadSampleMap(sampleMaps[value-1]);
    Sampler52.loadSampleMap(sampleMaps[value-1]);
  

};

Content.getComponent("BankA7").setControlCallback(onBankA7Control);

inline function onBankA8Control(component, value)
{

   Sampler8.loadSampleMap(sampleMaps[value-1]);
    Sampler17.loadSampleMap(sampleMaps[value-1]);
    Sampler26.loadSampleMap(sampleMaps[value-1]);
    Sampler35.loadSampleMap(sampleMaps[value-1]);
    Sampler44.loadSampleMap(sampleMaps[value-1]);
    Sampler53.loadSampleMap(sampleMaps[value-1]);
  

};

Content.getComponent("BankA8").setControlCallback(onBankA8Control);

inline function onBankA9Control(component, value)
{

    Sampler9.loadSampleMap(sampleMaps[value-1]);
    Sampler18.loadSampleMap(sampleMaps[value-1]);
    Sampler27.loadSampleMap(sampleMaps[value-1]);
    Sampler36.loadSampleMap(sampleMaps[value-1]);
    Sampler45.loadSampleMap(sampleMaps[value-1]);
    Sampler54.loadSampleMap(sampleMaps[value-1]);
  

};

Content.getComponent("BankA9").setControlCallback(onBankA9Control);

//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
    g.setFont("Avenir", 16.0);
   
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});

laf.registerFunction("drawPresetBrowserListItem", function(g, obj)
{
    if(obj.selected)
    {
        g.setColour(0x22FFFFFF);
        g.fillRoundedRectangle(obj.area, 5.0);
        
       g.setFont("Avenir", 16.0);
    }
   
    g.setColour(obj.textColour);
    g.setFont("Avenir", 16.0);
    g.drawAlignedText(obj.text, obj.area, "centred");
});