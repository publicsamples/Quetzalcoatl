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

namespace xfade1_impl
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
using input_toggle16_t = control::input_toggle<NV, 
                                               parameter::plain<pma9_t<NV>, 2>>;
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
DECLARE_PARAMETER_RANGE(xfader_x1_c0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using xfader_x1_c0 = parameter::from0To1<pma8_t<NV>, 
                                         2, 
                                         xfader_x1_c0Range>;

template <int NV>
using xfader_x1_multimod = parameter::list<xfader_x1_c0<NV>, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
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
using input_toggle2_t = control::input_toggle<NV, 
                                              parameter::plain<pma11_t<NV>, 2>>;
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
using xfader2_x1_c0 = parameter::from0To1<pma10_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader2_x1_multimod = parameter::list<xfader2_x1_c0<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
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
using input_toggle4_t = control::input_toggle<NV, 
                                              parameter::plain<pma13_t<NV>, 2>>;
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
using xfader1_x1_c0 = parameter::from0To1<pma12_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader1_x1_multimod = parameter::list<xfader1_x1_c0<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
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
using input_toggle5_t = control::input_toggle<NV, 
                                              parameter::plain<pma15_t<NV>, 2>>;
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
using xfader3_x1_c0 = parameter::from0To1<pma17_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader3_x1_multimod = parameter::list<xfader3_x1_c0<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
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
using input_toggle3_t = control::input_toggle<NV, 
                                              parameter::plain<pma16_t<NV>, 2>>;
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
using xfader4_x1_c0 = parameter::from0To1<pma14_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader4_x1_multimod = parameter::list<xfader4_x1_c0<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
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
using input_toggle6_t = control::input_toggle<NV, 
                                              parameter::plain<pma19_t<NV>, 2>>;
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
using xfader_x2_c0 = parameter::from0To1<pma21_t<NV>, 
                                         2, 
                                         xfader_x1_c0Range>;

template <int NV>
using xfader_x2_multimod = parameter::list<xfader_x2_c0<NV>, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty>;

template <int NV>
using xfader_x2_t = control::xfader<xfader_x2_multimod<NV>, faders::switcher>;

template <int NV> using pma20_mod = pma9_mod<NV>;

template <int NV>
using pma20_t = control::pma<NV, pma20_mod<NV>>;
template <int NV>
using input_toggle7_t = control::input_toggle<NV, 
                                              parameter::plain<pma20_t<NV>, 2>>;
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
using xfader2_x2_c0 = parameter::from0To1<pma18_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader2_x2_multimod = parameter::list<xfader2_x2_c0<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader2_x2_t = control::xfader<xfader2_x2_multimod<NV>, 
                                     faders::linear>;

template <int NV> using pma23_mod = pma9_mod<NV>;

template <int NV>
using pma23_t = control::pma<NV, pma23_mod<NV>>;
template <int NV>
using input_toggle8_t = control::input_toggle<NV, 
                                              parameter::plain<pma23_t<NV>, 2>>;
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
using xfader1_x2_c0 = parameter::from0To1<pma22_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader1_x2_multimod = parameter::list<xfader1_x2_c0<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader1_x2_t = control::xfader<xfader1_x2_multimod<NV>, 
                                     faders::squared>;

template <int NV> using pma25_mod = pma9_mod<NV>;

template <int NV>
using pma25_t = control::pma<NV, pma25_mod<NV>>;
template <int NV>
using input_toggle9_t = control::input_toggle<NV, 
                                              parameter::plain<pma25_t<NV>, 2>>;
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
using xfader3_x2_c0 = parameter::from0To1<pma24_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader3_x2_multimod = parameter::list<xfader3_x2_c0<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader3_x2_t = control::xfader<xfader3_x2_multimod<NV>, 
                                     faders::cosine>;

template <int NV> using pma27_mod = pma9_mod<NV>;

template <int NV>
using pma27_t = control::pma<NV, pma27_mod<NV>>;
template <int NV>
using input_toggle10_t = control::input_toggle<NV, 
                                               parameter::plain<pma27_t<NV>, 2>>;
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
using xfader4_x2_c0 = parameter::from0To1<pma26_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader4_x2_multimod = parameter::list<xfader4_x2_c0<NV>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader4_x2_t = control::xfader<xfader4_x2_multimod<NV>, 
                                     faders::threshold>;

template <int NV> using pma32_mod = pma9_mod<NV>;

template <int NV>
using pma32_t = control::pma<NV, pma32_mod<NV>>;
template <int NV>
using input_toggle11_t = control::input_toggle<NV, 
                                               parameter::plain<pma32_t<NV>, 2>>;
template <int NV>
using smoothed_parameter10_t = wrap::mod<parameter::plain<input_toggle11_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using smoothed_parameter_x3_t = wrap::mod<parameter::plain<input_toggle11_t<NV>, 1>, 
                                          control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using pma28_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter10_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter_x3_t<NV>, 0>>;

template <int NV>
using pma28_t = control::pma<NV, pma28_mod<NV>>;
template <int NV>
using xfader_x3_c0 = parameter::from0To1<pma28_t<NV>, 
                                         2, 
                                         xfader_x1_c0Range>;

template <int NV>
using xfader_x3_multimod = parameter::list<xfader_x3_c0<NV>, parameter::empty>;

template <int NV>
using xfader_x3_t = control::xfader<xfader_x3_multimod<NV>, faders::switcher>;

template <int NV> using pma37_mod = pma9_mod<NV>;

template <int NV>
using pma37_t = control::pma<NV, pma37_mod<NV>>;
template <int NV>
using input_toggle12_t = control::input_toggle<NV, 
                                               parameter::plain<pma37_t<NV>, 2>>;
template <int NV>
using smoothed_parameter1_x3_t = wrap::mod<parameter::plain<input_toggle12_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter11_t = wrap::mod<parameter::plain<input_toggle12_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma29_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter1_x3_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter11_t<NV>, 0>>;

template <int NV>
using pma29_t = control::pma<NV, pma29_mod<NV>>;
template <int NV>
using xfader2_x3_c0 = parameter::from0To1<pma29_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader2_x3_multimod = parameter::list<xfader2_x3_c0<NV>, parameter::empty>;

template <int NV>
using xfader2_x3_t = control::xfader<xfader2_x3_multimod<NV>, 
                                     faders::linear>;

template <int NV> using pma36_mod = pma9_mod<NV>;

template <int NV>
using pma36_t = control::pma<NV, pma36_mod<NV>>;
template <int NV>
using input_toggle13_t = control::input_toggle<NV, 
                                               parameter::plain<pma36_t<NV>, 2>>;
template <int NV>
using smoothed_parameter2_x3_t = wrap::mod<parameter::plain<input_toggle13_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter12_t = wrap::mod<parameter::plain<input_toggle13_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma35_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter2_x3_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter12_t<NV>, 0>>;

template <int NV>
using pma35_t = control::pma<NV, pma35_mod<NV>>;
template <int NV>
using xfader1_x3_c0 = parameter::from0To1<pma35_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader1_x3_multimod = parameter::list<xfader1_x3_c0<NV>, parameter::empty>;

template <int NV>
using xfader1_x3_t = control::xfader<xfader1_x3_multimod<NV>, 
                                     faders::squared>;

template <int NV> using pma34_mod = pma9_mod<NV>;

template <int NV>
using pma34_t = control::pma<NV, pma34_mod<NV>>;
template <int NV>
using input_toggle14_t = control::input_toggle<NV, 
                                               parameter::plain<pma34_t<NV>, 2>>;
template <int NV>
using smoothed_parameter4_x3_t = wrap::mod<parameter::plain<input_toggle14_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter13_t = wrap::mod<parameter::plain<input_toggle14_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma33_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter4_x3_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter13_t<NV>, 0>>;

template <int NV>
using pma33_t = control::pma<NV, pma33_mod<NV>>;
template <int NV>
using xfader3_x3_c0 = parameter::from0To1<pma33_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader3_x3_multimod = parameter::list<xfader3_x3_c0<NV>, parameter::empty>;

template <int NV>
using xfader3_x3_t = control::xfader<xfader3_x3_multimod<NV>, 
                                     faders::cosine>;

template <int NV> using pma31_mod = pma9_mod<NV>;

template <int NV>
using pma31_t = control::pma<NV, pma31_mod<NV>>;
template <int NV>
using input_toggle15_t = control::input_toggle<NV, 
                                               parameter::plain<pma31_t<NV>, 2>>;
template <int NV>
using smoothed_parameter3_x3_t = wrap::mod<parameter::plain<input_toggle15_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter14_t = wrap::mod<parameter::plain<input_toggle15_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma30_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter3_x3_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter14_t<NV>, 0>>;

template <int NV>
using pma30_t = control::pma<NV, pma30_mod<NV>>;
template <int NV>
using xfader4_x3_c0 = parameter::from0To1<pma30_t<NV>, 
                                          2, 
                                          xfader_x1_c0Range>;

template <int NV>
using xfader4_x3_multimod = parameter::list<xfader4_x3_c0<NV>, parameter::empty>;

template <int NV>
using xfader4_x3_t = control::xfader<xfader4_x3_multimod<NV>, 
                                     faders::overlap>;

template <int NV> using pma41_mod = pma9_mod<NV>;

template <int NV>
using pma41_t = control::pma<NV, pma41_mod<NV>>;
template <int NV>
using input_toggle18_t = control::input_toggle<NV, 
                                               parameter::plain<pma41_t<NV>, 2>>;
template <int NV>
using smoothed_parameter3_x5_t = wrap::mod<parameter::plain<input_toggle18_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter16_t = wrap::mod<parameter::plain<input_toggle18_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma40_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter3_x5_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter16_t<NV>, 0>>;

template <int NV>
using pma40_t = control::pma<NV, pma40_mod<NV>>;
template <int NV>
using cable_table17_mod = parameter::from0To1<pma40_t<NV>, 
                                              2, 
                                              xfader_x1_c0Range>;

template <int NV>
using cable_table17_t = wrap::data<control::cable_table<cable_table17_mod<NV>>, 
                                   data::external::table<0>>;

struct cable_table3_t_data
{
	span<float, 512> data =
	{
		0.f, 0.0154147f, 0.0308294f, 0.0462441f, 0.0616589f, 0.0770736f,
		0.0924883f, 0.107903f, 0.123318f, 0.138732f, 0.154147f, 0.169562f,
		0.184977f, 0.200391f, 0.215806f, 0.231221f, 0.246636f, 0.26205f,
		0.277465f, 0.29288f, 0.308294f, 0.323709f, 0.339124f, 0.354539f,
		0.369953f, 0.385368f, 0.400783f, 0.416198f, 0.431612f, 0.447027f,
		0.462442f, 0.477856f, 0.493271f, 0.508686f, 0.524101f, 0.539515f,
		0.55493f, 0.570345f, 0.585759f, 0.601174f, 0.616589f, 0.632004f,
		0.647418f, 0.662833f, 0.678248f, 0.693663f, 0.709077f, 0.724492f,
		0.739907f, 0.755321f, 0.770736f, 0.786151f, 0.801566f, 0.81698f,
		0.832395f, 0.84781f, 0.863225f, 0.878639f, 0.894054f, 0.909469f,
		0.924883f, 0.940298f, 0.955713f, 0.971128f, 0.986542f, 1.f,
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
using cable_table3_t = wrap::data<control::cable_table<parameter::plain<cable_table17_t<NV>, 0>>, 
                                  data::embedded::table<cable_table3_t_data>>;

struct cable_table5_t_data
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
		0.f, 0.f, 0.f, 0.00190473f, 0.0173844f, 0.0328641f,
		0.0483437f, 0.0638235f, 0.0793031f, 0.0947828f, 0.110262f, 0.125742f,
		0.141222f, 0.156702f, 0.172181f, 0.187661f, 0.20314f, 0.21862f,
		0.2341f, 0.24958f, 0.265059f, 0.280539f, 0.296018f, 0.311498f,
		0.326978f, 0.342458f, 0.357937f, 0.373417f, 0.388897f, 0.404376f,
		0.419856f, 0.435336f, 0.450815f, 0.466295f, 0.481775f, 0.497254f,
		0.512734f, 0.528214f, 0.543693f, 0.559173f, 0.574653f, 0.590132f,
		0.605612f, 0.621092f, 0.636571f, 0.652051f, 0.667531f, 0.68301f,
		0.69849f, 0.71397f, 0.729449f, 0.744929f, 0.760409f, 0.775888f,
		0.791368f, 0.806848f, 0.822327f, 0.837807f, 0.853287f, 0.868766f,
		0.884246f, 0.899726f, 0.915205f, 0.930685f, 0.946165f, 0.961644f,
		0.977124f, 0.988771f, 0.988801f, 0.98883f, 0.988859f, 0.988888f,
		0.988918f, 0.988947f, 0.988976f, 0.989005f, 0.989034f, 0.989064f,
		0.989093f, 0.989122f, 0.989151f, 0.989181f, 0.98921f, 0.989239f,
		0.989268f, 0.989298f, 0.989327f, 0.989356f, 0.989385f, 0.989415f,
		0.989444f, 0.989473f, 0.989502f, 0.989532f, 0.989561f, 0.98959f,
		0.989619f, 0.989649f, 0.989678f, 0.989707f, 0.989736f, 0.989766f,
		0.989795f, 0.989824f, 0.989853f, 0.989882f, 0.989912f, 0.989941f,
		0.98997f, 0.989999f, 0.990029f, 0.990058f, 0.990087f, 0.990116f,
		0.990146f, 0.990175f, 0.990204f, 0.990233f, 0.990263f, 0.990292f,
		0.990321f, 0.99035f, 0.99038f, 0.990409f, 0.990438f, 0.990467f,
		0.990497f, 0.990526f, 0.990555f, 0.990584f, 0.990614f, 0.990643f,
		0.990672f, 0.990701f, 0.99073f, 0.99076f, 0.990789f, 0.990818f,
		0.990847f, 0.990877f, 0.990906f, 0.990935f, 0.990964f, 0.990994f,
		0.991023f, 0.991052f, 0.991081f, 0.991111f, 0.99114f, 0.991169f,
		0.991198f, 0.991228f, 0.991257f, 0.991286f, 0.991315f, 0.991345f,
		0.991374f, 0.991403f, 0.991432f, 0.991462f, 0.991491f, 0.99152f,
		0.991549f, 0.991578f, 0.991608f, 0.991637f, 0.991666f, 0.991695f,
		0.991725f, 0.991754f, 0.991783f, 0.991812f, 0.991842f, 0.991871f,
		0.9919f, 0.991929f, 0.991959f, 0.991988f, 0.992017f, 0.992046f,
		0.992076f, 0.992105f, 0.992134f, 0.992163f, 0.992193f, 0.992222f,
		0.992251f, 0.99228f, 0.99231f, 0.992339f, 0.992368f, 0.992397f,
		0.992426f, 0.992456f, 0.992485f, 0.992514f, 0.992543f, 0.992573f,
		0.992602f, 0.992631f, 0.99266f, 0.99269f, 0.992719f, 0.992748f,
		0.992777f, 0.992807f, 0.992836f, 0.992865f, 0.992894f, 0.992924f,
		0.992953f, 0.992982f, 0.993011f, 0.993041f, 0.99307f, 0.993099f,
		0.993128f, 0.993158f, 0.993187f, 0.993216f, 0.993245f, 0.993274f,
		0.993304f, 0.993333f, 0.993362f, 0.993391f, 0.993421f, 0.99345f,
		0.993479f, 0.993508f, 0.993538f, 0.993567f, 0.993596f, 0.993625f,
		0.993655f, 0.993684f, 0.993713f, 0.993742f, 0.993772f, 0.993801f,
		0.99383f, 0.993859f, 0.993889f, 0.993918f, 0.993947f, 0.993976f,
		0.994006f, 0.994035f, 0.994064f, 0.994093f, 0.994123f, 0.994152f,
		0.994181f, 0.99421f, 0.994239f, 0.994269f, 0.994298f, 0.994327f,
		0.994356f, 0.994386f, 0.994415f, 0.994444f, 0.994473f, 0.994503f,
		0.994532f, 0.994561f, 0.99459f, 0.99462f, 0.994649f, 0.994678f,
		0.994707f, 0.994737f, 0.994766f, 0.994795f, 0.994824f, 0.994853f,
		0.994883f, 0.994912f, 0.994941f, 0.994971f, 0.995f, 0.995029f,
		0.995058f, 0.995087f, 0.995117f, 0.995146f, 0.995175f, 0.995204f,
		0.995234f, 0.995263f, 0.995292f, 0.995321f, 0.995351f, 0.99538f,
		0.995409f, 0.995438f, 0.995468f, 0.995497f, 0.995526f, 0.995555f,
		0.995585f, 0.995614f, 0.995643f, 0.995672f, 0.995701f, 0.995731f,
		0.99576f, 0.995789f, 0.995818f, 0.995848f, 0.995877f, 0.995906f,
		0.995935f, 0.995965f, 0.995994f, 0.996023f, 0.996052f, 0.996082f,
		0.996111f, 0.99614f, 0.996169f, 0.996199f, 0.996228f, 0.996257f,
		0.996286f, 0.996316f, 0.996345f, 0.996374f, 0.996403f, 0.996433f,
		0.996462f, 0.996491f, 0.99652f, 0.996549f, 0.996579f, 0.996608f,
		0.996637f, 0.996666f, 0.996696f, 0.996725f, 0.996754f, 0.996783f,
		0.996813f, 0.996842f, 0.996871f, 0.9969f, 0.99693f, 0.996959f,
		0.996988f, 0.997017f, 0.997047f, 0.997076f, 0.997105f, 0.997134f,
		0.997164f, 0.997193f, 0.997222f, 0.997251f, 0.997281f, 0.99731f,
		0.997339f, 0.997368f, 0.997398f, 0.997427f, 0.997456f, 0.997485f,
		0.997514f, 0.997544f, 0.997573f, 0.997602f, 0.997631f, 0.997661f,
		0.99769f, 0.997719f, 0.997748f, 0.997778f, 0.997807f, 0.997836f,
		0.997865f, 0.997895f, 0.997924f, 0.997953f, 0.997982f, 0.998012f,
		0.998041f, 0.99807f, 0.998099f, 0.998129f, 0.998158f, 0.998187f,
		0.998216f, 0.998246f, 0.998275f, 0.998304f, 0.998333f, 0.998362f,
		0.998392f, 0.998421f, 0.99845f, 0.998479f, 0.998509f, 0.998538f,
		0.998567f, 0.998596f, 0.998626f, 0.998655f, 0.998684f, 0.998713f,
		0.998743f, 0.998772f, 0.998801f, 0.99883f, 0.99886f, 0.998889f,
		0.998918f, 0.998947f, 0.998977f, 0.999006f, 0.999035f, 0.999064f,
		0.999094f, 0.999123f, 0.999152f, 0.999181f, 0.99921f, 0.99924f,
		0.999269f, 0.999298f, 0.999327f, 0.999357f, 0.999386f, 0.999415f,
		0.999444f, 0.999474f, 0.999503f, 0.999532f, 0.999561f, 0.999591f,
		0.99962f, 0.999649f, 0.999678f, 0.999708f, 0.999737f, 0.999766f,
		0.999795f, 0.999825f, 0.999854f, 0.999883f, 0.999912f, 0.999942f,
		0.999971f, 1.f
	};
};

using cable_table5_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table5_t_data>>;

struct cable_table7_t_data
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
		0.f, 0.00394499f, 0.019849f, 0.035753f, 0.0516573f, 0.0675613f,
		0.0834653f, 0.0993693f, 0.115274f, 0.131178f, 0.147082f, 0.162986f,
		0.17889f, 0.194794f, 0.210698f, 0.226602f, 0.242506f, 0.25841f,
		0.274314f, 0.290218f, 0.306123f, 0.322027f, 0.337931f, 0.353835f,
		0.369739f, 0.385643f, 0.401547f, 0.417451f, 0.433355f, 0.449259f,
		0.465163f, 0.481067f, 0.496971f, 0.512875f, 0.52878f, 0.544684f,
		0.560588f, 0.576492f, 0.592396f, 0.6083f, 0.624204f, 0.640108f,
		0.656012f, 0.671916f, 0.68782f, 0.703724f, 0.719628f, 0.735532f,
		0.751437f, 0.767341f, 0.783245f, 0.799149f, 0.815053f, 0.830957f,
		0.846861f, 0.862765f, 0.878669f, 0.894573f, 0.910477f, 0.926381f,
		0.942286f, 0.95819f, 0.974094f, 0.989998f, 1.f, 1.f,
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

using cable_table7_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table7_t_data>>;

struct cable_table9_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.00572038f, 0.0211351f,
		0.0365497f, 0.0519644f, 0.0673793f, 0.082794f, 0.0982086f, 0.113623f,
		0.129038f, 0.144453f, 0.159868f, 0.175282f, 0.190697f, 0.206112f,
		0.221526f, 0.236941f, 0.252356f, 0.267771f, 0.283185f, 0.2986f,
		0.314015f, 0.32943f, 0.344844f, 0.360259f, 0.375674f, 0.391088f,
		0.406503f, 0.421918f, 0.437333f, 0.452747f, 0.468162f, 0.483577f,
		0.498992f, 0.514406f, 0.529821f, 0.545236f, 0.56065f, 0.576065f,
		0.59148f, 0.606894f, 0.622309f, 0.637724f, 0.653139f, 0.668553f,
		0.683968f, 0.699383f, 0.714798f, 0.730212f, 0.745627f, 0.761042f,
		0.776456f, 0.791871f, 0.807286f, 0.822701f, 0.838115f, 0.85353f,
		0.868945f, 0.884359f, 0.899774f, 0.915189f, 0.930604f, 0.946018f,
		0.961433f, 0.976848f, 0.992263f, 1.f, 1.f, 1.f,
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

using cable_table9_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table9_t_data>>;

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
		0.00841469f, 0.0251139f, 0.0418137f, 0.0585129f, 0.0752121f, 0.0919113f,
		0.108611f, 0.12531f, 0.142009f, 0.158708f, 0.175408f, 0.192107f,
		0.208806f, 0.225506f, 0.242205f, 0.258904f, 0.275603f, 0.292302f,
		0.309002f, 0.325701f, 0.342401f, 0.3591f, 0.375799f, 0.392498f,
		0.409198f, 0.425897f, 0.442596f, 0.459296f, 0.475995f, 0.492694f,
		0.509393f, 0.526093f, 0.542792f, 0.559491f, 0.576191f, 0.59289f,
		0.609589f, 0.626288f, 0.642988f, 0.659687f, 0.676386f, 0.693085f,
		0.709785f, 0.726484f, 0.743183f, 0.759883f, 0.776582f, 0.793281f,
		0.80998f, 0.826679f, 0.843379f, 0.860078f, 0.876778f, 0.893477f,
		0.910176f, 0.926875f, 0.943575f, 0.960274f, 0.976974f, 0.993673f,
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

using cable_table11_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::embedded::table<cable_table11_t_data>>;

struct cable_table13_t_data
{
	span<float, 512> data =
	{
		0.f, 7.12276e-05f, 0.000142515f, 0.000213742f, 0.000285029f, 0.000356257f,
		0.000427544f, 0.000498772f, 0.000569999f, 0.000641286f, 0.000712514f, 0.000783801f,
		0.000855029f, 0.000926316f, 0.000997543f, 0.00106877f, 0.00114006f, 0.00121129f,
		0.00128257f, 0.0013538f, 0.00142503f, 0.00149632f, 0.00156754f, 0.00163883f,
		0.00171006f, 0.00178134f, 0.00185257f, 0.0019238f, 0.00199509f, 0.00206631f,
		0.0021376f, 0.00220883f, 0.00228012f, 0.00235134f, 0.00242257f, 0.00249386f,
		0.00256509f, 0.00263637f, 0.0027076f, 0.00277889f, 0.00285012f, 0.00292134f,
		0.00299263f, 0.00306386f, 0.00313514f, 0.00320637f, 0.0032776f, 0.00334889f,
		0.00342011f, 0.0034914f, 0.00356263f, 0.00363392f, 0.00370514f, 0.00377637f,
		0.00384766f, 0.00391889f, 0.00399017f, 0.0040614f, 0.00413269f, 0.00420392f,
		0.00427514f, 0.00434643f, 0.00441766f, 0.00448895f, 0.00456017f, 0.00463146f,
		0.00470269f, 0.00477391f, 0.0048452f, 0.00491643f, 0.00498772f, 0.00505894f,
		0.00513017f, 0.00520146f, 0.00527269f, 0.00534397f, 0.0054152f, 0.00548649f,
		0.00555772f, 0.00562894f, 0.00570023f, 0.00577146f, 0.00584275f, 0.00591397f,
		0.00598526f, 0.00605649f, 0.00612772f, 0.006199f, 0.00627023f, 0.00634152f,
		0.00641274f, 0.00648403f, 0.00655526f, 0.00662649f, 0.00669777f, 0.006769f,
		0.00684029f, 0.00691152f, 0.00698274f, 0.00705403f, 0.00712526f, 0.00719655f,
		0.00726777f, 0.00733906f, 0.00741029f, 0.00748152f, 0.0075528f, 0.00762403f,
		0.00769532f, 0.00776654f, 0.00783783f, 0.00790906f, 0.00798029f, 0.00805157f,
		0.0081228f, 0.00819409f, 0.00826532f, 0.0083366f, 0.00840783f, 0.00847906f,
		0.00855035f, 0.00862157f, 0.00869286f, 0.00876409f, 0.00883532f, 0.0089066f,
		0.00897783f, 0.00904912f, 0.00912035f, 0.00919163f, 0.00926286f, 0.00933409f,
		0.00940537f, 0.0094766f, 0.00954789f, 0.00961912f, 0.0096904f, 0.00976163f,
		0.00983286f, 0.00990415f, 0.00997537f, 0.0100467f, 0.0101179f, 0.0101892f,
		0.0102604f, 0.0103316f, 0.0104029f, 0.0104741f, 0.0105454f, 0.0106167f,
		0.0106879f, 0.0107592f, 0.0108304f, 0.0109017f, 0.0109729f, 0.0110442f,
		0.0111154f, 0.0111867f, 0.0112579f, 0.0113292f, 0.0114005f, 0.0114717f,
		0.011543f, 0.0116142f, 0.0116854f, 0.0117567f, 0.0118279f, 0.0118992f,
		0.0119705f, 0.0120417f, 0.012113f, 0.0121842f, 0.0122555f, 0.0123267f,
		0.012398f, 0.0124692f, 0.0125405f, 0.0126117f, 0.012683f, 0.0127543f,
		0.0128255f, 0.0128968f, 0.012968f, 0.0130392f, 0.0131105f, 0.0131817f,
		0.013253f, 0.0133243f, 0.0133955f, 0.0134668f, 0.013538f, 0.0136093f,
		0.0136805f, 0.0137518f, 0.013823f, 0.0138943f, 0.0139655f, 0.0140368f,
		0.0141081f, 0.0141793f, 0.0142506f, 0.0143218f, 0.0143931f, 0.0144643f,
		0.0145355f, 0.0146068f, 0.0146781f, 0.0147493f, 0.0148206f, 0.0148918f,
		0.0149631f, 0.0150343f, 0.0151056f, 0.0151768f, 0.0152481f, 0.0153193f,
		0.0153906f, 0.0154619f, 0.0155331f, 0.0156044f, 0.0156756f, 0.0157469f,
		0.0158181f, 0.0158893f, 0.0159606f, 0.0160319f, 0.0161031f, 0.0161744f,
		0.0162457f, 0.0163169f, 0.0163881f, 0.0164594f, 0.0165306f, 0.0166019f,
		0.0166731f, 0.0167444f, 0.0168157f, 0.0168869f, 0.0169582f, 0.0170294f,
		0.0171007f, 0.0171719f, 0.0172431f, 0.0173144f, 0.0173857f, 0.0174569f,
		0.0175282f, 0.0175995f, 0.0176707f, 0.0177419f, 0.0178132f, 0.0178844f,
		0.0179557f, 0.0180269f, 0.0180982f, 0.0181695f, 0.0182407f, 0.018312f,
		0.0183832f, 0.0184545f, 0.0185257f, 0.018597f, 0.0186682f, 0.0187395f,
		0.0188107f, 0.018882f, 0.0189533f, 0.0190245f, 0.0190957f, 0.019167f,
		0.0192382f, 0.0193095f, 0.0193807f, 0.019452f, 0.0195233f, 0.0195945f,
		0.0196658f, 0.019737f, 0.0198083f, 0.0198795f, 0.0199508f, 0.020022f,
		0.0200933f, 0.0201645f, 0.0202358f, 0.0203071f, 0.0203783f, 0.0204495f,
		0.0205208f, 0.020592f, 0.0206633f, 0.0207345f, 0.0208058f, 0.0208771f,
		0.0209483f, 0.0210196f, 0.0210908f, 0.0211621f, 0.0212333f, 0.0213046f,
		0.0213758f, 0.0214471f, 0.0215183f, 0.0215896f, 0.0216609f, 0.0217321f,
		0.0218034f, 0.0218746f, 0.0219458f, 0.0220171f, 0.0220883f, 0.0221596f,
		0.0222309f, 0.0223022f, 0.0223734f, 0.0224446f, 0.0313618f, 0.0457653f,
		0.0601687f, 0.0745723f, 0.0889757f, 0.103379f, 0.117783f, 0.132186f,
		0.14659f, 0.160994f, 0.175397f, 0.189801f, 0.204204f, 0.218608f,
		0.233011f, 0.247415f, 0.261818f, 0.276222f, 0.290625f, 0.305029f,
		0.319432f, 0.333836f, 0.348239f, 0.362643f, 0.377047f, 0.39145f,
		0.405854f, 0.420257f, 0.434661f, 0.449064f, 0.463468f, 0.477871f,
		0.492275f, 0.506679f, 0.521082f, 0.535486f, 0.549889f, 0.564293f,
		0.578696f, 0.5931f, 0.607504f, 0.621907f, 0.636311f, 0.650714f,
		0.665118f, 0.679521f, 0.693924f, 0.708328f, 0.722732f, 0.737135f,
		0.751539f, 0.765942f, 0.780346f, 0.794749f, 0.809153f, 0.823556f,
		0.83796f, 0.852364f, 0.866767f, 0.881171f, 0.895574f, 0.909978f,
		0.924381f, 0.938785f, 0.953189f, 0.967592f, 0.981996f, 0.996399f,
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

using cable_table13_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::embedded::table<cable_table13_t_data>>;

struct cable_table15_t_data
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
		0.0125244f, 0.0292236f, 0.0459229f, 0.0626221f, 0.0793218f, 0.0960211f,
		0.11272f, 0.129419f, 0.146119f, 0.162818f, 0.179517f, 0.196216f,
		0.212916f, 0.229615f, 0.246315f, 0.263014f, 0.279713f, 0.296412f,
		0.313111f, 0.329811f, 0.34651f, 0.36321f, 0.379909f, 0.396608f,
		0.413307f, 0.430006f, 0.446706f, 0.463405f, 0.480105f, 0.496804f,
		0.513503f, 0.530202f, 0.546901f, 0.563601f, 0.5803f, 0.596999f,
		0.613699f, 0.630398f, 0.647097f, 0.663797f, 0.680496f, 0.697195f,
		0.713894f, 0.730593f, 0.747293f, 0.763992f, 0.780692f, 0.797391f,
		0.81409f, 0.830789f, 0.847488f, 0.864188f, 0.880887f, 0.897587f,
		0.914286f, 0.930985f, 0.947684f, 0.964383f, 0.981083f, 0.997782f,
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

using cable_table15_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::embedded::table<cable_table15_t_data>>;
using cable_table16_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<7>>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table3_t<NV>, 0>, 
                                  parameter::plain<cable_table5_t, 0>, 
                                  parameter::plain<cable_table7_t, 0>, 
                                  parameter::plain<cable_table9_t, 0>, 
                                  parameter::plain<cable_table11_t, 0>, 
                                  parameter::plain<cable_table13_t, 0>, 
                                  parameter::plain<cable_table15_t, 0>, 
                                  parameter::plain<cable_table16_t, 0>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;

template <int NV> using pma39_mod = pma9_mod<NV>;

template <int NV>
using pma39_t = control::pma<NV, pma39_mod<NV>>;
template <int NV>
using input_toggle17_t = control::input_toggle<NV, 
                                               parameter::plain<pma39_t<NV>, 2>>;
template <int NV>
using smoothed_parameter3_x4_t = wrap::mod<parameter::plain<input_toggle17_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter15_t = wrap::mod<parameter::plain<input_toggle17_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma38_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter3_x4_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter15_t<NV>, 0>>;

template <int NV>
using pma38_t = control::pma<NV, pma38_mod<NV>>;
template <int NV>
using cable_table_mod = parameter::from0To1<pma38_t<NV>, 
                                            2, 
                                            xfader_x1_c0Range>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::external::table<0>>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00776708f, 0.0155342f, 0.0233013f, 0.0310684f, 0.0388355f,
		0.0466027f, 0.0543697f, 0.0621369f, 0.069904f, 0.0776711f, 0.0854382f,
		0.0932053f, 0.100972f, 0.108739f, 0.116507f, 0.124274f, 0.132041f,
		0.139808f, 0.147575f, 0.155342f, 0.163109f, 0.170876f, 0.178643f,
		0.186411f, 0.194178f, 0.201945f, 0.209712f, 0.217479f, 0.225246f,
		0.233013f, 0.24078f, 0.248547f, 0.256315f, 0.264082f, 0.271849f,
		0.279616f, 0.287383f, 0.29515f, 0.302917f, 0.310684f, 0.318451f,
		0.326219f, 0.333986f, 0.341753f, 0.34952f, 0.357287f, 0.365054f,
		0.372821f, 0.380588f, 0.388355f, 0.396123f, 0.40389f, 0.411657f,
		0.419424f, 0.427191f, 0.434958f, 0.442725f, 0.450492f, 0.458259f,
		0.466026f, 0.473794f, 0.481561f, 0.489328f, 0.497095f, 0.504862f,
		0.512629f, 0.520396f, 0.528163f, 0.535931f, 0.543698f, 0.551465f,
		0.559232f, 0.566999f, 0.574766f, 0.582533f, 0.5903f, 0.598067f,
		0.605834f, 0.613602f, 0.621369f, 0.629136f, 0.636903f, 0.64467f,
		0.652437f, 0.660204f, 0.667971f, 0.675738f, 0.683506f, 0.691273f,
		0.69904f, 0.706807f, 0.714574f, 0.722341f, 0.730108f, 0.737875f,
		0.745642f, 0.75341f, 0.761177f, 0.768944f, 0.776711f, 0.784478f,
		0.792245f, 0.800012f, 0.807779f, 0.815546f, 0.823313f, 0.831081f,
		0.838848f, 0.846615f, 0.854382f, 0.862149f, 0.869916f, 0.877683f,
		0.88545f, 0.893217f, 0.900985f, 0.908752f, 0.916519f, 0.924286f,
		0.932053f, 0.93982f, 0.947587f, 0.955354f, 0.963121f, 0.970889f,
		0.978656f, 0.986423f, 0.99419f, 1.f, 1.f, 1.f,
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
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<cable_table_t<NV>, 0>>, 
                                  data::embedded::table<cable_table1_t_data>>;

struct cable_table2_t_data
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
		0.f, 0.00194168f, 0.00976944f, 0.0175972f, 0.0254251f, 0.0332528f,
		0.0410806f, 0.0489084f, 0.0567362f, 0.064564f, 0.0723917f, 0.0802195f,
		0.0880474f, 0.0958751f, 0.103703f, 0.111531f, 0.119359f, 0.127186f,
		0.135014f, 0.142842f, 0.15067f, 0.158497f, 0.166325f, 0.174153f,
		0.181981f, 0.189809f, 0.197636f, 0.205464f, 0.213292f, 0.22112f,
		0.228948f, 0.236775f, 0.244603f, 0.252431f, 0.260259f, 0.268086f,
		0.275914f, 0.283742f, 0.29157f, 0.299398f, 0.307225f, 0.315053f,
		0.322881f, 0.330709f, 0.338537f, 0.346364f, 0.354192f, 0.36202f,
		0.369848f, 0.377676f, 0.385503f, 0.393331f, 0.401159f, 0.408987f,
		0.416814f, 0.424642f, 0.43247f, 0.440298f, 0.448126f, 0.455953f,
		0.463781f, 0.471609f, 0.479437f, 0.487265f, 0.495092f, 0.50292f,
		0.510748f, 0.518576f, 0.526404f, 0.534231f, 0.542059f, 0.549887f,
		0.557715f, 0.565542f, 0.57337f, 0.581198f, 0.589026f, 0.596854f,
		0.604681f, 0.612509f, 0.620337f, 0.628165f, 0.635993f, 0.64382f,
		0.651648f, 0.659476f, 0.667304f, 0.675131f, 0.682959f, 0.690787f,
		0.698615f, 0.706443f, 0.71427f, 0.722098f, 0.729926f, 0.737754f,
		0.745582f, 0.753409f, 0.761237f, 0.769065f, 0.776893f, 0.784721f,
		0.792548f, 0.800376f, 0.808204f, 0.816032f, 0.823859f, 0.831687f,
		0.839515f, 0.847343f, 0.855171f, 0.862998f, 0.870826f, 0.878654f,
		0.886482f, 0.89431f, 0.902137f, 0.909965f, 0.917793f, 0.925621f,
		0.933449f, 0.941276f, 0.949104f, 0.956932f, 0.96476f, 0.972587f,
		0.980415f, 0.988243f, 0.996071f, 1.f, 1.f, 1.f,
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

using cable_table2_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table2_t_data>>;

struct cable_table4_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.00385368f, 0.011561f,
		0.0192683f, 0.0269756f, 0.0346832f, 0.0423906f, 0.0500979f, 0.0578052f,
		0.0655125f, 0.0732199f, 0.0809272f, 0.0886346f, 0.0963421f, 0.104049f,
		0.111757f, 0.119464f, 0.127171f, 0.134879f, 0.142586f, 0.150293f,
		0.158001f, 0.165708f, 0.173416f, 0.181123f, 0.18883f, 0.196538f,
		0.204245f, 0.211952f, 0.21966f, 0.227367f, 0.235075f, 0.242782f,
		0.250489f, 0.258197f, 0.265904f, 0.273611f, 0.281319f, 0.289026f,
		0.296733f, 0.304441f, 0.312148f, 0.319855f, 0.327563f, 0.33527f,
		0.342978f, 0.350685f, 0.358392f, 0.3661f, 0.373807f, 0.381514f,
		0.389222f, 0.396929f, 0.404637f, 0.412344f, 0.420051f, 0.427759f,
		0.435466f, 0.443173f, 0.450881f, 0.458588f, 0.466295f, 0.474003f,
		0.48171f, 0.489417f, 0.497125f, 0.504832f, 0.512539f, 0.520247f,
		0.527954f, 0.535662f, 0.543369f, 0.551076f, 0.558784f, 0.566491f,
		0.574198f, 0.581906f, 0.589613f, 0.597321f, 0.605028f, 0.612735f,
		0.620443f, 0.62815f, 0.635857f, 0.643565f, 0.651272f, 0.658979f,
		0.666687f, 0.674394f, 0.682101f, 0.689809f, 0.697516f, 0.705224f,
		0.712931f, 0.720638f, 0.728346f, 0.736053f, 0.74376f, 0.751468f,
		0.759175f, 0.766882f, 0.77459f, 0.782297f, 0.790005f, 0.797712f,
		0.805419f, 0.813127f, 0.820834f, 0.828541f, 0.836249f, 0.843956f,
		0.851663f, 0.859371f, 0.867078f, 0.874785f, 0.882493f, 0.8902f,
		0.897908f, 0.905615f, 0.913322f, 0.92103f, 0.928737f, 0.936444f,
		0.944152f, 0.951859f, 0.959567f, 0.967274f, 0.974981f, 0.982689f,
		0.990396f, 0.998103f, 1.f, 1.f, 1.f, 1.f,
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

using cable_table4_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table4_t_data>>;

struct cable_table6_t_data
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
		0.f, 0.00597948f, 0.0139315f, 0.0218835f, 0.0298358f, 0.0377878f,
		0.0457398f, 0.0536918f, 0.0616438f, 0.0695958f, 0.0775478f, 0.0854998f,
		0.0934521f, 0.101404f, 0.109356f, 0.117308f, 0.12526f, 0.133212f,
		0.141164f, 0.149116f, 0.157068f, 0.16502f, 0.172972f, 0.180924f,
		0.188876f, 0.196828f, 0.20478f, 0.212732f, 0.220685f, 0.228637f,
		0.236589f, 0.244541f, 0.252493f, 0.260445f, 0.268397f, 0.276349f,
		0.284301f, 0.292253f, 0.300205f, 0.308157f, 0.316109f, 0.324061f,
		0.332013f, 0.339965f, 0.347917f, 0.355869f, 0.363821f, 0.371773f,
		0.379725f, 0.387677f, 0.395629f, 0.403581f, 0.411534f, 0.419486f,
		0.427438f, 0.43539f, 0.443342f, 0.451294f, 0.459246f, 0.467198f,
		0.47515f, 0.483102f, 0.491054f, 0.499006f, 0.506958f, 0.51491f,
		0.522862f, 0.530814f, 0.538766f, 0.546718f, 0.55467f, 0.562622f,
		0.570574f, 0.578526f, 0.586478f, 0.59443f, 0.602383f, 0.610335f,
		0.618287f, 0.626239f, 0.634191f, 0.642143f, 0.650095f, 0.658047f,
		0.665999f, 0.673951f, 0.681903f, 0.689855f, 0.697807f, 0.705759f,
		0.713711f, 0.721663f, 0.729615f, 0.737567f, 0.745519f, 0.753471f,
		0.761423f, 0.769375f, 0.777327f, 0.785279f, 0.793231f, 0.801184f,
		0.809135f, 0.817088f, 0.82504f, 0.832992f, 0.840944f, 0.848896f,
		0.856848f, 0.8648f, 0.872752f, 0.880704f, 0.888656f, 0.896608f,
		0.90456f, 0.912512f, 0.920464f, 0.928416f, 0.936368f, 0.94432f,
		0.952272f, 0.960224f, 0.968176f, 0.976128f, 0.98408f, 0.992032f,
		0.999984f, 1.f
	};
};

using cable_table6_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table6_t_data>>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table1_t<NV>, 0>, 
                                  parameter::plain<cable_table2_t, 0>, 
                                  parameter::plain<cable_table4_t, 0>, 
                                  parameter::plain<cable_table6_t, 0>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;

template <int NV> using pma44_mod = pma9_mod<NV>;

template <int NV>
using pma44_t = control::pma<NV, pma44_mod<NV>>;
template <int NV>
using input_toggle19_t = control::input_toggle<NV, 
                                               parameter::plain<pma44_t<NV>, 2>>;
template <int NV>
using smoothed_parameter3_x6_t = wrap::mod<parameter::plain<input_toggle19_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter18_t = wrap::mod<parameter::plain<input_toggle19_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma43_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter3_x6_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter18_t<NV>, 0>>;

template <int NV>
using pma43_t = control::pma<NV, pma43_mod<NV>>;
template <int NV>
using cable_table22_mod = parameter::from0To1<pma43_t<NV>, 
                                              2, 
                                              xfader_x1_c0Range>;

template <int NV>
using cable_table22_t = wrap::data<control::cable_table<cable_table22_mod<NV>>, 
                                   data::external::table<0>>;

struct cable_table18_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00394469f, 0.00788945f, 0.0118341f, 0.0157788f, 0.0197235f,
		0.0236683f, 0.027613f, 0.0315577f, 0.0355024f, 0.0394471f, 0.0433918f,
		0.0473366f, 0.0512813f, 0.055226f, 0.0591707f, 0.0631154f, 0.0670601f,
		0.0710048f, 0.0749495f, 0.0788943f, 0.082839f, 0.0867836f, 0.0907284f,
		0.0946731f, 0.0986178f, 0.102563f, 0.106507f, 0.110452f, 0.114397f,
		0.118341f, 0.122286f, 0.126231f, 0.130176f, 0.13412f, 0.138065f,
		0.14201f, 0.145954f, 0.149899f, 0.153844f, 0.157789f, 0.161733f,
		0.165678f, 0.169623f, 0.173567f, 0.177512f, 0.181457f, 0.185401f,
		0.189346f, 0.193291f, 0.197236f, 0.20118f, 0.205125f, 0.20907f,
		0.213014f, 0.216959f, 0.220904f, 0.224849f, 0.228793f, 0.232738f,
		0.236683f, 0.240627f, 0.244572f, 0.248517f, 0.252462f, 0.256406f,
		0.260351f, 0.264296f, 0.26824f, 0.272185f, 0.27613f, 0.280075f,
		0.284019f, 0.287964f, 0.291909f, 0.295853f, 0.299798f, 0.303743f,
		0.307688f, 0.311632f, 0.315577f, 0.319522f, 0.323466f, 0.327411f,
		0.331356f, 0.335301f, 0.339245f, 0.34319f, 0.347135f, 0.351079f,
		0.355024f, 0.358969f, 0.362913f, 0.366858f, 0.370803f, 0.374748f,
		0.378692f, 0.382637f, 0.386582f, 0.390527f, 0.394471f, 0.398416f,
		0.402361f, 0.406305f, 0.41025f, 0.414195f, 0.41814f, 0.422084f,
		0.426029f, 0.429974f, 0.433918f, 0.437863f, 0.441808f, 0.445753f,
		0.449697f, 0.453642f, 0.457587f, 0.461531f, 0.465476f, 0.469421f,
		0.473365f, 0.47731f, 0.481255f, 0.4852f, 0.489144f, 0.493089f,
		0.497034f, 0.500978f, 0.504923f, 0.508868f, 0.512813f, 0.516757f,
		0.520702f, 0.524647f, 0.528591f, 0.532536f, 0.536481f, 0.540426f,
		0.54437f, 0.548315f, 0.55226f, 0.556204f, 0.560149f, 0.564094f,
		0.568039f, 0.571983f, 0.575928f, 0.579873f, 0.583817f, 0.587762f,
		0.591707f, 0.595652f, 0.599596f, 0.603541f, 0.607486f, 0.61143f,
		0.615375f, 0.61932f, 0.623265f, 0.627209f, 0.631154f, 0.635099f,
		0.639043f, 0.642988f, 0.646933f, 0.650878f, 0.654822f, 0.658767f,
		0.662712f, 0.666656f, 0.670601f, 0.674546f, 0.678491f, 0.682435f,
		0.68638f, 0.690325f, 0.694269f, 0.698214f, 0.702159f, 0.706104f,
		0.710048f, 0.713993f, 0.717938f, 0.721882f, 0.725827f, 0.729772f,
		0.733717f, 0.737661f, 0.741606f, 0.745551f, 0.749495f, 0.75344f,
		0.757385f, 0.761329f, 0.765274f, 0.769219f, 0.773164f, 0.777108f,
		0.781053f, 0.784998f, 0.788942f, 0.792887f, 0.796832f, 0.800777f,
		0.804721f, 0.808666f, 0.812611f, 0.816556f, 0.8205f, 0.824445f,
		0.82839f, 0.832334f, 0.836279f, 0.840224f, 0.844168f, 0.848113f,
		0.852058f, 0.856003f, 0.859947f, 0.863892f, 0.867837f, 0.871781f,
		0.875726f, 0.879671f, 0.883616f, 0.88756f, 0.891505f, 0.89545f,
		0.899394f, 0.903339f, 0.907284f, 0.911229f, 0.915173f, 0.919118f,
		0.923063f, 0.927007f, 0.930952f, 0.934897f, 0.938842f, 0.942786f,
		0.946731f, 0.950676f, 0.95462f, 0.958565f, 0.96251f, 0.966455f,
		0.970399f, 0.974344f, 0.978289f, 0.982233f, 0.986178f, 0.990123f,
		0.994067f, 0.998012f, 1.f, 1.f, 1.f, 1.f,
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
using cable_table18_t = wrap::data<control::cable_table<parameter::plain<cable_table22_t<NV>, 0>>, 
                                   data::embedded::table<cable_table18_t_data>>;

struct cable_table19_t_data
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
		0.f, 0.f, 0.00193411f, 0.00583279f, 0.00973141f, 0.0136301f,
		0.0175287f, 0.0214274f, 0.0253261f, 0.0292248f, 0.0331234f, 0.0370221f,
		0.0409207f, 0.0448194f, 0.048718f, 0.0526167f, 0.0565155f, 0.0604141f,
		0.0643128f, 0.0682114f, 0.0721101f, 0.0760087f, 0.0799074f, 0.083806f,
		0.0877048f, 0.0916035f, 0.0955021f, 0.0994008f, 0.103299f, 0.107198f,
		0.111097f, 0.114995f, 0.118894f, 0.122793f, 0.126691f, 0.13059f,
		0.134489f, 0.138387f, 0.142286f, 0.146185f, 0.150083f, 0.153982f,
		0.157881f, 0.161779f, 0.165678f, 0.169577f, 0.173475f, 0.177374f,
		0.181273f, 0.185171f, 0.18907f, 0.192969f, 0.196867f, 0.200766f,
		0.204665f, 0.208563f, 0.212462f, 0.216361f, 0.220259f, 0.224158f,
		0.228057f, 0.231955f, 0.235854f, 0.239753f, 0.243651f, 0.24755f,
		0.251449f, 0.255347f, 0.259246f, 0.263145f, 0.267043f, 0.270942f,
		0.274841f, 0.278739f, 0.282638f, 0.286537f, 0.290435f, 0.294334f,
		0.298233f, 0.302131f, 0.30603f, 0.309929f, 0.313827f, 0.317726f,
		0.321625f, 0.325523f, 0.329422f, 0.333321f, 0.337219f, 0.341118f,
		0.345017f, 0.348915f, 0.352814f, 0.356713f, 0.360611f, 0.36451f,
		0.368409f, 0.372307f, 0.376206f, 0.380105f, 0.384003f, 0.387902f,
		0.391801f, 0.395699f, 0.399598f, 0.403497f, 0.407395f, 0.411294f,
		0.415193f, 0.419091f, 0.42299f, 0.426889f, 0.430787f, 0.434686f,
		0.438585f, 0.442483f, 0.446382f, 0.450281f, 0.454179f, 0.458078f,
		0.461977f, 0.465875f, 0.469774f, 0.473673f, 0.477571f, 0.48147f,
		0.485368f, 0.489267f, 0.493166f, 0.497065f, 0.500963f, 0.504862f,
		0.508761f, 0.512659f, 0.516558f, 0.520456f, 0.524355f, 0.528254f,
		0.532153f, 0.536051f, 0.53995f, 0.543849f, 0.547747f, 0.551646f,
		0.555545f, 0.559443f, 0.563342f, 0.567241f, 0.571139f, 0.575038f,
		0.578936f, 0.582835f, 0.586734f, 0.590633f, 0.594531f, 0.59843f,
		0.602328f, 0.606227f, 0.610126f, 0.614024f, 0.617923f, 0.621822f,
		0.625721f, 0.629619f, 0.633518f, 0.637416f, 0.641315f, 0.645214f,
		0.649113f, 0.653011f, 0.65691f, 0.660809f, 0.664707f, 0.668606f,
		0.672504f, 0.676403f, 0.680302f, 0.684201f, 0.688099f, 0.691998f,
		0.695896f, 0.699795f, 0.703694f, 0.707592f, 0.711491f, 0.71539f,
		0.719288f, 0.723187f, 0.727086f, 0.730984f, 0.734883f, 0.738782f,
		0.74268f, 0.746579f, 0.750478f, 0.754376f, 0.758275f, 0.762174f,
		0.766072f, 0.769971f, 0.77387f, 0.777768f, 0.781667f, 0.785566f,
		0.789464f, 0.793363f, 0.797262f, 0.80116f, 0.805059f, 0.808958f,
		0.812856f, 0.816755f, 0.820654f, 0.824552f, 0.828451f, 0.83235f,
		0.836248f, 0.840147f, 0.844046f, 0.847944f, 0.851843f, 0.855742f,
		0.85964f, 0.863539f, 0.867438f, 0.871336f, 0.875235f, 0.879134f,
		0.883032f, 0.886931f, 0.89083f, 0.894728f, 0.898627f, 0.902526f,
		0.906424f, 0.910323f, 0.914222f, 0.91812f, 0.922019f, 0.925918f,
		0.929816f, 0.933715f, 0.937614f, 0.941512f, 0.945411f, 0.94931f,
		0.953208f, 0.957107f, 0.961006f, 0.964904f, 0.968803f, 0.972702f,
		0.9766f, 0.980499f, 0.984398f, 0.988296f, 0.992195f, 0.996094f,
		0.999992f, 1.f
	};
};

using cable_table19_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::embedded::table<cable_table19_t_data>>;

template <int NV>
using pma42_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table18_t<NV>, 0>, 
                                   parameter::plain<cable_table19_t, 0>>;

template <int NV>
using pma42_t = control::pma<NV, pma42_mod<NV>>;
template <int NV>
using pma_mod_15 = parameter::from0To1<pma2_t<NV>, 
                                       2, 
                                       xfader_x1_c0Range>;

template <int NV>
using pma_mod_16 = parameter::from0To1<pma1_t<NV>, 
                                       2, 
                                       xfader_x1_c0Range>;

template <int NV>
using pma_mod_17 = parameter::from0To1<pma42_t<NV>, 
                                       2, 
                                       xfader_x1_c0Range>;

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
                                 parameter::plain<xfader4_x2_t<NV>, 0>, 
                                 parameter::plain<xfader_x3_t<NV>, 0>, 
                                 parameter::plain<xfader2_x3_t<NV>, 0>, 
                                 parameter::plain<xfader1_x3_t<NV>, 0>, 
                                 parameter::plain<xfader3_x3_t<NV>, 0>, 
                                 parameter::plain<xfader4_x3_t<NV>, 0>, 
                                 pma_mod_15<NV>, 
                                 pma_mod_16<NV>, 
                                 pma_mod_17<NV>>;

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

template <int NV>
using pma7_t = control::pma<NV, 
                            parameter::plain<pma6_t<NV>, 2>>;
template <int NV>
using event_data_reader7_t = wrap::mod<parameter::plain<pma7_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;
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

template <int NV>
using peak2_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
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
                                   wrap::fix<1, split21_t<NV>>>;

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
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table3_t<NV>>>;

using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table5_t>>;

using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table7_t>>;

using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table9_t>>;

using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table11_t>>;

using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table13_t>>;

using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table15_t>>;

using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table16_t>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain28_t<NV>>, 
                                  chain38_t, 
                                  chain39_t, 
                                  chain40_t, 
                                  chain41_t, 
                                  chain42_t, 
                                  chain43_t, 
                                  chain44_t>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split1_t<NV>>, 
                                      cable_table17_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV>
using split23_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter3_x5_t<NV>>, 
                                   smoothed_parameter16_t<NV>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split23_t<NV>>, 
                                   input_toggle18_t<NV>, 
                                   pma41_t<NV>>;

template <int NV>
using chain5_x5_t = container::chain<parameter::empty, 
                                     wrap::fix<2, pma2_t<NV>>, 
                                     modchain2_t<NV>, 
                                     pma40_t<NV>, 
                                     chain45_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using soft_bypass3_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain5_x5_t<NV>>>;

template <int NV>
using soft_bypass3_t = bypass::smoothed<20, soft_bypass3_t_<NV>>;

template <int NV>
using sb5_x4_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, soft_bypass3_t<NV>>>;

template <int NV>
using sb5_x4_t = bypass::smoothed<20, sb5_x4_t_<NV>>;
template <int NV>
using switcher_x1_c5 = parameter::bypass<sb5_x4_t<NV>>;

template <int NV>
using switcher_x1_multimod = parameter::list<switcher_x1_c0<NV>, 
                                             switcher_x1_c1<NV>, 
                                             switcher_x1_c2<NV>, 
                                             switcher_x1_c3<NV>, 
                                             switcher_x1_c4<NV>, 
                                             switcher_x1_c5<NV>>;

template <int NV>
using switcher_x1_t = control::xfader<switcher_x1_multimod<NV>, 
                                      faders::switcher>;

template <int NV>
using sb_container_x1_t = container::chain<parameter::empty, 
                                           wrap::fix<2, sb1_x1_t<NV>>, 
                                           sb2_x1_t<NV>, 
                                           sb3_x1_t<NV>, 
                                           sb4_x1_t<NV>, 
                                           sb5_x1_t<NV>, 
                                           sb5_x4_t<NV>>;

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
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, cable_table1_t<NV>>>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table2_t>>;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table4_t>>;

using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table6_t>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>, 
                                 chain1_t, 
                                 chain2_t, 
                                 chain3_t>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split_t<NV>>, 
                                      cable_table_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using split22_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter3_x4_t<NV>>, 
                                   smoothed_parameter15_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split22_t<NV>>, 
                                   input_toggle17_t<NV>, 
                                   pma39_t<NV>>;

template <int NV>
using chain5_x4_t = container::chain<parameter::empty, 
                                     wrap::fix<2, pma1_t<NV>>, 
                                     modchain1_t<NV>, 
                                     pma38_t<NV>, 
                                     chain23_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using soft_bypass_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, chain5_x4_t<NV>>>;

template <int NV>
using soft_bypass_t = bypass::smoothed<20, soft_bypass_t_<NV>>;
template <int NV>
using switcher_x2_c5 = parameter::bypass<soft_bypass_t<NV>>;

template <int NV>
using switcher_x2_multimod = parameter::list<switcher_x2_c0<NV>, 
                                             switcher_x2_c1<NV>, 
                                             switcher_x2_c2<NV>, 
                                             switcher_x2_c3<NV>, 
                                             switcher_x2_c4<NV>, 
                                             switcher_x2_c5<NV>>;

template <int NV>
using switcher_x2_t = control::xfader<switcher_x2_multimod<NV>, 
                                      faders::switcher>;

template <int NV>
using sb_container_x2_t = container::chain<parameter::empty, 
                                           wrap::fix<2, sb1_x2_t<NV>>, 
                                           sb2_x2_t<NV>, 
                                           sb3_x2_t<NV>, 
                                           sb4_x2_t<NV>, 
                                           sb5_x2_t<NV>, 
                                           soft_bypass_t<NV>>;

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

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter_x3_t<NV>>, 
                                   smoothed_parameter10_t<NV>>;

template <int NV>
using chain1_x3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader_x3_t<NV>>, 
                                     pma28_t<NV>, 
                                     split14_t<NV>, 
                                     input_toggle11_t<NV>, 
                                     pma32_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb1_x3_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain1_x3_t<NV>>>;

template <int NV>
using sb1_x3_t = bypass::smoothed<20, sb1_x3_t_<NV>>;
template <int NV>
using switcher_x3_c0 = parameter::bypass<sb1_x3_t<NV>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter1_x3_t<NV>>, 
                                   smoothed_parameter11_t<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split15_t<NV>>, 
                                   input_toggle12_t<NV>>;

template <int NV>
using chain3_x1_x3_t = container::chain<parameter::empty, 
                                        wrap::fix<2, xfader2_x3_t<NV>>, 
                                        pma29_t<NV>, 
                                        chain19_t<NV>, 
                                        pma37_t<NV>, 
                                        core::gain<NV>>;

template <int NV>
using sb2_x3_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain3_x1_x3_t<NV>>>;

template <int NV>
using sb2_x3_t = bypass::smoothed<20, sb2_x3_t_<NV>>;
template <int NV>
using switcher_x3_c1 = parameter::bypass<sb2_x3_t<NV>>;

template <int NV>
using split16_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter2_x3_t<NV>>, 
                                   smoothed_parameter12_t<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split16_t<NV>>, 
                                   input_toggle13_t<NV>>;

template <int NV>
using chain2_x3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader1_x3_t<NV>>, 
                                     pma35_t<NV>, 
                                     chain20_t<NV>, 
                                     pma36_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb3_x3_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain2_x3_t<NV>>>;

template <int NV>
using sb3_x3_t = bypass::smoothed<20, sb3_x3_t_<NV>>;
template <int NV>
using switcher_x3_c2 = parameter::bypass<sb3_x3_t<NV>>;

template <int NV>
using split17_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter4_x3_t<NV>>, 
                                   smoothed_parameter13_t<NV>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma33_t<NV>>, 
                                   split17_t<NV>, 
                                   input_toggle14_t<NV>, 
                                   pma34_t<NV>>;

template <int NV>
using chain4_x3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader3_x3_t<NV>>, 
                                     chain21_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb4_x3_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain4_x3_t<NV>>>;

template <int NV>
using sb4_x3_t = bypass::smoothed<20, sb4_x3_t_<NV>>;
template <int NV>
using switcher_x3_c3 = parameter::bypass<sb4_x3_t<NV>>;

template <int NV>
using split18_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter3_x3_t<NV>>, 
                                   smoothed_parameter14_t<NV>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split18_t<NV>>, 
                                   input_toggle15_t<NV>, 
                                   pma31_t<NV>>;

template <int NV>
using chain5_x3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader4_x3_t<NV>>, 
                                     pma30_t<NV>, 
                                     chain22_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb5_x3_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain5_x3_t<NV>>>;

template <int NV>
using sb5_x3_t = bypass::smoothed<20, sb5_x3_t_<NV>>;
template <int NV>
using switcher_x3_c4 = parameter::bypass<sb5_x3_t<NV>>;

template <int NV>
using switcher_x3_multimod = parameter::list<switcher_x3_c0<NV>, 
                                             switcher_x3_c1<NV>, 
                                             switcher_x3_c2<NV>, 
                                             switcher_x3_c3<NV>, 
                                             switcher_x3_c4<NV>>;

template <int NV>
using switcher_x3_t = control::xfader<switcher_x3_multimod<NV>, 
                                      faders::switcher>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table18_t<NV>>>;

using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table19_t>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain46_t<NV>>, 
                                  chain47_t>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split2_t<NV>>, 
                                      cable_table22_t<NV>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV>
using split24_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter3_x6_t<NV>>, 
                                   smoothed_parameter18_t<NV>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split24_t<NV>>, 
                                   input_toggle19_t<NV>, 
                                   pma44_t<NV>>;

template <int NV>
using chain5_x6_t = container::chain<parameter::empty, 
                                     wrap::fix<2, pma42_t<NV>>, 
                                     modchain3_t<NV>, 
                                     pma43_t<NV>, 
                                     chain50_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using soft_bypass1_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain5_x6_t<NV>>>;

template <int NV>
using soft_bypass1_t = bypass::smoothed<20, soft_bypass1_t_<NV>>;

template <int NV>
using sb_container_x3_t = container::chain<parameter::empty, 
                                           wrap::fix<2, sb1_x3_t<NV>>, 
                                           sb2_x3_t<NV>, 
                                           sb3_x3_t<NV>, 
                                           sb4_x3_t<NV>, 
                                           sb5_x3_t<NV>, 
                                           soft_bypass1_t<NV>>;

template <int NV>
using x3_t = container::chain<parameter::empty, 
                              wrap::fix<2, switcher_x3_t<NV>>, 
                              sb_container_x3_t<NV>>;

template <int NV>
using sb5_t_ = container::chain<parameter::empty, wrap::fix<2, x3_t<NV>>>;

template <int NV>
using sb5_t = bypass::smoothed<20, sb5_t_<NV>>;
template <int NV>
using switcher1_c2 = parameter::bypass<sb5_t<NV>>;

template <int NV>
using switcher1_multimod = parameter::list<switcher1_c0<NV>, 
                                           switcher1_c1<NV>, 
                                           switcher1_c2<NV>>;

template <int NV>
using switcher1_t = control::xfader<switcher1_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb3_t<NV>>, 
                                         sb4_t<NV>, 
                                         sb5_t<NV>>;

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
// Parameter list for xfade1_impl::XF1_t -----------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(smooth_x1_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_STEP(smooth_x1_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth_x1_0 = parameter::from0To1<xfade1_impl::smoothed_parameter2_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_1 = parameter::from0To1<xfade1_impl::smoothed_parameter4_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_2 = parameter::from0To1<xfade1_impl::smoothed_parameter3_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_3 = parameter::from0To1<xfade1_impl::smoothed_parameter3_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_4 = parameter::from0To1<xfade1_impl::smoothed_parameter4_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_5 = parameter::from0To1<xfade1_impl::smoothed_parameter2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_6 = parameter::from0To1<xfade1_impl::smoothed_parameter_x2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_7 = parameter::from0To1<xfade1_impl::smoothed_parameter5_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_8 = parameter::from0To1<xfade1_impl::smoothed_parameter1_x2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_9 = parameter::from0To1<xfade1_impl::smoothed_parameter2_x2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_10 = parameter::from0To1<xfade1_impl::smoothed_parameter6_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_11 = parameter::from0To1<xfade1_impl::smoothed_parameter7_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_12 = parameter::from0To1<xfade1_impl::smoothed_parameter8_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_13 = parameter::from0To1<xfade1_impl::smoothed_parameter4_x2_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_14 = parameter::from0To1<xfade1_impl::smoothed_parameter3_x2_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_15 = parameter::from0To1<xfade1_impl::smoothed_parameter9_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_16 = parameter::from0To1<xfade1_impl::smoothed_parameter_x3_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_17 = parameter::from0To1<xfade1_impl::smoothed_parameter10_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_18 = parameter::from0To1<xfade1_impl::smoothed_parameter1_x3_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_19 = parameter::from0To1<xfade1_impl::smoothed_parameter11_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_20 = parameter::from0To1<xfade1_impl::smoothed_parameter2_x3_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_21 = parameter::from0To1<xfade1_impl::smoothed_parameter12_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_22 = parameter::from0To1<xfade1_impl::smoothed_parameter4_x3_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_23 = parameter::from0To1<xfade1_impl::smoothed_parameter13_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_24 = parameter::from0To1<xfade1_impl::smoothed_parameter3_x3_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_25 = parameter::from0To1<xfade1_impl::smoothed_parameter14_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_26 = parameter::from0To1<xfade1_impl::smoothed_parameter1_x4_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_27 = parameter::from0To1<xfade1_impl::smoothed_parameter17_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_28 = parameter::from0To1<xfade1_impl::smoothed_parameter1_x1_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_29 = parameter::from0To1<xfade1_impl::smoothed_parameter1_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_30 = parameter::from0To1<xfade1_impl::smoothed_parameter3_x4_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_31 = parameter::from0To1<xfade1_impl::smoothed_parameter15_t<NV>, 
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
                                   smooth_x1_19<NV>, 
                                   smooth_x1_20<NV>, 
                                   smooth_x1_21<NV>, 
                                   smooth_x1_22<NV>, 
                                   smooth_x1_23<NV>, 
                                   smooth_x1_24<NV>, 
                                   smooth_x1_25<NV>, 
                                   smooth_x1_26<NV>, 
                                   smooth_x1_27<NV>, 
                                   smooth_x1_28<NV>, 
                                   smooth_x1_29<NV>, 
                                   smooth_x1_30<NV>, 
                                   smooth_x1_31<NV>>;

DECLARE_PARAMETER_RANGE_STEP(SmoothType_0Range, 
                             0., 
                             1., 
                             1.);

template <int NV>
using SmoothType_0 = parameter::from0To1<xfade1_impl::input_toggle2_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_1 = parameter::from0To1<xfade1_impl::input_toggle4_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_2 = parameter::from0To1<xfade1_impl::input_toggle5_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_3 = parameter::from0To1<xfade1_impl::input_toggle3_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_4 = parameter::from0To1<xfade1_impl::input_toggle6_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_5 = parameter::from0To1<xfade1_impl::input_toggle7_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_6 = parameter::from0To1<xfade1_impl::input_toggle8_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_7 = parameter::from0To1<xfade1_impl::input_toggle9_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_8 = parameter::from0To1<xfade1_impl::input_toggle10_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_9 = parameter::from0To1<xfade1_impl::input_toggle11_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_10 = parameter::from0To1<xfade1_impl::input_toggle12_t<NV>, 
                                          0, 
                                          SmoothType_0Range>;

template <int NV>
using SmoothType_11 = parameter::from0To1<xfade1_impl::input_toggle13_t<NV>, 
                                          0, 
                                          SmoothType_0Range>;

template <int NV>
using SmoothType_12 = parameter::from0To1<xfade1_impl::input_toggle14_t<NV>, 
                                          0, 
                                          SmoothType_0Range>;

template <int NV>
using SmoothType_13 = parameter::from0To1<xfade1_impl::input_toggle15_t<NV>, 
                                          0, 
                                          SmoothType_0Range>;

template <int NV>
using SmoothType_14 = parameter::from0To1<xfade1_impl::input_toggle16_t<NV>, 
                                          0, 
                                          SmoothType_0Range>;

template <int NV>
using SmoothType_15 = parameter::from0To1<xfade1_impl::input_toggle17_t<NV>, 
                                          0, 
                                          SmoothType_0Range>;

template <int NV>
using SmoothType = parameter::chain<ranges::Identity, 
                                    SmoothType_0<NV>, 
                                    SmoothType_1<NV>, 
                                    SmoothType_2<NV>, 
                                    SmoothType_3<NV>, 
                                    SmoothType_4<NV>, 
                                    SmoothType_5<NV>, 
                                    SmoothType_6<NV>, 
                                    SmoothType_7<NV>, 
                                    SmoothType_8<NV>, 
                                    SmoothType_9<NV>, 
                                    SmoothType_10<NV>, 
                                    SmoothType_11<NV>, 
                                    SmoothType_12<NV>, 
                                    SmoothType_13<NV>, 
                                    SmoothType_14<NV>, 
                                    SmoothType_15<NV>>;

template <int NV>
using XF1_t_plist = parameter::list<smooth_x1<NV>, SmoothType<NV>>;
}

template <int NV>
using XF1_t = container::chain<XF1_t_parameters::XF1_t_plist<NV>, 
                               wrap::fix<2, fix8_block_t<NV>>>;

namespace xfade1_t_parameters
{
// Parameter list for xfade1_impl::xfade1_t --------------------------------------------------------

DECLARE_PARAMETER_RANGE(MainParam_InputRange, 
                        1., 
                        8.);
template <int NV>
using MainParam_0 = parameter::from0To1<xfade1_impl::pma7_t<NV>, 
                                        2, 
                                        xfade1_impl::xfader_x1_c0Range>;

template <int NV>
using MainParam = parameter::chain<MainParam_InputRange, MainParam_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(_2ndParam_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_SKEW(_2ndParam_0Range, 
                             0., 
                             1000., 
                             0.30103);

template <int NV>
using _2ndParam_0 = parameter::from0To1<xfade1_impl::XF1_t<NV>, 
                                        0, 
                                        _2ndParam_0Range>;

template <int NV>
using _2ndParam_1 = parameter::from0To1<xfade1_impl::smoothed_parameter3_x6_t<NV>, 
                                        1, 
                                        xfade1_impl::XF1_t_parameters::smooth_x1_0Range>;

template <int NV>
using _2ndParam_2 = parameter::from0To1<xfade1_impl::smoothed_parameter18_t<NV>, 
                                        1, 
                                        xfade1_impl::XF1_t_parameters::smooth_x1_0Range>;

template <int NV>
using _2ndParam_3 = parameter::from0To1<xfade1_impl::smoothed_parameter3_x5_t<NV>, 
                                        1, 
                                        xfade1_impl::XF1_t_parameters::smooth_x1_0Range>;

template <int NV>
using _2ndParam_4 = parameter::from0To1<xfade1_impl::smoothed_parameter16_t<NV>, 
                                        1, 
                                        xfade1_impl::XF1_t_parameters::smooth_x1_0Range>;

template <int NV>
using _2ndParam = parameter::chain<_2ndParam_InputRange, 
                                   _2ndParam_0<NV>, 
                                   _2ndParam_1<NV>, 
                                   _2ndParam_2<NV>, 
                                   _2ndParam_3<NV>, 
                                   _2ndParam_4<NV>>;

DECLARE_PARAMETER_RANGE(_3rdParam_InputRange, 
                        0., 
                        7.);

template <int NV>
using _3rdParam = parameter::chain<_3rdParam_InputRange, 
                                   parameter::plain<xfade1_impl::switcher_x1_t<NV>, 0>, 
                                   parameter::plain<xfade1_impl::switcher_x2_t<NV>, 0>, 
                                   parameter::plain<xfade1_impl::switcher_x3_t<NV>, 0>>;

template <int NV>
using _4thParam_1 = parameter::from0To1<xfade1_impl::input_toggle19_t<NV>, 
                                        0, 
                                        xfade1_impl::XF1_t_parameters::SmoothType_0Range>;

template <int NV>
using _4thParam_2 = parameter::from0To1<xfade1_impl::input_toggle18_t<NV>, 
                                        0, 
                                        xfade1_impl::XF1_t_parameters::SmoothType_0Range>;

template <int NV>
using _4thParam = parameter::chain<ranges::Identity, 
                                   parameter::plain<xfade1_impl::XF1_t<NV>, 1>, 
                                   _4thParam_1<NV>, 
                                   _4thParam_2<NV>>;

DECLARE_PARAMETER_RANGE(_5thParam_InputRange, 
                        0., 
                        3.);

template <int NV>
using _5thParam = parameter::chain<_5thParam_InputRange, 
                                   parameter::plain<xfade1_impl::switcher1_t<NV>, 0>>;

template <int NV>
using Poly = parameter::plain<xfade1_impl::pma_t<NV>, 1>;
template <int NV>
using Global = parameter::plain<xfade1_impl::pma7_t<NV>, 
                                1>;
template <int NV>
using GlobalSrc = parameter::plain<xfade1_impl::event_data_reader7_t<NV>, 
                                   0>;
template <int NV>
using Vel = parameter::plain<xfade1_impl::pma3_t<NV>, 
                             1>;
template <int NV>
using Trk = parameter::plain<xfade1_impl::pma4_t<NV>, 
                             1>;
template <int NV>
using MW = parameter::plain<xfade1_impl::pma5_t<NV>, 
                            1>;
template <int NV>
using AT = parameter::plain<xfade1_impl::pma6_t<NV>, 
                            1>;
template <int NV>
using MonoSrc = parameter::plain<xfade1_impl::branch3_t<NV>, 
                                 0>;
template <int NV>
using xfade1_t_plist = parameter::list<MainParam<NV>, 
                                       _2ndParam<NV>, 
                                       _3rdParam<NV>, 
                                       _4thParam<NV>, 
                                       _5thParam<NV>, 
                                       Poly<NV>, 
                                       Global<NV>, 
                                       GlobalSrc<NV>, 
                                       Vel<NV>, 
                                       Trk<NV>, 
                                       MW<NV>, 
                                       AT<NV>, 
                                       MonoSrc<NV>>;
}

template <int NV>
using xfade1_t_ = container::chain<xfade1_t_parameters::xfade1_t_plist<NV>, 
                                   wrap::fix<2, modchain_t<NV>>, 
                                   XF1_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xfade1_impl::xfade1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 8;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(xfade1);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(224)
		{
			0x005C, 0x0000, 0x0000, 0x614D, 0x6E69, 0x6150, 0x6172, 0x006D, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0100, 0x0000, 0x5F00, 0x6E32, 0x5064, 
            0x7261, 0x6D61, 0x0000, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 
            0x3FC0, 0x209B, 0x3E9A, 0xCCCD, 0x3DCC, 0x005C, 0x0002, 0x0000, 
            0x335F, 0x6472, 0x6150, 0x6172, 0x006D, 0x0000, 0x0000, 0x0000, 
            0xE000, 0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0300, 0x0000, 0x5F00, 0x7434, 0x5068, 0x7261, 0x6D61, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x96E7, 0x3F7B, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0004, 0x0000, 0x355F, 0x6874, 0x6150, 
            0x6172, 0x006D, 0x0000, 0x0000, 0x0000, 0x4000, 0xF240, 0x0C52, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0500, 0x0000, 0x5000, 
            0x6C6F, 0x0079, 0x0000, 0x8000, 0x00BF, 0x8000, 0x483F, 0x1F73, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0600, 0x0000, 0x4700, 
            0x6F6C, 0x6162, 0x006C, 0x0000, 0x8000, 0x00BF, 0x8000, 0x3F3F, 
            0x8225, 0x00BD, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0700, 0x0000, 
            0x4700, 0x6F6C, 0x6162, 0x536C, 0x6372, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x4180, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0008, 0x0000, 0x6556, 0x006C, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0900, 0x0000, 0x5400, 0x6B72, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x000A, 0x0000, 0x574D, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000B, 
            0x0000, 0x5441, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000C, 0x0000, 
            0x6F4D, 0x6F6E, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 0xE000, 
            0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                           // xfade1_impl::modchain_t<NV>
		auto& split19 = this->getT(0).getT(0);                                                    // xfade1_impl::split19_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0);                                                // xfade1_impl::pma_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(1);                                             // xfade1_impl::split7_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(1).getT(0);                                     // xfade1_impl::chain5_t<NV>
		auto& midi = this->getT(0).getT(0).getT(1).getT(0).getT(0);                               // xfade1_impl::midi_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                               // xfade1_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(1);                                     // xfade1_impl::chain6_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                              // xfade1_impl::midi1_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                               // xfade1_impl::pma4_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(1).getT(2);                                     // xfade1_impl::chain9_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(1).getT(2).getT(0);                            // xfade1_impl::midi_cc_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                               // xfade1_impl::pma5_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(3);                                    // xfade1_impl::chain14_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                           // xfade1_impl::midi_cc1_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                               // xfade1_impl::pma6_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(4);                                    // xfade1_impl::chain25_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                            // xfade1_impl::chain10_t<NV>
		auto& split21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0);                    // xfade1_impl::split21_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0).getT(0); // xfade1_impl::event_data_reader7_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0).getT(1);            // xfade1_impl::chain29_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(1).getT(4).                                    // xfade1_impl::branch3_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& chain30 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade1_impl::chain30_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(0);
		auto& global_cable16 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade1_impl::global_cable16_t<NV>
                               getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& chain31 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade1_impl::chain31_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(1);
		auto& global_cable17 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade1_impl::global_cable17_t<NV>
                               getT(0).getT(1).getT(0).getT(1).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(1).getT(1);
		auto& chain32 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade1_impl::chain32_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(2);
		auto& global_cable18 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade1_impl::global_cable18_t<NV>
                               getT(0).getT(1).getT(0).getT(2).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(2).getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade1_impl::chain33_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(3);
		auto& global_cable19 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade1_impl::global_cable19_t<NV>
                               getT(0).getT(1).getT(0).getT(3).getT(0);
		auto& add19 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(3).getT(1);
		auto& chain34 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade1_impl::chain34_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(4);
		auto& global_cable20 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade1_impl::global_cable20_t<NV>
                               getT(0).getT(1).getT(0).getT(4).getT(0);
		auto& add20 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(4).getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade1_impl::chain35_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(5);
		auto& global_cable21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade1_impl::global_cable21_t<NV>
                               getT(0).getT(1).getT(0).getT(5).getT(0);
		auto& add21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(5).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade1_impl::chain36_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(6);
		auto& global_cable22 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade1_impl::global_cable22_t<NV>
                               getT(0).getT(1).getT(0).getT(6).getT(0);
		auto& add22 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(6).getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade1_impl::chain37_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(7);
		auto& global_cable23 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade1_impl::global_cable23_t<NV>
                               getT(0).getT(1).getT(0).getT(7).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(7).getT(1);
		auto& peak2 = this->getT(0).getT(0).getT(1).getT(4).                                   // xfade1_impl::peak2_t<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& clear = this->getT(0).getT(0).getT(1).getT(4).                                   // math::clear<NV>
                      getT(0).getT(0).getT(1).getT(2);
		auto& pma7 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                            // xfade1_impl::pma7_t<NV>
		auto& XF1 = this->getT(1);                                                             // xfade1_impl::XF1_t<NV>
		auto& fix8_block = this->getT(1).getT(0);                                              // xfade1_impl::fix8_block_t<NV>
		auto& softbypass_switch4 = this->getT(1).getT(0).getT(0);                              // xfade1_impl::softbypass_switch4_t<NV>
		auto& switcher1 = this->getT(1).getT(0).getT(0).getT(0);                               // xfade1_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(1).getT(0).getT(0).getT(1);                           // xfade1_impl::sb_container1_t<NV>
		auto& sb3 = this->getT(1).getT(0).getT(0).getT(1).getT(0);                             // xfade1_impl::sb3_t<NV>
		auto& x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0);                      // xfade1_impl::x1_t<NV>
		auto& switcher_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);     // xfade1_impl::switcher_x1_t<NV>
		auto& sb_container_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1); // xfade1_impl::sb_container_x1_t<NV>
		auto& sb1_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb1_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(0);
		auto& chain1_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain1_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(0).
                          getT(0);
		auto& xfader_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                       // xfade1_impl::xfader_x1_t<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& pma8 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade1_impl::pma8_t<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& chain26 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade1_impl::chain26_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2);
		auto& split20 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade1_impl::split20_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter1_x4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade1_impl::smoothed_parameter1_x4_t<NV>
                                       getT(1).getT(0).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).    // xfade1_impl::smoothed_parameter17_t<NV>
                                     getT(1).getT(0).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                  // xfade1_impl::input_toggle16_t<NV>
                               getT(0).getT(1).getT(0).getT(0).getT(2).
                               getT(1);
		auto& pma9 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade1_impl::pma9_t<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(2).
                     getT(2);
		auto& gain16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).
                       getT(3);
		auto& sb2_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb2_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& chain3_x1_x1 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade1_impl::chain3_x1_x1_t<NV>
                             getT(0).getT(0).getT(1).getT(1).
                             getT(0);
		auto& xfader2_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade1_impl::xfader2_x1_t<NV>
                           getT(0).getT(1).getT(1).getT(0).getT(0);
		auto& pma10 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade1_impl::pma10_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(1);
		auto& chain7 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade1_impl::chain7_t<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2);
		auto& split4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade1_impl::split4_t<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter1_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade1_impl::smoothed_parameter1_x1_t<NV>
                                       getT(1).getT(1).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade1_impl::smoothed_parameter1_t<NV>
                                    getT(1).getT(1).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade1_impl::input_toggle2_t<NV>
                              getT(0).getT(1).getT(1).getT(0).getT(2).
                              getT(1);
		auto& pma11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade1_impl::pma11_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(2).
                      getT(2);
		auto& gain1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(2).
                      getT(3);
		auto& sb3_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb3_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(2);
		auto& chain2_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain2_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(2).
                          getT(0);
		auto& xfader1_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade1_impl::xfader1_x1_t<NV>
                           getT(0).getT(1).getT(2).getT(0).getT(0);
		auto& pma12 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade1_impl::pma12_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(1);
		auto& chain12 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade1_impl::chain12_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(2);
		auto& split6 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade1_impl::split6_t<NV>
                       getT(0).getT(1).getT(2).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter2_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade1_impl::smoothed_parameter2_x1_t<NV>
                                       getT(1).getT(2).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade1_impl::smoothed_parameter3_t<NV>
                                    getT(1).getT(2).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade1_impl::input_toggle4_t<NV>
                              getT(0).getT(1).getT(2).getT(0).getT(2).
                              getT(1);
		auto& pma13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade1_impl::pma13_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(3);
		auto& gain2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(4);
		auto& sb4_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb4_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(3);
		auto& chain4_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain4_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& xfader3_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade1_impl::xfader3_x1_t<NV>
                           getT(0).getT(1).getT(3).getT(0).getT(0);
		auto& pma17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade1_impl::pma17_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(1);
		auto& chain13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade1_impl::chain13_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(2);
		auto& split8 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade1_impl::split8_t<NV>
                       getT(0).getT(1).getT(3).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter4_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade1_impl::smoothed_parameter4_x1_t<NV>
                                       getT(1).getT(3).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade1_impl::smoothed_parameter4_t<NV>
                                    getT(1).getT(3).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade1_impl::input_toggle5_t<NV>
                              getT(0).getT(1).getT(3).getT(0).getT(2).
                              getT(1);
		auto& pma15 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade1_impl::pma15_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(2).
                      getT(2);
		auto& gain3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(3);
		auto& sb5_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb5_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(4);
		auto& chain5_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain5_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& xfader4_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade1_impl::xfader4_x1_t<NV>
                           getT(0).getT(1).getT(4).getT(0).getT(0);
		auto& pma14 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade1_impl::pma14_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(1);
		auto& chain11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade1_impl::chain11_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2);
		auto& split5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade1_impl::split5_t<NV>
                       getT(0).getT(1).getT(4).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter3_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade1_impl::smoothed_parameter3_x1_t<NV>
                                       getT(1).getT(4).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade1_impl::smoothed_parameter2_t<NV>
                                    getT(1).getT(4).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade1_impl::input_toggle3_t<NV>
                              getT(0).getT(1).getT(4).getT(0).getT(2).
                              getT(1);
		auto& pma16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade1_impl::pma16_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(2).
                      getT(2);
		auto& gain4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(3);
		auto& sb5_x4 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb5_x4_t<NV>
                       getT(0).getT(0).getT(1).getT(5);
		auto& soft_bypass3 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade1_impl::soft_bypass3_t<NV>
                             getT(0).getT(0).getT(1).getT(5).
                             getT(0);
		auto& chain5_x5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                       // xfade1_impl::chain5_x5_t<NV>
                          getT(0).getT(1).getT(5).getT(0).getT(0);
		auto& pma2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade1_impl::pma2_t<NV>
                     getT(0).getT(1).getT(5).getT(0).getT(0).
                     getT(0);
		auto& modchain2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                       // xfade1_impl::modchain2_t<NV>
                          getT(0).getT(1).getT(5).getT(0).getT(0).
                          getT(1);
		auto& split1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                  // xfade1_impl::split1_t<NV>
                       getT(1).getT(5).getT(0).getT(0).getT(1).getT(0);
		auto& chain28 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade1_impl::chain28_t<NV>
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(0);
		auto& cable_table3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).    // xfade1_impl::cable_table3_t<NV>
                             getT(5).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& chain38 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade1_impl::chain38_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(1);
		auto& cable_table5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).    // xfade1_impl::cable_table5_t
                             getT(5).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);
		auto& chain39 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade1_impl::chain39_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(2);
		auto& cable_table7 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).    // xfade1_impl::cable_table7_t
                             getT(5).getT(0).getT(0).getT(1).getT(0).getT(2).getT(0);
		auto& chain40 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade1_impl::chain40_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(3);
		auto& cable_table9 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).    // xfade1_impl::cable_table9_t
                             getT(5).getT(0).getT(0).getT(1).getT(0).getT(3).getT(0);
		auto& chain41 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade1_impl::chain41_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(4);
		auto& cable_table11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).   // xfade1_impl::cable_table11_t
                              getT(5).getT(0).getT(0).getT(1).getT(0).getT(4).getT(0);
		auto& chain42 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade1_impl::chain42_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(5);
		auto& cable_table13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).   // xfade1_impl::cable_table13_t
                              getT(5).getT(0).getT(0).getT(1).getT(0).getT(5).getT(0);
		auto& chain43 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade1_impl::chain43_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(6);
		auto& cable_table15 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).   // xfade1_impl::cable_table15_t
                              getT(5).getT(0).getT(0).getT(1).getT(0).getT(6).getT(0);
		auto& chain44 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade1_impl::chain44_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(7);
		auto& cable_table16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).   // xfade1_impl::cable_table16_t
                              getT(5).getT(0).getT(0).getT(1).getT(0).getT(7).getT(0);
		auto& cable_table17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).           // xfade1_impl::cable_table17_t<NV>
                              getT(1).getT(5).getT(0).getT(0).getT(1).getT(1);
		auto& pma40 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade1_impl::pma40_t<NV>
                      getT(0).getT(1).getT(5).getT(0).getT(0).
                      getT(2);
		auto& chain45 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade1_impl::chain45_t<NV>
                        getT(0).getT(1).getT(5).getT(0).getT(0).
                        getT(3);
		auto& split23 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade1_impl::split23_t<NV>
                        getT(1).getT(5).getT(0).getT(0).getT(3).getT(0);
		auto& smoothed_parameter3_x5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade1_impl::smoothed_parameter3_x5_t<NV>
                                       getT(1).getT(5).getT(0).getT(0).getT(3).getT(0).
                                       getT(0);
		auto& smoothed_parameter16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).    // xfade1_impl::smoothed_parameter16_t<NV>
                                     getT(1).getT(5).getT(0).getT(0).getT(3).getT(0).
                                     getT(1);
		auto& input_toggle18 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).          // xfade1_impl::input_toggle18_t<NV>
                               getT(1).getT(5).getT(0).getT(0).getT(3).getT(1);
		auto& pma41 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                   // xfade1_impl::pma41_t<NV>
                      getT(1).getT(5).getT(0).getT(0).getT(3).getT(2);
		auto& gain17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(5).getT(0).getT(0).
                       getT(4);
		auto& sb4 = this->getT(1).getT(0).getT(0).getT(1).getT(1);                             // xfade1_impl::sb4_t<NV>
		auto& x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0);                      // xfade1_impl::x2_t<NV>
		auto& switcher_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).getT(0);     // xfade1_impl::switcher_x2_t<NV>
		auto& sb_container_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).getT(1); // xfade1_impl::sb_container_x2_t<NV>
		auto& sb1_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb1_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(0);
		auto& chain1_x2 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain1_x2_t<NV>
                          getT(1).getT(0).getT(1).getT(0).
                          getT(0);
		auto& xfader_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                       // xfade1_impl::xfader_x2_t<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& pma21 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma21_t<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& split9 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                          // xfade1_impl::split9_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2);
		auto& smoothed_parameter_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).           // xfade1_impl::smoothed_parameter_x2_t<NV>
                                      getT(0).getT(1).getT(0).getT(0).getT(2).
                                      getT(0);
		auto& smoothed_parameter5 = this->getT(1).getT(0).getT(0).getT(1).getT(1).             // xfade1_impl::smoothed_parameter5_t<NV>
                                    getT(0).getT(1).getT(0).getT(0).getT(2).
                                    getT(1);
		auto& input_toggle6 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                   // xfade1_impl::input_toggle6_t<NV>
                              getT(0).getT(1).getT(0).getT(0).getT(3);
		auto& pma19 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma19_t<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(4);
		auto& gain5 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // core::gain<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(5);
		auto& sb2_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb2_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(1);
		auto& chain3_x1_x2 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade1_impl::chain3_x1_x2_t<NV>
                             getT(1).getT(0).getT(1).getT(1).
                             getT(0);
		auto& xfader2_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                      // xfade1_impl::xfader2_x2_t<NV>
                           getT(0).getT(1).getT(1).getT(0).getT(0);
		auto& pma18 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma18_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(1);
		auto& chain15 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::chain15_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2);
		auto& split10 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::split10_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter1_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade1_impl::smoothed_parameter1_x2_t<NV>
                                       getT(1).getT(1).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter6 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).     // xfade1_impl::smoothed_parameter6_t<NV>
                                    getT(1).getT(1).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle7 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                   // xfade1_impl::input_toggle7_t<NV>
                              getT(0).getT(1).getT(1).getT(0).getT(2).
                              getT(1);
		auto& pma20 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma20_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(3);
		auto& gain6 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // core::gain<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(4);
		auto& sb3_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb3_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(2);
		auto& chain2_x2 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain2_x2_t<NV>
                          getT(1).getT(0).getT(1).getT(2).
                          getT(0);
		auto& xfader1_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                      // xfade1_impl::xfader1_x2_t<NV>
                           getT(0).getT(1).getT(2).getT(0).getT(0);
		auto& chain16 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::chain16_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(1);
		auto& pma22 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma22_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(1).
                      getT(0);
		auto& split11 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::split11_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(1).
                        getT(1);
		auto& smoothed_parameter2_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade1_impl::smoothed_parameter2_x2_t<NV>
                                       getT(1).getT(2).getT(0).getT(1).getT(1).getT(0);
		auto& smoothed_parameter7 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).     // xfade1_impl::smoothed_parameter7_t<NV>
                                    getT(1).getT(2).getT(0).getT(1).getT(1).getT(1);
		auto& input_toggle8 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                   // xfade1_impl::input_toggle8_t<NV>
                              getT(0).getT(1).getT(2).getT(0).getT(1).
                              getT(2);
		auto& pma23 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma23_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(1).
                      getT(3);
		auto& gain7 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // core::gain<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(2);
		auto& sb4_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb4_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(3);
		auto& chain4_x2 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain4_x2_t<NV>
                          getT(1).getT(0).getT(1).getT(3).
                          getT(0);
		auto& xfader3_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                      // xfade1_impl::xfader3_x2_t<NV>
                           getT(0).getT(1).getT(3).getT(0).getT(0);
		auto& pma24 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma24_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(1);
		auto& chain17 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::chain17_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(2);
		auto& split12 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::split12_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter4_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade1_impl::smoothed_parameter4_x2_t<NV>
                                       getT(1).getT(3).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter8 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).     // xfade1_impl::smoothed_parameter8_t<NV>
                                    getT(1).getT(3).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle9 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                   // xfade1_impl::input_toggle9_t<NV>
                              getT(0).getT(1).getT(3).getT(0).getT(2).
                              getT(1);
		auto& pma25 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma25_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(2).
                      getT(2);
		auto& gain8 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // core::gain<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(3);
		auto& sb5_x2 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb5_x2_t<NV>
                       getT(1).getT(0).getT(1).getT(4);
		auto& chain5_x2 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain5_x2_t<NV>
                          getT(1).getT(0).getT(1).getT(4).
                          getT(0);
		auto& xfader4_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                      // xfade1_impl::xfader4_x2_t<NV>
                           getT(0).getT(1).getT(4).getT(0).getT(0);
		auto& pma26 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma26_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(1);
		auto& chain18 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::chain18_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2);
		auto& split13 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::split13_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter3_x2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade1_impl::smoothed_parameter3_x2_t<NV>
                                       getT(1).getT(4).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter9 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).     // xfade1_impl::smoothed_parameter9_t<NV>
                                    getT(1).getT(4).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle10 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                  // xfade1_impl::input_toggle10_t<NV>
                               getT(0).getT(1).getT(4).getT(0).getT(2).
                               getT(1);
		auto& pma27 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma27_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(2).
                      getT(2);
		auto& gain9 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // core::gain<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(3);
		auto& soft_bypass = this->getT(1).getT(0).getT(0).getT(1).                             // xfade1_impl::soft_bypass_t<NV>
                            getT(1).getT(0).getT(1).getT(5);
		auto& chain5_x4 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain5_x4_t<NV>
                          getT(1).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma1 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                            // xfade1_impl::pma1_t<NV>
                     getT(0).getT(1).getT(5).getT(0).getT(0);
		auto& modchain1 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                       // xfade1_impl::modchain1_t<NV>
                          getT(0).getT(1).getT(5).getT(0).getT(1);
		auto& split = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::split_t<NV>
                      getT(0).getT(1).getT(5).getT(0).getT(1).
                      getT(0);
		auto& chain = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).                   // xfade1_impl::chain_t<NV>
                      getT(1).getT(5).getT(0).getT(1).getT(0).getT(0);
		auto& cable_table1 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).            // xfade1_impl::cable_table1_t<NV>
                             getT(1).getT(5).getT(0).getT(1).getT(0).getT(0).
                             getT(0);
		auto& chain1 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).                  // xfade1_impl::chain1_t
                       getT(1).getT(5).getT(0).getT(1).getT(0).getT(1);
		auto& cable_table2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).            // xfade1_impl::cable_table2_t
                             getT(1).getT(5).getT(0).getT(1).getT(0).getT(1).
                             getT(0);
		auto& chain2 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).                  // xfade1_impl::chain2_t
                       getT(1).getT(5).getT(0).getT(1).getT(0).getT(2);
		auto& cable_table4 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).            // xfade1_impl::cable_table4_t
                             getT(1).getT(5).getT(0).getT(1).getT(0).getT(2).
                             getT(0);
		auto& chain3 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).                  // xfade1_impl::chain3_t
                       getT(1).getT(5).getT(0).getT(1).getT(0).getT(3);
		auto& cable_table6 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).            // xfade1_impl::cable_table6_t
                             getT(1).getT(5).getT(0).getT(1).getT(0).getT(3).
                             getT(0);
		auto& cable_table = this->getT(1).getT(0).getT(0).getT(1).getT(1).                     // xfade1_impl::cable_table_t<NV>
                            getT(0).getT(1).getT(5).getT(0).getT(1).
                            getT(1);
		auto& pma38 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma38_t<NV>
                      getT(0).getT(1).getT(5).getT(0).getT(2);
		auto& chain23 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::chain23_t<NV>
                        getT(0).getT(1).getT(5).getT(0).getT(3);
		auto& split22 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                         // xfade1_impl::split22_t<NV>
                        getT(0).getT(1).getT(5).getT(0).getT(3).
                        getT(0);
		auto& smoothed_parameter3_x4 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade1_impl::smoothed_parameter3_x4_t<NV>
                                       getT(1).getT(5).getT(0).getT(3).getT(0).getT(0);
		auto& smoothed_parameter15 = this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).    // xfade1_impl::smoothed_parameter15_t<NV>
                                     getT(1).getT(5).getT(0).getT(3).getT(0).getT(1);
		auto& input_toggle17 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                  // xfade1_impl::input_toggle17_t<NV>
                               getT(0).getT(1).getT(5).getT(0).getT(3).
                               getT(1);
		auto& pma39 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                           // xfade1_impl::pma39_t<NV>
                      getT(0).getT(1).getT(5).getT(0).getT(3).
                      getT(2);
		auto& gain15 = this->getT(1).getT(0).getT(0).getT(1).getT(1).                          // core::gain<NV>
                       getT(0).getT(1).getT(5).getT(0).getT(4);
		auto& sb5 = this->getT(1).getT(0).getT(0).getT(1).getT(2);                             // xfade1_impl::sb5_t<NV>
		auto& x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0);                      // xfade1_impl::x3_t<NV>
		auto& switcher_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).getT(0);     // xfade1_impl::switcher_x3_t<NV>
		auto& sb_container_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).getT(1); // xfade1_impl::sb_container_x3_t<NV>
		auto& sb1_x3 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb1_x3_t<NV>
                       getT(2).getT(0).getT(1).getT(0);
		auto& chain1_x3 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain1_x3_t<NV>
                          getT(2).getT(0).getT(1).getT(0).
                          getT(0);
		auto& xfader_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                       // xfade1_impl::xfader_x3_t<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& pma28 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma28_t<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& split14 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::split14_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2);
		auto& smoothed_parameter_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).           // xfade1_impl::smoothed_parameter_x3_t<NV>
                                      getT(0).getT(1).getT(0).getT(0).getT(2).
                                      getT(0);
		auto& smoothed_parameter10 = this->getT(1).getT(0).getT(0).getT(1).getT(2).            // xfade1_impl::smoothed_parameter10_t<NV>
                                     getT(0).getT(1).getT(0).getT(0).getT(2).
                                     getT(1);
		auto& input_toggle11 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                  // xfade1_impl::input_toggle11_t<NV>
                               getT(0).getT(1).getT(0).getT(0).getT(3);
		auto& pma32 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma32_t<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(4);
		auto& gain10 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                          // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(5);
		auto& sb2_x3 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb2_x3_t<NV>
                       getT(2).getT(0).getT(1).getT(1);
		auto& chain3_x1_x3 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade1_impl::chain3_x1_x3_t<NV>
                             getT(2).getT(0).getT(1).getT(1).
                             getT(0);
		auto& xfader2_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                      // xfade1_impl::xfader2_x3_t<NV>
                           getT(0).getT(1).getT(1).getT(0).getT(0);
		auto& pma29 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma29_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(1);
		auto& chain19 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::chain19_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2);
		auto& split15 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::split15_t<NV>
                        getT(0).getT(1).getT(1).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter1_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).  // xfade1_impl::smoothed_parameter1_x3_t<NV>
                                       getT(1).getT(1).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter11 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).    // xfade1_impl::smoothed_parameter11_t<NV>
                                     getT(1).getT(1).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle12 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                  // xfade1_impl::input_toggle12_t<NV>
                               getT(0).getT(1).getT(1).getT(0).getT(2).
                               getT(1);
		auto& pma37 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma37_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(3);
		auto& gain11 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                          // core::gain<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(4);
		auto& sb3_x3 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb3_x3_t<NV>
                       getT(2).getT(0).getT(1).getT(2);
		auto& chain2_x3 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain2_x3_t<NV>
                          getT(2).getT(0).getT(1).getT(2).
                          getT(0);
		auto& xfader1_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                      // xfade1_impl::xfader1_x3_t<NV>
                           getT(0).getT(1).getT(2).getT(0).getT(0);
		auto& pma35 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma35_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(1);
		auto& chain20 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::chain20_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(2);
		auto& split16 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::split16_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter2_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).  // xfade1_impl::smoothed_parameter2_x3_t<NV>
                                       getT(1).getT(2).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter12 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).    // xfade1_impl::smoothed_parameter12_t<NV>
                                     getT(1).getT(2).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle13 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                  // xfade1_impl::input_toggle13_t<NV>
                               getT(0).getT(1).getT(2).getT(0).getT(2).
                               getT(1);
		auto& pma36 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma36_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(3);
		auto& gain12 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                          // core::gain<NV>
                       getT(0).getT(1).getT(2).getT(0).getT(4);
		auto& sb4_x3 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb4_x3_t<NV>
                       getT(2).getT(0).getT(1).getT(3);
		auto& chain4_x3 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain4_x3_t<NV>
                          getT(2).getT(0).getT(1).getT(3).
                          getT(0);
		auto& xfader3_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                      // xfade1_impl::xfader3_x3_t<NV>
                           getT(0).getT(1).getT(3).getT(0).getT(0);
		auto& chain21 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::chain21_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(1);
		auto& pma33 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma33_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(1).
                      getT(0);
		auto& split17 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::split17_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(1).
                        getT(1);
		auto& smoothed_parameter4_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).  // xfade1_impl::smoothed_parameter4_x3_t<NV>
                                       getT(1).getT(3).getT(0).getT(1).getT(1).getT(0);
		auto& smoothed_parameter13 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).    // xfade1_impl::smoothed_parameter13_t<NV>
                                     getT(1).getT(3).getT(0).getT(1).getT(1).getT(1);
		auto& input_toggle14 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                  // xfade1_impl::input_toggle14_t<NV>
                               getT(0).getT(1).getT(3).getT(0).getT(1).
                               getT(2);
		auto& pma34 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma34_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(1).
                      getT(3);
		auto& gain13 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                          // core::gain<NV>
                       getT(0).getT(1).getT(3).getT(0).getT(2);
		auto& sb5_x3 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade1_impl::sb5_x3_t<NV>
                       getT(2).getT(0).getT(1).getT(4);
		auto& chain5_x3 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain5_x3_t<NV>
                          getT(2).getT(0).getT(1).getT(4).
                          getT(0);
		auto& xfader4_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                      // xfade1_impl::xfader4_x3_t<NV>
                           getT(0).getT(1).getT(4).getT(0).getT(0);
		auto& pma30 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma30_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(1);
		auto& chain22 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::chain22_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2);
		auto& split18 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::split18_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter3_x3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).  // xfade1_impl::smoothed_parameter3_x3_t<NV>
                                       getT(1).getT(4).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter14 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).    // xfade1_impl::smoothed_parameter14_t<NV>
                                     getT(1).getT(4).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle15 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                  // xfade1_impl::input_toggle15_t<NV>
                               getT(0).getT(1).getT(4).getT(0).getT(2).
                               getT(1);
		auto& pma31 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma31_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(2).
                      getT(2);
		auto& gain14 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                          // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(0).getT(3);
		auto& soft_bypass1 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade1_impl::soft_bypass1_t<NV>
                             getT(2).getT(0).getT(1).getT(5);
		auto& chain5_x6 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade1_impl::chain5_x6_t<NV>
                          getT(2).getT(0).getT(1).getT(5).
                          getT(0);
		auto& pma42 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma42_t<NV>
                      getT(0).getT(1).getT(5).getT(0).getT(0);
		auto& modchain3 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                       // xfade1_impl::modchain3_t<NV>
                          getT(0).getT(1).getT(5).getT(0).getT(1);
		auto& split2 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                          // xfade1_impl::split2_t<NV>
                       getT(0).getT(1).getT(5).getT(0).getT(1).
                       getT(0);
		auto& chain46 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).                 // xfade1_impl::chain46_t<NV>
                        getT(1).getT(5).getT(0).getT(1).getT(0).getT(0);
		auto& cable_table18 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).           // xfade1_impl::cable_table18_t<NV>
                              getT(1).getT(5).getT(0).getT(1).getT(0).getT(0).
                              getT(0);
		auto& chain47 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).                 // xfade1_impl::chain47_t
                        getT(1).getT(5).getT(0).getT(1).getT(0).getT(1);
		auto& cable_table19 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).           // xfade1_impl::cable_table19_t
                              getT(1).getT(5).getT(0).getT(1).getT(0).getT(1).
                              getT(0);
		auto& cable_table22 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                   // xfade1_impl::cable_table22_t<NV>
                              getT(0).getT(1).getT(5).getT(0).getT(1).
                              getT(1);
		auto& pma43 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                           // xfade1_impl::pma43_t<NV>
                      getT(0).getT(1).getT(5).getT(0).getT(2);
		auto& chain50 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::chain50_t<NV>
                        getT(0).getT(1).getT(5).getT(0).getT(3);
		auto& split24 = this->getT(1).getT(0).getT(0).getT(1).getT(2).                         // xfade1_impl::split24_t<NV>
                        getT(0).getT(1).getT(5).getT(0).getT(3).
                        getT(0);
		auto& smoothed_parameter3_x6 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).  // xfade1_impl::smoothed_parameter3_x6_t<NV>
                                       getT(1).getT(5).getT(0).getT(3).getT(0).getT(0);
		auto& smoothed_parameter18 = this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).  // xfade1_impl::smoothed_parameter18_t<NV>
                                     getT(1).getT(5).getT(0).getT(3).getT(0).getT(1);
		auto& input_toggle19 = this->getT(1).getT(0).getT(0).getT(1).getT(2).  // xfade1_impl::input_toggle19_t<NV>
                               getT(0).getT(1).getT(5).getT(0).getT(3).
                               getT(1);
		auto& pma44 = this->getT(1).getT(0).getT(0).getT(1).getT(2).   // xfade1_impl::pma44_t<NV>
                      getT(0).getT(1).getT(5).getT(0).getT(3).
                      getT(2);
		auto& gain18 = this->getT(1).getT(0).getT(0).getT(1).getT(2).  // core::gain<NV>
                       getT(0).getT(1).getT(5).getT(0).getT(4);
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& XF1_smooth_x1_p = XF1.getParameterT(0);
		XF1_smooth_x1_p.connectT(0, smoothed_parameter2_x1);  // smooth_x1 -> smoothed_parameter2_x1::SmoothingTime
		XF1_smooth_x1_p.connectT(1, smoothed_parameter4_x1);  // smooth_x1 -> smoothed_parameter4_x1::SmoothingTime
		XF1_smooth_x1_p.connectT(2, smoothed_parameter3_x1);  // smooth_x1 -> smoothed_parameter3_x1::SmoothingTime
		XF1_smooth_x1_p.connectT(3, smoothed_parameter3);     // smooth_x1 -> smoothed_parameter3::SmoothingTime
		XF1_smooth_x1_p.connectT(4, smoothed_parameter4);     // smooth_x1 -> smoothed_parameter4::SmoothingTime
		XF1_smooth_x1_p.connectT(5, smoothed_parameter2);     // smooth_x1 -> smoothed_parameter2::SmoothingTime
		XF1_smooth_x1_p.connectT(6, smoothed_parameter_x2);   // smooth_x1 -> smoothed_parameter_x2::SmoothingTime
		XF1_smooth_x1_p.connectT(7, smoothed_parameter5);     // smooth_x1 -> smoothed_parameter5::SmoothingTime
		XF1_smooth_x1_p.connectT(8, smoothed_parameter1_x2);  // smooth_x1 -> smoothed_parameter1_x2::SmoothingTime
		XF1_smooth_x1_p.connectT(9, smoothed_parameter2_x2);  // smooth_x1 -> smoothed_parameter2_x2::SmoothingTime
		XF1_smooth_x1_p.connectT(10, smoothed_parameter6);    // smooth_x1 -> smoothed_parameter6::SmoothingTime
		XF1_smooth_x1_p.connectT(11, smoothed_parameter7);    // smooth_x1 -> smoothed_parameter7::SmoothingTime
		XF1_smooth_x1_p.connectT(12, smoothed_parameter8);    // smooth_x1 -> smoothed_parameter8::SmoothingTime
		XF1_smooth_x1_p.connectT(13, smoothed_parameter4_x2); // smooth_x1 -> smoothed_parameter4_x2::SmoothingTime
		XF1_smooth_x1_p.connectT(14, smoothed_parameter3_x2); // smooth_x1 -> smoothed_parameter3_x2::SmoothingTime
		XF1_smooth_x1_p.connectT(15, smoothed_parameter9);    // smooth_x1 -> smoothed_parameter9::SmoothingTime
		XF1_smooth_x1_p.connectT(16, smoothed_parameter_x3);  // smooth_x1 -> smoothed_parameter_x3::SmoothingTime
		XF1_smooth_x1_p.connectT(17, smoothed_parameter10);   // smooth_x1 -> smoothed_parameter10::SmoothingTime
		XF1_smooth_x1_p.connectT(18, smoothed_parameter1_x3); // smooth_x1 -> smoothed_parameter1_x3::SmoothingTime
		XF1_smooth_x1_p.connectT(19, smoothed_parameter11);   // smooth_x1 -> smoothed_parameter11::SmoothingTime
		XF1_smooth_x1_p.connectT(20, smoothed_parameter2_x3); // smooth_x1 -> smoothed_parameter2_x3::SmoothingTime
		XF1_smooth_x1_p.connectT(21, smoothed_parameter12);   // smooth_x1 -> smoothed_parameter12::SmoothingTime
		XF1_smooth_x1_p.connectT(22, smoothed_parameter4_x3); // smooth_x1 -> smoothed_parameter4_x3::SmoothingTime
		XF1_smooth_x1_p.connectT(23, smoothed_parameter13);   // smooth_x1 -> smoothed_parameter13::SmoothingTime
		XF1_smooth_x1_p.connectT(24, smoothed_parameter3_x3); // smooth_x1 -> smoothed_parameter3_x3::SmoothingTime
		XF1_smooth_x1_p.connectT(25, smoothed_parameter14);   // smooth_x1 -> smoothed_parameter14::SmoothingTime
		XF1_smooth_x1_p.connectT(26, smoothed_parameter1_x4); // smooth_x1 -> smoothed_parameter1_x4::SmoothingTime
		XF1_smooth_x1_p.connectT(27, smoothed_parameter17);   // smooth_x1 -> smoothed_parameter17::SmoothingTime
		XF1_smooth_x1_p.connectT(28, smoothed_parameter1_x1); // smooth_x1 -> smoothed_parameter1_x1::SmoothingTime
		XF1_smooth_x1_p.connectT(29, smoothed_parameter1);    // smooth_x1 -> smoothed_parameter1::SmoothingTime
		XF1_smooth_x1_p.connectT(30, smoothed_parameter3_x4); // smooth_x1 -> smoothed_parameter3_x4::SmoothingTime
		XF1_smooth_x1_p.connectT(31, smoothed_parameter15);   // smooth_x1 -> smoothed_parameter15::SmoothingTime
		
		auto& XF1_SmoothType_p = XF1.getParameterT(1);
		XF1_SmoothType_p.connectT(0, input_toggle2);   // SmoothType -> input_toggle2::Input
		XF1_SmoothType_p.connectT(1, input_toggle4);   // SmoothType -> input_toggle4::Input
		XF1_SmoothType_p.connectT(2, input_toggle5);   // SmoothType -> input_toggle5::Input
		XF1_SmoothType_p.connectT(3, input_toggle3);   // SmoothType -> input_toggle3::Input
		XF1_SmoothType_p.connectT(4, input_toggle6);   // SmoothType -> input_toggle6::Input
		XF1_SmoothType_p.connectT(5, input_toggle7);   // SmoothType -> input_toggle7::Input
		XF1_SmoothType_p.connectT(6, input_toggle8);   // SmoothType -> input_toggle8::Input
		XF1_SmoothType_p.connectT(7, input_toggle9);   // SmoothType -> input_toggle9::Input
		XF1_SmoothType_p.connectT(8, input_toggle10);  // SmoothType -> input_toggle10::Input
		XF1_SmoothType_p.connectT(9, input_toggle11);  // SmoothType -> input_toggle11::Input
		XF1_SmoothType_p.connectT(10, input_toggle12); // SmoothType -> input_toggle12::Input
		XF1_SmoothType_p.connectT(11, input_toggle13); // SmoothType -> input_toggle13::Input
		XF1_SmoothType_p.connectT(12, input_toggle14); // SmoothType -> input_toggle14::Input
		XF1_SmoothType_p.connectT(13, input_toggle15); // SmoothType -> input_toggle15::Input
		XF1_SmoothType_p.connectT(14, input_toggle16); // SmoothType -> input_toggle16::Input
		XF1_SmoothType_p.connectT(15, input_toggle17); // SmoothType -> input_toggle17::Input
		this->getParameterT(0).connectT(0, pma7);      // MainParam -> pma7::Add
		
		auto& _2ndParam_p = this->getParameterT(1);
		_2ndParam_p.connectT(0, XF1);                    // _2ndParam -> XF1::smooth_x1
		_2ndParam_p.connectT(1, smoothed_parameter3_x6); // _2ndParam -> smoothed_parameter3_x6::SmoothingTime
		_2ndParam_p.connectT(2, smoothed_parameter18);   // _2ndParam -> smoothed_parameter18::SmoothingTime
		_2ndParam_p.connectT(3, smoothed_parameter3_x5); // _2ndParam -> smoothed_parameter3_x5::SmoothingTime
		_2ndParam_p.connectT(4, smoothed_parameter16);   // _2ndParam -> smoothed_parameter16::SmoothingTime
		
		auto& _3rdParam_p = this->getParameterT(2);
		_3rdParam_p.connectT(0, switcher_x1); // _3rdParam -> switcher_x1::Value
		_3rdParam_p.connectT(1, switcher_x2); // _3rdParam -> switcher_x2::Value
		_3rdParam_p.connectT(2, switcher_x3); // _3rdParam -> switcher_x3::Value
		
		auto& _4thParam_p = this->getParameterT(3);
		_4thParam_p.connectT(0, XF1);            // _4thParam -> XF1::SmoothType
		_4thParam_p.connectT(1, input_toggle19); // _4thParam -> input_toggle19::Input
		_4thParam_p.connectT(2, input_toggle18); // _4thParam -> input_toggle18::Input
		
		this->getParameterT(4).connectT(0, switcher1); // _5thParam -> switcher1::Value
		
		this->getParameterT(5).connectT(0, pma); // Poly -> pma::Multiply
		
		this->getParameterT(6).connectT(0, pma7); // Global -> pma7::Multiply
		
		this->getParameterT(7).connectT(0, event_data_reader7); // GlobalSrc -> event_data_reader7::SlotIndex
		
		this->getParameterT(8).connectT(0, pma3); // Vel -> pma3::Multiply
		
		this->getParameterT(9).connectT(0, pma4); // Trk -> pma4::Multiply
		
		this->getParameterT(10).connectT(0, pma5); // MW -> pma5::Multiply
		
		this->getParameterT(11).connectT(0, pma6); // AT -> pma6::Multiply
		
		this->getParameterT(12).connectT(0, branch3); // MonoSrc -> branch3::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma9.getWrappedObject().getParameter().connectT(0, gain16);                 // pma9 -> gain16::Gain
		input_toggle16.getWrappedObject().getParameter().connectT(0, pma9);         // input_toggle16 -> pma9::Add
		smoothed_parameter1_x4.getParameter().connectT(0, input_toggle16);          // smoothed_parameter1_x4 -> input_toggle16::Value1
		smoothed_parameter17.getParameter().connectT(0, input_toggle16);            // smoothed_parameter17 -> input_toggle16::Value2
		pma8.getWrappedObject().getParameter().connectT(0, smoothed_parameter1_x4); // pma8 -> smoothed_parameter1_x4::Value
		pma8.getWrappedObject().getParameter().connectT(1, smoothed_parameter17);   // pma8 -> smoothed_parameter17::Value
		auto& xfader_x1_p = xfader_x1.getWrappedObject().getParameter();
		xfader_x1_p.getParameterT(0).connectT(0, pma8);                              // xfader_x1 -> pma8::Add
		pma11.getWrappedObject().getParameter().connectT(0, gain1);                  // pma11 -> gain1::Gain
		input_toggle2.getWrappedObject().getParameter().connectT(0, pma11);          // input_toggle2 -> pma11::Add
		smoothed_parameter1.getParameter().connectT(0, input_toggle2);               // smoothed_parameter1 -> input_toggle2::Value2
		smoothed_parameter1_x1.getParameter().connectT(0, input_toggle2);            // smoothed_parameter1_x1 -> input_toggle2::Value1
		pma10.getWrappedObject().getParameter().connectT(0, smoothed_parameter1);    // pma10 -> smoothed_parameter1::Value
		pma10.getWrappedObject().getParameter().connectT(1, smoothed_parameter1_x1); // pma10 -> smoothed_parameter1_x1::Value
		auto& xfader2_x1_p = xfader2_x1.getWrappedObject().getParameter();
		xfader2_x1_p.getParameterT(0).connectT(0, pma10);                            // xfader2_x1 -> pma10::Add
		pma13.getWrappedObject().getParameter().connectT(0, gain2);                  // pma13 -> gain2::Gain
		input_toggle4.getWrappedObject().getParameter().connectT(0, pma13);          // input_toggle4 -> pma13::Add
		smoothed_parameter2_x1.getParameter().connectT(0, input_toggle4);            // smoothed_parameter2_x1 -> input_toggle4::Value1
		smoothed_parameter3.getParameter().connectT(0, input_toggle4);               // smoothed_parameter3 -> input_toggle4::Value2
		pma12.getWrappedObject().getParameter().connectT(0, smoothed_parameter2_x1); // pma12 -> smoothed_parameter2_x1::Value
		pma12.getWrappedObject().getParameter().connectT(1, smoothed_parameter3);    // pma12 -> smoothed_parameter3::Value
		auto& xfader1_x1_p = xfader1_x1.getWrappedObject().getParameter();
		xfader1_x1_p.getParameterT(0).connectT(0, pma12);                            // xfader1_x1 -> pma12::Add
		pma15.getWrappedObject().getParameter().connectT(0, gain3);                  // pma15 -> gain3::Gain
		input_toggle5.getWrappedObject().getParameter().connectT(0, pma15);          // input_toggle5 -> pma15::Add
		smoothed_parameter4_x1.getParameter().connectT(0, input_toggle5);            // smoothed_parameter4_x1 -> input_toggle5::Value1
		smoothed_parameter4.getParameter().connectT(0, input_toggle5);               // smoothed_parameter4 -> input_toggle5::Value2
		pma17.getWrappedObject().getParameter().connectT(0, smoothed_parameter4_x1); // pma17 -> smoothed_parameter4_x1::Value
		pma17.getWrappedObject().getParameter().connectT(1, smoothed_parameter4);    // pma17 -> smoothed_parameter4::Value
		auto& xfader3_x1_p = xfader3_x1.getWrappedObject().getParameter();
		xfader3_x1_p.getParameterT(0).connectT(0, pma17);                            // xfader3_x1 -> pma17::Add
		pma16.getWrappedObject().getParameter().connectT(0, gain4);                  // pma16 -> gain4::Gain
		input_toggle3.getWrappedObject().getParameter().connectT(0, pma16);          // input_toggle3 -> pma16::Add
		smoothed_parameter3_x1.getParameter().connectT(0, input_toggle3);            // smoothed_parameter3_x1 -> input_toggle3::Value1
		smoothed_parameter2.getParameter().connectT(0, input_toggle3);               // smoothed_parameter2 -> input_toggle3::Value2
		pma14.getWrappedObject().getParameter().connectT(0, smoothed_parameter3_x1); // pma14 -> smoothed_parameter3_x1::Value
		pma14.getWrappedObject().getParameter().connectT(1, smoothed_parameter2);    // pma14 -> smoothed_parameter2::Value
		auto& xfader4_x1_p = xfader4_x1.getWrappedObject().getParameter();
		xfader4_x1_p.getParameterT(0).connectT(0, pma14);                           // xfader4_x1 -> pma14::Add
		pma19.getWrappedObject().getParameter().connectT(0, gain5);                 // pma19 -> gain5::Gain
		input_toggle6.getWrappedObject().getParameter().connectT(0, pma19);         // input_toggle6 -> pma19::Add
		smoothed_parameter_x2.getParameter().connectT(0, input_toggle6);            // smoothed_parameter_x2 -> input_toggle6::Value1
		smoothed_parameter5.getParameter().connectT(0, input_toggle6);              // smoothed_parameter5 -> input_toggle6::Value2
		pma21.getWrappedObject().getParameter().connectT(0, smoothed_parameter_x2); // pma21 -> smoothed_parameter_x2::Value
		pma21.getWrappedObject().getParameter().connectT(1, smoothed_parameter5);   // pma21 -> smoothed_parameter5::Value
		auto& xfader_x2_p = xfader_x2.getWrappedObject().getParameter();
		xfader_x2_p.getParameterT(0).connectT(0, pma21);                             // xfader_x2 -> pma21::Add
		pma20.getWrappedObject().getParameter().connectT(0, gain6);                  // pma20 -> gain6::Gain
		input_toggle7.getWrappedObject().getParameter().connectT(0, pma20);          // input_toggle7 -> pma20::Add
		smoothed_parameter6.getParameter().connectT(0, input_toggle7);               // smoothed_parameter6 -> input_toggle7::Value2
		smoothed_parameter1_x2.getParameter().connectT(0, input_toggle7);            // smoothed_parameter1_x2 -> input_toggle7::Value1
		pma18.getWrappedObject().getParameter().connectT(0, smoothed_parameter6);    // pma18 -> smoothed_parameter6::Value
		pma18.getWrappedObject().getParameter().connectT(1, smoothed_parameter1_x2); // pma18 -> smoothed_parameter1_x2::Value
		auto& xfader2_x2_p = xfader2_x2.getWrappedObject().getParameter();
		xfader2_x2_p.getParameterT(0).connectT(0, pma18);                            // xfader2_x2 -> pma18::Add
		pma23.getWrappedObject().getParameter().connectT(0, gain7);                  // pma23 -> gain7::Gain
		input_toggle8.getWrappedObject().getParameter().connectT(0, pma23);          // input_toggle8 -> pma23::Add
		smoothed_parameter2_x2.getParameter().connectT(0, input_toggle8);            // smoothed_parameter2_x2 -> input_toggle8::Value1
		smoothed_parameter7.getParameter().connectT(0, input_toggle8);               // smoothed_parameter7 -> input_toggle8::Value2
		pma22.getWrappedObject().getParameter().connectT(0, smoothed_parameter2_x2); // pma22 -> smoothed_parameter2_x2::Value
		pma22.getWrappedObject().getParameter().connectT(1, smoothed_parameter7);    // pma22 -> smoothed_parameter7::Value
		auto& xfader1_x2_p = xfader1_x2.getWrappedObject().getParameter();
		xfader1_x2_p.getParameterT(0).connectT(0, pma22);                            // xfader1_x2 -> pma22::Add
		pma25.getWrappedObject().getParameter().connectT(0, gain8);                  // pma25 -> gain8::Gain
		input_toggle9.getWrappedObject().getParameter().connectT(0, pma25);          // input_toggle9 -> pma25::Add
		smoothed_parameter4_x2.getParameter().connectT(0, input_toggle9);            // smoothed_parameter4_x2 -> input_toggle9::Value1
		smoothed_parameter8.getParameter().connectT(0, input_toggle9);               // smoothed_parameter8 -> input_toggle9::Value2
		pma24.getWrappedObject().getParameter().connectT(0, smoothed_parameter4_x2); // pma24 -> smoothed_parameter4_x2::Value
		pma24.getWrappedObject().getParameter().connectT(1, smoothed_parameter8);    // pma24 -> smoothed_parameter8::Value
		auto& xfader3_x2_p = xfader3_x2.getWrappedObject().getParameter();
		xfader3_x2_p.getParameterT(0).connectT(0, pma24);                            // xfader3_x2 -> pma24::Add
		pma27.getWrappedObject().getParameter().connectT(0, gain9);                  // pma27 -> gain9::Gain
		input_toggle10.getWrappedObject().getParameter().connectT(0, pma27);         // input_toggle10 -> pma27::Add
		smoothed_parameter9.getParameter().connectT(0, input_toggle10);              // smoothed_parameter9 -> input_toggle10::Value2
		smoothed_parameter3_x2.getParameter().connectT(0, input_toggle10);           // smoothed_parameter3_x2 -> input_toggle10::Value1
		pma26.getWrappedObject().getParameter().connectT(0, smoothed_parameter9);    // pma26 -> smoothed_parameter9::Value
		pma26.getWrappedObject().getParameter().connectT(1, smoothed_parameter3_x2); // pma26 -> smoothed_parameter3_x2::Value
		auto& xfader4_x2_p = xfader4_x2.getWrappedObject().getParameter();
		xfader4_x2_p.getParameterT(0).connectT(0, pma26);                           // xfader4_x2 -> pma26::Add
		pma32.getWrappedObject().getParameter().connectT(0, gain10);                // pma32 -> gain10::Gain
		input_toggle11.getWrappedObject().getParameter().connectT(0, pma32);        // input_toggle11 -> pma32::Add
		smoothed_parameter10.getParameter().connectT(0, input_toggle11);            // smoothed_parameter10 -> input_toggle11::Value2
		smoothed_parameter_x3.getParameter().connectT(0, input_toggle11);           // smoothed_parameter_x3 -> input_toggle11::Value1
		pma28.getWrappedObject().getParameter().connectT(0, smoothed_parameter10);  // pma28 -> smoothed_parameter10::Value
		pma28.getWrappedObject().getParameter().connectT(1, smoothed_parameter_x3); // pma28 -> smoothed_parameter_x3::Value
		auto& xfader_x3_p = xfader_x3.getWrappedObject().getParameter();
		xfader_x3_p.getParameterT(0).connectT(0, pma28);                             // xfader_x3 -> pma28::Add
		pma37.getWrappedObject().getParameter().connectT(0, gain11);                 // pma37 -> gain11::Gain
		input_toggle12.getWrappedObject().getParameter().connectT(0, pma37);         // input_toggle12 -> pma37::Add
		smoothed_parameter1_x3.getParameter().connectT(0, input_toggle12);           // smoothed_parameter1_x3 -> input_toggle12::Value1
		smoothed_parameter11.getParameter().connectT(0, input_toggle12);             // smoothed_parameter11 -> input_toggle12::Value2
		pma29.getWrappedObject().getParameter().connectT(0, smoothed_parameter1_x3); // pma29 -> smoothed_parameter1_x3::Value
		pma29.getWrappedObject().getParameter().connectT(1, smoothed_parameter11);   // pma29 -> smoothed_parameter11::Value
		auto& xfader2_x3_p = xfader2_x3.getWrappedObject().getParameter();
		xfader2_x3_p.getParameterT(0).connectT(0, pma29);                            // xfader2_x3 -> pma29::Add
		pma36.getWrappedObject().getParameter().connectT(0, gain12);                 // pma36 -> gain12::Gain
		input_toggle13.getWrappedObject().getParameter().connectT(0, pma36);         // input_toggle13 -> pma36::Add
		smoothed_parameter2_x3.getParameter().connectT(0, input_toggle13);           // smoothed_parameter2_x3 -> input_toggle13::Value1
		smoothed_parameter12.getParameter().connectT(0, input_toggle13);             // smoothed_parameter12 -> input_toggle13::Value2
		pma35.getWrappedObject().getParameter().connectT(0, smoothed_parameter2_x3); // pma35 -> smoothed_parameter2_x3::Value
		pma35.getWrappedObject().getParameter().connectT(1, smoothed_parameter12);   // pma35 -> smoothed_parameter12::Value
		auto& xfader1_x3_p = xfader1_x3.getWrappedObject().getParameter();
		xfader1_x3_p.getParameterT(0).connectT(0, pma35);                            // xfader1_x3 -> pma35::Add
		pma34.getWrappedObject().getParameter().connectT(0, gain13);                 // pma34 -> gain13::Gain
		input_toggle14.getWrappedObject().getParameter().connectT(0, pma34);         // input_toggle14 -> pma34::Add
		smoothed_parameter4_x3.getParameter().connectT(0, input_toggle14);           // smoothed_parameter4_x3 -> input_toggle14::Value1
		smoothed_parameter13.getParameter().connectT(0, input_toggle14);             // smoothed_parameter13 -> input_toggle14::Value2
		pma33.getWrappedObject().getParameter().connectT(0, smoothed_parameter4_x3); // pma33 -> smoothed_parameter4_x3::Value
		pma33.getWrappedObject().getParameter().connectT(1, smoothed_parameter13);   // pma33 -> smoothed_parameter13::Value
		auto& xfader3_x3_p = xfader3_x3.getWrappedObject().getParameter();
		xfader3_x3_p.getParameterT(0).connectT(0, pma33);                            // xfader3_x3 -> pma33::Add
		pma31.getWrappedObject().getParameter().connectT(0, gain14);                 // pma31 -> gain14::Gain
		input_toggle15.getWrappedObject().getParameter().connectT(0, pma31);         // input_toggle15 -> pma31::Add
		smoothed_parameter3_x3.getParameter().connectT(0, input_toggle15);           // smoothed_parameter3_x3 -> input_toggle15::Value1
		smoothed_parameter14.getParameter().connectT(0, input_toggle15);             // smoothed_parameter14 -> input_toggle15::Value2
		pma30.getWrappedObject().getParameter().connectT(0, smoothed_parameter3_x3); // pma30 -> smoothed_parameter3_x3::Value
		pma30.getWrappedObject().getParameter().connectT(1, smoothed_parameter14);   // pma30 -> smoothed_parameter14::Value
		auto& xfader4_x3_p = xfader4_x3.getWrappedObject().getParameter();
		xfader4_x3_p.getParameterT(0).connectT(0, pma30);                            // xfader4_x3 -> pma30::Add
		pma41.getWrappedObject().getParameter().connectT(0, gain17);                 // pma41 -> gain17::Gain
		input_toggle18.getWrappedObject().getParameter().connectT(0, pma41);         // input_toggle18 -> pma41::Add
		smoothed_parameter3_x5.getParameter().connectT(0, input_toggle18);           // smoothed_parameter3_x5 -> input_toggle18::Value1
		smoothed_parameter16.getParameter().connectT(0, input_toggle18);             // smoothed_parameter16 -> input_toggle18::Value2
		pma40.getWrappedObject().getParameter().connectT(0, smoothed_parameter3_x5); // pma40 -> smoothed_parameter3_x5::Value
		pma40.getWrappedObject().getParameter().connectT(1, smoothed_parameter16);   // pma40 -> smoothed_parameter16::Value
		cable_table17.getWrappedObject().getParameter().connectT(0, pma40);          // cable_table17 -> pma40::Add
		cable_table3.getWrappedObject().getParameter().connectT(0, cable_table17);   // cable_table3 -> cable_table17::Value
		pma2.getWrappedObject().getParameter().connectT(0, cable_table3);            // pma2 -> cable_table3::Value
		pma2.getWrappedObject().getParameter().connectT(1, cable_table5);            // pma2 -> cable_table5::Value
		pma2.getWrappedObject().getParameter().connectT(2, cable_table7);            // pma2 -> cable_table7::Value
		pma2.getWrappedObject().getParameter().connectT(3, cable_table9);            // pma2 -> cable_table9::Value
		pma2.getWrappedObject().getParameter().connectT(4, cable_table11);           // pma2 -> cable_table11::Value
		pma2.getWrappedObject().getParameter().connectT(5, cable_table13);           // pma2 -> cable_table13::Value
		pma2.getWrappedObject().getParameter().connectT(6, cable_table15);           // pma2 -> cable_table15::Value
		pma2.getWrappedObject().getParameter().connectT(7, cable_table16);           // pma2 -> cable_table16::Value
		pma39.getWrappedObject().getParameter().connectT(0, gain15);                 // pma39 -> gain15::Gain
		input_toggle17.getWrappedObject().getParameter().connectT(0, pma39);         // input_toggle17 -> pma39::Add
		smoothed_parameter3_x4.getParameter().connectT(0, input_toggle17);           // smoothed_parameter3_x4 -> input_toggle17::Value1
		smoothed_parameter15.getParameter().connectT(0, input_toggle17);             // smoothed_parameter15 -> input_toggle17::Value2
		pma38.getWrappedObject().getParameter().connectT(0, smoothed_parameter3_x4); // pma38 -> smoothed_parameter3_x4::Value
		pma38.getWrappedObject().getParameter().connectT(1, smoothed_parameter15);   // pma38 -> smoothed_parameter15::Value
		cable_table.getWrappedObject().getParameter().connectT(0, pma38);            // cable_table -> pma38::Add
		cable_table1.getWrappedObject().getParameter().connectT(0, cable_table);     // cable_table1 -> cable_table::Value
		pma1.getWrappedObject().getParameter().connectT(0, cable_table1);            // pma1 -> cable_table1::Value
		pma1.getWrappedObject().getParameter().connectT(1, cable_table2);            // pma1 -> cable_table2::Value
		pma1.getWrappedObject().getParameter().connectT(2, cable_table4);            // pma1 -> cable_table4::Value
		pma1.getWrappedObject().getParameter().connectT(3, cable_table6);            // pma1 -> cable_table6::Value
		pma44.getWrappedObject().getParameter().connectT(0, gain18);                 // pma44 -> gain18::Gain
		input_toggle19.getWrappedObject().getParameter().connectT(0, pma44);         // input_toggle19 -> pma44::Add
		smoothed_parameter3_x6.getParameter().connectT(0, input_toggle19);           // smoothed_parameter3_x6 -> input_toggle19::Value1
		smoothed_parameter18.getParameter().connectT(0, input_toggle19);             // smoothed_parameter18 -> input_toggle19::Value2
		pma43.getWrappedObject().getParameter().connectT(0, smoothed_parameter3_x6); // pma43 -> smoothed_parameter3_x6::Value
		pma43.getWrappedObject().getParameter().connectT(1, smoothed_parameter18);   // pma43 -> smoothed_parameter18::Value
		cable_table22.getWrappedObject().getParameter().connectT(0, pma43);          // cable_table22 -> pma43::Add
		cable_table18.getWrappedObject().getParameter().connectT(0, cable_table22);  // cable_table18 -> cable_table22::Value
		pma42.getWrappedObject().getParameter().connectT(0, cable_table18);          // pma42 -> cable_table18::Value
		pma42.getWrappedObject().getParameter().connectT(1, cable_table19);          // pma42 -> cable_table19::Value
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
		pma.getWrappedObject().getParameter().connectT(10, xfader_x3);               // pma -> xfader_x3::Value
		pma.getWrappedObject().getParameter().connectT(11, xfader2_x3);              // pma -> xfader2_x3::Value
		pma.getWrappedObject().getParameter().connectT(12, xfader1_x3);              // pma -> xfader1_x3::Value
		pma.getWrappedObject().getParameter().connectT(13, xfader3_x3);              // pma -> xfader3_x3::Value
		pma.getWrappedObject().getParameter().connectT(14, xfader4_x3);              // pma -> xfader4_x3::Value
		pma.getWrappedObject().getParameter().connectT(15, pma2);                    // pma -> pma2::Add
		pma.getWrappedObject().getParameter().connectT(16, pma1);                    // pma -> pma1::Add
		pma.getWrappedObject().getParameter().connectT(17, pma42);                   // pma -> pma42::Add
		pma3.getWrappedObject().getParameter().connectT(0, pma);                     // pma3 -> pma::Add
		midi.getParameter().connectT(0, pma3);                                       // midi -> pma3::Value
		pma4.getWrappedObject().getParameter().connectT(0, pma3);                    // pma4 -> pma3::Add
		midi1.getParameter().connectT(0, pma4);                                      // midi1 -> pma4::Value
		pma5.getWrappedObject().getParameter().connectT(0, pma4);                    // pma5 -> pma4::Add
		midi_cc.getWrappedObject().getParameter().connectT(0, pma5);                 // midi_cc -> pma5::Value
		pma6.getWrappedObject().getParameter().connectT(0, pma5);                    // pma6 -> pma5::Add
		midi_cc1.getWrappedObject().getParameter().connectT(0, pma6);                // midi_cc1 -> pma6::Value
		pma7.getWrappedObject().getParameter().connectT(0, pma6);                    // pma7 -> pma6::Add
		event_data_reader7.getParameter().connectT(0, pma7);                         // event_data_reader7 -> pma7::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add16);         // global_cable16 -> add16::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add17);         // global_cable17 -> add17::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add18);         // global_cable18 -> add18::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add19);         // global_cable19 -> add19::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add20);         // global_cable20 -> add20::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add21);         // global_cable21 -> add21::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add22);         // global_cable22 -> add22::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add23);         // global_cable23 -> add23::Value
		peak2.getParameter().connectT(0, pma);                                       // peak2 -> pma::Value
		auto& switcher_x1_p = switcher_x1.getWrappedObject().getParameter();
		switcher_x1_p.getParameterT(0).connectT(0, sb1_x1); // switcher_x1 -> sb1_x1::Bypassed
		switcher_x1_p.getParameterT(1).connectT(0, sb2_x1); // switcher_x1 -> sb2_x1::Bypassed
		switcher_x1_p.getParameterT(2).connectT(0, sb3_x1); // switcher_x1 -> sb3_x1::Bypassed
		switcher_x1_p.getParameterT(3).connectT(0, sb4_x1); // switcher_x1 -> sb4_x1::Bypassed
		switcher_x1_p.getParameterT(4).connectT(0, sb5_x1); // switcher_x1 -> sb5_x1::Bypassed
		switcher_x1_p.getParameterT(5).connectT(0, sb5_x4); // switcher_x1 -> sb5_x4::Bypassed
		auto& switcher_x2_p = switcher_x2.getWrappedObject().getParameter();
		switcher_x2_p.getParameterT(0).connectT(0, sb1_x2);      // switcher_x2 -> sb1_x2::Bypassed
		switcher_x2_p.getParameterT(1).connectT(0, sb2_x2);      // switcher_x2 -> sb2_x2::Bypassed
		switcher_x2_p.getParameterT(2).connectT(0, sb3_x2);      // switcher_x2 -> sb3_x2::Bypassed
		switcher_x2_p.getParameterT(3).connectT(0, sb4_x2);      // switcher_x2 -> sb4_x2::Bypassed
		switcher_x2_p.getParameterT(4).connectT(0, sb5_x2);      // switcher_x2 -> sb5_x2::Bypassed
		switcher_x2_p.getParameterT(5).connectT(0, soft_bypass); // switcher_x2 -> soft_bypass::Bypassed
		auto& switcher_x3_p = switcher_x3.getWrappedObject().getParameter();
		switcher_x3_p.getParameterT(0).connectT(0, sb1_x3); // switcher_x3 -> sb1_x3::Bypassed
		switcher_x3_p.getParameterT(1).connectT(0, sb2_x3); // switcher_x3 -> sb2_x3::Bypassed
		switcher_x3_p.getParameterT(2).connectT(0, sb3_x3); // switcher_x3 -> sb3_x3::Bypassed
		switcher_x3_p.getParameterT(3).connectT(0, sb4_x3); // switcher_x3 -> sb4_x3::Bypassed
		switcher_x3_p.getParameterT(4).connectT(0, sb5_x3); // switcher_x3 -> sb5_x3::Bypassed
		auto& switcher1_p = switcher1.getWrappedObject().getParameter();
		switcher1_p.getParameterT(0).connectT(0, sb3); // switcher1 -> sb3::Bypassed
		switcher1_p.getParameterT(1).connectT(0, sb4); // switcher1 -> sb4::Bypassed
		switcher1_p.getParameterT(2).connectT(0, sb5); // switcher1 -> sb5::Bypassed
		
		// Default Values --------------------------------------------------------------------------
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
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
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		; // XF1::smooth_x1 is automated
		; // XF1::SmoothType is automated
		
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
		
		pma2.setParameterT(0, 0.); // control::pma::Value
		pma2.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma2::Add is automated
		
		; // cable_table3::Value is automated
		
		; // cable_table5::Value is automated
		
		; // cable_table7::Value is automated
		
		; // cable_table9::Value is automated
		
		; // cable_table11::Value is automated
		
		; // cable_table13::Value is automated
		
		; // cable_table15::Value is automated
		
		; // cable_table16::Value is automated
		
		; // cable_table17::Value is automated
		
		pma40.setParameterT(0, 0.); // control::pma::Value
		pma40.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma40::Add is automated
		
		;                                            // smoothed_parameter3_x5::Value is automated
		;                                            // smoothed_parameter3_x5::SmoothingTime is automated
		smoothed_parameter3_x5.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter16::Value is automated
		;                                          // smoothed_parameter16::SmoothingTime is automated
		smoothed_parameter16.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle18::Input is automated
		; // input_toggle18::Value1 is automated
		; // input_toggle18::Value2 is automated
		
		pma41.setParameterT(0, 0.); // control::pma::Value
		pma41.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma41::Add is automated
		
		;                               // gain17::Gain is automated
		gain17.setParameterT(1, 0.);    // core::gain::Smoothing
		gain17.setParameterT(2, -100.); // core::gain::ResetValue
		
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
		
		pma1.setParameterT(0, 0.); // control::pma::Value
		pma1.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma1::Add is automated
		
		; // cable_table1::Value is automated
		
		; // cable_table2::Value is automated
		
		; // cable_table4::Value is automated
		
		; // cable_table6::Value is automated
		
		; // cable_table::Value is automated
		
		pma38.setParameterT(0, 0.); // control::pma::Value
		pma38.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma38::Add is automated
		
		;                                            // smoothed_parameter3_x4::Value is automated
		;                                            // smoothed_parameter3_x4::SmoothingTime is automated
		smoothed_parameter3_x4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter15::Value is automated
		;                                          // smoothed_parameter15::SmoothingTime is automated
		smoothed_parameter15.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle17::Input is automated
		; // input_toggle17::Value1 is automated
		; // input_toggle17::Value2 is automated
		
		pma39.setParameterT(0, 0.); // control::pma::Value
		pma39.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma39::Add is automated
		
		;                               // gain15::Gain is automated
		gain15.setParameterT(1, 0.);    // core::gain::Smoothing
		gain15.setParameterT(2, -100.); // core::gain::ResetValue
		
		x3.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher_x3::Value is automated
		
		; // xfader_x3::Value is automated
		
		pma28.setParameterT(0, 0.); // control::pma::Value
		pma28.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma28::Add is automated
		
		;                                           // smoothed_parameter_x3::Value is automated
		;                                           // smoothed_parameter_x3::SmoothingTime is automated
		smoothed_parameter_x3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter10::Value is automated
		;                                          // smoothed_parameter10::SmoothingTime is automated
		smoothed_parameter10.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle11::Input is automated
		; // input_toggle11::Value1 is automated
		; // input_toggle11::Value2 is automated
		
		pma32.setParameterT(0, 0.); // control::pma::Value
		pma32.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma32::Add is automated
		
		;                               // gain10::Gain is automated
		gain10.setParameterT(1, 0.);    // core::gain::Smoothing
		gain10.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader2_x3::Value is automated
		
		pma29.setParameterT(0, 0.); // control::pma::Value
		pma29.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma29::Add is automated
		
		;                                            // smoothed_parameter1_x3::Value is automated
		;                                            // smoothed_parameter1_x3::SmoothingTime is automated
		smoothed_parameter1_x3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter11::Value is automated
		;                                          // smoothed_parameter11::SmoothingTime is automated
		smoothed_parameter11.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle12::Input is automated
		; // input_toggle12::Value1 is automated
		; // input_toggle12::Value2 is automated
		
		pma37.setParameterT(0, 0.); // control::pma::Value
		pma37.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma37::Add is automated
		
		;                               // gain11::Gain is automated
		gain11.setParameterT(1, 0.);    // core::gain::Smoothing
		gain11.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader1_x3::Value is automated
		
		pma35.setParameterT(0, 0.); // control::pma::Value
		pma35.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma35::Add is automated
		
		;                                            // smoothed_parameter2_x3::Value is automated
		;                                            // smoothed_parameter2_x3::SmoothingTime is automated
		smoothed_parameter2_x3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter12::Value is automated
		;                                          // smoothed_parameter12::SmoothingTime is automated
		smoothed_parameter12.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle13::Input is automated
		; // input_toggle13::Value1 is automated
		; // input_toggle13::Value2 is automated
		
		pma36.setParameterT(0, 0.); // control::pma::Value
		pma36.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma36::Add is automated
		
		;                               // gain12::Gain is automated
		gain12.setParameterT(1, 0.);    // core::gain::Smoothing
		gain12.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader3_x3::Value is automated
		
		pma33.setParameterT(0, 0.); // control::pma::Value
		pma33.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma33::Add is automated
		
		;                                            // smoothed_parameter4_x3::Value is automated
		;                                            // smoothed_parameter4_x3::SmoothingTime is automated
		smoothed_parameter4_x3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter13::Value is automated
		;                                          // smoothed_parameter13::SmoothingTime is automated
		smoothed_parameter13.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle14::Input is automated
		; // input_toggle14::Value1 is automated
		; // input_toggle14::Value2 is automated
		
		pma34.setParameterT(0, 0.); // control::pma::Value
		pma34.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma34::Add is automated
		
		;                               // gain13::Gain is automated
		gain13.setParameterT(1, 0.);    // core::gain::Smoothing
		gain13.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader4_x3::Value is automated
		
		pma30.setParameterT(0, 0.); // control::pma::Value
		pma30.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma30::Add is automated
		
		;                                            // smoothed_parameter3_x3::Value is automated
		;                                            // smoothed_parameter3_x3::SmoothingTime is automated
		smoothed_parameter3_x3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter14::Value is automated
		;                                          // smoothed_parameter14::SmoothingTime is automated
		smoothed_parameter14.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle15::Input is automated
		; // input_toggle15::Value1 is automated
		; // input_toggle15::Value2 is automated
		
		pma31.setParameterT(0, 0.); // control::pma::Value
		pma31.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma31::Add is automated
		
		;                               // gain14::Gain is automated
		gain14.setParameterT(1, 0.);    // core::gain::Smoothing
		gain14.setParameterT(2, -100.); // core::gain::ResetValue
		
		pma42.setParameterT(0, 0.); // control::pma::Value
		pma42.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma42::Add is automated
		
		; // cable_table18::Value is automated
		
		; // cable_table19::Value is automated
		
		; // cable_table22::Value is automated
		
		pma43.setParameterT(0, 0.); // control::pma::Value
		pma43.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma43::Add is automated
		
		;                                            // smoothed_parameter3_x6::Value is automated
		;                                            // smoothed_parameter3_x6::SmoothingTime is automated
		smoothed_parameter3_x6.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter18::Value is automated
		;                                          // smoothed_parameter18::SmoothingTime is automated
		smoothed_parameter18.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle19::Input is automated
		; // input_toggle19::Value1 is automated
		; // input_toggle19::Value2 is automated
		
		pma44.setParameterT(0, 0.); // control::pma::Value
		pma44.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma44::Add is automated
		
		;                               // gain18::Gain is automated
		gain18.setParameterT(1, 0.);    // core::gain::Smoothing
		gain18.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.5);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.982771);
		this->setParameterT(4, 0.548141);
		this->setParameterT(5, -0.622853);
		this->setParameterT(6, -0.0635476);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade1_impl::global_cable16_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade1_impl::global_cable17_t<NV>
        getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade1_impl::global_cable18_t<NV>
        getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade1_impl::global_cable19_t<NV>
        getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade1_impl::global_cable20_t<NV>
        getT(0).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade1_impl::global_cable21_t<NV>
        getT(0).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade1_impl::global_cable22_t<NV>
        getT(0).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade1_impl::global_cable23_t<NV>
        getT(0).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(4).                          // xfade1_impl::peak2_t<NV>
        getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade1_impl::cable_table3_t<NV>
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade1_impl::cable_table5_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade1_impl::cable_table7_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(2).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade1_impl::cable_table9_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade1_impl::cable_table11_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(4).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade1_impl::cable_table13_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(5).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade1_impl::cable_table15_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(6).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade1_impl::cable_table16_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(7).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade1_impl::cable_table17_t<NV>
        getT(1).getT(5).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade1_impl::cable_table1_t<NV>
        getT(1).getT(5).getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade1_impl::cable_table2_t
        getT(1).getT(5).getT(0).getT(1).getT(0).getT(1).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade1_impl::cable_table4_t
        getT(1).getT(5).getT(0).getT(1).getT(0).getT(2).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(1).getT(0).  // xfade1_impl::cable_table6_t
        getT(1).getT(5).getT(0).getT(1).getT(0).getT(3).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(1).          // xfade1_impl::cable_table_t<NV>
        getT(0).getT(1).getT(5).getT(0).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).  // xfade1_impl::cable_table18_t<NV>
        getT(1).getT(5).getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(2).getT(0).  // xfade1_impl::cable_table19_t
        getT(1).getT(5).getT(0).getT(1).getT(0).getT(1).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(2).  // xfade1_impl::cable_table22_t<NV>
        getT(0).getT(1).getT(5).getT(0).getT(1).
        getT(1).setExternalData(b, index);
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
using xfade1 = wrap::node<xfade1_impl::instance<NV>>;
}


