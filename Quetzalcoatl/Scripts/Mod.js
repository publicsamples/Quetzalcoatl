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

const var m1table8 = Content.getComponent("m1table8");
const var m1table9 = Content.getComponent("m1table9");
const var m1table10 = Content.getComponent("m1table10");
const var m1table11 = Content.getComponent("m1table11");
const var m1table12 = Content.getComponent("m1table12");
const var m1table13 = Content.getComponent("m1table13");
const var m1table14 = Content.getComponent("m1table14");
const var m1table15 = Content.getComponent("m1table15");

const var m1step8 = Content.getComponent("m1step8");
const var m1step9 = Content.getComponent("m1step9");
const var m1step10 = Content.getComponent("m1step10");
const var m1step11 = Content.getComponent("m1step11");
const var m1step12 = Content.getComponent("m1step12");
const var m1step13 = Content.getComponent("m1step13");
const var m1step14 = Content.getComponent("m1step14");
const var m1step15 = Content.getComponent("m1step15");

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

const var env4 = Content.getComponent("env4");
const var env5 = Content.getComponent("env5");
const var env6 = Content.getComponent("env6");
const var env7 = Content.getComponent("env7");
const var env8 = Content.getComponent("env8");
const var env9 = Content.getComponent("env9");
const var env10 = Content.getComponent("env10");
const var env11 = Content.getComponent("env11");

const var Vel = [Synth.getModulator("Velocity Modulator1"),
 					Synth.getModulator("Velocity Modulator2"),
 					Synth.getModulator("Velocity Modulator3"),
 					Synth.getModulator("Velocity Modulator4"),
 					Synth.getModulator("Velocity Modulator5"),
 					Synth.getModulator("Velocity Modulator6"),
 					Synth.getModulator("Velocity Modulator7"),
 					Synth.getModulator("Velocity Modulator8")];


inline function onGmodMode1Control(component, value)
{
	if(value == 1)
	  	{

	m1step.showControl(1);
    m1table.showControl(0);
    env4.showControl(0);
    Gmod1.setAttribute(Gmod1.type, 0);
    
    }
    
    if(value == 2)
    	  	{
    
    	m1step.showControl(0);
        m1table.showControl(1);
        env4.showControl(0);
        Gmod1.setAttribute(Gmod1.type, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
           	m1step.showControl(0);
               m1table.showControl(0);
               env4.showControl(1);
               Gmod1.setAttribute(Gmod1.type, 2);
               
               }
};

Content.getComponent("GmodMode1").setControlCallback(onGmodMode1Control);

inline function onGmodMode2Control(component, value)
{
	if(value == 1)
	  	{

	m1step2.showControl(1);
    m1table2.showControl(0);
    env5.showControl(0);
    Gmod2.setAttribute(Gmod2.type, 0);
    
    }
    
    if(value == 2)
    	  	{
    
    	m1step2.showControl(0);
        m1table2.showControl(1);
        env5.showControl(0);
        Gmod2.setAttribute(Gmod2.type, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
           	m1step2.showControl(0);
               m1table2.showControl(0);
               env5.showControl(1);
               Gmod2.setAttribute(Gmod2.type, 2);
               
               }
};

Content.getComponent("GmodMode2").setControlCallback(onGmodMode2Control);



inline function onGmodMode3Control(component, value)
{
	if(value == 1)
	  	{

	m1step3.showControl(1);
    m1table3.showControl(0);
    env6.showControl(0);
    Gmod3.setAttribute(Gmod3.type, 0);
    
    }
    
    if(value == 2)
    	  	{
    
    	m1step3.showControl(0);
        m1table3.showControl(1);
        env6.showControl(0);
        Gmod3.setAttribute(Gmod3.type, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
           	m1step3.showControl(0);
               m1table3.showControl(0);
               env6.showControl(1);
               Gmod3.setAttribute(Gmod3.type, 2);
               
               }
};

Content.getComponent("GmodMode3").setControlCallback(onGmodMode3Control);

inline function onGmodMode4Control(component, value)
{
	if(value == 1)
	  	{

	m1step4.showControl(1);
    m1table4.showControl(0);
    env7.showControl(0);
    Gmod4.setAttribute(Gmod4.type, 0);
    
    }
    
    if(value == 2)
    	  	{
    
    	m1step4.showControl(0);
        m1table4.showControl(1);
        env7.showControl(0);
        Gmod4.setAttribute(Gmod4.type, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
           	m1step4.showControl(0);
               m1table4.showControl(0);
               env7.showControl(1);
               Gmod4.setAttribute(Gmod4.type, 2);
               
               }
};

Content.getComponent("GmodMode4").setControlCallback(onGmodMode4Control);


inline function onGmodMode5Control(component, value)
{
	if(value == 1)
	  	{

	m1step5.showControl(1);
    m1table5.showControl(0);
    env8.showControl(0);
    Gmod5.setAttribute(Gmod5.type, 0);
    
    }
    
    if(value == 2)
    	  	{
    
    	m1step5.showControl(0);
        m1table5.showControl(1);
        env8.showControl(0);
        Gmod5.setAttribute(Gmod5.type, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
           	m1step5.showControl(0);
               m1table5.showControl(0);
               env8.showControl(1);
               Gmod5.setAttribute(Gmod5.type, 2);
               
               }
};

Content.getComponent("GmodMode5").setControlCallback(onGmodMode5Control);


inline function onGmodMode6Control(component, value)
{
	if(value == 1)
	  	{

	m1step6.showControl(1);
    m1table6.showControl(0);
    env9.showControl(0);
    Gmod6.setAttribute(Gmod6.type, 0);
    
    }
    
    if(value == 2)
    	  	{
    
    	m1step6.showControl(0);
        m1table6.showControl(1);
        env9.showControl(0);
        Gmod6.setAttribute(Gmod6.type, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
           	m1step6.showControl(0);
               m1table6.showControl(0);
               env9.showControl(1);
               Gmod6.setAttribute(Gmod6.type, 2);
               
               }
};

Content.getComponent("GmodMode6").setControlCallback(onGmodMode6Control);


inline function onGmodMode7Control(component, value)
{
	if(value == 1)
	  	{

	m1step7.showControl(1);
    m1table7.showControl(0);
    env10.showControl(0);
    Gmod7.setAttribute(Gmod7.type, 0);
    
    }
    
    if(value == 2)
    	  	{
    	m1step7.showControl(0);
    m1table7.showControl(1);
    env10.showControl(0);
    Gmod7.setAttribute(Gmod7.type, 1);
        
        }
        
        
           if(value == 3)
           	  	{
           
     m1step7.showControl(0);
    m1table7.showControl(0);
    env10.showControl(1);
    Gmod7.setAttribute(Gmod7.type, 2);
               
               }
};

Content.getComponent("GmodMode7").setControlCallback(onGmodMode7Control);


inline function onGmodMode8Control(component, value)
{
	if(value == 1)
	  	{

	m1step8.showControl(1);
    m1table8.showControl(0);
    env11.showControl(0);
    Gmod8.setAttribute(Gmod8.type, 0);
    
    }
    
    if(value == 2)
    	  	{
  	m1step8.showControl(0);
    m1table8.showControl(1);
    env11.showControl(0);
    Gmod8.setAttribute(Gmod8.type, 1);
        
        }
        
        
           if(value == 3)
           	  	{
  	m1step8.showControl(0);
    m1table8.showControl(0);
    env11.showControl(1);
    Gmod8.setAttribute(Gmod8.type, 2);
               
               }
};

Content.getComponent("GmodMode8").setControlCallback(onGmodMode8Control);

inline function onGmodMode9Control(component, value)
{
	if(value == 1)
	  	{
	Waveform2.showControl(1);
	m1step1.showControl(0);
	    m1table1.showControl(0);
	    Gmod9.setAttribute(Gmod9.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform2.showControl(1);
	    m1step1.showControl(0);
	        m1table1.showControl(0);
	        Gmod9.setAttribute(Gmod9.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform2.showControl(1);
	        	    m1step1.showControl(0);
	        	        m1table1.showControl(0);
	        	        Gmod9.setAttribute(Gmod9.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform2.showControl(1);
		        	    m1step1.showControl(0);
		        	        m1table1.showControl(0);
		        	        Gmod9.setAttribute(Gmod9.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform2.showControl(1);
		        	    m1step1.showControl(0);
		        	        m1table1.showControl(0);
		        	        Gmod9.setAttribute(Gmod9.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform2.showControl(0);
			        	    m1step1.showControl(0);
			        	        m1table1.showControl(1);
			        	        Gmod9.setAttribute(Gmod9.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform2.showControl(0);
			        	    m1step1.showControl(1);
			        	        m1table1.showControl(0);
			        	        Gmod9.setAttribute(Gmod9.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode9").setControlCallback(onGmodMode9Control);

inline function onGmodMode10Control(component, value)
{
	if(value == 1)
	  	{
	Waveform4.showControl(1);
	m1step9.showControl(0);
	    m1table9.showControl(0);
	    Gmod10.setAttribute(Gmod10.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform4.showControl(1);
	    m1step9.showControl(0);
	        m1table9.showControl(0);
	        Gmod10.setAttribute(Gmod10.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform4.showControl(1);
	        	    m1step9.showControl(0);
	        	        m1table9.showControl(0);
	        	        Gmod10.setAttribute(Gmod10.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform4.showControl(1);
		        	    m1step9.showControl(0);
		        	        m1table9.showControl(0);
		        	        Gmod10.setAttribute(Gmod10.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform4.showControl(1);
		        	    m1step9.showControl(0);
		        	        m1table9.showControl(0);
		        	        Gmod10.setAttribute(Gmod10.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform4.showControl(0);
			        	    m1step9.showControl(0);
			        	        m1table9.showControl(1);
			        	        Gmod10.setAttribute(Gmod10.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform4.showControl(0);
			        	    m1step9.showControl(1);
			        	        m1table9.showControl(0);
			        	        Gmod10.setAttribute(Gmod10.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode10").setControlCallback(onGmodMode10Control);

inline function onGmodMode11Control(component, value)
{
	if(value == 1)
	  	{
	Waveform6.showControl(1);
	m1step10.showControl(0);
	    m1table10.showControl(0);
	    Gmod11.setAttribute(Gmod11.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform6.showControl(1);
	    m1step10.showControl(0);
	        m1table10.showControl(0);
	        Gmod11.setAttribute(Gmod11.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform6.showControl(1);
	        	    m1step10.showControl(0);
	        	        m1table10.showControl(0);
	        	        Gmod11.setAttribute(Gmod11.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform6.showControl(1);
		        	    m1step10.showControl(0);
		        	        m1table10.showControl(0);
		        	        Gmod11.setAttribute(Gmod11.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform6.showControl(1);
		        	    m1step10.showControl(0);
		        	        m1table10.showControl(0);
		        	        Gmod11.setAttribute(Gmod11.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform6.showControl(0);
			        	    m1step10.showControl(0);
			        	        m1table10.showControl(1);
			        	        Gmod11.setAttribute(Gmod11.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform6.showControl(0);
			        	    m1step10.showControl(1);
			        	        m1table10.showControl(0);
			        	        Gmod11.setAttribute(Gmod11.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode11").setControlCallback(onGmodMode11Control);


inline function onGmodMode12Control(component, value)
{
	if(value == 1)
	  	{
	Waveform8.showControl(1);
	m1step11.showControl(0);
	    m1table11.showControl(0);
	    Gmod12.setAttribute(Gmod12.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform8.showControl(1);
	    m1step11.showControl(0);
	        m1table11.showControl(0);
	        Gmod12.setAttribute(Gmod12.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform8.showControl(1);
	        	    m1step11.showControl(0);
	        	        m1table11.showControl(0);
	        	        Gmod12.setAttribute(Gmod12.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform8.showControl(1);
		        	    m1step11.showControl(0);
		        	        m1table11.showControl(0);
		        	        Gmod12.setAttribute(Gmod12.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform8.showControl(1);
		        	    m1step11.showControl(0);
		        	        m1table11.showControl(0);
		        	        Gmod12.setAttribute(Gmod12.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform8.showControl(0);
			        	    m1step11.showControl(0);
			        	        m1table11.showControl(1);
			        	        Gmod12.setAttribute(Gmod12.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform8.showControl(0);
			        	    m1step11.showControl(1);
			        	        m1table11.showControl(0);
			        	        Gmod12.setAttribute(Gmod12.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode12").setControlCallback(onGmodMode12Control);

inline function onGmodMode13Control(component, value)
{
	if(value == 1)
	  	{
	Waveform10.showControl(1);
	m1step12.showControl(0);
	    m1table12.showControl(0);
	    Gmod13.setAttribute(Gmod13.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform10.showControl(1);
	    m1step12.showControl(0);
	        m1table12.showControl(0);
	        Gmod13.setAttribute(Gmod13.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform10.showControl(1);
	        	    m1step12.showControl(0);
	        	        m1table12.showControl(0);
	        	        Gmod13.setAttribute(Gmod13.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform10.showControl(1);
		        	    m1step12.showControl(0);
		        	        m1table12.showControl(0);
		        	        Gmod13.setAttribute(Gmod13.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform10.showControl(1);
		        	    m1step12.showControl(0);
		        	        m1table12.showControl(0);
		        	        Gmod13.setAttribute(Gmod13.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform10.showControl(0);
			        	    m1step12.showControl(0);
			        	        m1table12.showControl(1);
			        	        Gmod13.setAttribute(Gmod13.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform10.showControl(0);
			        	    m1step12.showControl(1);
			        	        m1table12.showControl(0);
			        	        Gmod13.setAttribute(Gmod13.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode13").setControlCallback(onGmodMode13Control);

inline function onGmodMode14Control(component, value)
{
	if(value == 1)
	  	{
	Waveform12.showControl(1);
	m1step13.showControl(0);
	    m1table13.showControl(0);
	    Gmod14.setAttribute(Gmod14.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform12.showControl(1);
	    m1step13.showControl(0);
	        m1table13.showControl(0);
	        Gmod14.setAttribute(Gmod14.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform12.showControl(1);
	        	    m1step13.showControl(0);
	        	        m1table13.showControl(0);
	        	        Gmod14.setAttribute(Gmod14.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform12.showControl(1);
		        	    m1step13.showControl(0);
		        	        m1table13.showControl(0);
		        	        Gmod14.setAttribute(Gmod14.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform12.showControl(1);
		        	    m1step13.showControl(0);
		        	        m1table13.showControl(0);
		        	        Gmod14.setAttribute(Gmod14.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform12.showControl(0);
			        	    m1step13.showControl(0);
			        	        m1table13.showControl(1);
			        	        Gmod14.setAttribute(Gmod14.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform12.showControl(0);
			        	    m1step13.showControl(1);
			        	        m1table13.showControl(0);
			        	        Gmod14.setAttribute(Gmod14.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode14").setControlCallback(onGmodMode14Control);

inline function onGmodMode15Control(component, value)
{
	if(value == 1)
	  	{
	Waveform14.showControl(1);
	m1step14.showControl(0);
	    m1table14.showControl(0);
	    Gmod15.setAttribute(Gmod15.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform14.showControl(1);
	    m1step14.showControl(0);
	        m1table14.showControl(0);
	        Gmod15.setAttribute(Gmod15.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform14.showControl(1);
	        	    m1step14.showControl(0);
	        	        m1table14.showControl(0);
	        	        Gmod15.setAttribute(Gmod15.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform14.showControl(1);
		        	    m1step14.showControl(0);
		        	        m1table14.showControl(0);
		        	        Gmod15.setAttribute(Gmod15.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform14.showControl(1);
		        	    m1step14.showControl(0);
		        	        m1table14.showControl(0);
		        	        Gmod15.setAttribute(Gmod15.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform14.showControl(0);
			        	    m1step14.showControl(0);
			        	        m1table14.showControl(1);
			        	        Gmod15.setAttribute(Gmod15.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform14.showControl(0);
			        	    m1step14.showControl(1);
			        	        m1table14.showControl(0);
			        	        Gmod15.setAttribute(Gmod15.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode15").setControlCallback(onGmodMode15Control);

inline function onGmodMode16Control(component, value)
{
	if(value == 1)
	  	{
	Waveform16.showControl(1);
	m1step15.showControl(0);
	    m1table15.showControl(0);
	    Gmod16.setAttribute(Gmod16.Shape, 0);
	    }
	    
	    if(value == 2)
	      	{
	    Waveform16.showControl(1);
	    m1step15.showControl(0);
	        m1table15.showControl(0);
	        Gmod16.setAttribute(Gmod16.Shape, 1.2);
	        }
	        
	        if(value == 3)
	        	      	{
	        	    Waveform16.showControl(1);
	        	    m1step15.showControl(0);
	        	        m1table15.showControl(0);
	        	        Gmod16.setAttribute(Gmod16.Shape, 2.4);
	        	        }
	if(value == 4)
		        	      	{
		        	    Waveform16.showControl(1);
		        	    m1step15.showControl(0);
		        	        m1table15.showControl(0);
		        	        Gmod16.setAttribute(Gmod16.Shape, 3.6);
		        	        }
		        	        
	if(value == 5)
		        	      	{
		        	    Waveform16.showControl(1);
		        	    m1step15.showControl(0);
		        	        m1table15.showControl(0);
		        	        Gmod16.setAttribute(Gmod16.Shape, 4.8);
		        	        }	        
		        	        
	if(value == 6)
			        	      	{
			        	    Waveform16.showControl(0);
			        	    m1step15.showControl(0);
			        	        m1table15.showControl(1);
			        	        Gmod16.setAttribute(Gmod16.Shape, 6);
			        	        }	
			        	        
	if(value == 7)
			        	      	{
			        	    Waveform16.showControl(0);
			        	    m1step15.showControl(1);
			        	        m1table15.showControl(0);
			        	        Gmod16.setAttribute(Gmod16.Shape, 7.1);
			        	        }			        	                	        	        	        
};

Content.getComponent("GmodMode16").setControlCallback(onGmodMode16Control);





const var preloadBar = Content.getComponent("preloadBar");
preloadBar.setPaintRoutine(function(g)
{
	g.fillAll(this.get("bgColour"));
	g.setColour(this.get("itemColour"));
	g.fillRect([0, 0, this.getWidth() * this.data.progress, this.getHeight()]);
});

preloadBar.setTimerCallback(function()
{
	this.data.progress = Engine.getPreloadProgress();
	this.repaint();	
});

preloadBar.setLoadingCallback(function(isPreloading)
{
    this.data.progress = 0.0;
    this.set("visible", isPreloading);
    
	if(isPreloading)
        this.startTimer(80);
    else
        this.stopTimer();
});



inline function onAmpVelControl(component, value)
{
	for(s in Vel)
	       s.setIntensity(value);
};

Content.getComponent("AmpVel").setControlCallback(onAmpVelControl);

const var GlobalMod1 = Content.getComponent("GlobalMod1");
const var GlobalMod2 = Content.getComponent("GlobalMod2");
const var GlobalMod3 = Content.getComponent("GlobalMod3");
const var GlobalMod4 = Content.getComponent("GlobalMod4");
const var GlobalMod5 = Content.getComponent("GlobalMod5");
const var GlobalMod6 = Content.getComponent("GlobalMod6");
const var GlobalMod7 = Content.getComponent("GlobalMod7");
const var GlobalMod8 = Content.getComponent("GlobalMod8");
const var GlobalMod9 = Content.getComponent("GlobalMod9");
const var GlobalMod10 = Content.getComponent("GlobalMod10");
const var GlobalMod11 = Content.getComponent("GlobalMod11");
const var GlobalMod12 = Content.getComponent("GlobalMod12");
const var GlobalMod13 = Content.getComponent("GlobalMod13");
const var GlobalMod14 = Content.getComponent("GlobalMod14");
const var GlobalMod15 = Content.getComponent("GlobalMod15");
const var GlobalMod16 = Content.getComponent("GlobalMod16");

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


inline function onModPage2Control(component, value)
{
	
	if(value == 1)
	  	{

		GlobalMod9.showControl(1);
	    GlobalMod11.showControl(0);
	    GlobalMod10.showControl(0);
	    GlobalMod12.showControl(0);
	    GlobalMod13.showControl(0);
	    GlobalMod15.showControl(0);
	    GlobalMod14.showControl(0);
	    GlobalMod16.showControl(0);
	
	    
	    }
	    

if(value == 2)
  	{

	GlobalMod9.showControl(0);
	    GlobalMod11.showControl(0);
	    GlobalMod10.showControl(1);
	    GlobalMod12.showControl(0);
	    GlobalMod13.showControl(0);
	    GlobalMod15.showControl(0);
	    GlobalMod14.showControl(0);
	    GlobalMod16.showControl(0);
	
    }
if(value == 3)
  	{

			GlobalMod9.showControl(0);
	    GlobalMod11.showControl(1);
	    GlobalMod10.showControl(0);
	    GlobalMod12.showControl(0);
	    GlobalMod13.showControl(0);
	    GlobalMod15.showControl(0);
	    GlobalMod14.showControl(0);
	    GlobalMod16.showControl(0);
	
   
    }
   
   if(value == 4)
     	{
   
   		GlobalMod9.showControl(0);
	    GlobalMod11.showControl(0);
	    GlobalMod10.showControl(0);
	    GlobalMod12.showControl(1);
	    GlobalMod13.showControl(0);
	    GlobalMod15.showControl(0);
	    GlobalMod14.showControl(0);
	    GlobalMod16.showControl(0);
	
       } 
       
       if(value == 5)
         	{
       
       		GlobalMod9.showControl(0);
       	    GlobalMod11.showControl(0);
       	    GlobalMod10.showControl(0);
       	    GlobalMod12.showControl(0);
       	    GlobalMod13.showControl(1);
       	    GlobalMod15.showControl(0);
       	    GlobalMod14.showControl(0);
       	    GlobalMod16.showControl(0);
       	
           } 
           
           
           if(value == 6)
                   	{
                 
                 		GlobalMod9.showControl(0);
                 	    GlobalMod11.showControl(0);
                 	    GlobalMod10.showControl(0);
                 	    GlobalMod12.showControl(0);
                 	    GlobalMod13.showControl(0);
                 	    GlobalMod15.showControl(0);
                 	    GlobalMod14.showControl(1);
                 	    GlobalMod16.showControl(0);
                 	
                     } 
  if(value == 7)
                    	{
                  
                  		GlobalMod9.showControl(0);
                  	    GlobalMod11.showControl(0);
                  	    GlobalMod10.showControl(0);
                  	    GlobalMod12.showControl(0);
                  	    GlobalMod13.showControl(0);
                  	    GlobalMod15.showControl(1);
                  	    GlobalMod14.showControl(0);
                  	    GlobalMod16.showControl(0);
                  	
                      } 
                      
                        if(value == 8)
                    	{
                  
                  		GlobalMod9.showControl(0);
                  	    GlobalMod11.showControl(0);
                  	    GlobalMod10.showControl(0);
                  	    GlobalMod12.showControl(0);
                  	    GlobalMod13.showControl(0);
                  	    GlobalMod15.showControl(0);
                  	    GlobalMod14.showControl(0);
                  	    GlobalMod16.showControl(1);
                  	
                      }                   
    
};

Content.getComponent("ModPage2").setControlCallback(onModPage2Control);

//tempo mod menus

inline function onTrigMode20Control(component, value)
{
	Gmod9.setAttribute(Gmod9.TempoSrc, value-1);
};

Content.getComponent("TrigMode20").setControlCallback(onTrigMode20Control);


inline function onTrigMode22Control(component, value)
{
	Gmod10.setAttribute(Gmod10.TempoSrc, value-1);
};

Content.getComponent("TrigMode22").setControlCallback(onTrigMode22Control);


inline function onTrigMode24Control(component, value)
{
	Gmod11.setAttribute(Gmod11.TempoSrc, value-1);
};

Content.getComponent("TrigMode24").setControlCallback(onTrigMode24Control);


inline function onTrigMode26Control(component, value)
{
		Gmod12.setAttribute(Gmod12.TempoSrc, value-1);
};

Content.getComponent("TrigMode26").setControlCallback(onTrigMode26Control);


inline function onTrigMode28Control(component, value)
{
		Gmod13.setAttribute(Gmod13.TempoSrc, value-1);
};

Content.getComponent("TrigMode28").setControlCallback(onTrigMode28Control);


inline function onTrigMode30Control(component, value)
{
		Gmod14.setAttribute(Gmod14.TempoSrc, value-1);
};

Content.getComponent("TrigMode30").setControlCallback(onTrigMode30Control);


inline function onTrigMode32Control(component, value)
{
	Gmod15.setAttribute(Gmod15.TempoSrc, value-1);
};

Content.getComponent("TrigMode32").setControlCallback(onTrigMode32Control);


inline function onTrigMode34Control(component, value)
{
	Gmod16.setAttribute(Gmod16.TempoSrc, value-1);
};

Content.getComponent("TrigMode34").setControlCallback(onTrigMode34Control);


//adjust mod


inline function onTrigMode37Control(component, value)
{
	Gmod9.setAttribute(Gmod9.ModifierShapeModSrc, value-1);
};

Content.getComponent("TrigMode37").setControlCallback(onTrigMode37Control);


inline function onTrigMode39Control(component, value)
{
	Gmod10.setAttribute(Gmod10.ModifierShapeModSrc, value-1);
};

Content.getComponent("TrigMode39").setControlCallback(onTrigMode39Control);


inline function onTrigMode41Control(component, value)
{
	Gmod11.setAttribute(Gmod11.ModifierShapeModSrc, value-1);
};

Content.getComponent("TrigMode41").setControlCallback(onTrigMode41Control);


inline function onTrigMode43Control(component, value)
{
	Gmod12.setAttribute(Gmod12.ModifierShapeModSrc, value-1);
};

Content.getComponent("TrigMode43").setControlCallback(onTrigMode43Control);


inline function onTrigMode45Control(component, value)
{
		Gmod13.setAttribute(Gmod13.ModifierShapeModSrc, value-1);
};

Content.getComponent("TrigMode45").setControlCallback(onTrigMode45Control);


inline function onTrigMode47Control(component, value)
{
Gmod14.setAttribute(Gmod14.ModifierShapeModSrc, value-1);
};

Content.getComponent("TrigMode47").setControlCallback(onTrigMode47Control);


inline function onTrigMode49Control(component, value)
{
	Gmod15.setAttribute(Gmod15.ModifierShapeModSrc, value-1);
};

Content.getComponent("TrigMode49").setControlCallback(onTrigMode49Control);


inline function onTrigMode51Control(component, value)
{
	Gmod16.setAttribute(Gmod16.ModifierShapeModSrc, value-1);
};

Content.getComponent("TrigMode51").setControlCallback(onTrigMode51Control);

//Trig


inline function onTrigMode19Control(component, value)
{
	Gmod9.setAttribute(Gmod9.trigmode, value-1);
};

Content.getComponent("TrigMode19").setControlCallback(onTrigMode19Control);


inline function onTrigMode21Control(component, value)
{
	Gmod10.setAttribute(Gmod10.trigmode, value-1);
};

Content.getComponent("TrigMode21").setControlCallback(onTrigMode21Control);


inline function onTrigMode23Control(component, value)
{
		Gmod11.setAttribute(Gmod11.trigmode, value-1);
};

Content.getComponent("TrigMode23").setControlCallback(onTrigMode23Control);


inline function onTrigMode25Control(component, value)
{
		Gmod12.setAttribute(Gmod12.trigmode, value-1);
};

Content.getComponent("TrigMode25").setControlCallback(onTrigMode25Control);


inline function onTrigMode27Control(component, value)
{
	Gmod13.setAttribute(Gmod13.trigmode, value-1);
};

Content.getComponent("TrigMode27").setControlCallback(onTrigMode27Control);


inline function onTrigMode29Control(component, value)
{
	Gmod14.setAttribute(Gmod14.trigmode, value-1);
};

Content.getComponent("TrigMode29").setControlCallback(onTrigMode29Control);

inline function onTrigMode49Control(component, value)
{
	Gmod15.setAttribute(Gmod15.trigmode, value-1);
};

Content.getComponent("TrigMode49").setControlCallback(onTrigMode49Control);

inline function onTrigMode33Control(component, value)
{
	Gmod16.setAttribute(Gmod16.trigmode, value-1);
};

Content.getComponent("TrigMode33").setControlCallback(onTrigMode33Control);
