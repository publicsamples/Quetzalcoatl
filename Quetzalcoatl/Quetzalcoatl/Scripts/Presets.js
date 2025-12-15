//Presets
          

const var PRESET_Bar = Content.getComponent("PRESET_Bar");


const var PRESET_Browser = Content.getComponent("PRESET_Browser");

namespace UserPresetWidgets
{
	
	inline function createPresetDisplay(name, x, y)
	{
		local widget = Content.addPanel(name, 0, 0);
    
		Content.setPropertiesFromJSON(name, {

		"tooltip": "Click to show the Preset browser",
        "parentComponent": "PRESET_Bar",
		});
    
    	widget.setPaintRoutine(function(g)
		{
			g.fillAll(this.data.hover ? 0x00000000 : 0x00000000);
			g.setColour(0xBE291A1A);
			g.drawRect([0, 0, this.getWidth(), this.getHeight()], 0);
			g.setFont("Montserrat", 14.0);
			g.setColour(0xFFF9968E);
    	
			g.drawAlignedText(Engine.getCurrentUserPresetName(), [0, 0, this.getWidth(), this.getHeight()], "centred");
		});
    
		widget.setTimerCallback(function()
		{
			this.repaint();
		});
    
		widget.startTimer(300);
	
    
		widget.setMouseCallback(function(event)
		{
			this.data.hover = event.hover;
			this.repaint();
		});
		return widget;
	};

}


Engine.loadNextUserPreset(true);
const var PresetDisplay = UserPresetWidgets.createPresetDisplay("PresetDisplay", 50, 0);

//Preset Nav buttons

inline function onPresetLeftControl(component, value)
{
	if (value == 1)
	    {
	    	Engine.loadPreviousUserPreset(false);
	    }

};

Content.getComponent("PresetLeft").setControlCallback(onPresetLeftControl);


inline function onPresetRightControl(component, value)
{
	if (value == 1)
	    {
	    	Engine.loadNextUserPreset(false);
	    }
};

Content.getComponent("PresetRight").setControlCallback(onPresetRightControl);


