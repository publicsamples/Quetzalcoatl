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

namespace Mod3_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_pack_t<NV>, 0>, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, tempo_sync_t<NV>>, 
                                 ramp_t<NV>, 
                                 math::clear<NV>>;
using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, pack_resizer_t>, 
                                  cable_pack_t<NV>, 
                                  math::add<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using ahdsr_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                       parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;
template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<ahdsr_t<NV>, 8>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 1>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::add<NV>>, 
                                  math::rect<NV>, 
                                  peak1_t<NV>, 
                                  input_toggle_t<NV>, 
                                  math::clear<NV>, 
                                  ahdsr_t<NV>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain3_t<NV>>, 
                                   chain4_t<NV>, 
                                   chain5_t<NV>>;

template <int NV>
using peak_t = wrap::mod<parameter::plain<routing::event_data_writer<NV>, 1>, 
                         wrap::no_data<core::peak>>;

using ahdsr1_multimod = parameter::list<parameter::empty, 
                                        parameter::plain<envelope::voice_manager, 0>>;

template <int NV>
using ahdsr1_t = wrap::no_data<envelope::ahdsr<NV, ahdsr1_multimod>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, ahdsr1_t<NV>>, 
                                  envelope::voice_manager>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, chain_t<NV>>, 
                                     branch_t<NV>, 
                                     peak_t<NV>, 
                                     routing::event_data_writer<NV>, 
                                     chain1_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

namespace Mod3_t_parameters
{
// Parameter list for Mod3_impl::Mod3_t ------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(multi_InputRange, 
                             1., 
                             32., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(multi_0Range, 
                             1., 
                             32., 
                             1.);

template <int NV>
using multi_0 = parameter::from0To1<Mod3_impl::tempo_sync_t<NV>, 
                                    1, 
                                    multi_0Range>;

template <int NV>
using multi = parameter::chain<multi_InputRange, multi_0<NV>>;

DECLARE_PARAMETER_RANGE(packs_InputRange, 
                        5.55112e-17, 
                        16.);
DECLARE_PARAMETER_RANGE_STEP(packs_0Range, 
                             0., 
                             16., 
                             1.);

using packs_0 = parameter::from0To1<Mod3_impl::pack_resizer_t, 
                                    0, 
                                    packs_0Range>;

using packs = parameter::chain<packs_InputRange, packs_0>;

template <int NV>
using onshot = parameter::chain<ranges::Identity, 
                                parameter::plain<Mod3_impl::ramp_t<NV>, 1>, 
                                parameter::plain<Mod3_impl::input_toggle_t<NV>, 0>>;

template <int NV>
using tempo = parameter::plain<Mod3_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using type = parameter::plain<Mod3_impl::branch_t<NV>, 
                              0>;
template <int NV>
using a = parameter::plain<Mod3_impl::ahdsr_t<NV>, 0>;
template <int NV>
using d = parameter::plain<Mod3_impl::ahdsr_t<NV>, 3>;
template <int NV>
using s = parameter::plain<Mod3_impl::ahdsr_t<NV>, 4>;
template <int NV>
using r = parameter::plain<Mod3_impl::ahdsr_t<NV>, 5>;
template <int NV>
using h = parameter::plain<Mod3_impl::ahdsr_t<NV>, 2>;
template <int NV>
using crv = parameter::plain<Mod3_impl::ahdsr_t<NV>, 6>;
template <int NV>
using Mod3_t_plist = parameter::list<tempo<NV>, 
                                     multi<NV>, 
                                     packs, 
                                     type<NV>, 
                                     onshot<NV>, 
                                     a<NV>, 
                                     d<NV>, 
                                     s<NV>, 
                                     r<NV>, 
                                     h<NV>, 
                                     crv<NV>>;
}

template <int NV>
using Mod3_t_ = container::chain<Mod3_t_parameters::Mod3_t_plist<NV>, 
                                 wrap::fix<2, modchain_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Mod3_impl::Mod3_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Mod3);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(160)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x756D, 0x746C, 0x0069, 0x0000, 0x3F80, 0x0000, 
            0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 0x025B, 
            0x0000, 0x7000, 0x6361, 0x736B, 0x0000, 0x8000, 0x0024, 0x8000, 
            0x9841, 0x8B1E, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 
            0x0000, 0x7974, 0x6570, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 
            0x0000, 0x0000, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0004, 0x0000, 
            0x6E6F, 0x6873, 0x746F, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0005, 0x0000, 
            0x0061, 0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 0x42D6, 0x6A72, 
            0x3E4A, 0xCCCD, 0x3DCC, 0x065B, 0x0000, 0x6400, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0xB090, 0x7244, 0x4A6A, 0xCD3E, 0xCCCC, 
            0x5B3D, 0x0007, 0x0000, 0x0073, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 
            0x7200, 0x0000, 0x0000, 0x0000, 0x1C40, 0x0046, 0x8000, 0x723F, 
            0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x0009, 0x0000, 0x0068, 0x0000, 
            0x0000, 0x4000, 0x461C, 0x0000, 0x4060, 0x6A72, 0x3E4A, 0xCCCD, 
            0x3DCC, 0x0A5B, 0x0000, 0x6300, 0x7672, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                             // Mod3_impl::modchain_t<NV>
		auto& chain = this->getT(0).getT(0);                        // Mod3_impl::chain_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(0);           // Mod3_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(0).getT(0).getT(1);                 // Mod3_impl::ramp_t<NV>
		auto& clear = this->getT(0).getT(0).getT(2);                // math::clear<NV>
		auto& branch = this->getT(0).getT(1);                       // Mod3_impl::branch_t<NV>
		auto& chain3 = this->getT(0).getT(1).getT(0);               // Mod3_impl::chain3_t<NV>
		auto& pack_resizer = this->getT(0).getT(1).getT(0).getT(0); // Mod3_impl::pack_resizer_t
		auto& cable_pack = this->getT(0).getT(1).getT(0).getT(1);   // Mod3_impl::cable_pack_t<NV>
		auto& add1 = this->getT(0).getT(1).getT(0).getT(2);         // math::add<NV>
		auto& chain4 = this->getT(0).getT(1).getT(1);               // Mod3_impl::chain4_t<NV>
		auto& cable_table = this->getT(0).getT(1).getT(1).getT(0);  // Mod3_impl::cable_table_t<NV>
		auto& add2 = this->getT(0).getT(1).getT(1).getT(1);         // math::add<NV>
		auto& chain5 = this->getT(0).getT(1).getT(2);               // Mod3_impl::chain5_t<NV>
		auto& add4 = this->getT(0).getT(1).getT(2).getT(0);         // math::add<NV>
		auto& rect = this->getT(0).getT(1).getT(2).getT(1);         // math::rect<NV>
		auto& peak1 = this->getT(0).getT(1).getT(2).getT(2);        // Mod3_impl::peak1_t<NV>
		auto& input_toggle = this->getT(0).getT(1).getT(2).getT(3); // Mod3_impl::input_toggle_t<NV>
		auto& clear1 = this->getT(0).getT(1).getT(2).getT(4);       // math::clear<NV>
		auto& ahdsr = this->getT(0).getT(1).getT(2).getT(5);        // Mod3_impl::ahdsr_t<NV>
		auto& add3 = this->getT(0).getT(1).getT(2).getT(6);         // math::add<NV>
		auto& peak = this->getT(0).getT(2);                         // Mod3_impl::peak_t<NV>
		auto& event_data_writer = this->getT(0).getT(3);            // routing::event_data_writer<NV>
		auto& chain1 = this->getT(0).getT(4);                       // Mod3_impl::chain1_t<NV>
		auto& ahdsr1 = this->getT(0).getT(4).getT(0);               // Mod3_impl::ahdsr1_t<NV>
		auto& voice_manager = this->getT(0).getT(4).getT(1);        // envelope::voice_manager
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync); // multi -> tempo_sync::Multiplier
		
		this->getParameterT(2).connectT(0, pack_resizer); // packs -> pack_resizer::NumSliders
		
		this->getParameterT(3).connectT(0, branch); // type -> branch::Index
		
		auto& onshot_p = this->getParameterT(4);
		onshot_p.connectT(0, ramp);         // onshot -> ramp::LoopStart
		onshot_p.connectT(1, input_toggle); // onshot -> input_toggle::Input
		
		this->getParameterT(5).connectT(0, ahdsr); // a -> ahdsr::Attack
		
		this->getParameterT(6).connectT(0, ahdsr); // d -> ahdsr::Decay
		
		this->getParameterT(7).connectT(0, ahdsr); // s -> ahdsr::Sustain
		
		this->getParameterT(8).connectT(0, ahdsr); // r -> ahdsr::Release
		
		this->getParameterT(9).connectT(0, ahdsr); // h -> ahdsr::Hold
		
		this->getParameterT(10).connectT(0, ahdsr); // crv -> ahdsr::AttackCurve
		
		// Modulation Connections ------------------------------------------------------------------
		
		cable_pack.getWrappedObject().getParameter().connectT(0, add1);  // cable_pack -> add1::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add2); // cable_table -> add2::Value
		ramp.getParameter().connectT(0, cable_pack);                     // ramp -> cable_pack::Value
		ramp.getParameter().connectT(1, cable_table);                    // ramp -> cable_table::Value
		ramp.getParameter().connectT(2, add4);                           // ramp -> add4::Value
		tempo_sync.getParameter().connectT(0, ramp);                     // tempo_sync -> ramp::PeriodTime
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, add3);                        // ahdsr -> add3::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, ahdsr); // input_toggle -> ahdsr::Gate
		peak1.getParameter().connectT(0, input_toggle);                    // peak1 -> input_toggle::Value1
		peak.getParameter().connectT(0, event_data_writer);                // peak -> event_data_writer::Value
		auto& ahdsr1_p = ahdsr1.getWrappedObject().getParameter();
		ahdsr1_p.getParameterT(1).connectT(0, voice_manager); // ahdsr1 -> voice_manager::KillVoice
		
		// Default Values --------------------------------------------------------------------------
		
		;                                // tempo_sync::Tempo is automated
		;                                // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.); // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 0.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch::Index is automated
		
		; // pack_resizer::NumSliders is automated
		
		; // cable_pack::Value is automated
		
		; // add1::Value is automated
		
		; // cable_table::Value is automated
		
		; // add2::Value is automated
		
		; // add4::Value is automated
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		;                                  // input_toggle::Input is automated
		;                                  // input_toggle::Value1 is automated
		input_toggle.setParameterT(2, 1.); // control::input_toggle::Value2
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		;                           // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.); // envelope::ahdsr::AttackLevel
		;                           // ahdsr::Hold is automated
		;                           // ahdsr::Decay is automated
		;                           // ahdsr::Sustain is automated
		;                           // ahdsr::Release is automated
		;                           // ahdsr::AttackCurve is automated
		ahdsr.setParameterT(7, 0.); // envelope::ahdsr::Retrigger
		;                           // ahdsr::Gate is automated
		
		; // add3::Value is automated
		
		event_data_writer.setParameterT(0, 2.); // routing::event_data_writer::SlotIndex
		;                                       // event_data_writer::Value is automated
		
		ahdsr1.setParameterT(0, 0.);   // envelope::ahdsr::Attack
		ahdsr1.setParameterT(1, 1.);   // envelope::ahdsr::AttackLevel
		ahdsr1.setParameterT(2, 20.);  // envelope::ahdsr::Hold
		ahdsr1.setParameterT(3, 300.); // envelope::ahdsr::Decay
		ahdsr1.setParameterT(4, 0.5);  // envelope::ahdsr::Sustain
		ahdsr1.setParameterT(5, 20.);  // envelope::ahdsr::Release
		ahdsr1.setParameterT(6, 0.5);  // envelope::ahdsr::AttackCurve
		ahdsr1.setParameterT(7, 0.);   // envelope::ahdsr::Retrigger
		ahdsr1.setParameterT(8, 0.);   // envelope::ahdsr::Gate
		
		; // voice_manager::KillVoice is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 4.34748);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 107.);
		this->setParameterT(6, 1412.5);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 3.5);
		this->setParameterT(10, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).setExternalData(b, index);         // Mod3_impl::ramp_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).setExternalData(b, index); // Mod3_impl::pack_resizer_t
		this->getT(0).getT(1).getT(0).getT(1).setExternalData(b, index); // Mod3_impl::cable_pack_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).setExternalData(b, index); // Mod3_impl::cable_table_t<NV>
		this->getT(0).getT(1).getT(2).getT(2).setExternalData(b, index); // Mod3_impl::peak1_t<NV>
		this->getT(0).getT(1).getT(2).getT(5).setExternalData(b, index); // Mod3_impl::ahdsr_t<NV>
		this->getT(0).getT(2).setExternalData(b, index);                 // Mod3_impl::peak_t<NV>
		this->getT(0).getT(4).getT(0).setExternalData(b, index);         // Mod3_impl::ahdsr1_t<NV>
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
using Mod3 = wrap::node<Mod3_impl::instance<NV>>;
}


