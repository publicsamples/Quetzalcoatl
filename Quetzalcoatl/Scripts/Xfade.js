 //Xfade
  
  
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


  inline function onSmoothControl(component, value)
  {	
  	for(s in Xfader)
  	       s.setAttribute(s._2ndParam, value);
  
   
  };
  
  Content.getComponent("Smooth").setControlCallback(onSmoothControl);
  
  
  inline function onXfsel2Control(component, value)
  {
  	  	for(s in Xfader)
  	       s.setAttribute(s._3rdParam, value);
  };
  
  Content.getComponent("Xfsel2").setControlCallback(onXfsel2Control);


const var Pre = Synth.getModulator("Pre");

const var XfIcons = Content.getComponent("XfIcons");
const var XfIcons1 = Content.getComponent("XfIcons1");
const var XfIcons2 = Content.getComponent("XfIcons2");


const var Wsubs58 = [Content.getComponent("WaveSub8"),
                     Content.getComponent("WaveSub5"),
                     Content.getComponent("WaveSub6"),
                     Content.getComponent("WaveSub7")];

const var Wsubs38 = [Content.getComponent("WaveSub3"),
                     Content.getComponent("WaveSub4")];

const var WaveSub1 = Content.getComponent("WaveSub1");
const var WaveSub2 = Content.getComponent("WaveSub2");
const var WaveSub3 = Content.getComponent("WaveSub3");
const var WaveSub4 = Content.getComponent("WaveSub4");

const var HideWtLabels = [Content.getComponent("SampleWt5"),
                        Content.getComponent("SampleWt6"),
                        Content.getComponent("SampleWt7"),
                        Content.getComponent("SampleWt8")];

const var HideWtLabels1 = [Content.getComponent("SampleWt3"),
						Content.getComponent("SampleWt4")];

const var HideSfzLabels = [Content.getComponent("SampleSfz5"),
                        Content.getComponent("SampleSfz6"),
                        Content.getComponent("SampleSfz7"),
                        Content.getComponent("SampleSfz8")];

const var HideSfzLabels1 = [Content.getComponent("SampleSfz3"),
						Content.getComponent("SampleSfz4")];

const var HideUserLabels = [Content.getComponent("SampleUser5"),
                        Content.getComponent("SampleUser6"),
                        Content.getComponent("SampleUser7"),
                        Content.getComponent("SampleUser8")];

const var HideUserLabels1 = [Content.getComponent("SampleUser3"),
						Content.getComponent("SampleUser4")];
						
const var HideIntLabels = [Content.getComponent("SampleInt5"),
                        Content.getComponent("SampleInt6"),
                        Content.getComponent("SampleInt7"),
                        Content.getComponent("SampleInt8")];

const var HideIntLabels1 = [Content.getComponent("SampleInt3"),
						Content.getComponent("SampleInt4")];
						
const var HideLabels = [Content.getComponent("Sample5"),
                        Content.getComponent("Sample6"),
                        Content.getComponent("Sample7"),
                        Content.getComponent("Sample8")];

const var HideLabels1 = [Content.getComponent("Sample3"),
						Content.getComponent("Sample4")];
                  
const var PitchSliders = Synth.getModulator("PitchSliders");
const var PanSliders = Synth.getModulator("PanSliders");

const var QEXPANDED = Content.getComponent("QEXPANDED");
const var AllCollection = Content.getComponent("AllCollection");
                       
 inline function onXfStagesControl(component, value)
 {
 	if(value == 1)
 	{
 	for(s in Xfader)
        s.setAttribute(s._5thParam, 0);
        
        Group3.setBypassed(0);
        Group4.setBypassed(0);
        Group5.setBypassed(0);
        Group6.setBypassed(0);
        Group7.setBypassed(0);
        Group8.setBypassed(0);

for(s in Wsubs38)
        s.showControl(1);
        
for(s in Wsubs58)
        s.showControl(1);
        
       
        FilterSpData.setNumSliders(8);
     FilterMasterSpData.setNumSliders(8);
    XfIcons.showControl(1);
     XfIcons1.showControl(0);
     XfIcons2.showControl(0);
  
  for(s in HideLabels)
             s.showControl(1);
   for(s in HideLabels1)
                s.showControl(1);     
                
   for(s in HideWtLabels)
              s.showControl(1);
    for(s in HideWtLabels1)
                 s.showControl(1);  
                 
     for(s in HideSfzLabels)
                s.showControl(1);
      for(s in HideSfzLabels1)
                   s.showControl(1);    
                   
       for(s in HideUserLabels)
                  s.showControl(1);
        for(s in HideUserLabels1)
                     s.showControl(1);        
                     
        for(s in HideIntLabels)
                         s.showControl(1);
               for(s in HideIntLabels1)
                            s.showControl(1);                                                          
    
   
        for(s in Filters)
                        s.setAttribute(48, 8);   
                        
         Pre.setAttribute(Pre.Pack, 8.0);        
         PanSliders.setAttribute(PanSliders.Pack, 8.0);   
         PitchSliders.setAttribute(PitchSliders.Pack, 8.0);      
		
		
		QEXPANDED.showControl(0); 
		AllCollection.showControl(0); 

        }
        
     if(value == 2)
     {
     for(s in Xfader)
            s.setAttribute(s._5thParam, 1);
            
  for(s in HideLabels)
             s.showControl(0);
  for(s in HideLabels1)
               s.showControl(1);          
for(s in HideWtLabels)
             s.showControl(0);
   for(s in HideWtLabels1)
                s.showControl(1);  
                
    for(s in HideSfzLabels)
               s.showControl(0);
     for(s in HideSfzLabels1)
                  s.showControl(1);    
                  
      for(s in HideUserLabels)
                 s.showControl(0);
       for(s in HideUserLabels1)
                    s.showControl(1);        
                    
       for(s in HideIntLabels)
                        s.showControl(0);
              for(s in HideIntLabels1)
                           s.showControl(1); 
  	
 	Group3.setBypassed(0);
     Group4.setBypassed(0);
     Group5.setBypassed(1);
     Group6.setBypassed(1);
     Group7.setBypassed(1);
     Group8.setBypassed(1);   
     
     for(s in Wsubs38)
             s.showControl(1);
             
     for(s in Wsubs58)
             s.showControl(0);

           
          
            XfIcons.showControl(0);
            XfIcons1.showControl(1);
            XfIcons2.showControl(0);
         FilterMasterSpData.setNumSliders(4);
                  
  
for(s in Filters)
s.setAttribute(48, 4.0);


Pre.setAttribute(Pre.Pack, 4.0);
PitchSliders.setAttribute(PitchSliders.Pack, 4.0);           
       PanSliders.setAttribute(PanSliders.Pack, 4.0);  
            QEXPANDED.showControl(1); 
            AllCollection.showControl(0); 
            
             
            }
   
     if(value == 3)
     {
     for(s in Xfader)
            s.setAttribute(s._5thParam, 2);
            
            for(s in Wsubs38)
                    s.showControl(0);
                    
            for(s in Wsubs58)
                    s.showControl(0);
            
            for(s in HideLabels)
            s.showControl(0); 
                              
          for(s in HideLabels1)
             s.showControl(0);
             
             for(s in HideWtLabels)
                          s.showControl(0);
                for(s in HideWtLabels1)
                             s.showControl(0);  
                             
                 for(s in HideSfzLabels)
                            s.showControl(0);
                  for(s in HideSfzLabels1)
                               s.showControl(0);    
                              
                   for(s in HideUserLabels)
                              s.showControl(0);
                    for(s in HideUserLabels1)
                                 s.showControl(0);        
                                 
                    for(s in HideIntLabels)
                                     s.showControl(0);
                           for(s in HideIntLabels1)
                                        s.showControl(0); 
              
                   
            
            Group3.setBypassed(1);
                Group4.setBypassed(1);
                Group5.setBypassed(1);
                Group6.setBypassed(1);
                Group7.setBypassed(1);
                Group8.setBypassed(1); 

						XfIcons.showControl(0);
                       XfIcons1.showControl(0);
                       XfIcons2.showControl(1);

                    
                             FilterMasterSpData.setNumSliders(2);
                             
                        
                             for(s in Filters)
                            s.setAttribute(48, 2.0);                                  
                 
                 Pre.setAttribute(Pre.Pack, 2.0);    
                 PitchSliders.setAttribute(PitchSliders.Pack, 2.0);       
                        PanSliders.setAttribute(PanSliders.Pack, 2.0);  
                      
                      QEXPANDED.showControl(0);    
                      AllCollection.showControl(1); 
                      
                
            }
   
 };
 
 Content.getComponent("XfStages").setControlCallback(onXfStagesControl);
 
  
  
  inline function onXfSmoothModeControl(component, value)
  {
  	for(s in Xfader)
  	       s.setAttribute(3, value);
  };
  
  Content.getComponent("XfSmoothMode").setControlCallback(onXfSmoothModeControl);
                        

inline function onXfGlobalModControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(s.Global, value);
};

Content.getComponent("XfGlobalMod").setControlCallback(onXfGlobalModControl);


inline function onXfselControl(component, value)
{
		for(s in Xfader)
	       s.setAttribute(s.GlobalSrc, value);
};

Content.getComponent("Xfsel").setControlCallback(onXfselControl);



inline function onXfVelControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(s.Vel, value);

};

Content.getComponent("XfVel").setControlCallback(onXfVelControl);

inline function onXfTrkControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(s.Trk, value);
};

Content.getComponent("XfTrk").setControlCallback(onXfTrkControl);




inline function onXfAtControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(s.AT, value);
};

Content.getComponent("XfAt").setControlCallback(onXfAtControl);





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


  
    
