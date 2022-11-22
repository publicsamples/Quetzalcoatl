Content.makeFrontInterface(600, 500);


const var Sampler1 = Synth.getSampler("Sampler1");


var sampleMapList1 = ["filter-2nsweep","filter-2nsweep1","filter-2nsweep2","filter-2nsweep3"];

var sampleMapList2 = ["filter-2nsweep4","filter-2nsweep5","filter-2nsweep6","filter-2nsweep7"];

const var KickBox = Content.getComponent("KickBox");
const var SnareBox = Content.getComponent("SnareBox");


KickBox.set("items", sampleMapList1.join("\n"));
SnareBox.set("items", sampleMapList2.join("\n"));

inline function onKickBoxControl(component, value)
{
Sampler1.loadSampleMap(sampleMapList1[value-1]);	

};

Content.getComponent("KickBox").setControlCallback(onKickBoxControl);

inline function onSnareBoxControl(component, value)
{
Sampler1.loadSampleMap(sampleMapList2[value-1]);	
};

Content.getComponent("SnareBox").setControlCallback(onSnareBoxControl);





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
 