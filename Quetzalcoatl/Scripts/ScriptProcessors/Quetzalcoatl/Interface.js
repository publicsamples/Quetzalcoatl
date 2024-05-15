Content.makeFrontInterface(870, 725);

 

Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);

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
//include("Xfade.js");
include("Filters.js");
//include("Osc2.js");
//include("osc1.js");
//include("FM.js");
include("GeneralUi.js");
include("Mod.js");
  
  //Xfade
  
  const var Xfsync = Content.getComponent("Xfsync");
  const var XfTempo = Content.getComponent("XfTempo");
  const var XfTempo2 = Content.getComponent("XfTempo2");
  
  const var Xfader = [Synth.getEffect("Xfade1"),
                       Synth.getEffect("Xfade2"),
                       Synth.getEffect("Xfade3"),
                       Synth.getEffect("Xfade4"),
                       Synth.getEffect("Xfade5"),
                       Synth.getEffect("Xfade6"),
                       Synth.getEffect("Xfade7"),
                       Synth.getEffect("Xfade8")];
                       
  
                                            
  const var Xf1 = Synth.getModulator("Xf1");
  
  //mo
  
  inline function onXfTempoControl(component, value)
  {
  for(s in Xfader)
  	       s.setAttribute(0, value);
  	       for(s in Filters)
  	              s.setAttribute(0, value);
  	     for(s in Pitches)
  	      	       s.setAttribute(2, value);         
  	              
   
  }
  
  Content.getComponent("XfTempo").setControlCallback(onXfTempoControl);
  
  
  inline function onXfDivControl(component, value)
  {
  for(s in Xfader)
  	       s.setAttribute(1, value);
  	       for(s in Filters)
  	              s.setAttribute(1, value);
  	              
  	        for(s in Pitches)
  	          	      	       s.setAttribute(3, value);      
  };
  
  Content.getComponent("XfDiv").setControlCallback(onXfDivControl);
  
  inline function onXfTrigModeControl(component, value)
  {
  	if(value == 0)
  	{
  		
  for(s in Xfader)
  	       s.setAttribute(2, 0);
  	       for(s in Filters)
  	              s.setAttribute(2, 0);
  	              for(s in Pitches)
  	              s.setAttribute(4, 0);      
  
  	LoopLabel1.showControl(0);  
  	     OneShtLabel1.showControl(1);   
  	     }
  	     
  	     	if(value == 1)
  	     {
  for(s in Xfader)
  	       s.setAttribute(2, 1);
  	       for(s in Filters)
  	              s.setAttribute(2, 1);
  for(s in Pitches)
    	              s.setAttribute(4, 1);    
  
  	LoopLabel1.showControl(1);  
  	     OneShtLabel1.showControl(0);
  	     }   
  
  };
  
  Content.getComponent("XfTrigMode").setControlCallback(onXfTrigModeControl);
  
  
  const var MODSEL1 = Content.getComponent("MODSEL1");
  
  const var mods = [];
  
  mods[0] = Content.getComponent("8step1");
  mods[1] = Content.getComponent("LFO1");

  
  const var SharedTempo = Content.getComponent("SharedTempo");
  
  
  
  inline function onMODSEL1Control(component, value)
  
  {
  
  	if(value == 1)
  	{
  	for(s in Xfader)
  	s.setAttribute(3, 2.70);
  	for(s in Filters)
  	s.setAttribute(3, 2.70);
  	for(s in Pitches)
  	s.setAttribute(5, 2.70);  
   mods[0].showControl(1);  
   mods[1].showControl(0);   

            
  	}
  	
  		if(value == 2)
  	{
	for(s in Xfader)
	s.setAttribute(3, 1.7);
	for(s in Filters)
	s.setAttribute(3, 1.7);
	for(s in Pitches)
	s.setAttribute(5, 1.7);    
    mods[0].showControl(0);  
    mods[1].showControl(1);   
	  
  	} 	 
  };
  
  
  Content.getComponent("MODSEL1").setControlCallback(onMODSEL1Control);
  
  inline function onLfoShapeXFControl(component, value)
  {
  	for(s in Xfader)
  	    s.setAttribute(4, value);
  	    for(s in Filters)
  	           s.setAttribute(4, value);
  	           for(s in Pitches)
  	           s.setAttribute(6, value); 
  };
  
  Content.getComponent("LfoShapeXF").setControlCallback(onLfoShapeXFControl);
  
  //Poly Envs
  
  inline function onXfAControl(component, value)
  {
  		for(s in Xfader)
  	       s.setAttribute(8, value);
  	       for(s in Filters)
  	              s.setAttribute(8, value);
  	              for(s in Pitches)
  	               	           s.setAttribute(10, value); 
  };
  
  Content.getComponent("XfA").setControlCallback(onXfAControl);
  
  
  
  inline function onXfDDControl(component, value)
  {
  		for(s in Xfader)
  	       s.setAttribute(9, value);
  	       for(s in Filters)
  	              s.setAttribute(9, value);
  	              for(s in Pitches)
  	               	           s.setAttribute(11, value); 
  };
  
  Content.getComponent("XfDD").setControlCallback(onXfDDControl);
  
  
  inline function onXfSControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(10, value);
  	       for(s in Filters)
  	              s.setAttribute(10, value);
  	              for(s in Pitches)
  	               	           s.setAttribute(12, value); 
  };
  
  Content.getComponent("XfS").setControlCallback(onXfSControl);
  
  
  inline function onXfRControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(11, value);
  	       for(s in Filters)
  	              s.setAttribute(11, value);
  	              for(s in Pitches)
  	             s.setAttribute(13, value); 
  };
  
  Content.getComponent("XfR").setControlCallback(onXfRControl);
  
  
  inline function onXfAtkLpControl(component, value)
  {
  for(s in Xfader)
  	       s.setAttribute(12, value);
  	       for(s in Filters)
  	              s.setAttribute(12, value);
  	              for(s in Pitches)
  	               	           s.setAttribute(14, value); 
  };
  
  Content.getComponent("XfAtkLp").setControlCallback(onXfAtkLpControl);
  
  
  
  inline function onXftrlLpControl(component, value)
  {
  for(s in Xfader)
  	       s.setAttribute(13, value);
  	       for(s in Filters)
  	              s.setAttribute(13, value);
  	              for(s in Pitches)
  	               	           s.setAttribute(15, value); 
  };
  
  Content.getComponent("XftrlLp").setControlCallback(onXftrlLpControl);
  
  inline function onXfTempo1Control(component, value)
  {
  for(s in Xfader)
    	       s.setAttribute(14, value);
    	       for(s in Filters)
    	              s.setAttribute(14, value);
    	              for(s in Pitches)
    	               	           s.setAttribute(16, value); 
  };
  
  Content.getComponent("XfTempo1").setControlCallback(onXfTempo1Control);
  
  
  
  inline function onXfCrvControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(17, value);
  	       for(s in Filters)
  	              s.setAttribute(17, value);
  	              for(s in Pitches)
  	             s.setAttribute(18, value); 
  	             
  };
  
  Content.getComponent("XfCrv").setControlCallback(onXfCrvControl);
  
  
  
  inline function onXfDiv1Control(component, value)
  {
  for(s in Xfader)
  	       s.setAttribute(16, value);
  	       for(s in Filters)
  	              s.setAttribute(16, value);
  	              
   for(s in Pitches)
   s.setAttribute(19, value); 
  };
  
  Content.getComponent("XfDiv1").setControlCallback(onXfDiv1Control);
  



inline function onLpOneControl(component, value)
{
	for(s in Xfader)
  	       s.setAttribute(15, value);
  	       for(s in Filters)
  	              s.setAttribute(15, value);
  	              for(s in Pitches)
  	               	           s.setAttribute(17, value); 
};

Content.getComponent("LpOne").setControlCallback(onLpOneControl);



  
  
  
  
  
  
  
  const var XfWaves = [];
  
  XfWaves[0] = Content.getComponent("Wave1");
  XfWaves[1] = Content.getComponent("Wave2");
  XfWaves[2] = Content.getComponent("Wave3");
  XfWaves[3] = Content.getComponent("Wave4");
  XfWaves[4] = Content.getComponent("Wave5");
  XfWaves[5] = Content.getComponent("Wave6");
  XfWaves[6] = Content.getComponent("Wave7");
  XfWaves[7] = Content.getComponent("Wave8");
  
  const var StageSelect = Content.getComponent("StageSelect");
  
  
  inline function onXFsliderControl(component, value)
  {
  
  
         
    for (i = 0; i < XfWaves.length; i++)
                 XfWaves[i].showControl(value - 1 == i);
  
  for(s in Xfader)
         s.setAttribute(24, value);
         
         StageSelect.setValue(value);
  
        
  	
  };
  
  Content.getComponent("XFslider").setControlCallback(onXFsliderControl);
  
  
  inline function onXFslider2Control(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(24, value);
  
  	if(value == 1)
  		{
  	XfWaves[0].showControl(1);
  	XfWaves[1].showControl(0);
  	XfWaves[2].showControl(0);
  	XfWaves[3].showControl(0);
  	XfWaves[4].showControl(0);
  	XfWaves[5].showControl(0);
  	XfWaves[6].showControl(0);
  	XfWaves[7].showControl(0);
  	StageSelect.setValue(1);
  
         }
         
         if(value == 4)
         	{
         XfWaves[0].showControl(1);
         XfWaves[1].showControl(0);
         XfWaves[2].showControl(0);
         XfWaves[3].showControl(0);
         XfWaves[4].showControl(0);
         XfWaves[5].showControl(0);
         XfWaves[6].showControl(0);
         XfWaves[7].showControl(0);
         StageSelect.setValue(1);
         
                }
         
         if(value == 5)
         	{
         XfWaves[0].showControl(0);
         XfWaves[1].showControl(1);
         XfWaves[2].showControl(0);
         XfWaves[3].showControl(0);
         XfWaves[4].showControl(0);
         XfWaves[5].showControl(0);
         XfWaves[6].showControl(0);
         XfWaves[7].showControl(0);
         StageSelect.setValue(2);
         
                }
         
  };
  
  Content.getComponent("XFslider2").setControlCallback(onXFslider2Control);
  
  
  inline function onXFslider1Control(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(24, value);
  
  	if(value == 1)
  		{
  	XfWaves[0].showControl(1);
  	XfWaves[1].showControl(0);
  	XfWaves[2].showControl(0);
  	XfWaves[3].showControl(0);
  	XfWaves[4].showControl(0);
  	XfWaves[5].showControl(0);
  	XfWaves[6].showControl(0);
  	XfWaves[7].showControl(0);
  	StageSelect.setValue(1);
  
         }
         
         if(value == 3)
         	{
         XfWaves[0].showControl(0);
         XfWaves[1].showControl(1);
         XfWaves[2].showControl(0);
         XfWaves[3].showControl(0);
         XfWaves[4].showControl(0);
         XfWaves[5].showControl(0);
         XfWaves[6].showControl(0);
         XfWaves[7].showControl(0);
         StageSelect.setValue(2);
         
                }
         
         if(value == 5)
         	{
         XfWaves[0].showControl(0);
         XfWaves[1].showControl(0);
         XfWaves[2].showControl(1);
         XfWaves[3].showControl(0);
         XfWaves[4].showControl(0);
         XfWaves[5].showControl(0);
         XfWaves[6].showControl(0);
         XfWaves[7].showControl(0);
         StageSelect.setValue(3);
         
                }
                
        if(value == 7)
             	{
             XfWaves[0].showControl(0);
             XfWaves[1].showControl(0);
             XfWaves[2].showControl(0);
             XfWaves[3].showControl(1);
             XfWaves[4].showControl(0);
             XfWaves[5].showControl(0);
             XfWaves[6].showControl(0);
             XfWaves[7].showControl(0);
             StageSelect.setValue(4);
             
                    }  
  };
  
  Content.getComponent("XFslider1").setControlCallback(onXFslider1Control);
  
  
  
  inline function onSmoothControl(component, value)
  {	
  	for(s in Xfader)
  	       s.setAttribute(25, value);
  
   
  };
  
  Content.getComponent("Smooth").setControlCallback(onSmoothControl);
  
  
  
  inline function onXfSmoothModeControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(23, value);
  };
  
  Content.getComponent("XfSmoothMode").setControlCallback(onXfSmoothModeControl);
  
  
  inline function onXfModControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(26, value);
   
  };
  
  Content.getComponent("XfMod").setControlCallback(onXfModControl);
  
  
  
  inline function onXfEnvMod1Control(component, value)
  {
  for(s in Xfader)
  	       s.setAttribute(6, value);
  };
  
  Content.getComponent("XfEnvMod1").setControlCallback(onXfEnvMod1Control);
  
  
  
  inline function onXfEnvMod2Control(component, value)
  {
  for(s in Xfader)
  	       s.setAttribute(7, value);
  };
  
  Content.getComponent("XfEnvMod2").setControlCallback(onXfEnvMod2Control);
  
  
  inline function onXfGlobalModControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(18, value);
  };
  
  Content.getComponent("XfGlobalMod").setControlCallback(onXfGlobalModControl);
  
  
  
  
  
  
  
  inline function onXfsel2Control(component, value)
  {
  for(s in Xfader)
         s.setAttribute(32, value);

         
  	
  };
  
  Content.getComponent("Xfsel2").setControlCallback(onXfsel2Control);
  
  const var XFslider = Content.getComponent("XFslider");
  const var XFslider1 = Content.getComponent("XFslider1");
  const var XFslider2 = Content.getComponent("XFslider2");
  
  
  
  
  
  
  inline function onXfStahesControl(component, value)
  {
  	if(value == 1)
  	{
  	for(s in Xfader)
         s.setAttribute(33, 0);
         
         Group3.setBypassed(0);
         Group4.setBypassed(0);
         Group5.setBypassed(0);
         Group6.setBypassed(0);
         Group7.setBypassed(0);
         Group8.setBypassed(0);
         XFslider.showControl(1);
         XFslider1.showControl(0);
         XFslider2.showControl(0);
         SpData1.setNumSliders(8);  
          
         SpData3.setNumSliders(8);  
         
         }
         
      if(value == 2)
      {
      for(s in Xfader)
             s.setAttribute(33, 1);
  
  	Group3.setBypassed(0);
      Group4.setBypassed(0);
      Group5.setBypassed(1);
      Group6.setBypassed(1);
      Group7.setBypassed(1);
      Group8.setBypassed(1);   
      XFslider.showControl(0);
             XFslider1.showControl(1);
             XFslider2.showControl(0);   
             SpData1.setNumSliders(4);   
             
                    SpData3.setNumSliders(4);   
              
             }
    
      if(value == 3)
      {
      for(s in Xfader)
             s.setAttribute(33, 2);
             
             Group3.setBypassed(1);
                 Group4.setBypassed(1);
                 Group5.setBypassed(1);
                 Group6.setBypassed(1);
                 Group7.setBypassed(1);
                 Group8.setBypassed(1); 
                 XFslider.showControl(0);
                        XFslider1.showControl(0);
                        XFslider2.showControl(1);
                        SpData1.setNumSliders(2); 
                         
                               SpData3.setNumSliders(2);   
                 
             }
    
  };
  
  Content.getComponent("XfStahes").setControlCallback(onXfStahesControl);
  
  
  
  
  
  inline function onXfVelControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(28, value);
  
  };
  
  Content.getComponent("XfVel").setControlCallback(onXfVelControl);
  
  
  inline function onXfTrkControl(component, value)
  {
  		for(s in Xfader)
  	       s.setAttribute(29, value);

  };
  
  Content.getComponent("XfTrk").setControlCallback(onXfTrkControl);
  
  inline function onXfMwControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(30, value);

  };
  
  Content.getComponent("XfMw").setControlCallback(onXfMwControl);
  
  
  inline function onXfAtControl(component, value)
  {
  for(s in Xfader)
  	       s.setAttribute(31, value);

  };
  
  Content.getComponent("XfAt").setControlCallback(onXfAtControl);
  
  
  
  
  inline function onXfselControl(component, value)
  {
  
  	for(s in Xfader)
  	       s.setAttribute(19, value);
  
  };
  
  Content.getComponent("Xfsel").setControlCallback(onXfselControl);
  
  
  inline function onXfAControl(component, value)
  {
  for(s in Xfader)
  	       s.setAttribute(8, value);
  };
  
  Content.getComponent("XfA").setControlCallback(onXfAControl);
  
  
  inline function onXfDDControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(9, value);
  };
  
  Content.getComponent("XfDD").setControlCallback(onXfDDControl);
  
  
  inline function onXfSControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(10, value);
  };
  
  Content.getComponent("XfS").setControlCallback(onXfSControl);
  
  
  inline function onXfRControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(11, value);
  };
  
  Content.getComponent("XfR").setControlCallback(onXfRControl);
  
  
  
  
  
  const var XfDiv1 = Content.getComponent("XfDiv1");
  const var XfEnv1 = Content.getComponent("XfEnv1");
  const var XfEnv2 = Content.getComponent("XfEnv2");
  
    
  inline function onXfDiv1Control(component, value)
  {
  		for(s in Xfader)
  	      s.setAttribute(40, value);
  };
  
  Content.getComponent("XfDiv1").setControlCallback(onXfDiv1Control);
  
  
  
  const var XfSp = Content.getComponent("XfSp");
  

  
  
  const SpData1 = Engine.createAndRegisterSliderPackData(0);
  
  
  


const var FspA1 = [Content.getComponent("fsp1"),
                   Content.getComponent("fsp2"),
                   Content.getComponent("fsp3"),
                   Content.getComponent("fsp4"),
                   Content.getComponent("fsp5"),
                   Content.getComponent("fsp6"),
                   Content.getComponent("fsp7"),
                   Content.getComponent("fsp8"),
                   Content.getComponent("fsp9")];
                   
                   

const var FspA2 = [Content.getComponent("fsp10"),
                   Content.getComponent("fsp11"),
                   Content.getComponent("fsp12"),
                   Content.getComponent("fsp13"),
                   Content.getComponent("fsp14"),
                   Content.getComponent("fsp15"),
                   Content.getComponent("fsp16"),
                   Content.getComponent("fsp17"),
				   Content.getComponent("fsp18")];
                   
                   const var Fenv1 = Content.getComponent("Fenv1");
                   const var Fenv2 = Content.getComponent("Fenv2");
                   const var FmasterSp1 = Content.getComponent("FmasterSp1");
                   const var FmasterSp2 = Content.getComponent("FmasterSp2");
                   
//osc

                   
const var SampleGroups = [Synth.getChildSynth("Group1"),
                     Synth.getChildSynth("Group2"),
                     Synth.getChildSynth("Group3"),
                     Synth.getChildSynth("Group4"),
                     Synth.getChildSynth("Group5"),
                     Synth.getChildSynth("Group6"),
                     Synth.getChildSynth("Group7"),
                     Synth.getChildSynth("Group8")];
                     
                     
const var SampleComp = [ Content.getComponent("SampleWave1"),
                     Content.getComponent("SampleWave2"),
                     Content.getComponent("SampleWave3"),
                     Content.getComponent("SampleWave4"),
                     Content.getComponent("SampleWave5"),
                     Content.getComponent("SampleWave6"),
                     Content.getComponent("SampleWave7"),
                     Content.getComponent("SampleWave8"),
                     Content.getComponent("SampleWave9"),
                     Content.getComponent("Waves1"),
                     Content.getComponent("Waves2"),
                     Content.getComponent("Waves3"),
                     Content.getComponent("Waves4"),
                     Content.getComponent("Waves5"),
                     Content.getComponent("Waves6"),
                     Content.getComponent("Waves7"),
                     Content.getComponent("Waves8"),
                     Content.getComponent("Waves9")];
                     
                     
                     

                     
const var WtComp = [Content.getComponent("Wt1"),
                     Content.getComponent("Wt2"),
                     Content.getComponent("Wt3"),
                     Content.getComponent("Wt4"),
                     Content.getComponent("Wt5"),
                     Content.getComponent("Wt6"),
                     Content.getComponent("Wt7"),
                     Content.getComponent("Wt8"),
                     Content.getComponent("Wt9"),
                     Content.getComponent("TableView1"),
                     Content.getComponent("TableView2"),
                     Content.getComponent("TableView3"),
                     Content.getComponent("TableView4"),
                     Content.getComponent("TableView5"),
                     Content.getComponent("TableView6"),
                     Content.getComponent("TableView7"),
                     Content.getComponent("TableView8"),
                     Content.getComponent("TableView9")];
                     
                     
const var LoopComp = [Content.getComponent("UserWave1"),
                     Content.getComponent("UserWave2"),
                     Content.getComponent("UserWave3"),
                     Content.getComponent("UserWave4"),
                     Content.getComponent("UserWave5"),
                     Content.getComponent("UserWave6"),
                     Content.getComponent("UserWave7"),
                     Content.getComponent("UserWave8"),
                     Content.getComponent("UserWave9"),
                     Content.getComponent("LpControls1"),
                     Content.getComponent("LpControls1"),
                     Content.getComponent("LpControls2"),
                     Content.getComponent("LpControls3"),
                     Content.getComponent("LpControls4"),
                     Content.getComponent("LpControls5"),
                     Content.getComponent("LpControls6"),
                     Content.getComponent("LpControls7"),
                     Content.getComponent("LpControls8"),
                     Content.getComponent("LpControls9")];

const var MODSEL3 = Content.getComponent("MODSEL3");
const var MODSEL4 = Content.getComponent("MODSEL4");

const var Gmod1 = Synth.getModulator("Gmod1");
const var Gmod2 = Synth.getModulator("Gmod2");

const var mods3 = [];

mods3[0] = Content.getComponent("LFO1");
mods3[1] = Content.getComponent("Table3");
mods3[2] = Content.getComponent("8step3");
mods3[3] = Content.getComponent("8Trig3");

const var mods4 = [];

mods4[0] = Content.getComponent("LFO2");
mods4[1] = Content.getComponent("Table4");
mods4[2] = Content.getComponent("8step4");
mods4[3] = Content.getComponent("8Trig4");




const var LoopLabel1 = Content.getComponent("LoopLabel1");
const var OneShtLabel1 = Content.getComponent("OneShtLabel1");
const var TrigMode3 = Content.getComponent("TrigMode3");
const var TrigLabel1 = Content.getComponent("TrigLabel1");
const var TempoS3 = Content.getComponent("TempoS3");
const var TempoS4 = Content.getComponent("TempoS4");
const var TempoF3 = Content.getComponent("TempoF3");
const var TempoF4 = Content.getComponent("TempoF4");
const var sync3 = Content.getComponent("sync3");
const var sync4 = Content.getComponent("sync4");
const var synclabel1 = Content.getComponent("synclabel1");
const var synclabel2 = Content.getComponent("synclabel2");
const var synclabel3 = Content.getComponent("synclabel3");
const var synclabel4 = Content.getComponent("synclabel4");
const var freelabel1 = Content.getComponent("freelabel1");
const var freelabel2 = Content.getComponent("freelabel2");


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
				
const var Fm = [Synth.getAudioSampleProcessor("FM1"),
				Synth.getAudioSampleProcessor("FM2"),
				Synth.getAudioSampleProcessor("FM3"),
				Synth.getAudioSampleProcessor("FM4"),
				Synth.getAudioSampleProcessor("FM5"),
				Synth.getAudioSampleProcessor("FM6"),
				Synth.getAudioSampleProcessor("FM7"),
				Synth.getAudioSampleProcessor("FM8")];
				
const var FmOn = [Synth.getChildSynth("FM1"),
				Synth.getChildSynth("FM2"),
				Synth.getChildSynth("FM3"),
				Synth.getChildSynth("FM4"),
				Synth.getChildSynth("FM5"),
				Synth.getChildSynth("FM6"),
				Synth.getChildSynth("FM7"),
				Synth.getChildSynth("FM8")];								



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
const var SampleWave9 = Content.getComponent("SamplerWave9");

const var Waves1 = Content.getComponent("Waves1");
const var Waves2 = Content.getComponent("Waves2");
const var Waves3 = Content.getComponent("Waves3");
const var Waves4 = Content.getComponent("Waves4");
const var Waves5 = Content.getComponent("Waves5");
const var Waves6 = Content.getComponent("Waves6");
const var Waves7 = Content.getComponent("Waves7");
const var Waves8 = Content.getComponent("Waves8");
const var Waves9 = Content.getComponent("Waves9"); 
                     
const var Wt1 = Content.getComponent("Wt1");
const var Wt2 = Content.getComponent("Wt2");
const var Wt3 = Content.getComponent("Wt3");
const var Wt4 = Content.getComponent("Wt4");
const var Wt5 = Content.getComponent("Wt5");
const var Wt6 = Content.getComponent("Wt6");
const var Wt7 = Content.getComponent("Wt7");
const var Wt8 = Content.getComponent("Wt8");
const var Wt9 = Content.getComponent("Wt9");

const var TableView1 = Content.getComponent("TableView1");
const var TableView2 = Content.getComponent("TableView2");
const var TableView3 = Content.getComponent("TableView3");
const var TableView4 = Content.getComponent("TableView4");
const var TableView5 = Content.getComponent("TableView5");
const var TableView6 = Content.getComponent("TableView6");
const var TableView7 = Content.getComponent("TableView7");
const var TableView8 = Content.getComponent("TableView8");
const var TableView9 = Content.getComponent("TableView9");
                     
                     
const var UserWave1 = Content.getComponent("UserWave1");
const var UserWave2 = Content.getComponent("UserWave2");
const var UserWave3 = Content.getComponent("UserWave3");
const var UserWave4 = Content.getComponent("UserWave4");
const var UserWave5 = Content.getComponent("UserWave5");
const var UserWave6 = Content.getComponent("UserWave6");
const var UserWave7 = Content.getComponent("UserWave7");
const var UserWave8 = Content.getComponent("UserWave8");
const var UserWave9 = Content.getComponent("UserWave9");

const var LpControls1 = Content.getComponent("LpControls1");
const var LpControls2 = Content.getComponent("LpControls2");
const var LpControls3 = Content.getComponent("LpControls3");
const var LpControls4 = Content.getComponent("LpControls4");
const var LpControls5 = Content.getComponent("LpControls5");
const var LpControls6 = Content.getComponent("LpControls6");
const var LpControls7 = Content.getComponent("LpControls7");
const var LpControls8 = Content.getComponent("LpControls8");
const var LpControls9 = Content.getComponent("LpControls9");


const var Lwav1 = Synth.getAudioSampleProcessor("LoopA1");
const var Lwav2 = Synth.getAudioSampleProcessor("LoopA2");
const var Lwav3 = Synth.getAudioSampleProcessor("LoopA3");
const var Lwav4 = Synth.getAudioSampleProcessor("LoopA4");
const var Lwav5 = Synth.getAudioSampleProcessor("LoopA5");
const var Lwav6 = Synth.getAudioSampleProcessor("LoopA6");
const var Lwav7 = Synth.getAudioSampleProcessor("LoopA7");
const var Lwav8 = Synth.getAudioSampleProcessor("LoopA8");



const var WtSliders = Content.getComponent("WtSliders");

const var FmSlider = Content.getComponent("FmSlider");

const var LpSwitches1 = Content.getComponent("LpSwitches1");

const var FmWaves1 = Content.getComponent("FmWaves1");
const var FmWaves2 = Content.getComponent("FmWaves2");
const var FmWaves3 = Content.getComponent("FmWaves3");
const var FmWaves4 = Content.getComponent("FmWaves4");
const var FmWaves5 = Content.getComponent("FmWaves5");
const var FmWaves6 = Content.getComponent("FmWaves6");
const var FmWaves7 = Content.getComponent("FmWaves7");
const var FmWaves8 = Content.getComponent("FmWaves8");

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

const var FmLoad = Content.getComponent("FmLoad");





inline function onTablePitchControl(component, value)
{
	
	if(value == 1)
	{

		HarmPitch.showControl(1);
        GainSliders.showControl(0);
        FmLoad.showControl(0);
    
    }
    
    if(value == 2)
    	{
    
    		HarmPitch.showControl(0);        
            GainSliders.showControl(1);
            FmLoad.showControl(0);
        
        }
        
        if(value == 3)
        	{
        
        		HarmPitch.showControl(0);
                GainSliders.showControl(0);
                FmLoad.showControl(1);
            
            }
};

Content.getComponent("TablePitch").setControlCallback(onTablePitchControl);


const var FmWave = Content.getComponent("FmWave");



inline function onFmTrkControl(component, value)
{
for(s in FmOn)
		       s.setAttribute(6, value);
};

Content.getComponent("FmTrk").setControlCallback(onFmTrkControl);


inline function onFmRootControl(component, value)
{
for(s in FmOn)
		       s.setAttribute(7, value);
};

Content.getComponent("FmRoot").setControlCallback(onFmRootControl);

const var Detune1 = Synth.getModulator("Detune1");

const var Detune = [Synth.getModulator("Detune1"),
					 Synth.getModulator("Detune2"),
					 Synth.getModulator("Detune3"),
					 Synth.getModulator("Detune4"),
					 Synth.getModulator("Detune5"),
					 Synth.getModulator("Detune6"),
					 Synth.getModulator("Detune7"),
					 Synth.getModulator("Detune8")];
					 


inline function onFmDetuneControl(component, value)
{
	
	for(s in Detune)
	       s.setIntensity(value);

};

Content.getComponent("FmDetune").setControlCallback(onFmDetuneControl);


const var FmEnv = [Synth.getModulator("FmEnv1"),
					 Synth.getModulator("FmEnv2"),
					 Synth.getModulator("FmEnv3"),
					 Synth.getModulator("FmEnv4"),
					 Synth.getModulator("FmEnv5"),
					 Synth.getModulator("FmEnv6"),
					 Synth.getModulator("FmEnv7"),
					 Synth.getModulator("FmEnv8")];


inline function onFmAtkControl(component, value)
{
	for(s in FmEnv)
		       s.setAttribute(2, value);
};

Content.getComponent("FmAtk").setControlCallback(onFmAtkControl);


inline function onFmDcyControl(component, value)
{
		for(s in FmEnv)
		       s.setAttribute(5, value);
};

Content.getComponent("FmDcy").setControlCallback(onFmDcyControl);


inline function onFmSusControl(component, value)
{
		for(s in FmEnv)
		       s.setAttribute(6, value);
};

Content.getComponent("FmSus").setControlCallback(onFmSusControl);


inline function onFmRelControl(component, value)
{
for(s in FmEnv)
		       s.setAttribute(7, value);
};

Content.getComponent("FmRel").setControlCallback(onFmRelControl);





const var preset = Content.getComponent("preset");
const var SettingsPresets = Content.getComponent("SettingsPresets");


inline function onpresetControl(component, value)
{
	if(value == 0)
		{
	
	      SettingsPresets.showControl(0);  
	  	         
		}

	if(value == 1)
		{
	
	      SettingsPresets.showControl(1);  
	  	         
		}

};

Content.getComponent("preset").setControlCallback(onpresetControl);





inline function onGainControl(component, value)
{
for(s in Osc1)
       s.setAttribute(0, value);    
};

Content.getComponent("Gain").setControlCallback(onGainControl);


const var Pitches = [Synth.getModulator("PitchA1"),
						Synth.getModulator("PitchA2"),
						Synth.getModulator("PitchA3"),
						Synth.getModulator("PitchA4"),
						Synth.getModulator("PitchA5"),
						Synth.getModulator("PitchA6"),
						Synth.getModulator("PitchA7"),
						Synth.getModulator("PitchA8")];
						

inline function onPitchModeControl(component, value)
{
for(s in Pitches)
       s.setAttribute(34, value);
       
};

Content.getComponent("PitchMode").setControlCallback(onPitchModeControl);


inline function onHarmControl(component, value)
{
   for(s in Pitches)
       s.setAttribute(26, value);
       
};

Content.getComponent("Harm").setControlCallback(onHarmControl);


inline function onHarmModControl(component, value)
{
for(s in Pitches)
       s.setAttribute(28, value);
       
};

Content.getComponent("HarmMod").setControlCallback(onHarmModControl);


inline function onHarmModSrcControl(component, value)
{

	 for(s in Pitches)
	 	 	 s.setAttribute(21, value);

};

Content.getComponent("HarmModSrc").setControlCallback(onHarmModSrcControl);


inline function onHarmEnv1Control(component, value)
{
 for(s in Pitches)
	 	 	 s.setAttribute(8, value);
};

Content.getComponent("HarmEnv1").setControlCallback(onHarmEnv1Control);


inline function onHarmEnv2Control(component, value)
{
	 for(s in Pitches)
	 	 	 s.setAttribute(9, value);
};

Content.getComponent("HarmEnv2").setControlCallback(onHarmEnv2Control);


inline function onHarmGlobalControl(component, value)
{
	 for(s in Pitches)
	 	 	 s.setAttribute(20, value);
};

Content.getComponent("HarmGlobal").setControlCallback(onHarmGlobalControl);







const var PitchMasterSP = Content.getComponent("PitchMasterSP");

const var PitchSps = [Content.getComponent("PitchSp1"),
                      Content.getComponent("PitchSp2"),
                      Content.getComponent("PitchSp3"),
                      Content.getComponent("PitchSp4"),
                      Content.getComponent("PitchSp5"),
                      Content.getComponent("PitchSp6"),
                      Content.getComponent("PitchSp7"),
                      Content.getComponent("PitchSp8"),
                      Content.getComponent("PitchSp9"),
                      Content.getComponent("PitchSp10"),
                      Content.getComponent("PitchSp11"),
                      Content.getComponent("PitchSp12"),
                      Content.getComponent("PitchSp13"),
                      Content.getComponent("PitchSp14"),
                      Content.getComponent("PitchSp15"),
                      Content.getComponent("PitchSp16"),
                      Content.getComponent("PitchSp17"),
                      Content.getComponent("PitchSp18"),
                      Content.getComponent("PitchSp19"),
                      Content.getComponent("PitchSp20"),
                      Content.getComponent("PitchSp21"),
                      Content.getComponent("PitchSp22"),
                      Content.getComponent("PitchSp23"),
                      Content.getComponent("PitchSp24")];
                      


              
const var fSp = Content.getComponent("FmasterSp1");


const SpData3 = Engine.createAndRegisterSliderPackData(2);
const SpData4 = Engine.createAndRegisterSliderPackData(1);   

                      
PitchMasterSP.referToData(SpData1);
fSp.referToData(SpData3);
XfSp.referToData(SpData4);






inline function onXfSpControl(component, value)
{
for(s in PitchSps)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("XfSp").setControlCallback(onXfSpControl);






inline function onPitchMasterSPControl(component, value)
{
	

for(s in PitchSps)
   		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
   

	      
};

PitchMasterSP.setControlCallback(onPitchMasterSPControl);


const var HarmPitch = Content.getComponent("HarmPitch");
const var TableSliders = Content.getComponent("WtSliders");




const var Gates = Content.getComponent("Gates");
const var GatePage = Content.getComponent("GatePage");



inline function onCloseGatesControl(component, value)
{
	Gates.showControl(0);  
	GatePage.setValue(-1);
    
};

Content.getComponent("CloseGates").setControlCallback(onCloseGatesControl);



inline function onGatePageControl(component, value)
{
	Gates.showControl(value);  
	
};
Content.getComponent("GatePage").setControlCallback(onGatePageControl);



const var Osc1Env = [Synth.getModulator("AHDSR Envelope1"),
					Synth.getModulator("AHDSR Envelope2"),
					Synth.getModulator("AHDSR Envelope3"),
					Synth.getModulator("AHDSR Envelope4"),
					Synth.getModulator("AHDSR Envelope5"),
					Synth.getModulator("AHDSR Envelope6"),
					Synth.getModulator("AHDSR Envelope7"),
					Synth.getModulator("AHDSR Envelope8")];



inline function onATTACK5Control(component, value)
{
	
	for(s in Osc1Env)
	       s.setAttribute(2, value);

	
};

Content.getComponent("ATTACK5").setControlCallback(onATTACK5Control);


inline function onDECAY5Control(component, value)
{
		for(s in Osc1Env)
	       s.setAttribute(5, value);

};

Content.getComponent("DECAY5").setControlCallback(onDECAY5Control);


inline function onSUSTAIN5Control(component, value)
{
		for(s in Osc1Env)
	       s.setAttribute(6, value);

};

Content.getComponent("SUSTAIN5").setControlCallback(onSUSTAIN5Control);



inline function onRELEASE5Control(component, value)
{
		for(s in Osc1Env)
	       s.setAttribute(7, value);

};

Content.getComponent("RELEASE5").setControlCallback(onRELEASE5Control);

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


const var XfMod = [Content.getComponent("XfSp1"),
                      Content.getComponent("XfSp2"),
                      Content.getComponent("XfSp3"),
                      Content.getComponent("XfSp4"),
                      Content.getComponent("XfSp5"),
                      Content.getComponent("XfSp6"),
                      Content.getComponent("XfSp7"),
             	   	  Content.getComponent("XfSp8"),
             	   	  Content.getComponent("XfSp9"),
             	   	  Content.getComponent("XfSp10"),
             	   	  Content.getComponent("XfSp11"),
             	   	  Content.getComponent("XfSp12"),
             	   	  Content.getComponent("XfSp13"),
             	   	  Content.getComponent("XfSp14"),
             	   	  Content.getComponent("XfSp15"),
             	   	  Content.getComponent("XfSp16"),
             	   	  Content.getComponent("XfSp17"),
             	   	  Content.getComponent("XfSp18"),
             	   	  Content.getComponent("XfSp19"),
             	   	  Content.getComponent("XfSp20"),
             	   	  Content.getComponent("XfSp21"),
             	   	  Content.getComponent("XfSp22"),
             	   	  Content.getComponent("XfSp23"),
             	   	  Content.getComponent("XfSp24")];
                      

inline function onXfSpControl(component, value)
{
for(s in XfMod)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("XfSp").setControlCallback(onXfSpControl);




//Harm Mod


inline function onHarmVelControl(component, value)
{
for(s in Pitches)
       s.setAttribute(28, value);
};

Content.getComponent("HarmVel").setControlCallback(onHarmVelControl);


inline function onHarmTrkControl(component, value)
{
for(s in Pitches)
       s.setAttribute(29, value);
};

Content.getComponent("HarmTrk").setControlCallback(onHarmTrkControl);


inline function onHarmMwControl(component, value)
{for(s in Pitches)
       s.setAttribute(30, value);
};

Content.getComponent("HarmMw").setControlCallback(onHarmMwControl);


inline function onHarmAtControl(component, value)
{
	for(s in Pitches)
       s.setAttribute(31, value);
};

Content.getComponent("HarmAt").setControlCallback(onHarmAtControl);


//User Pitches

inline function onUserPitch1Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(36, value);
};

Content.getComponent("UserPitch1").setControlCallback(onUserPitch1Control);

inline function onUserPitch2Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(37, value);
};

Content.getComponent("UserPitch2").setControlCallback(onUserPitch2Control);

inline function onUserPitch3Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(38, value);
};

Content.getComponent("UserPitch3").setControlCallback(onUserPitch3Control);

inline function onUserPitch4Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(39, value);
};

Content.getComponent("UserPitch4").setControlCallback(onUserPitch4Control);

inline function onUserPitch5Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(40, value);
};

Content.getComponent("UserPitch5").setControlCallback(onUserPitch5Control);

inline function onUserPitch6Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(41, value);
};

Content.getComponent("UserPitch6").setControlCallback(onUserPitch6Control);

inline function onUserPitch7Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(42, value);
};

Content.getComponent("UserPitch7").setControlCallback(onUserPitch7Control);

inline function onUserPitch8Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(43, value);
};

Content.getComponent("UserPitch8").setControlCallback(onUserPitch8Control);

inline function onUserPitch9Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(44, value);
};

Content.getComponent("UserPitch9").setControlCallback(onUserPitch9Control);

inline function onUserPitch10Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(45, value);
};

Content.getComponent("UserPitch10").setControlCallback(onUserPitch10Control);

inline function onUserPitch11Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(46, value);
};

Content.getComponent("UserPitch11").setControlCallback(onUserPitch11Control);

inline function onUserPitch12Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(47, value);
};

Content.getComponent("UserPitch12").setControlCallback(onUserPitch12Control);

inline function onUserPitch13Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(48, value);
};

Content.getComponent("UserPitch13").setControlCallback(onUserPitch13Control);

inline function onUserPitch14Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(49, value);
};

Content.getComponent("UserPitch14").setControlCallback(onUserPitch14Control);

inline function onUserPitch15Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(50, value);
};

Content.getComponent("UserPitch15").setControlCallback(onUserPitch15Control);

inline function onUserPitch16Control(component, value)
{
		for(s in Pitches)
       s.setAttribute(51, value);
};

Content.getComponent("UserPitch16").setControlCallback(onUserPitch16Control);function onNoteOn()
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
 