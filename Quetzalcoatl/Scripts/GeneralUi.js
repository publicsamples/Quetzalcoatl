// PRESETS ///////////////////////
const var Presets = Content.getComponent("Presets");

const var expansionPresets = [];

//expansionPresets.push();

for(e in expHandler.getExpansionList())
    expansionPresets.push(e.getUserPresetList());
    for (i in e)
    	menuItems.insert(-1, i);
    	
    

var menuItems = [];

const var x = Engine.getUserPresetList(); 
for (i in x)
	menuItems.insert(-1, i);
	


menuItems = menuItems.join("\n");
Presets.set("items", menuItems);

inline function onPresetsControl(component, value)
{
	
	local cx = expHandler.getCurrentExpansion();
	    sampleMaps = cx.getSampleMapList();
	    sampleMapsed = cx.getSampleMapList();
	    local expansionProps = cx.getProperties();
	    local expName = expansionProps.Name;

	Engine.loadUserPreset(Presets.getItemText() + ".preset");
};

Content.getComponent("Presets").setControlCallback(onPresetsControl);

