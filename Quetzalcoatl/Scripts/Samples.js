//Sample Loading

const var BankA1 = Content.getComponent("BankA1");
const var BankA2 = Content.getComponent("BankA2");
const var BankA3 = Content.getComponent("BankA3");
const var BankA4 = Content.getComponent("BankA4");
const var BankA5 = Content.getComponent("BankA5");
const var BankA6 = Content.getComponent("BankA6");
const var BankA7 = Content.getComponent("BankA7");
const var BankA8 = Content.getComponent("BankA8");
const var BankA11 = Content.getComponent("BankA11");

const var Sample1 = Content.getComponent("Sample1");
const var Sample2 = Content.getComponent("Sample2");
const var Sample3 = Content.getComponent("Sample3");
const var Sample4 = Content.getComponent("Sample4");
const var Sample5 = Content.getComponent("Sample5");
const var Sample6 = Content.getComponent("Sample6");
const var Sample7 = Content.getComponent("Sample7");
const var Sample8 = Content.getComponent("Sample8");

const var SamplerA1 = Synth.getSampler("SamplerA1");
const var SamplerA2 = Synth.getSampler("SamplerA2");
const var SamplerA3 = Synth.getSampler("SamplerA3");
const var SamplerA4 = Synth.getSampler("SamplerA4");
const var SamplerA5 = Synth.getSampler("SamplerA5");
const var SamplerA6 = Synth.getSampler("SamplerA6");
const var SamplerA7 = Synth.getSampler("SamplerA7");
const var SamplerA8 = Synth.getSampler("SamplerA8");

const var Group1 = Synth.getChildSynth("Group1");
const var Group2 = Synth.getChildSynth("Group2");
const var Group3 = Synth.getChildSynth("Group3");
const var Group4 = Synth.getChildSynth("Group4");
const var Group5 = Synth.getChildSynth("Group5");
const var Group6 = Synth.getChildSynth("Group6");
const var Group7 = Synth.getChildSynth("Group7");
const var Group8 = Synth.getChildSynth("Group8");


const samplemaps = Sampler.getSampleMapList();
const tables = Engine.getWavetableList();
const var SampleMode = Content.getComponent("SampleMode1");
const var SampleModes = SampleMode.getValue();

inline function onBankA1Control(component, value)
{

//if (SampleModes == 2)
{
  SamplerA1.loadSampleMap(sampleMaps[value-1]);
  Sample1.set("text",BankA1.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

}

  	 	
};

Content.getComponent("BankA1").setControlCallback(onBankA1Control);

inline function onBankA2Control(component, value)
{

//if (SampleModes == 2)
{
	SamplerA2.loadSampleMap(sampleMaps[value-1]); 
   Sample2.set("text",BankA2.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
}

};

Content.getComponent("BankA2").setControlCallback(onBankA2Control);

inline function onBankA3Control(component, value)
{

//if (SampleModes == 2)
{
   SamplerA3.loadSampleMap(sampleMaps[value-1]);
   Sample3.set("text",BankA3.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
}

};

Content.getComponent("BankA3").setControlCallback(onBankA3Control);

inline function onBankA4Control(component, value)
{

//if (SampleModes == 2)
{
   SamplerA4.loadSampleMap(sampleMaps[value-1]);
   Sample4.set("text",BankA4.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
}
   


};

Content.getComponent("BankA4").setControlCallback(onBankA4Control);

inline function onBankA5Control(component, value)
{

//if (SampleModes == 2)
{
   SamplerA5.loadSampleMap(sampleMaps[value-1]);
	Sample5.set("text",BankA5.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
}	
 	

};

Content.getComponent("BankA5").setControlCallback(onBankA5Control);

inline function onBankA6Control(component, value)
{
	
//if (SampleModes == 2)
{

   SamplerA6.loadSampleMap(sampleMaps[value-1]);
Sample6.set("text",BankA6.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

}


};

Content.getComponent("BankA6").setControlCallback(onBankA6Control);

inline function onBankA7Control(component, value)
{
//if (SampleModes == 2)
{

   SamplerA7.loadSampleMap(sampleMaps[value-1]);
Sample7.set("text",BankA7.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  }

};

Content.getComponent("BankA7").setControlCallback(onBankA7Control);

inline function onBankA8Control(component, value)
{
//	if (SampleModes == 2)
	{

   SamplerA8.loadSampleMap(sampleMaps[value-1]);
 Sample8.set("text",BankA8.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  
  }

};

Content.getComponent("BankA8").setControlCallback(onBankA8Control);


inline function onBankA11Control(component, value)
{
	
	for(s in Banks)
	       s.setValue(value);
	       
	       for(s in Banks)
	              s.changed();
	              

};

Content.getComponent("BankA11").setControlCallback(onBankA11Control);

//wavetables



const var Wt1 = Synth.getChildSynth("Wt1");
const var Wt2 = Synth.getChildSynth("Wt2");
const var Wt3 = Synth.getChildSynth("Wt3");
const var Wt4 = Synth.getChildSynth("Wt4");
const var Wt5 = Synth.getChildSynth("Wt5");
const var Wt6 = Synth.getChildSynth("Wt6");
const var Wt7 = Synth.getChildSynth("Wt7");
const var Wt8 = Synth.getChildSynth("Wt8");

const var SampleWt1 = Content.getComponent("SampleWt1");
const var SampleWt2 = Content.getComponent("SampleWt2");
const var SampleWt3 = Content.getComponent("SampleWt3");
const var SampleWt4 = Content.getComponent("SampleWt4");
const var SampleWt5 = Content.getComponent("SampleWt5");
const var SampleWt6 = Content.getComponent("SampleWt6");
const var SampleWt7 = Content.getComponent("SampleWt7");
const var SampleWt8 = Content.getComponent("SampleWt8");

inline function onWtLoad1Control(component, value)
{ 
  		SampleWt1.set("text",WtLoad1.get("items").split("\n")[value-1]);
  		Wt1.setAttribute(Wt1.LoadedBankIndex, value);		
};

Content.getComponent("WtLoad1").setControlCallback(onWtLoad1Control);


inline function onWtLoad2Control(component, value)
{

	SampleWt2.set("text",WtLoad2.get("items").split("\n")[value-1]);
	Wt2.setAttribute(Wt2.LoadedBankIndex, value);

};

Content.getComponent("WtLoad2").setControlCallback(onWtLoad2Control);

inline function onWtLoad3Control(component, value)
{

	SampleWt3.set("text",WtLoad3.get("items").split("\n")[value-1]);
	Wt3.setAttribute(Wt3.LoadedBankIndex, value);
	
};

Content.getComponent("WtLoad3").setControlCallback(onWtLoad3Control);


inline function onWtLoad4Control(component, value)
{
	

	SampleWt4.set("text",WtLoad4.get("items").split("\n")[value-1]);
	Wt4.setAttribute(Wt4.LoadedBankIndex, value);

	
	};

Content.getComponent("WtLoad4").setControlCallback(onWtLoad4Control);



inline function onWtLoad5Control(component, value)
{
 SampleWt5.set("text",WtLoad5.get("items").split("\n")[value-1]);
 Wt5.setAttribute(Wt5.LoadedBankIndex, value);

};

Content.getComponent("WtLoad5").setControlCallback(onWtLoad5Control);


inline function onWtLoad6Control(component, value)
{
    SampleWt6.set("text",WtLoad6.get("items").split("\n")[value-1]);
    Wt6.setAttribute(Wt6.LoadedBankIndex, value);

};

Content.getComponent("WtLoad6").setControlCallback(onWtLoad6Control);


inline function onWtLoad7Control(component, value)
{

	SampleWt7.set("text",WtLoad7.get("items").split("\n")[value-1]);
	Wt7.setAttribute(Wt7.LoadedBankIndex, value);
};

Content.getComponent("WtLoad7").setControlCallback(onWtLoad7Control);


inline function onWtLoad8Control(component, value)
{
	SampleWt8.set("text",WtLoad8.get("items").split("\n")[value-1]);
	Wt8.setAttribute(Wt8.LoadedBankIndex, value);
};

Content.getComponent("WtLoad8").setControlCallback(onWtLoad8Control);

const var WtLoad1 = Content.getComponent("WtLoad1");
const var WtLoad2 = Content.getComponent("WtLoad2");
const var WtLoad3 = Content.getComponent("WtLoad3");
const var WtLoad4 = Content.getComponent("WtLoad4");
const var WtLoad5 = Content.getComponent("WtLoad5");
const var WtLoad6 = Content.getComponent("WtLoad6");
const var WtLoad7 = Content.getComponent("WtLoad7");
const var WtLoad8 = Content.getComponent("WtLoad8");

const var WtMenus = [Content.getComponent("WtLoad1"),
                     Content.getComponent("WtLoad2"),
                     Content.getComponent("WtLoad3"),
                     Content.getComponent("WtLoad4"),
                     Content.getComponent("WtLoad5"),
                     Content.getComponent("WtLoad6"),
                     Content.getComponent("WtLoad7"),
                     Content.getComponent("WtLoad8")];

inline function onWtAllControl(component, value)
{
	for(s in WtMenus)
       s.setValue(value);
       
    for(s in WtMenus)
       s.changed();                    
};

Content.getComponent("WtAll").setControlCallback(onWtAllControl);
