Processor 
Type SynthChain ID Preset Bypassed Gain 	      �?Balance 	        VoiceLimit 	      P@KillFadeTime 	      4@IconColour 0 packageName  BuildVersion �  EditorStates BodyShown 0 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type ScriptProcessor ID Interface Bypassed Script �Content.makeFrontInterface(600, 600);


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
  EditorStates BodyShown 1 Visible 1 Solo 0 contentShown 1 onInitOpen 1  ChildProcessors   Content  Control type ScriptSlider id M1 value 	      �? Control type ScriptComboBox id Modes value 	      @ Control type ScriptSlider id M2 value 	         Control type ScriptSlider id M3 value 	   @33�? Control type ScriptSlider id OVERSAMPLE value 	         Control type ScriptSlider id FilterMode value 	         Control type ScriptSlider id q value 	   @33�? Control type ScriptSlider id cutoff value 	      �? Control type ScriptAudioWaveform id AudioWaveform1 value 	        data  rangeStart     rangeEnd      Control type ScriptTable id TABLE value 	        data 536...............vO2c289fsfs5iSc41O...f+.1B1xyQ9EiO  Control type ScriptSliderPack id ScriptSliderPack1 value 	      1@data e72.CWOZ+35Qg7Sb8nvOJb8n9....5CWOJjOZlYF9nYlY3SOJbkOOJbc97nv04yiBWmOOJbc97nv04yiBWmOOJbc97Qgq4yGEtlO  Control type ScriptSlider id 	SpSteps value 	      2@ Control type ScriptSlider id mix value 	      �? Control type ScriptSlider id 	CompMod value 	         Control type ScriptSlider id 
CompMod1 value 	      Y� Control type ScriptSlider id Ratio value 	   @33@ Control type ScriptSlider id 	Release value 	     @P@ Control type ScriptSlider id Attack value 	         UIData  ContentProperties DeviceType 	Desktop Component 	type ScriptPanel id Panel2 x 	        y 	        width �  height *  itemColour2 	��3�    itemColour 	uq8�    locked  Component type ScriptSlider id M1 x 	      .@y 	       @processorId Script FX1 parameterId m1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@ Component type ScriptComboBox id Modes x 	     �y@y 	      @items �Table
Sliders
File
Xmod
RM SINE
RM SAW
RM SQUARE
Light COS
Heavy COS
Light SIN
Heavy SIN
Light Fold
Heavy Fold
Clipper
Clipper
squared
atan
asin
silly fold
 max     Component type ScriptSlider id M2 x 	     �S@y 	       @processorId Script FX1 parameterId m2 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width (   height (    Component type ScriptSlider id M3 x 	      c@y 	       @processorId Script FX1 parameterId m3 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@ Component type ScriptSlider id OVERSAMPLE x 	     u@y 	        processorId Script FX1 parameterId OverSampling max 	      @stepSize 1.0 middlePosition 	       @filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 2   height (    Component type ScriptSlider id FilterMode x 	      .@y 	      c@processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@text F parameterId mode max 	       @stepSize 1.0  Component type ScriptSlider id q x 	      c@y 	     �T@processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@min 	333333�?max 	������#@ Component type ScriptSlider id cutoff x 	     �S@y 	     �T@processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@parameterId cut  Component type ScriptPanel id Panel1 x 	     �i@y 	      C@width J  height   Component type ScriptAudioWaveform id AudioWaveform1 x 	      (@y 	      $@parentComponent Panel1 width 	     �r@height 	     �f@visible  Component 	type ScriptTable id TABLE x 	      (@y 	      $@width 	     �r@height 	     �f@processorId Script FX1 parentComponent Panel1 visible  Component 
type ScriptSliderPack id ScriptSliderPack1 x 	      (@y 	      $@width 	     �r@height 	     �f@parentComponent Panel1 processorId Script FX1 flashActive visible Component type ScriptSlider id 	SpSteps x   y    processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@parameterId 	Sliders parentComponent ScriptSliderPack1 min 	      @max 	      P@stepSize 1.0 middlePosition 	      A@ Component type ScriptSlider id mix x 	      .@y 	     �T@processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@parameterId Mix  Component type ScriptLabel id label x 	      .@y 4   bgColour 	   �    text M1 width (   height     Component type ScriptLabel id label1 x 	     �S@y 4   bgColour 	   �    text M2 width (   height     Component type ScriptLabel id label2 x 	      c@y 4   bgColour 	   �    text M3 width (   height     Component type ScriptLabel id label3 x 	      .@y 	      _@bgColour 	   �    text MIX width (   height     Component type ScriptLabel id label4 x 	     �n@y 	      "@bgColour 	   �    text OVERSAMPLE width P   height     Component type ScriptLabel id label5 x 	     @Q@y 	      _@bgColour 	   �    text CUTOFF width <   height     Component type ScriptLabel id label6 x 	      c@y 	      _@bgColour 	   �    text Q width    height     Component type ScriptSlider id 	CompMod x 	     �S@y 	      c@processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@text F parameterId 	compmod min 	      �middlePosition 	         Component type ScriptSlider id 
CompMod1 x 	      c@y 	      c@processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@text F parameterId thresh mode 	Decibel min 	      Y�max 	        stepSize 	�������?suffix  dB middlePosition 	     2� Component type ScriptSlider id Ratio x 	      c@y 	     �k@processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@text F parameterId ratio min 	      �?max 	      @@stepSize 0.1 middlePosition 	     �0@ Component type ScriptSlider id 	Release x 	     �S@y 	     �k@processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@text F parameterId 	release mode Time max 	     @o@stepSize 	      �?suffix  ms middlePosition 	     @_@ Component type ScriptSlider id Attack x 	      .@y 	     �k@processorId Script FX1 filmstripImage {PROJECT_FOLDER}k9.png numStrips 125 isVertical showTextBox width 	      I@text F parameterId attack mode Time max 	     @o@stepSize 	      �?suffix  ms middlePosition 	     @_@ Component type ScriptLabel id label7 x 	     �`@y 	     @h@bgColour 	   �    text THRESHOLD width F   height     Component type ScriptLabel id label8 x 	      Q@y 	     @h@bgColour 	   �    text 
COMP MOD width <   height     Component type ScriptLabel id label9 x 	      *@y 	     @h@bgColour 	   �    text F.TYPE width (   height     Component type ScriptLabel id RATIO x 	      b@y 	      q@bgColour 	   �    width 2   height     Component type ScriptLabel id 	label11 x 	      Q@y 	      q@bgColour 	   �    text 	RELEASE width <   height     Component type ScriptLabel id 	label12 x 	      $@y 	      q@bgColour 	   �    text ATTACK width 2   height     Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type 
Analyser ID Analyser1 Bypassed BufferSize 	      �@PreviewType 	      @EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Processor Type AudioLooper ID Audio Loop Player1 Bypassed Gain 	   �}�?Balance 	        VoiceLimit 	      p@KillFadeTime 	      4@IconColour 0 SyncMode 	      �?PitchTracking 	        LoopEnabled 	      �?RootNote 	      P@SampleStartMod 	        Reversed 	        FileName d/Library/Application Support/modularsamples/oi grandad/AudioFiles/Stems/SomethingInTheWater-06.wav min     max �S loopStart     loopEnd �S EditorStates BodyShown 1 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor 	Type SimpleEnvelope ID DefaultEnvelope1 Bypassed Monophonic 	        Retrigger 	      �?Intensity 	      �?Attack 	      @Release 	      $@LinearMode 	      �?EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors  Processor Type ModulatorChain ID Attack Time Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type PolyshapeFX ID Polyshape FX1 Bypassed Curve �144...............vO7bDn8...l8C...vO490E9.........vOw39U9...j8C...vO1kTY9.........vO9qKo9...38C...vOWRku9.........vOqF779....9C...vOrKoB+.........vO7bDH+....9C...vO9v3N+.........vO...f+....9i...0O AsymetricalCurve  Drive 	        Mode 	      @@Oversampling 	        EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors  Processor Type ModulatorChain ID Drive Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   Processor Type 
ScriptFX ID Script FX1 Bypassed NumTables    NumSliderPacks    NumAudioFiles    Script � function prepareToPlay(sampleRate, blockSize)
{
	
}
 function processBlock(channels)
{
	
}
 function onControl(number, value)
{
	
}
  EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Content   Networks  Network ID Camel Version 0.0.0  UIData  ContentProperties DeviceType 	Desktop  Processor Type 	ShapeFX ID Shape FX1 Bypassed Curve  BiasLeft 	   `���?BiasRight 	        HighPass 	      4@LowPass 	     ��@Mode 	      @Oversampling 	      �?Gain 	        Reduce 	        Autogain 	      �?LimitInput 	      �?Drive 	        Mix 	      �?BypassFilters 	        EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� macro_controls  macro name 	Macro 1 value 	        midi_cc ���� macro name 	Macro 2 value 	        midi_cc ���� macro name 	Macro 3 value 	        midi_cc ���� macro name 	Macro 4 value 	        midi_cc ���� macro name 	Macro 5 value 	        midi_cc ���� macro name 	Macro 6 value 	        midi_cc ���� macro name 	Macro 7 value 	        midi_cc ���� macro name 	Macro 8 value 	        midi_cc ���� MidiAutomation   MPEData Enabled  