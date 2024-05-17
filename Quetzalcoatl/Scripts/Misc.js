

const var Gates = Content.getComponent("Gates");
const var GatePage = Content.getComponent("GatePage");



inline function onCloseGatesControl(component, value)
{
	Gates.showControl(0);  
	GatePage.setValue(-1);
    
};

Content.getComponent("CloseGates").setControlCallback(onCloseGatesControl);



inline function onGatePageControl(component, value)
{
	Gates.showControl(value);  
	
};
Content.getComponent("GatePage").setControlCallback(onGatePageControl);



const var Osc1Env = [Synth.getModulator("AHDSR Envelope1"),
					Synth.getModulator("AHDSR Envelope2"),
					Synth.getModulator("AHDSR Envelope3"),
					Synth.getModulator("AHDSR Envelope4"),
					Synth.getModulator("AHDSR Envelope5"),
					Synth.getModulator("AHDSR Envelope6"),
					Synth.getModulator("AHDSR Envelope7"),
					Synth.getModulator("AHDSR Envelope8")];



inline function onATTACK5Control(component, value)
{
	
	for(s in Osc1Env)
	       s.setAttribute(2, value);

	
};

Content.getComponent("ATTACK5").setControlCallback(onATTACK5Control);


inline function onDECAY5Control(component, value)
{
		for(s in Osc1Env)
	       s.setAttribute(5, value);

};

Content.getComponent("DECAY5").setControlCallback(onDECAY5Control);


inline function onSUSTAIN5Control(component, value)
{
		for(s in Osc1Env)
	       s.setAttribute(6, value);

};

Content.getComponent("SUSTAIN5").setControlCallback(onSUSTAIN5Control);



inline function onRELEASE5Control(component, value)
{
		for(s in Osc1Env)
	       s.setAttribute(7, value);

};

Content.getComponent("RELEASE5").setControlCallback(onRELEASE5Control);

const var Filter = Content.getComponent("Filter");



inline function onTablePitchControl(component, value)
{
	
	if(value == 1)
	{

		HarmPitch.showControl(1);
        GainSliders.showControl(0);
        FmLoad.showControl(0);
        Filter.showControl(0);
    
    }
    
    if(value == 2)
    	{
    
    		HarmPitch.showControl(0);        
            GainSliders.showControl(1);
            FmLoad.showControl(0);
            Filter.showControl(0);
        
        }
        
        if(value == 3)
        	{
        
        		HarmPitch.showControl(0);
                GainSliders.showControl(0);
                FmLoad.showControl(0);
                Filter.showControl(1);
            
            }
};

Content.getComponent("TablePitch").setControlCallback(onTablePitchControl);







const var preset = Content.getComponent("preset");
const var SettingsPresets = Content.getComponent("SettingsPresets");


inline function onpresetControl(component, value)
{
	if(value == 0)
		{
	
	      SettingsPresets.showControl(0);  
	  	         
		}

	if(value == 1)
		{
	
	      SettingsPresets.showControl(1);  
	  	         
		}

};

Content.getComponent("preset").setControlCallback(onpresetControl);





inline function onGainControl(component, value)
{
for(s in Osc1)
       s.setAttribute(0, value);    
};

Content.getComponent("Gain").setControlCallback(onGainControl);