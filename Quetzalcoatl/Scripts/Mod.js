

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


				 


inline function onWtWav1Control(component, value)
{
Engine.allNotesOff();
Wt1.setAttribute(WavetableSynthesiser1.LoadedBankIndex, (value));



};

Content.getComponent("WtWav1").setControlCallback(onWtWav1Control);



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


inline function onModPage1Control(component, value)
{
		GlobalMod1.showControl(value);
	    GlobalMod3.showControl(1-value);
	    GlobalMod2.showControl(value);
	    GlobalMod4.showControl(1-value);
};

Content.getComponent("ModPage1").setControlCallback(onModPage1Control);



inline function onModPage2Control(component, value)
{
	GlobalMod5.showControl(value);
	    GlobalMod7.showControl(1-value);
	    GlobalMod6.showControl(value);
	    GlobalMod8.showControl(1-value);
};

Content.getComponent("ModPage2").setControlCallback(onModPage2Control);
