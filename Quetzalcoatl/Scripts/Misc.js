const var Filter = Content.getComponent("Filter");

const var preset = Content.getComponent("preset");
const var SettingsPresets = Content.getComponent("SettingsPresets");


inline function onpresetControl(component, value)
{

SettingsPresets.showControl(value);  
ModMatrix.showControl(0);  



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



