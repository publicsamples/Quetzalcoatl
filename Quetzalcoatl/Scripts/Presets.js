

namespace UserPresetWidgets
{
	/** Creates a arrow button that cycles through the current category. */
	inline function createPresetButton(name, x, y, up)
	{
		local widget = Content.addPanel(name, x, y);
    
		Content.setPropertiesFromJSON(name, {
		"width": 15,
		"height": 20,
		"saveInPreset": false,
		"tooltip": up ? "Load next user preset" : "Load previous user preset",
		"allowCallbacks": "Clicks & Hover"
		});
    
		widget.data.up = up;
    
		widget.setPaintRoutine(function(g)
		{
			g.setColour(this.data.hover ? 0x29FFFFFF : 0xFF161819);
			g.fillTriangle([0, 0, this.getWidth(), this.getHeight()], this.data.up ? Math.PI/2 : 1.5 * Math.PI);
		});
    
		widget.setMouseCallback(function(event)
		{
			this.data.hover = event.hover;
    	
			if(event.clicked)
			{
				if(this.data.up)
					Engine.loadNextUserPreset(true);
				else
					Engine.loadPreviousUserPreset(true);		
			}
    	
			this.repaint();
		});
		return widget;
	};

	/** Creates a Label that shows the current User Preset.
	*
	*	You can click on it and it will open up a popup with the preset browser.
	*
	*	Customization: Use the itemColour property of the Panel to set the
	*	Preset Browser Colour.
	*/
	inline function createPresetDisplay(name, x, y)
	{
		local widget = Content.addPanel(name, x, y);
    
		Content.setPropertiesFromJSON(name, {
		"width": 150,
		"height": 31,
		"tooltip": "Click to show the Preset browser",
		});
    
    
		widget.setPaintRoutine(function(g)
		{
			g.fillAll(this.data.hover ? 0xFF252526 : 0xFF252526);
			g.setColour(0x01FFFFFF);
			g.drawRect([0, 0, this.getWidth(), this.getHeight()], 1);
			g.setFont("oxygen.regular", 21.0);
			g.setColour(0xFFadaea8);
    	
			g.drawAlignedText(Engine.getCurrentUserPresetName(), [10, 0, this.getWidth(), this.getHeight()], "left");
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


const var UpButton = UserPresetWidgets.createPresetButton("UpButton", 775, 630, true);
const var DownButton = UserPresetWidgets.createPresetButton("DownButton", 593, 630, false);
const var PresetDisplay = UserPresetWidgets.createPresetDisplay("PresetDisplay", 620, 626);
Engine.loadNextUserPreset(true);

