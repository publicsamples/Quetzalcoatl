/** This namespace contains the logic of detecting the pitch of a sample
	and set it as root. 
*/
namespace PitchDetector
{
	reg newPitch = 0;
	

	
	// This function is being executed asynchronously when the user 
	// presses OK after a detected pitch change.
	inline function showPitch(ok)
	{
		if(ok)
		{
			SampleLoadSave.setAndStore(Sampler.Root, newPitch);
		}
	}
	
	inline function onDetectPitchControl(component, value)
	{
		if(value && isDefined(sound))
		{
			local buf = sound.loadIntoBufferArray()[0];
			local freq = buf.detectPitch(sound.getSampleRate());
			
			for(i = 0; i < 128; i++)
			{
				local thisFreq = Engine.getFrequencyForMidiNoteNumber(i);
				if(freq < thisFreq)
				{
					newPitch = i-1;
		
					if(sound.get(Sampler.Root) != newPitch)
					{
						local m = "";
						
						m += "Old pitch: `";
						m += Engine.getMidiNoteName(sound.get(Sampler.Root));
						m += "`  \nNewPitch: `";
						m += Engine.getMidiNoteName(newPitch);
						m += "`";
	
						Engine.showYesNoWindow("Different Pitch detected", m, showPitch);
					}
					
					break;
				}
			}
		}
	};
	
	Content.getComponent("DetectPitch").setControlCallback(onDetectPitchControl);
}