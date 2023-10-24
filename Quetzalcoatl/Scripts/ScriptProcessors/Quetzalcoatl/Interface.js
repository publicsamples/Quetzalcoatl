Content.makeFrontInterface(1100, 860);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
Settings.setZoomLevel(0.9);
const var HARMONIC = Synth.getChildSynth("HARMONIC");
include("ExpansionWaves.js");
include("waves.js");



//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
   
 g.setFont("Montserrat", 13.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});

const var saf = Engine.createGlobalScriptLookAndFeel();
saf.registerFunction("drawTableRuler", function(g, obj)
{
    g.setColour(Colours.withAlpha(obj.bgColour, 0.8));
    
    var x = obj.position * obj.area[2];
    
//g.drawLine(x, x, 0, obj.area[3], 25.0);
    g.setColour(obj.bgColour);
    g.drawLine(x, x, 0, obj.area[3], 4.5);
});


const var MODSEL1 = Content.getComponent("MODSEL1");
const var MODSEL2 = Content.getComponent("MODSEL2");
const var MODSEL3 = Content.getComponent("MODSEL3");
const var MODSEL4 = Content.getComponent("MODSEL4");
const var MODSEL5 = Content.getComponent("MODSEL5");
const var MODSEL6 = Content.getComponent("MODSEL6");
const var Mod1 = Synth.getModulator("Mod1");
const var Mod2 = Synth.getModulator("Mod2");
const var Gmod1 = Synth.getModulator("Gmod1");
const var Gmod2 = Synth.getModulator("Gmod2");
const var Gmod3 = Synth.getModulator("Gmod3");
const var Gmod4 = Synth.getModulator("Gmod4");

const var mods = [];

mods[0] = Content.getComponent("env1");
mods[1] = Content.getComponent("Table1");
mods[2] = Content.getComponent("8step1");
mods[3] = Content.getComponent("8Trig1");

const var mods2 = [];

mods2[0] = Content.getComponent("env2");
mods2[1] = Content.getComponent("Table2");
mods2[2] = Content.getComponent("8step2");
mods2[3] = Content.getComponent("8Trig2");

const var mods3 = [];

mods3[0] = Content.getComponent("LFO1");
mods3[1] = Content.getComponent("Table3");
mods3[2] = Content.getComponent("8step3");
mods3[3] = Content.getComponent("8Trig3");

const var mods4 = [];

mods4[0] = Content.getComponent("LFO2");
mods4[1] = Content.getComponent("Table4");
mods4[2] = Content.getComponent("8step4");
mods4[3] = Content.getComponent("8Trig4");

const var mods5 = [];

mods5[0] = Content.getComponent("LFO3");
mods5[1] = Content.getComponent("Table5");
mods5[2] = Content.getComponent("8step5");
mods5[3] = Content.getComponent("8Trig5");

const var mods6 = [];

mods6[0] = Content.getComponent("LFO4");
mods6[1] = Content.getComponent("Table6");
mods6[2] = Content.getComponent("8step6");
mods6[3] = Content.getComponent("8Trig6");

inline function onMODSEL1Control(component, value)

{

	if(value == 1)
	{
	
	Mod1.setAttribute(Mod1.modsel, 0);
      mods[0].showControl(1);  
      mods[1].showControl(0);   
      mods[2].showControl(0);  
      mods[3].showControl(0);    
         
	}
	
		if(value == 2)
	{

      Mod1.setAttribute(Mod1.modsel, 1.7);
      mods[0].showControl(0);  
      mods[1].showControl(1);   
      mods[2].showControl(0);  
      mods[3].showControl(0);  
	  
	}
	
	if(value == 3)
	{
	
	Mod1.setAttribute(Mod1.modsel, 2.70);
   mods[0].showControl(0);  
      mods[1].showControl(0);   
      mods[2].showControl(1);  
      mods[3].showControl(0);  
	  
	}
	
	if(value == 4)
	{
	
	Mod1.setAttribute(Mod1.modsel, 4);
   mods[0].showControl(0);  
      mods[1].showControl(0);   
      mods[2].showControl(0);  
      mods[3].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL1").setControlCallback(onMODSEL1Control);

inline function onMODSEL2Control(component, value)

{

	if(value == 1)
	{
	
	Mod2.setAttribute(Mod2.modsel, 0);
      mods2[0].showControl(1);  
      mods2[1].showControl(0);   
      mods2[2].showControl(0);  
      mods2[3].showControl(0);    
         
	}
	
		if(value == 2)
	{

      Mod2.setAttribute(Mod2.modsel, 1.7);
      mods2[0].showControl(0);  
      mods2[1].showControl(1);   
      mods2[2].showControl(0);  
      mods2[3].showControl(0);  
	  
	}
	
	if(value == 3)
	{
	
	Mod2.setAttribute(Mod2.modsel, 2.7);
   mods2[0].showControl(0);  
      mods2[1].showControl(0);   
      mods2[2].showControl(1);  
      mods2[3].showControl(0);  
	  
	}
	
	if(value == 4)
	{
	
	Mod2.setAttribute(Mod2.modsel, 4);
   mods2[0].showControl(0);  
      mods2[1].showControl(0);   
      mods2[2].showControl(0);  
      mods2[3].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL2").setControlCallback(onMODSEL2Control);


inline function onMODSEL3Control(component, value)

{

	if(value == 1)
	{
	
	Gmod1.setAttribute(Gmod1.modsel, 0);
      mods3[0].showControl(1);  
      mods3[1].showControl(0);   
      mods3[2].showControl(0);  
      mods3[3].showControl(0);    
         
	}
	
		if(value == 2)
	{

      Gmod1.setAttribute(Gmod1.modsel, 1.7);
      mods3[0].showControl(0);  
      mods3[1].showControl(1);   
      mods3[2].showControl(0);  
      mods3[3].showControl(0);  
	  
	}
	
	if(value == 3)
	{
	
	Gmod1.setAttribute(Gmod1.modsel, 2.7);
   mods3[0].showControl(0);  
      mods3[1].showControl(0);   
      mods3[2].showControl(1);  
      mods3[3].showControl(0);  
	  
	}
	
	if(value == 4)
	{
	
	Gmod1.setAttribute(Gmod1.modsel, 4);
   mods3[0].showControl(0);  
      mods3[1].showControl(0);   
      mods3[2].showControl(0);  
      mods3[3].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL3").setControlCallback(onMODSEL3Control);

const var presets = Content.getComponent("presets");

const var SettingsPresets = Content.getComponent("SettingsPresets");


inline function onpresetsControl(component, value)
{
	SettingsPresets.showControl(value); 
        SettingsPresets.showControl(1-value);
};

Content.getComponent("presets").setControlCallback(onpresetsControl);


inline function onMODSEL4Control(component, value)

{

	if(value == 1)
	{
	
	Gmod2.setAttribute(Gmod2.modsel, 0);
      mods4[0].showControl(1);  
      mods4[1].showControl(0);   
      mods4[2].showControl(0);  
      mods4[3].showControl(0);    
         
	}
	
		if(value == 2)
	{

      Gmod2.setAttribute(Gmod2.modsel, 1.7);
      mods4[0].showControl(0);  
      mods4[1].showControl(1);   
      mods4[2].showControl(0);  
      mods4[3].showControl(0);  
	  
	}
	
	if(value == 3)
	{
	
	Gmod2.setAttribute(Gmod2.modsel, 2.7);
   mods4[0].showControl(0);  
      mods4[1].showControl(0);   
      mods4[2].showControl(1);  
      mods4[3].showControl(0);  
	  
	}
	
	if(value == 4)
	{
	
	Gmod2.setAttribute(Gmod2.modsel, 4);
   mods4[0].showControl(0);  
      mods4[1].showControl(0);   
      mods4[2].showControl(0);  
      mods4[3].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL4").setControlCallback(onMODSEL4Control);

inline function onMODSEL5Control(component, value)

{

	if(value == 1)
	{
	
	Gmod3.setAttribute(Gmod3.modsel, 0);
      mods5[0].showControl(1);  
      mods5[1].showControl(0);   
      mods5[2].showControl(0);  
      mods5[3].showControl(0);    
         
	}
	
		if(value == 2)
	{

      Gmod3.setAttribute(Gmod3.modsel, 1.7);
      mods5[0].showControl(0);  
      mods5[1].showControl(1);   
      mods5[2].showControl(0);  
      mods5[3].showControl(0);  
	  
	}
	
	if(value == 3)
	{
	
	Gmod3.setAttribute(Gmod3.modsel, 2.7);
   mods5[0].showControl(0);  
      mods5[1].showControl(0);   
      mods5[2].showControl(1);  
      mods5[3].showControl(0);  
	  
	}
	
	if(value == 4)
	{
	
	Gmod3.setAttribute(Gmod3.modsel, 4);
   mods5[0].showControl(0);  
      mods5[1].showControl(0);   
      mods5[2].showControl(0);  
      mods5[3].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL5").setControlCallback(onMODSEL5Control);

 inline function onMODSEL6Control(component, value)
 
 {
 
 	if(value == 1)
 	{
 	
 	Gmod4.setAttribute(Gmod4.modsel, 0);
       mods6[0].showControl(1);  
       mods6[1].showControl(0);   
       mods6[2].showControl(0);  
       mods6[3].showControl(0);    
          
 	}
 	
 		if(value == 2)
 	{
 
       Gmod4.setAttribute(Gmod4.modsel, 1.7);
       mods6[0].showControl(0);  
       mods6[1].showControl(1);   
       mods6[2].showControl(0);  
       mods6[3].showControl(0);  
 	  
 	}
 	
 	if(value == 3)
 	{
 	
 	Gmod4.setAttribute(Gmod4.modsel, 2.7);
    mods6[0].showControl(0);  
       mods6[1].showControl(0);   
       mods6[2].showControl(1);  
       mods6[3].showControl(0);  
 	  
 	}
 	
 	if(value == 4)
 	{
 	
 	Gmod4.setAttribute(Gmod4.modsel, 4);
    mods6[0].showControl(0);  
       mods6[1].showControl(0);   
       mods6[2].showControl(0);  
       mods6[3].showControl(1);  
 	  
 	}
 };
 
 
 Content.getComponent("MODSEL6").setControlCallback(onMODSEL6Control);

const var GmodSel = Content.getComponent("GmodSel");

const var Gm = []

Gm[0] = Content.getComponent("GlobalMod1");
Gm[1] = Content.getComponent("GlobalMod2");
Gm[2] = Content.getComponent("GlobalMod3");
Gm[3] = Content.getComponent("GlobalMod4");


inline function onGmodSelControl(component, value)
{
 for (i = 0; i < Gm.length; i++)
        Gm[i].fadeComponent(value - 1 == i, 500);
    
};

Content.getComponent("GmodSel").setControlCallback(onGmodSelControl);

const var FadeStack1 = Content.getComponent("FadeStack1");
const var FadeLabel1 = Content.getComponent("FadeLabel1");
const var StackLabel1 = Content.getComponent("StackLabel1");

inline function onFadeStack1Control(component, value)
{
	
	if(value == 0)
	{
	HARMONIC.setAttribute(HARMONIC.XfIn1, 0);
      FadeLabel1.showControl(1);  
     StackLabel1.showControl(0);   
	          
	}
	
		if(value == 1)
	{
	 
	HARMONIC.setAttribute(HARMONIC.XfIn1, 1);
      FadeLabel1.showControl(0);  
     StackLabel1.showControl(1);   
	  
	}


};

Content.getComponent("FadeStack1").setControlCallback(onFadeStack1Control);

const var FadeStack2 = Content.getComponent("FadeStack2");
const var FadeLabel2 = Content.getComponent("FadeLabel2");
const var StackLabel2 = Content.getComponent("StackLabel2");

inline function onFadeStack2Control(component, value)
{
	
	if(value == 0)
	{
	HARMONIC.setAttribute(HARMONIC.XfIn1, 0);
      FadeLabel2.showControl(1);  
     StackLabel2.showControl(0);   
	          
	}
	
		if(value == 1)
	{
	 
	HARMONIC.setAttribute(HARMONIC.XfIn2, 1);
      FadeLabel2.showControl(0);  
     StackLabel2.showControl(1);   
	  
	}


};

Content.getComponent("FadeStack2").setControlCallback(onFadeStack2Control);

const var TrigMode1 = Content.getComponent("TrigMode1");
const var LoopLabel1 = Content.getComponent("LoopLabel1");
const var OneShtLabel1 = Content.getComponent("OneShtLabel1");

inline function onTrigMode1Control(component, value)
{
	
	if(value == 0)
	{
	Mod1.setAttribute(Mod1.one, 0);
      LoopLabel1.showControl(0);  
     OneShtLabel1.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
	Mod1.setAttribute(Mod1.one, 1);
      LoopLabel1.showControl(1);  
     OneShtLabel1.showControl(0);   
	  
	}


};

Content.getComponent("TrigMode1").setControlCallback(onTrigMode1Control);

const var TrigMode2 = Content.getComponent("TrigMode2");
const var LoopLabel2 = Content.getComponent("LoopLabel2");
const var OneShtLabel2 = Content.getComponent("OneShtLabel2");

inline function onTrigMode2Control(component, value)
{
	
	if(value == 0)
	{
	Mod2.setAttribute(Mod2.one, 0);
      LoopLabel2.showControl(0);  
     OneShtLabel2.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
	Mod2.setAttribute(Mod2.one, 1);
      LoopLabel2.showControl(2);  
     OneShtLabel2.showControl(0);   
	  
	}


};

Content.getComponent("TrigMode2").setControlCallback(onTrigMode2Control);

const var TrigMode3 = Content.getComponent("TrigMode3");
const var FreeLabel1 = Content.getComponent("FreeLabel1");
const var TrigLabel1 = Content.getComponent("TrigLabel1");

inline function onTrigMode3Control(component, value)
{
	
	if(value == 0)
	{
	Gmod1.setAttribute(Gmod1.trigin, 0);
      FreeLabel1.showControl(0);  
     TrigLabel1.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
	Gmod1.setAttribute(Gmod1.trigin, 1);
      FreeLabel1.showControl(1);  
     TrigLabel1.showControl(0);   
	  
	}


};

Content.getComponent("TrigMode3").setControlCallback(onTrigMode3Control);

const var TrigMode4 = Content.getComponent("TrigMode4");
const var FreeLabel2 = Content.getComponent("FreeLabel2");
const var TrigLabel2 = Content.getComponent("TrigLabel2");

inline function onTrigMode4Control(component, value)
{
	
	if(value == 0)
	{
	Gmod2.setAttribute(Gmod2.trigin, 0);
      FreeLabel2.showControl(0);  
     TrigLabel2.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
	Gmod2.setAttribute(Gmod2.trigin, 1);
      FreeLabel2.showControl(1);  
     TrigLabel2.showControl(0);   
	  
	}


};

Content.getComponent("TrigMode4").setControlCallback(onTrigMode4Control);


const var TrigMode5 = Content.getComponent("TrigMode5");
const var FreeLabel3 = Content.getComponent("FreeLabel3");
const var TrigLabel3 = Content.getComponent("TrigLabel3");

inline function onTrigMode5Control(component, value)
{
	
	if(value == 0)
	{
	Gmod3.setAttribute(Gmod3.trigin, 0);
      FreeLabel3.showControl(0);  
     TrigLabel3.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
	Gmod3.setAttribute(Gmod3.trigin, 1);
      FreeLabel3.showControl(1);  
     TrigLabel3.showControl(0);   
	  
	}


};

Content.getComponent("TrigMode5").setControlCallback(onTrigMode5Control);

const var TrigMode6 = Content.getComponent("TrigMode6");
const var FreeLabel4 = Content.getComponent("FreeLabel4");
const var TrigLabel4 = Content.getComponent("TrigLabel4");

inline function onTrigMode6Control(component, value)
{
	
	if(value == 0)
	{
	Gmod4.setAttribute(Gmod4.trigin, 0);
      FreeLabel4.showControl(0);  
     TrigLabel4.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
	Gmod4.setAttribute(Gmod4.trigin, 1);
      FreeLabel4.showControl(1);  
     TrigLabel4.showControl(0);   
	  
	}


};

Content.getComponent("TrigMode6").setControlCallback(onTrigMode6Control);




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
 