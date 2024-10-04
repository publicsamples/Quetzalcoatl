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

namespace PolyMod_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;

template <int NV>
using tempo_sync1_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<ramp_t<NV>, 0>, 
                                         parameter::plain<fx::sampleandhold<NV>, 0>>;

template <int NV>
using tempo_sync1_t = wrap::mod<tempo_sync1_mod<NV>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma1_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma1_mod = parameter::from0To1<tempo_sync1_t<NV>, 
                                     0, 
                                     pma1_modRange>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<tempo_sync1_t<NV>, 3>>;
template <int NV>
using pma3_t = control::pma<NV, 
                            parameter::plain<minmax_t<NV>, 0>>;

template <int NV>
using event_data_reader1_mod = parameter::chain<ranges::Identity, 
                                                parameter::plain<pma1_t<NV>, 0>, 
                                                parameter::plain<pma3_t<NV>, 0>>;

template <int NV>
using event_data_reader1_t = wrap::mod<event_data_reader1_mod<NV>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, pma1_t<NV>>, 
                                 pma3_t<NV>>;
using global_cable_t_index = runtime_target::indexers::fix_hash<541098268>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable_t<NV>>, 
                                  math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<541098269>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<541098270>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<541098271>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<541098272>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   math::add<NV>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<541098273>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable5_t<NV>>, 
                                   math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<541098274>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<541098275>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain6_t<NV>>, 
                                    chain9_t<NV>, 
                                    chain7_t<NV>, 
                                    chain10_t<NV>, 
                                    chain11_t<NV>, 
                                    chain12_t<NV>, 
                                    chain13_t<NV>, 
                                    chain14_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, branch3_t<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, ramp_t<NV>>>;

template <int NV>
using event_data_reader_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                      routing::event_data_reader<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, event_data_reader_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain2_t<NV>>, 
                                   chain3_t<NV>, 
                                   chain4_t<NV>>;

namespace custom
{

struct expr7
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 2.0 * value * Math.PI) * (1 - Math.PI);
		;
	}
};
}

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;
using cable_pack_t = wrap::data<control::cable_pack<parameter::empty>, 
                                data::external::sliderpack<0>>;

using ahdsr_multimod = parameter::list<parameter::empty, parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod>>;
template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<ahdsr_t<NV>, 8>>;

template <int NV>
using peak1_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::expr<NV, custom::expr7>, 0>, 
                                   parameter::plain<cable_table_t<NV>, 0>, 
                                   parameter::plain<cable_pack_t, 0>, 
                                   parameter::plain<input_toggle_t<NV>, 2>>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ahdsr_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using tempo_sync4_t = wrap::mod<parameter::plain<ahdsr_t<NV>, 2>, 
                                control::tempo_sync<NV>>;

template <int NV>
using tempo_sync3_t = wrap::mod<parameter::plain<ahdsr_t<NV>, 3>, 
                                control::tempo_sync<NV>>;

template <int NV>
using tempo_sync5_t = wrap::mod<parameter::plain<ahdsr_t<NV>, 5>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, tempo_sync_t<NV>>, 
                                 tempo_sync4_t<NV>, 
                                 tempo_sync3_t<NV>, 
                                 tempo_sync5_t<NV>, 
                                 input_toggle_t<NV>, 
                                 ahdsr_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::pi<NV>>, 
                                   math::sin<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::rect<NV>>>;

using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;
using peak5_t = wrap::no_data<core::peak>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, wrap::no_process<math::clear<NV>>>, 
                                   math::expr<NV, custom::expr7>, 
                                   math::sig2mod<NV>, 
                                   peak5_t>;
template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, oscillator_t<NV>>, 
                                   wrap::no_process<math::pi<NV>>, 
                                   fx::sampleandhold<NV>, 
                                   math::sig2mod<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_table_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_pack_t, 
                                   math::add<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain_t<NV>>, 
                                    chain23_t<NV>, 
                                    chain8_t<NV>, 
                                    chain5_t, 
                                    chain41_t<NV>, 
                                    chain32_t<NV>, 
                                    chain20_t<NV>, 
                                    chain26_t<NV>>;
using peak_t = wrap::data<core::peak, 
                          data::external::displaybuffer<0>>;

namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 24.0 * value * input) * (2 - Math.PI);;
	}
};
}

namespace custom
{

struct expr5
{
	static float op(float input, float value)
	{
		return input * Math.asin(Math.PI * 1.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr8
{
	static float op(float input, float value)
	{
		return input * Math.cos(Math.PI * 12.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr9
{
	static float op(float input, float value)
	{
		return input * Math.log(Math.PI * 1.0 * value * input) * (1 - Math.PI);;
	}
};
}

DECLARE_PARAMETER_RANGE(pma_mod_0Range, 
                        0.01, 
                        1.);

template <int NV>
using pma_mod_0 = parameter::from0To1<math::expr<NV, custom::expr3>, 
                                      0, 
                                      pma_mod_0Range>;

DECLARE_PARAMETER_RANGE(pma_mod_1Range, 
                        0.02, 
                        1.);

template <int NV>
using pma_mod_1 = parameter::from0To1<math::expr<NV, custom::expr5>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 pma_mod_1<NV>, 
                                 parameter::plain<math::expr<NV, custom::expr8>, 0>, 
                                 parameter::plain<math::expr<NV, custom::expr9>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using event_data_reader2_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

using chain1_t = chain5_t;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr3>>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr5>>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr8>>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr9>>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain1_t>, 
                                    chain29_t<NV>, 
                                    chain35_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>>;

template <int NV>
using peak2_t = wrap::mod<parameter::plain<routing::event_data_writer<NV>, 1>, 
                          wrap::data<core::peak, data::external::displaybuffer<1>>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch1_t<NV>>, 
                                   peak_t, 
                                   event_data_reader2_t<NV>, 
                                   pma_t<NV>, 
                                   branch2_t<NV>, 
                                   peak2_t<NV>, 
                                   routing::event_data_writer<NV>, 
                                   wrap::no_process<math::clear<NV>>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, event_data_reader1_t<NV>>, 
                                     split_t<NV>, 
                                     minmax_t<NV>, 
                                     tempo_sync1_t<NV>, 
                                     branch_t<NV>, 
                                     peak1_t<NV>, 
                                     chain47_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

namespace PolyMod_t_parameters
{
// Parameter list for PolyMod_impl::PolyMod_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Tempo_InputRange, 
                             0., 
                             18., 
                             1.);
DECLARE_PARAMETER_RANGE(Tempo_0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Tempo_0 = parameter::from0To1<PolyMod_impl::pma1_t<NV>, 
                                    2, 
                                    Tempo_0Range>;

template <int NV>
using Tempo = parameter::chain<Tempo_InputRange, Tempo_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(DivideRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using Divide = parameter::from0To1<PolyMod_impl::tempo_sync1_t<NV>, 
                                   1, 
                                   DivideRange>;

template <int NV>
using TempoMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<PolyMod_impl::pma1_t<NV>, 1>, 
                                  parameter::plain<PolyMod_impl::pma3_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(TempoSrc_InputRange, 
                        0., 
                        167.);
DECLARE_PARAMETER_RANGE_STEP(TempoSrc_0Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using TempoSrc_0 = parameter::from0To1<PolyMod_impl::event_data_reader1_t<NV>, 
                                       0, 
                                       TempoSrc_0Range>;

template <int NV>
using TempoSrc = parameter::chain<TempoSrc_InputRange, TempoSrc_0<NV>>;

DECLARE_PARAMETER_RANGE(SpeedMS_InputRange, 
                        0., 
                        10000.);
template <int NV>
using SpeedMS_0 = parameter::from0To1<PolyMod_impl::pma3_t<NV>, 
                                      2, 
                                      Tempo_0Range>;

template <int NV>
using SpeedMS = parameter::chain<SpeedMS_InputRange, SpeedMS_0<NV>>;

DECLARE_PARAMETER_RANGE(Shape_InputRange, 
                        0., 
                        8.);
DECLARE_PARAMETER_RANGE_STEP(Shape_0Range, 
                             0., 
                             7., 
                             1.);

template <int NV>
using Shape_0 = parameter::from0To1<PolyMod_impl::branch1_t<NV>, 
                                    0, 
                                    Shape_0Range>;

template <int NV>
using Shape = parameter::chain<Shape_InputRange, Shape_0<NV>>;

template <int NV>
using a_0 = parameter::from0To1<PolyMod_impl::tempo_sync_t<NV>, 
                                0, 
                                PolyMod_impl::pma1_modRange>;

DECLARE_PARAMETER_RANGE_STEP(a_1Range, 
                             0., 
                             10000., 
                             0.1);

template <int NV>
using a_1 = parameter::from0To1<PolyMod_impl::tempo_sync_t<NV>, 
                                3, 
                                a_1Range>;

template <int NV>
using a = parameter::chain<ranges::Identity, 
                           a_0<NV>, 
                           a_1<NV>>;

template <int NV>
using h_0 = parameter::from0To1<PolyMod_impl::tempo_sync4_t<NV>, 
                                0, 
                                PolyMod_impl::pma1_modRange>;

template <int NV>
using h_1 = parameter::from0To1<PolyMod_impl::tempo_sync4_t<NV>, 
                                3, 
                                a_1Range>;

template <int NV>
using h = parameter::chain<ranges::Identity, 
                           h_0<NV>, 
                           h_1<NV>>;

template <int NV>
using d_0 = parameter::from0To1<PolyMod_impl::tempo_sync3_t<NV>, 
                                0, 
                                PolyMod_impl::pma1_modRange>;

template <int NV>
using d_1 = parameter::from0To1<PolyMod_impl::tempo_sync3_t<NV>, 
                                3, 
                                a_1Range>;

template <int NV>
using d = parameter::chain<ranges::Identity, 
                           d_0<NV>, 
                           d_1<NV>>;

template <int NV>
using r_0 = parameter::from0To1<PolyMod_impl::tempo_sync5_t<NV>, 
                                0, 
                                PolyMod_impl::pma1_modRange>;

template <int NV>
using r_1 = parameter::from0To1<PolyMod_impl::tempo_sync5_t<NV>, 
                                3, 
                                a_1Range>;

template <int NV>
using r = parameter::chain<ranges::Identity, 
                           r_0<NV>, 
                           r_1<NV>>;

template <int NV>
using EnvSync = parameter::chain<ranges::Identity, 
                                 parameter::plain<PolyMod_impl::tempo_sync_t<NV>, 2>, 
                                 parameter::plain<PolyMod_impl::tempo_sync4_t<NV>, 2>, 
                                 parameter::plain<PolyMod_impl::tempo_sync3_t<NV>, 2>, 
                                 parameter::plain<PolyMod_impl::tempo_sync5_t<NV>, 2>>;

template <int NV>
using EnvDiv = parameter::chain<ranges::Identity, 
                                parameter::plain<PolyMod_impl::tempo_sync_t<NV>, 1>, 
                                parameter::plain<PolyMod_impl::tempo_sync4_t<NV>, 1>, 
                                parameter::plain<PolyMod_impl::tempo_sync3_t<NV>, 1>, 
                                parameter::plain<PolyMod_impl::tempo_sync5_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(TrigMode_InputRange, 
                        0., 
                        2.);
DECLARE_PARAMETER_RANGE_STEP(TrigMode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using TrigMode_0 = parameter::from0To1<PolyMod_impl::branch_t<NV>, 
                                       0, 
                                       TrigMode_0Range>;

template <int NV>
using TrigMode = parameter::chain<TrigMode_InputRange, TrigMode_0<NV>>;

DECLARE_PARAMETER_RANGE(ModTrigSrc_InputRange, 
                        0., 
                        16.);
template <int NV>
using ModTrigSrc_0 = parameter::from0To1<PolyMod_impl::event_data_reader_t<NV>, 
                                         0, 
                                         TempoSrc_0Range>;

template <int NV>
using ModTrigSrc = parameter::chain<ModTrigSrc_InputRange, ModTrigSrc_0<NV>>;

DECLARE_PARAMETER_RANGE(Modifier_InputRange, 
                        0., 
                        4.);
DECLARE_PARAMETER_RANGE_STEP(Modifier_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using Modifier_0 = parameter::from0To1<PolyMod_impl::branch2_t<NV>, 
                                       0, 
                                       Modifier_0Range>;

template <int NV>
using Modifier = parameter::chain<Modifier_InputRange, Modifier_0<NV>>;

template <int NV>
using ModiferAdjust = parameter::from0To1<PolyMod_impl::pma_t<NV>, 
                                          2, 
                                          Tempo_0Range>;

DECLARE_PARAMETER_RANGE(ModiferAdjustSrc_InputRange, 
                        0., 
                        16.);
template <int NV>
using ModiferAdjustSrc_0 = parameter::from0To1<PolyMod_impl::event_data_reader2_t<NV>, 
                                               0, 
                                               TempoSrc_0Range>;

template <int NV>
using ModiferAdjustSrc = parameter::chain<ModiferAdjustSrc_InputRange, 
                                          ModiferAdjustSrc_0<NV>>;

template <int NV>
using Sync = parameter::plain<PolyMod_impl::tempo_sync1_t<NV>, 
                              2>;
template <int NV>
using s = parameter::plain<PolyMod_impl::ahdsr_t<NV>, 
                           4>;
template <int NV>
using EnvTrig = parameter::plain<PolyMod_impl::input_toggle_t<NV>, 
                                 0>;
template <int NV>
using OneShot = parameter::plain<PolyMod_impl::ramp_t<NV>, 
                                 1>;
template <int NV>
using ModiferAdjustMod = parameter::plain<PolyMod_impl::pma_t<NV>, 
                                          1>;
template <int NV>
using OUTPUT = parameter::plain<routing::event_data_writer<NV>, 
                                0>;
template <int NV>
using MonoRampInput = parameter::plain<PolyMod_impl::branch3_t<NV>, 
                                       0>;
template <int NV>
using PolyMod_t_plist = parameter::list<Tempo<NV>, 
                                        Divide<NV>, 
                                        TempoMod<NV>, 
                                        TempoSrc<NV>, 
                                        Sync<NV>, 
                                        SpeedMS<NV>, 
                                        Shape<NV>, 
                                        a<NV>, 
                                        h<NV>, 
                                        d<NV>, 
                                        s<NV>, 
                                        r<NV>, 
                                        EnvSync<NV>, 
                                        EnvDiv<NV>, 
                                        EnvTrig<NV>, 
                                        TrigMode<NV>, 
                                        ModTrigSrc<NV>, 
                                        OneShot<NV>, 
                                        Modifier<NV>, 
                                        ModiferAdjust<NV>, 
                                        ModiferAdjustMod<NV>, 
                                        ModiferAdjustSrc<NV>, 
                                        OUTPUT<NV>, 
                                        MonoRampInput<NV>>;
}

template <int NV>
using PolyMod_t_ = container::chain<PolyMod_t_parameters::PolyMod_t_plist<NV>, 
                                    wrap::fix<2, modchain_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public PolyMod_impl::PolyMod_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 2;
		
		SNEX_METADATA_ID(PolyMod);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(396)
		{
			0x005B, 0x0000, 0x5400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x4000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6944, 0x6976, 0x6564, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0002, 0x0000, 0x6554, 0x706D, 0x4D6F, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0003, 0x0000, 0x6554, 0x706D, 0x536F, 0x6372, 0x0000, 
            0x0000, 0x0000, 0x2700, 0x0043, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0004, 0x0000, 0x7953, 0x636E, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0005, 0x0000, 0x7053, 0x6565, 0x4D64, 0x0053, 0x0000, 
            0x0000, 0x4000, 0x461C, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x065B, 0x0000, 0x5300, 0x6168, 0x6570, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0007, 0x0000, 0x0061, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 
            0x6800, 0x0000, 0x0000, 0x0000, 0x8000, 0x793F, 0x9EE7, 0x003E, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0009, 0x0000, 0x0064, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x1E04, 0x3DFB, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0A5B, 0x0000, 0x7300, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xB63F, 0x9721, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000B, 
            0x0000, 0x0072, 0x0000, 0x0000, 0x0000, 0x3F80, 0x130E, 0x3EF1, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0C5B, 0x0000, 0x4500, 0x766E, 
            0x7953, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000D, 0x0000, 0x6E45, 
            0x4476, 0x7669, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000E, 0x0000, 0x6E45, 
            0x5476, 0x6972, 0x0067, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0F5B, 0x0000, 0x5400, 
            0x6972, 0x4D67, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x4000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x105B, 0x0000, 
            0x4D00, 0x646F, 0x7254, 0x6769, 0x7253, 0x0063, 0x0000, 0x0000, 
            0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x115B, 0x0000, 0x4F00, 0x656E, 0x6853, 0x746F, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0012, 0x0000, 0x6F4D, 0x6964, 0x6966, 0x7265, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0013, 0x0000, 0x6F4D, 0x6964, 0x6566, 0x4172, 
            0x6A64, 0x7375, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x145B, 0x0000, 0x4D00, 
            0x646F, 0x6669, 0x7265, 0x6441, 0x756A, 0x7473, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x155B, 0x0000, 0x4D00, 0x646F, 0x6669, 0x7265, 
            0x6441, 0x756A, 0x7473, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x165B, 
            0x0000, 0x4F00, 0x5455, 0x5550, 0x0054, 0x0000, 0x0000, 0x0000, 
            0x4180, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x175B, 
            0x0000, 0x4D00, 0x6E6F, 0x526F, 0x6D61, 0x4970, 0x706E, 0x7475, 
            0x0000, 0x0000, 0x0000, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                              // PolyMod_impl::modchain_t<NV>
		auto& event_data_reader1 = this->getT(0).getT(0);                            // PolyMod_impl::event_data_reader1_t<NV>
		auto& split = this->getT(0).getT(1);                                         // PolyMod_impl::split_t<NV>
		auto& pma1 = this->getT(0).getT(1).getT(0);                                  // PolyMod_impl::pma1_t<NV>
		auto& pma3 = this->getT(0).getT(1).getT(1);                                  // PolyMod_impl::pma3_t<NV>
		auto& minmax = this->getT(0).getT(2);                                        // PolyMod_impl::minmax_t<NV>
		auto& tempo_sync1 = this->getT(0).getT(3);                                   // PolyMod_impl::tempo_sync1_t<NV>
		auto& branch = this->getT(0).getT(4);                                        // PolyMod_impl::branch_t<NV>
		auto& chain2 = this->getT(0).getT(4).getT(0);                                // PolyMod_impl::chain2_t<NV>
		auto& branch3 = this->getT(0).getT(4).getT(0).getT(0);                       // PolyMod_impl::branch3_t<NV>
		auto& chain6 = this->getT(0).getT(4).getT(0).getT(0).getT(0);                // PolyMod_impl::chain6_t<NV>
		auto& global_cable = this->getT(0).getT(4).getT(0).getT(0).getT(0).getT(0);  // PolyMod_impl::global_cable_t<NV>
		auto& add2 = this->getT(0).getT(4).getT(0).getT(0).getT(0).getT(1);          // math::add<NV>
		auto& chain9 = this->getT(0).getT(4).getT(0).getT(0).getT(1);                // PolyMod_impl::chain9_t<NV>
		auto& global_cable2 = this->getT(0).getT(4).getT(0).getT(0).getT(1).getT(0); // PolyMod_impl::global_cable2_t<NV>
		auto& add6 = this->getT(0).getT(4).getT(0).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain7 = this->getT(0).getT(4).getT(0).getT(0).getT(2);                // PolyMod_impl::chain7_t<NV>
		auto& global_cable1 = this->getT(0).getT(4).getT(0).getT(0).getT(2).getT(0); // PolyMod_impl::global_cable1_t<NV>
		auto& add5 = this->getT(0).getT(4).getT(0).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain10 = this->getT(0).getT(4).getT(0).getT(0).getT(3);               // PolyMod_impl::chain10_t<NV>
		auto& global_cable3 = this->getT(0).getT(4).getT(0).getT(0).getT(3).getT(0); // PolyMod_impl::global_cable3_t<NV>
		auto& add7 = this->getT(0).getT(4).getT(0).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& chain11 = this->getT(0).getT(4).getT(0).getT(0).getT(4);               // PolyMod_impl::chain11_t<NV>
		auto& global_cable4 = this->getT(0).getT(4).getT(0).getT(0).getT(4).getT(0); // PolyMod_impl::global_cable4_t<NV>
		auto& add8 = this->getT(0).getT(4).getT(0).getT(0).getT(4).getT(1);          // math::add<NV>
		auto& chain12 = this->getT(0).getT(4).getT(0).getT(0).getT(5);               // PolyMod_impl::chain12_t<NV>
		auto& global_cable5 = this->getT(0).getT(4).getT(0).getT(0).getT(5).getT(0); // PolyMod_impl::global_cable5_t<NV>
		auto& add9 = this->getT(0).getT(4).getT(0).getT(0).getT(5).getT(1);          // math::add<NV>
		auto& chain13 = this->getT(0).getT(4).getT(0).getT(0).getT(6);               // PolyMod_impl::chain13_t<NV>
		auto& global_cable6 = this->getT(0).getT(4).getT(0).getT(0).getT(6).getT(0); // PolyMod_impl::global_cable6_t<NV>
		auto& add10 = this->getT(0).getT(4).getT(0).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& chain14 = this->getT(0).getT(4).getT(0).getT(0).getT(7);               // PolyMod_impl::chain14_t<NV>
		auto& global_cable7 = this->getT(0).getT(4).getT(0).getT(0).getT(7).getT(0); // PolyMod_impl::global_cable7_t<NV>
		auto& add11 = this->getT(0).getT(4).getT(0).getT(0).getT(7).getT(1);         // math::add<NV>
		auto& chain3 = this->getT(0).getT(4).getT(1);                                // PolyMod_impl::chain3_t<NV>
		auto& ramp = this->getT(0).getT(4).getT(1).getT(0);                          // PolyMod_impl::ramp_t<NV>
		auto& chain4 = this->getT(0).getT(4).getT(2);                                // PolyMod_impl::chain4_t<NV>
		auto& event_data_reader = this->getT(0).getT(4).getT(2).getT(0);             // PolyMod_impl::event_data_reader_t<NV>
		auto& add4 = this->getT(0).getT(4).getT(2).getT(1);                          // math::add<NV>
		auto& peak1 = this->getT(0).getT(5);                                         // PolyMod_impl::peak1_t<NV>
		auto& chain47 = this->getT(0).getT(6);                                       // PolyMod_impl::chain47_t<NV>
		auto& branch1 = this->getT(0).getT(6).getT(0);                               // PolyMod_impl::branch1_t<NV>
		auto& chain = this->getT(0).getT(6).getT(0).getT(0);                         // PolyMod_impl::chain_t<NV>
		auto& tempo_sync = this->getT(0).getT(6).getT(0).getT(0).getT(0);            // PolyMod_impl::tempo_sync_t<NV>
		auto& tempo_sync4 = this->getT(0).getT(6).getT(0).getT(0).getT(1);           // PolyMod_impl::tempo_sync4_t<NV>
		auto& tempo_sync3 = this->getT(0).getT(6).getT(0).getT(0).getT(2);           // PolyMod_impl::tempo_sync3_t<NV>
		auto& tempo_sync5 = this->getT(0).getT(6).getT(0).getT(0).getT(3);           // PolyMod_impl::tempo_sync5_t<NV>
		auto& input_toggle = this->getT(0).getT(6).getT(0).getT(0).getT(4);          // PolyMod_impl::input_toggle_t<NV>
		auto& ahdsr = this->getT(0).getT(6).getT(0).getT(0).getT(5);                 // PolyMod_impl::ahdsr_t<NV>
		auto& chain23 = this->getT(0).getT(6).getT(0).getT(1);                       // PolyMod_impl::chain23_t<NV>
		auto& pi5 = this->getT(0).getT(6).getT(0).getT(1).getT(0);                   // math::pi<NV>
		auto& sin5 = this->getT(0).getT(6).getT(0).getT(1).getT(1);                  // math::sin<NV>
		auto& chain8 = this->getT(0).getT(6).getT(0).getT(2);                        // PolyMod_impl::chain8_t<NV>
		auto& rect1 = this->getT(0).getT(6).getT(0).getT(2).getT(0);                 // math::rect<NV>
		auto& chain5 = this->getT(0).getT(6).getT(0).getT(3);                        // PolyMod_impl::chain5_t
		auto& chain41 = this->getT(0).getT(6).getT(0).getT(4);                       // PolyMod_impl::chain41_t<NV>
		auto& clear13 = this->getT(0).getT(6).getT(0).getT(4).getT(0);               // wrap::no_process<math::clear<NV>>
		auto& expr7 = this->getT(0).getT(6).getT(0).getT(4).getT(1);                 // math::expr<NV, custom::expr7>
		auto& sig2mod9 = this->getT(0).getT(6).getT(0).getT(4).getT(2);              // math::sig2mod<NV>
		auto& peak5 = this->getT(0).getT(6).getT(0).getT(4).getT(3);                 // PolyMod_impl::peak5_t
		auto& chain32 = this->getT(0).getT(6).getT(0).getT(5);                       // PolyMod_impl::chain32_t<NV>
		auto& oscillator = this->getT(0).getT(6).getT(0).getT(5).getT(0);            // PolyMod_impl::oscillator_t<NV>
		auto& pi = this->getT(0).getT(6).getT(0).getT(5).getT(1);                    // wrap::no_process<math::pi<NV>>
		auto& sampleandhold1 = this->getT(0).getT(6).getT(0).getT(5).getT(2);        // fx::sampleandhold<NV>
		auto& sig2mod7 = this->getT(0).getT(6).getT(0).getT(5).getT(3);              // math::sig2mod<NV>
		auto& chain20 = this->getT(0).getT(6).getT(0).getT(6);                       // PolyMod_impl::chain20_t<NV>
		auto& clear15 = this->getT(0).getT(6).getT(0).getT(6).getT(0);               // math::clear<NV>
		auto& cable_table = this->getT(0).getT(6).getT(0).getT(6).getT(1);           // PolyMod_impl::cable_table_t<NV>
		auto& add = this->getT(0).getT(6).getT(0).getT(6).getT(2);                   // math::add<NV>
		auto& chain26 = this->getT(0).getT(6).getT(0).getT(7);                       // PolyMod_impl::chain26_t<NV>
		auto& clear5 = this->getT(0).getT(6).getT(0).getT(7).getT(0);                // math::clear<NV>
		auto& cable_pack = this->getT(0).getT(6).getT(0).getT(7).getT(1);            // PolyMod_impl::cable_pack_t
		auto& add3 = this->getT(0).getT(6).getT(0).getT(7).getT(2);                  // math::add<NV>
		auto& peak = this->getT(0).getT(6).getT(1);                                  // PolyMod_impl::peak_t
		auto& event_data_reader2 = this->getT(0).getT(6).getT(2);                    // PolyMod_impl::event_data_reader2_t<NV>
		auto& pma = this->getT(0).getT(6).getT(3);                                   // PolyMod_impl::pma_t<NV>
		auto& branch2 = this->getT(0).getT(6).getT(4);                               // PolyMod_impl::branch2_t<NV>
		auto& chain1 = this->getT(0).getT(6).getT(4).getT(0);                        // PolyMod_impl::chain1_t
		auto& chain29 = this->getT(0).getT(6).getT(4).getT(1);                       // PolyMod_impl::chain29_t<NV>
		auto& expr3 = this->getT(0).getT(6).getT(4).getT(1).getT(0);                 // math::expr<NV, custom::expr3>
		auto& chain35 = this->getT(0).getT(6).getT(4).getT(2);                       // PolyMod_impl::chain35_t<NV>
		auto& expr5 = this->getT(0).getT(6).getT(4).getT(2).getT(0);                 // math::expr<NV, custom::expr5>
		auto& chain44 = this->getT(0).getT(6).getT(4).getT(3);                       // PolyMod_impl::chain44_t<NV>
		auto& expr8 = this->getT(0).getT(6).getT(4).getT(3).getT(0);                 // math::expr<NV, custom::expr8>
		auto& chain45 = this->getT(0).getT(6).getT(4).getT(4);                       // PolyMod_impl::chain45_t<NV>
		auto& expr9 = this->getT(0).getT(6).getT(4).getT(4).getT(0);                 // math::expr<NV, custom::expr9>
		auto& peak2 = this->getT(0).getT(6).getT(5);                                 // PolyMod_impl::peak2_t<NV>
		auto& event_data_writer = this->getT(0).getT(6).getT(6);                     // routing::event_data_writer<NV>
		auto& clear3 = this->getT(0).getT(6).getT(7);                                // wrap::no_process<math::clear<NV>>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Tempo -> pma1::Add
		
		this->getParameterT(1).connectT(0, tempo_sync1); // Divide -> tempo_sync1::Multiplier
		
		auto& TempoMod_p = this->getParameterT(2);
		TempoMod_p.connectT(0, pma1); // TempoMod -> pma1::Multiply
		TempoMod_p.connectT(1, pma3); // TempoMod -> pma3::Multiply
		
		this->getParameterT(3).connectT(0, event_data_reader1); // TempoSrc -> event_data_reader1::SlotIndex
		
		this->getParameterT(4).connectT(0, tempo_sync1); // Sync -> tempo_sync1::Enabled
		
		this->getParameterT(5).connectT(0, pma3); // SpeedMS -> pma3::Add
		
		this->getParameterT(6).connectT(0, branch1); // Shape -> branch1::Index
		
		auto& a_p = this->getParameterT(7);
		a_p.connectT(0, tempo_sync); // a -> tempo_sync::Tempo
		a_p.connectT(1, tempo_sync); // a -> tempo_sync::UnsyncedTime
		
		auto& h_p = this->getParameterT(8);
		h_p.connectT(0, tempo_sync4); // h -> tempo_sync4::Tempo
		h_p.connectT(1, tempo_sync4); // h -> tempo_sync4::UnsyncedTime
		
		auto& d_p = this->getParameterT(9);
		d_p.connectT(0, tempo_sync3); // d -> tempo_sync3::Tempo
		d_p.connectT(1, tempo_sync3); // d -> tempo_sync3::UnsyncedTime
		
		this->getParameterT(10).connectT(0, ahdsr); // s -> ahdsr::Sustain
		
		auto& r_p = this->getParameterT(11);
		r_p.connectT(0, tempo_sync5); // r -> tempo_sync5::Tempo
		r_p.connectT(1, tempo_sync5); // r -> tempo_sync5::UnsyncedTime
		
		auto& EnvSync_p = this->getParameterT(12);
		EnvSync_p.connectT(0, tempo_sync);  // EnvSync -> tempo_sync::Enabled
		EnvSync_p.connectT(1, tempo_sync4); // EnvSync -> tempo_sync4::Enabled
		EnvSync_p.connectT(2, tempo_sync3); // EnvSync -> tempo_sync3::Enabled
		EnvSync_p.connectT(3, tempo_sync5); // EnvSync -> tempo_sync5::Enabled
		
		auto& EnvDiv_p = this->getParameterT(13);
		EnvDiv_p.connectT(0, tempo_sync);  // EnvDiv -> tempo_sync::Multiplier
		EnvDiv_p.connectT(1, tempo_sync4); // EnvDiv -> tempo_sync4::Multiplier
		EnvDiv_p.connectT(2, tempo_sync3); // EnvDiv -> tempo_sync3::Multiplier
		EnvDiv_p.connectT(3, tempo_sync5); // EnvDiv -> tempo_sync5::Multiplier
		
		this->getParameterT(14).connectT(0, input_toggle); // EnvTrig -> input_toggle::Input
		
		this->getParameterT(15).connectT(0, branch); // TrigMode -> branch::Index
		
		this->getParameterT(16).connectT(0, event_data_reader); // ModTrigSrc -> event_data_reader::SlotIndex
		
		this->getParameterT(17).connectT(0, ramp); // OneShot -> ramp::LoopStart
		
		this->getParameterT(18).connectT(0, branch2); // Modifier -> branch2::Index
		
		this->getParameterT(19).connectT(0, pma); // ModiferAdjust -> pma::Add
		
		this->getParameterT(20).connectT(0, pma); // ModiferAdjustMod -> pma::Multiply
		
		this->getParameterT(21).connectT(0, event_data_reader2); // ModiferAdjustSrc -> event_data_reader2::SlotIndex
		
		this->getParameterT(22).connectT(0, event_data_writer); // OUTPUT -> event_data_writer::SlotIndex
		
		this->getParameterT(23).connectT(0, branch3); // MonoRampInput -> branch3::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		tempo_sync1.getParameter().connectT(0, ramp);                       // tempo_sync1 -> ramp::PeriodTime
		tempo_sync1.getParameter().connectT(1, sampleandhold1);             // tempo_sync1 -> sampleandhold1::Counter
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync1);    // pma1 -> tempo_sync1::Tempo
		minmax.getWrappedObject().getParameter().connectT(0, tempo_sync1);  // minmax -> tempo_sync1::UnsyncedTime
		pma3.getWrappedObject().getParameter().connectT(0, minmax);         // pma3 -> minmax::Value
		event_data_reader1.getParameter().connectT(0, pma1);                // event_data_reader1 -> pma1::Value
		event_data_reader1.getParameter().connectT(1, pma3);                // event_data_reader1 -> pma3::Value
		global_cable.getWrappedObject().getParameter().connectT(0, add2);   // global_cable -> add2::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add6);  // global_cable2 -> add6::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add5);  // global_cable1 -> add5::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add7);  // global_cable3 -> add7::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add8);  // global_cable4 -> add8::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add9);  // global_cable5 -> add9::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add10); // global_cable6 -> add10::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add11); // global_cable7 -> add11::Value
		event_data_reader.getParameter().connectT(0, add4);                 // event_data_reader -> add4::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add);     // cable_table -> add::Value
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		input_toggle.getWrappedObject().getParameter().connectT(0, ahdsr); // input_toggle -> ahdsr::Gate
		peak1.getParameter().connectT(0, expr7);                           // peak1 -> expr7::Value
		peak1.getParameter().connectT(1, cable_table);                     // peak1 -> cable_table::Value
		peak1.getParameter().connectT(2, cable_pack);                      // peak1 -> cable_pack::Value
		peak1.getParameter().connectT(3, input_toggle);                    // peak1 -> input_toggle::Value2
		tempo_sync.getParameter().connectT(0, ahdsr);                      // tempo_sync -> ahdsr::Attack
		tempo_sync4.getParameter().connectT(0, ahdsr);                     // tempo_sync4 -> ahdsr::Hold
		tempo_sync3.getParameter().connectT(0, ahdsr);                     // tempo_sync3 -> ahdsr::Decay
		tempo_sync5.getParameter().connectT(0, ahdsr);                     // tempo_sync5 -> ahdsr::Release
		pma.getWrappedObject().getParameter().connectT(0, expr3);          // pma -> expr3::Value
		pma.getWrappedObject().getParameter().connectT(1, expr5);          // pma -> expr5::Value
		pma.getWrappedObject().getParameter().connectT(2, expr8);          // pma -> expr8::Value
		pma.getWrappedObject().getParameter().connectT(3, expr9);          // pma -> expr9::Value
		event_data_reader2.getParameter().connectT(0, pma);                // event_data_reader2 -> pma::Value
		peak2.getParameter().connectT(0, event_data_writer);               // peak2 -> event_data_writer::Value
		
		// Default Values --------------------------------------------------------------------------
		
		;                                        // event_data_reader1::SlotIndex is automated
		event_data_reader1.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		;                                // minmax::Value is automated
		minmax.setParameterT(1, 0.);     // control::minmax::Minimum
		minmax.setParameterT(2, 10000.); // control::minmax::Maximum
		minmax.setParameterT(3, 1.);     // control::minmax::Skew
		minmax.setParameterT(4, 0.);     // control::minmax::Step
		minmax.setParameterT(5, 1.);     // control::minmax::Polarity
		
		; // tempo_sync1::Tempo is automated
		; // tempo_sync1::Multiplier is automated
		; // tempo_sync1::Enabled is automated
		; // tempo_sync1::UnsyncedTime is automated
		
		; // branch::Index is automated
		
		; // branch3::Index is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		;                                       // event_data_reader::SlotIndex is automated
		event_data_reader.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add4::Value is automated
		
		; // branch1::Index is automated
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		; // tempo_sync4::Tempo is automated
		; // tempo_sync4::Multiplier is automated
		; // tempo_sync4::Enabled is automated
		; // tempo_sync4::UnsyncedTime is automated
		
		; // tempo_sync3::Tempo is automated
		; // tempo_sync3::Multiplier is automated
		; // tempo_sync3::Enabled is automated
		; // tempo_sync3::UnsyncedTime is automated
		
		; // tempo_sync5::Tempo is automated
		; // tempo_sync5::Multiplier is automated
		; // tempo_sync5::Enabled is automated
		; // tempo_sync5::UnsyncedTime is automated
		
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 0.); // control::input_toggle::Value1
		;                                  // input_toggle::Value2 is automated
		
		;                                 // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);       // envelope::ahdsr::AttackLevel
		;                                 // ahdsr::Hold is automated
		;                                 // ahdsr::Decay is automated
		;                                 // ahdsr::Sustain is automated
		;                                 // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.500965); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);       // envelope::ahdsr::Retrigger
		;                                 // ahdsr::Gate is automated
		
		pi5.setParameterT(0, 1.); // math::pi::Value
		
		sin5.setParameterT(0, 1.); // math::sin::Value
		
		rect1.setParameterT(0, 0.166743); // math::rect::Value
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		; // expr7::Value is automated
		
		sig2mod9.setParameterT(0, 0.); // math::sig2mod::Value
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		; // sampleandhold1::Counter is automated
		
		sig2mod7.setParameterT(0, 0.); // math::sig2mod::Value
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table::Value is automated
		
		; // add::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack::Value is automated
		
		add3.setParameterT(0, 0.); // math::add::Value
		
		;                                        // event_data_reader2::SlotIndex is automated
		event_data_reader2.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // branch2::Index is automated
		
		; // expr3::Value is automated
		
		; // expr5::Value is automated
		
		; // expr8::Value is automated
		
		; // expr9::Value is automated
		
		; // event_data_writer::SlotIndex is automated
		; // event_data_writer::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		this->setParameterT(0, 12.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 4.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.31036);
		this->setParameterT(9, 0.122616);
		this->setParameterT(10, 0.295179);
		this->setParameterT(11, 0.470849);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 0.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 0.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 1.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 1.);
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
		
		this->getT(0).getT(4).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // PolyMod_impl::global_cable_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // PolyMod_impl::global_cable2_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // PolyMod_impl::global_cable1_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // PolyMod_impl::global_cable3_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // PolyMod_impl::global_cable4_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // PolyMod_impl::global_cable5_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // PolyMod_impl::global_cable6_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // PolyMod_impl::global_cable7_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(4).getT(1).getT(0).setExternalData(b, index);         // PolyMod_impl::ramp_t<NV>
		this->getT(0).getT(5).setExternalData(b, index);                         // PolyMod_impl::peak1_t<NV>
		this->getT(0).getT(6).getT(0).getT(0).getT(5).setExternalData(b, index); // PolyMod_impl::ahdsr_t<NV>
		this->getT(0).getT(6).getT(0).getT(4).getT(3).setExternalData(b, index); // PolyMod_impl::peak5_t
		this->getT(0).getT(6).getT(0).getT(5).getT(0).setExternalData(b, index); // PolyMod_impl::oscillator_t<NV>
		this->getT(0).getT(6).getT(0).getT(6).getT(1).setExternalData(b, index); // PolyMod_impl::cable_table_t<NV>
		this->getT(0).getT(6).getT(0).getT(7).getT(1).setExternalData(b, index); // PolyMod_impl::cable_pack_t
		this->getT(0).getT(6).getT(1).setExternalData(b, index);                 // PolyMod_impl::peak_t
		this->getT(0).getT(6).getT(5).setExternalData(b, index);                 // PolyMod_impl::peak2_t<NV>
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
using PolyMod = wrap::node<PolyMod_impl::instance<NV>>;
}


