Content.makeFrontInterface(1020, 715);



Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
Settings.setZoomLevel(0.9);
const var HARMONIC = Synth.getChildSynth("HARMONIC");
include("ExpansionWaves.js");
include("waves.js");
include("Sfz.js");
include("Ui.js");


// PRESETS ///////////////////////
const var Presets = Content.getComponent("Presets");
var menuItems = [];

const var x = Engine.getUserPresetList(); 
for (i in x)
	menuItems.insert(-1, i);

menuItems = menuItems.join("\n");
Presets.set("items", menuItems);

inline function onPresetsControl(component, value)
{
	Engine.loadUserPreset(Presets.getItemText() + ".preset");
};

Content.getComponent("Presets").setControlCallback(onPresetsControl);

const var CLICK = Content.getComponent("CLICK");

CLICK.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
  });function onNoteOn()
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
 