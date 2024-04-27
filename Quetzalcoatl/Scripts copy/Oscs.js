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

const var HarmBsp = [Content.getComponent("HarmSpB1"),
                     Content.getComponent("HarmSpB2"),
                     Content.getComponent("HarmSpB3"),
                     Content.getComponent("HarmSpB4"),
                     Content.getComponent("HarmSpB5"),
                     Content.getComponent("HarmSpB6"),
                     Content.getComponent("HarmSpB7"),
                     Content.getComponent("HarmSpB8")];


inline function onPitchBmasterControl(component, value)
{
	for(s in HarmBsp)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("PitchBmaster").setControlCallback(onPitchBmasterControl);


const var Groups = [Synth.getChildSynth("Group1"), Synth.getChildSynth("Group2"), Synth.getChildSynth("Group3"), Synth.getChildSynth("Group4"),Synth.getChildSynth("Group5"), Synth.getChildSynth("Group6"),  Synth.getChildSynth("Group7"), Synth.getChildSynth("Group8"), Synth.getChildSynth("LoopGroup1"), Synth.getChildSynth("LoopGroup2"), Synth.getChildSynth("LoopGroup3"), Synth.getChildSynth("LoopGroup4"), Synth.getChildSynth("LoopGroup5"), Synth.getChildSynth("LoopGroup6"), Synth.getChildSynth("LoopGroup7"), Synth.getChildSynth("LoopGroup8"), Synth.getChildSynth("WtGroup1"), Synth.getChildSynth("WtGroup2"), Synth.getChildSynth("WtGroup3"),Synth.getChildSynth("WtGroup4"),Synth.getChildSynth("WtGroup5"),Synth.getChildSynth("WtGroup6"),Synth.getChildSynth("WtGroup7"),Synth.getChildSynth("WtGroup8")];

const var Osc2 = [Synth.getChildSynth("SamplerB1"),
				  Synth.getChildSynth("SamplerB2"),
				  Synth.getChildSynth("SamplerB3"),
				  Synth.getChildSynth("SamplerB4"),
				  Synth.getChildSynth("SamplerB5"),
				  Synth.getChildSynth("SamplerB6"),
				  Synth.getChildSynth("SamplerB7"),
				  Synth.getChildSynth("SamplerB8"),
				  Synth.getChildSynth("LoopB1"),
				  Synth.getChildSynth("LoopB2"),
				  Synth.getChildSynth("LoopB3"),
				  Synth.getChildSynth("LoopB4"),
				  Synth.getChildSynth("LoopB5"),
				  Synth.getChildSynth("LoopB6"),
				  Synth.getChildSynth("LoopB7"),
				  Synth.getChildSynth("LoopB8"),
				  Synth.getChildSynth("WtB1"),
				  Synth.getChildSynth("WtB2"),
				  Synth.getChildSynth("WtB3"),
				  Synth.getChildSynth("WtB4"),
				  Synth.getChildSynth("WtB5"),
				  Synth.getChildSynth("WtB6"),
				  Synth.getChildSynth("WtB7"),
				  Synth.getChildSynth("WtB8")];


const var harmscaleB = [Synth.getModulator("PitchB1"),
						Synth.getModulator("PitchB2"),
						Synth.getModulator("PitchB3"),
						Synth.getModulator("PitchB4"),
						Synth.getModulator("PitchB5"),
						Synth.getModulator("PitchB6"),
						Synth.getModulator("PitchB7"),
						Synth.getModulator("PitchB8")];

inline function onPitchMode1Control(component, value)
{
for(s in harmscaleB)
       s.setAttribute(0, value);
       
};

Content.getComponent("PitchMode1").setControlCallback(onPitchMode1Control);


inline function onHarm2Control(component, value)
{
	for(s in harmscaleB)
       s.setAttribute(1, value);
};

Content.getComponent("Harm2").setControlCallback(onHarm2Control);


inline function onHarmMod2Control(component, value)
{
		for(s in harmscaleB)
       s.setAttribute(2, value);
};

Content.getComponent("HarmMod2").setControlCallback(onHarmMod2Control);


inline function onHarmModSrc2Control(component, value)
{
for(s in harmscaleB)
       s.setAttribute(3, value);
};

Content.getComponent("HarmModSrc2").setControlCallback(onHarmModSrc2Control);

inline function onFmOnControl(component, value)
{

	if(value == 0)
		{
for(s in Groups)
	       s.setAttribute(4, 0);
	 for(s in Groups)
	 	       s.setAttribute(5, 0);
	 for(s in Groups)
	 	 	       s.setAttribute(6, 0);	 
	 	 	       
	 	 	  }       
	if(value == 1)
		{
	for(s in Groups)
		       s.setAttribute(4, 1);
	 for(s in Groups)
	 	       s.setAttribute(5, 1);
	 for(s in Groups)
	 	 	       s.setAttribute(6, 2);	 
	 	 	       
	 	 	  }  	 	      
};

Content.getComponent("FmOn").setControlCallback(onFmOnControl);



inline function onPitchMode1Control(component, value)
{
	for(s in harmscaleB)
	       s.setAttribute(2, value);
};

Content.getComponent("PitchMode1").setControlCallback(onPitchMode1Control);

const var Shape = [Synth.getEffect("Polyshape FX1"),
				   Synth.getEffect("Polyshape FX2"),
  				   Synth.getEffect("Polyshape FX3"),
				     Synth.getEffect("Polyshape FX4"),
				     Synth.getEffect("Polyshape FX5"),
				     Synth.getEffect("Polyshape FX6"),
				     Synth.getEffect("Polyshape FX7"),
				     Synth.getEffect("Polyshape FX8"),
				     Synth.getEffect("Polyshape LP1"),
				     Synth.getEffect("Polyshape LP2"),
				     Synth.getEffect("Polyshape LP3"),
				     Synth.getEffect("Polyshape LP4"),
				     Synth.getEffect("Polyshape LP5"),
				     Synth.getEffect("Polyshape LP6"),
				     Synth.getEffect("Polyshape LP7"),
				     Synth.getEffect("Polyshape LP8"),
				     Synth.getEffect("Polyshape FXWt1"),
				     Synth.getEffect("Polyshape FXWt2"),
				     Synth.getEffect("Polyshape FXWt3"),
				     Synth.getEffect("Polyshape FXWt4"),
				     Synth.getEffect("Polyshape FXWt5"),
				     Synth.getEffect("Polyshape FXWt6"),
				     Synth.getEffect("Polyshape FXWt7"),
				     Synth.getEffect("Polyshape FXWt8")];
				     
					
inline function onOsc2DriveControl(component, value)
{
		for(s in Shape)
	       s.setAttribute(0, value);
		
};

Content.getComponent("Osc2Drive").setControlCallback(onOsc2DriveControl);


inline function onShapeModeControl(component, value)
{
	
	if(value == 1)
	{
for(s in Shape)
	       s.setAttribute(1, 1);
	       }
	 if(value == 2)
	 {
	 for(s in Shape)
	        s.setAttribute(1, 2);
	        }       
	if(value == 3)
		 {
		 for(s in Shape)
		        s.setAttribute(1, 4);
		        }
	if(value == 4)
		 {
		 for(s in Shape)
		        s.setAttribute(1, 5);
		        }     
	if(value == 5)
		 {
		 for(s in Shape)
		        s.setAttribute(1, 9);
		        }
	if(value == 6)
		 {
		 for(s in Shape)
		        s.setAttribute(1, 10);
		        }
	if(value == 7)
		 {
		 for(s in Shape)
		        s.setAttribute(1, 11);
		        }  
	if(value == 8)
		 {
		 for(s in Shape)
		        s.setAttribute(1, 12);
		        }                	                                         
};

Content.getComponent("ShapeMode").setControlCallback(onShapeModeControl);

const var FmPolyGain1 = Synth.getModulator("FmPolyGain1");
const var FmPolyGain2 = Synth.getModulator("FmPolyGain2");
const var FmPolyGain3 = Synth.getModulator("FmPolyGain3");
const var FmPolyGain4 = Synth.getModulator("FmPolyGain4");
const var FmPolyGain5 = Synth.getModulator("FmPolyGain5");
const var FmPolyGain6 = Synth.getModulator("FmPolyGain6");
const var FmPolyGain7 = Synth.getModulator("FmPolyGain7");
const var FmPolyGain8 = Synth.getModulator("FmPolyGain8");

const var GlobalFmGains = Synth.getModulator("GlobalFmGains");

const var PolyGain = [Synth.getModulator("FmPolyGain1"),
					  Synth.getModulator("FmPolyGain2"),
					  Synth.getModulator("FmPolyGain3"),
					  Synth.getModulator("FmPolyGain4"),
					  Synth.getModulator("FmPolyGain5"),
					  Synth.getModulator("FmPolyGain6"),
					  Synth.getModulator("FmPolyGain7"),
					  Synth.getModulator("FmPolyGain8")];
					  
const var MonoGain = [Synth.getModulator("GlobalFmGain1"),
					  Synth.getModulator("GlobalFmGain2"),
					  Synth.getModulator("GlobalFmGain3"),
					  Synth.getModulator("GlobalFmGain4"),
					  Synth.getModulator("GlobalFmGain5"),
					  Synth.getModulator("GlobalFmGain6"),
					  Synth.getModulator("GlobalFmGain7"),
					  Synth.getModulator("GlobalFmGain8")];


inline function onFmGainControl(component, value)
{
	FmPolyGain1.setAttribute(FmPolyGain1.FmGain, value);
	FmPolyGain2.setAttribute(FmPolyGain2.FmGain, value);
	FmPolyGain3.setAttribute(FmPolyGain3.FmGain, value);
	FmPolyGain4.setAttribute(FmPolyGain4.FmGain, value);
	FmPolyGain5.setAttribute(FmPolyGain5.FmGain, value);
	FmPolyGain6.setAttribute(FmPolyGain6.FmGain, value);
	FmPolyGain7.setAttribute(FmPolyGain7.FmGain, value);
	FmPolyGain8.setAttribute(FmPolyGain8.FmGain, value);
	
	GlobalFmGains.setAttribute(GlobalFmGains.FmGain, value);
};

Content.getComponent("FmGain").setControlCallback(onFmGainControl);



inline function onFmGainModControl(component, value)
{
	FmPolyGain1.setAttribute(FmPolyGain1.FmMod, value);
	FmPolyGain2.setAttribute(FmPolyGain2.FmMod, value);
	FmPolyGain3.setAttribute(FmPolyGain3.FmMod, value);
	FmPolyGain4.setAttribute(FmPolyGain4.FmMod, value);
	FmPolyGain5.setAttribute(FmPolyGain5.FmMod, value);
	FmPolyGain6.setAttribute(FmPolyGain6.FmMod, value);
	FmPolyGain7.setAttribute(FmPolyGain7.FmMod, value);
	FmPolyGain8.setAttribute(FmPolyGain8.FmMod, value);
	GlobalFmGains.setAttribute(GlobalFmGains.FmMod, value);
	
};

Content.getComponent("FmGainMod").setControlCallback(onFmGainModControl);


inline function onFmGainModSrcControl(component, value)
{
	if(value == 1)
	{
for(s in PolyGain)
	       s.setBypassed(0);
for(s in MonoGain)
	       s.setBypassed(1);	 
GlobalFmGains.setAttribute(GlobalFmGains.Src, 0);	             
	       }
	if(value == 2)
	{
for(s in PolyGain)
	       s.setBypassed(1);
for(s in MonoGain)
	       s.setBypassed(0);	 
GlobalFmGains.setAttribute(GlobalFmGains.Src, 0);	             
	       }
	if(value == 3)
		{
	for(s in PolyGain)
		       s.setBypassed(1);
	for(s in MonoGain)
		       s.setBypassed(0);	 
	GlobalFmGains.setAttribute(GlobalFmGains.Src, 1);	             
		       }
if(value == 4)
		{
	for(s in PolyGain)
		       s.setBypassed(1);
	for(s in MonoGain)
		       s.setBypassed(0);	 
	GlobalFmGains.setAttribute(GlobalFmGains.Src, 2);	             
		       }
if(value == 5)
		{
	for(s in PolyGain)
		       s.setBypassed(1);
	for(s in MonoGain)
		       s.setBypassed(0);	 
	GlobalFmGains.setAttribute(GlobalFmGains.Src, 3);	             
		       }		       
};

Content.getComponent("FmGainModSrc").setControlCallback(onFmGainModSrcControl);


