//Mod Sliderpack

//Link
//const SpData1 = Engine.createAndRegisterSliderPackData(0);
const SpData3 = Engine.createAndRegisterSliderPackData(2);
const SpData4 = Engine.createAndRegisterSliderPackData(1);   

                      
//PitchMasterSP.referToData(SpData1);
fSp.referToData(SpData3);
XfSp.referToData(SpData4);

//Pitch

const var PitchMasterSP = Content.getComponent("PitchMasterSP");

const var PitchSps = [Content.getComponent("PitchSp1"),
                      Content.getComponent("PitchSp2"),
                      Content.getComponent("PitchSp3"),
                      Content.getComponent("PitchSp4"),
                      Content.getComponent("PitchSp5"),
                      Content.getComponent("PitchSp6"),
                      Content.getComponent("PitchSp7"),
                      Content.getComponent("PitchSp8")];
                      


              
const var fSp = Content.getComponent("FmasterSp1");



inline function onPitchMasterSPControl(component, value)
{
	

for(s in PitchSps)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
   

	      
};

PitchMasterSP.setControlCallback(onPitchMasterSPControl);




const var HarmPitch = Content.getComponent("HarmPitch");
const var TableSliders = Content.getComponent("WtSliders");


//Xfade
  
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
  
 
 
 //Shaper 
  
  const var XfSp = Content.getComponent("XfSp");
  
const var ShapeSp = [Content.getComponent("PitchSp17"),
                     Content.getComponent("PitchSp18"),
                     Content.getComponent("PitchSp19"),
                     Content.getComponent("PitchSp20"),
                     Content.getComponent("PitchSp21"),
                     Content.getComponent("PitchSp22"),
                     Content.getComponent("PitchSp23"),
                     Content.getComponent("PitchSp24")];                 
                 
const var ShapeFx = [Content.getComponent("PitchSp25"),
                     Content.getComponent("PitchSp26"),
                     Content.getComponent("PitchSp27"),
                     Content.getComponent("PitchSp28"),
                     Content.getComponent("PitchSp29"),
                     Content.getComponent("PitchSp30"),
                     Content.getComponent("PitchSp31"),
                     Content.getComponent("PitchSp32")];


inline function onShapeMasterControl(component, value)
{
	for(s in ShapeSp)
	      		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("ShapeMaster").setControlCallback(onShapeMasterControl);

inline function onShapeFXMasterControl(component, value)
{
		for(s in ShapeFx)
	      		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("ShapeFXMaster").setControlCallback(onShapeFXMasterControl);
