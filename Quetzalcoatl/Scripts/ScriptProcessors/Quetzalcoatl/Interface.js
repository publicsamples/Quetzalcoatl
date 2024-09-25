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

//Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);
const var rm = Engine.getGlobalRoutingManager();

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
Engine.loadAudioFilesIntoPool();

const var laf = Engine.createGlobalScriptLookAndFeel();
Settings.setZoomLevel(0.92);

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



const var AHDSREnvelope = [Synth.getModulator("AHDSR Envelope1"),
							Synth.getModulator("AHDSR Envelope2"),
							Synth.getModulator("AHDSR Envelope3"),
							Synth.getModulator("AHDSR Envelope4"),
							Synth.getModulator("AHDSR Envelope5"),
							Synth.getModulator("AHDSR Envelope6"),
							Synth.getModulator("AHDSR Envelope7"),
							Synth.getModulator("AHDSR Envelope8")];


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


const var WtScan =[];

for (i = 0; i < 8; i++)
{
    WtScan[i] = Content.getComponent("WtScan"+(i+10));

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
    WtScanSrc[i] = Content.getComponent("WtScanSrc"+(i+10));

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
    WtMod[i] = Content.getComponent("WtMod"+(i+10));

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
    WtSmooth[i] = Content.getComponent("WtSmooth"+(i+10));

}	

inline function onWtSmooth9Control(component, value)
{
		for(s in WtSmooth)
                  s.setValue(value);
                 
         for(s in WtSmooth)
                  s.changed();
};

Content.getComponent("WtSmooth9").setControlCallback(onWtSmooth9Control);

cfunction onNoteOn()
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
 