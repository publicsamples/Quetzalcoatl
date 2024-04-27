Content.makeFrontInterface(1020, 715);



Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
//Settings.setZoomLevel(0.9);
const var HARMONIC = Synth.getChildSynth("HARMONIC");
include("ExpansionWaves.js");
include("waves.js");
//include("Sfz.js");
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
  });
  


const var Xfade1 = Synth.getModulator("Xfade1");
const var Xfade2 = Synth.getModulator("Xfade2");
const var Xfade3 = Synth.getModulator("Xfade3");
const var Xfade4 = Synth.getModulator("Xfade4");
const var Xfade5 = Synth.getModulator("Xfade5");
const var Xfade6 = Synth.getModulator("Xfade6");
const var Xfade7 = Synth.getModulator("Xfade7");
const var Xfade8 = Synth.getModulator("Xfade8");

inline function onXfsel2Control(component, value)
{
	Xfade1.setAttribute(Xfade1.XfModer, value);
	Xfade2.setAttribute(Xfade2.XfModer, value);
	Xfade3.setAttribute(Xfade3.XfModer, value);
	Xfade4.setAttribute(Xfade4.XfModer, value);
	Xfade5.setAttribute(Xfade5.XfModer, value);
	Xfade6.setAttribute(Xfade6.XfModer, value);
	Xfade7.setAttribute(Xfade7.XfModer, value);
	Xfade8.setAttribute(Xfade8.XfModer, value);
	
};

Content.getComponent("Xfsel2").setControlCallback(onXfsel2Control);


inline function onXFsliderControl(component, value)
{
	Xfade1.setAttribute(Xfade1.XF, value);
	Xfade2.setAttribute(Xfade2.XF, value);
	Xfade3.setAttribute(Xfade3.XF, value);
	Xfade4.setAttribute(Xfade4.XF, value);
	Xfade5.setAttribute(Xfade5.XF, value);
	Xfade6.setAttribute(Xfade6.XF, value);
	Xfade7.setAttribute(Xfade7.XF, value);
	Xfade8.setAttribute(Xfade8.XF, value);
};

Content.getComponent("XFslider").setControlCallback(onXFsliderControl);


inline function onSmoothControl(component, value)
{
	Xfade1.setAttribute(Xfade1.XFsmooth, value);
	Xfade2.setAttribute(Xfade2.XFsmooth, value);
	Xfade3.setAttribute(Xfade3.XFsmooth, value);
	Xfade4.setAttribute(Xfade4.XFsmooth, value);
	Xfade5.setAttribute(Xfade5.XFsmooth, value);
	Xfade6.setAttribute(Xfade6.XFsmooth, value);
	Xfade7.setAttribute(Xfade7.XFsmooth, value);
	Xfade8.setAttribute(Xfade8.XFsmooth, value);
};

Content.getComponent("Smooth").setControlCallback(onSmoothControl);


inline function onXfModControl(component, value)
{
	Xfade1.setAttribute(Xfade1.XfMod, value);
	Xfade2.setAttribute(Xfade2.XfMod, value);
	Xfade3.setAttribute(Xfade3.XfMod, value);
	Xfade4.setAttribute(Xfade4.XfMod, value);
	Xfade5.setAttribute(Xfade5.XfMod, value);
	Xfade6.setAttribute(Xfade6.XfMod, value);
	Xfade7.setAttribute(Xfade7.XfMod, value);
	Xfade8.setAttribute(Xfade8.XfMod, value);
};

Content.getComponent("XfMod").setControlCallback(onXfModControl);


inline function onXfselControl(component, value)
{
	Xfade1.setAttribute(Xfade1.XfModSrc, value);
	Xfade2.setAttribute(Xfade2.XfModSrc, value);
	Xfade3.setAttribute(Xfade3.XfModSrc, value);
	Xfade4.setAttribute(Xfade4.XfModSrc, value);
	Xfade5.setAttribute(Xfade5.XfModSrc, value);
	Xfade6.setAttribute(Xfade6.XfModSrc, value);
	Xfade7.setAttribute(Xfade7.XfModSrc, value);
	Xfade8.setAttribute(Xfade8.XfModSrc, value);
};

Content.getComponent("Xfsel").setControlCallback(onXfselControl);


inline function onXfAtControl(component, value)
{
	Xfade1.setAttribute(Xfade1.aft, value);
	Xfade2.setAttribute(Xfade2.aft, value);
	Xfade3.setAttribute(Xfade3.aft, value);
	Xfade4.setAttribute(Xfade4.aft, value);
	Xfade5.setAttribute(Xfade5.aft, value);
	Xfade6.setAttribute(Xfade6.aft, value);
	Xfade7.setAttribute(Xfade7.aft, value);
	Xfade8.setAttribute(Xfade8.aft, value);
};

Content.getComponent("XfAt").setControlCallback(onXfAtControl);


inline function onXfMwControl(component, value)
{
	Xfade1.setAttribute(Xfade1.mw, value);
	Xfade2.setAttribute(Xfade2.mw, value);
	Xfade3.setAttribute(Xfade3.mw, value);
	Xfade4.setAttribute(Xfade4.mw, value);
	Xfade5.setAttribute(Xfade5.mw, value);
	Xfade6.setAttribute(Xfade6.mw, value);
	Xfade7.setAttribute(Xfade7.mw, value);
	Xfade8.setAttribute(Xfade8.mw, value);
};

Content.getComponent("XfMw").setControlCallback(onXfMwControl);


inline function onXfVelControl(component, value)
{
	Xfade1.setAttribute(Xfade1.vel, value);
	Xfade2.setAttribute(Xfade2.vel, value);
	Xfade3.setAttribute(Xfade3.vel, value);
	Xfade4.setAttribute(Xfade4.vel, value);
	Xfade5.setAttribute(Xfade5.vel, value);
	Xfade6.setAttribute(Xfade6.vel, value);
	Xfade7.setAttribute(Xfade7.vel, value);
	Xfade8.setAttribute(Xfade8.vel, value);
};

Content.getComponent("XfVel").setControlCallback(onXfVelControl);


inline function onXfTrkControl(component, value)
{
	Xfade1.setAttribute(Xfade1.trk, value);
	Xfade2.setAttribute(Xfade2.trk, value);
	Xfade3.setAttribute(Xfade3.trk, value);
	Xfade4.setAttribute(Xfade4.trk, value);
	Xfade5.setAttribute(Xfade5.trk, value);
	Xfade6.setAttribute(Xfade6.trk, value);
	Xfade7.setAttribute(Xfade7.trk, value);
	Xfade8.setAttribute(Xfade8.trk, value);
};

Content.getComponent("XfTrk").setControlCallback(onXfTrkControl);



inline function onXfTempoControl(component, value)
{
	Xfade1.setAttribute(Xfade1.tempo, value);
	Xfade2.setAttribute(Xfade2.tempo, value);
	Xfade3.setAttribute(Xfade3.tempo, value);
	Xfade4.setAttribute(Xfade4.tempo, value);
	Xfade5.setAttribute(Xfade5.tempo, value);
	Xfade6.setAttribute(Xfade6.tempo, value);
	Xfade7.setAttribute(Xfade7.tempo, value);
	Xfade8.setAttribute(Xfade8.tempo, value);
};

Content.getComponent("XfTempo").setControlCallback(onXfTempoControl);


inline function onXfDivControl(component, value)
{
	Xfade1.setAttribute(Xfade1.mul, value);
	Xfade2.setAttribute(Xfade2.mul, value);
	Xfade3.setAttribute(Xfade3.mul, value);
	Xfade4.setAttribute(Xfade4.mul, value);
	Xfade5.setAttribute(Xfade5.mul, value);
	Xfade6.setAttribute(Xfade6.mul, value);
	Xfade7.setAttribute(Xfade7.mul, value);
	Xfade8.setAttribute(Xfade8.mul, value);
};

Content.getComponent("XfDiv").setControlCallback(onXfDivControl);


inline function onXfTrigModeControl(component, value)
{
	if(value == 0)
	{
		
	Xfade1.setAttribute(Xfade1.one, 0);
	Xfade2.setAttribute(Xfade2.one, 0);
	Xfade3.setAttribute(Xfade3.one, 0);
	Xfade4.setAttribute(Xfade4.one, 0);
	Xfade5.setAttribute(Xfade5.one, 0);
	Xfade6.setAttribute(Xfade6.one, 0);
	Xfade7.setAttribute(Xfade7.one, 0);
	Xfade8.setAttribute(Xfade8.one, 0);
	LoopLabel1.showControl(0);  
	     OneShtLabel1.showControl(1);   
	     }
	     
	     	if(value == 1)
	     {
	Xfade1.setAttribute(Xfade1.one, 1);
	Xfade2.setAttribute(Xfade2.one, 1);
	Xfade3.setAttribute(Xfade3.one, 1);
	Xfade4.setAttribute(Xfade4.one, 1);
	Xfade5.setAttribute(Xfade5.one, 1);
	Xfade6.setAttribute(Xfade6.one, 1);
	Xfade7.setAttribute(Xfade7.one, 1);
	Xfade8.setAttribute(Xfade8.one, 1);
	LoopLabel1.showControl(1);  
	     OneShtLabel1.showControl(0);
	     }   

};

Content.getComponent("XfTrigMode").setControlCallback(onXfTrigModeControl);

const var Xfsync = Content.getComponent("Xfsync");
const var XfTempo = Content.getComponent("XfTempo");
const var XfTempo2 = Content.getComponent("XfTempo2");


inline function onXfsyncControl(component, value)
{
	if(value == 0)
	{
	
	Xfade1.setAttribute(Xfade1.sync, 1);
	Xfade2.setAttribute(Xfade2.sync, 1);
	Xfade3.setAttribute(Xfade3.sync, 1);
	Xfade4.setAttribute(Xfade4.sync, 1);
	Xfade5.setAttribute(Xfade5.sync, 1);
	Xfade6.setAttribute(Xfade6.sync, 1);
	Xfade7.setAttribute(Xfade7.sync, 1);
	Xfade8.setAttribute(Xfade8.sync, 1);
	XfTempo.showControl(0);  
	XfTempo2.showControl(1);   
	synclabel2.showControl(0);  
	freelabel2.showControl(1);   
	 
	 }
	 
	 if(value == 1)
	 	{
	Xfade1.setAttribute(Xfade1.sync, 0);
	Xfade2.setAttribute(Xfade2.sync, 0);
	Xfade3.setAttribute(Xfade3.sync, 0);
	Xfade4.setAttribute(Xfade4.sync, 0);
	Xfade5.setAttribute(Xfade5.sync, 0);
	Xfade6.setAttribute(Xfade6.sync, 0);
	Xfade7.setAttribute(Xfade7.sync, 0);
	Xfade8.setAttribute(Xfade8.sync, 0);
	XfTempo.showControl(1);  
	XfTempo2.showControl(0);   
	synclabel2.showControl(1);  
	freelabel2.showControl(0); 
	}

	 
};

Content.getComponent("Xfsync").setControlCallback(onXfsyncControl);



const var harmscaleA1 = Synth.getModulator("harmscaleA1");
const var harmscaleA2 = Synth.getModulator("harmscaleA2");
const var harmscaleA3 = Synth.getModulator("harmscaleA3");
const var harmscaleA4 = Synth.getModulator("harmscaleA4");
const var harmscaleA5 = Synth.getModulator("harmscaleA5");
const var harmscaleA6 = Synth.getModulator("harmscaleA6");
const var harmscaleA7 = Synth.getModulator("harmscaleA7");
const var harmscaleA8 = Synth.getModulator("harmscaleA8");



inline function onPitchModeControl(component, value)
{
	harmscaleA1.setAttribute(harmscaleA1.Mode, value);
	harmscaleA2.setAttribute(harmscaleA2.Mode, value);
	harmscaleA3.setAttribute(harmscaleA3.Mode, value);
	harmscaleA4.setAttribute(harmscaleA4.Mode, value);
	harmscaleA5.setAttribute(harmscaleA5.Mode, value);
	harmscaleA6.setAttribute(harmscaleA6.Mode, value);
	harmscaleA7.setAttribute(harmscaleA7.Mode, value);
	harmscaleA8.setAttribute(harmscaleA8.Mode, value);

};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);

const var XfTable1 = Synth.getTableProcessor("Xfade1");
const var XfTable2 = Synth.getTableProcessor("Xfade2");
const var XfTable3 = Synth.getTableProcessor("Xfade3");
const var XfTable4 = Synth.getTableProcessor("Xfade4");
const var XfTable5 = Synth.getTableProcessor("Xfade5");
const var XfTable6 = Synth.getTableProcessor("Xfade6");
const var XfTable7 = Synth.getTableProcessor("Xfade7");
const var XfTable8 = Synth.getTableProcessor("Xfade8");

XfTable1.getTable(0).linkTo(XfTable2.getTable(0));

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
 