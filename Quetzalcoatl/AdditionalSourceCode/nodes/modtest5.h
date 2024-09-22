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

namespace modtest5_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable1_t_index = runtime_target::indexers::fix_hash<3357039>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, global_cable1_t<NV>>, 
                                 math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<3357040>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<3357041>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable3_t<NV>>, 
                                  math::add<NV>>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<3357042>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable4_t<NV>>, 
                                  math::add<NV>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<3357043>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable5_t<NV>>, 
                                  math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<3357044>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable6_t<NV>>, 
                                  math::add<NV>>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<3357045>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable7_t<NV>>, 
                                  math::add<NV>>;
using global_cable8_t_index = runtime_target::indexers::fix_hash<3357046>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   math::add<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;
using global_cable14_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>>;
using global_cable15_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>>;
using global_cable16_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = runtime_target::indexers::fix_hash<104068263>;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain_t<NV>>, 
                                    chain2_t<NV>, 
                                    chain3_t<NV>, 
                                    chain4_t<NV>, 
                                    chain6_t<NV>, 
                                    chain7_t<NV>, 
                                    chain9_t<NV>, 
                                    chain10_t<NV>, 
                                    chain14_t<NV>, 
                                    chain15_t<NV>, 
                                    chain25_t<NV>, 
                                    chain17_t<NV>, 
                                    chain18_t<NV>, 
                                    chain19_t<NV>, 
                                    chain21_t<NV>, 
                                    chain22_t<NV>>;

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

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::expr<NV, custom::expr7>, 0>, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  parameter::plain<cable_pack_t<NV>, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<ramp_t<NV>, 0>, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
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
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>>;
using global_cable19_t_index = global_cable1_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;
using global_cable20_t_index = global_cable2_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable3_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = global_cable4_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = global_cable5_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>>;
using global_cable24_t_index = global_cable6_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>>;
using global_cable25_t_index = global_cable7_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>>;
using global_cable26_t_index = global_cable8_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>>;
using global_cable27_t_index = global_cable10_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>>;
using global_cable28_t_index = global_cable11_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   math::add<NV>>;
using global_cable29_t_index = global_cable12_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   math::add<NV>>;
using global_cable30_t_index = global_cable13_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable30_t<NV>>, 
                                   math::add<NV>>;
using global_cable31_t_index = global_cable14_t_index;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable31_t<NV>>, 
                                   math::add<NV>>;
using global_cable32_t_index = global_cable15_t_index;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable32_t<NV>>, 
                                   math::add<NV>>;
using global_cable33_t_index = global_cable16_t_index;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable33_t<NV>>, 
                                   math::add<NV>>;
using global_cable34_t_index = global_cable17_t_index;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable34_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain28_t<NV>>, 
                                    chain30_t<NV>, 
                                    chain31_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>, 
                                    chain36_t<NV>, 
                                    chain37_t<NV>, 
                                    chain38_t<NV>, 
                                    chain39_t<NV>, 
                                    chain40_t<NV>, 
                                    chain42_t<NV>, 
                                    chain43_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>, 
                                    chain54_t<NV>, 
                                    chain55_t<NV>>;

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
using peak4_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   peak4_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>>;

template <int NV>
using simple_ar_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                           parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod<NV>>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, simple_ar_t<NV>>, 
                                      math::add<NV>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;
using global_cable48_t_index = global_cable1_t_index;

template <int NV>
using global_cable48_t = routing::global_cable<global_cable48_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable48_t<NV>>, 
                                   math::add<NV>>;
using global_cable49_t_index = global_cable2_t_index;

template <int NV>
using global_cable49_t = routing::global_cable<global_cable49_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable49_t<NV>>, 
                                   math::add<NV>>;
using global_cable50_t_index = global_cable3_t_index;

template <int NV>
using global_cable50_t = routing::global_cable<global_cable50_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable50_t<NV>>, 
                                   math::add<NV>>;
using global_cable51_t_index = global_cable4_t_index;

template <int NV>
using global_cable51_t = routing::global_cable<global_cable51_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable51_t<NV>>, 
                                   math::add<NV>>;
using global_cable52_t_index = global_cable5_t_index;

template <int NV>
using global_cable52_t = routing::global_cable<global_cable52_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable52_t<NV>>, 
                                   math::add<NV>>;
using global_cable53_t_index = global_cable6_t_index;

template <int NV>
using global_cable53_t = routing::global_cable<global_cable53_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable53_t<NV>>, 
                                   math::add<NV>>;
using global_cable56_t_index = global_cable10_t_index;

template <int NV>
using global_cable56_t = routing::global_cable<global_cable56_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable56_t<NV>>, 
                                   math::add<NV>>;
using global_cable57_t_index = global_cable11_t_index;

template <int NV>
using global_cable57_t = routing::global_cable<global_cable57_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable57_t<NV>>, 
                                   math::add<NV>>;
using global_cable58_t_index = global_cable12_t_index;

template <int NV>
using global_cable58_t = routing::global_cable<global_cable58_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable58_t<NV>>, 
                                   math::add<NV>>;
using global_cable59_t_index = global_cable13_t_index;

template <int NV>
using global_cable59_t = routing::global_cable<global_cable59_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable59_t<NV>>, 
                                   math::add<NV>>;
using global_cable60_t_index = global_cable14_t_index;

template <int NV>
using global_cable60_t = routing::global_cable<global_cable60_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable60_t<NV>>, 
                                   math::add<NV>>;
using global_cable61_t_index = global_cable15_t_index;

template <int NV>
using global_cable61_t = routing::global_cable<global_cable61_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable61_t<NV>>, 
                                   math::add<NV>>;
using global_cable62_t_index = global_cable16_t_index;

template <int NV>
using global_cable62_t = routing::global_cable<global_cable62_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable62_t<NV>>, 
                                   math::add<NV>>;
using global_cable63_t_index = global_cable17_t_index;

template <int NV>
using global_cable63_t = routing::global_cable<global_cable63_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable63_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain11_t<NV>>, 
                                    midichain_t<NV>, 
                                    chain47_t<NV>, 
                                    chain48_t<NV>, 
                                    chain49_t<NV>, 
                                    chain56_t<NV>, 
                                    chain57_t<NV>, 
                                    chain58_t<NV>, 
                                    chain61_t<NV>, 
                                    chain62_t<NV>, 
                                    chain63_t<NV>, 
                                    chain64_t<NV>, 
                                    chain65_t<NV>, 
                                    chain66_t<NV>, 
                                    chain67_t<NV>, 
                                    chain68_t<NV>>;

template <int NV>
using peak6_t = wrap::mod<parameter::plain<ramp_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   peak6_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::pi<NV>>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   math::mod2sig<NV>, 
                                   math::sin<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, wrap::no_process<math::pi<NV>>>, 
                                  wrap::no_process<math::mod2sig<NV>>, 
                                  wrap::no_process<math::sig2mod<NV>>, 
                                  wrap::no_process<math::pi<NV>>, 
                                  wrap::no_process<math::clip<NV>>, 
                                  wrap::no_process<math::sin<NV>>, 
                                  wrap::no_process<math::square<NV>>, 
                                  wrap::no_process<math::sqrt<NV>>, 
                                  math::rect<NV>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, wrap::no_process<math::sig2mod<NV>>>, 
                                  wrap::no_process<math::mod2sig<NV>>>;
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
                                   cable_pack_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain23_t<NV>>, 
                                   chain8_t<NV>, 
                                   chain5_t<NV>, 
                                   chain41_t<NV>, 
                                   chain32_t<NV>, 
                                   chain20_t<NV>, 
                                   chain26_t<NV>>;
using peak_t = wrap::data<core::peak, 
                          data::external::displaybuffer<0>>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;

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
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain1_t>, 
                                    chain29_t<NV>, 
                                    chain35_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>>;

using global_cable54_t_index = global_cable14_t_index;
using peak2_mod = parameter::plain<routing::global_cable<global_cable54_t_index, parameter::empty>, 
                                   0>;
using peak2_t = wrap::mod<peak2_mod, 
                          wrap::data<core::peak, data::external::displaybuffer<1>>>;

namespace modtest5_t_parameters
{
// Parameter list for modtest5_impl::modtest5_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE(Tempo_InputRange, 
                        0., 
                        18.);
DECLARE_PARAMETER_RANGE(Tempo_0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Tempo_0 = parameter::from0To1<modtest5_impl::pma1_t<NV>, 
                                    2, 
                                    Tempo_0Range>;

template <int NV>
using Tempo = parameter::chain<Tempo_InputRange, Tempo_0<NV>>;

DECLARE_PARAMETER_RANGE(TempoSrc_InputRange, 
                        0., 
                        16.);
DECLARE_PARAMETER_RANGE_STEP(TempoSrc_0Range, 
                             0., 
                             15., 
                             1.);

template <int NV>
using TempoSrc_0 = parameter::from0To1<modtest5_impl::branch3_t<NV>, 
                                       0, 
                                       TempoSrc_0Range>;

template <int NV>
using TempoSrc = parameter::chain<TempoSrc_InputRange, TempoSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Shape_InputRange, 
                             0., 
                             7., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(Shape_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using Shape_0 = parameter::from0To1<modtest5_impl::branch_t<NV>, 
                                    0, 
                                    Shape_0Range>;

template <int NV>
using Shape = parameter::chain<Shape_InputRange, Shape_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Modifiers_InputRange, 
                             0., 
                             4., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(Modifiers_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using Modifiers_0 = parameter::from0To1<modtest5_impl::branch1_t<NV>, 
                                        0, 
                                        Modifiers_0Range>;

template <int NV>
using Modifiers = parameter::chain<Modifiers_InputRange, Modifiers_0<NV>>;

template <int NV>
using ModiferShape = parameter::from0To1<modtest5_impl::pma_t<NV>, 
                                         2, 
                                         Tempo_0Range>;

DECLARE_PARAMETER_RANGE(ModifierShapeModSrc_InputRange, 
                        0., 
                        16.);
template <int NV>
using ModifierShapeModSrc_0 = parameter::from0To1<modtest5_impl::branch5_t<NV>, 
                                                  0, 
                                                  TempoSrc_0Range>;

template <int NV>
using ModifierShapeModSrc = parameter::chain<ModifierShapeModSrc_InputRange, 
                                             ModifierShapeModSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(trigmode_InputRange, 
                             0., 
                             18., 
                             0.1);
template <int NV>
using trigmode_0 = parameter::from0To1<modtest5_impl::branch6_t<NV>, 
                                       0, 
                                       TempoSrc_0Range>;

template <int NV>
using trigmode = parameter::chain<trigmode_InputRange, trigmode_0<NV>>;

template <int NV>
using TempoMod = parameter::plain<modtest5_impl::pma1_t<NV>, 
                                  1>;
template <int NV>
using Div = parameter::plain<modtest5_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using ModifierShapeMod = parameter::plain<modtest5_impl::pma_t<NV>, 
                                          1>;
using out = parameter::empty;
template <int NV>
using oneshot = parameter::plain<modtest5_impl::ramp_t<NV>, 
                                 1>;
template <int NV>
using modtest5_t_plist = parameter::list<Tempo<NV>, 
                                         TempoMod<NV>, 
                                         TempoSrc<NV>, 
                                         Div<NV>, 
                                         Shape<NV>, 
                                         Modifiers<NV>, 
                                         ModiferShape<NV>, 
                                         ModifierShapeMod<NV>, 
                                         ModifierShapeModSrc<NV>, 
                                         out, 
                                         trigmode<NV>, 
                                         oneshot<NV>>;
}

template <int NV>
using modtest5_t_ = container::chain<modtest5_t_parameters::modtest5_t_plist<NV>, 
                                     wrap::fix<1, chain12_t<NV>>, 
                                     chain27_t<NV>, 
                                     math::clear<NV>, 
                                     chain46_t<NV>, 
                                     math::clear<NV>, 
                                     pma1_t<NV>, 
                                     tempo_sync_t<NV>, 
                                     ramp_t<NV>, 
                                     wrap::no_process<math::fmod<NV>>, 
                                     branch_t<NV>, 
                                     peak_t, 
                                     pma_t<NV>, 
                                     branch1_t<NV>, 
                                     peak2_t, 
                                     math::clear<NV>, 
                                     routing::global_cable<global_cable54_t_index, parameter::empty>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public modtest5_impl::modtest5_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 2;
		
		SNEX_METADATA_ID(modtest5);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(208)
		{
			0x005B, 0x0000, 0x5400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6554, 0x706D, 0x4D6F, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x253F, 0xF306, 0x003A, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0002, 0x0000, 0x6554, 0x706D, 0x536F, 0x6372, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0003, 0x0000, 0x6944, 0x0076, 0x0000, 0x3F80, 
            0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x045B, 0x0000, 0x5300, 0x6168, 0x6570, 0x0000, 0x0000, 0x0000, 
            0xE000, 0x3340, 0xB333, 0x0040, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 
            0x0005, 0x0000, 0x6F4D, 0x6964, 0x6966, 0x7265, 0x0073, 0x0000, 
            0x0000, 0x0000, 0x4080, 0x0000, 0x0000, 0x0000, 0x3F80, 0xCCCD, 
            0x3DCC, 0x065B, 0x0000, 0x4D00, 0x646F, 0x6669, 0x7265, 0x6853, 
            0x7061, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x60E5, 0x3E6E, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x4D00, 0x646F, 
            0x6669, 0x6569, 0x5372, 0x6168, 0x6570, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x624E, 0x3940, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x085B, 0x0000, 0x4D00, 0x646F, 0x6669, 0x6569, 0x5372, 
            0x6168, 0x6570, 0x6F4D, 0x5364, 0x6372, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x9641, 0x8213, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0009, 0x0000, 0x756F, 0x0074, 0x0000, 0x0000, 0x0000, 0x4180, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 0x0000, 
            0x7400, 0x6972, 0x6D67, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x4190, 0x0000, 0x3F80, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 0x0B5B, 
            0x0000, 0x6F00, 0x656E, 0x6873, 0x746F, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain12 = this->getT(0);                                 // modtest5_impl::chain12_t<NV>
		auto& branch3 = this->getT(0).getT(0);                         // modtest5_impl::branch3_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0);                   // modtest5_impl::chain_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(0);   // modtest5_impl::global_cable1_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain2 = this->getT(0).getT(0).getT(1);                  // modtest5_impl::chain2_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(1).getT(0);   // modtest5_impl::global_cable2_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(1);            // math::add<NV>
		auto& chain3 = this->getT(0).getT(0).getT(2);                  // modtest5_impl::chain3_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(2).getT(0);   // modtest5_impl::global_cable3_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& chain4 = this->getT(0).getT(0).getT(3);                  // modtest5_impl::chain4_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(3).getT(0);   // modtest5_impl::global_cable4_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(3).getT(1);            // math::add<NV>
		auto& chain6 = this->getT(0).getT(0).getT(4);                  // modtest5_impl::chain6_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(4).getT(0);   // modtest5_impl::global_cable5_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(4).getT(1);            // math::add<NV>
		auto& chain7 = this->getT(0).getT(0).getT(5);                  // modtest5_impl::chain7_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(5).getT(0);   // modtest5_impl::global_cable6_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(5).getT(1);            // math::add<NV>
		auto& chain9 = this->getT(0).getT(0).getT(6);                  // modtest5_impl::chain9_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(6).getT(0);   // modtest5_impl::global_cable7_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(6).getT(1);            // math::add<NV>
		auto& chain10 = this->getT(0).getT(0).getT(7);                 // modtest5_impl::chain10_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(7).getT(0);   // modtest5_impl::global_cable8_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(8);                 // modtest5_impl::chain14_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(8).getT(0);  // modtest5_impl::global_cable10_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain15 = this->getT(0).getT(0).getT(9);                 // modtest5_impl::chain15_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(9).getT(0);  // modtest5_impl::global_cable11_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain25 = this->getT(0).getT(0).getT(10);                // modtest5_impl::chain25_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(10).getT(0); // modtest5_impl::global_cable12_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain17 = this->getT(0).getT(0).getT(11);                // modtest5_impl::chain17_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(11).getT(0); // modtest5_impl::global_cable13_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(12);                // modtest5_impl::chain18_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(12).getT(0); // modtest5_impl::global_cable14_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain19 = this->getT(0).getT(0).getT(13);                // modtest5_impl::chain19_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(13).getT(0); // modtest5_impl::global_cable15_t<NV>
		auto& add17 = this->getT(0).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(14);                // modtest5_impl::chain21_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(14).getT(0); // modtest5_impl::global_cable16_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(15);                // modtest5_impl::chain22_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(15).getT(0); // modtest5_impl::global_cable17_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak1 = this->getT(0).getT(1);                           // modtest5_impl::peak1_t<NV>
		auto& clear = this->getT(0).getT(2);                           // math::clear<NV>
		auto& chain27 = this->getT(1);                                 // modtest5_impl::chain27_t<NV>
		auto& branch5 = this->getT(1).getT(0);                         // modtest5_impl::branch5_t<NV>
		auto& chain28 = this->getT(1).getT(0).getT(0);                 // modtest5_impl::chain28_t<NV>
		auto& global_cable19 = this->getT(1).getT(0).getT(0).getT(0);  // modtest5_impl::global_cable19_t<NV>
		auto& add21 = this->getT(1).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain30 = this->getT(1).getT(0).getT(1);                 // modtest5_impl::chain30_t<NV>
		auto& global_cable20 = this->getT(1).getT(0).getT(1).getT(0);  // modtest5_impl::global_cable20_t<NV>
		auto& add22 = this->getT(1).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain31 = this->getT(1).getT(0).getT(2);                 // modtest5_impl::chain31_t<NV>
		auto& global_cable21 = this->getT(1).getT(0).getT(2).getT(0);  // modtest5_impl::global_cable21_t<NV>
		auto& add23 = this->getT(1).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain33 = this->getT(1).getT(0).getT(3);                 // modtest5_impl::chain33_t<NV>
		auto& global_cable22 = this->getT(1).getT(0).getT(3).getT(0);  // modtest5_impl::global_cable22_t<NV>
		auto& add24 = this->getT(1).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain34 = this->getT(1).getT(0).getT(4);                 // modtest5_impl::chain34_t<NV>
		auto& global_cable23 = this->getT(1).getT(0).getT(4).getT(0);  // modtest5_impl::global_cable23_t<NV>
		auto& add25 = this->getT(1).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain36 = this->getT(1).getT(0).getT(5);                 // modtest5_impl::chain36_t<NV>
		auto& global_cable24 = this->getT(1).getT(0).getT(5).getT(0);  // modtest5_impl::global_cable24_t<NV>
		auto& add26 = this->getT(1).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain37 = this->getT(1).getT(0).getT(6);                 // modtest5_impl::chain37_t<NV>
		auto& global_cable25 = this->getT(1).getT(0).getT(6).getT(0);  // modtest5_impl::global_cable25_t<NV>
		auto& add27 = this->getT(1).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain38 = this->getT(1).getT(0).getT(7);                 // modtest5_impl::chain38_t<NV>
		auto& global_cable26 = this->getT(1).getT(0).getT(7).getT(0);  // modtest5_impl::global_cable26_t<NV>
		auto& add28 = this->getT(1).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain39 = this->getT(1).getT(0).getT(8);                 // modtest5_impl::chain39_t<NV>
		auto& global_cable27 = this->getT(1).getT(0).getT(8).getT(0);  // modtest5_impl::global_cable27_t<NV>
		auto& add29 = this->getT(1).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain40 = this->getT(1).getT(0).getT(9);                 // modtest5_impl::chain40_t<NV>
		auto& global_cable28 = this->getT(1).getT(0).getT(9).getT(0);  // modtest5_impl::global_cable28_t<NV>
		auto& add30 = this->getT(1).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain42 = this->getT(1).getT(0).getT(10);                // modtest5_impl::chain42_t<NV>
		auto& global_cable29 = this->getT(1).getT(0).getT(10).getT(0); // modtest5_impl::global_cable29_t<NV>
		auto& add31 = this->getT(1).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain43 = this->getT(1).getT(0).getT(11);                // modtest5_impl::chain43_t<NV>
		auto& global_cable30 = this->getT(1).getT(0).getT(11).getT(0); // modtest5_impl::global_cable30_t<NV>
		auto& add32 = this->getT(1).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain52 = this->getT(1).getT(0).getT(12);                // modtest5_impl::chain52_t<NV>
		auto& global_cable31 = this->getT(1).getT(0).getT(12).getT(0); // modtest5_impl::global_cable31_t<NV>
		auto& add33 = this->getT(1).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain53 = this->getT(1).getT(0).getT(13);                // modtest5_impl::chain53_t<NV>
		auto& global_cable32 = this->getT(1).getT(0).getT(13).getT(0); // modtest5_impl::global_cable32_t<NV>
		auto& add34 = this->getT(1).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain54 = this->getT(1).getT(0).getT(14);                // modtest5_impl::chain54_t<NV>
		auto& global_cable33 = this->getT(1).getT(0).getT(14).getT(0); // modtest5_impl::global_cable33_t<NV>
		auto& add35 = this->getT(1).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain55 = this->getT(1).getT(0).getT(15);                // modtest5_impl::chain55_t<NV>
		auto& global_cable34 = this->getT(1).getT(0).getT(15).getT(0); // modtest5_impl::global_cable34_t<NV>
		auto& add36 = this->getT(1).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak4 = this->getT(1).getT(1);                           // modtest5_impl::peak4_t<NV>
		auto& clear6 = this->getT(2);                                  // math::clear<NV>
		auto& chain46 = this->getT(3);                                 // modtest5_impl::chain46_t<NV>
		auto& branch6 = this->getT(3).getT(0);                         // modtest5_impl::branch6_t<NV>
		auto& chain11 = this->getT(3).getT(0).getT(0);                 // modtest5_impl::chain11_t<NV>
		auto& add11 = this->getT(3).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& midichain = this->getT(3).getT(0).getT(1);               // modtest5_impl::midichain_t<NV>
		auto& simple_ar = this->getT(3).getT(0).getT(1).getT(0);       // modtest5_impl::simple_ar_t<NV>
		auto& add20 = this->getT(3).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain47 = this->getT(3).getT(0).getT(2);                 // modtest5_impl::chain47_t<NV>
		auto& global_cable48 = this->getT(3).getT(0).getT(2).getT(0);  // modtest5_impl::global_cable48_t<NV>
		auto& add37 = this->getT(3).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain48 = this->getT(3).getT(0).getT(3);                 // modtest5_impl::chain48_t<NV>
		auto& global_cable49 = this->getT(3).getT(0).getT(3).getT(0);  // modtest5_impl::global_cable49_t<NV>
		auto& add38 = this->getT(3).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain49 = this->getT(3).getT(0).getT(4);                 // modtest5_impl::chain49_t<NV>
		auto& global_cable50 = this->getT(3).getT(0).getT(4).getT(0);  // modtest5_impl::global_cable50_t<NV>
		auto& add39 = this->getT(3).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain56 = this->getT(3).getT(0).getT(5);                 // modtest5_impl::chain56_t<NV>
		auto& global_cable51 = this->getT(3).getT(0).getT(5).getT(0);  // modtest5_impl::global_cable51_t<NV>
		auto& add40 = this->getT(3).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain57 = this->getT(3).getT(0).getT(6);                 // modtest5_impl::chain57_t<NV>
		auto& global_cable52 = this->getT(3).getT(0).getT(6).getT(0);  // modtest5_impl::global_cable52_t<NV>
		auto& add41 = this->getT(3).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain58 = this->getT(3).getT(0).getT(7);                 // modtest5_impl::chain58_t<NV>
		auto& global_cable53 = this->getT(3).getT(0).getT(7).getT(0);  // modtest5_impl::global_cable53_t<NV>
		auto& add42 = this->getT(3).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain61 = this->getT(3).getT(0).getT(8);                 // modtest5_impl::chain61_t<NV>
		auto& global_cable56 = this->getT(3).getT(0).getT(8).getT(0);  // modtest5_impl::global_cable56_t<NV>
		auto& add45 = this->getT(3).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain62 = this->getT(3).getT(0).getT(9);                 // modtest5_impl::chain62_t<NV>
		auto& global_cable57 = this->getT(3).getT(0).getT(9).getT(0);  // modtest5_impl::global_cable57_t<NV>
		auto& add46 = this->getT(3).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain63 = this->getT(3).getT(0).getT(10);                // modtest5_impl::chain63_t<NV>
		auto& global_cable58 = this->getT(3).getT(0).getT(10).getT(0); // modtest5_impl::global_cable58_t<NV>
		auto& add47 = this->getT(3).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain64 = this->getT(3).getT(0).getT(11);                // modtest5_impl::chain64_t<NV>
		auto& global_cable59 = this->getT(3).getT(0).getT(11).getT(0); // modtest5_impl::global_cable59_t<NV>
		auto& add48 = this->getT(3).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain65 = this->getT(3).getT(0).getT(12);                // modtest5_impl::chain65_t<NV>
		auto& global_cable60 = this->getT(3).getT(0).getT(12).getT(0); // modtest5_impl::global_cable60_t<NV>
		auto& add49 = this->getT(3).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain66 = this->getT(3).getT(0).getT(13);                // modtest5_impl::chain66_t<NV>
		auto& global_cable61 = this->getT(3).getT(0).getT(13).getT(0); // modtest5_impl::global_cable61_t<NV>
		auto& add50 = this->getT(3).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain67 = this->getT(3).getT(0).getT(14);                // modtest5_impl::chain67_t<NV>
		auto& global_cable62 = this->getT(3).getT(0).getT(14).getT(0); // modtest5_impl::global_cable62_t<NV>
		auto& add51 = this->getT(3).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain68 = this->getT(3).getT(0).getT(15);                // modtest5_impl::chain68_t<NV>
		auto& global_cable63 = this->getT(3).getT(0).getT(15).getT(0); // modtest5_impl::global_cable63_t<NV>
		auto& add52 = this->getT(3).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak6 = this->getT(3).getT(1);                           // modtest5_impl::peak6_t<NV>
		auto& clear7 = this->getT(3).getT(2);                          // math::clear<NV>
		auto& clear2 = this->getT(4);                                  // math::clear<NV>
		auto& pma1 = this->getT(5);                                    // modtest5_impl::pma1_t<NV>
		auto& tempo_sync = this->getT(6);                              // modtest5_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(7);                                    // modtest5_impl::ramp_t<NV>
		auto& fmod1 = this->getT(8);                                   // wrap::no_process<math::fmod<NV>>
		auto& branch = this->getT(9);                                  // modtest5_impl::branch_t<NV>
		auto& chain23 = this->getT(9).getT(0);                         // modtest5_impl::chain23_t<NV>
		auto& pi5 = this->getT(9).getT(0).getT(0);                     // math::pi<NV>
		auto& sig2mod5 = this->getT(9).getT(0).getT(1);                // wrap::no_process<math::sig2mod<NV>>
		auto& mod2sig5 = this->getT(9).getT(0).getT(2);                // math::mod2sig<NV>
		auto& sin5 = this->getT(9).getT(0).getT(3);                    // math::sin<NV>
		auto& chain8 = this->getT(9).getT(1);                          // modtest5_impl::chain8_t<NV>
		auto& pi2 = this->getT(9).getT(1).getT(0);                     // wrap::no_process<math::pi<NV>>
		auto& mod2sig1 = this->getT(9).getT(1).getT(1);                // wrap::no_process<math::mod2sig<NV>>
		auto& sig2mod = this->getT(9).getT(1).getT(2);                 // wrap::no_process<math::sig2mod<NV>>
		auto& pi1 = this->getT(9).getT(1).getT(3);                     // wrap::no_process<math::pi<NV>>
		auto& clip1 = this->getT(9).getT(1).getT(4);                   // wrap::no_process<math::clip<NV>>
		auto& sin1 = this->getT(9).getT(1).getT(5);                    // wrap::no_process<math::sin<NV>>
		auto& square1 = this->getT(9).getT(1).getT(6);                 // wrap::no_process<math::square<NV>>
		auto& sqrt = this->getT(9).getT(1).getT(7);                    // wrap::no_process<math::sqrt<NV>>
		auto& rect1 = this->getT(9).getT(1).getT(8);                   // math::rect<NV>
		auto& chain5 = this->getT(9).getT(2);                          // modtest5_impl::chain5_t<NV>
		auto& sig2mod4 = this->getT(9).getT(2).getT(0);                // wrap::no_process<math::sig2mod<NV>>
		auto& mod2sig = this->getT(9).getT(2).getT(1);                 // wrap::no_process<math::mod2sig<NV>>
		auto& chain41 = this->getT(9).getT(3);                         // modtest5_impl::chain41_t<NV>
		auto& clear13 = this->getT(9).getT(3).getT(0);                 // wrap::no_process<math::clear<NV>>
		auto& expr7 = this->getT(9).getT(3).getT(1);                   // math::expr<NV, custom::expr7>
		auto& sig2mod9 = this->getT(9).getT(3).getT(2);                // math::sig2mod<NV>
		auto& peak5 = this->getT(9).getT(3).getT(3);                   // modtest5_impl::peak5_t
		auto& chain32 = this->getT(9).getT(4);                         // modtest5_impl::chain32_t<NV>
		auto& oscillator = this->getT(9).getT(4).getT(0);              // modtest5_impl::oscillator_t<NV>
		auto& pi = this->getT(9).getT(4).getT(1);                      // wrap::no_process<math::pi<NV>>
		auto& sampleandhold1 = this->getT(9).getT(4).getT(2);          // fx::sampleandhold<NV>
		auto& sig2mod7 = this->getT(9).getT(4).getT(3);                // math::sig2mod<NV>
		auto& chain20 = this->getT(9).getT(5);                         // modtest5_impl::chain20_t<NV>
		auto& clear15 = this->getT(9).getT(5).getT(0);                 // math::clear<NV>
		auto& cable_table = this->getT(9).getT(5).getT(1);             // modtest5_impl::cable_table_t<NV>
		auto& add = this->getT(9).getT(5).getT(2);                     // math::add<NV>
		auto& chain26 = this->getT(9).getT(6);                         // modtest5_impl::chain26_t<NV>
		auto& clear5 = this->getT(9).getT(6).getT(0);                  // math::clear<NV>
		auto& cable_pack = this->getT(9).getT(6).getT(1);              // modtest5_impl::cable_pack_t<NV>
		auto& add1 = this->getT(9).getT(6).getT(2);                    // math::add<NV>
		auto& peak = this->getT(10);                                   // modtest5_impl::peak_t
		auto& pma = this->getT(11);                                    // modtest5_impl::pma_t<NV>
		auto& branch1 = this->getT(12);                                // modtest5_impl::branch1_t<NV>
		auto& chain1 = this->getT(12).getT(0);                         // modtest5_impl::chain1_t
		auto& chain29 = this->getT(12).getT(1);                        // modtest5_impl::chain29_t<NV>
		auto& expr3 = this->getT(12).getT(1).getT(0);                  // math::expr<NV, custom::expr3>
		auto& chain35 = this->getT(12).getT(2);                        // modtest5_impl::chain35_t<NV>
		auto& expr5 = this->getT(12).getT(2).getT(0);                  // math::expr<NV, custom::expr5>
		auto& chain44 = this->getT(12).getT(3);                        // modtest5_impl::chain44_t<NV>
		auto& expr8 = this->getT(12).getT(3).getT(0);                  // math::expr<NV, custom::expr8>
		auto& chain45 = this->getT(12).getT(4);                        // modtest5_impl::chain45_t<NV>
		auto& expr9 = this->getT(12).getT(4).getT(0);                  // math::expr<NV, custom::expr9>
		auto& peak2 = this->getT(13);                                  // modtest5_impl::peak2_t
		auto& clear3 = this->getT(14);                                 // math::clear<NV>
		auto& global_cable54 = this->getT(15);                         // routing::global_cable<global_cable54_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Tempo -> pma1::Add
		
		this->getParameterT(1).connectT(0, pma1); // TempoMod -> pma1::Multiply
		
		this->getParameterT(2).connectT(0, branch3); // TempoSrc -> branch3::Index
		
		this->getParameterT(3).connectT(0, tempo_sync); // Div -> tempo_sync::Multiplier
		
		this->getParameterT(4).connectT(0, branch); // Shape -> branch::Index
		
		this->getParameterT(5).connectT(0, branch1); // Modifiers -> branch1::Index
		
		this->getParameterT(6).connectT(0, pma); // ModiferShape -> pma::Add
		
		this->getParameterT(7).connectT(0, pma); // ModifierShapeMod -> pma::Multiply
		
		this->getParameterT(8).connectT(0, branch5); // ModifierShapeModSrc -> branch5::Index
		
		this->getParameterT(10).connectT(0, branch6); // trigmode -> branch6::Index
		
		this->getParameterT(11).connectT(0, ramp); // oneshot -> ramp::LoopStart
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable1.getWrappedObject().getParameter().connectT(0, add2);   // global_cable1 -> add2::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add4);   // global_cable2 -> add4::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add5);   // global_cable3 -> add5::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add6);   // global_cable4 -> add6::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add7);   // global_cable5 -> add7::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add8);   // global_cable6 -> add8::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add9);   // global_cable7 -> add9::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add10);  // global_cable8 -> add10::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add12); // global_cable10 -> add12::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add13); // global_cable11 -> add13::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add14); // global_cable12 -> add14::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add15); // global_cable13 -> add15::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add16); // global_cable14 -> add16::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add17); // global_cable15 -> add17::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add18); // global_cable16 -> add18::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add19); // global_cable17 -> add19::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add);      // cable_table -> add::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add1);      // cable_pack -> add1::Value
		ramp.getParameter().connectT(0, expr7);                              // ramp -> expr7::Value
		ramp.getParameter().connectT(1, cable_table);                        // ramp -> cable_table::Value
		ramp.getParameter().connectT(2, cable_pack);                         // ramp -> cable_pack::Value
		tempo_sync.getParameter().connectT(0, ramp);                         // tempo_sync -> ramp::PeriodTime
		tempo_sync.getParameter().connectT(1, sampleandhold1);               // tempo_sync -> sampleandhold1::Counter
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync);      // pma1 -> tempo_sync::Tempo
		peak1.getParameter().connectT(0, pma1);                              // peak1 -> pma1::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add21); // global_cable19 -> add21::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add22); // global_cable20 -> add22::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add23); // global_cable21 -> add23::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add24); // global_cable22 -> add24::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add25); // global_cable23 -> add25::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add26); // global_cable24 -> add26::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add27); // global_cable25 -> add27::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add28); // global_cable26 -> add28::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add29); // global_cable27 -> add29::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add30); // global_cable28 -> add30::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add31); // global_cable29 -> add31::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add32); // global_cable30 -> add32::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add33); // global_cable31 -> add33::Value
		global_cable32.getWrappedObject().getParameter().connectT(0, add34); // global_cable32 -> add34::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add35); // global_cable33 -> add35::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add36); // global_cable34 -> add36::Value
		pma.getWrappedObject().getParameter().connectT(0, expr3);            // pma -> expr3::Value
		pma.getWrappedObject().getParameter().connectT(1, expr5);            // pma -> expr5::Value
		pma.getWrappedObject().getParameter().connectT(2, expr8);            // pma -> expr8::Value
		pma.getWrappedObject().getParameter().connectT(3, expr9);            // pma -> expr9::Value
		peak4.getParameter().connectT(0, pma);                               // peak4 -> pma::Value
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(0).connectT(0, add20);                     // simple_ar -> add20::Value
		global_cable48.getWrappedObject().getParameter().connectT(0, add37); // global_cable48 -> add37::Value
		global_cable49.getWrappedObject().getParameter().connectT(0, add38); // global_cable49 -> add38::Value
		global_cable50.getWrappedObject().getParameter().connectT(0, add39); // global_cable50 -> add39::Value
		global_cable51.getWrappedObject().getParameter().connectT(0, add40); // global_cable51 -> add40::Value
		global_cable52.getWrappedObject().getParameter().connectT(0, add41); // global_cable52 -> add41::Value
		global_cable53.getWrappedObject().getParameter().connectT(0, add42); // global_cable53 -> add42::Value
		global_cable56.getWrappedObject().getParameter().connectT(0, add45); // global_cable56 -> add45::Value
		global_cable57.getWrappedObject().getParameter().connectT(0, add46); // global_cable57 -> add46::Value
		global_cable58.getWrappedObject().getParameter().connectT(0, add47); // global_cable58 -> add47::Value
		global_cable59.getWrappedObject().getParameter().connectT(0, add48); // global_cable59 -> add48::Value
		global_cable60.getWrappedObject().getParameter().connectT(0, add49); // global_cable60 -> add49::Value
		global_cable61.getWrappedObject().getParameter().connectT(0, add50); // global_cable61 -> add50::Value
		global_cable62.getWrappedObject().getParameter().connectT(0, add51); // global_cable62 -> add51::Value
		global_cable63.getWrappedObject().getParameter().connectT(0, add52); // global_cable63 -> add52::Value
		peak6.getParameter().connectT(0, ramp);                              // peak6 -> ramp::Gate
		peak2.getParameter().connectT(0, global_cable54);                    // peak2 -> global_cable54::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch3::Index is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add17::Value is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch5::Index is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add22::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add23::Value is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add24::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add25::Value is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add35::Value is automated
		
		global_cable34.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add36::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // branch6::Index is automated
		
		add11.setParameterT(0, 1.); // math::add::Value
		
		simple_ar.setParameterT(0, 10.); // envelope::simple_ar::Attack
		simple_ar.setParameterT(1, 10.); // envelope::simple_ar::Release
		simple_ar.setParameterT(2, 0.);  // envelope::simple_ar::Gate
		simple_ar.setParameterT(3, 0.);  // envelope::simple_ar::AttackCurve
		
		; // add20::Value is automated
		
		global_cable48.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add37::Value is automated
		
		global_cable49.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add38::Value is automated
		
		global_cable50.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add39::Value is automated
		
		global_cable51.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add40::Value is automated
		
		global_cable52.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add41::Value is automated
		
		global_cable53.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add42::Value is automated
		
		global_cable56.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add45::Value is automated
		
		global_cable57.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add46::Value is automated
		
		global_cable58.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add47::Value is automated
		
		global_cable59.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add48::Value is automated
		
		global_cable60.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add49::Value is automated
		
		global_cable61.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add50::Value is automated
		
		global_cable62.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add51::Value is automated
		
		global_cable63.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add52::Value is automated
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // ramp::PeriodTime is automated
		; // ramp::LoopStart is automated
		; // ramp::Gate is automated
		
		fmod1.setParameterT(0, 0.614986); // math::fmod::Value
		
		; // branch::Index is automated
		
		pi5.setParameterT(0, 0.495527); // math::pi::Value
		
		sig2mod5.setParameterT(0, 0.); // math::sig2mod::Value
		
		mod2sig5.setParameterT(0, 0.0554316); // math::mod2sig::Value
		
		sin5.setParameterT(0, 1.); // math::sin::Value
		
		pi2.setParameterT(0, 1.); // math::pi::Value
		
		mod2sig1.setParameterT(0, 0.); // math::mod2sig::Value
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		pi1.setParameterT(0, 0.49445); // math::pi::Value
		
		clip1.setParameterT(0, 1.); // math::clip::Value
		
		sin1.setParameterT(0, 1.); // math::sin::Value
		
		square1.setParameterT(0, 0.); // math::square::Value
		
		sqrt.setParameterT(0, 0.135992); // math::sqrt::Value
		
		rect1.setParameterT(0, 0.166743); // math::rect::Value
		
		sig2mod4.setParameterT(0, 0.); // math::sig2mod::Value
		
		mod2sig.setParameterT(0, 0.); // math::mod2sig::Value
		
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
		
		; // add1::Value is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // branch1::Index is automated
		
		; // expr3::Value is automated
		
		; // expr5::Value is automated
		
		; // expr8::Value is automated
		
		; // expr9::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // global_cable54::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.00185413);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 5.6);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.232792);
		this->setParameterT(7, 0.000183472);
		this->setParameterT(8, 1.01622);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable14_t<NV>
		this->getT(0).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable17_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable19_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable20_t<NV>
		this->getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable21_t<NV>
		this->getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable22_t<NV>
		this->getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable23_t<NV>
		this->getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable24_t<NV>
		this->getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable25_t<NV>
		this->getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable26_t<NV>
		this->getT(1).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable27_t<NV>
		this->getT(1).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable28_t<NV>
		this->getT(1).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable29_t<NV>
		this->getT(1).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable30_t<NV>
		this->getT(1).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable31_t<NV>
		this->getT(1).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable32_t<NV>
		this->getT(1).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable33_t<NV>
		this->getT(1).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable34_t<NV>
		this->getT(3).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable48_t<NV>
		this->getT(3).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable49_t<NV>
		this->getT(3).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable50_t<NV>
		this->getT(3).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable51_t<NV>
		this->getT(3).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable52_t<NV>
		this->getT(3).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable53_t<NV>
		this->getT(3).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable56_t<NV>
		this->getT(3).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest5_impl::global_cable57_t<NV>
		this->getT(3).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable58_t<NV>
		this->getT(3).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable59_t<NV>
		this->getT(3).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable60_t<NV>
		this->getT(3).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable61_t<NV>
		this->getT(3).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable62_t<NV>
		this->getT(3).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // modtest5_impl::global_cable63_t<NV>
		this->getT(15).connectToRuntimeTarget(addConnection, c);                         // routing::global_cable<global_cable54_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(1).setExternalData(b, index);                 // modtest5_impl::peak1_t<NV>
		this->getT(1).getT(1).setExternalData(b, index);                 // modtest5_impl::peak4_t<NV>
		this->getT(3).getT(0).getT(1).getT(0).setExternalData(b, index); // modtest5_impl::simple_ar_t<NV>
		this->getT(3).getT(1).setExternalData(b, index);                 // modtest5_impl::peak6_t<NV>
		this->getT(7).setExternalData(b, index);                         // modtest5_impl::ramp_t<NV>
		this->getT(9).getT(3).getT(3).setExternalData(b, index);         // modtest5_impl::peak5_t
		this->getT(9).getT(4).getT(0).setExternalData(b, index);         // modtest5_impl::oscillator_t<NV>
		this->getT(9).getT(5).getT(1).setExternalData(b, index);         // modtest5_impl::cable_table_t<NV>
		this->getT(9).getT(6).getT(1).setExternalData(b, index);         // modtest5_impl::cable_pack_t<NV>
		this->getT(10).setExternalData(b, index);                        // modtest5_impl::peak_t
		this->getT(13).setExternalData(b, index);                        // modtest5_impl::peak2_t
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
using modtest5 = wrap::node<modtest5_impl::instance<NV>>;
}


