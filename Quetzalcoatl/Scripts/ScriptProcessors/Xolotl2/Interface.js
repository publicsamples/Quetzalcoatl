Content.makeFrontInterface(945, 605);

include("UISTUFF.js");
include("ExpansionWaves.js");

Settings.setVoiceMultiplier(7);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
const var harm2 = Synth.getAudioSampleProcessor("HARMONIC2");



var Maps = [];
Maps.push(MiscWaves);
Maps.push(GM);
Maps.push(Hybrids);
Maps.push(cs30);
Maps.push(em25);
Maps.push(MiscRoland);
Maps.push(kraftzwerg);
Maps.push(Xpander);
Maps.push(Monopoly);

var SMAPS = ["MiscWaves", "GM", "Hybrids",  "cs30", "em25", "MiscRoland", "kraftzwerg",  "Xpander", "Monopoly"];

// BANK A

const var HARMONIC = Synth.getChildSynth("HARMONIC")
const var WAVELABEL1b = Content.getComponent("WAVELABEL1b");
const var AudioWaveform2 = Content.getComponent("AudioWaveform2");

const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);
const slot2 = harm.getAudioFile(2);
const slot3 = harm.getAudioFile(3);
const slot4 = harm.getAudioFile(4);
const slot5 = harm.getAudioFile(5);
const slot6 = harm.getAudioFile(6);
const slot7 = harm.getAudioFile(7);
const slot8 = harm.getAudioFile(8);
const slot9 = harm.getAudioFile(9);
const slot10 = harm.getAudioFile(10);


const var BankA = Content.getComponent("BankA");
const var WAVELABEL1 = Content.getComponent("WAVELABEL1");
const var Categories = Content.getComponent("Categories");


 inline function onBankAControl(component, value)
 {
 	WAVELABEL1.set("text",BankA.get("items").split("\n")[value-1]);
 	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
 };
 
 Content.getComponent("BankA").setControlCallback(onBankAControl);

 
inline function onCategoriesControl(component, value)
 {
 
 	BankA.set("items", [].join("\n")); 
 	BankA.set("items", Maps[value-1].join("\n"));
 	BankA.setValue(1);
 	Categories.set("items", SMAPS.join("\n"));
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
XlAble1.set("text",XBankA1.get("items").split("\n")[value-1]);
 	slot2.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA1").setControlCallback(onXBankA1Control);

inline function onXBankA2Control(component, value)
{
XlAble2.set("text",XBankA2.get("items").split("\n")[value-1]);
 	slot3.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA2").setControlCallback(onXBankA2Control);

inline function onXBankA3Control(component, value)
{
XlAble3.set("text",XBankA3.get("items").split("\n")[value-1]);
 	slot4.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA3").setControlCallback(onXBankA3Control);

inline function onXBankA4Control(component, value)
{
XlAble4.set("text",XBankA4.get("items").split("\n")[value-1]);
 	slot5.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA4").setControlCallback(onXBankA4Control);
 
inline function onXBankA5Control(component, value)
{
XlAble5.set("text",XBankA5.get("items").split("\n")[value-1]);
 	slot6.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA5").setControlCallback(onXBankA5Control);

inline function onXBankA6Control(component, value)
{
XlAble5.set("text",XBankA6.get("items").split("\n")[value-1]);
 	slot7.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA6").setControlCallback(onXBankA6Control);

inline function onXBankA7Control(component, value)
{
XlAble6.set("text",XBankA7.get("items").split("\n")[value-1]);
 	slot8.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA7").setControlCallback(onXBankA7Control);

inline function onXBankA8Control(component, value)
{
XlAble7.set("text",XBankA8.get("items").split("\n")[value-1]);
 	slot9.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA8").setControlCallback(onXBankA8Control);


const var A = Content.getComponent("A");
const var B = Content.getComponent("B");
const var C = Content.getComponent("C");
const var User1 = Content.getComponent("User1");
const var ScriptAudioWaveform1 = Content.getComponent("ScriptAudioWaveform1");
const var XFLABLE = Content.getComponent("XFLABLE");
const var XF1 = Content.getComponent("XF1");
const var BankMode = Content.getComponent("BankMode");
const var SecRow = Content.getComponent("SecRow");








inline function onUser1Control(component, value)
{
	
	HARMONIC.setAttribute(HARMONIC.userwav2, value);

	if(value == 1)
	{	 	    
		 A.showControl(1);
		 B.showControl(0);
		 C.showControl(0);
		 XF1.showControl(0);
		 XFLABLE.showControl(0);
		 SecRow.showControl(0);
		 BankMode.showControl(1);
	}	
		if(value == 2)
	{
		 A.showControl(0);
		 B.showControl(1);
		 C.showControl(0);
		 XF1.showControl(0);
		 XFLABLE.showControl(0);
		 SecRow.showControl(0);
		 BankMode.showControl(0);
	}
	if(value == 3)
	{
		 A.showControl(0);
		 B.showControl(0);
		 C.showControl(1);
		 XF1.showControl(1);
		 XFLABLE.showControl(1);
		 SecRow.showControl(0);
		 BankMode.showControl(1);
	}
	if(value == 4)
	{
		 A.showControl(0);
		 B.showControl(0);
		 C.showControl(1);
		 XF1.showControl(1);
		 XFLABLE.showControl(1);
		 SecRow.showControl(1);
		 BankMode.showControl(1);
	}
};

Content.getComponent("User1").setControlCallback(onUser1Control);



inline function onLoadSFZ1Control(component, value)
{


	if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slot5.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		WAVELABEL1b.set("text", "SFZ");
	
	});	

}

}; 

Content.getComponent("LoadSFZ1").setControlCallback(onLoadSFZ1Control);

// BANK B


const var WAVELABEL2b = Content.getComponent("WAVELABEL2b");


const slotB = harm2.getAudioFile(0);
const slotB1 = harm2.getAudioFile(1);
const slotB2 = harm2.getAudioFile(2);
const slotB3 = harm2.getAudioFile(3);
const slotB4 = harm2.getAudioFile(4);
const slotB5 = harm2.getAudioFile(5);
const slotB6 = harm2.getAudioFile(6);
const slotB7 = harm2.getAudioFile(7);
const slotB8 = harm2.getAudioFile(8);
const slotB9 = harm2.getAudioFile(9);
const slotB10 = harm2.getAudioFile(10);


const var BankA1 = Content.getComponent("BankA1");
const var WAVELABEL2 = Content.getComponent("WAVELABEL2");
const var Categories2 = Content.getComponent("Categories2");


 inline function onBankA1Control(component, value)
 {
 	WAVELABEL2.set("text",BankA1.get("items").split("\n")[value-1]);
 	slotB.loadFile("{XYZ::SampleMap}" + component.getItemText());
 };
 
 Content.getComponent("BankA1").setControlCallback(onBankA1Control);

 
inline function onCategories2Control(component, value)
 {
 
 	BankA1.set("items", [].join("\n")); 
 	BankA1.set("items", Maps[value-1].join("\n"));
 	BankA1.setValue(1);
 	Categories2.set("items", SMAPS.join("\n"));
 	XBankA9.set("items", [].join("\n")); 
 	XBankA9.set("items", Maps[value-1].join("\n"));
 	XBankA9.setValue(1);
 	XBankA10.set("items", [].join("\n")); 
 	XBankA10.set("items", Maps[value-1].join("\n"));
 	 XBankA10.setValue(1);
 	 XBankA11.set("items", [].join("\n")); 
 	 XBankA11.set("items", Maps[value-1].join("\n"));
 	 XBankA11.setValue(1);
 	 XBankA12.set("items", [].join("\n")); 
 	 XBankA12.set("items", Maps[value-1].join("\n"));
 	 XBankA12.setValue(1);
 	 XBankA13.set("items", [].join("\n")); 
 	  	XBankA13.set("items", Maps[value-1].join("\n"));
 	  	XBankA13.setValue(1);
 	  	XBankA14.set("items", [].join("\n")); 
 	  	XBankA14.set("items", Maps[value-1].join("\n"));
 	  	 XBankA14.setValue(1);
 	  	 XBankA15.set("items", [].join("\n")); 
 	  	 XBankA15.set("items", Maps[value-1].join("\n"));
 	  	 XBankA15.setValue(1);
 	  	 XBankA16.set("items", [].join("\n")); 
 	  	 XBankA16.set("items", Maps[value-1].join("\n"));
 	  	 XBankA16.setValue(1);
 
 };
 
 Content.getComponent("Categories2").setControlCallback(onCategories2Control);
 
 


const var XlAble9 = Content.getComponent("XlAble9");
const var XlAble10 = Content.getComponent("XlAble10");
const var XlAble11 = Content.getComponent("XlAble11");
const var XlAble12 = Content.getComponent("XlAble12");
const var XlAble13 = Content.getComponent("XlAble13");
const var XlAble14 = Content.getComponent("XlAble14");
const var XlAble15 = Content.getComponent("XlAble15");
const var XlAble16 = Content.getComponent("XlAble16");
 
 const var XBankA9 = Content.getComponent("XBankA9");
 const var XBankA10 = Content.getComponent("XBankA10");
 const var XBankA11 = Content.getComponent("XBankA11");
 const var XBankA12 = Content.getComponent("XBankA12");
 const var XBankA13 = Content.getComponent("XBankA13");
 const var XBankA14 = Content.getComponent("XBankA14");
 const var XBankA15 = Content.getComponent("XBankA15");
 const var XBankA16 = Content.getComponent("XBankA16");
 
 

inline function onXBankA9Control(component, value)
{
XlAble9.set("text",XBankA9.get("items").split("\n")[value-1]);
 	slotB2.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA9").setControlCallback(onXBankA9Control);

inline function onXBankA10Control(component, value)
{
XlAble10.set("text",XBankA10.get("items").split("\n")[value-1]);
 	slotB3.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA10").setControlCallback(onXBankA10Control);

inline function onXBankA11Control(component, value)
{
XlAble11.set("text",XBankA11.get("items").split("\n")[value-1]);
 	slotB4.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA11").setControlCallback(onXBankA11Control);

inline function onXBankA12Control(component, value)
{
XlAble12.set("text",XBankA12.get("items").split("\n")[value-1]);
 	slotB5.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA12").setControlCallback(onXBankA12Control);
 
inline function onXBankA13Control(component, value)
{
XlAble13.set("text",XBankA13.get("items").split("\n")[value-1]);
 	slotB6.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA13").setControlCallback(onXBankA13Control);

inline function onXBankA14Control(component, value)
{
XlAble13.set("text",XBankA14.get("items").split("\n")[value-1]);
 	slotB7.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA14").setControlCallback(onXBankA14Control);

inline function onXBankA15Control(component, value)
{
XlAble14.set("text",XBankA15.get("items").split("\n")[value-1]);
 	slotB8.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA15").setControlCallback(onXBankA15Control);

inline function onXBankA16Control(component, value)
{
XlAble15.set("text",XBankA16.get("items").split("\n")[value-1]);
 	slotB9.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA16").setControlCallback(onXBankA16Control);


const var A1 = Content.getComponent("A1");
const var B1 = Content.getComponent("B1");
const var C1 = Content.getComponent("C1");
const var User2 = Content.getComponent("User2");
const var XFLABLE1 = Content.getComponent("XFLABLE1");
const var XF2 = Content.getComponent("XF2");
const var BankMode1 = Content.getComponent("BankMode1");
const var SecRow1 = Content.getComponent("SecRow1");








inline function onUser2Control(component, value)
{
	
	HARMONIC2.setAttribute(HARMONIC2.userwav2, value);

	if(value == 1)
	{	 	    
		 A1.showControl(1);
		 B1.showControl(0);
		 C1.showControl(0);
		 XF2.showControl(0);
		 XFLABLE1.showControl(0);
		 SecRow1.showControl(0);
		 BankMode1.showControl(1);
	}	
		if(value == 2)
	{
		 A1.showControl(0);
		 B1.showControl(1);
		 C1.showControl(0);
		 XF2.showControl(0);
		 XFLABLE1.showControl(0);
		 SecRow1.showControl(0);
		 BankMode1.showControl(0);
	}
	if(value == 3)
	{
		 A1.showControl(0);
		 B1.showControl(0);
		 C1.showControl(1);
		 XF2.showControl(1);
		 XFLABLE1.showControl(1);
		 SecRow1.showControl(0);
		 BankMode1.showControl(1);
	}
	if(value == 4)
	{
		 A1.showControl(0);
		 B1.showControl(0);
		 C1.showControl(1);
		 XF2.showControl(1);
		 XFLABLE1.showControl(1);
		 SecRow1.showControl(1);
		 BankMode1.showControl(1);
	}
};

Content.getComponent("User2").setControlCallback(onUser2Control);



inline function onLoadSFZ2Control(component, value)
{


	if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotB5.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		WAVELABEL2b.set("text", "SFZ");
	
	});	

}

}; 

Content.getComponent("LoadSFZ2").setControlCallback(onLoadSFZ2Control);


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
 