const var Filter = Content.getComponent("Filter");

const var Overview = Content.getComponent("Overview");
const var HarmPitch = Content.getComponent("HarmPitch");
const var UserTune = Content.getComponent("UserTune");


const var preset = Content.getComponent("preset");
const var SettingsPresets = Content.getComponent("SettingsPresets");


inline function onpresetControl(component, value)
{

SettingsPresets.showControl(value-1);  



};

Content.getComponent("preset").setControlCallback(onpresetControl);

const var Loading = Content.getComponent("Loading");


const var EveryLink = Content.getComponent("CLICK");

EveryLink.setMouseCallback(function(event)
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

ExpandedLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://www.modularsamples.com/l/rhnqwh");
}
});



