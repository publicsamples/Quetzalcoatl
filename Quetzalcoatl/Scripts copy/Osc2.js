

const var Osc2 = [Synth.getChildSynth("SamplerB")];


const var harmscaleB = [Synth.getModulator("PitchB1")];

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



inline function onPitchMode1Control(component, value)
{
	for(s in harmscaleB)
	       s.setAttribute(2, value);
};

Content.getComponent("PitchMode1").setControlCallback(onPitchMode1Control);

const var Shape = [Synth.getEffect("Polyshape FX")];
				     
					
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

const var FmIn8 = Synth.getChildSynth("FmIn8");

const var LoopB1 = Synth.getAudioSampleProcessor("LoopB");

const var AdsrFm = Synth.getModulator("AdsrFm");

const var FmIn = [Synth.getChildSynth("FmIn1"),
                    Synth.getChildSynth("FmIn2"),
                    Synth.getChildSynth("FmIn3"),
                    Synth.getChildSynth("FmIn4"),
                    Synth.getChildSynth("FmIn5"),
                    Synth.getChildSynth("FmIn6"),
                    Synth.getChildSynth("FmIn7"),                     
                    Synth.getChildSynth("FmIn8")];


inline function onATTACKFmControl(component, value)
{
	AdsrFm.setAttribute(2, value);
	for(s in FmIn)
	       s.setAttribute(4, value);
};

Content.getComponent("ATTACKFm").setControlCallback(onATTACKFmControl);


inline function onDECAYFmControl(component, value)
{
		AdsrFm.setAttribute(5, value);
	for(s in FmIn)
	       s.setAttribute(5, value);
};

Content.getComponent("DECAYFm").setControlCallback(onDECAYFmControl);


inline function onSUSTAINFmControl(component, value)
{
	AdsrFm.setAttribute(6, value);
	for(s in FmIn)
	       s.setAttribute(6, value);
};

Content.getComponent("SUSTAINFm").setControlCallback(onSUSTAINFmControl);


inline function onRELEASEFmControl(component, value)
{
		AdsrFm.setAttribute(7, value);
	for(s in FmIn)
	       s.setAttribute(7, value);
};

Content.getComponent("RELEASEFm").setControlCallback(onRELEASEFmControl);


