//Sample Loading


const var expHandler = Engine.createExpansionHandler();
const var expansions = expHandler.getExpansionList();

const var BankA1 = Content.getComponent("BankA1");
const var BankA2 = Content.getComponent("BankA2");
const var BankA3 = Content.getComponent("BankA3");
const var BankA4 = Content.getComponent("BankA4");
const var BankA5 = Content.getComponent("BankA5");
const var BankA6 = Content.getComponent("BankA6");
const var BankA7 = Content.getComponent("BankA7");
const var BankA8 = Content.getComponent("BankA8");
const var BankA11 = Content.getComponent("BankA11");

const var ExpansionSelector = Content.getComponent("ExpansionSelector");
const var ExpansionSelector2 = Content.getComponent("ExpansionSelector2");
const var ExpansionSelector3 = Content.getComponent("ExpansionSelector3");

expHandler.setAllowedExpansionTypes([expHandler.FileBased, 
                                     expHandler.Intermediate, 
                                     expHandler.Encrypted]);

                                     
const var expansionNames = [];

expansionNames.push("FACTORY");

for(e in expHandler.getExpansionList())
    expansionNames.push(e.getProperties().Name);

ExpansionSelector.set("items", expansionNames.join("\n"));
ExpansionSelector2.set("items", expansionNames.join("\n"));
ExpansionSelector3.set("items", expansionNames.join("\n"));




inline function onExpansionSelectorControl(component, value)
{
	local expansionToLoad = component.getItemText();
	

	if(expansionToLoad == expansionNames[0])
        expansionToLoad = "";
    
	expHandler.setCurrentExpansion(expansionToLoad);
	
	
		ExpansionSelector2.setValue(value);
		ExpansionSelector3.setValue(value);
	
};

Content.getComponent("ExpansionSelector").setControlCallback(onExpansionSelectorControl);

inline function onExpansionSelector2Control(component, value)
{
	
	ExpansionSelector.setValue(value);
	ExpansionSelector2.setValue(value);
	ExpansionSelector.changed();
};

Content.getComponent("ExpansionSelector2").setControlCallback(onExpansionSelector2Control);

inline function onExpansionSelector3Control(component, value)
{
	ExpansionSelector.setValue(value);
	ExpansionSelector3.setValue(value);
	ExpansionSelector.changed();
	
};

Content.getComponent("ExpansionSelector3").setControlCallback(onExpansionSelector3Control);

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
		BankA11.set("items", "");
        BankA11.set("items", sampleMapsed.join("\n"));       
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
 	    BankA11.set("items", "");
        BankA11.set("items", sampleMaps.join("\n"));     

    }
    
    
}

expHandler.setExpansionCallback(newcombobox);

newcombobox(undefined);



//Samples

const samplemaps = Sampler.getSampleMapList();


inline function onBankA1Control(component, value)
{

  SamplerA1.loadSampleMap(sampleMaps[value-1]);
 
  	Sample1.set("text",BankA1.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

  	
};

Content.getComponent("BankA1").setControlCallback(onBankA1Control);

inline function onBankA2Control(component, value)
{

	SamplerA2.loadSampleMap(sampleMaps[value-1]); 
   Sample2.set("text",BankA2.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
   
   
  

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

const var ModeMenus = [Content.getComponent("SampleMode1"),
                       Content.getComponent("SampleMode2"),
                       Content.getComponent("SampleMode3"),
                       Content.getComponent("SampleMode4"),
                       Content.getComponent("SampleMode5"),
                       Content.getComponent("SampleMode6"),
                       Content.getComponent("SampleMode7"),
                       Content.getComponent("SampleMode8")];

const var SampleWaves = [Content.getComponent("Waves3"),
                         Content.getComponent("Waves1"),
                         Content.getComponent("Waves2"),
                         Content.getComponent("Waves4"),
                         Content.getComponent("Waves5"),
                         Content.getComponent("Waves6"),
                         Content.getComponent("Waves7"),
                         Content.getComponent("Waves8")];

const var SLoad = [Content.getComponent("SfzLoad2"),
                   Content.getComponent("SfzLoad1"),
                   Content.getComponent("SfzLoad3"),
                   Content.getComponent("SfzLoad4"),
                   Content.getComponent("SfzLoad5"),
                   Content.getComponent("SfzLoad6"),
                   Content.getComponent("SfzLoad7"),
                   Content.getComponent("SfzLoad8")];

const var LoopCont = [Content.getComponent("LpControls8"),
                      Content.getComponent("LpControls1"),
                      Content.getComponent("LpControls2"),
                      Content.getComponent("LpControls3"),
                      Content.getComponent("LpControls4"),
                      Content.getComponent("LpControls5"),
                      Content.getComponent("LpControls6"),
                      Content.getComponent("LpControls7")];

const var UserWavs = [Content.getComponent("UserWave1"),
                      Content.getComponent("UserWave2"),
                      Content.getComponent("UserWave3"),
                      Content.getComponent("UserWave4"),
                      Content.getComponent("UserWave5"),
                      Content.getComponent("UserWave6"),
                      Content.getComponent("UserWave7"),
                      Content.getComponent("UserWave8")];

const var SplWaves = [Content.getComponent("SamplerWave1"),
                      Content.getComponent("SamplerWave2"),
                      Content.getComponent("SamplerWave3"),
                      Content.getComponent("SamplerWave4"),
                      Content.getComponent("SamplerWave5"),
                      Content.getComponent("SamplerWave6"),
                      Content.getComponent("SamplerWave7"),
                      Content.getComponent("SamplerWave8")];
                      
const var SfMultWaves = [Content.getComponent("SfzWave8"),
                         Content.getComponent("SfzWave7"),
                         Content.getComponent("SfzWave6"),
                         Content.getComponent("SfzWave5"),
                         Content.getComponent("SfzWave4"),
                         Content.getComponent("SfzWave3"),
                         Content.getComponent("SfzWave2"),
                         Content.getComponent("SfzWave1")];
                     




inline function onBankA11Control(component, value)
{
	for(s in ModeMenus)
	       s.setValue(1);
	       
	for(s in SampleWaves)
	       s.showControl(1);
	for(s in SplWaves)
		       s.showControl(1);       
	for(s in LoopCont)
			       s.showControl(0);      
	for(s in UserWavs)
			       s.showControl(0);      
	for(s in SLoad)
			       s.showControl(0);      
	for(s in SfMultWaves)
			       s.showControl(0);      

Sampler1.setBypassed(0); Sampler2.setBypassed(0); Sampler3.setBypassed(0); 	Sampler4.setBypassed(0); Sampler5.setBypassed(0); Sampler6.setBypassed(0); 	Sampler7.setBypassed(0); Sampler8.setBypassed(0); 	
		
Sfz1.setBypassed(1); Sfz2.setBypassed(1); Sfz3.setBypassed(1); Sfz4.setBypassed(1); Sfz5.setBypassed(1); Sfz6.setBypassed(1); Sfz7.setBypassed(1); Sfz8.setBypassed(1);
	
loop1.setBypassed(1); loop2.setBypassed(1); loop3.setBypassed(1); loop4.setBypassed(1); loop5.setBypassed(1); loop6.setBypassed(1); loop7.setBypassed(1); loop8.setBypassed(1); 

SamplerA1.loadSampleMap(sampleMaps[value-1]);	
SamplerA2.loadSampleMap(sampleMaps[value-1]);	
SamplerA3.loadSampleMap(sampleMaps[value-1]);
SamplerA4.loadSampleMap(sampleMaps[value-1]);	
SamplerA5.loadSampleMap(sampleMaps[value-1]);
SamplerA6.loadSampleMap(sampleMaps[value-1]);
SamplerA7.loadSampleMap(sampleMaps[value-1]);
SamplerA8.loadSampleMap(sampleMaps[value-1]);

BankA1.setValue(value);
BankA2.setValue(value);
BankA3.setValue(value);
BankA4.setValue(value);
BankA5.setValue(value);
BankA6.setValue(value);
BankA7.setValue(value);
BankA8.setValue(value);


Sample1.set("text",BankA1.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

Sample2.set("text",BankA2.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

Sample3.set("text",BankA3.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

Sample4.set("text",BankA4.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);

Sample5.set("text",BankA5.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
   
Sample6.set("text",BankA6.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  
Sample7.set("text",BankA7.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  Sample8.set("text",BankA8.get("items").replace("XPSaw_").replace("XPSqr_").replace("XPMisc_").replace("XPTri_").replace("XPFM_").replace("XPMisc_").replace("ST_").replace("ModShape_").replace("ModFM_").replace("ModShape_").replace("ModFiltered_").replace("K3Pluck_").replace("K3Pad_").replace("K3Lead_").replace("K3Lead_").replace("K3Keys_").replace("K3Bell_").replace("K3FX_").replace("K3Bass_").replace("CSWave_").replace("CSStrings_").replace("CSPad_").replace("CSLead_").replace("CSFX_").replace("CSKeys_").replace("CSBass_").replace("101Tri_").replace("101Sqr_").replace("101Saw_").replace("101Noise_").replace("101Ext_").split("\n")[value-1]);
  
};

Content.getComponent("BankA11").setControlCallback(onBankA11Control);

const var WaveLabel1 = Content.getComponent("WaveLabel1");
const var WaveLabel2 = Content.getComponent("WaveLabel2");
const var WaveLabel3 = Content.getComponent("WaveLabel3");
const var WaveLabel4 = Content.getComponent("WaveLabel4");
const var WaveLabel5 = Content.getComponent("WaveLabel5");
const var WaveLabel6 = Content.getComponent("WaveLabel6");
const var WaveLabel7 = Content.getComponent("WaveLabel7");
const var WaveLabel8 = Content.getComponent("WaveLabel8");





inline function onLpLoad1Control(component, value)
{
	
	

if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA1.setFile((f.toString(File.FullPath)));
				Sample1.set("text", f.toString(f.NoExtension));	
			
				WaveLabel1.set("text", f.toString(f.NoExtension));	
				root1.setValue(64); 
				root1.changed();
				
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
	    		WaveLabel2.set("text", f.toString(f.NoExtension));	
	    		root2.setValue(64); 
				root2.changed();		
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
				WaveLabel3.set("text", f.toString(f.NoExtension));
				root3.setValue(64); 
				root3.changed();				
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
				WaveLabel4.set("text", f.toString(f.NoExtension));
				root4.setValue(64); 
				root4.changed();
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
				WaveLabel5.set("text", f.toString(f.NoExtension));	
				root5.setValue(64); 
				root5.changed();
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
				WaveLabel6.set("text", f.toString(f.NoExtension));
				root6.setValue(64); 
				root6.changed();
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
				WaveLabel7.set("text", f.toString(f.NoExtension));
				root7.setValue(64); 
				root7.changed();
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
				WaveLabel8.set("text", f.toString(f.NoExtension));
				root8.setValue(64); 
				root8.changed();
	});	

}
};

Content.getComponent("LpLoad8").setControlCallback(onLpLoad8Control);


inline function onLoadAllLoopControl(component, value)
{
	
	for(s in ModeMenus)
	       s.setValue(2);
	       
	       for(s in SampleWaves)
	              s.showControl(0);
	       for(s in SplWaves)
	       	       s.showControl(0);       	    
	       for(s in LoopCont)
	       		       s.showControl(1);      
	       for(s in UserWavs)
	       		       s.showControl(1);      
	       for(s in SLoad)
	       		       s.showControl(0);      
	       for(s in SfMultWaves)
	       		       s.showControl(0);      
	      
Sampler1.setBypassed(1); Sampler2.setBypassed(1); Sampler3.setBypassed(1); 	Sampler4.setBypassed(1); Sampler5.setBypassed(1); Sampler6.setBypassed(1); 	Sampler7.setBypassed(1); Sampler8.setBypassed(1); 	
		
Sfz1.setBypassed(1); Sfz2.setBypassed(1); Sfz3.setBypassed(1); Sfz4.setBypassed(1); Sfz5.setBypassed(1); Sfz6.setBypassed(1); Sfz7.setBypassed(1); Sfz8.setBypassed(1);
	
loop1.setBypassed(0); loop2.setBypassed(0); loop3.setBypassed(0); loop4.setBypassed(0); loop5.setBypassed(0); loop6.setBypassed(0); loop7.setBypassed(0); loop8.setBypassed(0);       
	              

if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
	
	

	
LoopA1.setFile((f.toString(File.FullPath)));
	
LoopA2.setFile( (f.toString(File.FullPath)));

LoopA3.setFile( (f.toString(File.FullPath)));

LoopA4.setFile( (f.toString(File.FullPath)));

LoopA5.setFile( (f.toString(File.FullPath)));

LoopA6.setFile( (f.toString(File.FullPath)));

LoopA7.setFile( (f.toString(File.FullPath)));

LoopA8.setFile( (f.toString(File.FullPath)));

WaveLabel1.set("text", f.toString(f.NoExtension));
WaveLabel2.set("text", f.toString(f.NoExtension));
WaveLabel3.set("text", f.toString(f.NoExtension));
WaveLabel4.set("text", f.toString(f.NoExtension));
WaveLabel5.set("text", f.toString(f.NoExtension));
WaveLabel6.set("text", f.toString(f.NoExtension));
WaveLabel7.set("text", f.toString(f.NoExtension));
WaveLabel8.set("text", f.toString(f.NoExtension));
	});	

}
};


Content.getComponent("LoadAllLoop").setControlCallback(onLoadAllLoopControl);



const var Sz1 = Synth.getSampler("Sfz1");
const var Sz2 = Synth.getSampler("Sfz2");
const var Sz3 = Synth.getSampler("Sfz3");
const var Sz4 = Synth.getSampler("Sfz4");
const var Sz5 = Synth.getSampler("Sfz5");
const var Sz6 = Synth.getSampler("Sfz6");
const var Sz7 = Synth.getSampler("Sfz7");
const var Sz8 = Synth.getSampler("Sfz8");

const var SfzWave1 = Content.getComponent("SfzWave1");
const var SfzWave2 = Content.getComponent("SfzWave2");
const var SfzWave3 = Content.getComponent("SfzWave3");
const var SfzWave4 = Content.getComponent("SfzWave4");
const var SfzWave5 = Content.getComponent("SfzWave5");
const var SfzWave6 = Content.getComponent("SfzWave6");
const var SfzWave7 = Content.getComponent("SfzWave7");
const var SfzWave8 = Content.getComponent("SfzWave8");

inline function onSampleMode1Control(component, value)
{


if(value == 1)
	{
	
	Engine.allNotesOff();
	
//sampler

	Sampler1.setBypassed(0);
	
	Waves1.showControl(1);
	BankA1.showControl(1);
	SampleWave1.showControl(1);	
	Sample1.showControl(1);
	SfzWave1.showControl(0);
	SfzLoad1.showControl(0);
	Sfz1.setBypassed(1);
	LabelsSfz1[0].showControl(0);
	

//Loop	
	
	loop1.setBypassed(1);
	UserWave1.showControl(0);
	LpControls1.showControl(0);
	

	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler1.setBypassed(1);
		
		Waves1.showControl(0);
		BankA1.showControl(0);
		SampleWave1.showControl(0);	
		Sample1.showControl(1);
		
		SfzLoad1.showControl(0);
		Sfz1.setBypassed(1);
		LabelsSfz1[0].showControl(0);
		
		SfzWave1.showControl(0);
		SamplerA1.clearSampleMap();
		Sz1.clearSampleMap();
		
	//Loop	
		
		loop1.setBypassed(0);
		
		UserWave1.showControl(1);
		LpControls1.showControl(1);


	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler1.setBypassed(1);	
		Waves1.showControl(0);
		BankA1.showControl(0);
		SampleWave1.showControl(0);	
		Sample1.showControl(1);
	
		SfzLoad1.showControl(1);
		Sfz1.setBypassed(0);
		LabelsSfz1[0].showControl(1);
		
		SfzWave1.showControl(1);


	SamplerA1.clearSampleMap();
	
	
	//Loop	
		
		loop1.setBypassed(1);
		
		UserWave1.showControl(0);
		LpControls1.showControl(0);

	
	}

};

Content.getComponent("SampleMode1").setControlCallback(onSampleMode1Control);


inline function onSampleMode2Control(component, value)
{


if(value == 1)
	{
	
	Engine.allNotesOff();
	
//sampler

	Sampler2.setBypassed(0);
	
	Waves2.showControl(1);
	BankA2.showControl(1);
	SampleWave2.showControl(1);	
	Sample2.showControl(1);
	SfzWave2.showControl(0);
	SfzLoad2.showControl(0);
	Sfz2.setBypassed(1);
	LabelsSfz1[1].showControl(0);

	


	

	 
//Loop	
	
	loop2.setBypassed(1);
	UserWave2.showControl(0);
	LpControls2.showControl(0);
	

	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler2.setBypassed(1);
		
		Waves2.showControl(0);
		BankA2.showControl(0);
		SampleWave2.showControl(0);	
		Sample2.showControl(1);
		SfzWave2.showControl(0);
		
		SfzLoad2.showControl(0);
		Sfz2.setBypassed(1);
		LabelsSfz1[1].showControl(0);

		
	//Loop	
		
		loop2.setBypassed(0);
		
		UserWave2.showControl(1);
		LpControls2.showControl(1);
		
		SamplerA2.clearSampleMap();
		Sz2.clearSampleMap();

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler2.setBypassed(1);	
		Waves2.showControl(0);
		BankA2.showControl(0);
		SampleWave2.showControl(1);	
		Sample2.showControl(1);
		SfzWave2.showControl(1);
	
		SfzLoad2.showControl(1);
		Sfz2.setBypassed(0);
		LabelsSfz1[1].showControl(1);
		

	
	//Loop	
		
		loop2.setBypassed(1);
		
		UserWave2.showControl(0);
		LpControls2.showControl(0);
		
		SamplerA2.clearSampleMap();
	

	
	}

};

Content.getComponent("SampleMode2").setControlCallback(onSampleMode2Control);

inline function onSampleMode3Control(component, value)
{


if(value == 1)
	{
	
	Engine.allNotesOff();
	
//sampler

	Sampler3.setBypassed(0);
	
	Waves3.showControl(1);
	BankA3.showControl(1);
	SampleWave3.showControl(1);	
	Sample3.showControl(1);
	SfzWave3.showControl(0);
	SfzLoad3.showControl(0);
	Sfz3.setBypassed(1);
	LabelsSfz1[2].showControl(0);

	

	 
//Loop	
	
	loop3.setBypassed(1);
	UserWave3.showControl(0);
	LpControls3.showControl(0);
	

	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler3.setBypassed(1);
		
		Waves3.showControl(0);
		BankA3.showControl(0);
		SampleWave3.showControl(0);	
		Sample3.showControl(1);

	
		
		SfzLoad3.showControl(0);
		Sfz3.setBypassed(1);
		LabelsSfz1[2].showControl(0);

	//Loop	
		
		loop3.setBypassed(0);
		
		UserWave3.showControl(1);
		LpControls3.showControl(1);
		
		SamplerA3.clearSampleMap();
		Sz3.clearSampleMap();

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler3.setBypassed(1);	
		Waves3.showControl(0);
		BankA3.showControl(0);
		SampleWave3.showControl(1);	
		Sample3.showControl(1);
	
		SfzLoad3.showControl(1);
		Sfz3.setBypassed(0);
		LabelsSfz1[2].showControl(1);

	Sampler3.setBypassed(1);	
	Sfz3.setBypassed(0);
	loop3.setBypassed(1);
	//Loop	
		
		loop3.setBypassed(1);
		
		UserWave3.showControl(0);
		LpControls3.showControl(0);
		

		SamplerA3.clearSampleMap();

	
	}

};

Content.getComponent("SampleMode3").setControlCallback(onSampleMode3Control);

inline function onSampleMode4Control(component, value)
{


if(value == 1)
	{
	
	Engine.allNotesOff();
	
//sampler

	Sampler4.setBypassed(0);
	
	Waves4.showControl(1);
	BankA4.showControl(1);
	SampleWave4.showControl(1);	
	Sample4.showControl(1);
	SfzWave4.showControl(0);
	SfzLoad4.showControl(0);
	Sfz4.setBypassed(1);
	LabelsSfz1[3].showControl(0);
	

//Loop	
	
	loop4.setBypassed(1);
	UserWave4.showControl(0);
	LpControls4.showControl(0);
	

	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler4.setBypassed(1);
		
		Waves4.showControl(0);
		BankA4.showControl(0);
		SampleWave4.showControl(0);	
		Sample4.showControl(1);
		
		SfzLoad4.showControl(0);
		Sfz4.setBypassed(1);
		LabelsSfz1[3].showControl(0);
		

	//Loop	
		
		loop4.setBypassed(0);
		
		UserWave4.showControl(1);
		LpControls4.showControl(1);
		
		
		SamplerA4.clearSampleMap();
		Sz4.clearSampleMap();

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler4.setBypassed(1);	
		Waves4.showControl(0);
		BankA4.showControl(0);
		SampleWave4.showControl(0);	
		Sample4.showControl(1);
	
		SfzLoad4.showControl(1);
		Sfz4.setBypassed(0);
		LabelsSfz1[3].showControl(1);
	

	
	//Loop	
		
		loop4.setBypassed(1);
		
		UserWave4.showControl(0);
		LpControls4.showControl(0);
		
		SamplerA4.clearSampleMap();
		

	
	}

};

Content.getComponent("SampleMode4").setControlCallback(onSampleMode4Control);

inline function onSampleMode5Control(component, value)
{


if(value == 1)
	{
	
	Engine.allNotesOff();
	
//sampler

	Sampler5.setBypassed(0);
	
	Waves5.showControl(1);
	BankA5.showControl(1);
	SampleWave5.showControl(1);	
	Sample5.showControl(1);
	SfzWave5.showControl(0);
	SfzLoad5.showControl(0);
	Sfz5.setBypassed(1);
	LabelsSfz1[4].showControl(0);
	
	

	 
//Loop	
	
	loop5.setBypassed(1);
	UserWave5.showControl(0);
	LpControls5.showControl(0);
	

	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler5.setBypassed(1);
		
		Waves5.showControl(0);
		BankA5.showControl(0);
		SampleWave5.showControl(0);	
		Sample5.showControl(1);
		
		SfzLoad5.showControl(0);
		Sfz5.setBypassed(1);
		LabelsSfz1[4].showControl(0);
	

	//Loop	
		
		loop5.setBypassed(0);
		
		UserWave5.showControl(1);
		LpControls5.showControl(1);
		
		SamplerA5.clearSampleMap();
			Sz5.clearSampleMap();

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler5.setBypassed(1);	
		Waves5.showControl(0);
		BankA5.showControl(0);
		SampleWave5.showControl(1);	
		Sample5.showControl(1);
	
		SfzLoad5.showControl(1);
		Sfz5.setBypassed(0);
		LabelsSfz1[4].showControl(1);
		
		
	
	//Loop	
		
		loop5.setBypassed(1);
		
		UserWave5.showControl(0);
		LpControls5.showControl(0);
		
		SamplerA5.clearSampleMap();
	

	
	}

};

Content.getComponent("SampleMode5").setControlCallback(onSampleMode5Control);


inline function onSampleMode6Control(component, value)
{


if(value == 1)
	{
	
	Engine.allNotesOff();
	
//sampler

	Sampler6.setBypassed(0);
	
	Waves6.showControl(1);
	BankA6.showControl(1);
	SampleWave6.showControl(1);	
	Sample6.showControl(1);
	SfzWave6.showControl(0);
	SfzLoad6.showControl(0);
	Sfz6.setBypassed(1);
	LabelsSfz1[5].showControl(0);

	
	 
//Loop	
	
	loop6.setBypassed(1);
	UserWave6.showControl(0);
	LpControls6.showControl(0);
	

	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler6.setBypassed(1);
		
		Waves6.showControl(0);
		BankA6.showControl(0);
		SampleWave6.showControl(0);	
		Sample6.showControl(1);
		
		SfzLoad6.showControl(0);
		Sfz6.setBypassed(1);
		LabelsSfz1[5].showControl(0);
	
	
		
		
	//Loop	
		
		loop6.setBypassed(0);
		
		UserWave6.showControl(1);
		LpControls6.showControl(1);
		
		
		SamplerA6.clearSampleMap();
			Sz6.clearSampleMap();

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler6.setBypassed(1);	
		Waves6.showControl(0);
		BankA6.showControl(0);
		SampleWave6.showControl(1);	
		Sample6.showControl(1);
	
		SfzLoad6.showControl(1);
		Sfz6.setBypassed(0);
		LabelsSfz1[5].showControl(1);
	
		

	//Loop	
		
		loop6.setBypassed(1);
		
		UserWave6.showControl(0);
		LpControls6.showControl(0);
		
		SamplerA6.clearSampleMap();
	

	
	}

};

Content.getComponent("SampleMode6").setControlCallback(onSampleMode6Control);


inline function onSampleMode7Control(component, value)
{


if(value == 1)
	{
	
	Engine.allNotesOff();
	
//sampler

	Sampler7.setBypassed(0);
	
	Waves7.showControl(1);
	BankA7.showControl(1);
	SampleWave7.showControl(1);	
	Sample7.showControl(1);
	SfzWave7.showControl(0);
	SfzLoad7.showControl(0);
	Sfz7.setBypassed(1);
	LabelsSfz1[6].showControl(0);

	
	

	 
//Loop	
	
	loop7.setBypassed(1);
	UserWave7.showControl(0);
	LpControls7.showControl(0);
	

	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler7.setBypassed(1);
		
		Waves7.showControl(0);
		BankA7.showControl(0);
		SampleWave7.showControl(0);	
		Sample7.showControl(1);
		
		SfzLoad7.showControl(0);
		Sfz7.setBypassed(1);
		LabelsSfz1[6].showControl(0);
	

	//Loop	
		
		loop7.setBypassed(0);
		
		UserWave7.showControl(1);
		LpControls7.showControl(1);

	SamplerA7.clearSampleMap();
		Sz7.clearSampleMap();
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler7.setBypassed(1);	
		Waves7.showControl(0);
		BankA7.showControl(0);
		SampleWave7.showControl(1);	
		Sample7.showControl(1);
	
		SfzLoad7.showControl(1);
		Sfz7.setBypassed(0);
		LabelsSfz1[6].showControl(1);



	
	//Loop	
		
		loop7.setBypassed(1);
		
		UserWave7.showControl(0);
		LpControls7.showControl(0);

	SamplerA7.clearSampleMap();
	
	}

};

Content.getComponent("SampleMode7").setControlCallback(onSampleMode7Control);


inline function onSampleMode8Control(component, value)
{


if(value == 1)
	{
	
	Engine.allNotesOff();
	
//sampler

	Sampler8.setBypassed(0);
	
	Waves8.showControl(1);
	BankA8.showControl(1);
	SampleWave8.showControl(1);	
	Sample8.showControl(1);
	SfzWave8.showControl(0);
	SfzLoad8.showControl(0);
	Sfz8.setBypassed(1);
	LabelsSfz1[7].showControl(0);



//Loop	
	
	loop8.setBypassed(1);
	UserWave8.showControl(0);
	LpControls8.showControl(0);
	

	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler8.setBypassed(1);
		
		Waves8.showControl(0);
		BankA8.showControl(0);
		SampleWave8.showControl(0);	
		Sample8.showControl(1);
		
		SfzLoad8.showControl(0);
		Sfz8.setBypassed(1);
		LabelsSfz1[7].showControl(0);
	

	//Loop	
		
		loop8.setBypassed(0);
		
		UserWave8.showControl(1);
		LpControls8.showControl(1);
SamplerA8.clearSampleMap();
	Sz8.clearSampleMap();
	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler8.setBypassed(1);	
		Waves8.showControl(0);
		BankA8.showControl(0);
		SampleWave8.showControl(0);	
		Sample8.showControl(1);
	
		SfzLoad8.showControl(1);
		Sfz8.setBypassed(0);
		LabelsSfz1[7].showControl(1);

		

	//Loop	
		
		loop8.setBypassed(1);
		
		UserWave8.showControl(0);
		LpControls8.showControl(0);

	SamplerA8.clearSampleMap();
	
	}

};

Content.getComponent("SampleMode8").setControlCallback(onSampleMode8Control);



const var Sfz1 = Synth.getChildSynth("Sfz1");
const var Sfz2 = Synth.getChildSynth("Sfz2");
const var Sfz3 = Synth.getChildSynth("Sfz3");
const var Sfz4 = Synth.getChildSynth("Sfz4");
const var Sfz5 = Synth.getChildSynth("Sfz5");
const var Sfz6 = Synth.getChildSynth("Sfz6");
const var Sfz7 = Synth.getChildSynth("Sfz7");
const var Sfz8 = Synth.getChildSynth("Sfz8");


const var SfzLoad1 = Content.getComponent("SfzLoad1");
const var SfzLoad2 = Content.getComponent("SfzLoad2");
const var SfzLoad3 = Content.getComponent("SfzLoad3");
const var SfzLoad4 = Content.getComponent("SfzLoad4");
const var SfzLoad5 = Content.getComponent("SfzLoad5");
const var SfzLoad6 = Content.getComponent("SfzLoad6");
const var SfzLoad7 = Content.getComponent("SfzLoad7");
const var SfzLoad8 = Content.getComponent("SfzLoad8");
{
	
}

const var LabelsSfz1 = [];

LabelsSfz1[0] = Content.getComponent("SfzLabelStore1");
LabelsSfz1[1] = Content.getComponent("SfzLabelStore2");
LabelsSfz1[2] = Content.getComponent("SfzLabelStore3");
LabelsSfz1[3] = Content.getComponent("SfzLabelStore4");
LabelsSfz1[4] = Content.getComponent("SfzLabelStore5");
LabelsSfz1[5] = Content.getComponent("SfzLabelStore6");
LabelsSfz1[6] = Content.getComponent("SfzLabelStore7");
LabelsSfz1[7] = Content.getComponent("SfzLabelStore8");






const var Sf1 = Synth.getSampler("Sfz1");
const var Sf2 = Synth.getSampler("Sfz2");
const var Sf3 = Synth.getSampler("Sfz3");
const var Sf4 = Synth.getSampler("Sfz4");
const var Sf5 = Synth.getSampler("Sfz5");
const var Sf6 = Synth.getSampler("Sfz6");
const var Sf7 = Synth.getSampler("Sfz7");
const var Sf8 = Synth.getSampler("Sfz8");

///SFZ

const var SfzLabelStore1 = Content.getComponent("SfzLabelStore1");
const var SfzLabelStore2 = Content.getComponent("SfzLabelStore2");
const var SfzLabelStore3 = Content.getComponent("SfzLabelStore3");
const var SfzLabelStore4 = Content.getComponent("SfzLabelStore4");
const var SfzLabelStore5 = Content.getComponent("SfzLabelStore5");
const var SfzLabelStore6 = Content.getComponent("SfzLabelStore6");
const var SfzLabelStore7 = Content.getComponent("SfzLabelStore7");
const var SfzLabelStore8 = Content.getComponent("SfzLabelStore8");


Sf1.loadSfzFile(SfzLabelStore1.get("text"));
Sf2.loadSfzFile(SfzLabelStore2.get("text"));
Sf3.loadSfzFile(SfzLabelStore3.get("text"));
Sf4.loadSfzFile(SfzLabelStore4.get("text"));
Sf5.loadSfzFile(SfzLabelStore5.get("text"));
Sf6.loadSfzFile(SfzLabelStore6.get("text"));
Sf7.loadSfzFile(SfzLabelStore7.get("text"));
Sf8.loadSfzFile(SfzLabelStore8.get("text"));


inline function onSfzAllControl(component, value)
{
	
	for(s in ModeMenus)
	       s.setValue(3);
	       
	       for(s in SampleWaves)
	       	              s.showControl(0);
	       	       for(s in SplWaves)
	       	       	       s.showControl(0);       	    
	       	       for(s in LoopCont)
	       	       		       s.showControl(0);      
	       	       for(s in UserWavs)
	       	       		       s.showControl(0);      
	       	       for(s in SLoad)
	       	       		       s.showControl(1);      
	       	       for(s in SfMultWaves)
	       	       		       s.showControl(1);    

Sampler1.setBypassed(1); Sampler2.setBypassed(1); Sampler3.setBypassed(1); 	Sampler4.setBypassed(1); Sampler5.setBypassed(1); Sampler6.setBypassed(1); 	Sampler7.setBypassed(1); Sampler8.setBypassed(1); 	
		
Sfz1.setBypassed(0); Sfz2.setBypassed(0); Sfz3.setBypassed(0); Sfz4.setBypassed(0); Sfz5.setBypassed(0); Sfz6.setBypassed(0); Sfz7.setBypassed(0); Sfz8.setBypassed(0);
	
loop1.setBypassed(1); loop2.setBypassed(1); loop3.setBypassed(1); loop4.setBypassed(1); loop5.setBypassed(1); loop6.setBypassed(1); loop7.setBypassed(1); loop8.setBypassed(1);            
	              

		if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

Sf1.loadSfzFile(f.toString(File.FullPath));
	
		LabelsSfz1[0].set("text", f.toString(f.FullPath));
	
		Sf2.loadSfzFile(f.toString(File.FullPath));

		    		LabelsSfz1[1].set("text", f.toString(f.FullPath));	
		    	
		    		Sf3.loadSfzFile(f.toString(File.FullPath));

		    		     		LabelsSfz1[2].set("text", f.toString(f.FullPath));

		    		     		Sf4.loadSfzFile(f.toString(File.FullPath));

		    		     		      		LabelsSfz1[3].set("text", f.toString(f.FullPath));

		    		     		      		Sf5.loadSfzFile(f.toString(File.FullPath));


		    		     		      		       		LabelsSfz1[4].set("text", f.toString(f.FullPath));	
Sf6.loadSfzFile(f.toString(File.FullPath));

        		LabelsSfz1[5].set("text", f.toString(f.FullPath));

Sf7.loadSfzFile(f.toString(File.FullPath));

         		LabelsSfz1[6].set("text", f.toString(f.FullPath));

 
 Sf8.loadSfzFile(f.toString(File.FullPath));

           		LabelsSfz1[7].set("text", f.toString(f.FullPath));

SfLabel1.set("text", f.toString(f.NoExtension));
SfLabel2.set("text", f.toString(f.NoExtension));
SfLabel3.set("text", f.toString(f.NoExtension));
SfLabel4.set("text", f.toString(f.NoExtension));
SfLabel5.set("text", f.toString(f.NoExtension));
SfLabel6.set("text", f.toString(f.NoExtension));
SfLabel7.set("text", f.toString(f.NoExtension));
SfLabel8.set("text", f.toString(f.NoExtension));

		    		     		      		       			    		     		      		       		
		    				
	});	

}

};

Content.getComponent("SfzAll").setControlCallback(onSfzAllControl);

const var SfLabel1 = Content.getComponent("SfLabel1");
const var SfLabel2 = Content.getComponent("SfLabel2");
const var SfLabel3 = Content.getComponent("SfLabel3");
const var SfLabel4 = Content.getComponent("SfLabel4");
const var SfLabel5 = Content.getComponent("SfLabel5");
const var SfLabel6 = Content.getComponent("SfLabel6");
const var SfLabel7 = Content.getComponent("SfLabel7");
const var SfLabel8 = Content.getComponent("SfLabel8");





inline function onSfz1Control(component, value)
{
		if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

Sf1.loadSfzFile(f.toString(File.FullPath));
	
		LabelsSfz1[0].set("text", f.toString(f.FullPath));

		SfLabel1.set("text", f.toString(f.NoExtension));		
	});	

}

};

Content.getComponent("Sfz1").setControlCallback(onSfz1Control);

inline function onSfzLabelStore1Control(component, value)
{
	
Sf1.loadSfzFile(value);
};

Content.getComponent("SfzLabelStore1").setControlCallback(onSfzLabelStore1Control);


    
    inline function onSfz2Control(component, value)
    {
    		if (value)
    		{
    		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
    	{
    		
    
    		Sf2.loadSfzFile(f.toString(File.FullPath));
    	SfLabel2.set("text", f.toString(f.NoExtension));
    		LabelsSfz1[1].set("text", f.toString(f.FullPath));	

    	});	
    
    }
    
    };
    
    Content.getComponent("Sfz2").setControlCallback(onSfz2Control);
    
    inline function onSfzLabelStore2Control(component, value)
    {
    	
    Sf2.loadSfzFile(value);
    };
    
    Content.getComponent("SfzLabelStore2").setControlCallback(onSfzLabelStore2Control);
    
    
    
    inline function onSfz3Control(component, value)
     {
     		if (value)
     		{
     		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
     	{
     		
     
     		Sf3.loadSfzFile(f.toString(File.FullPath));
     		SfLabel3.set("text", f.toString(f.NoExtension));	
     		LabelsSfz1[2].set("text", f.toString(f.FullPath));

     	});	
     
     }
     
     };
     
     Content.getComponent("Sfz3").setControlCallback(onSfz3Control);
    	
  
  inline function onSfzLabelStore3Control(component, value)
  {
  	
  Sf3.loadSfzFile(value);
  };
  
  Content.getComponent("SfzLabelStore3").setControlCallback(onSfzLabelStore3Control);
  
  
  
  
  
     inline function onSfz4Control(component, value)
      {
      		if (value)
      		{
      		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
      	{
     		
    
      		Sf4.loadSfzFile(f.toString(File.FullPath));
      		SfLabel4.set("text", f.toString(f.NoExtension));	
      		LabelsSfz1[3].set("text", f.toString(f.FullPath));

      	});	
     
      }
     
      };
     
      Content.getComponent("Sfz4").setControlCallback(onSfz4Control);
      
      
      inline function onSfzLabelStore4Control(component, value)
      {
      	
      Sf4.loadSfzFile(value);
      };
      
      Content.getComponent("SfzLabelStore4").setControlCallback(onSfzLabelStore4Control);
      
     
    	 
      inline function onSfz5Control(component, value)
       {
       		if (value)
       		{
       		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
       	{
     		
     
       		Sf5.loadSfzFile(f.toString(File.FullPath));
       		SfLabel5.set("text", f.toString(f.NoExtension));
       		SfzLabel5.set("text", f.toString(f.NoExtension));	

       	});	
     
       }
     
       };
     
       Content.getComponent("Sfz5").setControlCallback(onSfz5Control);
       
       inline function onSfzLabelStore5Control(component, value)
       {
       	
       Sf5.loadSfzFile(value);
       };
       
       Content.getComponent("SfzLabelStore5").setControlCallback(onSfzLabelStore5Control);
       
       
    	  
       inline function onSfz6Control(component, value)
        {
        		if (value)
        		{
        		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
        	{
     		
     
        		Sf6.loadSfzFile(f.toString(File.FullPath));
        		SfLabel6.set("text", f.toString(f.NoExtension));
        		LabelsSfz1[5].set("text", f.toString(f.FullPath));

        	});	
     
        }
     
        };
     
        Content.getComponent("Sfz6").setControlCallback(onSfz6Control);
    	   
    	   inline function onSfzLabelStore6Control(component, value)
    	   {
    	   	
    	   Sf6.loadSfzFile(value);
    	   };
    	   
    	   Content.getComponent("SfzLabelStore6").setControlCallback(onSfzLabelStore6Control);
    	   
    	   
    	   
        inline function onSfz7Control(component, value)
         {
         		if (value)
         		{
         		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
         	{
     		
     
         		Sf7.loadSfzFile(f.toString(File.FullPath));
         		SfLabel7.set("text", f.toString(f.NoExtension));
         		LabelsSfz1[6].set("text", f.toString(f.FullPath));

         	});	
     
         }
     
         };
     
         Content.getComponent("Sfz7").setControlCallback(onSfz7Control);
         
           inline function onSfzLabelStore7Control(component, value)
           {
           	
           Sf7.loadSfzFile(value);
           };
           
           Content.getComponent("SfzLabelStore7").setControlCallback(onSfzLabelStore7Control);
           
           
    		
         inline function onSfz8Control(component, value)
          {
          		if (value)
          		{
          		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
          	{
     		
     
          		Sf8.loadSfzFile(f.toString(File.FullPath));
          		SfLabel8.set("text", f.toString(f.NoExtension));
          		LabelsSfz1[7].set("text", f.toString(f.FullPath));

          	});	
     
          }
     
          };
     
          Content.getComponent("Sfz8").setControlCallback(onSfz8Control);
          
          inline function onSfzLabelStore8Control(component, value)
          {
          	
          Sf8.loadSfzFile(value);
          };
          
          Content.getComponent("SfzLabelStore8").setControlCallback(onSfzLabelStore8Control);
 
const var root1 = Content.getComponent("root1");
const var root2 = Content.getComponent("root2");
const var root3 = Content.getComponent("root3");
const var root4 = Content.getComponent("root4");
const var root5 = Content.getComponent("root5");
const var root6 = Content.getComponent("root6");
const var root7 = Content.getComponent("root7");
const var root8 = Content.getComponent("root8");

    