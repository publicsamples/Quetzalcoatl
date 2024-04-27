// BANK A


var Maps = [];
Maps.push(BasicWaveforms);
Maps.push(GM);
Maps.push(Hybrids);
Maps.push(cs30);
Maps.push(em25);
Maps.push(sys101);
Maps.push(jx3p);
Maps.push(kraftzwerg);
Maps.push(Xpander);
Maps.push(Monopoly);



var SMAPS = ["BasicWaveforms", "GM", "Hybrids",  "cs30", "em25", "sys101","jx3p", "kraftzwerg",  "Xpander", "Monopoly"];


const var BankA = Content.getComponent("BankA");
const var BankA1 = Content.getComponent("BankA1");
const var WAVELABEL1 = Content.getComponent("WAVELABEL1");
const var WAVELABEL2 = Content.getComponent("WAVELABEL2");
const var Categories = Content.getComponent("Categories");
const var Categories1 = Content.getComponent("Categories1");



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
 
 };
 
 Content.getComponent("Categories").setControlCallback(onCategoriesControl);
 
 
 
 // BANK A1
 
 
 inline function onBankA1Control(component, value)
 {
 	WAVELABEL2.set("text",BankA1.get("items").split("\n")[value-1]);
 	slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
 	
 
 };
 
 Content.getComponent("BankA1").setControlCallback(onBankA1Control);
 
 
 
 Categories1.set("items", SMAPS.join("\n"));
 
 inline function onCategories1Control(component, value)
 {
 
 	BankA1.set("items", [].join("\n")); 
 	BankA1.set("items", Maps[value-1].join("\n"));
 	BankA1.setValue(1);
 
 };
 
 Content.getComponent("Categories1").setControlCallback(onCategories1Control);

