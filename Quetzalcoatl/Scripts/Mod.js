

inline function onGmodMode1Control(component, value)
{
	m1step.showControl(value);
    m1table.showControl(1-value);
    Gmod1.setAttribute(Gmod1.modsel, value);
};

Content.getComponent("GmodMode1").setControlCallback(onGmodMode1Control);

inline function onGmodMode2Control(component, value)
{
	m1step1.showControl(value);
    m1table1.showControl(1-value);
    Gmod2.setAttribute(Gmod2.modsel, value);
};

Content.getComponent("GmodMode2").setControlCallback(onGmodMode2Control);



inline function onGmodMode3Control(component, value)
{
	m1step2.showControl(value);
    m1table2.showControl(1-value);
    Gmod3.setAttribute(Gmod3.modsel, value);
};

Content.getComponent("GmodMode3").setControlCallback(onGmodMode3Control);

inline function onGmodMode3Control(component, value)
{
	m1step2.showControl(value);
    m1table2.showControl(1-value);
    Gmod3.setAttribute(Gmod3.modsel, value);
};

Content.getComponent("GmodMode3").setControlCallback(onGmodMode3Control);


inline function onGmodMode4Control(component, value)
{
	m1step3.showControl(value);
    m1table3.showControl(1-value);
    Gmod4.setAttribute(Gmod4.modsel, value);
};

Content.getComponent("GmodMode4").setControlCallback(onGmodMode4Control);


inline function onGmodMode5Control(component, value)
{
	m1step4.showControl(value);
	    m1table4.showControl(1-value);
	    Gmod5.setAttribute(Gmod5.modsel, value);
};

Content.getComponent("GmodMode5").setControlCallback(onGmodMode5Control);


inline function onGmodMode6Control(component, value)
{
	m1step5.showControl(value);
	    m1table5.showControl(1-value);
	    Gmod6.setAttribute(Gmod6.modsel, value);
};

Content.getComponent("GmodMode6").setControlCallback(onGmodMode6Control);


inline function onGmodMode7Control(component, value)
{
	m1step6.showControl(value);
	    m1table6.showControl(1-value);
	    Gmod7.setAttribute(Gmod7.modsel, value);
};

Content.getComponent("GmodMode7").setControlCallback(onGmodMode7Control);


inline function onGmodMode8Control(component, value)
{
	m1step7.showControl(value);
	    m1table7.showControl(1-value);
	    Gmod8.setAttribute(Gmod8.modsel, value);
};

Content.getComponent("GmodMode8").setControlCallback(onGmodMode8Control);


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

const var Gate1 = Content.getComponent("Gate1");
const var Gate2 = Content.getComponent("Gate2");
const var Gate3 = Content.getComponent("Gate3");
const var Gate4 = Content.getComponent("Gate4");
const var Gate5 = Content.getComponent("Gate5");
const var Gate6 = Content.getComponent("Gate6");
const var Gate7 = Content.getComponent("Gate7");
const var Gate8 = Content.getComponent("Gate8");






inline function onModPage1Control(component, value)
{
	
	if(value == 1)
	  	{

		GlobalMod1.showControl(1);
	    GlobalMod3.showControl(1);
	    GlobalMod2.showControl(1);
	    GlobalMod4.showControl(1);
	    GlobalMod5.showControl(0);
	    GlobalMod7.showControl(0);
	    GlobalMod6.showControl(0);
	    GlobalMod8.showControl(0);
		Gate1.showControl(0);
  		Gate2.showControl(0);
 		Gate3.showControl(0);
 	    Gate4.showControl(0);
    	Gate5.showControl(0);
    	Gate6.showControl(0);
    	Gate7.showControl(0);
    	Gate8.showControl(0);	    
	    
	    }
	    

if(value == 2)
  	{

	GlobalMod1.showControl(0);
    GlobalMod3.showControl(0);
    GlobalMod2.showControl(0);
    GlobalMod4.showControl(0);
    GlobalMod5.showControl(1);
    GlobalMod7.showControl(2);
    GlobalMod6.showControl(3);
    GlobalMod8.showControl(4);
		Gate1.showControl(0);
  		Gate2.showControl(0);
 		Gate3.showControl(0);
 	    Gate4.showControl(0);
    	Gate5.showControl(0);
    	Gate6.showControl(0);
    	Gate7.showControl(0);
    	Gate8.showControl(0);	            
    
    }
if(value == 3)
  	{

		GlobalMod1.showControl(0);
	    GlobalMod3.showControl(0);
	    GlobalMod2.showControl(0);
	    GlobalMod4.showControl(0);
	    GlobalMod5.showControl(0);
	    GlobalMod7.showControl(0);
	    GlobalMod6.showControl(0);
	    GlobalMod8.showControl(0);
		Gate1.showControl(1);
  		Gate2.showControl(1);
 		Gate3.showControl(1);
 	    Gate4.showControl(1);
    	Gate5.showControl(0);
    	Gate6.showControl(0);
    	Gate7.showControl(0);
    	Gate8.showControl(0);
    
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
    		Gate1.showControl(0);
      		Gate2.showControl(0);
     		Gate3.showControl(0);
     	    Gate4.showControl(0);
        	Gate5.showControl(1);
        	Gate6.showControl(1);
        	Gate7.showControl(1);
        	Gate8.showControl(1);
        
        }
    
};

Content.getComponent("ModPage1").setControlCallback(onModPage1Control);




