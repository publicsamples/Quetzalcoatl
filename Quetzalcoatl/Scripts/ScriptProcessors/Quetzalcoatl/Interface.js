Content.makeFrontInterface(885, 745);

//presets

const var Pbox = [];

Pbox[0] = Content.getComponent("settings");
Pbox[1] = Content.getComponent("blank1");
Pbox[2] = Content.getComponent("blank2");

const var pre= Content.getComponent("presets");

inline function onpresetsControl(component, value)
{
    for (i = 0; i < Pbox.length; i++)
        Pbox[i].showControl(value - 1 == i);
};


Content.getComponent("presets").setControlCallback(onpresetsControl);

function onControl(number, value)
{
    if(number == widget1)
    {
        Module1.setAttribute(Module1.Parameter, value);
    }
    else if (number == widget2)
    {
        Module2.setAttribute(Module2.Parameter, value);
    }
}

const var Sampler1 = Synth.getSampler("Sampler1");
const var Sampler2 = Synth.getSampler("Sampler2");
const var Sampler3 = Synth.getSampler("Sampler3");
const var Sampler4 = Synth.getSampler("Sampler4");
const var Sampler5 = Synth.getSampler("Sampler5");
const var Sampler6 = Synth.getSampler("Sampler6");
const var Sampler7 = Synth.getSampler("Sampler7");
const var Sampler8 = Synth.getSampler("Sampler8");
const var Sampler9 = Synth.getSampler("Sampler9");

const var sampleMaps = Sampler.getSampleMapList();

//sample menus

const var Shape = Content.getComponent("Shape");
const var ShapeLabel = Content.getComponent("ShapeLabel");

inline function onShapeControl(component, value)
{
	ShapeLabel.set("text",Shape.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("xx::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX3P::","").replace("sys101::",""));



    Sampler1.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape").setControlCallback(onShapeControl);

Shape.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape2 = Content.getComponent("Shape2");
const var ShapeLabel2 = Content.getComponent("ShapeLabel2");

inline function onShape2Control(component, value)
{
	ShapeLabel2.set("text",Shape2.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FFM::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX3P::","").replace("sys101::",""));



    Sampler2.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape2").setControlCallback(onShape2Control);

Shape2.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape3 = Content.getComponent("Shape3");
const var ShapeLabel3 = Content.getComponent("ShapeLabel3");

inline function onShape3Control(component, value)
{
	ShapeLabel3.set("text",Shape3.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FFM::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX3P::","").replace("sys101::",""));



    Sampler3.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape3").setControlCallback(onShape3Control);

Shape3.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape4 = Content.getComponent("Shape4");
const var ShapeLabel4 = Content.getComponent("ShapeLabel4");

inline function onShape4Control(component, value)
{
	ShapeLabel4.set("text",Shape4.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FFM::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX3P::","").replace("sys101::",""));



    Sampler4.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape4").setControlCallback(onShape4Control);

Shape4.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape5 = Content.getComponent("Shape5");
const var ShapeLabel5 = Content.getComponent("ShapeLabel5");

inline function onShape5Control(component, value)
{
	ShapeLabel5.set("text",Shape5.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FFM::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX3P::","").replace("sys101::",""));



    Sampler5.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape5").setControlCallback(onShape5Control);

Shape5.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape6 = Content.getComponent("Shape6");
const var ShapeLabel6 = Content.getComponent("ShapeLabel6");

inline function onShape6Control(component, value)
{
	ShapeLabel6.set("text",Shape6.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FFM::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX3P::","").replace("sys101::",""));



    Sampler6.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape6").setControlCallback(onShape6Control);

Shape6.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape7 = Content.getComponent("Shape7");
const var ShapeLabel7 = Content.getComponent("ShapeLabel7");

inline function onShape7Control(component, value)
{
	ShapeLabel7.set("text",Shape7.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FFM::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX3P::","").replace("sys101::",""));



    Sampler7.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape7").setControlCallback(onShape7Control);

Shape7.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape8 = Content.getComponent("Shape8");
const var ShapeLabel8 = Content.getComponent("ShapeLabel8");

inline function onShape8Control(component, value)
{
	ShapeLabel8.set("text",Shape8.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FFM::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX3P::","").replace("sys101::",""));



    Sampler8.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape8").setControlCallback(onShape8Control);

Shape8.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape9 = Content.getComponent("Shape9");
const var ShapeLabel9 = Content.getComponent("ShapeLabel9");

inline function onShape9Control(component, value)
{
	ShapeLabel9.set("text",Shape9.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FFM::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("MISC::","").replace("JX3P::","").replace("sys101::",""));



    Sampler9.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape9").setControlCallback(onShape9Control);

Shape9.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});



//controls

const var Group1 = Synth.getChildSynth("Group1");
const var Group2 = Synth.getChildSynth("Group2");
const var Group3 = Synth.getChildSynth("Group3");
const var Group4 = Synth.getChildSynth("Group4");
const var Group5 = Synth.getChildSynth("Group5");
const var Group6 = Synth.getChildSynth("Group6");
const var Group7 = Synth.getChildSynth("Group7");
const var Group8 = Synth.getChildSynth("Group8");



Content.getComponent("PitB").setControlCallback(onPitBControl);

const var XFADE = Content.getComponent("XFADE");
const var vecxfade = Synth.getModulator("vecxfade");
const var Smooth = Content.getComponent("Smooth");


inline function onXFADEControl(component, value)
{
   vecxfade.setAttribute(vecxfade.scan, value);

};



inline function onSmoothControl(component, value)
{
 vecxfade.setAttribute(vecxfade.smooth, value);

};

Content.getComponent("Smooth").setControlCallback(onSmoothControl);


const var PitchB1 = Synth.getModulator("PitchB1");

const var fmin1 = Synth.getChildSynth("fmin1");
const var fmin2 = Synth.getChildSynth("fmin2");
const var fmin3 = Synth.getChildSynth("fmin3");
const var fmin4 = Synth.getChildSynth("fmin4");
const var fmin5 = Synth.getChildSynth("fmin5");
const var fmin6 = Synth.getChildSynth("fmin6");
const var fmin7 = Synth.getChildSynth("fmin7");
const var fmin8 = Synth.getChildSynth("fmin8");

const var FMLevel = Content.getComponent("FMLevel");

inline function onFMLevelControl(component, value)
{
 	fmin1.setAttribute(0, value);
	fmin2.setAttribute(0, value);
	fmin3.setAttribute(0, value);
	fmin4.setAttribute(0, value);
	fmin5.setAttribute(0, value);
	fmin6.setAttribute(0, value);
	fmin7.setAttribute(0, value);
	fmin8.setAttribute(0, value);
};

Content.getComponent("FMLevel").setControlCallback(onFMLevelControl);

const var Feedback = Content.getComponent("Feedback");

inline function onFeedbackControl(component, value)
{
  fmin1.setAttribute(fmin1.feedback, value);
  fmin2.setAttribute(fmin2.feedback, value);
  fmin3.setAttribute(fmin3.feedback, value);
  fmin4.setAttribute(fmin4.feedback, value);
  fmin5.setAttribute(fmin5.feedback, value);
  fmin6.setAttribute(fmin6.feedback, value);
  fmin7.setAttribute(fmin7.feedback, value);
  fmin8.setAttribute(fmin8.feedback, value);
};

Content.getComponent("Feedback").setControlCallback(onFeedbackControl);

const var FMmod1 = Content.getComponent("FMmod1");
{
	
}

inline function onFMmod1Control(component, value)
{
fmin1.setAttribute(fmin1.fmmod, value);
fmin2.setAttribute(fmin2.fmmod, value);
fmin3.setAttribute(fmin3.fmmod, value);
fmin4.setAttribute(fmin4.fmmod, value);
fmin5.setAttribute(fmin5.fmmod, value);
fmin6.setAttribute(fmin6.fmmod, value);
fmin7.setAttribute(fmin7.fmmod, value);
fmin8.setAttribute(fmin8.fmmod, value);

};

Content.getComponent("FMmod1").setControlCallback(onFMmod1Control);



const var FMmodSel1 = Content.getComponent("FMmodSel1");

inline function onFMmodSel1Control(component, value)
{
fmin1.setAttribute(fmin1.fmdest, value);
fmin2.setAttribute(fmin2.fmdest, value);
fmin3.setAttribute(fmin3.fmdest, value);
fmin4.setAttribute(fmin4.fmdest, value);
fmin5.setAttribute(fmin5.fmdest, value);
fmin6.setAttribute(fmin6.fmdest, value);
fmin7.setAttribute(fmin7.fmdest, value);
fmin8.setAttribute(fmin8.fmdest, value);

};

Content.getComponent("FMmodSel1").setControlCallback(onFMmodSel1Control);


const var FeedMod1 = Content.getComponent("FeedMod1");

inline function onFeedMod1Control(component, value)
{
fmin1.setAttribute(fmin1.feedmod, value);
fmin2.setAttribute(fmin2.feedmod, value);
fmin3.setAttribute(fmin3.feedmod, value);
fmin4.setAttribute(fmin4.feedmod, value);
fmin5.setAttribute(fmin5.feedmod, value);
fmin6.setAttribute(fmin6.feedmod, value);
fmin7.setAttribute(fmin7.feedmod, value);
fmin8.setAttribute(fmin8.feedmod, value);

};

Content.getComponent("FeedMod1").setControlCallback(onFeedMod1Control);

const var FeedModSel1 = Content.getComponent("FeedModSel1");


inline function onFeedModSel1Control(component, value)
{
fmin1.setAttribute(fmin1.feeddest, value);
fmin2.setAttribute(fmin2.feeddest, value);
fmin3.setAttribute(fmin3.feeddest, value);
fmin4.setAttribute(fmin4.feeddest, value);
fmin5.setAttribute(fmin5.feeddest, value);
fmin6.setAttribute(fmin6.feeddest, value);
fmin7.setAttribute(fmin7.feeddest, value);
fmin8.setAttribute(fmin8.feeddest, value);

};

Content.getComponent("FeedModSel1").setControlCallback(onFeedModSel1Control);


const var Envelope1 = Synth.getModulator("Envelope1");
const var Envelope2 = Synth.getModulator("Envelope2");
const var Envelope3 = Synth.getModulator("Envelope3");
const var Envelope4 = Synth.getModulator("Envelope4");
const var Envelope5 = Synth.getModulator("Envelope5");
const var Envelope6 = Synth.getModulator("Envelope6");
const var Envelope7 = Synth.getModulator("Envelope7");
const var Envelope8 = Synth.getModulator("Envelope8");

const var VecAttack = Content.getComponent("VecAttack");


inline function onVecAttackControl(component, value)
{
	Envelope1.setAttribute(2, value);
	Envelope2.setAttribute(2, value);
	Envelope3.setAttribute(2, value);
	Envelope4.setAttribute(2, value);
	Envelope5.setAttribute(2, value);
	Envelope6.setAttribute(2, value);
	Envelope7.setAttribute(2, value);
	Envelope8.setAttribute(2, value);
};

Content.getComponent("VecAttack").setControlCallback(onVecAttackControl);

const var VecDecay = Content.getComponent("VecDecay");


inline function onVecDecayControl(component, value)
{
		Envelope1.setAttribute(5, value);
		Envelope2.setAttribute(5, value);
		Envelope3.setAttribute(5, value);
		Envelope4.setAttribute(5, value);
		Envelope5.setAttribute(5, value);
		Envelope6.setAttribute(5, value);
		Envelope7.setAttribute(5, value);
		Envelope8.setAttribute(5, value);
};

Content.getComponent("VecDecay").setControlCallback(onVecDecayControl);

const var VecSustan = Content.getComponent("VecSustan");

const var FMenvelope1 = Synth.getModulator("FMenvelope1");
const var FMenvelope2 = Synth.getModulator("FMenvelope2");
const var FMenvelope3 = Synth.getModulator("FMenvelope3");
const var FMenvelope4 = Synth.getModulator("FMenvelope4");
const var FMenvelope5 = Synth.getModulator("FMenvelope5");
const var FMenvelope6 = Synth.getModulator("FMenvelope6");
const var FMenvelope7 = Synth.getModulator("FMenvelope7");
const var FMenvelope8 = Synth.getModulator("FMenvelope8");
 const var Envelope9 = Synth.getModulator("Envelope9");
const var FMAttack = Content.getComponent("FMAttack");

const var Ampvel = Content.getComponent("Ampvel");
const var Ampvel1 = Synth.getModulator("Ampvel1");
const var Ampvel2 = Synth.getModulator("Ampvel2");
const var Ampvel3 = Synth.getModulator("Ampvel3");
const var Ampvel4 = Synth.getModulator("Ampvel4");
const var Ampvel5 = Synth.getModulator("Ampvel5");
const var Ampvel6 = Synth.getModulator("Ampvel6");
const var Ampvel7 = Synth.getModulator("Ampvel7");
const var Ampvel8 = Synth.getModulator("Ampvel8");
const var Ampvel9 = Synth.getModulator("Ampvel9");

inline function onAmpvelControl(component, value)
{
	Ampvel1.setIntensity(value);
	Ampvel2.setIntensity(value);
	Ampvel3.setIntensity(value);
	Ampvel4.setIntensity(value);
	Ampvel5.setIntensity(value);
	Ampvel6.setIntensity(value);
	Ampvel7.setIntensity(value);
	Ampvel8.setIntensity(value);
	Ampvel9.setIntensity(value);
};

Content.getComponent("Ampvel").setControlCallback(onAmpvelControl);

const var legato = Content.getComponent("legato1");
const var legato1 = Synth.getMidiProcessor("legato1");
const var legato2 = Synth.getMidiProcessor("legato2");
const var legato3 = Synth.getMidiProcessor("legato3");
const var legato4 = Synth.getMidiProcessor("legato4");
const var legato5 = Synth.getMidiProcessor("legato5");
const var legato6 = Synth.getMidiProcessor("legato6");
const var legato7 = Synth.getMidiProcessor("legato7");
const var legato8 = Synth.getMidiProcessor("legato8");

inline function onlegato1Control(component, value)
{
legato1.setBypassed(value);
	legato1.setBypassed(1 - value);
	legato2.setBypassed(value);
	legato2.setBypassed(1 - value);
	legato3.setBypassed(value);
	legato3.setBypassed(1 - value);
	legato4.setBypassed(value);
	legato4.setBypassed(1 - value);
	legato5.setBypassed(value);
	legato5.setBypassed(1 - value);
	legato6.setBypassed(value);
	legato6.setBypassed(1 - value);
 	legato7.setBypassed(value);
	legato7.setBypassed(1 - value);
	legato8.setBypassed(value);
	legato8.setBypassed(1 - value);
};

Content.getComponent("legato1").setControlCallback(onlegato1Control);



inline function onFMAttackControl(component, value)
{
	FMenvelope1.setAttribute(2, value);
	FMenvelope2.setAttribute(2, value);
	FMenvelope3.setAttribute(2, value);
	FMenvelope4.setAttribute(2, value);
	FMenvelope5.setAttribute(2, value);
	FMenvelope6.setAttribute(2, value);
	FMenvelope7.setAttribute(2, value);
	FMenvelope8.setAttribute(2, value);
	Envelope9.setAttribute(2, value);
};

Content.getComponent("FMAttack").setControlCallback(onFMAttackControl);

const var FMDecay = Content.getComponent("FMDecay");


inline function onFMDecayControl(component, value)
{
		FMenvelope1.setAttribute(5, value);
		FMenvelope2.setAttribute(5, value);
		FMenvelope3.setAttribute(5, value);
		FMenvelope4.setAttribute(5, value);
		FMenvelope5.setAttribute(5, value);
		FMenvelope6.setAttribute(5, value);
		FMenvelope7.setAttribute(5, value);
		FMenvelope8.setAttribute(5, value);
		Envelope9.setAttribute(5, value);
	
};

Content.getComponent("FMDecay").setControlCallback(onFMDecayControl);

const var FMSustain = Content.getComponent("FMSustain");


inline function onFMSustainControl(component, value)
{
	FMenvelope1.setAttribute(6, value);
	FMenvelope2.setAttribute(6, value);
	FMenvelope3.setAttribute(6, value);
	FMenvelope4.setAttribute(6, value);
	FMenvelope5.setAttribute(6, value);
	FMenvelope6.setAttribute(6, value);
	FMenvelope7.setAttribute(6, value);
	FMenvelope8.setAttribute(6, value);
	Envelope9.setAttribute(6, value);
};

Content.getComponent("FMSustain").setControlCallback(onFMSustainControl);

const var FMRelease = Content.getComponent("FMRelease");


inline function onFMReleaseControl(component, value)
{
	FMenvelope1.setAttribute(7, value);
	FMenvelope2.setAttribute(7, value);
	FMenvelope3.setAttribute(7, value);
	FMenvelope4.setAttribute(7, value);
	FMenvelope5.setAttribute(7, value);
	FMenvelope6.setAttribute(7, value);
	FMenvelope7.setAttribute(7, value);
	FMenvelope8.setAttribute(7, value);
	Envelope9.setAttribute(7, value);
};

Content.getComponent("FMRelease").setControlCallback(onFMReleaseControl);



inline function onVecSustanControl(component, value)
{
	Envelope1.setAttribute(6, value);
	Envelope2.setAttribute(6, value);
	Envelope3.setAttribute(6, value);
	Envelope4.setAttribute(6, value);
	Envelope5.setAttribute(6, value);
	Envelope6.setAttribute(6, value);
	Envelope7.setAttribute(6, value);
	Envelope8.setAttribute(6, value);
};

Content.getComponent("VecSustan").setControlCallback(onVecSustanControl);

const var VecRelease = Content.getComponent("VecRelease");


inline function onVecReleaseControl(component, value)
{
	Envelope1.setAttribute(7, value);
	Envelope2.setAttribute(7, value);
	Envelope3.setAttribute(7, value);
	Envelope4.setAttribute(7, value);
	Envelope5.setAttribute(7, value);
	Envelope6.setAttribute(7, value);
	Envelope7.setAttribute(7, value);
	Envelope8.setAttribute(7, value);
};

Content.getComponent("VecRelease").setControlCallback(onVecReleaseControl);

const var Filter1 = Synth.getEffect("Filter1");
const var Filter2 = Synth.getEffect("Filter2");
const var Filter3 = Synth.getEffect("Filter3");
const var Filter4 = Synth.getEffect("Filter4");
const var Filter5 = Synth.getEffect("Filter5");
const var Filter6 = Synth.getEffect("Filter6");
const var Filter7 = Synth.getEffect("Filter7");
const var Filter8 = Synth.getEffect("Filter8");
const var Filter9 = Synth.getEffect("Filter9");

const var Ftype = Content.getComponent("Ftype");

inline function onFtypeControl(component, value)
{
	Filter1.setAttribute(3, value);
	Filter2.setAttribute(3, value);
	Filter3.setAttribute(3, value);
	Filter4.setAttribute(3, value);
	Filter5.setAttribute(3, value);
	Filter6.setAttribute(3, value);
	Filter7.setAttribute(3, value);
	Filter8.setAttribute(3, value);
	Filter9.setAttribute(3, value);

}

Content.getComponent("Ftype").setControlCallback(onFtypeControl);




const var Cutoff = Content.getComponent("Cutoff");


inline function onCutoffControl(component, value)
{
	Filter1.setAttribute(1, value);
	Filter2.setAttribute(1, value);
	Filter3.setAttribute(1, value);
	Filter4.setAttribute(1, value);
	Filter5.setAttribute(1, value);
	Filter6.setAttribute(1, value);
	Filter7.setAttribute(1, value);
	Filter8.setAttribute(1, value);
	Filter9.setAttribute(1, value);
};

Content.getComponent("Cutoff").setControlCallback(onCutoffControl);

const var Resonance = Content.getComponent("Resonance");

inline function onResonanceControl(component, value)
{
	Filter1.setAttribute(2, value);
	Filter2.setAttribute(2, value);
	Filter3.setAttribute(2, value);
	Filter4.setAttribute(2, value);
	Filter5.setAttribute(2, value);
	Filter6.setAttribute(2, value);
	Filter7.setAttribute(2, value);
	Filter8.setAttribute(2, value);
	Filter9.setAttribute(2, value);
};

Content.getComponent("Resonance").setControlCallback(onResonanceControl);

inline function onResonanceControl(component, value)
{
	Filter1.setAttribute(2, value);
	Filter2.setAttribute(2, value);
	Filter3.setAttribute(2, value);
	Filter4.setAttribute(2, value);
	Filter5.setAttribute(2, value);
	Filter6.setAttribute(2, value);
	Filter7.setAttribute(2, value);
	Filter8.setAttribute(2, value);
	Filter9.setAttribute(2, value);
};

Content.getComponent("Resonance").setControlCallback(onResonanceControl);

const var FilterEnvelope1 = Synth.getModulator("FilterEnvelope1");
const var FilterEnvelope2 = Synth.getModulator("FilterEnvelope2");
const var FilterEnvelope3 = Synth.getModulator("FilterEnvelope3");
const var FilterEnvelope4 = Synth.getModulator("FilterEnvelope4");
const var FilterEnvelope5 = Synth.getModulator("FilterEnvelope5");
const var FilterEnvelope6 = Synth.getModulator("FilterEnvelope6");
const var FilterEnvelope7 = Synth.getModulator("FilterEnvelope7");
const var FilterEnvelope8 = Synth.getModulator("FilterEnvelope8");
 const var FilterEnvelope9 = Synth.getModulator("FilterEnvelope9");
const var FilterAttack = Content.getComponent("FilterAttack");


inline function onFilterAttackControl(component, value)
{
	FilterEnvelope1.setAttribute(2, value);
	FilterEnvelope2.setAttribute(2, value);
	FilterEnvelope3.setAttribute(2, value);
	FilterEnvelope4.setAttribute(2, value);
	FilterEnvelope5.setAttribute(2, value);
	FilterEnvelope6.setAttribute(2, value);
	FilterEnvelope7.setAttribute(2, value);
	FilterEnvelope8.setAttribute(2, value);
	FilterEnvelope9.setAttribute(2, value);
};

Content.getComponent("FilterAttack").setControlCallback(onFilterAttackControl);

const var FilterDecay = Content.getComponent("FilterDecay");


inline function onFilterDecayControl(component, value)
{
		FilterEnvelope1.setAttribute(5, value);
		FilterEnvelope2.setAttribute(5, value);
		FilterEnvelope3.setAttribute(5, value);
		FilterEnvelope4.setAttribute(5, value);
		FilterEnvelope5.setAttribute(5, value);
		FilterEnvelope6.setAttribute(5, value);
		FilterEnvelope7.setAttribute(5, value);
		FilterEnvelope8.setAttribute(5, value);
		FilterEnvelope9.setAttribute(5, value);
	
};

Content.getComponent("FilterDecay").setControlCallback(onFilterDecayControl);

const var FilterSustain = Content.getComponent("FilterSustain");


inline function onFilterSustainControl(component, value)
{
	FilterEnvelope1.setAttribute(6, value);
	FilterEnvelope2.setAttribute(6, value);
	FilterEnvelope3.setAttribute(6, value);
	FilterEnvelope4.setAttribute(6, value);
	FilterEnvelope5.setAttribute(6, value);
	FilterEnvelope6.setAttribute(6, value);
	FilterEnvelope7.setAttribute(6, value);
	FilterEnvelope8.setAttribute(6, value);
	FilterEnvelope9.setAttribute(6, value);
};

Content.getComponent("FilterSustain").setControlCallback(onFilterSustainControl);

const var FilterRelease = Content.getComponent("FilterRelease");


inline function onFilterReleaseControl(component, value)
{
	FilterEnvelope1.setAttribute(7, value);
	FilterEnvelope2.setAttribute(7, value);
	FilterEnvelope3.setAttribute(7, value);
	FilterEnvelope4.setAttribute(7, value);
	FilterEnvelope5.setAttribute(7, value);
	FilterEnvelope6.setAttribute(7, value);
	FilterEnvelope7.setAttribute(7, value);
	FilterEnvelope8.setAttribute(7, value);
	FilterEnvelope9.setAttribute(7, value);
};

Content.getComponent("FilterRelease").setControlCallback(onFilterReleaseControl);

const var FEnvMod = Content.getComponent("FEnvMod");

inline function onFEnvModControl(component, value)
{
	FilterEnvelope1.setIntensity(value);
	FilterEnvelope2.setIntensity(value);
	FilterEnvelope3.setIntensity(value);
	FilterEnvelope4.setIntensity(value);
	FilterEnvelope5.setIntensity(value);
	FilterEnvelope6.setIntensity(value);
	FilterEnvelope7.setIntensity(value);
	FilterEnvelope8.setIntensity(value);
	FilterEnvelope9.setIntensity(value);
};

Content.getComponent("FEnvMod").setControlCallback(onFEnvModControl);

const var FModA = Content.getComponent("FModA");
const var FilterModA1 = Synth.getModulator("FilterModA1");
const var FilterModA2 = Synth.getModulator("FilterModA2");
const var FilterModA3 = Synth.getModulator("FilterModA3");
const var FilterModA4 = Synth.getModulator("FilterModA4");
const var FilterModA5 = Synth.getModulator("FilterModA5");
const var FilterModA6 = Synth.getModulator("FilterModA6");
const var FilterModA7 = Synth.getModulator("FilterModA7");
const var FilterModA8 = Synth.getModulator("FilterModA8");
const var FilterModA9 = Synth.getModulator("FilterModA9");

inline function onFModAControl(component, value)
{
	FilterModA1.setIntensity(value);
	FilterModA2.setIntensity(value);
	FilterModA3.setIntensity(value);
	FilterModA4.setIntensity(value);
	FilterModA5.setIntensity(value);
	FilterModA6.setIntensity(value);
	FilterModA7.setIntensity(value);
	FilterModA8.setIntensity(value);
	FilterModA9.setIntensity(value);
};

Content.getComponent("FModA").setControlCallback(onFModAControl);




const var FilterVEL = Content.getComponent("FilterVEL");
const var vel1 = Synth.getModulator("vel1");
const var vel2 = Synth.getModulator("vel2");
const var vel3 = Synth.getModulator("vel3");
const var vel4 = Synth.getModulator("vel4");
const var vel5 = Synth.getModulator("vel5");
const var vel6 = Synth.getModulator("vel6");
const var vel7 = Synth.getModulator("vel7");
const var vel8 = Synth.getModulator("vel8");
const var vel9 = Synth.getModulator("vel9");

inline function onFilterVELControl(component, value)
{
	vel1.setIntensity(value);
	vel2.setIntensity(value);
	vel3.setIntensity(value);
	vel4.setIntensity(value);
	vel5.setIntensity(value);
	vel6.setIntensity(value);
	vel7.setIntensity(value);
	vel8.setIntensity(value);
	vel9.setIntensity(value);
};

Content.getComponent("FilterVEL").setControlCallback(onFilterVELControl);

const var FilterTRACK = Content.getComponent("FilterTRACK");
const var track1 = Synth.getModulator("track1");
const var track2 = Synth.getModulator("track2");
const var track3 = Synth.getModulator("track3");
const var track4 = Synth.getModulator("track4");
const var track5 = Synth.getModulator("track5");
const var track6 = Synth.getModulator("track6");
const var track7 = Synth.getModulator("track7");
const var track8 = Synth.getModulator("track8");
const var track9 = Synth.getModulator("track9");

inline function onFilterTRACKControl(component, value)
{
	track1.setIntensity(value);
	track2.setIntensity(value);
	track3.setIntensity(value);
	track4.setIntensity(value);
	track5.setIntensity(value);
	track6.setIntensity(value);
	track7.setIntensity(value);
	track8.setIntensity(value);
	track9.setIntensity(value);
};

Content.getComponent("FilterTRACK").setControlCallback(onFilterTRACKControl);



//show hide mod params

const var button1 = Content.getComponent("seqtype1");
const var table1 = Content.getComponent("ScriptTable1");
const var step1 = Content.getComponent("SliderPack1");
const var s1 = Synth.getModulator("s1");

inline function onseqtype1Control(number, value)
{
        step1.showControl(value);
        table1.showControl(1-value); 
        s1.setAttribute(s1.type, 1-value);
        s2.setAttribute(s2.type, 0);
}







button1.setControlCallback(onseqtype1Control);






const var button2 = Content.getComponent("seqtype2");
const var table2 = Content.getComponent("ScriptTable2");
const var step2 = Content.getComponent("SliderPack2");
const var s2 = Synth.getModulator("s2");

inline function onseqtype2Control(number, value)
{
        step2.showControl(value);
        table2.showControl(1-value); 
        s2.setAttribute(s2.type, 0);
        s2.setAttribute(s2.type, 1-value);
}


button2.setControlCallback(onseqtype2Control);



const var button3 = Content.getComponent("seqtype3");
const var table3 = Content.getComponent("ScriptTable3");
const var step3 = Content.getComponent("SliderPack3");
const var s3 = Synth.getModulator("s3");

inline function onseqtype3Control(number, value)
{
        step3.showControl(value);
        table3.showControl(1-value); 
        s3.setAttribute(s3.type, 0);
        s3.setAttribute(s3.type, 1-value);
}


button3.setControlCallback(onseqtype3Control);



const var button4 = Content.getComponent("seqtype4");
const var table4 = Content.getComponent("ScriptTable4");
const var step4 = Content.getComponent("SliderPack4");
const var s4 = Synth.getModulator("s4");

inline function onseqtype4Control(number, value)
{
        step4.showControl(value);
        table4.showControl(1-value); 
        s4.setAttribute(s4.type, 0);
        s4.setAttribute(s4.type, 1-value);
}


button4.setControlCallback(onseqtype4Control);


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
 