Content.makeFrontInterface(785, 570);

include("ExpansionWaves.js");
include("waves.js");
include("UISTUFF.js");


//Settings.setVoiceMultiplier(16);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");



const var MODSEL1 = Content.getComponent("MODSEL1");
const var mod1 = Synth.getModulator("mod1");
const var mods = [];

mods[0] = Content.getComponent("env1");
mods[1] = Content.getComponent("table1");
mods[2] = Content.getComponent("8STEP1");
mods[3] = Content.getComponent("8STEP2");


inline function onMODSEL1Control(component, value)
{
	
mod1.setAttribute(mod1.modsel, value);

for (i = 0; i < mods.length; i++)
        mods[i].fadeComponent(value - 1 == i, 500);
};

Content.getComponent("MODSEL1").setControlCallback(onMODSEL1Control);



const var MODSEL2 = Content.getComponent("MODSEL2");
const var mod2 = Synth.getModulator("mod2");
const var mods2 = [];

mods2[0] = Content.getComponent("env2");
mods2[1] = Content.getComponent("table2");
mods2[2] = Content.getComponent("8STEP3");
mods2[3] = Content.getComponent("8STEP4");

inline function onMODSEL2Control(component, value)
{
	
mod2.setAttribute(mod2.modsel, value);

for (i = 0; i < mods2.length; i++)
        mods2[i].fadeComponent(value - 1 == i, 500);
};

Content.getComponent("MODSEL2").setControlCallback(onMODSEL2Control);

const var MODSEL3 = Content.getComponent("MODSEL3");
const var mod3 = Synth.getModulator("mod3");
const var mods3 = [];

mods3[0] = Content.getComponent("table3");
mods3[1] = Content.getComponent("8STEP5");
mods3[2] = Content.getComponent("LFO3");
mods3[3] = Content.getComponent("8STEP6");


inline function onMODSEL3Control(component, value)
{
	
mod3.setAttribute(mod3.modsel, value);

for (i = 0; i < mods3.length; i++)
        mods3[i].fadeComponent(value - 1 == i, 500);
};

Content.getComponent("MODSEL3").setControlCallback(onMODSEL3Control);

const var MODSEL4 = Content.getComponent("MODSEL4");
const var mod4 = Synth.getModulator("mod4");
const var mods4 = [];

mods4[0] = Content.getComponent("table4");
mods4[1] = Content.getComponent("8STEP7");
mods4[2] = Content.getComponent("LFO4");
mods4[3] = Content.getComponent("8STEP8");


inline function onMODSEL4Control(component, value)
{
mod4.setAttribute(mod4.modsel, value);

for (i = 0; i < mods4.length; i++)
        mods4[i].fadeComponent(value - 1 == i, 500);
};

Content.getComponent("MODSEL4").setControlCallback(onMODSEL4Control);

const var ModPage = Content.getComponent("ModPage");

const var m1 = Content.getComponent("m1");
const var m2 = Content.getComponent("m2");
const var m3 = Content.getComponent("m3");
const var m4 = Content.getComponent("m4");




inline function onModPageControl(component, value)
{
	m1.showControl(value); 
		m2.showControl(value); 
        m3.showControl(1-value);
        m4.showControl(1-value);
};

Content.getComponent("ModPage").setControlCallback(onModPageControl);

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
 