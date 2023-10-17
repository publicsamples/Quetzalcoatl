Content.makeFrontInterface(900, 760);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

Settings.setVoiceMultiplier(6);

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


const var MODSEL1 = Content.getComponent("MODSEL1");
const var HARMONIC = Synth.getEffect("HARMONIC");
const var mods = [];

mods[0] = Content.getComponent("env1");
mods[1] = Content.getComponent("8STEP2");


inline function onMODSEL1Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC.setAttribute(HARMONIC.modmode1, 0);
      mods[0].showControl(1);  
      mods[1].showControl(0);     
         
	}
	
		if(value == 2)
	{

	HARMONIC.setAttribute(HARMONIC.modmode1, 1);
	mods[0].showControl(0);  
	   mods[1].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL1").setControlCallback(onMODSEL1Control);

const var MODSEL2 = Content.getComponent("MODSEL2");

const var LFO1 = Content.getComponent("LFO1");
const var Cable1 = Content.getComponent("Cable1");
const var table1 = Content.getComponent("table1");




inline function onMODSEL2Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC.setAttribute(HARMONIC.modmode2, 0);
      LFO1.showControl(1);  
     Cable1.showControl(0);     
      table1.showControl(0);   
         
	}
	
		if(value == 3)
	{

	HARMONIC.setAttribute(HARMONIC.modmode2, 0.5);
   LFO1.showControl(0);  
     Cable1.showControl(1);     
      table1.showControl(0);   
	  
	}
	
	if(value == 2)
		{
	
		HARMONIC.setAttribute(HARMONIC.modmode2, 1);
   LFO1.showControl(0);  
     Cable1.showControl(0);     
      table1.showControl(1);   
		  
		}

};

Content.getComponent("MODSEL2").setControlCallback(onMODSEL2Control);
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
 