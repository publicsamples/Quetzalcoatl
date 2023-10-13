/** This defines a panel that will mimic the loop dragging facilities from the sampler */
namespace LoopPointDragger
{
	
// Create the path for the fade in
const var fadePath = Content.createPath();

fadePath.startNewSubPath(0.0, 1.0);
fadePath.lineTo(1.0, 0.0);
fadePath.lineTo(1.0, 1.0);
fadePath.closeSubPath();

const var fadeOutPath = Content.createPath();
fadeOutPath.startNewSubPath(0.0, 1.0);
fadeOutPath.lineTo(0.0, 0.0);
fadeOutPath.lineTo(1.0, 1.0);
fadeOutPath.closeSubPath();

/** this will update the internal data for the panel and must be called
	whenever one of the sample property changes.
*/
inline function updateLoopPoints()
{
	if(!isDefined(sound))
	{
		LoopPanel.data.sx = 0;
		LoopPanel.data.sw = 0;
		LoopPanel.data.lx = 0;
		LoopPanel.data.lw = 0;
		LoopPanel.data.dx = 0;
		LoopPanel.data.dw = 0;
		LoopPanel.data.xfw = 0;

		LoopPanel.repaint();
		return;
	}


	local w = LoopPanel.getWidth();
	local ss = sound.get(Sampler.SampleStart) / totalSamples;
	local se = sound.get(Sampler.SampleEnd) / totalSamples;
	local ls = sound.get(Sampler.LoopStart) / totalSamples;
	local le = sound.get(Sampler.LoopEnd) / totalSamples;
	LoopPanel.data.sx = ss * w;
	LoopPanel.data.sw = (se - ss) * w;
	LoopPanel.data.lx = ls * w;
	LoopPanel.data.lw = (le - ls) * w;
	LoopPanel.data.dx = LoopPanel.data.lx;
	LoopPanel.data.dw = LoopPanel.data.lw;
	LoopPanel.data.xfw = parseInt(sound.get(Sampler.LoopXFade) / totalSamples * w);
	LoopPanel.repaint();
}

SampleLoadSave.initAfterSampleLoad();

LoopPanel.setMouseCallback(function(event)
{
	this.data.hover = event.hover || event.drag;
	
	// Just make sure that everything is up to date before we
	// start fiddleing around
	//updateLoopPoints();
	
	var midX = this.data.lx + 0.5 * this.data.lw;
	
	if(!event.drag)
		this.data.setLeft = event.x < midX;
	
	if(event.drag || event.mouseUp)
	{
		if(this.data.setLeft)
		{
			var right = this.data.dx + this.data.dw;

			this.data.dx = Math.range(event.x, this.data.sx + this.data.xfw, right - 5 - this.data.xfw);
			this.data.dw = right - this.data.dx;
		}
		else
		{
			var maxRight = this.data.sx + this.data.sw;
			this.data.dw = Math.range(event.x - this.data.dx, this.data.xfw + 5 , maxRight - this.data.dx);
		}
	}
	
	if(event.mouseUp)
	{
		var pos = this.data.dx;
		
		if(!this.data.setLeft)
			pos += this.data.dw;
			
		pos = parseInt(pos / this.getWidth() * totalSamples);

		if(this.data.setLeft)
			SampleLoadSave.setAndStore(Sampler.LoopStart, pos);
		else
			SampleLoadSave.setAndStore(Sampler.LoopEnd, pos);
		
		updateLoopPoints();
	}
	
	this.repaint();
});

LoopPanel.setPaintRoutine(function(g)
{
	var alpha = 0.2;
	
	var h = this.getHeight();
	
	if(this.data.hover)
		alpha += 0.1;
	
	if(this.data.down)
		alpha += 0.1;
		
	var loopColour = Colours.withAlpha(Colours.cornflowerblue, alpha);
	var sampleColour = Colours.withAlpha(Colours.white, alpha);
	
	g.setColour(sampleColour);
	g.fillRect([this.data.sx, 0, this.data.sw, h]);
	
	if(!isDefined(sound))
		return;
	
	if(sound.get(Sampler.LoopEnabled))
	{
		g.setColour(loopColour);
		g.fillRect([this.data.dx, 0, this.data.dw, h]);
		
		if(this.data.xfw > 0)
		{
			var isReversed = Reverse.getValue();

			var fadeInRect = [this.data.dx - this.data.xfw, 0, this.data.xfw, h];
			var fadeOutRect = [this.data.dx - this.data.xfw + this.data.dw, 0, this.data.xfw, h];

			if(isReversed)
			{
				fadeInRect[0] += this.data.dw + this.data.xfw;
				fadeOutRect[0] -= this.data.dw - this.data.xfw;
			}

			g.setColour(0x55447788);
			g.fillPath(isReversed ? fadeOutPath : fadePath, fadeInRect);
			
			g.setColour(0x33447788);
			g.fillPath(fadePath, fadeOutRect);
			g.fillPath(fadeOutPath, fadeOutRect);
		}
		
		if(this.data.hover)
		{
			g.setColour(Colours.withAlpha(loopColour, 1.0));
			var handleX = this.data.dx;
			
			if(!this.data.setLeft)
				handleX += this.data.dw - 5;
			
			g.fillRect([handleX, 0, 5, h]);
		}
	}	
});

}