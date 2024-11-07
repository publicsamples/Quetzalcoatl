Content.makeFrontInterface(600, 600);


const var MetaScreens = [];


MetaScreens[0] = Content.getComponent("TABLE");
MetaScreens[1] = Content.getComponent("ScriptSliderPack1");
MetaScreens[2] = Content.getComponent("AudioWaveform1");

const var ScriptFX1 = Synth.getEffect("Script FX1");

inline function onModesControl(component, value)
{
 ScriptFX1.setAttribute(ScriptFX1.ModeSelect, value);
 
 for (i = 0; i < MetaScreens.length; i++)
        MetaScreens[i].showControl(value - 1 == i);
	

};

Content.getComponent("Modes").setControlCallback(onModesControl);
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
 