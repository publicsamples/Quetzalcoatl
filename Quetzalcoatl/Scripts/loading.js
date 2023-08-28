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

// BANKS A
const var BankB1 = Content.getComponent("BankB1");
const var WAVELABELB1 = Content.getComponent("WAVELABELB1");
inline function onBankB1Control(component, value)
{
	WAVELABELB1.set("text",BankB1.get("items").split("\n")[value-1]);
	slot8.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankB1").setControlCallback(onBankB1Control);

const var BankB2 = Content.getComponent("BankB2");
const var WAVELABELB2 = Content.getComponent("WAVELABELB2");
inline function onBankB2Control(component, value)
{
	WAVELABELB2.set("text",BankB2.get("items").split("\n")[value-1]);
	slot9.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankB2").setControlCallback(onBankB2Control);

const var BankB3 = Content.getComponent("BankB3");
const var WAVELABELB3 = Content.getComponent("WAVELABELB3");
inline function onBankB3Control(component, value)
{
	WAVELABELB3.set("text",BankB3.get("items").split("\n")[value-1]);
	slot10.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankB3").setControlCallback(onBankB3Control);

const var BankB4 = Content.getComponent("BankB4");
const var WAVELABELB4 = Content.getComponent("WAVELABELB4");
inline function onBankB4Control(component, value)
{
	WAVELABELB4.set("text",BankB4.get("items").split("\n")[value-1]);
	slot11.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankB4").setControlCallback(onBankB4Control);

const var BankB5 = Content.getComponent("BankB5");
const var WAVELABELB5 = Content.getComponent("WAVELABELB5");
inline function onBankB5Control(component, value)
{
	WAVELABELB5.set("text",BankB5.get("items").split("\n")[value-1]);
	slot12.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankB5").setControlCallback(onBankB5Control);

const var BankB6 = Content.getComponent("BankB6");
const var WAVELABELB6 = Content.getComponent("WAVELABELB6");
inline function onBankB6Control(component, value)
{
	WAVELABELB6.set("text",BankB6.get("items").split("\n")[value-1]);
	slot13.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankB6").setControlCallback(onBankB6Control);

const var BankB7 = Content.getComponent("BankB7");
const var WAVELABELB7 = Content.getComponent("WAVELABELB7");
inline function onBankB7Control(component, value)
{
	WAVELABELB7.set("text",BankB7.get("items").split("\n")[value-1]);
	slot14.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankB7").setControlCallback(onBankB7Control);

const var BankB8 = Content.getComponent("BankB8");
const var WAVELABELB8 = Content.getComponent("WAVELABELB8");
inline function onBankB8Control(component, value)
{
	WAVELABELB8.set("text",BankB8.get("items").split("\n")[value-1]);
	slot15.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("BankB8").setControlCallback(onBankB8Control);
