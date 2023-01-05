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

namespace WF_impl
{
// ===================| Node & Parameter type declarations |===================

namespace WF_t_parameters
{
// Parameter list for WF_impl::WF_t -------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(offsetRange, 
                             -1., 
                             1., 
                             0.001);

template <int NV>
using offset = parameter::from0To1<project::Folder<NV>, 
                                   2, 
                                   offsetRange>;

template <int NV>
using fold = parameter::plain<project::Folder<NV>, 0>;
template <int NV>
using lowpass = parameter::plain<project::Folder<NV>, 1>;
template <int NV>
using WF_t_plist = parameter::list<fold<NV>, 
                                   lowpass<NV>, 
                                   offset<NV>>;
}

template <int NV>
using WF_t_ = container::chain<WF_t_parameters::WF_t_plist<NV>, 
                               wrap::fix<2, project::Folder<NV>>>;

// =======================| Root node initialiser class |=======================

template <int NV> struct instance: public WF_impl::WF_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(WF);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(48)
		{
			0x005B, 0x0000, 0x6600, 0x6C6F, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 
            0x0000, 0x6C00, 0x776F, 0x6170, 0x7373, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0002, 0x0000, 0x666F, 0x7366, 0x7465, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ----------------------------------------------------
		
		auto& faust = this->getT(0); // project::Folder<NV>
		
		// Parameter Connections ----------------------------------------------
		
		this->getParameterT(0).connectT(0, faust); // fold -> faust::fold
		
		this->getParameterT(1).connectT(0, faust); // lowpass -> faust::lowpass
		
		this->getParameterT(2).connectT(0, faust); // offset -> faust::offset
		
		// Default Values -----------------------------------------------------
		
		; // faust::fold is automated
		; // faust::lowpass is automated
		; // faust::offset is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ============================| Public Definition |============================

namespace project
{
// polyphonic template declaration

template <int NV>
using WF = wrap::node<WF_impl::instance<NV>>;
}


