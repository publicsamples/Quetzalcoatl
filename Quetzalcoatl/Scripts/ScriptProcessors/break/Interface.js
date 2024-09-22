Content.makeFrontInterface(800, 760);

include("Samples.js");
include("Filters.js");
include("Mod.js");
include("Xfade.js");
include("OutPuts.js");
include("Misc.js");
include("Expansions.js");
include("Loops.js");
include("FileMenus.js");
include("SfzImport.js");
include("LfoWaves.js");

Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);
const var rm = Engine.getGlobalRoutingManager();

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
Engine.loadAudioFilesIntoPool();

const var laf = Engine.createGlobalScriptLookAndFeel();


laf.registerFunction("drawComboBox", function(g, obj)
{
  	g.setColour(obj.bgColour);
	g.fillRect(obj.area);
	g.setColour(obj.textColour);
//	g.drawAlignedText(obj.text, obj.area, "centred");

	g.setFont("Montserrat", 12.0);
   
  
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
       s.setAttribute(s.TuneMode, 1);
    for(e in Pitches)
                            e.setBypassed(0);
       TuningOff.showControl(0);
       
       }
       
    if(value == 2)
        	{
    
       for(s in Pitches)
           s.setAttribute(s.TuneMode, 2);
       for(e in Pitches)
                            e.setBypassed(0);
           TuningOff.showControl(0);
           }   
           
      if(value == 3)
             	{
         
            for(s in Pitches)
                s.setAttribute(s.TuneMode, 3);
            for(e in Pitches)
                            e.setBypassed(0);
                TuningOff.showControl(0);
                }      
      if(value == 4)
                  	{
              
                 for(s in Pitches)
                     s.setAttribute(s.TuneMode, 4);
                   for(e in Pitches)
                            e.setBypassed(0);
                     TuningOff.showControl(0);
                     }      
     if(value == 5)
                 	{
             
                for(s in Pitches)
                    s.setAttribute(s.TuneMode, 5);
                    for(e in Pitches)
                            e.setBypassed(0);
                    TuningOff.showControl(0);
                    }   
     if(value == 6)
                      	{
                  
                     for(s in Pitches)
                         s.setAttribute(s.TuneMode, 6);
                         for(e in Pitches)
                            e.setBypassed(0);
                         TuningOff.showControl(0);
                         }   
    if(value == 7)
                         	{
                     
                        for(s in Pitches)
                            s.setAttribute(s.TuneMode, 7);
                       	for(e in Pitches)
                            e.setBypassed(0);
                            TuningOff.showControl(0);
                            }  
     if(value == 8)
                          	{
                      
                         for(s in Pitches)
                             s.setAttribute(s.TuneMode, 8);
                         for(e in Pitches)    
                             e.setBypassed(1);
                             TuningOff.showControl(1);
                             }                                                                                               
};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);						



const var s1 = Synth.getChildSynth("SamplerA1");


//Mod Sliderpack                         


              
const var fSp = Content.getComponent("FmasterSp1");



 
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
                    
      
inline function onFilterSp2Control(component, value)
{
	for(s in FspB1)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("FilterSp2").setControlCallback(onFilterSp2Control);

const var PitchMasterSP2 = Content.getComponent("PitchMasterSP2");


const var FilterSp2 = Content.getComponent("FilterSp2");
  

  

const FilterSpData = Engine.createAndRegisterSliderPackData(5);
const FilterMasterSpData = Engine.createAndRegisterSliderPackData(8);



FmasterSp1.referToData(FilterMasterSpData);
FilterSp2.referToData(FilterMasterSpData);

const FilterStepModData = Engine.createAndRegisterSliderPackData(2);

const var ModMatrix = Content.getComponent("ModMatrix");


inline function onModMatrixOpenControl(component, value)
{
	ModMatrix.showControl(value);
	SettingsPresets.showControl(0);  
};

Content.getComponent("ModMatrixOpen").setControlCallback(onModMatrixOpenControl);


const var HarmGlobal =[];

for (i = 0; i < 8; i++)
{
    HarmGlobal[i] = Content.getComponent("HarmGlobal"+(i+1));
}
     
  

inline function onHarmGlobalAllControl(component, value)
{
   for(s in HarmGlobal)
                  s.setValue(value);
                 
         for(s in HarmGlobal)
                  s.changed();
};

Content.getComponent("HarmGlobalAll").setControlCallback(onHarmGlobalAllControl);

const var HarmOffset =[];

for (i = 0; i < 8; i++)
{
    HarmOffset[i] = Content.getComponent("HarmOffset"+(i+1));

}
     

inline function onHarmOffset9Control(component, value)
{
	  for(s in HarmOffset)
                  s.setValue(value);
                 
         for(s in HarmOffset)
                  s.changed();
};

Content.getComponent("HarmOffset9").setControlCallback(onHarmOffset9Control);
						
const var HarmSrc =[];

for (i = 0; i < 8; i++)
{
    HarmSrc[i] = Content.getComponent("HarmSrc"+(i+1));

}
					

inline function onHarmSrc9Control(component, value)
{
	 for(s in HarmSrc)
                  s.setValue(value);
                 
         for(s in HarmSrc)
                  s.changed();
};

Content.getComponent("HarmSrc9").setControlCallback(onHarmSrc9Control);

const var HarmMod =[];

for (i = 0; i < 8; i++)
{
    HarmMod[i] = Content.getComponent("HarmMod"+(i+1));

}		


inline function onHarmMod9Control(component, value)
{
 for(s in HarmMod)
                  s.setValue(value);
                 
         for(s in HarmMod)
                  s.changed();
};

Content.getComponent("HarmMod9").setControlCallback(onHarmMod9Control);
		
const var HarmMode =[];

for (i = 0; i < 8; i++)
{
    HarmMode[i] = Content.getComponent("HarmMode"+(i+1));

}		


inline function onHarmMode9Control(component, value)
{
	for(s in HarmMode)
                  s.setValue(value);
                 
         for(s in HarmMode)
                  s.changed();
};

Content.getComponent("HarmMode9").setControlCallback(onHarmMode9Control);

const var HarmMin =[];

for (i = 0; i < 8; i++)
{
    HarmMin[i] = Content.getComponent("HarmMin"+(i+1));

}		


inline function onHarmMin9Control(component, value)
{
		for(s in HarmMin)
                  s.setValue(value);
                 
         for(s in HarmMin)
                  s.changed();
};

Content.getComponent("HarmMin9").setControlCallback(onHarmMin9Control);

const var HarmMax =[];

for (i = 0; i < 8; i++)
{
    HarmMax[i] = Content.getComponent("HarmMax"+(i+1));

}		


inline function onHarmMax9Control(component, value)
{
		for(s in HarmMax)
                  s.setValue(value);
                 
         for(s in HarmMax)
                  s.changed();
};


Content.getComponent("HarmMax9").setControlCallback(onHarmMax9Control);

const var HarmStep =[];

for (i = 0; i < 8; i++)
{
    HarmStep[i] = Content.getComponent("HarmStep"+(i+1));

}		

inline function onHarmStep9Control(component, value)
{
for(s in HarmStep)
                  s.setValue(value);
                 
         for(s in HarmStep)
                  s.changed();
};

Content.getComponent("HarmStep9").setControlCallback(onHarmStep9Control);

const var WtScan =[];

for (i = 0; i < 8; i++)
{
    WtScan[i] = Content.getComponent("WtScan"+(i+1));

}	

inline function onWtScan9Control(component, value)
{
for(s in WtScan)
                  s.setValue(value);
                 
         for(s in WtScan)
                  s.changed();
};

Content.getComponent("WtScan9").setControlCallback(onWtScan9Control);

const var WtScanSrc =[];

for (i = 0; i < 8; i++)
{
    WtScanSrc[i] = Content.getComponent("WtScanSrc"+(i+1));

}	

inline function onWtScanSrc9Control(component, value)
{
for(s in WtScanSrc)
                  s.setValue(value);
                 
         for(s in WtScanSrc)
                  s.changed();
};

Content.getComponent("WtScanSrc9").setControlCallback(onWtScanSrc9Control);


const var WtMod =[];

for (i = 0; i < 8; i++)
{
    WtMod[i] = Content.getComponent("WtMod"+(i+1));

}	

inline function onWtMod9Control(component, value)
{
	for(s in WtMod)
                  s.setValue(value);
                 
         for(s in WtMod)
                  s.changed();
};

Content.getComponent("WtMod9").setControlCallback(onWtMod9Control);

const var WtSmooth =[];

for (i = 0; i < 8; i++)
{
    WtSmooth[i] = Content.getComponent("WtSmooth"+(i+1));

}	

inline function onWtSmooth9Control(component, value)
{
		for(s in WtSmooth)
                  s.setValue(value);
                 
         for(s in WtSmooth)
                  s.changed();
};

Content.getComponent("WtSmooth9").setControlCallback(onWtSmooth9Control);

const var FmMix =[];

for (i = 0; i < 8; i++)
{
    FmMix[i] = Content.getComponent("FmMix"+(i+1));

}	

inline function onFmMixMasterControl(component, value)
{
		for(s in FmMix)
                  s.setValue(value);
                 
         for(s in FmMix)
                  s.changed();
};

Content.getComponent("FmMixMaster").setControlCallback(onFmMixMasterControl);

const var FmOscBTune =[];

for (i = 0; i < 8; i++)
{
    FmOscBTune[i] = Content.getComponent("FmOscBTune"+(i+1));

}	


inline function onFmOscBTuneMasterControl(component, value)
{
		for(s in FmOscBTune)
                  s.setValue(value);
                 
         for(s in FmOscBTune)
                  s.changed();
};

Content.getComponent("FmOscBTuneMaster").setControlCallback(onFmOscBTuneMasterControl);

const var Osc2Oct =[];

for (i = 0; i < 8; i++)
{
    Osc2Oct[i] = Content.getComponent("Osc2Oct"+(i+1));

}	


inline function onOsc2OctMasterControl(component, value)
{
		for(s in Osc2Oct)
                  s.setValue(value);
                 
         for(s in Osc2Oct)
                  s.changed();
};

Content.getComponent("Osc2OctMaster").setControlCallback(onOsc2OctMasterControl);

const var FmAmount =[];

for (i = 0; i < 8; i++)
{
    FmAmount[i] = Content.getComponent("FmAmount"+(i+1));

}	


inline function onFmAmountMasterControl(component, value)
{
		for(s in FmAmount)
                  s.setValue(value);
                 
         for(s in FmAmount)
                  s.changed();
};

Content.getComponent("FmAmountMaster").setControlCallback(onFmAmountMasterControl);

const var FmMod =[];

for (i = 0; i < 8; i++)
{
    FmMod[i] = Content.getComponent("FmMod"+(i+1));

}	


inline function onFmModMasterControl(component, value)
{
	for(s in FmMod)
                  s.setValue(value);
                 
         for(s in FmMod)
                  s.changed();
};

Content.getComponent("FmModMaster").setControlCallback(onFmModMasterControl);

const var FmSrc =[];

for (i = 0; i < 8; i++)
{
    FmSrc[i] = Content.getComponent("FmSrc"+(i+1));

}	


inline function onFmSrcMasterControl(component, value)
{
	for(s in FmSrc)
                  s.setValue(value);
                 
         for(s in FmSrc)
                  s.changed();
};

Content.getComponent("FmSrcMaster").setControlCallback(onFmSrcMasterControl);

const var AmMod =[];

for (i = 0; i < 8; i++)
{
    AmMod[i] = Content.getComponent("AmMod"+(i+1));

}	

inline function onAmModMasterControl(component, value)
{
	for(s in AmMod)
                  s.setValue(value);
                 
         for(s in AmMod)
                  s.changed();
};

Content.getComponent("AmModMaster").setControlCallback(onAmModMasterControl);


const var AmSrc =[];

for (i = 0; i < 8; i++)
{
    AmSrc[i] = Content.getComponent("AmSrc"+(i+1));

}	

inline function onAmSrcMasterControl(component, value)
{
		for(s in AmSrc)
                  s.setValue(value);
                 
         for(s in AmSrc)
                  s.changed();
};

Content.getComponent("AmSrcMaster").setControlCallback(onAmSrcMasterControl);

const var AmAmount =[];

for (i = 0; i < 8; i++)
{
    AmAmount[i] = Content.getComponent("AmAmount"+(i+1));

}	


inline function onAmAmountMasterControl(component, value)
{
		for(s in AmAmount)
                  s.setValue(value);
                 
         for(s in AmAmount)
                  s.changed();
};

Content.getComponent("AmAmountMaster").setControlCallback(onAmAmountMasterControl);

const var FmOscAWave =[];

for (i = 0; i < 8; i++)
{
    FmOscAWave[i] = Content.getComponent("FmOscAWave"+(i+1));

}	

inline function onFmOscAWave9Control(component, value)
{
		for(s in FmOscAWave)
                  s.setValue(value);
                 
         for(s in FmOscAWave)
                  s.changed();
};

Content.getComponent("FmOscAWave9").setControlCallback(onFmOscAWave9Control);

const var FmOscBWave =[];

for (i = 0; i < 8; i++)
{
    FmOscBWave[i] = Content.getComponent("FmOscBWave"+(i+1));

}	

inline function onFmOscBWave9Control(component, value)
{
	for(s in FmOscBWave)
                  s.setValue(value);
                 
         for(s in FmOscBWave)
                  s.changed();
};

Content.getComponent("FmOscBWave9").setControlCallback(onFmOscBWave9Control);

const var Folder = Content.getComponent("Folder");
const var WtMaster = Content.getComponent("WtMaster");
const var HarmPitch = Content.getComponent("Harm9");
const var FmAll = Content.getComponent("FmAll");


inline function onVarMenuControl(component, value)
{
		if(value == 1)
	    	{
	Folder.showControl(1);
	WtMaster.showControl(0);
	HarmPitch.showControl(0);
	FmAll.showControl(0);
}
if(value == 2)
    	{
Folder.showControl(0);
WtMaster.showControl(1);
HarmPitch.showControl(0);
FmAll.showControl(0);
}
if(value == 3)
    	{
Folder.showControl(0);
WtMaster.showControl(0);
HarmPitch.showControl(1);
FmAll.showControl(0);
}
if(value == 4)
    	{
Folder.showControl(0);
WtMaster.showControl(0);
HarmPitch.showControl(0);
FmAll.showControl(1);
}

};

Content.getComponent("VarMenu").setControlCallback(onVarMenuControl);

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
 