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

namespace xfade4_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(pma9_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using pma9_mod = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     pma9_modRange>;

template <int NV>
using pma9_t = control::pma<NV, pma9_mod<NV>>;
template <int NV>
using input_toggle16_t = control::input_toggle<parameter::plain<pma9_t<NV>, 2>>;
template <int NV>
using smoothed_parameter1_x4_t = wrap::mod<parameter::plain<input_toggle16_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter17_t = wrap::mod<parameter::plain<input_toggle16_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma8_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<smoothed_parameter1_x4_t<NV>, 0>, 
                                  parameter::plain<smoothed_parameter17_t<NV>, 0>>;

template <int NV>
using pma8_t = control::pma<NV, pma8_mod<NV>>;
DECLARE_PARAMETER_RANGE(xfader_x1_c3Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using xfader_x1_c3 = parameter::from0To1<pma8_t<NV>, 
                                         2, 
                                         xfader_x1_c3Range>;

template <int NV>
using xfader_x1_multimod = parameter::list<parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           xfader_x1_c3<NV>, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty>;

template <int NV>
using xfader_x1_t = control::xfader<xfader_x1_multimod<NV>, faders::switcher>;

template <int NV> using pma11_mod = pma9_mod<NV>;

template <int NV>
using pma11_t = control::pma<NV, pma11_mod<NV>>;
template <int NV>
using input_toggle2_t = control::input_toggle<parameter::plain<pma11_t<NV>, 2>>;
template <int NV>
using smoothed_parameter1_t = wrap::mod<parameter::plain<input_toggle2_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using smoothed_parameter1_x1_t = wrap::mod<parameter::plain<input_toggle2_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using pma10_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter1_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter1_x1_t<NV>, 0>>;

template <int NV>
using pma10_t = control::pma<NV, pma10_mod<NV>>;
template <int NV>
using xfader2_x1_c3 = parameter::from0To1<pma10_t<NV>, 
                                          2, 
                                          xfader_x1_c3Range>;

template <int NV>
using xfader2_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader2_x1_c3<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader2_x1_t = control::xfader<xfader2_x1_multimod<NV>, 
                                     faders::linear>;

template <int NV> using pma13_mod = pma9_mod<NV>;

template <int NV>
using pma13_t = control::pma<NV, pma13_mod<NV>>;
template <int NV>
using input_toggle4_t = control::input_toggle<parameter::plain<pma13_t<NV>, 2>>;
template <int NV>
using smoothed_parameter2_x1_t = wrap::mod<parameter::plain<input_toggle4_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter3_t = wrap::mod<parameter::plain<input_toggle4_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma12_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter2_x1_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter3_t<NV>, 0>>;

template <int NV>
using pma12_t = control::pma<NV, pma12_mod<NV>>;
template <int NV>
using xfader1_x1_c3 = parameter::from0To1<pma12_t<NV>, 
                                          2, 
                                          xfader_x1_c3Range>;

template <int NV>
using xfader1_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader1_x1_c3<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader1_x1_t = control::xfader<xfader1_x1_multimod<NV>, 
                                     faders::squared>;

template <int NV> using pma15_mod = pma9_mod<NV>;

template <int NV>
using pma15_t = control::pma<NV, pma15_mod<NV>>;
template <int NV>
using input_toggle5_t = control::input_toggle<parameter::plain<pma15_t<NV>, 2>>;
template <int NV>
using smoothed_parameter4_x1_t = wrap::mod<parameter::plain<input_toggle5_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter4_t = wrap::mod<parameter::plain<input_toggle5_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma17_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter4_x1_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter4_t<NV>, 0>>;

template <int NV>
using pma17_t = control::pma<NV, pma17_mod<NV>>;
template <int NV>
using xfader3_x1_c3 = parameter::from0To1<pma17_t<NV>, 
                                          2, 
                                          xfader_x1_c3Range>;

template <int NV>
using xfader3_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader3_x1_c3<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader3_x1_t = control::xfader<xfader3_x1_multimod<NV>, 
                                     faders::cosine>;

template <int NV> using pma16_mod = pma9_mod<NV>;

template <int NV>
using pma16_t = control::pma<NV, pma16_mod<NV>>;
template <int NV>
using input_toggle3_t = control::input_toggle<parameter::plain<pma16_t<NV>, 2>>;
template <int NV>
using smoothed_parameter3_x1_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter2_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma14_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter3_x1_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter2_t<NV>, 0>>;

template <int NV>
using pma14_t = control::pma<NV, pma14_mod<NV>>;
template <int NV>
using xfader4_x1_c3 = parameter::from0To1<pma14_t<NV>, 
                                          2, 
                                          xfader_x1_c3Range>;

template <int NV>
using xfader4_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader4_x1_c3<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader4_x1_t = control::xfader<xfader4_x1_multimod<NV>, 
                                     faders::threshold>;

template <int NV> using pma19_mod = pma9_mod<NV>;

template <int NV>
using pma19_t = control::pma<NV, pma19_mod<NV>>;
template <int NV>
using input_toggle6_t = control::input_toggle<parameter::plain<pma19_t<NV>, 2>>;
template <int NV>
using smoothed_parameter_x2_t = wrap::mod<parameter::plain<input_toggle6_t<NV>, 1>, 
                                          control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter5_t = wrap::mod<parameter::plain<input_toggle6_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma21_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter_x2_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter5_t<NV>, 0>>;

template <int NV>
using pma21_t = control::pma<NV, pma21_mod<NV>>;
template <int NV>
using xfader_x2_c3 = parameter::from0To1<pma21_t<NV>, 
                                         2, 
                                         xfader_x1_c3Range>;

template <int NV>
using xfader_x2_multimod = parameter::list<parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           xfader_x2_c3<NV>>;

template <int NV>
using xfader_x2_t = control::xfader<xfader_x2_multimod<NV>, faders::switcher>;

template <int NV> using pma20_mod = pma9_mod<NV>;

template <int NV>
using pma20_t = control::pma<NV, pma20_mod<NV>>;
template <int NV>
using input_toggle7_t = control::input_toggle<parameter::plain<pma20_t<NV>, 2>>;
template <int NV>
using smoothed_parameter6_t = wrap::mod<parameter::plain<input_toggle7_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using smoothed_parameter1_x2_t = wrap::mod<parameter::plain<input_toggle7_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using pma18_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter6_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter1_x2_t<NV>, 0>>;

template <int NV>
using pma18_t = control::pma<NV, pma18_mod<NV>>;
template <int NV>
using xfader2_x2_c3 = parameter::from0To1<pma18_t<NV>, 
                                          2, 
                                          xfader_x1_c3Range>;

template <int NV>
using xfader2_x2_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader2_x2_c3<NV>>;

template <int NV>
using xfader2_x2_t = control::xfader<xfader2_x2_multimod<NV>, 
                                     faders::linear>;

template <int NV> using pma23_mod = pma9_mod<NV>;

template <int NV>
using pma23_t = control::pma<NV, pma23_mod<NV>>;
template <int NV>
using input_toggle8_t = control::input_toggle<parameter::plain<pma23_t<NV>, 2>>;
template <int NV>
using smoothed_parameter2_x2_t = wrap::mod<parameter::plain<input_toggle8_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter7_t = wrap::mod<parameter::plain<input_toggle8_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma22_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter2_x2_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter7_t<NV>, 0>>;

template <int NV>
using pma22_t = control::pma<NV, pma22_mod<NV>>;
template <int NV>
using xfader1_x2_c3 = parameter::from0To1<pma22_t<NV>, 
                                          2, 
                                          xfader_x1_c3Range>;

template <int NV>
using xfader1_x2_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader1_x2_c3<NV>>;

template <int NV>
using xfader1_x2_t = control::xfader<xfader1_x2_multimod<NV>, 
                                     faders::squared>;

template <int NV> using pma25_mod = pma9_mod<NV>;

template <int NV>
using pma25_t = control::pma<NV, pma25_mod<NV>>;
template <int NV>
using input_toggle9_t = control::input_toggle<parameter::plain<pma25_t<NV>, 2>>;
template <int NV>
using smoothed_parameter4_x2_t = wrap::mod<parameter::plain<input_toggle9_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter8_t = wrap::mod<parameter::plain<input_toggle9_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma24_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter4_x2_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter8_t<NV>, 0>>;

template <int NV>
using pma24_t = control::pma<NV, pma24_mod<NV>>;
template <int NV>
using xfader3_x2_c3 = parameter::from0To1<pma24_t<NV>, 
                                          2, 
                                          xfader_x1_c3Range>;

template <int NV>
using xfader3_x2_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader3_x2_c3<NV>>;

template <int NV>
using xfader3_x2_t = control::xfader<xfader3_x2_multimod<NV>, 
                                     faders::cosine>;

template <int NV> using pma27_mod = pma9_mod<NV>;

template <int NV>
using pma27_t = control::pma<NV, pma27_mod<NV>>;
template <int NV>
using input_toggle10_t = control::input_toggle<parameter::plain<pma27_t<NV>, 2>>;
template <int NV>
using smoothed_parameter9_t = wrap::mod<parameter::plain<input_toggle10_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using smoothed_parameter3_x2_t = wrap::mod<parameter::plain<input_toggle10_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using pma26_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter9_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter3_x2_t<NV>, 0>>;

template <int NV>
using pma26_t = control::pma<NV, pma26_mod<NV>>;
template <int NV>
using xfader4_x2_c3 = parameter::from0To1<pma26_t<NV>, 
                                          2, 
                                          xfader_x1_c3Range>;

template <int NV>
using xfader4_x2_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader4_x2_c3<NV>>;

template <int NV>
using xfader4_x2_t = control::xfader<xfader4_x2_multimod<NV>, 
                                     faders::threshold>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<xfader_x1_t<NV>, 0>, 
                                 parameter::plain<xfader2_x1_t<NV>, 0>, 
                                 parameter::plain<xfader1_x1_t<NV>, 0>, 
                                 parameter::plain<xfader3_x1_t<NV>, 0>, 
                                 parameter::plain<xfader4_x1_t<NV>, 0>, 
                                 parameter::plain<xfader_x2_t<NV>, 0>, 
                                 parameter::plain<xfader2_x2_t<NV>, 0>, 
                                 parameter::plain<xfader1_x2_t<NV>, 0>, 
                                 parameter::plain<xfader3_x2_t<NV>, 0>, 
                                 parameter::plain<xfader4_x2_t<NV>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

template <int NV>
using pma3_t = control::pma<NV, 
                            parameter::plain<pma_t<NV>, 2>>;
template <int NV>
using midi_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                         control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_t<NV>>, 
                                  pma3_t<NV>>;

template <int NV>
using pma4_t = control::pma<NV, 
                            parameter::plain<pma3_t<NV>, 2>>;
template <int NV>
using midi1_t = wrap::mod<parameter::plain<pma4_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi1_t<NV>>, 
                                  pma4_t<NV>>;

template <int NV>
using pma5_t = control::pma<NV, 
                            parameter::plain<pma4_t<NV>, 2>>;
template <int NV>
using midi_cc_t = control::midi_cc<parameter::plain<pma5_t<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc_t<NV>>, 
                                  pma5_t<NV>>;

template <int NV>
using pma6_t = control::pma<NV, 
                            parameter::plain<pma5_t<NV>, 2>>;
template <int NV>
using midi_cc1_t = control::midi_cc<parameter::plain<pma6_t<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc1_t<NV>>, 
                                   pma6_t<NV>>;

using global_cable16_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
using global_cable18_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>>;
using global_cable19_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;
using global_cable20_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = runtime_target::indexers::fix_hash<104068263>;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain30_t<NV>>, 
                                    chain31_t<NV>, 
                                    chain32_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>, 
                                    chain37_t<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table11_modRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using cable_table11_mod = parameter::from0To1<branch3_t<NV>, 
                                              0, 
                                              cable_table11_modRange>;

struct cable_table11_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.00243765f, 0.00683218f, 0.0112267f, 0.0156212f,
		0.0200158f, 0.0244103f, 0.0288048f, 0.0331994f, 0.037594f, 0.0419886f,
		0.0463831f, 0.0507776f, 0.0551721f, 0.0595667f, 0.0639613f, 0.0683557f,
		0.0727504f, 0.077145f, 0.0815395f, 0.085934f, 0.0903286f, 0.0947231f,
		0.0991176f, 0.103512f, 0.107907f, 0.112301f, 0.116696f, 0.12109f,
		0.125485f, 0.129879f, 0.134274f, 0.138669f, 0.143063f, 0.147458f,
		0.151852f, 0.156247f, 0.160641f, 0.165036f, 0.16943f, 0.173825f,
		0.17822f, 0.182614f, 0.187009f, 0.191403f, 0.195798f, 0.200192f,
		0.204587f, 0.208981f, 0.213376f, 0.21777f, 0.222165f, 0.22656f,
		0.230954f, 0.235349f, 0.239743f, 0.244138f, 0.248532f, 0.252927f,
		0.257321f, 0.261716f, 0.26611f, 0.270505f, 0.2749f, 0.279294f,
		0.283689f, 0.288083f, 0.292478f, 0.296872f, 0.301267f, 0.305661f,
		0.310056f, 0.31445f, 0.318845f, 0.32324f, 0.327634f, 0.332029f,
		0.336423f, 0.340818f, 0.345212f, 0.349607f, 0.354002f, 0.358396f,
		0.362791f, 0.367185f, 0.37158f, 0.375974f, 0.380369f, 0.384763f,
		0.389158f, 0.393552f, 0.397947f, 0.402341f, 0.406736f, 0.411131f,
		0.415525f, 0.41992f, 0.424314f, 0.428709f, 0.433103f, 0.437498f,
		0.441892f, 0.446287f, 0.450681f, 0.455076f, 0.459471f, 0.463865f,
		0.46826f, 0.472654f, 0.477049f, 0.481443f, 0.485838f, 0.490232f,
		0.494627f, 0.499022f, 0.503416f, 0.507811f, 0.512205f, 0.5166f,
		0.520994f, 0.525389f, 0.529783f, 0.534178f, 0.538572f, 0.542967f,
		0.547362f, 0.551756f, 0.556151f, 0.560545f, 0.56494f, 0.569334f,
		0.573729f, 0.578123f, 0.582518f, 0.586912f, 0.591307f, 0.595702f,
		0.600096f, 0.604491f, 0.608885f, 0.61328f, 0.617674f, 0.622069f,
		0.626463f, 0.630858f, 0.635253f, 0.639647f, 0.644042f, 0.648436f,
		0.652831f, 0.657225f, 0.66162f, 0.666014f, 0.670409f, 0.674803f,
		0.679198f, 0.683593f, 0.687987f, 0.692382f, 0.696776f, 0.701171f,
		0.705565f, 0.70996f, 0.714354f, 0.718749f, 0.723144f, 0.727538f,
		0.731933f, 0.736327f, 0.740722f, 0.745116f, 0.749511f, 0.753905f,
		0.7583f, 0.762694f, 0.767089f, 0.771483f, 0.775878f, 0.780273f,
		0.784667f, 0.789062f, 0.793456f, 0.797851f, 0.802245f, 0.80664f,
		0.811035f, 0.815429f, 0.819824f, 0.824218f, 0.828613f, 0.833007f,
		0.837402f, 0.841796f, 0.846191f, 0.850585f, 0.85498f, 0.859374f,
		0.863769f, 0.868164f, 0.872558f, 0.876953f, 0.881347f, 0.885742f,
		0.890136f, 0.894531f, 0.898925f, 0.90332f, 0.907714f, 0.912109f,
		0.916504f, 0.920898f, 0.925293f, 0.929687f, 0.934082f, 0.938476f,
		0.942871f, 0.947265f, 0.95166f, 0.956055f, 0.960449f, 0.964844f,
		0.969238f, 0.973633f, 0.978027f, 0.982422f, 0.986816f, 0.991211f,
		0.995606f, 1.f
	};
};

template <int NV>
using cable_table11_t = wrap::data<control::cable_table<cable_table11_mod<NV>>, 
                                   data::embedded::table<cable_table11_t_data>>;

template <int NV>
using pma7_t = control::pma<NV, 
                            parameter::plain<pma6_t<NV>, 2>>;
template <int NV>
using input_toggle1x_t = control::input_toggle<parameter::plain<pma7_t<NV>, 0>>;

struct cable_table12_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.49707f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table12_t = wrap::data<control::cable_table<parameter::plain<input_toggle1x_t<NV>, 0>>, 
                                   data::embedded::table<cable_table12_t_data>>;

template <int NV>
using event_data_reader7_t = wrap::mod<parameter::plain<input_toggle1x_t<NV>, 1>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using peak2_t = wrap::mod<parameter::plain<input_toggle1x_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak2_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split21_t = container::split<parameter::empty, 
                                   wrap::fix<1, event_data_reader7_t<NV>>, 
                                   chain29_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table11_t<NV>>, 
                                   cable_table12_t<NV>, 
                                   split21_t<NV>, 
                                   input_toggle1x_t<NV>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain10_t<NV>>, 
                                   pma7_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain5_t<NV>>, 
                                  chain6_t<NV>, 
                                  chain9_t<NV>, 
                                  chain14_t<NV>, 
                                  chain25_t<NV>>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma_t<NV>>, 
                                   split7_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split19_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter1_x4_t<NV>>, 
                                   smoothed_parameter17_t<NV>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split20_t<NV>>, 
                                   input_toggle16_t<NV>, 
                                   pma9_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain1_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader_x1_t<NV>>, 
                                     pma8_t<NV>, 
                                     chain26_t<NV>>;

template <int NV>
using sb1_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain1_x1_t<NV>>>;

template <int NV>
using sb1_x1_t = bypass::smoothed<20, sb1_x1_t_<NV>>;
template <int NV>
using switcher_x1_c0 = parameter::bypass<sb1_x1_t<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter1_x1_t<NV>>, 
                                  smoothed_parameter1_t<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split4_t<NV>>, 
                                  input_toggle2_t<NV>, 
                                  pma11_t<NV>, 
                                  core::gain<NV>>;

template <int NV>
using chain3_x1_x1_t = container::chain<parameter::empty, 
                                        wrap::fix<2, xfader2_x1_t<NV>>, 
                                        pma10_t<NV>, 
                                        chain7_t<NV>>;

template <int NV>
using sb2_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain3_x1_x1_t<NV>>>;

template <int NV>
using sb2_x1_t = bypass::smoothed<20, sb2_x1_t_<NV>>;
template <int NV>
using switcher_x1_c1 = parameter::bypass<sb2_x1_t<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter2_x1_t<NV>>, 
                                  smoothed_parameter3_t<NV>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split6_t<NV>>, 
                                   input_toggle4_t<NV>>;

template <int NV>
using chain2_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader1_x1_t<NV>>, 
                                     pma12_t<NV>, 
                                     chain12_t<NV>, 
                                     pma13_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb3_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain2_x1_t<NV>>>;

template <int NV>
using sb3_x1_t = bypass::smoothed<20, sb3_x1_t_<NV>>;
template <int NV>
using switcher_x1_c2 = parameter::bypass<sb3_x1_t<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter4_x1_t<NV>>, 
                                  smoothed_parameter4_t<NV>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split8_t<NV>>, 
                                   input_toggle5_t<NV>, 
                                   pma15_t<NV>>;

template <int NV>
using chain4_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader3_x1_t<NV>>, 
                                     pma17_t<NV>, 
                                     chain13_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb4_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain4_x1_t<NV>>>;

template <int NV>
using sb4_x1_t = bypass::smoothed<20, sb4_x1_t_<NV>>;
template <int NV>
using switcher_x1_c3 = parameter::bypass<sb4_x1_t<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter3_x1_t<NV>>, 
                                  smoothed_parameter2_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split5_t<NV>>, 
                                   input_toggle3_t<NV>, 
                                   pma16_t<NV>>;

template <int NV>
using chain5_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader4_x1_t<NV>>, 
                                     pma14_t<NV>, 
                                     chain11_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb5_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain5_x1_t<NV>>>;

template <int NV>
using sb5_x1_t = bypass::smoothed<20, sb5_x1_t_<NV>>;
template <int NV>
using switcher_x1_c4 = parameter::bypass<sb5_x1_t<NV>>;

template <int NV>
using switcher_x1_multimod = parameter::list<switcher_x1_c0<NV>, 
                                             switcher_x1_c1<NV>, 
                                             switcher_x1_c2<NV>, 
                                             switcher_x1_c3<NV>, 
                                             switcher_x1_c4<NV>>;

template <int NV>
using switcher_x1_t = control::xfader<switcher_x1_multimod<NV>, 
                                      faders::switcher>;

template <int NV>
using sb_container_x1_t = container::chain<parameter::empty, 
                                           wrap::fix<2, sb1_x1_t<NV>>, 
                                           sb2_x1_t<NV>, 
                                           sb3_x1_t<NV>, 
                                           sb4_x1_t<NV>, 
                                           sb5_x1_t<NV>>;

template <int NV>
using x1_t = container::chain<parameter::empty, 
                              wrap::fix<2, switcher_x1_t<NV>>, 
                              sb_container_x1_t<NV>>;

template <int NV>
using sb3_t_ = container::chain<parameter::empty, wrap::fix<2, x1_t<NV>>>;

template <int NV>
using sb3_t = bypass::smoothed<20, sb3_t_<NV>>;
template <int NV>
using switcher1_c0 = parameter::bypass<sb3_t<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter_x2_t<NV>>, 
                                  smoothed_parameter5_t<NV>>;

template <int NV>
using chain1_x2_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader_x2_t<NV>>, 
                                     pma21_t<NV>, 
                                     split9_t<NV>, 
                                     input_toggle6_t<NV>, 
                                     pma19_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb1_x2_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain1_x2_t<NV>>>;

template <int NV>
using sb1_x2_t = bypass::smoothed<20, sb1_x2_t_<NV>>;
template <int NV>
using switcher_x2_c0 = parameter::bypass<sb1_x2_t<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter1_x2_t<NV>>, 
                                   smoothed_parameter6_t<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split10_t<NV>>, 
                                   input_toggle7_t<NV>>;

template <int NV>
using chain3_x1_x2_t = container::chain<parameter::empty, 
                                        wrap::fix<2, xfader2_x2_t<NV>>, 
                                        pma18_t<NV>, 
                                        chain15_t<NV>, 
                                        pma20_t<NV>, 
                                        core::gain<NV>>;

template <int NV>
using sb2_x2_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain3_x1_x2_t<NV>>>;

template <int NV>
using sb2_x2_t = bypass::smoothed<20, sb2_x2_t_<NV>>;
template <int NV>
using switcher_x2_c1 = parameter::bypass<sb2_x2_t<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter2_x2_t<NV>>, 
                                   smoothed_parameter7_t<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma22_t<NV>>, 
                                   split11_t<NV>, 
                                   input_toggle8_t<NV>, 
                                   pma23_t<NV>>;

template <int NV>
using chain2_x2_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader1_x2_t<NV>>, 
                                     chain16_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb3_x2_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain2_x2_t<NV>>>;

template <int NV>
using sb3_x2_t = bypass::smoothed<20, sb3_x2_t_<NV>>;
template <int NV>
using switcher_x2_c2 = parameter::bypass<sb3_x2_t<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter4_x2_t<NV>>, 
                                   smoothed_parameter8_t<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split12_t<NV>>, 
                                   input_toggle9_t<NV>, 
                                   pma25_t<NV>>;

template <int NV>
using chain4_x2_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader3_x2_t<NV>>, 
                                     pma24_t<NV>, 
                                     chain17_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb4_x2_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain4_x2_t<NV>>>;

template <int NV>
using sb4_x2_t = bypass::smoothed<20, sb4_x2_t_<NV>>;
template <int NV>
using switcher_x2_c3 = parameter::bypass<sb4_x2_t<NV>>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter3_x2_t<NV>>, 
                                   smoothed_parameter9_t<NV>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split13_t<NV>>, 
                                   input_toggle10_t<NV>, 
                                   pma27_t<NV>>;

template <int NV>
using chain5_x2_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader4_x2_t<NV>>, 
                                     pma26_t<NV>, 
                                     chain18_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb5_x2_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain5_x2_t<NV>>>;

template <int NV>
using sb5_x2_t = bypass::smoothed<20, sb5_x2_t_<NV>>;
template <int NV>
using switcher_x2_c4 = parameter::bypass<sb5_x2_t<NV>>;

template <int NV>
using switcher_x2_multimod = parameter::list<switcher_x2_c0<NV>, 
                                             switcher_x2_c1<NV>, 
                                             switcher_x2_c2<NV>, 
                                             switcher_x2_c3<NV>, 
                                             switcher_x2_c4<NV>>;

template <int NV>
using switcher_x2_t = control::xfader<switcher_x2_multimod<NV>, 
                                      faders::switcher>;

template <int NV>
using sb_container_x2_t = container::chain<parameter::empty, 
                                           wrap::fix<2, sb1_x2_t<NV>>, 
                                           sb2_x2_t<NV>, 
                                           sb3_x2_t<NV>, 
                                           sb4_x2_t<NV>, 
                                           sb5_x2_t<NV>>;

template <int NV>
using x2_t = container::chain<parameter::empty, 
                              wrap::fix<2, switcher_x2_t<NV>>, 
                              sb_container_x2_t<NV>>;

template <int NV>
using sb4_t_ = container::chain<parameter::empty, wrap::fix<2, x2_t<NV>>>;

template <int NV>
using sb4_t = bypass::smoothed<20, sb4_t_<NV>>;
template <int NV>
using switcher1_c1 = parameter::bypass<sb4_t<NV>>;

using sb5_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, core::empty>>;

using sb5_t = bypass::smoothed<20, sb5_t_>;
using switcher1_c2 = parameter::bypass<sb5_t>;

template <int NV>
using switcher1_multimod = parameter::list<switcher1_c0<NV>, 
                                           switcher1_c1<NV>, 
                                           switcher1_c2>;

template <int NV>
using switcher1_t = control::xfader<switcher1_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb3_t<NV>>, 
                                         sb4_t<NV>, 
                                         sb5_t>;

template <int NV>
using softbypass_switch4_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher1_t<NV>>, 
                                              sb_container1_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, softbypass_switch4_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

namespace XF1_t_parameters
{
// Parameter list for xfade4_impl::XF1_t -----------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(smooth_x1_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_STEP(smooth_x1_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth_x1_0 = parameter::from0To1<xfade4_impl::smoothed_parameter2_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_1 = parameter::from0To1<xfade4_impl::smoothed_parameter4_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_2 = parameter::from0To1<xfade4_impl::smoothed_parameter3_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_3 = parameter::from0To1<xfade4_impl::smoothed_parameter3_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_4 = parameter::from0To1<xfade4_impl::smoothed_parameter4_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_5 = parameter::from0To1<xfade4_impl::smoothed_parameter2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_6 = parameter::from0To1<xfade4_impl::smoothed_parameter_x2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_7 = parameter::from0To1<xfade4_impl::smoothed_parameter5_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_8 = parameter::from0To1<xfade4_impl::smoothed_parameter1_x2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_9 = parameter::from0To1<xfade4_impl::smoothed_parameter2_x2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_10 = parameter::from0To1<xfade4_impl::smoothed_parameter6_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_11 = parameter::from0To1<xfade4_impl::smoothed_parameter7_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_12 = parameter::from0To1<xfade4_impl::smoothed_parameter8_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_13 = parameter::from0To1<xfade4_impl::smoothed_parameter4_x2_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_14 = parameter::from0To1<xfade4_impl::smoothed_parameter3_x2_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_15 = parameter::from0To1<xfade4_impl::smoothed_parameter9_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_16 = parameter::from0To1<xfade4_impl::smoothed_parameter1_x4_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_17 = parameter::from0To1<xfade4_impl::smoothed_parameter17_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_18 = parameter::from0To1<xfade4_impl::smoothed_parameter1_x1_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_19 = parameter::from0To1<xfade4_impl::smoothed_parameter1_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1 = parameter::chain<smooth_x1_InputRange, 
                                   smooth_x1_0<NV>, 
                                   smooth_x1_1<NV>, 
                                   smooth_x1_2<NV>, 
                                   smooth_x1_3<NV>, 
                                   smooth_x1_4<NV>, 
                                   smooth_x1_5<NV>, 
                                   smooth_x1_6<NV>, 
                                   smooth_x1_7<NV>, 
                                   smooth_x1_8<NV>, 
                                   smooth_x1_9<NV>, 
                                   smooth_x1_10<NV>, 
                                   smooth_x1_11<NV>, 
                                   smooth_x1_12<NV>, 
                                   smooth_x1_13<NV>, 
                                   smooth_x1_14<NV>, 
                                   smooth_x1_15<NV>, 
                                   smooth_x1_16<NV>, 
                                   smooth_x1_17<NV>, 
                                   smooth_x1_18<NV>, 
                                   smooth_x1_19<NV>>;

template <int NV>
using SmoothType = parameter::chain<ranges::Identity, 
                                    parameter::plain<xfade4_impl::input_toggle2_t<NV>, 0>, 
                                    parameter::plain<xfade4_impl::input_toggle4_t<NV>, 0>, 
                                    parameter::plain<xfade4_impl::input_toggle5_t<NV>, 0>, 
                                    parameter::plain<xfade4_impl::input_toggle3_t<NV>, 0>, 
                                    parameter::plain<xfade4_impl::input_toggle6_t<NV>, 0>, 
                                    parameter::plain<xfade4_impl::input_toggle7_t<NV>, 0>, 
                                    parameter::plain<xfade4_impl::input_toggle8_t<NV>, 0>, 
                                    parameter::plain<xfade4_impl::input_toggle9_t<NV>, 0>, 
                                    parameter::plain<xfade4_impl::input_toggle10_t<NV>, 0>, 
                                    parameter::plain<xfade4_impl::input_toggle16_t<NV>, 0>>;

using mode_x1 = parameter::empty;
template <int NV>
using XF1_t_plist = parameter::list<smooth_x1<NV>, 
                                    mode_x1, 
                                    SmoothType<NV>>;
}

template <int NV>
using XF1_t = container::chain<XF1_t_parameters::XF1_t_plist<NV>, 
                               wrap::fix<2, fix8_block_t<NV>>>;

namespace xfade4_t_parameters
{
// Parameter list for xfade4_impl::xfade4_t --------------------------------------------------------

DECLARE_PARAMETER_RANGE(MainParam_InputRange, 
                        1., 
                        8.);
template <int NV>
using MainParam_0 = parameter::from0To1<xfade4_impl::pma7_t<NV>, 
                                        2, 
                                        xfade4_impl::xfader_x1_c3Range>;

template <int NV>
using MainParam = parameter::chain<MainParam_InputRange, MainParam_0<NV>>;

DECLARE_PARAMETER_RANGE(_3rdParam_InputRange, 
                        0., 
                        6.);

template <int NV>
using _3rdParam = parameter::chain<_3rdParam_InputRange, 
                                   parameter::plain<xfade4_impl::switcher_x1_t<NV>, 0>, 
                                   parameter::plain<xfade4_impl::switcher_x2_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(_5thParam_InputRange, 
                        0., 
                        2.);

template <int NV>
using _5thParam = parameter::chain<_5thParam_InputRange, 
                                   parameter::plain<xfade4_impl::switcher1_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(GlobalSrc_InputRange, 
                             0., 
                             16., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(GlobalSrc_2Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using GlobalSrc_2 = parameter::from0To1<xfade4_impl::event_data_reader7_t<NV>, 
                                        0, 
                                        GlobalSrc_2Range>;

template <int NV>
using GlobalSrc = parameter::chain<GlobalSrc_InputRange, 
                                   parameter::plain<xfade4_impl::cable_table11_t<NV>, 0>, 
                                   parameter::plain<xfade4_impl::cable_table12_t<NV>, 0>, 
                                   GlobalSrc_2<NV>>;

template <int NV>
using _2ndParam = parameter::plain<xfade4_impl::XF1_t<NV>, 0>;
template <int NV>
using _4thParam = parameter::plain<xfade4_impl::XF1_t<NV>, 2>;
using Env1 = parameter::empty;
using Env2 = Env1;
template <int NV>
using Poly = parameter::plain<xfade4_impl::pma_t<NV>, 1>;
template <int NV>
using Global = parameter::plain<xfade4_impl::pma7_t<NV>, 
                                1>;
template <int NV>
using Vel = parameter::plain<xfade4_impl::pma3_t<NV>, 
                             1>;
template <int NV>
using Trk = parameter::plain<xfade4_impl::pma4_t<NV>, 
                             1>;
template <int NV>
using MW = parameter::plain<xfade4_impl::pma5_t<NV>, 
                            1>;
template <int NV>
using AT = parameter::plain<xfade4_impl::pma6_t<NV>, 
                            1>;
template <int NV>
using xfade4_t_plist = parameter::list<MainParam<NV>, 
                                       _2ndParam<NV>, 
                                       _3rdParam<NV>, 
                                       _4thParam<NV>, 
                                       _5thParam<NV>, 
                                       Env1, 
                                       Env2, 
                                       Poly<NV>, 
                                       Global<NV>, 
                                       GlobalSrc<NV>, 
                                       Vel<NV>, 
                                       Trk<NV>, 
                                       MW<NV>, 
                                       AT<NV>>;
}

template <int NV>
using xfade4_t_ = container::chain<xfade4_t_parameters::xfade4_t_plist<NV>, 
                                   wrap::fix<2, modchain_t<NV>>, 
                                   XF1_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xfade4_impl::xfade4_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(xfade4);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(224)
		{
			0x005B, 0x0000, 0x4D00, 0x6961, 0x506E, 0x7261, 0x6D61, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0001, 0x0000, 0x325F, 0x646E, 0x6150, 0x6172, 
            0x006D, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 0x3FC0, 0x209B, 
            0x3E9A, 0xCCCD, 0x3DCC, 0x025B, 0x0000, 0x5F00, 0x7233, 0x5064, 
            0x7261, 0x6D61, 0x0000, 0x0000, 0x0000, 0xC000, 0x0040, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 0x345F, 
            0x6874, 0x6150, 0x6172, 0x006D, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 
            0x5F00, 0x7435, 0x5068, 0x7261, 0x6D61, 0x0000, 0x0000, 0x0000, 
            0x0000, 0xF240, 0x0C52, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0005, 0x0000, 0x6E45, 0x3176, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 
            0x0000, 0x6E45, 0x3276, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 
            0x6F50, 0x796C, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0008, 0x0000, 0x6C47, 
            0x626F, 0x6C61, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0009, 0x0000, 0x6C47, 
            0x626F, 0x6C61, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 0x4180, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 0x0A5B, 0x0000, 
            0x5600, 0x6C65, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000B, 0x0000, 0x7254, 
            0x006B, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0C5B, 0x0000, 0x4D00, 0x0057, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0D5B, 0x0000, 0x4100, 0x0054, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                           // xfade4_impl::modchain_t<NV>
		auto& split19 = this->getT(0).getT(0);                                                    // xfade4_impl::split19_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0);                                                // xfade4_impl::pma_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(1);                                             // xfade4_impl::split7_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(1).getT(0);                                     // xfade4_impl::chain5_t<NV>
		auto& midi = this->getT(0).getT(0).getT(1).getT(0).getT(0);                               // xfade4_impl::midi_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                               // xfade4_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(1);                                     // xfade4_impl::chain6_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                              // xfade4_impl::midi1_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                               // xfade4_impl::pma4_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(1).getT(2);                                     // xfade4_impl::chain9_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(1).getT(2).getT(0);                            // xfade4_impl::midi_cc_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                               // xfade4_impl::pma5_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(3);                                    // xfade4_impl::chain14_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                           // xfade4_impl::midi_cc1_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                               // xfade4_impl::pma6_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(4);                                    // xfade4_impl::chain25_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                            // xfade4_impl::chain10_t<NV>
		auto& cable_table11 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0);              // xfade4_impl::cable_table11_t<NV>
		auto& cable_table12 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(1);              // xfade4_impl::cable_table12_t<NV>
		auto& split21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(2);                    // xfade4_impl::split21_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(2).getT(0); // xfade4_impl::event_data_reader7_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(2).getT(1);            // xfade4_impl::chain29_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(1).getT(4).                                    // xfade4_impl::branch3_t<NV>
                        getT(0).getT(2).getT(1).getT(0);
		auto& chain30 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade4_impl::chain30_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(0);
		auto& global_cable16 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade4_impl::global_cable16_t<NV>
                               getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(0).getT(1);
		auto& chain31 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade4_impl::chain31_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(1);
		auto& global_cable17 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade4_impl::global_cable17_t<NV>
                               getT(2).getT(1).getT(0).getT(1).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(1).getT(1);
		auto& chain32 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade4_impl::chain32_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(2);
		auto& global_cable18 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade4_impl::global_cable18_t<NV>
                               getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(2).getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade4_impl::chain33_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(3);
		auto& global_cable19 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade4_impl::global_cable19_t<NV>
                               getT(2).getT(1).getT(0).getT(3).getT(0);
		auto& add19 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(3).getT(1);
		auto& chain34 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade4_impl::chain34_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(4);
		auto& global_cable20 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade4_impl::global_cable20_t<NV>
                               getT(2).getT(1).getT(0).getT(4).getT(0);
		auto& add20 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(4).getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade4_impl::chain35_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(5);
		auto& global_cable21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade4_impl::global_cable21_t<NV>
                               getT(2).getT(1).getT(0).getT(5).getT(0);
		auto& add21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(5).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade4_impl::chain36_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(6);
		auto& global_cable22 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade4_impl::global_cable22_t<NV>
                               getT(2).getT(1).getT(0).getT(6).getT(0);
		auto& add22 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(6).getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade4_impl::chain37_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(7);
		auto& global_cable23 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade4_impl::global_cable23_t<NV>
                               getT(2).getT(1).getT(0).getT(7).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(7).getT(1);
		auto& peak2 = this->getT(0).getT(0).getT(1).getT(4).                                   // xfade4_impl::peak2_t<NV>
                      getT(0).getT(2).getT(1).getT(1);
		auto& clear = this->getT(0).getT(0).getT(1).getT(4).                                   // math::clear<NV>
                      getT(0).getT(2).getT(1).getT(2);
		auto& input_toggle1x = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(3);          // xfade4_impl::input_toggle1x_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                            // xfade4_impl::pma7_t<NV>
		auto& XF1 = this->getT(1);                                                             // xfade4_impl::XF1_t<NV>
		auto& fix8_block = this->getT(1).getT(0);                                              // xfade4_impl::fix8_block_t<NV>
		auto& softbypass_switch4 = this->getT(1).getT(0).getT(0);                              // xfade4_impl::softbypass_switch4_t<NV>
		auto& switcher1 = this->getT(1).getT(0).getT(0).getT(0);                               // xfade4_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(1).getT(0).getT(0).getT(1);                           // xfade4_impl::sb_container1_t<NV>
		auto& sb3 = this->getT(1).getT(0).getT(0).getT(1).getT(0);                             // xfade4_impl::sb3_t<NV>
		auto& x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0);                      // xfade4_impl::x1_t<NV>
		auto& switcher_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);     // xfade4_impl::switcher_x1_t<NV>
		auto& sb_container_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1); // xfade4_impl::sb_container_x1_t<NV>
		auto& sb1_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb1_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(0);
		auto& chain1_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade4_impl::chain1_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(0).
                          getT(0);
		auto& xfader_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                       // xfade4_impl::xfader_x1_t<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& pma8 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade4_impl::pma8_t<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& chain26 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade4_impl::chain26_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2);
		auto& split20 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade4_impl::split20_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter1_x4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade4_impl::smoothed_parameter1_x4_t<NV>
                                       getT(1).getT(0).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).    // xfade4_impl::smoothed_parameter17_t<NV>
                                     getT(1).getT(0).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                  // xfade4_impl::input_toggle16_t<NV>
                               getT(0).getT(1).getT(0).getT(0).getT(2).
                               getT(1);
		auto& pma9 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade4_impl::pma9_t<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(2).
                     getT(2);
		auto& gain16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).
                       getT(3);
		auto& sb2_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb2_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& chain3_x1_x1 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade4_impl::chain3_x1_x1_t<NV>
                             getT(0).getT(0).getT(1).getT(1).
                             getT(0);
		auto& xfader2_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade4_impl::xfader2_x1_t<NV>
                           getT(0).getT(1).getT(1).getT(0).getT(0);
		auto& pma10 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade4_impl::pma10_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(1);
		auto& chain7 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade4_impl::chain7_t<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2);
		auto& split4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade4_impl::split4_t<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter1_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade4_impl::smoothed_parameter1_x1_t<NV>
                                       getT(1).getT(1).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade4_impl::smoothed_parameter1_t<NV>
                                    getT(1).getT(1).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade4_impl::input_toggle2_t<NV>
                              getT(0).getT(1).getT(1).getT(0).getT(2).
                              getT(1);
		auto& pma11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade4_impl::pma11_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(2).
                      getT(2);
		auto& gain1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(2).
                      getT(3);
		auto& sb3_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb3_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(2);
		auto& chain2_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade4_impl::chain2_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(2).
                          getT(0);
		auto& xfader1_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade4_impl::xfader1_x1_t<NV>
                           getT(0).getT(1).getT(2).getT(0).getT(0);
		auto& pma12 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade4_impl::pma12_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(1);
		auto& chain12 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade4_impl::chain12_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(2);
		auto& split6 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade4_impl::split6_t<NV>
                       getT(0).getT(1).getT(2).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter2_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade4_impl::smoothed_parameter2_x1_t<NV>
                                       getT(1).getT(2).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade4_impl::smoothed_parameter3_t<NV>
                                    getT(1).getT(2).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade4_impl::input_toggle4_t<NV>
                              getT(0).getT(1).getT(2).getT(0).getT(2).
                              getT(1);
		auto& pma13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade4_impl::pma13_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(3);
		auto& gain2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(4);
		auto& sb4_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb4_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(3);
		auto& chain4_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade4_impl::chain4_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& xfader3_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade4_impl::xfader3_x1_t<NV>
                           getT(0).getT(1).getT(3).getT(0).getT(0);
		auto& pma17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade4_impl::pma17_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(1);
		auto& chain13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade4_impl::chain13_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(2);
		auto& split8 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade4_impl::split8_t<NV>
                       getT(0).getT(1).getT(3).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter4_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade4_impl::smoothed_parameter4_x1_t<NV>
                                       getT(1).getT(3).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade4_impl::smoothed_parameter4_t<NV>
                                    getT(1).getT(3).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade4_impl::input_toggle5_t<NV>
                              getT(0).getT(1).getT(3).getT(0).getT(2).
                              getT(1);
		auto& pma15 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade4_impl::pma15_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(2).
                      getT(2);
		auto& gain3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(3);
		auto& sb5_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb5_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(4);
		auto& chain5_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade4_impl::chain5_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& xfader4_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade4_impl::xfader4_x1_t<NV>
                           getT(0).getT(1).getT(4).getT(0).getT(0);
		auto& pma14 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade4_impl::pma14_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(1);
		auto& chain11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade4_impl::chain11_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2);
		auto& split5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade4_impl::split5_t<NV>
                       getT(0).getT(1).getT(4).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter3_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade4_impl::smoothed_parameter3_x1_t<NV>
                                       getT(1).getT(4).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade4_impl::smoothed_parameter2_t<NV>
                                    getT(1).getT(4).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade4_impl::input_toggle3_t<NV>
                              getT(0).getT(1).getT(4).getT(0).getT(2).
                              getT(1);
		auto& pma16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade4_impl::pma16_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(2).
                      getT(2);
		auto& gain4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(3);
		auto& sb4 = this->getT(1).getT(0).getT(0).getT(1).getT(1);                             // xfade4_impl::sb4_t<NV>
		auto& x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0);                      // xfade4_impl::x2_t<NV>
		auto& switcher_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).getT(0);     // xfade4_impl::switcher_x2_t<NV>
		auto& sb_container_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).getT(1); // xfade4_impl::sb_container_x2_t<NV>
		auto& sb1_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb1_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(0);
		auto& chain1_x2 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade4_impl::chain1_x2_t<NV>
                          getT(1).getT(0).getT(1).getT(0).
                          getT(0);
		auto& xfader_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                       // xfade4_impl::xfader_x2_t<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& pma21 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade4_impl::pma21_t<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& split9 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                          // xfade4_impl::split9_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2);
		auto& smoothed_parameter_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).           // xfade4_impl::smoothed_parameter_x2_t<NV>
                                      getT(0).getT(1).getT(0).getT(0).getT(2).
                                      getT(0);
		auto& smoothed_parameter5 = this->getT(1).getT(0).getT(0).getT(1).getT(1).             // xfade4_impl::smoothed_parameter5_t<NV>
                                    getT(0).getT(1).getT(0).getT(0).getT(2).
                                    getT(1);
		auto& input_toggle6 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                   // xfade4_impl::input_toggle6_t<NV>
                              getT(0).getT(1).getT(0).getT(0).getT(3);
		auto& pma19 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade4_impl::pma19_t<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(4);
		auto& gain5 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // core::gain<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(5);
		auto& sb2_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb2_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(1);
		auto& chain3_x1_x2 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade4_impl::chain3_x1_x2_t<NV>
                             getT(1).getT(0).getT(1).getT(1).
                             getT(0);
		auto& xfader2_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                      // xfade4_impl::xfader2_x2_t<NV>
                           getT(0).getT(1).getT(1).getT(0).getT(0);
		auto& pma18 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade4_impl::pma18_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(1);
		auto& chain15 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade4_impl::chain15_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2);
		auto& split10 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade4_impl::split10_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter1_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade4_impl::smoothed_parameter1_x2_t<NV>
                                       getT(1).getT(1).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter6 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).     // xfade4_impl::smoothed_parameter6_t<NV>
                                    getT(1).getT(1).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle7 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                   // xfade4_impl::input_toggle7_t<NV>
                              getT(0).getT(1).getT(1).getT(0).getT(2).
                              getT(1);
		auto& pma20 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade4_impl::pma20_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(3);
		auto& gain6 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // core::gain<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(4);
		auto& sb3_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb3_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(2);
		auto& chain2_x2 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade4_impl::chain2_x2_t<NV>
                          getT(1).getT(0).getT(1).getT(2).
                          getT(0);
		auto& xfader1_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                      // xfade4_impl::xfader1_x2_t<NV>
                           getT(0).getT(1).getT(2).getT(0).getT(0);
		auto& chain16 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade4_impl::chain16_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(1);
		auto& pma22 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade4_impl::pma22_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(1).
                      getT(0);
		auto& split11 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade4_impl::split11_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(1).
                        getT(1);
		auto& smoothed_parameter2_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade4_impl::smoothed_parameter2_x2_t<NV>
                                       getT(1).getT(2).getT(0).getT(1).getT(1).getT(0);
		auto& smoothed_parameter7 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).     // xfade4_impl::smoothed_parameter7_t<NV>
                                    getT(1).getT(2).getT(0).getT(1).getT(1).getT(1);
		auto& input_toggle8 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                   // xfade4_impl::input_toggle8_t<NV>
                              getT(0).getT(1).getT(2).getT(0).getT(1).
                              getT(2);
		auto& pma23 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade4_impl::pma23_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(1).
                      getT(3);
		auto& gain7 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // core::gain<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(2);
		auto& sb4_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb4_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(3);
		auto& chain4_x2 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade4_impl::chain4_x2_t<NV>
                          getT(1).getT(0).getT(1).getT(3).
                          getT(0);
		auto& xfader3_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                      // xfade4_impl::xfader3_x2_t<NV>
                           getT(0).getT(1).getT(3).getT(0).getT(0);
		auto& pma24 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade4_impl::pma24_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(1);
		auto& chain17 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade4_impl::chain17_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(2);
		auto& split12 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade4_impl::split12_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter4_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade4_impl::smoothed_parameter4_x2_t<NV>
                                       getT(1).getT(3).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter8 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).     // xfade4_impl::smoothed_parameter8_t<NV>
                                    getT(1).getT(3).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle9 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                   // xfade4_impl::input_toggle9_t<NV>
                              getT(0).getT(1).getT(3).getT(0).getT(2).
                              getT(1);
		auto& pma25 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade4_impl::pma25_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(2).
                      getT(2);
		auto& gain8 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // core::gain<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(3);
		auto& sb5_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade4_impl::sb5_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(4);
		auto& chain5_x2 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade4_impl::chain5_x2_t<NV>
                          getT(1).getT(0).getT(1).getT(4).
                          getT(0);
		auto& xfader4_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                      // xfade4_impl::xfader4_x2_t<NV>
                           getT(0).getT(1).getT(4).getT(0).getT(0);
		auto& pma26 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade4_impl::pma26_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(1);
		auto& chain18 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade4_impl::chain18_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2);
		auto& split13 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade4_impl::split13_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter3_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade4_impl::smoothed_parameter3_x2_t<NV>
                                       getT(1).getT(4).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter9 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade4_impl::smoothed_parameter9_t<NV>
                                    getT(1).getT(4).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle10 = this->getT(1).getT(0).getT(0).getT(1).getT(1).  // xfade4_impl::input_toggle10_t<NV>
                               getT(0).getT(1).getT(4).getT(0).getT(2).
                               getT(1);
		auto& pma27 = this->getT(1).getT(0).getT(0).getT(1).getT(1).  // xfade4_impl::pma27_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(2).
                      getT(2);
		auto& gain9 = this->getT(1).getT(0).getT(0).getT(1).getT(1).  // core::gain<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(3);
		auto& sb5 = this->getT(1).getT(0).getT(0).getT(1).getT(2); // xfade4_impl::sb5_t
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& smooth_x1_p = XF1.getParameterT(0);
		smooth_x1_p.connectT(0, smoothed_parameter2_x1);  // smooth_x1 -> smoothed_parameter2_x1::SmoothingTime
		smooth_x1_p.connectT(1, smoothed_parameter4_x1);  // smooth_x1 -> smoothed_parameter4_x1::SmoothingTime
		smooth_x1_p.connectT(2, smoothed_parameter3_x1);  // smooth_x1 -> smoothed_parameter3_x1::SmoothingTime
		smooth_x1_p.connectT(3, smoothed_parameter3);     // smooth_x1 -> smoothed_parameter3::SmoothingTime
		smooth_x1_p.connectT(4, smoothed_parameter4);     // smooth_x1 -> smoothed_parameter4::SmoothingTime
		smooth_x1_p.connectT(5, smoothed_parameter2);     // smooth_x1 -> smoothed_parameter2::SmoothingTime
		smooth_x1_p.connectT(6, smoothed_parameter_x2);   // smooth_x1 -> smoothed_parameter_x2::SmoothingTime
		smooth_x1_p.connectT(7, smoothed_parameter5);     // smooth_x1 -> smoothed_parameter5::SmoothingTime
		smooth_x1_p.connectT(8, smoothed_parameter1_x2);  // smooth_x1 -> smoothed_parameter1_x2::SmoothingTime
		smooth_x1_p.connectT(9, smoothed_parameter2_x2);  // smooth_x1 -> smoothed_parameter2_x2::SmoothingTime
		smooth_x1_p.connectT(10, smoothed_parameter6);    // smooth_x1 -> smoothed_parameter6::SmoothingTime
		smooth_x1_p.connectT(11, smoothed_parameter7);    // smooth_x1 -> smoothed_parameter7::SmoothingTime
		smooth_x1_p.connectT(12, smoothed_parameter8);    // smooth_x1 -> smoothed_parameter8::SmoothingTime
		smooth_x1_p.connectT(13, smoothed_parameter4_x2); // smooth_x1 -> smoothed_parameter4_x2::SmoothingTime
		smooth_x1_p.connectT(14, smoothed_parameter3_x2); // smooth_x1 -> smoothed_parameter3_x2::SmoothingTime
		smooth_x1_p.connectT(15, smoothed_parameter9);    // smooth_x1 -> smoothed_parameter9::SmoothingTime
		smooth_x1_p.connectT(16, smoothed_parameter1_x4); // smooth_x1 -> smoothed_parameter1_x4::SmoothingTime
		smooth_x1_p.connectT(17, smoothed_parameter17);   // smooth_x1 -> smoothed_parameter17::SmoothingTime
		smooth_x1_p.connectT(18, smoothed_parameter1_x1); // smooth_x1 -> smoothed_parameter1_x1::SmoothingTime
		smooth_x1_p.connectT(19, smoothed_parameter1);    // smooth_x1 -> smoothed_parameter1::SmoothingTime
		
		auto& SmoothType_p = XF1.getParameterT(2);
		SmoothType_p.connectT(0, input_toggle2);  // SmoothType -> input_toggle2::Input
		SmoothType_p.connectT(1, input_toggle4);  // SmoothType -> input_toggle4::Input
		SmoothType_p.connectT(2, input_toggle5);  // SmoothType -> input_toggle5::Input
		SmoothType_p.connectT(3, input_toggle3);  // SmoothType -> input_toggle3::Input
		SmoothType_p.connectT(4, input_toggle6);  // SmoothType -> input_toggle6::Input
		SmoothType_p.connectT(5, input_toggle7);  // SmoothType -> input_toggle7::Input
		SmoothType_p.connectT(6, input_toggle8);  // SmoothType -> input_toggle8::Input
		SmoothType_p.connectT(7, input_toggle9);  // SmoothType -> input_toggle9::Input
		SmoothType_p.connectT(8, input_toggle10); // SmoothType -> input_toggle10::Input
		SmoothType_p.connectT(9, input_toggle16); // SmoothType -> input_toggle16::Input
		this->getParameterT(0).connectT(0, pma7); // MainParam -> pma7::Add
		
		this->getParameterT(1).connectT(0, XF1); // _2ndParam -> XF1::smooth_x1
		
		auto& _3rdParam_p = this->getParameterT(2);
		_3rdParam_p.connectT(0, switcher_x1); // _3rdParam -> switcher_x1::Value
		_3rdParam_p.connectT(1, switcher_x2); // _3rdParam -> switcher_x2::Value
		
		this->getParameterT(3).connectT(0, XF1); // _4thParam -> XF1::SmoothType
		
		this->getParameterT(4).connectT(0, switcher1); // _5thParam -> switcher1::Value
		
		this->getParameterT(7).connectT(0, pma); // Poly -> pma::Multiply
		
		this->getParameterT(8).connectT(0, pma7); // Global -> pma7::Multiply
		
		auto& GlobalSrc_p = this->getParameterT(9);
		GlobalSrc_p.connectT(0, cable_table11);      // GlobalSrc -> cable_table11::Value
		GlobalSrc_p.connectT(1, cable_table12);      // GlobalSrc -> cable_table12::Value
		GlobalSrc_p.connectT(2, event_data_reader7); // GlobalSrc -> event_data_reader7::SlotIndex
		
		this->getParameterT(10).connectT(0, pma3); // Vel -> pma3::Multiply
		
		this->getParameterT(11).connectT(0, pma4); // Trk -> pma4::Multiply
		
		this->getParameterT(12).connectT(0, pma5); // MW -> pma5::Multiply
		
		this->getParameterT(13).connectT(0, pma6); // AT -> pma6::Multiply
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma9.getWrappedObject().getParameter().connectT(0, gain16);                 // pma9 -> gain16::Gain
		input_toggle16.getWrappedObject().getParameter().connectT(0, pma9);         // input_toggle16 -> pma9::Add
		smoothed_parameter1_x4.getParameter().connectT(0, input_toggle16);          // smoothed_parameter1_x4 -> input_toggle16::Value1
		smoothed_parameter17.getParameter().connectT(0, input_toggle16);            // smoothed_parameter17 -> input_toggle16::Value2
		pma8.getWrappedObject().getParameter().connectT(0, smoothed_parameter1_x4); // pma8 -> smoothed_parameter1_x4::Value
		pma8.getWrappedObject().getParameter().connectT(1, smoothed_parameter17);   // pma8 -> smoothed_parameter17::Value
		auto& xfader_x1_p = xfader_x1.getWrappedObject().getParameter();
		xfader_x1_p.getParameterT(3).connectT(0, pma8);                              // xfader_x1 -> pma8::Add
		pma11.getWrappedObject().getParameter().connectT(0, gain1);                  // pma11 -> gain1::Gain
		input_toggle2.getWrappedObject().getParameter().connectT(0, pma11);          // input_toggle2 -> pma11::Add
		smoothed_parameter1.getParameter().connectT(0, input_toggle2);               // smoothed_parameter1 -> input_toggle2::Value2
		smoothed_parameter1_x1.getParameter().connectT(0, input_toggle2);            // smoothed_parameter1_x1 -> input_toggle2::Value1
		pma10.getWrappedObject().getParameter().connectT(0, smoothed_parameter1);    // pma10 -> smoothed_parameter1::Value
		pma10.getWrappedObject().getParameter().connectT(1, smoothed_parameter1_x1); // pma10 -> smoothed_parameter1_x1::Value
		auto& xfader2_x1_p = xfader2_x1.getWrappedObject().getParameter();
		xfader2_x1_p.getParameterT(3).connectT(0, pma10);                            // xfader2_x1 -> pma10::Add
		pma13.getWrappedObject().getParameter().connectT(0, gain2);                  // pma13 -> gain2::Gain
		input_toggle4.getWrappedObject().getParameter().connectT(0, pma13);          // input_toggle4 -> pma13::Add
		smoothed_parameter2_x1.getParameter().connectT(0, input_toggle4);            // smoothed_parameter2_x1 -> input_toggle4::Value1
		smoothed_parameter3.getParameter().connectT(0, input_toggle4);               // smoothed_parameter3 -> input_toggle4::Value2
		pma12.getWrappedObject().getParameter().connectT(0, smoothed_parameter2_x1); // pma12 -> smoothed_parameter2_x1::Value
		pma12.getWrappedObject().getParameter().connectT(1, smoothed_parameter3);    // pma12 -> smoothed_parameter3::Value
		auto& xfader1_x1_p = xfader1_x1.getWrappedObject().getParameter();
		xfader1_x1_p.getParameterT(3).connectT(0, pma12);                            // xfader1_x1 -> pma12::Add
		pma15.getWrappedObject().getParameter().connectT(0, gain3);                  // pma15 -> gain3::Gain
		input_toggle5.getWrappedObject().getParameter().connectT(0, pma15);          // input_toggle5 -> pma15::Add
		smoothed_parameter4_x1.getParameter().connectT(0, input_toggle5);            // smoothed_parameter4_x1 -> input_toggle5::Value1
		smoothed_parameter4.getParameter().connectT(0, input_toggle5);               // smoothed_parameter4 -> input_toggle5::Value2
		pma17.getWrappedObject().getParameter().connectT(0, smoothed_parameter4_x1); // pma17 -> smoothed_parameter4_x1::Value
		pma17.getWrappedObject().getParameter().connectT(1, smoothed_parameter4);    // pma17 -> smoothed_parameter4::Value
		auto& xfader3_x1_p = xfader3_x1.getWrappedObject().getParameter();
		xfader3_x1_p.getParameterT(3).connectT(0, pma17);                            // xfader3_x1 -> pma17::Add
		pma16.getWrappedObject().getParameter().connectT(0, gain4);                  // pma16 -> gain4::Gain
		input_toggle3.getWrappedObject().getParameter().connectT(0, pma16);          // input_toggle3 -> pma16::Add
		smoothed_parameter3_x1.getParameter().connectT(0, input_toggle3);            // smoothed_parameter3_x1 -> input_toggle3::Value1
		smoothed_parameter2.getParameter().connectT(0, input_toggle3);               // smoothed_parameter2 -> input_toggle3::Value2
		pma14.getWrappedObject().getParameter().connectT(0, smoothed_parameter3_x1); // pma14 -> smoothed_parameter3_x1::Value
		pma14.getWrappedObject().getParameter().connectT(1, smoothed_parameter2);    // pma14 -> smoothed_parameter2::Value
		auto& xfader4_x1_p = xfader4_x1.getWrappedObject().getParameter();
		xfader4_x1_p.getParameterT(3).connectT(0, pma14);                           // xfader4_x1 -> pma14::Add
		pma19.getWrappedObject().getParameter().connectT(0, gain5);                 // pma19 -> gain5::Gain
		input_toggle6.getWrappedObject().getParameter().connectT(0, pma19);         // input_toggle6 -> pma19::Add
		smoothed_parameter_x2.getParameter().connectT(0, input_toggle6);            // smoothed_parameter_x2 -> input_toggle6::Value1
		smoothed_parameter5.getParameter().connectT(0, input_toggle6);              // smoothed_parameter5 -> input_toggle6::Value2
		pma21.getWrappedObject().getParameter().connectT(0, smoothed_parameter_x2); // pma21 -> smoothed_parameter_x2::Value
		pma21.getWrappedObject().getParameter().connectT(1, smoothed_parameter5);   // pma21 -> smoothed_parameter5::Value
		auto& xfader_x2_p = xfader_x2.getWrappedObject().getParameter();
		xfader_x2_p.getParameterT(3).connectT(0, pma21);                             // xfader_x2 -> pma21::Add
		pma20.getWrappedObject().getParameter().connectT(0, gain6);                  // pma20 -> gain6::Gain
		input_toggle7.getWrappedObject().getParameter().connectT(0, pma20);          // input_toggle7 -> pma20::Add
		smoothed_parameter6.getParameter().connectT(0, input_toggle7);               // smoothed_parameter6 -> input_toggle7::Value2
		smoothed_parameter1_x2.getParameter().connectT(0, input_toggle7);            // smoothed_parameter1_x2 -> input_toggle7::Value1
		pma18.getWrappedObject().getParameter().connectT(0, smoothed_parameter6);    // pma18 -> smoothed_parameter6::Value
		pma18.getWrappedObject().getParameter().connectT(1, smoothed_parameter1_x2); // pma18 -> smoothed_parameter1_x2::Value
		auto& xfader2_x2_p = xfader2_x2.getWrappedObject().getParameter();
		xfader2_x2_p.getParameterT(3).connectT(0, pma18);                            // xfader2_x2 -> pma18::Add
		pma23.getWrappedObject().getParameter().connectT(0, gain7);                  // pma23 -> gain7::Gain
		input_toggle8.getWrappedObject().getParameter().connectT(0, pma23);          // input_toggle8 -> pma23::Add
		smoothed_parameter2_x2.getParameter().connectT(0, input_toggle8);            // smoothed_parameter2_x2 -> input_toggle8::Value1
		smoothed_parameter7.getParameter().connectT(0, input_toggle8);               // smoothed_parameter7 -> input_toggle8::Value2
		pma22.getWrappedObject().getParameter().connectT(0, smoothed_parameter2_x2); // pma22 -> smoothed_parameter2_x2::Value
		pma22.getWrappedObject().getParameter().connectT(1, smoothed_parameter7);    // pma22 -> smoothed_parameter7::Value
		auto& xfader1_x2_p = xfader1_x2.getWrappedObject().getParameter();
		xfader1_x2_p.getParameterT(3).connectT(0, pma22);                            // xfader1_x2 -> pma22::Add
		pma25.getWrappedObject().getParameter().connectT(0, gain8);                  // pma25 -> gain8::Gain
		input_toggle9.getWrappedObject().getParameter().connectT(0, pma25);          // input_toggle9 -> pma25::Add
		smoothed_parameter4_x2.getParameter().connectT(0, input_toggle9);            // smoothed_parameter4_x2 -> input_toggle9::Value1
		smoothed_parameter8.getParameter().connectT(0, input_toggle9);               // smoothed_parameter8 -> input_toggle9::Value2
		pma24.getWrappedObject().getParameter().connectT(0, smoothed_parameter4_x2); // pma24 -> smoothed_parameter4_x2::Value
		pma24.getWrappedObject().getParameter().connectT(1, smoothed_parameter8);    // pma24 -> smoothed_parameter8::Value
		auto& xfader3_x2_p = xfader3_x2.getWrappedObject().getParameter();
		xfader3_x2_p.getParameterT(3).connectT(0, pma24);                            // xfader3_x2 -> pma24::Add
		pma27.getWrappedObject().getParameter().connectT(0, gain9);                  // pma27 -> gain9::Gain
		input_toggle10.getWrappedObject().getParameter().connectT(0, pma27);         // input_toggle10 -> pma27::Add
		smoothed_parameter9.getParameter().connectT(0, input_toggle10);              // smoothed_parameter9 -> input_toggle10::Value2
		smoothed_parameter3_x2.getParameter().connectT(0, input_toggle10);           // smoothed_parameter3_x2 -> input_toggle10::Value1
		pma26.getWrappedObject().getParameter().connectT(0, smoothed_parameter9);    // pma26 -> smoothed_parameter9::Value
		pma26.getWrappedObject().getParameter().connectT(1, smoothed_parameter3_x2); // pma26 -> smoothed_parameter3_x2::Value
		auto& xfader4_x2_p = xfader4_x2.getWrappedObject().getParameter();
		xfader4_x2_p.getParameterT(3).connectT(0, pma26);                            // xfader4_x2 -> pma26::Add
		pma.getWrappedObject().getParameter().connectT(0, xfader_x1);                // pma -> xfader_x1::Value
		pma.getWrappedObject().getParameter().connectT(1, xfader2_x1);               // pma -> xfader2_x1::Value
		pma.getWrappedObject().getParameter().connectT(2, xfader1_x1);               // pma -> xfader1_x1::Value
		pma.getWrappedObject().getParameter().connectT(3, xfader3_x1);               // pma -> xfader3_x1::Value
		pma.getWrappedObject().getParameter().connectT(4, xfader4_x1);               // pma -> xfader4_x1::Value
		pma.getWrappedObject().getParameter().connectT(5, xfader_x2);                // pma -> xfader_x2::Value
		pma.getWrappedObject().getParameter().connectT(6, xfader2_x2);               // pma -> xfader2_x2::Value
		pma.getWrappedObject().getParameter().connectT(7, xfader1_x2);               // pma -> xfader1_x2::Value
		pma.getWrappedObject().getParameter().connectT(8, xfader3_x2);               // pma -> xfader3_x2::Value
		pma.getWrappedObject().getParameter().connectT(9, xfader4_x2);               // pma -> xfader4_x2::Value
		pma3.getWrappedObject().getParameter().connectT(0, pma);                     // pma3 -> pma::Add
		midi.getParameter().connectT(0, pma3);                                       // midi -> pma3::Value
		pma4.getWrappedObject().getParameter().connectT(0, pma3);                    // pma4 -> pma3::Add
		midi1.getParameter().connectT(0, pma4);                                      // midi1 -> pma4::Value
		pma5.getWrappedObject().getParameter().connectT(0, pma4);                    // pma5 -> pma4::Add
		midi_cc.getWrappedObject().getParameter().connectT(0, pma5);                 // midi_cc -> pma5::Value
		pma6.getWrappedObject().getParameter().connectT(0, pma5);                    // pma6 -> pma5::Add
		midi_cc1.getWrappedObject().getParameter().connectT(0, pma6);                // midi_cc1 -> pma6::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add16);         // global_cable16 -> add16::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add17);         // global_cable17 -> add17::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add18);         // global_cable18 -> add18::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add19);         // global_cable19 -> add19::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add20);         // global_cable20 -> add20::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add21);         // global_cable21 -> add21::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add22);         // global_cable22 -> add22::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add23);         // global_cable23 -> add23::Value
		cable_table11.getWrappedObject().getParameter().connectT(0, branch3);        // cable_table11 -> branch3::Index
		pma7.getWrappedObject().getParameter().connectT(0, pma6);                    // pma7 -> pma6::Add
		input_toggle1x.getWrappedObject().getParameter().connectT(0, pma7);          // input_toggle1x -> pma7::Value
		cable_table12.getWrappedObject().getParameter().connectT(0, input_toggle1x); // cable_table12 -> input_toggle1x::Input
		event_data_reader7.getParameter().connectT(0, input_toggle1x);               // event_data_reader7 -> input_toggle1x::Value1
		peak2.getParameter().connectT(0, input_toggle1x);                            // peak2 -> input_toggle1x::Value2
		auto& switcher_x1_p = switcher_x1.getWrappedObject().getParameter();
		switcher_x1_p.getParameterT(0).connectT(0, sb1_x1); // switcher_x1 -> sb1_x1::Bypassed
		switcher_x1_p.getParameterT(1).connectT(0, sb2_x1); // switcher_x1 -> sb2_x1::Bypassed
		switcher_x1_p.getParameterT(2).connectT(0, sb3_x1); // switcher_x1 -> sb3_x1::Bypassed
		switcher_x1_p.getParameterT(3).connectT(0, sb4_x1); // switcher_x1 -> sb4_x1::Bypassed
		switcher_x1_p.getParameterT(4).connectT(0, sb5_x1); // switcher_x1 -> sb5_x1::Bypassed
		auto& switcher_x2_p = switcher_x2.getWrappedObject().getParameter();
		switcher_x2_p.getParameterT(0).connectT(0, sb1_x2); // switcher_x2 -> sb1_x2::Bypassed
		switcher_x2_p.getParameterT(1).connectT(0, sb2_x2); // switcher_x2 -> sb2_x2::Bypassed
		switcher_x2_p.getParameterT(2).connectT(0, sb3_x2); // switcher_x2 -> sb3_x2::Bypassed
		switcher_x2_p.getParameterT(3).connectT(0, sb4_x2); // switcher_x2 -> sb4_x2::Bypassed
		switcher_x2_p.getParameterT(4).connectT(0, sb5_x2); // switcher_x2 -> sb5_x2::Bypassed
		auto& switcher1_p = switcher1.getWrappedObject().getParameter();
		switcher1_p.getParameterT(0).connectT(0, sb3); // switcher1 -> sb3::Bypassed
		switcher1_p.getParameterT(1).connectT(0, sb4); // switcher1 -> sb4::Bypassed
		switcher1_p.getParameterT(2).connectT(0, sb5); // switcher1 -> sb5::Bypassed
		
		// Default Values --------------------------------------------------------------------------
		
		pma.setParameterT(0, 0.); // control::pma::Value
		;                         // pma::Multiply is automated
		;                         // pma::Add is automated
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
		midi_cc.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // pma5::Value is automated
		; // pma5::Multiply is automated
		; // pma5::Add is automated
		
		midi_cc1.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc1.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc1.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // pma6::Value is automated
		; // pma6::Multiply is automated
		; // pma6::Add is automated
		
		; // cable_table11::Value is automated
		
		; // cable_table12::Value is automated
		
		;                                        // event_data_reader7::SlotIndex is automated
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // branch3::Index is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add17::Value is automated
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add20::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add22::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add23::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // input_toggle1x::Input is automated
		; // input_toggle1x::Value1 is automated
		; // input_toggle1x::Value2 is automated
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		;                         // XF1::smooth_x1 is automated
		XF1.setParameterT(1, 0.); // container::chain::mode_x1
		;                         // XF1::SmoothType is automated
		
		; // switcher1::Value is automated
		
		x1.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher_x1::Value is automated
		
		; // xfader_x1::Value is automated
		
		pma8.setParameterT(0, 0.); // control::pma::Value
		pma8.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma8::Add is automated
		
		;                                            // smoothed_parameter1_x4::Value is automated
		;                                            // smoothed_parameter1_x4::SmoothingTime is automated
		smoothed_parameter1_x4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter17::Value is automated
		;                                          // smoothed_parameter17::SmoothingTime is automated
		smoothed_parameter17.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle16::Input is automated
		; // input_toggle16::Value1 is automated
		; // input_toggle16::Value2 is automated
		
		pma9.setParameterT(0, 0.); // control::pma::Value
		pma9.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma9::Add is automated
		
		;                               // gain16::Gain is automated
		gain16.setParameterT(1, 0.);    // core::gain::Smoothing
		gain16.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader2_x1::Value is automated
		
		pma10.setParameterT(0, 0.); // control::pma::Value
		pma10.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma10::Add is automated
		
		;                                            // smoothed_parameter1_x1::Value is automated
		;                                            // smoothed_parameter1_x1::SmoothingTime is automated
		smoothed_parameter1_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter1::Value is automated
		;                                         // smoothed_parameter1::SmoothingTime is automated
		smoothed_parameter1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle2::Input is automated
		; // input_toggle2::Value1 is automated
		; // input_toggle2::Value2 is automated
		
		pma11.setParameterT(0, 0.); // control::pma::Value
		pma11.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma11::Add is automated
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 0.);    // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader1_x1::Value is automated
		
		pma12.setParameterT(0, 0.); // control::pma::Value
		pma12.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma12::Add is automated
		
		;                                            // smoothed_parameter2_x1::Value is automated
		;                                            // smoothed_parameter2_x1::SmoothingTime is automated
		smoothed_parameter2_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter3::Value is automated
		;                                         // smoothed_parameter3::SmoothingTime is automated
		smoothed_parameter3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle4::Input is automated
		; // input_toggle4::Value1 is automated
		; // input_toggle4::Value2 is automated
		
		pma13.setParameterT(0, 0.); // control::pma::Value
		pma13.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma13::Add is automated
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 0.);    // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader3_x1::Value is automated
		
		pma17.setParameterT(0, 0.); // control::pma::Value
		pma17.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma17::Add is automated
		
		;                                            // smoothed_parameter4_x1::Value is automated
		;                                            // smoothed_parameter4_x1::SmoothingTime is automated
		smoothed_parameter4_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter4::Value is automated
		;                                         // smoothed_parameter4::SmoothingTime is automated
		smoothed_parameter4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle5::Input is automated
		; // input_toggle5::Value1 is automated
		; // input_toggle5::Value2 is automated
		
		pma15.setParameterT(0, 0.); // control::pma::Value
		pma15.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma15::Add is automated
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 0.);    // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader4_x1::Value is automated
		
		pma14.setParameterT(0, 0.); // control::pma::Value
		pma14.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma14::Add is automated
		
		;                                            // smoothed_parameter3_x1::Value is automated
		;                                            // smoothed_parameter3_x1::SmoothingTime is automated
		smoothed_parameter3_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter2::Value is automated
		;                                         // smoothed_parameter2::SmoothingTime is automated
		smoothed_parameter2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle3::Input is automated
		; // input_toggle3::Value1 is automated
		; // input_toggle3::Value2 is automated
		
		pma16.setParameterT(0, 0.); // control::pma::Value
		pma16.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma16::Add is automated
		
		;                              // gain4::Gain is automated
		gain4.setParameterT(1, 0.);    // core::gain::Smoothing
		gain4.setParameterT(2, -100.); // core::gain::ResetValue
		
		x2.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher_x2::Value is automated
		
		; // xfader_x2::Value is automated
		
		pma21.setParameterT(0, 0.); // control::pma::Value
		pma21.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma21::Add is automated
		
		;                                           // smoothed_parameter_x2::Value is automated
		;                                           // smoothed_parameter_x2::SmoothingTime is automated
		smoothed_parameter_x2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter5::Value is automated
		;                                         // smoothed_parameter5::SmoothingTime is automated
		smoothed_parameter5.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle6::Input is automated
		; // input_toggle6::Value1 is automated
		; // input_toggle6::Value2 is automated
		
		pma19.setParameterT(0, 0.); // control::pma::Value
		pma19.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma19::Add is automated
		
		;                              // gain5::Gain is automated
		gain5.setParameterT(1, 0.);    // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader2_x2::Value is automated
		
		pma18.setParameterT(0, 0.); // control::pma::Value
		pma18.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma18::Add is automated
		
		;                                            // smoothed_parameter1_x2::Value is automated
		;                                            // smoothed_parameter1_x2::SmoothingTime is automated
		smoothed_parameter1_x2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter6::Value is automated
		;                                         // smoothed_parameter6::SmoothingTime is automated
		smoothed_parameter6.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle7::Input is automated
		; // input_toggle7::Value1 is automated
		; // input_toggle7::Value2 is automated
		
		pma20.setParameterT(0, 0.); // control::pma::Value
		pma20.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma20::Add is automated
		
		;                              // gain6::Gain is automated
		gain6.setParameterT(1, 0.);    // core::gain::Smoothing
		gain6.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader1_x2::Value is automated
		
		pma22.setParameterT(0, 0.); // control::pma::Value
		pma22.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma22::Add is automated
		
		;                                            // smoothed_parameter2_x2::Value is automated
		;                                            // smoothed_parameter2_x2::SmoothingTime is automated
		smoothed_parameter2_x2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter7::Value is automated
		;                                         // smoothed_parameter7::SmoothingTime is automated
		smoothed_parameter7.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle8::Input is automated
		; // input_toggle8::Value1 is automated
		; // input_toggle8::Value2 is automated
		
		pma23.setParameterT(0, 0.); // control::pma::Value
		pma23.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma23::Add is automated
		
		;                              // gain7::Gain is automated
		gain7.setParameterT(1, 0.);    // core::gain::Smoothing
		gain7.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader3_x2::Value is automated
		
		pma24.setParameterT(0, 0.00177637); // control::pma::Value
		pma24.setParameterT(1, 1.);         // control::pma::Multiply
		;                                   // pma24::Add is automated
		
		;                                            // smoothed_parameter4_x2::Value is automated
		;                                            // smoothed_parameter4_x2::SmoothingTime is automated
		smoothed_parameter4_x2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter8::Value is automated
		;                                         // smoothed_parameter8::SmoothingTime is automated
		smoothed_parameter8.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle9::Input is automated
		; // input_toggle9::Value1 is automated
		; // input_toggle9::Value2 is automated
		
		pma25.setParameterT(0, 0.); // control::pma::Value
		pma25.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma25::Add is automated
		
		;                              // gain8::Gain is automated
		gain8.setParameterT(1, 0.);    // core::gain::Smoothing
		gain8.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader4_x2::Value is automated
		
		pma26.setParameterT(0, 0.); // control::pma::Value
		pma26.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma26::Add is automated
		
		;                                            // smoothed_parameter3_x2::Value is automated
		;                                            // smoothed_parameter3_x2::SmoothingTime is automated
		smoothed_parameter3_x2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter9::Value is automated
		;                                         // smoothed_parameter9::SmoothingTime is automated
		smoothed_parameter9.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle10::Input is automated
		; // input_toggle10::Value1 is automated
		; // input_toggle10::Value2 is automated
		
		pma27.setParameterT(0, 0.); // control::pma::Value
		pma27.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma27::Add is automated
		
		;                              // gain9::Gain is automated
		gain9.setParameterT(1, 0.);    // core::gain::Smoothing
		gain9.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.5);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 3.);
		this->setParameterT(4, 0.548141);
		this->setParameterT(5, -1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 0.);
		this->setParameterT(13, 0.);
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
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade4_impl::global_cable16_t<NV>
        getT(2).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade4_impl::global_cable17_t<NV>
        getT(2).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade4_impl::global_cable18_t<NV>
        getT(2).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade4_impl::global_cable19_t<NV>
        getT(2).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade4_impl::global_cable20_t<NV>
        getT(2).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade4_impl::global_cable21_t<NV>
        getT(2).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade4_impl::global_cable22_t<NV>
        getT(2).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade4_impl::global_cable23_t<NV>
        getT(2).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0).setExternalData(b, index); // xfade4_impl::cable_table11_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(1).setExternalData(b, index); // xfade4_impl::cable_table12_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).                                           // xfade4_impl::peak2_t<NV>
        getT(0).getT(2).getT(1).getT(1).setExternalData(b, index);
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
using xfade4 = wrap::node<xfade4_impl::instance<NV>>;
}

