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
    
    
    //xfader
     
     
     inline function onXFsliderControl(component, value)
     {
     
     
            
       for (i = 0; i < XfWaves.length; i++)
                    XfWaves[i].showControl(value - 1 == i);
     
     for(s in Xfader)
            s.setAttribute(0, value);
            
            StageSelect.setValue(value);
     
           
     	
     };
     
     Content.getComponent("XFslider").setControlCallback(onXFsliderControl);
     
     
     inline function onXFslider2Control(component, value)
     {
     	for(s in Xfader)
     	       s.setAttribute(0, value);
     
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
     	       s.setAttribute(0, value);
     
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
     
     
//smooth

  inline function onSmoothControl(component, value)
  {	
  	for(s in Xfader)
  	       s.setAttribute(1, value);
  
   
  };
  
  Content.getComponent("Smooth").setControlCallback(onSmoothControl);
  
  
  inline function onXfsel2Control(component, value)
  {
  	  	for(s in Xfader)
  	       s.setAttribute(2, value);
  };
  
  Content.getComponent("Xfsel2").setControlCallback(onXfsel2Control);
  

 inline function onXfStahesControl(component, value)
 {
 	if(value == 1)
 	{
 	for(s in Xfader)
        s.setAttribute(4, 0);
        
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
            s.setAttribute(4, 1);
 
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
            s.setAttribute(4, 2);
            
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
 
  
  
  inline function onXfSmoothModeControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(3, value);
  };
  
  Content.getComponent("XfSmoothMode").setControlCallback(onXfSmoothModeControl);
                        
                        



inline function onXfEnvMod1Control(component, value)
{
for(s in Xfader)
	       s.setAttribute(5, value);
};

Content.getComponent("XfEnvMod1").setControlCallback(onXfEnvMod1Control);



inline function onXfEnvMod2Control(component, value)
{
for(s in Xfader)
	       s.setAttribute(6, value);
};

Content.getComponent("XfEnvMod2").setControlCallback(onXfEnvMod2Control);

inline function onXfModControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(7, value);
 
};

Content.getComponent("XfMod").setControlCallback(onXfModControl);


inline function onXfGlobalModControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(8, value);
};

Content.getComponent("XfGlobalMod").setControlCallback(onXfGlobalModControl);



inline function onXfVelControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(10
	       , value);

};

Content.getComponent("XfVel").setControlCallback(onXfVelControl);


inline function onXfTrkControl(component, value)
{
		for(s in Xfader)
	       s.setAttribute(11, value);

};

Content.getComponent("XfTrk").setControlCallback(onXfTrkControl);

inline function onXfMwControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(12, value);

};

Content.getComponent("XfMw").setControlCallback(onXfMwControl);


inline function onXfAtControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(13, value);

};

Content.getComponent("XfAt").setControlCallback(onXfAtControl);



inline function onXfTempoControl(component, value)
{
	for(s in Xfader)
		       s.setAttribute(14, value);

};

Content.getComponent("XfTempo").setControlCallback(onXfTempoControl);


inline function onXfDivControl(component, value)
{
for(s in Xfader)
		       s.setAttribute(15, value);
};

Content.getComponent("XfDiv").setControlCallback(onXfDivControl);


inline function onXfTrigModeControl(component, value)
{
for(s in Xfader)
		       s.setAttribute(16, value);
};

Content.getComponent("XfTrigMode").setControlCallback(onXfTrigModeControl);


inline function onLfoShapeXFControl(component, value)
{
	for(s in Xfader)
		       s.setAttribute(17, value);
};

Content.getComponent("LfoShapeXF").setControlCallback(onLfoShapeXFControl);


inline function onXfAControl(component, value)
{
	for(s in Xfader)
		       s.setAttribute(18, value);
};

Content.getComponent("XfA").setControlCallback(onXfAControl);

inline function onXfDDControl(component, value)
{
	for(s in Xfader)
		       s.setAttribute(19, value);
};

Content.getComponent("XfDD").setControlCallback(onXfDDControl);

inline function onXfSControl(component, value)
{
	for(s in Xfader)
			       s.setAttribute(20, value);
};

Content.getComponent("XfS").setControlCallback(onXfSControl);

inline function onXfRControl(component, value)
{
for(s in Xfader)
		       s.setAttribute(21, value);
};

Content.getComponent("XfR").setControlCallback(onXfRControl);

//loopenv

inline function onXfAtkLpControl(component, value)
{
for(s in Xfader)
		       s.setAttribute(22, value);
};

Content.getComponent("XfAtkLp").setControlCallback(onXfAtkLpControl);


inline function onXftrlLpControl(component, value)
{
	for(s in Xfader)
		       s.setAttribute(23, value);
};

Content.getComponent("XftrlLp").setControlCallback(onXftrlLpControl);



inline function onXfTempo1Control(component, value)
{
for(s in Xfader)
		       s.setAttribute(24, value);
};

Content.getComponent("XfTempo1").setControlCallback(onXfTempo1Control);

inline function onXfDiv1Control(component, value)
{
for(s in Xfader)
		       s.setAttribute(25, value);
};

Content.getComponent("XfDiv1").setControlCallback(onXfDiv1Control);

inline function onLpOneControl(component, value)
{
for(s in Xfader)
		       s.setAttribute(27, value);
};

Content.getComponent("LpOne").setControlCallback(onLpOneControl);




inline function onXfCrvControl(component, value)
{
for(s in Xfader)
		       s.setAttribute(24, value);
};

Content.getComponent("XfCrv").setControlCallback(onXfCrvControl);







const var XFslider = Content.getComponent("XFslider");
const var XFslider1 = Content.getComponent("XFslider1");
const var XFslider2 = Content.getComponent("XFslider2");



 





                                            

  
  //Poly Envs
  const var F1 = Synth.getEffect("F1");
  const var F2 = Synth.getEffect("F2");
  const var F3 = Synth.getEffect("F3");
  const var F4 = Synth.getEffect("F4");
  const var F5 = Synth.getEffect("F5");
  const var F6 = Synth.getEffect("F6");
  const var F7 = Synth.getEffect("F7");
  const var F8 = Synth.getEffect("F8");


  const var XfDiv1 = Content.getComponent("XfDiv1");
  const var XfEnv1 = Content.getComponent("XfEnv1");
  const var XfEnv2 = Content.getComponent("XfEnv2");
  
    
//Mod Sliderpack
  
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
  
  
  
  const var XfSp = Content.getComponent("XfSp");
  
