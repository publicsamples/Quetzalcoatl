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

const var Xfsync = Content.getComponent("Xfsync");
const var XfTempo = Content.getComponent("XfTempo");
const var XfTempo2 = Content.getComponent("XfTempo2");

const var Xfader = [];

                     
 const var Xfader2 = [Synth.getModulator("Xf1"),
                     Synth.getModulator("Xf2"),
                     Synth.getModulator("Xf3"),
                     Synth.getModulator("Xf4"),
                     Synth.getModulator("Xf5"),
                     Synth.getModulator("Xf6"),
                     Synth.getModulator("Xf7"),                     
                     Synth.getModulator("Xf8")];
                                          


inline function onXfsel2Control(component, value)
{
//	Xfader.setAttribute(Xfade1.Xfader, value);
	Xfader2.setAttribute(Xfader2.mode_x1, value);
	
};

Content.getComponent("Xfsel2").setControlCallback(onXfsel2Control);




inline function onSmoothControl(component, value)
{
	Xfader.setAttribute(Xfader.XFsmooth, value);
	Xfader2.setAttribute(Xfader2.smooth_x1, value);

};

Content.getComponent("Smooth").setControlCallback(onSmoothControl);


inline function onXfModControl(component, value)
{
	Xfader.setAttribute(Xfader.XfMod, value);
	Xfader2.setAttribute(Xfader2.ModAmnt, value);

};

Content.getComponent("XfMod").setControlCallback(onXfModControl);


inline function onXfselControl(component, value)
{
	
	if(value == 1)
	{
	
	Xfader.setAttribute(Xfader.XfModSrc, 0);
	Xfader2.setAttribute(Xfader2.Src, 0);
	for(s in Xfader)
	       s.setBypassed(1);
	for(s in Xfader2)
	       s.setBypassed(0);
	}
	
	if(value == 2)
		{
	
		Xfader.setAttribute(Xfader.XfModSrc, 0);
		Xfader2.setAttribute(Xfader2.Src, 0);
		for(s in Xfader)
		       s.setBypassed(0);
		for(s in Xfader2)
		       s.setBypassed(1);
		}


};

Content.getComponent("Xfsel").setControlCallback(onXfselControl);


inline function onXfAtControl(component, value)
{
	Xfader1.setAttribute(Xfader1.aft, value);

};

Content.getComponent("XfAt").setControlCallback(onXfAtControl);


inline function onXfMwControl(component, value)
{
	Xfader1.setAttribute(Xfader1.mw, value);
	
};

Content.getComponent("XfMw").setControlCallback(onXfMwControl);


inline function onXfVelControl(component, value)
{
	Xfader1.setAttribute(Xfader1.vel, value);

};

Content.getComponent("XfVel").setControlCallback(onXfVelControl);


inline function onXfTrkControl(component, value)
{
	Xfader1.setAttribute(Xfader1.trk, value);

};

Content.getComponent("XfTrk").setControlCallback(onXfTrkControl);



inline function onXfTempoControl(component, value)
{
	Xfader1.setAttribute(Xfader1.tempo, value);
}

Content.getComponent("XfTempo").setControlCallback(onXfTempoControl);


inline function onXfDivControl(component, value)
{
	Xfader1.setAttribute(Xfader1.mul, value);

};

Content.getComponent("XfDiv").setControlCallback(onXfDivControl);


inline function onXfTrigModeControl(component, value)
{
	if(value == 0)
	{
		
	Xfader1.setAttribute(Xfader1.one, 0);

	LoopLabel1.showControl(0);  
	     OneShtLabel1.showControl(1);   
	     }
	     
	     	if(value == 1)
	     {
	Xfader1.setAttribute(Xfader1.one, 1);

	LoopLabel1.showControl(1);  
	     OneShtLabel1.showControl(0);
	     }   

};

Content.getComponent("XfTrigMode").setControlCallback(onXfTrigModeControl);




inline function onXfsyncControl(component, value)
{
	if(value == 0)
	{
	
	Xfader1.setAttribute(Xfader1.sync, 1);

	XfTempo.showControl(0);  
	XfTempo2.showControl(1);   
	synclabel2.showControl(0);  
	freelabel2.showControl(1);   
	 
	 }
	 
	 if(value == 1)
	 	{
	Xfader1.setAttribute(Xfader1.sync, 0);

	XfTempo.showControl(1);  
	XfTempo2.showControl(0);   
	synclabel2.showControl(1);  
	freelabel2.showControl(0); 
	}

	 
};

Content.getComponent("Xfsync").setControlCallback(onXfsyncControl);

//harmonic/pitch

const var harmscaleA = [Synth.getModulator("harmscaleA1"),
						Synth.getModulator("harmscaleA2"),
						Synth.getModulator("harmscaleA3"),
						Synth.getModulator("harmscaleA4"),
						Synth.getModulator("harmscaleA5"),
						Synth.getModulator("harmscaleA6"),
						Synth.getModulator("harmscaleA7"),
						Synth.getModulator("harmscaleA8"),
						Synth.getModulator("harmscaleLPA1"),
						Synth.getModulator("harmscaleLPA2"),
						Synth.getModulator("harmscaleLPA3"),
						Synth.getModulator("harmscaleLPA4"),
						Synth.getModulator("harmscaleLPA5"),
						Synth.getModulator("harmscaleLPA6"),
						Synth.getModulator("harmscaleLPA7"),
						Synth.getModulator("harmscaleLPA8")];



inline function onPitchModeControl(component, value)
{
	harmscaleA.setAttribute(harmscaleA.Mode, value);

};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);


//fm osc/group



const var Groups = [Synth.getChildSynth("Group1"), Synth.getChildSynth("Group2"), Synth.getChildSynth("Group3"), Synth.getChildSynth("Group4"),Synth.getChildSynth("Group5"), Synth.getChildSynth("Group6"),  Synth.getChildSynth("Group7"), Synth.getChildSynth("Group8"), Synth.getChildSynth("LoopGroup1"), Synth.getChildSynth("LoopGroup2"), Synth.getChildSynth("LoopGroup3"), Synth.getChildSynth("LoopGroup4"), Synth.getChildSynth("LoopGroup5"), Synth.getChildSynth("LoopGroup6"), Synth.getChildSynth("LoopGroup7"), Synth.getChildSynth("LoopGroup8"), Synth.getChildSynth("WtGroup1"), Synth.getChildSynth("WtGroup2"), Synth.getChildSynth("WtGroup3"),Synth.getChildSynth("WtGroup4"),Synth.getChildSynth("WtGroup5"),Synth.getChildSynth("WtGroup6"),Synth.getChildSynth("WtGroup7"),Synth.getChildSynth("WtGroup8")];

const var Osc2 = [Synth.getChildSynth("SamplerB1"),
				  Synth.getChildSynth("SamplerB2"),
				  Synth.getChildSynth("SamplerB3"),
				  Synth.getChildSynth("SamplerB4"),
				  Synth.getChildSynth("SamplerB5"),
				  Synth.getChildSynth("SamplerB6"),
				  Synth.getChildSynth("SamplerB7"),
				  Synth.getChildSynth("SamplerB8"),
				  Synth.getChildSynth("LoopB1"),
				  Synth.getChildSynth("LoopB2"),
				  Synth.getChildSynth("LoopB3"),
				  Synth.getChildSynth("LoopB4"),
				  Synth.getChildSynth("LoopB5"),
				  Synth.getChildSynth("LoopB6"),
				  Synth.getChildSynth("LoopB7"),
				  Synth.getChildSynth("LoopB8"),
				  Synth.getChildSynth("WtB1"),
				  Synth.getChildSynth("WtB2"),
				  Synth.getChildSynth("WtB3"),
				  Synth.getChildSynth("WtB4"),
				  Synth.getChildSynth("WtB5"),
				  Synth.getChildSynth("WtB6"),
				  Synth.getChildSynth("WtB7"),
				  Synth.getChildSynth("WtB8")];




inline function onOsc2PowerControl(component, value)
{
	Osc2.setBypassed(1 - value);

	Groups.setAttribute(4, 0 - value);
	
	
};

Content.getComponent("Osc2Power").setControlCallback(onOsc2PowerControl);



inline function onFmOnControl(component, value)
{
	Groups.setAttribute(4, value);
	Groups.setAttribute(5, 0);
	Groups.setAttribute(6, 3 - value);

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



const var SampleGroups = [Synth.getChildSynth("Group1"),
                     Synth.getChildSynth("Group2"),
                     Synth.getChildSynth("Group3"),
                     Synth.getChildSynth("Group4"),
                     Synth.getChildSynth("Group5"),
                     Synth.getChildSynth("Group6"),
                     Synth.getChildSynth("Group7"),
                     Synth.getChildSynth("Group8")];
                     
                     
const var SampleComp = [ Content.getComponent("SampleWave1"),
                     Content.getComponent("SampleWave2"),
                     Content.getComponent("SampleWave3"),
                     Content.getComponent("SampleWave4"),
                     Content.getComponent("SampleWave5"),
                     Content.getComponent("SampleWave6"),
                     Content.getComponent("SampleWave7"),
                     Content.getComponent("SampleWave8"),
                     Content.getComponent("SampleWave9"),
                     Content.getComponent("Waves1"),
                     Content.getComponent("Waves2"),
                     Content.getComponent("Waves3"),
                     Content.getComponent("Waves4"),
                     Content.getComponent("Waves5"),
                     Content.getComponent("Waves6"),
                     Content.getComponent("Waves7"),
                     Content.getComponent("Waves8"),
                     Content.getComponent("Waves9")];
                     
                     
                     
const var WtGroups = [Synth.getChildSynth("WtGroup1"),
                     Synth.getChildSynth("WtGroup2"),
                     Synth.getChildSynth("WtGroup3"),
                     Synth.getChildSynth("WtGroup4"),
                     Synth.getChildSynth("WtGroup5"),
                     Synth.getChildSynth("WtGroup6"),
                     Synth.getChildSynth("WtGroup7"),
                     Synth.getChildSynth("WtGroup8")];
                     
const var WtComp = [Content.getComponent("Wt1"),
                     Content.getComponent("Wt2"),
                     Content.getComponent("Wt3"),
                     Content.getComponent("Wt4"),
                     Content.getComponent("Wt5"),
                     Content.getComponent("Wt6"),
                     Content.getComponent("Wt7"),
                     Content.getComponent("Wt8"),
                     Content.getComponent("Wt9"),
                     Content.getComponent("TableView1"),
                     Content.getComponent("TableView2"),
                     Content.getComponent("TableView3"),
                     Content.getComponent("TableView4"),
                     Content.getComponent("TableView5"),
                     Content.getComponent("TableView6"),
                     Content.getComponent("TableView7"),
                     Content.getComponent("TableView8"),
                     Content.getComponent("TableView9")];
                     
                     
const var LoopComp = [Content.getComponent("UserWave1"),
                     Content.getComponent("UserWave2"),
                     Content.getComponent("UserWave3"),
                     Content.getComponent("UserWave4"),
                     Content.getComponent("UserWave5"),
                     Content.getComponent("UserWave6"),
                     Content.getComponent("UserWave7"),
                     Content.getComponent("UserWave8"),
                     Content.getComponent("UserWave9"),
                     Content.getComponent("LpControls1"),
                     Content.getComponent("LpControls1"),
                     Content.getComponent("LpControls2"),
                     Content.getComponent("LpControls3"),
                     Content.getComponent("LpControls4"),
                     Content.getComponent("LpControls5"),
                     Content.getComponent("LpControls6"),
                     Content.getComponent("LpControls7"),
                     Content.getComponent("LpControls8"),
                     Content.getComponent("LpControls9")];

const var LoopGroups = [Synth.getChildSynth("LoopGroup1"),
                     Synth.getChildSynth("LoopGroup2"),
                     Synth.getChildSynth("LoopGroup3"),
                     Synth.getChildSynth("LoopGroup4"),
                     Synth.getChildSynth("LoopGroup5"),
                     Synth.getChildSynth("LoopGroup6"),
                     Synth.getChildSynth("LoopGroup7"),
                     Synth.getChildSynth("LoopGroup8")];


inline function onSampleMode1Control(component, value)
{
	if(value == 1)
	{
	for(s in SampleGroups)
	       s.setBypassed(0);
	for(s in SampleComp)
		       s.showControl(1);
	for(s in LoopGroups)
       s.setBypassed(1);
	for(s in LoopComp)
	        s.showControl(0);    
	for(s in WtComp)
		    s.showControl(0);    
    for(s in WtGroups)
    		    s.setBypassed(1);       
	}
	
	if(value == 2)
		{	
	
	for(s in SampleGroups)
	       s.setBypassed(1);
	for(s in SampleComp)
		       s.showControl(0);
	for(s in LoopGroups)
       s.setBypassed(0);
	for(s in LoopComp)
	        s.showControl(1);    
	for(s in WtComp)
		    s.showControl(0);    
    for(s in WtGroups)
    		    s.setBypassed(1);           
		}
		
    if(value == 3)
    	{	
    
   	for(s in SampleGroups)
	       s.setBypassed(1);
	for(s in SampleComp)
		       s.showControl(0);
	for(s in LoopGroups)
       s.setBypassed(1);
	for(s in LoopComp)
	        s.showControl(0);    
	for(s in WtComp)
		    s.showControl(1);    
    for(s in WtGroups)
    		    s.setBypassed(0);               
    	}

};

Content.getComponent("SampleMode1").setControlCallback(onSampleMode1Control);


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
 