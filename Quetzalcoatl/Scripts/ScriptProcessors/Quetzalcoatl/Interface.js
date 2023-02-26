Content.makeFrontInterface(880, 700);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat-Medium");

include("waves.js");
include("import.js");
include("rr.js");
include("presets.js");
include("xfade.js");
include("FMandPitch.js");
include("Filter.js");
include("modulators.js");
include("osc2.js");
include("mod.js");
include("Migration.js");
include("load1.js");
include("load2.js");
include("load3.js");
include("load4.js");
include("load5.js");
include("load6.js");
include("load7.js");
include("load8.js");
include("load9.js");
include("SAMPLESELECT.js");
include("expansion.js");
//links

const var ulp = Content.getComponent("ulp");


ulp.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/lybce");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
});


const var modpos = Content.getComponent("modpos");


reg index = 1; // index of the filmstrip 
reg total_frames = 125; // total frames in the filmstrip
reg frame_height = 650; // the height(y) of each frame


modpos.loadImage("{PROJECT_FOLDER}modposition.png", "dot");

const var LFOModulator1 = Synth.getModulator("dummymod");
const var y = LFOModulator1.getCurrentLevel();
const var intensity = LFOModulator1.getIntensity();

modpos.setPaintRoutine(function(g){
    
index = Math.floor(LFOModulator1.getCurrentLevel() * total_frames);


  
  g.drawImage("dot", [0, 0, this.get("width"), this.get("height")], 0, index * frame_height);
});

modpos.setTimerCallback(function(){
    index = (index + 1) % total_frames;
    this.repaint();
   
});



modpos.startTimer(40);





//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
 
    g.setFont("Montserrat-Medium", 12.0);
   
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});










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
	if(rrIndex++ >= 6)
	    rrIndex = 1;
 }

  
 function onNoteOff()
 {     local c = EventIdStack.pop(noteOnChannels, Message.getEventId());
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
 