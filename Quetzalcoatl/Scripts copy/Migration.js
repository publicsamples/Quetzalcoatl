/** This namespace will handle the migration of a old
	system that used audio waveforms to the new samplemap JSON format.
*/

namespace Migration
{
	// This object can be registered to execute callbacks when a 
	// user preset is being loaded / stored
	const var up = Engine.createUserPresetHandler();
	
	// This tells the user preset handler to convert the
	// user preset to a JSON object and vice versa so that
	// you can perform modifications of it
	// The second argument must be true so that it unpacks
	// and packs the JSON{...} string to an actual object
	up.setEnableUserPresetPreprocessing(true, true);
	
	up.setPreCallback(function(data)
	{
		// this will be added to the user preset data
		var newObject = 
		{
			"type": "ScriptPanel",
			"id": "SampleDropper", 
			"value": 
			{
				"isCustom": true,
				"value": false
			}
		};
		
		// Now we iterate the preset content and look for the
		// old waveform
		for(d in data.Content)
		{
			if(d.id == "OldWaveform")
			{
				// This API call will transform the user preset object
				// into a valid base 64 samplemap (you're welcome...)
				var b64 = Sampler1.getAudioWaveformContentAsBase64(d);

				
				Console.print("Migrate old user preset");
				newObject.value.value = b64;
				break;
			}
		}
		
		// this will return true if we've added the base 64 string in the loop
		if(newObject.value.value)
		{
			// we can just add it to the Content list of the data object
			// and it will be added to the user preset tree later on.
			// In order for this to work we need to enable the complex data unpacking
			// so that it converts the JSON object to the string starting with "JSON"
			data.Content.push(newObject);
		}
	});
}