

//

const var fm = [Synth.getChildSynth("Fm1"),
				Synth.getChildSynth("Fm2"),
				Synth.getChildSynth("Fm3"),
				Synth.getChildSynth("Fm4"),
				Synth.getChildSynth("Fm5"),
				Synth.getChildSynth("Fm6"),
				Synth.getChildSynth("Fm7"),
				Synth.getChildSynth("Fm8")];


inline function onFmMixControl(component, value)
{
	for(s in fm)
	       s.setAttribute(7, value);
};

Content.getComponent("FmMix").setControlCallback(onFmMixControl);


inline function onFmTrackControl(component, value)
{
	for(s in fm)
	       s.setAttribute(14, value);
};

Content.getComponent("FmTrack").setControlCallback(onFmTrackControl);


inline function onAMControl(component, value)
{
		for(s in fm)
	       s.setAttribute(8, value);
};

Content.getComponent("AM").setControlCallback(onAMControl);


inline function onAmModControl(component, value)
{
	for(s in fm)
	       s.setAttribute(9, value);
};

Content.getComponent("AmMod").setControlCallback(onAmModControl);


inline function onAmMordSrcControl(component, value)
{
	for(s in fm)
	       s.setAttribute(10, value);
};

Content.getComponent("AmMordSrc").setControlCallback(onAmMordSrcControl);



inline function onadditionalmodeswitchControl(component, value)
{
 WtSliders.showControl(value);
 FmSlider.showControl(1-value);
};

Content.getComponent("additionalmodeswitch").setControlCallback(onadditionalmodeswitchControl);