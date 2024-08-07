Content.makeFrontInterface(825, 690);

Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);
const var rm = Engine.getGlobalRoutingManager();

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


laf.registerFunction("drawPresetBrowserListItem", function(g, obj)
{
	
	g.setFont("Montserrat",14);

	g.setColour(Colours.black);
	g.drawAlignedText("  "+ obj.text, obj.area, "left");
	
    if(obj.selected)
    {	
   	 g.setFont("FMontserrat",14);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
        g.fillRoundedRectangle(obj.area,4);
     //   g.setColour(presetOnColour);
        g.drawAlignedText("  " + obj.text, obj.area, "left");
    } 

});

laf.registerFunction("drawDialogButton", function(g, obj)
{

//g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
//  g.drawRoundedRectangle(obj.area, 3.0, 3.0);
  g.setColour(0xFF22251D);
 g.fillRoundedRectangle(obj.area,4);
 g.setFont("Montserrat", 18.0);
 

  var a = obj.area;
  g.setColour(0xFFCDB65B);
 g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");
});


//Settings.setVoiceMultiplier(4);


include("Samples.js");
include("Filters.js");
include("Mod.js");
include("Xfade.js");
include("OutPuts.js");
include("Const.js");
include("Misc.js");

const var Pres = [Synth.getEffect("pre1"),
					Synth.getEffect("pre2"),
					Synth.getEffect("pre3"),
					Synth.getEffect("pre4"),
					Synth.getEffect("pre5"),
					Synth.getEffect("pre6"),
					Synth.getEffect("pre7"),
					Synth.getEffect("pre8")];


inline function onPreOffControl(component, value)
{
	
for(s in Pres)
       s.setAttribute(0, value);
};

Content.getComponent("PreOff").setControlCallback(onPreOffControl);


//Pitch/Harmonic

const var TuningOff = Content.getComponent("TuningOff");

const var Pitches = [Synth.getModulator("PitchA1"),
						Synth.getModulator("PitchA2"),
						Synth.getModulator("PitchA3"),
						Synth.getModulator("PitchA4"),
						Synth.getModulator("PitchA5"),
						Synth.getModulator("PitchA6"),
						Synth.getModulator("PitchA7"),
						Synth.getModulator("PitchA8")];
						
						
inline function onPitchModeControl(component, value)
{
	if(value == 1)
	    	{

   for(s in Pitches)
       s.setAttribute(1, 1);
    for(e in Pitches)
                            e.setBypassed(0);
       TuningOff.showControl(0);
       
       }
       
    if(value == 2)
        	{
    
       for(s in Pitches)
           s.setAttribute(1, 2);
       for(e in Pitches)
                            e.setBypassed(0);
           TuningOff.showControl(0);
           }   
           
      if(value == 3)
             	{
         
            for(s in Pitches)
                s.setAttribute(1, 3);
            for(e in Pitches)
                            e.setBypassed(0);
                TuningOff.showControl(0);
                }      
      if(value == 4)
                  	{
              
                 for(s in Pitches)
                     s.setAttribute(1, 4);
                   for(e in Pitches)
                            e.setBypassed(0);
                     TuningOff.showControl(0);
                     }      
     if(value == 5)
                 	{
             
                for(s in Pitches)
                    s.setAttribute(1, 5);
                    for(e in Pitches)
                            e.setBypassed(0);
                    TuningOff.showControl(0);
                    }   
     if(value == 6)
                      	{
                  
                     for(s in Pitches)
                         s.setAttribute(1, 6);
                         for(e in Pitches)
                            e.setBypassed(0);
                         TuningOff.showControl(0);
                         }   
    if(value == 7)
                         	{
                     
                        for(s in Pitches)
                            s.setAttribute(1, 7);
                       	for(e in Pitches)
                            e.setBypassed(0);
                            TuningOff.showControl(0);
                            }  
     if(value == 8)
                          	{
                      
                         for(s in Pitches)
                             s.setAttribute(1, 8);
                         for(e in Pitches)    
                             e.setBypassed(1);
                             TuningOff.showControl(1);
                             }                                                                                               
};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);						

inline function onHarmControl(component, value)
{
for(s in Pitches)
       s.setAttribute(0, value);
       
};

Content.getComponent("Harm").setControlCallback(onHarmControl);


inline function onHarmGlobalControl(component, value)
{
	 for(s in Pitches)
	 	 	 s.setAttribute(8, value);
};

Content.getComponent("HarmGlobal").setControlCallback(onHarmGlobalControl);


inline function onHarmModSrcControl(component, value)
{

	 for(s in Pitches)
	 	 	 s.setAttribute(9, value);

};

Content.getComponent("HarmModSrc").setControlCallback(onHarmModSrcControl);


inline function onHarmVelControl(component, value)
{
for(s in Pitches)
       s.setAttribute(10, value);
};

Content.getComponent("HarmVel").setControlCallback(onHarmVelControl);

inline function onHarmTrkControl(component, value)
{
for(s in Pitches)
       s.setAttribute(11, value);
};

Content.getComponent("HarmTrk").setControlCallback(onHarmTrkControl);


inline function onHarmAtControl(component, value)
{
for(s in Pitches)
       s.setAttribute(13, value);
};

Content.getComponent("HarmAt").setControlCallback(onHarmAtControl);


const var s1 = Synth.getChildSynth("SamplerA1");





//User Pitches

inline function onUserPitch1Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(31, value);
};

Content.getComponent("UserPitch1").setControlCallback(onUserPitch1Control);

inline function onUserPitch2Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(32, value);
};

Content.getComponent("UserPitch2").setControlCallback(onUserPitch2Control);

inline function onUserPitch3Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(33, value);
};

Content.getComponent("UserPitch3").setControlCallback(onUserPitch3Control);

inline function onUserPitch4Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(34, value);
};

Content.getComponent("UserPitch4").setControlCallback(onUserPitch4Control);

inline function onUserPitch5Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(35, value);
};

Content.getComponent("UserPitch5").setControlCallback(onUserPitch5Control);

inline function onUserPitch6Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(36, value);
};

Content.getComponent("UserPitch6").setControlCallback(onUserPitch6Control);

inline function onUserPitch7Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(37, value);
};

Content.getComponent("UserPitch7").setControlCallback(onUserPitch7Control);

inline function onUserPitch8Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(38, value);
};

Content.getComponent("UserPitch8").setControlCallback(onUserPitch8Control);

inline function onUserPitch9Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(39, value);
};

Content.getComponent("UserPitch9").setControlCallback(onUserPitch9Control);

inline function onUserPitch10Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(40, value);
};

Content.getComponent("UserPitch10").setControlCallback(onUserPitch10Control);

inline function onUserPitch11Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(41, value);
};

Content.getComponent("UserPitch11").setControlCallback(onUserPitch11Control);

inline function onUserPitch12Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(42, value);
};

Content.getComponent("UserPitch12").setControlCallback(onUserPitch12Control);

inline function onUserPitch13Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(43, value);
};

Content.getComponent("UserPitch13").setControlCallback(onUserPitch13Control);

inline function onUserPitch14Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(44, value);
};

Content.getComponent("UserPitch14").setControlCallback(onUserPitch14Control);

inline function onUserPitch15Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(45, value);
};

Content.getComponent("UserPitch15").setControlCallback(onUserPitch15Control);

inline function onUserPitch16Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(46, value);
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




//Mod Sliderpack                         


//Pitch

const var PitchMasterSP = Content.getComponent("PitchMasterSP");

const var PitchSps = [Content.getComponent("PitchSp1"),
                      Content.getComponent("PitchSp2"),
                      Content.getComponent("PitchSp3"),
                      Content.getComponent("PitchSp4"),
                      Content.getComponent("PitchSp5"),
                      Content.getComponent("PitchSp6"),
                      Content.getComponent("PitchSp7"),
                      Content.getComponent("PitchSp8"),
                      Content.getComponent("PitchMasterSP2")];
                      
const var PitchSps2 = [Content.getComponent("PitchSp1"),
                      Content.getComponent("PitchSp2"),
                      Content.getComponent("PitchSp3"),
                      Content.getComponent("PitchSp4"),
                      Content.getComponent("PitchSp5"),
                      Content.getComponent("PitchSp6"),
                      Content.getComponent("PitchSp7"),
                      Content.getComponent("PitchSp8"),
                      Content.getComponent("PitchMasterSP")];
              
const var fSp = Content.getComponent("FmasterSp1");

inline function onPitchMasterSPControl(component, value)
{
	

for(s in PitchSps)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value)); 

	      
};

PitchMasterSP.setControlCallback(onPitchMasterSPControl);


inline function onPitchMasterSP2Control(component, value)
{
	for(s in PitchSps2)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value)); 

};

Content.getComponent("PitchMasterSP2").setControlCallback(onPitchMasterSP2Control);



 
 const var FspA1 = [Content.getComponent("fsp1"),
                    Content.getComponent("fsp2"),
                    Content.getComponent("fsp3"),
                    Content.getComponent("fsp4"),
                    Content.getComponent("fsp5"),
                    Content.getComponent("fsp6"),
                    Content.getComponent("fsp7"),
                    Content.getComponent("fsp8"),
                    Content.getComponent("FilterSp2")];
                    
                    
const var FspB1 = [Content.getComponent("fsp1"),
                   Content.getComponent("fsp2"),
                   Content.getComponent("fsp3"),
                   Content.getComponent("fsp4"),
                   Content.getComponent("fsp5"),
                   Content.getComponent("fsp6"),
                   Content.getComponent("fsp7"),
                   Content.getComponent("fsp8"),
                   Content.getComponent("FmasterSp1")];                    
                    

                    
 

const var FmasterSp1 = Content.getComponent("FmasterSp1");
                    
                                      
                //    const var FmasterSp2 = Content.getComponent("FmasterSp2");
     

inline function onFilterSp2Control(component, value)
{
	for(s in FspB1)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("FilterSp2").setControlCallback(onFilterSp2Control);

const var PitchMasterSP2 = Content.getComponent("PitchMasterSP2");


const var FilterSp2 = Content.getComponent("FilterSp2");
  



//xf



//harm


  

  
const PitchSpData = Engine.createAndRegisterSliderPackData(3);
//const GainSpData = Engine.createAndRegisterSliderPackData(4);
const FilterSpData = Engine.createAndRegisterSliderPackData(5);
const FilterMasterSpData = Engine.createAndRegisterSliderPackData(8);




PitchMasterSP.referToData(PitchSpData);
PitchMasterSP2.referToData(PitchSpData);

FmasterSp1.referToData(FilterMasterSpData);
FilterSp2.referToData(FilterMasterSpData);

const FilterStepModData = Engine.createAndRegisterSliderPackData(2);



const var Loading = Content.getComponent("Loading");

inline function onLoadWavesControl(component, value)
{
	if(value == 1)
	    	{

	Loading.showControl(1);
	}
};

Content.getComponent("LoadWaves").setControlCallback(onLoadWavesControl);




inline function onCloseWavePageControl(component, value)
{
	if(value == 1)
	    	{

	Loading.showControl(0);
	}
};

Content.getComponent("CloseWavePage").setControlCallback(onCloseWavePageControl);


inline function onScriptButton2Control(component, value)
{
	 if(value == 1)
    	{
	SettingsPresets.showControl(0);
	}
};

Content.getComponent("ScriptButton2").setControlCallback(onScriptButton2Control);

const var ScriptFX1 = Synth.getEffect("Script FX1");
const var Chrous = Synth.getEffect("Chrous");
const var Verb = Synth.getEffect("Verb");
const var Delay = Content.getComponent("Delay");
const var Chorus = Content.getComponent("Chorus");
const var ReVerb = Content.getComponent("ReVerb");
const var QImg = Content.getComponent("QImg");


inline function onFxTypeControl(component, value)
{

	 if(value == 1)
    	{
	QImg.showControl(1);
	Delay.showControl(0);
	Chorus.showControl(0);
	ReVerb.showControl(0);
	ScriptFX1.setBypassed(1);
	Chrous.setBypassed(1);
	Verb.setBypassed(1);

	}
	
	if(value == 2)
	    	{
		QImg.showControl(0);
		Delay.showControl(1);
		Chorus.showControl(0);
		ReVerb.showControl(0);
		ScriptFX1.setBypassed(0);
		Chrous.setBypassed(1);
		Verb.setBypassed(1);
	
		}
		
	if(value == 3)
	    	{
		QImg.showControl(0);
		Delay.showControl(0);
		Chorus.showControl(1);
		ReVerb.showControl(0);
		ScriptFX1.setBypassed(1);
		Chrous.setBypassed(0);
		Verb.setBypassed(1);
	
		}
	if(value == 4)
		    	{
			QImg.showControl(0);
			Delay.showControl(0);
			Chorus.showControl(0);
			ReVerb.showControl(1);
			ScriptFX1.setBypassed(1);
			Chrous.setBypassed(1);
			Verb.setBypassed(0);
		
			}
};

Content.getComponent("FxType").setControlCallback(onFxTypeControl);


		
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
 