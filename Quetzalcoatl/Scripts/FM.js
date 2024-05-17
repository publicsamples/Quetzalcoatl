const var FmWave = Content.getComponent("FmWave");



inline function onFmTrkControl(component, value)
{
for(s in FmOn)
		       s.setAttribute(6, value);
};

Content.getComponent("FmTrk").setControlCallback(onFmTrkControl);


inline function onFmRootControl(component, value)
{
for(s in FmOn)
		       s.setAttribute(7, value);
};

Content.getComponent("FmRoot").setControlCallback(onFmRootControl);

const var Detune1 = Synth.getModulator("Detune1");

const var Detune = [Synth.getModulator("Detune1"),
					 Synth.getModulator("Detune2"),
					 Synth.getModulator("Detune3"),
					 Synth.getModulator("Detune4"),
					 Synth.getModulator("Detune5"),
					 Synth.getModulator("Detune6"),
					 Synth.getModulator("Detune7"),
					 Synth.getModulator("Detune8")];
					 


inline function onFmDetuneControl(component, value)
{
	
	for(s in Detune)
	       s.setIntensity(value);

};

Content.getComponent("FmDetune").setControlCallback(onFmDetuneControl);


const var FmEnv = [Synth.getModulator("FmEnv1"),
					 Synth.getModulator("FmEnv2"),
					 Synth.getModulator("FmEnv3"),
					 Synth.getModulator("FmEnv4"),
					 Synth.getModulator("FmEnv5"),
					 Synth.getModulator("FmEnv6"),
					 Synth.getModulator("FmEnv7"),
					 Synth.getModulator("FmEnv8")];


inline function onFmAtkControl(component, value)
{
	for(s in FmEnv)
		       s.setAttribute(2, value);
};

Content.getComponent("FmAtk").setControlCallback(onFmAtkControl);


inline function onFmDcyControl(component, value)
{
		for(s in FmEnv)
		       s.setAttribute(5, value);
};

Content.getComponent("FmDcy").setControlCallback(onFmDcyControl);


inline function onFmSusControl(component, value)
{
		for(s in FmEnv)
		       s.setAttribute(6, value);
};

Content.getComponent("FmSus").setControlCallback(onFmSusControl);


inline function onFmRelControl(component, value)
{
for(s in FmEnv)
		       s.setAttribute(7, value);
};

Content.getComponent("FmRel").setControlCallback(onFmRelControl);

