const var fmin1 = Synth.getChildSynth("fmin1");
const var fmin2 = Synth.getChildSynth("fmin2");
const var fmin3 = Synth.getChildSynth("fmin3");
const var fmin4 = Synth.getChildSynth("fmin4");
const var fmin5 = Synth.getChildSynth("fmin5");
const var fmin6 = Synth.getChildSynth("fmin6");
const var fmin7 = Synth.getChildSynth("fmin7");
const var fmin8 = Synth.getChildSynth("fmin8");
const var fmin9 = Synth.getChildSynth("fmin9");
const var fmin10 = Synth.getChildSynth("fmin10");
const var fmin11 = Synth.getChildSynth("fmin11");
const var fmin12 = Synth.getChildSynth("fmin12");
const var fmin13 = Synth.getChildSynth("fmin13");
const var fmin14 = Synth.getChildSynth("fmin14");
const var fmin15 = Synth.getChildSynth("fmin15");
const var fmin16 = Synth.getChildSynth("fmin16");
const var fmin17 = Synth.getChildSynth("fmin17");
const var fmin18 = Synth.getChildSynth("fmin18");
const var fmin19 = Synth.getChildSynth("fmin19");
const var fmin20 = Synth.getChildSynth("fmin20");
const var fmin21 = Synth.getChildSynth("fmin21");
const var fmin22 = Synth.getChildSynth("fmin22");
const var fmin23 = Synth.getChildSynth("fmin23");
const var fmin24 = Synth.getChildSynth("fmin24");
const var fmin25 = Synth.getChildSynth("fmin25");
const var fmin26 = Synth.getChildSynth("fmin26");
const var fmin27 = Synth.getChildSynth("fmin27");
const var fmin28 = Synth.getChildSynth("fmin28");
const var fmin29 = Synth.getChildSynth("fmin29");
const var fmin30 = Synth.getChildSynth("fmin30");
const var fmin31 = Synth.getChildSynth("fmin31");
const var fmin32 = Synth.getChildSynth("fmin32");
const var fmin33 = Synth.getChildSynth("fmin33");
const var fmin34 = Synth.getChildSynth("fmin34");
const var fmin35 = Synth.getChildSynth("fmin35");
const var fmin36 = Synth.getChildSynth("fmin36");
const var fmin37 = Synth.getChildSynth("fmin37");
const var fmin38 = Synth.getChildSynth("fmin38");
const var fmin39 = Synth.getChildSynth("fmin39");
const var fmin40 = Synth.getChildSynth("fmin40");
const var fmin41 = Synth.getChildSynth("fmin41");
const var fmin42 = Synth.getChildSynth("fmin42");
const var fmin43 = Synth.getChildSynth("fmin43");
const var fmin44 = Synth.getChildSynth("fmin44");
const var fmin45 = Synth.getChildSynth("fmin45");
const var fmin46 = Synth.getChildSynth("fmin46");
const var fmin47 = Synth.getChildSynth("fmin47");
const var fmin48 = Synth.getChildSynth("fmin48");


const var FMLevel = Content.getComponent("FMLevel");

inline function onFMLevelControl(component, value)
{
  fmin1.setAttribute(fmin1.gain, value);
fmin2.setAttribute(fmin2.gain, value);
fmin3.setAttribute(fmin3.gain, value);
fmin4.setAttribute(fmin4.gain, value);
fmin5.setAttribute(fmin5.gain, value);
fmin6.setAttribute(fmin6.gain, value);
fmin7.setAttribute(fmin7.gain, value);
fmin8.setAttribute(fmin8.gain, value);
fmin9.setAttribute(fmin9.gain, value);
fmin10.setAttribute(fmin10.gain, value);
fmin11.setAttribute(fmin11.gain, value);
fmin12.setAttribute(fmin12.gain, value);
fmin13.setAttribute(fmin13.gain, value);
fmin14.setAttribute(fmin14.gain, value);
fmin15.setAttribute(fmin15.gain, value);
fmin16.setAttribute(fmin16.gain, value);
fmin17.setAttribute(fmin17.gain, value);
fmin18.setAttribute(fmin18.gain, value);
fmin19.setAttribute(fmin19.gain, value);
fmin20.setAttribute(fmin20.gain, value);
fmin21.setAttribute(fmin21.gain, value);
fmin22.setAttribute(fmin22.gain, value);
fmin23.setAttribute(fmin23.gain, value);
fmin24.setAttribute(fmin24.gain, value);
fmin25.setAttribute(fmin25.gain, value);
fmin26.setAttribute(fmin26.gain, value);
fmin27.setAttribute(fmin27.gain, value);
fmin28.setAttribute(fmin28.gain, value);
fmin19.setAttribute(fmin29.gain, value);
fmin30.setAttribute(fmin30.gain, value);
fmin31.setAttribute(fmin31.gain, value);
fmin32.setAttribute(fmin32.gain, value);
fmin33.setAttribute(fmin33.gain, value);
fmin34.setAttribute(fmin34.gain, value);
fmin35.setAttribute(fmin35.gain, value);
fmin36.setAttribute(fmin36.gain, value);
fmin37.setAttribute(fmin37.gain, value);
fmin38.setAttribute(fmin38.gain, value);
fmin39.setAttribute(fmin39.gain, value);
fmin40.setAttribute(fmin40.gain, value);
fmin41.setAttribute(fmin41.gain, value);
fmin42.setAttribute(fmin42.gain, value);
fmin43.setAttribute(fmin43.gain, value);
fmin44.setAttribute(fmin44.gain, value);
fmin45.setAttribute(fmin45.gain, value);
fmin46.setAttribute(fmin46.gain, value);
fmin47.setAttribute(fmin47.gain, value);
fmin48.setAttribute(fmin48.gain, value);
	
	
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
fmin9.setAttribute(fmin9.feedback, value);
fmin10.setAttribute(fmin10.feedback, value);
fmin11.setAttribute(fmin11.feedback, value);
fmin12.setAttribute(fmin12.feedback, value);
fmin13.setAttribute(fmin13.feedback, value);
fmin14.setAttribute(fmin14.feedback, value);
fmin15.setAttribute(fmin15.feedback, value);
fmin16.setAttribute(fmin16.feedback, value);
fmin17.setAttribute(fmin17.feedback, value);
fmin18.setAttribute(fmin18.feedback, value);
fmin19.setAttribute(fmin19.feedback, value);
fmin20.setAttribute(fmin20.feedback, value);
fmin21.setAttribute(fmin21.feedback, value);
fmin22.setAttribute(fmin22.feedback, value);
fmin23.setAttribute(fmin23.feedback, value);
fmin24.setAttribute(fmin24.feedback, value);
fmin25.setAttribute(fmin25.feedback, value);
fmin26.setAttribute(fmin26.feedback, value);
fmin27.setAttribute(fmin27.feedback, value);
fmin28.setAttribute(fmin28.feedback, value);
fmin19.setAttribute(fmin29.feedback, value);
fmin30.setAttribute(fmin30.feedback, value);
fmin31.setAttribute(fmin31.feedback, value);
fmin32.setAttribute(fmin32.feedback, value);
fmin33.setAttribute(fmin33.feedback, value);
fmin34.setAttribute(fmin34.feedback, value);
fmin35.setAttribute(fmin35.feedback, value);
fmin36.setAttribute(fmin36.feedback, value);
fmin37.setAttribute(fmin37.feedback, value);
fmin38.setAttribute(fmin38.feedback, value);
fmin39.setAttribute(fmin39.feedback, value);
fmin40.setAttribute(fmin40.feedback, value);
fmin41.setAttribute(fmin41.feedback, value);
fmin42.setAttribute(fmin42.feedback, value);
fmin43.setAttribute(fmin43.feedback, value);
fmin44.setAttribute(fmin44.feedback, value);
fmin45.setAttribute(fmin45.feedback, value);
fmin46.setAttribute(fmin46.feedback, value);
fmin47.setAttribute(fmin47.feedback, value);
fmin48.setAttribute(fmin48.feedback, value);
    
     
     
};

Content.getComponent("Feedback").setControlCallback(onFeedbackControl);

const var FMmod1 = Content.getComponent("FMmod1");
{
	
}

inline function onFMmod1Control(component, value)
{

	fmin2.setAttribute(fmin1.fmmod, value);
fmin2.setAttribute(fmin2.fmmod, value);
fmin3.setAttribute(fmin3.fmmod, value);
fmin4.setAttribute(fmin4.fmmod, value);
fmin5.setAttribute(fmin5.fmmod, value);
fmin6.setAttribute(fmin6.fmmod, value);
fmin7.setAttribute(fmin7.fmmod, value);
fmin8.setAttribute(fmin8.fmmod, value);
fmin9.setAttribute(fmin9.fmmod, value);
fmin10.setAttribute(fmin10.fmmod, value);
fmin11.setAttribute(fmin11.fmmod, value);
fmin12.setAttribute(fmin12.fmmod, value);
fmin13.setAttribute(fmin13.fmmod, value);
fmin14.setAttribute(fmin14.fmmod, value);
fmin15.setAttribute(fmin15.fmmod, value);
fmin16.setAttribute(fmin16.fmmod, value);
fmin17.setAttribute(fmin17.fmmod, value);
fmin18.setAttribute(fmin18.fmmod, value);
fmin19.setAttribute(fmin19.fmmod, value);
fmin20.setAttribute(fmin20.fmmod, value);
fmin21.setAttribute(fmin21.fmmod, value);
fmin22.setAttribute(fmin22.fmmod, value);
fmin23.setAttribute(fmin23.fmmod, value);
fmin24.setAttribute(fmin24.fmmod, value);
fmin25.setAttribute(fmin25.fmmod, value);
fmin26.setAttribute(fmin26.fmmod, value);
fmin27.setAttribute(fmin27.fmmod, value);
fmin28.setAttribute(fmin28.fmmod, value);
fmin19.setAttribute(fmin29.fmmod, value);
fmin30.setAttribute(fmin30.fmmod, value);
fmin31.setAttribute(fmin31.fmmod, value);
fmin32.setAttribute(fmin32.fmmod, value);
fmin33.setAttribute(fmin33.fmmod, value);
fmin34.setAttribute(fmin34.fmmod, value);
fmin35.setAttribute(fmin35.fmmod, value);
fmin36.setAttribute(fmin36.fmmod, value);
fmin37.setAttribute(fmin37.fmmod, value);
fmin38.setAttribute(fmin38.fmmod, value);
fmin39.setAttribute(fmin39.fmmod, value);
fmin40.setAttribute(fmin40.fmmod, value);
fmin41.setAttribute(fmin41.fmmod, value);
fmin42.setAttribute(fmin42.fmmod, value);
fmin43.setAttribute(fmin43.fmmod, value);
fmin44.setAttribute(fmin44.fmmod, value);
fmin45.setAttribute(fmin45.fmmod, value);
fmin46.setAttribute(fmin46.fmmod, value);
fmin47.setAttribute(fmin47.fmmod, value);
fmin48.setAttribute(fmin48.fmmod, value);
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
fmin9.setAttribute(fmin9.fmdest, value);
fmin10.setAttribute(fmin10.fmdest, value);
fmin11.setAttribute(fmin11.fmdest, value);
fmin12.setAttribute(fmin12.fmdest, value);
fmin13.setAttribute(fmin13.fmdest, value);
fmin14.setAttribute(fmin14.fmdest, value);
fmin15.setAttribute(fmin15.fmdest, value);
fmin16.setAttribute(fmin16.fmdest, value);
fmin17.setAttribute(fmin17.fmdest, value);
fmin18.setAttribute(fmin18.fmdest, value);
fmin19.setAttribute(fmin19.fmdest, value);
fmin20.setAttribute(fmin20.fmdest, value);
fmin21.setAttribute(fmin21.fmdest, value);
fmin22.setAttribute(fmin22.fmdest, value);
fmin23.setAttribute(fmin23.fmdest, value);
fmin24.setAttribute(fmin24.fmdest, value);
fmin25.setAttribute(fmin25.fmdest, value);
fmin26.setAttribute(fmin26.fmdest, value);
fmin27.setAttribute(fmin27.fmdest, value);
fmin28.setAttribute(fmin28.fmdest, value);
fmin19.setAttribute(fmin29.fmdest, value);
fmin30.setAttribute(fmin30.fmdest, value);
fmin31.setAttribute(fmin31.fmdest, value);
fmin32.setAttribute(fmin32.fmdest, value);
fmin33.setAttribute(fmin33.fmdest, value);
fmin34.setAttribute(fmin34.fmdest, value);
fmin35.setAttribute(fmin35.fmdest, value);
fmin36.setAttribute(fmin36.fmdest, value);
fmin37.setAttribute(fmin37.fmdest, value);
fmin38.setAttribute(fmin38.fmdest, value);
fmin39.setAttribute(fmin39.fmdest, value);
fmin40.setAttribute(fmin40.fmdest, value);
fmin41.setAttribute(fmin41.fmdest, value);
fmin42.setAttribute(fmin42.fmdest, value);
fmin43.setAttribute(fmin43.fmdest, value);
fmin44.setAttribute(fmin44.fmdest, value);
fmin45.setAttribute(fmin45.fmdest, value);
fmin46.setAttribute(fmin46.fmdest, value);
fmin47.setAttribute(fmin47.fmdest, value);
fmin48.setAttribute(fmin48.fmdest, value);
    
     
     

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
fmin9.setAttribute(fmin9.feedmod, value);
fmin10.setAttribute(fmin10.feedmod, value);
fmin11.setAttribute(fmin11.feedmod, value);
fmin12.setAttribute(fmin12.feedmod, value);
fmin13.setAttribute(fmin13.feedmod, value);
fmin14.setAttribute(fmin14.feedmod, value);
fmin15.setAttribute(fmin15.feedmod, value);
fmin16.setAttribute(fmin16.feedmod, value);
fmin17.setAttribute(fmin17.feedmod, value);
fmin18.setAttribute(fmin18.feedmod, value);
fmin19.setAttribute(fmin19.feedmod, value);
fmin20.setAttribute(fmin20.feedmod, value);
fmin21.setAttribute(fmin21.feedmod, value);
fmin22.setAttribute(fmin22.feedmod, value);
fmin23.setAttribute(fmin23.feedmod, value);
fmin24.setAttribute(fmin24.feedmod, value);
fmin25.setAttribute(fmin25.feedmod, value);
fmin26.setAttribute(fmin26.feedmod, value);
fmin27.setAttribute(fmin27.feedmod, value);
fmin28.setAttribute(fmin28.feedmod, value);
fmin19.setAttribute(fmin29.feedmod, value);
fmin30.setAttribute(fmin30.feedmod, value);
fmin31.setAttribute(fmin31.feedmod, value);
fmin32.setAttribute(fmin32.feedmod, value);
fmin33.setAttribute(fmin33.feedmod, value);
fmin34.setAttribute(fmin34.feedmod, value);
fmin35.setAttribute(fmin35.feedmod, value);
fmin36.setAttribute(fmin36.feedmod, value);
fmin37.setAttribute(fmin37.feedmod, value);
fmin38.setAttribute(fmin38.feedmod, value);
fmin39.setAttribute(fmin39.feedmod, value);
fmin40.setAttribute(fmin40.feedmod, value);
fmin41.setAttribute(fmin41.feedmod, value);
fmin42.setAttribute(fmin42.feedmod, value);
fmin43.setAttribute(fmin43.feedmod, value);
fmin44.setAttribute(fmin44.feedmod, value);
fmin45.setAttribute(fmin45.feedmod, value);
fmin46.setAttribute(fmin46.feedmod, value);
fmin47.setAttribute(fmin47.feedmod, value);
fmin48.setAttribute(fmin48.feedmod, value);

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
fmin9.setAttribute(fmin9.feeddest, value);
fmin10.setAttribute(fmin10.feeddest, value);
fmin11.setAttribute(fmin11.feeddest, value);
fmin12.setAttribute(fmin12.feeddest, value);
fmin13.setAttribute(fmin13.feeddest, value);
fmin14.setAttribute(fmin14.feeddest, value);
fmin15.setAttribute(fmin15.feeddest, value);
fmin16.setAttribute(fmin16.feeddest, value);
fmin17.setAttribute(fmin17.feeddest, value);
fmin18.setAttribute(fmin18.feeddest, value);
fmin19.setAttribute(fmin19.feeddest, value);
fmin20.setAttribute(fmin20.feeddest, value);
fmin21.setAttribute(fmin21.feeddest, value);
fmin22.setAttribute(fmin22.feeddest, value);
fmin23.setAttribute(fmin23.feeddest, value);
fmin24.setAttribute(fmin24.feeddest, value);
fmin25.setAttribute(fmin25.feeddest, value);
fmin26.setAttribute(fmin26.feeddest, value);
fmin27.setAttribute(fmin27.feeddest, value);
fmin28.setAttribute(fmin28.feeddest, value);
fmin19.setAttribute(fmin29.feeddest, value);
fmin30.setAttribute(fmin30.feeddest, value);
fmin31.setAttribute(fmin31.feeddest, value);
fmin32.setAttribute(fmin32.feeddest, value);
fmin33.setAttribute(fmin33.feeddest, value);
fmin34.setAttribute(fmin34.feeddest, value);
fmin35.setAttribute(fmin35.feeddest, value);
fmin36.setAttribute(fmin36.feeddest, value);
fmin37.setAttribute(fmin37.feeddest, value);
fmin38.setAttribute(fmin38.feeddest, value);
fmin39.setAttribute(fmin39.feeddest, value);
fmin40.setAttribute(fmin40.feeddest, value);
fmin41.setAttribute(fmin41.feeddest, value);
fmin42.setAttribute(fmin42.feeddest, value);
fmin43.setAttribute(fmin43.feeddest, value);
fmin44.setAttribute(fmin44.feeddest, value);
fmin45.setAttribute(fmin45.feeddest, value);
fmin46.setAttribute(fmin46.feeddest, value);
fmin47.setAttribute(fmin47.feeddest, value);
fmin48.setAttribute(fmin48.feeddest, value);

};

Content.getComponent("FeedModSel1").setControlCallback(onFeedModSel1Control);