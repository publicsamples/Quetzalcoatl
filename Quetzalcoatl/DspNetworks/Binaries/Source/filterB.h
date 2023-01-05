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

namespace filterB_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(pma_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma_mod = parameter::from0To1<filters::svf<NV>, 
                                    0, 
                                    pma_modRange>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using ahdsr_multimod = parameter::list<parameter::plain<pma_t<NV>, 0>, 
                                       parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, ahdsr_t<NV>>, 
                                      pma_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, modchain1_t<NV>>, 
                                 filters::svf<NV>>;

using simple_ar_multimod = parameter::list<parameter::empty, 
                                           parameter::plain<envelope::voice_manager, 0>>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, simple_ar_t<NV>>, 
                                  math::clear<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain1_t<NV>>;

namespace filterB_t_parameters
{
// Parameter list for filterB_impl::filterB_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(resRange, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using res = parameter::from0To1<filters::svf<NV>, 
                                1, 
                                resRange>;

DECLARE_PARAMETER_RANGE_STEP(type_InputRange, 
                             0., 
                             4., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(type_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using type_0 = parameter::from0To1<filters::svf<NV>, 
                                   4, 
                                   type_0Range>;

template <int NV>
using type = parameter::chain<type_InputRange, type_0<NV>>;

DECLARE_PARAMETER_RANGE(envmodRange, 
                        -1., 
                        1.);

template <int NV>
using envmod = parameter::from0To1<filterB_impl::pma_t<NV>, 
                                   1, 
                                   envmodRange>;

template <int NV>
using cut = parameter::plain<filterB_impl::pma_t<NV>, 
                             2>;
using cutmod = parameter::empty;
using cutdets = cutmod;
template <int NV>
using attack = parameter::plain<filterB_impl::ahdsr_t<NV>, 
                                0>;
template <int NV>
using decay = parameter::plain<filterB_impl::ahdsr_t<NV>, 
                               3>;
template <int NV>
using sustain = parameter::plain<filterB_impl::ahdsr_t<NV>, 
                                 4>;
template <int NV>
using release = parameter::plain<filterB_impl::ahdsr_t<NV>, 
                                 5>;
template <int NV>
using filterB_t_plist = parameter::list<cut<NV>, 
                                        res<NV>, 
                                        type<NV>, 
                                        envmod<NV>, 
                                        cutmod, 
                                        cutdets, 
                                        attack<NV>, 
                                        decay<NV>, 
                                        sustain<NV>, 
                                        release<NV>>;
}

template <int NV>
using filterB_t_ = container::chain<filterB_t_parameters::filterB_t_plist<NV>, 
                                    wrap::fix<2, split_t<NV>>, 
                                    envelope::voice_manager>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public filterB_impl::filterB_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(filterB);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(158)
		{
			0x005B, 0x0000, 0x6300, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x6A3F, 0xF851, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x6572, 0x0073, 0x0000, 0x0000, 0x0000, 0x3F80, 0xF877, 
            0x3F16, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x7400, 
            0x7079, 0x0065, 0x0000, 0x0000, 0x0000, 0x4080, 0xCCCD, 0x3DCC, 
            0x0000, 0x3F80, 0xCCCD, 0x3DCC, 0x035B, 0x0000, 0x6500, 0x766E, 
            0x6F6D, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x6300, 0x7475, 
            0x6F6D, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 0xDF44, 0x3F09, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x6300, 0x7475, 
            0x6564, 0x7374, 0x0000, 0x0000, 0x0000, 0x8000, 0x0041, 0x0000, 
            0x0000, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0006, 0x0000, 0x7461, 
            0x6174, 0x6B63, 0x0000, 0x0000, 0x0000, 0x1C40, 0x0046, 0x0000, 
            0x7200, 0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x0007, 0x0000, 0x6564, 
            0x6163, 0x0079, 0x0000, 0x0000, 0x4000, 0x461C, 0x6667, 0x4298, 
            0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x085B, 0x0000, 0x7300, 0x7375, 
            0x6174, 0x6E69, 0x0000, 0x0000, 0x0000, 0x8000, 0xE13F, 0x8C2C, 
            0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0009, 0x0000, 0x6572, 
            0x656C, 0x7361, 0x0065, 0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 
            0x3F80, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split = this->getT(0);                         // filterB_impl::split_t<NV>
		auto& chain = this->getT(0).getT(0);                 // filterB_impl::chain_t<NV>
		auto& modchain1 = this->getT(0).getT(0).getT(0);     // filterB_impl::modchain1_t<NV>
		auto& ahdsr = this->getT(0).getT(0).getT(0).getT(0); // filterB_impl::ahdsr_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0).getT(1);   // filterB_impl::pma_t<NV>
		auto& svf1 = this->getT(0).getT(0).getT(1);          // filters::svf<NV>
		auto& chain1 = this->getT(0).getT(1);                // filterB_impl::chain1_t<NV>
		auto& simple_ar = this->getT(0).getT(1).getT(0);     // filterB_impl::simple_ar_t<NV>
		auto& clear = this->getT(0).getT(1).getT(1);         // math::clear<NV>
		auto& voice_manager = this->getT(1);                 // envelope::voice_manager
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma); // cut -> pma::Add
		
		this->getParameterT(1).connectT(0, svf1); // res -> svf1::Q
		
		this->getParameterT(2).connectT(0, svf1); // type -> svf1::Mode
		
		this->getParameterT(3).connectT(0, pma); // envmod -> pma::Multiply
		
		this->getParameterT(6).connectT(0, ahdsr); // attack -> ahdsr::Attack
		
		this->getParameterT(7).connectT(0, ahdsr); // decay -> ahdsr::Decay
		
		this->getParameterT(8).connectT(0, ahdsr); // sustain -> ahdsr::Sustain
		
		this->getParameterT(9).connectT(0, ahdsr); // release -> ahdsr::Release
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma.getWrappedObject().getParameter().connectT(0, svf1); // pma -> svf1::Frequency
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, pma); // ahdsr -> pma::Value
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(1).connectT(0, voice_manager); // simple_ar -> voice_manager::KillVoice
		
		// Default Values --------------------------------------------------------------------------
		
		;                            // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 0.);  // envelope::ahdsr::Hold
		;                            // ahdsr::Decay is automated
		;                            // ahdsr::Sustain is automated
		;                            // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		ahdsr.setParameterT(8, 0.);  // envelope::ahdsr::Gate
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf1::Mode is automated
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		simple_ar.setParameterT(0, 0.); // envelope::simple_ar::Attack
		simple_ar.setParameterT(1, 0.); // envelope::simple_ar::Release
		simple_ar.setParameterT(2, 0.); // envelope::simple_ar::Gate
		simple_ar.setParameterT(3, 0.); // envelope::simple_ar::AttackCurve
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // voice_manager::KillVoice is automated
		
		this->setParameterT(0, 0.484996);
		this->setParameterT(1, 0.589729);
		this->setParameterT(2, 0.1);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.538563);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 76.2);
		this->setParameterT(8, 0.27378);
		this->setParameterT(9, 1.);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // filterB_impl::ahdsr_t<NV>
		this->getT(0).getT(1).getT(0).setExternalData(b, index);         // filterB_impl::simple_ar_t<NV>
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
using filterB = wrap::node<filterB_impl::instance<NV>>;
}


