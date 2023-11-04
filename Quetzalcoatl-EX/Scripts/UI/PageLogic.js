namespace PageLogic
{
	const var Panel2 = Content.getComponent("Panel2");
	
	Panel2.setPaintRoutine(function(g)
	{
		var b = this.getLocalBounds(5);
		
		g.fillAll(0xFF333333);
		
		g.setColour(0xFF222222);
		
		g.fillRoundedRectangle(Rect.removeFromBottom(b, 530), 4);
		
		g.setColour(Colours.black);
		g.fillRect([42, 625, 713, 4]);
	
		//g.addNoise(0.05);
		
		g.setFont("Lato Bold", 18.0);
		g.setColour(0xAAFFFFFF);
		g.drawAlignedText(Engine.getProjectInfo().ProjectName, b, "topRight");
	});
	
	const var menuButtonLaf = Content.createLocalLookAndFeel();
	
	menuButtonLaf.registerFunction("drawToggleButton", function(g, obj)
	{
		g.setColour(0x22000000);
		g.fillRect(obj.area);
		g.setColour(Colours.withAlpha(Colours.white, obj.over ? 0.8 : 0.6));
		g.setFont("Lato Bold", 13.0);
		g.drawAlignedText(obj.text, obj.area, "centred");
	});
	
	const var menuButtons = [Content.getComponent("Button1"), 
	                         Content.getComponent("Button2"), 
	                         Content.getComponent("Button3")];
	
	inline function onMenuButton(component, value)
	{
		if(!value)
			return;
		
		local idx = menuButtons.indexOf(component);
		
		if(idx == 0)
			Engine.undo();
		else if(idx == 1)
			Engine.redo();
		else if(idx == 2)
			matrix.clearAllConnections();
	}
	
	for(c in menuButtons)
	{
		c.set("isMomentary", true);
		c.setLocalLookAndFeel(menuButtonLaf);
		c.set("saveInPreset", false);
		c.setControlCallback(onMenuButton);
	}
	    
	
	const var pageButton_laf = Content.createLocalLookAndFeel();
	
	pageButton_laf.registerFunction("drawToggleButton", function(g, obj)
	{
		
	
		g.setColour(0x22000000);
		if(obj.value)
			g.fillRect(obj.area);
		
		var alpha = 0.2;
		
		if(obj.over)
			alpha += 0.1;
			
		if(obj.value)
			alpha += 0.5;
		
		g.setColour(Colours.withAlpha(Colours.white, alpha));
		g.setFont("Lato Bold", 13.0);
		g.drawAlignedText(obj.text, obj.area, "centred");
	});
	
	const var pageButton_laf_targets = [Content.getComponent("Button4"), 
	                                    Content.getComponent("Button5")];
	
	const var pageBroadcaster = Engine.createBroadcaster({
		"id": "pageBroadcaster",
		"args": ["index"]
	});
	
	pageBroadcaster.attachToRadioGroup(9000, "page logic");
	
	pageBroadcaster.addComponentPropertyListener(["TableBG", "MatrixBG"], "visible", "show pages", function(index, i)
	{
		return index == i;
	});
	
	for(c in pageButton_laf_targets)
	    c.setLocalLookAndFeel(pageButton_laf);
}