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

namespace modtest2_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable40_t_index = runtime_target::indexers::fix_hash<3357039>;

template <int NV>
using global_cable40_t = routing::global_cable<global_cable40_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable40_t<NV>>, 
                                   math::add<NV>>;
using global_cable41_t_index = runtime_target::indexers::fix_hash<3357040>;

template <int NV>
using global_cable41_t = routing::global_cable<global_cable41_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable41_t<NV>>, 
                                   math::add<NV>>;
using global_cable42_t_index = runtime_target::indexers::fix_hash<3357041>;

template <int NV>
using global_cable42_t = routing::global_cable<global_cable42_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable42_t<NV>>, 
                                   math::add<NV>>;
using global_cable43_t_index = runtime_target::indexers::fix_hash<3357042>;

template <int NV>
using global_cable43_t = routing::global_cable<global_cable43_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable43_t<NV>>, 
                                   math::add<NV>>;
using global_cable44_t_index = runtime_target::indexers::fix_hash<3357043>;

template <int NV>
using global_cable44_t = routing::global_cable<global_cable44_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable44_t<NV>>, 
                                   math::add<NV>>;
using global_cable45_t_index = runtime_target::indexers::fix_hash<3357044>;

template <int NV>
using global_cable45_t = routing::global_cable<global_cable45_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable45_t<NV>>, 
                                   math::add<NV>>;
using global_cable46_t_index = runtime_target::indexers::fix_hash<3357045>;

template <int NV>
using global_cable46_t = routing::global_cable<global_cable46_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable46_t<NV>>, 
                                   math::add<NV>>;
using global_cable47_t_index = runtime_target::indexers::fix_hash<3357046>;

template <int NV>
using global_cable47_t = routing::global_cable<global_cable47_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable47_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain47_t<NV>>, 
                                    chain48_t<NV>, 
                                    chain49_t<NV>, 
                                    chain56_t<NV>, 
                                    chain57_t<NV>, 
                                    chain58_t<NV>, 
                                    chain61_t<NV>, 
                                    chain71_t<NV>>;

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma1_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma1_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                     0, 
                                     pma1_modRange>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma_modRange, 
                             0., 
                             10000., 
                             0.1);

template <int NV>
using pma_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                    3, 
                                    pma_modRange>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma1_t<NV>, 0>, 
                                  parameter::plain<pma_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<541098268>;
using peak3_mod = parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 
                                   0>;
using peak3_t = wrap::mod<peak3_mod, 
                          wrap::no_data<core::peak>>;

using chain13_t = container::chain<parameter::empty, wrap::fix<1, peak3_t>>;

using global_cable39_t_index = runtime_target::indexers::fix_hash<541098269>;
using peak9_mod = parameter::plain<routing::global_cable<global_cable39_t_index, parameter::empty>, 
                                   0>;
using peak9_t = wrap::mod<peak9_mod, 
                          wrap::no_data<core::peak>>;

using chain16_t = container::chain<parameter::empty, wrap::fix<1, peak9_t>>;

using global_cable38_t_index = runtime_target::indexers::fix_hash<541098270>;
using peak8_mod = parameter::plain<routing::global_cable<global_cable38_t_index, parameter::empty>, 
                                   0>;
using peak8_t = wrap::mod<peak8_mod, 
                          wrap::no_data<core::peak>>;

using chain24_t = container::chain<parameter::empty, wrap::fix<1, peak8_t>>;

using global_cable37_t_index = runtime_target::indexers::fix_hash<541098271>;
using peak7_mod = parameter::plain<routing::global_cable<global_cable37_t_index, parameter::empty>, 
                                   0>;
using peak7_t = wrap::mod<peak7_mod, 
                          wrap::no_data<core::peak>>;

using chain50_t = container::chain<parameter::empty, wrap::fix<1, peak7_t>>;

using global_cable36_t_index = runtime_target::indexers::fix_hash<541098272>;
using peak10_mod = parameter::plain<routing::global_cable<global_cable36_t_index, parameter::empty>, 
                                    0>;
using peak10_t = wrap::mod<peak10_mod, 
                           wrap::no_data<core::peak>>;

using chain51_t = container::chain<parameter::empty, wrap::fix<1, peak10_t>>;

using global_cable35_t_index = runtime_target::indexers::fix_hash<541098273>;
using peak11_mod = parameter::plain<routing::global_cable<global_cable35_t_index, parameter::empty>, 
                                    0>;
using peak11_t = wrap::mod<peak11_mod, 
                           wrap::no_data<core::peak>>;

using chain59_t = container::chain<parameter::empty, wrap::fix<1, peak11_t>>;

using global_cable18_t_index = runtime_target::indexers::fix_hash<541098274>;
using peak12_mod = parameter::plain<routing::global_cable<global_cable18_t_index, parameter::empty>, 
                                    0>;
using peak12_t = wrap::mod<peak12_mod, 
                           wrap::no_data<core::peak>>;

using chain60_t = container::chain<parameter::empty, wrap::fix<1, peak12_t>>;

using global_cable9_t_index = runtime_target::indexers::fix_hash<541098275>;
using peak13_mod = parameter::plain<routing::global_cable<global_cable9_t_index, parameter::empty>, 
                                    0>;
using peak13_t = wrap::mod<peak13_mod, 
                           wrap::no_data<core::peak>>;

using chain69_t = container::chain<parameter::empty, wrap::fix<1, peak13_t>>;
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain13_t>, 
                                    chain16_t, 
                                    chain24_t, 
                                    chain50_t, 
                                    chain51_t, 
                                    chain59_t, 
                                    chain60_t, 
                                    chain69_t>;

using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, routing::global_cable<global_cable_t_index, parameter::empty>>, 
                                 routing::global_cable<global_cable39_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable38_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable37_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable36_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable35_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable18_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable9_t_index, parameter::empty>>;

namespace modtest2_t_parameters
{
// Parameter list for modtest2_impl::modtest2_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE(Tempo_InputRange, 
                        0., 
                        18.);
DECLARE_PARAMETER_RANGE(Tempo_0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Tempo_0 = parameter::from0To1<modtest2_impl::pma1_t<NV>, 
                                    2, 
                                    Tempo_0Range>;

template <int NV>
using Tempo = parameter::chain<Tempo_InputRange, Tempo_0<NV>>;

template <int NV>
using TempoMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<modtest2_impl::pma1_t<NV>, 1>, 
                                  parameter::plain<modtest2_impl::pma_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(TempoSrc_InputRange, 
                        0., 
                        8.);
DECLARE_PARAMETER_RANGE_STEP(TempoSrc_0Range, 
                             0., 
                             7., 
                             1.);

template <int NV>
using TempoSrc_0 = parameter::from0To1<modtest2_impl::branch4_t<NV>, 
                                       0, 
                                       TempoSrc_0Range>;

template <int NV>
using TempoSrc = parameter::chain<TempoSrc_InputRange, TempoSrc_0<NV>>;

DECLARE_PARAMETER_RANGE(SpeedMsRange, 
                        5.55112e-17, 
                        10000.);

template <int NV>
using SpeedMs = parameter::from0To1<modtest2_impl::pma_t<NV>, 
                                    2, 
                                    SpeedMsRange>;

template <int NV>
using Div = parameter::plain<modtest2_impl::tempo_sync_t<NV>, 
                             1>;
using OUTPUT = parameter::plain<modtest2_impl::branch2_t, 
                                0>;
template <int NV>
using Sync = parameter::plain<modtest2_impl::tempo_sync_t<NV>, 
                              2>;
template <int NV>
using modtest2_t_plist = parameter::list<Tempo<NV>, 
                                         TempoMod<NV>, 
                                         TempoSrc<NV>, 
                                         Div<NV>, 
                                         OUTPUT, 
                                         SpeedMs<NV>, 
                                         Sync<NV>>;
}

template <int NV>
using modtest2_t_ = container::chain<modtest2_t_parameters::modtest2_t_plist<NV>, 
                                     wrap::fix<1, math::clear<NV>>, 
                                     math::clear<NV>, 
                                     branch4_t<NV>, 
                                     peak_t<NV>, 
                                     math::clear<NV>, 
                                     pma_t<NV>, 
                                     pma1_t<NV>, 
                                     tempo_sync_t<NV>, 
                                     ramp_t<NV>, 
                                     branch2_t, 
                                     split_t>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public modtest2_impl::modtest2_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(modtest2);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(112)
		{
			0x005B, 0x0000, 0x5400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6554, 0x706D, 0x4D6F, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x253F, 0xF306, 0x003A, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0002, 0x0000, 0x6554, 0x706D, 0x536F, 0x6372, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0003, 0x0000, 0x6944, 0x0076, 0x0000, 0x3F80, 
            0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x045B, 0x0000, 0x4F00, 0x5455, 0x5550, 0x0054, 0x0000, 0x0000, 
            0x0000, 0x40E0, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x055B, 0x0000, 0x5300, 0x6570, 0x6465, 0x734D, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0006, 0x0000, 0x7953, 0x636E, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& clear6 = this->getT(0);                         // math::clear<NV>
		auto& clear2 = this->getT(1);                         // math::clear<NV>
		auto& branch4 = this->getT(2);                        // modtest2_impl::branch4_t<NV>
		auto& chain47 = this->getT(2).getT(0);                // modtest2_impl::chain47_t<NV>
		auto& global_cable40 = this->getT(2).getT(0).getT(0); // modtest2_impl::global_cable40_t<NV>
		auto& add37 = this->getT(2).getT(0).getT(1);          // math::add<NV>
		auto& chain48 = this->getT(2).getT(1);                // modtest2_impl::chain48_t<NV>
		auto& global_cable41 = this->getT(2).getT(1).getT(0); // modtest2_impl::global_cable41_t<NV>
		auto& add38 = this->getT(2).getT(1).getT(1);          // math::add<NV>
		auto& chain49 = this->getT(2).getT(2);                // modtest2_impl::chain49_t<NV>
		auto& global_cable42 = this->getT(2).getT(2).getT(0); // modtest2_impl::global_cable42_t<NV>
		auto& add39 = this->getT(2).getT(2).getT(1);          // math::add<NV>
		auto& chain56 = this->getT(2).getT(3);                // modtest2_impl::chain56_t<NV>
		auto& global_cable43 = this->getT(2).getT(3).getT(0); // modtest2_impl::global_cable43_t<NV>
		auto& add40 = this->getT(2).getT(3).getT(1);          // math::add<NV>
		auto& chain57 = this->getT(2).getT(4);                // modtest2_impl::chain57_t<NV>
		auto& global_cable44 = this->getT(2).getT(4).getT(0); // modtest2_impl::global_cable44_t<NV>
		auto& add41 = this->getT(2).getT(4).getT(1);          // math::add<NV>
		auto& chain58 = this->getT(2).getT(5);                // modtest2_impl::chain58_t<NV>
		auto& global_cable45 = this->getT(2).getT(5).getT(0); // modtest2_impl::global_cable45_t<NV>
		auto& add42 = this->getT(2).getT(5).getT(1);          // math::add<NV>
		auto& chain61 = this->getT(2).getT(6);                // modtest2_impl::chain61_t<NV>
		auto& global_cable46 = this->getT(2).getT(6).getT(0); // modtest2_impl::global_cable46_t<NV>
		auto& add43 = this->getT(2).getT(6).getT(1);          // math::add<NV>
		auto& chain71 = this->getT(2).getT(7);                // modtest2_impl::chain71_t<NV>
		auto& global_cable47 = this->getT(2).getT(7).getT(0); // modtest2_impl::global_cable47_t<NV>
		auto& add44 = this->getT(2).getT(7).getT(1);          // math::add<NV>
		auto& peak = this->getT(3);                           // modtest2_impl::peak_t<NV>
		auto& clear = this->getT(4);                          // math::clear<NV>
		auto& pma = this->getT(5);                            // modtest2_impl::pma_t<NV>
		auto& pma1 = this->getT(6);                           // modtest2_impl::pma1_t<NV>
		auto& tempo_sync = this->getT(7);                     // modtest2_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(8);                           // modtest2_impl::ramp_t<NV>
		auto& branch2 = this->getT(9);                        // modtest2_impl::branch2_t
		auto& chain13 = this->getT(9).getT(0);                // modtest2_impl::chain13_t
		auto& peak3 = this->getT(9).getT(0).getT(0);          // modtest2_impl::peak3_t
		auto& chain16 = this->getT(9).getT(1);                // modtest2_impl::chain16_t
		auto& peak9 = this->getT(9).getT(1).getT(0);          // modtest2_impl::peak9_t
		auto& chain24 = this->getT(9).getT(2);                // modtest2_impl::chain24_t
		auto& peak8 = this->getT(9).getT(2).getT(0);          // modtest2_impl::peak8_t
		auto& chain50 = this->getT(9).getT(3);                // modtest2_impl::chain50_t
		auto& peak7 = this->getT(9).getT(3).getT(0);          // modtest2_impl::peak7_t
		auto& chain51 = this->getT(9).getT(4);                // modtest2_impl::chain51_t
		auto& peak10 = this->getT(9).getT(4).getT(0);         // modtest2_impl::peak10_t
		auto& chain59 = this->getT(9).getT(5);                // modtest2_impl::chain59_t
		auto& peak11 = this->getT(9).getT(5).getT(0);         // modtest2_impl::peak11_t
		auto& chain60 = this->getT(9).getT(6);                // modtest2_impl::chain60_t
		auto& peak12 = this->getT(9).getT(6).getT(0);         // modtest2_impl::peak12_t
		auto& chain69 = this->getT(9).getT(7);                // modtest2_impl::chain69_t
		auto& peak13 = this->getT(9).getT(7).getT(0);         // modtest2_impl::peak13_t
		auto& split = this->getT(10);                         // modtest2_impl::split_t
		auto& global_cable = this->getT(10).getT(0);          // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& global_cable39 = this->getT(10).getT(1);        // routing::global_cable<global_cable39_t_index, parameter::empty>
		auto& global_cable38 = this->getT(10).getT(2);        // routing::global_cable<global_cable38_t_index, parameter::empty>
		auto& global_cable37 = this->getT(10).getT(3);        // routing::global_cable<global_cable37_t_index, parameter::empty>
		auto& global_cable36 = this->getT(10).getT(4);        // routing::global_cable<global_cable36_t_index, parameter::empty>
		auto& global_cable35 = this->getT(10).getT(5);        // routing::global_cable<global_cable35_t_index, parameter::empty>
		auto& global_cable18 = this->getT(10).getT(6);        // routing::global_cable<global_cable18_t_index, parameter::empty>
		auto& global_cable9 = this->getT(10).getT(7);         // routing::global_cable<global_cable9_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Tempo -> pma1::Add
		
		auto& TempoMod_p = this->getParameterT(1);
		TempoMod_p.connectT(0, pma1); // TempoMod -> pma1::Multiply
		TempoMod_p.connectT(1, pma);  // TempoMod -> pma::Multiply
		
		this->getParameterT(2).connectT(0, branch4); // TempoSrc -> branch4::Index
		
		this->getParameterT(3).connectT(0, tempo_sync); // Div -> tempo_sync::Multiplier
		
		this->getParameterT(4).connectT(0, branch2); // OUTPUT -> branch2::Index
		
		this->getParameterT(5).connectT(0, pma); // SpeedMs -> pma::Add
		
		this->getParameterT(6).connectT(0, tempo_sync); // Sync -> tempo_sync::Enabled
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable40.getWrappedObject().getParameter().connectT(0, add37); // global_cable40 -> add37::Value
		global_cable41.getWrappedObject().getParameter().connectT(0, add38); // global_cable41 -> add38::Value
		global_cable42.getWrappedObject().getParameter().connectT(0, add39); // global_cable42 -> add39::Value
		global_cable43.getWrappedObject().getParameter().connectT(0, add40); // global_cable43 -> add40::Value
		global_cable44.getWrappedObject().getParameter().connectT(0, add41); // global_cable44 -> add41::Value
		global_cable45.getWrappedObject().getParameter().connectT(0, add42); // global_cable45 -> add42::Value
		global_cable46.getWrappedObject().getParameter().connectT(0, add43); // global_cable46 -> add43::Value
		global_cable47.getWrappedObject().getParameter().connectT(0, add44); // global_cable47 -> add44::Value
		tempo_sync.getParameter().connectT(0, ramp);                         // tempo_sync -> ramp::PeriodTime
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync);      // pma1 -> tempo_sync::Tempo
		pma.getWrappedObject().getParameter().connectT(0, tempo_sync);       // pma -> tempo_sync::UnsyncedTime
		peak.getParameter().connectT(0, pma1);                               // peak -> pma1::Value
		peak.getParameter().connectT(1, pma);                                // peak -> pma::Value
		peak3.getParameter().connectT(0, global_cable);                      // peak3 -> global_cable::Value
		peak9.getParameter().connectT(0, global_cable39);                    // peak9 -> global_cable39::Value
		peak8.getParameter().connectT(0, global_cable38);                    // peak8 -> global_cable38::Value
		peak7.getParameter().connectT(0, global_cable37);                    // peak7 -> global_cable37::Value
		peak10.getParameter().connectT(0, global_cable36);                   // peak10 -> global_cable36::Value
		peak11.getParameter().connectT(0, global_cable35);                   // peak11 -> global_cable35::Value
		peak12.getParameter().connectT(0, global_cable18);                   // peak12 -> global_cable18::Value
		peak13.getParameter().connectT(0, global_cable9);                    // peak13 -> global_cable9::Value
		
		// Default Values --------------------------------------------------------------------------
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // branch4::Index is automated
		
		global_cable40.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add37::Value is automated
		
		global_cable41.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add38::Value is automated
		
		global_cable42.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add39::Value is automated
		
		global_cable43.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add40::Value is automated
		
		global_cable44.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add41::Value is automated
		
		global_cable45.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add42::Value is automated
		
		global_cable46.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add43::Value is automated
		
		global_cable47.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add44::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch2::Index is automated
		
		; // global_cable::Value is automated
		
		; // global_cable39::Value is automated
		
		; // global_cable38::Value is automated
		
		; // global_cable37::Value is automated
		
		; // global_cable36::Value is automated
		
		; // global_cable35::Value is automated
		
		; // global_cable18::Value is automated
		
		; // global_cable9::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.00185413);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 1.);
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
		
		this->getT(2).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // modtest2_impl::global_cable40_t<NV>
		this->getT(2).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // modtest2_impl::global_cable41_t<NV>
		this->getT(2).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // modtest2_impl::global_cable42_t<NV>
		this->getT(2).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // modtest2_impl::global_cable43_t<NV>
		this->getT(2).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // modtest2_impl::global_cable44_t<NV>
		this->getT(2).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // modtest2_impl::global_cable45_t<NV>
		this->getT(2).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // modtest2_impl::global_cable46_t<NV>
		this->getT(2).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // modtest2_impl::global_cable47_t<NV>
		this->getT(10).getT(0).connectToRuntimeTarget(addConnection, c);        // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(10).getT(1).connectToRuntimeTarget(addConnection, c);        // routing::global_cable<global_cable39_t_index, parameter::empty>
		this->getT(10).getT(2).connectToRuntimeTarget(addConnection, c);        // routing::global_cable<global_cable38_t_index, parameter::empty>
		this->getT(10).getT(3).connectToRuntimeTarget(addConnection, c);        // routing::global_cable<global_cable37_t_index, parameter::empty>
		this->getT(10).getT(4).connectToRuntimeTarget(addConnection, c);        // routing::global_cable<global_cable36_t_index, parameter::empty>
		this->getT(10).getT(5).connectToRuntimeTarget(addConnection, c);        // routing::global_cable<global_cable35_t_index, parameter::empty>
		this->getT(10).getT(6).connectToRuntimeTarget(addConnection, c);        // routing::global_cable<global_cable18_t_index, parameter::empty>
		this->getT(10).getT(7).connectToRuntimeTarget(addConnection, c);        // routing::global_cable<global_cable9_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(3).setExternalData(b, index);                 // modtest2_impl::peak_t<NV>
		this->getT(8).setExternalData(b, index);                 // modtest2_impl::ramp_t<NV>
		this->getT(9).getT(0).getT(0).setExternalData(b, index); // modtest2_impl::peak3_t
		this->getT(9).getT(1).getT(0).setExternalData(b, index); // modtest2_impl::peak9_t
		this->getT(9).getT(2).getT(0).setExternalData(b, index); // modtest2_impl::peak8_t
		this->getT(9).getT(3).getT(0).setExternalData(b, index); // modtest2_impl::peak7_t
		this->getT(9).getT(4).getT(0).setExternalData(b, index); // modtest2_impl::peak10_t
		this->getT(9).getT(5).getT(0).setExternalData(b, index); // modtest2_impl::peak11_t
		this->getT(9).getT(6).getT(0).setExternalData(b, index); // modtest2_impl::peak12_t
		this->getT(9).getT(7).getT(0).setExternalData(b, index); // modtest2_impl::peak13_t
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
using modtest2 = wrap::node<modtest2_impl::instance<NV>>;
}


