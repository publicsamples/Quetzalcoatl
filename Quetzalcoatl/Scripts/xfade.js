const var vecxfade = Synth.getModulator("vecxfade");
const var vecxfade2 = Synth.getModulator("vecxfade2");
const var vecxfade3 = Synth.getModulator("vecxfade3");
const var vecxfade4 = Synth.getModulator("vecxfade4");
const var vecxfade5 = Synth.getModulator("vecxfade5");
const var vecxfade6 = Synth.getModulator("vecxfade6");
const var Smooth = Content.getComponent("Smooth");
const var posmod = Content.getComponent("posmod");
const var xfadetype = Content.getComponent("xfadetype");

const var XFADE = Content.getComponent("XFADE");


inline function onXFADEControl(component, value)
{
vecxfade.setAttribute(vecxfade.scan, value);
   vecxfade2.setAttribute(vecxfade2.scan, value);
   vecxfade3.setAttribute(vecxfade3.scan, value);
   vecxfade4.setAttribute(vecxfade4.scan, value);
   vecxfade5.setAttribute(vecxfade5.scan, value);
   vecxfade6.setAttribute(vecxfade6.scan, value);
};

Content.getComponent("XFADE").setControlCallback(onXFADEControl);



inline function onSmoothControl(component, value)
{
 vecxfade.setAttribute(vecxfade.smooth, value);
 vecxfade2.setAttribute(vecxfade2.smooth, value);
   vecxfade3.setAttribute(vecxfade3.smooth, value);
   vecxfade4.setAttribute(vecxfade4.smooth, value);
   vecxfade5.setAttribute(vecxfade5.smooth, value);
   vecxfade6.setAttribute(vecxfade6.smooth, value);

};

Content.getComponent("Smooth").setControlCallback(onSmoothControl);


inline function onposmodControl(component, value)
{
 vecxfade.setAttribute(vecxfade.modamount, value);
    vecxfade2.setAttribute(vecxfade2.modamount, value);
      vecxfade3.setAttribute(vecxfade3.modamount, value);
      vecxfade4.setAttribute(vecxfade4.modamount, value);
      vecxfade5.setAttribute(vecxfade5.modamount, value);
   vecxfade6.setAttribute(vecxfade6.modamount, value);
};

Content.getComponent("posmod").setControlCallback(onposmodControl);




const var XFAttack = Content.getComponent("XFAttack");


inline function onXFAttackControl(component, value)
{
 vecxfade.setAttribute(vecxfade.atk, value);
    vecxfade2.setAttribute(vecxfade2.atk, value);
      vecxfade3.setAttribute(vecxfade3.atk, value);
      vecxfade4.setAttribute(vecxfade4.atk, value);
      vecxfade5.setAttribute(vecxfade5.atk, value);
   vecxfade6.setAttribute(vecxfade6.atk, value);
};

Content.getComponent("XFAttack").setControlCallback(onXFAttackControl);

const var XFDecay = Content.getComponent("XFDecay");


inline function onXFDecayControl(component, value)
{
 vecxfade.setAttribute(vecxfade.dcy, value);
    vecxfade2.setAttribute(vecxfade2.dcy, value);
      vecxfade3.setAttribute(vecxfade3.dcy, value);
      vecxfade4.setAttribute(vecxfade4.dcy, value);
      vecxfade5.setAttribute(vecxfade5.dcy, value);
   vecxfade6.setAttribute(vecxfade6.dcy, value);
};

Content.getComponent("XFDecay").setControlCallback(onXFDecayControl);

const var XFSustan = Content.getComponent("XFSustan");


inline function onXFSustanControl(component, value)
{
vecxfade.setAttribute(vecxfade.sus, value);
    vecxfade2.setAttribute(vecxfade2.sus, value);
      vecxfade3.setAttribute(vecxfade3.sus, value);
      vecxfade4.setAttribute(vecxfade4.sus, value);
      vecxfade5.setAttribute(vecxfade5.sus, value);
   vecxfade6.setAttribute(vecxfade6.sus, value);
};

Content.getComponent("XFSustan").setControlCallback(onXFSustanControl);

const var XFRel = Content.getComponent("XFRel");


inline function onXFRelControl(component, value)
{
	vecxfade.setAttribute(vecxfade.rel, value);
    vecxfade2.setAttribute(vecxfade2.rel, value);
      vecxfade3.setAttribute(vecxfade3.rel, value);
      vecxfade4.setAttribute(vecxfade4.rel, value);
      vecxfade5.setAttribute(vecxfade5.rel, value);
   vecxfade6.setAttribute(vecxfade6.rel, value);
};

Content.getComponent("XFRel").setControlCallback(onXFRelControl);




inline function onxfadetypeControl(component, value)
{
	
vecxfade.setAttribute(vecxfade.fadetype, value);
   vecxfade2.setAttribute(vecxfade2.fadetype, value);
   vecxfade3.setAttribute(vecxfade3.fadetype, value);
   vecxfade4.setAttribute(vecxfade4.fadetype, value);
   vecxfade5.setAttribute(vecxfade5.fadetype, value);
   vecxfade6.setAttribute(vecxfade6.fadetype, value);
};

Content.getComponent("xfadetype").setControlCallback(onxfadetypeControl);

const var Envelope1 = Synth.getModulator("Envelope1");
const var Envelope2 = Synth.getModulator("Envelope2");
const var Envelope3 = Synth.getModulator("Envelope3");
const var Envelope4 = Synth.getModulator("Envelope4");
const var Envelope5 = Synth.getModulator("Envelope5");
const var Envelope6 = Synth.getModulator("Envelope6");
const var Envelope7 = Synth.getModulator("Envelope7");
const var Envelope8 = Synth.getModulator("Envelope8");

const var Envelope10 = Synth.getModulator("Envelope10");
const var Envelope11 = Synth.getModulator("Envelope11");
const var Envelope12 = Synth.getModulator("Envelope12");
const var Envelope13 = Synth.getModulator("Envelope13");
const var Envelope14 = Synth.getModulator("Envelope14");
const var Envelope15 = Synth.getModulator("Envelope15");
const var Envelope16 = Synth.getModulator("Envelope16");
const var Envelope17 = Synth.getModulator("Envelope17");
const var Envelope18 = Synth.getModulator("Envelope18");
const var Envelope19 = Synth.getModulator("Envelope19");
const var Envelope20 = Synth.getModulator("Envelope20");
const var Envelope21 = Synth.getModulator("Envelope21");
const var Envelope22 = Synth.getModulator("Envelope22");
const var Envelope23 = Synth.getModulator("Envelope23");
const var Envelope24 = Synth.getModulator("Envelope24");
const var Envelope25 = Synth.getModulator("Envelope25");
const var Envelope26 = Synth.getModulator("Envelope26");
const var Envelope27 = Synth.getModulator("Envelope27");
const var Envelope28 = Synth.getModulator("Envelope28");
const var Envelope29 = Synth.getModulator("Envelope29");
const var Envelope30 = Synth.getModulator("Envelope30");
const var Envelope31 = Synth.getModulator("Envelope31");
const var Envelope32 = Synth.getModulator("Envelope32");
const var Envelope33 = Synth.getModulator("Envelope33");
const var Envelope34 = Synth.getModulator("Envelope34");
const var Envelope35 = Synth.getModulator("Envelope35");
const var Envelope36 = Synth.getModulator("Envelope36");
const var Envelope37 = Synth.getModulator("Envelope37");
const var Envelope38 = Synth.getModulator("Envelope38");
const var Envelope39 = Synth.getModulator("Envelope39");
const var Envelope40 = Synth.getModulator("Envelope40");
const var Envelope41 = Synth.getModulator("Envelope41");
const var Envelope42 = Synth.getModulator("Envelope42");
const var Envelope43 = Synth.getModulator("Envelope43");
const var Envelope44 = Synth.getModulator("Envelope44");
const var Envelope45 = Synth.getModulator("Envelope45");
const var Envelope46 = Synth.getModulator("Envelope46");
const var Envelope47 = Synth.getModulator("Envelope47");
const var Envelope48 = Synth.getModulator("Envelope48");
const var Envelope49 = Synth.getModulator("Envelope49");
const var Envelope50 = Synth.getModulator("Envelope50");
const var Envelope51 = Synth.getModulator("Envelope51");
const var Envelope52 = Synth.getModulator("Envelope52");
const var Envelope53 = Synth.getModulator("Envelope53");
const var Envelope54 = Synth.getModulator("Envelope54");

const var Envelope9 = Synth.getModulator("Envelope9");


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
	Envelope10.setAttribute(2, value);
	Envelope11.setAttribute(2, value);
	Envelope12.setAttribute(2, value);
	Envelope13.setAttribute(2, value);
	Envelope14.setAttribute(2, value);
	Envelope15.setAttribute(2, value);
	Envelope16.setAttribute(2, value);
	Envelope17.setAttribute(2, value);
	Envelope19.setAttribute(2, value);
	Envelope20.setAttribute(2, value);
	Envelope21.setAttribute(2, value);
	Envelope22.setAttribute(2, value);
	Envelope23.setAttribute(2, value);
	Envelope24.setAttribute(2, value);
	Envelope25.setAttribute(2, value);
	Envelope26.setAttribute(2, value);
	Envelope28.setAttribute(2, value);
	Envelope29.setAttribute(2, value);
	Envelope30.setAttribute(2, value);
	Envelope31.setAttribute(2, value);
	Envelope32.setAttribute(2, value);
	Envelope33.setAttribute(2, value);
	Envelope34.setAttribute(2, value);
	Envelope35.setAttribute(2, value);
	Envelope37.setAttribute(2, value);
	Envelope38.setAttribute(2, value);
	Envelope39.setAttribute(2, value);
	Envelope40.setAttribute(2, value);
	Envelope41.setAttribute(2, value);
	Envelope42.setAttribute(2, value);
	Envelope43.setAttribute(2, value);
	Envelope44.setAttribute(2, value);
	Envelope46.setAttribute(2, value);
	Envelope47.setAttribute(2, value);
	Envelope48.setAttribute(2, value);
	Envelope49.setAttribute(2, value);
	Envelope50.setAttribute(2, value);
	Envelope51.setAttribute(2, value);
	Envelope52.setAttribute(2, value);
	Envelope53.setAttribute(2, value);
	
	
	
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
	Envelope10.setAttribute(5, value);
	Envelope11.setAttribute(5, value);
	Envelope12.setAttribute(5, value);
	Envelope13.setAttribute(5, value);
	Envelope14.setAttribute(5, value);
	Envelope15.setAttribute(5, value);
	Envelope16.setAttribute(5, value);
	Envelope17.setAttribute(5, value);
	Envelope19.setAttribute(5, value);
	Envelope20.setAttribute(5, value);
	Envelope21.setAttribute(5, value);
	Envelope22.setAttribute(5, value);
	Envelope23.setAttribute(5, value);
	Envelope24.setAttribute(5, value);
	Envelope25.setAttribute(5, value);
	Envelope26.setAttribute(5, value);
	Envelope28.setAttribute(5, value);
	Envelope29.setAttribute(5, value);
	Envelope30.setAttribute(5, value);
	Envelope31.setAttribute(5, value);
	Envelope32.setAttribute(5, value);
	Envelope33.setAttribute(5, value);
	Envelope34.setAttribute(5, value);
	Envelope35.setAttribute(5, value);
	Envelope37.setAttribute(5, value);
	Envelope38.setAttribute(5, value);
	Envelope39.setAttribute(5, value);
	Envelope40.setAttribute(5, value);
	Envelope41.setAttribute(5, value);
	Envelope42.setAttribute(5, value);
	Envelope43.setAttribute(5, value);
	Envelope44.setAttribute(5, value);
	Envelope46.setAttribute(5, value);
	Envelope47.setAttribute(5, value);
	Envelope48.setAttribute(5, value);
	Envelope49.setAttribute(5, value);
	Envelope50.setAttribute(5, value);
	Envelope51.setAttribute(5, value);
	Envelope52.setAttribute(5, value);
	Envelope53.setAttribute(5, value);
	
	
};

Content.getComponent("VecDecay").setControlCallback(onVecDecayControl);

const var VecSustan = Content.getComponent("VecSustan");



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
	Envelope10.setAttribute(6, value);
	Envelope11.setAttribute(6, value);
	Envelope12.setAttribute(6, value);
	Envelope13.setAttribute(6, value);
	Envelope14.setAttribute(6, value);
	Envelope15.setAttribute(6, value);
	Envelope16.setAttribute(6, value);
	Envelope17.setAttribute(6, value);
	Envelope19.setAttribute(6, value);
	Envelope20.setAttribute(6, value);
	Envelope21.setAttribute(6, value);
	Envelope22.setAttribute(6, value);
	Envelope23.setAttribute(6, value);
	Envelope24.setAttribute(6, value);
	Envelope25.setAttribute(6, value);
	Envelope26.setAttribute(6, value);
	Envelope28.setAttribute(6, value);
	Envelope29.setAttribute(6, value);
	Envelope30.setAttribute(6, value);
	Envelope31.setAttribute(6, value);
	Envelope32.setAttribute(6, value);
	Envelope33.setAttribute(6, value);
	Envelope34.setAttribute(6, value);
	Envelope35.setAttribute(6, value);
	Envelope37.setAttribute(6, value);
	Envelope38.setAttribute(6, value);
	Envelope39.setAttribute(6, value);
	Envelope40.setAttribute(6, value);
	Envelope41.setAttribute(6, value);
	Envelope42.setAttribute(6, value);
	Envelope43.setAttribute(6, value);
	Envelope44.setAttribute(6, value);
	Envelope46.setAttribute(6, value);
	Envelope47.setAttribute(6, value);
	Envelope48.setAttribute(6, value);
	Envelope49.setAttribute(6, value);
	Envelope50.setAttribute(6, value);
	Envelope51.setAttribute(6, value);
	Envelope52.setAttribute(6, value);
	Envelope53.setAttribute(6, value);
	
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
	Envelope10.setAttribute(7, value);
	Envelope11.setAttribute(7, value);
	Envelope12.setAttribute(7, value);
	Envelope13.setAttribute(7, value);
	Envelope14.setAttribute(7, value);
	Envelope15.setAttribute(7, value);
	Envelope16.setAttribute(7, value);
	Envelope17.setAttribute(7, value);
	Envelope19.setAttribute(7, value);
	Envelope20.setAttribute(7, value);
	Envelope21.setAttribute(7, value);
	Envelope22.setAttribute(7, value);
	Envelope23.setAttribute(7, value);
	Envelope24.setAttribute(7, value);
	Envelope25.setAttribute(7, value);
	Envelope26.setAttribute(7, value);
	Envelope28.setAttribute(7, value);
	Envelope29.setAttribute(7, value);
	Envelope30.setAttribute(7, value);
	Envelope31.setAttribute(7, value);
	Envelope32.setAttribute(7, value);
	Envelope33.setAttribute(7, value);
	Envelope34.setAttribute(7, value);
	Envelope35.setAttribute(7, value);
	Envelope37.setAttribute(7, value);
	Envelope38.setAttribute(7, value);
	Envelope39.setAttribute(7, value);
	Envelope40.setAttribute(7, value);
	Envelope41.setAttribute(7, value);
	Envelope42.setAttribute(7, value);
	Envelope43.setAttribute(7, value);
	Envelope44.setAttribute(7, value);
	Envelope46.setAttribute(7, value);
	Envelope47.setAttribute(7, value);
	Envelope48.setAttribute(7, value);
	Envelope49.setAttribute(7, value);
	Envelope50.setAttribute(7, value);
	Envelope51.setAttribute(7, value);
	Envelope52.setAttribute(7, value);
	Envelope53.setAttribute(7, value);
	
	
};

Content.getComponent("VecRelease").setControlCallback(onVecReleaseControl);

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

const var Osc2Vol = Content.getComponent("Osc2Vol");


inline function onOsc2VolControl(component, value)
{
	Sampler1.setAttribute(0, value);
	Sampler2.setAttribute(0, value);
	Sampler3.setAttribute(0, value);
	Sampler4.setAttribute(0, value);
	Sampler5.setAttribute(0, value);
	Sampler6.setAttribute(0, value);
	Sampler7.setAttribute(0, value);
	Sampler8.setAttribute(0, value);
	Sampler10.setAttribute(0, value);
	Sampler11.setAttribute(0, value);
	Sampler12.setAttribute(0, value);
	Sampler13.setAttribute(0, value);
	Sampler14.setAttribute(0, value);
	Sampler15.setAttribute(0, value);
	Sampler16.setAttribute(0, value);
	Sampler17.setAttribute(0, value);
	Sampler19.setAttribute(0, value);
	Sampler20.setAttribute(0, value);
	Sampler21.setAttribute(0, value);
	Sampler22.setAttribute(0, value);
	Sampler23.setAttribute(0, value);
	Sampler24.setAttribute(0, value);
	Sampler25.setAttribute(0, value);
	Sampler26.setAttribute(0, value);
	Sampler28.setAttribute(0, value);
	Sampler29.setAttribute(0, value);
	Sampler30.setAttribute(0, value);
	Sampler31.setAttribute(0, value);
	Sampler32.setAttribute(0, value);
	Sampler33.setAttribute(0, value);
	Sampler34.setAttribute(0, value);
	Sampler35.setAttribute(0, value);
	Sampler37.setAttribute(0, value);
	Sampler38.setAttribute(0, value);
	Sampler39.setAttribute(0, value);
	Sampler40.setAttribute(0, value);
	Sampler41.setAttribute(0, value);
	Sampler42.setAttribute(0, value);
	Sampler43.setAttribute(0, value);
	Sampler44.setAttribute(0, value);
	Sampler46.setAttribute(0, value);
	Sampler47.setAttribute(0, value);
	Sampler48.setAttribute(0, value);
	Sampler49.setAttribute(0, value);
	Sampler50.setAttribute(0, value);
	Sampler51.setAttribute(0, value);
	Sampler52.setAttribute(0, value);
	Sampler53.setAttribute(0, value);
};

Content.getComponent("Osc2Vol").setControlCallback(onOsc2VolControl);


const var spitch1 = Synth.getModulator("spitch1");
const var spitch2 = Synth.getModulator("spitch2");
const var spitch3 = Synth.getModulator("spitch3");
const var spitch4 = Synth.getModulator("spitch4");
const var spitch5 = Synth.getModulator("spitch5");
const var spitch6 = Synth.getModulator("spitch6");
const var spitch7 = Synth.getModulator("spitch7");
const var spitch8 = Synth.getModulator("spitch8");
const var spitch9 = Synth.getModulator("spitch9");
const var spitch10 = Synth.getModulator("spitch10");
const var spitch11 = Synth.getModulator("spitch11");
const var spitch12 = Synth.getModulator("spitch12");
const var spitch13 = Synth.getModulator("spitch13");
const var spitch14 = Synth.getModulator("spitch14");
const var spitch15 = Synth.getModulator("spitch15");
const var spitch16 = Synth.getModulator("spitch16");
const var spitch17 = Synth.getModulator("spitch17");
const var spitch18 = Synth.getModulator("spitch18");
const var spitch19 = Synth.getModulator("spitch19");
const var spitch20 = Synth.getModulator("spitch20");
const var spitch21 = Synth.getModulator("spitch21");
const var spitch22 = Synth.getModulator("spitch22");
const var spitch23 = Synth.getModulator("spitch23");
const var spitch24 = Synth.getModulator("spitch24");
const var spitch25 = Synth.getModulator("spitch25");
const var spitch26 = Synth.getModulator("spitch26");
const var spitch27 = Synth.getModulator("spitch27");
const var spitch28 = Synth.getModulator("spitch28");
const var spitch29 = Synth.getModulator("spitch29");
const var spitch30 = Synth.getModulator("spitch30");
const var spitch31 = Synth.getModulator("spitch31");
const var spitch32 = Synth.getModulator("spitch32");
const var spitch33 = Synth.getModulator("spitch33");
const var spitch34 = Synth.getModulator("spitch34");
const var spitch35 = Synth.getModulator("spitch35");
const var spitch36 = Synth.getModulator("spitch36");
const var spitch37 = Synth.getModulator("spitch37");
const var spitch38 = Synth.getModulator("spitch38");
const var spitch39 = Synth.getModulator("spitch39");
const var spitch40 = Synth.getModulator("spitch40");
const var spitch41 = Synth.getModulator("spitch41");
const var spitch42 = Synth.getModulator("spitch42");
const var spitch43 = Synth.getModulator("spitch43");
const var spitch44 = Synth.getModulator("spitch44");
const var spitch45 = Synth.getModulator("spitch45");
const var spitch46 = Synth.getModulator("spitch46");
const var spitch47 = Synth.getModulator("spitch47");
const var spitch48 = Synth.getModulator("spitch48");
const var spitch49 = Synth.getModulator("spitch49");
const var spitch50 = Synth.getModulator("spitch50");
const var spitch51 = Synth.getModulator("spitch51");
const var spitch52 = Synth.getModulator("spitch52");
const var spitch53 = Synth.getModulator("spitch53");
const var spitch54 = Synth.getModulator("spitch54");
const var spitch55 = Synth.getModulator("spitch55");
const var spitch56 = Synth.getModulator("spitch56");
const var spitch57 = Synth.getModulator("spitch57");
const var spitch58 = Synth.getModulator("spitch58");
const var spitch59 = Synth.getModulator("spitch59");
const var spitch60 = Synth.getModulator("spitch60");
const var spitch61 = Synth.getModulator("spitch61");
const var spitch62 = Synth.getModulator("spitch62");
const var spitch63 = Synth.getModulator("spitch63");
const var spitch64 = Synth.getModulator("spitch64");
const var spitch65 = Synth.getModulator("spitch65");
const var spitch66 = Synth.getModulator("spitch66");
const var spitch67 = Synth.getModulator("spitch67");
const var spitch68 = Synth.getModulator("spitch68");
const var spitch69 = Synth.getModulator("spitch69");
const var spitch70 = Synth.getModulator("spitch60");
const var spitch71 = Synth.getModulator("spitch71");
const var spitch72 = Synth.getModulator("spitch72");
const var spitch73 = Synth.getModulator("spitch73");
const var spitch74 = Synth.getModulator("spitch74");
const var spitch75 = Synth.getModulator("spitch75");
const var spitch76 = Synth.getModulator("spitch76");
const var spitch77 = Synth.getModulator("spitch77");
const var spitch78 = Synth.getModulator("spitch78");
const var spitch79 = Synth.getModulator("spitch79");
const var spitch80 = Synth.getModulator("spitch80");
const var spitch81 = Synth.getModulator("spitch81");
const var spitch82 = Synth.getModulator("spitch82");
const var spitch83 = Synth.getModulator("spitch83");
const var spitch84 = Synth.getModulator("spitch84");
const var spitch85 = Synth.getModulator("spitch85");
const var spitch86 = Synth.getModulator("spitch86");
const var spitch87 = Synth.getModulator("spitch87");
const var spitch88 = Synth.getModulator("spitch88");
const var spitch89 = Synth.getModulator("spitch89");
const var spitch90 = Synth.getModulator("spitch90");
const var spitch91 = Synth.getModulator("spitch91");
const var spitch92 = Synth.getModulator("spitch92");
const var spitch93 = Synth.getModulator("spitch93");
const var spitch94 = Synth.getModulator("spitch94");
const var spitch95 = Synth.getModulator("spitch95");
const var spitch96 = Synth.getModulator("spitch96");

const var Osc1Oct1 = Content.getComponent("Osc1Oct1");
const var Osc1Oct2 = Content.getComponent("Osc1Oct2");
const var Osc1Oct3 = Content.getComponent("Osc1Oct3");
const var Osc1Oct4 = Content.getComponent("Osc1Oct4");
const var Osc1Oct5 = Content.getComponent("Osc1Oct5");
const var Osc1Oct6 = Content.getComponent("Osc1Oct6");
const var Osc1Oct7 = Content.getComponent("Osc1Oct7");
const var Osc1Oct8 = Content.getComponent("Osc1Oct8");

const var Osc1Pitch1 = Content.getComponent("Osc1Pitch1");
const var Osc1Pitch2 = Content.getComponent("Osc1Pitch2");
const var Osc1Pitch3 = Content.getComponent("Osc1Pitch3");
const var Osc1Pitch4 = Content.getComponent("Osc1Pitch4");
const var Osc1Pitch5 = Content.getComponent("Osc1Pitch5");
const var Osc1Pitch6 = Content.getComponent("Osc1Pitch6");
const var Osc1Pitch7 = Content.getComponent("Osc1Pitch7");
const var Osc1Pitch8 = Content.getComponent("Osc1Pitch8");

inline function onOsc1Oct1Control(component, value)
{
	spitch1.setIntensity(value);
	spitch17.setIntensity(value);
	spitch33.setIntensity(value);
	spitch49.setIntensity(value);
	spitch65.setIntensity(value);
	spitch81.setIntensity(value);
};

Content.getComponent("Osc1Oct1").setControlCallback(onOsc1Oct1Control);


inline function onOsc1Pitch1Control(component, value)
{
	spitch2.setIntensity(value);
	spitch18.setIntensity(value);
	spitch34.setIntensity(value);
	spitch50.setIntensity(value);
	spitch66.setIntensity(value);
	spitch82.setIntensity(value);
};

Content.getComponent("Osc1Pitch1").setControlCallback(onOsc1Pitch1Control);


inline function onOsc1Oct2Control(component, value)
{
		spitch3.setIntensity(value);
	spitch19.setIntensity(value);
	spitch35.setIntensity(value);
	spitch51.setIntensity(value);
	spitch67.setIntensity(value);
	spitch83.setIntensity(value);
};

Content.getComponent("Osc1Oct2").setControlCallback(onOsc1Oct2Control);


inline function onOsc1Pitch2Control(component, value)
{
spitch4.setIntensity(value);
spitch20.setIntensity(value);
spitch36.setIntensity(value);
spitch52.setIntensity(value);
spitch68.setIntensity(value);
spitch84.setIntensity(value);
};

Content.getComponent("Osc1Pitch2").setControlCallback(onOsc1Pitch2Control);


inline function onOsc1Oct3Control(component, value)
{
	spitch5.setIntensity(value);
spitch21.setIntensity(value);
spitch37.setIntensity(value);
spitch53.setIntensity(value);
spitch69.setIntensity(value);
spitch85.setIntensity(value);
};

Content.getComponent("Osc1Oct3").setControlCallback(onOsc1Oct3Control);


inline function onOsc1Pitch3Control(component, value)
{
	spitch6.setIntensity(value);
spitch22.setIntensity(value);
spitch38.setIntensity(value);
spitch54.setIntensity(value);
spitch70.setIntensity(value);
spitch86.setIntensity(value);
};

Content.getComponent("Osc1Pitch3").setControlCallback(onOsc1Pitch3Control);


inline function onOsc1Oct4Control(component, value)
{
		spitch7.setIntensity(value);
spitch23.setIntensity(value);
spitch39.setIntensity(value);
spitch55.setIntensity(value);
spitch71.setIntensity(value);
spitch87.setIntensity(value);
};

Content.getComponent("Osc1Oct4").setControlCallback(onOsc1Oct4Control);


inline function onOsc1Pitch4Control(component, value)
{
	spitch8.setIntensity(value);
spitch24.setIntensity(value);
spitch40.setIntensity(value);
spitch56.setIntensity(value);
spitch72.setIntensity(value);
spitch88.setIntensity(value);
};

Content.getComponent("Osc1Pitch4").setControlCallback(onOsc1Pitch4Control);


inline function onOsc1Oct5Control(component, value)
{
	
spitch9.setIntensity(value);
spitch25.setIntensity(value);
spitch41.setIntensity(value);
spitch57.setIntensity(value);
spitch73.setIntensity(value);
spitch89.setIntensity(value);
};

Content.getComponent("Osc1Oct5").setControlCallback(onOsc1Oct5Control);


inline function onOsc1Pitch15Control(component, value)
{
spitch10.setIntensity(value);
spitch26.setIntensity(value);
spitch42.setIntensity(value);
spitch58.setIntensity(value);
spitch74.setIntensity(value);
spitch90.setIntensity(value);
};

Content.getComponent("Osc1Pitch5").setControlCallback(onOsc1Pitch5Control);


inline function onOsc1Oct6Control(component, value)
{
	spitch11.setIntensity(value);
spitch27.setIntensity(value);
spitch43.setIntensity(value);
spitch59.setIntensity(value);
spitch75.setIntensity(value);
spitch91.setIntensity(value);
};

Content.getComponent("Osc1Oct6").setControlCallback(onOsc1Oct6Control);


inline function onOsc1Pitch6Control(component, value)
{
spitch12.setIntensity(value);
spitch28.setIntensity(value);
spitch44.setIntensity(value);
spitch60.setIntensity(value);
spitch76.setIntensity(value);
spitch92.setIntensity(value);
};

Content.getComponent("Osc1Pitch6").setControlCallback(onOsc1Pitch6Control);


inline function onOsc1Oct7Control(component, value)
{
spitch13.setIntensity(value);
spitch29.setIntensity(value);
spitch45.setIntensity(value);
spitch61.setIntensity(value);
spitch77.setIntensity(value);
spitch93.setIntensity(value);
};

Content.getComponent("Osc1Oct7").setControlCallback(onOsc1Oct7Control);


inline function onOsc1Pitch7Control(component, value)
{
spitch14.setIntensity(value);
spitch30.setIntensity(value);
spitch46.setIntensity(value);
spitch62.setIntensity(value);
spitch78.setIntensity(value);
spitch94.setIntensity(value);
};

Content.getComponent("Osc1Pitch7").setControlCallback(onOsc1Pitch7Control);


inline function onOsc1Oct8Control(component, value)
{
spitch15.setIntensity(value);
spitch31.setIntensity(value);
spitch47.setIntensity(value);
spitch63.setIntensity(value);
spitch79.setIntensity(value);
spitch95.setIntensity(value);
};

Content.getComponent("Osc1Oct8").setControlCallback(onOsc1Oct8Control);

 
 inline function onOsc1Pitch8Control(component, value)
 {
spitch16.setIntensity(value);
spitch32.setIntensity(value);
spitch48.setIntensity(value);
spitch64.setIntensity(value);
spitch80.setIntensity(value);
spitch96.setIntensity(value);
 };
 
 Content.getComponent("Osc1Pitch8").setControlCallback(onOsc1Pitch8Control);
 
 const var Osc1Vol1 = Content.getComponent("Osc1Vol1");
const var Osc1Vol2 = Content.getComponent("Osc1Vol2"); 
 const var Osc1Vol3 = Content.getComponent("Osc1Vol3");
 const var Osc1Vol4 = Content.getComponent("Osc1Vol4");
 const var Osc1Vol5 = Content.getComponent("Osc1Vol5");
 const var Osc1Vol6 = Content.getComponent("Osc1Vol6");
 const var Osc1Vol7 = Content.getComponent("Osc1Vol7");
 const var Osc1Vol8 = Content.getComponent("Osc1Vol8");
 
 inline function onOsc1Vol1Control(component, value)
 {
 	Group1.setAttribute(0, value);
 	Group9.setAttribute(0, value);
 	Group17.setAttribute(0, value);
 	Group25.setAttribute(0, value);
 	Group33.setAttribute(0, value);
 	Group41.setAttribute(0, value);
 };
 
 Content.getComponent("Osc1Vol1").setControlCallback(onOsc1Vol1Control);
 
 inline function onOsc1Vol2Control(component, value)
 {
 	Group2.setAttribute(0, value);
 	Group10.setAttribute(0, value);
 	Group18.setAttribute(0, value);
 	Group26.setAttribute(0, value);
 	Group34.setAttribute(0, value);
 	Group42.setAttribute(0, value);
 };
 
 Content.getComponent("Osc1Vol2").setControlCallback(onOsc1Vol2Control);
 
 inline function onOsc1Vol3Control(component, value)
 {
 	Group3.setAttribute(0, value);
 	Group11.setAttribute(0, value);
 	Group19.setAttribute(0, value);
 	Group27.setAttribute(0, value);
 	Group35.setAttribute(0, value);
 	Group43.setAttribute(0, value);
 };
 
 Content.getComponent("Osc1Vol3").setControlCallback(onOsc1Vol3Control);
 
 inline function onOsc1Vol4Control(component, value)
 {
 	Group4.setAttribute(0, value);
 	Group12.setAttribute(0, value);
 	Group20.setAttribute(0, value);
 	Group28.setAttribute(0, value);
 	Group36.setAttribute(0, value);
 	Group44.setAttribute(0, value);
 };
 
 Content.getComponent("Osc1Vol4").setControlCallback(onOsc1Vol4Control);
 
 inline function onOsc1Vol5Control(component, value)
 {
 	Group5.setAttribute(0, value);
 	Group13.setAttribute(0, value);
 	Group21.setAttribute(0, value);
 	Group29.setAttribute(0, value);
 	Group37.setAttribute(0, value);
 	Group45.setAttribute(0, value);
 };
 
 Content.getComponent("Osc1Vol5").setControlCallback(onOsc1Vol5Control);
 
 inline function onOsc1Vol6Control(component, value)
 {
 	Group6.setAttribute(0, value);
 	Group14.setAttribute(0, value);
 	Group22.setAttribute(0, value);
 	Group30.setAttribute(0, value);
 	Group38.setAttribute(0, value);
 	Group46.setAttribute(0, value);
 };
 
 Content.getComponent("Osc1Vol6").setControlCallback(onOsc1Vol6Control);
 
 inline function onOsc1Vol7Control(component, value)
 {
 	Group7.setAttribute(0, value);
 	Group15.setAttribute(0, value);
 	Group23.setAttribute(0, value);
 	Group31.setAttribute(0, value);
 	Group39.setAttribute(0, value);
 	Group47.setAttribute(0, value);
 };
 
 Content.getComponent("Osc1Vol7").setControlCallback(onOsc1Vol7Control);
 
 inline function onOsc1Vol8Control(component, value)
 {
 	Group8.setAttribute(0, value);
 	Group16.setAttribute(0, value);
 	Group24.setAttribute(0, value);
 	Group32.setAttribute(0, value);
 	Group40.setAttribute(0, value);
 	Group48.setAttribute(0, value);
 };
 
 Content.getComponent("Osc1Vol8").setControlCallback(onOsc1Vol8Control);
 
 const var Osc1Pan1 = Content.getComponent("Osc1Pan1");
 const var Osc1Pan2 = Content.getComponent("Osc1Pan2"); 
 const var Osc1Pan3 = Content.getComponent("Osc1Pan3");
 const var Osc1Pan4 = Content.getComponent("Osc1Pan4");
 const var Osc1Pan5 = Content.getComponent("Osc1Pan5");
 const var Osc1Pan6 = Content.getComponent("Osc1Pan6");
 const var Osc1Pan7 = Content.getComponent("Osc1Pan7");
 const var Osc1Pan8 = Content.getComponent("Osc1Pan8");
 
 inline function onOsc1Pan1Control(component, value)
 {
 	Group1.setAttribute(1, value);
 	Group9.setAttribute(1, value);
 	Group17.setAttribute(1, value);
 	Group25.setAttribute(1, value);
 	Group33.setAttribute(1, value);
 	Group41.setAttribute(1, value);
 };
 
 Content.getComponent("Osc1Pan1").setControlCallback(onOsc1Pan1Control);
 
 inline function onOsc1Pan2Control(component, value)
 {
 	Group2.setAttribute(1, value);
 	Group10.setAttribute(1, value);
 	Group18.setAttribute(1, value);
 	Group26.setAttribute(1, value);
 	Group34.setAttribute(1, value);
 	Group42.setAttribute(1, value);
 };
 
 Content.getComponent("Osc1Pan2").setControlCallback(onOsc1Pan2Control);
 
 inline function onOsc1Pan3Control(component, value)
 {
 	Group3.setAttribute(1, value);
 	Group11.setAttribute(1, value);
 	Group19.setAttribute(1, value);
 	Group27.setAttribute(1, value);
 	Group35.setAttribute(1, value);
 	Group43.setAttribute(1, value);
 };
 
 Content.getComponent("Osc1Pan3").setControlCallback(onOsc1Pan3Control);
 
 inline function onOsc1Pan4Control(component, value)
 {
 	Group4.setAttribute(1, value);
 	Group12.setAttribute(1, value);
 	Group20.setAttribute(1, value);
 	Group28.setAttribute(1, value);
 	Group36.setAttribute(1, value);
 	Group44.setAttribute(1, value);
 };
 
 Content.getComponent("Osc1Pan4").setControlCallback(onOsc1Pan4Control);
 
 inline function onOsc1Pan5Control(component, value)
 {
 	Group5.setAttribute(1, value);
 	Group13.setAttribute(1, value);
 	Group21.setAttribute(1, value);
 	Group29.setAttribute(1, value);
 	Group37.setAttribute(1, value);
 	Group45.setAttribute(1, value);
 };
 
 Content.getComponent("Osc1Pan5").setControlCallback(onOsc1Pan5Control);
 
 inline function onOsc1Pan6Control(component, value)
 {
 	Group6.setAttribute(1, value);
 	Group14.setAttribute(1, value);
 	Group22.setAttribute(1, value);
 	Group30.setAttribute(1, value);
 	Group38.setAttribute(1, value);
 	Group46.setAttribute(1, value);
 };
 
 Content.getComponent("Osc1Pan6").setControlCallback(onOsc1Pan6Control);
 
 inline function onOsc1Pan7Control(component, value)
 {
 	Group7.setAttribute(1, value);
 	Group15.setAttribute(1, value);
 	Group23.setAttribute(1, value);
 	Group31.setAttribute(1, value);
 	Group39.setAttribute(1, value);
 	Group47.setAttribute(1, value);
 };
 
 Content.getComponent("Osc1Pan7").setControlCallback(onOsc1Pan7Control);
 
 inline function onOsc1Pan8Control(component, value)
 {
 	Group8.setAttribute(1, value);
 	Group16.setAttribute(1, value);
 	Group24.setAttribute(1, value);
 	Group32.setAttribute(1, value);
 	Group40.setAttribute(1, value);
 	Group48.setAttribute(1, value);
 };
 
 Content.getComponent("Osc1Pan8").setControlCallback(onOsc1Pan8Control);
 



const var step4 = Content.getComponent("Modulator4");


const var Modulator4 = Content.getComponent("Modulator4");



const var Mod4extraSL3 = Content.getComponent("Mod4extraSL3");
const var Mod4extraSL4 = Content.getComponent("Mod4extraSL4");
const var Mod4extraSL5 = Content.getComponent("Mod4extraSL5");
const var Mod4extraSL6 = Content.getComponent("Mod4extraSL6");
const var Mod4extraSL7 = Content.getComponent("Mod4extraSL7");







inline function onModulator4Control(component, value)
{

    
    Mod4extraSL3.setSliderAtIndex(value, component.getSliderValueAt(value));
    Mod4extraSL4.setSliderAtIndex(value, component.getSliderValueAt(value));
    Mod4extraSL5.setSliderAtIndex(value, component.getSliderValueAt(value));
    Mod4extraSL6.setSliderAtIndex(value, component.getSliderValueAt(value));
     Mod4extraSL7.setSliderAtIndex(value, component.getSliderValueAt(value));
  
};

Content.getComponent("Modulator4").setControlCallback(onModulator4Control);





const var tempo4 = Content.getComponent("tempo4");


inline function ontempo4Control(component, value)
{
	vecxfade.setAttribute(vecxfade.temp, value);
   vecxfade2.setAttribute(vecxfade2.temp, value);
   vecxfade3.setAttribute(vecxfade3.temp, value);
   vecxfade4.setAttribute(vecxfade4.temp, value);
   vecxfade5.setAttribute(vecxfade5.temp, value);
   vecxfade6.setAttribute(vecxfade6.temp, value);


};

Content.getComponent("tempo4").setControlCallback(ontempo4Control);

const var multi3 = Content.getComponent("multi3");


inline function onmulti3Control(component, value)
{
	vecxfade.setAttribute(vecxfade.div, value);
   vecxfade2.setAttribute(vecxfade2.div, value);
   vecxfade3.setAttribute(vecxfade3.div, value);
   vecxfade4.setAttribute(vecxfade4.div, value);
   vecxfade5.setAttribute(vecxfade5.div, value);
   vecxfade6.setAttribute(vecxfade6.div, value);

};

Content.getComponent("multi3").setControlCallback(onmulti3Control);

const var mod3 = Content.getComponent("mod3");

inline function onmod3Control(component, value)
{
vecxfade.setAttribute(vecxfade.tempomod, value);
   vecxfade2.setAttribute(vecxfade2.tempomod, value);
   vecxfade3.setAttribute(vecxfade3.tempomod, value);
   vecxfade4.setAttribute(vecxfade4.tempomod, value);
   vecxfade5.setAttribute(vecxfade5.tempomod, value);
   vecxfade6.setAttribute(vecxfade6.tempomod, value);


};

Content.getComponent("mod3").setControlCallback(onmod3Control);

const var moddest = Content.getComponent("moddest");


inline function onmoddestControl(component, value)
{
vecxfade.setAttribute(vecxfade.mdest, value);
   vecxfade2.setAttribute(vecxfade2.mdest, value);
   vecxfade3.setAttribute(vecxfade3.mdest, value);
   vecxfade4.setAttribute(vecxfade4.mdest, value);
   vecxfade5.setAttribute(vecxfade5.mdest, value);
   vecxfade6.setAttribute(vecxfade6.mdest, value);

    

};

Content.getComponent("moddest").setControlCallback(onmoddestControl);

const var trig4 = Content.getComponent("trig4");


inline function ontrig4Control(component, value)
{
vecxfade.setAttribute(vecxfade.ksync, value);
   vecxfade2.setAttribute(vecxfade2.ksync, value);
   vecxfade3.setAttribute(vecxfade3.ksync, value);
   vecxfade4.setAttribute(vecxfade4.ksync, value);
   vecxfade5.setAttribute(vecxfade5.ksync, value);
   vecxfade6.setAttribute(vecxfade6.ksync, value);

   

};



const var one4 = Content.getComponent("one4");


inline function onone4Control(component, value)
{
   vecxfade.setAttribute(vecxfade.one, value);
   vecxfade2.setAttribute(vecxfade2.one, value);
   vecxfade3.setAttribute(vecxfade3.one, value);
   vecxfade4.setAttribute(vecxfade4.one, value);
   vecxfade5.setAttribute(vecxfade5.one, value);
   vecxfade6.setAttribute(vecxfade6.one, value);


};

Content.getComponent("one4").setControlCallback(onone4Control);

const var type = Content.getComponent("type");
const var step = Content.getComponent("step");
const var xfenv = Content.getComponent("xfenv");

inline function ontypeControl(number, value)
{
        step.showControl(value);
        xfenv.showControl(1-value); 
        
        vecxfade.setAttribute(vecxfade.type, 0);
        vecxfade.setAttribute(vecxfade.type, 1-value);
        vecxfade2.setAttribute(vecxfade2.type, 0);
        vecxfade2.setAttribute(vecxfade2.type, 1-value);
        vecxfade3.setAttribute(vecxfade3.type, 0);
        vecxfade3.setAttribute(vecxfade3.type, 1-value);
        vecxfade4.setAttribute(vecxfade4.type, 0);
        vecxfade4.setAttribute(vecxfade4.type, 1-value);
        vecxfade5.setAttribute(vecxfade5.type, 0);
        vecxfade5.setAttribute(vecxfade5.type, 1-value);
        vecxfade6.setAttribute(vecxfade6.type, 0);
        vecxfade6.setAttribute(vecxfade6.type, 1-value); 
}

type.setControlCallback(ontypeControl);

const var XFHold = Content.getComponent("XFHold");


inline function onXFHoldControl(component, value)
{
	vecxfade.setAttribute(vecxfade.hold, value);
   vecxfade2.setAttribute(vecxfade2.hold, value);
   vecxfade3.setAttribute(vecxfade3.hold, value);
   vecxfade4.setAttribute(vecxfade4.hold, value);
   vecxfade5.setAttribute(vecxfade5.hold, value);
   vecxfade6.setAttribute(vecxfade6.hold, value);
};

Content.getComponent("XFHold").setControlCallback(onXFHoldControl);

