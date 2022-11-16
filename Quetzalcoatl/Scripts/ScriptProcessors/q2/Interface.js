Content.makeFrontInterface(885, 745);

include("waves.js");
include("rr.js");
include("presets.js");

include("xfade.js");
include("FMandPitch.js");
include("Filter.js");
include("modulators.js");
include("osc2.js");
include("mod.js");


const var Shape = Content.getComponent("Shape");
const var Shape2 = Content.getComponent("Shape2");
const var Shape3 = Content.getComponent("Shape3");
const var Shape4 = Content.getComponent("Shape4");
const var Shape5 = Content.getComponent("Shape5");
const var Shape6 = Content.getComponent("Shape6");
const var Shape7 = Content.getComponent("Shape7");
const var Shape8 = Content.getComponent("Shape8");
const var Shape9 = Content.getComponent("Shape9");

const var ShapeLabel = Content.getComponent("ShapeLabel");
const var ShapeLabel2 = Content.getComponent("ShapeLabel2");
const var ShapeLabel3 = Content.getComponent("ShapeLabel3");
const var ShapeLabel4 = Content.getComponent("ShapeLabel4");
const var ShapeLabel5 = Content.getComponent("ShapeLabel5");
const var ShapeLabel6 = Content.getComponent("ShapeLabel6");
const var ShapeLabel7 = Content.getComponent("ShapeLabel7");
const var ShapeLabel8 = Content.getComponent("ShapeLabel8");
const var ShapeLabel9 = Content.getComponent("ShapeLabel9");

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
       
        Shape.set("items", "");
        Shape.set("items", sampleMapsed.join("\n"));
        Shape2.set("items", "");
       	Shape2.set("items", sampleMapsed.join("\n"));
       	Shape3.set("items", "");
       	Shape3.set("items", sampleMapsed.join("\n"));
        Shape4.set("items", "");
      	Shape4.set("items", sampleMapsed.join("\n"));
      	Shape5.set("items", "");
      	Shape5.set("items", sampleMapsed.join("\n"));
      	Shape6.set("items", "");
      	Shape6.set("items", sampleMapsed.join("\n"));
      	Shape7.set("items", "");
      	Shape7.set("items", sampleMapsed.join("\n"));
      	Shape8.set("items", "");
        Shape8.set("items", sampleMapsed.join("\n"));
       
       
       

    }
    
    else
    
    {
        sampleMaps = Sampler.getSampleMapList();
        Shape.set("items", "");
        Shape.set("items", sampleMaps.join("\n"));
        Shape2.set("items", "");
       	Shape2.set("items", sampleMaps.join("\n"));
       	Shape3.set("items", "");
       	Shape3.set("items", sampleMaps.join("\n"));
        Shape4.set("items", "");
      	Shape4.set("items", sampleMaps.join("\n"));
      	Shape5.set("items", "");
      	Shape5.set("items", sampleMaps.join("\n"));
      	Shape6.set("items", "");
      	Shape6.set("items", sampleMaps.join("\n"));
      	Shape7.set("items", "");
      	Shape7.set("items", sampleMaps.join("\n"));
      	Shape8.set("items", "");
        Shape8.set("items", sampleMaps.join("\n"));
        

    }
    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);


inline function onShapeControl(component, value)
{

   Sampler1.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler10.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler19.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler28.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler37.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler46.asSampler().loadSampleMap(sampleMaps[value-1]);
  ShapeLabel.set("text",Shape.get("items").replace("noise-").replace("shape-").replace("misc-").replace("jx-").replace("101-").replace("noise-").replace("filter-").split("\n")[value-1]);
};

Content.getComponent("Shape").setControlCallback(onShapeControl);

inline function onShape2Control(component, value)
{

   Sampler2.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler11.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler20.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler29.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler38.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler47.asSampler().loadSampleMap(sampleMaps[value-1]);
  
ShapeLabel2.set("text",Shape2.get("items").replace("noise-").replace("shape-").replace("misc-").replace("jx-").replace("101-").replace("noise-").replace("filter-").split("\n")[value-1]);
};

Content.getComponent("Shape2").setControlCallback(onShape2Control);

inline function onShape3Control(component, value)
{

   Sampler3.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler12.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler21.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler30.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler39.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler48.asSampler().loadSampleMap(sampleMaps[value-1]);
  
ShapeLabel3.set("text",Shape3.get("items").replace("noise-").replace("shape-").replace("misc-").replace("jx-").replace("101-").replace("noise-").replace("filter-").split("\n")[value-1]);
};

Content.getComponent("Shape3").setControlCallback(onShape3Control);

inline function onShape4Control(component, value)
{

   Sampler4.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler13.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler22.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler31.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler40.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler49.asSampler().loadSampleMap(sampleMaps[value-1]);
  
ShapeLabel4.set("text",Shape4.get("items").replace("noise-").replace("shape-").replace("misc-").replace("jx-").replace("101-").replace("noise-").replace("filter-").split("\n")[value-1]);
};

Content.getComponent("Shape4").setControlCallback(onShape4Control);

inline function onShape5Control(component, value)
{

   Sampler5.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler14.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler23.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler32.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler41.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler50.asSampler().loadSampleMap(sampleMaps[value-1]);
  
ShapeLabel5.set("text",Shape5.get("items").replace("noise-").replace("shape-").replace("misc-").replace("jx-").replace("101-").replace("noise-").replace("filter-").split("\n")[value-1]);
};

Content.getComponent("Shape5").setControlCallback(onShape5Control);

inline function onShape6Control(component, value)
{

   Sampler6.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler15.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler24.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler33.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler42.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler51.asSampler().loadSampleMap(sampleMaps[value-1]);
  
ShapeLabel6.set("text",Shape6.get("items").replace("noise-").replace("shape-").replace("misc-").replace("jx-").replace("101-").replace("noise-").replace("filter-").split("\n")[value-1]);
};

Content.getComponent("Shape6").setControlCallback(onShape6Control);

inline function onShape7Control(component, value)
{

   Sampler7.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler16.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler25.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler32.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler43.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler52.asSampler().loadSampleMap(sampleMaps[value-1]);
  
ShapeLabel7.set("text",Shape7.get("items").replace("noise-").replace("shape-").replace("misc-").replace("jx-").replace("101-").replace("noise-").replace("filter-").split("\n")[value-1]);
};

Content.getComponent("Shape7").setControlCallback(onShape7Control);

inline function onShape8Control(component, value)
{

   Sampler8.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler17.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler26.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler33.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler44.asSampler().loadSampleMap(sampleMaps[value-1]);
    Sampler53.asSampler().loadSampleMap(sampleMaps[value-1]);
  
ShapeLabel8.set("text",Shape8.get("items").replace("noise-").replace("shape-").replace("misc-").replace("jx-").replace("101-").replace("noise-").replace("filter-").split("\n")[value-1]);
};

Content.getComponent("Shape8").setControlCallback(onShape8Control);function onNoteOn()
{
	// the index is zero based like everything else in good
	// programming, so we need to add one to get the actual
	// channel number
	local d = rrIndex+1;
	
	// Store the value in the MIDIList for the note on
	EventIdStack.push(noteOnChannels, Message.getEventId(), d);
	Console.print(d);
	Message.setChannel(d);
	
	// Cycle through the round robin amount
	if(rrIndex++ >= 5)
	    rrIndex = 0;
}
 

  
 function onNoteOff()
 {
     local c = EventIdStack.pop(noteOnChannels, Message.getEventId());
 	Message.setChannel(c);
     
 }function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 