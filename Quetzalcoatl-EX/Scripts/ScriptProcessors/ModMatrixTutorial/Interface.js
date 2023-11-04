include("UI/RectHelpers.js");


Content.makeFrontInterface(800, 700);

Synth.setUseUniformVoiceHandler("ModMatrixTutorial", true);

const var matrix = Engine.createModulationMatrix("Global Modulator Container1");

matrix.setUseUndoManager(true);

matrix.setEditCallback(function(name)
{
	
});

matrix.addModulatorTarget({
	"Target": "OSC 1",
	"Chain": matrix.Gain,
	"ID": "OSC 1 Gain",
	"Component": "Knob1",
	"Slots": [2, 2, 1]
});


matrix.addModulatorTarget({
	"Target": "OSC 1",
	"Chain": matrix.Pitch,
	"ID": "OSC 1 Pitch",
	"Component": "Knob3",
	"Slots": [1, 1, 1]
});

matrix.addModulatorTarget({
	"Target": "OSC 1 StereoFX",
	"Chain": 0,
	"ID": "OSC 1 Pan",
	"Component": "Knob2",
	"Slots": [2, 1, 1]
});

matrix.addModulatorTarget({
	"Target": "OSC 1 Filter",
	"Chain": matrix.Frequency,
	"ID": "OSC 1 Frequency",
	"Component": "Knob5",
	"Slots": [2, 2, 1]
});

matrix.addParameterTarget({
	"Target": "OSC 1 Reverb",
	"Parameter": "WetLevel",
	"ID": "OSC 1 Reverb",
	"Component": "Knob4",
	"Mode": matrix.Bipolar
});

include("TableLogic.js");
include("UI/TableLookAndFeel.js");
include("UI/KnobLookAndFeel.js");
include("UI/DragPanel.js");
include("UI/PageLogic.js");






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
 