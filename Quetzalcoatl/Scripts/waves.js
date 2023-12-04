const audio = Engine.createAndRegisterAudioFile(0);

const samplemaps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");


var Maps = [];




Maps.push(ModFM);
Maps.push(ModFiltered);
Maps.push(ModShape);
Maps.push(Stereo);
Maps.push(CSWaves);



var SMAPS = ["ModFM", "ModFiltered", "ModShape","Stereo", "CSWaves"];

const var Categories = Content.getComponent("Categories");

Categories.set("items", SMAPS.join("\n"));

// BANK A

const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);
const slot2 = harm.getAudioFile(2);
const slot3 = harm.getAudioFile(3);
const slot4 = harm.getAudioFile(4);
const slot5 = harm.getAudioFile(5);
const slot6 = harm.getAudioFile(6);
const slot7 = harm.getAudioFile(7);

const slotC = harm.getAudioFile(16);
const slotC1 = harm.getAudioFile(17);
const slotC2 = harm.getAudioFile(18);
const slotC3 = harm.getAudioFile(19);
const slotC4 = harm.getAudioFile(20);
const slotC5 = harm.getAudioFile(21);
const slotC6 = harm.getAudioFile(22);
const slotC7 = harm.getAudioFile(23);

 
inline function onCategoriesControl(component, value)
 {
 
 	XBankA1.set("items", [].join("\n")); 
 	XBankA1.set("items", Maps[value-1].join("\n"));
 	XBankA1.setValue(1);
 	XBankA2.set("items", [].join("\n")); 
 	XBankA2.set("items", Maps[value-1].join("\n"));
 	 XBankA2.setValue(1);
 	 XBankA3.set("items", [].join("\n")); 
 	 XBankA3.set("items", Maps[value-1].join("\n"));
 	 XBankA3.setValue(1);
 	 XBankA4.set("items", [].join("\n")); 
 	 XBankA4.set("items", Maps[value-1].join("\n"));
 	 XBankA4.setValue(1);
 	 XBankA5.set("items", [].join("\n")); 
 	 XBankA5.set("items", Maps[value-1].join("\n"));
 	 XBankA5.setValue(1);
 	 XBankA6.set("items", [].join("\n")); 
 	 XBankA6.set("items", Maps[value-1].join("\n"));
 	 XBankA6.setValue(1);
 	 XBankA7.set("items", [].join("\n")); 
 	 XBankA7.set("items", Maps[value-1].join("\n"));
 	 XBankA7.setValue(1);
 	 XBankA8.set("items", [].join("\n")); 
 	  	 XBankA8.set("items", Maps[value-1].join("\n"));
 	  	 XBankA8.setValue(1);
 	

 };
 
 Content.getComponent("Categories").setControlCallback(onCategoriesControl);
 


 


const var XlAble1 = Content.getComponent("XlAble1");
const var XlAble2 = Content.getComponent("XlAble2");
const var XlAble3 = Content.getComponent("XlAble3");
const var XlAble4 = Content.getComponent("XlAble4");
const var XlAble5 = Content.getComponent("XlAble5");
const var XlAble6 = Content.getComponent("XlAble6");
const var XlAble7 = Content.getComponent("XlAble7");
const var XlAble8 = Content.getComponent("XlAble8");

 
 const var XBankA1 = Content.getComponent("XBankA1");
 const var XBankA2 = Content.getComponent("XBankA2");
 const var XBankA3 = Content.getComponent("XBankA3");
 const var XBankA4 = Content.getComponent("XBankA4");
 const var XBankA5 = Content.getComponent("XBankA5");
 const var XBankA6 = Content.getComponent("XBankA6");
 const var XBankA7 = Content.getComponent("XBankA7");
 const var XBankA8 = Content.getComponent("XBankA8");

inline function onXBankA1Control(component, value)
{
XlAble1.set("text",XBankA1.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

 	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA1").setControlCallback(onXBankA1Control);

inline function onXBankA2Control(component, value)
{
XlAble2.set("text",XBankA2.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
 	slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA2").setControlCallback(onXBankA2Control);

inline function onXBankA3Control(component, value)
{
XlAble3.set("text",XBankA3.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
 	slot2.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA3").setControlCallback(onXBankA3Control);

inline function onXBankA4Control(component, value)
{
XlAble4.set("text",XBankA4.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
 	slot3.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA4").setControlCallback(onXBankA4Control);
 
inline function onXBankA5Control(component, value)
{
XlAble5.set("text",XBankA5.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
 	slot4.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA5").setControlCallback(onXBankA5Control);
 

inline function onXBankA6Control(component, value)
{
XlAble6.set("text",XBankA6.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	slot5.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA6").setControlCallback(onXBankA6Control);

inline function onXBankA7Control(component, value)
{
XlAble7.set("text",XBankA7.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	slot6.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA7").setControlCallback(onXBankA7Control);

inline function onXBankA8Control(component, value)
{
XlAble8.set("text",XBankA8.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	slot7.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA8").setControlCallback(onXBankA8Control);

