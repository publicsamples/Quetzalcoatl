Content.makeFrontInterface(600, 600);



const var Knob1 = Content.getComponent("Knob1");
const var Sampler2 = Synth.getChildSynth("Sampler2");
const var Sampler4 = Synth.getChildSynth("Sampler4");
const var Sampler6 = Synth.getChildSynth("Sampler6");
const var Sampler8 = Synth.getChildSynth("Sampler8");
const var Sampler10 = Synth.getChildSynth("Sampler10");
const var Sampler12 = Synth.getChildSynth("Sampler12");
const var Sampler14 = Synth.getChildSynth("Sampler14");
const var Sampler16 = Synth.getChildSynth("Sampler16");


Knob1.setControlCallback(onKnob1Control);

inline function onKnob1Control(component, value)
{
	Sampler2.setAttribute(0, value);
	Sampler4.setAttribute(0, value);
	Sampler6.setAttribute(0, value);
	Sampler8.setAttribute(0, value);
	Sampler10.setAttribute(0, value);
	Sampler12.setAttribute(0, value);
	Sampler14.setAttribute(0, value);
	Sampler16.setAttribute(0, value);
};

Content.getComponent("Knob1").setControlCallback(onKnob1Control);


const var Group1 = Synth.getChildSynth("Group1");
const var Group2 = Synth.getChildSynth("Group2");
const var Group3 = Synth.getChildSynth("Group3");
const var Group4 = Synth.getChildSynth("Group4");
const var Group5 = Synth.getChildSynth("Group5");
const var Group6 = Synth.getChildSynth("Group6");
const var Group7 = Synth.getChildSynth("Group7");
const var Group8 = Synth.getChildSynth("Group8");

const var Button1 = Content.getComponent("Button1");

inline function onButton1Control(component, value)
{
		Group1.setAttribute(4, value);
		Group1.setAttribute(5, value);
		Group2.setAttribute(4, value);
		Group2.setAttribute(5, value);
		Group3.setAttribute(4, value);
		Group3.setAttribute(5, value);
		Group4.setAttribute(4, value);
		Group4.setAttribute(5, value);
		Group5.setAttribute(4, value);
		Group5.setAttribute(5, value);
		Group6.setAttribute(4, value);
		Group6.setAttribute(5, value);
		Group7.setAttribute(4, value);
		Group7.setAttribute(5, value);
		Group8.setAttribute(4, value);
		Group8.setAttribute(5, value);

};

Content.getComponent("Button1").setControlCallback(onButton1Control);


const var PitchB1 = Synth.getModulator("PitchB1");
const var PitchB2 = Synth.getModulator("PitchB2");
const var PitchB3 = Synth.getModulator("PitchB3");
const var PitchB4 = Synth.getModulator("PitchB4");
const var PitchB5 = Synth.getModulator("PitchB5");
const var PitchB6 = Synth.getModulator("PitchB6");
const var PitchB7 = Synth.getModulator("PitchB7");
const var PitchB8 = Synth.getModulator("PitchB8");

const var PitB = Content.getComponent("PitB");

inline function onPitBControl(component, value)
{
	PitchB1.setIntensity(value);
	PitchB2.setIntensity(value);
	PitchB3.setIntensity(value);
	PitchB4.setIntensity(value);
	PitchB5.setIntensity(value);
	PitchB6.setIntensity(value);
	PitchB7.setIntensity(value);
	PitchB8.setIntensity(value);
};

Content.getComponent("PitB").setControlCallback(onPitBControl);

const var XFADE = Content.getComponent("XFADE");
const var vecxfade = Synth.getModulator("vecxfade");
const var vecxfadeb = Synth.getModulator("vecxfadeb");
const var Smooth = Content.getComponent("Smooth");


inline function onXFADEControl(component, value)
{
   vecxfade.setAttribute(vecxfade.scan, value);
   vecxfadeb.setAttribute(vecxfadeb.scan, value);
};

Content.getComponent("XFADE").setControlCallback(onXFADEControl);




inline function onSmoothControl(component, value)
{
 vecxfade.setAttribute(vecxfade.smooth, value);
   vecxfadeb.setAttribute(vecxfadeb.smooth, value);
};

Content.getComponent("Smooth").setControlCallback(onSmoothControl);




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
 