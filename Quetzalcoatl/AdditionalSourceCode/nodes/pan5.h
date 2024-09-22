#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace pan5_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable_t_index = runtime_target::indexers::fix_hash<3433272>;

DECLARE_PARAMETER_RANGE(global_cable_modRange, 
                        -1., 
                        1.);

template <int NV>
using global_cable_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                             0, 
                                             global_cable_modRange>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, global_cable_mod<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, global_cable_t<NV>>, 
                                 jdsp::jpanner<NV>>;

template <int NV>
using pan5_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 core::gain<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public pan5_impl::pan5_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(pan5);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(2)
		{
			0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain = this->getT(0);                // pan5_impl::chain_t<NV>
		auto& global_cable = this->getT(0).getT(0); // pan5_impl::global_cable_t<NV>
		auto& jpanner = this->getT(0).getT(1);      // jdsp::jpanner<NV>
		auto& gain = this->getT(1);                 // core::gain<NV>
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable.getWrappedObject().getParameter().connectT(0, jpanner); // global_cable -> jpanner::Pan
		
		// Default Values --------------------------------------------------------------------------
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		gain.setParameterT(0, -12.); // core::gain::Gain
		gain.setParameterT(1, 20.);  // core::gain::Smoothing
		gain.setParameterT(2, 0.);   // core::gain::ResetValue
		
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // pan5_impl::global_cable_t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using pan5 = wrap::node<pan5_impl::instance<NV>>;
}


