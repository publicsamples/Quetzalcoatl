Processor 
Type SynthChain ID Plattenspieler Bypassed Gain 	      ??Balance 	        VoiceLimit 	      P@KillFadeTime 	      4@IconColour 0 packageName  BuildVersion ?  EditorStates BodyShown 0 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type ScriptProcessor ID Interface Bypassed Script Content.makeFrontInterface(600, 500);

const var Panel1 = Content.getComponent("Panel1");
const var Button1 = Content.getComponent("Button1");

reg index = 0; // index of the filmstrip 
reg total_frames = 124; // total frames in the filmstrip
reg frame_height = 650; // the height(y) of each frame


Panel1.loadImage("{PROJECT_FOLDER}q3.png", "dot");

Panel1.setPaintRoutine(function(g){
    
    g.drawImage("dot", [0, 0, this.get("width"), this.get("height")], 0, index * frame_height);
});

Panel1.setTimerCallback(function(){
    index = (index + 1) % total_frames;
    this.repaint();
});


// Custom Callback for Button1

inline function onButton1Control(component, value)
{
	if (value)
    {  
        Panel1.startTimer(100);
    }
    else
    {
        Panel1.stopTimer();
    }
};

Content.getComponent("Button1").setControlCallback(onButton1Control);
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
  EditorStates BodyShown 1 Visible 1 Solo 0 contentShown 1 onInitOpen 1  ChildProcessors   Content  Control type ScriptButton id 	Button1 value 	      ?? UIData  ContentProperties DeviceType 	Desktop Component type ScriptPanel id Panel1 x 	     @e@y 	      N@width   height    Component type ScriptButton id 	Button1 x 	      0@y 	     ?Y@text start width 	      _@ Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      ??EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ????Channel1    Send1 ???? macro_controls  macro name 	Macro 1 value 0.0 midi_cc -1  macro name 	Macro 2 value 0.0 midi_cc -1  macro name 	Macro 3 value 0.0 midi_cc -1  macro name 	Macro 4 value 0.0 midi_cc -1  macro name 	Macro 5 value 0.0 midi_cc -1  macro name 	Macro 6 value 0.0 midi_cc -1  macro name 	Macro 7 value 0.0 midi_cc -1  macro name 	Macro 8 value 0.0 midi_cc -1  MidiAutomation   MPEData Enabled  