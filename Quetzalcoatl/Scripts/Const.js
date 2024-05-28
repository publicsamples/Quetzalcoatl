//mods
const var m1step = Content.getComponent("m1step");
const var m1step1 = Content.getComponent("m1step1");
const var m1step2 = Content.getComponent("m1step2");
const var m1step3 = Content.getComponent("m1step3");
const var m1step4 = Content.getComponent("m1step4");
const var m1step5 = Content.getComponent("m1step5");
const var m1step6 = Content.getComponent("m1step6");
const var m1step7 = Content.getComponent("m1step7");

const var m1table = Content.getComponent("m1table");
const var m1table1 = Content.getComponent("m1table1");
const var m1table2 = Content.getComponent("m1table2");
const var m1table3 = Content.getComponent("m1table3");
const var m1table4 = Content.getComponent("m1table4");
const var m1table5 = Content.getComponent("m1table5");
const var m1table6 = Content.getComponent("m1table6");
const var m1table7 = Content.getComponent("m1table7");



const var Gmod3 = Synth.getModulator("Gmod3");
const var Gmod4 = Synth.getModulator("Gmod4");
const var Gmod5 = Synth.getModulator("Gmod5");
const var Gmod6 = Synth.getModulator("Gmod6");
const var Gmod7 = Synth.getModulator("Gmod7");
const var Gmod8 = Synth.getModulator("Gmod8");


const var Vel = [Synth.getModulator("Velocity Modulator1"),
 					Synth.getModulator("Velocity Modulator2"),
 					Synth.getModulator("Velocity Modulator3"),
 					Synth.getModulator("Velocity Modulator4"),
 					Synth.getModulator("Velocity Modulator5"),
 					Synth.getModulator("Velocity Modulator6"),
 					Synth.getModulator("Velocity Modulator7"),
 					Synth.getModulator("Velocity Modulator8")];


const var Waves = [];

Waves[0] = Content.getComponent("Wave1");
Waves[1] = Content.getComponent("Wave2");
Waves[2] = Content.getComponent("Wave3");
Waves[3] = Content.getComponent("Wave4");
Waves[4] = Content.getComponent("Wave5");
Waves[5] = Content.getComponent("Wave6");
Waves[6] = Content.getComponent("Wave7");
Waves[7] = Content.getComponent("Wave8");
	
	

const var Sample1 = Content.getComponent("Sample1");
const var Sample2 = Content.getComponent("Sample2");
const var Sample3 = Content.getComponent("Sample3");
const var Sample4 = Content.getComponent("Sample4");
const var Sample5 = Content.getComponent("Sample5");
const var Sample6 = Content.getComponent("Sample6");
const var Sample7 = Content.getComponent("Sample7");
const var Sample8 = Content.getComponent("Sample8");
const var Sample9 = Content.getComponent("Sample9");

const var SamplerA1 = Synth.getSampler("SamplerA1");
const var SamplerA2 = Synth.getSampler("SamplerA2");
const var SamplerA3 = Synth.getSampler("SamplerA3");
const var SamplerA4 = Synth.getSampler("SamplerA4");
const var SamplerA5 = Synth.getSampler("SamplerA5");
const var SamplerA6 = Synth.getSampler("SamplerA6");
const var SamplerA7 = Synth.getSampler("SamplerA7");
const var SamplerA8 = Synth.getSampler("SamplerA8");

const var Groups = [Synth.getChildSynth("Group1"), Synth.getChildSynth("Group2"), Synth.getChildSynth("Group3"), Synth.getChildSynth("Group4"),Synth.getChildSynth("Group5"), Synth.getChildSynth("Group6"),  Synth.getChildSynth("Group7"), Synth.getChildSynth("Group8")];

const var Samplers = [Synth.getChildSynth("SamplerA1"),
					Synth.getChildSynth("SamplerA2"),
					Synth.getChildSynth("SamplerA3"),
					Synth.getChildSynth("SamplerA4"),
					Synth.getChildSynth("SamplerA5"),
					Synth.getChildSynth("SamplerA6"),
					Synth.getChildSynth("SamplerA7"),
					Synth.getChildSynth("SamplerA8")];
					


				
const var loops = [Synth.getChildSynth("LoopA2"),
				Synth.getChildSynth("LoopA2"),
				Synth.getChildSynth("LoopA3"),
				Synth.getChildSynth("LoopA4"),
				Synth.getChildSynth("LoopA5"),
				Synth.getChildSynth("LoopA6"),
				Synth.getChildSynth("LoopA7"),
				Synth.getChildSynth("LoopA8")];		
				



const var Group1 = Synth.getChildSynth("Group1");
const var Group2 = Synth.getChildSynth("Group2");
const var Group3 = Synth.getChildSynth("Group3");
const var Group4 = Synth.getChildSynth("Group4");
const var Group5 = Synth.getChildSynth("Group5");
const var Group6 = Synth.getChildSynth("Group6");
const var Group7 = Synth.getChildSynth("Group7");
const var Group8 = Synth.getChildSynth("Group8");
					

const var loop1 = Synth.getChildSynth("LoopA1");
const var loop2 = Synth.getChildSynth("LoopA2");
const var loop3 = Synth.getChildSynth("LoopA3");
const var loop4 = Synth.getChildSynth("LoopA4");
const var loop5 = Synth.getChildSynth("LoopA5");
const var loop6 = Synth.getChildSynth("LoopA6");
const var loop7 = Synth.getChildSynth("LoopA7");
const var loop8 = Synth.getChildSynth("LoopA8");	
	

const var SampleWave1 = Content.getComponent("SamplerWave1");
const var SampleWave2 = Content.getComponent("SamplerWave2");
const var SampleWave3 = Content.getComponent("SamplerWave3");
const var SampleWave4 = Content.getComponent("SamplerWave4");
const var SampleWave5 = Content.getComponent("SamplerWave5");
const var SampleWave6 = Content.getComponent("SamplerWave6");
const var SampleWave7 = Content.getComponent("SamplerWave7");
const var SampleWave8 = Content.getComponent("SamplerWave8");


const var Waves1 = Content.getComponent("Waves1");
const var Waves2 = Content.getComponent("Waves2");
const var Waves3 = Content.getComponent("Waves3");
const var Waves4 = Content.getComponent("Waves4");
const var Waves5 = Content.getComponent("Waves5");
const var Waves6 = Content.getComponent("Waves6");
const var Waves7 = Content.getComponent("Waves7");
const var Waves8 = Content.getComponent("Waves8");
const var Waves9 = Content.getComponent("Waves9"); 
                     
                     
const var UserWave1 = Content.getComponent("UserWave1");
const var UserWave2 = Content.getComponent("UserWave2");
const var UserWave3 = Content.getComponent("UserWave3");
const var UserWave4 = Content.getComponent("UserWave4");
const var UserWave5 = Content.getComponent("UserWave5");
const var UserWave6 = Content.getComponent("UserWave6");
const var UserWave7 = Content.getComponent("UserWave7");
const var UserWave8 = Content.getComponent("UserWave8");


const var LpControls1 = Content.getComponent("LpControls1");
const var LpControls2 = Content.getComponent("LpControls2");
const var LpControls3 = Content.getComponent("LpControls3");
const var LpControls4 = Content.getComponent("LpControls4");
const var LpControls5 = Content.getComponent("LpControls5");
const var LpControls6 = Content.getComponent("LpControls6");
const var LpControls7 = Content.getComponent("LpControls7");
const var LpControls8 = Content.getComponent("LpControls8");



const var Lwav1 = Synth.getAudioSampleProcessor("LoopA1");
const var Lwav2 = Synth.getAudioSampleProcessor("LoopA2");
const var Lwav3 = Synth.getAudioSampleProcessor("LoopA3");
const var Lwav4 = Synth.getAudioSampleProcessor("LoopA4");
const var Lwav5 = Synth.getAudioSampleProcessor("LoopA5");
const var Lwav6 = Synth.getAudioSampleProcessor("LoopA6");
const var Lwav7 = Synth.getAudioSampleProcessor("LoopA7");
const var Lwav8 = Synth.getAudioSampleProcessor("LoopA8");



const var ScriptImage2 = Content.getComponent("ScriptImage2");

const var LoopA1 = Synth.getAudioSampleProcessor("LoopA1");
const var LoopA2 = Synth.getAudioSampleProcessor("LoopA2");
const var LoopA3 = Synth.getAudioSampleProcessor("LoopA3");
const var LoopA4 = Synth.getAudioSampleProcessor("LoopA4");
const var LoopA5 = Synth.getAudioSampleProcessor("LoopA5");
const var LoopA6 = Synth.getAudioSampleProcessor("LoopA6");
const var LoopA7 = Synth.getAudioSampleProcessor("LoopA7");
const var LoopA8 = Synth.getAudioSampleProcessor("LoopA8");
const var Sampler1 = Synth.getChildSynth("SamplerA1");
const var Sampler2 = Synth.getChildSynth("SamplerA2");
const var Sampler3 = Synth.getChildSynth("SamplerA3");
const var Sampler4 = Synth.getChildSynth("SamplerA4");
const var Sampler5 = Synth.getChildSynth("SamplerA5");
const var Sampler6 = Synth.getChildSynth("SamplerA6");
const var Sampler7 = Synth.getChildSynth("SamplerA7");
const var Sampler8 = Synth.getChildSynth("SamplerA8");


const var GainSliders = Content.getComponent("GainSliders");



             
//osc


                   
const var SampleGroups = [Synth.getChildSynth("Group1"),
                     Synth.getChildSynth("Group2"),
                     Synth.getChildSynth("Group3"),
                     Synth.getChildSynth("Group4"),
                     Synth.getChildSynth("Group5"),
                     Synth.getChildSynth("Group6"),
                     Synth.getChildSynth("Group7"),
                     Synth.getChildSynth("Group8")];
                     
                     
const var SampleComp = [ 
                     Content.getComponent("Waves1"),
                     Content.getComponent("Waves2"),
                     Content.getComponent("Waves3"),
                     Content.getComponent("Waves4"),
                     Content.getComponent("Waves5"),
                     Content.getComponent("Waves6"),
                     Content.getComponent("Waves7"),
                     Content.getComponent("Waves8")];
                     
                     
                     


                     
const var LoopComp = [Content.getComponent("UserWave1"),
                     Content.getComponent("UserWave2"),
                     Content.getComponent("UserWave3"),
                     Content.getComponent("UserWave4"),
                     Content.getComponent("UserWave5"),
                     Content.getComponent("UserWave6"),
                     Content.getComponent("UserWave7"),
                     Content.getComponent("UserWave8"),
                     Content.getComponent("LpControls1"),
                     Content.getComponent("LpControls1"),
                     Content.getComponent("LpControls2"),
                     Content.getComponent("LpControls3"),
                     Content.getComponent("LpControls4"),
                     Content.getComponent("LpControls5"),
                     Content.getComponent("LpControls6"),
                     Content.getComponent("LpControls7"),
                     Content.getComponent("LpControls8")];




const var Gmod1 = Synth.getModulator("Gmod1");
const var Gmod2 = Synth.getModulator("Gmod2");

const var mods3 = [];

mods3[0] = Content.getComponent("LFO1");
mods3[1] = Content.getComponent("Table3");
mods3[2] = Content.getComponent("8step3");




const var Osc1 = [Synth.getChildSynth("SamplerA1"),
				  Synth.getChildSynth("SamplerA2"),
				  Synth.getChildSynth("SamplerA3"),
				  Synth.getChildSynth("SamplerA4"),
				  Synth.getChildSynth("SamplerA5"),
				  Synth.getChildSynth("SamplerA6"),
				  Synth.getChildSynth("SamplerA7"),
				  Synth.getChildSynth("SamplerA8"),
				  Synth.getChildSynth("LoopA1"),
				  Synth.getChildSynth("LoopA2"),
				  Synth.getChildSynth("LoopA3"),
				  Synth.getChildSynth("LoopA4"),
				  Synth.getChildSynth("LoopA5"),
				  Synth.getChildSynth("LoopA6"),
				  Synth.getChildSynth("LoopA7"),
				 Synth.getChildSynth("LoopA8")];


