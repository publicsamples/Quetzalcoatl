/** This namespace will handle the loading / saving of the custom
	sample map content. 
*/
namespace SampleLoadSave7
{
// We'll store the samplemap as base77 into the drop panel
SampleDropper7.set("saveInPreset", true);

// This function will write the current samplemap as base77 string
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
			v.value = Sampler7.getSampleMapAsBase77();
	}
	else
		v.value = Sampler7.getCurrentSampleMapId();
		
	SampleDropper7.setValue(v);
}

/** This function will set the sampleproperty and write it back
	to the sample map base 77 string. Use this function whenever you
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

inline function onSampleDropper7Control(component, value)
{
	// Check if it's an object that has a `value` key
	if(isDefined(value.value))
	{
		if(!value.isCustom)
		{
			// if the string is empty, we'll clear the map
			// otherwise we load it as ID

			if(value.value.length == 0)
				Sampler7.clearSampleMap();
			else
				Sampler7.loadSampleMap(value.value);
		}
		else
			Sampler7.loadSampleMapFromBase77(value.value);
	}
};

Content.getComponent("SampleDropper7").setControlCallback(onSampleDropperControl);

// This function will be called whenever a samplemap is loaded (at the end of a preloading task)
inline function initAfterSampleLoad()
{
	local id = Sampler7.getCurrentSampleMapId();
	
	isCustomMap = id == "CustomJSON";
	

		
	// fetch the first sound
	sound = Sampler7.createSelection(".*")[0];
	totalSamples = 0;
	
	// if the sample map is empty, clear everything and abort.
	if(!isDefined(sound))
	{
		LoopPointDragger7.updateLoopPoints();
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
	local s = [Sampler7.parseSampleFile(file)];
	
	Sampler7.loadSampleMapFromJSON(s);
	Sampler16.loadSampleMapFromJSON(s);
	   Sampler25.loadSampleMapFromJSON(s);
	   Sampler34.loadSampleMapFromJSON(s);
	   Sampler43.loadSampleMapFromJSON(s);
	   Sampler52.loadSampleMapFromJSON(s);
	   Sample7.setValue("User");
}

/** We'll mimic the behaviour of the audio waveform here... */
SampleDropper7.setMouseCallback(function(event)
{
	// Clear the sample on double click
	if(event.doubleClick)
	{
		Sampler7.clearSampleMap();
		return;
	}
	
	this.data.hover = event.hover;

	// Show a file browser on right click
	if(event.clicked)
		FileSystem.browse(FileSystem.Samples, false, "*.wav", loadSample);
		
	this.repaint();
});

SampleDropper7.setLoadingCallback(function(isPreloading)
{
	 if(!isPreloading)
	 {
		  // whenever this is executed, we'll store the current samplemap data 
		  // back into the sample dropper's value and update all non persistent
		  // controls
		  initAfterSampleLoad();
	 }
});

SampleDropper7.setFileDropCallback("Drop & Hover", "*.wav", function(obj)
{
	this.data.hover = obj.hover;

	if(obj.drop)
		loadSample(FileSystem.fromAbsolutePath(obj.fileName));
		
	this.repaint();
});

SampleDropper7.setPaintRoutine(function(g)
{
	g.fillAll(0xFFDA0000);
	
});
}