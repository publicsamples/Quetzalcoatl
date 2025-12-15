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

template <int NV>
using xfader_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::switcher>;

template <int NV> using xfader1_multimod = xfader_multimod<NV>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV> using xfader2_multimod = xfader_multimod<NV>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::squared>;

template <int NV> using xfader3_multimod = xfader_multimod<NV>;

template <int NV>
using xfader3_t = control::xfader<xfader3_multimod<NV>, faders::cosine_half>;

template <int NV> using xfader4_multimod = xfader_multimod<NV>;

template <int NV>
using xfader4_t = control::xfader<xfader4_multimod<NV>, faders::threshold>;

template <int NV> using xfader5_multimod = xfader_multimod<NV>;

template <int NV>
using xfader5_t = control::xfader<xfader5_multimod<NV>, faders::rms>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<1>>;

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<2>>;

template <int NV>
using cable_table3_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<3>>;

template <int NV>
using cable_table4_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<4>>;

template <int NV>
using cable_table5_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<5>>;

template <int NV>
using cable_table6_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<6>>;

template <int NV>
using cable_table7_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<7>>;

template <int NV>
using xfader6_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                         parameter::plain<math::add<NV>, 0>, 
                                         parameter::plain<math::add<NV>, 0>, 
                                         parameter::plain<math::add<NV>, 0>>;

template <int NV>
using xfader6_t = control::xfader<xfader6_multimod<NV>, faders::switcher>;

template <int NV> using xfader7_multimod = xfader6_multimod<NV>;

template <int NV>
using xfader7_t = control::xfader<xfader7_multimod<NV>, faders::linear>;

template <int NV> using xfader8_multimod = xfader6_multimod<NV>;

template <int NV>
using xfader8_t = control::xfader<xfader8_multimod<NV>, faders::squared>;

template <int NV> using xfader9_multimod = xfader6_multimod<NV>;

template <int NV>
using xfader9_t = control::xfader<xfader9_multimod<NV>, faders::cosine_half>;

template <int NV> using xfader10_multimod = xfader6_multimod<NV>;

template <int NV>
using xfader10_t = control::xfader<xfader10_multimod<NV>, faders::threshold>;

template <int NV> using xfader11_multimod = xfader6_multimod<NV>;

template <int NV>
using xfader11_t = control::xfader<xfader11_multimod<NV>, faders::rms>;

template <int NV> using cable_table8_t = cable_table_t<NV>;

template <int NV> using cable_table9_t = cable_table1_t<NV>;

template <int NV> using cable_table10_t = cable_table2_t<NV>;

template <int NV> using cable_table11_t = cable_table3_t<NV>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<xfader_t<NV>, 0>, 
                                 parameter::plain<xfader1_t<NV>, 0>, 
                                 parameter::plain<xfader2_t<NV>, 0>, 
                                 parameter::plain<xfader3_t<NV>, 0>, 
                                 parameter::plain<xfader4_t<NV>, 0>, 
                                 parameter::plain<xfader5_t<NV>, 0>, 
                                 parameter::plain<cable_table_t<NV>, 0>, 
                                 parameter::plain<cable_table1_t<NV>, 0>, 
                                 parameter::plain<cable_table2_t<NV>, 0>, 
                                 parameter::plain<cable_table3_t<NV>, 0>, 
                                 parameter::plain<cable_table4_t<NV>, 0>, 
                                 parameter::plain<cable_table5_t<NV>, 0>, 
                                 parameter::plain<cable_table6_t<NV>, 0>, 
                                 parameter::plain<cable_table7_t<NV>, 0>, 
                                 parameter::plain<xfader6_t<NV>, 0>, 
                                 parameter::plain<xfader7_t<NV>, 0>, 
                                 parameter::plain<xfader8_t<NV>, 0>, 
                                 parameter::plain<xfader9_t<NV>, 0>, 
                                 parameter::plain<xfader10_t<NV>, 0>, 
                                 parameter::plain<xfader11_t<NV>, 0>, 
                                 parameter::plain<cable_table8_t<NV>, 0>, 
                                 parameter::plain<cable_table9_t<NV>, 0>, 
                                 parameter::plain<cable_table10_t<NV>, 0>, 
                                 parameter::plain<cable_table11_t<NV>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using pma8_t = control::pma<NV, 
                            parameter::plain<pma_t<NV>, 2>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma8_t<NV>>>;

template <int NV>
using xfader12_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                          parameter::plain<math::add<NV>, 0>>;

template <int NV>
using xfader12_t = control::xfader<xfader12_multimod<NV>, faders::switcher>;

template <int NV> using xfader13_multimod = xfader12_multimod<NV>;

template <int NV>
using xfader13_t = control::xfader<xfader13_multimod<NV>, faders::linear>;

template <int NV> using xfader14_multimod = xfader12_multimod<NV>;

template <int NV>
using xfader14_t = control::xfader<xfader14_multimod<NV>, faders::squared>;

template <int NV> using xfader15_multimod = xfader12_multimod<NV>;

template <int NV>
using xfader15_t = control::xfader<xfader15_multimod<NV>, faders::cosine_half>;

template <int NV> using xfader16_multimod = xfader12_multimod<NV>;

template <int NV>
using xfader16_t = control::xfader<xfader16_multimod<NV>, faders::threshold>;

template <int NV> using xfader17_multimod = xfader12_multimod<NV>;

template <int NV>
using xfader17_t = control::xfader<xfader17_multimod<NV>, faders::rms>;

template <int NV> using cable_table16_t = cable_table_t<NV>;

template <int NV> using cable_table17_t = cable_table1_t<NV>;

template <int NV>
using pma3_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<xfader12_t<NV>, 0>, 
                                  parameter::plain<xfader13_t<NV>, 0>, 
                                  parameter::plain<xfader14_t<NV>, 0>, 
                                  parameter::plain<xfader15_t<NV>, 0>, 
                                  parameter::plain<xfader16_t<NV>, 0>, 
                                  parameter::plain<xfader17_t<NV>, 0>, 
                                  parameter::plain<cable_table16_t<NV>, 0>, 
                                  parameter::plain<cable_table17_t<NV>, 0>, 
                                  parameter::plain<pma8_t<NV>, 2>>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
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
using peak2_t = wrap::mod<parameter::plain<pma8_t<NV>, 0>, 
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
                                   wrap::fix<1, chain10_t<NV>>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain5_t<NV>>, 
                                  chain6_t<NV>, 
                                  chain9_t<NV>, 
                                  chain14_t<NV>, 
                                  pma7_t<NV>, 
                                  chain25_t<NV>>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain45_t<NV>>, 
                                   split7_t<NV>>;

template <int NV>
using split28_t = container::split<parameter::empty, 
                                   wrap::fix<1, split19_t<NV>>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split28_t<NV>>, 
                                     pma_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, cable_table_t<NV>>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, cable_table1_t<NV>>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, cable_table2_t<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, cable_table3_t<NV>>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, cable_table4_t<NV>>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table5_t<NV>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table6_t<NV>>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table7_t<NV>>>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain_t<NV>>, 
                                     chain1_t<NV>, 
                                     chain2_t<NV>, 
                                     chain3_t<NV>, 
                                     chain7_t<NV>, 
                                     chain11_t<NV>, 
                                     chain12_t<NV>, 
                                     chain13_t<NV>>;
using peak1_t = wrap::no_data<core::peak>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch12_t<NV>>, 
                                   peak1_t>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain8_t<NV>>, 
                                  xfader1_t<NV>, 
                                  xfader2_t<NV>, 
                                  xfader3_t<NV>, 
                                  xfader4_t<NV>, 
                                  xfader5_t<NV>, 
                                  chain51_t<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, math::add<NV>>, 
                                   math::add<NV>, 
                                   math::add<NV>, 
                                   math::add<NV>, 
                                   math::add<NV>, 
                                   math::add<NV>, 
                                   math::add<NV>>;
template <int NV> using branch1_t = branch_t<NV>;
template <int NV> using branch2_t = branch_t<NV>;
template <int NV> using branch5_t = branch_t<NV>;
template <int NV> using branch7_t = branch_t<NV>;
template <int NV> using branch8_t = branch_t<NV>;
template <int NV> using branch9_t = branch_t<NV>;
template <int NV> using branch10_t = branch_t<NV>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<2, branch_t<NV>>, 
                                    branch1_t<NV>, 
                                    branch2_t<NV>, 
                                    branch5_t<NV>, 
                                    branch7_t<NV>, 
                                    branch8_t<NV>, 
                                    branch9_t<NV>, 
                                    branch10_t<NV>>;

template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<math::mul<NV>, 0>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<smoothed_parameter_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, math::clear<NV>>, 
                                  branch4_t<NV>, 
                                  peak_t<NV>, 
                                  math::clear<NV>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter_t<NV>>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split3_t<NV>>, 
                                   chain4_t<NV>, 
                                   chain55_t<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader6_t<NV>>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table8_t<NV>>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table9_t<NV>>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table10_t<NV>>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table11_t<NV>>>;

using chain17_t = chain26_t;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain21_t<NV>>, 
                                     chain22_t<NV>, 
                                     chain23_t<NV>, 
                                     chain24_t<NV>, 
                                     chain17_t>;
using peak3_t = peak1_t;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch14_t<NV>>, 
                                   peak3_t>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain20_t<NV>>, 
                                  xfader7_t<NV>, 
                                  xfader8_t<NV>, 
                                  xfader9_t<NV>, 
                                  xfader10_t<NV>, 
                                  xfader11_t<NV>, 
                                  chain52_t<NV>>;
template <int NV> using branch16_t = branch_t<NV>;
template <int NV> using branch17_t = branch_t<NV>;
template <int NV> using branch18_t = branch_t<NV>;
template <int NV> using branch19_t = branch_t<NV>;

using chain40_t = chain26_t;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<2, branch16_t<NV>>, 
                                     branch17_t<NV>, 
                                     branch18_t<NV>, 
                                     branch19_t<NV>, 
                                     chain40_t>;

template <int NV>
using smoothed_parameter2_t = wrap::mod<parameter::plain<math::mul<NV>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<smoothed_parameter2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   branch15_t<NV>, 
                                   peak4_t<NV>, 
                                   math::clear<NV>, 
                                   smoothed_parameter2_t<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split4_t<NV>>, 
                                   chain39_t<NV>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader12_t<NV>>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table16_t<NV>>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table17_t<NV>>>;

using chain47_t = chain26_t;
template <int NV>
using branch26_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain43_t<NV>>, 
                                     chain44_t<NV>, 
                                     chain47_t>;
using peak5_t = peak1_t;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch26_t<NV>>, 
                                   peak5_t>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain42_t<NV>>, 
                                  xfader13_t<NV>, 
                                  xfader14_t<NV>, 
                                  xfader15_t<NV>, 
                                  xfader16_t<NV>, 
                                  xfader17_t<NV>, 
                                  chain59_t<NV>>;
template <int NV> using branch28_t = branch_t<NV>;
template <int NV> using branch29_t = branch_t<NV>;

using chain49_t = chain26_t;
template <int NV>
using branch27_t = container::branch<parameter::empty, 
                                     wrap::fix<2, branch28_t<NV>>, 
                                     branch29_t<NV>, 
                                     chain49_t>;

template <int NV>
using smoothed_parameter1_mod = parameter::chain<ranges::Identity, 
                                                 parameter::plain<control::minmax<NV, parameter::empty>, 0>, 
                                                 parameter::plain<math::mul<NV>, 0>>;

template <int NV>
using smoothed_parameter1_t = wrap::mod<smoothed_parameter1_mod<NV>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<smoothed_parameter1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter1_t<NV>>, 
                                   control::minmax<NV, parameter::empty>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   branch27_t<NV>, 
                                   peak6_t<NV>, 
                                   chain62_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split5_t<NV>>, 
                                   chain48_t<NV>>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain16_t<NV>>, 
                                     chain19_t<NV>, 
                                     chain41_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain26_t>, 
                                 branch13_t<NV>>;
template <int NV>
using branch31_t = container::branch<parameter::empty, 
                                     wrap::fix<2, math::mul<NV>>, 
                                     math::mul<NV>, 
                                     math::mul<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split_t<NV>>, 
                                   branch31_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, modchain_t<NV>>, 
                                       chain15_t<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

namespace xfade1_t_parameters
{
// Parameter list for xfade1_impl::xfade1_t --------------------------------------------------------

template <int NV>
using Smoothing = parameter::chain<ranges::Identity, 
                                   parameter::plain<xfade1_impl::smoothed_parameter_t<NV>, 1>, 
                                   parameter::plain<xfade1_impl::smoothed_parameter1_t<NV>, 1>, 
                                   parameter::plain<xfade1_impl::smoothed_parameter2_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(Mode_InputRange, 
                             1., 
                             7., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Mode_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using Mode_0 = parameter::from0To1<xfade1_impl::branch_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_1 = parameter::from0To1<xfade1_impl::branch1_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_2 = parameter::from0To1<xfade1_impl::branch2_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_3 = parameter::from0To1<xfade1_impl::branch5_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_4 = parameter::from0To1<xfade1_impl::branch7_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_5 = parameter::from0To1<xfade1_impl::branch8_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_6 = parameter::from0To1<xfade1_impl::branch9_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_7 = parameter::from0To1<xfade1_impl::branch10_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_8 = parameter::from0To1<xfade1_impl::branch16_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_9 = parameter::from0To1<xfade1_impl::branch17_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode_10 = parameter::from0To1<xfade1_impl::branch28_t<NV>, 
                                    0, 
                                    Mode_0Range>;

template <int NV>
using Mode_11 = parameter::from0To1<xfade1_impl::branch29_t<NV>, 
                                    0, 
                                    Mode_0Range>;

template <int NV>
using Mode_12 = parameter::from0To1<xfade1_impl::branch18_t<NV>, 
                                    0, 
                                    Mode_0Range>;

template <int NV>
using Mode_13 = parameter::from0To1<xfade1_impl::branch19_t<NV>, 
                                    0, 
                                    Mode_0Range>;

template <int NV>
using Mode = parameter::chain<Mode_InputRange, 
                              Mode_0<NV>, 
                              Mode_1<NV>, 
                              Mode_2<NV>, 
                              Mode_3<NV>, 
                              Mode_4<NV>, 
                              Mode_5<NV>, 
                              Mode_6<NV>, 
                              Mode_7<NV>, 
                              Mode_8<NV>, 
                              Mode_9<NV>, 
                              Mode_10<NV>, 
                              Mode_11<NV>, 
                              Mode_12<NV>, 
                              Mode_13<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Channel_InputRange, 
                             1., 
                             8., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Channel_0Range, 
                             0., 
                             7., 
                             1.);

template <int NV>
using Channel_0 = parameter::from0To1<xfade1_impl::branch4_t<NV>, 
                                      0, 
                                      Channel_0Range>;

template <int NV>
using Channel_1 = parameter::from0To1<xfade1_impl::branch12_t<NV>, 
                                      0, 
                                      Channel_0Range>;

template <int NV>
using Channel = parameter::chain<Channel_InputRange, 
                                 Channel_0<NV>, 
                                 Channel_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Channel2_InputRange, 
                             1., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Channel2_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using Channel2_0 = parameter::from0To1<xfade1_impl::branch15_t<NV>, 
                                       0, 
                                       Channel2_0Range>;

template <int NV>
using Channel2_1 = parameter::from0To1<xfade1_impl::branch14_t<NV>, 
                                       0, 
                                       Channel2_0Range>;

template <int NV>
using Channel2 = parameter::chain<Channel2_InputRange, 
                                  Channel2_0<NV>, 
                                  Channel2_1<NV>>;

DECLARE_PARAMETER_RANGE(Channel3_InputRange, 
                        1., 
                        3.);
DECLARE_PARAMETER_RANGE_STEP(Channel3_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using Channel3_0 = parameter::from0To1<xfade1_impl::branch26_t<NV>, 
                                       0, 
                                       Channel3_0Range>;

template <int NV>
using Channel3_1 = parameter::from0To1<xfade1_impl::branch27_t<NV>, 
                                       0, 
                                       Channel3_0Range>;

template <int NV>
using Channel3 = parameter::chain<Channel3_InputRange, 
                                  Channel3_0<NV>, 
                                  Channel3_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Stages_InputRange, 
                             1., 
                             3., 
                             1.);
template <int NV>
using Stages_0 = parameter::from0To1<xfade1_impl::branch13_t<NV>, 
                                     0, 
                                     Channel3_0Range>;

template <int NV>
using Stages_1 = parameter::from0To1<xfade1_impl::branch31_t<NV>, 
                                     0, 
                                     Channel3_0Range>;

template <int NV>
using Stages = parameter::chain<Stages_InputRange, 
                                Stages_0<NV>, 
                                Stages_1<NV>>;

template <int NV>
using Xfade = parameter::plain<xfade1_impl::pma7_t<NV>, 
                               2>;
template <int NV>
using Poly = parameter::plain<xfade1_impl::pma8_t<NV>, 
                              1>;
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
using OutMode = parameter::empty;
using FilterMode = OutMode;
using Q = OutMode;
using Gain = OutMode;
template <int NV>
using xfade1_t_plist = parameter::list<Xfade<NV>, 
                                       Smoothing<NV>, 
                                       Mode<NV>, 
                                       Poly<NV>, 
                                       Global<NV>, 
                                       GlobalSrc<NV>, 
                                       Vel<NV>, 
                                       Trk<NV>, 
                                       MW<NV>, 
                                       AT<NV>, 
                                       MonoSrc<NV>, 
                                       Channel<NV>, 
                                       Channel2<NV>, 
                                       Channel3<NV>, 
                                       Stages<NV>, 
                                       OutMode, 
                                       FilterMode, 
                                       Q, 
                                       Gain>;
}

template <int NV>
using xfade1_t_ = container::chain<xfade1_t_parameters::xfade1_t_plist<NV>, 
                                   wrap::fix<2, fix8_block_t<NV>>>;

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
		SNEX_METADATA_ENCODED_PARAMETERS(320)
		{
			0x005C, 0x0000, 0x0000, 0x6658, 0x6461, 0x0065, 0x0000, 0x8000, 
            0x0024, 0x8000, 0x0A3F, 0xA3D7, 0x003D, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x0100, 0x0000, 0x5300, 0x6F6D, 0x746F, 0x6968, 0x676E, 
            0x0000, 0xCCCD, 0x3DCC, 0x0000, 0x447A, 0x0000, 0x4120, 0x0000, 
            0x3F80, 0xCCCD, 0x3DCC, 0x005C, 0x0002, 0x0000, 0x6F4D, 0x6564, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x40C0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x005C, 0x0003, 0x0000, 0x6F50, 0x796C, 
            0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0004, 0x0000, 0x6C47, 0x626F, 
            0x6C61, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0005, 0x0000, 0x6C47, 
            0x626F, 0x6C61, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x0041, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0600, 
            0x0000, 0x5600, 0x6C65, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0007, 
            0x0000, 0x7254, 0x006B, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0800, 0x0000, 
            0x4D00, 0x0057, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0900, 0x0000, 0x4100, 
            0x0054, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x0A00, 0x0000, 0x4D00, 0x6E6F, 
            0x536F, 0x6372, 0x0000, 0x0000, 0x0000, 0x0000, 0x40E0, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x000B, 0x0000, 
            0x6843, 0x6E61, 0x656E, 0x006C, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0C00, 
            0x0000, 0x4300, 0x6168, 0x6E6E, 0x6C65, 0x0032, 0x0000, 0x8000, 
            0x003F, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0D00, 0x0000, 0x4300, 0x6168, 0x6E6E, 0x6C65, 0x0033, 
            0x0000, 0x8000, 0x003F, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0E00, 0x0000, 0x5300, 0x6174, 0x6567, 
            0x0073, 0x0000, 0x8000, 0x003F, 0x4000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x0F00, 0x0000, 0x4F00, 0x7475, 
            0x6F4D, 0x6564, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0010, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x40A0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0011, 0x0000, 0x0051, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xD73F, 0xF0A3, 0x003E, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1200, 
            0x0000, 0x4700, 0x6961, 0x006E, 0x0000, 0x9000, 0x00C1, 0x9000, 
            0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(25)
		{
			0x003A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);                                                          // xfade1_impl::fix8_block_t<NV>
		auto& modchain = this->getT(0).getT(0);                                                    // xfade1_impl::modchain_t<NV>
		auto& split28 = this->getT(0).getT(0).getT(0);                                             // xfade1_impl::split28_t<NV>
		auto& split19 = this->getT(0).getT(0).getT(0).getT(0);                                     // xfade1_impl::split19_t<NV>
		auto& chain45 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                             // xfade1_impl::chain45_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);                        // xfade1_impl::pma8_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                              // xfade1_impl::split7_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);                      // xfade1_impl::chain5_t<NV>
		auto& midi = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);                // xfade1_impl::midi_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);                // xfade1_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);                      // xfade1_impl::chain6_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);               // xfade1_impl::midi1_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);                // xfade1_impl::pma4_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);                      // xfade1_impl::chain9_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0);             // xfade1_impl::midi_cc_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(1);                // xfade1_impl::pma5_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);                     // xfade1_impl::chain14_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0);            // xfade1_impl::midi_cc1_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(1);                // xfade1_impl::pma6_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4);                        // xfade1_impl::pma7_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5);                     // xfade1_impl::chain25_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(0);             // xfade1_impl::chain10_t<NV>
		auto& split21 = this->getT(0).getT(0).getT(0).getT(0).                                     // xfade1_impl::split21_t<NV>
                        getT(1).getT(5).getT(0).getT(0);
		auto& event_data_reader7 = this->getT(0).getT(0).getT(0).getT(0).                          // xfade1_impl::event_data_reader7_t<NV>
                                   getT(1).getT(5).getT(0).getT(0).
                                   getT(0);
		auto& chain29 = this->getT(0).getT(0).getT(0).getT(0).                                     // xfade1_impl::chain29_t<NV>
                        getT(1).getT(5).getT(0).getT(0).
                        getT(1);
		auto& branch3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                             // xfade1_impl::branch3_t<NV>
                        getT(5).getT(0).getT(0).getT(1).getT(0);
		auto& chain30 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                             // xfade1_impl::chain30_t<NV>
                        getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(0);
		auto& global_cable16 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).              // xfade1_impl::global_cable16_t<NV>
                               getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).                       // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& chain31 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                             // xfade1_impl::chain31_t<NV>
                        getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(1);
		auto& global_cable17 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).              // xfade1_impl::global_cable17_t<NV>
                               getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).                       // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);
		auto& chain32 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                             // xfade1_impl::chain32_t<NV>
                        getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(2);
		auto& global_cable18 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).              // xfade1_impl::global_cable18_t<NV>
                               getT(0).getT(0).getT(1).getT(0).getT(2).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).                       // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(2).getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                             // xfade1_impl::chain33_t<NV>
                        getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(3);
		auto& global_cable19 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).              // xfade1_impl::global_cable19_t<NV>
                               getT(0).getT(0).getT(1).getT(0).getT(3).getT(0);
		auto& add19 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).                       // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(3).getT(1);
		auto& chain34 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                             // xfade1_impl::chain34_t<NV>
                        getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(4);
		auto& global_cable20 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).              // xfade1_impl::global_cable20_t<NV>
                               getT(0).getT(0).getT(1).getT(0).getT(4).getT(0);
		auto& add20 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).                       // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(4).getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                             // xfade1_impl::chain35_t<NV>
                        getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(5);
		auto& global_cable21 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).              // xfade1_impl::global_cable21_t<NV>
                               getT(0).getT(0).getT(1).getT(0).getT(5).getT(0);
		auto& add21 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).                       // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(5).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                             // xfade1_impl::chain36_t<NV>
                        getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(6);
		auto& global_cable22 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).              // xfade1_impl::global_cable22_t<NV>
                               getT(0).getT(0).getT(1).getT(0).getT(6).getT(0);
		auto& add22 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).                       // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(6).getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                             // xfade1_impl::chain37_t<NV>
                        getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(7);
		auto& global_cable23 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).              // xfade1_impl::global_cable23_t<NV>
                               getT(0).getT(0).getT(1).getT(0).getT(7).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).                       // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(7).getT(1);
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).                               // xfade1_impl::peak2_t<NV>
                      getT(5).getT(0).getT(0).getT(1).getT(1);
		auto& clear = this->getT(0).getT(0).getT(0).getT(0).getT(1).                               // math::clear<NV>
                      getT(5).getT(0).getT(0).getT(1).getT(2);
		auto& pma = this->getT(0).getT(0).getT(1);                                                 // xfade1_impl::pma_t<NV>
		auto& chain15 = this->getT(0).getT(1);                                                     // xfade1_impl::chain15_t<NV>
		auto& split = this->getT(0).getT(1).getT(0);                                               // xfade1_impl::split_t<NV>
		auto& chain26 = this->getT(0).getT(1).getT(0).getT(0);                                     // xfade1_impl::chain26_t
		auto& branch13 = this->getT(0).getT(1).getT(0).getT(1);                                    // xfade1_impl::branch13_t<NV>
		auto& chain16 = this->getT(0).getT(1).getT(0).getT(1).getT(0);                             // xfade1_impl::chain16_t<NV>
		auto& split3 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);                      // xfade1_impl::split3_t<NV>
		auto& chain8 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).getT(0);              // xfade1_impl::chain8_t<NV>
		auto& xfader = this->getT(0).getT(1).getT(0).getT(1).                                      // xfade1_impl::xfader_t<NV>
                       getT(0).getT(0).getT(0).getT(0);
		auto& xfader1 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).getT(1);             // xfade1_impl::xfader1_t<NV>
		auto& xfader2 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).getT(2);             // xfade1_impl::xfader2_t<NV>
		auto& xfader3 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).getT(3);             // xfade1_impl::xfader3_t<NV>
		auto& xfader4 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).getT(4);             // xfade1_impl::xfader4_t<NV>
		auto& xfader5 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).getT(5);             // xfade1_impl::xfader5_t<NV>
		auto& chain51 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).getT(6);             // xfade1_impl::chain51_t<NV>
		auto& branch12 = this->getT(0).getT(1).getT(0).getT(1).                                    // xfade1_impl::branch12_t<NV>
                         getT(0).getT(0).getT(6).getT(0);
		auto& chain = this->getT(0).getT(1).getT(0).getT(1).                                       // xfade1_impl::chain_t<NV>
                      getT(0).getT(0).getT(6).getT(0).
                      getT(0);
		auto& cable_table = this->getT(0).getT(1).getT(0).getT(1).getT(0).                         // xfade1_impl::cable_table_t<NV>
                            getT(0).getT(6).getT(0).getT(0).getT(0);
		auto& chain1 = this->getT(0).getT(1).getT(0).getT(1).                                      // xfade1_impl::chain1_t<NV>
                       getT(0).getT(0).getT(6).getT(0).
                       getT(1);
		auto& cable_table1 = this->getT(0).getT(1).getT(0).getT(1).getT(0).                        // xfade1_impl::cable_table1_t<NV>
                             getT(0).getT(6).getT(0).getT(1).getT(0);
		auto& chain2 = this->getT(0).getT(1).getT(0).getT(1).                                      // xfade1_impl::chain2_t<NV>
                       getT(0).getT(0).getT(6).getT(0).
                       getT(2);
		auto& cable_table2 = this->getT(0).getT(1).getT(0).getT(1).getT(0).                        // xfade1_impl::cable_table2_t<NV>
                             getT(0).getT(6).getT(0).getT(2).getT(0);
		auto& chain3 = this->getT(0).getT(1).getT(0).getT(1).                                      // xfade1_impl::chain3_t<NV>
                       getT(0).getT(0).getT(6).getT(0).
                       getT(3);
		auto& cable_table3 = this->getT(0).getT(1).getT(0).getT(1).getT(0).                        // xfade1_impl::cable_table3_t<NV>
                             getT(0).getT(6).getT(0).getT(3).getT(0);
		auto& chain7 = this->getT(0).getT(1).getT(0).getT(1).                                      // xfade1_impl::chain7_t<NV>
                       getT(0).getT(0).getT(6).getT(0).
                       getT(4);
		auto& cable_table4 = this->getT(0).getT(1).getT(0).getT(1).getT(0).                        // xfade1_impl::cable_table4_t<NV>
                             getT(0).getT(6).getT(0).getT(4).getT(0);
		auto& chain11 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::chain11_t<NV>
                        getT(0).getT(0).getT(6).getT(0).
                        getT(5);
		auto& cable_table5 = this->getT(0).getT(1).getT(0).getT(1).getT(0).                        // xfade1_impl::cable_table5_t<NV>
                             getT(0).getT(6).getT(0).getT(5).getT(0);
		auto& chain12 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::chain12_t<NV>
                        getT(0).getT(0).getT(6).getT(0).
                        getT(6);
		auto& cable_table6 = this->getT(0).getT(1).getT(0).getT(1).getT(0).                        // xfade1_impl::cable_table6_t<NV>
                             getT(0).getT(6).getT(0).getT(6).getT(0);
		auto& chain13 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::chain13_t<NV>
                        getT(0).getT(0).getT(6).getT(0).
                        getT(7);
		auto& cable_table7 = this->getT(0).getT(1).getT(0).getT(1).getT(0).                        // xfade1_impl::cable_table7_t<NV>
                             getT(0).getT(6).getT(0).getT(7).getT(0);
		auto& peak1 = this->getT(0).getT(1).getT(0).getT(1).                                       // xfade1_impl::peak1_t
                      getT(0).getT(0).getT(6).getT(1);
		auto& chain4 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);                      // xfade1_impl::chain4_t<NV>
		auto& clear2 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(1).getT(0);              // math::clear<NV>
		auto& branch4 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(1).getT(1);             // xfade1_impl::branch4_t<NV>
		auto& branch = this->getT(0).getT(1).getT(0).getT(1).                                      // xfade1_impl::branch_t<NV>
                       getT(0).getT(1).getT(1).getT(0);
		auto& add = this->getT(0).getT(1).getT(0).getT(1).                                         // math::add<NV>
                    getT(0).getT(1).getT(1).getT(0).
                    getT(0);
		auto& add5 = this->getT(0).getT(1).getT(0).getT(1).                                        // math::add<NV>
                     getT(0).getT(1).getT(1).getT(0).
                     getT(1);
		auto& add4 = this->getT(0).getT(1).getT(0).getT(1).                                        // math::add<NV>
                     getT(0).getT(1).getT(1).getT(0).
                     getT(2);
		auto& add3 = this->getT(0).getT(1).getT(0).getT(1).                                        // math::add<NV>
                     getT(0).getT(1).getT(1).getT(0).
                     getT(3);
		auto& add2 = this->getT(0).getT(1).getT(0).getT(1).                                        // math::add<NV>
                     getT(0).getT(1).getT(1).getT(0).
                     getT(4);
		auto& add7 = this->getT(0).getT(1).getT(0).getT(1).                                        // math::add<NV>
                     getT(0).getT(1).getT(1).getT(0).
                     getT(5);
		auto& add1 = this->getT(0).getT(1).getT(0).getT(1).                                        // math::add<NV>
                     getT(0).getT(1).getT(1).getT(0).
                     getT(6);
		auto& branch1 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::branch1_t<NV>
                        getT(0).getT(1).getT(1).getT(1);
		auto& add8 = this->getT(0).getT(1).getT(0).getT(1).                                        // math::add<NV>
                     getT(0).getT(1).getT(1).getT(1).
                     getT(0);
		auto& add9 = this->getT(0).getT(1).getT(0).getT(1).                                        // math::add<NV>
                     getT(0).getT(1).getT(1).getT(1).
                     getT(1);
		auto& add10 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1).
                      getT(2);
		auto& add11 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1).
                      getT(3);
		auto& add12 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1).
                      getT(4);
		auto& add13 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1).
                      getT(5);
		auto& add14 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1).
                      getT(6);
		auto& branch2 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::branch2_t<NV>
                        getT(0).getT(1).getT(1).getT(2);
		auto& add15 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2).
                      getT(0);
		auto& add24 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2).
                      getT(1);
		auto& add25 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2).
                      getT(2);
		auto& add26 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2).
                      getT(3);
		auto& add27 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2).
                      getT(4);
		auto& add28 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2).
                      getT(5);
		auto& add29 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(2).
                      getT(6);
		auto& branch5 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::branch5_t<NV>
                        getT(0).getT(1).getT(1).getT(3);
		auto& add30 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(3).
                      getT(0);
		auto& add31 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(3).
                      getT(1);
		auto& add32 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(3).
                      getT(2);
		auto& add33 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(3).
                      getT(3);
		auto& add34 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(3).
                      getT(4);
		auto& add35 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(3).
                      getT(5);
		auto& add36 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(3).
                      getT(6);
		auto& branch7 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::branch7_t<NV>
                        getT(0).getT(1).getT(1).getT(4);
		auto& add37 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(4).
                      getT(0);
		auto& add38 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(4).
                      getT(1);
		auto& add39 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(4).
                      getT(2);
		auto& add40 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(4).
                      getT(3);
		auto& add41 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(4).
                      getT(4);
		auto& add42 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(4).
                      getT(5);
		auto& add43 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(4).
                      getT(6);
		auto& branch8 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::branch8_t<NV>
                        getT(0).getT(1).getT(1).getT(5);
		auto& add44 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(5).
                      getT(0);
		auto& add45 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(5).
                      getT(1);
		auto& add46 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(5).
                      getT(2);
		auto& add47 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(5).
                      getT(3);
		auto& add48 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(5).
                      getT(4);
		auto& add49 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(5).
                      getT(5);
		auto& add50 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(5).
                      getT(6);
		auto& branch9 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::branch9_t<NV>
                        getT(0).getT(1).getT(1).getT(6);
		auto& add51 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(6).
                      getT(0);
		auto& add52 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(6).
                      getT(1);
		auto& add53 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(6).
                      getT(2);
		auto& add54 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(6).
                      getT(3);
		auto& add55 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(6).
                      getT(4);
		auto& add56 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(6).
                      getT(5);
		auto& add57 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(6).
                      getT(6);
		auto& branch10 = this->getT(0).getT(1).getT(0).getT(1).                                    // xfade1_impl::branch10_t<NV>
                         getT(0).getT(1).getT(1).getT(7);
		auto& add58 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(7).
                      getT(0);
		auto& add59 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(7).
                      getT(1);
		auto& add60 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(7).
                      getT(2);
		auto& add61 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(7).
                      getT(3);
		auto& add62 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(7).
                      getT(4);
		auto& add63 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(7).
                      getT(5);
		auto& add64 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(0).getT(1).getT(1).getT(7).
                      getT(6);
		auto& peak = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(1).getT(2);                // xfade1_impl::peak_t<NV>
		auto& clear1 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(1).getT(3);              // math::clear<NV>
		auto& chain55 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(2);                     // xfade1_impl::chain55_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(2).getT(0);  // xfade1_impl::smoothed_parameter_t<NV>
		auto& chain19 = this->getT(0).getT(1).getT(0).getT(1).getT(1);                             // xfade1_impl::chain19_t<NV>
		auto& split4 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0);                      // xfade1_impl::split4_t<NV>
		auto& chain20 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).getT(0);             // xfade1_impl::chain20_t<NV>
		auto& xfader6 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::xfader6_t<NV>
                        getT(1).getT(0).getT(0).getT(0);
		auto& xfader7 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).getT(1);             // xfade1_impl::xfader7_t<NV>
		auto& xfader8 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).getT(2);             // xfade1_impl::xfader8_t<NV>
		auto& xfader9 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).getT(3);             // xfade1_impl::xfader9_t<NV>
		auto& xfader10 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).getT(4);            // xfade1_impl::xfader10_t<NV>
		auto& xfader11 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).getT(5);            // xfade1_impl::xfader11_t<NV>
		auto& chain52 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).getT(6);             // xfade1_impl::chain52_t<NV>
		auto& branch14 = this->getT(0).getT(1).getT(0).getT(1).                                    // xfade1_impl::branch14_t<NV>
                         getT(1).getT(0).getT(6).getT(0);
		auto& chain21 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::chain21_t<NV>
                        getT(1).getT(0).getT(6).getT(0).
                        getT(0);
		auto& cable_table8 = this->getT(0).getT(1).getT(0).getT(1).getT(1).                        // xfade1_impl::cable_table8_t<NV>
                             getT(0).getT(6).getT(0).getT(0).getT(0);
		auto& chain22 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::chain22_t<NV>
                        getT(1).getT(0).getT(6).getT(0).
                        getT(1);
		auto& cable_table9 = this->getT(0).getT(1).getT(0).getT(1).getT(1).                        // xfade1_impl::cable_table9_t<NV>
                             getT(0).getT(6).getT(0).getT(1).getT(0);
		auto& chain23 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::chain23_t<NV>
                        getT(1).getT(0).getT(6).getT(0).
                        getT(2);
		auto& cable_table10 = this->getT(0).getT(1).getT(0).getT(1).getT(1).                       // xfade1_impl::cable_table10_t<NV>
                              getT(0).getT(6).getT(0).getT(2).getT(0);
		auto& chain24 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::chain24_t<NV>
                        getT(1).getT(0).getT(6).getT(0).
                        getT(3);
		auto& cable_table11 = this->getT(0).getT(1).getT(0).getT(1).getT(1).                       // xfade1_impl::cable_table11_t<NV>
                              getT(0).getT(6).getT(0).getT(3).getT(0);
		auto& chain17 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::chain17_t
                        getT(1).getT(0).getT(6).getT(0).
                        getT(4);
		auto& peak3 = this->getT(0).getT(1).getT(0).getT(1).                                       // xfade1_impl::peak3_t
                      getT(1).getT(0).getT(6).getT(1);
		auto& chain39 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(1);                     // xfade1_impl::chain39_t<NV>
		auto& clear3 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(1).getT(0);              // math::clear<NV>
		auto& branch15 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(1).getT(1);            // xfade1_impl::branch15_t<NV>
		auto& branch16 = this->getT(0).getT(1).getT(0).getT(1).                                    // xfade1_impl::branch16_t<NV>
                         getT(1).getT(1).getT(1).getT(0);
		auto& add72 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(0).
                      getT(0);
		auto& add73 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(0).
                      getT(1);
		auto& add74 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(0).
                      getT(2);
		auto& add75 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(0).
                      getT(3);
		auto& add76 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(0).
                      getT(4);
		auto& add77 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(0).
                      getT(5);
		auto& add78 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(0).
                      getT(6);
		auto& branch17 = this->getT(0).getT(1).getT(0).getT(1).                                    // xfade1_impl::branch17_t<NV>
                         getT(1).getT(1).getT(1).getT(1);
		auto& add79 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(0);
		auto& add80 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(1);
		auto& add81 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(2);
		auto& add82 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(3);
		auto& add83 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(4);
		auto& add84 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(5);
		auto& add85 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(6);
		auto& branch18 = this->getT(0).getT(1).getT(0).getT(1).                                    // xfade1_impl::branch18_t<NV>
                         getT(1).getT(1).getT(1).getT(2);
		auto& add86 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(2).
                      getT(0);
		auto& add87 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(2).
                      getT(1);
		auto& add88 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(2).
                      getT(2);
		auto& add89 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(2).
                      getT(3);
		auto& add90 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(2).
                      getT(4);
		auto& add91 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(2).
                      getT(5);
		auto& add92 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(2).
                      getT(6);
		auto& branch19 = this->getT(0).getT(1).getT(0).getT(1).                                    // xfade1_impl::branch19_t<NV>
                         getT(1).getT(1).getT(1).getT(3);
		auto& add93 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(0);
		auto& add94 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(1);
		auto& add95 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(2);
		auto& add96 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(3);
		auto& add97 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(4);
		auto& add98 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(5);
		auto& add99 = this->getT(0).getT(1).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(6);
		auto& chain40 = this->getT(0).getT(1).getT(0).getT(1).                                     // xfade1_impl::chain40_t
                        getT(1).getT(1).getT(1).getT(4);
		auto& peak4 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(1).getT(2);               // xfade1_impl::peak4_t<NV>
		auto& clear4 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(1).getT(3);              // math::clear<NV>
		auto& smoothed_parameter2 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(1).getT(4); // xfade1_impl::smoothed_parameter2_t<NV>
		auto& chain41 = this->getT(0).getT(1).getT(0).getT(1).getT(2);                             // xfade1_impl::chain41_t<NV>
		auto& split5 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(0);                      // xfade1_impl::split5_t<NV>
		auto& chain42 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).getT(0);             // xfade1_impl::chain42_t<NV>
		auto& xfader12 = this->getT(0).getT(1).getT(0).getT(1).                                    // xfade1_impl::xfader12_t<NV>
                         getT(2).getT(0).getT(0).getT(0);
		auto& xfader13 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).getT(1); // xfade1_impl::xfader13_t<NV>
		auto& xfader14 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).getT(2); // xfade1_impl::xfader14_t<NV>
		auto& xfader15 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).getT(3); // xfade1_impl::xfader15_t<NV>
		auto& xfader16 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).getT(4); // xfade1_impl::xfader16_t<NV>
		auto& xfader17 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).getT(5); // xfade1_impl::xfader17_t<NV>
		auto& chain59 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).getT(6);  // xfade1_impl::chain59_t<NV>
		auto& branch26 = this->getT(0).getT(1).getT(0).getT(1).                         // xfade1_impl::branch26_t<NV>
                         getT(2).getT(0).getT(6).getT(0);
		auto& chain43 = this->getT(0).getT(1).getT(0).getT(1).                          // xfade1_impl::chain43_t<NV>
                        getT(2).getT(0).getT(6).getT(0).
                        getT(0);
		auto& cable_table16 = this->getT(0).getT(1).getT(0).getT(1).getT(2).            // xfade1_impl::cable_table16_t<NV>
                              getT(0).getT(6).getT(0).getT(0).getT(0);
		auto& chain44 = this->getT(0).getT(1).getT(0).getT(1).                          // xfade1_impl::chain44_t<NV>
                        getT(2).getT(0).getT(6).getT(0).
                        getT(1);
		auto& cable_table17 = this->getT(0).getT(1).getT(0).getT(1).getT(2).            // xfade1_impl::cable_table17_t<NV>
                              getT(0).getT(6).getT(0).getT(1).getT(0);
		auto& chain47 = this->getT(0).getT(1).getT(0).getT(1).                          // xfade1_impl::chain47_t
                        getT(2).getT(0).getT(6).getT(0).
                        getT(2);
		auto& peak5 = this->getT(0).getT(1).getT(0).getT(1).                            // xfade1_impl::peak5_t
                      getT(2).getT(0).getT(6).getT(1);
		auto& chain48 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(1);          // xfade1_impl::chain48_t<NV>
		auto& clear5 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(1).getT(0);   // math::clear<NV>
		auto& branch27 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(1).getT(1); // xfade1_impl::branch27_t<NV>
		auto& branch28 = this->getT(0).getT(1).getT(0).getT(1).                         // xfade1_impl::branch28_t<NV>
                         getT(2).getT(1).getT(1).getT(0);
		auto& add128 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).
                       getT(0);
		auto& add129 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).
                       getT(1);
		auto& add130 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).
                       getT(2);
		auto& add131 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).
                       getT(3);
		auto& add132 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).
                       getT(4);
		auto& add133 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).
                       getT(5);
		auto& add134 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).
                       getT(6);
		auto& branch29 = this->getT(0).getT(1).getT(0).getT(1).                        // xfade1_impl::branch29_t<NV>
                         getT(2).getT(1).getT(1).getT(1);
		auto& add135 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(1).
                       getT(0);
		auto& add136 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(1).
                       getT(1);
		auto& add137 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(1).
                       getT(2);
		auto& add138 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(1).
                       getT(3);
		auto& add139 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(1).
                       getT(4);
		auto& add140 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(1).
                       getT(5);
		auto& add141 = this->getT(0).getT(1).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(1).getT(1).getT(1).
                       getT(6);
		auto& chain49 = this->getT(0).getT(1).getT(0).getT(1).                         // xfade1_impl::chain49_t
                        getT(2).getT(1).getT(1).getT(2);
		auto& peak6 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(1).getT(2);   // xfade1_impl::peak6_t<NV>
		auto& chain62 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(1).getT(3); // xfade1_impl::chain62_t<NV>
		auto& smoothed_parameter1 = this->getT(0).getT(1).getT(0).getT(1).             // xfade1_impl::smoothed_parameter1_t<NV>
                                    getT(2).getT(1).getT(3).getT(0);
		auto& minmax = this->getT(0).getT(1).getT(0).getT(1).                         // control::minmax<NV, parameter::empty>
                       getT(2).getT(1).getT(3).getT(1);
		auto& clear6 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(1).getT(4); // math::clear<NV>
		auto& branch31 = this->getT(0).getT(1).getT(1);                               // xfade1_impl::branch31_t<NV>
		auto& mul = this->getT(0).getT(1).getT(1).getT(0);                            // math::mul<NV>
		auto& mul2 = this->getT(0).getT(1).getT(1).getT(1);                           // math::mul<NV>
		auto& mul1 = this->getT(0).getT(1).getT(1).getT(2);                           // math::mul<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma7); // Xfade -> pma7::Add
		
		auto& Smoothing_p = this->getParameterT(1);
		Smoothing_p.connectT(0, smoothed_parameter);  // Smoothing -> smoothed_parameter::SmoothingTime
		Smoothing_p.connectT(1, smoothed_parameter1); // Smoothing -> smoothed_parameter1::SmoothingTime
		Smoothing_p.connectT(2, smoothed_parameter2); // Smoothing -> smoothed_parameter2::SmoothingTime
		
		auto& Mode_p = this->getParameterT(2);
		Mode_p.connectT(0, branch);    // Mode -> branch::Index
		Mode_p.connectT(1, branch1);   // Mode -> branch1::Index
		Mode_p.connectT(2, branch2);   // Mode -> branch2::Index
		Mode_p.connectT(3, branch5);   // Mode -> branch5::Index
		Mode_p.connectT(4, branch7);   // Mode -> branch7::Index
		Mode_p.connectT(5, branch8);   // Mode -> branch8::Index
		Mode_p.connectT(6, branch9);   // Mode -> branch9::Index
		Mode_p.connectT(7, branch10);  // Mode -> branch10::Index
		Mode_p.connectT(8, branch16);  // Mode -> branch16::Index
		Mode_p.connectT(9, branch17);  // Mode -> branch17::Index
		Mode_p.connectT(10, branch28); // Mode -> branch28::Index
		Mode_p.connectT(11, branch29); // Mode -> branch29::Index
		Mode_p.connectT(12, branch18); // Mode -> branch18::Index
		Mode_p.connectT(13, branch19); // Mode -> branch19::Index
		
		this->getParameterT(3).connectT(0, pma8); // Poly -> pma8::Multiply
		
		this->getParameterT(4).connectT(0, pma7); // Global -> pma7::Multiply
		
		this->getParameterT(5).connectT(0, event_data_reader7); // GlobalSrc -> event_data_reader7::SlotIndex
		
		this->getParameterT(6).connectT(0, pma3); // Vel -> pma3::Multiply
		
		this->getParameterT(7).connectT(0, pma4); // Trk -> pma4::Multiply
		
		this->getParameterT(8).connectT(0, pma5); // MW -> pma5::Multiply
		
		this->getParameterT(9).connectT(0, pma6); // AT -> pma6::Multiply
		
		this->getParameterT(10).connectT(0, branch3); // MonoSrc -> branch3::Index
		
		auto& Channel_p = this->getParameterT(11);
		Channel_p.connectT(0, branch4);  // Channel -> branch4::Index
		Channel_p.connectT(1, branch12); // Channel -> branch12::Index
		
		auto& Channel2_p = this->getParameterT(12);
		Channel2_p.connectT(0, branch15); // Channel2 -> branch15::Index
		Channel2_p.connectT(1, branch14); // Channel2 -> branch14::Index
		
		auto& Channel3_p = this->getParameterT(13);
		Channel3_p.connectT(0, branch26); // Channel3 -> branch26::Index
		Channel3_p.connectT(1, branch27); // Channel3 -> branch27::Index
		
		auto& Stages_p = this->getParameterT(14);
		Stages_p.connectT(0, branch13); // Stages -> branch13::Index
		Stages_p.connectT(1, branch31); // Stages -> branch31::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, add);   // xfader -> add::Value
		xfader_p.getParameterT(1).connectT(0, add8);  // xfader -> add8::Value
		xfader_p.getParameterT(2).connectT(0, add15); // xfader -> add15::Value
		xfader_p.getParameterT(3).connectT(0, add30); // xfader -> add30::Value
		xfader_p.getParameterT(4).connectT(0, add37); // xfader -> add37::Value
		xfader_p.getParameterT(5).connectT(0, add44); // xfader -> add44::Value
		xfader_p.getParameterT(6).connectT(0, add51); // xfader -> add51::Value
		xfader_p.getParameterT(7).connectT(0, add58); // xfader -> add58::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, add5);  // xfader1 -> add5::Value
		xfader1_p.getParameterT(1).connectT(0, add9);  // xfader1 -> add9::Value
		xfader1_p.getParameterT(2).connectT(0, add24); // xfader1 -> add24::Value
		xfader1_p.getParameterT(3).connectT(0, add31); // xfader1 -> add31::Value
		xfader1_p.getParameterT(4).connectT(0, add38); // xfader1 -> add38::Value
		xfader1_p.getParameterT(5).connectT(0, add45); // xfader1 -> add45::Value
		xfader1_p.getParameterT(6).connectT(0, add52); // xfader1 -> add52::Value
		xfader1_p.getParameterT(7).connectT(0, add59); // xfader1 -> add59::Value
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, add4);  // xfader2 -> add4::Value
		xfader2_p.getParameterT(1).connectT(0, add10); // xfader2 -> add10::Value
		xfader2_p.getParameterT(2).connectT(0, add25); // xfader2 -> add25::Value
		xfader2_p.getParameterT(3).connectT(0, add32); // xfader2 -> add32::Value
		xfader2_p.getParameterT(4).connectT(0, add39); // xfader2 -> add39::Value
		xfader2_p.getParameterT(5).connectT(0, add46); // xfader2 -> add46::Value
		xfader2_p.getParameterT(6).connectT(0, add53); // xfader2 -> add53::Value
		xfader2_p.getParameterT(7).connectT(0, add60); // xfader2 -> add60::Value
		auto& xfader3_p = xfader3.getWrappedObject().getParameter();
		xfader3_p.getParameterT(0).connectT(0, add3);  // xfader3 -> add3::Value
		xfader3_p.getParameterT(1).connectT(0, add11); // xfader3 -> add11::Value
		xfader3_p.getParameterT(2).connectT(0, add26); // xfader3 -> add26::Value
		xfader3_p.getParameterT(3).connectT(0, add33); // xfader3 -> add33::Value
		xfader3_p.getParameterT(4).connectT(0, add40); // xfader3 -> add40::Value
		xfader3_p.getParameterT(5).connectT(0, add47); // xfader3 -> add47::Value
		xfader3_p.getParameterT(6).connectT(0, add54); // xfader3 -> add54::Value
		xfader3_p.getParameterT(7).connectT(0, add61); // xfader3 -> add61::Value
		auto& xfader4_p = xfader4.getWrappedObject().getParameter();
		xfader4_p.getParameterT(0).connectT(0, add2);  // xfader4 -> add2::Value
		xfader4_p.getParameterT(1).connectT(0, add12); // xfader4 -> add12::Value
		xfader4_p.getParameterT(2).connectT(0, add27); // xfader4 -> add27::Value
		xfader4_p.getParameterT(3).connectT(0, add34); // xfader4 -> add34::Value
		xfader4_p.getParameterT(4).connectT(0, add41); // xfader4 -> add41::Value
		xfader4_p.getParameterT(5).connectT(0, add48); // xfader4 -> add48::Value
		xfader4_p.getParameterT(6).connectT(0, add55); // xfader4 -> add55::Value
		xfader4_p.getParameterT(7).connectT(0, add62); // xfader4 -> add62::Value
		auto& xfader5_p = xfader5.getWrappedObject().getParameter();
		xfader5_p.getParameterT(0).connectT(0, add7);                      // xfader5 -> add7::Value
		xfader5_p.getParameterT(1).connectT(0, add13);                     // xfader5 -> add13::Value
		xfader5_p.getParameterT(2).connectT(0, add28);                     // xfader5 -> add28::Value
		xfader5_p.getParameterT(3).connectT(0, add35);                     // xfader5 -> add35::Value
		xfader5_p.getParameterT(4).connectT(0, add42);                     // xfader5 -> add42::Value
		xfader5_p.getParameterT(5).connectT(0, add49);                     // xfader5 -> add49::Value
		xfader5_p.getParameterT(6).connectT(0, add56);                     // xfader5 -> add56::Value
		xfader5_p.getParameterT(7).connectT(0, add63);                     // xfader5 -> add63::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add1);   // cable_table -> add1::Value
		cable_table1.getWrappedObject().getParameter().connectT(0, add14); // cable_table1 -> add14::Value
		cable_table2.getWrappedObject().getParameter().connectT(0, add29); // cable_table2 -> add29::Value
		cable_table3.getWrappedObject().getParameter().connectT(0, add36); // cable_table3 -> add36::Value
		cable_table4.getWrappedObject().getParameter().connectT(0, add43); // cable_table4 -> add43::Value
		cable_table5.getWrappedObject().getParameter().connectT(0, add50); // cable_table5 -> add50::Value
		cable_table6.getWrappedObject().getParameter().connectT(0, add57); // cable_table6 -> add57::Value
		cable_table7.getWrappedObject().getParameter().connectT(0, add64); // cable_table7 -> add64::Value
		auto& xfader6_p = xfader6.getWrappedObject().getParameter();
		xfader6_p.getParameterT(0).connectT(0, add72); // xfader6 -> add72::Value
		xfader6_p.getParameterT(1).connectT(0, add79); // xfader6 -> add79::Value
		xfader6_p.getParameterT(2).connectT(0, add86); // xfader6 -> add86::Value
		xfader6_p.getParameterT(3).connectT(0, add93); // xfader6 -> add93::Value
		auto& xfader7_p = xfader7.getWrappedObject().getParameter();
		xfader7_p.getParameterT(0).connectT(0, add73); // xfader7 -> add73::Value
		xfader7_p.getParameterT(1).connectT(0, add80); // xfader7 -> add80::Value
		xfader7_p.getParameterT(2).connectT(0, add87); // xfader7 -> add87::Value
		xfader7_p.getParameterT(3).connectT(0, add94); // xfader7 -> add94::Value
		auto& xfader8_p = xfader8.getWrappedObject().getParameter();
		xfader8_p.getParameterT(0).connectT(0, add74); // xfader8 -> add74::Value
		xfader8_p.getParameterT(1).connectT(0, add81); // xfader8 -> add81::Value
		xfader8_p.getParameterT(2).connectT(0, add88); // xfader8 -> add88::Value
		xfader8_p.getParameterT(3).connectT(0, add95); // xfader8 -> add95::Value
		auto& xfader9_p = xfader9.getWrappedObject().getParameter();
		xfader9_p.getParameterT(0).connectT(0, add75); // xfader9 -> add75::Value
		xfader9_p.getParameterT(1).connectT(0, add82); // xfader9 -> add82::Value
		xfader9_p.getParameterT(2).connectT(0, add89); // xfader9 -> add89::Value
		xfader9_p.getParameterT(3).connectT(0, add96); // xfader9 -> add96::Value
		auto& xfader10_p = xfader10.getWrappedObject().getParameter();
		xfader10_p.getParameterT(0).connectT(0, add76); // xfader10 -> add76::Value
		xfader10_p.getParameterT(1).connectT(0, add83); // xfader10 -> add83::Value
		xfader10_p.getParameterT(2).connectT(0, add90); // xfader10 -> add90::Value
		xfader10_p.getParameterT(3).connectT(0, add97); // xfader10 -> add97::Value
		auto& xfader11_p = xfader11.getWrappedObject().getParameter();
		xfader11_p.getParameterT(0).connectT(0, add77);                     // xfader11 -> add77::Value
		xfader11_p.getParameterT(1).connectT(0, add84);                     // xfader11 -> add84::Value
		xfader11_p.getParameterT(2).connectT(0, add91);                     // xfader11 -> add91::Value
		xfader11_p.getParameterT(3).connectT(0, add98);                     // xfader11 -> add98::Value
		cable_table8.getWrappedObject().getParameter().connectT(0, add78);  // cable_table8 -> add78::Value
		cable_table9.getWrappedObject().getParameter().connectT(0, add85);  // cable_table9 -> add85::Value
		cable_table10.getWrappedObject().getParameter().connectT(0, add92); // cable_table10 -> add92::Value
		cable_table11.getWrappedObject().getParameter().connectT(0, add99); // cable_table11 -> add99::Value
		pma.getWrappedObject().getParameter().connectT(0, xfader);          // pma -> xfader::Value
		pma.getWrappedObject().getParameter().connectT(1, xfader1);         // pma -> xfader1::Value
		pma.getWrappedObject().getParameter().connectT(2, xfader2);         // pma -> xfader2::Value
		pma.getWrappedObject().getParameter().connectT(3, xfader3);         // pma -> xfader3::Value
		pma.getWrappedObject().getParameter().connectT(4, xfader4);         // pma -> xfader4::Value
		pma.getWrappedObject().getParameter().connectT(5, xfader5);         // pma -> xfader5::Value
		pma.getWrappedObject().getParameter().connectT(6, cable_table);     // pma -> cable_table::Value
		pma.getWrappedObject().getParameter().connectT(7, cable_table1);    // pma -> cable_table1::Value
		pma.getWrappedObject().getParameter().connectT(8, cable_table2);    // pma -> cable_table2::Value
		pma.getWrappedObject().getParameter().connectT(9, cable_table3);    // pma -> cable_table3::Value
		pma.getWrappedObject().getParameter().connectT(10, cable_table4);   // pma -> cable_table4::Value
		pma.getWrappedObject().getParameter().connectT(11, cable_table5);   // pma -> cable_table5::Value
		pma.getWrappedObject().getParameter().connectT(12, cable_table6);   // pma -> cable_table6::Value
		pma.getWrappedObject().getParameter().connectT(13, cable_table7);   // pma -> cable_table7::Value
		pma.getWrappedObject().getParameter().connectT(14, xfader6);        // pma -> xfader6::Value
		pma.getWrappedObject().getParameter().connectT(15, xfader7);        // pma -> xfader7::Value
		pma.getWrappedObject().getParameter().connectT(16, xfader8);        // pma -> xfader8::Value
		pma.getWrappedObject().getParameter().connectT(17, xfader9);        // pma -> xfader9::Value
		pma.getWrappedObject().getParameter().connectT(18, xfader10);       // pma -> xfader10::Value
		pma.getWrappedObject().getParameter().connectT(19, xfader11);       // pma -> xfader11::Value
		pma.getWrappedObject().getParameter().connectT(20, cable_table8);   // pma -> cable_table8::Value
		pma.getWrappedObject().getParameter().connectT(21, cable_table9);   // pma -> cable_table9::Value
		pma.getWrappedObject().getParameter().connectT(22, cable_table10);  // pma -> cable_table10::Value
		pma.getWrappedObject().getParameter().connectT(23, cable_table11);  // pma -> cable_table11::Value
		pma8.getWrappedObject().getParameter().connectT(0, pma);            // pma8 -> pma::Add
		auto& xfader12_p = xfader12.getWrappedObject().getParameter();
		xfader12_p.getParameterT(0).connectT(0, add128); // xfader12 -> add128::Value
		xfader12_p.getParameterT(1).connectT(0, add135); // xfader12 -> add135::Value
		auto& xfader13_p = xfader13.getWrappedObject().getParameter();
		xfader13_p.getParameterT(0).connectT(0, add129); // xfader13 -> add129::Value
		xfader13_p.getParameterT(1).connectT(0, add136); // xfader13 -> add136::Value
		auto& xfader14_p = xfader14.getWrappedObject().getParameter();
		xfader14_p.getParameterT(0).connectT(0, add130); // xfader14 -> add130::Value
		xfader14_p.getParameterT(1).connectT(0, add137); // xfader14 -> add137::Value
		auto& xfader15_p = xfader15.getWrappedObject().getParameter();
		xfader15_p.getParameterT(0).connectT(0, add131); // xfader15 -> add131::Value
		xfader15_p.getParameterT(1).connectT(0, add138); // xfader15 -> add138::Value
		auto& xfader16_p = xfader16.getWrappedObject().getParameter();
		xfader16_p.getParameterT(0).connectT(0, add132); // xfader16 -> add132::Value
		xfader16_p.getParameterT(1).connectT(0, add139); // xfader16 -> add139::Value
		auto& xfader17_p = xfader17.getWrappedObject().getParameter();
		xfader17_p.getParameterT(0).connectT(0, add133);                     // xfader17 -> add133::Value
		xfader17_p.getParameterT(1).connectT(0, add140);                     // xfader17 -> add140::Value
		cable_table16.getWrappedObject().getParameter().connectT(0, add134); // cable_table16 -> add134::Value
		cable_table17.getWrappedObject().getParameter().connectT(0, add141); // cable_table17 -> add141::Value
		pma3.getWrappedObject().getParameter().connectT(0, xfader12);        // pma3 -> xfader12::Value
		pma3.getWrappedObject().getParameter().connectT(1, xfader13);        // pma3 -> xfader13::Value
		pma3.getWrappedObject().getParameter().connectT(2, xfader14);        // pma3 -> xfader14::Value
		pma3.getWrappedObject().getParameter().connectT(3, xfader15);        // pma3 -> xfader15::Value
		pma3.getWrappedObject().getParameter().connectT(4, xfader16);        // pma3 -> xfader16::Value
		pma3.getWrappedObject().getParameter().connectT(5, xfader17);        // pma3 -> xfader17::Value
		pma3.getWrappedObject().getParameter().connectT(6, cable_table16);   // pma3 -> cable_table16::Value
		pma3.getWrappedObject().getParameter().connectT(7, cable_table17);   // pma3 -> cable_table17::Value
		pma3.getWrappedObject().getParameter().connectT(8, pma8);            // pma3 -> pma8::Add
		midi.getParameter().connectT(0, pma3);                               // midi -> pma3::Value
		pma4.getWrappedObject().getParameter().connectT(0, pma3);            // pma4 -> pma3::Add
		midi1.getParameter().connectT(0, pma4);                              // midi1 -> pma4::Value
		pma5.getWrappedObject().getParameter().connectT(0, pma4);            // pma5 -> pma4::Add
		midi_cc.getWrappedObject().getParameter().connectT(0, pma5);         // midi_cc -> pma5::Value
		pma6.getWrappedObject().getParameter().connectT(0, pma5);            // pma6 -> pma5::Add
		midi_cc1.getWrappedObject().getParameter().connectT(0, pma6);        // midi_cc1 -> pma6::Value
		pma7.getWrappedObject().getParameter().connectT(0, pma6);            // pma7 -> pma6::Add
		event_data_reader7.getParameter().connectT(0, pma7);                 // event_data_reader7 -> pma7::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add16); // global_cable16 -> add16::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add17); // global_cable17 -> add17::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add18); // global_cable18 -> add18::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add19); // global_cable19 -> add19::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add20); // global_cable20 -> add20::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add21); // global_cable21 -> add21::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add22); // global_cable22 -> add22::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add23); // global_cable23 -> add23::Value
		peak2.getParameter().connectT(0, pma8);                              // peak2 -> pma8::Value
		smoothed_parameter.getParameter().connectT(0, mul);                  // smoothed_parameter -> mul::Value
		peak.getParameter().connectT(0, smoothed_parameter);                 // peak -> smoothed_parameter::Value
		smoothed_parameter2.getParameter().connectT(0, mul2);                // smoothed_parameter2 -> mul2::Value
		peak4.getParameter().connectT(0, smoothed_parameter2);               // peak4 -> smoothed_parameter2::Value
		smoothed_parameter1.getParameter().connectT(0, minmax);              // smoothed_parameter1 -> minmax::Value
		smoothed_parameter1.getParameter().connectT(1, mul1);                // smoothed_parameter1 -> mul1::Value
		peak6.getParameter().connectT(0, smoothed_parameter1);               // peak6 -> smoothed_parameter1::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // pma8::Value is automated
		; // pma8::Multiply is automated
		; // pma8::Add is automated
		
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
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
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
		
		pma.setParameterT(0, 0.); // control::pma::Value
		pma.setParameterT(1, 0.); // control::pma::Multiply
		;                         // pma::Add is automated
		
		; // branch13::Index is automated
		
		; // xfader::Value is automated
		
		; // xfader1::Value is automated
		
		; // xfader2::Value is automated
		
		; // xfader3::Value is automated
		
		; // xfader4::Value is automated
		
		; // xfader5::Value is automated
		
		; // branch12::Index is automated
		
		; // cable_table::Value is automated
		
		; // cable_table1::Value is automated
		
		; // cable_table2::Value is automated
		
		; // cable_table3::Value is automated
		
		; // cable_table4::Value is automated
		
		; // cable_table5::Value is automated
		
		; // cable_table6::Value is automated
		
		; // cable_table7::Value is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // branch4::Index is automated
		
		; // branch::Index is automated
		
		; // add::Value is automated
		
		; // add5::Value is automated
		
		; // add4::Value is automated
		
		; // add3::Value is automated
		
		; // add2::Value is automated
		
		; // add7::Value is automated
		
		; // add1::Value is automated
		
		; // branch1::Index is automated
		
		; // add8::Value is automated
		
		; // add9::Value is automated
		
		; // add10::Value is automated
		
		; // add11::Value is automated
		
		; // add12::Value is automated
		
		; // add13::Value is automated
		
		; // add14::Value is automated
		
		; // branch2::Index is automated
		
		; // add15::Value is automated
		
		; // add24::Value is automated
		
		; // add25::Value is automated
		
		; // add26::Value is automated
		
		; // add27::Value is automated
		
		; // add28::Value is automated
		
		; // add29::Value is automated
		
		; // branch5::Index is automated
		
		; // add30::Value is automated
		
		; // add31::Value is automated
		
		; // add32::Value is automated
		
		; // add33::Value is automated
		
		; // add34::Value is automated
		
		; // add35::Value is automated
		
		; // add36::Value is automated
		
		; // branch7::Index is automated
		
		; // add37::Value is automated
		
		; // add38::Value is automated
		
		; // add39::Value is automated
		
		; // add40::Value is automated
		
		; // add41::Value is automated
		
		; // add42::Value is automated
		
		; // add43::Value is automated
		
		; // branch8::Index is automated
		
		; // add44::Value is automated
		
		; // add45::Value is automated
		
		; // add46::Value is automated
		
		; // add47::Value is automated
		
		; // add48::Value is automated
		
		; // add49::Value is automated
		
		; // add50::Value is automated
		
		; // branch9::Index is automated
		
		; // add51::Value is automated
		
		; // add52::Value is automated
		
		; // add53::Value is automated
		
		; // add54::Value is automated
		
		; // add55::Value is automated
		
		; // add56::Value is automated
		
		; // add57::Value is automated
		
		; // branch10::Index is automated
		
		; // add58::Value is automated
		
		; // add59::Value is automated
		
		; // add60::Value is automated
		
		; // add61::Value is automated
		
		; // add62::Value is automated
		
		; // add63::Value is automated
		
		; // add64::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // xfader6::Value is automated
		
		; // xfader7::Value is automated
		
		; // xfader8::Value is automated
		
		; // xfader9::Value is automated
		
		; // xfader10::Value is automated
		
		; // xfader11::Value is automated
		
		; // branch14::Index is automated
		
		; // cable_table8::Value is automated
		
		; // cable_table9::Value is automated
		
		; // cable_table10::Value is automated
		
		; // cable_table11::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // branch15::Index is automated
		
		; // branch16::Index is automated
		
		; // add72::Value is automated
		
		; // add73::Value is automated
		
		; // add74::Value is automated
		
		; // add75::Value is automated
		
		; // add76::Value is automated
		
		; // add77::Value is automated
		
		; // add78::Value is automated
		
		; // branch17::Index is automated
		
		; // add79::Value is automated
		
		; // add80::Value is automated
		
		; // add81::Value is automated
		
		; // add82::Value is automated
		
		; // add83::Value is automated
		
		; // add84::Value is automated
		
		; // add85::Value is automated
		
		; // branch18::Index is automated
		
		; // add86::Value is automated
		
		; // add87::Value is automated
		
		; // add88::Value is automated
		
		; // add89::Value is automated
		
		; // add90::Value is automated
		
		; // add91::Value is automated
		
		; // add92::Value is automated
		
		; // branch19::Index is automated
		
		; // add93::Value is automated
		
		; // add94::Value is automated
		
		; // add95::Value is automated
		
		; // add96::Value is automated
		
		; // add97::Value is automated
		
		; // add98::Value is automated
		
		; // add99::Value is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		;                                         // smoothed_parameter2::Value is automated
		;                                         // smoothed_parameter2::SmoothingTime is automated
		smoothed_parameter2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // xfader12::Value is automated
		
		; // xfader13::Value is automated
		
		; // xfader14::Value is automated
		
		; // xfader15::Value is automated
		
		; // xfader16::Value is automated
		
		; // xfader17::Value is automated
		
		; // branch26::Index is automated
		
		; // cable_table16::Value is automated
		
		; // cable_table17::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // branch27::Index is automated
		
		; // branch28::Index is automated
		
		; // add128::Value is automated
		
		; // add129::Value is automated
		
		; // add130::Value is automated
		
		; // add131::Value is automated
		
		; // add132::Value is automated
		
		; // add133::Value is automated
		
		; // add134::Value is automated
		
		; // branch29::Index is automated
		
		; // add135::Value is automated
		
		; // add136::Value is automated
		
		; // add137::Value is automated
		
		; // add138::Value is automated
		
		; // add139::Value is automated
		
		; // add140::Value is automated
		
		; // add141::Value is automated
		
		;                                         // smoothed_parameter1::Value is automated
		;                                         // smoothed_parameter1::SmoothingTime is automated
		smoothed_parameter1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                            // minmax::Value is automated
		minmax.setParameterT(1, 0.); // control::minmax::Minimum
		minmax.setParameterT(2, 1.); // control::minmax::Maximum
		minmax.setParameterT(3, 1.); // control::minmax::Skew
		minmax.setParameterT(4, 0.); // control::minmax::Step
		minmax.setParameterT(5, 1.); // control::minmax::Polarity
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // branch31::Index is automated
		
		; // mul::Value is automated
		
		; // mul2::Value is automated
		
		; // mul1::Value is automated
		
		this->setParameterT(0, 0.08);
		this->setParameterT(1, 10.);
		this->setParameterT(2, 6.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, -1.);
		this->setParameterT(5, 7.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 4.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 0.47);
		this->setParameterT(18, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).  // xfade1_impl::global_cable16_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).  // xfade1_impl::global_cable17_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).  // xfade1_impl::global_cable18_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).  // xfade1_impl::global_cable19_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).  // xfade1_impl::global_cable20_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).  // xfade1_impl::global_cable21_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).  // xfade1_impl::global_cable22_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).  // xfade1_impl::global_cable23_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).                                           // xfade1_impl::peak2_t<NV>
        getT(5).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(0).                                           // xfade1_impl::cable_table_t<NV>
        getT(0).getT(6).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(0).                                           // xfade1_impl::cable_table1_t<NV>
        getT(0).getT(6).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(0).                                           // xfade1_impl::cable_table2_t<NV>
        getT(0).getT(6).getT(0).getT(2).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(0).                                           // xfade1_impl::cable_table3_t<NV>
        getT(0).getT(6).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(0).                                           // xfade1_impl::cable_table4_t<NV>
        getT(0).getT(6).getT(0).getT(4).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(0).                                           // xfade1_impl::cable_table5_t<NV>
        getT(0).getT(6).getT(0).getT(5).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(0).                                           // xfade1_impl::cable_table6_t<NV>
        getT(0).getT(6).getT(0).getT(6).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(0).                                           // xfade1_impl::cable_table7_t<NV>
        getT(0).getT(6).getT(0).getT(7).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).                                                   // xfade1_impl::peak1_t
        getT(0).getT(0).getT(6).getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(1).getT(2).setExternalData(b, index); // xfade1_impl::peak_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).getT(1).                                           // xfade1_impl::cable_table8_t<NV>
        getT(0).getT(6).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(1).                                           // xfade1_impl::cable_table9_t<NV>
        getT(0).getT(6).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(1).                                           // xfade1_impl::cable_table10_t<NV>
        getT(0).getT(6).getT(0).getT(2).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(1).                                           // xfade1_impl::cable_table11_t<NV>
        getT(0).getT(6).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).                                                   // xfade1_impl::peak3_t
        getT(1).getT(0).getT(6).getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(1).getT(2).setExternalData(b, index); // xfade1_impl::peak4_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).getT(2).                                           // xfade1_impl::cable_table16_t<NV>
        getT(0).getT(6).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(2).                                           // xfade1_impl::cable_table17_t<NV>
        getT(0).getT(6).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).                                                   // xfade1_impl::peak5_t
        getT(2).getT(0).getT(6).getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(1).getT(2).setExternalData(b, index); // xfade1_impl::peak6_t<NV>
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


