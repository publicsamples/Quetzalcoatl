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

namespace fold_impl
{
// ===================| Node & Parameter type declarations |===================

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

using xfader_c0 = parameter::from0To1<core::gain, 
                                      0, 
                                      xfader_c0Range>;

using xfader_c1 = xfader_c0;

using xfader_multimod = parameter::list<xfader_c0, xfader_c1>;

using xfader_t = control::xfader<xfader_multimod, faders::linear>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, project::b259wf<NV>>, 
                                  core::gain>;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain1_t<NV>>, 
                                  chain2_t>;

namespace fold_t_parameters
{
// Parameter list for fold_impl::fold_t ---------------------------------------

template <int NV>
using fold = parameter::chain<ranges::Identity, 
                              parameter::plain<project::b259wf<NV>, -1>, 
                              parameter::plain<project::b259wf<NV>, 0>>;

template <int NV>
using lp = parameter::chain<ranges::Identity, 
                            parameter::plain<project::b259wf<NV>, -1>, 
                            parameter::plain<project::b259wf<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(offsetRange, 
                             -1., 
                             1., 
                             0.001);

template <int NV>
using offset = parameter::from0To1<project::b259wf<NV>, 
                                   2, 
                                   offsetRange>;

using mix = parameter::plain<fold_impl::xfader_t, 0>;
template <int NV>
using fold_t_plist = parameter::list<fold<NV>, 
                                     lp<NV>, 
                                     offset<NV>, 
                                     mix>;
}

template <int NV>
using fold_t_ = container::chain<fold_t_parameters::fold_t_plist<NV>, 
                                 wrap::fix<2, xfader_t>, 
                                 split1_t<NV>>;

// =======================| Root node initialiser class |=======================

template <int NV> struct instance: public fold_impl::fold_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(fold);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(60)
		{
			0x005B, 0x0000, 0x6600, 0x6C6F, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x4083, 0x3F7C, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 
            0x0000, 0x6C00, 0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 0xA1CB, 
            0x3F4F, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x6F00, 
            0x6666, 0x6573, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0xB852, 
            0x3EF2, 0x0000, 0x3F80, 0x0000, 0x0000, 0x035B, 0x0000, 0x6D00, 
            0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x3F3F, 0x4D35, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ----------------------------------------------------
		
		auto& xfader = this->getT(0);                // fold_impl::xfader_t
		auto& split1 = this->getT(1);                // fold_impl::split1_t<NV>
		auto& chain1 = this->getT(1).getT(0);        // fold_impl::chain1_t<NV>
		auto& faust = this->getT(1).getT(0).getT(0); // project::b259wf<NV>
		auto& gain = this->getT(1).getT(0).getT(1);  // core::gain
		auto& chain2 = this->getT(1).getT(1);        // fold_impl::chain2_t
		auto& gain1 = this->getT(1).getT(1).getT(0); // core::gain
		
		// Parameter Connections ----------------------------------------------
		
		auto& fold_p = this->getParameterT(0);
		fold_p.connectT(0, faust); // fold -> faust::Fold
		fold_p.connectT(1, faust); // fold -> faust::fold
		
		auto& lp_p = this->getParameterT(1);
		lp_p.connectT(0, faust); // lp -> faust::Lowpass
		lp_p.connectT(1, faust); // lp -> faust::lowpass
		
		this->getParameterT(2).connectT(0, faust); // offset -> faust::offset
		
		this->getParameterT(3).connectT(0, xfader); // mix -> xfader::Value
		
		// Modulation Connections ---------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1); // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain);  // xfader -> gain::Gain
		
		// Default Values -----------------------------------------------------
		
		; // xfader::Value is automated
		
		; // faust::fold is automated
		; // faust::lowpass is automated
		; // faust::offset is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.985359);
		this->setParameterT(1, 0.811063);
		this->setParameterT(2, 0.474062);
		this->setParameterT(3, 0.801594);
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
using fold = wrap::node<fold_impl::instance<NV>>;
}


