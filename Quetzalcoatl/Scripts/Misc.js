const var Filter = Content.getComponent("Filter");

const var preset = Content.getComponent("preset");
const var SettingsPresets = Content.getComponent("SettingsPresets");
const var ClosePresers = Content.getComponent("ClosePresers");
const var ModMatrixOpen = Content.getComponent("ModMatrixOpen");
const var CloseMod = Content.getComponent("CloseMod");


inline function onModMatrixOpenControl(component, value)
{
	
	if (value == 0)
	 {

	ModMatrix.showControl(0);

	CloseMod.setValue(0);
	
	} 
	
	if (value == 1)
	 {
	ModMatrix.showControl(1);
	SettingsPresets.showControl(0);
	CloseMod.setValue(0);
	preset.setValue(0);
	}
};

Content.getComponent("ModMatrixOpen").setControlCallback(onModMatrixOpenControl);




inline function onpresetControl(component, value)
{
	
if (value == 0)
 {

SettingsPresets.showControl(0);  
ClosePresers.setValue(0);


}

if (value == 1)
 {

SettingsPresets.showControl(1);  
ClosePresers.setValue(0);
ModMatrix.showControl(0);
CloseMod.setValue(0);;
ModMatrixOpen.setValue(0);

}

};

Content.getComponent("preset").setControlCallback(onpresetControl);


inline function onClosePresersControl(component, value)
{
	preset.setValue(0);  
	preset.changed(); 
};

Content.getComponent("ClosePresers").setControlCallback(onClosePresersControl);


inline function onCloseModControl(component, value)
{
	ModMatrixOpen.setValue(0); 
	ModMatrixOpen.changed(); 
};

Content.getComponent("CloseMod").setControlCallback(onCloseModControl);


const var Loading = Content.getComponent("Loading");
const var EveryLink = Content.getComponent("CLICK");
const var qex = Content.getComponent("QEXPANDED");



EveryLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/hnwjrr");
  } 
 
});

AllCollection.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/hnwjrr");
  } 
 
});


const var QExpandedLink = Content.getComponent("CLICK1");

QExpandedLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://www.modularsamples.com/l/lybce");
  } 

});




QExpandedLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://www.modularsamples.com/l/lybce");
  } 

});
const var ExpandedLink = Content.getComponent("CLICK2");

qex.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://www.modularsamples.com/l/lybce");
}
});




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

