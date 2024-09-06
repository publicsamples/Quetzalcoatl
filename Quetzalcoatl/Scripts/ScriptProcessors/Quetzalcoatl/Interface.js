Content.makeFrontInterface(810, 760);

include("Samples.js");
include("Filters.js");
include("Mod.js");
include("Xfade.js");
include("OutPuts.js");
include("Const.js");
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
for(s in PitchSps)
    		  s.changed();
	      
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
  

  
const PitchSpData = Engine.createAndRegisterSliderPackData(3);
const FilterSpData = Engine.createAndRegisterSliderPackData(5);
const FilterMasterSpData = Engine.createAndRegisterSliderPackData(8);

PitchMasterSP.referToData(PitchSpData);
PitchMasterSP2.referToData(PitchSpData);

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
 