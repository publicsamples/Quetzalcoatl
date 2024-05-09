

inline function onMODSEL3Control(component, value)

{

	if(value == 1)
	{
	
	Gmod1.setAttribute(Gmod1.modsel, 0);
      mods3[0].showControl(1);  
      mods3[1].showControl(0);   
      mods3[2].showControl(0);  
//      mods3[3].showControl(0);    
         
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





inline function onGainControl(component, value)
{
for(s in Osc1)
       s.setAttribute(0, value);    
};

Content.getComponent("Gain").setControlCallback(onGainControl);


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
for(s in Pitches)
       s.setAttribute(33, value);
       
};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);


inline function onHarmControl(component, value)
{
   for(s in Pitches)
       s.setAttribute(32, value);
       
};

Content.getComponent("Harm").setControlCallback(onHarmControl);


inline function onHarmModControl(component, value)
{
for(s in Pitches)
       s.setAttribute(34, value);
       
};

Content.getComponent("HarmMod").setControlCallback(onHarmModControl);


inline function onHarmModMixControl(component, value)
{
	for(s in Pitches)
	       s.setAttribute(28, value);
};

Content.getComponent("HarmModMix").setControlCallback(onHarmModMixControl);



inline function onHarmModSrcControl(component, value)
{

	 for(s in Pitches)
	 	 	 s.setAttribute(29, value);

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
const var TableSliders = Content.getComponent("WtSliders");




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


const var XfMod = [Content.getComponent("XfSp1"),
                      Content.getComponent("XfSp2"),
                      Content.getComponent("XfSp3"),
                      Content.getComponent("XfSp4"),
                      Content.getComponent("XfSp5"),
                      Content.getComponent("XfSp6"),
                      Content.getComponent("XfSp7"),
             	   	  Content.getComponent("XfSp8")];
                      

inline function onXfSpControl(component, value)
{
for(s in XfMod)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("XfSp").setControlCallback(onXfSpControl);


inline function onHarmVelControl(component, value)
{
for(s in Pitches)
       s.setAttribute(36, value);
};

Content.getComponent("HarmVel").setControlCallback(onHarmVelControl);


inline function onHarmTrkControl(component, value)
{
for(s in Pitches)
       s.setAttribute(37, value);
};

Content.getComponent("HarmTrk").setControlCallback(onHarmTrkControl);


inline function onHarmMwControl(component, value)
{for(s in Pitches)
       s.setAttribute(38, value);
};

Content.getComponent("HarmMw").setControlCallback(onHarmMwControl);


inline function onHarmAtControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(39, value);
};

Content.getComponent("HarmAt").setControlCallback(onHarmAtControl);





