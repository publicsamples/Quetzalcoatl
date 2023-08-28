Content.makeFrontInterface(900, 780);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat-Medium");

//links

const var ulp = Content.getComponent("ulp");


ulp.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/lybce");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
});


const var modpos = Content.getComponent("modpos");


reg index = 1; // index of the filmstrip 
reg total_frames = 125; // total frames in the filmstrip
reg frame_height = 650; // the height(y) of each frame



const var Mode1 = Content.getComponent("Mode1");
const var XF1 = Content.getComponent("XF1");
const var Harmonic1 = Content.getComponent("Harmonic1");
const var FM = Content.getComponent("FM");


inline function onMode1Control(component, value)
{
OSC1.setAttribute(OSC1.PlayBackMode, value);

if(value == 1)
	{
		XF1.fadeComponent(1, 500);
  		Harmonic1.fadeComponent(0, 500);
		FM.fadeComponent(0, 500);
	}
	else if(value == 2)
	{
			XF1.fadeComponent(0, 500);
  		Harmonic1.fadeComponent(1, 500);
		FM.fadeComponent(0, 500);
		}
	
	else if(value == 3)
	{
			XF1.fadeComponent(0, 500);
  		Harmonic1.fadeComponent(0, 500);
		FM.fadeComponent(1, 500);
		}
			

};

Content.getComponent("Mode1").setControlCallback(onMode1Control);





//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
 
    g.setFont("Montserrat-Medium", 12.0);
   
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});



include("Waves.js");

var Maps = [];
Maps.push(CS30);
Maps.push(EM25);
Maps.push(Misc);
Maps.push(Shape);
Maps.push(Square);
Maps.push(Sys101);

var SMAPS = ["CS30", "EM25", "Misc", "Shape", "Square", "Sys101"];

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat-Medium");


const var OSC1 = Synth.getChildSynth("OSC1");



const var Samples = Synth.getAudioSampleProcessor("OSC1");


const slot = Samples.getAudioFile(0);
const slot1 = Samples.getAudioFile(1);
const slot2 = Samples.getAudioFile(2);
const slot3 = Samples.getAudioFile(3);
const slot4 = Samples.getAudioFile(4);
const slot5 = Samples.getAudioFile(5);
const slot6 = Samples.getAudioFile(6);
const slot7  = Samples.getAudioFile(7);
const slot8 = Samples.getAudioFile(8);
const slot9 = Samples.getAudioFile(9);
const slot10 = Samples.getAudioFile(10);
const slot11 = Samples.getAudioFile(11);
const slot12 = Samples.getAudioFile(12);
const slot13 = Samples.getAudioFile(13);
const slot14 = Samples.getAudioFile(14);
const slot15  = Samples.getAudioFile(15);

// BANKS A
const var BankA1 = Content.getComponent("BankA1");
const var WAVELABELA1 = Content.getComponent("WAVELABELA1");
inline function onBankA1Control(component, value)
{
	WAVELABELA1.set("text",BankA1.get("items").split("\n")[value-1]);
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA1").setControlCallback(onBankA1Control);

const var BankA2 = Content.getComponent("BankA2");
const var WAVELABELA2 = Content.getComponent("WAVELABELA2");
inline function onBankA2Control(component, value)
{
	WAVELABELA2.set("text",BankA2.get("items").split("\n")[value-1]);
	slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA2").setControlCallback(onBankA2Control);

const var BankA3 = Content.getComponent("BankA3");
const var WAVELABELA3 = Content.getComponent("WAVELABELA3");
inline function onBankA3Control(component, value)
{
	WAVELABELA3.set("text",BankA3.get("items").split("\n")[value-1]);
	slot2.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA3").setControlCallback(onBankA3Control);

const var BankA4 = Content.getComponent("BankA4");
const var WAVELABELA4 = Content.getComponent("WAVELABELA4");
inline function onBankA4Control(component, value)
{
	WAVELABELA4.set("text",BankA4.get("items").split("\n")[value-1]);
	slot3.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA4").setControlCallback(onBankA4Control);

const var BankA5 = Content.getComponent("BankA5");
const var WAVELABELA5 = Content.getComponent("WAVELABELA5");
inline function onBankA5Control(component, value)
{
	WAVELABELA5.set("text",BankA5.get("items").split("\n")[value-1]);
	slot4.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA5").setControlCallback(onBankA5Control);

const var BankA6 = Content.getComponent("BankA6");
const var WAVELABELA6 = Content.getComponent("WAVELABELA6");
inline function onBankA6Control(component, value)
{
	WAVELABELA6.set("text",BankA6.get("items").split("\n")[value-1]);
	slot5.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA6").setControlCallback(onBankA6Control);

const var BankA7 = Content.getComponent("BankA7");
const var WAVELABELA7 = Content.getComponent("WAVELABELA7");
inline function onBankA7Control(component, value)
{
	WAVELABELA7.set("text",BankA7.get("items").split("\n")[value-1]);
	slot6.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA7").setControlCallback(onBankA7Control);

const var BankA8 = Content.getComponent("BankA8");
const var WAVELABELA8 = Content.getComponent("WAVELABELA8");
inline function onBankA8Control(component, value)
{
	WAVELABELA8.set("text",BankA8.get("items").split("\n")[value-1]);
	slot7.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankA8").setControlCallback(onBankA8Control);

const var Categories = Content.getComponent("Categories");


inline function onCategoriesControl(component, value)
{
	BankA1.set("items", [].join("\n")); 
	BankA1.set("items", Maps[value-1].join("\n"));
	BankA1.setValue(1);
	BankA2.set("items", [].join("\n")); 
	BankA2.set("items", Maps[value-1].join("\n"));
	BankA2.setValue(1);
	BankA3.set("items", [].join("\n")); 
	BankA3.set("items", Maps[value-1].join("\n"));
	BankA3.setValue(1);
	BankA4.set("items", [].join("\n")); 
	BankA4.set("items", Maps[value-1].join("\n"));
	BankA4.setValue(1);
	BankA5.set("items", [].join("\n")); 
	BankA5.set("items", Maps[value-1].join("\n"));
	BankA5.setValue(1);
	BankA6.set("items", [].join("\n")); 
	BankA6.set("items", Maps[value-1].join("\n"));
	BankA6.setValue(1);
	BankA7.set("items", [].join("\n")); 
	BankA7.set("items", Maps[value-1].join("\n"));
	BankA7.setValue(1);
	BankA8.set("items", [].join("\n")); 
	BankA8.set("items", Maps[value-1].join("\n"));
	BankA8.setValue(1);	
	HarmWave1.set("items", [].join("\n")); 
	HarmWave1.set("items", Maps[value-1].join("\n"));
	HarmWave1.setValue(1);	
	FMWaveA1.set("items", [].join("\n")); 
	FMWaveA1.set("items", Maps[value-1].join("\n"));
	FMWaveA1.setValue(1);	
	FMWaveB1.set("items", [].join("\n")); 
	FMWaveB1.set("items", Maps[value-1].join("\n"));
	FMWaveB1.setValue(1);	


	Categories.set("items", SMAPS.join("\n"));

};

Content.getComponent("Categories").setControlCallback(onCategoriesControl);

var USERMaps = [];
var USMAPS = ["USER"];
const var LoadSFZ1 = Content.getComponent("LoadSFZ1");


inline function onLoadSFZ1Control(component, value)
{


	if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slot.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		WAVELABELA1.set("text", "USER");
	
	});	

}

}; 

Content.getComponent("LoadSFZ1").setControlCallback(onLoadSFZ1Control);


//Harmonic

const var PitchPack1 = Content.getComponent("PitchPack1");
const var PitchPack2 = Content.getComponent("PitchPack2");
const var PitchPack3 = Content.getComponent("PitchPack3");
const var PitchPack4 = Content.getComponent("PitchPack4");
const var HarmFade = Content.getComponent("HarmFade");


inline function onHarmFadeControl(component, value)
{
OSC1.setAttribute(OSC1.hfade, value);

if(value == 0)
	{
		PitchPack1.fadeComponent(1, 500);
  		PitchPack2.fadeComponent(0, 500);
		PitchPack3.fadeComponent(0, 500);
		PitchPack4.fadeComponent(0, 500);
	}
	else if(value == 0.25)
	{
		PitchPack1.fadeComponent(0, 500);
  		PitchPack2.fadeComponent(1, 500);
		PitchPack3.fadeComponent(0, 500);
		PitchPack4.fadeComponent(0, 500);
		}
	
	else if(value == 0.75)
	{
		PitchPack1.fadeComponent(0, 500);
  		PitchPack2.fadeComponent(0, 500);
		PitchPack3.fadeComponent(1, 500);
		PitchPack4.fadeComponent(0, 500);
		}
			
		else if(value == 1)
	{
		PitchPack1.fadeComponent(0, 500);
  		PitchPack2.fadeComponent(0, 500);
		PitchPack3.fadeComponent(0, 500);
		PitchPack4.fadeComponent(1, 500);
		}

};

Content.getComponent("HarmFade").setControlCallback(onHarmFadeControl);

const var HarmWave1 = Content.getComponent("HarmWave1");
const var WAVELABELH1 = Content.getComponent("WAVELABELH1");


inline function onHarmWave1Control(component, value)
{
	WAVELABELH1.set("text",HarmWave1.get("items").split("\n")[value-1]);
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("HarmWave1").setControlCallback(onHarmWave1Control);


//fm

const var WAVELABELFMA1 = Content.getComponent("WAVELABELFMA1");
const var FMWaveA1 = Content.getComponent("FMWaveA1");


inline function onFMWaveA1Control(component, value)
{
	WAVELABELFMA1.set("text",FMWaveA1.get("items").split("\n")[value-1]);
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("FMWaveA1").setControlCallback(onFMWaveA1Control);

const var WAVELABELFMB1 = Content.getComponent("WAVELABELFMB1");
const var FMWaveB1 = Content.getComponent("FMWaveB1");


inline function onFMWaveB1Control(component, value)
{
	WAVELABELFMB1.set("text",FMWaveB1.get("items").split("\n")[value-1]);
	slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("FMWaveB1").setControlCallback(onFMWaveB1Control);









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
 