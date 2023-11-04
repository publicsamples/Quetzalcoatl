
const var PRESETS = Content.getComponent("PRESETS");

const var PRESETBUTTON = Content.getComponent("PRESETBUTTON");
const var HARMONIC = Synth.getChildSynth("HARMONIC");


inline function onPRESETBUTTONControl(component, value)
{
		PRESETS.showControl(value); 
        PRESETS.showControl(1-value);
};

Content.getComponent("PRESETBUTTON").setControlCallback(onPRESETBUTTONControl);




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

const var ulp = Content.getComponent("expansionad");


ulp.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/rhnqwh");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
});

//osc pages


const var PITCHPANEL1 = Content.getComponent("PITCHPANEL1");
const var PITCHPANEL2 = Content.getComponent("PITCHPANEL2");
const var PITCHPANEL3 = Content.getComponent("PITCHPANEL3")
const var PITCHPANEL4 = Content.getComponent("PITCHPANEL4")



inline function onWAVE1PANELControl(component, value)
{
	PITCHPANEL1.showControl(1);
	PITCHPANEL2.showControl(0);
	PITCHPANEL3.showControl(0);
	PITCHPANEL4.showControl(0);

};

Content.getComponent("WAVE1PANEL").setControlCallback(onWAVE1PANELControl);


inline function onWAVE2PANELControl(component, value)
{
	PITCHPANEL1.showControl(0);
	PITCHPANEL2.showControl(1);
	PITCHPANEL3.showControl(0);
	PITCHPANEL4.showControl(0);
;
};

Content.getComponent("WAVE2PANEL").setControlCallback(onWAVE2PANELControl);



inline function onWAVE3PANELControl(component, value)
{
	PITCHPANEL1.showControl(0);
	PITCHPANEL2.showControl(0);
	PITCHPANEL3.showControl(1);
	PITCHPANEL4.showControl(0);

};

Content.getComponent("WAVE3PANEL").setControlCallback(onWAVE3PANELControl);



inline function onWAVE4PANELControl(component, value)
{
	PITCHPANEL1.showControl(0);
	PITCHPANEL2.showControl(0);
	PITCHPANEL3.showControl(0);
	PITCHPANEL4.showControl(1);

};

Content.getComponent("WAVE4PANEL").setControlCallback(onWAVE4PANELControl);




const var W1 = Content.getComponent("W1");
const var W2 = Content.getComponent("W2");
const var W3 = Content.getComponent("W3");
const var W4 = Content.getComponent("W4");
const var WAVE4PANEL = Content.getComponent("WAVE4PANEL");
const var WAVE3PANEL = Content.getComponent("WAVE3PANEL");
const var WAVE2PANEL = Content.getComponent("WAVE2PANEL");

const var Waves = Content.getComponent("Waves");
const var Blank = Content.getComponent("Blank");
const var xfPANEL1 = Content.getComponent("xfPANEL1");



inline function onWavesControl(component, value)
{
HARMONIC.setAttribute(HARMONIC.Waves, value);

	if(value == 1)
	{	 
	     WAVE2PANEL.showControl(0);
		 W2.showControl(0);
	   	 WAVE3PANEL.showControl(0);
	     W3.showControl(0);
		 WAVE4PANEL.showControl(0);
		 W4.showControl(0);
		 Blank.showControl(1);
		 xfPANEL1.showControl(0);
		 PITCHPANEL1.showControl(1);
		 PITCHPANEL2.showControl(0);
		 PITCHPANEL3.showControl(0);
		 PITCHPANEL4.showControl(0);

	}
	
		if(value == 2)
	{

	
		 WAVE2PANEL.showControl(1);
		 W2.showControl(1);
	   	 WAVE3PANEL.showControl(0);
	     W3.showControl(0);
		 WAVE4PANEL.showControl(0);
		 W4.showControl(0);
		 Blank.showControl(0);
		 xfPANEL1.showControl(1);
	}
	
	if(value == 3)
	{
	WAVE2PANEL.showControl(1);
		 W2.showControl(1);
	   	 WAVE3PANEL.showControl(1);
	     W3.showControl(1);
		 WAVE4PANEL.showControl(1);
		 W4.showControl(1);
		 Blank.showControl(0);
		 xfPANEL1.showControl(1);
	}
	
	if(value == 4)
	{
		WAVE2PANEL.showControl(1);
		 W2.showControl(1);
	   	 WAVE3PANEL.showControl(1);
	     W3.showControl(1);
		 WAVE4PANEL.showControl(1);
		 W4.showControl(1);
		 Blank.showControl(0);
		 xfPANEL1.showControl(1);
	}
	
	if(value == 5)
	{
		WAVE2PANEL.showControl(1);
		 W2.showControl(1);
	   	 WAVE3PANEL.showControl(1);
	     W3.showControl(1);
		 WAVE4PANEL.showControl(1);
		 W4.showControl(1);
		 Blank.showControl(0);
		 xfPANEL1.showControl(1);
	}
};

Content.getComponent("Waves").setControlCallback(onWavesControl);







