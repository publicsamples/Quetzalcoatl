Content.makeFrontInterface(920, 820);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

//Settings.setVoiceMultiplier(0);

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

const var saf = Engine.createGlobalScriptLookAndFeel();
saf.registerFunction("drawTableRuler", function(g, obj)
{
    g.setColour(Colours.withAlpha(obj.bgColour, 0.8));
    
    var x = obj.position * obj.area[2];
    
  //  g.drawLine(x, x, 0, obj.area[3], 25.0);
    g.setColour(obj.bgColour);
    g.drawLine(x, x, 0, obj.area[3], 4.5);
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


const var MODSEL3 = Content.getComponent("MODSEL3");

const var LFO2 = Content.getComponent("LFO2");
const var Cable2 = Content.getComponent("Cable2");
const var table2 = Content.getComponent("table2");




inline function onMODSEL3Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC.setAttribute(HARMONIC.ModMode3, 0);
      LFO2.showControl(1);  
     Cable2.showControl(0);     
      table2.showControl(0);   
         
	}
	
		if(value == 3)
	{

	HARMONIC.setAttribute(HARMONIC.ModMode3, 0.5);
   LFO2.showControl(0);  
     Cable2.showControl(1);     
      table2.showControl(0);   
	  
	}
	
	if(value == 2)
		{
	
		HARMONIC.setAttribute(HARMONIC.ModMode3, 1);
   LFO2.showControl(0);  
     Cable2.showControl(0);     
      table2.showControl(1);   
		  
		}

};

Content.getComponent("MODSEL3").setControlCallback(onMODSEL3Control);

const var Voices = Content.getComponent("Voices");
const var voice1 = Content.getComponent("voice1");
const var voice2 = Content.getComponent("voice2");
const var voice3 = Content.getComponent("voice3");
const var voice4 = Content.getComponent("voice4");
const var SilentSynth1 = Synth.getChildSynth("Silent Synth1");
const var SilentSynth2 = Synth.getChildSynth("Silent Synth2");
const var SilentSynth3 = Synth.getChildSynth("Silent Synth3");
const var SilentSynth4 = Synth.getChildSynth("Silent Synth4");

inline function onVoicesControl(component, value)
{
	
	XFharm1.showControl(1);  
			     XFharm2.showControl(0);     
			     XFharm3.showControl(0);   
			     XFharm4.showControl(0);   

		if(value == 1)
	{
	SilentSynth1.setBypassed(0);
	SilentSynth2.setBypassed(1);
	SilentSynth3.setBypassed(1);
	SilentSynth4.setBypassed(1);
      voice1.showControl(1);  
     voice2.showControl(0);     
      voice3.showControl(0);   
      voice4.showControl(0); 
         
	}
	
		if(value == 2)
	{

	SilentSynth1.setBypassed(0);
	SilentSynth2.setBypassed(0);
	SilentSynth3.setBypassed(1);
	SilentSynth4.setBypassed(1);
      voice1.showControl(1);  
     voice2.showControl(1);     
      voice3.showControl(0);   
      voice4.showControl(0); 
	  
	}
	
	if(value == 3)
		{
	
	SilentSynth1.setBypassed(0);
	SilentSynth2.setBypassed(0);
	SilentSynth3.setBypassed(0);
	SilentSynth4.setBypassed(1);
      voice1.showControl(1);  
     voice2.showControl(1);     
      voice3.showControl(1);   
      voice4.showControl(0);   
		  
		}
		
		if(value == 4)
			{
		
		SilentSynth1.setBypassed(0);
		SilentSynth2.setBypassed(0);
		SilentSynth3.setBypassed(0);
		SilentSynth4.setBypassed(0);
		      voice1.showControl(1);  
		     voice2.showControl(1);     
		      voice3.showControl(1);   
		      voice4.showControl(1);   
			  
			}
};

Content.getComponent("Voices").setControlCallback(onVoicesControl);

const var XFharm1 = Content.getComponent("XFharm1");
const var XFharm2 = Content.getComponent("XFharm2");
const var XFharm3 = Content.getComponent("XFharm3");
const var XFharm4 = Content.getComponent("XFharm4");


inline function onvoice1Control(component, value)
{
			 XFharm1.showControl(1);  
		     XFharm2.showControl(0);     
		     XFharm3.showControl(0);   
		     XFharm4.showControl(0);   
};

Content.getComponent("voice1").setControlCallback(onvoice1Control);


inline function onvoice2Control(component, value)
{
			 XFharm1.showControl(0);  
		     XFharm2.showControl(1);     
		     XFharm3.showControl(0);   
		     XFharm4.showControl(0);   
};

Content.getComponent("voice2").setControlCallback(onvoice2Control);

inline function onvoice3Control(component, value)
{
			 XFharm1.showControl(0);  
		     XFharm2.showControl(0);     
		     XFharm3.showControl(1);   
		     XFharm4.showControl(0);   
};

Content.getComponent("voice3").setControlCallback(onvoice3Control);

inline function onvoice4Control(component, value)
{
			 XFharm1.showControl(0);  
		     XFharm2.showControl(0);     
		     XFharm3.showControl(0);   
		     XFharm4.showControl(1);   
};

Content.getComponent("voice4").setControlCallback(onvoice4Control);

const var MODSEL4 = Content.getComponent("MODSEL4");
const var HARMONIC2 = Synth.getEffect("HARMONIC2");
const var mods1 = [];

mods1[0] = Content.getComponent("env2");
mods1[1] = Content.getComponent("8STEP3");


inline function onMODSEL4Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC2.setAttribute(HARMONIC2.modmode1, 0);
      mods1[0].showControl(1);  
      mods1[1].showControl(0);     
         
	}
	
		if(value == 2)
	{

	HARMONIC2.setAttribute(HARMONIC2.modmode1, 1);
	mods1[0].showControl(0);  
	   mods1[1].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL4").setControlCallback(onMODSEL4Control);

const var MODSEL5 = Content.getComponent("MODSEL5");

const var LFO3 = Content.getComponent("LFO3");
const var Cable3 = Content.getComponent("Cable3");
const var table3 = Content.getComponent("table3");




inline function onMODSEL5Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC2.setAttribute(HARMONIC2.modmode2, 0);
      LFO3.showControl(1);  
     Cable3.showControl(0);     
      table3.showControl(0);   
         
	}
	
		if(value == 3)
	{

	HARMONIC2.setAttribute(HARMONIC2.modmode2, 0.5);
   LFO3.showControl(0);  
     Cable3.showControl(1);     
      table3.showControl(0);   
	  
	}
	
	if(value == 2)
		{
	
		HARMONIC2.setAttribute(HARMONIC2.modmode2, 1);
   LFO3.showControl(0);  
     Cable3.showControl(0);     
      table3.showControl(1);   
		  
		}

};

Content.getComponent("MODSEL5").setControlCallback(onMODSEL5Control);


const var MODSEL6 = Content.getComponent("MODSEL6");

const var LFO4 = Content.getComponent("LFO4");
const var Cable4 = Content.getComponent("Cable4");
const var table4 = Content.getComponent("table4");




inline function onMODSEL6Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC2.setAttribute(HARMONIC2.ModMode3, 0);
      LFO4.showControl(1);  
     Cable4.showControl(0);     
      table4.showControl(0);   
         
	}
	
		if(value == 3)
	{

	HARMONIC2.setAttribute(HARMONIC2.ModMode3, 0.5);
   LFO4.showControl(0);  
     Cable4.showControl(1);     
      table4.showControl(0);   
	  
	}
	
	if(value == 2)
		{
	
		HARMONIC2.setAttribute(HARMONIC2.ModMode3, 1);
   LFO4.showControl(0);  
     Cable4.showControl(0);     
      table4.showControl(1);   
		  
		}

};

Content.getComponent("MODSEL6").setControlCallback(onMODSEL6Control);

const var MODSEL7 = Content.getComponent("MODSEL7");
const var HARMONIC3 = Synth.getEffect("HARMONIC3");
const var mods2 = [];

mods2[0] = Content.getComponent("env3");
mods2[1] = Content.getComponent("8STEP4");


inline function onMODSEL7Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC3.setAttribute(HARMONIC3.modmode1, 0);
      mods2[0].showControl(1);  
      mods2[1].showControl(0);     
         
	}
	
		if(value == 2)
	{

	HARMONIC3.setAttribute(HARMONIC3.modmode1, 1);
	mods2[0].showControl(0);  
	   mods2[1].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL7").setControlCallback(onMODSEL7Control);

const var MODSEL8 = Content.getComponent("MODSEL8");

const var LFO5 = Content.getComponent("LFO5");
const var Cable5 = Content.getComponent("Cable5");
const var table5 = Content.getComponent("table5");




inline function onMODSEL8Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC3.setAttribute(HARMONIC3.modmode2, 0);
      LFO5.showControl(1);  
     Cable5.showControl(0);     
      table5.showControl(0);   
         
	}
	
		if(value == 3)
	{

	HARMONIC3.setAttribute(HARMONIC3.modmode2, 0.5);
   LFO5.showControl(0);  
     Cable5.showControl(1);     
      table5.showControl(0);   
	  
	}
	
	if(value == 2)
		{
	
		HARMONIC3.setAttribute(HARMONIC3.modmode2, 1);
   LFO5.showControl(0);  
     Cable5.showControl(0);     
      table5.showControl(1);   
		  
		}

};

Content.getComponent("MODSEL8").setControlCallback(onMODSEL8Control);


const var MODSEL9 = Content.getComponent("MODSEL9");

const var LFO6 = Content.getComponent("LFO6");
const var Cable6 = Content.getComponent("Cable6");
const var table6 = Content.getComponent("table6");




inline function onMODSEL9Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC3.setAttribute(HARMONIC3.ModMode3, 0);
      LFO6.showControl(1);  
     Cable6.showControl(0);     
      table6.showControl(0);   
         
	}
	
		if(value == 3)
	{

	HARMONIC3.setAttribute(HARMONIC3.ModMode3, 0.5);
   LFO6.showControl(0);  
     Cable6.showControl(1);     
      table6.showControl(0);   
	  
	}
	
	if(value == 2)
		{
	
		HARMONIC3.setAttribute(HARMONIC3.ModMode3, 1);
   LFO6.showControl(0);  
     Cable6.showControl(0);     
      table6.showControl(1);   
		  
		}

};

Content.getComponent("MODSEL9").setControlCallback(onMODSEL9Control);

const var MODSEL10 = Content.getComponent("MODSEL10");
const var HARMONIC4 = Synth.getEffect("HARMONIC4");
const var mods3 = [];

mods3[0] = Content.getComponent("env4");
mods3[1] = Content.getComponent("8STEP5");


inline function onMODSEL10Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC4.setAttribute(HARMONIC4.modmode1, 0);
      mods3[0].showControl(1);  
      mods3[1].showControl(0);     
         
	}
	
		if(value == 2)
	{

	HARMONIC4.setAttribute(HARMONIC4.modmode1, 1);
	mods3[0].showControl(0);  
	   mods3[1].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL10").setControlCallback(onMODSEL10Control);

const var MODSEL11 = Content.getComponent("MODSEL11");

const var LFO7 = Content.getComponent("LFO7");
const var Cable7 = Content.getComponent("Cable7");
const var table7 = Content.getComponent("table7");




inline function onMODSEL11Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC4.setAttribute(HARMONIC4.modmode2, 0);
      LFO7.showControl(1);  
     Cable7.showControl(0);     
      table7.showControl(0);   
         
	}
	
		if(value == 3)
	{

	HARMONIC4.setAttribute(HARMONIC4.modmode2, 0.5);
   LFO7.showControl(0);  
     Cable7.showControl(1);     
      table7.showControl(0);   
	  
	}
	
	if(value == 2)
		{
	
		HARMONIC4.setAttribute(HARMONIC4.modmode2, 1);
   LFO7.showControl(0);  
     Cable7.showControl(0);     
      table7.showControl(1);   
		  
		}

};

Content.getComponent("MODSEL11").setControlCallback(onMODSEL11Control);


const var MODSEL12 = Content.getComponent("MODSEL12");

const var LFO8 = Content.getComponent("LFO8");
const var Cable8 = Content.getComponent("Cable8");
const var table8 = Content.getComponent("table8");




inline function onMODSEL12Control(component, value)

{

	if(value == 1)
	{
	
	HARMONIC4.setAttribute(HARMONIC4.ModMode3, 0);
      LFO8.showControl(1);  
     Cable8.showControl(0);     
      table8.showControl(0);   
         
	}
	
		if(value == 3)
	{

	HARMONIC4.setAttribute(HARMONIC4.ModMode3, 0.5);
   LFO8.showControl(0);  
     Cable8.showControl(1);     
      table8.showControl(0);   
	  
	}
	
	if(value == 2)
		{
	
		HARMONIC4.setAttribute(HARMONIC4.ModMode3, 1);
   LFO8.showControl(0);  
     Cable8.showControl(0);     
      table8.showControl(1);   
		  
		}

};

Content.getComponent("MODSEL12").setControlCallback(onMODSEL12Control);


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
 