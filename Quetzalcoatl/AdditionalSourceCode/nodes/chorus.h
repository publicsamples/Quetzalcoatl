#pragma once

#include <JuceHeader.h>
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace chorus_impl
{
// =======================| Node & Parameter type declarations |=======================

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
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, jdsp::jchorus>, 
                                 filters::svf<NV>, 
                                 filters::svf<NV>, 
                                 core::gain>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain1_t>;

namespace chorus_t_parameters
{
// Parameter list for chorus_impl::chorus_t ------------------------------------------

DECLARE_PARAMETER_RANGE(centreRange, 
                        0., 
                        100.);

using centre = parameter::from0To1<jdsp::jchorus, 
                                   0, 
                                   centreRange>;

DECLARE_PARAMETER_RANGE(feedRange, 
                        -1., 
                        1.);

using feed = parameter::from0To1<jdsp::jchorus, 
                                 2, 
                                 feedRange>;

DECLARE_PARAMETER_RANGE_SKEW(rateRange, 
                             0., 
                             100., 
                             0.30103);

using rate = parameter::from0To1<jdsp::jchorus, 
                                 3, 
                                 rateRange>;

DECLARE_PARAMETER_RANGE_SKEW(lowRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using low = parameter::from0To1<filters::svf<NV>, 
                                0, 
                                lowRange>;

template <int NV> using high = low<NV>;

using depth = parameter::plain<jdsp::jchorus, 1>;
using mix = parameter::plain<chorus_impl::xfader_t, 0>;
template <int NV>
using chorus_t_plist = parameter::list<centre, 
                                       depth, 
                                       feed, 
                                       rate, 
                                       mix, 
                                       low<NV>, 
                                       high<NV>>;
}

template <int NV>
using chorus_t_ = container::chain<chorus_t_parameters::chorus_t_plist<NV>, 
                                   wrap::fix<2, xfader_t>, 
                                   split_t<NV>>;

// ==========================| Root node initialiser class |==========================

template <int NV> struct instance: public chorus_impl::chorus_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(chorus);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(106)
		{
			0x005B, 0x0000, 0x6300, 0x6E65, 0x7274, 0x0065, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0xD604, 0x3F07, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x6400, 0x7065, 0x6874, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xCB3F, 0x3CFE, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0002, 0x0000, 0x6566, 0x6465, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xE53F, 0x4050, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 
            0x0000, 0x6172, 0x6574, 0x0000, 0x0000, 0x0000, 0x8000, 0x8B3F, 
            0x0390, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 
            0x696D, 0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x1687, 0x3E39, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x6C00, 0x776F, 
            0x0000, 0x0000, 0x0000, 0x8000, 0xC93F, 0x4376, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 0x6968, 0x6867, 0x0000, 
            0x0000, 0x0000, 0x8000, 0xBC3F, 0x9074, 0x003E, 0x8000, 0x003F, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -----------------------------------------------------------
		
		auto& xfader = this->getT(0);                  // chorus_impl::xfader_t
		auto& split = this->getT(1);                   // chorus_impl::split_t<NV>
		auto& chain = this->getT(1).getT(0);           // chorus_impl::chain_t<NV>
		auto& jchorus = this->getT(1).getT(0).getT(0); // jdsp::jchorus
		auto& svf = this->getT(1).getT(0).getT(1);     // filters::svf<NV>
		auto& svf1 = this->getT(1).getT(0).getT(2);    // filters::svf<NV>
		auto& gain = this->getT(1).getT(0).getT(3);    // core::gain
		auto& chain1 = this->getT(1).getT(1);          // chorus_impl::chain1_t
		auto& gain1 = this->getT(1).getT(1).getT(0);   // core::gain
		
		// Parameter Connections -----------------------------------------------------
		
		this->getParameterT(0).connectT(0, jchorus); // centre -> jchorus::CentreDelay
		
		this->getParameterT(1).connectT(0, jchorus); // depth -> jchorus::Depth
		
		this->getParameterT(2).connectT(0, jchorus); // feed -> jchorus::Feedback
		
		this->getParameterT(3).connectT(0, jchorus); // rate -> jchorus::Rate
		
		this->getParameterT(4).connectT(0, xfader); // mix -> xfader::Value
		
		this->getParameterT(5).connectT(0, svf); // low -> svf::Frequency
		
		this->getParameterT(6).connectT(0, svf1); // high -> svf1::Frequency
		
		// Modulation Connections ----------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1); // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain);  // xfader -> gain::Gain
		
		// Default Values ------------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                             // jchorus::CentreDelay is automated
		;                             // jchorus::Depth is automated
		;                             // jchorus::Feedback is automated
		;                             // jchorus::Rate is automated
		jchorus.setParameterT(4, 1.); // jdsp::jchorus::Mix
		
		;                                 // svf::Frequency is automated
		svf.setParameterT(1, 0.38713);    // filters::svf::Q
		svf.setParameterT(2, 0.);         // filters::svf::Gain
		svf.setParameterT(3, 0.00416869); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);         // filters::svf::Mode
		svf.setParameterT(5, 1.);         // filters::svf::Enabled
		
		;                                // svf1::Frequency is automated
		svf1.setParameterT(1, 0.431426); // filters::svf::Q
		svf1.setParameterT(2, 0.);       // filters::svf::Gain
		svf1.setParameterT(3, 0.01);     // filters::svf::Smoothing
		svf1.setParameterT(4, 1.);       // filters::svf::Mode
		svf1.setParameterT(5, 1.);       // filters::svf::Enabled
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.530609);
		this->setParameterT(1, 0.738263);
		this->setParameterT(2, 0.751234);
		this->setParameterT(3, 0.128481);
		this->setParameterT(4, 0.18075);
		this->setParameterT(5, 0.763531);
		this->setParameterT(6, 0.282141);
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
// ===============================| Public Definition |===============================

namespace project
{
// polyphonic template declaration

template <int NV>
using chorus = wrap::node<chorus_impl::instance<NV>>;
}


