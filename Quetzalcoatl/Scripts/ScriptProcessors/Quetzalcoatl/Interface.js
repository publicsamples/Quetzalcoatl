Content.makeFrontInterface(1020, 800);

//const s1poly = SamplerA1.setAttribute(6, value ? 2 : 40); 
//const s1fmpoly = Fm2.setAttribute(2, value ? 1 : 40);

Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
Engine.loadAudioFilesIntoPool();

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
   g.setFont("Montserrat", 18.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");

});

//Settings.setVoiceMultiplier(2);
Settings.setZoomLevel(1.05);
include("Samples.js");
include("Xfade.js");
//include("Filter.js");
//include("Osc2.js");
include("osc1.js");

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
  
  
 const var Vel = [Synth.getModulator("Velocity Modulator1"),
 					Synth.getModulator("Velocity Modulator2"),
 					Synth.getModulator("Velocity Modulator3"),
 					Synth.getModulator("Velocity Modulator4"),
 					Synth.getModulator("Velocity Modulator5"),
 					Synth.getModulator("Velocity Modulator6"),
 					Synth.getModulator("Velocity Modulator7"),
 					Synth.getModulator("Velocity Modulator8")];


inline function onAmpVelControl(component, value)
{
	for(s in Vel)
	       s.setIntensity(value);
};

Content.getComponent("AmpVel").setControlCallback(onAmpVelControl);

//FILTER

const var Filters = [Synth.getEffect("F1"),
					Synth.getEffect("F2"),
					Synth.getEffect("F3"),
					Synth.getEffect("F4"),
					Synth.getEffect("F5"),
					Synth.getEffect("F6"),
					Synth.getEffect("F7"),
					Synth.getEffect("F8")];
					

inline function onCut1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(0, value);
};

Content.getComponent("Cut1").setControlCallback(onCut1Control);

inline function onCut2Control(component, value)
{
	for(s in Filters)
       s.setAttribute(1, value);
};

Content.getComponent("Cut2").setControlCallback(onCut2Control);

inline function onRes1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(2, value);
};

Content.getComponent("Res1").setControlCallback(onRes1Control);

inline function onRes2Control(component, value)
{
	for(s in Filters)
       s.setAttribute(3, value);
};

Content.getComponent("Res2").setControlCallback(onRes2Control);

inline function onFilterType1Control(component, value)
{	
		for(s in Filters)
       s.setAttribute(4, value);
};

Content.getComponent("FilterType1").setControlCallback(onFilterType1Control);

inline function onFilterType2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(5, value);

};

Content.getComponent("FilterType2").setControlCallback(onFilterType2Control);

inline function onFilterMix1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(6, value);
};

Content.getComponent("FilterMix1").setControlCallback(onFilterMix1Control);

inline function onFilterMix2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(7, value);
};

Content.getComponent("FilterMix2").setControlCallback(onFilterMix2Control);

inline function onCutMod1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(8, value);

};

Content.getComponent("CutMod1").setControlCallback(onCutMod1Control);


inline function onCutMod2Control(component, value)
{
for(s in Filters)
       s.setAttribute(9, value);
};

Content.getComponent("CutMod2").setControlCallback(onCutMod2Control);


inline function onFilterEnv1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(10, value);
};

Content.getComponent("FilterEnv1").setControlCallback(onFilterEnv1Control);

inline function onFilterEnv2Control(component, value)
{
		for(s in Filters)
       s.setAttribute(11, value);
};

Content.getComponent("FilterEnv2").setControlCallback(onFilterEnv2Control);



inline function onCutModSrc1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(12, value);
};

Content.getComponent("CutModSrc1").setControlCallback(onCutModSrc1Control);

inline function onCutModSrc2Control(component, value)
{
		for(s in Filters)
       s.setAttribute(13, value);
};

Content.getComponent("CutModSrc2").setControlCallback(onCutModSrc2Control);




inline function onFilterA1Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(15, value);
};

Content.getComponent("FilterA1").setControlCallback(onFilterA1Control);

inline function onFilterD1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(16, value);
};

Content.getComponent("FilterD1").setControlCallback(onFilterD1Control);


inline function onFilterS1Control(component, value)
{
for(s in Filters)
       s.setAttribute(17, value);
};

Content.getComponent("FilterS1").setControlCallback(onFilterS1Control);


inline function onFilterR1Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(18, value);
};

Content.getComponent("FilterR1").setControlCallback(onFilterR1Control);
	
	
	



inline function onFilterA2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(19, value);
};

Content.getComponent("FilterA2").setControlCallback(onFilterA2Control);



inline function onFilterD2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(20, value);
};

Content.getComponent("FilterD2").setControlCallback(onFilterD2Control);

inline function onFilterS2Control(component, value)
{
		for(s in Filters)
       s.setAttribute(21, value);
};


Content.getComponent("FilterS2").setControlCallback(onFilterS2Control);
				
inline function onFilterR2Control(component, value)
{
		for(s in Filters)
	       s.setAttribute(22, value);
};

Content.getComponent("FilterR2").setControlCallback(onFilterR2Control);

const var FspA1 = [Content.getComponent("fsp1"),
                   Content.getComponent("fsp2"),
                   Content.getComponent("fsp3"),
                   Content.getComponent("fsp4"),
                   Content.getComponent("fsp5"),
                   Content.getComponent("fsp6"),
                   Content.getComponent("fsp7"),
                   Content.getComponent("fsp8"),
                   Content.getComponent("fsp9")];


inline function onFmasterSp1Control(component, value)
{
	for(s in FspA1)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("FmasterSp1").setControlCallback(onFmasterSp1Control);

const var FspA2 = [Content.getComponent("fsp10"),
                   Content.getComponent("fsp11"),
                   Content.getComponent("fsp12"),
                   Content.getComponent("fsp13"),
                   Content.getComponent("fsp14"),
                   Content.getComponent("fsp15"),
                   Content.getComponent("fsp16"),
                   Content.getComponent("fsp17"),
                   Content.getComponent("fsp18")];


inline function onFmasterSp2Control(component, value)
{
		for(s in FspA2)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("FmasterSp2").setControlCallback(onFmasterSp2Control);

const var Fenv1 = Content.getComponent("Fenv1");

const var Fenv2 = Content.getComponent("Fenv2");

const var FmasterSp1 = Content.getComponent("FmasterSp1");

const var FmasterSp2 = Content.getComponent("FmasterSp2");




inline function onScriptButton45Control(component, value)
{
 Fenv1.showControl(value);
 FmasterSp1.showControl(1-value);
};

Content.getComponent("ScriptButton45").setControlCallback(onScriptButton45Control);


inline function onScriptButton47Control(component, value)
{
 Fenv2.showControl(value);
 FmasterSp2.showControl(1-value);
};

Content.getComponent("ScriptButton47").setControlCallback(onScriptButton47Control);


//

const var fm = [Synth.getChildSynth("Fm1"),
				Synth.getChildSynth("Fm2"),
				Synth.getChildSynth("Fm3"),
				Synth.getChildSynth("Fm4"),
				Synth.getChildSynth("Fm5"),
				Synth.getChildSynth("Fm6"),
				Synth.getChildSynth("Fm7"),
				Synth.getChildSynth("Fm8")];


inline function onFmMixControl(component, value)
{
	for(s in fm)
	       s.setAttribute(7, value);
};

Content.getComponent("FmMix").setControlCallback(onFmMixControl);


inline function onFmTrackControl(component, value)
{
	for(s in fm)
	       s.setAttribute(14, value);
};

Content.getComponent("FmTrack").setControlCallback(onFmTrackControl);


inline function onAMControl(component, value)
{
		for(s in fm)
	       s.setAttribute(8, value);
};

Content.getComponent("AM").setControlCallback(onAMControl);


inline function onAmModControl(component, value)
{
	for(s in fm)
	       s.setAttribute(9, value);
};

Content.getComponent("AmMod").setControlCallback(onAmModControl);


inline function onAmMordSrcControl(component, value)
{
	for(s in fm)
	       s.setAttribute(10, value);
};

Content.getComponent("AmMordSrc").setControlCallback(onAmMordSrcControl);



inline function onadditionalmodeswitchControl(component, value)
{
 WtSliders.showControl(value);
 FmSlider.showControl(1-value);
};

Content.getComponent("additionalmodeswitch").setControlCallback(onadditionalmodeswitchControl);

//mods
const var m1step = Content.getComponent("m1step");
const var m1step1 = Content.getComponent("m1step1");
const var m1step2 = Content.getComponent("m1step2");
const var m1step3 = Content.getComponent("m1step3");
const var m1step4 = Content.getComponent("m1step4");
const var m1step5 = Content.getComponent("m1step5");
const var m1step6 = Content.getComponent("m1step6");
const var m1step7 = Content.getComponent("m1step7");

const var m1table = Content.getComponent("m1table");
const var m1table1 = Content.getComponent("m1table1");
const var m1table2 = Content.getComponent("m1table2");
const var m1table3 = Content.getComponent("m1table3");
const var m1table4 = Content.getComponent("m1table4");
const var m1table5 = Content.getComponent("m1table5");
const var m1table6 = Content.getComponent("m1table6");
const var m1table7 = Content.getComponent("m1table7");


inline function onGmodMode1Control(component, value)
{
	m1step.showControl(value);
    m1table.showControl(1-value);
    Gmod1.setAttribute(Gmod1.modsel, value);
};

Content.getComponent("GmodMode1").setControlCallback(onGmodMode1Control);

inline function onGmodMode2Control(component, value)
{
	m1step1.showControl(value);
    m1table1.showControl(1-value);
    Gmod2.setAttribute(Gmod2.modsel, value);
};

Content.getComponent("GmodMode2").setControlCallback(onGmodMode2Control);

const var Gmod3 = Synth.getModulator("Gmod3");
const var Gmod4 = Synth.getModulator("Gmod4");
const var Gmod5 = Synth.getModulator("Gmod5");
const var Gmod6 = Synth.getModulator("Gmod6");
const var Gmod7 = Synth.getModulator("Gmod7");
const var Gmod8 = Synth.getModulator("Gmod8");


inline function onGmodMode3Control(component, value)
{
	m1step2.showControl(value);
    m1table2.showControl(1-value);
    Gmod3.setAttribute(Gmod3.modsel, value);
};

Content.getComponent("GmodMode3").setControlCallback(onGmodMode3Control);

inline function onGmodMode3Control(component, value)
{
	m1step2.showControl(value);
    m1table2.showControl(1-value);
    Gmod3.setAttribute(Gmod3.modsel, value);
};

Content.getComponent("GmodMode3").setControlCallback(onGmodMode3Control);


inline function onGmodMode4Control(component, value)
{
	m1step3.showControl(value);
    m1table3.showControl(1-value);
    Gmod4.setAttribute(Gmod4.modsel, value);
};

Content.getComponent("GmodMode4").setControlCallback(onGmodMode4Control);


inline function onGmodMode5Control(component, value)
{
	m1step4.showControl(value);
	    m1table4.showControl(1-value);
	    Gmod5.setAttribute(Gmod5.modsel, value);
};

Content.getComponent("GmodMode5").setControlCallback(onGmodMode5Control);


inline function onGmodMode6Control(component, value)
{
	m1step5.showControl(value);
	    m1table5.showControl(1-value);
	    Gmod6.setAttribute(Gmod6.modsel, value);
};

Content.getComponent("GmodMode6").setControlCallback(onGmodMode6Control);


inline function onGmodMode7Control(component, value)
{
	m1step6.showControl(value);
	    m1table6.showControl(1-value);
	    Gmod7.setAttribute(Gmod7.modsel, value);
};

Content.getComponent("GmodMode7").setControlCallback(onGmodMode7Control);


inline function onGmodMode8Control(component, value)
{
	m1step7.showControl(value);
	    m1table7.showControl(1-value);
	    Gmod8.setAttribute(Gmod8.modsel, value);
};

Content.getComponent("GmodMode8").setControlCallback(onGmodMode8Control);

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
 