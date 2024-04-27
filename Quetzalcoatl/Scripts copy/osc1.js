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



//misc ui

const var MODSEL3 = Content.getComponent("MODSEL3");
const var MODSEL4 = Content.getComponent("MODSEL4");

//const var Mod1 = Synth.getModulator("Mod1");
//const var Mod2 = Synth.getModulator("Mod2");
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

const var preset = Content.getComponent("preset");

const var SettingsPresets = Content.getComponent("SettingsPresets");


inline function onpresetControl(component, value)
{
	if(value == 0)
		{
	
	      SettingsPresets.showControl(0);  
	  	         
		}

	if(value == 1)
		{
	
	      SettingsPresets.showControl(1);  
	  	         
		}

};

Content.getComponent("preset").setControlCallback(onpresetControl);

const var ExtraMods = Content.getComponent("ExtraMods");
const var modpage = Content.getComponent("modpage");


inline function onmodpageControl(component, value)
{
	if(value == 0)
		{
	
	      ExtraMods.showControl(0);  
	  	         
		}

	if(value == 1)
		{
	
	      ExtraMods.showControl(1);  
	  	         
		}
};

Content.getComponent("modpage").setControlCallback(onmodpageControl);



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


const var LoopLabel1 = Content.getComponent("LoopLabel1");
const var OneShtLabel1 = Content.getComponent("OneShtLabel1");



const var TrigMode3 = Content.getComponent("TrigMode3");
const var FreeLabel1 = Content.getComponent("FreeLabel1");
const var TrigLabel1 = Content.getComponent("TrigLabel1");

inline function onTrigMode3Control(component, value)
{
	
	if(value == 0)
	{
//	Gmod1.setAttribute(Gmod1.trigin, 0);
      FreeLabel1.showControl(0);  
     TrigLabel1.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
//	Gmod1.setAttribute(Gmod1.trigin, 1);
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
//	Gmod2.setAttribute(Gmod2.trigin, 0);
      FreeLabel2.showControl(0);  
     TrigLabel2.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
//	Gmod2.setAttribute(Gmod2.trigin, 1);
      FreeLabel2.showControl(1);  
     TrigLabel2.showControl(0);   
	  
	}


};

Content.getComponent("TrigMode4").setControlCallback(onTrigMode4Control);


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
const var freelabel3 = Content.getComponent("freelabel3");
const var freelabel4 = Content.getComponent("freelabel4");




inline function onsync3Control(component, value)
{
	if(value == 0)
	{
//	Gmod1.setAttribute(Gmod1.sync, 1);
      TempoF3.showControl(0);  
     TempoS3.showControl(1);   
     synclabel3.showControl(0);  
     freelabel3.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
//	Gmod1.setAttribute(Gmod1.sync, 0);
      TempoF3.showControl(1);  
     TempoS3.showControl(0);   
     synclabel3.showControl(1);  
     freelabel3.showControl(0);   
	  
	}
};

Content.getComponent("sync3").setControlCallback(onsync3Control);

inline function onsync4Control(component, value)
{
	if(value == 0)
	{
//	Gmod2.setAttribute(Gmod2.sync, 1);
      TempoF4.showControl(0);  
     TempoS4.showControl(1);   
     synclabel4.showControl(0);  
     freelabel4.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
//	Gmod2.setAttribute(Gmod2.sync, 0);
      TempoF4.showControl(1);  
     TempoS4.showControl(0);   
     synclable4.showControl(1);  
     freelabel4.showControl(0);   
	  
	}
};

Content.getComponent("sync4").setControlCallback(onsync4Control);


//fm osc/group
const var PitchA1 = Synth.getModulator("PitchA1");

//osc1
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
				  Synth.getChildSynth("WtA8")];

inline function onGainControl(component, value)
{
for(s in Osc1)
       s.setAttribute(0, value);    
};

Content.getComponent("Gain").setControlCallback(onGainControl);


const var harmscaleA = [Synth.getModulator("PitchA1"),
						Synth.getModulator("PitchA2"),
						Synth.getModulator("PitchA3"),
						Synth.getModulator("PitchA4"),
						Synth.getModulator("PitchA5"),
						Synth.getModulator("PitchA6"),
						Synth.getModulator("PitchA7"),
						Synth.getModulator("PitchA8")];


inline function onPitchModeControl(component, value)
{
for(s in harmscaleA)
       s.setAttribute(0, value);
       
};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);


inline function onHarmControl(component, value)
{
	for(s in harmscaleA)
       s.setAttribute(1, value);
};

Content.getComponent("Harm").setControlCallback(onHarmControl);


inline function onHarmModControl(component, value)
{
		for(s in harmscaleA)
       s.setAttribute(2, value);
};

Content.getComponent("HarmMod").setControlCallback(onHarmModControl);


inline function onHarmModSrcControl(component, value)
{
for(s in harmscaleA)
       s.setAttribute(3, value);
};

Content.getComponent("HarmModSrc").setControlCallback(onHarmModSrcControl);


const var PitchMasterSP = Content.getComponent("PitchMasterSP");

const var PitchSps = [Content.getComponent("PitchSp2"),
                      Content.getComponent("PitchSp3"),
                      Content.getComponent("PitchSp4"),
                      Content.getComponent("PitchSp5"),
                      Content.getComponent("PitchSp6"),
                      Content.getComponent("PitchSp8"),
                      Content.getComponent("PitchSp7"),
                      Content.getComponent("PitchSp1")];

inline function onPitchMasterSPControl(component, value)
{
for(s in PitchSps)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
	      
};

PitchMasterSP.setControlCallback(onPitchMasterSPControl);


const var HarmPitch = Content.getComponent("HarmPitch");
const var TableSliders = Content.getComponent("TableSliders");


inline function onSliderPanelSwitchControl(component, value)
{
	if(value == 0)
	{

      HarmPitch.showControl(0);  
     TableSliders.showControl(1);   
	          
	}
	
		if(value == 1)
	{
	 
      HarmPitch.showControl(1);  
     TableSliders.showControl(0);   
	  
	}
};

Content.getComponent("SliderPanelSwitch").setControlCallback(onSliderPanelSwitchControl);

const var Gates = Content.getComponent("Gates");
const var GatePage = Content.getComponent("GatePage");



inline function onCloseGatesControl(component, value)
{
	Gates.showControl(0);  
	GatePage.setValue(-1);
    
};

Content.getComponent("CloseGates").setControlCallback(onCloseGatesControl);



inline function onGatePageControl(component, value)
{
	Gates.showControl(value);  
	
};
Content.getComponent("GatePage").setControlCallback(onGatePageControl);

const var ModPg1 = Content.getComponent("ModPg1");
const var ModPg2 = Content.getComponent("ModPg2");


inline function onModPageControl(component, value)
{
	ModPg1.showControl(value); 
	ModPg2.showControl(1-value); 
};

Content.getComponent("ModPage").setControlCallback(onModPageControl);


const var Osc1Env = [Synth.getModulator("AHDSR Envelope1"),
					Synth.getModulator("AHDSR Envelope2"),
					Synth.getModulator("AHDSR Envelope3"),
					Synth.getModulator("AHDSR Envelope4"),
					Synth.getModulator("AHDSR Envelope5"),
					Synth.getModulator("AHDSR Envelope6"),
					Synth.getModulator("AHDSR Envelope7"),
					Synth.getModulator("AHDSR Envelope8")];



inline function onATTACK5Control(component, value)
{
	
	for(s in Osc1Env)
	       s.setAttribute(2, value);

	
};

Content.getComponent("ATTACK5").setControlCallback(onATTACK5Control);


inline function onDECAY5Control(component, value)
{
		for(s in Osc1Env)
	       s.setAttribute(5, value);

};

Content.getComponent("DECAY5").setControlCallback(onDECAY5Control);


inline function onSUSTAIN5Control(component, value)
{
		for(s in Osc1Env)
	       s.setAttribute(6, value);

};

Content.getComponent("SUSTAIN5").setControlCallback(onSUSTAIN5Control);



inline function onRELEASE5Control(component, value)
{
		for(s in Osc1Env)
	       s.setAttribute(7, value);

};

Content.getComponent("RELEASE5").setControlCallback(onRELEASE5Control);





