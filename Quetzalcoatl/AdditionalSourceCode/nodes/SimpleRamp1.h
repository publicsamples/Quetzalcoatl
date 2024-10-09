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

namespace SimpleRamp1_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                    0, 
                                    pma_modRange>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<tempo_sync_t<NV>, 3>>;
template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<minmax_t<NV>, 0>>;

template <int NV>
using event_data_reader_mod = parameter::chain<ranges::Identity, 
                                               parameter::plain<pma_t<NV>, 0>, 
                                               parameter::plain<pma1_t<NV>, 0>>;

template <int NV>
using event_data_reader_t = wrap::mod<event_data_reader_mod<NV>, 
                                      routing::event_data_reader<NV>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, event_data_reader_t<NV>>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, pma_t<NV>>, 
                                 pma1_t<NV>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<541098268>;
using peak_mod = parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 
                                  0>;
using peak_t = wrap::mod<peak_mod, 
                         wrap::no_data<core::peak>>;

using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, peak_t>, 
                                 routing::global_cable<global_cable_t_index, parameter::empty>>;

using global_cable1_t_index = runtime_target::indexers::fix_hash<541098269>;
using peak1_mod = parameter::plain<routing::global_cable<global_cable1_t_index, parameter::empty>, 
                                   0>;
using peak1_t = wrap::mod<peak1_mod, 
                          wrap::no_data<core::peak>>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak1_t>, 
                                  routing::global_cable<global_cable1_t_index, parameter::empty>>;

using global_cable2_t_index = runtime_target::indexers::fix_hash<541098270>;
using peak2_mod = parameter::plain<routing::global_cable<global_cable2_t_index, parameter::empty>, 
                                   0>;
using peak2_t = wrap::mod<peak2_mod, 
                          wrap::no_data<core::peak>>;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak2_t>, 
                                  routing::global_cable<global_cable2_t_index, parameter::empty>>;

using global_cable3_t_index = runtime_target::indexers::fix_hash<541098271>;
using peak3_mod = parameter::plain<routing::global_cable<global_cable3_t_index, parameter::empty>, 
                                   0>;
using peak3_t = wrap::mod<peak3_mod, 
                          wrap::no_data<core::peak>>;

using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak3_t>, 
                                  routing::global_cable<global_cable3_t_index, parameter::empty>>;

using global_cable4_t_index = runtime_target::indexers::fix_hash<541098272>;
using peak4_mod = parameter::plain<routing::global_cable<global_cable4_t_index, parameter::empty>, 
                                   0>;
using peak4_t = wrap::mod<peak4_mod, 
                          wrap::no_data<core::peak>>;

using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak4_t>, 
                                  routing::global_cable<global_cable4_t_index, parameter::empty>>;

using global_cable5_t_index = runtime_target::indexers::fix_hash<541098273>;
using peak5_mod = parameter::plain<routing::global_cable<global_cable5_t_index, parameter::empty>, 
                                   0>;
using peak5_t = wrap::mod<peak5_mod, 
                          wrap::no_data<core::peak>>;

using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak5_t>, 
                                  routing::global_cable<global_cable5_t_index, parameter::empty>>;

using global_cable7_t_index = runtime_target::indexers::fix_hash<541098274>;
using peak7_mod = parameter::plain<routing::global_cable<global_cable7_t_index, parameter::empty>, 
                                   0>;
using peak7_t = wrap::mod<peak7_mod, 
                          wrap::no_data<core::peak>>;

using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak7_t>, 
                                  routing::global_cable<global_cable7_t_index, parameter::empty>>;

using global_cable6_t_index = runtime_target::indexers::fix_hash<541098275>;
using peak6_mod = parameter::plain<routing::global_cable<global_cable6_t_index, parameter::empty>, 
                                   0>;
using peak6_t = wrap::mod<peak6_mod, 
                          wrap::no_data<core::peak>>;

using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak6_t>, 
                                  routing::global_cable<global_cable6_t_index, parameter::empty>>;
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain_t>, 
                                   chain1_t, 
                                   chain2_t, 
                                   chain3_t, 
                                   chain4_t, 
                                   chain5_t, 
                                   chain7_t, 
                                   chain6_t>;

namespace SimpleRamp1_t_parameters
{
// Parameter list for SimpleRamp1_impl::SimpleRamp1_t ----------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Tempo_InputRange, 
                             0., 
                             18., 
                             1.);
DECLARE_PARAMETER_RANGE(Tempo_0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Tempo_0 = parameter::from0To1<SimpleRamp1_impl::pma_t<NV>, 
                                    2, 
                                    Tempo_0Range>;

template <int NV>
using Tempo = parameter::chain<Tempo_InputRange, Tempo_0<NV>>;

template <int NV>
using TempoMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<SimpleRamp1_impl::pma_t<NV>, 1>, 
                                  parameter::plain<SimpleRamp1_impl::pma1_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(TempoSrc_InputRange, 
                        0., 
                        16.);
DECLARE_PARAMETER_RANGE_STEP(TempoSrc_0Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using TempoSrc_0 = parameter::from0To1<SimpleRamp1_impl::event_data_reader_t<NV>, 
                                       0, 
                                       TempoSrc_0Range>;

template <int NV>
using TempoSrc = parameter::chain<TempoSrc_InputRange, TempoSrc_0<NV>>;

DECLARE_PARAMETER_RANGE(SpeedMS_InputRange, 
                        0., 
                        10000.);
template <int NV>
using SpeedMS_0 = parameter::from0To1<SimpleRamp1_impl::pma1_t<NV>, 
                                      2, 
                                      Tempo_0Range>;

template <int NV>
using SpeedMS = parameter::chain<SpeedMS_InputRange, SpeedMS_0<NV>>;

template <int NV>
using Divide = parameter::plain<SimpleRamp1_impl::tempo_sync_t<NV>, 
                                1>;
template <int NV>
using Sync = parameter::plain<SimpleRamp1_impl::tempo_sync_t<NV>, 
                              2>;
using OUTPUT = parameter::plain<SimpleRamp1_impl::branch_t, 
                                0>;
template <int NV>
using SimpleRamp1_t_plist = parameter::list<Tempo<NV>, 
                                            Divide<NV>, 
                                            Sync<NV>, 
                                            TempoMod<NV>, 
                                            TempoSrc<NV>, 
                                            SpeedMS<NV>, 
                                            OUTPUT>;
}

template <int NV>
using SimpleRamp1_t_ = container::chain<SimpleRamp1_t_parameters::SimpleRamp1_t_plist<NV>, 
                                        wrap::fix<1, midichain_t<NV>>, 
                                        split_t<NV>, 
                                        minmax_t<NV>, 
                                        tempo_sync_t<NV>, 
                                        ramp_t<NV>, 
                                        branch_t>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public SimpleRamp1_impl::SimpleRamp1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(SimpleRamp1);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(114)
		{
			0x005B, 0x0000, 0x5400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6944, 0x6976, 0x6564, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0002, 0x0000, 0x7953, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 
            0x0000, 0x6554, 0x706D, 0x4D6F, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0004, 0x0000, 0x6554, 0x706D, 0x536F, 0x6372, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0005, 0x0000, 0x7053, 0x6565, 0x4D64, 0x0053, 0x0000, 
            0x0000, 0x4000, 0x461C, 0x4855, 0x4581, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x065B, 0x0000, 0x4F00, 0x5455, 0x5550, 0x0054, 0x0000, 
            0x0000, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& midichain = this->getT(0);                     // SimpleRamp1_impl::midichain_t<NV>
		auto& event_data_reader = this->getT(0).getT(0);     // SimpleRamp1_impl::event_data_reader_t<NV>
		auto& split = this->getT(1);                         // SimpleRamp1_impl::split_t<NV>
		auto& pma = this->getT(1).getT(0);                   // SimpleRamp1_impl::pma_t<NV>
		auto& pma1 = this->getT(1).getT(1);                  // SimpleRamp1_impl::pma1_t<NV>
		auto& minmax = this->getT(2);                        // SimpleRamp1_impl::minmax_t<NV>
		auto& tempo_sync = this->getT(3);                    // SimpleRamp1_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(4);                          // SimpleRamp1_impl::ramp_t<NV>
		auto& branch = this->getT(5);                        // SimpleRamp1_impl::branch_t
		auto& chain = this->getT(5).getT(0);                 // SimpleRamp1_impl::chain_t
		auto& peak = this->getT(5).getT(0).getT(0);          // SimpleRamp1_impl::peak_t
		auto& global_cable = this->getT(5).getT(0).getT(1);  // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& chain1 = this->getT(5).getT(1);                // SimpleRamp1_impl::chain1_t
		auto& peak1 = this->getT(5).getT(1).getT(0);         // SimpleRamp1_impl::peak1_t
		auto& global_cable1 = this->getT(5).getT(1).getT(1); // routing::global_cable<global_cable1_t_index, parameter::empty>
		auto& chain2 = this->getT(5).getT(2);                // SimpleRamp1_impl::chain2_t
		auto& peak2 = this->getT(5).getT(2).getT(0);         // SimpleRamp1_impl::peak2_t
		auto& global_cable2 = this->getT(5).getT(2).getT(1); // routing::global_cable<global_cable2_t_index, parameter::empty>
		auto& chain3 = this->getT(5).getT(3);                // SimpleRamp1_impl::chain3_t
		auto& peak3 = this->getT(5).getT(3).getT(0);         // SimpleRamp1_impl::peak3_t
		auto& global_cable3 = this->getT(5).getT(3).getT(1); // routing::global_cable<global_cable3_t_index, parameter::empty>
		auto& chain4 = this->getT(5).getT(4);                // SimpleRamp1_impl::chain4_t
		auto& peak4 = this->getT(5).getT(4).getT(0);         // SimpleRamp1_impl::peak4_t
		auto& global_cable4 = this->getT(5).getT(4).getT(1); // routing::global_cable<global_cable4_t_index, parameter::empty>
		auto& chain5 = this->getT(5).getT(5);                // SimpleRamp1_impl::chain5_t
		auto& peak5 = this->getT(5).getT(5).getT(0);         // SimpleRamp1_impl::peak5_t
		auto& global_cable5 = this->getT(5).getT(5).getT(1); // routing::global_cable<global_cable5_t_index, parameter::empty>
		auto& chain7 = this->getT(5).getT(6);                // SimpleRamp1_impl::chain7_t
		auto& peak7 = this->getT(5).getT(6).getT(0);         // SimpleRamp1_impl::peak7_t
		auto& global_cable7 = this->getT(5).getT(6).getT(1); // routing::global_cable<global_cable7_t_index, parameter::empty>
		auto& chain6 = this->getT(5).getT(7);                // SimpleRamp1_impl::chain6_t
		auto& peak6 = this->getT(5).getT(7).getT(0);         // SimpleRamp1_impl::peak6_t
		auto& global_cable6 = this->getT(5).getT(7).getT(1); // routing::global_cable<global_cable6_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma); // Tempo -> pma::Add
		
		this->getParameterT(1).connectT(0, tempo_sync); // Divide -> tempo_sync::Multiplier
		
		this->getParameterT(2).connectT(0, tempo_sync); // Sync -> tempo_sync::Enabled
		
		auto& TempoMod_p = this->getParameterT(3);
		TempoMod_p.connectT(0, pma);  // TempoMod -> pma::Multiply
		TempoMod_p.connectT(1, pma1); // TempoMod -> pma1::Multiply
		
		this->getParameterT(4).connectT(0, event_data_reader); // TempoSrc -> event_data_reader::SlotIndex
		
		this->getParameterT(5).connectT(0, pma1); // SpeedMS -> pma1::Add
		
		this->getParameterT(6).connectT(0, branch); // OUTPUT -> branch::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		tempo_sync.getParameter().connectT(0, ramp);                      // tempo_sync -> ramp::PeriodTime
		pma.getWrappedObject().getParameter().connectT(0, tempo_sync);    // pma -> tempo_sync::Tempo
		minmax.getWrappedObject().getParameter().connectT(0, tempo_sync); // minmax -> tempo_sync::UnsyncedTime
		pma1.getWrappedObject().getParameter().connectT(0, minmax);       // pma1 -> minmax::Value
		event_data_reader.getParameter().connectT(0, pma);                // event_data_reader -> pma::Value
		event_data_reader.getParameter().connectT(1, pma1);               // event_data_reader -> pma1::Value
		peak.getParameter().connectT(0, global_cable);                    // peak -> global_cable::Value
		peak1.getParameter().connectT(0, global_cable1);                  // peak1 -> global_cable1::Value
		peak2.getParameter().connectT(0, global_cable2);                  // peak2 -> global_cable2::Value
		peak3.getParameter().connectT(0, global_cable3);                  // peak3 -> global_cable3::Value
		peak4.getParameter().connectT(0, global_cable4);                  // peak4 -> global_cable4::Value
		peak5.getParameter().connectT(0, global_cable5);                  // peak5 -> global_cable5::Value
		peak7.getParameter().connectT(0, global_cable7);                  // peak7 -> global_cable7::Value
		peak6.getParameter().connectT(0, global_cable6);                  // peak6 -> global_cable6::Value
		
		// Default Values --------------------------------------------------------------------------
		
		;                                       // event_data_reader::SlotIndex is automated
		event_data_reader.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                                // minmax::Value is automated
		minmax.setParameterT(1, 0.);     // control::minmax::Minimum
		minmax.setParameterT(2, 10000.); // control::minmax::Maximum
		minmax.setParameterT(3, 1.);     // control::minmax::Skew
		minmax.setParameterT(4, 0.);     // control::minmax::Step
		minmax.setParameterT(5, 1.);     // control::minmax::Polarity
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch::Index is automated
		
		; // global_cable::Value is automated
		
		; // global_cable1::Value is automated
		
		; // global_cable2::Value is automated
		
		; // global_cable3::Value is automated
		
		; // global_cable4::Value is automated
		
		; // global_cable5::Value is automated
		
		; // global_cable7::Value is automated
		
		; // global_cable6::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 4137.04);
		this->setParameterT(6, 1.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(5).getT(0).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(5).getT(1).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable1_t_index, parameter::empty>
		this->getT(5).getT(2).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable2_t_index, parameter::empty>
		this->getT(5).getT(3).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable3_t_index, parameter::empty>
		this->getT(5).getT(4).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable4_t_index, parameter::empty>
		this->getT(5).getT(5).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable5_t_index, parameter::empty>
		this->getT(5).getT(6).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable7_t_index, parameter::empty>
		this->getT(5).getT(7).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable6_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(4).setExternalData(b, index);                 // SimpleRamp1_impl::ramp_t<NV>
		this->getT(5).getT(0).getT(0).setExternalData(b, index); // SimpleRamp1_impl::peak_t
		this->getT(5).getT(1).getT(0).setExternalData(b, index); // SimpleRamp1_impl::peak1_t
		this->getT(5).getT(2).getT(0).setExternalData(b, index); // SimpleRamp1_impl::peak2_t
		this->getT(5).getT(3).getT(0).setExternalData(b, index); // SimpleRamp1_impl::peak3_t
		this->getT(5).getT(4).getT(0).setExternalData(b, index); // SimpleRamp1_impl::peak4_t
		this->getT(5).getT(5).getT(0).setExternalData(b, index); // SimpleRamp1_impl::peak5_t
		this->getT(5).getT(6).getT(0).setExternalData(b, index); // SimpleRamp1_impl::peak7_t
		this->getT(5).getT(7).getT(0).setExternalData(b, index); // SimpleRamp1_impl::peak6_t
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
using SimpleRamp1 = wrap::node<SimpleRamp1_impl::instance<NV>>;
}


