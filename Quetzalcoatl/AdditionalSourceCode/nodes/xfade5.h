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

namespace xfade5_impl
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
DECLARE_PARAMETER_RANGE(xfader_x1_c4Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using xfader_x1_c4 = parameter::from0To1<pma8_t<NV>, 
                                         2, 
                                         xfader_x1_c4Range>;

template <int NV>
using xfader_x1_multimod = parameter::list<parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           xfader_x1_c4<NV>, 
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
using xfader2_x1_c4 = parameter::from0To1<pma10_t<NV>, 
                                          2, 
                                          xfader_x1_c4Range>;

template <int NV>
using xfader2_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader2_x1_c4<NV>, 
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
using xfader1_x1_c4 = parameter::from0To1<pma12_t<NV>, 
                                          2, 
                                          xfader_x1_c4Range>;

template <int NV>
using xfader1_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader1_x1_c4<NV>, 
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
using xfader3_x1_c4 = parameter::from0To1<pma17_t<NV>, 
                                          2, 
                                          xfader_x1_c4Range>;

template <int NV>
using xfader3_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader3_x1_c4<NV>, 
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
using xfader4_x1_c4 = parameter::from0To1<pma14_t<NV>, 
                                          2, 
                                          xfader_x1_c4Range>;

template <int NV>
using xfader4_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader4_x1_c4<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader4_x1_t = control::xfader<xfader4_x1_multimod<NV>, 
                                     faders::threshold>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<xfader_x1_t<NV>, 0>, 
                                 parameter::plain<xfader2_x1_t<NV>, 0>, 
                                 parameter::plain<xfader1_x1_t<NV>, 0>, 
                                 parameter::plain<xfader3_x1_t<NV>, 0>, 
                                 parameter::plain<xfader4_x1_t<NV>, 0>>;

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
		0.f, 0.f, 0.0025149f, 0.00704861f, 0.0115823f, 0.016116f,
		0.0206498f, 0.0251835f, 0.0297172f, 0.0342509f, 0.0387848f, 0.0433185f,
		0.0478523f, 0.052386f, 0.0569197f, 0.0614534f, 0.0659872f, 0.0705209f,
		0.0750548f, 0.0795885f, 0.0841222f, 0.0886559f, 0.0931897f, 0.0977234f,
		0.102257f, 0.106791f, 0.111325f, 0.115858f, 0.120392f, 0.124926f,
		0.12946f, 0.133993f, 0.138527f, 0.143061f, 0.147595f, 0.152128f,
		0.156662f, 0.161196f, 0.16573f, 0.170263f, 0.174797f, 0.179331f,
		0.183865f, 0.188398f, 0.192932f, 0.197466f, 0.201999f, 0.206533f,
		0.211067f, 0.215601f, 0.220134f, 0.224668f, 0.229202f, 0.233736f,
		0.238269f, 0.242803f, 0.247337f, 0.251871f, 0.256404f, 0.260938f,
		0.265472f, 0.270006f, 0.274539f, 0.279073f, 0.283607f, 0.28814f,
		0.292674f, 0.297208f, 0.301742f, 0.306275f, 0.310809f, 0.315343f,
		0.319877f, 0.32441f, 0.328944f, 0.333478f, 0.338012f, 0.342545f,
		0.347079f, 0.351613f, 0.356147f, 0.36068f, 0.365214f, 0.369748f,
		0.374282f, 0.378815f, 0.383349f, 0.387883f, 0.392417f, 0.39695f,
		0.401484f, 0.406018f, 0.410552f, 0.415085f, 0.419619f, 0.424153f,
		0.428686f, 0.43322f, 0.437754f, 0.442288f, 0.446822f, 0.451355f,
		0.455889f, 0.460423f, 0.464956f, 0.46949f, 0.474024f, 0.478558f,
		0.483091f, 0.487625f, 0.492159f, 0.496693f, 0.501226f, 0.50576f,
		0.510294f, 0.514828f, 0.519361f, 0.523895f, 0.528429f, 0.532963f,
		0.537496f, 0.54203f, 0.546564f, 0.551098f, 0.555631f, 0.560165f,
		0.564699f, 0.569233f, 0.573766f, 0.5783f, 0.582834f, 0.587368f,
		0.591901f, 0.596435f, 0.600969f, 0.605502f, 0.610036f, 0.61457f,
		0.619104f, 0.623637f, 0.628171f, 0.632705f, 0.637239f, 0.641772f,
		0.646306f, 0.65084f, 0.655374f, 0.659907f, 0.664441f, 0.668975f,
		0.673509f, 0.678042f, 0.682576f, 0.68711f, 0.691644f, 0.696177f,
		0.700711f, 0.705245f, 0.709779f, 0.714312f, 0.718846f, 0.72338f,
		0.727914f, 0.732447f, 0.736981f, 0.741515f, 0.746048f, 0.750582f,
		0.755116f, 0.75965f, 0.764183f, 0.768717f, 0.773251f, 0.777785f,
		0.782318f, 0.786852f, 0.791386f, 0.79592f, 0.800453f, 0.804987f,
		0.809521f, 0.814055f, 0.818588f, 0.823122f, 0.827656f, 0.83219f,
		0.836723f, 0.841257f, 0.845791f, 0.850325f, 0.854858f, 0.859392f,
		0.863926f, 0.868459f, 0.872993f, 0.877527f, 0.882061f, 0.886594f,
		0.891128f, 0.895662f, 0.900196f, 0.904729f, 0.909263f, 0.913797f,
		0.918331f, 0.922864f, 0.927398f, 0.931932f, 0.936466f, 0.940999f,
		0.945533f, 0.950067f, 0.954601f, 0.959134f, 0.963668f, 0.968202f,
		0.972736f, 0.977269f, 0.981803f, 0.986337f, 0.99087f, 0.995404f,
		0.999938f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
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

using sb4_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, core::empty>>;

using sb4_t = bypass::smoothed<20, sb4_t_>;
using switcher1_c1 = parameter::bypass<sb4_t>;

using sb5_t_ = sb4_t_;

using sb5_t = bypass::smoothed<20, sb5_t_>;
using switcher1_c2 = parameter::bypass<sb5_t>;

template <int NV>
using switcher1_multimod = parameter::list<switcher1_c0<NV>, 
                                           switcher1_c1, 
                                           switcher1_c2>;

template <int NV>
using switcher1_t = control::xfader<switcher1_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb3_t<NV>>, 
                                         sb4_t, 
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
// Parameter list for xfade5_impl::XF1_t -----------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(smooth_x1_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_STEP(smooth_x1_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth_x1_0 = parameter::from0To1<xfade5_impl::smoothed_parameter2_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_1 = parameter::from0To1<xfade5_impl::smoothed_parameter4_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_2 = parameter::from0To1<xfade5_impl::smoothed_parameter3_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_3 = parameter::from0To1<xfade5_impl::smoothed_parameter3_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_4 = parameter::from0To1<xfade5_impl::smoothed_parameter4_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_5 = parameter::from0To1<xfade5_impl::smoothed_parameter2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_6 = parameter::from0To1<xfade5_impl::smoothed_parameter1_x4_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_7 = parameter::from0To1<xfade5_impl::smoothed_parameter17_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_8 = parameter::from0To1<xfade5_impl::smoothed_parameter1_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_9 = parameter::from0To1<xfade5_impl::smoothed_parameter1_t<NV>, 
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
                                   smooth_x1_9<NV>>;

template <int NV>
using SmoothType = parameter::chain<ranges::Identity, 
                                    parameter::plain<xfade5_impl::input_toggle2_t<NV>, 0>, 
                                    parameter::plain<xfade5_impl::input_toggle4_t<NV>, 0>, 
                                    parameter::plain<xfade5_impl::input_toggle5_t<NV>, 0>, 
                                    parameter::plain<xfade5_impl::input_toggle3_t<NV>, 0>, 
                                    parameter::plain<xfade5_impl::input_toggle16_t<NV>, 0>>;

using mode_x1 = parameter::empty;
template <int NV>
using XF1_t_plist = parameter::list<smooth_x1<NV>, 
                                    mode_x1, 
                                    SmoothType<NV>>;
}

template <int NV>
using XF1_t = container::chain<XF1_t_parameters::XF1_t_plist<NV>, 
                               wrap::fix<2, fix8_block_t<NV>>>;

namespace xfade5_t_parameters
{
// Parameter list for xfade5_impl::xfade5_t --------------------------------------------------------

DECLARE_PARAMETER_RANGE(MainParam_InputRange, 
                        1., 
                        8.);
template <int NV>
using MainParam_0 = parameter::from0To1<xfade5_impl::pma7_t<NV>, 
                                        2, 
                                        xfade5_impl::xfader_x1_c4Range>;

template <int NV>
using MainParam = parameter::chain<MainParam_InputRange, MainParam_0<NV>>;

DECLARE_PARAMETER_RANGE(_3rdParam_InputRange, 
                        0., 
                        6.);

template <int NV>
using _3rdParam = parameter::chain<_3rdParam_InputRange, 
                                   parameter::plain<xfade5_impl::switcher_x1_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(_5thParam_InputRange, 
                        0., 
                        2.);

template <int NV>
using _5thParam = parameter::chain<_5thParam_InputRange, 
                                   parameter::plain<xfade5_impl::switcher1_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(GlobalSrc_InputRange, 
                             0., 
                             16., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(GlobalSrc_2Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using GlobalSrc_2 = parameter::from0To1<xfade5_impl::event_data_reader7_t<NV>, 
                                        0, 
                                        GlobalSrc_2Range>;

template <int NV>
using GlobalSrc = parameter::chain<GlobalSrc_InputRange, 
                                   parameter::plain<xfade5_impl::cable_table11_t<NV>, 0>, 
                                   parameter::plain<xfade5_impl::cable_table12_t<NV>, 0>, 
                                   GlobalSrc_2<NV>>;

template <int NV>
using _2ndParam = parameter::plain<xfade5_impl::XF1_t<NV>, 0>;
template <int NV>
using _4thParam = parameter::plain<xfade5_impl::XF1_t<NV>, 2>;
using Env1 = parameter::empty;
using Env2 = Env1;
template <int NV>
using Poly = parameter::plain<xfade5_impl::pma_t<NV>, 1>;
template <int NV>
using Global = parameter::plain<xfade5_impl::pma7_t<NV>, 
                                1>;
template <int NV>
using Vel = parameter::plain<xfade5_impl::pma3_t<NV>, 
                             1>;
template <int NV>
using Trk = parameter::plain<xfade5_impl::pma4_t<NV>, 
                             1>;
template <int NV>
using MW = parameter::plain<xfade5_impl::pma5_t<NV>, 
                            1>;
template <int NV>
using AT = parameter::plain<xfade5_impl::pma6_t<NV>, 
                            1>;
template <int NV>
using xfade5_t_plist = parameter::list<MainParam<NV>, 
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
using xfade5_t_ = container::chain<xfade5_t_parameters::xfade5_t_plist<NV>, 
                                   wrap::fix<2, modchain_t<NV>>, 
                                   XF1_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xfade5_impl::xfade5_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(xfade5);
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
		
		auto& modchain = this->getT(0);                                                           // xfade5_impl::modchain_t<NV>
		auto& split19 = this->getT(0).getT(0);                                                    // xfade5_impl::split19_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0);                                                // xfade5_impl::pma_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(1);                                             // xfade5_impl::split7_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(1).getT(0);                                     // xfade5_impl::chain5_t<NV>
		auto& midi = this->getT(0).getT(0).getT(1).getT(0).getT(0);                               // xfade5_impl::midi_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                               // xfade5_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(1);                                     // xfade5_impl::chain6_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                              // xfade5_impl::midi1_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                               // xfade5_impl::pma4_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(1).getT(2);                                     // xfade5_impl::chain9_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(1).getT(2).getT(0);                            // xfade5_impl::midi_cc_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                               // xfade5_impl::pma5_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(3);                                    // xfade5_impl::chain14_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                           // xfade5_impl::midi_cc1_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                               // xfade5_impl::pma6_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(4);                                    // xfade5_impl::chain25_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                            // xfade5_impl::chain10_t<NV>
		auto& cable_table11 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0);              // xfade5_impl::cable_table11_t<NV>
		auto& cable_table12 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(1);              // xfade5_impl::cable_table12_t<NV>
		auto& split21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(2);                    // xfade5_impl::split21_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(2).getT(0); // xfade5_impl::event_data_reader7_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(2).getT(1);            // xfade5_impl::chain29_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(1).getT(4).                                    // xfade5_impl::branch3_t<NV>
                        getT(0).getT(2).getT(1).getT(0);
		auto& chain30 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade5_impl::chain30_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(0);
		auto& global_cable16 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade5_impl::global_cable16_t<NV>
                               getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(0).getT(1);
		auto& chain31 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade5_impl::chain31_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(1);
		auto& global_cable17 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade5_impl::global_cable17_t<NV>
                               getT(2).getT(1).getT(0).getT(1).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(1).getT(1);
		auto& chain32 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade5_impl::chain32_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(2);
		auto& global_cable18 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade5_impl::global_cable18_t<NV>
                               getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(2).getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade5_impl::chain33_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(3);
		auto& global_cable19 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade5_impl::global_cable19_t<NV>
                               getT(2).getT(1).getT(0).getT(3).getT(0);
		auto& add19 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(3).getT(1);
		auto& chain34 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade5_impl::chain34_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(4);
		auto& global_cable20 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade5_impl::global_cable20_t<NV>
                               getT(2).getT(1).getT(0).getT(4).getT(0);
		auto& add20 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(4).getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade5_impl::chain35_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(5);
		auto& global_cable21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade5_impl::global_cable21_t<NV>
                               getT(2).getT(1).getT(0).getT(5).getT(0);
		auto& add21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(5).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade5_impl::chain36_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(6);
		auto& global_cable22 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade5_impl::global_cable22_t<NV>
                               getT(2).getT(1).getT(0).getT(6).getT(0);
		auto& add22 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(6).getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade5_impl::chain37_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(7);
		auto& global_cable23 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade5_impl::global_cable23_t<NV>
                               getT(2).getT(1).getT(0).getT(7).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(2).getT(1).getT(0).getT(7).getT(1);
		auto& peak2 = this->getT(0).getT(0).getT(1).getT(4).                                   // xfade5_impl::peak2_t<NV>
                      getT(0).getT(2).getT(1).getT(1);
		auto& clear = this->getT(0).getT(0).getT(1).getT(4).                                   // math::clear<NV>
                      getT(0).getT(2).getT(1).getT(2);
		auto& input_toggle1x = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(3);          // xfade5_impl::input_toggle1x_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                            // xfade5_impl::pma7_t<NV>
		auto& XF1 = this->getT(1);                                                             // xfade5_impl::XF1_t<NV>
		auto& fix8_block = this->getT(1).getT(0);                                              // xfade5_impl::fix8_block_t<NV>
		auto& softbypass_switch4 = this->getT(1).getT(0).getT(0);                              // xfade5_impl::softbypass_switch4_t<NV>
		auto& switcher1 = this->getT(1).getT(0).getT(0).getT(0);                               // xfade5_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(1).getT(0).getT(0).getT(1);                           // xfade5_impl::sb_container1_t<NV>
		auto& sb3 = this->getT(1).getT(0).getT(0).getT(1).getT(0);                             // xfade5_impl::sb3_t<NV>
		auto& x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0);                      // xfade5_impl::x1_t<NV>
		auto& switcher_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);     // xfade5_impl::switcher_x1_t<NV>
		auto& sb_container_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1); // xfade5_impl::sb_container_x1_t<NV>
		auto& sb1_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade5_impl::sb1_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(0);
		auto& chain1_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade5_impl::chain1_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(0).
                          getT(0);
		auto& xfader_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                       // xfade5_impl::xfader_x1_t<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& pma8 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade5_impl::pma8_t<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& chain26 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade5_impl::chain26_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2);
		auto& split20 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade5_impl::split20_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter1_x4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade5_impl::smoothed_parameter1_x4_t<NV>
                                       getT(1).getT(0).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).    // xfade5_impl::smoothed_parameter17_t<NV>
                                     getT(1).getT(0).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                  // xfade5_impl::input_toggle16_t<NV>
                               getT(0).getT(1).getT(0).getT(0).getT(2).
                               getT(1);
		auto& pma9 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade5_impl::pma9_t<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(2).
                     getT(2);
		auto& gain16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).
                       getT(3);
		auto& sb2_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade5_impl::sb2_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& chain3_x1_x1 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade5_impl::chain3_x1_x1_t<NV>
                             getT(0).getT(0).getT(1).getT(1).
                             getT(0);
		auto& xfader2_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade5_impl::xfader2_x1_t<NV>
                           getT(0).getT(1).getT(1).getT(0).getT(0);
		auto& pma10 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade5_impl::pma10_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(1);
		auto& chain7 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade5_impl::chain7_t<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2);
		auto& split4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade5_impl::split4_t<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter1_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade5_impl::smoothed_parameter1_x1_t<NV>
                                       getT(1).getT(1).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade5_impl::smoothed_parameter1_t<NV>
                                    getT(1).getT(1).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade5_impl::input_toggle2_t<NV>
                              getT(0).getT(1).getT(1).getT(0).getT(2).
                              getT(1);
		auto& pma11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade5_impl::pma11_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(2).
                      getT(2);
		auto& gain1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(2).
                      getT(3);
		auto& sb3_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade5_impl::sb3_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(2);
		auto& chain2_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade5_impl::chain2_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(2).
                          getT(0);
		auto& xfader1_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade5_impl::xfader1_x1_t<NV>
                           getT(0).getT(1).getT(2).getT(0).getT(0);
		auto& pma12 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade5_impl::pma12_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(1);
		auto& chain12 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade5_impl::chain12_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(2);
		auto& split6 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade5_impl::split6_t<NV>
                       getT(0).getT(1).getT(2).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter2_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade5_impl::smoothed_parameter2_x1_t<NV>
                                       getT(1).getT(2).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade5_impl::smoothed_parameter3_t<NV>
                                    getT(1).getT(2).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade5_impl::input_toggle4_t<NV>
                              getT(0).getT(1).getT(2).getT(0).getT(2).
                              getT(1);
		auto& pma13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade5_impl::pma13_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(3);
		auto& gain2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(4);
		auto& sb4_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade5_impl::sb4_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(3);
		auto& chain4_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade5_impl::chain4_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& xfader3_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade5_impl::xfader3_x1_t<NV>
                           getT(0).getT(1).getT(3).getT(0).getT(0);
		auto& pma17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade5_impl::pma17_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(1);
		auto& chain13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade5_impl::chain13_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(2);
		auto& split8 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade5_impl::split8_t<NV>
                       getT(0).getT(1).getT(3).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter4_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade5_impl::smoothed_parameter4_x1_t<NV>
                                       getT(1).getT(3).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade5_impl::smoothed_parameter4_t<NV>
                                    getT(1).getT(3).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade5_impl::input_toggle5_t<NV>
                              getT(0).getT(1).getT(3).getT(0).getT(2).
                              getT(1);
		auto& pma15 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade5_impl::pma15_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(2).
                      getT(2);
		auto& gain3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(3);
		auto& sb5_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade5_impl::sb5_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(4);
		auto& chain5_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade5_impl::chain5_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& xfader4_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade5_impl::xfader4_x1_t<NV>
                           getT(0).getT(1).getT(4).getT(0).getT(0);
		auto& pma14 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade5_impl::pma14_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(1);
		auto& chain11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade5_impl::chain11_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2);
		auto& split5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade5_impl::split5_t<NV>
                       getT(0).getT(1).getT(4).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter3_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade5_impl::smoothed_parameter3_x1_t<NV>
                                       getT(1).getT(4).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade5_impl::smoothed_parameter2_t<NV>
                                    getT(1).getT(4).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).  // xfade5_impl::input_toggle3_t<NV>
                              getT(0).getT(1).getT(4).getT(0).getT(2).
                              getT(1);
		auto& pma16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).  // xfade5_impl::pma16_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(2).
                      getT(2);
		auto& gain4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).  // core::gain<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(3);
		auto& sb4 = this->getT(1).getT(0).getT(0).getT(1).getT(1); // xfade5_impl::sb4_t
		auto& sb5 = this->getT(1).getT(0).getT(0).getT(1).getT(2); // xfade5_impl::sb5_t
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& smooth_x1_p = XF1.getParameterT(0);
		smooth_x1_p.connectT(0, smoothed_parameter2_x1); // smooth_x1 -> smoothed_parameter2_x1::SmoothingTime
		smooth_x1_p.connectT(1, smoothed_parameter4_x1); // smooth_x1 -> smoothed_parameter4_x1::SmoothingTime
		smooth_x1_p.connectT(2, smoothed_parameter3_x1); // smooth_x1 -> smoothed_parameter3_x1::SmoothingTime
		smooth_x1_p.connectT(3, smoothed_parameter3);    // smooth_x1 -> smoothed_parameter3::SmoothingTime
		smooth_x1_p.connectT(4, smoothed_parameter4);    // smooth_x1 -> smoothed_parameter4::SmoothingTime
		smooth_x1_p.connectT(5, smoothed_parameter2);    // smooth_x1 -> smoothed_parameter2::SmoothingTime
		smooth_x1_p.connectT(6, smoothed_parameter1_x4); // smooth_x1 -> smoothed_parameter1_x4::SmoothingTime
		smooth_x1_p.connectT(7, smoothed_parameter17);   // smooth_x1 -> smoothed_parameter17::SmoothingTime
		smooth_x1_p.connectT(8, smoothed_parameter1_x1); // smooth_x1 -> smoothed_parameter1_x1::SmoothingTime
		smooth_x1_p.connectT(9, smoothed_parameter1);    // smooth_x1 -> smoothed_parameter1::SmoothingTime
		
		auto& SmoothType_p = XF1.getParameterT(2);
		SmoothType_p.connectT(0, input_toggle2);  // SmoothType -> input_toggle2::Input
		SmoothType_p.connectT(1, input_toggle4);  // SmoothType -> input_toggle4::Input
		SmoothType_p.connectT(2, input_toggle5);  // SmoothType -> input_toggle5::Input
		SmoothType_p.connectT(3, input_toggle3);  // SmoothType -> input_toggle3::Input
		SmoothType_p.connectT(4, input_toggle16); // SmoothType -> input_toggle16::Input
		this->getParameterT(0).connectT(0, pma7); // MainParam -> pma7::Add
		
		this->getParameterT(1).connectT(0, XF1); // _2ndParam -> XF1::smooth_x1
		
		this->getParameterT(2).connectT(0, switcher_x1); // _3rdParam -> switcher_x1::Value
		
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
		xfader_x1_p.getParameterT(4).connectT(0, pma8);                              // xfader_x1 -> pma8::Add
		pma11.getWrappedObject().getParameter().connectT(0, gain1);                  // pma11 -> gain1::Gain
		input_toggle2.getWrappedObject().getParameter().connectT(0, pma11);          // input_toggle2 -> pma11::Add
		smoothed_parameter1.getParameter().connectT(0, input_toggle2);               // smoothed_parameter1 -> input_toggle2::Value2
		smoothed_parameter1_x1.getParameter().connectT(0, input_toggle2);            // smoothed_parameter1_x1 -> input_toggle2::Value1
		pma10.getWrappedObject().getParameter().connectT(0, smoothed_parameter1);    // pma10 -> smoothed_parameter1::Value
		pma10.getWrappedObject().getParameter().connectT(1, smoothed_parameter1_x1); // pma10 -> smoothed_parameter1_x1::Value
		auto& xfader2_x1_p = xfader2_x1.getWrappedObject().getParameter();
		xfader2_x1_p.getParameterT(4).connectT(0, pma10);                            // xfader2_x1 -> pma10::Add
		pma13.getWrappedObject().getParameter().connectT(0, gain2);                  // pma13 -> gain2::Gain
		input_toggle4.getWrappedObject().getParameter().connectT(0, pma13);          // input_toggle4 -> pma13::Add
		smoothed_parameter2_x1.getParameter().connectT(0, input_toggle4);            // smoothed_parameter2_x1 -> input_toggle4::Value1
		smoothed_parameter3.getParameter().connectT(0, input_toggle4);               // smoothed_parameter3 -> input_toggle4::Value2
		pma12.getWrappedObject().getParameter().connectT(0, smoothed_parameter2_x1); // pma12 -> smoothed_parameter2_x1::Value
		pma12.getWrappedObject().getParameter().connectT(1, smoothed_parameter3);    // pma12 -> smoothed_parameter3::Value
		auto& xfader1_x1_p = xfader1_x1.getWrappedObject().getParameter();
		xfader1_x1_p.getParameterT(4).connectT(0, pma12);                            // xfader1_x1 -> pma12::Add
		pma15.getWrappedObject().getParameter().connectT(0, gain3);                  // pma15 -> gain3::Gain
		input_toggle5.getWrappedObject().getParameter().connectT(0, pma15);          // input_toggle5 -> pma15::Add
		smoothed_parameter4_x1.getParameter().connectT(0, input_toggle5);            // smoothed_parameter4_x1 -> input_toggle5::Value1
		smoothed_parameter4.getParameter().connectT(0, input_toggle5);               // smoothed_parameter4 -> input_toggle5::Value2
		pma17.getWrappedObject().getParameter().connectT(0, smoothed_parameter4_x1); // pma17 -> smoothed_parameter4_x1::Value
		pma17.getWrappedObject().getParameter().connectT(1, smoothed_parameter4);    // pma17 -> smoothed_parameter4::Value
		auto& xfader3_x1_p = xfader3_x1.getWrappedObject().getParameter();
		xfader3_x1_p.getParameterT(4).connectT(0, pma17);                            // xfader3_x1 -> pma17::Add
		pma16.getWrappedObject().getParameter().connectT(0, gain4);                  // pma16 -> gain4::Gain
		input_toggle3.getWrappedObject().getParameter().connectT(0, pma16);          // input_toggle3 -> pma16::Add
		smoothed_parameter3_x1.getParameter().connectT(0, input_toggle3);            // smoothed_parameter3_x1 -> input_toggle3::Value1
		smoothed_parameter2.getParameter().connectT(0, input_toggle3);               // smoothed_parameter2 -> input_toggle3::Value2
		pma14.getWrappedObject().getParameter().connectT(0, smoothed_parameter3_x1); // pma14 -> smoothed_parameter3_x1::Value
		pma14.getWrappedObject().getParameter().connectT(1, smoothed_parameter2);    // pma14 -> smoothed_parameter2::Value
		auto& xfader4_x1_p = xfader4_x1.getWrappedObject().getParameter();
		xfader4_x1_p.getParameterT(4).connectT(0, pma14);                            // xfader4_x1 -> pma14::Add
		pma.getWrappedObject().getParameter().connectT(0, xfader_x1);                // pma -> xfader_x1::Value
		pma.getWrappedObject().getParameter().connectT(1, xfader2_x1);               // pma -> xfader2_x1::Value
		pma.getWrappedObject().getParameter().connectT(2, xfader1_x1);               // pma -> xfader1_x1::Value
		pma.getWrappedObject().getParameter().connectT(3, xfader3_x1);               // pma -> xfader3_x1::Value
		pma.getWrappedObject().getParameter().connectT(4, xfader4_x1);               // pma -> xfader4_x1::Value
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
		
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade5_impl::global_cable16_t<NV>
        getT(2).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade5_impl::global_cable17_t<NV>
        getT(2).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade5_impl::global_cable18_t<NV>
        getT(2).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade5_impl::global_cable19_t<NV>
        getT(2).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade5_impl::global_cable20_t<NV>
        getT(2).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade5_impl::global_cable21_t<NV>
        getT(2).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade5_impl::global_cable22_t<NV>
        getT(2).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade5_impl::global_cable23_t<NV>
        getT(2).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0).setExternalData(b, index); // xfade5_impl::cable_table11_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(1).setExternalData(b, index); // xfade5_impl::cable_table12_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).                                           // xfade5_impl::peak2_t<NV>
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
using xfade5 = wrap::node<xfade5_impl::instance<NV>>;
}


