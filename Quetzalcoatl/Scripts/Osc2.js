



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
       s.setAttribute(32, value);
       
};

Content.getComponent("PitchMode1").setControlCallback(onPitchMode1Control);


inline function onHarm2Control(component, value)
{
	for(s in harmscaleB)
       s.setAttribute(32, value);
};

Content.getComponent("Harm2").setControlCallback(onHarm2Control);


//inline function onHarmMod2Control(component, value)
//{
	//	for(s in harmscaleB)
     //  s.setAttribute(34, value);
//};

//Content.getComponent("HarmMod2").setControlCallback(onHarmMod2Control);


//inline function onHarmModSrc2Control(component, value)
//{
//for(s in harmscaleB)
//       s.setAttribute(29, value);
//};

//Content.getComponent("HarmModSrc2").setControlCallback(onHarmModSrc2Control);



inline function onPitchMode1Control(component, value)
{
	for(s in harmscaleB)
	       s.setAttribute(2, value);
};

Content.getComponent("PitchMode1").setControlCallback(onPitchMode1Control);

const var Shape = [Synth.getEffect("Polyshape FX"),
					Synth.getEffect("Polyshape FX2"),
					Synth.getEffect("Polyshape FX3"),
					Synth.getEffect("Polyshape FX4"),
					Synth.getEffect("Polyshape FX5"),
					Synth.getEffect("Polyshape FX6"),
					Synth.getEffect("Polyshape FX7"),
					Synth.getEffect("Polyshape FX8")];
				     
					
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



const var LoopB = [Synth.getChildSynth("LoopB1"),
					Synth.getChildSynth("LoopB2"),
					Synth.getChildSynth("LoopB3"),
					Synth.getChildSynth("LoopB4"),
					Synth.getChildSynth("LoopB5"),
					Synth.getChildSynth("LoopB6"),
					Synth.getChildSynth("LoopB7"),
					Synth.getChildSynth("LoopB8")];



const var AdsrFm = [Synth.getModulator("AdsrFm1"),
                    Synth.getModulator("AdsrFm2"),
                    Synth.getModulator("AdsrFm3"),
                    Synth.getModulator("AdsrFm4"),
                    Synth.getModulator("AdsrFm5"),
                    Synth.getModulator("AdsrFm6"),
                    Synth.getModulator("AdsrFm7"),                     
                    Synth.getModulator("AdsrFm8")];


inline function onATTACKFmControl(component, value)
{

	for(s in AdsrFm)
	       s.setAttribute(2, value);
};

Content.getComponent("ATTACKFm").setControlCallback(onATTACKFmControl);


inline function onDECAYFmControl(component, value)
{
	for(s in AdsrFm)
	       s.setAttribute(5, value);
};

Content.getComponent("DECAYFm").setControlCallback(onDECAYFmControl);


inline function onSUSTAINFmControl(component, value)
{
	for(s in AdsrFm)
	       s.setAttribute(6, value);
};

Content.getComponent("SUSTAINFm").setControlCallback(onSUSTAINFmControl);


inline function onRELEASEFmControl(component, value)
{
	for(s in AdsrFm)
	       s.setAttribute(7, value);
};

Content.getComponent("RELEASEFm").setControlCallback(onRELEASEFmControl);


inline function onFmGain1Control(component, value)
{
	for(s in LoopB)
		       s.setAttribute(0, value);
};

Content.getComponent("FmGain1").setControlCallback(onFmGain1Control);

const var O2Pitch = [Synth.getModulator("ConstB1"),
					 Synth.getModulator("ConstB2"),
					 Synth.getModulator("ConstB3"),
					 Synth.getModulator("ConstB4"),
					 Synth.getModulator("ConstB5"),
					 Synth.getModulator("ConstB6"),
					 Synth.getModulator("ConstB7"),
					 Synth.getModulator("ConstB8")];
					 
					 

inline function onHarm3Control(component, value)
{
	for(s in O2Pitch)
	       s.setIntensity(value);
};

Content.getComponent("Harm3").setControlCallback(onHarm3Control);
					 

