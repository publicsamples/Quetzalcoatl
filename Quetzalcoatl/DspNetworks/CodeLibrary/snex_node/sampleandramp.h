template <int NV> struct sampleandramp
{
	SNEX_NODE(sampleandramp);
	
	// A compile time array of ramper objects
	// (sfloat is a built-in SNEX type for 
	// ramping between values for parameter
	// smoothing.
	span<sfloat, 2> rampers;
	
	double sampleRate = 44100.0;
	double fadeTimeMs = 1.0 / 44100.0 * 1000.0;
	
	// Initialise the processing specs here
	void prepare(PrepareSpecs ps)
	{
		sampleRate = ps.sampleRate;

		// set the fade time again
		// (for some reason, iterating over the arra
		// throws a SNEX compilation error, so we have
		// to spell it out for each element)...
		rampers[0].prepare(sampleRate, fadeTimeMs);
		rampers[1].prepare(sampleRate, fadeTimeMs);
	}
	
	// Reset the processing pipeline here
	void reset()
	{
		// This will reset the ramp position, so when you bypass / unbypass the node it will
		// not pick up from the old value and cause clicks.
		rampers[0].reset();
		rampers[1].reset();
	}
	
	float calculateSample(float input, sfloat& ramper)
	{
		// if the ramper isn't smoothing, it's waiting for
		// the next input
		if(!ramper.isActive())
			ramper.set(input);

		// this will calculate the next ramp value and
		// update the internal state
		return ramper.advance();
	}
	
	// Process the signal as frame here
	template <int C> void processFrame(span<float, C>& data)
	{
		data[0] = calculateSample(data[0], rampers[0]);
		
		if(C != 1)
			data[1] = calculateSample(data[1], rampers[1]);
	}
	
	// Process the signal here
	template <typename ProcessDataType> void process(ProcessDataType& data)
	{
		// We'll only use frame processing here...
		auto pd = data.toFrameData();
		
		while(pd.next())
			processFrame(pd.toSpan());
	}
	
	void handleHiseEvent(HiseEvent& e){}
	void setExternalData(const ExternalData& d, int index){}
	
	template <int P> void setParameter(double v)
	{
		if(P == 0) // Factor (1 - 64 with step size 1)
		{
			const auto factor = Math.range(v, 0.0, 256.0);
			
			// internally it will calculate the steps in
			// samples so this is two unnecessary divisions
			// but we get to use the built in type
			fadeTimeMs = (factor / sampleRate) * 1000.0;
			
			rampers[0].prepare(sampleRate, fadeTimeMs);
			rampers[1].prepare(sampleRate, fadeTimeMs);
		}
	}
};
