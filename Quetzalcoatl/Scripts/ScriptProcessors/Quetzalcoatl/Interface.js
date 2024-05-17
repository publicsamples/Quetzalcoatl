Content.makeFrontInterface(870, 725);

 

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
include("Filters.js");
include("Mod.js");
include("Xfade.js");
include("FM.js");
include("Const.js");
include("Misc.js");


//Pitch/Harmonic

const var Pitches = [Synth.getModulator("PitchA1"),
						Synth.getModulator("PitchA2"),
						Synth.getModulator("PitchA3"),
						Synth.getModulator("PitchA4"),
						Synth.getModulator("PitchA5"),
						Synth.getModulator("PitchA6"),
						Synth.getModulator("PitchA7"),
						Synth.getModulator("PitchA8")];
						
						
inline function onHarmControl(component, value)
{
   for(s in Pitches)
       s.setAttribute(2, value);
       
};

Content.getComponent("Harm").setControlCallback(onHarmControl);						

inline function onPitchModeControl(component, value)
{
for(s in Pitches)
       s.setAttribute(3, value);
       
};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);


inline function onHarmEnv1Control(component, value)
{
 for(s in Pitches)
	 	 	 s.setAttribute(7, value);
};

Content.getComponent("HarmEnv1").setControlCallback(onHarmEnv1Control);


inline function onHarmEnv2Control(component, value)
{
	 for(s in Pitches)
	 	 	 s.setAttribute(8, value);
};

Content.getComponent("HarmEnv2").setControlCallback(onHarmEnv2Control);



inline function onHarmModControl(component, value)
{
for(s in Pitches)
       s.setAttribute(9, value);
       
};

Content.getComponent("HarmMod").setControlCallback(onHarmModControl);


inline function onHarmGlobalControl(component, value)
{
	 for(s in Pitches)
	 	 	 s.setAttribute(10, value);
};

Content.getComponent("HarmGlobal").setControlCallback(onHarmGlobalControl);


inline function onHarmModSrcControl(component, value)
{

	 for(s in Pitches)
	 	 	 s.setAttribute(11, value);

};

Content.getComponent("HarmModSrc").setControlCallback(onHarmModSrcControl);


inline function onHarmVelControl(component, value)
{
for(s in Pitches)
       s.setAttribute(12, value);
};

Content.getComponent("HarmVel").setControlCallback(onHarmVelControl);


inline function onHarmTrkControl(component, value)
{
for(s in Pitches)
       s.setAttribute(13, value);
};

Content.getComponent("HarmTrk").setControlCallback(onHarmTrkControl);


inline function onHarmMwControl(component, value)
{for(s in Pitches)
       s.setAttribute(14, value);
};

Content.getComponent("HarmMw").setControlCallback(onHarmMwControl);


inline function onHarmAtControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(15, value);
};

Content.getComponent("HarmAt").setControlCallback(onHarmAtControl);


inline function onHarmTempoControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(16, value);
};

Content.getComponent("HarmTempo").setControlCallback(onHarmTempoControl);


inline function onHarmDivControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(17, value);
};

Content.getComponent("HarmDiv").setControlCallback(onHarmDivControl);


inline function onHarmTrigControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(18, value);
};

Content.getComponent("HarmTrig").setControlCallback(onHarmTrigControl);



inline function onLfoShapeHarmControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(19, value);
};

Content.getComponent("LfoShapeHarm").setControlCallback(onLfoShapeHarmControl);


inline function onHarmAControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(20, value);
};

Content.getComponent("HarmA").setControlCallback(onHarmAControl);


inline function onHarmDControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(21, value);
};

Content.getComponent("HarmD").setControlCallback(onHarmDControl);


inline function onHarmSControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(22, value);
};

Content.getComponent("HarmS").setControlCallback(onHarmSControl);


inline function onHarmRControl(component, value)
{
for(s in Pitches)
       s.setAttribute(23, value);
};

Content.getComponent("HarmR").setControlCallback(onHarmRControl);


inline function onHarmA2Control(component, value)
{
	for(s in Pitches)
	       s.setAttribute(24, value);
};

Content.getComponent("HarmA2").setControlCallback(onHarmA2Control);


inline function onHarmR2Control(component, value)
{
		for(s in Pitches)
	       s.setAttribute(25, value);
};

Content.getComponent("HarmR2").setControlCallback(onHarmR2Control);


inline function onHarmTempo2Control(component, value)
{
		for(s in Pitches)
	       s.setAttribute(26, value);
};

Content.getComponent("HarmTempo2").setControlCallback(onHarmTempo2Control);

inline function onHarmDiv2Control(component, value)
{
		for(s in Pitches)
	       s.setAttribute(27, value);
};

Content.getComponent("HarmDiv2").setControlCallback(onHarmDiv2Control);

inline function onHarmCrvControl(component, value)
{
	for(s in Pitches)
	       s.setAttribute(29, value);
};

Content.getComponent("HarmCrv").setControlCallback(onHarmCrvControl);


inline function onHarmOneControl(component, value)
{
		for(s in Pitches)
	       s.setAttribute(28, value);
};

Content.getComponent("HarmOne").setControlCallback(onHarmOneControl);












const var PitchMasterSP = Content.getComponent("PitchMasterSP");

const var PitchSps = [Content.getComponent("PitchSp1"),
                      Content.getComponent("PitchSp2"),
                      Content.getComponent("PitchSp3"),
                      Content.getComponent("PitchSp4"),
                      Content.getComponent("PitchSp5"),
                      Content.getComponent("PitchSp6"),
                      Content.getComponent("PitchSp7"),
                      Content.getComponent("PitchSp8"),
                      Content.getComponent("PitchSp9"),
                      Content.getComponent("PitchSp10"),
                      Content.getComponent("PitchSp11"),
                      Content.getComponent("PitchSp12"),
                      Content.getComponent("PitchSp13"),
                      Content.getComponent("PitchSp14"),
                      Content.getComponent("PitchSp15"),
                      Content.getComponent("PitchSp16")];
                      


              
const var fSp = Content.getComponent("FmasterSp1");

const SpData3 = Engine.createAndRegisterSliderPackData(2);
const SpData4 = Engine.createAndRegisterSliderPackData(1);   

                      
PitchMasterSP.referToData(SpData1);
fSp.referToData(SpData3);
XfSp.referToData(SpData4);




inline function onPitchMasterSPControl(component, value)
{
	

for(s in PitchSps)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
   

	      
};

PitchMasterSP.setControlCallback(onPitchMasterSPControl);




const var HarmPitch = Content.getComponent("HarmPitch");
const var TableSliders = Content.getComponent("WtSliders");




const var O1Pitch = [Synth.getModulator("p1"),
					 Synth.getModulator("p2"),
					 Synth.getModulator("p3"),
					 Synth.getModulator("p4"),
					 Synth.getModulator("p5"),
					 Synth.getModulator("p6"),
					 Synth.getModulator("p7"),
					 Synth.getModulator("p8")];
					 
					 

inline function onDetuneControl(component, value)
{
	for(s in O1Pitch)
	       s.setIntensity(value);
};

Content.getComponent("Detune").setControlCallback(onDetuneControl);

const var s1 = Synth.getChildSynth("SamplerA1");





//User Pitches

inline function onUserPitch1Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(33, value);
};

Content.getComponent("UserPitch1").setControlCallback(onUserPitch1Control);

inline function onUserPitch2Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(34, value);
};

Content.getComponent("UserPitch2").setControlCallback(onUserPitch2Control);

inline function onUserPitch3Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(35, value);
};

Content.getComponent("UserPitch3").setControlCallback(onUserPitch3Control);

inline function onUserPitch4Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(36, value);
};

Content.getComponent("UserPitch4").setControlCallback(onUserPitch4Control);

inline function onUserPitch5Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(37, value);
};

Content.getComponent("UserPitch5").setControlCallback(onUserPitch5Control);

inline function onUserPitch6Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(38, value);
};

Content.getComponent("UserPitch6").setControlCallback(onUserPitch6Control);

inline function onUserPitch7Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(39, value);
};

Content.getComponent("UserPitch7").setControlCallback(onUserPitch7Control);

inline function onUserPitch8Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(40, value);
};

Content.getComponent("UserPitch8").setControlCallback(onUserPitch8Control);

inline function onUserPitch9Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(41, value);
};

Content.getComponent("UserPitch9").setControlCallback(onUserPitch9Control);

inline function onUserPitch10Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(42, value);
};

Content.getComponent("UserPitch10").setControlCallback(onUserPitch10Control);

inline function onUserPitch11Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(43, value);
};

Content.getComponent("UserPitch11").setControlCallback(onUserPitch11Control);

inline function onUserPitch12Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(44, value);
};

Content.getComponent("UserPitch12").setControlCallback(onUserPitch12Control);

inline function onUserPitch13Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(45, value);
};

Content.getComponent("UserPitch13").setControlCallback(onUserPitch13Control);

inline function onUserPitch14Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(46, value);
};

Content.getComponent("UserPitch14").setControlCallback(onUserPitch14Control);

inline function onUserPitch15Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(47, value);
};

Content.getComponent("UserPitch15").setControlCallback(onUserPitch15Control);

inline function onUserPitch16Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(48, value);
};

Content.getComponent("UserPitch16").setControlCallback(onUserPitch16Control);


const var UserTuners = [Content.getComponent("UserPitch1"),
                        Content.getComponent("UserPitch2"),
                        Content.getComponent("UserPitch3"),
                        Content.getComponent("UserPitch4"),
                        Content.getComponent("UserPitch8"),
                        Content.getComponent("UserPitch7"),
                        Content.getComponent("UserPitch6"),
                        Content.getComponent("UserPitch5"),
                        Content.getComponent("UserPitch9"),
                        Content.getComponent("UserPitch13"),
                        Content.getComponent("UserPitch14"),
                        Content.getComponent("UserPitch10"),
                        Content.getComponent("UserPitch11"),
                        Content.getComponent("UserPitch15"),
                        Content.getComponent("UserPitch16"),
                        Content.getComponent("UserPitch12")];


inline function onTuneModeControl(component, value)
{
	if(value == 0)
	{
		
		for(s in UserTuners)
       s.setRange(-24,24, 1);
       }
       
       if(value == 1)
       {
       	
       	for(s in UserTuners)
              s.setRange(-24, 24, 0.01);
              }
};

Content.getComponent("TuneMode").setControlCallback(onTuneModeControl);


//Mono/Unison

const var Unison = Content.getComponent("Unison");


inline function onmonoControl(component, value)
{
		if(value == 0)
	{
	Unison.showControl(0);
	
	for(s in Groups)
	       s.setAttribute(7, 0);
	
}

if(value == 1)
{
Unison.showControl(1);

for(s in Groups)
       s.setAttribute(7, 16);
}

};


Content.getComponent("mono").setControlCallback(onmonoControl);


inline function onDetControl(component, value)
{
	for(s in Groups)
       s.setAttribute(8, value);
};

Content.getComponent("Det").setControlCallback(onDetControl);



inline function onSprdControl(component, value)
{
	for(s in Groups)
       s.setAttribute(9, value);
};

Content.getComponent("Sprd").setControlCallback(onSprdControl);

const var ModPages = [];
 
 ModPages[0] = Content.getComponent("XfPolyMod");
 ModPages[1] = Content.getComponent("HarmPolyMod");
 ModPages[2] = Content.getComponent("FilterPolyMod");


inline function onPolmodPageControl(component, value)
{
   for (i = 0; i < ModPages.length; i++)
                    ModPages[i].showControl(value - 1 == i);
};

Content.getComponent("PolmodPage").setControlCallback(onPolmodPageControl);




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
 