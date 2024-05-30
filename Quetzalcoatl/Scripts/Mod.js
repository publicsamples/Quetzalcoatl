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


const var Gmod9 = Synth.getModulator("Gmod9");
const var Gmod10 = Synth.getModulator("Gmod10");
const var Gmod11 = Synth.getModulator("Gmod11");
const var Gmod12 = Synth.getModulator("Gmod12");


inline function onGmodMode1Control(component, value)
{
	m1step.showControl(value);
    m1table.showControl(1-value);
    Gmod1.setAttribute(Gmod1.type, value);
};

Content.getComponent("GmodMode1").setControlCallback(onGmodMode1Control);

inline function onGmodMode2Control(component, value)
{
	m1step1.showControl(value);
    m1table1.showControl(1-value);
    Gmod2.setAttribute(Gmod2.type, value);
};

Content.getComponent("GmodMode2").setControlCallback(onGmodMode2Control);



inline function onGmodMode3Control(component, value)
{
	m1step2.showControl(value);
    m1table2.showControl(1-value);
    Gmod3.setAttribute(Gmod3.type, value);
};

Content.getComponent("GmodMode3").setControlCallback(onGmodMode3Control);

inline function onGmodMode3Control(component, value)
{
	m1step2.showControl(value);
    m1table2.showControl(1-value);
    Gmod3.setAttribute(Gmod3.type, value);
};

Content.getComponent("GmodMode3").setControlCallback(onGmodMode3Control);


inline function onGmodMode4Control(component, value)
{
	m1step3.showControl(value);
    m1table3.showControl(1-value);
    Gmod4.setAttribute(Gmod4.type, value);
};

Content.getComponent("GmodMode4").setControlCallback(onGmodMode4Control);


inline function onGmodMode5Control(component, value)
{
	m1step4.showControl(value);
	    m1table4.showControl(1-value);
	    Gmod5.setAttribute(Gmod5.type, value);
};

Content.getComponent("GmodMode5").setControlCallback(onGmodMode5Control);


inline function onGmodMode6Control(component, value)
{
	m1step5.showControl(value);
	    m1table5.showControl(1-value);
	    Gmod6.setAttribute(Gmod6.type, value);
};

Content.getComponent("GmodMode6").setControlCallback(onGmodMode6Control);


inline function onGmodMode7Control(component, value)
{
	m1step6.showControl(value);
	    m1table6.showControl(1-value);
	    Gmod7.setAttribute(Gmod7.type, value);
};

Content.getComponent("GmodMode7").setControlCallback(onGmodMode7Control);


inline function onGmodMode8Control(component, value)
{
	m1step7.showControl(value);
	    m1table7.showControl(1-value);
	    Gmod8.setAttribute(Gmod8.type, value);

};

Content.getComponent("GmodMode8").setControlCallback(onGmodMode8Control);

inline function onGmodMode9Control(component, value)
{
	m1step8.showControl(value);
	    m1table8.showControl(1-value);
	    Gmod9.setAttribute(Gmod9.type, value);

};

Content.getComponent("GmodMode9").setControlCallback(onGmodMode9Control);

inline function onGmodMode10Control(component, value)
{
	m1step9.showControl(value);
	    m1table9.showControl(1-value);
	    Gmod10.setAttribute(Gmod10.type, value);

};

Content.getComponent("GmodMode10").setControlCallback(onGmodMode10Control);
inline function onGmodMode11Control(component, value)
{
	m1step10.showControl(value);
	    m1table10.showControl(1-value);
	    Gmod11.setAttribute(Gmod11.type, value);

};

Content.getComponent("GmodMode11").setControlCallback(onGmodMode11Control);

inline function onGmodMode12Control(component, value)
{
	m1step11.showControl(value);
	    m1table11.showControl(1-value);
	    Gmod12.setAttribute(Gmod12.type, value);

};

Content.getComponent("GmodMode12").setControlCallback(onGmodMode12Control);

inline function onGmodMode13Control(component, value)
{
	m1step12.showControl(value);
	    m1table12.showControl(1-value);
	    Gmod13.setAttribute(Gmod13.type, value);

};




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
	    GlobalMod3.showControl(1);
	    GlobalMod2.showControl(1);
	    GlobalMod4.showControl(0);
	    GlobalMod5.showControl(0);
	    GlobalMod7.showControl(0);
	    GlobalMod6.showControl(0);
	    GlobalMod8.showControl(0);
		GlobalMod9.showControl(0);
  		GlobalMod10.showControl(0);
 		GlobalMod11.showControl(0);
 	    GlobalMod12.showControl(0);
       
	    
	    }
	    

if(value == 2)
  	{

	GlobalMod1.showControl(0);
    GlobalMod3.showControl(0);
    GlobalMod2.showControl(0);
    GlobalMod4.showControl(1);
    GlobalMod5.showControl(1);
    GlobalMod6.showControl(1);
    GlobalMod7.showControl(0);
 
    GlobalMod8.showControl(0);
		GlobalMod9.showControl(0);
  		GlobalMod10.showControl(0);
 		GlobalMod11.showControl(0);
 	    GlobalMod12.showControl(0);

    }
if(value == 3)
  	{

		GlobalMod1.showControl(0);
	    GlobalMod3.showControl(0);
	    GlobalMod2.showControl(0);
	    
	    GlobalMod4.showControl(0);
	    GlobalMod5.showControl(0);
	    GlobalMod7.showControl(1);
	    
	    GlobalMod6.showControl(0);
	    GlobalMod8.showControl(1);
		GlobalMod9.showControl(1);
		
  		GlobalMod10.showControl(0);
 		GlobalMod11.showControl(0);
 	    GlobalMod12.showControl(0);
   
    }
    
    if(value == 4)
      	{
    
    		GlobalMod1.showControl(0);
    	    GlobalMod3.showControl(0);
    	    GlobalMod2.showControl(0);
    	    GlobalMod4.showControl(0);
    	    GlobalMod5.showControl(0);
    	    GlobalMod7.showControl(0);
    	    GlobalMod6.showControl(0);
    	    GlobalMod8.showControl(0);
    		GlobalMod9.showControl(0);
  		GlobalMod10.showControl(1);
 		GlobalMod11.showControl(1);
 	    GlobalMod12.showControl(1);

        }
    
};

Content.getComponent("ModPage1").setControlCallback(onModPage1Control);




