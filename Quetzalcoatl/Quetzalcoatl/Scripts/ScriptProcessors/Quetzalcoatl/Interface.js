Content.makeFrontInterface(800, 760);

include("Samples.js");
//include("SamplesStd.js");
include("Filters.js");
include("Mod.js");
//include("Xfade.js");
include("XfadeStd.js");
include("OutPuts.js");
include("Misc.js");
include("Expansions.js");
include("Loops.js");
//include("LoopsStd.js");
include("FileMenus.js");
include("SfzImport.js");
include("LfoWaves.js");

//Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);
const var rm = Engine.getGlobalRoutingManager();

for (i = 1; i <= 16; i++)
    rm.getCable("mod" + i);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
Engine.loadAudioFilesIntoPool();

const var laf = Engine.createGlobalScriptLookAndFeel();
const var cBLaf = Content.createLocalLookAndFeel();
Settings.setZoomLevel(0.9);
//Settings.setVoiceMultiplier(8);


cBLaf.registerFunction("drawComboBox", function(g, obj)
{
   g.setColour(obj.bgColour);
	g.fillRect(obj.area);
	g.setColour(obj.textColour);
//	g.drawAlignedText(obj.text, obj.area, "centred");

	g.setFont("Montserrat", 12.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});


const var Modes=[
Content.getComponent("FilterType1"),
Content.getComponent("ModPage1"),
Content.getComponent("GmodMode1"),
Content.getComponent("GmodMode2"),
Content.getComponent("GmodMode3"),
Content.getComponent("GmodMode4"),
Content.getComponent("GmodMode5"),
Content.getComponent("GmodMode6"),
Content.getComponent("GmodMode7"),
Content.getComponent("GmodMode8"),
Content.getComponent("GmodMode9"),
Content.getComponent("GmodMode10"),
Content.getComponent("GmodMode11"),
Content.getComponent("GmodMode12"),
Content.getComponent("GmodMode13"),
Content.getComponent("GmodMode14"),
Content.getComponent("GmodMode15"),
Content.getComponent("GmodMode16"),
Content.getComponent("ModPage2"),
Content.getComponent("TrigMode38"),
Content.getComponent("TrigMode51"),
Content.getComponent("ScriptComboBox30"),
Content.getComponent("ScriptComboBox4"),
Content.getComponent("ScriptComboBox5"),
Content.getComponent("ScriptComboBox6"),
Content.getComponent("ScriptComboBox7"),
Content.getComponent("ScriptComboBox8"),
Content.getComponent("ScriptComboBox9"),
Content.getComponent("ScriptComboBox10"),
Content.getComponent("ScriptComboBox11"),
Content.getComponent("ScriptComboBox12"),
Content.getComponent("ScriptComboBox13"),
Content.getComponent("ScriptComboBox14"),
Content.getComponent("ScriptComboBox15"),
Content.getComponent("ScriptComboBox16"),
Content.getComponent("ScriptComboBox17"),
Content.getComponent("ScriptComboBox18"),
Content.getComponent("ScriptComboBox19"),
Content.getComponent("ScriptComboBox20"),
Content.getComponent("ScriptComboBox21"),
Content.getComponent("ScriptComboBox22"),
Content.getComponent("ScriptComboBox23"),
Content.getComponent("ScriptComboBox24"),
Content.getComponent("ScriptComboBox25"),
Content.getComponent("ScriptComboBox26"),
Content.getComponent("ScriptComboBox27"),
Content.getComponent("ScriptComboBox32"),
Content.getComponent("ScriptComboBox33"),
Content.getComponent("ScriptComboBox34"),
Content.getComponent("ScriptComboBox35"),
Content.getComponent("ScriptComboBox36"),
Content.getComponent("ScriptComboBox37"),
Content.getComponent("ScriptComboBox38"),
Content.getComponent("ScriptComboBox39"),
Content.getComponent("TrigMode19"),
Content.getComponent("TrigMode20"),
Content.getComponent("TrigMode36"),
Content.getComponent("TrigMode37"),
Content.getComponent("TrigMode21"),
Content.getComponent("TrigMode22"),
Content.getComponent("TrigMode38"),
Content.getComponent("TrigMode39"),
Content.getComponent("TrigMode23"),
Content.getComponent("TrigMode24"),
Content.getComponent("TrigMode40"),
Content.getComponent("TrigMode41"),
Content.getComponent("TrigMode25"),
Content.getComponent("TrigMode26"),
Content.getComponent("TrigMode42"),
Content.getComponent("TrigMode43"),
Content.getComponent("TrigMode27"),
Content.getComponent("TrigMode28"),
Content.getComponent("TrigMode44"),
Content.getComponent("TrigMode45"),
Content.getComponent("TrigMode29"),
Content.getComponent("TrigMode30"),
Content.getComponent("TrigMode46"),
Content.getComponent("TrigMode47"),
Content.getComponent("TrigMode31"),
Content.getComponent("TrigMode32"),
Content.getComponent("TrigMode48"),
Content.getComponent("TrigMode49"),
Content.getComponent("TrigMode33"),
Content.getComponent("TrigMode34"),
Content.getComponent("TrigMode50"),
Content.getComponent("HarmModSrc"),
Content.getComponent("WtScanSrc10"),
Content.getComponent("WtScanSrc9"),
Content.getComponent("FoldModSrc"),
Content.getComponent("ResSrc"),
Content.getComponent("MixSrc"),
Content.getComponent("CutModSrc3"),
Content.getComponent("CutModSrc1"),
Content.getComponent("CutModSrc2"),
Content.getComponent("WtLoad8"),
Content.getComponent("LpLoad1"),
Content.getComponent("WtLoad1"),
Content.getComponent("LpLoad2"),
Content.getComponent("WtLoad2"),
Content.getComponent("LpLoad3"),
Content.getComponent("WtLoad3"),
Content.getComponent("LpLoad4"),
Content.getComponent("WtLoad4"),
Content.getComponent("LpLoad5"),
Content.getComponent("WtLoad5"),
Content.getComponent("LpLoad6"),
Content.getComponent("WtLoad6"),
Content.getComponent("LpLoad7"),
Content.getComponent("WtLoad7"),
Content.getComponent("LpLoad8"),
Content.getComponent("SampleMode1"),
Content.getComponent("WtAll"),
Content.getComponent("WtBank"),
Content.getComponent("XfStages"),
Content.getComponent("Xfsel2"),
Content.getComponent("PitchMode"),
Content.getComponent("Xfsel"),
Content.getComponent("Xfsel1"),
Content.getComponent("LpLoadInt1"),
Content.getComponent("LpLoadUser"),
Content.getComponent("LpLoadInt2"),
Content.getComponent("LpLoadUser1"),
Content.getComponent("LpLoadInt3"),
Content.getComponent("LpLoadUser2"),
Content.getComponent("LpLoadInt4"),
Content.getComponent("LpLoadUser3"),
Content.getComponent("LpLoadInt5"),
Content.getComponent("LpLoadUser4"),
Content.getComponent("LpLoadInt6"),
Content.getComponent("LpLoadUser5"),
Content.getComponent("SfzLoadMenu1"),
Content.getComponent("SfzLoadMenu2"),
Content.getComponent("SfzLoadMenu3"),
Content.getComponent("SfzLoadMenu4"),
Content.getComponent("SfzLoadMenu5"),
Content.getComponent("SfzLoadMenu6"),
Content.getComponent("SfzLoadMenu7"),
Content.getComponent("LpLoadUser6"),
Content.getComponent("LpLoadInt7"),
Content.getComponent("SfzLoadMenu8"),
Content.getComponent("LpLoadUser7"),
Content.getComponent("LpLoadInt8"),
Content.getComponent("LoadAllUserSf"),
Content.getComponent("LoadAllInternal"),
Content.getComponent("LoadAllUser"),
Content.getComponent("BankA8"),
Content.getComponent("LpBank1"),
Content.getComponent("WtBank"),
Content.getComponent("BankA11"),
Content.getComponent("BankA1"),
Content.getComponent("BankA2"),
Content.getComponent("BankA3"),
Content.getComponent("BankA4"),
Content.getComponent("BankA5"),
Content.getComponent("BankA6"),
Content.getComponent("BankA7"),

];       
                   


for(s in Modes)
      s.setLocalLookAndFeel(cBLaf);


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



const var AHDSREnvelope = [Synth.getModulator("AHDSR Envelope1"),
							Synth.getModulator("AHDSR Envelope2"),
							Synth.getModulator("AHDSR Envelope3"),
							Synth.getModulator("AHDSR Envelope4"),
							Synth.getModulator("AHDSR Envelope5"),
							Synth.getModulator("AHDSR Envelope6"),
							Synth.getModulator("AHDSR Envelope7"),
							Synth.getModulator("AHDSR Envelope8"),
							Synth.getModulator("AHDSR Envelope9")];



inline function onATTACK5Control(component, value)
{
	for(s in AHDSREnvelope)
       s.setAttribute(2, value);
};

Content.getComponent("ATTACK5").setControlCallback(onATTACK5Control);


inline function onVolHoldControl(component, value)
{
for(s in AHDSREnvelope)
       s.setAttribute(4, value);
};

Content.getComponent("VolHold").setControlCallback(onVolHoldControl);


inline function onDECAY5Control(component, value)
{
	for(s in AHDSREnvelope)
       s.setAttribute(5, value);
};

Content.getComponent("DECAY5").setControlCallback(onDECAY5Control);


inline function onSUSTAIN5Control(component, value)
{
		for(s in AHDSREnvelope)
       s.setAttribute(6, value);
};

Content.getComponent("SUSTAIN5").setControlCallback(onSUSTAIN5Control);


inline function onRELEASE5Control(component, value)
{
	for(s in AHDSREnvelope)
       s.setAttribute(7, value);
};

Content.getComponent("RELEASE5").setControlCallback(onRELEASE5Control);



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
       s.setAttribute(s.TuneMode, 0);
    for(e in Pitches)
                            e.setBypassed(0);
       TuningOff.showControl(0);
       
       }
       
    if(value == 2)
        	{
    
       for(s in Pitches)
           s.setAttribute(s.TuneMode, 1);
       for(e in Pitches)
                            e.setBypassed(0);
           TuningOff.showControl(0);
           }   
           
      if(value == 3)
             	{
         
            for(s in Pitches)
                s.setAttribute(s.TuneMode, 2);
            for(e in Pitches)
                            e.setBypassed(0);
                TuningOff.showControl(0);
                }      
      if(value == 4)
                  	{
              
                 for(s in Pitches)
                     s.setAttribute(s.TuneMode, 3);
                   for(e in Pitches)
                            e.setBypassed(0);
                     TuningOff.showControl(0);
                     }      
     if(value == 5)
                 	{
             
                for(s in Pitches)
                    s.setAttribute(s.TuneMode, 4);
                    for(e in Pitches)
                            e.setBypassed(0);
                    TuningOff.showControl(0);
                    }   
     if(value == 6)
                      	{
                  
                     for(s in Pitches)
                         s.setAttribute(s.TuneMode, 5);
                         for(e in Pitches)
                            e.setBypassed(0);
                         TuningOff.showControl(0);
                         }   
    if(value == 7)
                         	{
                     
                        for(s in Pitches)
                            s.setAttribute(s.TuneMode, 6);
                       	for(e in Pitches)
                            e.setBypassed(0);
                            TuningOff.showControl(0);
                            }  
     if(value == 8)
                          	{
                      
                         for(s in Pitches)
                             s.setAttribute(s.TuneMode, 7);
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


const var LoopAedit = [Synth.getChildSynth("LoopA1"),
						Synth.getChildSynth("LoopA2"),
						Synth.getChildSynth("LoopA3"),
						Synth.getChildSynth("LoopA4"),
						Synth.getChildSynth("LoopA5"),
						Synth.getChildSynth("LoopA6"),
						Synth.getChildSynth("LoopA7"),
						Synth.getChildSynth("LoopA8")];                    
  
  const var UserEdit = [Synth.getChildSynth("User1"),
  						Synth.getChildSynth("User2"),
  						Synth.getChildSynth("User3"),
  						Synth.getChildSynth("User4"),
  						Synth.getChildSynth("User5"),
  						Synth.getChildSynth("User6"),
  						Synth.getChildSynth("User7"),
  						Synth.getChildSynth("User8")];    

const var SampleEdit = [Synth.getChildSynth("SamplerA1"),
  						Synth.getChildSynth("SamplerA2"),
  						Synth.getChildSynth("SamplerA3"),
  						Synth.getChildSynth("SamplerA4"),
  						Synth.getChildSynth("SamplerA5"),
  						Synth.getChildSynth("SamplerA6"),
  						Synth.getChildSynth("SamplerA7"),
  						Synth.getChildSynth("SamplerA8")];    
  						
const var SfzEdit = [Synth.getChildSynth("Sfz1"),
  						Synth.getChildSynth("Sfz2"),
  						Synth.getChildSynth("Sfz3"),
  						Synth.getChildSynth("Sfz4"),
  						Synth.getChildSynth("Sfz5"),
  						Synth.getChildSynth("Sfz6"),
  						Synth.getChildSynth("Sfz7"),
  						Synth.getChildSynth("Sfz8")];  
  
   const var WtTimeMod = [Synth.getModulator("WtTimeMod1"),
   							Synth.getModulator("WtTimeMod2"),
   							Synth.getModulator("WtTimeMod3"),
   							Synth.getModulator("WtTimeMod4"),
   							Synth.getModulator("WtTimeMod5"),
   							Synth.getModulator("WtTimeMod6"),
   							Synth.getModulator("WtTimeMod7"),
   							Synth.getModulator("WtTimeMod8")];
   
inline function onWaveReverseControl(component, value)
{

             for(s in LoopAedit)
             s.setAttribute(s.Reversed, value);
};

Content.getComponent("WaveReverse").setControlCallback(onWaveReverseControl);

inline function onWaveLoopControl(component, value)
{
	 for(s in LoopAedit)
             s.setAttribute(s.LoopEnabled, value);
};

Content.getComponent("WaveLoop").setControlCallback(onWaveLoopControl);


inline function onWavetrackControl(component, value)
{
for(s in LoopAedit)
             s.setAttribute(s.PitchTracking, value);
};

Content.getComponent("Wavetrack").setControlCallback(onWavetrackControl);


inline function onUserReverseControl(component, value)
{
for(s in UserEdit)
             s.setAttribute(s.Reversed, value);
};

Content.getComponent("UserReverse").setControlCallback(onUserReverseControl);


inline function onUserLoopControl(component, value)
{
	 for(s in UserEdit)
             s.setAttribute(s.LoopEnabled, value);
};

Content.getComponent("UserLoop").setControlCallback(onUserLoopControl);


inline function onUsertrackControl(component, value)
{
	 for(s in UserEdit)
             s.setAttribute(s.PitchTracking, value);
};

Content.getComponent("Usertrack").setControlCallback(onUsertrackControl);



inline function onWaveReverse3Control(component, value)
{
	 for(s in SampleEdit)
             s.setAttribute(s.Reversed, value);
};

Content.getComponent("WaveReverse3").setControlCallback(onWaveReverse3Control);


inline function onMultiTrackControl(component, value)
{
	
	 for(s in SampleEdit)
             s.setAttribute(s.PitchTracking, value);
};

Content.getComponent("MultiTrack").setControlCallback(onMultiTrackControl);


inline function onSfzTrackControl(component, value)
{
	 for(s in SfzEdit)
             s.setAttribute(s.PitchTracking, value);
};

Content.getComponent("SfzTrack").setControlCallback(onSfzTrackControl);


inline function onWaveReverse4Control(component, value)
{
	 for(s in SfzEdit)
             s.setAttribute(s.Reversed, value);
};

Content.getComponent("WaveReverse4").setControlCallback(onWaveReverse4Control);


inline function onWtSmooth9Control(component, value)
{
	for(s in WtTimeMod)
	s.setAttribute(s.Smooth, value);
	
};

Content.getComponent("WtSmooth9").setControlCallback(onWtSmooth9Control);


inline function onWtSmoothModeControl(component, value)
{
		for(s in WtTimeMod)
	s.setAttribute(s.SmoothMode, value);
	
};

Content.getComponent("WtSmoothMode").setControlCallback(onWtSmoothModeControl);

const var LegatowithRetrigger1 = Synth.getMidiProcessor("Legato with Retrigger1");

inline function onGatePage4Control(component, value)
{

	 
	 LegatowithRetrigger1.setBypassed(1-value);

	
};

Content.getComponent("GatePage4").setControlCallback(onGatePage4Control);



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
 