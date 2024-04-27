Content.makeFrontInterface(1020, 800);

Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
//Settings.setZoomLevel(0.9);

//include("ExpansionWaves.js");
//include("waves.js");
//include("Sfz.js");
//include("Ui.js");


// PRESETS ///////////////////////
const var Presets = Content.getComponent("Presets");
var menuItems = [];

const var x = Engine.getUserPresetList(); 
for (i in x)
	menuItems.insert(-1, i);

menuItems = menuItems.join("\n");
Presets.set("items", menuItems);

inline function onPresetsControl(component, value)
{
	Engine.loadUserPreset(Presets.getItemText() + ".preset");
};

Content.getComponent("Presets").setControlCallback(onPresetsControl);

const var CLICK = Content.getComponent("CLICK");

CLICK.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
  });
  
//Xfade

const var Xfade1 = Synth.getEffect("Xfade1");
const var Xfade2 = Synth.getEffect("Xfade2");
const var Xfade3 = Synth.getEffect("Xfade3");
const var Xfade4 = Synth.getEffect("Xfade4");
const var Xfade5 = Synth.getEffect("Xfade5");
const var Xfade6 = Synth.getEffect("Xfade6");
const var Xfade7 = Synth.getEffect("Xfade7");
const var Xfade8 = Synth.getEffect("Xfade8");

inline function onXfsel2Control(component, value)
{
	Xfade1.setAttribute(Xfade1.XfModer, value);
	Xfade2.setAttribute(Xfade2.XfModer, value);
	Xfade3.setAttribute(Xfade3.XfModer, value);
	Xfade4.setAttribute(Xfade4.XfModer, value);
	Xfade5.setAttribute(Xfade5.XfModer, value);
	Xfade6.setAttribute(Xfade6.XfModer, value);
	Xfade7.setAttribute(Xfade7.XfModer, value);
	Xfade8.setAttribute(Xfade8.XfModer, value);
	
};

Content.getComponent("Xfsel2").setControlCallback(onXfsel2Control);


inline function onXFsliderControl(component, value)
{
	Xfade1.setAttribute(Xfade1.XF, value);
	Xfade2.setAttribute(Xfade2.XF, value);
	Xfade3.setAttribute(Xfade3.XF, value);
	Xfade4.setAttribute(Xfade4.XF, value);
	Xfade5.setAttribute(Xfade5.XF, value);
	Xfade6.setAttribute(Xfade6.XF, value);
	Xfade7.setAttribute(Xfade7.XF, value);
	Xfade8.setAttribute(Xfade8.XF, value);
};

Content.getComponent("XFslider").setControlCallback(onXFsliderControl);


inline function onSmoothControl(component, value)
{
	Xfade1.setAttribute(Xfade1.XFsmooth, value);
	Xfade2.setAttribute(Xfade2.XFsmooth, value);
	Xfade3.setAttribute(Xfade3.XFsmooth, value);
	Xfade4.setAttribute(Xfade4.XFsmooth, value);
	Xfade5.setAttribute(Xfade5.XFsmooth, value);
	Xfade6.setAttribute(Xfade6.XFsmooth, value);
	Xfade7.setAttribute(Xfade7.XFsmooth, value);
	Xfade8.setAttribute(Xfade8.XFsmooth, value);
};

Content.getComponent("Smooth").setControlCallback(onSmoothControl);


inline function onXfModControl(component, value)
{
	Xfade1.setAttribute(Xfade1.XfMod, value);
	Xfade2.setAttribute(Xfade2.XfMod, value);
	Xfade3.setAttribute(Xfade3.XfMod, value);
	Xfade4.setAttribute(Xfade4.XfMod, value);
	Xfade5.setAttribute(Xfade5.XfMod, value);
	Xfade6.setAttribute(Xfade6.XfMod, value);
	Xfade7.setAttribute(Xfade7.XfMod, value);
	Xfade8.setAttribute(Xfade8.XfMod, value);
};

Content.getComponent("XfMod").setControlCallback(onXfModControl);


inline function onXfselControl(component, value)
{
	Xfade1.setAttribute(Xfade1.XfModSrc, value);
	Xfade2.setAttribute(Xfade2.XfModSrc, value);
	Xfade3.setAttribute(Xfade3.XfModSrc, value);
	Xfade4.setAttribute(Xfade4.XfModSrc, value);
	Xfade5.setAttribute(Xfade5.XfModSrc, value);
	Xfade6.setAttribute(Xfade6.XfModSrc, value);
	Xfade7.setAttribute(Xfade7.XfModSrc, value);
	Xfade8.setAttribute(Xfade8.XfModSrc, value);
};

Content.getComponent("Xfsel").setControlCallback(onXfselControl);


inline function onXfAtControl(component, value)
{
	Xfade1.setAttribute(Xfade1.aft, value);
	Xfade2.setAttribute(Xfade2.aft, value);
	Xfade3.setAttribute(Xfade3.aft, value);
	Xfade4.setAttribute(Xfade4.aft, value);
	Xfade5.setAttribute(Xfade5.aft, value);
	Xfade6.setAttribute(Xfade6.aft, value);
	Xfade7.setAttribute(Xfade7.aft, value);
	Xfade8.setAttribute(Xfade8.aft, value);
};

Content.getComponent("XfAt").setControlCallback(onXfAtControl);


inline function onXfMwControl(component, value)
{
	Xfade1.setAttribute(Xfade1.mw, value);
	Xfade2.setAttribute(Xfade2.mw, value);
	Xfade3.setAttribute(Xfade3.mw, value);
	Xfade4.setAttribute(Xfade4.mw, value);
	Xfade5.setAttribute(Xfade5.mw, value);
	Xfade6.setAttribute(Xfade6.mw, value);
	Xfade7.setAttribute(Xfade7.mw, value);
	Xfade8.setAttribute(Xfade8.mw, value);
};

Content.getComponent("XfMw").setControlCallback(onXfMwControl);


inline function onXfVelControl(component, value)
{
	Xfade1.setAttribute(Xfade1.vel, value);
	Xfade2.setAttribute(Xfade2.vel, value);
	Xfade3.setAttribute(Xfade3.vel, value);
	Xfade4.setAttribute(Xfade4.vel, value);
	Xfade5.setAttribute(Xfade5.vel, value);
	Xfade6.setAttribute(Xfade6.vel, value);
	Xfade7.setAttribute(Xfade7.vel, value);
	Xfade8.setAttribute(Xfade8.vel, value);
};

Content.getComponent("XfVel").setControlCallback(onXfVelControl);


inline function onXfTrkControl(component, value)
{
	Xfade1.setAttribute(Xfade1.trk, value);
	Xfade2.setAttribute(Xfade2.trk, value);
	Xfade3.setAttribute(Xfade3.trk, value);
	Xfade4.setAttribute(Xfade4.trk, value);
	Xfade5.setAttribute(Xfade5.trk, value);
	Xfade6.setAttribute(Xfade6.trk, value);
	Xfade7.setAttribute(Xfade7.trk, value);
	Xfade8.setAttribute(Xfade8.trk, value);
};

Content.getComponent("XfTrk").setControlCallback(onXfTrkControl);



inline function onXfTempoControl(component, value)
{
	Xfade1.setAttribute(Xfade1.tempo, value);
	Xfade2.setAttribute(Xfade2.tempo, value);
	Xfade3.setAttribute(Xfade3.tempo, value);
	Xfade4.setAttribute(Xfade4.tempo, value);
	Xfade5.setAttribute(Xfade5.tempo, value);
	Xfade6.setAttribute(Xfade6.tempo, value);
	Xfade7.setAttribute(Xfade7.tempo, value);
	Xfade8.setAttribute(Xfade8.tempo, value);
};

Content.getComponent("XfTempo").setControlCallback(onXfTempoControl);


inline function onXfDivControl(component, value)
{
	Xfade1.setAttribute(Xfade1.mul, value);
	Xfade2.setAttribute(Xfade2.mul, value);
	Xfade3.setAttribute(Xfade3.mul, value);
	Xfade4.setAttribute(Xfade4.mul, value);
	Xfade5.setAttribute(Xfade5.mul, value);
	Xfade6.setAttribute(Xfade6.mul, value);
	Xfade7.setAttribute(Xfade7.mul, value);
	Xfade8.setAttribute(Xfade8.mul, value);
};

Content.getComponent("XfDiv").setControlCallback(onXfDivControl);


inline function onXfTrigModeControl(component, value)
{
	if(value == 0)
	{
		
	Xfade1.setAttribute(Xfade1.one, 0);
	Xfade2.setAttribute(Xfade2.one, 0);
	Xfade3.setAttribute(Xfade3.one, 0);
	Xfade4.setAttribute(Xfade4.one, 0);
	Xfade5.setAttribute(Xfade5.one, 0);
	Xfade6.setAttribute(Xfade6.one, 0);
	Xfade7.setAttribute(Xfade7.one, 0);
	Xfade8.setAttribute(Xfade8.one, 0);
	LoopLabel1.showControl(0);  
	     OneShtLabel1.showControl(1);   
	     }
	     
	     	if(value == 1)
	     {
	Xfade1.setAttribute(Xfade1.one, 1);
	Xfade2.setAttribute(Xfade2.one, 1);
	Xfade3.setAttribute(Xfade3.one, 1);
	Xfade4.setAttribute(Xfade4.one, 1);
	Xfade5.setAttribute(Xfade5.one, 1);
	Xfade6.setAttribute(Xfade6.one, 1);
	Xfade7.setAttribute(Xfade7.one, 1);
	Xfade8.setAttribute(Xfade8.one, 1);
	LoopLabel1.showControl(1);  
	     OneShtLabel1.showControl(0);
	     }   

};

Content.getComponent("XfTrigMode").setControlCallback(onXfTrigModeControl);

const var Xfsync = Content.getComponent("Xfsync");
const var XfTempo = Content.getComponent("XfTempo");
const var XfTempo2 = Content.getComponent("XfTempo2");


inline function onXfsyncControl(component, value)
{
	if(value == 0)
	{
	
	Xfade1.setAttribute(Xfade1.sync, 1);
	Xfade2.setAttribute(Xfade2.sync, 1);
	Xfade3.setAttribute(Xfade3.sync, 1);
	Xfade4.setAttribute(Xfade4.sync, 1);
	Xfade5.setAttribute(Xfade5.sync, 1);
	Xfade6.setAttribute(Xfade6.sync, 1);
	Xfade7.setAttribute(Xfade7.sync, 1);
	Xfade8.setAttribute(Xfade8.sync, 1);
	XfTempo.showControl(0);  
	XfTempo2.showControl(1);   
	synclabel2.showControl(0);  
	freelabel2.showControl(1);   
	 
	 }
	 
	 if(value == 1)
	 	{
	Xfade1.setAttribute(Xfade1.sync, 0);
	Xfade2.setAttribute(Xfade2.sync, 0);
	Xfade3.setAttribute(Xfade3.sync, 0);
	Xfade4.setAttribute(Xfade4.sync, 0);
	Xfade5.setAttribute(Xfade5.sync, 0);
	Xfade6.setAttribute(Xfade6.sync, 0);
	Xfade7.setAttribute(Xfade7.sync, 0);
	Xfade8.setAttribute(Xfade8.sync, 0);
	XfTempo.showControl(1);  
	XfTempo2.showControl(0);   
	synclabel2.showControl(1);  
	freelabel2.showControl(0); 
	}

	 
};

Content.getComponent("Xfsync").setControlCallback(onXfsyncControl);

//harmonic/pitch

const var harmscaleA1 = Synth.getModulator("harmscaleA1");
const var harmscaleA2 = Synth.getModulator("harmscaleA2");
const var harmscaleA3 = Synth.getModulator("harmscaleA3");
const var harmscaleA4 = Synth.getModulator("harmscaleA4");
const var harmscaleA5 = Synth.getModulator("harmscaleA5");
const var harmscaleA6 = Synth.getModulator("harmscaleA6");
const var harmscaleA7 = Synth.getModulator("harmscaleA7");
const var harmscaleA8 = Synth.getModulator("harmscaleA8");



inline function onPitchModeControl(component, value)
{
	harmscaleA1.setAttribute(harmscaleA1.Mode, value);
	harmscaleA2.setAttribute(harmscaleA2.Mode, value);
	harmscaleA3.setAttribute(harmscaleA3.Mode, value);
	harmscaleA4.setAttribute(harmscaleA4.Mode, value);
	harmscaleA5.setAttribute(harmscaleA5.Mode, value);
	harmscaleA6.setAttribute(harmscaleA6.Mode, value);
	harmscaleA7.setAttribute(harmscaleA7.Mode, value);
	harmscaleA8.setAttribute(harmscaleA8.Mode, value);

};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);


//fm osc/group

const var Group1 = Synth.getChildSynth("Group1");
const var Group2 = Synth.getChildSynth("Group2");
const var Group3 = Synth.getChildSynth("Group3");
const var Group4 = Synth.getChildSynth("Group4");
const var Group5 = Synth.getChildSynth("Group5");
const var Group6 = Synth.getChildSynth("Group6");
const var Group7 = Synth.getChildSynth("Group7");
const var Group8 = Synth.getChildSynth("Group8");






inline function onOsc2PowerControl(component, value)
{
	SamplerB1.setBypassed(1 - value);
	SamplerB2.setBypassed(1 - value);
	SamplerB3.setBypassed(1 - value);
	SamplerB4.setBypassed(1 - value);
	SamplerB5.setBypassed(1 - value);
	SamplerB6.setBypassed(1 - value);
	SamplerB7.setBypassed(1 - value);
	SamplerB8.setBypassed(1 - value);
	Group1.setAttribute(4, 0 - value);
	Group2.setAttribute(4, 0 - value);
	Group3.setAttribute(4, 0 - value);
	Group4.setAttribute(4, 0 - value);
	Group5.setAttribute(4, 0 - value);
	Group6.setAttribute(4, 0 - value);
	Group7.setAttribute(4, 0 - value);
	Group8.setAttribute(4, 0 - value);
	
	
};

Content.getComponent("Osc2Power").setControlCallback(onOsc2PowerControl);



inline function onFmOnControl(component, value)
{
	Group1.setAttribute(4, value);
	Group2.setAttribute(4, value);
	Group3.setAttribute(4, value);
	Group4.setAttribute(4, value);
	Group5.setAttribute(4, value);
	Group6.setAttribute(4, value);
	Group7.setAttribute(4, value);
	Group8.setAttribute(4, value);
	Group1.setAttribute(5, value);
	Group2.setAttribute(5, value);
	Group3.setAttribute(5, value);
	Group4.setAttribute(5, value);
	Group5.setAttribute(5, value);
	Group6.setAttribute(5, value);
	Group7.setAttribute(5, value);
	Group8.setAttribute(5, value);
	Group1.setAttribute(6, 3 - value);
	Group2.setAttribute(6, 3 - value);
	Group3.setAttribute(6, 3 - value);
	Group4.setAttribute(6, 3 - value);
	Group5.setAttribute(6, 3 - value);
	Group6.setAttribute(6, 3 - value);
	Group7.setAttribute(6, 3 - value);
	Group8.setAttribute(6, 3 - value);
};

Content.getComponent("FmOn").setControlCallback(onFmOnControl);




const var HarmB1 = Synth.getModulator("HarmB1");
const var HarmB2 = Synth.getModulator("HarmB2");
const var HarmB3 = Synth.getModulator("HarmB3");
const var HarmB4 = Synth.getModulator("HarmB4");
const var HarmB5 = Synth.getModulator("HarmB5");
const var HarmB6 = Synth.getModulator("HarmB6");
const var HarmB7 = Synth.getModulator("HarmB7");
const var HarmB8 = Synth.getModulator("HarmB8");


inline function onPitchMode1Control(component, value)
{
	HarmB1.setAttribute(HarmB1.Mode, value);
	HarmB2.setAttribute(HarmB2.Mode, value);
	HarmB3.setAttribute(HarmB3.Mode, value);
	HarmB4.setAttribute(HarmB4.Mode, value);
	HarmB5.setAttribute(HarmB5.Mode, value);
	HarmB6.setAttribute(HarmB6.Mode, value);
	HarmB7.setAttribute(HarmB7.Mode, value);
	HarmB8.setAttribute(HarmB8.Mode, value);
};

Content.getComponent("PitchMode1").setControlCallback(onPitchMode1Control);

const var PolyshapeFX1 = Synth.getEffect("Polyshape FX1");
const var PolyshapeFX2 = Synth.getEffect("Polyshape FX2");
const var PolyshapeFX3 = Synth.getEffect("Polyshape FX3");
const var PolyshapeFX4 = Synth.getEffect("Polyshape FX4");
const var PolyshapeFX5 = Synth.getEffect("Polyshape FX5");
const var PolyshapeFX6 = Synth.getEffect("Polyshape FX6");
const var PolyshapeFX7 = Synth.getEffect("Polyshape FX7");
const var PolyshapeFX8 = Synth.getEffect("Polyshape FX8");


inline function onOsc2DriveControl(component, value)
{
		PolyshapeFX1.setAttribute(0, value);
		PolyshapeFX2.setAttribute(0, value);
		PolyshapeFX3.setAttribute(0, value);
		PolyshapeFX4.setAttribute(0, value);
		PolyshapeFX5.setAttribute(0, value);
		PolyshapeFX6.setAttribute(0, value);
		PolyshapeFX7.setAttribute(0, value);
		PolyshapeFX8.setAttribute(0, value);
		
};

Content.getComponent("Osc2Drive").setControlCallback(onOsc2DriveControl);


//Filter

const var Filter1 = Synth.getEffect("Filter1");
const var Filter2 = Synth.getEffect("Filter2");
const var Filter3 = Synth.getEffect("Filter3");
const var Filter4 = Synth.getEffect("Filter4");
const var Filter5 = Synth.getEffect("Filter5");
const var Filter6 = Synth.getEffect("Filter6");
const var Filter7 = Synth.getEffect("Filter7");
const var Filter8 = Synth.getEffect("Filter8");

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

const var Samb1 = Synth.getSampler("SamplerB1");
const var Samb2 = Synth.getSampler("SamplerB2");
const var Samb3 = Synth.getSampler("SamplerB3");
const var Samb4 = Synth.getSampler("SamplerB4");
const var Samb5 = Synth.getSampler("SamplerB5");
const var Samb6 = Synth.getSampler("SamplerB6");
const var Samb7 = Synth.getSampler("SamplerB7");
const var Samb8 = Synth.getSampler("SamplerB8");

inline function onBankA1Control(component, value)
{

   SamplerA1.loadSampleMap(sampleMaps[value-1]);
  
  	Sample1.set("text",BankA1.get("items").split("\n")[value-1]);
  	
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
  
  Sample3.set("text",BankA3.get("items").split("\n")[value-1]);

};

Content.getComponent("BankA3").setControlCallback(onBankA3Control);

inline function onBankA4Control(component, value)
{

   SamplerA4.loadSampleMap(sampleMaps[value-1]);
 
    
    Sample4.set("text",BankA4.get("items").split("\n")[value-1]);
  

};

Content.getComponent("BankA4").setControlCallback(onBankA4Control);

inline function onBankA5Control(component, value)
{

   SamplerA5.loadSampleMap(sampleMaps[value-1]);
 
  
	Sample5.set("text",BankA5.get("items").split("\n")[value-1]);
};

Content.getComponent("BankA5").setControlCallback(onBankA5Control);

inline function onBankA6Control(component, value)
{

   SamplerA6.loadSampleMap(sampleMaps[value-1]);
 
	Sample6.set("text",BankA6.get("items").split("\n")[value-1]);
};

Content.getComponent("BankA6").setControlCallback(onBankA6Control);

inline function onBankA7Control(component, value)
{

   SamplerA7.loadSampleMap(sampleMaps[value-1]);
  
    Sample7.set("text",BankA7.get("items").split("\n")[value-1]);
  

};

Content.getComponent("BankA7").setControlCallback(onBankA7Control);

inline function onBankA8Control(component, value)
{

   SamplerA8.loadSampleMap(sampleMaps[value-1]);
 
  Sample8.set("text",BankA8.get("items").split("\n")[value-1]);

};

Content.getComponent("BankA8").setControlCallback(onBankA8Control);

inline function onBankA9Control(component, value)
{

    Samb1.loadSampleMap(sampleMaps[value-1]);
    Samb2.loadSampleMap(sampleMaps[value-1]);
    Samb3.loadSampleMap(sampleMaps[value-1]);
    Samb4.loadSampleMap(sampleMaps[value-1]);
    Samb5.loadSampleMap(sampleMaps[value-1]);
    Samb6.loadSampleMap(sampleMaps[value-1]);
    Samb7.loadSampleMap(sampleMaps[value-1]);
    Samb8.loadSampleMap(sampleMaps[value-1]);
  
Sample9.set("text",BankA9.get("items").split("\n")[value-1]);

};

Content.getComponent("BankA9").setControlCallback(onBankA9Control);




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
 