Content.makeFrontInterface(600, 500);

const var Sampler1 = Synth.getSampler("Sampler1");
const var sampleMapList1 = Sampler1.getSampleMapList();

var Maps = [];

var List1 = ["filter-2nsweep","filter-2nsweep1","filter-2nsweep2","filter-2nsweep3"];

var List2 = ["filter-2nsweep4","filter-2nsweep5","filter-2nsweep6","filter-2nsweep7"];

Maps.push(List1);
Maps.push(List2);

const var KickBox = Content.getComponent("KickBox");
const var Categories = Content.getComponent("Categories");

inline function onCategoriesControl(component, value)
{
	//
	KickBox.set("items", [].join("\n")); // remove the old list
	KickBox.set("items", Maps[value-1].join("\n"));
	KickBox.setValue(1);
};

Content.getComponent("Categories").setControlCallback(onCategoriesControl);

KickBox.set("items", sampleMapList1.join("\n"));


inline function onKickBoxControl(component, value)
{
Sampler1.loadSampleMap(sampleMapList1[value-1]);	

};

Content.getComponent("KickBox").setControlCallback(onKickBoxControl);

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
 