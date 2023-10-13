/** This namespace will handle the loading / saving of the custom
	sample map content. 
*/
namespace SampleLoadSave
{

// This function will write the current samplemap as base64 string
// into the sample dropper panel and will be called whenever a sample
// property changes
inline function storeSampleMapData()
{
	local v =
	{
		"isCustom": isCustomMap,
		"value": ""
	};

	if(isCustomMap)
	{
		if(isDefined(sound))
			v.value = Sampler1.getSampleMapAsBase64();
	}
	else
		v.value = Sampler1.getCurrentSampleMapId();
		
	SampleDropper.setValue(v);
}

/** This function will set the sampleproperty and write it back
	to the sample map base 64 string. Use this function whenever you
	change a property in order to ensure that it will be saved in the 
	user preset
*/
inline function setAndStore(property, value)
{
	// do not store anything in a non-custom map
	if(!isCustomMap)
		return;

	sound.set(property, value);
	storeSampleMapData();
}

inline function onSampleDropperControl(component, value)
{
	// Check if it's an object that has a `value` key
	if(isDefined(value.value))
	{
		if(!value.isCustom)
		{
			// if the string is empty, we'll clear the map
			// otherwise we load it as ID

			if(value.value.length == 0)
				
				Sampler1.clearSampleMap();
			else
				Sampler1.loadSampleMap(value.value);
		}
		else
			Sampler1.loadSampleMapFromBase64(value.value);
		
	}
};

Content.getComponent("SampleDropper").setControlCallback(onSampleDropperControl);

// This function will be called whenever a samplemap is loaded (at the end of a preloading task)
inline function initAfterSampleLoad()
{
slot.loadFile("Sampler1");
	local id = Sampler1.getCurrentSampleMapId();
	slot.loadFile("CustomJSON");
	isCustomMap = id == "CustomJSON";
	
	if(isCustomMap || id.length == 0)
		SampleMapLoader.setValue(0);
		
	else
		SampleMapLoader.setValue(Sampler.getSampleMapList().indexOf(id) + 1);
	
	// fetch the first sound
	sound = Sampler1.createSelection(".*")[0];
	totalSamples = 0;
	
	// if the sample map is empty, clear everything and abort.
	if(!isDefined(sound))
	{
		LoopPointDragger.updateLoopPoints();
		storeSampleMapData();
		return;
	}
	
	// We need this number for the loop point dragger.
	totalSamples = sound.getRange(Sampler.SampleEnd)[1];
	
	local xf = sound.get(Sampler.LoopXFade);
	local xfr = sound.getRange(Sampler.LoopXFade)[1];
	
	// setup the non persistent UI controls
	local fadeValue = xfr > 0 ? xf / xfr : 0;
	Content.getComponent("XFade").setValue(fadeValue);
	Content.getComponent("Loop").setValue(sound.get(Sampler.LoopEnabled));
	

	storeSampleMapData();
}

/** This function will load the given file as new samplemap. */
inline function loadSample(file)
{
	// the parseSampleFile method will try to 
	// read the metadata (loop points) from the audio file
	// and create a relative reference if the sample's in
	// the sample folder
	local s = [Sampler1.parseSampleFile(file)];

	Sampler1.loadSampleMapFromJSON(s);
}

/** We'll mimic the behaviour of the audio waveform here... */
SampleDropper.setMouseCallback(function(event)
{
	// Clear the sample on double click
	if(event.doubleClick)
	{
		Sampler1.clearSampleMap();
		return;
	}
	
	this.data.hover = event.hover;

	// Show a file browser on right click
	if(event.rightClick && event.clicked)
		FileSystem.browse(FileSystem.Samples, false, "*.wav", loadSample);
		
	this.repaint();
});

SampleDropper.setLoadingCallback(function(isPreloading)
{
	 if(!isPreloading)
	 {
		  // whenever this is executed, we'll store the current samplemap data 
		  // back into the sample dropper's value and update all non persistent
		  // controls
		  initAfterSampleLoad();
		  
	 }
});

SampleDropper.setFileDropCallback("Drop & Hover", "*.wav", function(obj)
{
	this.data.hover = obj.hover;

	if(obj.drop)
		loadSample(FileSystem.fromAbsolutePath(obj.fileName));
		slot.loadFile("Sampler1");
	this.repaint();
});

SampleDropper.setPaintRoutine(function(g)
{
	g.fillAll(0xDD444444);
	g.setColour(Colours.withAlpha(Colours.white, this.data.hover ? 0.8 : 0.4));
	g.drawAlignedText("Drop File or right click to load sample", this.getLocalBounds(0), "centred");
	
});
}