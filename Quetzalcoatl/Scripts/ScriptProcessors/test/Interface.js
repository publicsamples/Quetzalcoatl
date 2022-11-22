Content.makeFrontInterface(885, 745);

include("waves.js");
include("rr.js");
include("presets.js");
include("wavemenus.js");
include("xfade.js");
include("FMandPitch.js");
include("Filter.js");
include("modulators.js");


const var Mod4extraTB3 = Content.getComponent("Mod4extraTB3");
Mod4extraTB3.referToData(tableData);

const var Mod4extraTB4 = Content.getComponent("Mod4extraTB4");
Mod4extraTB4.referToData(tableData);

const var ScriptTable4 = Content.getComponent("ScriptTable4");
ScriptTable4.referToData(tableData);



const var Sampler1 = Synth.getSampler("Sampler1");
const var Sampler2 = Synth.getSampler("Sampler2");
const var Sampler3 = Synth.getSampler("Sampler3");
const var Sampler4 = Synth.getSampler("Sampler4");
const var Sampler5 = Synth.getSampler("Sampler5");
const var Sampler6 = Synth.getSampler("Sampler6");
const var Sampler7 = Synth.getSampler("Sampler7");
const var Sampler8 = Synth.getSampler("Sampler8");
const var Sampler9 = Synth.getSampler("Sampler9");
const var Sampler10 = Synth.getSampler("Sampler10");
const var Sampler11 = Synth.getSampler("Sampler11");
const var Sampler12 = Synth.getSampler("Sampler12");
const var Sampler13 = Synth.getSampler("Sampler13");
const var Sampler14 = Synth.getSampler("Sampler14");
const var Sampler15 = Synth.getSampler("Sampler15");
const var Sampler16 = Synth.getSampler("Sampler16");
const var Sampler17 = Synth.getSampler("Sampler17");
const var Sampler18 = Synth.getSampler("Sampler18");
const var Sampler19 = Synth.getSampler("Sampler19");
const var Sampler20 = Synth.getSampler("Sampler20");
const var Sampler21 = Synth.getSampler("Sampler21");
const var Sampler22 = Synth.getSampler("Sampler22");
const var Sampler23 = Synth.getSampler("Sampler23");
const var Sampler24 = Synth.getSampler("Sampler24");
const var Sampler25 = Synth.getSampler("Sampler25");
const var Sampler26 = Synth.getSampler("Sampler26");
const var Sampler27 = Synth.getSampler("Sampler27");
const var Sampler28 = Synth.getSampler("Sampler28");
const var Sampler29 = Synth.getSampler("Sampler29");
const var Sampler30 = Synth.getSampler("Sampler30");
const var Sampler31 = Synth.getSampler("Sampler31");
const var Sampler32 = Synth.getSampler("Sampler32");
const var Sampler33 = Synth.getSampler("Sampler33");
const var Sampler34 = Synth.getSampler("Sampler34");
const var Sampler35 = Synth.getSampler("Sampler35");
const var Sampler36 = Synth.getSampler("Sampler36");
const var Sampler37 = Synth.getSampler("Sampler37");
const var Sampler38 = Synth.getSampler("Sampler38");
const var Sampler39 = Synth.getSampler("Sampler39");
const var Sampler40 = Synth.getSampler("Sampler40");
const var Sampler41 = Synth.getSampler("Sampler41");
const var Sampler42 = Synth.getSampler("Sampler42");
const var Sampler43 = Synth.getSampler("Sampler43");
const var Sampler44 = Synth.getSampler("Sampler44");
const var Sampler45 = Synth.getSampler("Sampler45");
const var Sampler46 = Synth.getSampler("Sampler46");
const var Sampler47 = Synth.getSampler("Sampler47");
const var Sampler48 = Synth.getSampler("Sampler48");
const var Sampler49 = Synth.getSampler("Sampler49");
const var Sampler50 = Synth.getSampler("Sampler50");
const var Sampler51 = Synth.getSampler("Sampler51");
const var Sampler52 = Synth.getSampler("Sampler52");
const var Sampler53 = Synth.getSampler("Sampler53");
const var Sampler54 = Synth.getSampler("Sampler54");
const var sampleMaps = Sampler.getSampleMapList();

const var Group1 = Synth.getChildSynth("Group1");
const var Group2 = Synth.getChildSynth("Group2");
const var Group3 = Synth.getChildSynth("Group3");
const var Group4 = Synth.getChildSynth("Group4");
const var Group5 = Synth.getChildSynth("Group5");
const var Group6 = Synth.getChildSynth("Group6");
const var Group7 = Synth.getChildSynth("Group7");
const var Group8 = Synth.getChildSynth("Group8");
const var Group9 = Synth.getChildSynth("Group9");
const var Group10 = Synth.getChildSynth("Group10");
const var Group11 = Synth.getChildSynth("Group11");
const var Group12 = Synth.getChildSynth("Group12");
const var Group13 = Synth.getChildSynth("Group13");
const var Group14 = Synth.getChildSynth("Group14");
const var Group15 = Synth.getChildSynth("Group15");
const var Group16 = Synth.getChildSynth("Group16");
const var Group17 = Synth.getChildSynth("Group17");
const var Group18 = Synth.getChildSynth("Group18");
const var Group19 = Synth.getChildSynth("Group19");
const var Group20 = Synth.getChildSynth("Group20");
const var Group21 = Synth.getChildSynth("Group21");
const var Group22 = Synth.getChildSynth("Group22");
const var Group23 = Synth.getChildSynth("Group23");
const var Group24 = Synth.getChildSynth("Group24");
const var Group25 = Synth.getChildSynth("Group25");
const var Group26 = Synth.getChildSynth("Group26");
const var Group27 = Synth.getChildSynth("Group27");
const var Group28 = Synth.getChildSynth("Group28");
const var Group29 = Synth.getChildSynth("Group29");
const var Group30 = Synth.getChildSynth("Group30");
const var Group31 = Synth.getChildSynth("Group31");
const var Group32 = Synth.getChildSynth("Group32");
const var Group33 = Synth.getChildSynth("Group33");
const var Group34 = Synth.getChildSynth("Group34");
const var Group35 = Synth.getChildSynth("Group35");
const var Group36 = Synth.getChildSynth("Group36");
const var Group37 = Synth.getChildSynth("Group37");
const var Group38 = Synth.getChildSynth("Group38");
const var Group39 = Synth.getChildSynth("Group39");
const var Group40 = Synth.getChildSynth("Group40");
const var Group41 = Synth.getChildSynth("Group41");
const var Group42 = Synth.getChildSynth("Group42");
const var Group43 = Synth.getChildSynth("Group43");
const var Group44 = Synth.getChildSynth("Group44");
const var Group45 = Synth.getChildSynth("Group45");
const var Group46 = Synth.getChildSynth("Group46");
const var Group47 = Synth.getChildSynth("Group47");
const var Group48 = Synth.getChildSynth("Group48");
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
 