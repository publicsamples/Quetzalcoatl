Processor 
Type SynthChain ID fxex Bypassed Gain 	      ??Balance 	        VoiceLimit 	      P@KillFadeTime 	      4@IconColour 0 packageName  BuildVersion ?  EditorStates BodyShown 0 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type ScriptProcessor ID Interface Bypassed Script ?Content.makeFrontInterface(600, 600);function onNoteOn()
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
  EditorStates BodyShown 1 Visible 1 Solo 0 contentShown 1 onInitOpen 1  ChildProcessors   Content   UIData  ContentProperties DeviceType 	Desktop  Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      ??EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type 
ScriptFX ID Script FX1 Bypassed Script ? function prepareToPlay(sampleRate, blockSize)
{
	
}
 function processBlock(channels)
{
	
}
 function onControl(number, value)
{
	
}
  EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ????Channel1    Send1 ???? Content   Networks  Network ID script_fx1 AllowCompilation 1 Version 0.0.0 Node FactoryPath container.chain ID script_fx1 Bypassed 0 Nodes  Node ID midichain FactoryPath container.midichain Bypassed 0 Nodes  Node ID frame2_block FactoryPath container.frame2_block Bypassed 0 Nodes  Node ID split FactoryPath container.split Bypassed 0 Nodes  Node ID chain FactoryPath container.chain Bypassed 0 Nodes  Node ID oscillator1 FactoryPath core.oscillator Bypassed 0 ComplexData  DisplayBuffers  DisplayBuffer Index -1  Parameters  Parameter MinValue 0.0 MaxValue 4.0 StepSize 1.0 ID Mode Value 0.0  Parameter MinValue 20.0 MaxValue 	20000.0 StepSize 0.1000000014901161 SkewFactor 0.2299045622348785 ID Frequency Value 220.0  Parameter MinValue 0.5 MaxValue 16.0 StepSize 1.0 ID Freq Ratio Value 0.5  Parameter MinValue 0.0 MaxValue 1.0 StepSize 1.0 ID Gate Value 1.0  Parameter MinValue 0.0 MaxValue 1.0 ID Phase Value 0.0  Parameter MinValue 0.0 MaxValue 1.0 ID Gain Value 1.0  Node ID 	sig2mod FactoryPath math.sig2mod Bypassed 0 Parameters  Parameter MinValue 0.0 MaxValue 1.0 ID Value Value 0.0  Node ID peak FactoryPath core.peak Bypassed 0 ModulationTargets  Connection NodeId oscillator2 ParameterId Freq Ratio  ComplexData  DisplayBuffers  DisplayBuffer Index -1  Parameters   Node ID clear FactoryPath math.clear Bypassed 0 Parameters  Parameter MinValue 0.0 MaxValue 1.0 ID Value Value 0.0  Parameters   Node ID chain1 FactoryPath container.chain Bypassed 0 Nodes  Node ID oscillator2 FactoryPath core.oscillator Bypassed 0 ComplexData  DisplayBuffers  DisplayBuffer Index -1  Parameters  Parameter MinValue 0.0 MaxValue 4.0 StepSize 1.0 ID Mode Value 0.0  Parameter MinValue 20.0 MaxValue 	20000.0 StepSize 0.1000000014901161 SkewFactor 0.2299045622348785 ID Frequency Value 220.0  Parameter MinValue 0.0 MaxValue 4.0 ID Freq Ratio Automated 1  Parameter MinValue 0.0 MaxValue 1.0 StepSize 1.0 ID Gate Value 1.0  Parameter MinValue 0.0 MaxValue 1.0 ID Phase Value 0.0  Parameter MinValue 0.0 MaxValue 1.0 ID Gain Value 1.0  Parameters   Parameters   Parameters   Node ID simple_ar FactoryPath envelope.simple_ar Bypassed 0 Properties  Property ID NumParameters Value     SwitchTargets  SwitchTarget  Connections   SwitchTarget  Connections   ComplexData  DisplayBuffers  DisplayBuffer Index -1 EmbeddedData   Parameters  Parameter MinValue 0.0 MaxValue 1000.0 StepSize 0.1000000014901161 SkewFactor 0.3010300099849701 ID Attack Value 10.0  Parameter MinValue 0.0 MaxValue 1000.0 StepSize 0.1000000014901161 SkewFactor 0.3010300099849701 ID 	Release Value 10.0  Parameter MinValue 0.0 MaxValue 1.0 StepSize 1.0 ID Gate Value 0.0  Parameter MinValue 0.0 MaxValue 1.0 ID AttackCurve Value 0.0  Parameters   Parameters   UIData  ContentProperties DeviceType 	Desktop  RoutingMatrix NumSourceChannels    Channel0     Send0 ????Channel1    Send1 ???? macro_controls  macro name 	Macro 1 value 0.0 midi_cc -1  macro name 	Macro 2 value 0.0 midi_cc -1  macro name 	Macro 3 value 0.0 midi_cc -1  macro name 	Macro 4 value 0.0 midi_cc -1  macro name 	Macro 5 value 0.0 midi_cc -1  macro name 	Macro 6 value 0.0 midi_cc -1  macro name 	Macro 7 value 0.0 midi_cc -1  macro name 	Macro 8 value 0.0 midi_cc -1  MidiAutomation   MPEData Enabled  