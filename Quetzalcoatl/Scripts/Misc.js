const var Filter = Content.getComponent("Filter");

const var Overview = Content.getComponent("Overview");
const var HarmPitch = Content.getComponent("HarmPitch");
const var UserTune = Content.getComponent("UserTune");

inline function onTablePitchControl(component, value)
{
	
	if(value == 1)
	{

		HarmPitch.showControl(1);
        GainSliders.showControl(0);
    
        Filter.showControl(0);

        Overview.showControl(0);
        UserTune.showControl(0);
    
    }
    
    if(value == 2)
    	{
    
    		HarmPitch.showControl(0);        
            GainSliders.showControl(1);
     
            Filter.showControl(0);

            Overview.showControl(0);
            UserTune.showControl(0);
           
        
        }
        
     
            
            if(value == 3)
                   	{
                   
                   		HarmPitch.showControl(0);
                           GainSliders.showControl(0);

                           Filter.showControl(1);
                         
                           Overview.showControl(0);
                           UserTune.showControl(0);
                       
                       }
                       
         if(value == 4)
                         	{
                         
                         		HarmPitch.showControl(0);
                                 GainSliders.showControl(0);

                                 Filter.showControl(0);
                   
                                 Overview.showControl(1);
                                 UserTune.showControl(0);
                             
                             } 
                             
if(value == 5)
                       	{
                       
                       		HarmPitch.showControl(0);
                               GainSliders.showControl(0);

                               Filter.showControl(0);
                  
                               Overview.showControl(0);
                               UserTune.showControl(1);
                           
                           }                                           
};

Content.getComponent("TablePitch").setControlCallback(onTablePitchControl);


const var preset = Content.getComponent("preset");
const var SettingsPresets = Content.getComponent("SettingsPresets");


inline function onpresetControl(component, value)
{

	if(value == 0)
	{
	      SettingsPresets.showControl(value-1);  
	      Loading.showControl(0);

}
};

Content.getComponent("preset").setControlCallback(onpresetControl);

const var Loading = Content.getComponent("Loading");

inline function onLoadWavesControl(component, value)
{
if(value == 0)
{

	Loading.showControl(value-1);
	SettingsPresets.showControl(0); 
	
}
	
};

Content.getComponent("LoadWaves").setControlCallback(onLoadWavesControl);


inline function onParametersControl(component, value)
{
	if(value == 0)
	{
	SettingsPresets.showControl(0); 
	Loading.showControl(0); 
		}
};

Content.getComponent("Parameters").setControlCallback(onParametersControl);



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

const var QExpandedLink2 = Content.getComponent("CLICK3");

QExpandedLink2.setMouseCallback(function(event)
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



