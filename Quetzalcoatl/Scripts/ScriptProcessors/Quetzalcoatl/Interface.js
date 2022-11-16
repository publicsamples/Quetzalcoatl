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
const var Shape1 = Content.getComponent("Shape1");

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
        Shape1.set("items", "");
               Shape1.set("items", sampleMapsed.join("\n"));
       
       

    }
    
    else
    
    {
        sampleMaps = Sampler.getSampleMapList();
        Shape.set("items", "");
        Shape.set("items", sampleMaps.join("\n"));
        Shape1.set("items", "");
               Shape1.set("items", sampleMaps.join("\n"));


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
  ShapeLabel.set("text",Shape.get("items").split("\n")[value-1]);
};

Content.getComponent("Shape").setControlCallback(onShapeControl);

inline function onShape1Control(component, value)
{

  Sampler2.asSampler().loadSampleMap(sampleMaps[value-1]);
  
};

Content.getComponent("Shape1").setControlCallback(onShape1Control);

const var ShapeLabel = Content.getComponent("ShapeLabel");




function onNoteOn()
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
 