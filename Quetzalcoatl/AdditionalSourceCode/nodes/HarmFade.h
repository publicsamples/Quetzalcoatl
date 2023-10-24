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

namespace HarmFade_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter1_modRange, 
                             -100., 
                             0., 
                             5.42227);

using smoothed_parameter1_mod = parameter::from0To1<core::gain, 
                                                    0, 
                                                    smoothed_parameter1_modRange>;

template <int NV>
using smoothed_parameter1_t = wrap::mod<smoothed_parameter1_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<smoothed_parameter1_t<NV>, 0>>;
template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<pma_t<NV>, 2>>;

using smoothed_parameter2_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter2_t = wrap::mod<smoothed_parameter2_mod, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using pma2_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter2_t<NV>, 0>>;
template <int NV>
using input_toggle1_t = control::input_toggle<parameter::plain<pma2_t<NV>, 2>>;

using smoothed_parameter3_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter3_t = wrap::mod<smoothed_parameter3_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma3_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter3_t<NV>, 0>>;
template <int NV>
using input_toggle2_t = control::input_toggle<parameter::plain<pma3_t<NV>, 2>>;

using smoothed_parameter4_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter4_t = wrap::mod<smoothed_parameter4_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma4_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter4_t<NV>, 0>>;
template <int NV>
using input_toggle3_t = control::input_toggle<parameter::plain<pma4_t<NV>, 2>>;

using smoothed_parameter_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter_t = wrap::mod<smoothed_parameter_mod, 
                                       control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma5_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter_t<NV>, 0>>;
template <int NV>
using input_toggle4_t = control::input_toggle<parameter::plain<pma5_t<NV>, 2>>;

using smoothed_parameter5_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter5_t = wrap::mod<smoothed_parameter5_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma6_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter5_t<NV>, 0>>;
template <int NV>
using input_toggle5_t = control::input_toggle<parameter::plain<pma6_t<NV>, 2>>;

using smoothed_parameter7_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter7_t = wrap::mod<smoothed_parameter7_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma7_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter7_t<NV>, 0>>;
template <int NV>
using input_toggle6_t = control::input_toggle<parameter::plain<pma7_t<NV>, 2>>;

using smoothed_parameter6_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter6_t = wrap::mod<smoothed_parameter6_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter6_t<NV>, 0>>;
template <int NV>
using input_toggle7_t = control::input_toggle<parameter::plain<pma1_t<NV>, 2>>;
template <int NV>
using xfader_multimod = parameter::list<parameter::plain<input_toggle_t<NV>, 1>, 
                                        parameter::plain<input_toggle1_t<NV>, 1>, 
                                        parameter::plain<input_toggle2_t<NV>, 1>, 
                                        parameter::plain<input_toggle3_t<NV>, 1>, 
                                        parameter::plain<input_toggle4_t<NV>, 1>, 
                                        parameter::plain<input_toggle5_t<NV>, 1>, 
                                        parameter::plain<input_toggle6_t<NV>, 1>, 
                                        parameter::plain<input_toggle7_t<NV>, 1>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::threshold>;

template <int NV>
using xfader3_multimod = parameter::list<parameter::plain<input_toggle_t<NV>, 2>, 
                                         parameter::plain<input_toggle1_t<NV>, 2>, 
                                         parameter::plain<input_toggle2_t<NV>, 2>, 
                                         parameter::plain<input_toggle3_t<NV>, 2>, 
                                         parameter::plain<input_toggle4_t<NV>, 2>, 
                                         parameter::plain<input_toggle5_t<NV>, 2>, 
                                         parameter::plain<input_toggle6_t<NV>, 2>, 
                                         parameter::plain<input_toggle7_t<NV>, 2>>;

template <int NV>
using xfader3_t = control::xfader<xfader3_multimod<NV>, faders::rms>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  xfader3_t<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, input_toggle_t<NV>>, 
                                  input_toggle1_t<NV>, 
                                  input_toggle2_t<NV>, 
                                  input_toggle3_t<NV>, 
                                  input_toggle4_t<NV>, 
                                  input_toggle5_t<NV>, 
                                  input_toggle6_t<NV>, 
                                  input_toggle7_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split1_t<NV>>, 
                                   split4_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain11_t<NV>>>;

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;
template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, 
                                             parameter::plain<file_player_t<NV>, 3>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled_t<NV>, 2>>;

template <int NV>
using file_player7_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;
template <int NV>
using file_player10_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<9>>;

template <int NV>
using pma_unscaled7_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player7_t<NV>, 3>, 
                                           parameter::plain<file_player10_t<NV>, 3>>;

template <int NV>
using pma_unscaled7_t = control::pma_unscaled<NV, pma_unscaled7_mod<NV>>;
template <int NV>
using minmax7_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled7_t<NV>, 2>>;

template <int NV>
using file_player6_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<2>>;
template <int NV>
using file_player11_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<10>>;

template <int NV>
using pma_unscaled6_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player6_t<NV>, 3>, 
                                           parameter::plain<file_player11_t<NV>, 3>>;

template <int NV>
using pma_unscaled6_t = control::pma_unscaled<NV, pma_unscaled6_mod<NV>>;
template <int NV>
using minmax6_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled6_t<NV>, 2>>;

template <int NV>
using file_player5_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<3>>;
template <int NV>
using file_player12_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<11>>;

template <int NV>
using pma_unscaled5_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player5_t<NV>, 3>, 
                                           parameter::plain<file_player12_t<NV>, 3>>;

template <int NV>
using pma_unscaled5_t = control::pma_unscaled<NV, pma_unscaled5_mod<NV>>;
template <int NV>
using minmax5_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled5_t<NV>, 2>>;

template <int NV>
using file_player4_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<4>>;
template <int NV>
using file_player13_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<12>>;

template <int NV>
using pma_unscaled4_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player4_t<NV>, 3>, 
                                           parameter::plain<file_player13_t<NV>, 3>>;

template <int NV>
using pma_unscaled4_t = control::pma_unscaled<NV, pma_unscaled4_mod<NV>>;
template <int NV>
using minmax4_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled4_t<NV>, 2>>;

template <int NV>
using file_player3_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<5>>;
template <int NV>
using file_player14_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<13>>;

template <int NV>
using pma_unscaled3_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player3_t<NV>, 3>, 
                                           parameter::plain<file_player14_t<NV>, 3>>;

template <int NV>
using pma_unscaled3_t = control::pma_unscaled<NV, pma_unscaled3_mod<NV>>;
template <int NV>
using minmax3_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled3_t<NV>, 2>>;

template <int NV>
using file_player2_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<6>>;
template <int NV>
using file_player15_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<14>>;

template <int NV>
using pma_unscaled2_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player2_t<NV>, 3>, 
                                           parameter::plain<file_player15_t<NV>, 3>>;

template <int NV>
using pma_unscaled2_t = control::pma_unscaled<NV, pma_unscaled2_mod<NV>>;
template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled2_t<NV>, 2>>;

template <int NV>
using file_player1_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<7>>;
template <int NV>
using file_player8_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<15>>;

template <int NV>
using pma_unscaled1_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player1_t<NV>, 3>, 
                                           parameter::plain<file_player8_t<NV>, 3>>;

template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, pma_unscaled1_mod<NV>>;
template <int NV>
using minmax1_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled1_t<NV>, 2>>;
template <int NV>
using harm_multimod = parameter::list<parameter::plain<minmax_t<NV>, 0>, 
                                      parameter::plain<minmax7_t<NV>, 0>, 
                                      parameter::plain<minmax6_t<NV>, 0>, 
                                      parameter::plain<minmax5_t<NV>, 0>, 
                                      parameter::plain<minmax4_t<NV>, 0>, 
                                      parameter::plain<minmax3_t<NV>, 0>, 
                                      parameter::plain<minmax2_t<NV>, 0>, 
                                      parameter::plain<minmax1_t<NV>, 0>>;

template <int NV>
using harm_t = wrap::data<control::sliderbank<harm_multimod<NV>>, 
                          data::external::sliderpack<0>>;

DECLARE_PARAMETER_RANGE_SKEW(cut_c0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using cut_c0 = parameter::from0To1<filters::svf<NV>, 
                                   0, 
                                   cut_c0Range>;

template <int NV> using cut_c1 = cut_c0<NV>;

template <int NV> using cut_c2 = cut_c0<NV>;

template <int NV> using cut_c3 = cut_c0<NV>;

template <int NV> using cut_c4 = cut_c0<NV>;

template <int NV> using cut_c5 = cut_c0<NV>;

template <int NV> using cut_c6 = cut_c0<NV>;

template <int NV> using cut_c7 = cut_c0<NV>;

template <int NV>
using cut_multimod = parameter::list<cut_c0<NV>, 
                                     cut_c1<NV>, 
                                     cut_c2<NV>, 
                                     cut_c3<NV>, 
                                     cut_c4<NV>, 
                                     cut_c5<NV>, 
                                     cut_c6<NV>, 
                                     cut_c7<NV>>;

template <int NV>
using cut_t = wrap::data<control::sliderbank<cut_multimod<NV>>, 
                         data::external::sliderpack<1>>;

DECLARE_PARAMETER_RANGE(pan_c0Range, 
                        -1., 
                        1.);

template <int NV>
using pan_c0 = parameter::from0To1<jdsp::jpanner<NV>, 
                                   0, 
                                   pan_c0Range>;

template <int NV> using pan_c1 = pan_c0<NV>;

template <int NV> using pan_c2 = pan_c0<NV>;

template <int NV> using pan_c3 = pan_c0<NV>;

template <int NV> using pan_c4 = pan_c0<NV>;

template <int NV> using pan_c5 = pan_c0<NV>;

template <int NV> using pan_c6 = pan_c0<NV>;

template <int NV> using pan_c7 = pan_c0<NV>;

template <int NV>
using pan_multimod = parameter::list<pan_c0<NV>, 
                                     pan_c1<NV>, 
                                     pan_c2<NV>, 
                                     pan_c3<NV>, 
                                     pan_c4<NV>, 
                                     pan_c5<NV>, 
                                     pan_c6<NV>, 
                                     pan_c7<NV>>;

template <int NV>
using pan_t = wrap::data<control::sliderbank<pan_multimod<NV>>, 
                         data::external::sliderpack<2>>;

using vol_c0 = smoothed_parameter1_mod;

using vol_c1 = smoothed_parameter1_mod;

using vol_c2 = smoothed_parameter1_mod;

using vol_c3 = smoothed_parameter1_mod;

using vol_c4 = smoothed_parameter1_mod;

using vol_c5 = smoothed_parameter1_mod;

using vol_c6 = smoothed_parameter1_mod;

using vol_c7 = smoothed_parameter1_mod;

using vol_multimod = parameter::list<vol_c0, 
                                     vol_c1, 
                                     vol_c2, 
                                     vol_c3, 
                                     vol_c4, 
                                     vol_c5, 
                                     vol_c6, 
                                     vol_c7>;

using vol_t = wrap::data<control::sliderbank<vol_multimod>, 
                         data::external::sliderpack<3>>;

template <int NV>
using pitch_multimod = parameter::list<parameter::plain<pma_unscaled_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled7_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled6_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled5_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled4_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled3_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled2_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled1_t<NV>, 0>>;

template <int NV>
using pitch_t = wrap::data<control::sliderbank<pitch_multimod<NV>>, 
                           data::external::sliderpack<4>>;

using dry_wet_mixer7_c0 = smoothed_parameter1_mod;

using dry_wet_mixer7_c1 = smoothed_parameter1_mod;

using dry_wet_mixer7_multimod = parameter::list<dry_wet_mixer7_c0, dry_wet_mixer7_c1>;

using dry_wet_mixer7_t = control::xfader<dry_wet_mixer7_multimod, 
                                         faders::linear>;

using dry_wet_mixer4_c0 = smoothed_parameter1_mod;

using dry_wet_mixer4_c1 = smoothed_parameter1_mod;

using dry_wet_mixer4_multimod = parameter::list<dry_wet_mixer4_c0, dry_wet_mixer4_c1>;

using dry_wet_mixer4_t = control::xfader<dry_wet_mixer4_multimod, 
                                         faders::linear>;

using dry_wet_mixer5_c0 = smoothed_parameter1_mod;

using dry_wet_mixer5_c1 = smoothed_parameter1_mod;

using dry_wet_mixer5_multimod = parameter::list<dry_wet_mixer5_c0, dry_wet_mixer5_c1>;

using dry_wet_mixer5_t = control::xfader<dry_wet_mixer5_multimod, 
                                         faders::linear>;

using dry_wet_mixer6_c0 = smoothed_parameter1_mod;

using dry_wet_mixer6_c1 = smoothed_parameter1_mod;

using dry_wet_mixer6_multimod = parameter::list<dry_wet_mixer6_c0, dry_wet_mixer6_c1>;

using dry_wet_mixer6_t = control::xfader<dry_wet_mixer6_multimod, 
                                         faders::linear>;

using dry_wet_mixer3_c0 = smoothed_parameter1_mod;

using dry_wet_mixer3_c1 = smoothed_parameter1_mod;

using dry_wet_mixer3_multimod = parameter::list<dry_wet_mixer3_c0, dry_wet_mixer3_c1>;

using dry_wet_mixer3_t = control::xfader<dry_wet_mixer3_multimod, 
                                         faders::linear>;

using dry_wet_mixer2_c0 = smoothed_parameter1_mod;

using dry_wet_mixer2_c1 = smoothed_parameter1_mod;

using dry_wet_mixer2_multimod = parameter::list<dry_wet_mixer2_c0, dry_wet_mixer2_c1>;

using dry_wet_mixer2_t = control::xfader<dry_wet_mixer2_multimod, 
                                         faders::linear>;

using dry_wet_mixer_c0 = smoothed_parameter1_mod;

using dry_wet_mixer_c1 = smoothed_parameter1_mod;

using dry_wet_mixer_multimod = parameter::list<dry_wet_mixer_c0, dry_wet_mixer_c1>;

using dry_wet_mixer_t = control::xfader<dry_wet_mixer_multimod, faders::linear>;

using dry_wet_mixer1_c0 = smoothed_parameter1_mod;

using dry_wet_mixer1_c1 = smoothed_parameter1_mod;

using dry_wet_mixer1_multimod = parameter::list<dry_wet_mixer1_c0, dry_wet_mixer1_c1>;

using dry_wet_mixer1_t = control::xfader<dry_wet_mixer1_multimod, 
                                         faders::linear>;

using cutmix_c0 = parameter::chain<ranges::Identity, 
                                   parameter::plain<dry_wet_mixer7_t, 0>, 
                                   parameter::plain<dry_wet_mixer4_t, 0>, 
                                   parameter::plain<dry_wet_mixer5_t, 0>, 
                                   parameter::plain<dry_wet_mixer6_t, 0>, 
                                   parameter::plain<dry_wet_mixer3_t, 0>, 
                                   parameter::plain<dry_wet_mixer2_t, 0>, 
                                   parameter::plain<dry_wet_mixer_t, 0>, 
                                   parameter::plain<dry_wet_mixer1_t, 0>>;

using cutmix_multimod = parameter::list<cutmix_c0, parameter::empty>;

using cutmix_t = wrap::data<control::sliderbank<cutmix_multimod>, 
                            data::external::sliderpack<6>>;

template <int NV>
using sb6_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player_t<NV>>>;

template <int NV>
using sb6_t = bypass::smoothed<20, sb6_t_<NV>>;
template <int NV>
using switcher2_c0 = parameter::bypass<sb6_t<NV>>;

template <int NV>
using file_player9_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<8>>;

template <int NV>
using sb7_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player9_t<NV>>>;

template <int NV>
using sb7_t = bypass::smoothed<20, sb7_t_<NV>>;
template <int NV>
using switcher2_c1 = parameter::bypass<sb7_t<NV>>;

template <int NV>
using switcher2_multimod = parameter::list<switcher2_c0<NV>, switcher2_c1<NV>>;

template <int NV>
using switcher2_t = control::xfader<switcher2_multimod<NV>, faders::switcher>;

template <int NV>
using sb8_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player7_t<NV>>>;

template <int NV>
using sb8_t = bypass::smoothed<20, sb8_t_<NV>>;
template <int NV>
using switcher3_c0 = parameter::bypass<sb8_t<NV>>;

template <int NV>
using sb9_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player10_t<NV>>>;

template <int NV>
using sb9_t = bypass::smoothed<20, sb9_t_<NV>>;
template <int NV>
using switcher3_c1 = parameter::bypass<sb9_t<NV>>;

template <int NV>
using switcher3_multimod = parameter::list<switcher3_c0<NV>, switcher3_c1<NV>>;

template <int NV>
using switcher3_t = control::xfader<switcher3_multimod<NV>, faders::switcher>;

template <int NV>
using sb10_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player6_t<NV>>>;

template <int NV>
using sb10_t = bypass::smoothed<20, sb10_t_<NV>>;
template <int NV>
using switcher4_c0 = parameter::bypass<sb10_t<NV>>;

template <int NV>
using sb11_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player11_t<NV>>>;

template <int NV>
using sb11_t = bypass::smoothed<20, sb11_t_<NV>>;
template <int NV>
using switcher4_c1 = parameter::bypass<sb11_t<NV>>;

template <int NV>
using switcher4_multimod = parameter::list<switcher4_c0<NV>, switcher4_c1<NV>>;

template <int NV>
using switcher4_t = control::xfader<switcher4_multimod<NV>, faders::switcher>;

template <int NV>
using sb12_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player5_t<NV>>>;

template <int NV>
using sb12_t = bypass::smoothed<20, sb12_t_<NV>>;
template <int NV>
using switcher5_c0 = parameter::bypass<sb12_t<NV>>;

template <int NV>
using sb13_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player12_t<NV>>>;

template <int NV>
using sb13_t = bypass::smoothed<20, sb13_t_<NV>>;
template <int NV>
using switcher5_c1 = parameter::bypass<sb13_t<NV>>;

template <int NV>
using switcher5_multimod = parameter::list<switcher5_c0<NV>, switcher5_c1<NV>>;

template <int NV>
using switcher5_t = control::xfader<switcher5_multimod<NV>, faders::switcher>;

template <int NV>
using sb14_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player4_t<NV>>>;

template <int NV>
using sb14_t = bypass::smoothed<20, sb14_t_<NV>>;
template <int NV>
using switcher6_c0 = parameter::bypass<sb14_t<NV>>;

template <int NV>
using sb15_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player13_t<NV>>>;

template <int NV>
using sb15_t = bypass::smoothed<20, sb15_t_<NV>>;
template <int NV>
using switcher6_c1 = parameter::bypass<sb15_t<NV>>;

template <int NV>
using switcher6_multimod = parameter::list<switcher6_c0<NV>, switcher6_c1<NV>>;

template <int NV>
using switcher6_t = control::xfader<switcher6_multimod<NV>, faders::switcher>;

template <int NV>
using sb16_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player3_t<NV>>>;

template <int NV>
using sb16_t = bypass::smoothed<20, sb16_t_<NV>>;
template <int NV>
using switcher7_c0 = parameter::bypass<sb16_t<NV>>;

template <int NV>
using sb17_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player14_t<NV>>>;

template <int NV>
using sb17_t = bypass::smoothed<20, sb17_t_<NV>>;
template <int NV>
using switcher7_c1 = parameter::bypass<sb17_t<NV>>;

template <int NV>
using switcher7_multimod = parameter::list<switcher7_c0<NV>, switcher7_c1<NV>>;

template <int NV>
using switcher7_t = control::xfader<switcher7_multimod<NV>, faders::switcher>;

template <int NV>
using sb18_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player2_t<NV>>>;

template <int NV>
using sb18_t = bypass::smoothed<20, sb18_t_<NV>>;
template <int NV>
using switcher8_c0 = parameter::bypass<sb18_t<NV>>;

template <int NV>
using sb19_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player15_t<NV>>>;

template <int NV>
using sb19_t = bypass::smoothed<20, sb19_t_<NV>>;
template <int NV>
using switcher8_c1 = parameter::bypass<sb19_t<NV>>;

template <int NV>
using switcher8_multimod = parameter::list<switcher8_c0<NV>, switcher8_c1<NV>>;

template <int NV>
using switcher8_t = control::xfader<switcher8_multimod<NV>, faders::switcher>;

template <int NV>
using sb4_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player1_t<NV>>>;

template <int NV>
using sb4_t = bypass::smoothed<20, sb4_t_<NV>>;
template <int NV>
using switcher1_c0 = parameter::bypass<sb4_t<NV>>;

template <int NV>
using sb5_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player8_t<NV>>>;

template <int NV>
using sb5_t = bypass::smoothed<20, sb5_t_<NV>>;
template <int NV>
using switcher1_c1 = parameter::bypass<sb5_t<NV>>;

template <int NV>
using switcher1_multimod = parameter::list<switcher1_c0<NV>, switcher1_c1<NV>>;

template <int NV>
using switcher1_t = control::xfader<switcher1_multimod<NV>, faders::switcher>;
template <int NV>
using SFZ_multimod = parameter::list<parameter::plain<switcher2_t<NV>, 0>, 
                                     parameter::plain<switcher3_t<NV>, 0>, 
                                     parameter::plain<switcher4_t<NV>, 0>, 
                                     parameter::plain<switcher5_t<NV>, 0>, 
                                     parameter::plain<switcher6_t<NV>, 0>, 
                                     parameter::plain<switcher7_t<NV>, 0>, 
                                     parameter::plain<switcher8_t<NV>, 0>, 
                                     parameter::plain<switcher1_t<NV>, 0>>;

template <int NV>
using SFZ_t = wrap::data<control::sliderbank<SFZ_multimod<NV>>, 
                         data::external::sliderpack<11>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, harm_t<NV>>, 
                                  cut_t<NV>, 
                                  pan_t<NV>, 
                                  vol_t, 
                                  pitch_t<NV>, 
                                  cutmix_t, 
                                  SFZ_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain10_t<NV>>, 
                                  split2_t<NV>, 
                                  math::clear<NV>>;

template <int NV>
using sb_container2_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb6_t<NV>>, 
                                         sb7_t<NV>>;

template <int NV>
using softbypass_switch5_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher2_t<NV>>, 
                                              sb_container2_t<NV>>;

using dry_path1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer1_t>, 
                                     core::gain>;

template <int NV>
using wet_path1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, filters::svf<NV>>, 
                                     core::gain>;

template <int NV>
using dry_wet2_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path1_t>, 
                                    wet_path1_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, minmax_t<NV>>, 
                                 pma_unscaled_t<NV>, 
                                 softbypass_switch5_t<NV>, 
                                 dry_wet2_t<NV>, 
                                 pma_t<NV>, 
                                 jdsp::jpanner<NV>, 
                                 core::gain, 
                                 smoothed_parameter1_t<NV>, 
                                 core::gain>;

template <int NV>
using sb_container3_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb8_t<NV>>, 
                                         sb9_t<NV>>;

template <int NV>
using softbypass_switch6_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher3_t<NV>>, 
                                              sb_container3_t<NV>>;

using dry_path2_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer2_t>, 
                                     core::gain>;

template <int NV> using wet_path2_t = wet_path1_t<NV>;

template <int NV>
using dry_wet3_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path2_t>, 
                                    wet_path2_t<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax7_t<NV>>, 
                                  pma_unscaled7_t<NV>, 
                                  softbypass_switch6_t<NV>, 
                                  dry_wet3_t<NV>, 
                                  pma2_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter2_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container4_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb10_t<NV>>, 
                                         sb11_t<NV>>;

template <int NV>
using softbypass_switch7_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher4_t<NV>>, 
                                              sb_container4_t<NV>>;

using dry_path3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer3_t>, 
                                     core::gain>;

template <int NV> using wet_path3_t = wet_path1_t<NV>;

template <int NV>
using dry_wet4_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path3_t>, 
                                    wet_path3_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax6_t<NV>>, 
                                  pma_unscaled6_t<NV>, 
                                  softbypass_switch7_t<NV>, 
                                  dry_wet4_t<NV>, 
                                  pma3_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter3_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container5_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb12_t<NV>>, 
                                         sb13_t<NV>>;

template <int NV>
using softbypass_switch8_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher5_t<NV>>, 
                                              sb_container5_t<NV>>;

using dry_path7_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer7_t>, 
                                     core::gain>;

template <int NV> using wet_path7_t = wet_path1_t<NV>;

template <int NV>
using dry_wet8_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path7_t>, 
                                    wet_path7_t<NV>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax5_t<NV>>, 
                                  pma_unscaled5_t<NV>, 
                                  softbypass_switch8_t<NV>, 
                                  dry_wet8_t<NV>, 
                                  pma4_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter4_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container6_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb14_t<NV>>, 
                                         sb15_t<NV>>;

template <int NV>
using softbypass_switch9_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher6_t<NV>>, 
                                              sb_container6_t<NV>>;

using dry_path4_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer4_t>, 
                                     core::gain>;

template <int NV> using wet_path4_t = wet_path1_t<NV>;

template <int NV>
using dry_wet5_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path4_t>, 
                                    wet_path4_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax4_t<NV>>, 
                                  pma_unscaled4_t<NV>, 
                                  softbypass_switch9_t<NV>, 
                                  dry_wet5_t<NV>, 
                                  pma5_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container7_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb16_t<NV>>, 
                                         sb17_t<NV>>;

template <int NV>
using softbypass_switch10_t = container::chain<parameter::empty, 
                                               wrap::fix<2, switcher7_t<NV>>, 
                                               sb_container7_t<NV>>;

using dry_path5_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer5_t>, 
                                     core::gain>;

template <int NV> using wet_path5_t = wet_path1_t<NV>;

template <int NV>
using dry_wet6_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path5_t>, 
                                    wet_path5_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax3_t<NV>>, 
                                  pma_unscaled3_t<NV>, 
                                  softbypass_switch10_t<NV>, 
                                  dry_wet6_t<NV>, 
                                  pma6_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter5_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container8_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb18_t<NV>>, 
                                         sb19_t<NV>>;

template <int NV>
using softbypass_switch11_t = container::chain<parameter::empty, 
                                               wrap::fix<2, switcher8_t<NV>>, 
                                               sb_container8_t<NV>>;

using dry_path6_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer6_t>, 
                                     core::gain>;

template <int NV> using wet_path6_t = wet_path1_t<NV>;

template <int NV>
using dry_wet7_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path6_t>, 
                                    wet_path6_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax2_t<NV>>, 
                                  pma_unscaled2_t<NV>, 
                                  softbypass_switch11_t<NV>, 
                                  dry_wet7_t<NV>, 
                                  pma7_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  smoothed_parameter7_t<NV>, 
                                  core::gain, 
                                  core::gain>;

template <int NV>
using sb_container1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb4_t<NV>>, 
                                         sb5_t<NV>>;

template <int NV>
using softbypass_switch3_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher1_t<NV>>, 
                                              sb_container1_t<NV>>;

using dry_path_t = container::chain<parameter::empty, 
                                    wrap::fix<2, dry_wet_mixer_t>, 
                                    core::gain>;

template <int NV> using wet_path_t = wet_path1_t<NV>;

template <int NV>
using dry_wet1_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path_t>, 
                                    wet_path_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax1_t<NV>>, 
                                  pma_unscaled1_t<NV>, 
                                  softbypass_switch3_t<NV>, 
                                  dry_wet1_t<NV>, 
                                  pma1_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  smoothed_parameter6_t<NV>, 
                                  core::gain, 
                                  core::gain>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain7_t<NV>, 
                                 chain6_t<NV>, 
                                 chain5_t<NV>, 
                                 chain4_t<NV>, 
                                 chain3_t<NV>, 
                                 chain2_t<NV>, 
                                 chain1_t<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain8_t<NV>>, 
                                  split_t<NV>>;

namespace HarmFade_t_parameters
{
// Parameter list for HarmFade_impl::HarmFade_t ----------------------------------------------------

template <int NV>
using xfinput = parameter::chain<ranges::Identity, 
                                 parameter::plain<HarmFade_impl::input_toggle_t<NV>, 0>, 
                                 parameter::plain<HarmFade_impl::input_toggle1_t<NV>, 0>, 
                                 parameter::plain<HarmFade_impl::input_toggle3_t<NV>, 0>, 
                                 parameter::plain<HarmFade_impl::input_toggle4_t<NV>, 0>, 
                                 parameter::plain<HarmFade_impl::input_toggle5_t<NV>, 0>, 
                                 parameter::plain<HarmFade_impl::input_toggle6_t<NV>, 0>, 
                                 parameter::plain<HarmFade_impl::input_toggle7_t<NV>, 0>, 
                                 parameter::plain<HarmFade_impl::input_toggle2_t<NV>, 0>>;

template <int NV>
using xfade = parameter::chain<ranges::Identity, 
                               parameter::plain<HarmFade_impl::xfader3_t<NV>, 0>, 
                               parameter::plain<HarmFade_impl::xfader_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(smooth_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_STEP(smooth_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth_0 = parameter::from0To1<HarmFade_impl::smoothed_parameter1_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_1 = parameter::from0To1<HarmFade_impl::smoothed_parameter2_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_2 = parameter::from0To1<HarmFade_impl::smoothed_parameter3_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_3 = parameter::from0To1<HarmFade_impl::smoothed_parameter4_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_4 = parameter::from0To1<HarmFade_impl::smoothed_parameter_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_5 = parameter::from0To1<HarmFade_impl::smoothed_parameter5_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_6 = parameter::from0To1<HarmFade_impl::smoothed_parameter7_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_7 = parameter::from0To1<HarmFade_impl::smoothed_parameter6_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth = parameter::chain<smooth_InputRange, 
                                smooth_0<NV>, 
                                smooth_1<NV>, 
                                smooth_2<NV>, 
                                smooth_3<NV>, 
                                smooth_4<NV>, 
                                smooth_5<NV>, 
                                smooth_6<NV>, 
                                smooth_7<NV>>;

template <int NV>
using min = parameter::chain<ranges::Identity, 
                             parameter::plain<HarmFade_impl::minmax7_t<NV>, 1>, 
                             parameter::plain<HarmFade_impl::minmax6_t<NV>, 1>, 
                             parameter::plain<HarmFade_impl::minmax5_t<NV>, 1>, 
                             parameter::plain<HarmFade_impl::minmax4_t<NV>, 1>, 
                             parameter::plain<HarmFade_impl::minmax3_t<NV>, 1>, 
                             parameter::plain<HarmFade_impl::minmax2_t<NV>, 1>, 
                             parameter::plain<HarmFade_impl::minmax1_t<NV>, 1>, 
                             parameter::plain<HarmFade_impl::minmax_t<NV>, 1>>;

template <int NV>
using max = parameter::chain<ranges::Identity, 
                             parameter::plain<HarmFade_impl::minmax7_t<NV>, 2>, 
                             parameter::plain<HarmFade_impl::minmax6_t<NV>, 2>, 
                             parameter::plain<HarmFade_impl::minmax5_t<NV>, 2>, 
                             parameter::plain<HarmFade_impl::minmax4_t<NV>, 2>, 
                             parameter::plain<HarmFade_impl::minmax3_t<NV>, 2>, 
                             parameter::plain<HarmFade_impl::minmax2_t<NV>, 2>, 
                             parameter::plain<HarmFade_impl::minmax1_t<NV>, 2>, 
                             parameter::plain<HarmFade_impl::minmax_t<NV>, 2>>;

template <int NV>
using step = parameter::chain<ranges::Identity, 
                              parameter::plain<HarmFade_impl::minmax7_t<NV>, 4>, 
                              parameter::plain<HarmFade_impl::minmax6_t<NV>, 4>, 
                              parameter::plain<HarmFade_impl::minmax5_t<NV>, 4>, 
                              parameter::plain<HarmFade_impl::minmax4_t<NV>, 4>, 
                              parameter::plain<HarmFade_impl::minmax3_t<NV>, 4>, 
                              parameter::plain<HarmFade_impl::minmax2_t<NV>, 4>, 
                              parameter::plain<HarmFade_impl::minmax1_t<NV>, 4>, 
                              parameter::plain<HarmFade_impl::minmax_t<NV>, 4>>;

template <int NV>
using res = parameter::chain<ranges::Identity, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>>;

DECLARE_PARAMETER_RANGE_SKEW(ftype_InputRange, 
                             0., 
                             5., 
                             0.968275);
DECLARE_PARAMETER_RANGE_STEP(ftype_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using ftype_0 = parameter::from0To1<filters::svf<NV>, 
                                    4, 
                                    ftype_0Range>;

template <int NV> using ftype_1 = ftype_0<NV>;

template <int NV> using ftype_2 = ftype_0<NV>;

template <int NV> using ftype_3 = ftype_0<NV>;

template <int NV> using ftype_4 = ftype_0<NV>;

template <int NV> using ftype_5 = ftype_0<NV>;

template <int NV> using ftype_6 = ftype_0<NV>;

template <int NV> using ftype_7 = ftype_0<NV>;

template <int NV>
using ftype = parameter::chain<ftype_InputRange, 
                               ftype_0<NV>, 
                               ftype_1<NV>, 
                               ftype_2<NV>, 
                               ftype_3<NV>, 
                               ftype_4<NV>, 
                               ftype_5<NV>, 
                               ftype_6<NV>, 
                               ftype_7<NV>>;

template <int NV>
using pitch1 = parameter::plain<HarmFade_impl::pitch_t<NV>, 
                                0>;
template <int NV>
using harmoffset = parameter::plain<HarmFade_impl::harm_t<NV>, 
                                    0>;
template <int NV>
using cutoffset = parameter::plain<HarmFade_impl::cut_t<NV>, 
                                   0>;
using gainofset = parameter::plain<HarmFade_impl::vol_t, 0>;
template <int NV>
using panoffset = parameter::plain<HarmFade_impl::pan_t<NV>, 
                                   0>;
template <int NV>
using HarmFade_t_plist = parameter::list<xfinput<NV>, 
                                         xfade<NV>, 
                                         smooth<NV>, 
                                         pitch1<NV>, 
                                         harmoffset<NV>, 
                                         min<NV>, 
                                         max<NV>, 
                                         step<NV>, 
                                         cutoffset<NV>, 
                                         res<NV>, 
                                         ftype<NV>, 
                                         gainofset, 
                                         panoffset<NV>>;
}

template <int NV>
using HarmFade_t_ = container::chain<HarmFade_t_parameters::HarmFade_t_plist<NV>, 
                                     wrap::fix<2, chain9_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public HarmFade_impl::HarmFade_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 12;
		static const int NumAudioFiles = 16;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(HarmFade);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(210)
		{
			0x005B, 0x0000, 0x7800, 0x6966, 0x706E, 0x7475, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0001, 0x0000, 0x6678, 0x6461, 0x0065, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x025B, 0x0000, 0x7300, 0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 
            0x0000, 0x447A, 0x0000, 0x0000, 0x209B, 0x3E9A, 0xCCCD, 0x3DCC, 
            0x035B, 0x0000, 0x7000, 0x7469, 0x6863, 0x0031, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x045B, 0x0000, 0x6800, 0x7261, 0x6F6D, 0x6666, 0x6573, 0x0074, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x055B, 0x0000, 0x6D00, 0x6E69, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0006, 0x0000, 0x616D, 0x0078, 0x0000, 0x3F80, 0x0000, 
            0x4180, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x075B, 
            0x0000, 0x7300, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 
            0x6300, 0x7475, 0x666F, 0x7366, 0x7465, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x5B3F, 0x3DDD, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0009, 0x0000, 0x6572, 0x0073, 0x999A, 0x3E99, 0x6666, 0x411E, 
            0x0000, 0x3F80, 0x8918, 0x3E87, 0x0000, 0x0000, 0x0A5B, 0x0000, 
            0x6600, 0x7974, 0x6570, 0x0000, 0x0000, 0x0000, 0xA000, 0x0040, 
            0x0000, 0xD900, 0x77E0, 0x003F, 0x0000, 0x5B00, 0x000B, 0x0000, 
            0x6167, 0x6E69, 0x666F, 0x6573, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0C5B, 
            0x0000, 0x7000, 0x6E61, 0x666F, 0x7366, 0x7465, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x563F, 0xDDFE, 0x003E, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain9 = this->getT(0);                                                        // HarmFade_impl::chain9_t<NV>
		auto& chain8 = this->getT(0).getT(0);                                                // HarmFade_impl::chain8_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0);                                       // HarmFade_impl::chain10_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(0).getT(0);                               // HarmFade_impl::chain11_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                        // HarmFade_impl::split1_t<NV>
		auto& xfader = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);                // HarmFade_impl::xfader_t<NV>
		auto& xfader3 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);               // HarmFade_impl::xfader3_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                        // HarmFade_impl::split4_t<NV>
		auto& input_toggle = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);          // HarmFade_impl::input_toggle_t<NV>
		auto& input_toggle1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);         // HarmFade_impl::input_toggle1_t<NV>
		auto& input_toggle2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);         // HarmFade_impl::input_toggle2_t<NV>
		auto& input_toggle3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);         // HarmFade_impl::input_toggle3_t<NV>
		auto& input_toggle4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4);         // HarmFade_impl::input_toggle4_t<NV>
		auto& input_toggle5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5);         // HarmFade_impl::input_toggle5_t<NV>
		auto& input_toggle6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6);         // HarmFade_impl::input_toggle6_t<NV>
		auto& input_toggle7 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7);         // HarmFade_impl::input_toggle7_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(1);                                        // HarmFade_impl::split2_t<NV>
		auto& harm = this->getT(0).getT(0).getT(1).getT(0);                                  // HarmFade_impl::harm_t<NV>
		auto& cut = this->getT(0).getT(0).getT(1).getT(1);                                   // HarmFade_impl::cut_t<NV>
		auto& pan = this->getT(0).getT(0).getT(1).getT(2);                                   // HarmFade_impl::pan_t<NV>
		auto& vol = this->getT(0).getT(0).getT(1).getT(3);                                   // HarmFade_impl::vol_t
		auto& pitch = this->getT(0).getT(0).getT(1).getT(4);                                 // HarmFade_impl::pitch_t<NV>
		auto& cutmix = this->getT(0).getT(0).getT(1).getT(5);                                // HarmFade_impl::cutmix_t
		auto& SFZ = this->getT(0).getT(0).getT(1).getT(6);                                   // HarmFade_impl::SFZ_t<NV>
		auto& clear = this->getT(0).getT(0).getT(2);                                         // math::clear<NV>
		auto& split = this->getT(0).getT(1);                                                 // HarmFade_impl::split_t<NV>
		auto& chain = this->getT(0).getT(1).getT(0);                                         // HarmFade_impl::chain_t<NV>
		auto& minmax = this->getT(0).getT(1).getT(0).getT(0);                                // HarmFade_impl::minmax_t<NV>
		auto& pma_unscaled = this->getT(0).getT(1).getT(0).getT(1);                          // HarmFade_impl::pma_unscaled_t<NV>
		auto& softbypass_switch5 = this->getT(0).getT(1).getT(0).getT(2);                    // HarmFade_impl::softbypass_switch5_t<NV>
		auto& switcher2 = this->getT(0).getT(1).getT(0).getT(2).getT(0);                     // HarmFade_impl::switcher2_t<NV>
		auto& sb_container2 = this->getT(0).getT(1).getT(0).getT(2).getT(1);                 // HarmFade_impl::sb_container2_t<NV>
		auto& sb6 = this->getT(0).getT(1).getT(0).getT(2).getT(1).getT(0);                   // HarmFade_impl::sb6_t<NV>
		auto& file_player = this->getT(0).getT(1).getT(0).getT(2).getT(1).getT(0).getT(0);   // HarmFade_impl::file_player_t<NV>
		auto& sb7 = this->getT(0).getT(1).getT(0).getT(2).getT(1).getT(1);                   // HarmFade_impl::sb7_t<NV>
		auto& file_player9 = this->getT(0).getT(1).getT(0).getT(2).getT(1).getT(1).getT(0);  // HarmFade_impl::file_player9_t<NV>
		auto& dry_wet2 = this->getT(0).getT(1).getT(0).getT(3);                              // HarmFade_impl::dry_wet2_t<NV>
		auto& dry_path1 = this->getT(0).getT(1).getT(0).getT(3).getT(0);                     // HarmFade_impl::dry_path1_t
		auto& dry_wet_mixer1 = this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(0);        // HarmFade_impl::dry_wet_mixer1_t
		auto& dry_gain1 = this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(1);             // core::gain
		auto& wet_path1 = this->getT(0).getT(1).getT(0).getT(3).getT(1);                     // HarmFade_impl::wet_path1_t<NV>
		auto& svf = this->getT(0).getT(1).getT(0).getT(3).getT(1).getT(0);                   // filters::svf<NV>
		auto& wet_gain1 = this->getT(0).getT(1).getT(0).getT(3).getT(1).getT(1);             // core::gain
		auto& pma = this->getT(0).getT(1).getT(0).getT(4);                                   // HarmFade_impl::pma_t<NV>
		auto& jpanner1 = this->getT(0).getT(1).getT(0).getT(5);                              // jdsp::jpanner<NV>
		auto& gain8 = this->getT(0).getT(1).getT(0).getT(6);                                 // core::gain
		auto& smoothed_parameter1 = this->getT(0).getT(1).getT(0).getT(7);                   // HarmFade_impl::smoothed_parameter1_t<NV>
		auto& gain = this->getT(0).getT(1).getT(0).getT(8);                                  // core::gain
		auto& chain7 = this->getT(0).getT(1).getT(1);                                        // HarmFade_impl::chain7_t<NV>
		auto& minmax7 = this->getT(0).getT(1).getT(1).getT(0);                               // HarmFade_impl::minmax7_t<NV>
		auto& pma_unscaled7 = this->getT(0).getT(1).getT(1).getT(1);                         // HarmFade_impl::pma_unscaled7_t<NV>
		auto& softbypass_switch6 = this->getT(0).getT(1).getT(1).getT(2);                    // HarmFade_impl::softbypass_switch6_t<NV>
		auto& switcher3 = this->getT(0).getT(1).getT(1).getT(2).getT(0);                     // HarmFade_impl::switcher3_t<NV>
		auto& sb_container3 = this->getT(0).getT(1).getT(1).getT(2).getT(1);                 // HarmFade_impl::sb_container3_t<NV>
		auto& sb8 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0);                   // HarmFade_impl::sb8_t<NV>
		auto& file_player7 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(0);  // HarmFade_impl::file_player7_t<NV>
		auto& sb9 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(1);                   // HarmFade_impl::sb9_t<NV>
		auto& file_player10 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(1).getT(0); // HarmFade_impl::file_player10_t<NV>
		auto& dry_wet3 = this->getT(0).getT(1).getT(1).getT(3);                              // HarmFade_impl::dry_wet3_t<NV>
		auto& dry_path2 = this->getT(0).getT(1).getT(1).getT(3).getT(0);                     // HarmFade_impl::dry_path2_t
		auto& dry_wet_mixer2 = this->getT(0).getT(1).getT(1).getT(3).getT(0).getT(0);        // HarmFade_impl::dry_wet_mixer2_t
		auto& dry_gain2 = this->getT(0).getT(1).getT(1).getT(3).getT(0).getT(1);             // core::gain
		auto& wet_path2 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                     // HarmFade_impl::wet_path2_t<NV>
		auto& svf7 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0);                  // filters::svf<NV>
		auto& wet_gain2 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(1);             // core::gain
		auto& pma2 = this->getT(0).getT(1).getT(1).getT(4);                                  // HarmFade_impl::pma2_t<NV>
		auto& jpanner2 = this->getT(0).getT(1).getT(1).getT(5);                              // jdsp::jpanner<NV>
		auto& gain9 = this->getT(0).getT(1).getT(1).getT(6);                                 // core::gain
		auto& smoothed_parameter2 = this->getT(0).getT(1).getT(1).getT(7);                   // HarmFade_impl::smoothed_parameter2_t<NV>
		auto& gain7 = this->getT(0).getT(1).getT(1).getT(8);                                 // core::gain
		auto& chain6 = this->getT(0).getT(1).getT(2);                                        // HarmFade_impl::chain6_t<NV>
		auto& minmax6 = this->getT(0).getT(1).getT(2).getT(0);                               // HarmFade_impl::minmax6_t<NV>
		auto& pma_unscaled6 = this->getT(0).getT(1).getT(2).getT(1);                         // HarmFade_impl::pma_unscaled6_t<NV>
		auto& softbypass_switch7 = this->getT(0).getT(1).getT(2).getT(2);                    // HarmFade_impl::softbypass_switch7_t<NV>
		auto& switcher4 = this->getT(0).getT(1).getT(2).getT(2).getT(0);                     // HarmFade_impl::switcher4_t<NV>
		auto& sb_container4 = this->getT(0).getT(1).getT(2).getT(2).getT(1);                 // HarmFade_impl::sb_container4_t<NV>
		auto& sb10 = this->getT(0).getT(1).getT(2).getT(2).getT(1).getT(0);                  // HarmFade_impl::sb10_t<NV>
		auto& file_player6 = this->getT(0).getT(1).getT(2).getT(2).getT(1).getT(0).getT(0);  // HarmFade_impl::file_player6_t<NV>
		auto& sb11 = this->getT(0).getT(1).getT(2).getT(2).getT(1).getT(1);                  // HarmFade_impl::sb11_t<NV>
		auto& file_player11 = this->getT(0).getT(1).getT(2).getT(2).getT(1).getT(1).getT(0); // HarmFade_impl::file_player11_t<NV>
		auto& dry_wet4 = this->getT(0).getT(1).getT(2).getT(3);                              // HarmFade_impl::dry_wet4_t<NV>
		auto& dry_path3 = this->getT(0).getT(1).getT(2).getT(3).getT(0);                     // HarmFade_impl::dry_path3_t
		auto& dry_wet_mixer3 = this->getT(0).getT(1).getT(2).getT(3).getT(0).getT(0);        // HarmFade_impl::dry_wet_mixer3_t
		auto& dry_gain3 = this->getT(0).getT(1).getT(2).getT(3).getT(0).getT(1);             // core::gain
		auto& wet_path3 = this->getT(0).getT(1).getT(2).getT(3).getT(1);                     // HarmFade_impl::wet_path3_t<NV>
		auto& svf6 = this->getT(0).getT(1).getT(2).getT(3).getT(1).getT(0);                  // filters::svf<NV>
		auto& wet_gain3 = this->getT(0).getT(1).getT(2).getT(3).getT(1).getT(1);             // core::gain
		auto& pma3 = this->getT(0).getT(1).getT(2).getT(4);                                  // HarmFade_impl::pma3_t<NV>
		auto& jpanner3 = this->getT(0).getT(1).getT(2).getT(5);                              // jdsp::jpanner<NV>
		auto& gain10 = this->getT(0).getT(1).getT(2).getT(6);                                // core::gain
		auto& smoothed_parameter3 = this->getT(0).getT(1).getT(2).getT(7);                   // HarmFade_impl::smoothed_parameter3_t<NV>
		auto& gain6 = this->getT(0).getT(1).getT(2).getT(8);                                 // core::gain
		auto& chain5 = this->getT(0).getT(1).getT(3);                                        // HarmFade_impl::chain5_t<NV>
		auto& minmax5 = this->getT(0).getT(1).getT(3).getT(0);                               // HarmFade_impl::minmax5_t<NV>
		auto& pma_unscaled5 = this->getT(0).getT(1).getT(3).getT(1);                         // HarmFade_impl::pma_unscaled5_t<NV>
		auto& softbypass_switch8 = this->getT(0).getT(1).getT(3).getT(2);                    // HarmFade_impl::softbypass_switch8_t<NV>
		auto& switcher5 = this->getT(0).getT(1).getT(3).getT(2).getT(0);                     // HarmFade_impl::switcher5_t<NV>
		auto& sb_container5 = this->getT(0).getT(1).getT(3).getT(2).getT(1);                 // HarmFade_impl::sb_container5_t<NV>
		auto& sb12 = this->getT(0).getT(1).getT(3).getT(2).getT(1).getT(0);                  // HarmFade_impl::sb12_t<NV>
		auto& file_player5 = this->getT(0).getT(1).getT(3).getT(2).getT(1).getT(0).getT(0);  // HarmFade_impl::file_player5_t<NV>
		auto& sb13 = this->getT(0).getT(1).getT(3).getT(2).getT(1).getT(1);                  // HarmFade_impl::sb13_t<NV>
		auto& file_player12 = this->getT(0).getT(1).getT(3).getT(2).getT(1).getT(1).getT(0); // HarmFade_impl::file_player12_t<NV>
		auto& dry_wet8 = this->getT(0).getT(1).getT(3).getT(3);                              // HarmFade_impl::dry_wet8_t<NV>
		auto& dry_path7 = this->getT(0).getT(1).getT(3).getT(3).getT(0);                     // HarmFade_impl::dry_path7_t
		auto& dry_wet_mixer7 = this->getT(0).getT(1).getT(3).getT(3).getT(0).getT(0);        // HarmFade_impl::dry_wet_mixer7_t
		auto& dry_gain7 = this->getT(0).getT(1).getT(3).getT(3).getT(0).getT(1);             // core::gain
		auto& wet_path7 = this->getT(0).getT(1).getT(3).getT(3).getT(1);                     // HarmFade_impl::wet_path7_t<NV>
		auto& svf5 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(0);                  // filters::svf<NV>
		auto& wet_gain7 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(1);             // core::gain
		auto& pma4 = this->getT(0).getT(1).getT(3).getT(4);                                  // HarmFade_impl::pma4_t<NV>
		auto& jpanner4 = this->getT(0).getT(1).getT(3).getT(5);                              // jdsp::jpanner<NV>
		auto& gain11 = this->getT(0).getT(1).getT(3).getT(6);                                // core::gain
		auto& smoothed_parameter4 = this->getT(0).getT(1).getT(3).getT(7);                   // HarmFade_impl::smoothed_parameter4_t<NV>
		auto& gain5 = this->getT(0).getT(1).getT(3).getT(8);                                 // core::gain
		auto& chain4 = this->getT(0).getT(1).getT(4);                                        // HarmFade_impl::chain4_t<NV>
		auto& minmax4 = this->getT(0).getT(1).getT(4).getT(0);                               // HarmFade_impl::minmax4_t<NV>
		auto& pma_unscaled4 = this->getT(0).getT(1).getT(4).getT(1);                         // HarmFade_impl::pma_unscaled4_t<NV>
		auto& softbypass_switch9 = this->getT(0).getT(1).getT(4).getT(2);                    // HarmFade_impl::softbypass_switch9_t<NV>
		auto& switcher6 = this->getT(0).getT(1).getT(4).getT(2).getT(0);                     // HarmFade_impl::switcher6_t<NV>
		auto& sb_container6 = this->getT(0).getT(1).getT(4).getT(2).getT(1);                 // HarmFade_impl::sb_container6_t<NV>
		auto& sb14 = this->getT(0).getT(1).getT(4).getT(2).getT(1).getT(0);                  // HarmFade_impl::sb14_t<NV>
		auto& file_player4 = this->getT(0).getT(1).getT(4).getT(2).getT(1).getT(0).getT(0);  // HarmFade_impl::file_player4_t<NV>
		auto& sb15 = this->getT(0).getT(1).getT(4).getT(2).getT(1).getT(1);                  // HarmFade_impl::sb15_t<NV>
		auto& file_player13 = this->getT(0).getT(1).getT(4).getT(2).getT(1).getT(1).getT(0); // HarmFade_impl::file_player13_t<NV>
		auto& dry_wet5 = this->getT(0).getT(1).getT(4).getT(3);                              // HarmFade_impl::dry_wet5_t<NV>
		auto& dry_path4 = this->getT(0).getT(1).getT(4).getT(3).getT(0);                     // HarmFade_impl::dry_path4_t
		auto& dry_wet_mixer4 = this->getT(0).getT(1).getT(4).getT(3).getT(0).getT(0);        // HarmFade_impl::dry_wet_mixer4_t
		auto& dry_gain4 = this->getT(0).getT(1).getT(4).getT(3).getT(0).getT(1);             // core::gain
		auto& wet_path4 = this->getT(0).getT(1).getT(4).getT(3).getT(1);                     // HarmFade_impl::wet_path4_t<NV>
		auto& svf4 = this->getT(0).getT(1).getT(4).getT(3).getT(1).getT(0);                  // filters::svf<NV>
		auto& wet_gain4 = this->getT(0).getT(1).getT(4).getT(3).getT(1).getT(1);             // core::gain
		auto& pma5 = this->getT(0).getT(1).getT(4).getT(4);                                  // HarmFade_impl::pma5_t<NV>
		auto& jpanner5 = this->getT(0).getT(1).getT(4).getT(5);                              // jdsp::jpanner<NV>
		auto& gain12 = this->getT(0).getT(1).getT(4).getT(6);                                // core::gain
		auto& smoothed_parameter = this->getT(0).getT(1).getT(4).getT(7);                    // HarmFade_impl::smoothed_parameter_t<NV>
		auto& gain4 = this->getT(0).getT(1).getT(4).getT(8);                                 // core::gain
		auto& chain3 = this->getT(0).getT(1).getT(5);                                        // HarmFade_impl::chain3_t<NV>
		auto& minmax3 = this->getT(0).getT(1).getT(5).getT(0);                               // HarmFade_impl::minmax3_t<NV>
		auto& pma_unscaled3 = this->getT(0).getT(1).getT(5).getT(1);                         // HarmFade_impl::pma_unscaled3_t<NV>
		auto& softbypass_switch10 = this->getT(0).getT(1).getT(5).getT(2);                   // HarmFade_impl::softbypass_switch10_t<NV>
		auto& switcher7 = this->getT(0).getT(1).getT(5).getT(2).getT(0);                     // HarmFade_impl::switcher7_t<NV>
		auto& sb_container7 = this->getT(0).getT(1).getT(5).getT(2).getT(1);                 // HarmFade_impl::sb_container7_t<NV>
		auto& sb16 = this->getT(0).getT(1).getT(5).getT(2).getT(1).getT(0);                  // HarmFade_impl::sb16_t<NV>
		auto& file_player3 = this->getT(0).getT(1).getT(5).getT(2).getT(1).getT(0).getT(0);  // HarmFade_impl::file_player3_t<NV>
		auto& sb17 = this->getT(0).getT(1).getT(5).getT(2).getT(1).getT(1);                  // HarmFade_impl::sb17_t<NV>
		auto& file_player14 = this->getT(0).getT(1).getT(5).getT(2).getT(1).getT(1).getT(0); // HarmFade_impl::file_player14_t<NV>
		auto& dry_wet6 = this->getT(0).getT(1).getT(5).getT(3);                              // HarmFade_impl::dry_wet6_t<NV>
		auto& dry_path5 = this->getT(0).getT(1).getT(5).getT(3).getT(0);                     // HarmFade_impl::dry_path5_t
		auto& dry_wet_mixer5 = this->getT(0).getT(1).getT(5).getT(3).getT(0).getT(0);        // HarmFade_impl::dry_wet_mixer5_t
		auto& dry_gain5 = this->getT(0).getT(1).getT(5).getT(3).getT(0).getT(1);             // core::gain
		auto& wet_path5 = this->getT(0).getT(1).getT(5).getT(3).getT(1);                     // HarmFade_impl::wet_path5_t<NV>
		auto& svf3 = this->getT(0).getT(1).getT(5).getT(3).getT(1).getT(0);                  // filters::svf<NV>
		auto& wet_gain5 = this->getT(0).getT(1).getT(5).getT(3).getT(1).getT(1);             // core::gain
		auto& pma6 = this->getT(0).getT(1).getT(5).getT(4);                                  // HarmFade_impl::pma6_t<NV>
		auto& jpanner6 = this->getT(0).getT(1).getT(5).getT(5);                              // jdsp::jpanner<NV>
		auto& gain13 = this->getT(0).getT(1).getT(5).getT(6);                                // core::gain
		auto& smoothed_parameter5 = this->getT(0).getT(1).getT(5).getT(7);                   // HarmFade_impl::smoothed_parameter5_t<NV>
		auto& gain3 = this->getT(0).getT(1).getT(5).getT(8);                                 // core::gain
		auto& chain2 = this->getT(0).getT(1).getT(6);                                        // HarmFade_impl::chain2_t<NV>
		auto& minmax2 = this->getT(0).getT(1).getT(6).getT(0);                               // HarmFade_impl::minmax2_t<NV>
		auto& pma_unscaled2 = this->getT(0).getT(1).getT(6).getT(1);                         // HarmFade_impl::pma_unscaled2_t<NV>
		auto& softbypass_switch11 = this->getT(0).getT(1).getT(6).getT(2);                   // HarmFade_impl::softbypass_switch11_t<NV>
		auto& switcher8 = this->getT(0).getT(1).getT(6).getT(2).getT(0);                     // HarmFade_impl::switcher8_t<NV>
		auto& sb_container8 = this->getT(0).getT(1).getT(6).getT(2).getT(1);                 // HarmFade_impl::sb_container8_t<NV>
		auto& sb18 = this->getT(0).getT(1).getT(6).getT(2).getT(1).getT(0);                  // HarmFade_impl::sb18_t<NV>
		auto& file_player2 = this->getT(0).getT(1).getT(6).getT(2).getT(1).getT(0).getT(0);  // HarmFade_impl::file_player2_t<NV>
		auto& sb19 = this->getT(0).getT(1).getT(6).getT(2).getT(1).getT(1);                  // HarmFade_impl::sb19_t<NV>
		auto& file_player15 = this->getT(0).getT(1).getT(6).getT(2).getT(1).getT(1).getT(0); // HarmFade_impl::file_player15_t<NV>
		auto& dry_wet7 = this->getT(0).getT(1).getT(6).getT(3);                              // HarmFade_impl::dry_wet7_t<NV>
		auto& dry_path6 = this->getT(0).getT(1).getT(6).getT(3).getT(0);                     // HarmFade_impl::dry_path6_t
		auto& dry_wet_mixer6 = this->getT(0).getT(1).getT(6).getT(3).getT(0).getT(0);        // HarmFade_impl::dry_wet_mixer6_t
		auto& dry_gain6 = this->getT(0).getT(1).getT(6).getT(3).getT(0).getT(1);             // core::gain
		auto& wet_path6 = this->getT(0).getT(1).getT(6).getT(3).getT(1);                     // HarmFade_impl::wet_path6_t<NV>
		auto& svf2 = this->getT(0).getT(1).getT(6).getT(3).getT(1).getT(0);                  // filters::svf<NV>
		auto& wet_gain6 = this->getT(0).getT(1).getT(6).getT(3).getT(1).getT(1);             // core::gain
		auto& pma7 = this->getT(0).getT(1).getT(6).getT(4);                                  // HarmFade_impl::pma7_t<NV>
		auto& jpanner7 = this->getT(0).getT(1).getT(6).getT(5);                              // jdsp::jpanner<NV>
		auto& smoothed_parameter7 = this->getT(0).getT(1).getT(6).getT(6);                   // HarmFade_impl::smoothed_parameter7_t<NV>
		auto& gain14 = this->getT(0).getT(1).getT(6).getT(7);                                // core::gain
		auto& gain2 = this->getT(0).getT(1).getT(6).getT(8);                                 // core::gain
		auto& chain1 = this->getT(0).getT(1).getT(7);                                        // HarmFade_impl::chain1_t<NV>
		auto& minmax1 = this->getT(0).getT(1).getT(7).getT(0);                               // HarmFade_impl::minmax1_t<NV>
		auto& pma_unscaled1 = this->getT(0).getT(1).getT(7).getT(1);                         // HarmFade_impl::pma_unscaled1_t<NV>
		auto& softbypass_switch3 = this->getT(0).getT(1).getT(7).getT(2);                    // HarmFade_impl::softbypass_switch3_t<NV>
		auto& switcher1 = this->getT(0).getT(1).getT(7).getT(2).getT(0);                     // HarmFade_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(0).getT(1).getT(7).getT(2).getT(1);                 // HarmFade_impl::sb_container1_t<NV>
		auto& sb4 = this->getT(0).getT(1).getT(7).getT(2).getT(1).getT(0);                   // HarmFade_impl::sb4_t<NV>
		auto& file_player1 = this->getT(0).getT(1).getT(7).getT(2).getT(1).getT(0).getT(0);  // HarmFade_impl::file_player1_t<NV>
		auto& sb5 = this->getT(0).getT(1).getT(7).getT(2).getT(1).getT(1);                   // HarmFade_impl::sb5_t<NV>
		auto& file_player8 = this->getT(0).getT(1).getT(7).getT(2).getT(1).getT(1).getT(0);  // HarmFade_impl::file_player8_t<NV>
		auto& dry_wet1 = this->getT(0).getT(1).getT(7).getT(3);                              // HarmFade_impl::dry_wet1_t<NV>
		auto& dry_path = this->getT(0).getT(1).getT(7).getT(3).getT(0);                      // HarmFade_impl::dry_path_t
		auto& dry_wet_mixer = this->getT(0).getT(1).getT(7).getT(3).getT(0).getT(0);         // HarmFade_impl::dry_wet_mixer_t
		auto& dry_gain = this->getT(0).getT(1).getT(7).getT(3).getT(0).getT(1);              // core::gain
		auto& wet_path = this->getT(0).getT(1).getT(7).getT(3).getT(1);                      // HarmFade_impl::wet_path_t<NV>
		auto& svf1 = this->getT(0).getT(1).getT(7).getT(3).getT(1).getT(0);                  // filters::svf<NV>
		auto& wet_gain = this->getT(0).getT(1).getT(7).getT(3).getT(1).getT(1);              // core::gain
		auto& pma1 = this->getT(0).getT(1).getT(7).getT(4);                                  // HarmFade_impl::pma1_t<NV>
		auto& jpanner = this->getT(0).getT(1).getT(7).getT(5);                               // jdsp::jpanner<NV>
		auto& smoothed_parameter6 = this->getT(0).getT(1).getT(7).getT(6);                   // HarmFade_impl::smoothed_parameter6_t<NV>
		auto& gain15 = this->getT(0).getT(1).getT(7).getT(7);                                // core::gain
		auto& gain1 = this->getT(0).getT(1).getT(7).getT(8);                                 // core::gain
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& xfinput_p = this->getParameterT(0);
		xfinput_p.connectT(0, input_toggle);  // xfinput -> input_toggle::Input
		xfinput_p.connectT(1, input_toggle1); // xfinput -> input_toggle1::Input
		xfinput_p.connectT(2, input_toggle3); // xfinput -> input_toggle3::Input
		xfinput_p.connectT(3, input_toggle4); // xfinput -> input_toggle4::Input
		xfinput_p.connectT(4, input_toggle5); // xfinput -> input_toggle5::Input
		xfinput_p.connectT(5, input_toggle6); // xfinput -> input_toggle6::Input
		xfinput_p.connectT(6, input_toggle7); // xfinput -> input_toggle7::Input
		xfinput_p.connectT(7, input_toggle2); // xfinput -> input_toggle2::Input
		
		auto& xfade_p = this->getParameterT(1);
		xfade_p.connectT(0, xfader3); // xfade -> xfader3::Value
		xfade_p.connectT(1, xfader);  // xfade -> xfader::Value
		
		auto& smooth_p = this->getParameterT(2);
		smooth_p.connectT(0, smoothed_parameter1); // smooth -> smoothed_parameter1::SmoothingTime
		smooth_p.connectT(1, smoothed_parameter2); // smooth -> smoothed_parameter2::SmoothingTime
		smooth_p.connectT(2, smoothed_parameter3); // smooth -> smoothed_parameter3::SmoothingTime
		smooth_p.connectT(3, smoothed_parameter4); // smooth -> smoothed_parameter4::SmoothingTime
		smooth_p.connectT(4, smoothed_parameter);  // smooth -> smoothed_parameter::SmoothingTime
		smooth_p.connectT(5, smoothed_parameter5); // smooth -> smoothed_parameter5::SmoothingTime
		smooth_p.connectT(6, smoothed_parameter7); // smooth -> smoothed_parameter7::SmoothingTime
		smooth_p.connectT(7, smoothed_parameter6); // smooth -> smoothed_parameter6::SmoothingTime
		
		this->getParameterT(3).connectT(0, pitch); // pitch1 -> pitch::Value
		
		this->getParameterT(4).connectT(0, harm); // harmoffset -> harm::Value
		
		auto& min_p = this->getParameterT(5);
		min_p.connectT(0, minmax7); // min -> minmax7::Minimum
		min_p.connectT(1, minmax6); // min -> minmax6::Minimum
		min_p.connectT(2, minmax5); // min -> minmax5::Minimum
		min_p.connectT(3, minmax4); // min -> minmax4::Minimum
		min_p.connectT(4, minmax3); // min -> minmax3::Minimum
		min_p.connectT(5, minmax2); // min -> minmax2::Minimum
		min_p.connectT(6, minmax1); // min -> minmax1::Minimum
		min_p.connectT(7, minmax);  // min -> minmax::Minimum
		
		auto& max_p = this->getParameterT(6);
		max_p.connectT(0, minmax7); // max -> minmax7::Maximum
		max_p.connectT(1, minmax6); // max -> minmax6::Maximum
		max_p.connectT(2, minmax5); // max -> minmax5::Maximum
		max_p.connectT(3, minmax4); // max -> minmax4::Maximum
		max_p.connectT(4, minmax3); // max -> minmax3::Maximum
		max_p.connectT(5, minmax2); // max -> minmax2::Maximum
		max_p.connectT(6, minmax1); // max -> minmax1::Maximum
		max_p.connectT(7, minmax);  // max -> minmax::Maximum
		
		auto& step_p = this->getParameterT(7);
		step_p.connectT(0, minmax7); // step -> minmax7::Step
		step_p.connectT(1, minmax6); // step -> minmax6::Step
		step_p.connectT(2, minmax5); // step -> minmax5::Step
		step_p.connectT(3, minmax4); // step -> minmax4::Step
		step_p.connectT(4, minmax3); // step -> minmax3::Step
		step_p.connectT(5, minmax2); // step -> minmax2::Step
		step_p.connectT(6, minmax1); // step -> minmax1::Step
		step_p.connectT(7, minmax);  // step -> minmax::Step
		
		this->getParameterT(8).connectT(0, cut); // cutoffset -> cut::Value
		
		auto& res_p = this->getParameterT(9);
		res_p.connectT(0, svf);  // res -> svf::Q
		res_p.connectT(1, svf7); // res -> svf7::Q
		res_p.connectT(2, svf6); // res -> svf6::Q
		res_p.connectT(3, svf5); // res -> svf5::Q
		res_p.connectT(4, svf4); // res -> svf4::Q
		res_p.connectT(5, svf3); // res -> svf3::Q
		res_p.connectT(6, svf2); // res -> svf2::Q
		res_p.connectT(7, svf1); // res -> svf1::Q
		
		auto& ftype_p = this->getParameterT(10);
		ftype_p.connectT(0, svf);  // ftype -> svf::Mode
		ftype_p.connectT(1, svf7); // ftype -> svf7::Mode
		ftype_p.connectT(2, svf6); // ftype -> svf6::Mode
		ftype_p.connectT(3, svf5); // ftype -> svf5::Mode
		ftype_p.connectT(4, svf4); // ftype -> svf4::Mode
		ftype_p.connectT(5, svf3); // ftype -> svf3::Mode
		ftype_p.connectT(6, svf2); // ftype -> svf2::Mode
		ftype_p.connectT(7, svf1); // ftype -> svf1::Mode
		
		this->getParameterT(11).connectT(0, vol); // gainofset -> vol::Value
		
		this->getParameterT(12).connectT(0, pan); // panoffset -> pan::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		smoothed_parameter1.getParameter().connectT(0, gain);                    // smoothed_parameter1 -> gain::Gain
		pma.getWrappedObject().getParameter().connectT(0, smoothed_parameter1);  // pma -> smoothed_parameter1::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, pma);         // input_toggle -> pma::Add
		smoothed_parameter2.getParameter().connectT(0, gain7);                   // smoothed_parameter2 -> gain7::Gain
		pma2.getWrappedObject().getParameter().connectT(0, smoothed_parameter2); // pma2 -> smoothed_parameter2::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, pma2);       // input_toggle1 -> pma2::Add
		smoothed_parameter3.getParameter().connectT(0, gain6);                   // smoothed_parameter3 -> gain6::Gain
		pma3.getWrappedObject().getParameter().connectT(0, smoothed_parameter3); // pma3 -> smoothed_parameter3::Value
		input_toggle2.getWrappedObject().getParameter().connectT(0, pma3);       // input_toggle2 -> pma3::Add
		smoothed_parameter4.getParameter().connectT(0, gain5);                   // smoothed_parameter4 -> gain5::Gain
		pma4.getWrappedObject().getParameter().connectT(0, smoothed_parameter4); // pma4 -> smoothed_parameter4::Value
		input_toggle3.getWrappedObject().getParameter().connectT(0, pma4);       // input_toggle3 -> pma4::Add
		smoothed_parameter.getParameter().connectT(0, gain4);                    // smoothed_parameter -> gain4::Gain
		pma5.getWrappedObject().getParameter().connectT(0, smoothed_parameter);  // pma5 -> smoothed_parameter::Value
		input_toggle4.getWrappedObject().getParameter().connectT(0, pma5);       // input_toggle4 -> pma5::Add
		smoothed_parameter5.getParameter().connectT(0, gain3);                   // smoothed_parameter5 -> gain3::Gain
		pma6.getWrappedObject().getParameter().connectT(0, smoothed_parameter5); // pma6 -> smoothed_parameter5::Value
		input_toggle5.getWrappedObject().getParameter().connectT(0, pma6);       // input_toggle5 -> pma6::Add
		smoothed_parameter7.getParameter().connectT(0, gain2);                   // smoothed_parameter7 -> gain2::Gain
		pma7.getWrappedObject().getParameter().connectT(0, smoothed_parameter7); // pma7 -> smoothed_parameter7::Value
		input_toggle6.getWrappedObject().getParameter().connectT(0, pma7);       // input_toggle6 -> pma7::Add
		smoothed_parameter6.getParameter().connectT(0, gain1);                   // smoothed_parameter6 -> gain1::Gain
		pma1.getWrappedObject().getParameter().connectT(0, smoothed_parameter6); // pma1 -> smoothed_parameter6::Value
		input_toggle7.getWrappedObject().getParameter().connectT(0, pma1);       // input_toggle7 -> pma1::Add
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, input_toggle);  // xfader -> input_toggle::Value1
		xfader_p.getParameterT(1).connectT(0, input_toggle1); // xfader -> input_toggle1::Value1
		xfader_p.getParameterT(2).connectT(0, input_toggle2); // xfader -> input_toggle2::Value1
		xfader_p.getParameterT(3).connectT(0, input_toggle3); // xfader -> input_toggle3::Value1
		xfader_p.getParameterT(4).connectT(0, input_toggle4); // xfader -> input_toggle4::Value1
		xfader_p.getParameterT(5).connectT(0, input_toggle5); // xfader -> input_toggle5::Value1
		xfader_p.getParameterT(6).connectT(0, input_toggle6); // xfader -> input_toggle6::Value1
		xfader_p.getParameterT(7).connectT(0, input_toggle7); // xfader -> input_toggle7::Value1
		auto& xfader3_p = xfader3.getWrappedObject().getParameter();
		xfader3_p.getParameterT(0).connectT(0, input_toggle);                       // xfader3 -> input_toggle::Value2
		xfader3_p.getParameterT(1).connectT(0, input_toggle1);                      // xfader3 -> input_toggle1::Value2
		xfader3_p.getParameterT(2).connectT(0, input_toggle2);                      // xfader3 -> input_toggle2::Value2
		xfader3_p.getParameterT(3).connectT(0, input_toggle3);                      // xfader3 -> input_toggle3::Value2
		xfader3_p.getParameterT(4).connectT(0, input_toggle4);                      // xfader3 -> input_toggle4::Value2
		xfader3_p.getParameterT(5).connectT(0, input_toggle5);                      // xfader3 -> input_toggle5::Value2
		xfader3_p.getParameterT(6).connectT(0, input_toggle6);                      // xfader3 -> input_toggle6::Value2
		xfader3_p.getParameterT(7).connectT(0, input_toggle7);                      // xfader3 -> input_toggle7::Value2
		pma_unscaled.getWrappedObject().getParameter().connectT(0, file_player);    // pma_unscaled -> file_player::FreqRatio
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled);         // minmax -> pma_unscaled::Add
		pma_unscaled7.getWrappedObject().getParameter().connectT(0, file_player7);  // pma_unscaled7 -> file_player7::FreqRatio
		pma_unscaled7.getWrappedObject().getParameter().connectT(1, file_player10); // pma_unscaled7 -> file_player10::FreqRatio
		minmax7.getWrappedObject().getParameter().connectT(0, pma_unscaled7);       // minmax7 -> pma_unscaled7::Add
		pma_unscaled6.getWrappedObject().getParameter().connectT(0, file_player6);  // pma_unscaled6 -> file_player6::FreqRatio
		pma_unscaled6.getWrappedObject().getParameter().connectT(1, file_player11); // pma_unscaled6 -> file_player11::FreqRatio
		minmax6.getWrappedObject().getParameter().connectT(0, pma_unscaled6);       // minmax6 -> pma_unscaled6::Add
		pma_unscaled5.getWrappedObject().getParameter().connectT(0, file_player5);  // pma_unscaled5 -> file_player5::FreqRatio
		pma_unscaled5.getWrappedObject().getParameter().connectT(1, file_player12); // pma_unscaled5 -> file_player12::FreqRatio
		minmax5.getWrappedObject().getParameter().connectT(0, pma_unscaled5);       // minmax5 -> pma_unscaled5::Add
		pma_unscaled4.getWrappedObject().getParameter().connectT(0, file_player4);  // pma_unscaled4 -> file_player4::FreqRatio
		pma_unscaled4.getWrappedObject().getParameter().connectT(1, file_player13); // pma_unscaled4 -> file_player13::FreqRatio
		minmax4.getWrappedObject().getParameter().connectT(0, pma_unscaled4);       // minmax4 -> pma_unscaled4::Add
		pma_unscaled3.getWrappedObject().getParameter().connectT(0, file_player3);  // pma_unscaled3 -> file_player3::FreqRatio
		pma_unscaled3.getWrappedObject().getParameter().connectT(1, file_player14); // pma_unscaled3 -> file_player14::FreqRatio
		minmax3.getWrappedObject().getParameter().connectT(0, pma_unscaled3);       // minmax3 -> pma_unscaled3::Add
		pma_unscaled2.getWrappedObject().getParameter().connectT(0, file_player2);  // pma_unscaled2 -> file_player2::FreqRatio
		pma_unscaled2.getWrappedObject().getParameter().connectT(1, file_player15); // pma_unscaled2 -> file_player15::FreqRatio
		minmax2.getWrappedObject().getParameter().connectT(0, pma_unscaled2);       // minmax2 -> pma_unscaled2::Add
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, file_player1);  // pma_unscaled1 -> file_player1::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(1, file_player8);  // pma_unscaled1 -> file_player8::FreqRatio
		minmax1.getWrappedObject().getParameter().connectT(0, pma_unscaled1);       // minmax1 -> pma_unscaled1::Add
		auto& harm_p = harm.getWrappedObject().getParameter();
		harm_p.getParameterT(0).connectT(0, minmax);  // harm -> minmax::Value
		harm_p.getParameterT(1).connectT(0, minmax7); // harm -> minmax7::Value
		harm_p.getParameterT(2).connectT(0, minmax6); // harm -> minmax6::Value
		harm_p.getParameterT(3).connectT(0, minmax5); // harm -> minmax5::Value
		harm_p.getParameterT(4).connectT(0, minmax4); // harm -> minmax4::Value
		harm_p.getParameterT(5).connectT(0, minmax3); // harm -> minmax3::Value
		harm_p.getParameterT(6).connectT(0, minmax2); // harm -> minmax2::Value
		harm_p.getParameterT(7).connectT(0, minmax1); // harm -> minmax1::Value
		auto& cut_p = cut.getWrappedObject().getParameter();
		cut_p.getParameterT(0).connectT(0, svf);  // cut -> svf::Frequency
		cut_p.getParameterT(1).connectT(0, svf7); // cut -> svf7::Frequency
		cut_p.getParameterT(2).connectT(0, svf6); // cut -> svf6::Frequency
		cut_p.getParameterT(3).connectT(0, svf5); // cut -> svf5::Frequency
		cut_p.getParameterT(4).connectT(0, svf4); // cut -> svf4::Frequency
		cut_p.getParameterT(5).connectT(0, svf3); // cut -> svf3::Frequency
		cut_p.getParameterT(6).connectT(0, svf2); // cut -> svf2::Frequency
		cut_p.getParameterT(7).connectT(0, svf1); // cut -> svf1::Frequency
		auto& pan_p = pan.getWrappedObject().getParameter();
		pan_p.getParameterT(0).connectT(0, jpanner1); // pan -> jpanner1::Pan
		pan_p.getParameterT(1).connectT(0, jpanner2); // pan -> jpanner2::Pan
		pan_p.getParameterT(2).connectT(0, jpanner3); // pan -> jpanner3::Pan
		pan_p.getParameterT(3).connectT(0, jpanner4); // pan -> jpanner4::Pan
		pan_p.getParameterT(4).connectT(0, jpanner5); // pan -> jpanner5::Pan
		pan_p.getParameterT(5).connectT(0, jpanner6); // pan -> jpanner6::Pan
		pan_p.getParameterT(6).connectT(0, jpanner7); // pan -> jpanner7::Pan
		pan_p.getParameterT(7).connectT(0, jpanner);  // pan -> jpanner::Pan
		auto& vol_p = vol.getWrappedObject().getParameter();
		vol_p.getParameterT(0).connectT(0, gain8);  // vol -> gain8::Gain
		vol_p.getParameterT(1).connectT(0, gain9);  // vol -> gain9::Gain
		vol_p.getParameterT(2).connectT(0, gain10); // vol -> gain10::Gain
		vol_p.getParameterT(3).connectT(0, gain11); // vol -> gain11::Gain
		vol_p.getParameterT(4).connectT(0, gain12); // vol -> gain12::Gain
		vol_p.getParameterT(5).connectT(0, gain13); // vol -> gain13::Gain
		vol_p.getParameterT(6).connectT(0, gain14); // vol -> gain14::Gain
		vol_p.getParameterT(7).connectT(0, gain15); // vol -> gain15::Gain
		auto& pitch_p = pitch.getWrappedObject().getParameter();
		pitch_p.getParameterT(0).connectT(0, pma_unscaled);  // pitch -> pma_unscaled::Value
		pitch_p.getParameterT(1).connectT(0, pma_unscaled7); // pitch -> pma_unscaled7::Value
		pitch_p.getParameterT(2).connectT(0, pma_unscaled6); // pitch -> pma_unscaled6::Value
		pitch_p.getParameterT(3).connectT(0, pma_unscaled5); // pitch -> pma_unscaled5::Value
		pitch_p.getParameterT(4).connectT(0, pma_unscaled4); // pitch -> pma_unscaled4::Value
		pitch_p.getParameterT(5).connectT(0, pma_unscaled3); // pitch -> pma_unscaled3::Value
		pitch_p.getParameterT(6).connectT(0, pma_unscaled2); // pitch -> pma_unscaled2::Value
		pitch_p.getParameterT(7).connectT(0, pma_unscaled1); // pitch -> pma_unscaled1::Value
		auto& dry_wet_mixer7_p = dry_wet_mixer7.getWrappedObject().getParameter();
		dry_wet_mixer7_p.getParameterT(0).connectT(0, dry_gain7); // dry_wet_mixer7 -> dry_gain7::Gain
		dry_wet_mixer7_p.getParameterT(1).connectT(0, wet_gain7); // dry_wet_mixer7 -> wet_gain7::Gain
		auto& dry_wet_mixer4_p = dry_wet_mixer4.getWrappedObject().getParameter();
		dry_wet_mixer4_p.getParameterT(0).connectT(0, dry_gain4); // dry_wet_mixer4 -> dry_gain4::Gain
		dry_wet_mixer4_p.getParameterT(1).connectT(0, wet_gain4); // dry_wet_mixer4 -> wet_gain4::Gain
		auto& dry_wet_mixer5_p = dry_wet_mixer5.getWrappedObject().getParameter();
		dry_wet_mixer5_p.getParameterT(0).connectT(0, dry_gain5); // dry_wet_mixer5 -> dry_gain5::Gain
		dry_wet_mixer5_p.getParameterT(1).connectT(0, wet_gain5); // dry_wet_mixer5 -> wet_gain5::Gain
		auto& dry_wet_mixer6_p = dry_wet_mixer6.getWrappedObject().getParameter();
		dry_wet_mixer6_p.getParameterT(0).connectT(0, dry_gain6); // dry_wet_mixer6 -> dry_gain6::Gain
		dry_wet_mixer6_p.getParameterT(1).connectT(0, wet_gain6); // dry_wet_mixer6 -> wet_gain6::Gain
		auto& dry_wet_mixer3_p = dry_wet_mixer3.getWrappedObject().getParameter();
		dry_wet_mixer3_p.getParameterT(0).connectT(0, dry_gain3); // dry_wet_mixer3 -> dry_gain3::Gain
		dry_wet_mixer3_p.getParameterT(1).connectT(0, wet_gain3); // dry_wet_mixer3 -> wet_gain3::Gain
		auto& dry_wet_mixer2_p = dry_wet_mixer2.getWrappedObject().getParameter();
		dry_wet_mixer2_p.getParameterT(0).connectT(0, dry_gain2); // dry_wet_mixer2 -> dry_gain2::Gain
		dry_wet_mixer2_p.getParameterT(1).connectT(0, wet_gain2); // dry_wet_mixer2 -> wet_gain2::Gain
		auto& dry_wet_mixer_p = dry_wet_mixer.getWrappedObject().getParameter();
		dry_wet_mixer_p.getParameterT(0).connectT(0, dry_gain); // dry_wet_mixer -> dry_gain::Gain
		dry_wet_mixer_p.getParameterT(1).connectT(0, wet_gain); // dry_wet_mixer -> wet_gain::Gain
		auto& dry_wet_mixer1_p = dry_wet_mixer1.getWrappedObject().getParameter();
		dry_wet_mixer1_p.getParameterT(0).connectT(0, dry_gain1); // dry_wet_mixer1 -> dry_gain1::Gain
		dry_wet_mixer1_p.getParameterT(1).connectT(0, wet_gain1); // dry_wet_mixer1 -> wet_gain1::Gain
		auto& cutmix_p = cutmix.getWrappedObject().getParameter();
		cutmix_p.getParameterT(0).connectT(0, dry_wet_mixer7); // cutmix -> dry_wet_mixer7::Value
		cutmix_p.getParameterT(0).connectT(1, dry_wet_mixer4); // cutmix -> dry_wet_mixer4::Value
		cutmix_p.getParameterT(0).connectT(2, dry_wet_mixer5); // cutmix -> dry_wet_mixer5::Value
		cutmix_p.getParameterT(0).connectT(3, dry_wet_mixer6); // cutmix -> dry_wet_mixer6::Value
		cutmix_p.getParameterT(0).connectT(4, dry_wet_mixer3); // cutmix -> dry_wet_mixer3::Value
		cutmix_p.getParameterT(0).connectT(5, dry_wet_mixer2); // cutmix -> dry_wet_mixer2::Value
		cutmix_p.getParameterT(0).connectT(6, dry_wet_mixer);  // cutmix -> dry_wet_mixer::Value
		cutmix_p.getParameterT(0).connectT(7, dry_wet_mixer1); // cutmix -> dry_wet_mixer1::Value
		auto& switcher2_p = switcher2.getWrappedObject().getParameter();
		switcher2_p.getParameterT(0).connectT(0, sb6); // switcher2 -> sb6::Bypassed
		switcher2_p.getParameterT(1).connectT(0, sb7); // switcher2 -> sb7::Bypassed
		auto& switcher3_p = switcher3.getWrappedObject().getParameter();
		switcher3_p.getParameterT(0).connectT(0, sb8); // switcher3 -> sb8::Bypassed
		switcher3_p.getParameterT(1).connectT(0, sb9); // switcher3 -> sb9::Bypassed
		auto& switcher4_p = switcher4.getWrappedObject().getParameter();
		switcher4_p.getParameterT(0).connectT(0, sb10); // switcher4 -> sb10::Bypassed
		switcher4_p.getParameterT(1).connectT(0, sb11); // switcher4 -> sb11::Bypassed
		auto& switcher5_p = switcher5.getWrappedObject().getParameter();
		switcher5_p.getParameterT(0).connectT(0, sb12); // switcher5 -> sb12::Bypassed
		switcher5_p.getParameterT(1).connectT(0, sb13); // switcher5 -> sb13::Bypassed
		auto& switcher6_p = switcher6.getWrappedObject().getParameter();
		switcher6_p.getParameterT(0).connectT(0, sb14); // switcher6 -> sb14::Bypassed
		switcher6_p.getParameterT(1).connectT(0, sb15); // switcher6 -> sb15::Bypassed
		auto& switcher7_p = switcher7.getWrappedObject().getParameter();
		switcher7_p.getParameterT(0).connectT(0, sb16); // switcher7 -> sb16::Bypassed
		switcher7_p.getParameterT(1).connectT(0, sb17); // switcher7 -> sb17::Bypassed
		auto& switcher8_p = switcher8.getWrappedObject().getParameter();
		switcher8_p.getParameterT(0).connectT(0, sb18); // switcher8 -> sb18::Bypassed
		switcher8_p.getParameterT(1).connectT(0, sb19); // switcher8 -> sb19::Bypassed
		auto& switcher1_p = switcher1.getWrappedObject().getParameter();
		switcher1_p.getParameterT(0).connectT(0, sb4); // switcher1 -> sb4::Bypassed
		switcher1_p.getParameterT(1).connectT(0, sb5); // switcher1 -> sb5::Bypassed
		auto& SFZ_p = SFZ.getWrappedObject().getParameter();
		SFZ_p.getParameterT(0).connectT(0, switcher2); // SFZ -> switcher2::Value
		SFZ_p.getParameterT(1).connectT(0, switcher3); // SFZ -> switcher3::Value
		SFZ_p.getParameterT(2).connectT(0, switcher4); // SFZ -> switcher4::Value
		SFZ_p.getParameterT(3).connectT(0, switcher5); // SFZ -> switcher5::Value
		SFZ_p.getParameterT(4).connectT(0, switcher6); // SFZ -> switcher6::Value
		SFZ_p.getParameterT(5).connectT(0, switcher7); // SFZ -> switcher7::Value
		SFZ_p.getParameterT(6).connectT(0, switcher8); // SFZ -> switcher8::Value
		SFZ_p.getParameterT(7).connectT(0, switcher1); // SFZ -> switcher1::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // xfader::Value is automated
		
		; // xfader3::Value is automated
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		; // input_toggle1::Input is automated
		; // input_toggle1::Value1 is automated
		; // input_toggle1::Value2 is automated
		
		; // input_toggle2::Input is automated
		; // input_toggle2::Value1 is automated
		; // input_toggle2::Value2 is automated
		
		; // input_toggle3::Input is automated
		; // input_toggle3::Value1 is automated
		; // input_toggle3::Value2 is automated
		
		; // input_toggle4::Input is automated
		; // input_toggle4::Value1 is automated
		; // input_toggle4::Value2 is automated
		
		; // input_toggle5::Input is automated
		; // input_toggle5::Value1 is automated
		; // input_toggle5::Value2 is automated
		
		; // input_toggle6::Input is automated
		; // input_toggle6::Value1 is automated
		; // input_toggle6::Value2 is automated
		
		; // input_toggle7::Input is automated
		; // input_toggle7::Value1 is automated
		; // input_toggle7::Value2 is automated
		
		; // harm::Value is automated
		
		; // cut::Value is automated
		
		; // pan::Value is automated
		
		; // vol::Value is automated
		
		; // pitch::Value is automated
		
		cutmix.setParameterT(0, 1.); // control::sliderbank::Value
		
		SFZ.setParameterT(0, 1.); // control::sliderbank::Value
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                                 // minmax::Value is automated
		;                                 // minmax::Minimum is automated
		;                                 // minmax::Maximum is automated
		minmax.setParameterT(3, 1.02534); // control::minmax::Skew
		;                                 // minmax::Step is automated
		minmax.setParameterT(5, 0.);      // control::minmax::Polarity
		
		;                                  // pma_unscaled::Value is automated
		pma_unscaled.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                  // pma_unscaled::Add is automated
		
		softbypass_switch5.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher2::Value is automated
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		file_player9.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player9.setParameterT(1, 0.);   // core::file_player::Gate
		file_player9.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player9.setParameterT(3, 0.);   // core::file_player::FreqRatio
		
		dry_wet2.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer1::Value is automated
		
		;                                // dry_gain1::Gain is automated
		dry_gain1.setParameterT(1, 20.); // core::gain::Smoothing
		dry_gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                           // svf::Mode is automated
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                // wet_gain1::Gain is automated
		wet_gain1.setParameterT(1, 20.); // core::gain::Smoothing
		wet_gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pma.setParameterT(0, 0.); // control::pma::Value
		pma.setParameterT(1, 1.); // control::pma::Multiply
		;                         // pma::Add is automated
		
		;                              // jpanner1::Pan is automated
		jpanner1.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                              // gain8::Gain is automated
		gain8.setParameterT(1, 27.);   // core::gain::Smoothing
		gain8.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter1::Value is automated
		;                                         // smoothed_parameter1::SmoothingTime is automated
		smoothed_parameter1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 0.);    // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax7::Value is automated
		;                             // minmax7::Minimum is automated
		;                             // minmax7::Maximum is automated
		minmax7.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax7::Step is automated
		minmax7.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled7::Value is automated
		pma_unscaled7.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled7::Add is automated
		
		softbypass_switch6.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher3::Value is automated
		
		file_player7.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player7.setParameterT(1, 0.);   // core::file_player::Gate
		file_player7.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player7::FreqRatio is automated
		
		file_player10.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player10.setParameterT(1, 0.);   // core::file_player::Gate
		file_player10.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player10::FreqRatio is automated
		
		dry_wet3.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer2::Value is automated
		
		;                                // dry_gain2::Gain is automated
		dry_gain2.setParameterT(1, 20.); // core::gain::Smoothing
		dry_gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf7::Frequency is automated
		;                            // svf7::Q is automated
		svf7.setParameterT(2, 0.);   // filters::svf::Gain
		svf7.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf7::Mode is automated
		svf7.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                // wet_gain2::Gain is automated
		wet_gain2.setParameterT(1, 20.); // core::gain::Smoothing
		wet_gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pma2.setParameterT(0, 0.); // control::pma::Value
		pma2.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma2::Add is automated
		
		;                              // jpanner2::Pan is automated
		jpanner2.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                              // gain9::Gain is automated
		gain9.setParameterT(1, 16.1);  // core::gain::Smoothing
		gain9.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter2::Value is automated
		;                                         // smoothed_parameter2::SmoothingTime is automated
		smoothed_parameter2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain7::Gain is automated
		gain7.setParameterT(1, 0.);    // core::gain::Smoothing
		gain7.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax6::Value is automated
		;                             // minmax6::Minimum is automated
		;                             // minmax6::Maximum is automated
		minmax6.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax6::Step is automated
		minmax6.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled6::Value is automated
		pma_unscaled6.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled6::Add is automated
		
		softbypass_switch7.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher4::Value is automated
		
		file_player6.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player6.setParameterT(1, 0.);   // core::file_player::Gate
		file_player6.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player6::FreqRatio is automated
		
		file_player11.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player11.setParameterT(1, 0.);   // core::file_player::Gate
		file_player11.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player11::FreqRatio is automated
		
		dry_wet4.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer3::Value is automated
		
		;                                // dry_gain3::Gain is automated
		dry_gain3.setParameterT(1, 20.); // core::gain::Smoothing
		dry_gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf6::Frequency is automated
		;                            // svf6::Q is automated
		svf6.setParameterT(2, 0.);   // filters::svf::Gain
		svf6.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf6::Mode is automated
		svf6.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                // wet_gain3::Gain is automated
		wet_gain3.setParameterT(1, 20.); // core::gain::Smoothing
		wet_gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pma3.setParameterT(0, 0.); // control::pma::Value
		pma3.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma3::Add is automated
		
		;                              // jpanner3::Pan is automated
		jpanner3.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                               // gain10::Gain is automated
		gain10.setParameterT(1, 16.5);  // core::gain::Smoothing
		gain10.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter3::Value is automated
		;                                         // smoothed_parameter3::SmoothingTime is automated
		smoothed_parameter3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain6::Gain is automated
		gain6.setParameterT(1, 0.);    // core::gain::Smoothing
		gain6.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax5::Value is automated
		;                             // minmax5::Minimum is automated
		;                             // minmax5::Maximum is automated
		minmax5.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax5::Step is automated
		minmax5.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled5::Value is automated
		pma_unscaled5.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled5::Add is automated
		
		softbypass_switch8.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher5::Value is automated
		
		file_player5.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player5.setParameterT(1, 0.);   // core::file_player::Gate
		file_player5.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player5::FreqRatio is automated
		
		file_player12.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player12.setParameterT(1, 0.);   // core::file_player::Gate
		file_player12.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player12::FreqRatio is automated
		
		dry_wet8.setParameterT(0, 0.); // container::split::DryWet
		
		; // dry_wet_mixer7::Value is automated
		
		;                                // dry_gain7::Gain is automated
		dry_gain7.setParameterT(1, 20.); // core::gain::Smoothing
		dry_gain7.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf5::Frequency is automated
		;                            // svf5::Q is automated
		svf5.setParameterT(2, 0.);   // filters::svf::Gain
		svf5.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf5::Mode is automated
		svf5.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                // wet_gain7::Gain is automated
		wet_gain7.setParameterT(1, 20.); // core::gain::Smoothing
		wet_gain7.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pma4.setParameterT(0, 0.); // control::pma::Value
		pma4.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma4::Add is automated
		
		;                              // jpanner4::Pan is automated
		jpanner4.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                               // gain11::Gain is automated
		gain11.setParameterT(1, 10.1);  // core::gain::Smoothing
		gain11.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter4::Value is automated
		;                                         // smoothed_parameter4::SmoothingTime is automated
		smoothed_parameter4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain5::Gain is automated
		gain5.setParameterT(1, 0.);    // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax4::Value is automated
		;                             // minmax4::Minimum is automated
		;                             // minmax4::Maximum is automated
		minmax4.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax4::Step is automated
		minmax4.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled4::Value is automated
		pma_unscaled4.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled4::Add is automated
		
		softbypass_switch9.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher6::Value is automated
		
		file_player4.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player4.setParameterT(1, 0.);   // core::file_player::Gate
		file_player4.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player4::FreqRatio is automated
		
		file_player13.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player13.setParameterT(1, 0.);   // core::file_player::Gate
		file_player13.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player13::FreqRatio is automated
		
		dry_wet5.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer4::Value is automated
		
		;                                // dry_gain4::Gain is automated
		dry_gain4.setParameterT(1, 20.); // core::gain::Smoothing
		dry_gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf4::Frequency is automated
		;                            // svf4::Q is automated
		svf4.setParameterT(2, 0.);   // filters::svf::Gain
		svf4.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf4::Mode is automated
		svf4.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                // wet_gain4::Gain is automated
		wet_gain4.setParameterT(1, 20.); // core::gain::Smoothing
		wet_gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pma5.setParameterT(0, 0.); // control::pma::Value
		pma5.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma5::Add is automated
		
		;                              // jpanner5::Pan is automated
		jpanner5.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                              // gain12::Gain is automated
		gain12.setParameterT(1, 16.2); // core::gain::Smoothing
		gain12.setParameterT(2, -72.); // core::gain::ResetValue
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain4::Gain is automated
		gain4.setParameterT(1, 0.);    // core::gain::Smoothing
		gain4.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax3::Value is automated
		;                             // minmax3::Minimum is automated
		;                             // minmax3::Maximum is automated
		minmax3.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax3::Step is automated
		minmax3.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled3::Value is automated
		pma_unscaled3.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled3::Add is automated
		
		softbypass_switch10.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher7::Value is automated
		
		file_player3.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player3.setParameterT(1, 0.);   // core::file_player::Gate
		file_player3.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player3::FreqRatio is automated
		
		file_player14.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player14.setParameterT(1, 0.);   // core::file_player::Gate
		file_player14.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player14::FreqRatio is automated
		
		dry_wet6.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer5::Value is automated
		
		;                                // dry_gain5::Gain is automated
		dry_gain5.setParameterT(1, 20.); // core::gain::Smoothing
		dry_gain5.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf3::Frequency is automated
		;                            // svf3::Q is automated
		svf3.setParameterT(2, 0.);   // filters::svf::Gain
		svf3.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf3::Mode is automated
		svf3.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                // wet_gain5::Gain is automated
		wet_gain5.setParameterT(1, 20.); // core::gain::Smoothing
		wet_gain5.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pma6.setParameterT(0, 0.); // control::pma::Value
		pma6.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma6::Add is automated
		
		;                              // jpanner6::Pan is automated
		jpanner6.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                               // gain13::Gain is automated
		gain13.setParameterT(1, 35.7);  // core::gain::Smoothing
		gain13.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter5::Value is automated
		;                                         // smoothed_parameter5::SmoothingTime is automated
		smoothed_parameter5.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 0.);    // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax2::Value is automated
		;                             // minmax2::Minimum is automated
		;                             // minmax2::Maximum is automated
		minmax2.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax2::Step is automated
		minmax2.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled2::Value is automated
		pma_unscaled2.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled2::Add is automated
		
		softbypass_switch11.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher8::Value is automated
		
		file_player2.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player2.setParameterT(1, 0.);   // core::file_player::Gate
		file_player2.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player2::FreqRatio is automated
		
		file_player15.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player15.setParameterT(1, 0.);   // core::file_player::Gate
		file_player15.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player15::FreqRatio is automated
		
		dry_wet7.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer6::Value is automated
		
		;                                // dry_gain6::Gain is automated
		dry_gain6.setParameterT(1, 20.); // core::gain::Smoothing
		dry_gain6.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf2::Mode is automated
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                // wet_gain6::Gain is automated
		wet_gain6.setParameterT(1, 20.); // core::gain::Smoothing
		wet_gain6.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pma7.setParameterT(0, 0.); // control::pma::Value
		pma7.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma7::Add is automated
		
		;                              // jpanner7::Pan is automated
		jpanner7.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                         // smoothed_parameter7::Value is automated
		;                                         // smoothed_parameter7::SmoothingTime is automated
		smoothed_parameter7.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                               // gain14::Gain is automated
		gain14.setParameterT(1, 0.);    // core::gain::Smoothing
		gain14.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 0.);    // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax1::Value is automated
		;                             // minmax1::Minimum is automated
		;                             // minmax1::Maximum is automated
		minmax1.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax1::Step is automated
		minmax1.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled1::Value is automated
		pma_unscaled1.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled1::Add is automated
		
		softbypass_switch3.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher1::Value is automated
		
		file_player1.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player1.setParameterT(1, 0.);   // core::file_player::Gate
		file_player1.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player1::FreqRatio is automated
		
		file_player8.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player8.setParameterT(1, 0.);   // core::file_player::Gate
		file_player8.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player8::FreqRatio is automated
		
		dry_wet1.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer::Value is automated
		
		;                               // dry_gain::Gain is automated
		dry_gain.setParameterT(1, 20.); // core::gain::Smoothing
		dry_gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf1::Mode is automated
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                               // wet_gain::Gain is automated
		wet_gain.setParameterT(1, 20.); // core::gain::Smoothing
		wet_gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pma1.setParameterT(0, 0.); // control::pma::Value
		pma1.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma1::Add is automated
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                         // smoothed_parameter6::Value is automated
		;                                         // smoothed_parameter6::SmoothingTime is automated
		smoothed_parameter6.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                               // gain15::Gain is automated
		gain15.setParameterT(1, 15.7);  // core::gain::Smoothing
		gain15.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 0.);    // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 16.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 0.741659);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 0.433581);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                         // HarmFade_impl::harm_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);                         // HarmFade_impl::cut_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).setExternalData(b, index);                         // HarmFade_impl::pan_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).setExternalData(b, index);                         // HarmFade_impl::vol_t
		this->getT(0).getT(0).getT(1).getT(4).setExternalData(b, index);                         // HarmFade_impl::pitch_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).setExternalData(b, index);                         // HarmFade_impl::cutmix_t
		this->getT(0).getT(0).getT(1).getT(6).setExternalData(b, index);                         // HarmFade_impl::SFZ_t<NV>
		this->getT(0).getT(1).getT(0).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // HarmFade_impl::file_player_t<NV>
		this->getT(0).getT(1).getT(0).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // HarmFade_impl::file_player9_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // HarmFade_impl::file_player7_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // HarmFade_impl::file_player10_t<NV>
		this->getT(0).getT(1).getT(2).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // HarmFade_impl::file_player6_t<NV>
		this->getT(0).getT(1).getT(2).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // HarmFade_impl::file_player11_t<NV>
		this->getT(0).getT(1).getT(3).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // HarmFade_impl::file_player5_t<NV>
		this->getT(0).getT(1).getT(3).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // HarmFade_impl::file_player12_t<NV>
		this->getT(0).getT(1).getT(4).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // HarmFade_impl::file_player4_t<NV>
		this->getT(0).getT(1).getT(4).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // HarmFade_impl::file_player13_t<NV>
		this->getT(0).getT(1).getT(5).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // HarmFade_impl::file_player3_t<NV>
		this->getT(0).getT(1).getT(5).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // HarmFade_impl::file_player14_t<NV>
		this->getT(0).getT(1).getT(6).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // HarmFade_impl::file_player2_t<NV>
		this->getT(0).getT(1).getT(6).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // HarmFade_impl::file_player15_t<NV>
		this->getT(0).getT(1).getT(7).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index); // HarmFade_impl::file_player1_t<NV>
		this->getT(0).getT(1).getT(7).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index); // HarmFade_impl::file_player8_t<NV>
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
using HarmFade = wrap::node<HarmFade_impl::instance<NV>>;
}


