namespace DragPanel
{
	const var Panel1 = Content.getComponent("Panel1");
	
	Panel1.data.sources = matrix.getSourceList();
	
	
	
	const var dragPath = Content.createPath();
	dragPath.loadFromData("228.t0FDlHBQvpTkCwFDlHBQ..abCwFVRnAQ..abCwFd+YBQPE.PCwFZrKCQ..abCwF4XqBQ..abCwF4XqBQvpTkCwFzQjCQvpTkCwFzQjCQ.RRgCwF..VDQ..fmCwFzQjCQfcssCwFzQjCQvDqoCwF4XqBQvDqoCwF4XqBQXOxvCwFZrKCQXOxvCwFd+YBQn8+1CwFVRnAQXOxvCwFDlHBQXOxvCwFDlHBQvDqoCwF7rOAQvDqoCwF7rOAQfcssCwF..d.Q..fmCwF7rOAQ.RRgCwF7rOAQvpTkCwFDlHBQvpTkCMVY");
	
	inline function paintSnapShot(g, obj)
	{
		local c = Rect.reduced(obj.area, obj.valid ? 2 : 3);
		
		g.setColour(0x99111111);
		g.fillRoundedRectangle(c, c[3]/2);
		g.setColour(obj.valid ? Colours.white : 0xaaffffff);
		g.drawRoundedRectangle(c, c[3]/2, 1);
		g.setFont("Lato Bold", 12.0);
		
		Rect.removeFromLeft(obj.area, obj.area[3]/2 - 3);
		
		local t = isDefined(obj.sourceMod) ? obj.sourceMod : this.data.source;
		
		t = TableLogic.SHORT_NAMES[t];	
		
		g.drawAlignedText(t, obj.area, "left");	
			
		local pathArea = Rect.removeFromRight(obj.area, obj.area[3]);
		pathArea = Rect.withSizeKeepingCentre(pathArea, 14, 14);
			
		g.fillPath(dragPath, pathArea);
		
	}
	
	Panel1.setPaintRoutine(function(g)
	{
		var area = this.getLocalBounds(0);
		
		var w = this.get("width") / this.data.sources.length;
		
		var idx = 0;
		
		for(s in this.data.sources)
		{
			paintSnapShot(g, {
				"area": Rect.removeFromLeft(area, w),
				"valid": this.data.hoverIndex == idx++,
				"sourceMod": s
			});
		}
	});
	
	Panel1.set("allowCallbacks", "All Callbacks");
	
	
	
	inline function isValidDrag(target)
	{
		local v = matrix.canConnect(this.data.source, matrix.getTargetId(target));
		return v;
	};
	
	inline function onModulationDrag(valid, target)
	{
		if(valid)
		{
			local targetId = matrix.getTargetId(target);
				
			if(targetId.length > 0)
			{
				local source = matrix.getSourceList()[this.data.dragIndex];
				matrix.connect(source, targetId, true);
			}
		}
	
		this.setMouseCursor("PointingHandCursor", Colours.white, [0, 0]);
	}
	
	Panel1.setMouseCursor("PointingHandCursor", Colours.white, [0, 0]);
	
	Panel1.data.hoverIndex = -1;
	
	Panel1.setMouseCallback(function(event)
	{
		this.data.hoverIndex = parseInt(event.x / this.get("width") * this.data.sources.length);
	
		if(!event.hover || event.drag)
			this.data.hoverIndex = -1;
	
		if(event.clicked && !event.drag)
		{
			this.setMouseCursor("DraggingHandCursor", Colours.white, [0, 0]);
	
			this.data.dragIndex = parseInt(event.x / this.get("width") * this.data.sources.length);
			this.data.source = matrix.getSourceList()[this.data.dragIndex];
	
			var w = this.get("width") / this.data.sources.length;
	
			var deltaX = -1.0 * Math.fmod(event.x, w);
			var deltaY = -event.y;
			
			this.startInternalDrag({
				"area": [event.x + deltaX, 0, w, this.get("height")],
				"offset": [deltaX, deltaY],
				"paintRoutine": paintSnapShot,
				"isValid": isValidDrag,
				"dragCallback": onModulationDrag
			});
		}
		if(event.drag)
		{
			Content.refreshDragImage();
		}
		
		this.repaint();
	});
}