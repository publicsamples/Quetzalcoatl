#pragma once

#include <JuceHeader.h>

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace qfade_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_INV(peak3_modRange, 
                            0., 
                            1.);

template <int NV>
using peak3_mod = parameter::from0To1_inv<math::add<NV>, 
                                          0, 
                                          peak3_modRange>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, project::XfadeMod>, 
                                      wrap::no_process<math::sig2mod<NV>>, 
                                      peak3_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV> using peak5_mod = peak3_mod<NV>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using pitch1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<1, project::XfadeMod>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   peak5_t<NV>>;

template <int NV>
using pitch1_t = wrap::control_rate<pitch1_t_<NV>>;

template <int NV> using peak6_mod = peak3_mod<NV>;

template <int NV>
using peak6_t = wrap::mod<peak6_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using pitch2_t_ = container::chain<parameter::empty, 
                                   wrap::fix<1, project::XfadeMod>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   peak6_t<NV>>;

template <int NV>
using pitch2_t = wrap::control_rate<pitch2_t_<NV>>;

template <int NV>
using peak7_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using FM_t_ = container::chain<parameter::empty, 
                               wrap::fix<1, project::XfadeMod>, 
                               wrap::no_process<math::sig2mod<NV>>, 
                               peak7_t<NV>>;

template <int NV>
using FM_t = wrap::control_rate<FM_t_<NV>>;

template <int NV> using peak9_mod = peak3_mod<NV>;

template <int NV>
using peak9_t = wrap::mod<peak9_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using Feed_t_ = container::chain<parameter::empty, 
                                 wrap::fix<1, project::XfadeMod>, 
                                 math::sig2mod<NV>, 
                                 peak9_t<NV>>;

template <int NV>
using Feed_t = wrap::control_rate<Feed_t_<NV>>;

template <int NV> using peak10_mod = peak3_mod<NV>;

template <int NV>
using peak10_t = wrap::mod<peak10_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using Filter_t_ = container::chain<parameter::empty, 
                                   wrap::fix<1, project::XfadeMod>, 
                                   math::sig2mod<NV>, 
                                   peak10_t<NV>>;

template <int NV>
using Filter_t = wrap::control_rate<Filter_t_<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain1_t<NV>>, 
                                  pitch1_t<NV>, 
                                  pitch2_t<NV>, 
                                  FM_t<NV>, 
                                  Feed_t<NV>, 
                                  Filter_t<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::add<NV>>>;

template <int NV> using chain11_t = chain9_t<NV>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain9_t<NV>>, 
                                  chain11_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(osc1smooth1_modRange, 
                             -100., 
                             0., 
                             5.42227);

using osc1smooth1_mod = parameter::from0To1<core::gain, 
                                            0, 
                                            osc1smooth1_modRange>;

template <int NV>
using osc1smooth1_t = wrap::mod<osc1smooth1_mod, 
                                control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using osc1smooth3_mod = osc1smooth1_mod;

template <int NV>
using osc1smooth3_t = wrap::mod<osc1smooth3_mod, 
                                control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using osc1smooth4_mod = osc1smooth1_mod;

template <int NV>
using osc1smooth4_t = wrap::mod<osc1smooth4_mod, 
                                control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using osc1smooth5_mod = osc1smooth1_mod;

template <int NV>
using osc1smooth5_t = wrap::mod<osc1smooth5_mod, 
                                control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using osc1smooth6_mod = osc1smooth1_mod;

template <int NV>
using osc1smooth6_t = wrap::mod<osc1smooth6_mod, 
                                control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using osc1smooth7_mod = osc1smooth1_mod;

template <int NV>
using osc1smooth7_t = wrap::mod<osc1smooth7_mod, 
                                control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using osc1smooth8_mod = osc1smooth1_mod;

template <int NV>
using osc1smooth8_t = wrap::mod<osc1smooth8_mod, 
                                control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader1_multimod = parameter::list<parameter::plain<osc1smooth1_t<NV>, 0>, 
                                         parameter::plain<control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>, 0>, 
                                         parameter::plain<osc1smooth3_t<NV>, 0>, 
                                         parameter::plain<osc1smooth4_t<NV>, 0>, 
                                         parameter::plain<osc1smooth5_t<NV>, 0>, 
                                         parameter::plain<osc1smooth6_t<NV>, 0>, 
                                         parameter::plain<osc1smooth7_t<NV>, 0>, 
                                         parameter::plain<osc1smooth8_t<NV>, 0>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::switcher>;
template <int NV>
using pma3_t = control::pma<NV, 
                            parameter::plain<xfader1_t<NV>, 0>>;
DECLARE_PARAMETER_RANGE(peak1_modRange, 
                        -1., 
                        1.);

template <int NV>
using peak1_mod = parameter::from0To1<pma3_t<NV>, 
                                      2, 
                                      peak1_modRange>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using XFADER_t = container::chain<parameter::empty, 
                                  wrap::fix<1, split6_t<NV>>, 
                                  math::sig2mod<NV>, 
                                  peak1_t<NV>, 
                                  pma3_t<NV>, 
                                  xfader1_t<NV>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, XFADER_t<NV>>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV> using chain_t = chain9_t<NV>;

template <int NV> using chain10_t = chain9_t<NV>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain_t<NV>>, 
                                  chain10_t<NV>>;

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;
template <int NV>
using file_player3_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;
template <int NV>
using file_player2_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<2>>;
template <int NV>
using file_player1_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<3>>;
template <int NV>
using file_player4_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<4>>;
template <int NV>
using file_player5_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<5>>;
template <int NV>
using file_player6_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<6>>;
template <int NV>
using file_player7_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<7>>;
DECLARE_PARAMETER_RANGE_STEP(pma1_mod_0Range, 
                             0.8, 
                             24., 
                             0.01);

template <int NV>
using pma1_mod_0 = parameter::from0To1<file_player_t<NV>, 
                                       3, 
                                       pma1_mod_0Range>;

template <int NV>
using pma1_mod_1 = parameter::from0To1<file_player3_t<NV>, 
                                       3, 
                                       pma1_mod_0Range>;

DECLARE_PARAMETER_RANGE(pma1_mod_2Range, 
                        0., 
                        24.);

template <int NV>
using pma1_mod_2 = parameter::from0To1<file_player2_t<NV>, 
                                       3, 
                                       pma1_mod_2Range>;

DECLARE_PARAMETER_RANGE(pma1_mod_3Range, 
                        0., 
                        2.);

template <int NV>
using pma1_mod_3 = parameter::from0To1<file_player1_t<NV>, 
                                       3, 
                                       pma1_mod_3Range>;

template <int NV>
using pma1_mod_4 = parameter::from0To1<file_player4_t<NV>, 
                                       3, 
                                       pma1_mod_3Range>;

template <int NV>
using pma1_mod_5 = parameter::from0To1<file_player5_t<NV>, 
                                       3, 
                                       pma1_mod_3Range>;

template <int NV>
using pma1_mod_6 = parameter::from0To1<file_player6_t<NV>, 
                                       3, 
                                       pma1_mod_3Range>;

DECLARE_PARAMETER_RANGE(pma1_mod_7Range, 
                        0.8, 
                        24.);

template <int NV>
using pma1_mod_7 = parameter::from0To1<file_player7_t<NV>, 
                                       3, 
                                       pma1_mod_7Range>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  pma1_mod_0<NV>, 
                                  pma1_mod_1<NV>, 
                                  pma1_mod_2<NV>, 
                                  pma1_mod_3<NV>, 
                                  pma1_mod_4<NV>, 
                                  pma1_mod_5<NV>, 
                                  pma1_mod_6<NV>, 
                                  pma1_mod_7<NV>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using osc1fm_t = container::chain<parameter::empty, 
                                  wrap::fix<1, split4_t<NV>>, 
                                  wrap::no_process<math::sig2mod<NV>>, 
                                  peak2_t<NV>, 
                                  pma1_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, osc1fm_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using osc1slot1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, osc1smooth1_t<NV>>, 
                                     file_player_t<NV>, 
                                     core::gain, 
                                     core::gain, 
                                     jdsp::jpanner<NV>>;

template <int NV>
using osc1slot2_t = container::chain<parameter::empty, 
                                     wrap::fix<2, control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>, 
                                     file_player3_t<NV>, 
                                     core::gain, 
                                     core::gain, 
                                     jdsp::jpanner<NV>>;

template <int NV>
using osc1slot3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, osc1smooth3_t<NV>>, 
                                     file_player2_t<NV>, 
                                     core::gain, 
                                     core::gain, 
                                     jdsp::jpanner<NV>>;

template <int NV>
using osc1slot4_t = container::chain<parameter::empty, 
                                     wrap::fix<2, osc1smooth4_t<NV>>, 
                                     file_player1_t<NV>, 
                                     core::gain, 
                                     core::gain, 
                                     jdsp::jpanner<NV>>;

template <int NV>
using osc1slot5_t = container::chain<parameter::empty, 
                                     wrap::fix<2, osc1smooth5_t<NV>>, 
                                     file_player4_t<NV>, 
                                     core::gain, 
                                     core::gain, 
                                     jdsp::jpanner<NV>>;

template <int NV>
using osc1slot6_t = container::chain<parameter::empty, 
                                     wrap::fix<2, osc1smooth6_t<NV>>, 
                                     file_player5_t<NV>, 
                                     core::gain, 
                                     core::gain, 
                                     jdsp::jpanner<NV>>;

template <int NV>
using osc1slot7_t = container::chain<parameter::empty, 
                                     wrap::fix<2, osc1smooth7_t<NV>>, 
                                     file_player6_t<NV>, 
                                     core::gain, 
                                     core::gain, 
                                     jdsp::jpanner<NV>>;

template <int NV>
using osc1slot8_t = container::chain<parameter::empty, 
                                     wrap::fix<2, osc1smooth8_t<NV>>, 
                                     file_player7_t<NV>, 
                                     core::gain, 
                                     core::gain, 
                                     jdsp::jpanner<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, osc1slot1_t<NV>>, 
                                 osc1slot2_t<NV>, 
                                 osc1slot3_t<NV>, 
                                 osc1slot4_t<NV>, 
                                 osc1slot5_t<NV>, 
                                 osc1slot6_t<NV>, 
                                 osc1slot7_t<NV>, 
                                 osc1slot8_t<NV>>;

template <int NV> using chain3_t = chain9_t<NV>;

template <int NV> using chain22_t = chain9_t<NV>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain3_t<NV>>, 
                                   chain22_t<NV>>;

using pma8_mod = osc1smooth1_mod;

template <int NV>
using pma8_t = control::pma<NV, pma8_mod>;
template <int NV>
using peak12_t = wrap::mod<parameter::plain<pma8_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using osc1fm3_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split11_t<NV>>, 
                                   peak12_t<NV>, 
                                   pma8_t<NV>>;

template <int NV>
using modchain5_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, osc1fm3_t<NV>>>;

template <int NV>
using modchain5_t = wrap::control_rate<modchain5_t_<NV>>;

template <int NV>
using OSC1_t = container::chain<parameter::empty, 
                                wrap::fix<2, modchain2_t<NV>>, 
                                modchain_t<NV>, 
                                split_t<NV>, 
                                modchain5_t<NV>, 
                                core::gain>;

template <int NV> using chain16_t = chain9_t<NV>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain16_t<NV>>>;

template <int NV>
using file_player8_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<8>>;
DECLARE_PARAMETER_RANGE_STEP(pma15_modRange, 
                             0., 
                             24., 
                             0.01);

template <int NV>
using pma15_mod = parameter::from0To1<file_player8_t<NV>, 
                                      3, 
                                      pma15_modRange>;

template <int NV>
using pma15_t = control::pma<NV, pma15_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma15_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using osc1fm1_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split8_t<NV>>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   peak4_t<NV>, 
                                   pma15_t<NV>>;

using pma7_mod = osc1smooth1_mod;

template <int NV>
using pma7_t = control::pma<NV, pma7_mod>;
template <int NV>
using peak11_t = wrap::mod<parameter::plain<pma7_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::add<NV>>, 
                                  peak11_t<NV>, 
                                  pma7_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, chain2_t<NV>>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, osc1fm1_t<NV>>, 
                                   chain1_t<NV>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split10_t<NV>>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;
using stereo_frame_cable = cable::frame<2>;

template <int NV> using intensity_mod = peak3_mod<NV>;

template <int NV>
using intensity_t = control::intensity<NV, intensity_mod<NV>>;

template <int NV> using intensity3_mod = peak3_mod<NV>;

template <int NV>
using intensity3_t = control::intensity<NV, intensity3_mod<NV>>;

template <int NV> using intensity1_mod = peak3_mod<NV>;

template <int NV>
using intensity1_t = control::intensity<NV, intensity1_mod<NV>>;

template <int NV> using intensity5_mod = peak3_mod<NV>;

template <int NV>
using intensity5_t = control::intensity<NV, intensity5_mod<NV>>;
template <int NV>
using peak_mod_0 = parameter::from0To1_inv<intensity_t<NV>, 
                                           0, 
                                           peak3_modRange>;

template <int NV>
using peak_mod_2 = parameter::from0To1_inv<intensity1_t<NV>, 
                                           0, 
                                           peak3_modRange>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  peak_mod_0<NV>, 
                                  parameter::plain<intensity3_t<NV>, 0>, 
                                  peak_mod_2<NV>, 
                                  parameter::plain<intensity5_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using xfade_t = container::chain<parameter::empty, 
                                 wrap::fix<2, intensity1_t<NV>>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, intensity_t<NV>>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, intensity3_t<NV>>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, intensity5_t<NV>>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<2, xfade_t<NV>>, 
                                  chain15_t<NV>, 
                                  chain21_t<NV>, 
                                  chain23_t<NV>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sig2mod<NV>>, 
                                   routing::receive<stereo_frame_cable>, 
                                   peak_t<NV>, 
                                   routing::send<stereo_frame_cable>, 
                                   split7_t<NV>, 
                                   math::clear<NV>>;

using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain12_t<NV>>, 
                                  chain13_t>;

template <int NV>
using frame2_block1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, split5_t<NV>>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, modchain3_t<NV>>, 
                                   file_player8_t<NV>, 
                                   core::gain, 
                                   frame2_block1_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain14_t<NV>>>;

template <int NV>
using OSC2_t = container::chain<parameter::empty, 
                                wrap::fix<2, split3_t<NV>>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, OSC1_t<NV>>, 
                                  OSC2_t<NV>>;

template <int NV> using chain19_t = chain9_t<NV>;

template <int NV> using chain20_t = chain9_t<NV>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain19_t<NV>>, 
                                  chain20_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma16_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma16_mod = parameter::from0To1<filters::svf<NV>, 
                                      0, 
                                      pma16_modRange>;

template <int NV>
using pma16_t = control::pma<NV, pma16_mod<NV>>;
template <int NV>
using peak8_t = wrap::mod<parameter::plain<pma16_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using osc1fm2_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split9_t<NV>>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   peak8_t<NV>, 
                                   pma16_t<NV>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, osc1fm2_t<NV>>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, modchain4_t<NV>>, 
                                   filters::svf<NV>>;

template <int NV>
using frame2_block_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, split1_t<NV>>, 
                                         chain18_t<NV>>;

template <int NV>
using frame2_block_t = wrap::frame<2, frame2_block_t_<NV>>;

namespace qfade_t_parameters
{
// Parameter list for qfade_impl::qfade_t ----------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(smooth_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth_0 = parameter::from0To1<qfade_impl::osc1smooth1_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_1 = parameter::from0To1<control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_2 = parameter::from0To1<qfade_impl::osc1smooth3_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_3 = parameter::from0To1<qfade_impl::osc1smooth4_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_5 = parameter::from0To1<qfade_impl::osc1smooth5_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_6 = parameter::from0To1<qfade_impl::osc1smooth7_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_7 = parameter::from0To1<qfade_impl::osc1smooth8_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth = parameter::chain<ranges::Identity, 
                                smooth_0<NV>, 
                                smooth_1<NV>, 
                                smooth_2<NV>, 
                                smooth_3<NV>, 
                                smooth_3<NV>, 
                                smooth_5<NV>, 
                                smooth_6<NV>, 
                                smooth_7<NV>>;

DECLARE_PARAMETER_RANGE_INV(xfade_mod1_InputRange, 
                            0., 
                            1.);

using xfade_mod1 = parameter::chain<xfade_mod1_InputRange, 
                                    parameter::plain<project::XfadeMod, 5>>;

DECLARE_PARAMETER_RANGE(osc1_mod_sourceRange, 
                        0., 
                        6.);

using osc1_mod_source = parameter::from0To1<project::XfadeMod, 
                                            0, 
                                            osc1_mod_sourceRange>;

using osc2_modsource = osc1_mod_source;

DECLARE_PARAMETER_RANGE_INV(osc2mod_InputRange, 
                            0., 
                            1.);

using osc2mod = parameter::chain<osc2mod_InputRange, 
                                 parameter::plain<project::XfadeMod, 5>>;

using filter_mod_source = osc1_mod_source;

DECLARE_PARAMETER_RANGE_INV(filter_mod_InputRange, 
                            0., 
                            1.);

using filter_mod = parameter::chain<filter_mod_InputRange, 
                                    parameter::plain<project::XfadeMod, 5>>;

using mod1_tempo = parameter::chain<ranges::Identity, 
                                    parameter::plain<project::XfadeMod, 1>, 
                                    parameter::plain<project::XfadeMod, 1>, 
                                    parameter::plain<project::XfadeMod, 1>, 
                                    parameter::plain<project::XfadeMod, 1>, 
                                    parameter::plain<project::XfadeMod, 1>, 
                                    parameter::plain<project::XfadeMod, 1>>;

using mod1_div = parameter::chain<ranges::Identity, 
                                  parameter::plain<project::XfadeMod, 2>, 
                                  parameter::plain<project::XfadeMod, 2>, 
                                  parameter::plain<project::XfadeMod, 2>, 
                                  parameter::plain<project::XfadeMod, 2>, 
                                  parameter::plain<project::XfadeMod, 2>, 
                                  parameter::plain<project::XfadeMod, 2>>;

using mod1_oneshot = parameter::chain<ranges::Identity, 
                                      parameter::plain<project::XfadeMod, 3>, 
                                      parameter::plain<project::XfadeMod, 3>, 
                                      parameter::plain<project::XfadeMod, 3>, 
                                      parameter::plain<project::XfadeMod, 3>, 
                                      parameter::plain<project::XfadeMod, 3>, 
                                      parameter::plain<project::XfadeMod, 3>>;

using mod1_trig = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::XfadeMod, 4>, 
                                   parameter::plain<project::XfadeMod, 4>, 
                                   parameter::plain<project::XfadeMod, 4>, 
                                   parameter::plain<project::XfadeMod, 4>, 
                                   parameter::plain<project::XfadeMod, 4>, 
                                   parameter::plain<project::XfadeMod, 4>>;

using mod2_tempo = parameter::chain<ranges::Identity, 
                                    parameter::plain<project::XfadeMod, 6>, 
                                    parameter::plain<project::XfadeMod, 6>, 
                                    parameter::plain<project::XfadeMod, 6>, 
                                    parameter::plain<project::XfadeMod, 6>, 
                                    parameter::plain<project::XfadeMod, 6>, 
                                    parameter::plain<project::XfadeMod, 6>>;

using mod2_div = parameter::chain<ranges::Identity, 
                                  parameter::plain<project::XfadeMod, 7>, 
                                  parameter::plain<project::XfadeMod, 7>, 
                                  parameter::plain<project::XfadeMod, 7>, 
                                  parameter::plain<project::XfadeMod, 7>, 
                                  parameter::plain<project::XfadeMod, 7>, 
                                  parameter::plain<project::XfadeMod, 7>>;

using mod2_oneshot = parameter::chain<ranges::Identity, 
                                      parameter::plain<project::XfadeMod, 8>, 
                                      parameter::plain<project::XfadeMod, 8>, 
                                      parameter::plain<project::XfadeMod, 8>, 
                                      parameter::plain<project::XfadeMod, 8>, 
                                      parameter::plain<project::XfadeMod, 8>, 
                                      parameter::plain<project::XfadeMod, 8>>;

using mod2_trig = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::XfadeMod, 9>, 
                                   parameter::plain<project::XfadeMod, 9>, 
                                   parameter::plain<project::XfadeMod, 9>, 
                                   parameter::plain<project::XfadeMod, 9>, 
                                   parameter::plain<project::XfadeMod, 9>, 
                                   parameter::plain<project::XfadeMod, 9>>;

using mod2_type = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::XfadeMod, 10>, 
                                   parameter::plain<project::XfadeMod, 10>, 
                                   parameter::plain<project::XfadeMod, 10>, 
                                   parameter::plain<project::XfadeMod, 10>, 
                                   parameter::plain<project::XfadeMod, 10>, 
                                   parameter::plain<project::XfadeMod, 10>>;

using mod3_tempo = parameter::chain<ranges::Identity, 
                                    parameter::plain<project::XfadeMod, 11>, 
                                    parameter::plain<project::XfadeMod, 11>, 
                                    parameter::plain<project::XfadeMod, 11>, 
                                    parameter::plain<project::XfadeMod, 11>, 
                                    parameter::plain<project::XfadeMod, 11>, 
                                    parameter::plain<project::XfadeMod, 11>>;

using mod3_div = parameter::chain<ranges::Identity, 
                                  parameter::plain<project::XfadeMod, 12>, 
                                  parameter::plain<project::XfadeMod, 12>, 
                                  parameter::plain<project::XfadeMod, 12>, 
                                  parameter::plain<project::XfadeMod, 12>, 
                                  parameter::plain<project::XfadeMod, 12>, 
                                  parameter::plain<project::XfadeMod, 12>>;

using mod3_oneshot = parameter::chain<ranges::Identity, 
                                      parameter::plain<project::XfadeMod, 13>, 
                                      parameter::plain<project::XfadeMod, 13>, 
                                      parameter::plain<project::XfadeMod, 13>, 
                                      parameter::plain<project::XfadeMod, 13>, 
                                      parameter::plain<project::XfadeMod, 13>, 
                                      parameter::plain<project::XfadeMod, 13>>;

using mod3_trig = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::XfadeMod, 14>, 
                                   parameter::plain<project::XfadeMod, 14>, 
                                   parameter::plain<project::XfadeMod, 14>, 
                                   parameter::plain<project::XfadeMod, 14>, 
                                   parameter::plain<project::XfadeMod, 14>, 
                                   parameter::plain<project::XfadeMod, 14>>;

using mod3_type = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::XfadeMod, 15>, 
                                   parameter::plain<project::XfadeMod, 15>, 
                                   parameter::plain<project::XfadeMod, 15>, 
                                   parameter::plain<project::XfadeMod, 15>, 
                                   parameter::plain<project::XfadeMod, 15>, 
                                   parameter::plain<project::XfadeMod, 15>>;

template <int NV>
using osc1pitch1A = parameter::from0To1<qfade_impl::pma1_t<NV>, 
                                        2, 
                                        qfade_impl::pma1_mod_2Range>;

using osc1vol1 = parameter::from0To1<core::gain, 
                                     0, 
                                     qfade_impl::osc1smooth1_modRange>;

using osc1vol2 = osc1vol1;

using osc1vol3 = osc1vol1;

using osc1vol4 = osc1vol1;

using osc1vol5 = osc1vol1;

using osc1vol6 = osc1vol1;

using osc1vol7 = osc1vol1;

using osc1vol8 = osc1vol1;

template <int NV>
using osc1pan4 = parameter::from0To1<jdsp::jpanner<NV>, 
                                     0, 
                                     qfade_impl::peak1_modRange>;

template <int NV> using osc1pan5 = osc1pan4<NV>;

template <int NV> using osc1pan6 = osc1pan4<NV>;

template <int NV> using osc1pan7 = osc1pan4<NV>;

template <int NV> using osc1pan8 = osc1pan4<NV>;

using modattack1 = parameter::chain<ranges::Identity, 
                                    parameter::plain<project::XfadeMod, 16>, 
                                    parameter::plain<project::XfadeMod, 16>, 
                                    parameter::plain<project::XfadeMod, 16>, 
                                    parameter::plain<project::XfadeMod, 16>, 
                                    parameter::plain<project::XfadeMod, 16>, 
                                    parameter::plain<project::XfadeMod, 16>>;

using moddecay1 = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::XfadeMod, 17>, 
                                   parameter::plain<project::XfadeMod, 17>, 
                                   parameter::plain<project::XfadeMod, 17>, 
                                   parameter::plain<project::XfadeMod, 17>, 
                                   parameter::plain<project::XfadeMod, 17>, 
                                   parameter::plain<project::XfadeMod, 17>>;

using modsustain1 = parameter::chain<ranges::Identity, 
                                     parameter::plain<project::XfadeMod, 18>, 
                                     parameter::plain<project::XfadeMod, 18>, 
                                     parameter::plain<project::XfadeMod, 18>, 
                                     parameter::plain<project::XfadeMod, 18>, 
                                     parameter::plain<project::XfadeMod, 18>, 
                                     parameter::plain<project::XfadeMod, 18>>;

using modrelease1 = parameter::chain<ranges::Identity, 
                                     parameter::plain<project::XfadeMod, 19>, 
                                     parameter::plain<project::XfadeMod, 19>, 
                                     parameter::plain<project::XfadeMod, 19>, 
                                     parameter::plain<project::XfadeMod, 19>, 
                                     parameter::plain<project::XfadeMod, 19>, 
                                     parameter::plain<project::XfadeMod, 19>>;

using modhold1 = parameter::chain<ranges::Identity, 
                                  parameter::plain<project::XfadeMod, 20>, 
                                  parameter::plain<project::XfadeMod, 20>, 
                                  parameter::plain<project::XfadeMod, 20>, 
                                  parameter::plain<project::XfadeMod, 20>, 
                                  parameter::plain<project::XfadeMod, 20>, 
                                  parameter::plain<project::XfadeMod, 20>>;

using modattack2 = parameter::chain<ranges::Identity, 
                                    parameter::plain<project::XfadeMod, 21>, 
                                    parameter::plain<project::XfadeMod, 21>, 
                                    parameter::plain<project::XfadeMod, 21>, 
                                    parameter::plain<project::XfadeMod, 21>, 
                                    parameter::plain<project::XfadeMod, 21>, 
                                    parameter::plain<project::XfadeMod, 21>>;

using moddecay2 = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::XfadeMod, 22>, 
                                   parameter::plain<project::XfadeMod, 22>, 
                                   parameter::plain<project::XfadeMod, 22>, 
                                   parameter::plain<project::XfadeMod, 22>, 
                                   parameter::plain<project::XfadeMod, 22>, 
                                   parameter::plain<project::XfadeMod, 22>>;

using modsustain2 = parameter::chain<ranges::Identity, 
                                     parameter::plain<project::XfadeMod, 23>, 
                                     parameter::plain<project::XfadeMod, 23>, 
                                     parameter::plain<project::XfadeMod, 23>, 
                                     parameter::plain<project::XfadeMod, 23>, 
                                     parameter::plain<project::XfadeMod, 23>, 
                                     parameter::plain<project::XfadeMod, 23>>;

using modrelease2 = parameter::chain<ranges::Identity, 
                                     parameter::plain<project::XfadeMod, 24>, 
                                     parameter::plain<project::XfadeMod, 24>, 
                                     parameter::plain<project::XfadeMod, 24>, 
                                     parameter::plain<project::XfadeMod, 24>, 
                                     parameter::plain<project::XfadeMod, 24>, 
                                     parameter::plain<project::XfadeMod, 24>>;

using modhold2 = parameter::chain<ranges::Identity, 
                                  parameter::plain<project::XfadeMod, 25>, 
                                  parameter::plain<project::XfadeMod, 25>, 
                                  parameter::plain<project::XfadeMod, 25>, 
                                  parameter::plain<project::XfadeMod, 25>, 
                                  parameter::plain<project::XfadeMod, 25>, 
                                  parameter::plain<project::XfadeMod, 25>>;

using modattack3 = parameter::chain<ranges::Identity, 
                                    parameter::plain<project::XfadeMod, 26>, 
                                    parameter::plain<project::XfadeMod, 26>, 
                                    parameter::plain<project::XfadeMod, 26>, 
                                    parameter::plain<project::XfadeMod, 26>, 
                                    parameter::plain<project::XfadeMod, 26>, 
                                    parameter::plain<project::XfadeMod, 26>>;

using moddecay3 = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::XfadeMod, 27>, 
                                   parameter::plain<project::XfadeMod, 27>, 
                                   parameter::plain<project::XfadeMod, 27>, 
                                   parameter::plain<project::XfadeMod, 27>, 
                                   parameter::plain<project::XfadeMod, 27>, 
                                   parameter::plain<project::XfadeMod, 27>>;

using modsustain3 = parameter::chain<ranges::Identity, 
                                     parameter::plain<project::XfadeMod, 28>, 
                                     parameter::plain<project::XfadeMod, 28>, 
                                     parameter::plain<project::XfadeMod, 28>, 
                                     parameter::plain<project::XfadeMod, 28>, 
                                     parameter::plain<project::XfadeMod, 28>, 
                                     parameter::plain<project::XfadeMod, 28>>;

using modrelease3 = parameter::chain<ranges::Identity, 
                                     parameter::plain<project::XfadeMod, 29>, 
                                     parameter::plain<project::XfadeMod, 29>, 
                                     parameter::plain<project::XfadeMod, 29>, 
                                     parameter::plain<project::XfadeMod, 29>, 
                                     parameter::plain<project::XfadeMod, 29>, 
                                     parameter::plain<project::XfadeMod, 29>>;

using modhold3 = parameter::chain<ranges::Identity, 
                                  parameter::plain<project::XfadeMod, 30>, 
                                  parameter::plain<project::XfadeMod, 30>, 
                                  parameter::plain<project::XfadeMod, 30>, 
                                  parameter::plain<project::XfadeMod, 30>, 
                                  parameter::plain<project::XfadeMod, 30>, 
                                  parameter::plain<project::XfadeMod, 30>>;

DECLARE_PARAMETER_RANGE_SKEW(osc2volRange, 
                             -100., 
                             0., 
                             5.42227);

using osc2vol = parameter::from0To1<core::gain, 
                                    0, 
                                    osc2volRange>;

using osc1_vol_modsource = osc1_mod_source;

DECLARE_PARAMETER_RANGE_INV(os1_vol_mod_InputRange, 
                            0., 
                            1.);

using os1_vol_mod = parameter::chain<os1_vol_mod_InputRange, 
                                     parameter::plain<project::XfadeMod, 5>>;

template <int NV>
using xfade = parameter::plain<qfade_impl::pma3_t<NV>, 0>;
using xfade_mod_source = parameter::plain<project::XfadeMod, 0>;
using osc1_mod = parameter::empty;
using mod1_type = osc1_mod;
using osc1pitch1B = osc1_mod;
using osc1pitch2A = osc1_mod;
using osc1pitch2B = osc1_mod;
using osc1pitch3A = osc1_mod;
using osc1pitch3B = osc1_mod;
using osc1pitch4A = osc1_mod;
using osc1pitch4B = osc1_mod;
template <int NV>
using osc1pan1 = parameter::plain<jdsp::jpanner<NV>, 0>;
template <int NV> using osc1pan2 = osc1pan1<NV>;
using osc1pan3 = osc1_mod;
using pitch1modmodamount = parameter::plain<project::XfadeMod, 5>;
template <int NV>
using Pitch1FM = parameter::plain<qfade_impl::intensity_t<NV>, 
                                  1>;
template <int NV>
using xfadefm = parameter::plain<qfade_impl::intensity1_t<NV>, 
                                 1>;
template <int NV>
using filterfm = parameter::plain<qfade_impl::intensity3_t<NV>, 
                                  1>;
template <int NV>
using osc1mastervol = parameter::plain<qfade_impl::pma8_t<NV>, 2>;
template <int NV>
using osc2vol_AM = parameter::plain<qfade_impl::intensity5_t<NV>, 
                                    1>;
template <int NV>
using qfade_t_plist = parameter::list<smooth<NV>, 
                                      xfade<NV>, 
                                      xfade_mod_source, 
                                      xfade_mod1, 
                                      osc1_mod_source, 
                                      osc1_mod, 
                                      osc2_modsource, 
                                      osc2mod, 
                                      filter_mod_source, 
                                      filter_mod, 
                                      mod1_tempo, 
                                      mod1_div, 
                                      mod1_oneshot, 
                                      mod1_trig, 
                                      mod1_type, 
                                      mod2_tempo, 
                                      mod2_div, 
                                      mod2_oneshot, 
                                      mod2_trig, 
                                      mod2_type, 
                                      mod3_tempo, 
                                      mod3_div, 
                                      mod3_oneshot, 
                                      mod3_trig, 
                                      mod3_type, 
                                      osc1pitch1A<NV>, 
                                      osc1pitch1B, 
                                      osc1pitch2A, 
                                      osc1pitch2B, 
                                      osc1pitch3A, 
                                      osc1pitch3B, 
                                      osc1pitch4A, 
                                      osc1pitch4B, 
                                      osc1vol1, 
                                      osc1vol2, 
                                      osc1vol3, 
                                      osc1vol4, 
                                      osc1vol5, 
                                      osc1vol6, 
                                      osc1vol7, 
                                      osc1vol8, 
                                      osc1pan1<NV>, 
                                      osc1pan2<NV>, 
                                      osc1pan3, 
                                      osc1pan4<NV>, 
                                      osc1pan5<NV>, 
                                      osc1pan6<NV>, 
                                      osc1pan7<NV>, 
                                      osc1pan8<NV>, 
                                      modattack1, 
                                      moddecay1, 
                                      modsustain1, 
                                      modrelease1, 
                                      modhold1, 
                                      modattack2, 
                                      moddecay2, 
                                      modsustain2, 
                                      modrelease2, 
                                      modhold2, 
                                      modattack3, 
                                      moddecay3, 
                                      modsustain3, 
                                      modrelease3, 
                                      modhold3, 
                                      pitch1modmodamount, 
                                      Pitch1FM<NV>, 
                                      xfadefm<NV>, 
                                      filterfm<NV>, 
                                      osc1mastervol<NV>, 
                                      osc2vol, 
                                      osc1_vol_modsource, 
                                      os1_vol_mod, 
                                      osc2vol_AM<NV>>;
}

template <int NV>
using qfade_t_ = container::chain<qfade_t_parameters::qfade_t_plist<NV>, 
                                  wrap::fix<2, split2_t<NV>>, 
                                  frame2_block_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public qfade_impl::qfade_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 9;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(qfade);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(1308)
		{
			0x005B, 0x0000, 0x7300, 0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x7800, 0x6166, 0x6564, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x2B3F, 0xD787, 0x003A, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0002, 0x0000, 0x6678, 0x6461, 0x5F65, 0x6F6D, 0x5F64, 0x6F73, 
            0x7275, 0x6563, 0x0000, 0x0000, 0x0000, 0xC000, 0x0040, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 0x6678, 
            0x6461, 0x5F65, 0x6F6D, 0x3164, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 
            0x0000, 0x736F, 0x3163, 0x6D5F, 0x646F, 0x735F, 0x756F, 0x6372, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x6F00, 0x6373, 0x5F31, 
            0x6F6D, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x065B, 0x0000, 0x6F00, 0x6373, 
            0x5F32, 0x6F6D, 0x7364, 0x756F, 0x6372, 0x0065, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x075B, 0x0000, 0x6F00, 0x6373, 0x6D32, 0x646F, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0008, 0x0000, 0x6966, 0x746C, 0x7265, 0x6D5F, 0x646F, 
            0x735F, 0x756F, 0x6372, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 
            0x6600, 0x6C69, 0x6574, 0x5F72, 0x6F6D, 0x0064, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0A5B, 0x0000, 0x6D00, 0x646F, 0x5F31, 0x6574, 0x706D, 0x006F, 
            0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0B5B, 0x0000, 0x6D00, 0x646F, 0x5F31, 0x6964, 
            0x0076, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0C5B, 0x0000, 0x6D00, 0x646F, 0x5F31, 
            0x6E6F, 0x7365, 0x6F68, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0D5B, 0x0000, 
            0x6D00, 0x646F, 0x5F31, 0x7274, 0x6769, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x000E, 0x0000, 0x6F6D, 0x3164, 0x745F, 0x7079, 0x0065, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0F5B, 0x0000, 0x6D00, 0x646F, 0x5F32, 0x6574, 0x706D, 
            0x006F, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x105B, 0x0000, 0x6D00, 0x646F, 0x5F32, 
            0x6964, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x115B, 0x0000, 0x6D00, 0x646F, 
            0x5F32, 0x6E6F, 0x7365, 0x6F68, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x125B, 
            0x0000, 0x6D00, 0x646F, 0x5F32, 0x7274, 0x6769, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0013, 0x0000, 0x6F6D, 0x3264, 0x745F, 0x7079, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x145B, 0x0000, 0x6D00, 0x646F, 0x5F33, 0x6574, 
            0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x155B, 0x0000, 0x6D00, 0x646F, 
            0x5F33, 0x6964, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x165B, 0x0000, 0x6D00, 
            0x646F, 0x5F33, 0x6E6F, 0x7365, 0x6F68, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x175B, 0x0000, 0x6D00, 0x646F, 0x5F33, 0x7274, 0x6769, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0018, 0x0000, 0x6F6D, 0x3364, 0x745F, 0x7079, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0xCADD, 0x3F7F, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x195B, 0x0000, 0x6F00, 0x6373, 0x7031, 
            0x7469, 0x6863, 0x4131, 0x0000, 0x0000, 0x0000, 0x8000, 0x0E3F, 
            0xF0A9, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001A, 0x0000, 
            0x736F, 0x3163, 0x6970, 0x6374, 0x3168, 0x0042, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x1B5B, 0x0000, 0x6F00, 0x6373, 0x7031, 0x7469, 0x6863, 0x4132, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x001C, 0x0000, 0x736F, 0x3163, 0x6970, 
            0x6374, 0x3268, 0x0042, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F00, 0x0000, 0x3F80, 0x0000, 0x0000, 0x1D5B, 0x0000, 0x6F00, 
            0x6373, 0x7031, 0x7469, 0x6863, 0x4133, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x001E, 0x0000, 0x736F, 0x3163, 0x6970, 0x6374, 0x3368, 0x0042, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F00, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x1F5B, 0x0000, 0x6F00, 0x6373, 0x7031, 0x7469, 
            0x6863, 0x4134, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0020, 0x0000, 0x736F, 
            0x3163, 0x6970, 0x6374, 0x3468, 0x0042, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F00, 0x0000, 0x3F80, 0x0000, 0x0000, 0x215B, 
            0x0000, 0x6F00, 0x6373, 0x7631, 0x6C6F, 0x0031, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0xA8A0, 0x3F06, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x225B, 0x0000, 0x6F00, 0x6373, 0x7631, 0x6C6F, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x072B, 0x3F03, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x235B, 0x0000, 0x6F00, 0x6373, 0x7631, 0x6C6F, 0x0033, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x6873, 0x3EFD, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x245B, 0x0000, 0x6F00, 0x6373, 0x7631, 0x6C6F, 
            0x0034, 0x0000, 0x0000, 0x0000, 0x3F80, 0xA6E9, 0x3F00, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x255B, 0x0000, 0x6F00, 0x6373, 0x7631, 
            0x6C6F, 0x0035, 0x0000, 0x0000, 0x0000, 0x3F80, 0xBE77, 0x3EFB, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x265B, 0x0000, 0x6F00, 0x6373, 
            0x7631, 0x6C6F, 0x0036, 0x0000, 0x0000, 0x0000, 0x3F80, 0x7EFA, 
            0x3EFE, 0x0000, 0x3F80, 0x0000, 0x0000, 0x275B, 0x0000, 0x6F00, 
            0x6373, 0x7631, 0x6C6F, 0x0037, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0xBE77, 0x3EFD, 0x0000, 0x3F80, 0x0000, 0x0000, 0x285B, 0x0000, 
            0x6F00, 0x6373, 0x7631, 0x6C6F, 0x0038, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0E56, 0x3EFD, 0x0000, 0x3F80, 0x0000, 0x0000, 0x295B, 
            0x0000, 0x6F00, 0x6373, 0x7031, 0x6E61, 0x0031, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0xA1AA, 0xBDFC, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x2A5B, 0x0000, 0x6F00, 0x6373, 0x7031, 0x6E61, 0x0032, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x7396, 0x3E81, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x2B5B, 0x0000, 0x6F00, 0x6373, 0x7031, 0x6E61, 0x0033, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0xA439, 0x3EF0, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x2C5B, 0x0000, 0x6F00, 0x6373, 0x7031, 0x6E61, 
            0x0034, 0x0000, 0x0000, 0x0000, 0x3F80, 0x2127, 0x3EE3, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x2D5B, 0x0000, 0x6F00, 0x6373, 0x7031, 
            0x6E61, 0x0035, 0x0000, 0x0000, 0x0000, 0x3F80, 0x34DD, 0x3EFD, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x2E5B, 0x0000, 0x6F00, 0x6373, 
            0x7031, 0x6E61, 0x0036, 0x0000, 0x0000, 0x0000, 0x3F80, 0x3FF0, 
            0x3EE1, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2F5B, 0x0000, 0x6F00, 
            0x6373, 0x7031, 0x6E61, 0x0037, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x1AB0, 0x3EF4, 0x0000, 0x3F80, 0x0000, 0x0000, 0x305B, 0x0000, 
            0x6F00, 0x6373, 0x7031, 0x6E61, 0x0038, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x69CB, 0x3EFC, 0x0000, 0x3F80, 0x0000, 0x0000, 0x315B, 
            0x0000, 0x6D00, 0x646F, 0x7461, 0x6174, 0x6B63, 0x0031, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x325B, 0x0000, 0x6D00, 0x646F, 0x6564, 0x6163, 0x3179, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0033, 0x0000, 0x6F6D, 0x7364, 0x7375, 
            0x6174, 0x6E69, 0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x345B, 0x0000, 0x6D00, 
            0x646F, 0x6572, 0x656C, 0x7361, 0x3165, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0035, 0x0000, 0x6F6D, 0x6864, 0x6C6F, 0x3164, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0036, 0x0000, 0x6F6D, 0x6164, 0x7474, 0x6361, 0x326B, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0037, 0x0000, 0x6F6D, 0x6464, 0x6365, 
            0x7961, 0x0032, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x385B, 0x0000, 0x6D00, 0x646F, 
            0x7573, 0x7473, 0x6961, 0x326E, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0039, 
            0x0000, 0x6F6D, 0x7264, 0x6C65, 0x6165, 0x6573, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x3A5B, 0x0000, 0x6D00, 0x646F, 0x6F68, 0x646C, 0x0032, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x3B5B, 0x0000, 0x6D00, 0x646F, 0x7461, 0x6174, 
            0x6B63, 0x0033, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x3C5B, 0x0000, 0x6D00, 0x646F, 
            0x6564, 0x6163, 0x3379, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x003D, 0x0000, 
            0x6F6D, 0x7364, 0x7375, 0x6174, 0x6E69, 0x0033, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x3E5B, 0x0000, 0x6D00, 0x646F, 0x6572, 0x656C, 0x7361, 0x3365, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x003F, 0x0000, 0x6F6D, 0x6864, 0x6C6F, 
            0x3364, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0040, 0x0000, 0x6970, 0x6374, 
            0x3168, 0x6F6D, 0x6D64, 0x646F, 0x6D61, 0x756F, 0x746E, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x7F3F, 0x7DDA, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0041, 0x0000, 0x6950, 0x6374, 0x3168, 0x4D46, 
            0x0000, 0x0000, 0x0000, 0x8000, 0xF03F, 0xFD17, 0x003D, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0042, 0x0000, 0x6678, 0x6461, 0x6665, 
            0x006D, 0x0000, 0x0000, 0x0000, 0x3F80, 0xBA7F, 0x3E46, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x435B, 0x0000, 0x6600, 0x6C69, 0x6574, 
            0x6672, 0x006D, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x445B, 0x0000, 0x6F00, 0x6373, 
            0x6D31, 0x7361, 0x6574, 0x7672, 0x6C6F, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0045, 0x0000, 0x736F, 0x3263, 0x6F76, 0x006C, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x465B, 0x0000, 0x6F00, 0x6373, 0x5F31, 0x6F76, 0x5F6C, 0x6F6D, 
            0x7364, 0x756F, 0x6372, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x475B, 0x0000, 
            0x6F00, 0x3173, 0x765F, 0x6C6F, 0x6D5F, 0x646F, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0048, 0x0000, 0x736F, 0x3263, 0x6F76, 0x5F6C, 0x4D41, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x933F, 0x6D2C, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split2 = this->getT(0);                                                  // qfade_impl::split2_t<NV>
		auto& modchain1 = this->getT(0).getT(0);                                       // qfade_impl::modchain1_t<NV>
		auto& XfadeMod = this->getT(0).getT(0).getT(0);                                // project::XfadeMod
		auto& sig2mod1 = this->getT(0).getT(0).getT(1);                                // wrap::no_process<math::sig2mod<NV>>
		auto& peak3 = this->getT(0).getT(0).getT(2);                                   // qfade_impl::peak3_t<NV>
		auto& pitch1 = this->getT(0).getT(1);                                          // qfade_impl::pitch1_t<NV>
		auto& PitchMod1 = this->getT(0).getT(1).getT(0);                               // project::XfadeMod
		auto& sig2mod3 = this->getT(0).getT(1).getT(1);                                // wrap::no_process<math::sig2mod<NV>>
		auto& peak5 = this->getT(0).getT(1).getT(2);                                   // qfade_impl::peak5_t<NV>
		auto& pitch2 = this->getT(0).getT(2);                                          // qfade_impl::pitch2_t<NV>
		auto& PitchMod2 = this->getT(0).getT(2).getT(0);                               // project::XfadeMod
		auto& sig2mod4 = this->getT(0).getT(2).getT(1);                                // wrap::no_process<math::sig2mod<NV>>
		auto& peak6 = this->getT(0).getT(2).getT(2);                                   // qfade_impl::peak6_t<NV>
		auto& FM = this->getT(0).getT(3);                                              // qfade_impl::FM_t<NV>
		auto& FMMod = this->getT(0).getT(3).getT(0);                                   // project::XfadeMod
		auto& sig2mod5 = this->getT(0).getT(3).getT(1);                                // wrap::no_process<math::sig2mod<NV>>
		auto& peak7 = this->getT(0).getT(3).getT(2);                                   // qfade_impl::peak7_t<NV>
		auto& Feed = this->getT(0).getT(4);                                            // qfade_impl::Feed_t<NV>
		auto& FeedMod = this->getT(0).getT(4).getT(0);                                 // project::XfadeMod
		auto& sig2mod7 = this->getT(0).getT(4).getT(1);                                // math::sig2mod<NV>
		auto& peak9 = this->getT(0).getT(4).getT(2);                                   // qfade_impl::peak9_t<NV>
		auto& Filter = this->getT(0).getT(5);                                          // qfade_impl::Filter_t<NV>
		auto& FeedMod1 = this->getT(0).getT(5).getT(0);                                // project::XfadeMod
		auto& sig2mod8 = this->getT(0).getT(5).getT(1);                                // math::sig2mod<NV>
		auto& peak10 = this->getT(0).getT(5).getT(2);                                  // qfade_impl::peak10_t<NV>
		auto& frame2_block = this->getT(1);                                            // qfade_impl::frame2_block_t<NV>
		auto& split1 = this->getT(1).getT(0);                                          // qfade_impl::split1_t<NV>
		auto& OSC1 = this->getT(1).getT(0).getT(0);                                    // qfade_impl::OSC1_t<NV>
		auto& modchain2 = this->getT(1).getT(0).getT(0).getT(0);                       // qfade_impl::modchain2_t<NV>
		auto& XFADER = this->getT(1).getT(0).getT(0).getT(0).getT(0);                  // qfade_impl::XFADER_t<NV>
		auto& split6 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);          // qfade_impl::split6_t<NV>
		auto& chain9 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);  // qfade_impl::chain9_t<NV>
		auto& add2 = this->getT(1).getT(0).getT(0).getT(0).                            // math::add<NV>
                     getT(0).getT(0).getT(0).getT(0);
		auto& chain11 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).getT(1); // qfade_impl::chain11_t<NV>
		auto& add8 = this->getT(1).getT(0).getT(0).getT(0).                            // math::add<NV>
                     getT(0).getT(0).getT(1).getT(0);
		auto& sig2mod2 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(1);        // math::sig2mod<NV>
		auto& peak1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(2);           // qfade_impl::peak1_t<NV>
		auto& pma3 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(3);            // qfade_impl::pma3_t<NV>
		auto& xfader1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(4);         // qfade_impl::xfader1_t<NV>
		auto& modchain = this->getT(1).getT(0).getT(0).getT(1);                        // qfade_impl::modchain_t<NV>
		auto& osc1fm = this->getT(1).getT(0).getT(0).getT(1).getT(0);                  // qfade_impl::osc1fm_t<NV>
		auto& split4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0);          // qfade_impl::split4_t<NV>
		auto& chain = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);   // qfade_impl::chain_t<NV>
		auto& add = this->getT(1).getT(0).getT(0).getT(1).                             // math::add<NV>
                    getT(0).getT(0).getT(0).getT(0);
		auto& chain10 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1); // qfade_impl::chain10_t<NV>
		auto& add3 = this->getT(1).getT(0).getT(0).getT(1).                            // math::add<NV>
                     getT(0).getT(0).getT(1).getT(0);
		auto& sig2mod9 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(1);        // wrap::no_process<math::sig2mod<NV>>
		auto& peak2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(2);           // qfade_impl::peak2_t<NV>
		auto& pma1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(3);            // qfade_impl::pma1_t<NV>
		auto& split = this->getT(1).getT(0).getT(0).getT(2);                           // qfade_impl::split_t<NV>
		auto& osc1slot1 = this->getT(1).getT(0).getT(0).getT(2).getT(0);               // qfade_impl::osc1slot1_t<NV>
		auto& osc1smooth1 = this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(0);     // qfade_impl::osc1smooth1_t<NV>
		auto& file_player = this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(1);     // qfade_impl::file_player_t<NV>
		auto& osc1fadegain2 = this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(2);   // core::gain
		auto& gain11 = this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(3);          // core::gain
		auto& jpanner = this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(4);         // jdsp::jpanner<NV>
		auto& osc1slot2 = this->getT(1).getT(0).getT(0).getT(2).getT(1);               // qfade_impl::osc1slot2_t<NV>
		auto& osc1smooth2 = this->getT(1).getT(0).getT(0).getT(2).getT(1).getT(0);     // control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>
		auto& file_player3 = this->getT(1).getT(0).getT(0).getT(2).getT(1).getT(1);    // qfade_impl::file_player3_t<NV>
		auto& osc1fadegain1 = this->getT(1).getT(0).getT(0).getT(2).getT(1).getT(2);   // core::gain
		auto& gain12 = this->getT(1).getT(0).getT(0).getT(2).getT(1).getT(3);          // core::gain
		auto& jpanner1 = this->getT(1).getT(0).getT(0).getT(2).getT(1).getT(4);        // jdsp::jpanner<NV>
		auto& osc1slot3 = this->getT(1).getT(0).getT(0).getT(2).getT(2);               // qfade_impl::osc1slot3_t<NV>
		auto& osc1smooth3 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(0);     // qfade_impl::osc1smooth3_t<NV>
		auto& file_player2 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1);    // qfade_impl::file_player2_t<NV>
		auto& osc1fadegain3 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(2);   // core::gain
		auto& gain13 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(3);          // core::gain
		auto& jpanner2 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(4);        // jdsp::jpanner<NV>
		auto& osc1slot4 = this->getT(1).getT(0).getT(0).getT(2).getT(3);               // qfade_impl::osc1slot4_t<NV>
		auto& osc1smooth4 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(0);     // qfade_impl::osc1smooth4_t<NV>
		auto& file_player1 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(1);    // qfade_impl::file_player1_t<NV>
		auto& osc1fadegain4 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(2);   // core::gain
		auto& gain14 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(3);          // core::gain
		auto& jpanner3 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(4);        // jdsp::jpanner<NV>
		auto& osc1slot5 = this->getT(1).getT(0).getT(0).getT(2).getT(4);               // qfade_impl::osc1slot5_t<NV>
		auto& osc1smooth5 = this->getT(1).getT(0).getT(0).getT(2).getT(4).getT(0);     // qfade_impl::osc1smooth5_t<NV>
		auto& file_player4 = this->getT(1).getT(0).getT(0).getT(2).getT(4).getT(1);    // qfade_impl::file_player4_t<NV>
		auto& osc1fadegain5 = this->getT(1).getT(0).getT(0).getT(2).getT(4).getT(2);   // core::gain
		auto& gain15 = this->getT(1).getT(0).getT(0).getT(2).getT(4).getT(3);          // core::gain
		auto& jpanner4 = this->getT(1).getT(0).getT(0).getT(2).getT(4).getT(4);        // jdsp::jpanner<NV>
		auto& osc1slot6 = this->getT(1).getT(0).getT(0).getT(2).getT(5);               // qfade_impl::osc1slot6_t<NV>
		auto& osc1smooth6 = this->getT(1).getT(0).getT(0).getT(2).getT(5).getT(0);     // qfade_impl::osc1smooth6_t<NV>
		auto& file_player5 = this->getT(1).getT(0).getT(0).getT(2).getT(5).getT(1);    // qfade_impl::file_player5_t<NV>
		auto& osc1fadegain6 = this->getT(1).getT(0).getT(0).getT(2).getT(5).getT(2);   // core::gain
		auto& gain16 = this->getT(1).getT(0).getT(0).getT(2).getT(5).getT(3);          // core::gain
		auto& jpanner5 = this->getT(1).getT(0).getT(0).getT(2).getT(5).getT(4);        // jdsp::jpanner<NV>
		auto& osc1slot7 = this->getT(1).getT(0).getT(0).getT(2).getT(6);               // qfade_impl::osc1slot7_t<NV>
		auto& osc1smooth7 = this->getT(1).getT(0).getT(0).getT(2).getT(6).getT(0);     // qfade_impl::osc1smooth7_t<NV>
		auto& file_player6 = this->getT(1).getT(0).getT(0).getT(2).getT(6).getT(1);    // qfade_impl::file_player6_t<NV>
		auto& osc1fadegain7 = this->getT(1).getT(0).getT(0).getT(2).getT(6).getT(2);   // core::gain
		auto& gain17 = this->getT(1).getT(0).getT(0).getT(2).getT(6).getT(3);          // core::gain
		auto& jpanner6 = this->getT(1).getT(0).getT(0).getT(2).getT(6).getT(4);        // jdsp::jpanner<NV>
		auto& osc1slot8 = this->getT(1).getT(0).getT(0).getT(2).getT(7);               // qfade_impl::osc1slot8_t<NV>
		auto& osc1smooth8 = this->getT(1).getT(0).getT(0).getT(2).getT(7).getT(0);     // qfade_impl::osc1smooth8_t<NV>
		auto& file_player7 = this->getT(1).getT(0).getT(0).getT(2).getT(7).getT(1);    // qfade_impl::file_player7_t<NV>
		auto& osc1fadegain8 = this->getT(1).getT(0).getT(0).getT(2).getT(7).getT(2);   // core::gain
		auto& gain18 = this->getT(1).getT(0).getT(0).getT(2).getT(7).getT(3);          // core::gain
		auto& jpanner7 = this->getT(1).getT(0).getT(0).getT(2).getT(7).getT(4);        // jdsp::jpanner<NV>
		auto& modchain5 = this->getT(1).getT(0).getT(0).getT(3);                       // qfade_impl::modchain5_t<NV>
		auto& osc1fm3 = this->getT(1).getT(0).getT(0).getT(3).getT(0);                 // qfade_impl::osc1fm3_t<NV>
		auto& split11 = this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(0);         // qfade_impl::split11_t<NV>
		auto& chain3 = this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(0).getT(0);  // qfade_impl::chain3_t<NV>
		auto& add9 = this->getT(1).getT(0).getT(0).getT(3).                            // math::add<NV>
                     getT(0).getT(0).getT(0).getT(0);
		auto& chain22 = this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(0).getT(1); // qfade_impl::chain22_t<NV>
		auto& add10 = this->getT(1).getT(0).getT(0).getT(3).                           // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0);
		auto& peak12 = this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(1);          // qfade_impl::peak12_t<NV>
		auto& pma8 = this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(2);            // qfade_impl::pma8_t<NV>
		auto& gain10 = this->getT(1).getT(0).getT(0).getT(4);                          // core::gain
		auto& OSC2 = this->getT(1).getT(0).getT(1);                                    // qfade_impl::OSC2_t<NV>
		auto& split3 = this->getT(1).getT(0).getT(1).getT(0);                          // qfade_impl::split3_t<NV>
		auto& chain14 = this->getT(1).getT(0).getT(1).getT(0).getT(0);                 // qfade_impl::chain14_t<NV>
		auto& modchain3 = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(0);       // qfade_impl::modchain3_t<NV>
		auto& split10 = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(0).getT(0); // qfade_impl::split10_t<NV>
		auto& osc1fm1 = this->getT(1).getT(0).getT(1).getT(0).                         // qfade_impl::osc1fm1_t<NV>
                        getT(0).getT(0).getT(0).getT(0);
		auto& split8 = this->getT(1).getT(0).getT(1).getT(0).                         // qfade_impl::split8_t<NV>
                       getT(0).getT(0).getT(0).getT(0).
                       getT(0);
		auto& chain16 = this->getT(1).getT(0).getT(1).getT(0).getT(0).                // qfade_impl::chain16_t<NV>
                        getT(0).getT(0).getT(0).getT(0).getT(0);
		auto& add1 = this->getT(1).getT(0).getT(1).getT(0).getT(0).                   // math::add<NV>
                     getT(0).getT(0).getT(0).getT(0).getT(0).
                     getT(0);
		auto& sig2mod10 = this->getT(1).getT(0).getT(1).getT(0).                      // wrap::no_process<math::sig2mod<NV>>
                          getT(0).getT(0).getT(0).getT(0).
                          getT(1);
		auto& peak4 = this->getT(1).getT(0).getT(1).getT(0).                          // qfade_impl::peak4_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(2);
		auto& pma15 = this->getT(1).getT(0).getT(1).getT(0).                          // qfade_impl::pma15_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(3);
		auto& chain1 = this->getT(1).getT(0).getT(1).getT(0).                         // qfade_impl::chain1_t<NV>
                       getT(0).getT(0).getT(0).getT(1);
		auto& chain2 = this->getT(1).getT(0).getT(1).getT(0).                         // qfade_impl::chain2_t<NV>
                       getT(0).getT(0).getT(0).getT(1).
                       getT(0);
		auto& add7 = this->getT(1).getT(0).getT(1).getT(0).getT(0).                   // math::add<NV>
                     getT(0).getT(0).getT(1).getT(0).getT(0);
		auto& peak11 = this->getT(1).getT(0).getT(1).getT(0).getT(0).                 // qfade_impl::peak11_t<NV>
                       getT(0).getT(0).getT(1).getT(0).getT(1);
		auto& pma7 = this->getT(1).getT(0).getT(1).getT(0).getT(0).                   // qfade_impl::pma7_t<NV>
                     getT(0).getT(0).getT(1).getT(0).getT(2);
		auto& file_player8 = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(1);   // qfade_impl::file_player8_t<NV>
		auto& gain = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(2);           // core::gain
		auto& frame2_block1 = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(3);  // qfade_impl::frame2_block1_t<NV>
		auto& split5 = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(3).getT(0); // qfade_impl::split5_t<NV>
		auto& chain12 = this->getT(1).getT(0).getT(1).getT(0).                        // qfade_impl::chain12_t<NV>
                        getT(0).getT(3).getT(0).getT(0);
		auto& sig2mod = this->getT(1).getT(0).getT(1).getT(0).                      // math::sig2mod<NV>
                        getT(0).getT(3).getT(0).getT(0).
                        getT(0);
		auto& receive = this->getT(1).getT(0).getT(1).getT(0).                      // routing::receive<stereo_frame_cable>
                        getT(0).getT(3).getT(0).getT(0).
                        getT(1);
		auto& peak = this->getT(1).getT(0).getT(1).getT(0).                         // qfade_impl::peak_t<NV>
                     getT(0).getT(3).getT(0).getT(0).
                     getT(2);
		auto& send = this->getT(1).getT(0).getT(1).getT(0).                         // routing::send<stereo_frame_cable>
                     getT(0).getT(3).getT(0).getT(0).
                     getT(3);
		auto& split7 = this->getT(1).getT(0).getT(1).getT(0).                       // qfade_impl::split7_t<NV>
                       getT(0).getT(3).getT(0).getT(0).
                       getT(4);
		auto& xfade = this->getT(1).getT(0).getT(1).getT(0).getT(0).                // qfade_impl::xfade_t<NV>
                      getT(3).getT(0).getT(0).getT(4).getT(0);
		auto& intensity1 = this->getT(1).getT(0).getT(1).getT(0).getT(0).           // qfade_impl::intensity1_t<NV>
                           getT(3).getT(0).getT(0).getT(4).getT(0).
                           getT(0);
		auto& chain15 = this->getT(1).getT(0).getT(1).getT(0).getT(0).              // qfade_impl::chain15_t<NV>
                        getT(3).getT(0).getT(0).getT(4).getT(1);
		auto& intensity = this->getT(1).getT(0).getT(1).getT(0).getT(0).            // qfade_impl::intensity_t<NV>
                          getT(3).getT(0).getT(0).getT(4).getT(1).
                          getT(0);
		auto& chain21 = this->getT(1).getT(0).getT(1).getT(0).getT(0).              // qfade_impl::chain21_t<NV>
                        getT(3).getT(0).getT(0).getT(4).getT(2);
		auto& intensity3 = this->getT(1).getT(0).getT(1).getT(0).getT(0).           // qfade_impl::intensity3_t<NV>
                           getT(3).getT(0).getT(0).getT(4).getT(2).
                           getT(0);
		auto& chain23 = this->getT(1).getT(0).getT(1).getT(0).getT(0).              // qfade_impl::chain23_t<NV>
                        getT(3).getT(0).getT(0).getT(4).getT(3);
		auto& intensity5 = this->getT(1).getT(0).getT(1).getT(0).getT(0).           // qfade_impl::intensity5_t<NV>
                           getT(3).getT(0).getT(0).getT(4).getT(3).
                           getT(0);
		auto& clear = this->getT(1).getT(0).getT(1).getT(0).                        // math::clear<NV>
                      getT(0).getT(3).getT(0).getT(0).
                      getT(5);
		auto& chain13 = this->getT(1).getT(0).getT(1).getT(0).                      // qfade_impl::chain13_t
                        getT(0).getT(3).getT(0).getT(1);
		auto& gain8 = this->getT(1).getT(0).getT(1).getT(0).                        // core::gain
                      getT(0).getT(3).getT(0).getT(1).
                      getT(0);
		auto& chain18 = this->getT(1).getT(1);                                      // qfade_impl::chain18_t<NV>
		auto& modchain4 = this->getT(1).getT(1).getT(0);                            // qfade_impl::modchain4_t<NV>
		auto& osc1fm2 = this->getT(1).getT(1).getT(0).getT(0);                      // qfade_impl::osc1fm2_t<NV>
		auto& split9 = this->getT(1).getT(1).getT(0).getT(0).getT(0);               // qfade_impl::split9_t<NV>
		auto& chain19 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);      // qfade_impl::chain19_t<NV>
		auto& add5 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0); // math::add<NV>
		auto& chain20 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(1);      // qfade_impl::chain20_t<NV>
		auto& add6 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(1).getT(0); // math::add<NV>
		auto& sig2mod11 = this->getT(1).getT(1).getT(0).getT(0).getT(1);            // wrap::no_process<math::sig2mod<NV>>
		auto& peak8 = this->getT(1).getT(1).getT(0).getT(0).getT(2);                // qfade_impl::peak8_t<NV>
		auto& pma16 = this->getT(1).getT(1).getT(0).getT(0).getT(3);                // qfade_impl::pma16_t<NV>
		auto& svf = this->getT(1).getT(1).getT(1);                                  // filters::svf<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& smooth_p = this->getParameterT(0);
		smooth_p.connectT(0, osc1smooth1); // smooth -> osc1smooth1::SmoothingTime
		smooth_p.connectT(1, osc1smooth2); // smooth -> osc1smooth2::SmoothingTime
		smooth_p.connectT(2, osc1smooth3); // smooth -> osc1smooth3::SmoothingTime
		smooth_p.connectT(3, osc1smooth4); // smooth -> osc1smooth4::SmoothingTime
		smooth_p.connectT(4, osc1smooth4); // smooth -> osc1smooth4::SmoothingTime
		smooth_p.connectT(5, osc1smooth5); // smooth -> osc1smooth5::SmoothingTime
		smooth_p.connectT(6, osc1smooth7); // smooth -> osc1smooth7::SmoothingTime
		smooth_p.connectT(7, osc1smooth8); // smooth -> osc1smooth8::SmoothingTime
		
		this->getParameterT(1).connectT(0, pma3); // xfade -> pma3::Value
		
		this->getParameterT(2).connectT(0, XfadeMod); // xfade_mod_source -> XfadeMod::xfade_mod_source
		
		this->getParameterT(3).connectT(0, XfadeMod); // xfade_mod1 -> XfadeMod::modamount
		
		this->getParameterT(4).connectT(0, PitchMod1); // osc1_mod_source -> PitchMod1::xfade_mod_source
		
		this->getParameterT(6).connectT(0, PitchMod2); // osc2_modsource -> PitchMod2::xfade_mod_source
		
		this->getParameterT(7).connectT(0, PitchMod2); // osc2mod -> PitchMod2::modamount
		
		this->getParameterT(8).connectT(0, FeedMod1); // filter_mod_source -> FeedMod1::xfade_mod_source
		
		this->getParameterT(9).connectT(0, FeedMod1); // filter_mod -> FeedMod1::modamount
		
		auto& mod1_tempo_p = this->getParameterT(10);
		mod1_tempo_p.connectT(0, XfadeMod);  // mod1_tempo -> XfadeMod::mod1_tempo
		mod1_tempo_p.connectT(1, PitchMod1); // mod1_tempo -> PitchMod1::mod1_tempo
		mod1_tempo_p.connectT(2, PitchMod2); // mod1_tempo -> PitchMod2::mod1_tempo
		mod1_tempo_p.connectT(3, FMMod);     // mod1_tempo -> FMMod::mod1_tempo
		mod1_tempo_p.connectT(4, FeedMod);   // mod1_tempo -> FeedMod::mod1_tempo
		mod1_tempo_p.connectT(5, FeedMod1);  // mod1_tempo -> FeedMod1::mod1_tempo
		
		auto& mod1_div_p = this->getParameterT(11);
		mod1_div_p.connectT(0, XfadeMod);  // mod1_div -> XfadeMod::mod1_div
		mod1_div_p.connectT(1, PitchMod1); // mod1_div -> PitchMod1::mod1_div
		mod1_div_p.connectT(2, PitchMod2); // mod1_div -> PitchMod2::mod1_div
		mod1_div_p.connectT(3, FMMod);     // mod1_div -> FMMod::mod1_div
		mod1_div_p.connectT(4, FeedMod);   // mod1_div -> FeedMod::mod1_div
		mod1_div_p.connectT(5, FeedMod1);  // mod1_div -> FeedMod1::mod1_div
		
		auto& mod1_oneshot_p = this->getParameterT(12);
		mod1_oneshot_p.connectT(0, XfadeMod);  // mod1_oneshot -> XfadeMod::mod1_oneshot
		mod1_oneshot_p.connectT(1, PitchMod1); // mod1_oneshot -> PitchMod1::mod1_oneshot
		mod1_oneshot_p.connectT(2, PitchMod2); // mod1_oneshot -> PitchMod2::mod1_oneshot
		mod1_oneshot_p.connectT(3, FMMod);     // mod1_oneshot -> FMMod::mod1_oneshot
		mod1_oneshot_p.connectT(4, FeedMod);   // mod1_oneshot -> FeedMod::mod1_oneshot
		mod1_oneshot_p.connectT(5, FeedMod1);  // mod1_oneshot -> FeedMod1::mod1_oneshot
		
		auto& mod1_trig_p = this->getParameterT(13);
		mod1_trig_p.connectT(0, XfadeMod);  // mod1_trig -> XfadeMod::mod1_trig
		mod1_trig_p.connectT(1, PitchMod1); // mod1_trig -> PitchMod1::mod1_trig
		mod1_trig_p.connectT(2, PitchMod2); // mod1_trig -> PitchMod2::mod1_trig
		mod1_trig_p.connectT(3, FMMod);     // mod1_trig -> FMMod::mod1_trig
		mod1_trig_p.connectT(4, FeedMod);   // mod1_trig -> FeedMod::mod1_trig
		mod1_trig_p.connectT(5, FeedMod1);  // mod1_trig -> FeedMod1::mod1_trig
		
		auto& mod2_tempo_p = this->getParameterT(15);
		mod2_tempo_p.connectT(0, XfadeMod);  // mod2_tempo -> XfadeMod::mod2_tempo
		mod2_tempo_p.connectT(1, PitchMod1); // mod2_tempo -> PitchMod1::mod2_tempo
		mod2_tempo_p.connectT(2, PitchMod2); // mod2_tempo -> PitchMod2::mod2_tempo
		mod2_tempo_p.connectT(3, FMMod);     // mod2_tempo -> FMMod::mod2_tempo
		mod2_tempo_p.connectT(4, FeedMod);   // mod2_tempo -> FeedMod::mod2_tempo
		mod2_tempo_p.connectT(5, FeedMod1);  // mod2_tempo -> FeedMod1::mod2_tempo
		
		auto& mod2_div_p = this->getParameterT(16);
		mod2_div_p.connectT(0, XfadeMod);  // mod2_div -> XfadeMod::mod2_div
		mod2_div_p.connectT(1, PitchMod1); // mod2_div -> PitchMod1::mod2_div
		mod2_div_p.connectT(2, PitchMod2); // mod2_div -> PitchMod2::mod2_div
		mod2_div_p.connectT(3, FMMod);     // mod2_div -> FMMod::mod2_div
		mod2_div_p.connectT(4, FeedMod);   // mod2_div -> FeedMod::mod2_div
		mod2_div_p.connectT(5, FeedMod1);  // mod2_div -> FeedMod1::mod2_div
		
		auto& mod2_oneshot_p = this->getParameterT(17);
		mod2_oneshot_p.connectT(0, XfadeMod);  // mod2_oneshot -> XfadeMod::mod2_oneshot
		mod2_oneshot_p.connectT(1, PitchMod1); // mod2_oneshot -> PitchMod1::mod2_oneshot
		mod2_oneshot_p.connectT(2, PitchMod2); // mod2_oneshot -> PitchMod2::mod2_oneshot
		mod2_oneshot_p.connectT(3, FMMod);     // mod2_oneshot -> FMMod::mod2_oneshot
		mod2_oneshot_p.connectT(4, FeedMod);   // mod2_oneshot -> FeedMod::mod2_oneshot
		mod2_oneshot_p.connectT(5, FeedMod1);  // mod2_oneshot -> FeedMod1::mod2_oneshot
		
		auto& mod2_trig_p = this->getParameterT(18);
		mod2_trig_p.connectT(0, XfadeMod);  // mod2_trig -> XfadeMod::mod2_trig
		mod2_trig_p.connectT(1, PitchMod1); // mod2_trig -> PitchMod1::mod2_trig
		mod2_trig_p.connectT(2, PitchMod2); // mod2_trig -> PitchMod2::mod2_trig
		mod2_trig_p.connectT(3, FMMod);     // mod2_trig -> FMMod::mod2_trig
		mod2_trig_p.connectT(4, FeedMod);   // mod2_trig -> FeedMod::mod2_trig
		mod2_trig_p.connectT(5, FeedMod1);  // mod2_trig -> FeedMod1::mod2_trig
		
		auto& mod2_type_p = this->getParameterT(19);
		mod2_type_p.connectT(0, XfadeMod);  // mod2_type -> XfadeMod::mod2_type
		mod2_type_p.connectT(1, PitchMod1); // mod2_type -> PitchMod1::mod2_type
		mod2_type_p.connectT(2, PitchMod2); // mod2_type -> PitchMod2::mod2_type
		mod2_type_p.connectT(3, FMMod);     // mod2_type -> FMMod::mod2_type
		mod2_type_p.connectT(4, FeedMod);   // mod2_type -> FeedMod::mod2_type
		mod2_type_p.connectT(5, FeedMod1);  // mod2_type -> FeedMod1::mod2_type
		
		auto& mod3_tempo_p = this->getParameterT(20);
		mod3_tempo_p.connectT(0, XfadeMod);  // mod3_tempo -> XfadeMod::mod3_tempo
		mod3_tempo_p.connectT(1, PitchMod1); // mod3_tempo -> PitchMod1::mod3_tempo
		mod3_tempo_p.connectT(2, PitchMod2); // mod3_tempo -> PitchMod2::mod3_tempo
		mod3_tempo_p.connectT(3, FMMod);     // mod3_tempo -> FMMod::mod3_tempo
		mod3_tempo_p.connectT(4, FeedMod);   // mod3_tempo -> FeedMod::mod3_tempo
		mod3_tempo_p.connectT(5, FeedMod1);  // mod3_tempo -> FeedMod1::mod3_tempo
		
		auto& mod3_div_p = this->getParameterT(21);
		mod3_div_p.connectT(0, XfadeMod);  // mod3_div -> XfadeMod::mod3_div
		mod3_div_p.connectT(1, PitchMod1); // mod3_div -> PitchMod1::mod3_div
		mod3_div_p.connectT(2, PitchMod2); // mod3_div -> PitchMod2::mod3_div
		mod3_div_p.connectT(3, FMMod);     // mod3_div -> FMMod::mod3_div
		mod3_div_p.connectT(4, FeedMod);   // mod3_div -> FeedMod::mod3_div
		mod3_div_p.connectT(5, FeedMod1);  // mod3_div -> FeedMod1::mod3_div
		
		auto& mod3_oneshot_p = this->getParameterT(22);
		mod3_oneshot_p.connectT(0, XfadeMod);  // mod3_oneshot -> XfadeMod::mod3_oneshot
		mod3_oneshot_p.connectT(1, PitchMod1); // mod3_oneshot -> PitchMod1::mod3_oneshot
		mod3_oneshot_p.connectT(2, PitchMod2); // mod3_oneshot -> PitchMod2::mod3_oneshot
		mod3_oneshot_p.connectT(3, FMMod);     // mod3_oneshot -> FMMod::mod3_oneshot
		mod3_oneshot_p.connectT(4, FeedMod);   // mod3_oneshot -> FeedMod::mod3_oneshot
		mod3_oneshot_p.connectT(5, FeedMod1);  // mod3_oneshot -> FeedMod1::mod3_oneshot
		
		auto& mod3_trig_p = this->getParameterT(23);
		mod3_trig_p.connectT(0, XfadeMod);  // mod3_trig -> XfadeMod::mod3_trig
		mod3_trig_p.connectT(1, PitchMod1); // mod3_trig -> PitchMod1::mod3_trig
		mod3_trig_p.connectT(2, PitchMod2); // mod3_trig -> PitchMod2::mod3_trig
		mod3_trig_p.connectT(3, FMMod);     // mod3_trig -> FMMod::mod3_trig
		mod3_trig_p.connectT(4, FeedMod);   // mod3_trig -> FeedMod::mod3_trig
		mod3_trig_p.connectT(5, FeedMod1);  // mod3_trig -> FeedMod1::mod3_trig
		
		auto& mod3_type_p = this->getParameterT(24);
		mod3_type_p.connectT(0, XfadeMod);  // mod3_type -> XfadeMod::mod3_type
		mod3_type_p.connectT(1, PitchMod1); // mod3_type -> PitchMod1::mod3_type
		mod3_type_p.connectT(2, PitchMod2); // mod3_type -> PitchMod2::mod3_type
		mod3_type_p.connectT(3, FMMod);     // mod3_type -> FMMod::mod3_type
		mod3_type_p.connectT(4, FeedMod);   // mod3_type -> FeedMod::mod3_type
		mod3_type_p.connectT(5, FeedMod1);  // mod3_type -> FeedMod1::mod3_type
		
		this->getParameterT(25).connectT(0, pma1); // osc1pitch1A -> pma1::Add
		
		this->getParameterT(33).connectT(0, gain11); // osc1vol1 -> gain11::Gain
		
		this->getParameterT(34).connectT(0, gain12); // osc1vol2 -> gain12::Gain
		
		this->getParameterT(35).connectT(0, gain13); // osc1vol3 -> gain13::Gain
		
		this->getParameterT(36).connectT(0, gain14); // osc1vol4 -> gain14::Gain
		
		this->getParameterT(37).connectT(0, gain15); // osc1vol5 -> gain15::Gain
		
		this->getParameterT(38).connectT(0, gain16); // osc1vol6 -> gain16::Gain
		
		this->getParameterT(39).connectT(0, gain17); // osc1vol7 -> gain17::Gain
		
		this->getParameterT(40).connectT(0, gain18); // osc1vol8 -> gain18::Gain
		
		this->getParameterT(41).connectT(0, jpanner); // osc1pan1 -> jpanner::Pan
		
		this->getParameterT(42).connectT(0, jpanner1); // osc1pan2 -> jpanner1::Pan
		
		this->getParameterT(44).connectT(0, jpanner3); // osc1pan4 -> jpanner3::Pan
		
		this->getParameterT(45).connectT(0, jpanner4); // osc1pan5 -> jpanner4::Pan
		
		this->getParameterT(46).connectT(0, jpanner5); // osc1pan6 -> jpanner5::Pan
		
		this->getParameterT(47).connectT(0, jpanner6); // osc1pan7 -> jpanner6::Pan
		
		this->getParameterT(48).connectT(0, jpanner7); // osc1pan8 -> jpanner7::Pan
		
		auto& modattack1_p = this->getParameterT(49);
		modattack1_p.connectT(0, XfadeMod);  // modattack1 -> XfadeMod::attack1
		modattack1_p.connectT(1, PitchMod1); // modattack1 -> PitchMod1::attack1
		modattack1_p.connectT(2, PitchMod2); // modattack1 -> PitchMod2::attack1
		modattack1_p.connectT(3, FMMod);     // modattack1 -> FMMod::attack1
		modattack1_p.connectT(4, FeedMod);   // modattack1 -> FeedMod::attack1
		modattack1_p.connectT(5, FeedMod1);  // modattack1 -> FeedMod1::attack1
		
		auto& moddecay1_p = this->getParameterT(50);
		moddecay1_p.connectT(0, XfadeMod);  // moddecay1 -> XfadeMod::decay1
		moddecay1_p.connectT(1, PitchMod1); // moddecay1 -> PitchMod1::decay1
		moddecay1_p.connectT(2, PitchMod2); // moddecay1 -> PitchMod2::decay1
		moddecay1_p.connectT(3, FMMod);     // moddecay1 -> FMMod::decay1
		moddecay1_p.connectT(4, FeedMod);   // moddecay1 -> FeedMod::decay1
		moddecay1_p.connectT(5, FeedMod1);  // moddecay1 -> FeedMod1::decay1
		
		auto& modsustain1_p = this->getParameterT(51);
		modsustain1_p.connectT(0, XfadeMod);  // modsustain1 -> XfadeMod::sustain1
		modsustain1_p.connectT(1, PitchMod1); // modsustain1 -> PitchMod1::sustain1
		modsustain1_p.connectT(2, PitchMod2); // modsustain1 -> PitchMod2::sustain1
		modsustain1_p.connectT(3, FMMod);     // modsustain1 -> FMMod::sustain1
		modsustain1_p.connectT(4, FeedMod);   // modsustain1 -> FeedMod::sustain1
		modsustain1_p.connectT(5, FeedMod1);  // modsustain1 -> FeedMod1::sustain1
		
		auto& modrelease1_p = this->getParameterT(52);
		modrelease1_p.connectT(0, XfadeMod);  // modrelease1 -> XfadeMod::release1
		modrelease1_p.connectT(1, PitchMod1); // modrelease1 -> PitchMod1::release1
		modrelease1_p.connectT(2, PitchMod2); // modrelease1 -> PitchMod2::release1
		modrelease1_p.connectT(3, FMMod);     // modrelease1 -> FMMod::release1
		modrelease1_p.connectT(4, FeedMod);   // modrelease1 -> FeedMod::release1
		modrelease1_p.connectT(5, FeedMod1);  // modrelease1 -> FeedMod1::release1
		
		auto& modhold1_p = this->getParameterT(53);
		modhold1_p.connectT(0, XfadeMod);  // modhold1 -> XfadeMod::hold1
		modhold1_p.connectT(1, PitchMod1); // modhold1 -> PitchMod1::hold1
		modhold1_p.connectT(2, PitchMod2); // modhold1 -> PitchMod2::hold1
		modhold1_p.connectT(3, FMMod);     // modhold1 -> FMMod::hold1
		modhold1_p.connectT(4, FeedMod);   // modhold1 -> FeedMod::hold1
		modhold1_p.connectT(5, FeedMod1);  // modhold1 -> FeedMod1::hold1
		
		auto& modattack2_p = this->getParameterT(54);
		modattack2_p.connectT(0, XfadeMod);  // modattack2 -> XfadeMod::attack2
		modattack2_p.connectT(1, PitchMod1); // modattack2 -> PitchMod1::attack2
		modattack2_p.connectT(2, PitchMod2); // modattack2 -> PitchMod2::attack2
		modattack2_p.connectT(3, FMMod);     // modattack2 -> FMMod::attack2
		modattack2_p.connectT(4, FeedMod);   // modattack2 -> FeedMod::attack2
		modattack2_p.connectT(5, FeedMod1);  // modattack2 -> FeedMod1::attack2
		
		auto& moddecay2_p = this->getParameterT(55);
		moddecay2_p.connectT(0, XfadeMod);  // moddecay2 -> XfadeMod::decay2
		moddecay2_p.connectT(1, PitchMod1); // moddecay2 -> PitchMod1::decay2
		moddecay2_p.connectT(2, PitchMod2); // moddecay2 -> PitchMod2::decay2
		moddecay2_p.connectT(3, FMMod);     // moddecay2 -> FMMod::decay2
		moddecay2_p.connectT(4, FeedMod);   // moddecay2 -> FeedMod::decay2
		moddecay2_p.connectT(5, FeedMod1);  // moddecay2 -> FeedMod1::decay2
		
		auto& modsustain2_p = this->getParameterT(56);
		modsustain2_p.connectT(0, XfadeMod);  // modsustain2 -> XfadeMod::sustain2
		modsustain2_p.connectT(1, PitchMod1); // modsustain2 -> PitchMod1::sustain2
		modsustain2_p.connectT(2, PitchMod2); // modsustain2 -> PitchMod2::sustain2
		modsustain2_p.connectT(3, FMMod);     // modsustain2 -> FMMod::sustain2
		modsustain2_p.connectT(4, FeedMod);   // modsustain2 -> FeedMod::sustain2
		modsustain2_p.connectT(5, FeedMod1);  // modsustain2 -> FeedMod1::sustain2
		
		auto& modrelease2_p = this->getParameterT(57);
		modrelease2_p.connectT(0, XfadeMod);  // modrelease2 -> XfadeMod::release2
		modrelease2_p.connectT(1, PitchMod1); // modrelease2 -> PitchMod1::release2
		modrelease2_p.connectT(2, PitchMod2); // modrelease2 -> PitchMod2::release2
		modrelease2_p.connectT(3, FMMod);     // modrelease2 -> FMMod::release2
		modrelease2_p.connectT(4, FeedMod);   // modrelease2 -> FeedMod::release2
		modrelease2_p.connectT(5, FeedMod1);  // modrelease2 -> FeedMod1::release2
		
		auto& modhold2_p = this->getParameterT(58);
		modhold2_p.connectT(0, XfadeMod);  // modhold2 -> XfadeMod::hold2
		modhold2_p.connectT(1, PitchMod1); // modhold2 -> PitchMod1::hold2
		modhold2_p.connectT(2, PitchMod2); // modhold2 -> PitchMod2::hold2
		modhold2_p.connectT(3, FMMod);     // modhold2 -> FMMod::hold2
		modhold2_p.connectT(4, FeedMod);   // modhold2 -> FeedMod::hold2
		modhold2_p.connectT(5, FeedMod1);  // modhold2 -> FeedMod1::hold2
		
		auto& modattack3_p = this->getParameterT(59);
		modattack3_p.connectT(0, XfadeMod);  // modattack3 -> XfadeMod::attack3
		modattack3_p.connectT(1, PitchMod1); // modattack3 -> PitchMod1::attack3
		modattack3_p.connectT(2, PitchMod2); // modattack3 -> PitchMod2::attack3
		modattack3_p.connectT(3, FMMod);     // modattack3 -> FMMod::attack3
		modattack3_p.connectT(4, FeedMod);   // modattack3 -> FeedMod::attack3
		modattack3_p.connectT(5, FeedMod1);  // modattack3 -> FeedMod1::attack3
		
		auto& moddecay3_p = this->getParameterT(60);
		moddecay3_p.connectT(0, XfadeMod);  // moddecay3 -> XfadeMod::decay3
		moddecay3_p.connectT(1, PitchMod1); // moddecay3 -> PitchMod1::decay3
		moddecay3_p.connectT(2, PitchMod2); // moddecay3 -> PitchMod2::decay3
		moddecay3_p.connectT(3, FMMod);     // moddecay3 -> FMMod::decay3
		moddecay3_p.connectT(4, FeedMod);   // moddecay3 -> FeedMod::decay3
		moddecay3_p.connectT(5, FeedMod1);  // moddecay3 -> FeedMod1::decay3
		
		auto& modsustain3_p = this->getParameterT(61);
		modsustain3_p.connectT(0, XfadeMod);  // modsustain3 -> XfadeMod::sustain3
		modsustain3_p.connectT(1, PitchMod1); // modsustain3 -> PitchMod1::sustain3
		modsustain3_p.connectT(2, PitchMod2); // modsustain3 -> PitchMod2::sustain3
		modsustain3_p.connectT(3, FMMod);     // modsustain3 -> FMMod::sustain3
		modsustain3_p.connectT(4, FeedMod);   // modsustain3 -> FeedMod::sustain3
		modsustain3_p.connectT(5, FeedMod1);  // modsustain3 -> FeedMod1::sustain3
		
		auto& modrelease3_p = this->getParameterT(62);
		modrelease3_p.connectT(0, XfadeMod);  // modrelease3 -> XfadeMod::release3
		modrelease3_p.connectT(1, PitchMod1); // modrelease3 -> PitchMod1::release3
		modrelease3_p.connectT(2, PitchMod2); // modrelease3 -> PitchMod2::release3
		modrelease3_p.connectT(3, FMMod);     // modrelease3 -> FMMod::release3
		modrelease3_p.connectT(4, FeedMod);   // modrelease3 -> FeedMod::release3
		modrelease3_p.connectT(5, FeedMod1);  // modrelease3 -> FeedMod1::release3
		
		auto& modhold3_p = this->getParameterT(63);
		modhold3_p.connectT(0, XfadeMod);  // modhold3 -> XfadeMod::hold3
		modhold3_p.connectT(1, PitchMod1); // modhold3 -> PitchMod1::hold3
		modhold3_p.connectT(2, PitchMod2); // modhold3 -> PitchMod2::hold3
		modhold3_p.connectT(3, FMMod);     // modhold3 -> FMMod::hold3
		modhold3_p.connectT(4, FeedMod);   // modhold3 -> FeedMod::hold3
		modhold3_p.connectT(5, FeedMod1);  // modhold3 -> FeedMod1::hold3
		
		this->getParameterT(64).connectT(0, PitchMod1); // pitch1modmodamount -> PitchMod1::modamount
		
		this->getParameterT(65).connectT(0, intensity); // Pitch1FM -> intensity::Intensity
		
		this->getParameterT(66).connectT(0, intensity1); // xfadefm -> intensity1::Intensity
		
		this->getParameterT(67).connectT(0, intensity3); // filterfm -> intensity3::Intensity
		
		this->getParameterT(68).connectT(0, pma8); // osc1mastervol -> pma8::Add
		
		this->getParameterT(69).connectT(0, gain8); // osc2vol -> gain8::Gain
		
		this->getParameterT(70).connectT(0, FeedMod); // osc1_vol_modsource -> FeedMod::xfade_mod_source
		
		this->getParameterT(71).connectT(0, FeedMod); // os1_vol_mod -> FeedMod::modamount
		
		this->getParameterT(72).connectT(0, intensity5); // osc2vol_AM -> intensity5::Intensity
		
		// Modulation Connections ------------------------------------------------------------------
		
		peak3.getParameter().connectT(0, add2);                // peak3 -> add2::Value
		peak5.getParameter().connectT(0, add);                 // peak5 -> add::Value
		peak6.getParameter().connectT(0, add1);                // peak6 -> add1::Value
		peak7.getParameter().connectT(0, add7);                // peak7 -> add7::Value
		peak9.getParameter().connectT(0, add9);                // peak9 -> add9::Value
		peak10.getParameter().connectT(0, add5);               // peak10 -> add5::Value
		osc1smooth1.getParameter().connectT(0, osc1fadegain2); // osc1smooth1 -> osc1fadegain2::Gain
		osc1smooth3.getParameter().connectT(0, osc1fadegain3); // osc1smooth3 -> osc1fadegain3::Gain
		osc1smooth4.getParameter().connectT(0, osc1fadegain4); // osc1smooth4 -> osc1fadegain4::Gain
		osc1smooth5.getParameter().connectT(0, osc1fadegain5); // osc1smooth5 -> osc1fadegain5::Gain
		osc1smooth6.getParameter().connectT(0, osc1fadegain6); // osc1smooth6 -> osc1fadegain6::Gain
		osc1smooth7.getParameter().connectT(0, osc1fadegain7); // osc1smooth7 -> osc1fadegain7::Gain
		osc1smooth8.getParameter().connectT(0, osc1fadegain8); // osc1smooth8 -> osc1fadegain8::Gain
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, osc1smooth1);               // xfader1 -> osc1smooth1::Value
		xfader1_p.getParameterT(1).connectT(0, osc1smooth2);               // xfader1 -> osc1smooth2::Value
		xfader1_p.getParameterT(2).connectT(0, osc1smooth3);               // xfader1 -> osc1smooth3::Value
		xfader1_p.getParameterT(3).connectT(0, osc1smooth4);               // xfader1 -> osc1smooth4::Value
		xfader1_p.getParameterT(4).connectT(0, osc1smooth5);               // xfader1 -> osc1smooth5::Value
		xfader1_p.getParameterT(5).connectT(0, osc1smooth6);               // xfader1 -> osc1smooth6::Value
		xfader1_p.getParameterT(6).connectT(0, osc1smooth7);               // xfader1 -> osc1smooth7::Value
		xfader1_p.getParameterT(7).connectT(0, osc1smooth8);               // xfader1 -> osc1smooth8::Value
		pma3.getWrappedObject().getParameter().connectT(0, xfader1);       // pma3 -> xfader1::Value
		peak1.getParameter().connectT(0, pma3);                            // peak1 -> pma3::Add
		pma1.getWrappedObject().getParameter().connectT(0, file_player);   // pma1 -> file_player::FreqRatio
		pma1.getWrappedObject().getParameter().connectT(1, file_player3);  // pma1 -> file_player3::FreqRatio
		pma1.getWrappedObject().getParameter().connectT(2, file_player2);  // pma1 -> file_player2::FreqRatio
		pma1.getWrappedObject().getParameter().connectT(3, file_player1);  // pma1 -> file_player1::FreqRatio
		pma1.getWrappedObject().getParameter().connectT(4, file_player4);  // pma1 -> file_player4::FreqRatio
		pma1.getWrappedObject().getParameter().connectT(5, file_player5);  // pma1 -> file_player5::FreqRatio
		pma1.getWrappedObject().getParameter().connectT(6, file_player6);  // pma1 -> file_player6::FreqRatio
		pma1.getWrappedObject().getParameter().connectT(7, file_player7);  // pma1 -> file_player7::FreqRatio
		peak2.getParameter().connectT(0, pma1);                            // peak2 -> pma1::Value
		pma8.getWrappedObject().getParameter().connectT(0, gain10);        // pma8 -> gain10::Gain
		peak12.getParameter().connectT(0, pma8);                           // peak12 -> pma8::Value
		pma15.getWrappedObject().getParameter().connectT(0, file_player8); // pma15 -> file_player8::FreqRatio
		peak4.getParameter().connectT(0, pma15);                           // peak4 -> pma15::Value
		pma7.getWrappedObject().getParameter().connectT(0, gain);          // pma7 -> gain::Gain
		peak11.getParameter().connectT(0, pma7);                           // peak11 -> pma7::Value
		intensity.getWrappedObject().getParameter().connectT(0, add3);     // intensity -> add3::Value
		intensity3.getWrappedObject().getParameter().connectT(0, add6);    // intensity3 -> add6::Value
		intensity1.getWrappedObject().getParameter().connectT(0, add8);    // intensity1 -> add8::Value
		intensity5.getWrappedObject().getParameter().connectT(0, add10);   // intensity5 -> add10::Value
		peak.getParameter().connectT(0, intensity);                        // peak -> intensity::Value
		peak.getParameter().connectT(1, intensity3);                       // peak -> intensity3::Value
		peak.getParameter().connectT(2, intensity1);                       // peak -> intensity1::Value
		peak.getParameter().connectT(3, intensity5);                       // peak -> intensity5::Value
		pma16.getWrappedObject().getParameter().connectT(0, svf);          // pma16 -> svf::Frequency
		peak8.getParameter().connectT(0, pma16);                           // peak8 -> pma16::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
		; // XfadeMod::xfade_mod_source is automated
		; // XfadeMod::mod1_tempo is automated
		; // XfadeMod::mod1_div is automated
		; // XfadeMod::mod1_oneshot is automated
		; // XfadeMod::mod1_trig is automated
		; // XfadeMod::modamount is automated
		; // XfadeMod::mod2_tempo is automated
		; // XfadeMod::mod2_div is automated
		; // XfadeMod::mod2_oneshot is automated
		; // XfadeMod::mod2_trig is automated
		; // XfadeMod::mod2_type is automated
		; // XfadeMod::mod3_tempo is automated
		; // XfadeMod::mod3_div is automated
		; // XfadeMod::mod3_oneshot is automated
		; // XfadeMod::mod3_trig is automated
		; // XfadeMod::mod3_type is automated
		; // XfadeMod::attack1 is automated
		; // XfadeMod::decay1 is automated
		; // XfadeMod::sustain1 is automated
		; // XfadeMod::release1 is automated
		; // XfadeMod::hold1 is automated
		; // XfadeMod::attack2 is automated
		; // XfadeMod::decay2 is automated
		; // XfadeMod::sustain2 is automated
		; // XfadeMod::release2 is automated
		; // XfadeMod::hold2 is automated
		; // XfadeMod::attack3 is automated
		; // XfadeMod::decay3 is automated
		; // XfadeMod::sustain3 is automated
		; // XfadeMod::release3 is automated
		; // XfadeMod::hold3 is automated
		
		sig2mod1.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // PitchMod1::xfade_mod_source is automated
		; // PitchMod1::mod1_tempo is automated
		; // PitchMod1::mod1_div is automated
		; // PitchMod1::mod1_oneshot is automated
		; // PitchMod1::mod1_trig is automated
		; // PitchMod1::modamount is automated
		; // PitchMod1::mod2_tempo is automated
		; // PitchMod1::mod2_div is automated
		; // PitchMod1::mod2_oneshot is automated
		; // PitchMod1::mod2_trig is automated
		; // PitchMod1::mod2_type is automated
		; // PitchMod1::mod3_tempo is automated
		; // PitchMod1::mod3_div is automated
		; // PitchMod1::mod3_oneshot is automated
		; // PitchMod1::mod3_trig is automated
		; // PitchMod1::mod3_type is automated
		; // PitchMod1::attack1 is automated
		; // PitchMod1::decay1 is automated
		; // PitchMod1::sustain1 is automated
		; // PitchMod1::release1 is automated
		; // PitchMod1::hold1 is automated
		; // PitchMod1::attack2 is automated
		; // PitchMod1::decay2 is automated
		; // PitchMod1::sustain2 is automated
		; // PitchMod1::release2 is automated
		; // PitchMod1::hold2 is automated
		; // PitchMod1::attack3 is automated
		; // PitchMod1::decay3 is automated
		; // PitchMod1::sustain3 is automated
		; // PitchMod1::release3 is automated
		; // PitchMod1::hold3 is automated
		
		sig2mod3.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // PitchMod2::xfade_mod_source is automated
		; // PitchMod2::mod1_tempo is automated
		; // PitchMod2::mod1_div is automated
		; // PitchMod2::mod1_oneshot is automated
		; // PitchMod2::mod1_trig is automated
		; // PitchMod2::modamount is automated
		; // PitchMod2::mod2_tempo is automated
		; // PitchMod2::mod2_div is automated
		; // PitchMod2::mod2_oneshot is automated
		; // PitchMod2::mod2_trig is automated
		; // PitchMod2::mod2_type is automated
		; // PitchMod2::mod3_tempo is automated
		; // PitchMod2::mod3_div is automated
		; // PitchMod2::mod3_oneshot is automated
		; // PitchMod2::mod3_trig is automated
		; // PitchMod2::mod3_type is automated
		; // PitchMod2::attack1 is automated
		; // PitchMod2::decay1 is automated
		; // PitchMod2::sustain1 is automated
		; // PitchMod2::release1 is automated
		; // PitchMod2::hold1 is automated
		; // PitchMod2::attack2 is automated
		; // PitchMod2::decay2 is automated
		; // PitchMod2::sustain2 is automated
		; // PitchMod2::release2 is automated
		; // PitchMod2::hold2 is automated
		; // PitchMod2::attack3 is automated
		; // PitchMod2::decay3 is automated
		; // PitchMod2::sustain3 is automated
		; // PitchMod2::release3 is automated
		; // PitchMod2::hold3 is automated
		
		sig2mod4.setParameterT(0, 0.); // math::sig2mod::Value
		
		FMMod.setParameterT(0, 0.); // project::XfadeMod::xfade_mod_source
		;                           // FMMod::mod1_tempo is automated
		;                           // FMMod::mod1_div is automated
		;                           // FMMod::mod1_oneshot is automated
		;                           // FMMod::mod1_trig is automated
		FMMod.setParameterT(5, 0.); // project::XfadeMod::modamount
		;                           // FMMod::mod2_tempo is automated
		;                           // FMMod::mod2_div is automated
		;                           // FMMod::mod2_oneshot is automated
		;                           // FMMod::mod2_trig is automated
		;                           // FMMod::mod2_type is automated
		;                           // FMMod::mod3_tempo is automated
		;                           // FMMod::mod3_div is automated
		;                           // FMMod::mod3_oneshot is automated
		;                           // FMMod::mod3_trig is automated
		;                           // FMMod::mod3_type is automated
		;                           // FMMod::attack1 is automated
		;                           // FMMod::decay1 is automated
		;                           // FMMod::sustain1 is automated
		;                           // FMMod::release1 is automated
		;                           // FMMod::hold1 is automated
		;                           // FMMod::attack2 is automated
		;                           // FMMod::decay2 is automated
		;                           // FMMod::sustain2 is automated
		;                           // FMMod::release2 is automated
		;                           // FMMod::hold2 is automated
		;                           // FMMod::attack3 is automated
		;                           // FMMod::decay3 is automated
		;                           // FMMod::sustain3 is automated
		;                           // FMMod::release3 is automated
		;                           // FMMod::hold3 is automated
		
		sig2mod5.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // FeedMod::xfade_mod_source is automated
		; // FeedMod::mod1_tempo is automated
		; // FeedMod::mod1_div is automated
		; // FeedMod::mod1_oneshot is automated
		; // FeedMod::mod1_trig is automated
		; // FeedMod::modamount is automated
		; // FeedMod::mod2_tempo is automated
		; // FeedMod::mod2_div is automated
		; // FeedMod::mod2_oneshot is automated
		; // FeedMod::mod2_trig is automated
		; // FeedMod::mod2_type is automated
		; // FeedMod::mod3_tempo is automated
		; // FeedMod::mod3_div is automated
		; // FeedMod::mod3_oneshot is automated
		; // FeedMod::mod3_trig is automated
		; // FeedMod::mod3_type is automated
		; // FeedMod::attack1 is automated
		; // FeedMod::decay1 is automated
		; // FeedMod::sustain1 is automated
		; // FeedMod::release1 is automated
		; // FeedMod::hold1 is automated
		; // FeedMod::attack2 is automated
		; // FeedMod::decay2 is automated
		; // FeedMod::sustain2 is automated
		; // FeedMod::release2 is automated
		; // FeedMod::hold2 is automated
		; // FeedMod::attack3 is automated
		; // FeedMod::decay3 is automated
		; // FeedMod::sustain3 is automated
		; // FeedMod::release3 is automated
		; // FeedMod::hold3 is automated
		
		sig2mod7.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // FeedMod1::xfade_mod_source is automated
		; // FeedMod1::mod1_tempo is automated
		; // FeedMod1::mod1_div is automated
		; // FeedMod1::mod1_oneshot is automated
		; // FeedMod1::mod1_trig is automated
		; // FeedMod1::modamount is automated
		; // FeedMod1::mod2_tempo is automated
		; // FeedMod1::mod2_div is automated
		; // FeedMod1::mod2_oneshot is automated
		; // FeedMod1::mod2_trig is automated
		; // FeedMod1::mod2_type is automated
		; // FeedMod1::mod3_tempo is automated
		; // FeedMod1::mod3_div is automated
		; // FeedMod1::mod3_oneshot is automated
		; // FeedMod1::mod3_trig is automated
		; // FeedMod1::mod3_type is automated
		; // FeedMod1::attack1 is automated
		; // FeedMod1::decay1 is automated
		; // FeedMod1::sustain1 is automated
		; // FeedMod1::release1 is automated
		; // FeedMod1::hold1 is automated
		; // FeedMod1::attack2 is automated
		; // FeedMod1::decay2 is automated
		; // FeedMod1::sustain2 is automated
		; // FeedMod1::release2 is automated
		; // FeedMod1::hold2 is automated
		; // FeedMod1::attack3 is automated
		; // FeedMod1::decay3 is automated
		; // FeedMod1::sustain3 is automated
		; // FeedMod1::release3 is automated
		; // FeedMod1::hold3 is automated
		
		sig2mod8.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // add2::Value is automated
		
		; // add8::Value is automated
		
		sig2mod2.setParameterT(0, 6.16984); // math::sig2mod::Value
		
		;                          // pma3::Value is automated
		pma3.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma3::Add is automated
		
		; // xfader1::Value is automated
		
		; // add::Value is automated
		
		; // add3::Value is automated
		
		sig2mod9.setParameterT(0, -0.979271); // math::sig2mod::Value
		
		;                          // pma1::Value is automated
		pma1.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma1::Add is automated
		
		split.setParameterT(0, 0.515542); // container::split::pitch
		
		;                                 // osc1smooth1::Value is automated
		;                                 // osc1smooth1::SmoothingTime is automated
		osc1smooth1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		file_player.setParameterT(0, 2.);      // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);      // core::file_player::Gate
		file_player.setParameterT(2, 523.995); // core::file_player::RootFrequency
		;                                      // file_player::FreqRatio is automated
		
		;                                     // osc1fadegain2::Gain is automated
		osc1fadegain2.setParameterT(1, 28.4); // core::gain::Smoothing
		osc1fadegain2.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                             // gain11::Gain is automated
		gain11.setParameterT(1, 20.); // core::gain::Smoothing
		gain11.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                 // osc1smooth2::Value is automated
		;                                 // osc1smooth2::SmoothingTime is automated
		osc1smooth2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		file_player3.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player3.setParameterT(1, 1.);   // core::file_player::Gate
		file_player3.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player3::FreqRatio is automated
		
		osc1fadegain1.setParameterT(0, 0.);  // core::gain::Gain
		osc1fadegain1.setParameterT(1, 20.); // core::gain::Smoothing
		osc1fadegain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // gain12::Gain is automated
		gain12.setParameterT(1, 20.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                              // jpanner1::Pan is automated
		jpanner1.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                 // osc1smooth3::Value is automated
		;                                 // osc1smooth3::SmoothingTime is automated
		osc1smooth3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		file_player2.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player2.setParameterT(1, 1.);   // core::file_player::Gate
		file_player2.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player2::FreqRatio is automated
		
		;                                    // osc1fadegain3::Gain is automated
		osc1fadegain3.setParameterT(1, 20.); // core::gain::Smoothing
		osc1fadegain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // gain13::Gain is automated
		gain13.setParameterT(1, 20.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.);  // core::gain::ResetValue
		
		jpanner2.setParameterT(0, 3.74091); // jdsp::jpanner::Pan
		jpanner2.setParameterT(1, 1.);      // jdsp::jpanner::Rule
		
		;                                 // osc1smooth4::Value is automated
		;                                 // osc1smooth4::SmoothingTime is automated
		osc1smooth4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		file_player1.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player1.setParameterT(1, 1.);   // core::file_player::Gate
		file_player1.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player1::FreqRatio is automated
		
		;                                    // osc1fadegain4::Gain is automated
		osc1fadegain4.setParameterT(1, 20.); // core::gain::Smoothing
		osc1fadegain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // gain14::Gain is automated
		gain14.setParameterT(1, 20.); // core::gain::Smoothing
		gain14.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                              // jpanner3::Pan is automated
		jpanner3.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                 // osc1smooth5::Value is automated
		;                                 // osc1smooth5::SmoothingTime is automated
		osc1smooth5.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		file_player4.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player4.setParameterT(1, 1.);   // core::file_player::Gate
		file_player4.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player4::FreqRatio is automated
		
		;                                    // osc1fadegain5::Gain is automated
		osc1fadegain5.setParameterT(1, 20.); // core::gain::Smoothing
		osc1fadegain5.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // gain15::Gain is automated
		gain15.setParameterT(1, 20.); // core::gain::Smoothing
		gain15.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                              // jpanner4::Pan is automated
		jpanner4.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                 // osc1smooth6::Value is automated
		osc1smooth6.setParameterT(1, 0.); // control::smoothed_parameter::SmoothingTime
		osc1smooth6.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		file_player5.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player5.setParameterT(1, 1.);   // core::file_player::Gate
		file_player5.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player5::FreqRatio is automated
		
		;                                    // osc1fadegain6::Gain is automated
		osc1fadegain6.setParameterT(1, 20.); // core::gain::Smoothing
		osc1fadegain6.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // gain16::Gain is automated
		gain16.setParameterT(1, 20.); // core::gain::Smoothing
		gain16.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                              // jpanner5::Pan is automated
		jpanner5.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                 // osc1smooth7::Value is automated
		;                                 // osc1smooth7::SmoothingTime is automated
		osc1smooth7.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		file_player6.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player6.setParameterT(1, 1.);   // core::file_player::Gate
		file_player6.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player6::FreqRatio is automated
		
		;                                    // osc1fadegain7::Gain is automated
		osc1fadegain7.setParameterT(1, 20.); // core::gain::Smoothing
		osc1fadegain7.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // gain17::Gain is automated
		gain17.setParameterT(1, 20.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                              // jpanner6::Pan is automated
		jpanner6.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                 // osc1smooth8::Value is automated
		;                                 // osc1smooth8::SmoothingTime is automated
		osc1smooth8.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		file_player7.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player7.setParameterT(1, 1.);   // core::file_player::Gate
		file_player7.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player7::FreqRatio is automated
		
		;                                    // osc1fadegain8::Gain is automated
		osc1fadegain8.setParameterT(1, 20.); // core::gain::Smoothing
		osc1fadegain8.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // gain18::Gain is automated
		gain18.setParameterT(1, 20.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                              // jpanner7::Pan is automated
		jpanner7.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		; // add9::Value is automated
		
		; // add10::Value is automated
		
		;                          // pma8::Value is automated
		pma8.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma8::Add is automated
		
		;                             // gain10::Gain is automated
		gain10.setParameterT(1, 20.); // core::gain::Smoothing
		gain10.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add1::Value is automated
		
		sig2mod10.setParameterT(0, -0.0446074); // math::sig2mod::Value
		
		;                                  // pma15::Value is automated
		pma15.setParameterT(1, 1.);        // control::pma::Multiply
		pma15.setParameterT(2, 0.0624711); // control::pma::Add
		
		; // add7::Value is automated
		
		;                                // pma7::Value is automated
		pma7.setParameterT(1, 1.);       // control::pma::Multiply
		pma7.setParameterT(2, 0.915838); // control::pma::Add
		
		file_player8.setParameterT(0, 2.);      // core::file_player::PlaybackMode
		file_player8.setParameterT(1, 1.);      // core::file_player::Gate
		file_player8.setParameterT(2, 1.40516); // core::file_player::RootFrequency
		;                                       // file_player8::FreqRatio is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		receive.setParameterT(0, 0.); // routing::receive::Feedback
		
		; // intensity1::Value is automated
		; // intensity1::Intensity is automated
		
		; // intensity::Value is automated
		; // intensity::Intensity is automated
		
		; // intensity3::Value is automated
		; // intensity3::Intensity is automated
		
		; // intensity5::Value is automated
		; // intensity5::Intensity is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                             // gain8::Gain is automated
		gain8.setParameterT(1, 25.2); // core::gain::Smoothing
		gain8.setParameterT(2, -66.); // core::gain::ResetValue
		
		; // add5::Value is automated
		
		; // add6::Value is automated
		
		sig2mod11.setParameterT(0, 0.000654297); // math::sig2mod::Value
		
		;                           // pma16::Value is automated
		pma16.setParameterT(1, 1.); // control::pma::Multiply
		pma16.setParameterT(2, 1.); // control::pma::Add
		
		;                           // svf::Frequency is automated
		svf.setParameterT(1, 0.3);  // filters::svf::Q
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.00164435);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 0.);
		this->setParameterT(13, 0.);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 0.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 1.);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 0.999189);
		this->setParameterT(25, 0.47004);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 0.5);
		this->setParameterT(28, 0.5);
		this->setParameterT(29, 0.5);
		this->setParameterT(30, 0.5);
		this->setParameterT(31, 0.5);
		this->setParameterT(32, 0.5);
		this->setParameterT(33, 0.52601);
		this->setParameterT(34, 0.511828);
		this->setParameterT(35, 0.494937);
		this->setParameterT(36, 0.502547);
		this->setParameterT(37, 0.491687);
		this->setParameterT(38, 0.497063);
		this->setParameterT(39, 0.495594);
		this->setParameterT(40, 0.49425);
		this->setParameterT(41, -0.123355);
		this->setParameterT(42, 0.252835);
		this->setParameterT(43, 0.470003);
		this->setParameterT(44, 0.443612);
		this->setParameterT(45, 0.494544);
		this->setParameterT(46, 0.439941);
		this->setParameterT(47, 0.476766);
		this->setParameterT(48, 0.492995);
		this->setParameterT(49, 1.);
		this->setParameterT(50, 1.);
		this->setParameterT(51, 1.);
		this->setParameterT(52, 1.);
		this->setParameterT(53, 1.);
		this->setParameterT(54, 1.);
		this->setParameterT(55, 1.);
		this->setParameterT(56, 1.);
		this->setParameterT(57, 1.);
		this->setParameterT(58, 1.);
		this->setParameterT(59, 1.);
		this->setParameterT(60, 1.);
		this->setParameterT(61, 1.);
		this->setParameterT(62, 1.);
		this->setParameterT(63, 1.);
		this->setParameterT(64, 0.991615);
		this->setParameterT(65, 0.123581);
		this->setParameterT(66, 0.194071);
		this->setParameterT(67, 0.);
		this->setParameterT(68, 1.);
		this->setParameterT(69, 0.);
		this->setParameterT(70, 0.);
		this->setParameterT(71, 0.);
		this->setParameterT(72, 0.926461);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(2).setExternalData(b, index);                         // qfade_impl::peak3_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index);                         // qfade_impl::peak5_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index);                         // qfade_impl::peak6_t<NV>
		this->getT(0).getT(3).getT(2).setExternalData(b, index);                         // qfade_impl::peak7_t<NV>
		this->getT(0).getT(4).getT(2).setExternalData(b, index);                         // qfade_impl::peak9_t<NV>
		this->getT(0).getT(5).getT(2).setExternalData(b, index);                         // qfade_impl::peak10_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // qfade_impl::peak1_t<NV>
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(2).setExternalData(b, index); // qfade_impl::peak2_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(1).setExternalData(b, index); // qfade_impl::file_player_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(1).getT(1).setExternalData(b, index); // qfade_impl::file_player3_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).setExternalData(b, index); // qfade_impl::file_player2_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(1).setExternalData(b, index); // qfade_impl::file_player1_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(4).getT(1).setExternalData(b, index); // qfade_impl::file_player4_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(5).getT(1).setExternalData(b, index); // qfade_impl::file_player5_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(6).getT(1).setExternalData(b, index); // qfade_impl::file_player6_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(7).getT(1).setExternalData(b, index); // qfade_impl::file_player7_t<NV>
		this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(1).setExternalData(b, index); // qfade_impl::peak12_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).                                           // qfade_impl::peak4_t<NV>
        getT(0).getT(0).getT(0).getT(0).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(1).getT(0).getT(0).                                   // qfade_impl::peak11_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index); // qfade_impl::file_player8_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).                                           // qfade_impl::peak_t<NV>
        getT(0).getT(3).getT(0).getT(0).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(1).getT(0).getT(0).getT(2).setExternalData(b, index); // qfade_impl::peak8_t<NV>
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
using qfade = wrap::node<qfade_impl::instance<NV>>;
}


