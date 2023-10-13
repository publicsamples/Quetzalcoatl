Content.makeFrontInterface(900, 800);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);

include("ExpansionWaves.js");
include("waves.js");

//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
 //  g.setFont("Montserrat", 16.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");



});




const var gatemods = Content.getComponent("gatemods");

const var gate = Content.getComponent("gate");


inline function ongatemodsControl(component, value)
{
gate.showControl(value);        gate.showControl(1-value);
};

Content.getComponent("gatemods").setControlCallback(ongatemodsControl);
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
 