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

namespace PitchSliders_impl
{
// ==============================| Node & Parameter type declarations |==============================

using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<0>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<545021411>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<545021412>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<545021413>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<545021414>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<545021415>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<545021416>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<545021417>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<545021418>;
using sliderbank_multimod = parameter::list<parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable1_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable2_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable3_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable4_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable5_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable6_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable7_t_index, parameter::empty>, 0>>;

using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod>, 
                                data::external::sliderpack<0>>;
template <int NV>
using pma7_t = control::pma<NV, 
                            parameter::plain<sliderbank_t, 0>>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<pma7_t<NV>, 0>>;

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
using pma6_t = control::pma<NV, 
                            parameter::plain<pma4_t<NV>, 2>>;
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
using input_toggle1x_t = control::input_toggle<parameter::plain<pma6_t<NV>, 2>>;

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
                                   wrap::fix<1, chain10_t<NV>>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain5_t<NV>>, 
                                  chain6_t<NV>, 
                                  chain14_t<NV>, 
                                  chain25_t<NV>>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma_t<NV>>, 
                                   split7_t<NV>>;

using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, routing::global_cable<global_cable_t_index, parameter::empty>>, 
                                 routing::global_cable<global_cable1_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable2_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable3_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable4_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable5_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable6_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable7_t_index, parameter::empty>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split19_t<NV>>, 
                                     pma7_t<NV>, 
                                     sliderbank_t, 
                                     split_t>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, pack_resizer_t>, 
                                      modchain_t<NV>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

namespace PitchSliders_t_parameters
{
// Parameter list for PitchSliders_impl::PitchSliders_t --------------------------------------------

DECLARE_PARAMETER_RANGE(OffsetRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Offset = parameter::from0To1<PitchSliders_impl::pma7_t<NV>, 
                                   2, 
                                   OffsetRange>;

DECLARE_PARAMETER_RANGE_STEP(ModSrc_InputRange, 
                             0., 
                             16., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(ModSrc_2Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using ModSrc_2 = parameter::from0To1<PitchSliders_impl::event_data_reader7_t<NV>, 
                                     0, 
                                     ModSrc_2Range>;

template <int NV>
using ModSrc = parameter::chain<ModSrc_InputRange, 
                                parameter::plain<PitchSliders_impl::cable_table11_t<NV>, 0>, 
                                parameter::plain<PitchSliders_impl::cable_table12_t<NV>, 0>, 
                                ModSrc_2<NV>>;

template <int NV>
using Mod = parameter::plain<PitchSliders_impl::pma7_t<NV>, 
                             1>;
template <int NV>
using Vel = parameter::plain<PitchSliders_impl::pma3_t<NV>, 
                             1>;
template <int NV>
using At = parameter::plain<PitchSliders_impl::pma6_t<NV>, 
                            1>;
template <int NV>
using Trk = parameter::plain<PitchSliders_impl::pma4_t<NV>, 
                             1>;
using Pack = parameter::plain<PitchSliders_impl::pack_resizer_t, 
                              0>;
template <int NV>
using PitchSliders_t_plist = parameter::list<Offset<NV>, 
                                             Mod<NV>, 
                                             ModSrc<NV>, 
                                             Vel<NV>, 
                                             At<NV>, 
                                             Trk<NV>, 
                                             Pack>;
}

template <int NV>
using PitchSliders_t_ = container::chain<PitchSliders_t_parameters::PitchSliders_t_plist<NV>, 
                                         wrap::fix<2, midichain_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public PitchSliders_impl::PitchSliders_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(PitchSliders);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(106)
		{
			0x005B, 0x0000, 0x4F00, 0x6666, 0x6573, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x4D00, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x103F, 0x8DB8, 0x00BC, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 
            0x0000, 0x6F4D, 0x5364, 0x6372, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x0041, 0x0000, 0x0000, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0003, 
            0x0000, 0x6556, 0x006C, 0x0000, 0x0000, 0x0000, 0x3F80, 0x9375, 
            0x3F25, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x4100, 
            0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x5400, 0x6B72, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0006, 0x0000, 0x6150, 0x6B63, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x0043, 0x2000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& midichain = this->getT(0);                                                      // PitchSliders_impl::midichain_t<NV>
		auto& pack_resizer = this->getT(0).getT(0);                                           // PitchSliders_impl::pack_resizer_t
		auto& modchain = this->getT(0).getT(1);                                               // PitchSliders_impl::modchain_t<NV>
		auto& split19 = this->getT(0).getT(1).getT(0);                                        // PitchSliders_impl::split19_t<NV>
		auto& pma = this->getT(0).getT(1).getT(0).getT(0);                                    // PitchSliders_impl::pma_t<NV>
		auto& split7 = this->getT(0).getT(1).getT(0).getT(1);                                 // PitchSliders_impl::split7_t<NV>
		auto& chain5 = this->getT(0).getT(1).getT(0).getT(1).getT(0);                         // PitchSliders_impl::chain5_t<NV>
		auto& midi = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);                   // PitchSliders_impl::midi_t<NV>
		auto& pma3 = this->getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);                   // PitchSliders_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(1).getT(0).getT(1).getT(1);                         // PitchSliders_impl::chain6_t<NV>
		auto& midi1 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0);                  // PitchSliders_impl::midi1_t<NV>
		auto& pma4 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(1);                   // PitchSliders_impl::pma4_t<NV>
		auto& chain14 = this->getT(0).getT(1).getT(0).getT(1).getT(2);                        // PitchSliders_impl::chain14_t<NV>
		auto& midi_cc1 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(0);               // PitchSliders_impl::midi_cc1_t<NV>
		auto& pma6 = this->getT(0).getT(1).getT(0).getT(1).getT(2).getT(1);                   // PitchSliders_impl::pma6_t<NV>
		auto& chain25 = this->getT(0).getT(1).getT(0).getT(1).getT(3);                        // PitchSliders_impl::chain25_t<NV>
		auto& chain10 = this->getT(0).getT(1).getT(0).getT(1).getT(3).getT(0);                // PitchSliders_impl::chain10_t<NV>
		auto& cable_table11 = this->getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).getT(0);  // PitchSliders_impl::cable_table11_t<NV>
		auto& cable_table12 = this->getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).getT(1);  // PitchSliders_impl::cable_table12_t<NV>
		auto& split21 = this->getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).getT(2);        // PitchSliders_impl::split21_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(1).getT(0).getT(1).                     // PitchSliders_impl::event_data_reader7_t<NV>
                                   getT(3).getT(0).getT(2).getT(0);
		auto& chain29 = this->getT(0).getT(1).getT(0).getT(1).                                // PitchSliders_impl::chain29_t<NV>
                        getT(3).getT(0).getT(2).getT(1);
		auto& branch3 = this->getT(0).getT(1).getT(0).getT(1).                                // PitchSliders_impl::branch3_t<NV>
                        getT(3).getT(0).getT(2).getT(1).
                        getT(0);
		auto& chain30 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                        // PitchSliders_impl::chain30_t<NV>
                        getT(0).getT(2).getT(1).getT(0).getT(0);
		auto& global_cable16 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                 // PitchSliders_impl::global_cable16_t<NV>
                               getT(0).getT(2).getT(1).getT(0).getT(0).
                               getT(0);
		auto& add16 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                          // math::add<NV>
                      getT(0).getT(2).getT(1).getT(0).getT(0).
                      getT(1);
		auto& chain31 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                        // PitchSliders_impl::chain31_t<NV>
                        getT(0).getT(2).getT(1).getT(0).getT(1);
		auto& global_cable17 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                 // PitchSliders_impl::global_cable17_t<NV>
                               getT(0).getT(2).getT(1).getT(0).getT(1).
                               getT(0);
		auto& add17 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                          // math::add<NV>
                      getT(0).getT(2).getT(1).getT(0).getT(1).
                      getT(1);
		auto& chain32 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                        // PitchSliders_impl::chain32_t<NV>
                        getT(0).getT(2).getT(1).getT(0).getT(2);
		auto& global_cable18 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                 // PitchSliders_impl::global_cable18_t<NV>
                               getT(0).getT(2).getT(1).getT(0).getT(2).
                               getT(0);
		auto& add18 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                          // math::add<NV>
                      getT(0).getT(2).getT(1).getT(0).getT(2).
                      getT(1);
		auto& chain33 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                        // PitchSliders_impl::chain33_t<NV>
                        getT(0).getT(2).getT(1).getT(0).getT(3);
		auto& global_cable19 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                 // PitchSliders_impl::global_cable19_t<NV>
                               getT(0).getT(2).getT(1).getT(0).getT(3).
                               getT(0);
		auto& add19 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                          // math::add<NV>
                      getT(0).getT(2).getT(1).getT(0).getT(3).
                      getT(1);
		auto& chain34 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                        // PitchSliders_impl::chain34_t<NV>
                        getT(0).getT(2).getT(1).getT(0).getT(4);
		auto& global_cable20 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                 // PitchSliders_impl::global_cable20_t<NV>
                               getT(0).getT(2).getT(1).getT(0).getT(4).
                               getT(0);
		auto& add20 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                          // math::add<NV>
                      getT(0).getT(2).getT(1).getT(0).getT(4).
                      getT(1);
		auto& chain35 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                        // PitchSliders_impl::chain35_t<NV>
                        getT(0).getT(2).getT(1).getT(0).getT(5);
		auto& global_cable21 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                 // PitchSliders_impl::global_cable21_t<NV>
                               getT(0).getT(2).getT(1).getT(0).getT(5).
                               getT(0);
		auto& add21 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                          // math::add<NV>
                      getT(0).getT(2).getT(1).getT(0).getT(5).
                      getT(1);
		auto& chain36 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                        // PitchSliders_impl::chain36_t<NV>
                        getT(0).getT(2).getT(1).getT(0).getT(6);
		auto& global_cable22 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                 // PitchSliders_impl::global_cable22_t<NV>
                               getT(0).getT(2).getT(1).getT(0).getT(6).
                               getT(0);
		auto& add22 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                          // math::add<NV>
                      getT(0).getT(2).getT(1).getT(0).getT(6).
                      getT(1);
		auto& chain37 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                        // PitchSliders_impl::chain37_t<NV>
                        getT(0).getT(2).getT(1).getT(0).getT(7);
		auto& global_cable23 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                 // PitchSliders_impl::global_cable23_t<NV>
                               getT(0).getT(2).getT(1).getT(0).getT(7).
                               getT(0);
		auto& add23 = this->getT(0).getT(1).getT(0).getT(1).getT(3).                          // math::add<NV>
                      getT(0).getT(2).getT(1).getT(0).getT(7).
                      getT(1);
		auto& peak2 = this->getT(0).getT(1).getT(0).getT(1).                                  // PitchSliders_impl::peak2_t<NV>
                      getT(3).getT(0).getT(2).getT(1).
                      getT(1);
		auto& clear = this->getT(0).getT(1).getT(0).getT(1).                                  // math::clear<NV>
                      getT(3).getT(0).getT(2).getT(1).
                      getT(2);
		auto& input_toggle1x = this->getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).getT(3); // PitchSliders_impl::input_toggle1x_t<NV>
		auto& pma7 = this->getT(0).getT(1).getT(1);                                           // PitchSliders_impl::pma7_t<NV>
		auto& sliderbank = this->getT(0).getT(1).getT(2);                                     // PitchSliders_impl::sliderbank_t
		auto& split = this->getT(0).getT(1).getT(3);                                          // PitchSliders_impl::split_t
		auto& global_cable = this->getT(0).getT(1).getT(3).getT(0);                           // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& global_cable1 = this->getT(0).getT(1).getT(3).getT(1);                          // routing::global_cable<global_cable1_t_index, parameter::empty>
		auto& global_cable2 = this->getT(0).getT(1).getT(3).getT(2);                          // routing::global_cable<global_cable2_t_index, parameter::empty>
		auto& global_cable3 = this->getT(0).getT(1).getT(3).getT(3);                          // routing::global_cable<global_cable3_t_index, parameter::empty>
		auto& global_cable4 = this->getT(0).getT(1).getT(3).getT(4);                          // routing::global_cable<global_cable4_t_index, parameter::empty>
		auto& global_cable5 = this->getT(0).getT(1).getT(3).getT(5);                          // routing::global_cable<global_cable5_t_index, parameter::empty>
		auto& global_cable6 = this->getT(0).getT(1).getT(3).getT(6);                          // routing::global_cable<global_cable6_t_index, parameter::empty>
		auto& global_cable7 = this->getT(0).getT(1).getT(3).getT(7);                          // routing::global_cable<global_cable7_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma7); // Offset -> pma7::Add
		
		this->getParameterT(1).connectT(0, pma7); // Mod -> pma7::Multiply
		
		auto& ModSrc_p = this->getParameterT(2);
		ModSrc_p.connectT(0, cable_table11);      // ModSrc -> cable_table11::Value
		ModSrc_p.connectT(1, cable_table12);      // ModSrc -> cable_table12::Value
		ModSrc_p.connectT(2, event_data_reader7); // ModSrc -> event_data_reader7::SlotIndex
		
		this->getParameterT(3).connectT(0, pma3); // Vel -> pma3::Multiply
		
		this->getParameterT(4).connectT(0, pma6); // At -> pma6::Multiply
		
		this->getParameterT(5).connectT(0, pma4); // Trk -> pma4::Multiply
		
		this->getParameterT(6).connectT(0, pack_resizer); // Pack -> pack_resizer::NumSliders
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, global_cable);                     // sliderbank -> global_cable::Value
		sliderbank_p.getParameterT(1).connectT(0, global_cable1);                    // sliderbank -> global_cable1::Value
		sliderbank_p.getParameterT(2).connectT(0, global_cable2);                    // sliderbank -> global_cable2::Value
		sliderbank_p.getParameterT(3).connectT(0, global_cable3);                    // sliderbank -> global_cable3::Value
		sliderbank_p.getParameterT(4).connectT(0, global_cable4);                    // sliderbank -> global_cable4::Value
		sliderbank_p.getParameterT(5).connectT(0, global_cable5);                    // sliderbank -> global_cable5::Value
		sliderbank_p.getParameterT(6).connectT(0, global_cable6);                    // sliderbank -> global_cable6::Value
		sliderbank_p.getParameterT(7).connectT(0, global_cable7);                    // sliderbank -> global_cable7::Value
		pma7.getWrappedObject().getParameter().connectT(0, sliderbank);              // pma7 -> sliderbank::Value
		pma.getWrappedObject().getParameter().connectT(0, pma7);                     // pma -> pma7::Value
		pma3.getWrappedObject().getParameter().connectT(0, pma);                     // pma3 -> pma::Add
		midi.getParameter().connectT(0, pma3);                                       // midi -> pma3::Value
		pma4.getWrappedObject().getParameter().connectT(0, pma3);                    // pma4 -> pma3::Add
		midi1.getParameter().connectT(0, pma4);                                      // midi1 -> pma4::Value
		pma6.getWrappedObject().getParameter().connectT(0, pma4);                    // pma6 -> pma4::Add
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
		input_toggle1x.getWrappedObject().getParameter().connectT(0, pma6);          // input_toggle1x -> pma6::Add
		cable_table12.getWrappedObject().getParameter().connectT(0, input_toggle1x); // cable_table12 -> input_toggle1x::Input
		event_data_reader7.getParameter().connectT(0, input_toggle1x);               // event_data_reader7 -> input_toggle1x::Value1
		peak2.getParameter().connectT(0, input_toggle1x);                            // peak2 -> input_toggle1x::Value2
		
		// Default Values --------------------------------------------------------------------------
		
		; // pack_resizer::NumSliders is automated
		
		pma.setParameterT(0, 0.); // control::pma::Value
		pma.setParameterT(1, 0.); // control::pma::Multiply
		;                         // pma::Add is automated
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
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
		
		; // sliderbank::Value is automated
		
		; // global_cable::Value is automated
		
		; // global_cable1::Value is automated
		
		; // global_cable2::Value is automated
		
		; // global_cable3::Value is automated
		
		; // global_cable4::Value is automated
		
		; // global_cable5::Value is automated
		
		; // global_cable6::Value is automated
		
		; // global_cable7::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, -0.0172997);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.646781);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 10.);
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
		
		this->getT(0).getT(1).getT(0).getT(1).getT(3).                                  // PitchSliders_impl::global_cable16_t<NV>
        getT(0).getT(2).getT(1).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(1).getT(3).                                  // PitchSliders_impl::global_cable17_t<NV>
        getT(0).getT(2).getT(1).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(1).getT(3).                                  // PitchSliders_impl::global_cable18_t<NV>
        getT(0).getT(2).getT(1).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(1).getT(3).                                  // PitchSliders_impl::global_cable19_t<NV>
        getT(0).getT(2).getT(1).getT(0).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(1).getT(3).                                  // PitchSliders_impl::global_cable20_t<NV>
        getT(0).getT(2).getT(1).getT(0).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(1).getT(3).                                  // PitchSliders_impl::global_cable21_t<NV>
        getT(0).getT(2).getT(1).getT(0).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(1).getT(3).                                  // PitchSliders_impl::global_cable22_t<NV>
        getT(0).getT(2).getT(1).getT(0).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(1).getT(3).                                  // PitchSliders_impl::global_cable23_t<NV>
        getT(0).getT(2).getT(1).getT(0).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(0).getT(1).getT(3).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable1_t_index, parameter::empty>
		this->getT(0).getT(1).getT(3).getT(2).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable2_t_index, parameter::empty>
		this->getT(0).getT(1).getT(3).getT(3).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable3_t_index, parameter::empty>
		this->getT(0).getT(1).getT(3).getT(4).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable4_t_index, parameter::empty>
		this->getT(0).getT(1).getT(3).getT(5).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable5_t_index, parameter::empty>
		this->getT(0).getT(1).getT(3).getT(6).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable6_t_index, parameter::empty>
		this->getT(0).getT(1).getT(3).getT(7).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable7_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).setExternalData(b, index);                                         // PitchSliders_impl::pack_resizer_t
		this->getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).getT(0).setExternalData(b, index); // PitchSliders_impl::cable_table11_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).getT(1).setExternalData(b, index); // PitchSliders_impl::cable_table12_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).                                                   // PitchSliders_impl::peak2_t<NV>
        getT(3).getT(0).getT(2).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).setExternalData(b, index); // PitchSliders_impl::sliderbank_t
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
using PitchSliders = wrap::node<PitchSliders_impl::instance<NV>>;
}


