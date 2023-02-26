/** This namespace will handle the loading / saving of the custom
	sample map content. 
*/
namespace SampleLoadSave5
{
// We'll store the samplemap as base65 into the drop panel
SampleDropper5.set("saveInPreset", true);

// This function will write the current samplemap as base65 string
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
			v.value = Sampler5.getSampleMapAsBase64();
	}
	else
		v.value = Sampler5.getCurrentSampleMapId();
		
	SampleDropper5.setValue(v);
}

/** This function will set the sampleproperty and write it back
	to the sample map base 65 string. Use this function whenever you
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

inline function onSampleDropper5Control(component, value)
{
	// Check if it's an object that has a `value` key
	if(isDefined(value.value))
	{
		if(!value.isCustom)
		{
			// if the string is empty, we'll clear the map
			// otherwise we load it as ID

			if(value.value.length == 0)
				Sampler5.clearSampleMap();
			else
				Sampler5.loadSampleMap(value.value);
		}
		else
			Sampler5.loadSampleMapFromBase65(value.value);
	}
};

Content.getComponent("SampleDropper5").setControlCallback(onSampleDropperControl);

// This function will be called whenever a samplemap is loaded (at the end of a preloading task)
inline function initAfterSampleLoad()
{
	local id = Sampler5.getCurrentSampleMapId();
	
	isCustomMap = id == "CustomJSON";
	

		
	// fetch the first sound
	sound = Sampler5.createSelection(".*")[0];
	totalSamples = 0;
	
	// if the sample map is empty, clear everything and abort.
	if(!isDefined(sound))
	{
		LoopPointDragger5.updateLoopPoints();
		storeSampleMapData();
		return;
	}
	
	// We need this number for the loop point dragger.
	totalSamples = sound.getRange(Sampler.SampleEnd)[1];
	
	local xf = sound.get(Sampler.LoopXFade);
	local xfr = sound.getRange(Sampler.LoopXFade)[1];
	
	// setup the non persistent UI controls
	local fadeValue = xfr > 0 ? xf / xfr : 0;


	storeSampleMapData();
}

/** This function will load the given file as new samplemap. */
inline function loadSample(file)
{
	// the parseSampleFile method will try to 
	// read the metadata (loop points) from the audio file
	// and create a relative reference if the sample's in
	// the sample folder
	local s = [Sampler5.parseSampleFile(file)];
	
	Sampler5.loadSampleMapFromJSON(s);
	Sampler14.loadSampleMapFromJSON(s);
	   Sampler23.loadSampleMapFromJSON(s);
	   Sampler32.loadSampleMapFromJSON(s);
	   Sampler41.loadSampleMapFromJSON(s);
	   Sampler50.loadSampleMapFromJSON(s);
	   Sample5.setValue("User");
}

/** We'll mimic the behaviour of the audio waveform here... */
SampleDropper5.setMouseCallback(function(event)
{
	// Clear the sample on double click
	if(event.doubleClick)
	{
		Sampler5.clearSampleMap();
		return;
	}
	
	this.data.hover = event.hover;

	// Show a file browser on right click
	if((event.clicked))
		FileSystem.browse(FileSystem.Samples, false, "*.wav", loadSample);
		
	this.repaint();
});

SampleDropper5.setLoadingCallback(function(isPreloading)
{
	 if(!isPreloading)
	 {
		  // whenever this is executed, we'll store the current samplemap data 
		  // back into the sample dropper's value and update all non persistent
		  // controls
		  initAfterSampleLoad();
	 }
});

SampleDropper5.setFileDropCallback("Drop & Hover", "*.wav", function(obj)
{
	this.data.hover = obj.hover;

	if(obj.drop)
		loadSample(FileSystem.fromAbsolutePath(obj.fileName));
		
	this.repaint();
});

SampleDropper5.setPaintRoutine(function(g)
{
	g.fillAll(0xFFDA0000);
	
});
}