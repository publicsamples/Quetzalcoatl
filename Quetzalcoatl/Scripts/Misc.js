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



inline function onCloseModControl(component, value)
{
	ModMatrixOpen.setValue(0); 
	ModMatrixOpen.changed(); 
};

Content.getComponent("CloseMod").setControlCallback(onCloseModControl);



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



const var Loading = Content.getComponent("Loading");
const var EveryLink = Content.getComponent("CLICK");
const var qex = Content.getComponent("QEXPANDED");



EveryLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/lybce");
  } 
 
});

const var AllCollection = Content.getComponent("AllCollection");


AllCollection.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://payhip.com/b/tKoDs");
  } 
 
});


const var QExpandedLink = Content.getComponent("CLICK1");

QExpandedLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://payhip.com/b/tKoDs");
  } 

});




QExpandedLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://payhip.com/b/tKoDs");
  } 

});
const var ExpandedLink = Content.getComponent("CLICK2");

qex.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://payhip.com/b/tKoDs");
}
});



