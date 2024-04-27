//Sample Loading

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
const var SamplerA8 = Synth.getSampler("SamplerA8");



inline function onBankA1Control(component, value)
{

   SamplerA1.loadSampleMap(sampleMaps[value-1]);
  
  	Sample1.set("text",BankA1.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  	
};

Content.getComponent("BankA1").setControlCallback(onBankA1Control);

inline function onBankA2Control(component, value)
{

   SamplerA2.loadSampleMap(sampleMaps[value-1]);
  
    
    Sample2.set("text",BankA2.get("items").split("\n")[value-1]);
  

};

Content.getComponent("BankA2").setControlCallback(onBankA2Control);

inline function onBankA3Control(component, value)
{

   SamplerA3.loadSampleMap(sampleMaps[value-1]);
  
  Sample3.set("text",BankA3.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

};

Content.getComponent("BankA3").setControlCallback(onBankA3Control);

inline function onBankA4Control(component, value)
{

   SamplerA4.loadSampleMap(sampleMaps[value-1]);
 
    
    Sample4.set("text",BankA4.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  

};

Content.getComponent("BankA4").setControlCallback(onBankA4Control);

inline function onBankA5Control(component, value)
{

   SamplerA5.loadSampleMap(sampleMaps[value-1]);
 
  
	Sample5.set("text",BankA5.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
};

Content.getComponent("BankA5").setControlCallback(onBankA5Control);

inline function onBankA6Control(component, value)
{

   SamplerA6.loadSampleMap(sampleMaps[value-1]);
 
	Sample6.set("text",BankA6.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
};

Content.getComponent("BankA6").setControlCallback(onBankA6Control);

inline function onBankA7Control(component, value)
{

   SamplerA7.loadSampleMap(sampleMaps[value-1]);
  
    Sample7.set("text",BankA7.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  

};

Content.getComponent("BankA7").setControlCallback(onBankA7Control);

inline function onBankA8Control(component, value)
{

   SamplerA8.loadSampleMap(sampleMaps[value-1]);
 
  Sample8.set("text",BankA8.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

};

Content.getComponent("BankA8").setControlCallback(onBankA8Control);


const var Samb1 = Synth.getSampler("SamplerB");

inline function onBankA9Control(component, value)
{

    Samb1.loadSampleMap(sampleMaps[value-1]);
  
  
Sample9.set("text",BankA9.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

};

Content.getComponent("BankA9").setControlCallback(onBankA9Control);


const var Loading = Content.getComponent("Loading");



inline function onLoadControl(component, value)
{
		Loading.showControl(1);  
	   
};

Content.getComponent("Load").setControlCallback(onLoadControl);




inline function onCloseLoadControl(component, value)
{
	Loading.showControl(0);  
};

Content.getComponent("CloseLoad").setControlCallback(onCloseLoadControl);

const var LoopA1 = Synth.getAudioSampleProcessor("LoopA1");
const var LoopA2 = Synth.getAudioSampleProcessor("LoopA2");
const var LoopA3 = Synth.getAudioSampleProcessor("LoopA3");
const var LoopA4 = Synth.getAudioSampleProcessor("LoopA4");
const var LoopA5 = Synth.getAudioSampleProcessor("LoopA5");
const var LoopA6 = Synth.getAudioSampleProcessor("LoopA6");
const var LoopA7 = Synth.getAudioSampleProcessor("LoopA7");
const var LoopA8 = Synth.getAudioSampleProcessor("LoopA8");
const var LoopB = Synth.getAudioSampleProcessor("LoopB");


inline function onLpLoad1Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.wav,*.aif ", function (f) 
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
		FileSystem.browse (FileSystem.Desktop, false, "*.wav,*.aif ", function (f) 
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
		FileSystem.browse (FileSystem.Desktop, false, "*.wav,*.aif ", function (f) 
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
		FileSystem.browse (FileSystem.Desktop, false, "*.wav,*.aif ", function (f) 
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
		FileSystem.browse (FileSystem.Desktop, false, "*.wav,*.aif ", function (f) 
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
		FileSystem.browse (FileSystem.Desktop, false, "*.wav,*.aif ", function (f) 
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
		FileSystem.browse (FileSystem.Desktop, false, "*.wav,*.aif ", function (f) 
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
		FileSystem.browse (FileSystem.Desktop, false, "*.wav,*.aif ", function (f) 
	{
				LoopA8.setFile( (f.toString(File.FullPath)));
				Sample8.set("text", f.toString(f.NoExtension));	
	});	

}
};

Content.getComponent("LpLoad8").setControlCallback(onLpLoad8Control);

inline function onLpLoad9Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.wav,*.aif ", function (f) 
	{
				LoopB.setFile( (f.toString(File.FullPath)));
				Sample9.set("text", f.toString(f.NoExtension));	
	});	

}
};

Content.getComponent("LpLoad9").setControlCallback(onLpLoad9Control);

const var Sampler1 = Synth.getChildSynth("SamplerA1");
const var Sampler2 = Synth.getChildSynth("SamplerA2");
const var Sampler3 = Synth.getChildSynth("SamplerA3");
const var Sampler4 = Synth.getChildSynth("SamplerA4");
const var Sampler5 = Synth.getChildSynth("SamplerA5");
const var Sampler6 = Synth.getChildSynth("SamplerA6");
const var Sampler7 = Synth.getChildSynth("SamplerA7");
const var Sampler8 = Synth.getChildSynth("SamplerA8");
const var SamplerB = Synth.getChildSynth("SamplerB");

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
const var WtB = Synth.getChildSynth("WtB");
				
const var loop1 = Synth.getChildSynth("LoopA1");
const var loop2 = Synth.getChildSynth("LoopA2");
const var loop3 = Synth.getChildSynth("LoopA3");
const var loop4 = Synth.getChildSynth("LoopA4");
const var loop5 = Synth.getChildSynth("LoopA5");
const var loop6 = Synth.getChildSynth("LoopA6");
const var loop7 = Synth.getChildSynth("LoopA7");
const var loop8 = Synth.getChildSynth("LoopA8");	
const var loopB = Synth.getChildSynth("LoopB");	

const var SampleWave1 = Content.getComponent("SampleWave1");
const var SampleWave2 = Content.getComponent("SampleWave2");
const var SampleWave3 = Content.getComponent("SampleWave3");
const var SampleWave4 = Content.getComponent("SampleWave4");
const var SampleWave5 = Content.getComponent("SampleWave5");
const var SampleWave6 = Content.getComponent("SampleWave6");
const var SampleWave7 = Content.getComponent("SampleWave7");
const var SampleWave8 = Content.getComponent("SampleWave8");
const var SampleWave9 = Content.getComponent("SampleWave9");

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





inline function onSampleMode1Control(component, value)
{
if(value == 1)
	{
	Sampler1.setBypassed(0);
	loop1.setBypassed(1);
	WtA1.setBypassed(1);
	Group1.setAttribute(5, 1);
	SampleWave1.showControl(1);
	Waves1.showControl(1);
	Wt1.showControl(0);
	TableView1.showControl(0);
	UserWave1.showControl(0);
	LpControls1.showControl(0);
	
	}
if(value == 2)
	{
	Sampler1.setBypassed(1);
	loop1.setBypassed(0);
	WtA1.setBypassed(1);
	Group1.setAttribute(5, 2);
	SampleWave1.showControl(0);
	Waves1.showControl(0);
	Wt1.showControl(0);
	TableView1.showControl(0);
	UserWave1.showControl(1);
	LpControls1.showControl(1);
	
	}
	
	if(value == 3)
		{
		Sampler1.setBypassed(1);
		loop1.setBypassed(1);
		WtA1.setBypassed(0);
		Group1.setAttribute(5, 3);
		SampleWave1.showControl(0);
		Waves1.showControl(0);
		Wt1.showControl(1);
		TableView1.showControl(1);
		UserWave1.showControl(0);
		LpControls1.showControl(0);
		
		}		

};

Content.getComponent("SampleMode1").setControlCallback(onSampleMode1Control);

inline function onSampleMode2Control(component, value)
{
if(value == 1)
	{
	Sampler2.setBypassed(0);
	loop2.setBypassed(1);
	WtA2.setBypassed(1);
	Group2.setAttribute(5, 1);
	SampleWave2.showControl(1);
	Waves2.showControl(1);
	Wt2.showControl(0);
	TableView2.showControl(0);
	UserWave2.showControl(0);
	LpControls2.showControl(0);
	
	}
if(value == 2)
	{
	Sampler2.setBypassed(1);
	loop2.setBypassed(0);
	WtA2.setBypassed(1);
	Group2.setAttribute(5, 2);
	SampleWave2.showControl(0);
	Waves2.showControl(0);
	Wt2.showControl(0);
	TableView2.showControl(0);
	UserWave2.showControl(1);
	LpControls2.showControl(1);
	
	}
	
	if(value == 3)
		{
		Sampler2.setBypassed(1);
		loop2.setBypassed(1);
		WtA2.setBypassed(0);
		Group2.setAttribute(5, 3);
		SampleWave2.showControl(0);
		Waves2.showControl(0);
		Wt2.showControl(1);
		TableView2.showControl(1);
		UserWave2.showControl(0);
		LpControls2.showControl(0);
		
		}		

};

Content.getComponent("SampleMode2").setControlCallback(onSampleMode2Control);

inline function onSampleMode3Control(component, value)
{
if(value == 1)
	{
	Sampler3.setBypassed(0);
	loop3.setBypassed(1);
	WtA3.setBypassed(1);
	Group3.setAttribute(5, 1);
	SampleWave3.showControl(1);
	Waves3.showControl(1);
	Wt3.showControl(0);
	TableView3.showControl(0);
	UserWave3.showControl(0);
	LpControls3.showControl(0);
	
	}
if(value == 2)
	{
	Sampler3.setBypassed(1);
	loop3.setBypassed(0);
	WtA3.setBypassed(1);
	Group3.setAttribute(5, 2);
	SampleWave3.showControl(0);
	Waves3.showControl(0);
	Wt3.showControl(0);
	TableView3.showControl(0);
	UserWave3.showControl(1);
	LpControls3.showControl(1);
	
	}
	
	if(value == 3)
		{
		Sampler3.setBypassed(1);
		loop3.setBypassed(1);
		WtA3.setBypassed(0);
		Group3.setAttribute(5, 3);
		SampleWave3.showControl(0);
		Waves3.showControl(0);
		Wt3.showControl(1);
		TableView3.showControl(1);
		UserWave3.showControl(0);
		LpControls3.showControl(0);
		
		}		

};

Content.getComponent("SampleMode3").setControlCallback(onSampleMode3Control);

inline function onSampleMode4Control(component, value)
{
if(value == 1)
	{
	Sampler4.setBypassed(0);
	loop4.setBypassed(1);
	WtA4.setBypassed(1);
	Group4.setAttribute(5, 1);
	SampleWave4.showControl(1);
	Waves4.showControl(1);
	Wt4.showControl(0);
	TableView4.showControl(0);
	UserWave4.showControl(0);
	LpControls4.showControl(0);
	
	}
if(value == 2)
	{
	Sampler4.setBypassed(1);
	loop4.setBypassed(0);
	WtA4.setBypassed(1);
	Group4.setAttribute(5, 2);
	SampleWave4.showControl(0);
	Waves4.showControl(0);
	Wt4.showControl(0);
	TableView4.showControl(0);
	UserWave4.showControl(1);
	LpControls4.showControl(1);
	
	}
	
	if(value == 3)
		{
		Sampler4.setBypassed(1);
		loop4.setBypassed(1);
		WtA4.setBypassed(0);
		Group4.setAttribute(5, 3);
		SampleWave4.showControl(0);
		Waves4.showControl(0);
		Wt4.showControl(1);
		TableView4.showControl(1);
		UserWave4.showControl(0);
		LpControls4.showControl(0);
		
		}		

};

Content.getComponent("SampleMode4").setControlCallback(onSampleMode4Control);


inline function onSampleMode5Control(component, value)
{
if(value == 1)
	{
	Sampler5.setBypassed(0);
	loop5.setBypassed(1);
	WtA5.setBypassed(1);
	Group5.setAttribute(5, 1);
	SampleWave5.showControl(1);
	Waves5.showControl(1);
	Wt5.showControl(0);
	TableView5.showControl(0);
	UserWave5.showControl(0);
	LpControls5.showControl(0);
	
	}
if(value == 2)
	{
	Sampler5.setBypassed(1);
	loop5.setBypassed(0);
	WtA5.setBypassed(1);
	Group5.setAttribute(5, 2);
	SampleWave5.showControl(0);
	Waves5.showControl(0);
	Wt5.showControl(0);
	TableView5.showControl(0);
	UserWave5.showControl(1);
	LpControls5.showControl(1);
	
	}
	
	if(value == 3)
		{
		Sampler5.setBypassed(1);
		loop5.setBypassed(1);
		WtA5.setBypassed(0);
		Group5.setAttribute(5, 3);
		SampleWave5.showControl(0);
		Waves5.showControl(0);
		Wt5.showControl(1);
		TableView5.showControl(1);
		UserWave5.showControl(0);
		LpControls5.showControl(0);
		
		}
};

Content.getComponent("SampleMode5").setControlCallback(onSampleMode5Control);



inline function onSampleMode6Control(component, value)
{
if(value == 1)
	{
	Sampler6.setBypassed(0);
	loop6.setBypassed(1);
	WtA6.setBypassed(1);
	Group6.setAttribute(5, 1);
	SampleWave6.showControl(1);
	Waves6.showControl(1);
	Wt6.showControl(0);
	TableView6.showControl(0);
	UserWave6.showControl(0);
	LpControls6.showControl(0);
	
	}
if(value == 2)
	{
	Sampler6.setBypassed(1);
	loop6.setBypassed(0);
	WtA6.setBypassed(1);
	Group6.setAttribute(5, 2);
	SampleWave6.showControl(0);
	Waves6.showControl(0);
	Wt6.showControl(0);
	TableView6.showControl(0);
	UserWave6.showControl(1);
	LpControls6.showControl(1);
	
	}
	
	if(value == 3)
		{
		Sampler6.setBypassed(1);
		loop6.setBypassed(1);
		WtA6.setBypassed(0);
		Group6.setAttribute(5, 3);
		SampleWave6.showControl(0);
		Waves6.showControl(0);
		Wt6.showControl(1);
		TableView6.showControl(1);
		UserWave6.showControl(0);
		LpControls6.showControl(0);
		
		}		

};

Content.getComponent("SampleMode6").setControlCallback(onSampleMode6Control);




inline function onSampleMode7Control(component, value)

{
if(value == 1)
	{
	Sampler7.setBypassed(0);
	loop7.setBypassed(1);
	WtA7.setBypassed(1);
	Group7.setAttribute(5, 1);
	SampleWave7.showControl(1);
	Waves7.showControl(1);
	Wt7.showControl(0);
	TableView7.showControl(0);
	UserWave7.showControl(0);
	LpControls7.showControl(0);
	
	}
if(value == 2)
	{
	Sampler7.setBypassed(1);
	loop7.setBypassed(0);
	WtA7.setBypassed(1);
	Group7.setAttribute(5, 2);
	SampleWave7.showControl(0);
	Waves7.showControl(0);
	Wt7.showControl(0);
	TableView7.showControl(0);
	UserWave7.showControl(1);
	LpControls7.showControl(1);
	
	}
	
	if(value == 3)
		{
		Sampler7.setBypassed(1);
		loop7.setBypassed(1);
		WtA7.setBypassed(0);
		Group7.setAttribute(5, 3);
		SampleWave7.showControl(0);
		Waves7.showControl(0);
		Wt7.showControl(1);
		TableView7.showControl(1);
		UserWave7.showControl(0);
		LpControls7.showControl(0);
		
		}		

};

Content.getComponent("SampleMode7").setControlCallback(onSampleMode7Control);



inline function onSampleMode8Control(component, value)
{
if(value == 1)
	{
	Sampler8.setBypassed(0);
	loop8.setBypassed(1);
	WtA8.setBypassed(1);
	Group8.setAttribute(5, 1);
	SampleWave8.showControl(1);
	Waves8.showControl(1);
	Wt8.showControl(0);
	TableView8.showControl(0);
	UserWave8.showControl(0);
	LpControls8.showControl(0);
	
	}
if(value == 2)
	{
	Sampler8.setBypassed(1);
	loop8.setBypassed(0);
	WtA8.setBypassed(1);
	Group8.setAttribute(5, 2);
	SampleWave8.showControl(0);
	Waves8.showControl(0);
	Wt8.showControl(0);
	TableView8.showControl(0);
	UserWave8.showControl(1);
	LpControls8.showControl(1);
	
	}
	
	if(value == 3)
		{
		Sampler8.setBypassed(1);
		loop8.setBypassed(1);
		WtA8.setBypassed(0);
		Group8.setAttribute(5, 3);
		SampleWave8.showControl(0);
		Waves8.showControl(0);
		Wt8.showControl(1);
		TableView8.showControl(1);
		UserWave8.showControl(0);
		LpControls8.showControl(0);
		
		}		

};

Content.getComponent("SampleMode8").setControlCallback(onSampleMode8Control);


inline function onSampleMode9Control(component, value)

{
if(value == 1)
	{
	SamplerB.setBypassed(0);
	loopB.setBypassed(1);
	WtB.setBypassed(1);
	SampleWave9.showControl(1);
	Waves9.showControl(1);
	Wt9.showControl(0);
	TableView9.showControl(0);
	UserWave9.showControl(0);
	LpControls9.showControl(0);
	
	}
if(value == 2)
	{
	SamplerB.setBypassed(1);
	loopB.setBypassed(0);
	WtB.setBypassed(1);
	SampleWave9.showControl(0);
	Waves9.showControl(0);
	Wt9.showControl(0);
	TableView9.showControl(0);
	UserWave9.showControl(1);
	LpControls9.showControl(1);
	
	}
	
	if(value == 3)
		{
		SamplerB.setBypassed(1);
		loopB.setBypassed(1);
		WtB.setBypassed(0);
		SampleWave9.showControl(0);
		Waves9.showControl(0);
		Wt9.showControl(1);
		TableView9.showControl(1);
		UserWave9.showControl(0);
		LpControls9.showControl(0);
		
		}		

};

Content.getComponent("SampleMode9").setControlCallback(onSampleMode9Control);
