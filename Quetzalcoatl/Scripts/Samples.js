//Sample Loading

//SamplerA1.setAttribute(6, value ? 2 : 40); 
//Fm2.setAttribute(2, value ? 1 : 40);


const var FmSlotA1 = Synth.getAudioSampleProcessor("Fm1");			
const var FmSlotA2 = Synth.getAudioSampleProcessor("Fm2");		
const var FmSlotA3 = Synth.getAudioSampleProcessor("Fm3");		
const var FmSlotA4 = Synth.getAudioSampleProcessor("Fm4");		
const var FmSlotA5 = Synth.getAudioSampleProcessor("Fm5");		
const var FmSlotA6 = Synth.getAudioSampleProcessor("Fm6");		
const var FmSlotA7 = Synth.getAudioSampleProcessor("Fm7");		
const var FmSlotA8 = Synth.getAudioSampleProcessor("Fm8");		
	
const slotA1 = FmSlotA1.getAudioFile(0);
const slotB1 = FmSlotA1.getAudioFile(1);
const slotA2 = FmSlotA2.getAudioFile(0);
const slotB2 = FmSlotA2.getAudioFile(1);
const slotA3 = FmSlotA3.getAudioFile(0);
const slotB3 = FmSlotA3.getAudioFile(1);
const slotA4 = FmSlotA4.getAudioFile(0);
const slotB4 = FmSlotA4.getAudioFile(1);
const slotA5 = FmSlotA5.getAudioFile(0);
const slotB5 = FmSlotA5.getAudioFile(1);
const slotA6 = FmSlotA6.getAudioFile(0);
const slotB6 = FmSlotA6.getAudioFile(1);
const slotA7 = FmSlotA7.getAudioFile(0);
const slotB7 = FmSlotA7.getAudioFile(1);
const slotA8 = FmSlotA8.getAudioFile(0);
const slotB8 = FmSlotA8.getAudioFile(1);

const var BankA1 = Content.getComponent("BankA1");
const var BankA2 = Content.getComponent("BankA2");
const var BankA3 = Content.getComponent("BankA3");
const var BankA4 = Content.getComponent("BankA4");
const var BankA5 = Content.getComponent("BankA5");
const var BankA6 = Content.getComponent("BankA6");
const var BankA7 = Content.getComponent("BankA7");
const var BankA8 = Content.getComponent("BankA8");
const var BankA9 = Content.getComponent("BankA9");

const var ExpansionSelector = Content.getComponent("ExpansionSelector");

const var expHandler = Engine.createExpansionHandler();

const var expansions = expHandler.getExpansionList();

expHandler.setAllowedExpansionTypes([expHandler.FileBased, 
                                     expHandler.Intermediate, 
                                     expHandler.Encrypted]);

                                     
const var expansionNames = [];

expansionNames.push("FACTORY");

for(e in expHandler.getExpansionList())
    expansionNames.push(e.getProperties().Name);


ExpansionSelector.set("items", expansionNames.join("\n"));




inline function onExpansionSelectorControl(component, value)
{
	local expansionToLoad = component.getItemText();
	

	if(expansionToLoad == expansionNames[0])
        expansionToLoad = "";
    
	expHandler.setCurrentExpansion(expansionToLoad);
};

Content.getComponent("ExpansionSelector").setControlCallback(onExpansionSelectorControl);

var sampleMaps = Sampler.getSampleMapList();
var sampleMapsed = Sampler.getSampleMapList();



inline function newcombobox(newExpansion)
{

       if(isDefined(newExpansion))
        
       
    {
        local cx = expHandler.getCurrentExpansion();
        sampleMaps = cx.getSampleMapList();
        sampleMapsed = cx.getSampleMapList();
        local expansionProps = cx.getProperties();
        local expName = expansionProps.Name;
        
        for (i = 0; i < sampleMapsed.length; i++)
        {
        sampleMapsed[i] = sampleMapsed[i].replace("{EXP::");
        sampleMapsed[i] = sampleMapsed[i].replace("}");
        sampleMapsed[i] = sampleMapsed[i].replace(expName);

        }
       
        BankA1.set("items", "");
        BankA1.set("items", sampleMapsed.join("\n"));
        BankA2.set("items", "");
       	BankA2.set("items", sampleMapsed.join("\n"));
       	BankA3.set("items", "");
       	BankA3.set("items", sampleMapsed.join("\n"));
        BankA4.set("items", "");
      	BankA4.set("items", sampleMapsed.join("\n"));
      	BankA5.set("items", "");
      	BankA5.set("items", sampleMapsed.join("\n"));
      	BankA6.set("items", "");
      	BankA6.set("items", sampleMapsed.join("\n"));
      	BankA7.set("items", "");
      	BankA7.set("items", sampleMapsed.join("\n"));
      	BankA8.set("items", "");
        BankA8.set("items", sampleMapsed.join("\n"));
BankA9.set("items", "");
        BankA9.set("items", sampleMapsed.join("\n"));       
       
       

    }
    
    else
    
    {
        sampleMaps = Sampler.getSampleMapList();
        BankA1.set("items", "");
        BankA1.set("items", sampleMaps.join("\n"));
        BankA2.set("items", "");
       	BankA2.set("items", sampleMaps.join("\n"));
       	BankA3.set("items", "");
       	BankA3.set("items", sampleMaps.join("\n"));
        BankA4.set("items", "");
      	BankA4.set("items", sampleMaps.join("\n"));
      	BankA5.set("items", "");
      	BankA5.set("items", sampleMaps.join("\n"));
      	BankA6.set("items", "");
      	BankA6.set("items", sampleMaps.join("\n"));
      	BankA7.set("items", "");
      	BankA7.set("items", sampleMaps.join("\n"));
      	BankA8.set("items", "");
        BankA8.set("items", sampleMaps.join("\n"));
	BankA9.set("items", "");
        BankA9.set("items", sampleMaps.join("\n"));
        

    }
    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);

const var Sample1 = Content.getComponent("Sample1");
const var Sample2 = Content.getComponent("Sample2");
const var Sample3 = Content.getComponent("Sample3");
const var Sample4 = Content.getComponent("Sample4");
const var Sample5 = Content.getComponent("Sample5");
const var Sample6 = Content.getComponent("Sample6");
const var Sample7 = Content.getComponent("Sample7");
const var Sample8 = Content.getComponent("Sample8");
const var Sample9 = Content.getComponent("Sample9");

const var SamplerA1 = Synth.getSampler("SamplerA1");
const var SamplerA2 = Synth.getSampler("SamplerA2");
const var SamplerA3 = Synth.getSampler("SamplerA3");
const var SamplerA4 = Synth.getSampler("SamplerA4");
const var SamplerA5 = Synth.getSampler("SamplerA5");
const var SamplerA6 = Synth.getSampler("SamplerA6");
const var SamplerA7 = Synth.getSampler("SamplerA7");
const var SamplerA8 = Synth.getSampler
("SamplerA8");

const samplemaps = Sampler.getSampleMapList();


inline function onBankA1Control(component, value)
{

  SamplerA1.loadSampleMap(sampleMaps[value-1]);
   slotA1.loadFile("{XYZ::SampleMap}" + component.getItemText());
  
  	Sample1.set("text",BankA1.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  	
};

Content.getComponent("BankA1").setControlCallback(onBankA1Control);

inline function onBankA2Control(component, value)
{

	SamplerA2.loadSampleMap(sampleMaps[value-1]); slotA2.loadFile("{XYZ::SampleMap}" + component.getItemText());
   Sample2.set("text",BankA2.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  

};

Content.getComponent("BankA2").setControlCallback(onBankA2Control);

inline function onBankA3Control(component, value)
{

   SamplerA3.loadSampleMap(sampleMaps[value-1]);
   slotA3.loadFile("{XYZ::SampleMap}" + component.getItemText());
  Sample3.set("text",BankA3.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

};

Content.getComponent("BankA3").setControlCallback(onBankA3Control);

inline function onBankA4Control(component, value)
{

   SamplerA4.loadSampleMap(sampleMaps[value-1]);
 slotA4.loadFile("{XYZ::SampleMap}" + component.getItemText());
    
    Sample4.set("text",BankA4.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  

};

Content.getComponent("BankA4").setControlCallback(onBankA4Control);

inline function onBankA5Control(component, value)
{

   SamplerA5.loadSampleMap(sampleMaps[value-1]);
   slotA5.loadFile("{XYZ::SampleMap}" + component.getItemText());
 
  
	Sample5.set("text",BankA5.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
};

Content.getComponent("BankA5").setControlCallback(onBankA5Control);

inline function onBankA6Control(component, value)
{

   SamplerA6.loadSampleMap(sampleMaps[value-1]);
 slotA6.loadFile("{XYZ::SampleMap}" + component.getItemText());
 
	Sample6.set("text",BankA6.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
};

Content.getComponent("BankA6").setControlCallback(onBankA6Control);

inline function onBankA7Control(component, value)
{

   SamplerA7.loadSampleMap(sampleMaps[value-1]);
   slotA7.loadFile("{XYZ::SampleMap}" + component.getItemText());
  
    Sample7.set("text",BankA7.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  

};

Content.getComponent("BankA7").setControlCallback(onBankA7Control);

inline function onBankA8Control(component, value)
{

   SamplerA8.loadSampleMap(sampleMaps[value-1]);
   slotA8.loadFile("{XYZ::SampleMap}" + component.getItemText());
 
  Sample8.set("text",BankA8.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

};

Content.getComponent("BankA8").setControlCallback(onBankA8Control);



inline function onBankA9Control(component, value)
{

   slotB1.loadFile("{XYZ::SampleMap}" + component.getItemText());
   slotB2.loadFile("{XYZ::SampleMap}" + component.getItemText());
   slotB3.loadFile("{XYZ::SampleMap}" + component.getItemText());
   slotB4.loadFile("{XYZ::SampleMap}" + component.getItemText());
   slotB5.loadFile("{XYZ::SampleMap}" + component.getItemText());
   slotB6.loadFile("{XYZ::SampleMap}" + component.getItemText());
   slotB7.loadFile("{XYZ::SampleMap}" + component.getItemText());
   slotB8.loadFile("{XYZ::SampleMap}" + component.getItemText());
   
  Sample9.set("text",BankA9.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

};

Content.getComponent("BankA9").setControlCallback(onBankA9Control);



const var LoopA1 = Synth.getAudioSampleProcessor("LoopA1");
const var LoopA2 = Synth.getAudioSampleProcessor("LoopA2");
const var LoopA3 = Synth.getAudioSampleProcessor("LoopA3");
const var LoopA4 = Synth.getAudioSampleProcessor("LoopA4");
const var LoopA5 = Synth.getAudioSampleProcessor("LoopA5");
const var LoopA6 = Synth.getAudioSampleProcessor("LoopA6");
const var LoopA7 = Synth.getAudioSampleProcessor("LoopA7");
const var LoopA8 = Synth.getAudioSampleProcessor("LoopA8");




inline function onLpLoad1Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA1.setFile((f.toString(File.FullPath)));
				Sample1.set("text", f.toString(f.NoExtension));	
							
	});	
	

	

}
};

Content.getComponent("LpLoad1").setControlCallback(onLpLoad1Control);

inline function onLpLoad2Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA2.setFile( (f.toString(File.FullPath)));
				Sample2.set("text", f.toString(f.NoExtension));	
	});	
	

}
};

Content.getComponent("LpLoad2").setControlCallback(onLpLoad2Control);

inline function onLpLoad3Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA3.setFile( (f.toString(File.FullPath)));
				Sample3.set("text", f.toString(f.NoExtension));	
	});	

}
};

Content.getComponent("LpLoad3").setControlCallback(onLpLoad3Control);

inline function onLpLoad4Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA4.setFile( (f.toString(File.FullPath)));
				Sample4.set("text", f.toString(f.NoExtension));	
	});	

}
};

Content.getComponent("LpLoad4").setControlCallback(onLpLoad4Control);

inline function onLpLoad5Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA5.setFile( (f.toString(File.FullPath)));
				Sample5.set("text", f.toString(f.NoExtension));	
	});	
	

}
};

Content.getComponent("LpLoad5").setControlCallback(onLpLoad5Control);

inline function onLpLoad6Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA6.setFile( (f.toString(File.FullPath)));
				Sample6.set("text", f.toString(f.NoExtension));	
	});	

}
};

Content.getComponent("LpLoad6").setControlCallback(onLpLoad6Control);

inline function onLpLoad7Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA7.setFile( (f.toString(File.FullPath)));
				Sample7.set("text", f.toString(f.NoExtension));	
	});	

}
};

Content.getComponent("LpLoad7").setControlCallback(onLpLoad7Control);

inline function onLpLoad8Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA8.setFile( (f.toString(File.FullPath)));
				Sample8.set("text", f.toString(f.NoExtension));	
	});	

}
};

Content.getComponent("LpLoad8").setControlCallback(onLpLoad8Control);


const var Sampler1 = Synth.getChildSynth("SamplerA1");
const var Sampler2 = Synth.getChildSynth("SamplerA2");
const var Sampler3 = Synth.getChildSynth("SamplerA3");
const var Sampler4 = Synth.getChildSynth("SamplerA4");
const var Sampler5 = Synth.getChildSynth("SamplerA5");
const var Sampler6 = Synth.getChildSynth("SamplerA6");
const var Sampler7 = Synth.getChildSynth("SamplerA7");
const var Sampler8 = Synth.getChildSynth("SamplerA8");


const var Groups = [Synth.getChildSynth("Group1"), Synth.getChildSynth("Group2"), Synth.getChildSynth("Group3"), Synth.getChildSynth("Group4"),Synth.getChildSynth("Group5"), Synth.getChildSynth("Group6"),  Synth.getChildSynth("Group7"), Synth.getChildSynth("Group8")];

const var Samplers = [Synth.getChildSynth("SamplerA1"),
					Synth.getChildSynth("SamplerA2"),
					Synth.getChildSynth("SamplerA3"),
					Synth.getChildSynth("SamplerA4"),
					Synth.getChildSynth("SamplerA5"),
					Synth.getChildSynth("SamplerA6"),
					Synth.getChildSynth("SamplerA7"),
					Synth.getChildSynth("SamplerA8")];
					

const var Wts = [Synth.getChildSynth("WtA1"),
				Synth.getChildSynth("WtA2"),
				Synth.getChildSynth("WtA3"),
				Synth.getChildSynth("WtA4"),
				Synth.getChildSynth("WtA5"),
				Synth.getChildSynth("WtA6"),
				Synth.getChildSynth("WtA7"),
				Synth.getChildSynth("WtA8")];
				
const var loops = [Synth.getChildSynth("LoopA2"),
				Synth.getChildSynth("LoopA2"),
				Synth.getChildSynth("LoopA3"),
				Synth.getChildSynth("LoopA4"),
				Synth.getChildSynth("LoopA5"),
				Synth.getChildSynth("LoopA6"),
				Synth.getChildSynth("LoopA7"),
				Synth.getChildSynth("LoopA8")];				


const var Group1 = Synth.getChildSynth("Group1");
const var Group2 = Synth.getChildSynth("Group2");
const var Group3 = Synth.getChildSynth("Group3");
const var Group4 = Synth.getChildSynth("Group4");
const var Group5 = Synth.getChildSynth("Group5");
const var Group6 = Synth.getChildSynth("Group6");
const var Group7 = Synth.getChildSynth("Group7");
const var Group8 = Synth.getChildSynth("Group8");
					
const var WtA1 = Synth.getChildSynth("WtA1");
const var WtA2 = Synth.getChildSynth("WtA2");
const var WtA3 = Synth.getChildSynth("WtA3");
const var WtA4 = Synth.getChildSynth("WtA4");
const var WtA5 = Synth.getChildSynth("WtA5");
const var WtA6 = Synth.getChildSynth("WtA6");
const var WtA7 = Synth.getChildSynth("WtA7");
const var WtA8 = Synth.getChildSynth("WtA8");

const var loop1 = Synth.getChildSynth("LoopA1");
const var loop2 = Synth.getChildSynth("LoopA2");
const var loop3 = Synth.getChildSynth("LoopA3");
const var loop4 = Synth.getChildSynth("LoopA4");
const var loop5 = Synth.getChildSynth("LoopA5");
const var loop6 = Synth.getChildSynth("LoopA6");
const var loop7 = Synth.getChildSynth("LoopA7");
const var loop8 = Synth.getChildSynth("LoopA8");	
	

const var SampleWave1 = Content.getComponent("SamplerWave1");
const var SampleWave2 = Content.getComponent("SamplerWave2");
const var SampleWave3 = Content.getComponent("SamplerWave3");
const var SampleWave4 = Content.getComponent("SamplerWave4");
const var SampleWave5 = Content.getComponent("SamplerWave5");
const var SampleWave6 = Content.getComponent("SamplerWave6");
const var SampleWave7 = Content.getComponent("SamplerWave7");
const var SampleWave8 = Content.getComponent("SamplerWave8");
const var SampleWave9 = Content.getComponent("SamplerWave9");

const var Waves1 = Content.getComponent("Waves1");
const var Waves2 = Content.getComponent("Waves2");
const var Waves3 = Content.getComponent("Waves3");
const var Waves4 = Content.getComponent("Waves4");
const var Waves5 = Content.getComponent("Waves5");
const var Waves6 = Content.getComponent("Waves6");
const var Waves7 = Content.getComponent("Waves7");
const var Waves8 = Content.getComponent("Waves8");
const var Waves9 = Content.getComponent("Waves9"); 
                     
const var Wt1 = Content.getComponent("Wt1");
const var Wt2 = Content.getComponent("Wt2");
const var Wt3 = Content.getComponent("Wt3");
const var Wt4 = Content.getComponent("Wt4");
const var Wt5 = Content.getComponent("Wt5");
const var Wt6 = Content.getComponent("Wt6");
const var Wt7 = Content.getComponent("Wt7");
const var Wt8 = Content.getComponent("Wt8");
const var Wt9 = Content.getComponent("Wt9");

const var TableView1 = Content.getComponent("TableView1");
const var TableView2 = Content.getComponent("TableView2");
const var TableView3 = Content.getComponent("TableView3");
const var TableView4 = Content.getComponent("TableView4");
const var TableView5 = Content.getComponent("TableView5");
const var TableView6 = Content.getComponent("TableView6");
const var TableView7 = Content.getComponent("TableView7");
const var TableView8 = Content.getComponent("TableView8");
const var TableView9 = Content.getComponent("TableView9");
                     
                     
const var UserWave1 = Content.getComponent("UserWave1");
const var UserWave2 = Content.getComponent("UserWave2");
const var UserWave3 = Content.getComponent("UserWave3");
const var UserWave4 = Content.getComponent("UserWave4");
const var UserWave5 = Content.getComponent("UserWave5");
const var UserWave6 = Content.getComponent("UserWave6");
const var UserWave7 = Content.getComponent("UserWave7");
const var UserWave8 = Content.getComponent("UserWave8");
const var UserWave9 = Content.getComponent("UserWave9");

const var LpControls1 = Content.getComponent("LpControls1");
const var LpControls2 = Content.getComponent("LpControls2");
const var LpControls3 = Content.getComponent("LpControls3");
const var LpControls4 = Content.getComponent("LpControls4");
const var LpControls5 = Content.getComponent("LpControls5");
const var LpControls6 = Content.getComponent("LpControls6");
const var LpControls7 = Content.getComponent("LpControls7");
const var LpControls8 = Content.getComponent("LpControls8");
const var LpControls9 = Content.getComponent("LpControls9");


const var Lwav1 = Synth.getAudioSampleProcessor("LoopA1");
const var Lwav2 = Synth.getAudioSampleProcessor("LoopA2");
const var Lwav3 = Synth.getAudioSampleProcessor("LoopA3");
const var Lwav4 = Synth.getAudioSampleProcessor("LoopA4");
const var Lwav5 = Synth.getAudioSampleProcessor("LoopA5");
const var Lwav6 = Synth.getAudioSampleProcessor("LoopA6");
const var Lwav7 = Synth.getAudioSampleProcessor("LoopA7");
const var Lwav8 = Synth.getAudioSampleProcessor("LoopA8");

const var Fm1 = Synth.getChildSynth("Fm1");
const var Fm2 = Synth.getChildSynth("Fm2");
const var Fm3 = Synth.getChildSynth("Fm3");
const var Fm4 = Synth.getChildSynth("Fm4");
const var Fm5 = Synth.getChildSynth("Fm5");
const var Fm6 = Synth.getChildSynth("Fm6");
const var Fm7 = Synth.getChildSynth("Fm7");
const var Fm8 = Synth.getChildSynth("Fm8");

const var WtSliders = Content.getComponent("WtSliders");

const var FmSlider = Content.getComponent("FmSlider");

const var LpSwitches1 = Content.getComponent("LpSwitches1");

const var FmWaves1 = Content.getComponent("FmWaves1");
const var FmWaves2 = Content.getComponent("FmWaves2");
const var FmWaves3 = Content.getComponent("FmWaves3");
const var FmWaves4 = Content.getComponent("FmWaves4");
const var FmWaves5 = Content.getComponent("FmWaves5");
const var FmWaves6 = Content.getComponent("FmWaves6");
const var FmWaves7 = Content.getComponent("FmWaves7");
const var FmWaves8 = Content.getComponent("FmWaves8");

const var ScriptImage2 = Content.getComponent("ScriptImage2");



inline function onSampleMode1Control(component, value)
{
if(value == 1)
	{
	
//sampler

	Sampler1.setBypassed(0);
	Waves1.showControl(1);
	
//Loop	
	
	loop1.setBypassed(1);
	LpSwitches1.showControl(0);
	UserWave1.showControl(0);
	LpControls1.showControl(0);
	
//WT	
	
	WtA1.setBypassed(1);
	Wt1.showControl(0);
	WtSliders.showControl(0);
	TableView1.showControl(0);
	ScriptImage2.showControl(1);

//FM
	
	Fm1.setBypassed(1);
	SampleWave1.showControl(1);	
	FmSlider.showControl(0);
	FmWaves1.showControl(0);
	
	
	
	
	Sample1.set("text",BankA1.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	
	}
if(value == 2)
	{
	
	//sampler
	
		Sampler1.setBypassed(1);
		Waves1.showControl(0);
		
	//Loop	
		
		loop1.setBypassed(0);
		LpSwitches1.showControl(1);
		UserWave1.showControl(1);
		LpControls1.showControl(1);
		
	//WT	
		
		WtA1.setBypassed(1);
		Wt1.showControl(0);
		WtSliders.showControl(0);
		TableView1.showControl(0);
	
	//FM
		
		Fm1.setBypassed(1);
		SampleWave1.showControl(1);	
		FmSlider.showControl(0);
		FmWaves1.showControl(0);
		ScriptImage2.showControl(1);
	
	Sample1.set("text",Lwav1.getFilename().replace(".wav").replace(".aif").replace("{PROJECT_FOLDER}").replace("Single Cycle").replace("Roland Jupiter 4").replace("Loops").replace("DronesChords"));
	
	}
	
	if(value == 3)
		{
		//sampler
	
		Sampler1.setBypassed(1);
		Waves1.showControl(0);
		
	//Loop	
		
		loop1.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave1.showControl(0);
		LpControls1.showControl(0);
		
	//WT	
		
		WtA1.setBypassed(0);
		Wt1.showControl(1);
		WtSliders.showControl(1);
		TableView1.showControl(1);
	
	//FM
		
		Fm1.setBypassed(1);
		SampleWave1.showControl(1);	
		FmSlider.showControl(0);
		FmWaves1.showControl(0);
		
		ScriptImage2.showControl(0);
		
		}		
		
		
		if(value == 4)
			{
			//sampler
	
		Sampler1.setBypassed(1);
		Waves1.showControl(0);
		
	//Loop	
		
		loop1.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave1.showControl(0);
		LpControls1.showControl(0);
		
	//WT	
		
		WtA1.setBypassed(1);
		Wt1.showControl(0);
		WtSliders.showControl(0);
		TableView1.showControl(0);
	
	//FM
		
		Fm1.setBypassed(0);
		SampleWave1.showControl(1);	
		FmSlider.showControl(1);
		FmWaves1.showControl(1);
		ScriptImage2.showControl(0);
			
			}		

};

Content.getComponent("SampleMode1").setControlCallback(onSampleMode1Control);

inline function onSampleMode2Control(component, value)
{
if(value == 1)
	{
	
//sampler

	Sampler2.setBypassed(0);
	Waves2.showControl(1);
	
//Loop	
	
	loop2.setBypassed(1);
	LpSwitches1.showControl(0);
	UserWave2.showControl(0);
	LpControls2.showControl(0);
	
//WT	
	
	WtA2.setBypassed(1);
	Wt2.showControl(0);
	WtSliders.showControl(0);
	TableView1.showControl(0);

//FM
	
	Fm2.setBypassed(1);
	SampleWave2.showControl(1);	
	FmSlider.showControl(0);
	FmWaves2.showControl(0);
	
	ScriptImage2.showControl(1);
	
	
	
	Sample2.set("text",BankA2.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	
	}
if(value == 2)
	{
	
	//sampler
	
		Sampler2.setBypassed(1);
		Waves2.showControl(0);
		
	//Loop	
		
		loop2.setBypassed(0);
		LpSwitches1.showControl(1);
		UserWave2.showControl(1);
		LpControls2.showControl(1);
		
	//WT	
		
		WtA2.setBypassed(1);
		Wt2.showControl(0);
		WtSliders.showControl(0);
		TableView1.showControl(0);
	
	//FM
		
		Fm2.setBypassed(1);
		SampleWave2.showControl(1);	
		FmSlider.showControl(0);
		FmWaves2.showControl(0);
		ScriptImage2.showControl(1);
	
	Sample2.set("text",Lwav2.getFilename().replace(".wav").replace(".aif").replace("{PROJECT_FOLDER}").replace("Single Cycle").replace("Roland Jupiter 4").replace("Loops").replace("DronesChords"));
	
	}
	
	if(value == 3)
		{
		//sampler
	
		Sampler2.setBypassed(1);
		Waves2.showControl(0);
		
	//Loop	
		
		loop2.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave2.showControl(0);
		LpControls2.showControl(0);
		
	//WT	
		
		WtA2.setBypassed(0);
		Wt2.showControl(1);
		WtSliders.showControl(1);
		TableView2.showControl(1);
	
	//FM
		
		Fm2.setBypassed(1);
		SampleWave2.showControl(1);	
		FmSlider.showControl(0);
		FmWaves2.showControl(0);
		
		ScriptImage2.showControl(0);
		
		}		
		
		
		if(value == 4)
			{
			//sampler
	
		Sampler2.setBypassed(1);
		Waves2.showControl(0);
		
	//Loop	
		
		loop2.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave2.showControl(0);
		LpControls2.showControl(0);
		
	//WT	
		
		WtA2.setBypassed(1);
		Wt2.showControl(0);
		WtSliders.showControl(0);
		TableView2.showControl(0);
	
	//FM
		
		Fm2.setBypassed(0);
		SampleWave2.showControl(1);	
		FmSlider.showControl(1);
		FmWaves2.showControl(1);
		
		ScriptImage2.showControl(0);
			
			}		

};

Content.getComponent("SampleMode2").setControlCallback(onSampleMode2Control);

inline function onSampleMode3Control(component, value)
{
if(value == 1)
	{
	
//sampler

	Sampler3.setBypassed(0);
	Waves3.showControl(1);
	
//Loop	
	
	loop3.setBypassed(1);
	LpSwitches1.showControl(0);
	UserWave3.showControl(0);
	LpControls3.showControl(0);
	
//WT	
	
	WtA3.setBypassed(1);
	Wt3.showControl(0);
	WtSliders.showControl(0);
	TableView1.showControl(0);

//FM
	
	Fm3.setBypassed(1);
	SampleWave3.showControl(1);	
	FmSlider.showControl(0);
	FmWaves3.showControl(0);
	
	ScriptImage2.showControl(1);
	
	
	
	Sample3.set("text",BankA3.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	
	}
if(value == 2)
	{
	
	//sampler
	
		Sampler3.setBypassed(1);
		Waves3.showControl(0);
		
	//Loop	
		
		loop3.setBypassed(0);
		LpSwitches1.showControl(1);
		UserWave3.showControl(1);
		LpControls3.showControl(1);
		
	//WT	
		
		WtA3.setBypassed(1);
		Wt3.showControl(0);
		WtSliders.showControl(0);
		TableView1.showControl(0);
	
	//FM
		
		Fm3.setBypassed(1);
		SampleWave3.showControl(1);	
		FmSlider.showControl(0);
		FmWaves3.showControl(0);
		
		ScriptImage2.showControl(1);
	
	Sample3.set("text",Lwav3.getFilename().replace(".wav").replace(".aif").replace("{PROJECT_FOLDER}").replace("Single Cycle").replace("Roland Jupiter 4").replace("Loops").replace("DronesChords"));
	
	}
	
	if(value == 3)
		{
		//sampler
	
		Sampler3.setBypassed(1);
		Waves3.showControl(0);
		
	//Loop	
		
		loop3.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave3.showControl(0);
		LpControls3.showControl(0);
		
	//WT	
		
		WtA3.setBypassed(0);
		Wt3.showControl(1);
		WtSliders.showControl(1);
		TableView3.showControl(1);
	
	//FM
		
		Fm3.setBypassed(1);
		SampleWave3.showControl(1);	
		FmSlider.showControl(0);
		FmWaves3.showControl(0);
		ScriptImage2.showControl(0);
		
		}		
		
		
		if(value == 4)
			{
			//sampler
	
		Sampler3.setBypassed(1);
		Waves3.showControl(0);
		
	//Loop	
		
		loop3.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave3.showControl(0);
		LpControls3.showControl(0);
		
	//WT	
		
		WtA3.setBypassed(1);
		Wt3.showControl(0);
		WtSliders.showControl(0);
		TableView3.showControl(0);
	
	//FM
		
		Fm3.setBypassed(0);
		SampleWave3.showControl(1);	
		FmSlider.showControl(1);
		FmWaves3.showControl(1);
		ScriptImage2.showControl(0);
			
			}		

};

Content.getComponent("SampleMode3").setControlCallback(onSampleMode3Control);

inline function onSampleMode4Control(component, value)
{
if(value == 1)
	{
	
//sampler

	Sampler4.setBypassed(0);
	Waves4.showControl(1);
	
//Loop	
	
	loop4.setBypassed(1);
	LpSwitches1.showControl(0);
	UserWave4.showControl(0);
	LpControls4.showControl(0);
	
//WT	
	
	WtA4.setBypassed(1);
	Wt4.showControl(0);
	WtSliders.showControl(0);
	TableView1.showControl(0);

//FM
	
	Fm4.setBypassed(1);
	SampleWave4.showControl(1);	
	FmSlider.showControl(0);
	FmWaves4.showControl(0);
	ScriptImage2.showControl(1);
	
	
	
	
	Sample4.set("text",BankA4.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	
	}
if(value == 2)
	{
	
	//sampler
	
		Sampler4.setBypassed(1);
		Waves4.showControl(0);
		
	//Loop	
		
		loop4.setBypassed(0);
		LpSwitches1.showControl(1);
		UserWave4.showControl(1);
		LpControls4.showControl(1);
		
	//WT	
		
		WtA4.setBypassed(1);
		Wt4.showControl(0);
		WtSliders.showControl(0);
		TableView1.showControl(0);
	
	//FM
		
		Fm4.setBypassed(1);
		SampleWave4.showControl(1);	
		FmSlider.showControl(0);
		FmWaves4.showControl(0);
		ScriptImage2.showControl(1);
	
	Sample4.set("text",Lwav4.getFilename().replace(".wav").replace(".aif").replace("{PROJECT_FOLDER}").replace("Single Cycle").replace("Roland Jupiter 4").replace("Loops").replace("DronesChords"));
	
	}
	
	if(value == 3)
		{
		//sampler
	
		Sampler4.setBypassed(1);
		Waves4.showControl(0);
		
	//Loop	
		
		loop4.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave4.showControl(0);
		LpControls4.showControl(0);
		
	//WT	
		
		WtA4.setBypassed(0);
		Wt4.showControl(1);
		WtSliders.showControl(1);
		TableView4.showControl(1);
	
	//FM
		
		Fm4.setBypassed(1);
		SampleWave4.showControl(1);	
		FmSlider.showControl(0);
		FmWaves4.showControl(0);
		ScriptImage2.showControl(0);
		
		}		
		
		
		if(value == 4)
			{
			//sampler
	
		Sampler4.setBypassed(1);
		Waves4.showControl(0);
		
	//Loop	
		
		loop4.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave4.showControl(0);
		LpControls4.showControl(0);
		
	//WT	
		
		WtA4.setBypassed(1);
		Wt4.showControl(0);
		WtSliders.showControl(0);
		TableView4.showControl(0);
	
	//FM
		
		Fm4.setBypassed(0);
		SampleWave4.showControl(1);	
		FmSlider.showControl(1);
		FmWaves4.showControl(1);
		ScriptImage2.showControl(0);
			
			}		

};

Content.getComponent("SampleMode4").setControlCallback(onSampleMode4Control);


inline function onSampleMode5Control(component, value)
{
if(value == 1)
	{
	
//sampler

	Sampler5.setBypassed(0);
	Waves5.showControl(1);
	
//Loop	
	
	loop5.setBypassed(1);
	LpSwitches1.showControl(0);
	UserWave5.showControl(0);
	LpControls5.showControl(0);
	
//WT	
	
	WtA5.setBypassed(1);
	Wt5.showControl(0);
	WtSliders.showControl(0);
	TableView1.showControl(0);

//FM
	
	Fm5.setBypassed(1);
	SampleWave5.showControl(1);	
	FmSlider.showControl(0);
	FmWaves5.showControl(0);
	ScriptImage2.showControl(1);
	
	
	
	
	Sample5.set("text",BankA5.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	
	}
if(value == 2)
	{
	
	//sampler
	
		Sampler5.setBypassed(1);
		Waves5.showControl(0);
		
	//Loop	
		
		loop5.setBypassed(0);
		LpSwitches1.showControl(1);
		UserWave5.showControl(1);
		LpControls5.showControl(1);
		
	//WT	
		
		WtA5.setBypassed(1);
		Wt5.showControl(0);
		WtSliders.showControl(0);
		TableView1.showControl(0);
	
	//FM
		
		Fm5.setBypassed(1);
		SampleWave5.showControl(1);	
		FmSlider.showControl(0);
		FmWaves5.showControl(0);
		ScriptImage2.showControl(1);
	
	Sample5.set("text",Lwav5.getFilename().replace(".wav").replace(".aif").replace("{PROJECT_FOLDER}").replace("Single Cycle").replace("Roland Jupiter 4").replace("Loops").replace("DronesChords"));
	
	}
	
	if(value == 3)
		{
		//sampler
	
		Sampler5.setBypassed(1);
		Waves5.showControl(0);
		
	//Loop	
		
		loop5.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave5.showControl(0);
		LpControls5.showControl(0);
		
	//WT	
		
		WtA5.setBypassed(0);
		Wt5.showControl(1);
		WtSliders.showControl(1);
		TableView5.showControl(1);
	
	//FM
		
		Fm5.setBypassed(1);
		SampleWave5.showControl(1);	
		FmSlider.showControl(0);
		FmWaves5.showControl(0);
		
		ScriptImage2.showControl(0);
		
		}		
		
		
		if(value == 4)
			{
			//sampler
	
		Sampler5.setBypassed(1);
		Waves5.showControl(0);
		
	//Loop	
		
		loop5.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave5.showControl(0);
		LpControls5.showControl(0);
		
	//WT	
		
		WtA5.setBypassed(1);
		Wt5.showControl(0);
		WtSliders.showControl(0);
		TableView5.showControl(0);
	
	//FM
		
		Fm5.setBypassed(0);
		SampleWave5.showControl(1);	
		FmSlider.showControl(1);
		FmWaves5.showControl(1);
		
		ScriptImage2.showControl(0);
			
			}	
};

Content.getComponent("SampleMode5").setControlCallback(onSampleMode5Control);



inline function onSampleMode6Control(component, value)
{
if(value == 1)
	{
	
//sampler

	Sampler6.setBypassed(0);
	Waves6.showControl(1);
	
//Loop	
	
	loop6.setBypassed(1);
	LpSwitches1.showControl(0);
	UserWave6.showControl(0);
	LpControls6.showControl(0);
	
//WT	
	
	WtA6.setBypassed(1);
	Wt6.showControl(0);
	WtSliders.showControl(0);
	TableView1.showControl(0);

//FM
	
	Fm6.setBypassed(1);
	SampleWave6.showControl(1);	
	FmSlider.showControl(0);
	FmWaves6.showControl(0);
	ScriptImage2.showControl(1);
	
	
	
	
	Sample6.set("text",BankA6.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	
	}
if(value == 2)
	{
	
	//sampler
	
		Sampler6.setBypassed(1);
		Waves6.showControl(0);
		
	//Loop	
		
		loop6.setBypassed(0);
		LpSwitches1.showControl(1);
		UserWave6.showControl(1);
		LpControls6.showControl(1);
		
	//WT	
		
		WtA6.setBypassed(1);
		Wt6.showControl(0);
		WtSliders.showControl(0);
		TableView1.showControl(0);
	
	//FM
		
		Fm6.setBypassed(1);
		SampleWave6.showControl(1);	
		FmSlider.showControl(0);
		FmWaves6.showControl(0);
		ScriptImage2.showControl(1);
	
	Sample6.set("text",Lwav6.getFilename().replace(".wav").replace(".aif").replace("{PROJECT_FOLDER}").replace("Single Cycle").replace("Roland Jupiter 4").replace("Loops").replace("DronesChords"));
	
	}
	
	if(value == 3)
		{
		//sampler
	
		Sampler6.setBypassed(1);
		Waves6.showControl(0);
		
	//Loop	
		
		loop6.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave6.showControl(0);
		LpControls6.showControl(0);
		
	//WT	
		
		WtA6.setBypassed(0);
		Wt6.showControl(1);
		WtSliders.showControl(1);
		TableView6.showControl(1);
	
	//FM
		
		Fm6.setBypassed(1);
		SampleWave6.showControl(1);	
		FmSlider.showControl(0);
		FmWaves6.showControl(0);
		ScriptImage2.showControl(0);
		
		}		
		
		
		if(value == 4)
			{
			//sampler
	
		Sampler6.setBypassed(1);
		Waves6.showControl(0);
		
	//Loop	
		
		loop6.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave6.showControl(0);
		LpControls6.showControl(0);
		
	//WT	
		
		WtA6.setBypassed(1);
		Wt6.showControl(0);
		WtSliders.showControl(0);
		TableView6.showControl(0);
	
	//FM
		
		Fm6.setBypassed(0);
		SampleWave6.showControl(1);	
		FmSlider.showControl(1);
		FmWaves6.showControl(1);
		ScriptImage2.showControl(0);
			
			}		

};

Content.getComponent("SampleMode6").setControlCallback(onSampleMode6Control);




inline function onSampleMode7Control(component, value)

{
if(value == 1)
	{
	
//sampler

	Sampler7.setBypassed(0);
	Waves7.showControl(1);
	
//Loop	
	
	loop7.setBypassed(1);
	LpSwitches1.showControl(0);
	UserWave7.showControl(0);
	LpControls7.showControl(0);
	
//WT	
	
	WtA7.setBypassed(1);
	Wt7.showControl(0);
	WtSliders.showControl(0);
	TableView1.showControl(0);

//FM
	
	Fm7.setBypassed(1);
	SampleWave7.showControl(1);	
	FmSlider.showControl(0);
	FmWaves7.showControl(0);
	ScriptImage2.showControl(1);
	
	
	
	
	Sample7.set("text",BankA7.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	
	}
if(value == 2)
	{
	
	//sampler
	
		Sampler7.setBypassed(1);
		Waves7.showControl(0);
		
	//Loop	
		
		loop7.setBypassed(0);
		LpSwitches1.showControl(1);
		UserWave7.showControl(1);
		LpControls7.showControl(1);
		
	//WT	
		
		WtA7.setBypassed(1);
		Wt7.showControl(0);
		WtSliders.showControl(0);
		TableView1.showControl(0);
	
	//FM
		
		Fm7.setBypassed(1);
		SampleWave7.showControl(1);	
		FmSlider.showControl(0);
		FmWaves7.showControl(0);
		ScriptImage2.showControl(1);
	
	Sample7.set("text",Lwav7.getFilename().replace(".wav").replace(".aif").replace("{PROJECT_FOLDER}").replace("Single Cycle").replace("Roland Jupiter 4").replace("Loops").replace("DronesChords"));
	
	}
	
	if(value == 3)
		{
		//sampler
	
		Sampler7.setBypassed(1);
		Waves7.showControl(0);
		
	//Loop	
		
		loop7.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave7.showControl(0);
		LpControls7.showControl(0);
		
	//WT	
		
		WtA7.setBypassed(0);
		Wt7.showControl(1);
		WtSliders.showControl(1);
		TableView7.showControl(1);
	
	//FM
		
		Fm7.setBypassed(1);
		SampleWave7.showControl(1);	
		FmSlider.showControl(0);
		FmWaves7.showControl(0);
		ScriptImage2.showControl(0);
		
		}		
		
		
		if(value == 4)
			{
			//sampler
	
		Sampler7.setBypassed(1);
		Waves7.showControl(0);
		
	//Loop	
		
		loop7.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave7.showControl(0);
		LpControls7.showControl(0);
		
	//WT	
		
		WtA7.setBypassed(1);
		Wt7.showControl(0);
		WtSliders.showControl(0);
		TableView7.showControl(0);
	
	//FM
		
		Fm7.setBypassed(0);
		SampleWave7.showControl(1);	
		FmSlider.showControl(1);
		FmWaves7.showControl(1);
		ScriptImage2.showControl(0);
			
			}		

};

Content.getComponent("SampleMode7").setControlCallback(onSampleMode7Control);



inline function onSampleMode8Control(component, value)
{
if(value == 1)
	{
	
//sampler

	Sampler8.setBypassed(0);
	Waves8.showControl(1);
	
//Loop	
	
	loop8.setBypassed(1);
	LpSwitches1.showControl(0);
	UserWave8.showControl(0);
	LpControls8.showControl(0);
	
//WT	
	
	WtA8.setBypassed(1);
	Wt8.showControl(0);
	WtSliders.showControl(0);
	TableView1.showControl(0);

//FM
	
	Fm8.setBypassed(1);
	SampleWave8.showControl(1);	
	FmSlider.showControl(0);
	FmWaves8.showControl(0);
	ScriptImage2.showControl(1);
	
	Sample8.set("text",BankA8.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
	
	}
if(value == 2)
	{
	
	//sampler
	
		Sampler8.setBypassed(1);
		Waves8.showControl(0);
		
	//Loop	
		
		loop8.setBypassed(0);
		LpSwitches1.showControl(1);
		UserWave8.showControl(1);
		LpControls8.showControl(1);
		
	//WT	
		
		WtA8.setBypassed(1);
		Wt8.showControl(0);
		WtSliders.showControl(0);
		TableView1.showControl(0);
	
	//FM
		
		Fm8.setBypassed(1);
		SampleWave8.showControl(1);	
		FmSlider.showControl(0);
		FmWaves8.showControl(0);
		ScriptImage2.showControl(1);
	
	Sample8.set("text",Lwav8.getFilename().replace(".wav").replace(".aif").replace("{PROJECT_FOLDER}").replace("Single Cycle").replace("Roland Jupiter 4").replace("Loops").replace("DronesChords"));
	
	}
	
	if(value == 3)
		{
		//sampler
	
		Sampler8.setBypassed(1);
		Waves8.showControl(0);
		
	//Loop	
		
		loop8.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave8.showControl(0);
		LpControls8.showControl(0);
		
	//WT	
		
		WtA8.setBypassed(0);
		Wt8.showControl(1);
		WtSliders.showControl(1);
		TableView8.showControl(1);
	
	//FM
		
		Fm8.setBypassed(1);
		SampleWave8.showControl(1);	
		FmSlider.showControl(0);
		FmWaves8.showControl(0);
		ScriptImage2.showControl(0);
		
		}		
		
		
		if(value == 4)
			{
			//sampler
	
		Sampler8.setBypassed(1);
		Waves8.showControl(0);
		
	//Loop	
		
		loop8.setBypassed(1);
		LpSwitches1.showControl(0);
		UserWave8.showControl(0);
		LpControls8.showControl(0);
		
	//WT	
		
		WtA8.setBypassed(1);
		Wt8.showControl(0);
		WtSliders.showControl(0);
		TableView8.showControl(0);
	
	//FM
		
		Fm8.setBypassed(0);
		SampleWave8.showControl(1);	
		FmSlider.showControl(1);
		FmWaves8.showControl(1);
		ScriptImage2.showControl(0);
			
			}			

};

Content.getComponent("SampleMode8").setControlCallback(onSampleMode8Control);




inline function onLoadExpControl(component, value)
{
    if (value)
    {
        FileSystem.browse("", false, "", function(result)
        {
            hr = result;
	        
            FileSystem.browseForDirectory("", function(dir)
            {
                expHandler.installExpansionFromPackage(hr, dir);
            });
        });
    }
};

Content.getComponent("LoadExp").setControlCallback(onLoadExpControl);



const var Waves = [];

Waves[0] = Content.getComponent("Wave1");
Waves[1] = Content.getComponent("Wave2");
Waves[2] = Content.getComponent("Wave3");
Waves[3] = Content.getComponent("Wave4");
Waves[4] = Content.getComponent("Wave5");
Waves[5] = Content.getComponent("Wave6");
Waves[6] = Content.getComponent("Wave7");
Waves[7] = Content.getComponent("Wave8");


inline function onStageSelectControl(component, value)
{
	for (i = 0; i < Waves.length; i++)
        Waves[i].showControl(value - 1 == i);
};

Content.getComponent("StageSelect").setControlCallback(onStageSelectControl);






