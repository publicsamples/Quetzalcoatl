Content.makeFrontInterface(820, 690);



//Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
Engine.loadAudioFilesIntoPool();

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
   g.setFont("Montserrat", 18.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");

});

//Settings.setVoiceMultiplier(2);
Settings.setZoomLevel(1.05);

include("Samples.js");
include("Filters.js");
include("Mod.js");
include("Xfade.js");
//include("FM.js");
include("Const.js");
include("Misc.js");


const var Pres = [Synth.getEffect("pre1"),
					Synth.getEffect("pre2"),
					Synth.getEffect("pre3"),
					Synth.getEffect("pre4"),
					Synth.getEffect("pre5"),
					Synth.getEffect("pre6"),
					Synth.getEffect("pre7"),
					Synth.getEffect("pre8")];


inline function onPreOffControl(component, value)
{
	
for(s in Pres)
       s.setAttribute(0, value);
};

Content.getComponent("PreOff").setControlCallback(onPreOffControl);


//Pitch/Harmonic

const var Pitches = [Synth.getModulator("PitchA1"),
						Synth.getModulator("PitchA2"),
						Synth.getModulator("PitchA3"),
						Synth.getModulator("PitchA4"),
						Synth.getModulator("PitchA5"),
						Synth.getModulator("PitchA6"),
						Synth.getModulator("PitchA7"),
						Synth.getModulator("PitchA8")];
						
						
inline function onHarmControl(component, value)
{
   for(s in Pitches)
       s.setAttribute(2, value);
       
};

Content.getComponent("Harm").setControlCallback(onHarmControl);						

inline function onPitchModeControl(component, value)
{
for(s in Pitches)
       s.setAttribute(3, value);
       
};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);


inline function onHarmGlobalControl(component, value)
{
	 for(s in Pitches)
	 	 	 s.setAttribute(10, value);
};

Content.getComponent("HarmGlobal").setControlCallback(onHarmGlobalControl);


inline function onHarmModSrcControl(component, value)
{

	 for(s in Pitches)
	 	 	 s.setAttribute(11, value);

};

Content.getComponent("HarmModSrc").setControlCallback(onHarmModSrcControl);


inline function onHarmVelControl(component, value)
{
for(s in Pitches)
       s.setAttribute(12, value);
};

Content.getComponent("HarmVel").setControlCallback(onHarmVelControl);



const var O1Pitch = [Synth.getModulator("p1"),
					 Synth.getModulator("p2"),
					 Synth.getModulator("p3"),
					 Synth.getModulator("p4"),
					 Synth.getModulator("p5"),
					 Synth.getModulator("p6"),
					 Synth.getModulator("p7"),
					 Synth.getModulator("p8")];
					 
					 

inline function onDetuneControl(component, value)
{
	for(s in O1Pitch)
	       s.setIntensity(value);
};

Content.getComponent("Detune").setControlCallback(onDetuneControl);

const var s1 = Synth.getChildSynth("SamplerA1");





//User Pitches

inline function onUserPitch1Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(33, value);
};

Content.getComponent("UserPitch1").setControlCallback(onUserPitch1Control);

inline function onUserPitch2Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(34, value);
};

Content.getComponent("UserPitch2").setControlCallback(onUserPitch2Control);

inline function onUserPitch3Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(35, value);
};

Content.getComponent("UserPitch3").setControlCallback(onUserPitch3Control);

inline function onUserPitch4Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(36, value);
};

Content.getComponent("UserPitch4").setControlCallback(onUserPitch4Control);

inline function onUserPitch5Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(37, value);
};

Content.getComponent("UserPitch5").setControlCallback(onUserPitch5Control);

inline function onUserPitch6Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(38, value);
};

Content.getComponent("UserPitch6").setControlCallback(onUserPitch6Control);

inline function onUserPitch7Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(39, value);
};

Content.getComponent("UserPitch7").setControlCallback(onUserPitch7Control);

inline function onUserPitch8Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(40, value);
};

Content.getComponent("UserPitch8").setControlCallback(onUserPitch8Control);

inline function onUserPitch9Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(41, value);
};

Content.getComponent("UserPitch9").setControlCallback(onUserPitch9Control);

inline function onUserPitch10Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(42, value);
};

Content.getComponent("UserPitch10").setControlCallback(onUserPitch10Control);

inline function onUserPitch11Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(43, value);
};

Content.getComponent("UserPitch11").setControlCallback(onUserPitch11Control);

inline function onUserPitch12Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(44, value);
};

Content.getComponent("UserPitch12").setControlCallback(onUserPitch12Control);

inline function onUserPitch13Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(45, value);
};

Content.getComponent("UserPitch13").setControlCallback(onUserPitch13Control);

inline function onUserPitch14Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(46, value);
};

Content.getComponent("UserPitch14").setControlCallback(onUserPitch14Control);

inline function onUserPitch15Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(47, value);
};

Content.getComponent("UserPitch15").setControlCallback(onUserPitch15Control);

inline function onUserPitch16Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(48, value);
};

Content.getComponent("UserPitch16").setControlCallback(onUserPitch16Control);


const var UserTuners = [Content.getComponent("UserPitch1"),
                        Content.getComponent("UserPitch2"),
                        Content.getComponent("UserPitch3"),
                        Content.getComponent("UserPitch4"),
                        Content.getComponent("UserPitch8"),
                        Content.getComponent("UserPitch7"),
                        Content.getComponent("UserPitch6"),
                        Content.getComponent("UserPitch5"),
                        Content.getComponent("UserPitch9"),
                        Content.getComponent("UserPitch13"),
                        Content.getComponent("UserPitch14"),
                        Content.getComponent("UserPitch10"),
                        Content.getComponent("UserPitch11"),
                        Content.getComponent("UserPitch15"),
                        Content.getComponent("UserPitch16"),
                        Content.getComponent("UserPitch12")];


inline function onTuneModeControl(component, value)
{
	if(value == 0)
	{
		
		for(s in UserTuners)
       s.setRange(-24,24, 1);
       }
       
       if(value == 1)
       {
       	
       	for(s in UserTuners)
              s.setRange(-24, 24, 0.01);
              }
};

Content.getComponent("TuneMode").setControlCallback(onTuneModeControl);


//Mono/Unison


inline function onUNIControl(component, value)
{
		for(s in Groups)
       s.setAttribute(7, value);
};

Content.getComponent("UNI").setControlCallback(onUNIControl);


inline function onDetControl(component, value)
{
	for(s in Groups)
       s.setAttribute(8, value);
};

Content.getComponent("Det").setControlCallback(onDetControl);



inline function onSprdControl(component, value)
{
	for(s in Groups)
       s.setAttribute(9, value);
};

Content.getComponent("Sprd").setControlCallback(onSprdControl);

const var ModPages = [];
 
 ModPages[0] = Content.getComponent("XfPolyMod");
 ModPages[1] = Content.getComponent("HarmPolyMod");
 ModPages[2] = Content.getComponent("FilterPolyMod");


inline function onPolmodPageControl(component, value)
{
   for (i = 0; i < ModPages.length; i++)
                    ModPages[i].showControl(value - 1 == i);
};

Content.getComponent("PolmodPage").setControlCallback(onPolmodPageControl);

const var step2 = Content.getComponent("8step2");

const var LFO2 = Content.getComponent("LFO2");



 
 const var step3 = Content.getComponent("8step3");
 const var LFO3 = Content.getComponent("LFO3");
 
 inline function onMODSEL11Control(component, value)
 {
 	 if(value == 1)
	{
  	step3.showControl(1);
  	LFO3.showControl(0);
  	
  	for(s in Filters)
  	  	       s.setAttribute(51, 3.1);
  }
  
  if(value == 2)
    	{
   	step3.showControl(0);
   	LFO3.showControl(1);
   	for(s in Filters)
   	  	       s.setAttribute(51, 2.1);
      }
 };
 
 Content.getComponent("MODSEL11").setControlCallback(onMODSEL11Control);
 
 
 
 const var Shapers = [Synth.getEffect("Shape1"),
 					Synth.getEffect("Shape2"),
 					Synth.getEffect("Shape3"),
 					Synth.getEffect("Shape4"),
 					Synth.getEffect("Shape5"),
 					Synth.getEffect("Shape6"),
 					Synth.getEffect("Shape7"),
 					Synth.getEffect("Shape8")];
 					

inline function onShapeOffsetControl(component, value)
{
		for(s in Shapers)
       s.setAttribute(0, value);
};

Content.getComponent("ShapeOffset").setControlCallback(onShapeOffsetControl);

inline function onShapeSmoothControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(1, value);
};

Content.getComponent("ShapeSmooth").setControlCallback(onShapeSmoothControl);


inline function onShapeMixControl(component, value)
{
		for(s in Shapers)
       s.setAttribute(2, value);
};

Content.getComponent("ShapeMix").setControlCallback(onShapeMixControl);



inline function onShapeModeControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(3, value);
};

Content.getComponent("ShapeMode").setControlCallback(onShapeModeControl);



inline function onShapeDriveControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(4, value);
};

Content.getComponent("ShapeDrive").setControlCallback(onShapeDriveControl);


inline function onShapeEnv1Control(component, value)
{
	for(s in Shapers)
       s.setAttribute(5, value);
};

Content.getComponent("ShapeEnv1").setControlCallback(onShapeEnv1Control);



inline function onShapeEnv2Control(component, value)
{
	for(s in Shapers)
       s.setAttribute(6, value);
};

Content.getComponent("ShapeEnv2").setControlCallback(onShapeEnv2Control);


inline function onShapeModControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(7, value);
};

Content.getComponent("ShapeMod").setControlCallback(onShapeModControl);


inline function onShpGblControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(8, value);
};

Content.getComponent("ShpGbl").setControlCallback(onShpGblControl);


inline function onShpGlbSrcControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(9, value);
};

Content.getComponent("ShpGlbSrc").setControlCallback(onShpGlbSrcControl);


inline function onShpVelControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(9, value);
};

Content.getComponent("ShpVel").setControlCallback(onShpVelControl);

inline function onHarmTempoControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(14, value);
};

Content.getComponent("HarmTempo").setControlCallback(onHarmTempoControl);


inline function onHarmDivControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(15, value);
};

Content.getComponent("HarmDiv").setControlCallback(onHarmDivControl);


inline function onHarmTrigControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(16, value);
};

Content.getComponent("HarmTrig").setControlCallback(onHarmTrigControl);



 inline function onMODSEL2Control(component, value)
 {
 if(value == 1)
	{
  	step2.showControl(1);
  	LFO2.showControl(0);
  	
  	for(s in Shapers)
  	  	       s.setAttribute(51, 3.1);
  }
  
  if(value == 2)
    	{
   	step2.showControl(0);
   	LFO2.showControl(1);
   	for(s in Shapers)
   	  	       s.setAttribute(51, 2.1);
      }
 };
 
 Content.getComponent("MODSEL2").setControlCallback(onMODSEL2Control);

inline function onLfoShapeHarmControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(17, value);
};

Content.getComponent("LfoShapeHarm").setControlCallback(onLfoShapeHarmControl);


inline function onHarmAControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(18, value);
};

Content.getComponent("HarmA").setControlCallback(onHarmAControl);


inline function onHarmDControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(19, value);
};

Content.getComponent("HarmD").setControlCallback(onHarmDControl);


inline function onHarmSControl(component, value)
{
	for(s in Shapers)
       s.setAttribute(20, value);
};

Content.getComponent("HarmS").setControlCallback(onHarmSControl);


inline function onHarmRControl(component, value)
{
for(s in Shapers)
       s.setAttribute(21, value);
};

Content.getComponent("HarmR").setControlCallback(onHarmRControl);


inline function onHarmA2Control(component, value)
{
	for(s in Shapers)
	       s.setAttribute(22, value);
};

Content.getComponent("HarmA2").setControlCallback(onHarmA2Control);


inline function onHarmR2Control(component, value)
{
		for(s in Shapers)
	       s.setAttribute(23, value);
};

Content.getComponent("HarmR2").setControlCallback(onHarmR2Control);


inline function onHarmTempo2Control(component, value)
{
		for(s in Shapers)
	       s.setAttribute(24, value);
};

Content.getComponent("HarmTempo2").setControlCallback(onHarmTempo2Control);

inline function onHarmDiv2Control(component, value)
{
		for(s in Shapers)
	       s.setAttribute(25, value);
};

Content.getComponent("HarmDiv2").setControlCallback(onHarmDiv2Control);

inline function onHarmCrvControl(component, value)
{
	for(s in Shapers)
	       s.setAttribute(26, value);
};

Content.getComponent("HarmCrv").setControlCallback(onHarmCrvControl);


inline function onHarmOneControl(component, value)
{
		for(s in Shapers)
	       s.setAttribute(27, value);
};

Content.getComponent("HarmOne").setControlCallback(onHarmOneControl);


//Mod Sliderpack                         


//Pitch

const var PitchMasterSP = Content.getComponent("PitchMasterSP");


const var PitchSps = [Content.getComponent("PitchSp1"),
                      Content.getComponent("PitchSp2"),
                      Content.getComponent("PitchSp3"),
                      Content.getComponent("PitchSp4"),
                      Content.getComponent("PitchSp5"),
                      Content.getComponent("PitchSp6"),
                      Content.getComponent("PitchSp7"),
                      Content.getComponent("PitchSp8"),
                      Content.getComponent("PitchMasterSP2")];
                      

const var PitchSps2 = [Content.getComponent("PitchSp1"),
                      Content.getComponent("PitchSp2"),
                      Content.getComponent("PitchSp3"),
                      Content.getComponent("PitchSp4"),
                      Content.getComponent("PitchSp5"),
                      Content.getComponent("PitchSp6"),
                      Content.getComponent("PitchSp7"),
                      Content.getComponent("PitchSp8"),
                      Content.getComponent("PitchMasterSP")];
              
const var fSp = Content.getComponent("FmasterSp1");



inline function onPitchMasterSPControl(component, value)
{
	

for(s in PitchSps)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value)); 

	      
};

PitchMasterSP.setControlCallback(onPitchMasterSPControl);


inline function onPitchMasterSP2Control(component, value)
{
	for(s in PitchSps2)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value)); 

};

Content.getComponent("PitchMasterSP2").setControlCallback(onPitchMasterSP2Control);


const var TableSliders = Content.getComponent("WtSliders");



//gain






 //filter
 
 
 const var FspA1 = [Content.getComponent("fsp1"),
                    Content.getComponent("fsp2"),
                    Content.getComponent("fsp3"),
                    Content.getComponent("fsp4"),
                    Content.getComponent("fsp5"),
                    Content.getComponent("fsp6"),
                    Content.getComponent("fsp7"),
                    Content.getComponent("fsp8"),
                    Content.getComponent("FilterSp2")];
                    
                    
const var FspB1 = [Content.getComponent("fsp1"),
                   Content.getComponent("fsp2"),
                   Content.getComponent("fsp3"),
                   Content.getComponent("fsp4"),
                   Content.getComponent("fsp5"),
                   Content.getComponent("fsp6"),
                   Content.getComponent("fsp7"),
                   Content.getComponent("fsp8"),
                   Content.getComponent("FmasterSp1")];                    
                    

                    
 

                    const var Fenv1 = Content.getComponent("Fenv1");
                    const var Fenv2 = Content.getComponent("Fenv2");
                    const var FmasterSp1 = Content.getComponent("FmasterSp1");
                    
                    
                //    const var FmasterSp2 = Content.getComponent("FmasterSp2");
     




inline function onFilterSp2Control(component, value)
{
	for(s in FspB1)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("FilterSp2").setControlCallback(onFilterSp2Control);


const var XfSp = Content.getComponent("XfSp");
const var PitchMasterSP2 = Content.getComponent("PitchMasterSP2");
const var GainMaster = Content.getComponent("GainMaster");
const var GainSp2 = Content.getComponent("GainSp2");
const var FilterSp2 = Content.getComponent("FilterSp2");
const var ShaperSp2 = Content.getComponent("ShapeSp2");
const var ShapeMaster = Content.getComponent("ShapeMaster");
const var PannyPack = Content.getComponent("PannyPack");
const var HarmStep = Content.getComponent("HarmStep");
const var FilterSp = Content.getComponent("FilterSp");


 //Shaper 
  

  
const var ShapeSp = [Content.getComponent("PitchSp17"),
                     Content.getComponent("PitchSp18"),
                     Content.getComponent("PitchSp19"),
                     Content.getComponent("PitchSp20"),
                     Content.getComponent("PitchSp21"),
                     Content.getComponent("PitchSp22"),
                     Content.getComponent("PitchSp23"),
                     Content.getComponent("PitchSp24"),
                     Content.getComponent("ShapeSp2")];  
                     
const var ShapeSp2 = [Content.getComponent("PitchSp17"),
                     Content.getComponent("PitchSp18"),
                     Content.getComponent("PitchSp19"),
                     Content.getComponent("PitchSp20"),
                     Content.getComponent("PitchSp21"),
                     Content.getComponent("PitchSp22"),
                     Content.getComponent("PitchSp23"),
                     Content.getComponent("PitchSp24"),
                     Content.getComponent("ShapeMaster")];                                     
                 


inline function onShapeMasterControl(component, value)
{
	for(s in ShapeSp)
	      		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("ShapeMaster").setControlCallback(onShapeMasterControl);


inline function onShapeSp2Control(component, value)
{
	for(s in ShapeSp2)
	      		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("ShapeSp2").setControlCallback(onShapeSp2Control);




const var Glide = [Synth.getModulator("Glide1"),
					Synth.getModulator("Glide2"),
					Synth.getModulator("Glide3"),
					Synth.getModulator("Glide4"),
					Synth.getModulator("Glide5"),
					Synth.getModulator("Glide6"),
					Synth.getModulator("Glide7"),
					Synth.getModulator("Glide8")];


inline function onGlideControl(component, value)
{
			for(s in Glide)
	       s.setAttribute(4, value);
};

Content.getComponent("Glide").setControlCallback(onGlideControl);


inline function onGlideTimeControl(component, value)
{
		for(s in Glide)
	       s.setAttribute(2, value);
};

Content.getComponent("GlideTime").setControlCallback(onGlideTimeControl);


inline function onGlideDivControl(component, value)
{
	for(s in Glide)
	       s.setAttribute(3, value);
};

Content.getComponent("GlideDiv").setControlCallback(onGlideDivControl);



//xf

const PolyStepData = Engine.createAndRegisterSliderPackData(0);

XfSp.referToData(PolyStepData);

inline function onXFStepsControl(component, value)
{
	PolyStepData.setNumSliders(value);
	
for(s in Xfader)
		       s.setAttribute(47, value);
};

Content.getComponent("XFSteps").setControlCallback(onXFStepsControl);
  
  const var XfMod = [Content.getComponent("XfSp1"),
                        Content.getComponent("XfSp2"),
                        Content.getComponent("XfSp3"),
                        Content.getComponent("XfSp4"),
                        Content.getComponent("XfSp5"),
                        Content.getComponent("XfSp6"),
                        Content.getComponent("XfSp7"),
               	   	  Content.getComponent("XfSp8")];
               	   	  
                      
  
  inline function onXfSpControl(component, value)
  {
  for(s in XfMod)
      		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
  };
  
  Content.getComponent("XfSp").setControlCallback(onXfSpControl);


//harm

const ShpStepData = Engine.createAndRegisterSliderPackData(1);

HarmStep.referToData(ShpStepData);



inline function onShpStepsControl(component, value)
{
	ShpStepData.setNumSliders(value);
	
for(s in Shapers)
		       s.setAttribute(47, value);
};

Content.getComponent("ShpSteps").setControlCallback(onShpStepsControl);
  
  
  
  const var HarmModSps = [Content.getComponent("XfSp26"),
                          Content.getComponent("XfSp35"),
                          Content.getComponent("XfSp36"),
                          Content.getComponent("XfSp37"),
                          Content.getComponent("XfSp38"),
                          Content.getComponent("XfSp39"),
                          Content.getComponent("XfSp40"),
                          Content.getComponent("XfSp41")];
  
  
  inline function onHarmStepControl(component, value)
  {
  	  for(s in HarmModSps)
      		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
  };
  
  Content.getComponent("HarmStep").setControlCallback(onHarmStepControl);
  

  
  const var FilterModSP = [Content.getComponent("XfSp51"),
                           Content.getComponent("XfSp68"),
                           Content.getComponent("XfSp69"),
                           Content.getComponent("XfSp70"),
                           Content.getComponent("XfSp71"),
                           Content.getComponent("XfSp72"),
                           Content.getComponent("XfSp73"),
                           Content.getComponent("XfSp74")];
  
  
  inline function onFilterSpControl(component, value)
  {
  	for(s in FilterModSP)
      		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
  };
  
  Content.getComponent("FilterSp").setControlCallback(onFilterSpControl);
  
const var PannyPack1 = Content.getComponent("PannyPack1");
  
  
const PitchSpData = Engine.createAndRegisterSliderPackData(3);
const GainSpData = Engine.createAndRegisterSliderPackData(4);
const FilterSpData = Engine.createAndRegisterSliderPackData(5);
const PannyData = Engine.createAndRegisterSliderPackData(6);
const ShapeSpData = Engine.createAndRegisterSliderPackData(7);
const FilterMasterSpData = Engine.createAndRegisterSliderPackData(8);

const var GainSp = Content.getComponent("GainSp");
const var GainSps = [Content.getComponent("GainSp")];

const var ShpSp2 = Content.getComponent("ShapeSp2");


const var Pre = Synth.getSliderPackProcessor("Pre").getSliderPack(0);
const var PanSliders = Synth.getSliderPackProcessor("PanSliders").getSliderPack(0);

PitchMasterSP.referToData(PitchSpData);
PitchMasterSP2.referToData(PitchSpData);
//GainSp2.referToData(GainSpData);
//PannyPack1.referToData(PannyData);
//GainMaster.referToData(GainSpData);
ShapeMaster.referToData(ShapeSpData);
ShpSp2.referToData(ShapeSpData);
FilterSp.referToData(FilterStepModData);
FmasterSp1.referToData(FilterMasterSpData);
FilterSp2.referToData(FilterMasterSpData);

//GainMaster.linkTo(GainMaster);
//GainSpData.linkTo(GainSp2);

const FilterStepModData = Engine.createAndRegisterSliderPackData(2);

FilterSp.referToData(FilterStepModData);


inline function onFilterStepsControl(component, value)
{
		FilterStepModData.setNumSliders(value);
	
for(s in Filters)
		       s.setAttribute(47, value);
};

Content.getComponent("FilterSteps").setControlCallback(onFilterStepsControl);




inline function onGainMasterControl(component, value)
{

//Pre.setSliderAtIndex(value, component.getSliderValueAt(value));
GainMaster.setSliderAtIndex(value, component.getSliderValueAt(value));


};

Content.getComponent("GainMaster").setControlCallback(onGainMasterControl);



inline function onPannyPack1Control(component, value)
{
	PannyPack1.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("PannyPack1").setControlCallback(onPannyPack1Control);

const var Loading = Content.getComponent("Loading");



inline function onLoadWavesControl(component, value)
{
	if(value == 1)
	    	{

	Loading.showControl(1);
	}
};

Content.getComponent("LoadWaves").setControlCallback(onLoadWavesControl);




inline function onCloseWavePageControl(component, value)
{
	if(value == 1)
	    	{

	Loading.showControl(0);
	}
};

Content.getComponent("CloseWavePage").setControlCallback(onCloseWavePageControl);


inline function onScriptButton2Control(component, value)
{
	 if(value == 1)
    	{
	SettingsPresets.showControl(0);
	}
};

Content.getComponent("ScriptButton2").setControlCallback(onScriptButton2Control);


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
 