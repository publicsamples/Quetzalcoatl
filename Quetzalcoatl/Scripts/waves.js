const audio = Engine.createAndRegisterAudioFile(0);

const maps = Sampler.getSampleMapList();
const var harm = Synth.getAudioSampleProcessor("HARMONIC");
const var harm2 = Synth.getAudioSampleProcessor("HARMONIC2");
const var harm3 = Synth.getAudioSampleProcessor("HARMONIC3");
const var harm4 = Synth.getAudioSampleProcessor("HARMONIC4");



var Maps = [];
Maps.push(MiscWaves);
Maps.push(GM);
Maps.push(hybrids);
Maps.push(cs30);
Maps.push(em25);
Maps.push(MiscRoland);
Maps.push(kraftzwerg);
Maps.push(Xpander);
Maps.push(Monopoly);
Maps.push(FmFilter);



var SMAPS = ["MiscWaves", "GM", "hybrids",  "cs30", "em25", "MiscRoland", "kraftzwerg",  "Xpander", "Monopoly"];



// BANK A



const slot = harm.getAudioFile(0);
const slot1 = harm.getAudioFile(1);
const slot2 = harm.getAudioFile(2);
const slot3 = harm.getAudioFile(3);
const slot4 = harm.getAudioFile(4);
const slot5 = harm.getAudioFile(5);
const slot6 = harm.getAudioFile(6);
const slot7 = harm.getAudioFile(7);


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



const slotB = harm2.getAudioFile(0);
const slotB1 = harm2.getAudioFile(1);
const slotB2 = harm2.getAudioFile(2);
const slotB3 = harm2.getAudioFile(3);
const slotB4 = harm2.getAudioFile(4);
const slotB5 = harm2.getAudioFile(5);
const slotB6 = harm2.getAudioFile(6);
const slotB7 = harm2.getAudioFile(7);


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

// BANK C



const slotC = harm2.getAudioFile(0);
const slotC1 = harm2.getAudioFile(1);
const slotC2 = harm2.getAudioFile(2);
const slotC3 = harm2.getAudioFile(3);
const slotC4 = harm2.getAudioFile(4);
const slotC5 = harm2.getAudioFile(5);
const slotC6 = harm2.getAudioFile(6);
const slotC7 = harm2.getAudioFile(7);


const var Categories2 = Content.getComponent("Categories2");


Categories2.set("items", SMAPS.join("\n"));

 
inline function onCategories2Control(component, value)
 {
 
 	XBankA17.set("items", [].join("\n")); 
 	XBankA17.set("items", Maps[value-1].join("\n"));
 	XBankA17.setValue(1);
 	XBankA18.set("items", [].join("\n")); 
 	XBankA18.set("items", Maps[value-1].join("\n"));
 	 XBankA18.setValue(1);
 	 XBankA19.set("items", [].join("\n")); 
 	 XBankA19.set("items", Maps[value-1].join("\n"));
 	 XBankA19.setValue(1);
 	 XBankA20.set("items", [].join("\n")); 
 	 XBankA20.set("items", Maps[value-1].join("\n"));
 	 XBankA20.setValue(1);
 	 XBankA21.set("items", [].join("\n")); 
 	 XBankA21.set("items", Maps[value-1].join("\n"));
 	 XBankA21.setValue(1);
 	 XBankA22.set("items", [].join("\n")); 
 	 XBankA22.set("items", Maps[value-1].join("\n"));
 	 XBankA22.setValue(1);
 	 XBankA23.set("items", [].join("\n")); 
 	 XBankA23.set("items", Maps[value-1].join("\n"));
 	 XBankA23.setValue(1);
 	 XBankA24.set("items", [].join("\n")); 
 	  	 XBankA24.set("items", Maps[value-1].join("\n"));
 	  	 XBankA24.setValue(1);
 	

 };
 
 Content.getComponent("Categories2").setControlCallback(onCategories2Control);
 


 


const var XlAble17 = Content.getComponent("XlAble17");
const var XlAble18 = Content.getComponent("XlAble18");
const var XlAble19 = Content.getComponent("XlAble19");
const var XlAble20 = Content.getComponent("XlAble20");
const var XlAble21 = Content.getComponent("XlAble21");
const var XlAble22 = Content.getComponent("XlAble22");
const var XlAble23 = Content.getComponent("XlAble23");
const var XlAble24 = Content.getComponent("XlAble24");

 
 const var XBankA17 = Content.getComponent("XBankA17");
 const var XBankA18 = Content.getComponent("XBankA18");
 const var XBankA19 = Content.getComponent("XBankA19");
 const var XBankA20 = Content.getComponent("XBankA20");
 const var XBankA21 = Content.getComponent("XBankA21");
 const var XBankA22 = Content.getComponent("XBankA22");
 const var XBankA23 = Content.getComponent("XBankA23");
 const var XBankA24 = Content.getComponent("XBankA24");


inline function onXBankA17Control(component, value)
{
XlAble17.set("text",XBankA17.get("items").split("\n")[value-1]);
 	slotC.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA17").setControlCallback(onXBankA17Control);

inline function onXBankA18Control(component, value)
{
XlAble18.set("text",XBankA18.get("items").split("\n")[value-1]);
 	slotC1.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA18").setControlCallback(onXBankA18Control);

inline function onXBankA19Control(component, value)
{
XlAble19.set("text",XBankA19.get("items").split("\n")[value-1]);
 	slotC2.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA19").setControlCallback(onXBankA19Control);

inline function onXBankA20Control(component, value)
{
XlAble20.set("text",XBankA20.get("items").split("\n")[value-1]);
 	slotC3.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA20").setControlCallback(onXBankA20Control);
 
inline function onXBankA21Control(component, value)
{
XlAble21.set("text",XBankA21.get("items").split("\n")[value-1]);
 	slotC4.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA21").setControlCallback(onXBankA21Control);
 

inline function onXBankA22Control(component, value)
{
XlAble22.set("text",XBankA22.get("items").split("\n")[value-1]);
	slotC5.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA22").setControlCallback(onXBankA22Control);

inline function onXBankA23Control(component, value)
{
XlAble23.set("text",XBankA23.get("items").split("\n")[value-1]);
	slotC6.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA23").setControlCallback(onXBankA23Control);

inline function onXBankA24Control(component, value)
{
XlAble24.set("text",XBankA24.get("items").split("\n")[value-1]);
	slotC7.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA24").setControlCallback(onXBankA24Control);

// BANK D



const slotD = harm2.getAudioFile(0);
const slotD1 = harm2.getAudioFile(1);
const slotD2 = harm2.getAudioFile(2);
const slotD3 = harm2.getAudioFile(3);
const slotD4 = harm2.getAudioFile(4);
const slotD5 = harm2.getAudioFile(5);
const slotD6 = harm2.getAudioFile(6);
const slotD7 = harm2.getAudioFile(7);


const var Categories3 = Content.getComponent("Categories3");


Categories3.set("items", SMAPS.join("\n"));

 
inline function onCategories3Control(component, value)
 {
 
 	XBankA25.set("items", [].join("\n")); 
 	XBankA25.set("items", Maps[value-1].join("\n"));
 	XBankA25.setValue(1);
 	XBankA26.set("items", [].join("\n")); 
 	XBankA26.set("items", Maps[value-1].join("\n"));
 	 XBankA26.setValue(1);
 	 XBankA27.set("items", [].join("\n")); 
 	 XBankA27.set("items", Maps[value-1].join("\n"));
 	 XBankA27.setValue(1);
 	 XBankA28.set("items", [].join("\n")); 
 	 XBankA28.set("items", Maps[value-1].join("\n"));
 	 XBankA28.setValue(1);
 	 XBankA29.set("items", [].join("\n")); 
 	 XBankA29.set("items", Maps[value-1].join("\n"));
 	 XBankA29.setValue(1);
 	 XBankA30.set("items", [].join("\n")); 
 	 XBankA30.set("items", Maps[value-1].join("\n"));
 	 XBankA30.setValue(1);
 	 XBankA31.set("items", [].join("\n")); 
 	 XBankA31.set("items", Maps[value-1].join("\n"));
 	 XBankA31.setValue(1);
 	 XBankA32.set("items", [].join("\n")); 
 	  	 XBankA32.set("items", Maps[value-1].join("\n"));
 	  	 XBankA32.setValue(1);
 	

 };
 
 Content.getComponent("Categories3").setControlCallback(onCategories3Control);
 


 


const var XlAble25 = Content.getComponent("XlAble25");
const var XlAble26 = Content.getComponent("XlAble26");
const var XlAble27 = Content.getComponent("XlAble27");
const var XlAble28 = Content.getComponent("XlAble28");
const var XlAble29 = Content.getComponent("XlAble29");
const var XlAble30 = Content.getComponent("XlAble30");
const var XlAble31 = Content.getComponent("XlAble31");
const var XlAble32 = Content.getComponent("XlAble32");

 
 const var XBankA25 = Content.getComponent("XBankA25");
 const var XBankA26 = Content.getComponent("XBankA26");
 const var XBankA27 = Content.getComponent("XBankA27");
 const var XBankA28 = Content.getComponent("XBankA28");
 const var XBankA29 = Content.getComponent("XBankA29");
 const var XBankA30 = Content.getComponent("XBankA30");
 const var XBankA31 = Content.getComponent("XBankA31");
 const var XBankA32 = Content.getComponent("XBankA32");


inline function onXBankA25Control(component, value)
{
XlAble25.set("text",XBankA25.get("items").split("\n")[value-1]);
 	slotD.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA25").setControlCallback(onXBankA25Control);

inline function onXBankA26Control(component, value)
{
XlAble26.set("text",XBankA26.get("items").split("\n")[value-1]);
 	slotD1.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA26").setControlCallback(onXBankA26Control);

inline function onXBankA27Control(component, value)
{
XlAble27.set("text",XBankA27.get("items").split("\n")[value-1]);
 	slotD2.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA27").setControlCallback(onXBankA27Control);

inline function onXBankA28Control(component, value)
{
XlAble28.set("text",XBankA28.get("items").split("\n")[value-1]);
 	slotD3.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA28").setControlCallback(onXBankA28Control);
 
inline function onXBankA29Control(component, value)
{
XlAble29.set("text",XBankA29.get("items").split("\n")[value-1]);
 	slotD4.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA29").setControlCallback(onXBankA29Control);
 

inline function onXBankA30Control(component, value)
{
XlAble30.set("text",XBankA30.get("items").split("\n")[value-1]);
	slotD5.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA30").setControlCallback(onXBankA30Control);

inline function onXBankA31Control(component, value)
{
XlAble31.set("text",XBankA31.get("items").split("\n")[value-1]);
	slotD6.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA31").setControlCallback(onXBankA31Control);

inline function onXBankA32Control(component, value)
{
XlAble32.set("text",XBankA32.get("items").split("\n")[value-1]);
	slotD7.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("XBankA32").setControlCallback(onXBankA32Control);