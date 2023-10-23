const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");



var Maps = [];
Maps.push(MiscWaves);
Maps.push(Stereo);
//Maps.push(hybrids);
//Maps.push(cs30);
//Maps.push(em25);
//Maps.push(MiscRoland);
//Maps.push(kraftzwerg);
//Maps.push(Xpander);
//Maps.push(Monopoly);




//var SMAPS = ["MiscWaves",  "hybrids",  "cs30", "em25", "MiscRoland", "kraftzwerg",  "Xpander", "Monopoly"];

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

const var Sets1 = Content.getComponent("Sets1");

const var Labels1 = [];

Labels1[0] = Content.getComponent("XlAble1");
Labels1[1] = Content.getComponent("XlAble2");
Labels1[2] = Content.getComponent("XlAble3");
Labels1[3] = Content.getComponent("XlAble4");
Labels1[4] = Content.getComponent("XlAble5");
Labels1[5] = Content.getComponent("XlAble6");
Labels1[6] = Content.getComponent("XlAble7");
Labels1[7] = Content.getComponent("XlAble8");

//Sets1.set("items", Labels1.join("\n"));     

inline function onSets1Control(component, value)
{
if(value == 1)
{

for (i = 0; i < Labels1.length; i++)
       Labels1[i].set("text", "CS-Sine");
	slot.loadFile("{XYZ::SampleMap}" + "CS-Sine");
	slot1.loadFile("{XYZ::SampleMap}" + "CS-Sine");
	slot2.loadFile("{XYZ::SampleMap}" + "CS-Sine");
	slot3.loadFile("{XYZ::SampleMap}" + "CS-Sine");
	slot4.loadFile("{XYZ::SampleMap}" + "CS-Sine");
	slot5.loadFile("{XYZ::SampleMap}" + "CS-Sine");
	slot6.loadFile("{XYZ::SampleMap}" + "CS-Sine");
	slot7.loadFile("{XYZ::SampleMap}" + "CS-Sine");
         
}

	if(value == 2)
{


for (i = 0; i < Labels1.length; i++)
       Labels1[i].set("text", "CS Pulses");

	slot.loadFile("{XYZ::SampleMap}" + "CS-Pulse1");
	slot1.loadFile("{XYZ::SampleMap}" + "CS-Pulse2");
	slot2.loadFile("{XYZ::SampleMap}" + "CS-Pulse3");
	slot3.loadFile("{XYZ::SampleMap}" + "CS-Pulse1");
	slot4.loadFile("{XYZ::SampleMap}" + "CS-Pulse2");
	slot5.loadFile("{XYZ::SampleMap}" + "CS-Pulse3");
	slot6.loadFile("{XYZ::SampleMap}" + "CS-Pulse1");
	slot7.loadFile("{XYZ::SampleMap}" + "CS-Pulse2");
  
}

if(value == 3)
{


for (i = 0; i < Labels1.length; i++)
       Labels1[i].set("text", "CS-Saw");

slot.loadFile("{XYZ::SampleMap}" + "CS-Saw");
slot1.loadFile("{XYZ::SampleMap}" + "CS-Saw");
slot2.loadFile("{XYZ::SampleMap}" + "CS-Saw");
slot3.loadFile("{XYZ::SampleMap}" + "CS-Saw");
slot4.loadFile("{XYZ::SampleMap}" + "CS-Saw");
slot5.loadFile("{XYZ::SampleMap}" + "CS-Saw");
slot6.loadFile("{XYZ::SampleMap}" + "CS-Saw");
slot7.loadFile("{XYZ::SampleMap}" + "CS-Saw");
  
}

if(value == 4)
{


for (i = 0; i < Labels1.length; i++)
       Labels1[i].set("text", "101 Bells");

slot.loadFile("{XYZ::SampleMap}" + "101-bell1");
slot1.loadFile("{XYZ::SampleMap}" + "101-bell2");
slot2.loadFile("{XYZ::SampleMap}" + "101-bell3");
slot3.loadFile("{XYZ::SampleMap}" + "101-bell4");
slot4.loadFile("{XYZ::SampleMap}" + "101-bell4");
slot5.loadFile("{XYZ::SampleMap}" + "101-bell3");
slot6.loadFile("{XYZ::SampleMap}" + "101-bell2");
slot7.loadFile("{XYZ::SampleMap}" + "101-bell1");
  
}

if(value == 5)
{


for (i = 0; i < Labels1.length; i++)
       Labels1[i].set("text", "101 PWM");

slot.loadFile("{XYZ::SampleMap}" + "101-pwm1");
slot1.loadFile("{XYZ::SampleMap}" + "101-pwm2");
slot2.loadFile("{XYZ::SampleMap}" + "101-pwm3");
slot3.loadFile("{XYZ::SampleMap}" + "101-pwm4");
slot4.loadFile("{XYZ::SampleMap}" + "101-pwm4");
slot5.loadFile("{XYZ::SampleMap}" + "101-pwm3");
slot6.loadFile("{XYZ::SampleMap}" + "101-pwm2");
slot7.loadFile("{XYZ::SampleMap}" + "101-pwm1");
  
}

};

Content.getComponent("Sets1").setControlCallback(onSets1Control);




