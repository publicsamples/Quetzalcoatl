// ==================================| Third Party Node Template |==================================

#pragma once
#include <JuceHeader.h>

namespace project
{
using namespace juce;
using namespace hise;
using namespace scriptnode;

// ==========================| The node class with all required callbacks |==========================

template <int NV> struct custom_node: public data::base
{
	// Metadata Definitions ------------------------------------------------------------------------
	
	SNEX_NODE(custom_node);
	
	struct MetadataClass
	{
		SN_NODE_ID("custom_node");
	};
	
	// set to true if you want this node to have a modulation dragger
	static constexpr bool isModNode() { return false; };
	static constexpr bool isPolyphonic() { return NV > 1; };
	// set to true if your node produces a tail
	static constexpr bool hasTail() { return false; };
	// set to true if your doesn't generate sound from silence and can be suspended when the input signal is silent
	static constexpr bool isSuspendedOnSilence() { return false; };
	// Undefine this method if you want a dynamic channel count
	static constexpr int getFixChannelAmount() { return 2; };
	
	// Define the amount and types of external data slots you want to use
	static constexpr int NumTables = 0;
	static constexpr int NumSliderPacks = 0;
	static constexpr int NumAudioFiles = 0;
	static constexpr int NumFilters = 0;
	static constexpr int NumDisplayBuffers = 0;
	
	// Scriptnode Callbacks ------------------------------------------------------------------------
	
	void prepare(PrepareSpecs specs)
	{
		
	}
	
	void reset()
	{
		
	}
	
	void handleHiseEvent(HiseEvent& e)
	{
		
	}
	
	template <typename T> void process(T& data)
	{
		
		static constexpr int NumChannels = getFixChannelAmount();
		// Cast the dynamic channel data to a fixed channel amount
		auto& fixData = data.template as<ProcessData<NumChannels>>();
		
		// Create a FrameProcessor object
		auto fd = fixData.toFrameData();
		
		while(fd.next())
		{
			// Forward to frame processing
			processFrame(fd.toSpan());
		}
		
	}
	
	template <typename T> void processFrame(T& data)
	{
		
	}
	
	int handleModulation(double& value)
	{
		
		return 0;
		
	}
	
	void setExternalData(const ExternalData& data, int index)
	{
		
	}
	// Parameter Functions -------------------------------------------------------------------------
	
	template <int P> void setParameter(double v)
	{
		if (P == 0)
		{
			// This will be executed for MyParameter (see below)
			jassertfalse;
		}
		
	}
	
	void createParameters(ParameterDataList& data)
	{
		{
			// Create a parameter like this
			parameter::data p("MyParameter", { 0.0, 1.0 });
			// The template parameter (<0>) will be forwarded to setParameter<P>()
			registerCallback<0>(p);
			p.setDefaultValue(0.5);
			data.add(std::move(p));
		}
	}
};
}


