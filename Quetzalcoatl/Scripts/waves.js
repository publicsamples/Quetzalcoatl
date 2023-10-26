const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");


var Maps = [];
Maps.push(MiscWaves);
Maps.push(Stereo);
//Maps.push(HT700_1);
///.push(HT700_2);
//Maps.push(HT700_3);
//Maps.push(hybrids);
//Maps.push(cs30);
//Maps.push(em25);
//Maps.push(MiscRoland);
//Maps.push(kraftzwerg);
//Maps.push(Xpander);
//Maps.push(Monopoly);




//var SMAPS = ["MiscWaves",  "hybrids",  "cs30", "em25", "MiscRoland", "kraftzwerg",  "Xpander", "Monopoly"];

var SMAPS = ["MiscWaves", "Stereo", "HT700_1", "HT700_2", "HT700_3"];

var SMAPS = ["MiscWaves", "Stereo"];

// BANK A



const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);
const slot2 = harm.getAudioFile(2);
const slot3 = harm.getAudioFile(3);
const slot4 = harm.getAudioFile(4);
const slot5 = harm.getAudioFile(5);
const slot6 = harm.getAudioFile(6);
const slot7 = harm.getAudioFile(7);
const slotB = harm.getAudioFile(8);
const slotB1 = harm.getAudioFile(9);
const slotB2 = harm.getAudioFile(10);
const slotB3 = harm.getAudioFile(11);
const slotB4 = harm.getAudioFile(12);
const slotB5 = harm.getAudioFile(13);
const slotB6 = harm.getAudioFile(14);
const slotB7 = harm.getAudioFile(15);
const slotC = harm.getAudioFile(16);
const slotC1 = harm.getAudioFile(17);
const slotC2 = harm.getAudioFile(18);
const slotC3 = harm.getAudioFile(19);
const slotC4 = harm.getAudioFile(20);
const slotC5 = harm.getAudioFile(21);
const slotC6 = harm.getAudioFile(22);
const slotC7 = harm.getAudioFile(23);
const slotD = harm.getAudioFile(24);
const slotD1 = harm.getAudioFile(25);
const slotD2 = harm.getAudioFile(26);
const slotD3 = harm.getAudioFile(27);
const slotD4 = harm.getAudioFile(28);
const slotD5 = harm.getAudioFile(30);
const slotD6 = harm.getAudioFile(31);
const slotD7 = harm.getAudioFile(32);


const var Categories = Content.getComponent("Categories");


Categories.set("items", SMAPS.join("\n"));

 
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
XlAble1.set("text",XBankA1.get("items").split("\n")[value-1]);
 	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA1").setControlCallback(onXBankA1Control);

inline function onXBankA2Control(component, value)
{
XlAble2.set("text",XBankA2.get("items").split("\n")[value-1]);
 	slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA2").setControlCallback(onXBankA2Control);

inline function onXBankA3Control(component, value)
{
XlAble3.set("text",XBankA3.get("items").split("\n")[value-1]);
 	slot2.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA3").setControlCallback(onXBankA3Control);

inline function onXBankA4Control(component, value)
{
XlAble4.set("text",XBankA4.get("items").split("\n")[value-1]);
 	slot3.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA4").setControlCallback(onXBankA4Control);
 
inline function onXBankA5Control(component, value)
{
XlAble5.set("text",XBankA5.get("items").split("\n")[value-1]);
 	slot4.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA5").setControlCallback(onXBankA5Control);
 

inline function onXBankA6Control(component, value)
{
XlAble6.set("text",XBankA6.get("items").split("\n")[value-1]);
	slot5.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA6").setControlCallback(onXBankA6Control);

inline function onXBankA7Control(component, value)
{
XlAble7.set("text",XBankA7.get("items").split("\n")[value-1]);
	slot6.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA7").setControlCallback(onXBankA7Control);

inline function onXBankA8Control(component, value)
{
XlAble8.set("text",XBankA8.get("items").split("\n")[value-1]);
	slot7.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA8").setControlCallback(onXBankA8Control);

// BANK B

const var Categories1 = Content.getComponent("Categories1");


Categories1.set("items", SMAPS.join("\n"));

 
inline function onCategories1Control(component, value)
 {
 
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
 
 Content.getComponent("Categories1").setControlCallback(onCategories1Control);
 
 
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
 	slotB.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA9").setControlCallback(onXBankA9Control);

inline function onXBankA10Control(component, value)
{
XlAble10.set("text",XBankA10.get("items").split("\n")[value-1]);
 	slotB1.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA10").setControlCallback(onXBankA10Control);

inline function onXBankA11Control(component, value)
{
XlAble11.set("text",XBankA11.get("items").split("\n")[value-1]);
 	slotB2.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA11").setControlCallback(onXBankA11Control);

inline function onXBankA12Control(component, value)
{
XlAble12.set("text",XBankA12.get("items").split("\n")[value-1]);
 	slotB3.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA12").setControlCallback(onXBankA12Control);
 
inline function onXBankA13Control(component, value)
{
XlAble13.set("text",XBankA13.get("items").split("\n")[value-1]);
 	slotB4.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA13").setControlCallback(onXBankA13Control);
 

inline function onXBankA14Control(component, value)
{
XlAble14.set("text",XBankA14.get("items").split("\n")[value-1]);
	slotB5.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA14").setControlCallback(onXBankA14Control);

inline function onXBankA15Control(component, value)
{
XlAble15.set("text",XBankA15.get("items").split("\n")[value-1]);
	slotB6.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA15").setControlCallback(onXBankA15Control);

inline function onXBankA16Control(component, value)
{
XlAble16.set("text",XBankA16.get("items").split("\n")[value-1]);
	slotB7.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA16").setControlCallback(onXBankA16Control);


const var UserA1 = Content.getComponent("UserA1");


inline function onUserA1Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
	//	var nom = f.toString(File.NoExtension);

//XlAble1.set("text") + (f.toString(f.NoExtension));
XlAble1.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA1").setControlCallback(onUserA1Control);

const var UserA2 = Content.getComponent("UserA2");

	
inline function onUserA2Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC1.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble2.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA2").setControlCallback(onUserA2Control);

const var UserA3 = Content.getComponent("UserA3");

	
inline function onUserA3Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC2.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble3.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA3").setControlCallback(onUserA3Control);

const var UserA4 = Content.getComponent("UserA4");

	
inline function onUserA4Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC3.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble4.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA4").setControlCallback(onUserA4Control);

const var UserA5 = Content.getComponent("UserA5");

	
inline function onUserA5Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC4.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble5.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA5").setControlCallback(onUserA5Control);

const var UserA6 = Content.getComponent("UserA6");

	
inline function onUserA6Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC5.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble6.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA6").setControlCallback(onUserA6Control);

const var UserA7 = Content.getComponent("UserA7");

	
inline function onUserA7Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC6.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble7.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA7").setControlCallback(onUserA7Control);


const var UserA8 = Content.getComponent("UserA8");

	
inline function onUserA8Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC7.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble8.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA8").setControlCallback(onUserA8Control);

const var UserB1 = Content.getComponent("UserB1");


inline function onUserB1Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotD.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
	//	var nom = f.toString(File.NoExtension);

//XlAble1.set("text") + (f.toString(f.NoExtension));
XlAble9.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserB1").setControlCallback(onUserB1Control);

const var UserB2 = Content.getComponent("UserB2");

	
inline function onUserB2Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotD1.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble10.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserB2").setControlCallback(onUserB2Control);

const var UserB3 = Content.getComponent("UserB3");

	
inline function onUserB3Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotD2.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble11.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserB3").setControlCallback(onUserB3Control);

const var UserB4 = Content.getComponent("UserB4");

	
inline function onUserB4Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotD3.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble12.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserB4").setControlCallback(onUserB4Control);

const var UserB5 = Content.getComponent("UserB5");

	
inline function onUserB5Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotD4.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble13.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserB5").setControlCallback(onUserB5Control);

const var UserB6 = Content.getComponent("UserB6");

	
inline function onUserB6Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotD5.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble14.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserB6").setControlCallback(onUserB6Control);

const var UserB7 = Content.getComponent("UserB7");

	
inline function onUserB7Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotD6.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble15.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserB7").setControlCallback(onUserB7Control);


const var UserB8 = Content.getComponent("UserB8");

	
inline function onUserB8Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotD7.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		XlAble15.set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserB8").setControlCallback(onUserB8Control);



