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

namespace Fold_impl
{
// ==================| Node & Parameter type declarations |==================

namespace Fold_t_parameters
{
// Parameter list for Fold_impl::Fold_t ------------------------------------

template <int NV>
using Fold = parameter::plain<project::b259wf<NV>, 0>;
template <int NV>
using LP = parameter::plain<project::b259wf<NV>, 1>;
template <int NV>
using Fold_t_plist = parameter::list<Fold<NV>, LP<NV>>;
}

template <int NV>
using Fold_t_ = container::chain<Fold_t_parameters::Fold_t_plist<NV>, 
                                 wrap::fix<2, project::b259wf<NV>>>;

// =====================| Root node initialiser class |=====================

template <int NV> struct instance: public Fold_impl::Fold_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Fold);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(30)
		{
			0x005B, 0x0000, 0x4600, 0x6C6F, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 
            0x0000, 0x4C00, 0x0050, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------
		
		auto& faust = this->getT(0); // project::b259wf<NV>
		
		// Parameter Connections -------------------------------------------
		
		this->getParameterT(0).connectT(0, faust); // Fold -> faust::fold
		
		this->getParameterT(1).connectT(0, faust); // LP -> faust::lowpass
		
		// Default Values --------------------------------------------------
		
		;                           // faust::fold is automated
		;                           // faust::lowpass is automated
		faust.setParameterT(2, 0.); // core::faust::offset
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ==========================| Public Definition |==========================

namespace project
{
// polyphonic template declaration

template <int NV>
using Fold = wrap::node<Fold_impl::instance<NV>>;
}


