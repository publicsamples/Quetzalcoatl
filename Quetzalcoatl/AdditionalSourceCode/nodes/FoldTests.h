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

namespace FoldTests_impl
{
// ============================| Node & Parameter type declarations |============================

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, core::smoother<NV>>>;

template <int NV> using chain1_t = chain_t<NV>;

template <int NV>
using multi_t = container::multi<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>, 
                                 wrap::fix<1, chain1_t<NV>>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, multi_t<NV>>>;
namespace custom
{

struct expr2
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 100.0 * value * input) * (1 - Math.PI);
		;
	}
};
}

namespace FoldTests_t_parameters
{
// Parameter list for FoldTests_impl::FoldTests_t -----------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(LpRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using Lp = parameter::from0To1<filters::ladder<NV>, 
                               0, 
                               LpRange>;

DECLARE_PARAMETER_RANGE_SKEW_INV(Fold_0Range, 
                                 0., 
                                 2000., 
                                 0.231378);

template <int NV>
using Fold_0 = parameter::from0To1_inv<core::smoother<NV>, 
                                       0, 
                                       Fold_0Range>;

template <int NV> using Fold_1 = Fold_0<NV>;

template <int NV>
using Fold = parameter::chain<ranges::Identity, 
                              Fold_0<NV>, 
                              Fold_1<NV>>;

template <int NV>
using Offset = parameter::plain<math::expr<NV, custom::expr2>, 
                                0>;
template <int NV>
using Res = parameter::plain<filters::ladder<NV>, 1>;
template <int NV>
using FoldTests_t_plist = parameter::list<Offset<NV>, 
                                          Lp<NV>, 
                                          Res<NV>, 
                                          Fold<NV>>;
}

template <int NV>
using FoldTests_t_ = container::chain<FoldTests_t_parameters::FoldTests_t_plist<NV>, 
                                      wrap::fix<2, math::sub<NV>>, 
                                      chain2_t<NV>, 
                                      math::expr<NV, custom::expr2>, 
                                      filters::ladder<NV>>;

// ================================| Root node initialiser class |================================

template <int NV> struct instance: public FoldTests_impl::FoldTests_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(FoldTests);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(60)
		{
			0x005B, 0x0000, 0x4F00, 0x6666, 0x6573, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x96DE, 0x3F1C, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x4C00, 0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 
            0x5200, 0x7365, 0x9A00, 0x9999, 0x663E, 0x1E66, 0x9A41, 0x9999, 
            0x183E, 0x8789, 0x003E, 0x0000, 0x5B00, 0x0003, 0x0000, 0x6F46, 
            0x646C, 0x0000, 0x0000, 0x0000, 0x8000, 0x913F, 0x54ED, 0x003E, 
            0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ----------------------------------------------------------------------
		
		auto& sub = this->getT(0);                               // math::sub<NV>
		auto& chain2 = this->getT(1);                            // FoldTests_impl::chain2_t<NV>
		auto& multi = this->getT(1).getT(0);                     // FoldTests_impl::multi_t<NV>
		auto& chain = this->getT(1).getT(0).getT(0);             // FoldTests_impl::chain_t<NV>
		auto& smoother = this->getT(1).getT(0).getT(0).getT(0);  // core::smoother<NV>
		auto& chain1 = this->getT(1).getT(0).getT(1);            // FoldTests_impl::chain1_t<NV>
		auto& smoother2 = this->getT(1).getT(0).getT(1).getT(0); // core::smoother<NV>
		auto& expr2 = this->getT(2);                             // math::expr<NV, custom::expr2>
		auto& ladder = this->getT(3);                            // filters::ladder<NV>
		
		// Parameter Connections ----------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, expr2); // Offset -> expr2::Value
		
		this->getParameterT(1).connectT(0, ladder); // Lp -> ladder::Frequency
		
		this->getParameterT(2).connectT(0, ladder); // Res -> ladder::Q
		
		auto& Fold_p = this->getParameterT(3);
		Fold_p.connectT(0, smoother);  // Fold -> smoother::SmoothingTime
		Fold_p.connectT(1, smoother2); // Fold -> smoother2::SmoothingTime
		
		// Default Values -----------------------------------------------------------------------
		
		sub.setParameterT(0, 1.); // math::sub::Value
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 1.); // core::smoother::DefaultValue
		
		;                                     // smoother2::SmoothingTime is automated
		smoother2.setParameterT(1, 0.535042); // core::smoother::DefaultValue
		
		; // expr2::Value is automated
		
		;                              // ladder::Frequency is automated
		;                              // ladder::Q is automated
		ladder.setParameterT(2, 0.);   // filters::ladder::Gain
		ladder.setParameterT(3, 0.01); // filters::ladder::Smoothing
		ladder.setParameterT(4, 0.);   // filters::ladder::Mode
		ladder.setParameterT(5, 1.);   // filters::ladder::Enabled
		
		this->setParameterT(0, 0.611677);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.3);
		this->setParameterT(3, 0.207937);
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
// =====================================| Public Definition |=====================================

namespace project
{
// polyphonic template declaration

template <int NV>
using FoldTests = wrap::node<FoldTests_impl::instance<NV>>;
}


