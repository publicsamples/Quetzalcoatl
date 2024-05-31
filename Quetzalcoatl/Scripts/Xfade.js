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
     

    
    //xfader
     

     inline function onXFsliderControl(component, value)
     {
	
	for(s in Xfader)
	          s.setAttribute(0, value);

     };
     
     Content.getComponent("XFslider").setControlCallback(onXFsliderControl);
     

   /*  
     
     inline function onXFslider2Control(component, value)
     {
     	for(s in Xfader)
     	       s.setAttribute(0, value);
     
     
            
     };
     
     Content.getComponent("XFslider2").setControlCallback(onXFslider2Control);
     
     
     inline function onXFslider1Control(component, value)
     {
     	for(s in Xfader)
     	       s.setAttribute(0, value);
     
      
     };
     
     Content.getComponent("XFslider1").setControlCallback(onXFslider1Control);
    */
     


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
  
  const var step1 = Content.getComponent("step1");
  const var LFO1 = Content.getComponent("LFO1");
  
  
 
    
    inline function onMODSEL1Control(component, value)
    {
    if(value == 1)
   	{
  	step1.showControl(1);
  	LFO1.showControl(0);
  	
  	for(s in Xfader)
  	  	       s.setAttribute(51, 3.1);
     }
     
     if(value == 2)
       	{
      	step1.showControl(0);
      	LFO1.showControl(1);
      	for(s in Xfader)
      	  	       s.setAttribute(51, 2.1);
         }
    };
    
    Content.getComponent("MODSEL1").setControlCallback(onMODSEL1Control);
    
const var Pre = Synth.getModulator("Pre");
const var PanSliders = Synth.getModulator("PanSliders");
const var XfIcons = Content.getComponent("XfIcons");
const var XfIcons1 = Content.getComponent("XfIcons1");
const var XfIcons2 = Content.getComponent("XfIcons2");






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


        PitchSpData.setNumSliders(8);
        FilterSpData.setNumSliders(8);
     FilterMasterSpData.setNumSliders(8);
     XfIcons.showControl(1);
     XfIcons1.showControl(0);
     XfIcons2.showControl(0);
        
        for(s in Pitches)
                s.setAttribute(50, 8.0);
        for(s in Filters)
                        s.setAttribute(48, 8);   
                        
         Pre.setAttribute(Pre.Pack, 8.0);        
         PanSliders.setAttribute(PanSliders.Pack, 8.0);   


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

            PitchSpData.setNumSliders(4);
            FilterMasterSpData.setNumSliders(8);
            XfIcons.showControl(0);
            XfIcons1.showControl(1);
            XfIcons2.showControl(0);

                  FilterMasterSpData.setNumSliders(4);
                  
                  for(s in Pitches)
                                s.setAttribute(50, 4.0);
for(s in Filters)
s.setAttribute(48, 4.0);


Pre.setAttribute(Pre.Pack, 4.0);        
       PanSliders.setAttribute(PanSliders.Pack, 4.0);  
            
             
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

                       PitchSpData.setNumSliders(2);
                       FilterMasterSpData.setNumSliders(8);
                       XfIcons.showControl(0);
                       XfIcons1.showControl(0);
                       XfIcons2.showControl(1);
                    
                             FilterMasterSpData.setNumSliders(2);
                             
                             for(s in Pitches)
                                           s.setAttribute(50, 2.0);
                             for(s in Filters)
                            s.setAttribute(48, 2.0);                                  
                 
                 Pre.setAttribute(Pre.Pack, 2.0);        
                        PanSliders.setAttribute(PanSliders.Pack, 2.0);  
                           
                
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
	       s.setAttribute(10, value);

};

Content.getComponent("XfVel").setControlCallback(onXfVelControl);

inline function onXfTrkControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(11, value);
};

Content.getComponent("XfTrk").setControlCallback(onXfTrkControl);




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
		       s.setAttribute(26, value);
};

Content.getComponent("LpOne").setControlCallback(onLpOneControl);




inline function onXfCrvControl(component, value)
{
for(s in Xfader)
		       s.setAttribute(27, value);
};

Content.getComponent("XfCrv").setControlCallback(onXfCrvControl);





const var XFslider = Content.getComponent("XFslider");


 





                                            

  
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

  
    
