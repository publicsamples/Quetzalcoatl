Content.makeFrontInterface(870, 740);



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
include("Filters.js");
//include("Osc2.js");
include("osc1.js");
//include("FM.js");
include("GeneralUi.js");
include("Mod.js");
  
  
 



const var FspA1 = [Content.getComponent("fsp1"),
                   Content.getComponent("fsp2"),
                   Content.getComponent("fsp3"),
                   Content.getComponent("fsp4"),
                   Content.getComponent("fsp5"),
                   Content.getComponent("fsp6"),
                   Content.getComponent("fsp7"),
                   Content.getComponent("fsp8"),
                   Content.getComponent("fsp9")];
                   
                   

const var FspA2 = [Content.getComponent("fsp10"),
                   Content.getComponent("fsp11"),
                   Content.getComponent("fsp12"),
                   Content.getComponent("fsp13"),
                   Content.getComponent("fsp14"),
                   Content.getComponent("fsp15"),
                   Content.getComponent("fsp16"),
                   Content.getComponent("fsp17"),
				   Content.getComponent("fsp18")];
                   
                   const var Fenv1 = Content.getComponent("Fenv1");
                   const var Fenv2 = Content.getComponent("Fenv2");
                   const var FmasterSp1 = Content.getComponent("FmasterSp1");
                   const var FmasterSp2 = Content.getComponent("FmasterSp2");
                   
//osc

                   
const var SampleGroups = [Synth.getChildSynth("Group1"),
                     Synth.getChildSynth("Group2"),
                     Synth.getChildSynth("Group3"),
                     Synth.getChildSynth("Group4"),
                     Synth.getChildSynth("Group5"),
                     Synth.getChildSynth("Group6"),
                     Synth.getChildSynth("Group7"),
                     Synth.getChildSynth("Group8")];
                     
                     
const var SampleComp = [ Content.getComponent("SampleWave1"),
                     Content.getComponent("SampleWave2"),
                     Content.getComponent("SampleWave3"),
                     Content.getComponent("SampleWave4"),
                     Content.getComponent("SampleWave5"),
                     Content.getComponent("SampleWave6"),
                     Content.getComponent("SampleWave7"),
                     Content.getComponent("SampleWave8"),
                     Content.getComponent("SampleWave9"),
                     Content.getComponent("Waves1"),
                     Content.getComponent("Waves2"),
                     Content.getComponent("Waves3"),
                     Content.getComponent("Waves4"),
                     Content.getComponent("Waves5"),
                     Content.getComponent("Waves6"),
                     Content.getComponent("Waves7"),
                     Content.getComponent("Waves8"),
                     Content.getComponent("Waves9")];
                     
                     
                     

                     
const var WtComp = [Content.getComponent("Wt1"),
                     Content.getComponent("Wt2"),
                     Content.getComponent("Wt3"),
                     Content.getComponent("Wt4"),
                     Content.getComponent("Wt5"),
                     Content.getComponent("Wt6"),
                     Content.getComponent("Wt7"),
                     Content.getComponent("Wt8"),
                     Content.getComponent("Wt9"),
                     Content.getComponent("TableView1"),
                     Content.getComponent("TableView2"),
                     Content.getComponent("TableView3"),
                     Content.getComponent("TableView4"),
                     Content.getComponent("TableView5"),
                     Content.getComponent("TableView6"),
                     Content.getComponent("TableView7"),
                     Content.getComponent("TableView8"),
                     Content.getComponent("TableView9")];
                     
                     
const var LoopComp = [Content.getComponent("UserWave1"),
                     Content.getComponent("UserWave2"),
                     Content.getComponent("UserWave3"),
                     Content.getComponent("UserWave4"),
                     Content.getComponent("UserWave5"),
                     Content.getComponent("UserWave6"),
                     Content.getComponent("UserWave7"),
                     Content.getComponent("UserWave8"),
                     Content.getComponent("UserWave9"),
                     Content.getComponent("LpControls1"),
                     Content.getComponent("LpControls1"),
                     Content.getComponent("LpControls2"),
                     Content.getComponent("LpControls3"),
                     Content.getComponent("LpControls4"),
                     Content.getComponent("LpControls5"),
                     Content.getComponent("LpControls6"),
                     Content.getComponent("LpControls7"),
                     Content.getComponent("LpControls8"),
                     Content.getComponent("LpControls9")];

const var MODSEL3 = Content.getComponent("MODSEL3");
const var MODSEL4 = Content.getComponent("MODSEL4");

const var Gmod1 = Synth.getModulator("Gmod1");
const var Gmod2 = Synth.getModulator("Gmod2");

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




const var LoopLabel1 = Content.getComponent("LoopLabel1");
const var OneShtLabel1 = Content.getComponent("OneShtLabel1");
const var TrigMode3 = Content.getComponent("TrigMode3");
const var TrigLabel1 = Content.getComponent("TrigLabel1");
const var TempoS3 = Content.getComponent("TempoS3");
const var TempoS4 = Content.getComponent("TempoS4");
const var TempoF3 = Content.getComponent("TempoF3");
const var TempoF4 = Content.getComponent("TempoF4");
const var sync3 = Content.getComponent("sync3");
const var sync4 = Content.getComponent("sync4");
const var synclabel1 = Content.getComponent("synclabel1");
const var synclabel2 = Content.getComponent("synclabel2");
const var synclabel3 = Content.getComponent("synclabel3");
const var synclabel4 = Content.getComponent("synclabel4");
const var freelabel1 = Content.getComponent("freelabel1");
const var freelabel2 = Content.getComponent("freelabel2");


const var Osc1 = [Synth.getChildSynth("SamplerA1"),
				  Synth.getChildSynth("SamplerA2"),
				  Synth.getChildSynth("SamplerA3"),
				  Synth.getChildSynth("SamplerA4"),
				  Synth.getChildSynth("SamplerA5"),
				  Synth.getChildSynth("SamplerA6"),
				  Synth.getChildSynth("SamplerA7"),
				  Synth.getChildSynth("SamplerA8"),
				  Synth.getChildSynth("LoopA1"),
				  Synth.getChildSynth("LoopA2"),
				  Synth.getChildSynth("LoopA3"),
				  Synth.getChildSynth("LoopA4"),
				  Synth.getChildSynth("LoopA5"),
				  Synth.getChildSynth("LoopA6"),
				  Synth.getChildSynth("LoopA7"),
				  Synth.getChildSynth("LoopA8"),
				  Synth.getChildSynth("WtA1"),
				  Synth.getChildSynth("WtA2"),
				  Synth.getChildSynth("WtA3"),
				  Synth.getChildSynth("WtA4"),
				  Synth.getChildSynth("WtA5"),
				  Synth.getChildSynth("WtA6"),
				  Synth.getChildSynth("WtA7"),
				  Synth.getChildSynth("WtA8"),
				  Synth.getChildSynth("LoopA8"),
				  Synth.getChildSynth("Fm1"),
				  Synth.getChildSynth("Fm2"),
				 Synth.getChildSynth("Fm3"),
				  				  Synth.getChildSynth("Fm4"),
				  				  Synth.getChildSynth("Fm5"),
				  				  Synth.getChildSynth("Fm6"),
				  				  Synth.getChildSynth("Fm7"),
				  				  Synth.getChildSynth("Fm8")];


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



const var Gmod3 = Synth.getModulator("Gmod3");
const var Gmod4 = Synth.getModulator("Gmod4");
const var Gmod5 = Synth.getModulator("Gmod5");
const var Gmod6 = Synth.getModulator("Gmod6");
const var Gmod7 = Synth.getModulator("Gmod7");
const var Gmod8 = Synth.getModulator("Gmod8");


const var Vel = [Synth.getModulator("Velocity Modulator1"),
 					Synth.getModulator("Velocity Modulator2"),
 					Synth.getModulator("Velocity Modulator3"),
 					Synth.getModulator("Velocity Modulator4"),
 					Synth.getModulator("Velocity Modulator5"),
 					Synth.getModulator("Velocity Modulator6"),
 					Synth.getModulator("Velocity Modulator7"),
 					Synth.getModulator("Velocity Modulator8")];


const var FmSlotA1 = Synth.getAudioSampleProcessor("Fm1");			
const var FmSlotA2 = Synth.getAudioSampleProcessor("Fm2");		
const var FmSlotA3 = Synth.getAudioSampleProcessor("Fm3");		
const var FmSlotA4 = Synth.getAudioSampleProcessor("Fm4");		
const var FmSlotA5 = Synth.getAudioSampleProcessor("Fm5");		
const var FmSlotA6 = Synth.getAudioSampleProcessor("Fm6");		
const var FmSlotA7 = Synth.getAudioSampleProcessor("Fm7");		
const var FmSlotA8 = Synth.getAudioSampleProcessor("Fm8");	

const var Waves = [];

Waves[0] = Content.getComponent("Wave1");
Waves[1] = Content.getComponent("Wave2");
Waves[2] = Content.getComponent("Wave3");
Waves[3] = Content.getComponent("Wave4");
Waves[4] = Content.getComponent("Wave5");
Waves[5] = Content.getComponent("Wave6");
Waves[6] = Content.getComponent("Wave7");
Waves[7] = Content.getComponent("Wave8");	
	
const slotA1 = FmSlotA1.getAudioFile(0);
const slotB1 = FmSlotA1.getAudioFile(1);
const slotA2 = FmSlotA2.getAudioFile(0);
const slotB2 = FmSlotA2.getAudioFile(1);
const slotA3 = FmSlotA3.getAudioFile(0);
const slotB3 = FmSlotA3.getAudioFile(1);
const slotA4 = FmSlotA4.getAudioFile(0);
const slotB4 = FmSlotA4.getAudioFile(1);
const slotA5 = FmSlotA5.getAudioFile(0);
const slotB5 = FmSlotA5.getAudioFile(1);
const slotA6 = FmSlotA6.getAudioFile(0);
const slotB6 = FmSlotA6.getAudioFile(1);
const slotA7 = FmSlotA7.getAudioFile(0);
const slotB7 = FmSlotA7.getAudioFile(1);
const slotA8 = FmSlotA8.getAudioFile(0);
const slotB8 = FmSlotA8.getAudioFile(1);

const var Sample1 = Content.getComponent("Sample1");
const var Sample2 = Content.getComponent("Sample2");
const var Sample3 = Content.getComponent("Sample3");
const var Sample4 = Content.getComponent("Sample4");
const var Sample5 = Content.getComponent("Sample5");
const var Sample6 = Content.getComponent("Sample6");
const var Sample7 = Content.getComponent("Sample7");
const var Sample8 = Content.getComponent("Sample8");
const var Sample9 = Content.getComponent("Sample9");

const var SamplerA1 = Synth.getSampler("SamplerA1");
const var SamplerA2 = Synth.getSampler("SamplerA2");
const var SamplerA3 = Synth.getSampler("SamplerA3");
const var SamplerA4 = Synth.getSampler("SamplerA4");
const var SamplerA5 = Synth.getSampler("SamplerA5");
const var SamplerA6 = Synth.getSampler("SamplerA6");
const var SamplerA7 = Synth.getSampler("SamplerA7");
const var SamplerA8 = Synth.getSampler("SamplerA8");

const var Groups = [Synth.getChildSynth("Group1"), Synth.getChildSynth("Group2"), Synth.getChildSynth("Group3"), Synth.getChildSynth("Group4"),Synth.getChildSynth("Group5"), Synth.getChildSynth("Group6"),  Synth.getChildSynth("Group7"), Synth.getChildSynth("Group8")];

const var Samplers = [Synth.getChildSynth("SamplerA1"),
					Synth.getChildSynth("SamplerA2"),
					Synth.getChildSynth("SamplerA3"),
					Synth.getChildSynth("SamplerA4"),
					Synth.getChildSynth("SamplerA5"),
					Synth.getChildSynth("SamplerA6"),
					Synth.getChildSynth("SamplerA7"),
					Synth.getChildSynth("SamplerA8")];
					

const var Wts = [Synth.getChildSynth("WtA1"),
				Synth.getChildSynth("WtA2"),
				Synth.getChildSynth("WtA3"),
				Synth.getChildSynth("WtA4"),
				Synth.getChildSynth("WtA5"),
				Synth.getChildSynth("WtA6"),
				Synth.getChildSynth("WtA7"),
				Synth.getChildSynth("WtA8")];
				
const var loops = [Synth.getChildSynth("LoopA2"),
				Synth.getChildSynth("LoopA2"),
				Synth.getChildSynth("LoopA3"),
				Synth.getChildSynth("LoopA4"),
				Synth.getChildSynth("LoopA5"),
				Synth.getChildSynth("LoopA6"),
				Synth.getChildSynth("LoopA7"),
				Synth.getChildSynth("LoopA8")];				


const var Group1 = Synth.getChildSynth("Group1");
const var Group2 = Synth.getChildSynth("Group2");
const var Group3 = Synth.getChildSynth("Group3");
const var Group4 = Synth.getChildSynth("Group4");
const var Group5 = Synth.getChildSynth("Group5");
const var Group6 = Synth.getChildSynth("Group6");
const var Group7 = Synth.getChildSynth("Group7");
const var Group8 = Synth.getChildSynth("Group8");
					
const var WtA1 = Synth.getChildSynth("WtA1");
const var WtA2 = Synth.getChildSynth("WtA2");
const var WtA3 = Synth.getChildSynth("WtA3");
const var WtA4 = Synth.getChildSynth("WtA4");
const var WtA5 = Synth.getChildSynth("WtA5");
const var WtA6 = Synth.getChildSynth("WtA6");
const var WtA7 = Synth.getChildSynth("WtA7");
const var WtA8 = Synth.getChildSynth("WtA8");

const var loop1 = Synth.getChildSynth("LoopA1");
const var loop2 = Synth.getChildSynth("LoopA2");
const var loop3 = Synth.getChildSynth("LoopA3");
const var loop4 = Synth.getChildSynth("LoopA4");
const var loop5 = Synth.getChildSynth("LoopA5");
const var loop6 = Synth.getChildSynth("LoopA6");
const var loop7 = Synth.getChildSynth("LoopA7");
const var loop8 = Synth.getChildSynth("LoopA8");	
	

const var SampleWave1 = Content.getComponent("SamplerWave1");
const var SampleWave2 = Content.getComponent("SamplerWave2");
const var SampleWave3 = Content.getComponent("SamplerWave3");
const var SampleWave4 = Content.getComponent("SamplerWave4");
const var SampleWave5 = Content.getComponent("SamplerWave5");
const var SampleWave6 = Content.getComponent("SamplerWave6");
const var SampleWave7 = Content.getComponent("SamplerWave7");
const var SampleWave8 = Content.getComponent("SamplerWave8");
const var SampleWave9 = Content.getComponent("SamplerWave9");

const var Waves1 = Content.getComponent("Waves1");
const var Waves2 = Content.getComponent("Waves2");
const var Waves3 = Content.getComponent("Waves3");
const var Waves4 = Content.getComponent("Waves4");
const var Waves5 = Content.getComponent("Waves5");
const var Waves6 = Content.getComponent("Waves6");
const var Waves7 = Content.getComponent("Waves7");
const var Waves8 = Content.getComponent("Waves8");
const var Waves9 = Content.getComponent("Waves9"); 
                     
const var Wt1 = Content.getComponent("Wt1");
const var Wt2 = Content.getComponent("Wt2");
const var Wt3 = Content.getComponent("Wt3");
const var Wt4 = Content.getComponent("Wt4");
const var Wt5 = Content.getComponent("Wt5");
const var Wt6 = Content.getComponent("Wt6");
const var Wt7 = Content.getComponent("Wt7");
const var Wt8 = Content.getComponent("Wt8");
const var Wt9 = Content.getComponent("Wt9");

const var TableView1 = Content.getComponent("TableView1");
const var TableView2 = Content.getComponent("TableView2");
const var TableView3 = Content.getComponent("TableView3");
const var TableView4 = Content.getComponent("TableView4");
const var TableView5 = Content.getComponent("TableView5");
const var TableView6 = Content.getComponent("TableView6");
const var TableView7 = Content.getComponent("TableView7");
const var TableView8 = Content.getComponent("TableView8");
const var TableView9 = Content.getComponent("TableView9");
                     
                     
const var UserWave1 = Content.getComponent("UserWave1");
const var UserWave2 = Content.getComponent("UserWave2");
const var UserWave3 = Content.getComponent("UserWave3");
const var UserWave4 = Content.getComponent("UserWave4");
const var UserWave5 = Content.getComponent("UserWave5");
const var UserWave6 = Content.getComponent("UserWave6");
const var UserWave7 = Content.getComponent("UserWave7");
const var UserWave8 = Content.getComponent("UserWave8");
const var UserWave9 = Content.getComponent("UserWave9");

const var LpControls1 = Content.getComponent("LpControls1");
const var LpControls2 = Content.getComponent("LpControls2");
const var LpControls3 = Content.getComponent("LpControls3");
const var LpControls4 = Content.getComponent("LpControls4");
const var LpControls5 = Content.getComponent("LpControls5");
const var LpControls6 = Content.getComponent("LpControls6");
const var LpControls7 = Content.getComponent("LpControls7");
const var LpControls8 = Content.getComponent("LpControls8");
const var LpControls9 = Content.getComponent("LpControls9");


const var Lwav1 = Synth.getAudioSampleProcessor("LoopA1");
const var Lwav2 = Synth.getAudioSampleProcessor("LoopA2");
const var Lwav3 = Synth.getAudioSampleProcessor("LoopA3");
const var Lwav4 = Synth.getAudioSampleProcessor("LoopA4");
const var Lwav5 = Synth.getAudioSampleProcessor("LoopA5");
const var Lwav6 = Synth.getAudioSampleProcessor("LoopA6");
const var Lwav7 = Synth.getAudioSampleProcessor("LoopA7");
const var Lwav8 = Synth.getAudioSampleProcessor("LoopA8");

const var Fm1 = Synth.getChildSynth("Fm1");
const var Fm2 = Synth.getChildSynth("Fm2");
const var Fm3 = Synth.getChildSynth("Fm3");
const var Fm4 = Synth.getChildSynth("Fm4");
const var Fm5 = Synth.getChildSynth("Fm5");
const var Fm6 = Synth.getChildSynth("Fm6");
const var Fm7 = Synth.getChildSynth("Fm7");
const var Fm8 = Synth.getChildSynth("Fm8");

const var WtSliders = Content.getComponent("WtSliders");

const var FmSlider = Content.getComponent("FmSlider");

const var LpSwitches1 = Content.getComponent("LpSwitches1");

const var FmWaves1 = Content.getComponent("FmWaves1");
const var FmWaves2 = Content.getComponent("FmWaves2");
const var FmWaves3 = Content.getComponent("FmWaves3");
const var FmWaves4 = Content.getComponent("FmWaves4");
const var FmWaves5 = Content.getComponent("FmWaves5");
const var FmWaves6 = Content.getComponent("FmWaves6");
const var FmWaves7 = Content.getComponent("FmWaves7");
const var FmWaves8 = Content.getComponent("FmWaves8");

const var ScriptImage2 = Content.getComponent("ScriptImage2");

const var LoopA1 = Synth.getAudioSampleProcessor("LoopA1");
const var LoopA2 = Synth.getAudioSampleProcessor("LoopA2");
const var LoopA3 = Synth.getAudioSampleProcessor("LoopA3");
const var LoopA4 = Synth.getAudioSampleProcessor("LoopA4");
const var LoopA5 = Synth.getAudioSampleProcessor("LoopA5");
const var LoopA6 = Synth.getAudioSampleProcessor("LoopA6");
const var LoopA7 = Synth.getAudioSampleProcessor("LoopA7");
const var LoopA8 = Synth.getAudioSampleProcessor("LoopA8");
const var Sampler1 = Synth.getChildSynth("SamplerA1");
const var Sampler2 = Synth.getChildSynth("SamplerA2");
const var Sampler3 = Synth.getChildSynth("SamplerA3");
const var Sampler4 = Synth.getChildSynth("SamplerA4");
const var Sampler5 = Synth.getChildSynth("SamplerA5");
const var Sampler6 = Synth.getChildSynth("SamplerA6");
const var Sampler7 = Synth.getChildSynth("SamplerA7");
const var Sampler8 = Synth.getChildSynth("SamplerA8");


const var GainSliders = Content.getComponent("GainSliders");





inline function onTablePitchControl(component, value)
{
	
	if(value == 1)
	{

		HarmPitch.showControl(1);
        WtSliders.showControl(0);
        GainSliders.showControl(0);
    
    }
    
    if(value == 2)
    	{
    
    		HarmPitch.showControl(0);
            WtSliders.showControl(0);
            GainSliders.showControl(1);
        
        }
        
        if(value == 3)
        	{
        
        		HarmPitch.showControl(0);
                WtSliders.showControl(1);
                GainSliders.showControl(0);
            
            }
};

Content.getComponent("TablePitch").setControlCallback(onTablePitchControl);

// Multichannel menus
const var MultiChannelTest = Synth.getChildSynth("Quetzalcoatl");



var matrix = MultiChannelTest.getRoutingMatrix();


inline function onOutputSelectorControl(component, value)
{
	
	local success = true;
	
	switch(value)
    {
        case 1: 
            matrix.addConnection(0, 0);
            matrix.addConnection(1, 1);
            matrix.addConnection(3, );
            matrix.addConnection(4, 3);
            break;
        case 2: 
            matrix.addConnection(0, 2);
            
          
            success = matrix.addConnection(1, 3);
            break;
       
    }
    
    if(!success)
    {
        matrix.addConnection(0, 0);
        matrix.addConnection(1, 1);
    }
    
};



Content.getComponent("OutputSelector").setControlCallback(onOutputSelectorControl);



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
 