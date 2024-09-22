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

namespace SineStack_impl
{
// ==============================| Node & Parameter type declarations |==============================

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
		0.f, 0.f, 0.00244838f, 0.00686228f, 0.0112762f, 0.0156901f,
		0.0201039f, 0.0245178f, 0.0289317f, 0.0333456f, 0.0377597f, 0.0421736f,
		0.0465874f, 0.0510013f, 0.0554152f, 0.0598291f, 0.064243f, 0.0686569f,
		0.0730709f, 0.0774848f, 0.0818987f, 0.0863126f, 0.0907265f, 0.0951403f,
		0.0995542f, 0.103968f, 0.108382f, 0.112796f, 0.11721f, 0.121624f,
		0.126038f, 0.130452f, 0.134866f, 0.139279f, 0.143693f, 0.148107f,
		0.152521f, 0.156935f, 0.161349f, 0.165763f, 0.170177f, 0.174591f,
		0.179005f, 0.183419f, 0.187832f, 0.192246f, 0.19666f, 0.201074f,
		0.205488f, 0.209902f, 0.214316f, 0.21873f, 0.223144f, 0.227558f,
		0.231972f, 0.236385f, 0.240799f, 0.245213f, 0.249627f, 0.254041f,
		0.258455f, 0.262869f, 0.267283f, 0.271697f, 0.276111f, 0.280524f,
		0.284938f, 0.289352f, 0.293766f, 0.29818f, 0.302594f, 0.307008f,
		0.311422f, 0.315836f, 0.32025f, 0.324664f, 0.329077f, 0.333491f,
		0.337905f, 0.342319f, 0.346733f, 0.351147f, 0.355561f, 0.359975f,
		0.364389f, 0.368803f, 0.373217f, 0.37763f, 0.382044f, 0.386458f,
		0.390872f, 0.395286f, 0.3997f, 0.404114f, 0.408528f, 0.412942f,
		0.417356f, 0.421769f, 0.426183f, 0.430597f, 0.435011f, 0.439425f,
		0.443839f, 0.448253f, 0.452667f, 0.457081f, 0.461495f, 0.465909f,
		0.470322f, 0.474736f, 0.47915f, 0.483564f, 0.487978f, 0.492392f,
		0.496806f, 0.50122f, 0.505634f, 0.510048f, 0.514462f, 0.518875f,
		0.523289f, 0.527703f, 0.532117f, 0.536531f, 0.540945f, 0.545359f,
		0.549773f, 0.554187f, 0.558601f, 0.563015f, 0.567428f, 0.571842f,
		0.576256f, 0.58067f, 0.585084f, 0.589498f, 0.593912f, 0.598326f,
		0.60274f, 0.607154f, 0.611567f, 0.615981f, 0.620395f, 0.624809f,
		0.629223f, 0.633637f, 0.638051f, 0.642465f, 0.646879f, 0.651293f,
		0.655707f, 0.66012f, 0.664534f, 0.668948f, 0.673362f, 0.677776f,
		0.68219f, 0.686604f, 0.691018f, 0.695432f, 0.699846f, 0.70426f,
		0.708673f, 0.713087f, 0.717501f, 0.721915f, 0.726329f, 0.730743f,
		0.735157f, 0.739571f, 0.743985f, 0.748399f, 0.752813f, 0.757226f,
		0.76164f, 0.766054f, 0.770468f, 0.774882f, 0.779296f, 0.78371f,
		0.788124f, 0.792538f, 0.796952f, 0.801365f, 0.805779f, 0.810193f,
		0.814607f, 0.819021f, 0.823435f, 0.827849f, 0.832263f, 0.836677f,
		0.841091f, 0.845505f, 0.849919f, 0.854332f, 0.858746f, 0.86316f,
		0.867574f, 0.871988f, 0.876402f, 0.880816f, 0.88523f, 0.889644f,
		0.894058f, 0.898471f, 0.902885f, 0.907299f, 0.911713f, 0.916127f,
		0.920541f, 0.924955f, 0.929369f, 0.933783f, 0.938197f, 0.942611f,
		0.947024f, 0.951438f, 0.955852f, 0.960266f, 0.96468f, 0.969094f,
		0.973508f, 0.977922f, 0.982336f, 0.98675f, 0.991164f, 0.995577f,
		0.999991f, 1.f
	};
};

template <int NV>
using cable_table11_t = wrap::data<control::cable_table<cable_table11_mod<NV>>, 
                                   data::embedded::table<cable_table11_t_data>>;

template <int NV>
using oscillator54_t = wrap::no_data<core::oscillator<NV>>;
template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;

template <int NV>
using converter_mod = parameter::chain<ranges::Identity, 
                                       parameter::plain<oscillator54_t<NV>, 2>, 
                                       parameter::plain<file_player_t<NV>, 3>>;

template <int NV>
using converter_t = control::converter<converter_mod<NV>, 
                                       conversion_logic::st2pitch>;
template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, 
                                             parameter::plain<converter_t<NV>, 0>>;
template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, 
                                              parameter::plain<pma_unscaled_t<NV>, 2>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled1_t<NV>, 1>>;

template <int NV> using oscillator61_t = oscillator54_t<NV>;
template <int NV> using file_player7_t = file_player_t<NV>;

template <int NV>
using converter7_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<oscillator61_t<NV>, 2>, 
                                        parameter::plain<file_player7_t<NV>, 3>>;

template <int NV>
using converter7_t = control::converter<converter7_mod<NV>, 
                                        conversion_logic::st2pitch>;
template <int NV>
using pma_unscaled15_t = control::pma_unscaled<NV, 
                                               parameter::plain<converter7_t<NV>, 0>>;
template <int NV>
using pma_unscaled16_t = control::pma_unscaled<NV, 
                                               parameter::plain<pma_unscaled15_t<NV>, 2>>;
template <int NV>
using minmax14_t = control::minmax<NV, 
                                   parameter::plain<pma_unscaled16_t<NV>, 1>>;

template <int NV> using oscillator60_t = oscillator54_t<NV>;
template <int NV> using file_player6_t = file_player_t<NV>;

template <int NV>
using converter6_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<oscillator60_t<NV>, 2>, 
                                        parameter::plain<file_player6_t<NV>, 3>>;

template <int NV>
using converter6_t = control::converter<converter6_mod<NV>, 
                                        conversion_logic::st2pitch>;
template <int NV>
using pma_unscaled13_t = control::pma_unscaled<NV, 
                                               parameter::plain<converter6_t<NV>, 0>>;
template <int NV>
using pma_unscaled14_t = control::pma_unscaled<NV, 
                                               parameter::plain<pma_unscaled13_t<NV>, 2>>;
template <int NV>
using minmax12_t = control::minmax<NV, 
                                   parameter::plain<pma_unscaled14_t<NV>, 1>>;

template <int NV> using oscillator59_t = oscillator54_t<NV>;
template <int NV> using file_player5_t = file_player_t<NV>;

template <int NV>
using converter5_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<oscillator59_t<NV>, 2>, 
                                        parameter::plain<file_player5_t<NV>, 3>>;

template <int NV>
using converter5_t = control::converter<converter5_mod<NV>, 
                                        conversion_logic::st2pitch>;
template <int NV>
using pma_unscaled11_t = control::pma_unscaled<NV, 
                                               parameter::plain<converter5_t<NV>, 0>>;
template <int NV>
using pma_unscaled12_t = control::pma_unscaled<NV, 
                                               parameter::plain<pma_unscaled11_t<NV>, 2>>;
template <int NV>
using minmax10_t = control::minmax<NV, 
                                   parameter::plain<pma_unscaled12_t<NV>, 1>>;

template <int NV> using oscillator58_t = oscillator54_t<NV>;
template <int NV> using file_player4_t = file_player_t<NV>;

template <int NV>
using converter4_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<oscillator58_t<NV>, 2>, 
                                        parameter::plain<file_player4_t<NV>, 3>>;

template <int NV>
using converter4_t = control::converter<converter4_mod<NV>, 
                                        conversion_logic::st2pitch>;
template <int NV>
using pma_unscaled9_t = control::pma_unscaled<NV, 
                                              parameter::plain<converter4_t<NV>, 0>>;
template <int NV>
using pma_unscaled10_t = control::pma_unscaled<NV, 
                                               parameter::plain<pma_unscaled9_t<NV>, 2>>;
template <int NV>
using minmax8_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled10_t<NV>, 1>>;

template <int NV> using oscillator57_t = oscillator54_t<NV>;
template <int NV> using file_player3_t = file_player_t<NV>;

template <int NV>
using converter3_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<oscillator57_t<NV>, 2>, 
                                        parameter::plain<file_player3_t<NV>, 3>>;

template <int NV>
using converter3_t = control::converter<converter3_mod<NV>, 
                                        conversion_logic::st2pitch>;
template <int NV>
using pma_unscaled7_t = control::pma_unscaled<NV, 
                                              parameter::plain<converter3_t<NV>, 0>>;
template <int NV>
using pma_unscaled8_t = control::pma_unscaled<NV, 
                                              parameter::plain<pma_unscaled7_t<NV>, 2>>;
template <int NV>
using minmax6_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled8_t<NV>, 1>>;

template <int NV> using oscillator56_t = oscillator54_t<NV>;
template <int NV> using file_player2_t = file_player_t<NV>;

template <int NV>
using converter2_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<oscillator56_t<NV>, 2>, 
                                        parameter::plain<file_player2_t<NV>, 3>>;

template <int NV>
using converter2_t = control::converter<converter2_mod<NV>, 
                                        conversion_logic::st2pitch>;
template <int NV>
using pma_unscaled5_t = control::pma_unscaled<NV, 
                                              parameter::plain<converter2_t<NV>, 0>>;
template <int NV>
using pma_unscaled6_t = control::pma_unscaled<NV, 
                                              parameter::plain<pma_unscaled5_t<NV>, 2>>;
template <int NV>
using minmax4_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled6_t<NV>, 1>>;

template <int NV> using oscillator55_t = oscillator54_t<NV>;
template <int NV> using file_player1_t = file_player_t<NV>;

template <int NV>
using converter1_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<oscillator55_t<NV>, 2>, 
                                        parameter::plain<file_player1_t<NV>, 3>>;

template <int NV>
using converter1_t = control::converter<converter1_mod<NV>, 
                                        conversion_logic::st2pitch>;
template <int NV>
using pma_unscaled3_t = control::pma_unscaled<NV, 
                                              parameter::plain<converter1_t<NV>, 0>>;
template <int NV>
using pma_unscaled4_t = control::pma_unscaled<NV, 
                                              parameter::plain<pma_unscaled3_t<NV>, 2>>;
template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled4_t<NV>, 1>>;
template <int NV>
using sliderbank1_multimod = parameter::list<parameter::plain<minmax_t<NV>, 0>, 
                                             parameter::plain<minmax14_t<NV>, 0>, 
                                             parameter::plain<minmax12_t<NV>, 0>, 
                                             parameter::plain<minmax10_t<NV>, 0>, 
                                             parameter::plain<minmax8_t<NV>, 0>, 
                                             parameter::plain<minmax6_t<NV>, 0>, 
                                             parameter::plain<minmax4_t<NV>, 0>, 
                                             parameter::plain<minmax2_t<NV>, 0>>;

template <int NV>
using sliderbank1_t = wrap::data<control::sliderbank<sliderbank1_multimod<NV>>, 
                                 data::external::sliderpack<0>>;
template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<sliderbank1_t<NV>, 0>>;
template <int NV>
using input_toggle1x_t = control::input_toggle<parameter::plain<pma1_t<NV>, 0>>;

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

using global_cable_t_index = runtime_target::indexers::fix_hash<426836980>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, global_cable_t<NV>>, 
                                 math::add<NV>>;

template <int NV>
using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain_t<NV>>>;

template <int NV>
using sb1_t = bypass::smoothed<20, sb1_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb1_t<NV>>;

using global_cable1_t_index = runtime_target::indexers::fix_hash<426836981>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain1_t<NV>>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

using global_cable2_t_index = runtime_target::indexers::fix_hash<426836982>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb3_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain4_t<NV>>>;

template <int NV>
using sb3_t = bypass::smoothed<20, sb3_t_<NV>>;
template <int NV>
using switcher_c2 = parameter::bypass<sb3_t<NV>>;

using global_cable3_t_index = runtime_target::indexers::fix_hash<426836983>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable3_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb4_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain5_t<NV>>>;

template <int NV>
using sb4_t = bypass::smoothed<20, sb4_t_<NV>>;
template <int NV>
using switcher_c3 = parameter::bypass<sb4_t<NV>>;

using global_cable4_t_index = runtime_target::indexers::fix_hash<426836984>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable4_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb5_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain6_t<NV>>>;

template <int NV>
using sb5_t = bypass::smoothed<20, sb5_t_<NV>>;
template <int NV>
using switcher_c4 = parameter::bypass<sb5_t<NV>>;

using global_cable5_t_index = runtime_target::indexers::fix_hash<426836985>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable5_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb6_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain7_t<NV>>>;

template <int NV>
using sb6_t = bypass::smoothed<20, sb6_t_<NV>>;
template <int NV>
using switcher_c5 = parameter::bypass<sb6_t<NV>>;

using global_cable6_t_index = runtime_target::indexers::fix_hash<426836986>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable6_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb7_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain8_t<NV>>>;

template <int NV>
using sb7_t = bypass::smoothed<20, sb7_t_<NV>>;
template <int NV>
using switcher_c6 = parameter::bypass<sb7_t<NV>>;

using global_cable7_t_index = runtime_target::indexers::fix_hash<426836987>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable7_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb8_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain9_t<NV>>>;

template <int NV>
using sb8_t = bypass::smoothed<20, sb8_t_<NV>>;
template <int NV>
using switcher_c7 = parameter::bypass<sb8_t<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0<NV>, 
                                          switcher_c1<NV>, 
                                          switcher_c2<NV>, 
                                          switcher_c3<NV>, 
                                          switcher_c4<NV>, 
                                          switcher_c5<NV>, 
                                          switcher_c6<NV>, 
                                          switcher_c7<NV>>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<1, sb1_t<NV>>, 
                                        sb2_t<NV>, 
                                        sb3_t<NV>, 
                                        sb4_t<NV>, 
                                        sb5_t<NV>, 
                                        sb6_t<NV>, 
                                        sb7_t<NV>, 
                                        sb8_t<NV>>;

template <int NV>
using minmax1_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled1_t<NV>, 2>>;

template <int NV>
using minmax15_t = control::minmax<NV, 
                                   parameter::plain<pma_unscaled16_t<NV>, 2>>;

template <int NV>
using minmax13_t = control::minmax<NV, 
                                   parameter::plain<pma_unscaled14_t<NV>, 2>>;

template <int NV>
using minmax11_t = control::minmax<NV, 
                                   parameter::plain<pma_unscaled12_t<NV>, 2>>;

template <int NV>
using minmax9_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled10_t<NV>, 2>>;

template <int NV>
using minmax7_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled8_t<NV>, 2>>;

template <int NV>
using minmax5_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled6_t<NV>, 2>>;

template <int NV>
using minmax3_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled4_t<NV>, 2>>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<minmax1_t<NV>, 0>, 
                                 parameter::plain<minmax15_t<NV>, 0>, 
                                 parameter::plain<minmax13_t<NV>, 0>, 
                                 parameter::plain<minmax11_t<NV>, 0>, 
                                 parameter::plain<minmax9_t<NV>, 0>, 
                                 parameter::plain<minmax7_t<NV>, 0>, 
                                 parameter::plain<minmax5_t<NV>, 0>, 
                                 parameter::plain<minmax3_t<NV>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
DECLARE_PARAMETER_RANGE(peak_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using peak_mod = parameter::from0To1<pma_t<NV>, 
                                     2, 
                                     peak_modRange>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

namespace softbypass_switch9_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(Switch_InputRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using Switch = parameter::chain<Switch_InputRange, 
                                parameter::plain<SineStack_impl::switcher_t<NV>, 0>>;

}

template <int NV>
using softbypass_switch9_t = container::chain<softbypass_switch9_t_parameters::Switch<NV>, 
                                              wrap::fix<1, switcher_t<NV>>, 
                                              sb_container_t<NV>, 
                                              peak_t<NV>>;

template <int NV>
using split17_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma_t<NV>>, 
                                   pma1_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, chain10_t<NV>>, 
                                     softbypass_switch9_t<NV>, 
                                     math::clear<NV>, 
                                     split17_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;
using pack_resizer1_t = wrap::data<control::pack_resizer, 
                                   data::external::sliderpack<0>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, minmax_t<NV>>, 
                                  minmax1_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, pma_unscaled_t<NV>>, 
                                 pma_unscaled1_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, oscillator54_t<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, file_player_t<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain2_t<NV>>, 
                                   chain3_t<NV>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split1_t<NV>>, 
                                   split_t<NV>, 
                                   converter_t<NV>, 
                                   branch_t<NV>>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<2, minmax14_t<NV>>, 
                                   minmax15_t<NV>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<2, pma_unscaled15_t<NV>>, 
                                   pma_unscaled16_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator61_t<NV>>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, file_player7_t<NV>>>;
template <int NV>
using branch8_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain23_t<NV>>, 
                                    chain24_t<NV>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split14_t<NV>>, 
                                   split15_t<NV>, 
                                   converter7_t<NV>, 
                                   branch8_t<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<2, minmax12_t<NV>>, 
                                   minmax13_t<NV>>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<2, pma_unscaled13_t<NV>>, 
                                   pma_unscaled14_t<NV>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator60_t<NV>>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, file_player6_t<NV>>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain21_t<NV>>, 
                                    chain22_t<NV>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split12_t<NV>>, 
                                   split13_t<NV>, 
                                   converter6_t<NV>, 
                                   branch7_t<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<2, minmax10_t<NV>>, 
                                   minmax11_t<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<2, pma_unscaled11_t<NV>>, 
                                   pma_unscaled12_t<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator59_t<NV>>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, file_player5_t<NV>>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain19_t<NV>>, 
                                    chain20_t<NV>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split10_t<NV>>, 
                                   split11_t<NV>, 
                                   converter5_t<NV>, 
                                   branch6_t<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, minmax8_t<NV>>, 
                                  minmax9_t<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<2, pma_unscaled9_t<NV>>, 
                                  pma_unscaled10_t<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator58_t<NV>>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, file_player4_t<NV>>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain17_t<NV>>, 
                                    chain18_t<NV>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split8_t<NV>>, 
                                   split9_t<NV>, 
                                   converter4_t<NV>, 
                                   branch5_t<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, minmax6_t<NV>>, 
                                  minmax7_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<2, pma_unscaled7_t<NV>>, 
                                  pma_unscaled8_t<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator57_t<NV>>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, file_player3_t<NV>>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain15_t<NV>>, 
                                    chain16_t<NV>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split6_t<NV>>, 
                                   split7_t<NV>, 
                                   converter3_t<NV>, 
                                   branch4_t<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, minmax4_t<NV>>, 
                                  minmax5_t<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, pma_unscaled5_t<NV>>, 
                                  pma_unscaled6_t<NV>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator56_t<NV>>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, file_player2_t<NV>>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain13_t<NV>>, 
                                    chain14_t<NV>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split4_t<NV>>, 
                                   split5_t<NV>, 
                                   converter2_t<NV>, 
                                   branch2_t<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, minmax2_t<NV>>, 
                                  minmax3_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, pma_unscaled3_t<NV>>, 
                                  pma_unscaled4_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscillator55_t<NV>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, file_player1_t<NV>>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain11_t<NV>>, 
                                    chain12_t<NV>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split2_t<NV>>, 
                                   split3_t<NV>, 
                                   converter1_t<NV>, 
                                   branch1_t<NV>>;

template <int NV>
using split44_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain64_t<NV>>, 
                                   chain71_t<NV>, 
                                   chain70_t<NV>, 
                                   chain69_t<NV>, 
                                   chain68_t<NV>, 
                                   chain67_t<NV>, 
                                   chain66_t<NV>, 
                                   chain65_t<NV>>;

namespace SineStack_t_parameters
{
// Parameter list for SineStack_impl::SineStack_t --------------------------------------------------

template <int NV>
using OFFSET = parameter::from0To1<SineStack_impl::pma1_t<NV>, 
                                   2, 
                                   SineStack_impl::peak_modRange>;

DECLARE_PARAMETER_RANGE(SRC_InputRange, 
                        0., 
                        16.);
DECLARE_PARAMETER_RANGE_STEP(SRC_2Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using SRC_2 = parameter::from0To1<SineStack_impl::event_data_reader7_t<NV>, 
                                  0, 
                                  SRC_2Range>;

template <int NV>
using SRC = parameter::chain<SRC_InputRange, 
                             parameter::plain<SineStack_impl::cable_table11_t<NV>, 0>, 
                             parameter::plain<SineStack_impl::cable_table12_t<NV>, 0>, 
                             SRC_2<NV>>;

DECLARE_PARAMETER_RANGE_STEP(min_InputRange, 
                             1., 
                             30., 
                             1.);
DECLARE_PARAMETER_RANGE(min_0Range, 
                        -12., 
                        18.);

template <int NV>
using min_0 = parameter::from0To1<SineStack_impl::minmax_t<NV>, 
                                  1, 
                                  min_0Range>;

DECLARE_PARAMETER_RANGE(min_1Range, 
                        -12., 
                        19.);

template <int NV>
using min_1 = parameter::from0To1<SineStack_impl::minmax1_t<NV>, 
                                  1, 
                                  min_1Range>;

template <int NV>
using min_2 = parameter::from0To1<SineStack_impl::minmax14_t<NV>, 
                                  1, 
                                  min_0Range>;

DECLARE_PARAMETER_RANGE(min_3Range, 
                        19., 
                        48.);

template <int NV>
using min_3 = parameter::from0To1<SineStack_impl::minmax15_t<NV>, 
                                  1, 
                                  min_3Range>;

template <int NV>
using min_4 = parameter::from0To1<SineStack_impl::minmax12_t<NV>, 
                                  1, 
                                  min_0Range>;

template <int NV>
using min_5 = parameter::from0To1<SineStack_impl::minmax13_t<NV>, 
                                  1, 
                                  min_3Range>;

template <int NV>
using min_6 = parameter::from0To1<SineStack_impl::minmax10_t<NV>, 
                                  1, 
                                  min_0Range>;

template <int NV>
using min_7 = parameter::from0To1<SineStack_impl::minmax11_t<NV>, 
                                  1, 
                                  min_3Range>;

template <int NV>
using min_8 = parameter::from0To1<SineStack_impl::minmax8_t<NV>, 
                                  1, 
                                  min_0Range>;

template <int NV>
using min_9 = parameter::from0To1<SineStack_impl::minmax9_t<NV>, 
                                  1, 
                                  min_3Range>;

template <int NV>
using min_10 = parameter::from0To1<SineStack_impl::minmax6_t<NV>, 
                                   1, 
                                   min_0Range>;

template <int NV>
using min_11 = parameter::from0To1<SineStack_impl::minmax7_t<NV>, 
                                   1, 
                                   min_3Range>;

template <int NV>
using min_12 = parameter::from0To1<SineStack_impl::minmax4_t<NV>, 
                                   1, 
                                   min_0Range>;

template <int NV>
using min_13 = parameter::from0To1<SineStack_impl::minmax5_t<NV>, 
                                   1, 
                                   min_3Range>;

template <int NV>
using min_14 = parameter::from0To1<SineStack_impl::minmax2_t<NV>, 
                                   1, 
                                   min_0Range>;

template <int NV>
using min_15 = parameter::from0To1<SineStack_impl::minmax3_t<NV>, 
                                   1, 
                                   min_3Range>;

template <int NV>
using min = parameter::chain<min_InputRange, 
                             min_0<NV>, 
                             min_1<NV>, 
                             min_2<NV>, 
                             min_3<NV>, 
                             min_4<NV>, 
                             min_5<NV>, 
                             min_6<NV>, 
                             min_7<NV>, 
                             min_8<NV>, 
                             min_9<NV>, 
                             min_10<NV>, 
                             min_11<NV>, 
                             min_12<NV>, 
                             min_13<NV>, 
                             min_14<NV>, 
                             min_15<NV>>;

template <int NV>
using MODE = parameter::chain<ranges::Identity, 
                              parameter::plain<SineStack_impl::branch_t<NV>, 0>, 
                              parameter::plain<SineStack_impl::branch8_t<NV>, 0>, 
                              parameter::plain<SineStack_impl::branch7_t<NV>, 0>, 
                              parameter::plain<SineStack_impl::branch6_t<NV>, 0>, 
                              parameter::plain<SineStack_impl::branch5_t<NV>, 0>, 
                              parameter::plain<SineStack_impl::branch4_t<NV>, 0>, 
                              parameter::plain<SineStack_impl::branch2_t<NV>, 0>, 
                              parameter::plain<SineStack_impl::branch1_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(max_InputRange, 
                             1., 
                             30., 
                             1.);
template <int NV>
using max_0 = parameter::from0To1<SineStack_impl::minmax_t<NV>, 
                                  2, 
                                  min_0Range>;

template <int NV>
using max_1 = parameter::from0To1<SineStack_impl::minmax1_t<NV>, 
                                  2, 
                                  min_3Range>;

template <int NV>
using max_2 = parameter::from0To1<SineStack_impl::minmax14_t<NV>, 
                                  2, 
                                  min_0Range>;

template <int NV>
using max_3 = parameter::from0To1<SineStack_impl::minmax15_t<NV>, 
                                  2, 
                                  min_3Range>;

template <int NV>
using max_4 = parameter::from0To1<SineStack_impl::minmax13_t<NV>, 
                                  2, 
                                  min_3Range>;

template <int NV>
using max_5 = parameter::from0To1<SineStack_impl::minmax12_t<NV>, 
                                  2, 
                                  min_0Range>;

template <int NV>
using max_6 = parameter::from0To1<SineStack_impl::minmax10_t<NV>, 
                                  2, 
                                  min_0Range>;

template <int NV>
using max_7 = parameter::from0To1<SineStack_impl::minmax11_t<NV>, 
                                  2, 
                                  min_3Range>;

template <int NV>
using max_8 = parameter::from0To1<SineStack_impl::minmax8_t<NV>, 
                                  2, 
                                  min_0Range>;

template <int NV>
using max_9 = parameter::from0To1<SineStack_impl::minmax9_t<NV>, 
                                  2, 
                                  min_3Range>;

template <int NV>
using max_10 = parameter::from0To1<SineStack_impl::minmax6_t<NV>, 
                                   2, 
                                   min_0Range>;

template <int NV>
using max_11 = parameter::from0To1<SineStack_impl::minmax7_t<NV>, 
                                   2, 
                                   min_3Range>;

template <int NV>
using max_12 = parameter::from0To1<SineStack_impl::minmax4_t<NV>, 
                                   2, 
                                   min_0Range>;

template <int NV>
using max_13 = parameter::from0To1<SineStack_impl::minmax5_t<NV>, 
                                   2, 
                                   min_3Range>;

template <int NV>
using max_14 = parameter::from0To1<SineStack_impl::minmax2_t<NV>, 
                                   2, 
                                   min_0Range>;

template <int NV>
using max_15 = parameter::from0To1<SineStack_impl::minmax3_t<NV>, 
                                   2, 
                                   min_3Range>;

template <int NV>
using max = parameter::chain<max_InputRange, 
                             max_0<NV>, 
                             max_1<NV>, 
                             max_2<NV>, 
                             max_3<NV>, 
                             max_4<NV>, 
                             max_5<NV>, 
                             max_6<NV>, 
                             max_7<NV>, 
                             max_8<NV>, 
                             max_9<NV>, 
                             max_10<NV>, 
                             max_11<NV>, 
                             max_12<NV>, 
                             max_13<NV>, 
                             max_14<NV>, 
                             max_15<NV>>;

DECLARE_PARAMETER_RANGE_STEP(step_InputRange, 
                             0., 
                             12., 
                             1.);
DECLARE_PARAMETER_RANGE(step_0Range, 
                        0., 
                        12.);

template <int NV>
using step_0 = parameter::from0To1<SineStack_impl::minmax_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_1 = parameter::from0To1<SineStack_impl::minmax1_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_2 = parameter::from0To1<SineStack_impl::minmax14_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_3 = parameter::from0To1<SineStack_impl::minmax15_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_4 = parameter::from0To1<SineStack_impl::minmax12_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_5 = parameter::from0To1<SineStack_impl::minmax13_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_6 = parameter::from0To1<SineStack_impl::minmax10_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_7 = parameter::from0To1<SineStack_impl::minmax11_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_8 = parameter::from0To1<SineStack_impl::minmax8_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_9 = parameter::from0To1<SineStack_impl::minmax9_t<NV>, 
                                   4, 
                                   step_0Range>;

template <int NV>
using step_10 = parameter::from0To1<SineStack_impl::minmax6_t<NV>, 
                                    4, 
                                    step_0Range>;

template <int NV>
using step_11 = parameter::from0To1<SineStack_impl::minmax7_t<NV>, 
                                    4, 
                                    step_0Range>;

template <int NV>
using step_12 = parameter::from0To1<SineStack_impl::minmax4_t<NV>, 
                                    4, 
                                    step_0Range>;

template <int NV>
using step_13 = parameter::from0To1<SineStack_impl::minmax5_t<NV>, 
                                    4, 
                                    step_0Range>;

template <int NV>
using step_14 = parameter::from0To1<SineStack_impl::minmax2_t<NV>, 
                                    4, 
                                    step_0Range>;

template <int NV>
using step_15 = parameter::from0To1<SineStack_impl::minmax3_t<NV>, 
                                    4, 
                                    step_0Range>;

template <int NV>
using step = parameter::chain<step_InputRange, 
                              step_0<NV>, 
                              step_1<NV>, 
                              step_2<NV>, 
                              step_3<NV>, 
                              step_4<NV>, 
                              step_5<NV>, 
                              step_6<NV>, 
                              step_7<NV>, 
                              step_8<NV>, 
                              step_9<NV>, 
                              step_10<NV>, 
                              step_11<NV>, 
                              step_12<NV>, 
                              step_13<NV>, 
                              step_14<NV>, 
                              step_15<NV>>;

template <int NV>
using GLOBALOFFSET = parameter::plain<SineStack_impl::pma_t<NV>, 
                                      1>;
template <int NV>
using OFFSETMOD = parameter::plain<SineStack_impl::pma1_t<NV>, 
                                   1>;
template <int NV>
using pitchinput = parameter::plain<SineStack_impl::softbypass_switch9_t<NV>, 
                                    0>;
template <int NV>
using SineStack_t_plist = parameter::list<GLOBALOFFSET<NV>, 
                                          OFFSET<NV>, 
                                          OFFSETMOD<NV>, 
                                          SRC<NV>, 
                                          min<NV>, 
                                          MODE<NV>, 
                                          max<NV>, 
                                          step<NV>, 
                                          pitchinput<NV>>;
}

template <int NV>
using SineStack_t_ = container::chain<SineStack_t_parameters::SineStack_t_plist<NV>, 
                                      wrap::fix<2, modchain_t<NV>>, 
                                      pack_resizer1_t, 
                                      sliderbank1_t<NV>, 
                                      split44_t<NV>, 
                                      core::gain<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public SineStack_impl::SineStack_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(SineStack);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(146)
		{
			0x005B, 0x0000, 0x4700, 0x4F4C, 0x4142, 0x4F4C, 0x4646, 0x4553, 
            0x0054, 0x0000, 0xBF80, 0x0000, 0x3F80, 0xD439, 0xBCD2, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x015B, 0x0000, 0x4F00, 0x4646, 0x4553, 
            0x0054, 0x0000, 0x0000, 0x0000, 0x3F80, 0x6358, 0x3E8B, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x4F00, 0x4646, 0x4553, 
            0x4D54, 0x444F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x893F, 0x2C61, 
            0x00BD, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 0x5253, 
            0x0043, 0x0000, 0x0000, 0x0000, 0x4180, 0x084C, 0x4142, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x6D00, 0x6E69, 0x0000, 
            0x8000, 0x003F, 0xF000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0005, 0x0000, 0x4F4D, 0x4544, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0006, 0x0000, 0x616D, 0x0078, 0x0000, 0x3F80, 0x0000, 
            0x41F0, 0x0000, 0x41F0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x075B, 
            0x0000, 0x7300, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 0x4140, 
            0x0000, 0x40A0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x085B, 0x0000, 
            0x7000, 0x7469, 0x6863, 0x6E69, 0x7570, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x40E0, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                       // SineStack_impl::modchain_t<NV>
		auto& chain10 = this->getT(0).getT(0);                                                // SineStack_impl::chain10_t<NV>
		auto& cable_table11 = this->getT(0).getT(0).getT(0);                                  // SineStack_impl::cable_table11_t<NV>
		auto& cable_table12 = this->getT(0).getT(0).getT(1);                                  // SineStack_impl::cable_table12_t<NV>
		auto& split21 = this->getT(0).getT(0).getT(2);                                        // SineStack_impl::split21_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(2).getT(0);                     // SineStack_impl::event_data_reader7_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(2).getT(1);                                // SineStack_impl::chain29_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(2).getT(1).getT(0);                        // SineStack_impl::branch3_t<NV>
		auto& chain30 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);                // SineStack_impl::chain30_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(0); // SineStack_impl::global_cable16_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(1);          // math::add<NV>
		auto& chain31 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);                // SineStack_impl::chain31_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1).getT(0); // SineStack_impl::global_cable17_t<NV>
		auto& add17 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain32 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);                // SineStack_impl::chain32_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2).getT(0); // SineStack_impl::global_cable18_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain33 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(3);                // SineStack_impl::chain33_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(3).getT(0); // SineStack_impl::global_cable19_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& chain34 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(4);                // SineStack_impl::chain34_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(4).getT(0); // SineStack_impl::global_cable20_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(4).getT(1);          // math::add<NV>
		auto& chain35 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(5);                // SineStack_impl::chain35_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(5).getT(0); // SineStack_impl::global_cable21_t<NV>
		auto& add21 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(5).getT(1);          // math::add<NV>
		auto& chain36 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(6);                // SineStack_impl::chain36_t<NV>
		auto& global_cable22 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(6).getT(0); // SineStack_impl::global_cable22_t<NV>
		auto& add22 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(6).getT(1);          // math::add<NV>
		auto& chain37 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(7);                // SineStack_impl::chain37_t<NV>
		auto& global_cable23 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(7).getT(0); // SineStack_impl::global_cable23_t<NV>
		auto& add23 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(7).getT(1);          // math::add<NV>
		auto& peak2 = this->getT(0).getT(0).getT(2).getT(1).getT(1);                          // SineStack_impl::peak2_t<NV>
		auto& clear = this->getT(0).getT(0).getT(2).getT(1).getT(2);                          // math::clear<NV>
		auto& input_toggle1x = this->getT(0).getT(0).getT(3);                                 // SineStack_impl::input_toggle1x_t<NV>
		auto& softbypass_switch9 = this->getT(0).getT(1);                                     // SineStack_impl::softbypass_switch9_t<NV>
		auto& switcher = this->getT(0).getT(1).getT(0);                                       // SineStack_impl::switcher_t<NV>
		auto& sb_container = this->getT(0).getT(1).getT(1);                                   // SineStack_impl::sb_container_t<NV>
		auto& sb1 = this->getT(0).getT(1).getT(1).getT(0);                                    // SineStack_impl::sb1_t<NV>
		auto& chain = this->getT(0).getT(1).getT(1).getT(0).getT(0);                          // SineStack_impl::chain_t<NV>
		auto& global_cable = this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(0);           // SineStack_impl::global_cable_t<NV>
		auto& add = this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(1);                    // math::add<NV>
		auto& sb2 = this->getT(0).getT(1).getT(1).getT(1);                                    // SineStack_impl::sb2_t<NV>
		auto& chain1 = this->getT(0).getT(1).getT(1).getT(1).getT(0);                         // SineStack_impl::chain1_t<NV>
		auto& global_cable1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0);          // SineStack_impl::global_cable1_t<NV>
		auto& add1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1);                   // math::add<NV>
		auto& sb3 = this->getT(0).getT(1).getT(1).getT(2);                                    // SineStack_impl::sb3_t<NV>
		auto& chain4 = this->getT(0).getT(1).getT(1).getT(2).getT(0);                         // SineStack_impl::chain4_t<NV>
		auto& global_cable2 = this->getT(0).getT(1).getT(1).getT(2).getT(0).getT(0);          // SineStack_impl::global_cable2_t<NV>
		auto& add2 = this->getT(0).getT(1).getT(1).getT(2).getT(0).getT(1);                   // math::add<NV>
		auto& sb4 = this->getT(0).getT(1).getT(1).getT(3);                                    // SineStack_impl::sb4_t<NV>
		auto& chain5 = this->getT(0).getT(1).getT(1).getT(3).getT(0);                         // SineStack_impl::chain5_t<NV>
		auto& global_cable3 = this->getT(0).getT(1).getT(1).getT(3).getT(0).getT(0);          // SineStack_impl::global_cable3_t<NV>
		auto& add3 = this->getT(0).getT(1).getT(1).getT(3).getT(0).getT(1);                   // math::add<NV>
		auto& sb5 = this->getT(0).getT(1).getT(1).getT(4);                                    // SineStack_impl::sb5_t<NV>
		auto& chain6 = this->getT(0).getT(1).getT(1).getT(4).getT(0);                         // SineStack_impl::chain6_t<NV>
		auto& global_cable4 = this->getT(0).getT(1).getT(1).getT(4).getT(0).getT(0);          // SineStack_impl::global_cable4_t<NV>
		auto& add4 = this->getT(0).getT(1).getT(1).getT(4).getT(0).getT(1);                   // math::add<NV>
		auto& sb6 = this->getT(0).getT(1).getT(1).getT(5);                                    // SineStack_impl::sb6_t<NV>
		auto& chain7 = this->getT(0).getT(1).getT(1).getT(5).getT(0);                         // SineStack_impl::chain7_t<NV>
		auto& global_cable5 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0);          // SineStack_impl::global_cable5_t<NV>
		auto& add5 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(1);                   // math::add<NV>
		auto& sb7 = this->getT(0).getT(1).getT(1).getT(6);                                    // SineStack_impl::sb7_t<NV>
		auto& chain8 = this->getT(0).getT(1).getT(1).getT(6).getT(0);                         // SineStack_impl::chain8_t<NV>
		auto& global_cable6 = this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(0);          // SineStack_impl::global_cable6_t<NV>
		auto& add6 = this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(1);                   // math::add<NV>
		auto& sb8 = this->getT(0).getT(1).getT(1).getT(7);                                    // SineStack_impl::sb8_t<NV>
		auto& chain9 = this->getT(0).getT(1).getT(1).getT(7).getT(0);                         // SineStack_impl::chain9_t<NV>
		auto& global_cable7 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0);          // SineStack_impl::global_cable7_t<NV>
		auto& add7 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1);                   // math::add<NV>
		auto& peak = this->getT(0).getT(1).getT(2);                                           // SineStack_impl::peak_t<NV>
		auto& clear1 = this->getT(0).getT(2);                                                 // math::clear<NV>
		auto& split17 = this->getT(0).getT(3);                                                // SineStack_impl::split17_t<NV>
		auto& pma = this->getT(0).getT(3).getT(0);                                            // SineStack_impl::pma_t<NV>
		auto& pma1 = this->getT(0).getT(3).getT(1);                                           // SineStack_impl::pma1_t<NV>
		auto& pack_resizer1 = this->getT(1);                                                  // SineStack_impl::pack_resizer1_t
		auto& sliderbank1 = this->getT(2);                                                    // SineStack_impl::sliderbank1_t<NV>
		auto& split44 = this->getT(3);                                                        // SineStack_impl::split44_t<NV>
		auto& chain64 = this->getT(3).getT(0);                                                // SineStack_impl::chain64_t<NV>
		auto& split1 = this->getT(3).getT(0).getT(0);                                         // SineStack_impl::split1_t<NV>
		auto& minmax = this->getT(3).getT(0).getT(0).getT(0);                                 // SineStack_impl::minmax_t<NV>
		auto& minmax1 = this->getT(3).getT(0).getT(0).getT(1);                                // SineStack_impl::minmax1_t<NV>
		auto& split = this->getT(3).getT(0).getT(1);                                          // SineStack_impl::split_t<NV>
		auto& pma_unscaled = this->getT(3).getT(0).getT(1).getT(0);                           // SineStack_impl::pma_unscaled_t<NV>
		auto& pma_unscaled1 = this->getT(3).getT(0).getT(1).getT(1);                          // SineStack_impl::pma_unscaled1_t<NV>
		auto& converter = this->getT(3).getT(0).getT(2);                                      // SineStack_impl::converter_t<NV>
		auto& branch = this->getT(3).getT(0).getT(3);                                         // SineStack_impl::branch_t<NV>
		auto& chain2 = this->getT(3).getT(0).getT(3).getT(0);                                 // SineStack_impl::chain2_t<NV>
		auto& oscillator54 = this->getT(3).getT(0).getT(3).getT(0).getT(0);                   // SineStack_impl::oscillator54_t<NV>
		auto& chain3 = this->getT(3).getT(0).getT(3).getT(1);                                 // SineStack_impl::chain3_t<NV>
		auto& file_player = this->getT(3).getT(0).getT(3).getT(1).getT(0);                    // SineStack_impl::file_player_t<NV>
		auto& chain71 = this->getT(3).getT(1);                                                // SineStack_impl::chain71_t<NV>
		auto& split14 = this->getT(3).getT(1).getT(0);                                        // SineStack_impl::split14_t<NV>
		auto& minmax14 = this->getT(3).getT(1).getT(0).getT(0);                               // SineStack_impl::minmax14_t<NV>
		auto& minmax15 = this->getT(3).getT(1).getT(0).getT(1);                               // SineStack_impl::minmax15_t<NV>
		auto& split15 = this->getT(3).getT(1).getT(1);                                        // SineStack_impl::split15_t<NV>
		auto& pma_unscaled15 = this->getT(3).getT(1).getT(1).getT(0);                         // SineStack_impl::pma_unscaled15_t<NV>
		auto& pma_unscaled16 = this->getT(3).getT(1).getT(1).getT(1);                         // SineStack_impl::pma_unscaled16_t<NV>
		auto& converter7 = this->getT(3).getT(1).getT(2);                                     // SineStack_impl::converter7_t<NV>
		auto& branch8 = this->getT(3).getT(1).getT(3);                                        // SineStack_impl::branch8_t<NV>
		auto& chain23 = this->getT(3).getT(1).getT(3).getT(0);                                // SineStack_impl::chain23_t<NV>
		auto& oscillator61 = this->getT(3).getT(1).getT(3).getT(0).getT(0);                   // SineStack_impl::oscillator61_t<NV>
		auto& chain24 = this->getT(3).getT(1).getT(3).getT(1);                                // SineStack_impl::chain24_t<NV>
		auto& file_player7 = this->getT(3).getT(1).getT(3).getT(1).getT(0);                   // SineStack_impl::file_player7_t<NV>
		auto& chain70 = this->getT(3).getT(2);                                                // SineStack_impl::chain70_t<NV>
		auto& split12 = this->getT(3).getT(2).getT(0);                                        // SineStack_impl::split12_t<NV>
		auto& minmax12 = this->getT(3).getT(2).getT(0).getT(0);                               // SineStack_impl::minmax12_t<NV>
		auto& minmax13 = this->getT(3).getT(2).getT(0).getT(1);                               // SineStack_impl::minmax13_t<NV>
		auto& split13 = this->getT(3).getT(2).getT(1);                                        // SineStack_impl::split13_t<NV>
		auto& pma_unscaled13 = this->getT(3).getT(2).getT(1).getT(0);                         // SineStack_impl::pma_unscaled13_t<NV>
		auto& pma_unscaled14 = this->getT(3).getT(2).getT(1).getT(1);                         // SineStack_impl::pma_unscaled14_t<NV>
		auto& converter6 = this->getT(3).getT(2).getT(2);                                     // SineStack_impl::converter6_t<NV>
		auto& branch7 = this->getT(3).getT(2).getT(3);                                        // SineStack_impl::branch7_t<NV>
		auto& chain21 = this->getT(3).getT(2).getT(3).getT(0);                                // SineStack_impl::chain21_t<NV>
		auto& oscillator60 = this->getT(3).getT(2).getT(3).getT(0).getT(0);                   // SineStack_impl::oscillator60_t<NV>
		auto& chain22 = this->getT(3).getT(2).getT(3).getT(1);                                // SineStack_impl::chain22_t<NV>
		auto& file_player6 = this->getT(3).getT(2).getT(3).getT(1).getT(0);                   // SineStack_impl::file_player6_t<NV>
		auto& chain69 = this->getT(3).getT(3);                                                // SineStack_impl::chain69_t<NV>
		auto& split10 = this->getT(3).getT(3).getT(0);                                        // SineStack_impl::split10_t<NV>
		auto& minmax10 = this->getT(3).getT(3).getT(0).getT(0);                               // SineStack_impl::minmax10_t<NV>
		auto& minmax11 = this->getT(3).getT(3).getT(0).getT(1);                               // SineStack_impl::minmax11_t<NV>
		auto& split11 = this->getT(3).getT(3).getT(1);                                        // SineStack_impl::split11_t<NV>
		auto& pma_unscaled11 = this->getT(3).getT(3).getT(1).getT(0);                         // SineStack_impl::pma_unscaled11_t<NV>
		auto& pma_unscaled12 = this->getT(3).getT(3).getT(1).getT(1);                         // SineStack_impl::pma_unscaled12_t<NV>
		auto& converter5 = this->getT(3).getT(3).getT(2);                                     // SineStack_impl::converter5_t<NV>
		auto& branch6 = this->getT(3).getT(3).getT(3);                                        // SineStack_impl::branch6_t<NV>
		auto& chain19 = this->getT(3).getT(3).getT(3).getT(0);                                // SineStack_impl::chain19_t<NV>
		auto& oscillator59 = this->getT(3).getT(3).getT(3).getT(0).getT(0);                   // SineStack_impl::oscillator59_t<NV>
		auto& chain20 = this->getT(3).getT(3).getT(3).getT(1);                                // SineStack_impl::chain20_t<NV>
		auto& file_player5 = this->getT(3).getT(3).getT(3).getT(1).getT(0);                   // SineStack_impl::file_player5_t<NV>
		auto& chain68 = this->getT(3).getT(4);                                                // SineStack_impl::chain68_t<NV>
		auto& split8 = this->getT(3).getT(4).getT(0);                                         // SineStack_impl::split8_t<NV>
		auto& minmax8 = this->getT(3).getT(4).getT(0).getT(0);                                // SineStack_impl::minmax8_t<NV>
		auto& minmax9 = this->getT(3).getT(4).getT(0).getT(1);                                // SineStack_impl::minmax9_t<NV>
		auto& split9 = this->getT(3).getT(4).getT(1);                                         // SineStack_impl::split9_t<NV>
		auto& pma_unscaled9 = this->getT(3).getT(4).getT(1).getT(0);                          // SineStack_impl::pma_unscaled9_t<NV>
		auto& pma_unscaled10 = this->getT(3).getT(4).getT(1).getT(1);                         // SineStack_impl::pma_unscaled10_t<NV>
		auto& converter4 = this->getT(3).getT(4).getT(2);                                     // SineStack_impl::converter4_t<NV>
		auto& branch5 = this->getT(3).getT(4).getT(3);                                        // SineStack_impl::branch5_t<NV>
		auto& chain17 = this->getT(3).getT(4).getT(3).getT(0);                                // SineStack_impl::chain17_t<NV>
		auto& oscillator58 = this->getT(3).getT(4).getT(3).getT(0).getT(0);                   // SineStack_impl::oscillator58_t<NV>
		auto& chain18 = this->getT(3).getT(4).getT(3).getT(1);                                // SineStack_impl::chain18_t<NV>
		auto& file_player4 = this->getT(3).getT(4).getT(3).getT(1).getT(0);                   // SineStack_impl::file_player4_t<NV>
		auto& chain67 = this->getT(3).getT(5);                                                // SineStack_impl::chain67_t<NV>
		auto& split6 = this->getT(3).getT(5).getT(0);                                         // SineStack_impl::split6_t<NV>
		auto& minmax6 = this->getT(3).getT(5).getT(0).getT(0);                                // SineStack_impl::minmax6_t<NV>
		auto& minmax7 = this->getT(3).getT(5).getT(0).getT(1);                                // SineStack_impl::minmax7_t<NV>
		auto& split7 = this->getT(3).getT(5).getT(1);                                         // SineStack_impl::split7_t<NV>
		auto& pma_unscaled7 = this->getT(3).getT(5).getT(1).getT(0);                          // SineStack_impl::pma_unscaled7_t<NV>
		auto& pma_unscaled8 = this->getT(3).getT(5).getT(1).getT(1);                          // SineStack_impl::pma_unscaled8_t<NV>
		auto& converter3 = this->getT(3).getT(5).getT(2);                                     // SineStack_impl::converter3_t<NV>
		auto& branch4 = this->getT(3).getT(5).getT(3);                                        // SineStack_impl::branch4_t<NV>
		auto& chain15 = this->getT(3).getT(5).getT(3).getT(0);                                // SineStack_impl::chain15_t<NV>
		auto& oscillator57 = this->getT(3).getT(5).getT(3).getT(0).getT(0);                   // SineStack_impl::oscillator57_t<NV>
		auto& chain16 = this->getT(3).getT(5).getT(3).getT(1);                                // SineStack_impl::chain16_t<NV>
		auto& file_player3 = this->getT(3).getT(5).getT(3).getT(1).getT(0);                   // SineStack_impl::file_player3_t<NV>
		auto& chain66 = this->getT(3).getT(6);                                                // SineStack_impl::chain66_t<NV>
		auto& split4 = this->getT(3).getT(6).getT(0);                                         // SineStack_impl::split4_t<NV>
		auto& minmax4 = this->getT(3).getT(6).getT(0).getT(0);                                // SineStack_impl::minmax4_t<NV>
		auto& minmax5 = this->getT(3).getT(6).getT(0).getT(1);                                // SineStack_impl::minmax5_t<NV>
		auto& split5 = this->getT(3).getT(6).getT(1);                                         // SineStack_impl::split5_t<NV>
		auto& pma_unscaled5 = this->getT(3).getT(6).getT(1).getT(0);                          // SineStack_impl::pma_unscaled5_t<NV>
		auto& pma_unscaled6 = this->getT(3).getT(6).getT(1).getT(1);                          // SineStack_impl::pma_unscaled6_t<NV>
		auto& converter2 = this->getT(3).getT(6).getT(2);                                     // SineStack_impl::converter2_t<NV>
		auto& branch2 = this->getT(3).getT(6).getT(3);                                        // SineStack_impl::branch2_t<NV>
		auto& chain13 = this->getT(3).getT(6).getT(3).getT(0);                                // SineStack_impl::chain13_t<NV>
		auto& oscillator56 = this->getT(3).getT(6).getT(3).getT(0).getT(0);                   // SineStack_impl::oscillator56_t<NV>
		auto& chain14 = this->getT(3).getT(6).getT(3).getT(1);                                // SineStack_impl::chain14_t<NV>
		auto& file_player2 = this->getT(3).getT(6).getT(3).getT(1).getT(0);                   // SineStack_impl::file_player2_t<NV>
		auto& chain65 = this->getT(3).getT(7);                                                // SineStack_impl::chain65_t<NV>
		auto& split2 = this->getT(3).getT(7).getT(0);                                         // SineStack_impl::split2_t<NV>
		auto& minmax2 = this->getT(3).getT(7).getT(0).getT(0);                                // SineStack_impl::minmax2_t<NV>
		auto& minmax3 = this->getT(3).getT(7).getT(0).getT(1);                                // SineStack_impl::minmax3_t<NV>
		auto& split3 = this->getT(3).getT(7).getT(1);                                         // SineStack_impl::split3_t<NV>
		auto& pma_unscaled3 = this->getT(3).getT(7).getT(1).getT(0);                          // SineStack_impl::pma_unscaled3_t<NV>
		auto& pma_unscaled4 = this->getT(3).getT(7).getT(1).getT(1);                          // SineStack_impl::pma_unscaled4_t<NV>
		auto& converter1 = this->getT(3).getT(7).getT(2);                                     // SineStack_impl::converter1_t<NV>
		auto& branch1 = this->getT(3).getT(7).getT(3);                                        // SineStack_impl::branch1_t<NV>
		auto& chain11 = this->getT(3).getT(7).getT(3).getT(0);                                // SineStack_impl::chain11_t<NV>
		auto& oscillator55 = this->getT(3).getT(7).getT(3).getT(0).getT(0);                   // SineStack_impl::oscillator55_t<NV>
		auto& chain12 = this->getT(3).getT(7).getT(3).getT(1);                                // SineStack_impl::chain12_t<NV>
		auto& file_player1 = this->getT(3).getT(7).getT(3).getT(1).getT(0);                   // SineStack_impl::file_player1_t<NV>
		auto& gain = this->getT(4);                                                           // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		softbypass_switch9.getParameterT(0).connectT(0, switcher); // Switch -> switcher::Value
		this->getParameterT(0).connectT(0, pma);                   // GLOBALOFFSET -> pma::Multiply
		
		this->getParameterT(1).connectT(0, pma1); // OFFSET -> pma1::Add
		
		this->getParameterT(2).connectT(0, pma1); // OFFSETMOD -> pma1::Multiply
		
		auto& SRC_p = this->getParameterT(3);
		SRC_p.connectT(0, cable_table11);      // SRC -> cable_table11::Value
		SRC_p.connectT(1, cable_table12);      // SRC -> cable_table12::Value
		SRC_p.connectT(2, event_data_reader7); // SRC -> event_data_reader7::SlotIndex
		
		auto& min_p = this->getParameterT(4);
		min_p.connectT(0, minmax);   // min -> minmax::Minimum
		min_p.connectT(1, minmax1);  // min -> minmax1::Minimum
		min_p.connectT(2, minmax14); // min -> minmax14::Minimum
		min_p.connectT(3, minmax15); // min -> minmax15::Minimum
		min_p.connectT(4, minmax12); // min -> minmax12::Minimum
		min_p.connectT(5, minmax13); // min -> minmax13::Minimum
		min_p.connectT(6, minmax10); // min -> minmax10::Minimum
		min_p.connectT(7, minmax11); // min -> minmax11::Minimum
		min_p.connectT(8, minmax8);  // min -> minmax8::Minimum
		min_p.connectT(9, minmax9);  // min -> minmax9::Minimum
		min_p.connectT(10, minmax6); // min -> minmax6::Minimum
		min_p.connectT(11, minmax7); // min -> minmax7::Minimum
		min_p.connectT(12, minmax4); // min -> minmax4::Minimum
		min_p.connectT(13, minmax5); // min -> minmax5::Minimum
		min_p.connectT(14, minmax2); // min -> minmax2::Minimum
		min_p.connectT(15, minmax3); // min -> minmax3::Minimum
		
		auto& MODE_p = this->getParameterT(5);
		MODE_p.connectT(0, branch);  // MODE -> branch::Index
		MODE_p.connectT(1, branch8); // MODE -> branch8::Index
		MODE_p.connectT(2, branch7); // MODE -> branch7::Index
		MODE_p.connectT(3, branch6); // MODE -> branch6::Index
		MODE_p.connectT(4, branch5); // MODE -> branch5::Index
		MODE_p.connectT(5, branch4); // MODE -> branch4::Index
		MODE_p.connectT(6, branch2); // MODE -> branch2::Index
		MODE_p.connectT(7, branch1); // MODE -> branch1::Index
		
		auto& max_p = this->getParameterT(6);
		max_p.connectT(0, minmax);   // max -> minmax::Maximum
		max_p.connectT(1, minmax1);  // max -> minmax1::Maximum
		max_p.connectT(2, minmax14); // max -> minmax14::Maximum
		max_p.connectT(3, minmax15); // max -> minmax15::Maximum
		max_p.connectT(4, minmax13); // max -> minmax13::Maximum
		max_p.connectT(5, minmax12); // max -> minmax12::Maximum
		max_p.connectT(6, minmax10); // max -> minmax10::Maximum
		max_p.connectT(7, minmax11); // max -> minmax11::Maximum
		max_p.connectT(8, minmax8);  // max -> minmax8::Maximum
		max_p.connectT(9, minmax9);  // max -> minmax9::Maximum
		max_p.connectT(10, minmax6); // max -> minmax6::Maximum
		max_p.connectT(11, minmax7); // max -> minmax7::Maximum
		max_p.connectT(12, minmax4); // max -> minmax4::Maximum
		max_p.connectT(13, minmax5); // max -> minmax5::Maximum
		max_p.connectT(14, minmax2); // max -> minmax2::Maximum
		max_p.connectT(15, minmax3); // max -> minmax3::Maximum
		
		auto& step_p = this->getParameterT(7);
		step_p.connectT(0, minmax);   // step -> minmax::Step
		step_p.connectT(1, minmax1);  // step -> minmax1::Step
		step_p.connectT(2, minmax14); // step -> minmax14::Step
		step_p.connectT(3, minmax15); // step -> minmax15::Step
		step_p.connectT(4, minmax12); // step -> minmax12::Step
		step_p.connectT(5, minmax13); // step -> minmax13::Step
		step_p.connectT(6, minmax10); // step -> minmax10::Step
		step_p.connectT(7, minmax11); // step -> minmax11::Step
		step_p.connectT(8, minmax8);  // step -> minmax8::Step
		step_p.connectT(9, minmax9);  // step -> minmax9::Step
		step_p.connectT(10, minmax6); // step -> minmax6::Step
		step_p.connectT(11, minmax7); // step -> minmax7::Step
		step_p.connectT(12, minmax4); // step -> minmax4::Step
		step_p.connectT(13, minmax5); // step -> minmax5::Step
		step_p.connectT(14, minmax2); // step -> minmax2::Step
		step_p.connectT(15, minmax3); // step -> minmax3::Step
		
		this->getParameterT(8).connectT(0, softbypass_switch9); // pitchinput -> softbypass_switch9::Switch
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable16.getWrappedObject().getParameter().connectT(0, add16);          // global_cable16 -> add16::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add17);          // global_cable17 -> add17::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add18);          // global_cable18 -> add18::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add19);          // global_cable19 -> add19::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add20);          // global_cable20 -> add20::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add21);          // global_cable21 -> add21::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add22);          // global_cable22 -> add22::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add23);          // global_cable23 -> add23::Value
		cable_table11.getWrappedObject().getParameter().connectT(0, branch3);         // cable_table11 -> branch3::Index
		converter.getWrappedObject().getParameter().connectT(0, oscillator54);        // converter -> oscillator54::FreqRatio
		converter.getWrappedObject().getParameter().connectT(1, file_player);         // converter -> file_player::FreqRatio
		pma_unscaled.getWrappedObject().getParameter().connectT(0, converter);        // pma_unscaled -> converter::Value
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, pma_unscaled);    // pma_unscaled1 -> pma_unscaled::Add
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled1);          // minmax -> pma_unscaled1::Multiply
		converter7.getWrappedObject().getParameter().connectT(0, oscillator61);       // converter7 -> oscillator61::FreqRatio
		converter7.getWrappedObject().getParameter().connectT(1, file_player7);       // converter7 -> file_player7::FreqRatio
		pma_unscaled15.getWrappedObject().getParameter().connectT(0, converter7);     // pma_unscaled15 -> converter7::Value
		pma_unscaled16.getWrappedObject().getParameter().connectT(0, pma_unscaled15); // pma_unscaled16 -> pma_unscaled15::Add
		minmax14.getWrappedObject().getParameter().connectT(0, pma_unscaled16);       // minmax14 -> pma_unscaled16::Multiply
		converter6.getWrappedObject().getParameter().connectT(0, oscillator60);       // converter6 -> oscillator60::FreqRatio
		converter6.getWrappedObject().getParameter().connectT(1, file_player6);       // converter6 -> file_player6::FreqRatio
		pma_unscaled13.getWrappedObject().getParameter().connectT(0, converter6);     // pma_unscaled13 -> converter6::Value
		pma_unscaled14.getWrappedObject().getParameter().connectT(0, pma_unscaled13); // pma_unscaled14 -> pma_unscaled13::Add
		minmax12.getWrappedObject().getParameter().connectT(0, pma_unscaled14);       // minmax12 -> pma_unscaled14::Multiply
		converter5.getWrappedObject().getParameter().connectT(0, oscillator59);       // converter5 -> oscillator59::FreqRatio
		converter5.getWrappedObject().getParameter().connectT(1, file_player5);       // converter5 -> file_player5::FreqRatio
		pma_unscaled11.getWrappedObject().getParameter().connectT(0, converter5);     // pma_unscaled11 -> converter5::Value
		pma_unscaled12.getWrappedObject().getParameter().connectT(0, pma_unscaled11); // pma_unscaled12 -> pma_unscaled11::Add
		minmax10.getWrappedObject().getParameter().connectT(0, pma_unscaled12);       // minmax10 -> pma_unscaled12::Multiply
		converter4.getWrappedObject().getParameter().connectT(0, oscillator58);       // converter4 -> oscillator58::FreqRatio
		converter4.getWrappedObject().getParameter().connectT(1, file_player4);       // converter4 -> file_player4::FreqRatio
		pma_unscaled9.getWrappedObject().getParameter().connectT(0, converter4);      // pma_unscaled9 -> converter4::Value
		pma_unscaled10.getWrappedObject().getParameter().connectT(0, pma_unscaled9);  // pma_unscaled10 -> pma_unscaled9::Add
		minmax8.getWrappedObject().getParameter().connectT(0, pma_unscaled10);        // minmax8 -> pma_unscaled10::Multiply
		converter3.getWrappedObject().getParameter().connectT(0, oscillator57);       // converter3 -> oscillator57::FreqRatio
		converter3.getWrappedObject().getParameter().connectT(1, file_player3);       // converter3 -> file_player3::FreqRatio
		pma_unscaled7.getWrappedObject().getParameter().connectT(0, converter3);      // pma_unscaled7 -> converter3::Value
		pma_unscaled8.getWrappedObject().getParameter().connectT(0, pma_unscaled7);   // pma_unscaled8 -> pma_unscaled7::Add
		minmax6.getWrappedObject().getParameter().connectT(0, pma_unscaled8);         // minmax6 -> pma_unscaled8::Multiply
		converter2.getWrappedObject().getParameter().connectT(0, oscillator56);       // converter2 -> oscillator56::FreqRatio
		converter2.getWrappedObject().getParameter().connectT(1, file_player2);       // converter2 -> file_player2::FreqRatio
		pma_unscaled5.getWrappedObject().getParameter().connectT(0, converter2);      // pma_unscaled5 -> converter2::Value
		pma_unscaled6.getWrappedObject().getParameter().connectT(0, pma_unscaled5);   // pma_unscaled6 -> pma_unscaled5::Add
		minmax4.getWrappedObject().getParameter().connectT(0, pma_unscaled6);         // minmax4 -> pma_unscaled6::Multiply
		converter1.getWrappedObject().getParameter().connectT(0, oscillator55);       // converter1 -> oscillator55::FreqRatio
		converter1.getWrappedObject().getParameter().connectT(1, file_player1);       // converter1 -> file_player1::FreqRatio
		pma_unscaled3.getWrappedObject().getParameter().connectT(0, converter1);      // pma_unscaled3 -> converter1::Value
		pma_unscaled4.getWrappedObject().getParameter().connectT(0, pma_unscaled3);   // pma_unscaled4 -> pma_unscaled3::Add
		minmax2.getWrappedObject().getParameter().connectT(0, pma_unscaled4);         // minmax2 -> pma_unscaled4::Multiply
		auto& sliderbank1_p = sliderbank1.getWrappedObject().getParameter();
		sliderbank1_p.getParameterT(0).connectT(0, minmax);                          // sliderbank1 -> minmax::Value
		sliderbank1_p.getParameterT(1).connectT(0, minmax14);                        // sliderbank1 -> minmax14::Value
		sliderbank1_p.getParameterT(2).connectT(0, minmax12);                        // sliderbank1 -> minmax12::Value
		sliderbank1_p.getParameterT(3).connectT(0, minmax10);                        // sliderbank1 -> minmax10::Value
		sliderbank1_p.getParameterT(4).connectT(0, minmax8);                         // sliderbank1 -> minmax8::Value
		sliderbank1_p.getParameterT(5).connectT(0, minmax6);                         // sliderbank1 -> minmax6::Value
		sliderbank1_p.getParameterT(6).connectT(0, minmax4);                         // sliderbank1 -> minmax4::Value
		sliderbank1_p.getParameterT(7).connectT(0, minmax2);                         // sliderbank1 -> minmax2::Value
		pma1.getWrappedObject().getParameter().connectT(0, sliderbank1);             // pma1 -> sliderbank1::Value
		input_toggle1x.getWrappedObject().getParameter().connectT(0, pma1);          // input_toggle1x -> pma1::Value
		cable_table12.getWrappedObject().getParameter().connectT(0, input_toggle1x); // cable_table12 -> input_toggle1x::Input
		event_data_reader7.getParameter().connectT(0, input_toggle1x);               // event_data_reader7 -> input_toggle1x::Value1
		peak2.getParameter().connectT(0, input_toggle1x);                            // peak2 -> input_toggle1x::Value2
		global_cable.getWrappedObject().getParameter().connectT(0, add);             // global_cable -> add::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add1);           // global_cable1 -> add1::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);           // global_cable2 -> add2::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add3);           // global_cable3 -> add3::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add4);           // global_cable4 -> add4::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add5);           // global_cable5 -> add5::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add6);           // global_cable6 -> add6::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add7);           // global_cable7 -> add7::Value
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1);                           // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2);                           // switcher -> sb2::Bypassed
		switcher_p.getParameterT(2).connectT(0, sb3);                           // switcher -> sb3::Bypassed
		switcher_p.getParameterT(3).connectT(0, sb4);                           // switcher -> sb4::Bypassed
		switcher_p.getParameterT(4).connectT(0, sb5);                           // switcher -> sb5::Bypassed
		switcher_p.getParameterT(5).connectT(0, sb6);                           // switcher -> sb6::Bypassed
		switcher_p.getParameterT(6).connectT(0, sb7);                           // switcher -> sb7::Bypassed
		switcher_p.getParameterT(7).connectT(0, sb8);                           // switcher -> sb8::Bypassed
		minmax1.getWrappedObject().getParameter().connectT(0, pma_unscaled1);   // minmax1 -> pma_unscaled1::Add
		minmax15.getWrappedObject().getParameter().connectT(0, pma_unscaled16); // minmax15 -> pma_unscaled16::Add
		minmax13.getWrappedObject().getParameter().connectT(0, pma_unscaled14); // minmax13 -> pma_unscaled14::Add
		minmax11.getWrappedObject().getParameter().connectT(0, pma_unscaled12); // minmax11 -> pma_unscaled12::Add
		minmax9.getWrappedObject().getParameter().connectT(0, pma_unscaled10);  // minmax9 -> pma_unscaled10::Add
		minmax7.getWrappedObject().getParameter().connectT(0, pma_unscaled8);   // minmax7 -> pma_unscaled8::Add
		minmax5.getWrappedObject().getParameter().connectT(0, pma_unscaled6);   // minmax5 -> pma_unscaled6::Add
		minmax3.getWrappedObject().getParameter().connectT(0, pma_unscaled4);   // minmax3 -> pma_unscaled4::Add
		pma.getWrappedObject().getParameter().connectT(0, minmax1);             // pma -> minmax1::Value
		pma.getWrappedObject().getParameter().connectT(1, minmax15);            // pma -> minmax15::Value
		pma.getWrappedObject().getParameter().connectT(2, minmax13);            // pma -> minmax13::Value
		pma.getWrappedObject().getParameter().connectT(3, minmax11);            // pma -> minmax11::Value
		pma.getWrappedObject().getParameter().connectT(4, minmax9);             // pma -> minmax9::Value
		pma.getWrappedObject().getParameter().connectT(5, minmax7);             // pma -> minmax7::Value
		pma.getWrappedObject().getParameter().connectT(6, minmax5);             // pma -> minmax5::Value
		pma.getWrappedObject().getParameter().connectT(7, minmax3);             // pma -> minmax3::Value
		peak.getParameter().connectT(0, pma);                                   // peak -> pma::Add
		
		// Default Values --------------------------------------------------------------------------
		
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
		
		; // softbypass_switch9::Switch is automated
		
		; // switcher::Value is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add1::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add3::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		pma.setParameterT(0, 0.914643); // control::pma::Value
		;                               // pma::Multiply is automated
		;                               // pma::Add is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		pack_resizer1.setParameterT(0, 8.); // control::pack_resizer::NumSliders
		
		; // sliderbank1::Value is automated
		
		;                                  // minmax::Value is automated
		;                                  // minmax::Minimum is automated
		;                                  // minmax::Maximum is automated
		minmax.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                  // minmax::Step is automated
		minmax.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                   // minmax1::Value is automated
		;                                   // minmax1::Minimum is automated
		;                                   // minmax1::Maximum is automated
		minmax1.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                   // minmax1::Step is automated
		minmax1.setParameterT(5, 0.);       // control::minmax::Polarity
		
		pma_unscaled.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled.setParameterT(1, 0.); // control::pma_unscaled::Multiply
		;                                  // pma_unscaled::Add is automated
		
		pma_unscaled1.setParameterT(0, 1.); // control::pma_unscaled::Value
		;                                   // pma_unscaled1::Multiply is automated
		;                                   // pma_unscaled1::Add is automated
		
		; // converter::Value is automated
		
		; // branch::Index is automated
		
		oscillator54.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator54.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator54::FreqRatio is automated
		oscillator54.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator54.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator54.setParameterT(5, 0.193006); // core::oscillator::Gain
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		;                                    // minmax14::Value is automated
		;                                    // minmax14::Minimum is automated
		;                                    // minmax14::Maximum is automated
		minmax14.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                    // minmax14::Step is automated
		minmax14.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                    // minmax15::Value is automated
		;                                    // minmax15::Minimum is automated
		;                                    // minmax15::Maximum is automated
		minmax15.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                    // minmax15::Step is automated
		minmax15.setParameterT(5, 0.);       // control::minmax::Polarity
		
		pma_unscaled15.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled15.setParameterT(1, 0.); // control::pma_unscaled::Multiply
		;                                    // pma_unscaled15::Add is automated
		
		pma_unscaled16.setParameterT(0, 1.); // control::pma_unscaled::Value
		;                                    // pma_unscaled16::Multiply is automated
		;                                    // pma_unscaled16::Add is automated
		
		; // converter7::Value is automated
		
		; // branch8::Index is automated
		
		oscillator61.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator61.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator61::FreqRatio is automated
		oscillator61.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator61.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator61.setParameterT(5, 0.193006); // core::oscillator::Gain
		
		file_player7.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player7.setParameterT(1, 1.);   // core::file_player::Gate
		file_player7.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player7::FreqRatio is automated
		
		;                                    // minmax12::Value is automated
		;                                    // minmax12::Minimum is automated
		;                                    // minmax12::Maximum is automated
		minmax12.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                    // minmax12::Step is automated
		minmax12.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                    // minmax13::Value is automated
		;                                    // minmax13::Minimum is automated
		;                                    // minmax13::Maximum is automated
		minmax13.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                    // minmax13::Step is automated
		minmax13.setParameterT(5, 0.);       // control::minmax::Polarity
		
		pma_unscaled13.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled13.setParameterT(1, 0.); // control::pma_unscaled::Multiply
		;                                    // pma_unscaled13::Add is automated
		
		pma_unscaled14.setParameterT(0, 1.); // control::pma_unscaled::Value
		;                                    // pma_unscaled14::Multiply is automated
		;                                    // pma_unscaled14::Add is automated
		
		; // converter6::Value is automated
		
		; // branch7::Index is automated
		
		oscillator60.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator60.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator60::FreqRatio is automated
		oscillator60.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator60.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator60.setParameterT(5, 0.193006); // core::oscillator::Gain
		
		file_player6.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player6.setParameterT(1, 1.);   // core::file_player::Gate
		file_player6.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player6::FreqRatio is automated
		
		;                                    // minmax10::Value is automated
		;                                    // minmax10::Minimum is automated
		;                                    // minmax10::Maximum is automated
		minmax10.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                    // minmax10::Step is automated
		minmax10.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                    // minmax11::Value is automated
		;                                    // minmax11::Minimum is automated
		;                                    // minmax11::Maximum is automated
		minmax11.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                    // minmax11::Step is automated
		minmax11.setParameterT(5, 0.);       // control::minmax::Polarity
		
		pma_unscaled11.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled11.setParameterT(1, 0.); // control::pma_unscaled::Multiply
		;                                    // pma_unscaled11::Add is automated
		
		pma_unscaled12.setParameterT(0, 1.); // control::pma_unscaled::Value
		;                                    // pma_unscaled12::Multiply is automated
		;                                    // pma_unscaled12::Add is automated
		
		; // converter5::Value is automated
		
		; // branch6::Index is automated
		
		oscillator59.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator59.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator59::FreqRatio is automated
		oscillator59.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator59.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator59.setParameterT(5, 0.193006); // core::oscillator::Gain
		
		file_player5.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player5.setParameterT(1, 1.);   // core::file_player::Gate
		file_player5.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player5::FreqRatio is automated
		
		;                                   // minmax8::Value is automated
		;                                   // minmax8::Minimum is automated
		;                                   // minmax8::Maximum is automated
		minmax8.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                   // minmax8::Step is automated
		minmax8.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                   // minmax9::Value is automated
		;                                   // minmax9::Minimum is automated
		;                                   // minmax9::Maximum is automated
		minmax9.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                   // minmax9::Step is automated
		minmax9.setParameterT(5, 0.);       // control::minmax::Polarity
		
		pma_unscaled9.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled9.setParameterT(1, 0.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled9::Add is automated
		
		pma_unscaled10.setParameterT(0, 1.); // control::pma_unscaled::Value
		;                                    // pma_unscaled10::Multiply is automated
		;                                    // pma_unscaled10::Add is automated
		
		; // converter4::Value is automated
		
		; // branch5::Index is automated
		
		oscillator58.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator58.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator58::FreqRatio is automated
		oscillator58.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator58.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator58.setParameterT(5, 0.193006); // core::oscillator::Gain
		
		file_player4.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player4.setParameterT(1, 1.);   // core::file_player::Gate
		file_player4.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player4::FreqRatio is automated
		
		;                                   // minmax6::Value is automated
		;                                   // minmax6::Minimum is automated
		;                                   // minmax6::Maximum is automated
		minmax6.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                   // minmax6::Step is automated
		minmax6.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                   // minmax7::Value is automated
		;                                   // minmax7::Minimum is automated
		;                                   // minmax7::Maximum is automated
		minmax7.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                   // minmax7::Step is automated
		minmax7.setParameterT(5, 0.);       // control::minmax::Polarity
		
		pma_unscaled7.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled7.setParameterT(1, 0.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled7::Add is automated
		
		pma_unscaled8.setParameterT(0, 1.); // control::pma_unscaled::Value
		;                                   // pma_unscaled8::Multiply is automated
		;                                   // pma_unscaled8::Add is automated
		
		; // converter3::Value is automated
		
		; // branch4::Index is automated
		
		oscillator57.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator57.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator57::FreqRatio is automated
		oscillator57.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator57.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator57.setParameterT(5, 0.193006); // core::oscillator::Gain
		
		file_player3.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player3.setParameterT(1, 1.);   // core::file_player::Gate
		file_player3.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player3::FreqRatio is automated
		
		;                                   // minmax4::Value is automated
		;                                   // minmax4::Minimum is automated
		;                                   // minmax4::Maximum is automated
		minmax4.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                   // minmax4::Step is automated
		minmax4.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                   // minmax5::Value is automated
		;                                   // minmax5::Minimum is automated
		;                                   // minmax5::Maximum is automated
		minmax5.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                   // minmax5::Step is automated
		minmax5.setParameterT(5, 0.);       // control::minmax::Polarity
		
		pma_unscaled5.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled5.setParameterT(1, 0.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled5::Add is automated
		
		pma_unscaled6.setParameterT(0, 1.); // control::pma_unscaled::Value
		;                                   // pma_unscaled6::Multiply is automated
		;                                   // pma_unscaled6::Add is automated
		
		; // converter2::Value is automated
		
		; // branch2::Index is automated
		
		oscillator56.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator56.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator56::FreqRatio is automated
		oscillator56.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator56.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator56.setParameterT(5, 0.193006); // core::oscillator::Gain
		
		file_player2.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player2.setParameterT(1, 1.);   // core::file_player::Gate
		file_player2.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player2::FreqRatio is automated
		
		;                                   // minmax2::Value is automated
		;                                   // minmax2::Minimum is automated
		;                                   // minmax2::Maximum is automated
		minmax2.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                   // minmax2::Step is automated
		minmax2.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                   // minmax3::Value is automated
		;                                   // minmax3::Minimum is automated
		;                                   // minmax3::Maximum is automated
		minmax3.setParameterT(3, 0.986616); // control::minmax::Skew
		;                                   // minmax3::Step is automated
		minmax3.setParameterT(5, 0.);       // control::minmax::Polarity
		
		pma_unscaled3.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled3.setParameterT(1, 0.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled3::Add is automated
		
		pma_unscaled4.setParameterT(0, 1.); // control::pma_unscaled::Value
		;                                   // pma_unscaled4::Multiply is automated
		;                                   // pma_unscaled4::Add is automated
		
		; // converter1::Value is automated
		
		; // branch1::Index is automated
		
		oscillator55.setParameterT(0, 0.);       // core::oscillator::Mode
		oscillator55.setParameterT(1, 220.);     // core::oscillator::Frequency
		;                                        // oscillator55::FreqRatio is automated
		oscillator55.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator55.setParameterT(4, 0.);       // core::oscillator::Phase
		oscillator55.setParameterT(5, 0.193006); // core::oscillator::Gain
		
		file_player1.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player1.setParameterT(1, 1.);   // core::file_player::Gate
		file_player1.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player1::FreqRatio is automated
		
		gain.setParameterT(0, -16.); // core::gain::Gain
		gain.setParameterT(1, 20.);  // core::gain::Smoothing
		gain.setParameterT(2, 0.);   // core::gain::ResetValue
		
		this->setParameterT(0, -0.025736);
		this->setParameterT(1, 0.272242);
		this->setParameterT(2, -0.0420852);
		this->setParameterT(3, 12.127);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 30.);
		this->setParameterT(7, 5.);
		this->setParameterT(8, 0.);
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
		
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // SineStack_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // SineStack_impl::global_cable17_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // SineStack_impl::global_cable18_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // SineStack_impl::global_cable19_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // SineStack_impl::global_cable20_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // SineStack_impl::global_cable21_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // SineStack_impl::global_cable22_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // SineStack_impl::global_cable23_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);         // SineStack_impl::global_cable_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);         // SineStack_impl::global_cable1_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);         // SineStack_impl::global_cable2_t<NV>
		this->getT(0).getT(1).getT(1).getT(3).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);         // SineStack_impl::global_cable3_t<NV>
		this->getT(0).getT(1).getT(1).getT(4).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);         // SineStack_impl::global_cable4_t<NV>
		this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);         // SineStack_impl::global_cable5_t<NV>
		this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);         // SineStack_impl::global_cable6_t<NV>
		this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);         // SineStack_impl::global_cable7_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index);                 // SineStack_impl::cable_table11_t<NV>
		this->getT(0).getT(0).getT(1).setExternalData(b, index);                 // SineStack_impl::cable_table12_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(1).setExternalData(b, index); // SineStack_impl::peak2_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index);                 // SineStack_impl::peak_t<NV>
		this->getT(1).setExternalData(b, index);                                 // SineStack_impl::pack_resizer1_t
		this->getT(2).setExternalData(b, index);                                 // SineStack_impl::sliderbank1_t<NV>
		this->getT(3).getT(0).getT(3).getT(0).getT(0).setExternalData(b, index); // SineStack_impl::oscillator54_t<NV>
		this->getT(3).getT(0).getT(3).getT(1).getT(0).setExternalData(b, index); // SineStack_impl::file_player_t<NV>
		this->getT(3).getT(1).getT(3).getT(0).getT(0).setExternalData(b, index); // SineStack_impl::oscillator61_t<NV>
		this->getT(3).getT(1).getT(3).getT(1).getT(0).setExternalData(b, index); // SineStack_impl::file_player7_t<NV>
		this->getT(3).getT(2).getT(3).getT(0).getT(0).setExternalData(b, index); // SineStack_impl::oscillator60_t<NV>
		this->getT(3).getT(2).getT(3).getT(1).getT(0).setExternalData(b, index); // SineStack_impl::file_player6_t<NV>
		this->getT(3).getT(3).getT(3).getT(0).getT(0).setExternalData(b, index); // SineStack_impl::oscillator59_t<NV>
		this->getT(3).getT(3).getT(3).getT(1).getT(0).setExternalData(b, index); // SineStack_impl::file_player5_t<NV>
		this->getT(3).getT(4).getT(3).getT(0).getT(0).setExternalData(b, index); // SineStack_impl::oscillator58_t<NV>
		this->getT(3).getT(4).getT(3).getT(1).getT(0).setExternalData(b, index); // SineStack_impl::file_player4_t<NV>
		this->getT(3).getT(5).getT(3).getT(0).getT(0).setExternalData(b, index); // SineStack_impl::oscillator57_t<NV>
		this->getT(3).getT(5).getT(3).getT(1).getT(0).setExternalData(b, index); // SineStack_impl::file_player3_t<NV>
		this->getT(3).getT(6).getT(3).getT(0).getT(0).setExternalData(b, index); // SineStack_impl::oscillator56_t<NV>
		this->getT(3).getT(6).getT(3).getT(1).getT(0).setExternalData(b, index); // SineStack_impl::file_player2_t<NV>
		this->getT(3).getT(7).getT(3).getT(0).getT(0).setExternalData(b, index); // SineStack_impl::oscillator55_t<NV>
		this->getT(3).getT(7).getT(3).getT(1).getT(0).setExternalData(b, index); // SineStack_impl::file_player1_t<NV>
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
using SineStack = wrap::node<SineStack_impl::instance<NV>>;
}


