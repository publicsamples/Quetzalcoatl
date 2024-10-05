 const var m1step8 = Content.getComponent("m1step8");
const var m1step1 = Content.getComponent("m1step1");
const var m1step2 = Content.getComponent("m1step2");
const var m1step3 = Content.getComponent("m1step3");
const var m1step4 = Content.getComponent("m1step4");
const var m1step5 = Content.getComponent("m1step5");
const var m1step6 = Content.getComponent("m1step6");
const var m1step7 = Content.getComponent("m1step7");

const var m1table8 = Content.getComponent("m1table8");
const var m1table1 = Content.getComponent("m1table1");
const var m1table2 = Content.getComponent("m1table2");
const var m1table3 = Content.getComponent("m1table3");
const var m1table4 = Content.getComponent("m1table4");
const var m1table5 = Content.getComponent("m1table5");
const var m1table6 = Content.getComponent("m1table6");
const var m1table7 = Content.getComponent("m1table7");


const var Gmod1 = Synth.getEffect("Gmod1");
const var Gmod2 = Synth.getEffect("Gmod2");
const var Gmod3 = Synth.getEffect("Gmod3");
const var Gmod4 = Synth.getEffect("Gmod4");
const var Gmod5 = Synth.getEffect("Gmod5");
const var Gmod6 = Synth.getEffect("Gmod6");
const var Gmod7 = Synth.getEffect("Gmod7");
const var Gmod8 = Synth.getEffect("Gmod8");

const var Gmod9 = Synth.getModulator("Gmod9");
const var Gmod10 = Synth.getModulator("Gmod10");
const var Gmod11 = Synth.getModulator("Gmod11");
const var Gmod12 = Synth.getModulator("Gmod12");
const var Gmod13 = Synth.getModulator("Gmod13");
const var Gmod14 = Synth.getModulator("Gmod14");
const var Gmod15 = Synth.getModulator("Gmod15");
const var Gmod16 = Synth.getModulator("Gmod16");


const var Vel = [Synth.getModulator("Velocity Modulator1"),
 					Synth.getModulator("Velocity Modulator2"),
 					Synth.getModulator("Velocity Modulator3"),
 					Synth.getModulator("Velocity Modulator4"),
 					Synth.getModulator("Velocity Modulator5"),
 					Synth.getModulator("Velocity Modulator6"),
 					Synth.getModulator("Velocity Modulator7"),
 					Synth.getModulator("Velocity Modulator8")];

const var env1 = Content.getComponent("env1");



inline function onGmodMode1Control(component, value)
{
	if(value == 1)
	  	{

	m1step1.showControl(0);
    m1table1.showControl(0);
    env1.showControl(1);
    Waveform1.showControl(0);
    Gmod1.setAttribute(Gmod1.Shape, 0);
    
    }
    
    if(value == 2)
    	  	{
    
	m1step1.showControl(0);
    m1table1.showControl(0);
    env1.showControl(0);
    Waveform1.showControl(1);
    Gmod1.setAttribute(Gmod1.Shape, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
       	m1step1.showControl(0);
    m1table1.showControl(0);
    env1.showControl(0);
    Waveform1.showControl(1);
    Gmod1.setAttribute(Gmod1.Shape, 2);
               
               }
               

           if(value == 4)
           	  	{
           
          
       	m1step1.showControl(0);
    m1table1.showControl(0);
    env1.showControl(0);
    Waveform1.showControl(1);
    Gmod1.setAttribute(Gmod1.Shape, 3);
               
               } 
   if(value == 5)
           	  	{
           
         
       	m1step1.showControl(0);
    m1table1.showControl(0);
    env1.showControl(0);
    Waveform1.showControl(1);
    Gmod1.setAttribute(Gmod1.Shape, 4);
               
               }   
      if(value == 6)
           	  	{
           
       	m1step1.showControl(0);
    m1table1.showControl(0);
    env1.showControl(0);
    Waveform1.showControl(1);
    Gmod1.setAttribute(Gmod1.Shape, 5);
               
               }    
   if(value == 7)
           	  	{
           
       	m1step1.showControl(1);
    m1table1.showControl(0);
    env1.showControl(0);
    Waveform1.showControl(0);
    Gmod1.setAttribute(Gmod1.Shape, 7);
               
               }  
               
   if(value == 8)
             	  	{
             
         	m1step1.showControl(0);
      m1table1.showControl(1);
      env1.showControl(0);
      Waveform1.showControl(0);
      Gmod1.setAttribute(Gmod1.Shape, 6);
                 
                 }                       
                                                                  
};

Content.getComponent("GmodMode1").setControlCallback(onGmodMode1Control);

const var env2 = Content.getComponent("env2");



inline function onGmodMode2Control(component, value)
{
	if(value == 1)
	  	{

	m1step2.showControl(0);
    m1table2.showControl(0);
    env2.showControl(1);
    Waveform3.showControl(0);
    Gmod2.setAttribute(Gmod2.Shape, 0);
    
    }
    
    if(value == 2)
    	  	{
    
	m1step2.showControl(0);
    m1table2.showControl(0);
    env2.showControl(0);
    Waveform3.showControl(1);
    Gmod2.setAttribute(Gmod2.Shape, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
       	m1step2.showControl(0);
    m1table2.showControl(0);
    env2.showControl(0);
    Waveform3.showControl(1);
    Gmod2.setAttribute(Gmod2.Shape, 2);
               
               }
               

           if(value == 4)
           	  	{
           
          
       	m1step2.showControl(0);
    m1table2.showControl(0);
    env2.showControl(0);
    Waveform3.showControl(1);
    Gmod2.setAttribute(Gmod2.Shape, 3);
               
               } 
   if(value == 5)
           	  	{
           
         
       	m1step2.showControl(0);
    m1table2.showControl(0);
    env2.showControl(0);
    Waveform3.showControl(1);
    Gmod2.setAttribute(Gmod2.Shape, 4);
               
               }   
      if(value == 6)
           	  	{
           
       	m1step2.showControl(0);
    m1table2.showControl(0);
    env2.showControl(0);
    Waveform3.showControl(1);
    Gmod2.setAttribute(Gmod2.Shape, 5);
               
               }    
   if(value == 7)
           	  	{
           
       	m1step2.showControl(1);
    m1table2.showControl(0);
    env2.showControl(0);
    Waveform3.showControl(0);
    Gmod2.setAttribute(Gmod2.Shape, 6);
               
               }  
               
   if(value == 8)
             	  	{
             
         	m1step2.showControl(0);
      m1table2.showControl(1);
      env2.showControl(0);
      Waveform3.showControl(0);
      Gmod2.setAttribute(Gmod2.Shape, 7);
                 
                 }                       
                                                                  
};

Content.getComponent("GmodMode2").setControlCallback(onGmodMode2Control);

const var env3 = Content.getComponent("env3");



inline function onGmodMode3Control(component, value)
{
	if(value == 1)
	  	{

	m1step3.showControl(0);
    m1table3.showControl(0);
    env3.showControl(1);
    Waveform5.showControl(0);
    Gmod3.setAttribute(Gmod3.Shape, 0);
    
    }
    
    if(value == 2)
    	  	{
    
	m1step3.showControl(0);
    m1table3.showControl(0);
    env3.showControl(0);
    Waveform5.showControl(1);
    Gmod3.setAttribute(Gmod3.Shape, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
       	m1step3.showControl(0);
    m1table3.showControl(0);
    env3.showControl(0);
    Waveform5.showControl(1);
    Gmod3.setAttribute(Gmod3.Shape, 2);
               
               }
               

           if(value == 4)
           	  	{
           
          
       	m1step3.showControl(0);
    m1table3.showControl(0);
    env3.showControl(0);
    Waveform5.showControl(1);
    Gmod3.setAttribute(Gmod3.Shape, 3);
               
               } 
   if(value == 5)
           	  	{
           
         
       	m1step3.showControl(0);
    m1table3.showControl(0);
    env3.showControl(0);
    Waveform5.showControl(1);
    Gmod3.setAttribute(Gmod3.Shape, 4);
               
               }   
      if(value == 6)
           	  	{
           
       	m1step3.showControl(0);
    m1table3.showControl(0);
    env3.showControl(0);
    Waveform5.showControl(1);
    Gmod3.setAttribute(Gmod3.Shape, 5);
               
               }    
   if(value == 7)
           	  	{
           
       	m1step3.showControl(1);
    m1table3.showControl(0);
    env3.showControl(0);
    Waveform5.showControl(0);
    Gmod3.setAttribute(Gmod3.Shape, 6);
               
               }  
               
   if(value == 8)
             	  	{
             
         	m1step3.showControl(0);
      m1table3.showControl(1);
      env3.showControl(0);
      Waveform5.showControl(0);
      Gmod3.setAttribute(Gmod3.Shape, 7);
                 
                 }                       
                                                                  
};

Content.getComponent("GmodMode3").setControlCallback(onGmodMode3Control);

const var env4 = Content.getComponent("env4");



inline function onGmodMode4Control(component, value)
{
	if(value == 1)
	  	{

	m1step4.showControl(0);
    m1table4.showControl(0);
    env4.showControl(1);
    Waveform7.showControl(0);
    Gmod4.setAttribute(Gmod4.Shape, 0);
    
    }
    
    if(value == 2)
    	  	{
    
	m1step4.showControl(0);
    m1table4.showControl(0);
    env4.showControl(0);
    Waveform7.showControl(1);
    Gmod4.setAttribute(Gmod4.Shape, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
       	m1step4.showControl(0);
    m1table4.showControl(0);
    env4.showControl(0);
    Waveform7.showControl(1);
    Gmod4.setAttribute(Gmod4.Shape, 2);
               
               }
               

           if(value == 4)
           	  	{
           
          
       	m1step4.showControl(0);
    m1table4.showControl(0);
    env4.showControl(0);
    Waveform7.showControl(1);
    Gmod4.setAttribute(Gmod4.Shape, 3);
               
               } 
   if(value == 5)
           	  	{
           
         
       	m1step4.showControl(0);
    m1table4.showControl(0);
    env4.showControl(0);
    Waveform7.showControl(1);
    Gmod4.setAttribute(Gmod4.Shape, 4);
               
               }   
      if(value == 6)
           	  	{
           
       	m1step4.showControl(0);
    m1table4.showControl(0);
    env4.showControl(0);
    Waveform7.showControl(1);
    Gmod4.setAttribute(Gmod4.Shape, 5);
               
               }    
   if(value == 7)
           	  	{
           
       	m1step4.showControl(1);
    m1table4.showControl(0);
    env4.showControl(0);
    Waveform7.showControl(0);
    Gmod4.setAttribute(Gmod4.Shape, 6);
               
               }  
               
   if(value == 8)
             	  	{
             
         	m1step4.showControl(0);
      m1table4.showControl(1);
      env4.showControl(0);
      Waveform7.showControl(0);
      Gmod4.setAttribute(Gmod4.Shape, 7);
                 
                 }                       
                                                                  
};

Content.getComponent("GmodMode4").setControlCallback(onGmodMode4Control);

const var env5 = Content.getComponent("env5");



inline function onGmodMode5Control(component, value)
{
	if(value == 1)
	  	{

	m1step5.showControl(0);
    m1table5.showControl(0);
    env5.showControl(1);
    Waveform9.showControl(0);
    Gmod5.setAttribute(Gmod5.Shape, 0);
    
    }
    
    if(value == 2)
    	  	{
    
	m1step5.showControl(0);
    m1table5.showControl(0);
    env5.showControl(0);
    Waveform9.showControl(1);
    Gmod5.setAttribute(Gmod5.Shape, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
       	m1step5.showControl(0);
    m1table5.showControl(0);
    env5.showControl(0);
    Waveform9.showControl(1);
    Gmod5.setAttribute(Gmod5.Shape, 2);
               
               }
               

           if(value == 4)
           	  	{
           
          
       	m1step5.showControl(0);
    m1table5.showControl(0);
    env5.showControl(0);
    Waveform9.showControl(1);
    Gmod5.setAttribute(Gmod5.Shape, 3);
               
               } 
   if(value == 5)
           	  	{
           
         
       	m1step5.showControl(0);
    m1table5.showControl(0);
    env5.showControl(0);
    Waveform9.showControl(1);
    Gmod5.setAttribute(Gmod5.Shape, 4);
               
               }   
      if(value == 6)
           	  	{
           
       	m1step5.showControl(0);
    m1table5.showControl(0);
    env5.showControl(0);
    Waveform9.showControl(1);
    Gmod5.setAttribute(Gmod5.Shape, 5);
               
               }    
   if(value == 7)
           	  	{
           
       	m1step5.showControl(1);
    m1table5.showControl(0);
    env5.showControl(0);
    Waveform9.showControl(0);
    Gmod5.setAttribute(Gmod5.Shape, 6);
               
               }  
               
   if(value == 8)
             	  	{
             
         	m1step5.showControl(0);
      m1table5.showControl(1);
      env5.showControl(0);
      Waveform9.showControl(0);
      Gmod5.setAttribute(Gmod5.Shape, 7);
                 
                 }                       
                                                                  
};

Content.getComponent("GmodMode5").setControlCallback(onGmodMode5Control);

const var env6 = Content.getComponent("env6");



inline function onGmodMode6Control(component, value)
{
	if(value == 1)
	  	{

	m1step6.showControl(0);
    m1table6.showControl(0);
    env6.showControl(1);
    Waveform11.showControl(0);
    Gmod6.setAttribute(Gmod6.Shape, 0);
    
    }
    
    if(value == 2)
    	  	{
    
	m1step6.showControl(0);
    m1table6.showControl(0);
    env6.showControl(0);
    Waveform11.showControl(1);
    Gmod6.setAttribute(Gmod6.Shape, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
       	m1step6.showControl(0);
    m1table6.showControl(0);
    env6.showControl(0);
    Waveform11.showControl(1);
    Gmod6.setAttribute(Gmod6.Shape, 2);
               
               }
               

           if(value == 4)
           	  	{
           
          
       	m1step6.showControl(0);
    m1table6.showControl(0);
    env6.showControl(0);
    Waveform11.showControl(1);
    Gmod6.setAttribute(Gmod6.Shape, 3);
               
               } 
   if(value == 5)
           	  	{
           
         
       	m1step6.showControl(0);
    m1table6.showControl(0);
    env6.showControl(0);
    Waveform11.showControl(1);
    Gmod6.setAttribute(Gmod6.Shape, 4);
               
               }   
      if(value == 6)
           	  	{
           
       	m1step6.showControl(0);
    m1table6.showControl(0);
    env6.showControl(0);
    Waveform11.showControl(1);
    Gmod6.setAttribute(Gmod6.Shape, 5);
               
               }    
   if(value == 7)
           	  	{
           
       	m1step6.showControl(1);
    m1table6.showControl(0);
    env6.showControl(0);
    Waveform11.showControl(0);
    Gmod6.setAttribute(Gmod6.Shape, 6);
               
               }  
               
   if(value == 8)
             	  	{
             
         	m1step6.showControl(0);
      m1table6.showControl(1);
      env6.showControl(0);
      Waveform11.showControl(0);
      Gmod6.setAttribute(Gmod6.Shape, 7);
                 
                 }                       
                                                                  
};

Content.getComponent("GmodMode6").setControlCallback(onGmodMode6Control);

const var env7 = Content.getComponent("env7");



inline function onGmodMode7Control(component, value)
{
	if(value == 1)
	  	{

	m1step7.showControl(0);
    m1table7.showControl(0);
    env7.showControl(1);
    Waveform13.showControl(0);
    Gmod7.setAttribute(Gmod7.Shape, 0);
    
    }
    
    if(value == 2)
    	  	{
    
	m1step7.showControl(0);
    m1table7.showControl(0);
    env7.showControl(0);
    Waveform13.showControl(1);
    Gmod7.setAttribute(Gmod7.Shape, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
       	m1step7.showControl(0);
    m1table7.showControl(0);
    env7.showControl(0);
    Waveform13.showControl(1);
    Gmod7.setAttribute(Gmod7.Shape, 2);
               
               }
               

           if(value == 4)
           	  	{
           
          
       	m1step7.showControl(0);
    m1table7.showControl(0);
    env7.showControl(0);
    Waveform13.showControl(1);
    Gmod7.setAttribute(Gmod7.Shape, 3);
               
               } 
   if(value == 5)
           	  	{
           
         
       	m1step7.showControl(0);
    m1table7.showControl(0);
    env7.showControl(0);
    Waveform13.showControl(1);
    Gmod7.setAttribute(Gmod7.Shape, 4);
               
               }   
      if(value == 6)
           	  	{
           
       	m1step7.showControl(0);
    m1table7.showControl(0);
    env7.showControl(0);
    Waveform13.showControl(1);
    Gmod7.setAttribute(Gmod7.Shape, 5);
               
               }    
   if(value == 7)
           	  	{
           
       	m1step7.showControl(1);
    m1table7.showControl(0);
    env7.showControl(0);
    Waveform13.showControl(0);
    Gmod7.setAttribute(Gmod7.Shape, 6);
               
               }  
               
   if(value == 8)
             	  	{
             
         	m1step7.showControl(0);
      m1table7.showControl(1);
      env7.showControl(0);
      Waveform13.showControl(0);
      Gmod7.setAttribute(Gmod7.Shape, 7);
                 
                 }                       
                                                                  
};

Content.getComponent("GmodMode7").setControlCallback(onGmodMode7Control);

const var env8 = Content.getComponent("env8");



inline function onGmodMode8Control(component, value)
{
	if(value == 1)
	  	{

	m1step8.showControl(0);
    m1table8.showControl(0);
    env8.showControl(1);
    Waveform15.showControl(0);
    Gmod8.setAttribute(Gmod8.Shape, 0);
    
    }
    
    if(value == 2)
    	  	{
    
	m1step8.showControl(0);
    m1table8.showControl(0);
    env8.showControl(0);
    Waveform15.showControl(1);
    Gmod8.setAttribute(Gmod8.Shape, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
       	m1step8.showControl(0);
    m1table8.showControl(0);
    env8.showControl(0);
    Waveform15.showControl(1);
    Gmod8.setAttribute(Gmod8.Shape, 2);
               
               }
               

           if(value == 4)
           	  	{
           
          
       	m1step8.showControl(0);
    m1table8.showControl(0);
    env8.showControl(0);
    Waveform15.showControl(1);
    Gmod8.setAttribute(Gmod8.Shape, 3);
               
               } 
   if(value == 5)
           	  	{
           
         
       	m1step8.showControl(0);
    m1table8.showControl(0);
    env8.showControl(0);
    Waveform15.showControl(1);
    Gmod8.setAttribute(Gmod8.Shape, 4);
               
               }   
      if(value == 6)
           	  	{
           
       	m1step8.showControl(0);
    m1table8.showControl(0);
    env8.showControl(0);
    Waveform15.showControl(1);
    Gmod8.setAttribute(Gmod8.Shape, 5);
               
               }    
   if(value == 7)
           	  	{
           
       	m1step8.showControl(1);
    m1table8.showControl(0);
    env8.showControl(0);
    Waveform15.showControl(0);
    Gmod8.setAttribute(Gmod8.Shape, 6);
               
               }  
               
   if(value == 8)
             	  	{
             
         	m1step8.showControl(0);
      m1table8.showControl(1);
      env8.showControl(0);
      Waveform15.showControl(0);
      Gmod8.setAttribute(Gmod8.Shape, 7);
                 
                 }                       
                                                                  
};

Content.getComponent("GmodMode8").setControlCallback(onGmodMode8Control);






const var GlobalMod1 = Content.getComponent("GlobalMod1");
const var GlobalMod2 = Content.getComponent("GlobalMod2");
const var GlobalMod3 = Content.getComponent("GlobalMod3");
const var GlobalMod4 = Content.getComponent("GlobalMod4");
const var GlobalMod5 = Content.getComponent("GlobalMod5");
const var GlobalMod6 = Content.getComponent("GlobalMod6");
const var GlobalMod7 = Content.getComponent("GlobalMod7");
const var GlobalMod8 = Content.getComponent("GlobalMod8");


inline function onModPage1Control(component, value)
{
	
	if(value == 1)
	  	{

		GlobalMod1.showControl(1);
	    GlobalMod3.showControl(0);
	    GlobalMod2.showControl(0);
	    GlobalMod4.showControl(0);
	    GlobalMod5.showControl(0);
	    GlobalMod7.showControl(0);
	    GlobalMod6.showControl(0);
	    GlobalMod8.showControl(0);
	
	    
	    }
	    

if(value == 2)
  	{

	GlobalMod1.showControl(0);
	    GlobalMod3.showControl(0);
	    GlobalMod2.showControl(1);
	    GlobalMod4.showControl(0);
	    GlobalMod5.showControl(0);
	    GlobalMod7.showControl(0);
	    GlobalMod6.showControl(0);
	    GlobalMod8.showControl(0);
	
    }
if(value == 3)
  	{

			GlobalMod1.showControl(0);
	    GlobalMod3.showControl(1);
	    GlobalMod2.showControl(0);
	    GlobalMod4.showControl(0);
	    GlobalMod5.showControl(0);
	    GlobalMod7.showControl(0);
	    GlobalMod6.showControl(0);
	    GlobalMod8.showControl(0);
	
   
    }
   
   if(value == 4)
     	{
   
   		GlobalMod1.showControl(0);
	    GlobalMod3.showControl(0);
	    GlobalMod2.showControl(0);
	    GlobalMod4.showControl(1);
	    GlobalMod5.showControl(0);
	    GlobalMod7.showControl(0);
	    GlobalMod6.showControl(0);
	    GlobalMod8.showControl(0);
	
       } 
       
       if(value == 5)
         	{
       
       		GlobalMod1.showControl(0);
       	    GlobalMod3.showControl(0);
       	    GlobalMod2.showControl(0);
       	    GlobalMod4.showControl(0);
       	    GlobalMod5.showControl(1);
       	    GlobalMod7.showControl(0);
       	    GlobalMod6.showControl(0);
       	    GlobalMod8.showControl(0);
       	
           } 
           
           
           if(value == 6)
                   	{
                 
                 		GlobalMod1.showControl(0);
                 	    GlobalMod3.showControl(0);
                 	    GlobalMod2.showControl(0);
                 	    GlobalMod4.showControl(0);
                 	    GlobalMod5.showControl(0);
                 	    GlobalMod7.showControl(0);
                 	    GlobalMod6.showControl(1);
                 	    GlobalMod8.showControl(0);
                 	
                     } 
  if(value == 7)
                    	{
                  
                  		GlobalMod1.showControl(0);
                  	    GlobalMod3.showControl(0);
                  	    GlobalMod2.showControl(0);
                  	    GlobalMod4.showControl(0);
                  	    GlobalMod5.showControl(0);
                  	    GlobalMod7.showControl(1);
                  	    GlobalMod6.showControl(0);
                  	    GlobalMod8.showControl(0);
                  	
                      } 
                      
                        if(value == 8)
                    	{
                  
                  		GlobalMod1.showControl(0);
                  	    GlobalMod3.showControl(0);
                  	    GlobalMod2.showControl(0);
                  	    GlobalMod4.showControl(0);
                  	    GlobalMod5.showControl(0);
                  	    GlobalMod7.showControl(0);
                  	    GlobalMod6.showControl(0);
                  	    GlobalMod8.showControl(1);
                  	
                      }                   
    
};

Content.getComponent("ModPage1").setControlCallback(onModPage1Control);

//tempo mod menus


inline function onTempo1Control(component, value)
{
 Gmod1.setAttribute(Gmod1.Tempo, value);
	 Gmod9.setAttribute(Gmod9.Tempo, value);
};

Content.getComponent("Tempo1").setControlCallback(onTempo1Control);


inline function onDiv1Control(component, value)
{
	 Gmod1.setAttribute(Gmod1.Divide, value);
	 Gmod9.setAttribute(Gmod9.Div, value);
};

Content.getComponent("Div1").setControlCallback(onDiv1Control);

inline function onTmod1Control(component, value)
{
 Gmod1.setAttribute(Gmod1.TempoMod, value);
	 Gmod9.setAttribute(Gmod9.TempoMod, value);
};

Content.getComponent("Tmod1").setControlCallback(onTmod1Control);


inline function onTmodSrc1Control(component, value)
{
 Gmod1.setAttribute(Gmod1.TempoSrc, value-1);
 Gmod9.setAttribute(Gmod9.TempoSrc, value-1);
};

Content.getComponent("TmodSrc1").setControlCallback(onTmodSrc1Control);

const var Div1 = Content.getComponent("Div1");
const var Speed1 = Content.getComponent("Speed1");
const var Tempo1 = Content.getComponent("Tempo1");



inline function onTempoSync1Control(component, value)
{

 
 if(value == 0)
      	{
	Gmod1.setAttribute(Gmod1.Sync, 0);
	Gmod9.setAttribute(Gmod9.Sync, 0);
	Div1.showControl(0);
	Speed1.showControl(1);
	Tempo1.showControl(0);
	}

if(value == 1)
     	{
	Gmod1.setAttribute(Gmod1.Sync, 1);
	Gmod9.setAttribute(Gmod9.Sync, 1);
	Div1.showControl(1);
	Speed1.showControl(0);
	Tempo1.showControl(1);
	}	
	

};

Content.getComponent("TempoSync1").setControlCallback(onTempoSync1Control);

const var TrigSrc1 = Content.getComponent("TrigSrc1");
const var GmodOneShot1 = Content.getComponent("GmodOneShot1");


inline function onTrigMode1Control(component, value)
{
	 if(value == 1)
      	{
	Gmod1.setAttribute(Gmod1.TrigMode, 0);
	TrigSrc1.showControl(0);
	GmodOneShot1.showControl(0);

	}
	
	if(value == 2)
	      	{
		Gmod1.setAttribute(Gmod1.TrigMode, 1);
		TrigSrc1.showControl(0);
		GmodOneShot1.showControl(1);
	
		}
	if(value == 3)
	      	{
		Gmod1.setAttribute(Gmod1.TrigMode, 2);
		TrigSrc1.showControl(1);
		GmodOneShot1.showControl(1);
	
		}	
		
};

Content.getComponent("TrigMode1").setControlCallback(onTrigMode1Control);


inline function onSpeed1Control(component, value)
{
 Gmod1.setAttribute(Gmod1.SpeedMS, value);
	 Gmod9.setAttribute(Gmod9.SpeedMs, value);
};

Content.getComponent("Speed1").setControlCallback(onSpeed1Control);


inline function onTempo2Control(component, value)
{
 Gmod2.setAttribute(Gmod2.Tempo, value);
	 Gmod10.setAttribute(Gmod10.Tempo, value);
};

Content.getComponent("Tempo2").setControlCallback(onTempo2Control);


inline function onDiv2Control(component, value)
{
	 Gmod2.setAttribute(Gmod2.Divide, value);
	 Gmod10.setAttribute(Gmod10.Div, value);
};

Content.getComponent("Div2").setControlCallback(onDiv2Control);

inline function onTmod2Control(component, value)
{
 Gmod2.setAttribute(Gmod2.TempoMod, value);
	 Gmod10.setAttribute(Gmod10.TempoMod, value);
};

Content.getComponent("Tmod2").setControlCallback(onTmod2Control);


inline function onTmodSrc2Control(component, value)
{
 Gmod2.setAttribute(Gmod2.TempoSrc, value-1);
 Gmod10.setAttribute(Gmod10.TempoSrc, value)-1;
};

Content.getComponent("TmodSrc2").setControlCallback(onTmodSrc2Control);

const var Div2 = Content.getComponent("Div2");
const var Speed2 = Content.getComponent("Speed2");
const var Tempo2 = Content.getComponent("Tempo2");



inline function onTempoSync2Control(component, value)
{

 
 if(value == 0)
      	{
	Gmod2.setAttribute(Gmod2.Sync, 0);
	Gmod10.setAttribute(Gmod10.Sync, 0);
	Div2.showControl(0);
	Speed2.showControl(1);
	Tempo2.showControl(0);
	}

if(value == 1)
     	{
	Gmod2.setAttribute(Gmod2.Sync, 1);
	Gmod10.setAttribute(Gmod10.Sync, 1);
	Div2.showControl(1);
	Speed2.showControl(0);
	Tempo2.showControl(1);
	}	
	

};

Content.getComponent("TempoSync2").setControlCallback(onTempoSync2Control);

const var TrigSrc2 = Content.getComponent("TrigSrc2");
const var GmodOneShot2 = Content.getComponent("GmodOneShot2");


inline function onTrigMode2Control(component, value)
{
	 if(value == 1)
      	{
	Gmod2.setAttribute(Gmod2.TrigMode, 0);
	TrigSrc2.showControl(0);
	GmodOneShot2.showControl(0);

	}
	
	if(value == 2)
	      	{
		Gmod2.setAttribute(Gmod2.TrigMode, 1);
		TrigSrc2.showControl(0);
		GmodOneShot2.showControl(1);
	
		}
	if(value == 3)
	      	{
		Gmod2.setAttribute(Gmod2.TrigMode, 2);
		TrigSrc2.showControl(1);
		GmodOneShot2.showControl(1);
	
		}	
		
};

Content.getComponent("TrigMode2").setControlCallback(onTrigMode2Control);


inline function onSpeed2Control(component, value)
{
 Gmod2.setAttribute(Gmod2.SpeedMS, value);
	 Gmod10.setAttribute(Gmod10.SpeedMs, value);
};

Content.getComponent("Speed2").setControlCallback(onSpeed2Control);


inline function onTempo3Control(component, value)
{
 Gmod3.setAttribute(Gmod3.Tempo, value);
	 Gmod11.setAttribute(Gmod11.Tempo, value);
};

Content.getComponent("Tempo3").setControlCallback(onTempo3Control);


inline function onDiv3Control(component, value)
{
	 Gmod3.setAttribute(Gmod3.Divide, value);
	 Gmod11.setAttribute(Gmod11.Div, value);
};

Content.getComponent("Div3").setControlCallback(onDiv3Control);

inline function onTmod3Control(component, value)
{
 Gmod3.setAttribute(Gmod3.TempoMod, value);
	 Gmod11.setAttribute(Gmod11.TempoMod, value);
};

Content.getComponent("Tmod3").setControlCallback(onTmod3Control);


inline function onTmodSrc3Control(component, value)
{
 Gmod3.setAttribute(Gmod3.TempoSrc, value-1);
 Gmod11.setAttribute(Gmod11.TempoSrc, value-1);
};

Content.getComponent("TmodSrc3").setControlCallback(onTmodSrc3Control);

const var Div3 = Content.getComponent("Div3");
const var Speed3 = Content.getComponent("Speed3");
const var Tempo3 = Content.getComponent("Tempo3");



inline function onTempoSync3Control(component, value)
{

 
 if(value == 0)
      	{
	Gmod3.setAttribute(Gmod3.Sync, 0);
	Gmod11.setAttribute(Gmod11.Sync, 0);
	Div3.showControl(0);
	Speed3.showControl(1);
	Tempo3.showControl(0);
	}

if(value == 1)
     	{
	Gmod3.setAttribute(Gmod3.Sync, 1);
	Gmod11.setAttribute(Gmod11.Sync, 1);
	Div3.showControl(1);
	Speed3.showControl(0);
	Tempo3.showControl(1);
	}	
	

};

Content.getComponent("TempoSync3").setControlCallback(onTempoSync3Control);

const var TrigSrc3 = Content.getComponent("TrigSrc3");
const var GmodOneShot3 = Content.getComponent("GmodOneShot3");


inline function onTrigMode3Control(component, value)
{
	 if(value == 1)
      	{
	Gmod3.setAttribute(Gmod3.TrigMode, 0);
	TrigSrc3.showControl(0);
	GmodOneShot3.showControl(0);

	}
	
	if(value == 2)
	      	{
		Gmod3.setAttribute(Gmod3.TrigMode, 1);
		TrigSrc3.showControl(0);
		GmodOneShot3.showControl(1);
	
		}
	if(value == 3)
	      	{
		Gmod3.setAttribute(Gmod3.TrigMode, 2);
		TrigSrc3.showControl(1);
		GmodOneShot3.showControl(1);
	
		}	
		
};

Content.getComponent("TrigMode3").setControlCallback(onTrigMode3Control);


inline function onSpeed3Control(component, value)
{
 Gmod3.setAttribute(Gmod3.SpeedMS, value);
	 Gmod11.setAttribute(Gmod11.SpeedMs, value);
};

Content.getComponent("Speed3").setControlCallback(onSpeed3Control);


inline function onTempo4Control(component, value)
{
 Gmod4.setAttribute(Gmod4.Tempo, value);
	 Gmod12.setAttribute(Gmod12.Tempo, value);
};

Content.getComponent("Tempo4").setControlCallback(onTempo4Control);


inline function onDiv4Control(component, value)
{
	 Gmod4.setAttribute(Gmod4.Divide, value);
	 Gmod12.setAttribute(Gmod12.Div, value);
};

Content.getComponent("Div4").setControlCallback(onDiv4Control);

inline function onTmod4Control(component, value)
{
 Gmod4.setAttribute(Gmod4.TempoMod, value);
	 Gmod12.setAttribute(Gmod12.TempoMod, value);
};

Content.getComponent("Tmod4").setControlCallback(onTmod4Control);


inline function onTmodSrc4Control(component, value)
{
 Gmod4.setAttribute(Gmod4.TempoSrc, value-1);
 Gmod12.setAttribute(Gmod12.TempoSrc, value-1);
};

Content.getComponent("TmodSrc4").setControlCallback(onTmodSrc4Control);

const var Div4 = Content.getComponent("Div4");
const var Speed4 = Content.getComponent("Speed4");
const var Tempo4 = Content.getComponent("Tempo4");



inline function onTempoSync4Control(component, value)
{

 
 if(value == 0)
      	{
	Gmod4.setAttribute(Gmod4.Sync, 0);
	Gmod12.setAttribute(Gmod12.Sync, 0);
	Div4.showControl(0);
	Speed4.showControl(1);
	Tempo4.showControl(0);
	}

if(value == 1)
     	{
	Gmod4.setAttribute(Gmod4.Sync, 1);
	Gmod12.setAttribute(Gmod12.Sync, 1);
	Div4.showControl(1);
	Speed4.showControl(0);
	Tempo4.showControl(1);
	}	
	

};

Content.getComponent("TempoSync4").setControlCallback(onTempoSync4Control);

const var TrigSrc4 = Content.getComponent("TrigSrc4");
const var GmodOneShot4 = Content.getComponent("GmodOneShot4");


inline function onTrigMode4Control(component, value)
{
	 if(value == 1)
      	{
	Gmod4.setAttribute(Gmod4.TrigMode, 0);
	TrigSrc4.showControl(0);
	GmodOneShot4.showControl(0);

	}
	
	if(value == 2)
	      	{
		Gmod4.setAttribute(Gmod4.TrigMode, 1);
		TrigSrc4.showControl(0);
		GmodOneShot4.showControl(1);
	
		}
	if(value == 3)
	      	{
		Gmod4.setAttribute(Gmod4.TrigMode, 2);
		TrigSrc4.showControl(1);
		GmodOneShot4.showControl(1);
	
		}	
		
};

Content.getComponent("TrigMode4").setControlCallback(onTrigMode4Control);


inline function onSpeed4Control(component, value)
{
 Gmod4.setAttribute(Gmod4.SpeedMS, value);
	 Gmod12.setAttribute(Gmod12.SpeedMs, value);
};

Content.getComponent("Speed4").setControlCallback(onSpeed4Control);


inline function onTempo5Control(component, value)
{
 Gmod5.setAttribute(Gmod5.Tempo, value);
	 Gmod13.setAttribute(Gmod13.Tempo, value);
};

Content.getComponent("Tempo5").setControlCallback(onTempo5Control);


inline function onDiv5Control(component, value)
{
	 Gmod5.setAttribute(Gmod5.Divide, value);
	 Gmod13.setAttribute(Gmod13.Div, value);
};

Content.getComponent("Div5").setControlCallback(onDiv5Control);

inline function onTmod5Control(component, value)
{
 Gmod5.setAttribute(Gmod5.TempoMod, value);
	 Gmod13.setAttribute(Gmod13.TempoMod, value);
};

Content.getComponent("Tmod5").setControlCallback(onTmod5Control);


inline function onTmodSrc5Control(component, value)
{
 Gmod5.setAttribute(Gmod5.TempoSrc, value-1);
 Gmod13.setAttribute(Gmod13.TempoSrc, value-1);
};

Content.getComponent("TmodSrc5").setControlCallback(onTmodSrc5Control);

const var Div5 = Content.getComponent("Div5");
const var Speed5 = Content.getComponent("Speed5");
const var Tempo5 = Content.getComponent("Tempo5");



inline function onTempoSync5Control(component, value)
{

 
 if(value == 0)
      	{
	Gmod5.setAttribute(Gmod5.Sync, 0);
	Gmod13.setAttribute(Gmod13.Sync, 0);
	Div5.showControl(0);
	Speed5.showControl(1);
	Tempo5.showControl(0);
	}

if(value == 1)
     	{
	Gmod5.setAttribute(Gmod5.Sync, 1);
	Gmod13.setAttribute(Gmod13.Sync, 1);
	Div5.showControl(1);
	Speed5.showControl(0);
	Tempo5.showControl(1);
	}	
	

};

Content.getComponent("TempoSync5").setControlCallback(onTempoSync5Control);

const var TrigSrc5 = Content.getComponent("TrigSrc5");
const var GmodOneShot5 = Content.getComponent("GmodOneShot5");


inline function onTrigMode5Control(component, value)
{
	 if(value == 1)
      	{
	Gmod5.setAttribute(Gmod5.TrigMode, 0);
	TrigSrc5.showControl(0);
	GmodOneShot5.showControl(0);

	}
	
	if(value == 2)
	      	{
		Gmod5.setAttribute(Gmod5.TrigMode, 1);
		TrigSrc5.showControl(0);
		GmodOneShot5.showControl(1);
	
		}
	if(value == 3)
	      	{
		Gmod5.setAttribute(Gmod5.TrigMode, 2);
		TrigSrc5.showControl(1);
		GmodOneShot5.showControl(1);
	
		}	
		
};

Content.getComponent("TrigMode5").setControlCallback(onTrigMode5Control);


inline function onSpeed5Control(component, value)
{
 Gmod5.setAttribute(Gmod5.SpeedMS, value);
	 Gmod13.setAttribute(Gmod13.SpeedMs, value);
};

Content.getComponent("Speed5").setControlCallback(onSpeed5Control);


inline function onTempo6Control(component, value)
{
 Gmod6.setAttribute(Gmod6.Tempo, value);
	 Gmod14.setAttribute(Gmod14.Tempo, value);
};

Content.getComponent("Tempo6").setControlCallback(onTempo6Control);


inline function onDiv6Control(component, value)
{
	 Gmod6.setAttribute(Gmod6.Divide, value);
	 Gmod14.setAttribute(Gmod14.Div, value);
};

Content.getComponent("Div6").setControlCallback(onDiv6Control);

inline function onTmod6Control(component, value)
{
 Gmod6.setAttribute(Gmod6.TempoMod, value);
	 Gmod14.setAttribute(Gmod14.TempoMod, value);
};

Content.getComponent("Tmod6").setControlCallback(onTmod6Control);


inline function onTmodSrc6Control(component, value)
{
 Gmod6.setAttribute(Gmod6.TempoSrc, value);
 Gmod14.setAttribute(Gmod14.TempoSrc, value);
};

Content.getComponent("TmodSrc6").setControlCallback(onTmodSrc6Control);

const var Div6 = Content.getComponent("Div6");
const var Speed6 = Content.getComponent("Speed6");
const var Tempo6 = Content.getComponent("Tempo6");



inline function onTempoSync6Control(component, value)
{

 
 if(value == 0)
      	{
	Gmod6.setAttribute(Gmod6.Sync, 0);
	Gmod14.setAttribute(Gmod14.Sync, 0);
	Div6.showControl(0);
	Speed6.showControl(1);
	Tempo6.showControl(0);
	}

if(value == 1)
     	{
	Gmod6.setAttribute(Gmod6.Sync, 1);
	Gmod14.setAttribute(Gmod14.Sync, 1);
	Div6.showControl(1);
	Speed6.showControl(0);
	Tempo6.showControl(1);
	}	
	

};

Content.getComponent("TempoSync6").setControlCallback(onTempoSync6Control);

const var TrigSrc6 = Content.getComponent("TrigSrc6");
const var GmodOneShot6 = Content.getComponent("GmodOneShot6");


inline function onTrigMode6Control(component, value)
{
	 if(value == 1)
      	{
	Gmod6.setAttribute(Gmod6.TrigMode, 0);
	TrigSrc6.showControl(0);
	GmodOneShot6.showControl(0);

	}
	
	if(value == 2)
	      	{
		Gmod6.setAttribute(Gmod6.TrigMode, 1);
		TrigSrc6.showControl(0);
		GmodOneShot6.showControl(1);
	
		}
	if(value == 3)
	      	{
		Gmod6.setAttribute(Gmod6.TrigMode, 2);
		TrigSrc6.showControl(1);
		GmodOneShot6.showControl(1);
	
		}	
		
};

Content.getComponent("TrigMode6").setControlCallback(onTrigMode6Control);


inline function onSpeed6Control(component, value)
{
 Gmod6.setAttribute(Gmod6.SpeedMS, value);
	 Gmod14.setAttribute(Gmod14.SpeedMs, value);
};

Content.getComponent("Speed6").setControlCallback(onSpeed6Control);


inline function onTempo7Control(component, value)
{
 Gmod7.setAttribute(Gmod7.Tempo, value);
	 Gmod15.setAttribute(Gmod15.Tempo, value);
};

Content.getComponent("Tempo7").setControlCallback(onTempo7Control);


inline function onDiv7Control(component, value)
{
	 Gmod7.setAttribute(Gmod7.Divide, value);
	 Gmod15.setAttribute(Gmod15.Div, value);
};

Content.getComponent("Div7").setControlCallback(onDiv7Control);

inline function onTmod7Control(component, value)
{
 Gmod7.setAttribute(Gmod7.TempoMod, value);
	 Gmod15.setAttribute(Gmod15.TempoMod, value);
};

Content.getComponent("Tmod7").setControlCallback(onTmod7Control);


inline function onTmodSrc7Control(component, value)
{
 Gmod7.setAttribute(Gmod7.TempoSrc, value-1);
 Gmod15.setAttribute(Gmod15.TempoSrc, value-1);
};

Content.getComponent("TmodSrc7").setControlCallback(onTmodSrc7Control);

const var Div7 = Content.getComponent("Div7");
const var Speed7 = Content.getComponent("Speed7");
const var Tempo7 = Content.getComponent("Tempo7");



inline function onTempoSync7Control(component, value)
{

 
 if(value == 0)
      	{
	Gmod7.setAttribute(Gmod7.Sync, 0);
	Gmod15.setAttribute(Gmod15.Sync, 0);
	Div7.showControl(0);
	Speed7.showControl(1);
	Tempo7.showControl(0);
	}

if(value == 1)
     	{
	Gmod7.setAttribute(Gmod7.Sync, 1);
	Gmod15.setAttribute(Gmod15.Sync, 1);
	Div7.showControl(1);
	Speed7.showControl(0);
	Tempo7.showControl(1);
	}	
	

};

Content.getComponent("TempoSync7").setControlCallback(onTempoSync7Control);

const var TrigSrc7 = Content.getComponent("TrigSrc7");
const var GmodOneShot7 = Content.getComponent("GmodOneShot7");


inline function onTrigMode7Control(component, value)
{
	 if(value == 1)
      	{
	Gmod7.setAttribute(Gmod7.TrigMode, 0);
	TrigSrc7.showControl(0);
	GmodOneShot7.showControl(0);

	}
	
	if(value == 2)
	      	{
		Gmod7.setAttribute(Gmod7.TrigMode, 1);
		TrigSrc7.showControl(0);
		GmodOneShot7.showControl(1);
	
		}
	if(value == 3)
	      	{
		Gmod7.setAttribute(Gmod7.TrigMode, 2);
		TrigSrc7.showControl(1);
		GmodOneShot7.showControl(1);
	
		}	
		
};

Content.getComponent("TrigMode7").setControlCallback(onTrigMode7Control);


inline function onSpeed7Control(component, value)
{
 Gmod7.setAttribute(Gmod7.SpeedMS, value);
	 Gmod15.setAttribute(Gmod15.SpeedMs, value);
};

Content.getComponent("Speed7").setControlCallback(onSpeed7Control);


inline function onTempo8Control(component, value)
{
 Gmod8.setAttribute(Gmod8.Tempo, value);
	 Gmod16.setAttribute(Gmod16.Tempo, value);
};

Content.getComponent("Tempo8").setControlCallback(onTempo8Control);


inline function onDiv8Control(component, value)
{
	 Gmod8.setAttribute(Gmod8.Divide, value);
	 Gmod16.setAttribute(Gmod16.Div, value);
};

Content.getComponent("Div8").setControlCallback(onDiv8Control);

inline function onTmod8Control(component, value)
{
 Gmod8.setAttribute(Gmod8.TempoMod, value);
	 Gmod16.setAttribute(Gmod16.TempoMod, value);
};

Content.getComponent("Tmod8").setControlCallback(onTmod8Control);


inline function onTmodSrc8Control(component, value)
{
 Gmod8.setAttribute(Gmod8.TempoSrc, value-1);
 Gmod16.setAttribute(Gmod16.TempoSrc, value-1);
};

Content.getComponent("TmodSrc8").setControlCallback(onTmodSrc8Control);

const var Div8 = Content.getComponent("Div8");
const var Speed8 = Content.getComponent("Speed8");
const var Tempo8 = Content.getComponent("Tempo8");



inline function onTempoSync8Control(component, value)
{

 
 if(value == 0)
      	{
	Gmod8.setAttribute(Gmod8.Sync, 0);
	Gmod16.setAttribute(Gmod16.Sync, 0);
	Div8.showControl(0);
	Speed8.showControl(1);
	Tempo8.showControl(0);
	}

if(value == 1)
     	{
	Gmod8.setAttribute(Gmod8.Sync, 1);
	Gmod16.setAttribute(Gmod16.Sync, 1);
	Div8.showControl(1);
	Speed8.showControl(0);
	Tempo8.showControl(1);
	}	
	

};

Content.getComponent("TempoSync8").setControlCallback(onTempoSync8Control);

const var TrigSrc8 = Content.getComponent("TrigSrc8");
const var GmodOneShot8 = Content.getComponent("GmodOneShot8");


inline function onTrigMode8Control(component, value)
{
	 if(value == 1)
      	{
	Gmod8.setAttribute(Gmod8.TrigMode, 0);
	TrigSrc8.showControl(0);
	GmodOneShot8.showControl(0);

	}
	
	if(value == 2)
	      	{
		Gmod8.setAttribute(Gmod8.TrigMode, 1);
		TrigSrc8.showControl(0);
		GmodOneShot8.showControl(1);
	
		}
	if(value == 3)
	      	{
		Gmod8.setAttribute(Gmod8.TrigMode, 2);
		TrigSrc8.showControl(1);
		GmodOneShot8.showControl(1);
	
		}	
		
};

Content.getComponent("TrigMode8").setControlCallback(onTrigMode8Control);


inline function onSpeed8Control(component, value)
{
 Gmod8.setAttribute(Gmod8.SpeedMS, value);
	 Gmod16.setAttribute(Gmod16.SpeedMs, value);
};

Content.getComponent("Speed8").setControlCallback(onSpeed8Control);

