/** This namespace will handle the loading / saving of the custom
	sample map content. 
*/
namespace SampleLoadSave3
{
// We'll store the samplemap as base64 into the drop panel
SampleDropper3.set("saveInPreset", true);

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
			v.value = Sampler3.getSampleMapAsBase64();
	}
	else
		v.value = Sampler3.getCurrentSampleMapId();
		
	SampleDropper3.setValue(v);
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

inline function onSampleDropper3Control(component, value)
{
	// Check if it's an object that has a `value` key
	if(isDefined(value.value))
	{
		if(!value.isCustom)
		{
			// if the string is empty, we'll clear the map
			// otherwise we load it as ID

			if(value.value.length == 0)
				Sampler3.clearSampleMap();
			else
				Sampler3.loadSampleMap(value.value);
		}
		else
			Sampler3.loadSampleMapFromBase64(value.value);
	}
};

Content.getComponent("SampleDropper3").setControlCallback(onSampleDropperControl);

// This function will be called whenever a samplemap is loaded (at the end of a preloading task)
inline function initAfterSampleLoad()
{
	local id = Sampler3.getCurrentSampleMapId();
	
	isCustomMap = id == "CustomJSON";
	

		
	// fetch the first sound
	sound = Sampler3.createSelection(".*")[0];
	totalSamples = 0;
	
	// if the sample map is empty, clear everything and abort.
	if(!isDefined(sound))
	{
		LoopPointDragger3.updateLoopPoints();
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
	local s = [Sampler3.parseSampleFile(file)];
	
	Sampler3.loadSampleMapFromJSON(s);
	Sampler12.loadSampleMapFromJSON(s);
	   Sampler21.loadSampleMapFromJSON(s);
	   Sampler30.loadSampleMapFromJSON(s);
	   Sampler39.loadSampleMapFromJSON(s);
	   Sampler48.loadSampleMapFromJSON(s);
	   Sample3.setValue("User");
}

/** We'll mimic the behaviour of the audio waveform here... */
SampleDropper3.setMouseCallback(function(event)
{
	// Clear the sample on double click
	if(event.doubleClick)
	{
		Sampler3.clearSampleMap();
		return;
	}
	
	this.data.hover = event.hover;

	// Show a file browser on right click
	if((event.clicked))
		FileSystem.browse(FileSystem.Samples, false, "*.wav", loadSample);
		
	this.repaint();
});

SampleDropper3.setLoadingCallback(function(isPreloading)
{
	 if(!isPreloading)
	 {
		  // whenever this is executed, we'll store the current samplemap data 
		  // back into the sample dropper's value and update all non persistent
		  // controls
		  initAfterSampleLoad();
	 }
});

SampleDropper3.setFileDropCallback("Drop & Hover", "*.wav", function(obj)
{
	this.data.hover = obj.hover;

	if(obj.drop)
		loadSample(FileSystem.fromAbsolutePath(obj.fileName));
		
	this.repaint();
});

SampleDropper3.setPaintRoutine(function(g)
{
	g.fillAll(0xFFDA0000);
	
});
}