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

namespace FilterNew6_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(pma8_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma8_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                       0, 
                                       pma8_mod_0Range>;

template <int NV> using pma8_mod_1 = pma8_mod_0<NV>;

template <int NV> using pma8_mod_2 = pma8_mod_0<NV>;

template <int NV>
using pma8_mod_3 = parameter::from0To1<filters::allpass<NV>, 
                                       0, 
                                       pma8_mod_0Range>;

template <int NV>
using pma8_mod_4 = parameter::from0To1<filters::ring_mod<NV>, 
                                       0, 
                                       pma8_mod_0Range>;

template <int NV> using pma8_mod_5 = pma8_mod_0<NV>;

template <int NV> using pma8_mod_6 = pma8_mod_0<NV>;

template <int NV> using pma8_mod_7 = pma8_mod_0<NV>;

template <int NV> using pma8_mod_8 = pma8_mod_3<NV>;

template <int NV> using pma8_mod_9 = pma8_mod_4<NV>;

template <int NV>
using pma8_mod = parameter::chain<ranges::Identity, 
                                  pma8_mod_0<NV>, 
                                  pma8_mod_1<NV>, 
                                  pma8_mod_2<NV>, 
                                  pma8_mod_3<NV>, 
                                  pma8_mod_4<NV>, 
                                  pma8_mod_5<NV>, 
                                  pma8_mod_6<NV>, 
                                  pma8_mod_7<NV>, 
                                  pma8_mod_8<NV>, 
                                  pma8_mod_9<NV>>;

template <int NV>
using pma8_t = control::pma<NV, pma8_mod<NV>>;
DECLARE_PARAMETER_RANGE(sliderbank_c5Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using sliderbank_c5 = parameter::from0To1<pma8_t<NV>, 
                                          2, 
                                          sliderbank_c5Range>;

template <int NV>
using sliderbank_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            sliderbank_c5<NV>, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<0>>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<sliderbank_t<NV>, 0>>;

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

using global_cable8_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   math::add<NV>>;
using global_cable9_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable9_t<NV>>, 
                                   math::add<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;
using global_cable14_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>>;
using global_cable15_t_index = runtime_target::indexers::fix_hash<104068263>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain20_t<NV>>, 
                                    chain21_t<NV>, 
                                    chain22_t<NV>, 
                                    chain23_t<NV>, 
                                    chain24_t<NV>, 
                                    chain26_t<NV>, 
                                    chain27_t<NV>, 
                                    chain28_t<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table11_modRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using cable_table11_mod = parameter::from0To1<branch2_t<NV>, 
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
		0.f, 0.f, 0.00247014f, 0.00692326f, 0.0113764f, 0.0158296f,
		0.0202827f, 0.0247358f, 0.0291889f, 0.0336421f, 0.0380953f, 0.0425484f,
		0.0470015f, 0.0514547f, 0.0559078f, 0.0603609f, 0.064814f, 0.0692672f,
		0.0737205f, 0.0781736f, 0.0826267f, 0.0870798f, 0.0915329f, 0.0959861f,
		0.100439f, 0.104892f, 0.109346f, 0.113799f, 0.118252f, 0.122705f,
		0.127158f, 0.131611f, 0.136064f, 0.140517f, 0.144971f, 0.149424f,
		0.153877f, 0.15833f, 0.162783f, 0.167236f, 0.171689f, 0.176143f,
		0.180596f, 0.185049f, 0.189502f, 0.193955f, 0.198408f, 0.202861f,
		0.207315f, 0.211768f, 0.216221f, 0.220674f, 0.225127f, 0.22958f,
		0.234033f, 0.238487f, 0.24294f, 0.247393f, 0.251846f, 0.256299f,
		0.260752f, 0.265206f, 0.269659f, 0.274112f, 0.278565f, 0.283018f,
		0.287471f, 0.291924f, 0.296378f, 0.300831f, 0.305284f, 0.309737f,
		0.31419f, 0.318643f, 0.323096f, 0.32755f, 0.332003f, 0.336456f,
		0.340909f, 0.345362f, 0.349815f, 0.354268f, 0.358721f, 0.363175f,
		0.367628f, 0.372081f, 0.376534f, 0.380987f, 0.38544f, 0.389893f,
		0.394347f, 0.3988f, 0.403253f, 0.407706f, 0.412159f, 0.416612f,
		0.421065f, 0.425519f, 0.429972f, 0.434425f, 0.438878f, 0.443331f,
		0.447784f, 0.452237f, 0.456691f, 0.461144f, 0.465597f, 0.47005f,
		0.474503f, 0.478956f, 0.483409f, 0.487863f, 0.492316f, 0.496769f,
		0.501222f, 0.505675f, 0.510128f, 0.514581f, 0.519035f, 0.523488f,
		0.527941f, 0.532394f, 0.536847f, 0.5413f, 0.545753f, 0.550207f,
		0.55466f, 0.559113f, 0.563566f, 0.568019f, 0.572472f, 0.576926f,
		0.581379f, 0.585832f, 0.590285f, 0.594738f, 0.599191f, 0.603644f,
		0.608097f, 0.612551f, 0.617004f, 0.621457f, 0.62591f, 0.630363f,
		0.634816f, 0.639269f, 0.643723f, 0.648176f, 0.652629f, 0.657082f,
		0.661535f, 0.665988f, 0.670441f, 0.674895f, 0.679348f, 0.683801f,
		0.688254f, 0.692707f, 0.69716f, 0.701613f, 0.706066f, 0.71052f,
		0.714973f, 0.719426f, 0.723879f, 0.728332f, 0.732785f, 0.737239f,
		0.741692f, 0.746145f, 0.750598f, 0.755051f, 0.759504f, 0.763957f,
		0.768411f, 0.772864f, 0.777317f, 0.78177f, 0.786223f, 0.790676f,
		0.795129f, 0.799583f, 0.804036f, 0.808489f, 0.812942f, 0.817395f,
		0.821848f, 0.826301f, 0.830755f, 0.835208f, 0.839661f, 0.844114f,
		0.848567f, 0.85302f, 0.857473f, 0.861927f, 0.86638f, 0.870833f,
		0.875286f, 0.879739f, 0.884192f, 0.888645f, 0.893099f, 0.897552f,
		0.902005f, 0.906458f, 0.910911f, 0.915364f, 0.919817f, 0.92427f,
		0.928724f, 0.933177f, 0.93763f, 0.942083f, 0.946536f, 0.950989f,
		0.955443f, 0.959896f, 0.964349f, 0.968802f, 0.973255f, 0.977708f,
		0.982161f, 0.986615f, 0.991068f, 0.995521f, 0.999974f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table11_t = wrap::data<control::cable_table<cable_table11_mod<NV>>, 
                                   data::embedded::table<cable_table11_t_data>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader1_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader1_c0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       xfader1_c0Range>;

template <int NV> using xfader1_c1 = xfader1_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;
template <int NV>
using pma10_t = control::pma<NV, 
                             parameter::plain<xfader1_t<NV>, 0>>;

template <int NV> using xfader4_c0 = xfader1_c0<NV>;

template <int NV> using xfader4_c1 = xfader1_c0<NV>;

template <int NV>
using xfader4_multimod = parameter::list<xfader4_c0<NV>, xfader4_c1<NV>>;

template <int NV>
using xfader4_t = control::xfader<xfader4_multimod<NV>, faders::linear>;
template <int NV>
using pma13_t = control::pma<NV, 
                             parameter::plain<xfader4_t<NV>, 0>>;

template <int NV>
using input_toggle1_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<pma10_t<NV>, 0>, 
                                           parameter::plain<pma13_t<NV>, 0>>;

template <int NV>
using input_toggle1_t = control::input_toggle<input_toggle1_mod<NV>>;

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
using cable_table12_t = wrap::data<control::cable_table<parameter::plain<input_toggle1_t<NV>, 0>>, 
                                   data::embedded::table<cable_table12_t_data>>;

template <int NV>
using event_data_reader7_t = wrap::mod<parameter::plain<input_toggle1_t<NV>, 1>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using peak1_t = wrap::mod<parameter::plain<input_toggle1_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch2_t<NV>>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader7_t<NV>>, 
                                  chain19_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table11_t<NV>>, 
                                   cable_table12_t<NV>, 
                                   split6_t<NV>, 
                                   input_toggle1_t<NV>>;

using global_cable24_t_index = global_cable8_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>>;
using global_cable25_t_index = global_cable9_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>>;
using global_cable26_t_index = global_cable10_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>>;
using global_cable27_t_index = global_cable11_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>>;
using global_cable28_t_index = global_cable12_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   math::add<NV>>;
using global_cable29_t_index = global_cable13_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   math::add<NV>>;
using global_cable30_t_index = global_cable14_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable30_t<NV>>, 
                                   math::add<NV>>;
using global_cable31_t_index = global_cable15_t_index;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable31_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain39_t<NV>>, 
                                    chain40_t<NV>, 
                                    chain41_t<NV>, 
                                    chain42_t<NV>, 
                                    chain43_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>, 
                                    chain46_t<NV>>;
template <int NV>
using cable_table5_mod = parameter::from0To1<branch4_t<NV>, 
                                             0, 
                                             cable_table11_modRange>;

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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
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
using cable_table5_t = wrap::data<control::cable_table<cable_table5_mod<NV>>, 
                                  data::embedded::table<cable_table5_t_data>>;

template <int NV>
using pma7_t = control::pma<NV, 
                            parameter::plain<pma6_t<NV>, 2>>;
template <int NV>
using input_toggle3_t = control::input_toggle<parameter::plain<pma7_t<NV>, 0>>;

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
using cable_table6_t = wrap::data<control::cable_table<parameter::plain<input_toggle3_t<NV>, 0>>, 
                                  data::embedded::table<cable_table6_t_data>>;

template <int NV>
using event_data_reader4_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 1>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using peak3_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch4_t<NV>>, 
                                   peak3_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader4_t<NV>>, 
                                  chain38_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table5_t<NV>>, 
                                  cable_table6_t<NV>, 
                                  split3_t<NV>, 
                                  input_toggle3_t<NV>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain3_t<NV>>, 
                                   pma7_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain5_t<NV>>, 
                                  chain6_t<NV>, 
                                  chain9_t<NV>, 
                                  chain14_t<NV>, 
                                  chain10_t<NV>, 
                                  chain25_t<NV>>;
using pack_resizer1_t = wrap::data<control::pack_resizer, 
                                   data::external::sliderpack<0>>;

using global_cable16_t_index = global_cable8_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = global_cable9_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
using global_cable18_t_index = global_cable10_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>>;
using global_cable19_t_index = global_cable11_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;
using global_cable20_t_index = global_cable12_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable13_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = global_cable14_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = global_cable15_t_index;

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
using cable_table7_mod = parameter::from0To1<branch3_t<NV>, 
                                             0, 
                                             cable_table11_modRange>;

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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
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
using cable_table7_t = wrap::data<control::cable_table<cable_table7_mod<NV>>, 
                                  data::embedded::table<cable_table7_t_data>>;

template <int NV>
using input_toggle4_t = control::input_toggle<parameter::plain<pma8_t<NV>, 0>>;

struct cable_table8_t_data
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
using cable_table8_t = wrap::data<control::cable_table<parameter::plain<input_toggle4_t<NV>, 0>>, 
                                  data::embedded::table<cable_table8_t_data>>;

template <int NV>
using event_data_reader5_t = wrap::mod<parameter::plain<input_toggle4_t<NV>, 1>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using peak2_t = wrap::mod<parameter::plain<input_toggle4_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak2_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader5_t<NV>>, 
                                  chain29_t<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, pack_resizer1_t>, 
                                  sliderbank_t<NV>, 
                                  cable_table7_t<NV>, 
                                  cable_table8_t<NV>, 
                                  split4_t<NV>, 
                                  input_toggle4_t<NV>, 
                                  pma8_t<NV>>;

template <int NV> using xfader_c0_0 = xfader1_c0<NV>;

template <int NV> using xfader_c0_1 = xfader1_c0<NV>;

template <int NV>
using xfader_c0 = parameter::chain<ranges::Identity, 
                                   xfader_c0_0<NV>, 
                                   xfader_c0_1<NV>>;

template <int NV> using xfader_c1_0 = xfader1_c0<NV>;

template <int NV> using xfader_c1_1 = xfader1_c0<NV>;

template <int NV>
using xfader_c1 = parameter::chain<ranges::Identity, 
                                   xfader_c1_0<NV>, 
                                   xfader_c1_1<NV>>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;
template <int NV>
using pma9_t = control::pma<NV, 
                            parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<pma9_t<NV>, 0>>;
template <int NV>
using event_data_reader6_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 1>, 
                                       routing::event_data_reader<NV>>;

using global_cable_t_index = global_cable8_t_index;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, global_cable_t<NV>>, 
                                 math::add<NV>>;
using global_cable1_t_index = global_cable9_t_index;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>>;
using global_cable2_t_index = global_cable10_t_index;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable2_t<NV>>, 
                                   math::add<NV>>;
using global_cable3_t_index = global_cable11_t_index;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>>;
using global_cable4_t_index = global_cable12_t_index;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   math::add<NV>>;
using global_cable5_t_index = global_cable13_t_index;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable5_t<NV>>, 
                                   math::add<NV>>;
using global_cable6_t_index = global_cable14_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>>;
using global_cable7_t_index = global_cable15_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain_t<NV>>, 
                                    chain1_t<NV>, 
                                    chain12_t<NV>, 
                                    chain13_t<NV>, 
                                    chain15_t<NV>, 
                                    chain16_t<NV>, 
                                    chain17_t<NV>, 
                                    chain18_t<NV>>;
template <int NV>
using cable_table9_mod = parameter::from0To1<branch1_t<NV>, 
                                             0, 
                                             cable_table11_modRange>;

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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
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
using cable_table9_t = wrap::data<control::cable_table<cable_table9_mod<NV>>, 
                                  data::embedded::table<cable_table9_t_data>>;

struct cable_table10_t_data
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
using cable_table10_t = wrap::data<control::cable_table<parameter::plain<input_toggle_t<NV>, 0>>, 
                                   data::embedded::table<cable_table10_t_data>>;

template <int NV>
using peak_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 2>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table9_t<NV>>, 
                                   cable_table10_t<NV>, 
                                   branch1_t<NV>, 
                                   peak_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader6_t<NV>>, 
                                  chain11_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, split5_t<NV>>, 
                                  input_toggle_t<NV>>;

namespace custom
{

struct expr2
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 24.0 * value * input) * (2 - Math.PI);
		;
	}
};
}

template <int NV>
using smoothed_parameter1_t = wrap::mod<parameter::plain<math::expr<NV, custom::expr2>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

namespace custom
{

struct expr5
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 24.0 * value * input) * (2 - Math.PI);
		;
	}
};
}

template <int NV>
using smoothed_parameter7_t = wrap::mod<parameter::plain<math::expr<NV, custom::expr5>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<smoothed_parameter1_t<NV>, 0>, 
                                  parameter::plain<smoothed_parameter7_t<NV>, 0>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using input_toggle2_t = control::input_toggle<parameter::plain<pma1_t<NV>, 0>>;
template <int NV>
using event_data_reader8_t = wrap::mod<parameter::plain<input_toggle2_t<NV>, 1>, 
                                       routing::event_data_reader<NV>>;

using global_cable32_t_index = global_cable8_t_index;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable32_t<NV>>, 
                                   math::add<NV>>;
using global_cable33_t_index = global_cable9_t_index;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable33_t<NV>>, 
                                   math::add<NV>>;
using global_cable34_t_index = global_cable10_t_index;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable34_t<NV>>, 
                                   math::add<NV>>;
using global_cable35_t_index = global_cable11_t_index;

template <int NV>
using global_cable35_t = routing::global_cable<global_cable35_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable35_t<NV>>, 
                                   math::add<NV>>;
using global_cable36_t_index = global_cable12_t_index;

template <int NV>
using global_cable36_t = routing::global_cable<global_cable36_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable36_t<NV>>, 
                                   math::add<NV>>;
using global_cable37_t_index = global_cable13_t_index;

template <int NV>
using global_cable37_t = routing::global_cable<global_cable37_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable37_t<NV>>, 
                                   math::add<NV>>;
using global_cable38_t_index = global_cable14_t_index;

template <int NV>
using global_cable38_t = routing::global_cable<global_cable38_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable38_t<NV>>, 
                                   math::add<NV>>;
using global_cable39_t_index = global_cable15_t_index;

template <int NV>
using global_cable39_t = routing::global_cable<global_cable39_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable39_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain50_t<NV>>, 
                                    chain51_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>, 
                                    chain57_t<NV>, 
                                    chain58_t<NV>, 
                                    chain59_t<NV>, 
                                    chain60_t<NV>>;
template <int NV>
using cable_table13_mod = parameter::from0To1<branch5_t<NV>, 
                                              0, 
                                              cable_table11_modRange>;

struct cable_table13_t_data
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
using cable_table13_t = wrap::data<control::cable_table<cable_table13_mod<NV>>, 
                                   data::embedded::table<cable_table13_t_data>>;

struct cable_table14_t_data
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
using cable_table14_t = wrap::data<control::cable_table<parameter::plain<input_toggle2_t<NV>, 0>>, 
                                   data::embedded::table<cable_table14_t_data>>;

template <int NV>
using peak4_t = wrap::mod<parameter::plain<input_toggle2_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table13_t<NV>>, 
                                   cable_table14_t<NV>, 
                                   branch5_t<NV>, 
                                   peak4_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader8_t<NV>>, 
                                  chain49_t<NV>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split8_t<NV>>, 
                                   input_toggle2_t<NV>>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma_t<NV>>, 
                                   split7_t<NV>, 
                                   chain7_t<NV>, 
                                   chain8_t<NV>, 
                                   chain48_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split19_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<math::sub<NV>, 0>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sub<NV>>, 
                                   math::expr<NV, custom::expr2>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain2_t<NV>>, 
                                  chain47_t<NV>>;

template <int NV>
using dry_path_t = container::chain<parameter::empty, 
                                    wrap::fix<2, pma10_t<NV>>, 
                                    xfader1_t<NV>, 
                                    core::gain<NV>>;

template <int NV>
using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, filters::svf<NV>>>;

template <int NV>
using sb1_t = bypass::smoothed<20, sb1_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb1_t<NV>>;

template <int NV> using sb2_t_ = sb1_t_<NV>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

template <int NV> using sb3_t_ = sb1_t_<NV>;

template <int NV>
using sb3_t = bypass::smoothed<20, sb3_t_<NV>>;
template <int NV>
using switcher_c2 = parameter::bypass<sb3_t<NV>>;

template <int NV>
using soft_bypass_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, filters::allpass<NV>>>;

template <int NV>
using soft_bypass_t = bypass::smoothed<20, soft_bypass_t_<NV>>;
template <int NV>
using switcher_c3 = parameter::bypass<soft_bypass_t<NV>>;

template <int NV>
using soft_bypass1_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, filters::ring_mod<NV>>>;

template <int NV>
using soft_bypass1_t = bypass::smoothed<20, soft_bypass1_t_<NV>>;
template <int NV>
using switcher_c4 = parameter::bypass<soft_bypass1_t<NV>>;

using sb4_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, core::empty>>;

using sb4_t = bypass::smoothed<20, sb4_t_>;
using switcher_c5 = parameter::bypass<sb4_t>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0<NV>, 
                                          switcher_c1<NV>, 
                                          switcher_c2<NV>, 
                                          switcher_c3<NV>, 
                                          switcher_c4<NV>, 
                                          switcher_c5>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<2, sb1_t<NV>>, 
                                        sb2_t<NV>, 
                                        sb3_t<NV>, 
                                        soft_bypass_t<NV>, 
                                        soft_bypass1_t<NV>, 
                                        sb4_t>;

template <int NV>
using softbypass_switch5_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher_t<NV>>, 
                                              sb_container_t<NV>>;

template <int NV>
using wet_path_t = container::chain<parameter::empty, 
                                    wrap::fix<2, softbypass_switch5_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using filter1_t = container::split<parameter::empty, 
                                   wrap::fix<2, dry_path_t<NV>>, 
                                   wet_path_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter_t<NV>>, 
                                  smoothed_parameter1_t<NV>, 
                                  split1_t<NV>, 
                                  filter1_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain4_t<NV>>>;

template <int NV>
using sb5_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, split_t<NV>>>;

template <int NV>
using sb5_t = bypass::smoothed<20, sb5_t_<NV>>;
template <int NV>
using switcher1_c0 = parameter::bypass<sb5_t<NV>>;

template <int NV>
using dry_path3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, pma13_t<NV>>, 
                                     xfader4_t<NV>, 
                                     core::gain<NV>>;

template <int NV> using sb15_t_ = sb1_t_<NV>;

template <int NV>
using sb15_t = bypass::smoothed<20, sb15_t_<NV>>;
template <int NV>
using switcher4_c0 = parameter::bypass<sb15_t<NV>>;

template <int NV> using sb16_t_ = sb1_t_<NV>;

template <int NV>
using sb16_t = bypass::smoothed<20, sb16_t_<NV>>;
template <int NV>
using switcher4_c1 = parameter::bypass<sb16_t<NV>>;

template <int NV> using sb17_t_ = sb1_t_<NV>;

template <int NV>
using sb17_t = bypass::smoothed<20, sb17_t_<NV>>;
template <int NV>
using switcher4_c2 = parameter::bypass<sb17_t<NV>>;

template <int NV> using soft_bypass6_t_ = soft_bypass_t_<NV>;

template <int NV>
using soft_bypass6_t = bypass::smoothed<20, soft_bypass6_t_<NV>>;
template <int NV>
using switcher4_c3 = parameter::bypass<soft_bypass6_t<NV>>;

template <int NV> using soft_bypass7_t_ = soft_bypass1_t_<NV>;

template <int NV>
using soft_bypass7_t = bypass::smoothed<20, soft_bypass7_t_<NV>>;
template <int NV>
using switcher4_c4 = parameter::bypass<soft_bypass7_t<NV>>;

using sb18_t_ = sb4_t_;

using sb18_t = bypass::smoothed<20, sb18_t_>;
using switcher4_c5 = parameter::bypass<sb18_t>;

template <int NV>
using switcher4_multimod = parameter::list<switcher4_c0<NV>, 
                                           switcher4_c1<NV>, 
                                           switcher4_c2<NV>, 
                                           switcher4_c3<NV>, 
                                           switcher4_c4<NV>, 
                                           switcher4_c5>;

template <int NV>
using switcher4_t = control::xfader<switcher4_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container4_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb15_t<NV>>, 
                                         sb16_t<NV>, 
                                         sb17_t<NV>, 
                                         soft_bypass6_t<NV>, 
                                         soft_bypass7_t<NV>, 
                                         sb18_t>;

template <int NV>
using softbypass_switch8_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher4_t<NV>>, 
                                              sb_container4_t<NV>>;

template <int NV>
using wet_path3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, softbypass_switch8_t<NV>>, 
                                     core::gain<NV>>;

template <int NV>
using filter4_t = container::split<parameter::empty, 
                                   wrap::fix<2, dry_path3_t<NV>>, 
                                   wet_path3_t<NV>>;

template <int NV> using smoothed_parameter6_t = smoothed_parameter_t<NV>;

template <int NV> using chain55_t = chain2_t<NV>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sub<NV>>, 
                                   math::expr<NV, custom::expr5>, 
                                   core::gain<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain55_t<NV>>, 
                                   chain56_t<NV>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filter4_t<NV>>, 
                                   smoothed_parameter6_t<NV>, 
                                   smoothed_parameter7_t<NV>, 
                                   split12_t<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain54_t<NV>>>;

template <int NV>
using sb6_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, split11_t<NV>>, 
                                math::mul<NV>>;

template <int NV>
using sb6_t = bypass::smoothed<20, sb6_t_<NV>>;
template <int NV>
using switcher1_c1 = parameter::bypass<sb6_t<NV>>;

template <int NV>
using switcher1_multimod = parameter::list<switcher1_c0<NV>, switcher1_c1<NV>>;

template <int NV>
using switcher1_t = control::xfader<switcher1_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb5_t<NV>>, 
                                         sb6_t<NV>>;

template <int NV>
using softbypass_switch3_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher1_t<NV>>, 
                                              sb_container1_t<NV>>;

namespace FilterNew6_t_parameters
{
// Parameter list for FilterNew6_impl::FilterNew6_t ------------------------------------------------

DECLARE_PARAMETER_RANGE(_2ndParam_InputRange, 
                        5.55112e-17, 
                        1.);
DECLARE_PARAMETER_RANGE_SKEW(_2ndParam_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using _2ndParam_0 = parameter::from0To1<filters::ring_mod<NV>, 
                                        1, 
                                        _2ndParam_0Range>;

template <int NV>
using _2ndParam_1 = parameter::from0To1<filters::allpass<NV>, 
                                        1, 
                                        _2ndParam_0Range>;

template <int NV>
using _2ndParam_2 = parameter::from0To1<filters::svf<NV>, 
                                        1, 
                                        _2ndParam_0Range>;

template <int NV> using _2ndParam_3 = _2ndParam_2<NV>;

template <int NV> using _2ndParam_4 = _2ndParam_2<NV>;

template <int NV> using _2ndParam_5 = _2ndParam_2<NV>;

template <int NV> using _2ndParam_6 = _2ndParam_2<NV>;

template <int NV> using _2ndParam_7 = _2ndParam_2<NV>;

template <int NV> using _2ndParam_8 = _2ndParam_1<NV>;

template <int NV> using _2ndParam_9 = _2ndParam_0<NV>;

template <int NV>
using _2ndParam = parameter::chain<_2ndParam_InputRange, 
                                   _2ndParam_0<NV>, 
                                   _2ndParam_1<NV>, 
                                   _2ndParam_2<NV>, 
                                   _2ndParam_3<NV>, 
                                   _2ndParam_4<NV>, 
                                   _2ndParam_5<NV>, 
                                   _2ndParam_6<NV>, 
                                   _2ndParam_7<NV>, 
                                   _2ndParam_8<NV>, 
                                   _2ndParam_9<NV>>;

DECLARE_PARAMETER_RANGE_STEP(_3rdParam_InputRange, 
                             0., 
                             16., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(_3rdParam_0Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using _3rdParam_0 = parameter::from0To1<FilterNew6_impl::event_data_reader6_t<NV>, 
                                        0, 
                                        _3rdParam_0Range>;

template <int NV>
using _3rdParam = parameter::chain<_3rdParam_InputRange, 
                                   _3rdParam_0<NV>, 
                                   parameter::plain<FilterNew6_impl::cable_table9_t<NV>, 0>, 
                                   parameter::plain<FilterNew6_impl::cable_table10_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(_5thParam_InputRange, 
                             1., 
                             7., 
                             1.);

template <int NV>
using _5thParam = parameter::chain<_5thParam_InputRange, 
                                   parameter::plain<FilterNew6_impl::switcher_t<NV>, 0>, 
                                   parameter::plain<FilterNew6_impl::switcher4_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(GlobalSrc_InputRange, 
                             0., 
                             16., 
                             0.1);
template <int NV>
using GlobalSrc_0 = parameter::from0To1<FilterNew6_impl::event_data_reader4_t<NV>, 
                                        0, 
                                        _3rdParam_0Range>;

template <int NV>
using GlobalSrc = parameter::chain<GlobalSrc_InputRange, 
                                   GlobalSrc_0<NV>, 
                                   parameter::plain<FilterNew6_impl::cable_table6_t<NV>, 0>, 
                                   parameter::plain<FilterNew6_impl::cable_table5_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(StageModSrc_InputRange, 
                             0., 
                             16., 
                             0.1);
template <int NV>
using StageModSrc_0 = parameter::from0To1<FilterNew6_impl::event_data_reader5_t<NV>, 
                                          0, 
                                          _3rdParam_0Range>;

template <int NV>
using StageModSrc = parameter::chain<StageModSrc_InputRange, 
                                     StageModSrc_0<NV>, 
                                     parameter::plain<FilterNew6_impl::cable_table8_t<NV>, 0>, 
                                     parameter::plain<FilterNew6_impl::cable_table7_t<NV>, 0>>;

template <int NV>
using Stage1 = parameter::chain<ranges::Identity, 
                                parameter::plain<FilterNew6_impl::pma10_t<NV>, 2>, 
                                parameter::plain<FilterNew6_impl::pma13_t<NV>, 2>>;

template <int NV>
using Stage2 = parameter::chain<ranges::Identity, 
                                parameter::plain<FilterNew6_impl::pma10_t<NV>, 1>, 
                                parameter::plain<FilterNew6_impl::pma13_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(Stage3_InputRange, 
                             0., 
                             16., 
                             1.);
template <int NV>
using Stage3_2 = parameter::from0To1<FilterNew6_impl::event_data_reader7_t<NV>, 
                                     0, 
                                     _3rdParam_0Range>;

template <int NV>
using Stage3 = parameter::chain<Stage3_InputRange, 
                                parameter::plain<FilterNew6_impl::cable_table11_t<NV>, 0>, 
                                parameter::plain<FilterNew6_impl::cable_table12_t<NV>, 0>, 
                                Stage3_2<NV>>;

template <int NV>
using FoldSub = parameter::chain<ranges::Identity, 
                                 parameter::plain<FilterNew6_impl::smoothed_parameter6_t<NV>, 0>, 
                                 parameter::plain<FilterNew6_impl::smoothed_parameter_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(RangeSrx_InputRange, 
                        0., 
                        16.);
template <int NV>
using RangeSrx_0 = parameter::from0To1<FilterNew6_impl::event_data_reader8_t<NV>, 
                                       0, 
                                       _3rdParam_0Range>;

template <int NV>
using RangeSrx = parameter::chain<RangeSrx_InputRange, 
                                  RangeSrx_0<NV>, 
                                  parameter::plain<FilterNew6_impl::cable_table13_t<NV>, 0>, 
                                  parameter::plain<FilterNew6_impl::cable_table14_t<NV>, 0>>;

template <int NV>
using FoldSmooth = parameter::chain<ranges::Identity, 
                                    parameter::plain<FilterNew6_impl::smoothed_parameter1_t<NV>, 1>, 
                                    parameter::plain<FilterNew6_impl::smoothed_parameter7_t<NV>, 1>>;

template <int NV>
using MainParam = parameter::plain<FilterNew6_impl::pma7_t<NV>, 
                                   2>;
template <int NV>
using _4thParam = parameter::plain<FilterNew6_impl::pma9_t<NV>, 
                                   1>;
template <int NV>
using Global = parameter::plain<FilterNew6_impl::pma7_t<NV>, 
                                1>;
template <int NV>
using Vel = parameter::plain<FilterNew6_impl::pma3_t<NV>, 
                             1>;
template <int NV>
using Trk = parameter::plain<FilterNew6_impl::pma4_t<NV>, 
                             1>;
template <int NV>
using MW = parameter::plain<FilterNew6_impl::pma5_t<NV>, 
                            1>;
template <int NV>
using AT = parameter::plain<FilterNew6_impl::pma6_t<NV>, 
                            1>;
template <int NV>
using StageMod = parameter::plain<FilterNew6_impl::pma8_t<NV>, 
                                  1>;
template <int NV>
using FoldOffset = parameter::plain<FilterNew6_impl::pma1_t<NV>, 
                                    2>;
using Unsused2 = parameter::plain<FilterNew6_impl::pack_resizer1_t, 
                                  0>;
template <int NV>
using Fold = parameter::plain<FilterNew6_impl::pma9_t<NV>, 
                              2>;
template <int NV>
using FoldPos = parameter::plain<FilterNew6_impl::switcher1_t<NV>, 
                                 0>;
template <int NV>
using RangeMod = parameter::plain<FilterNew6_impl::pma1_t<NV>, 
                                  1>;
template <int NV>
using FilterNew6_t_plist = parameter::list<MainParam<NV>, 
                                           _2ndParam<NV>, 
                                           _3rdParam<NV>, 
                                           _4thParam<NV>, 
                                           _5thParam<NV>, 
                                           Global<NV>, 
                                           GlobalSrc<NV>, 
                                           Vel<NV>, 
                                           Trk<NV>, 
                                           MW<NV>, 
                                           AT<NV>, 
                                           StageMod<NV>, 
                                           StageModSrc<NV>, 
                                           Stage1<NV>, 
                                           Stage2<NV>, 
                                           Stage3<NV>, 
                                           FoldOffset<NV>, 
                                           Unsused2, 
                                           Fold<NV>, 
                                           FoldSub<NV>, 
                                           FoldPos<NV>, 
                                           RangeMod<NV>, 
                                           RangeSrx<NV>, 
                                           FoldSmooth<NV>>;
}

template <int NV>
using FilterNew6_t_ = container::chain<FilterNew6_t_parameters::FilterNew6_t_plist<NV>, 
                                       wrap::fix<2, modchain_t<NV>>, 
                                       pma9_t<NV>, 
                                       pma1_t<NV>, 
                                       xfader_t<NV>, 
                                       softbypass_switch3_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public FilterNew6_impl::FilterNew6_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(FilterNew6);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(398)
		{
			0x005B, 0x0000, 0x4D00, 0x6961, 0x506E, 0x7261, 0x6D61, 0x0000, 
            0x8000, 0x0024, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0001, 0x0000, 0x325F, 0x646E, 0x6150, 0x6172, 
            0x006D, 0x0000, 0x2480, 0x0000, 0x3F80, 0x70C5, 0x3D6A, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x5F00, 0x7233, 0x5064, 
            0x7261, 0x6D61, 0x0000, 0x0000, 0x0000, 0x8000, 0x0041, 0x0000, 
            0x0000, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0003, 0x0000, 0x345F, 
            0x6874, 0x6150, 0x6172, 0x006D, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 
            0x5F00, 0x7435, 0x5068, 0x7261, 0x6D61, 0x0000, 0x8000, 0x003F, 
            0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0005, 0x0000, 0x6C47, 0x626F, 0x6C61, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x273F, 0x6CF1, 0x003D, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0006, 0x0000, 0x6C47, 0x626F, 0x6C61, 0x7253, 0x0063, 0x0000, 
            0x0000, 0x0000, 0x4180, 0x999A, 0x40E9, 0x0000, 0x3F80, 0xCCCD, 
            0x3DCC, 0x075B, 0x0000, 0x5600, 0x6C65, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0008, 0x0000, 0x7254, 0x006B, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 
            0x4D00, 0x0057, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 0x0000, 0x4100, 0x0054, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0B5B, 0x0000, 0x5300, 0x6174, 0x6567, 0x6F4D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x7BE7, 0x3D78, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0C5B, 0x0000, 0x5300, 0x6174, 0x6567, 
            0x6F4D, 0x5364, 0x6372, 0x0000, 0x0000, 0x0000, 0x8000, 0x3341, 
            0x1333, 0x0041, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x000D, 0x0000, 
            0x7453, 0x6761, 0x3165, 0x0000, 0x8000, 0x0024, 0x8000, 0xE53F, 
            0x0CA3, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000E, 0x0000, 
            0x7453, 0x6761, 0x3265, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000F, 0x0000, 
            0x7453, 0x6761, 0x3365, 0x0000, 0x0000, 0x0000, 0x8000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0010, 0x0000, 
            0x6F46, 0x646C, 0x664F, 0x7366, 0x7465, 0x0000, 0x8000, 0x0024, 
            0x8000, 0x483F, 0xC55E, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0011, 0x0000, 0x6E55, 0x7573, 0x6573, 0x3264, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x0043, 0x0000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0012, 0x0000, 0x6F46, 0x646C, 0x0000, 0x8000, 0x0024, 
            0x8000, 0x643F, 0x07E7, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0013, 0x0000, 0x6F46, 0x646C, 0x7553, 0x0062, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0798, 0x3F0E, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x145B, 0x0000, 0x4600, 0x6C6F, 0x5064, 0x736F, 0x0000, 0x0000, 
            0x0000, 0x8000, 0xFE3F, 0x9864, 0x003E, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0015, 0x0000, 0x6152, 0x676E, 0x4D65, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0016, 0x0000, 0x6152, 0x676E, 0x5365, 0x7872, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0017, 0x0000, 0x6F46, 0x646C, 0x6D53, 
            0x6F6F, 0x6874, 0xCD00, 0xCCCC, 0x003D, 0x7A00, 0x0044, 0x8000, 
            0x003F, 0x8000, 0xCD3F, 0xCCCC, 0x003D, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                           // FilterNew6_impl::modchain_t<NV>
		auto& split19 = this->getT(0).getT(0);                                                    // FilterNew6_impl::split19_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0);                                                // FilterNew6_impl::pma_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(1);                                             // FilterNew6_impl::split7_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(1).getT(0);                                     // FilterNew6_impl::chain5_t<NV>
		auto& midi = this->getT(0).getT(0).getT(1).getT(0).getT(0);                               // FilterNew6_impl::midi_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                               // FilterNew6_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(1);                                     // FilterNew6_impl::chain6_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                              // FilterNew6_impl::midi1_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                               // FilterNew6_impl::pma4_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(1).getT(2);                                     // FilterNew6_impl::chain9_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(1).getT(2).getT(0);                            // FilterNew6_impl::midi_cc_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                               // FilterNew6_impl::pma5_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(3);                                    // FilterNew6_impl::chain14_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                           // FilterNew6_impl::midi_cc1_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                               // FilterNew6_impl::pma6_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(1).getT(4);                                    // FilterNew6_impl::chain10_t<NV>
		auto& cable_table11 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                      // FilterNew6_impl::cable_table11_t<NV>
		auto& cable_table12 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                      // FilterNew6_impl::cable_table12_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(1).getT(4).getT(2);                             // FilterNew6_impl::split6_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(0);         // FilterNew6_impl::event_data_reader7_t<NV>
		auto& chain19 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1);                    // FilterNew6_impl::chain19_t<NV>
		auto& branch2 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(0);            // FilterNew6_impl::branch2_t<NV>
		auto& chain20 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew6_impl::chain20_t<NV>
                        getT(2).getT(1).getT(0).getT(0);
		auto& global_cable8 = this->getT(0).getT(0).getT(1).getT(4).                              // FilterNew6_impl::global_cable8_t<NV>
                              getT(2).getT(1).getT(0).getT(0).
                              getT(0);
		auto& add8 = this->getT(0).getT(0).getT(1).getT(4).                                       // math::add<NV>
                     getT(2).getT(1).getT(0).getT(0).
                     getT(1);
		auto& chain21 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew6_impl::chain21_t<NV>
                        getT(2).getT(1).getT(0).getT(1);
		auto& global_cable9 = this->getT(0).getT(0).getT(1).getT(4).                              // FilterNew6_impl::global_cable9_t<NV>
                              getT(2).getT(1).getT(0).getT(1).
                              getT(0);
		auto& add9 = this->getT(0).getT(0).getT(1).getT(4).                                       // math::add<NV>
                     getT(2).getT(1).getT(0).getT(1).
                     getT(1);
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew6_impl::chain22_t<NV>
                        getT(2).getT(1).getT(0).getT(2);
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew6_impl::global_cable10_t<NV>
                               getT(2).getT(1).getT(0).getT(2).
                               getT(0);
		auto& add10 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(2).
                      getT(1);
		auto& chain23 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew6_impl::chain23_t<NV>
                        getT(2).getT(1).getT(0).getT(3);
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew6_impl::global_cable11_t<NV>
                               getT(2).getT(1).getT(0).getT(3).
                               getT(0);
		auto& add11 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(3).
                      getT(1);
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew6_impl::chain24_t<NV>
                        getT(2).getT(1).getT(0).getT(4);
		auto& global_cable12 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew6_impl::global_cable12_t<NV>
                               getT(2).getT(1).getT(0).getT(4).
                               getT(0);
		auto& add12 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(4).
                      getT(1);
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew6_impl::chain26_t<NV>
                        getT(2).getT(1).getT(0).getT(5);
		auto& global_cable13 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew6_impl::global_cable13_t<NV>
                               getT(2).getT(1).getT(0).getT(5).
                               getT(0);
		auto& add13 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(5).
                      getT(1);
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew6_impl::chain27_t<NV>
                        getT(2).getT(1).getT(0).getT(6);
		auto& global_cable14 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew6_impl::global_cable14_t<NV>
                               getT(2).getT(1).getT(0).getT(6).
                               getT(0);
		auto& add14 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(6).
                      getT(1);
		auto& chain28 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew6_impl::chain28_t<NV>
                        getT(2).getT(1).getT(0).getT(7);
		auto& global_cable15 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew6_impl::global_cable15_t<NV>
                               getT(2).getT(1).getT(0).getT(7).
                               getT(0);
		auto& add15 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(7).
                      getT(1);
		auto& peak1 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(1);              // FilterNew6_impl::peak1_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(2);             // math::clear<NV>
		auto& input_toggle1 = this->getT(0).getT(0).getT(1).getT(4).getT(3);                      // FilterNew6_impl::input_toggle1_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(5);                                    // FilterNew6_impl::chain25_t<NV>
		auto& chain3 = this->getT(0).getT(0).getT(1).getT(5).getT(0);                             // FilterNew6_impl::chain3_t<NV>
		auto& cable_table5 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(0);               // FilterNew6_impl::cable_table5_t<NV>
		auto& cable_table6 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(1);               // FilterNew6_impl::cable_table6_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(2);                     // FilterNew6_impl::split3_t<NV>
		auto& event_data_reader4 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(2).getT(0); // FilterNew6_impl::event_data_reader4_t<NV>
		auto& chain38 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(2).getT(1);            // FilterNew6_impl::chain38_t<NV>
		auto& branch4 = this->getT(0).getT(0).getT(1).getT(5).                                    // FilterNew6_impl::branch4_t<NV>
                        getT(0).getT(2).getT(1).getT(0);
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew6_impl::chain39_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(0);
		auto& global_cable24 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew6_impl::global_cable24_t<NV>
                               getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& add24 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(0).getT(1);
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew6_impl::chain40_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(1);
		auto& global_cable25 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew6_impl::global_cable25_t<NV>
                               getT(2).getT(1).getT(0).getT(1).getT(0);
		auto& add25 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(1).getT(1);
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew6_impl::chain41_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(2);
		auto& global_cable26 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew6_impl::global_cable26_t<NV>
                               getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& add26 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(2).getT(1);
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew6_impl::chain42_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(3);
		auto& global_cable27 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew6_impl::global_cable27_t<NV>
                               getT(2).getT(1).getT(0).getT(3).getT(0);
		auto& add27 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(3).getT(1);
		auto& chain43 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew6_impl::chain43_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(4);
		auto& global_cable28 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew6_impl::global_cable28_t<NV>
                               getT(2).getT(1).getT(0).getT(4).getT(0);
		auto& add28 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(4).getT(1);
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew6_impl::chain44_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(5);
		auto& global_cable29 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew6_impl::global_cable29_t<NV>
                               getT(2).getT(1).getT(0).getT(5).getT(0);
		auto& add29 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(5).getT(1);
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew6_impl::chain45_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(6);
		auto& global_cable30 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew6_impl::global_cable30_t<NV>
                               getT(2).getT(1).getT(0).getT(6).getT(0);
		auto& add30 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(6).getT(1);
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew6_impl::chain46_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(7);
		auto& global_cable31 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew6_impl::global_cable31_t<NV>
                               getT(2).getT(1).getT(0).getT(7).getT(0);
		auto& add31 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(7).getT(1);
		auto& peak3 = this->getT(0).getT(0).getT(1).getT(5).                               // FilterNew6_impl::peak3_t<NV>
                      getT(0).getT(2).getT(1).getT(1);
		auto& input_toggle3 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(3);       // FilterNew6_impl::input_toggle3_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                        // FilterNew6_impl::pma7_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(2);                                      // FilterNew6_impl::chain7_t<NV>
		auto& pack_resizer1 = this->getT(0).getT(0).getT(2).getT(0);                       // FilterNew6_impl::pack_resizer1_t
		auto& sliderbank = this->getT(0).getT(0).getT(2).getT(1);                          // FilterNew6_impl::sliderbank_t<NV>
		auto& cable_table7 = this->getT(0).getT(0).getT(2).getT(2);                        // FilterNew6_impl::cable_table7_t<NV>
		auto& cable_table8 = this->getT(0).getT(0).getT(2).getT(3);                        // FilterNew6_impl::cable_table8_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(2).getT(4);                              // FilterNew6_impl::split4_t<NV>
		auto& event_data_reader5 = this->getT(0).getT(0).getT(2).getT(4).getT(0);          // FilterNew6_impl::event_data_reader5_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(2).getT(4).getT(1);                     // FilterNew6_impl::chain29_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0);             // FilterNew6_impl::branch3_t<NV>
		auto& chain30 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(0);     // FilterNew6_impl::chain30_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew6_impl::global_cable16_t<NV>
                               getT(1).getT(0).getT(0).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1);
		auto& chain31 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(1);     // FilterNew6_impl::chain31_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew6_impl::global_cable17_t<NV>
                               getT(1).getT(0).getT(1).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(1).getT(1);
		auto& chain32 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(2);     // FilterNew6_impl::chain32_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew6_impl::global_cable18_t<NV>
                               getT(1).getT(0).getT(2).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(2).getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(3);     // FilterNew6_impl::chain33_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew6_impl::global_cable19_t<NV>
                               getT(1).getT(0).getT(3).getT(0);
		auto& add19 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(3).getT(1);
		auto& chain34 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(4);     // FilterNew6_impl::chain34_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew6_impl::global_cable20_t<NV>
                               getT(1).getT(0).getT(4).getT(0);
		auto& add20 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(4).getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(5);     // FilterNew6_impl::chain35_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew6_impl::global_cable21_t<NV>
                               getT(1).getT(0).getT(5).getT(0);
		auto& add21 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(5).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(6);     // FilterNew6_impl::chain36_t<NV>
		auto& global_cable22 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew6_impl::global_cable22_t<NV>
                               getT(1).getT(0).getT(6).getT(0);
		auto& add22 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(6).getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(7);     // FilterNew6_impl::chain37_t<NV>
		auto& global_cable23 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew6_impl::global_cable23_t<NV>
                               getT(1).getT(0).getT(7).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(7).getT(1);
		auto& peak2 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(1);               // FilterNew6_impl::peak2_t<NV>
		auto& clear = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(2);               // math::clear<NV>
		auto& input_toggle4 = this->getT(0).getT(0).getT(2).getT(5);                       // FilterNew6_impl::input_toggle4_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(2).getT(6);                                // FilterNew6_impl::pma8_t<NV>
		auto& chain8 = this->getT(0).getT(0).getT(3);                                      // FilterNew6_impl::chain8_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(3).getT(0);                              // FilterNew6_impl::split5_t<NV>
		auto& event_data_reader6 = this->getT(0).getT(0).getT(3).getT(0).getT(0);          // FilterNew6_impl::event_data_reader6_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(3).getT(0).getT(1);                     // FilterNew6_impl::chain11_t<NV>
		auto& cable_table9 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0);        // FilterNew6_impl::cable_table9_t<NV>
		auto& cable_table10 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1);       // FilterNew6_impl::cable_table10_t<NV>
		auto& branch1 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2);             // FilterNew6_impl::branch1_t<NV>
		auto& chain = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(0);       // FilterNew6_impl::chain_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(3).getT(0).                        // FilterNew6_impl::global_cable_t<NV>
                             getT(1).getT(2).getT(0).getT(0);
		auto& add = this->getT(0).getT(0).getT(3).getT(0).                                 // math::add<NV>
                    getT(1).getT(2).getT(0).getT(1);
		auto& chain1 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(1);      // FilterNew6_impl::chain1_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew6_impl::global_cable1_t<NV>
                              getT(1).getT(2).getT(1).getT(0);
		auto& add1 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(1).getT(1);
		auto& chain12 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(2);     // FilterNew6_impl::chain12_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew6_impl::global_cable2_t<NV>
                              getT(1).getT(2).getT(2).getT(0);
		auto& add2 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(2).getT(1);
		auto& chain13 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(3);     // FilterNew6_impl::chain13_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew6_impl::global_cable3_t<NV>
                              getT(1).getT(2).getT(3).getT(0);
		auto& add3 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(3).getT(1);
		auto& chain15 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(4);     // FilterNew6_impl::chain15_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew6_impl::global_cable4_t<NV>
                              getT(1).getT(2).getT(4).getT(0);
		auto& add4 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(4).getT(1);
		auto& chain16 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(5);     // FilterNew6_impl::chain16_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew6_impl::global_cable5_t<NV>
                              getT(1).getT(2).getT(5).getT(0);
		auto& add5 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(5).getT(1);
		auto& chain17 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(6);     // FilterNew6_impl::chain17_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew6_impl::global_cable6_t<NV>
                              getT(1).getT(2).getT(6).getT(0);
		auto& add6 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(6).getT(1);
		auto& chain18 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(7);     // FilterNew6_impl::chain18_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew6_impl::global_cable7_t<NV>
                              getT(1).getT(2).getT(7).getT(0);
		auto& add7 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(7).getT(1);
		auto& peak = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3);                // FilterNew6_impl::peak_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(4);              // math::clear<NV>
		auto& input_toggle = this->getT(0).getT(0).getT(3).getT(1);                        // FilterNew6_impl::input_toggle_t<NV>
		auto& chain48 = this->getT(0).getT(0).getT(4);                                     // FilterNew6_impl::chain48_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(4).getT(0);                              // FilterNew6_impl::split8_t<NV>
		auto& event_data_reader8 = this->getT(0).getT(0).getT(4).getT(0).getT(0);          // FilterNew6_impl::event_data_reader8_t<NV>
		auto& chain49 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                     // FilterNew6_impl::chain49_t<NV>
		auto& cable_table13 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0);       // FilterNew6_impl::cable_table13_t<NV>
		auto& cable_table14 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(1);       // FilterNew6_impl::cable_table14_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2);             // FilterNew6_impl::branch5_t<NV>
		auto& chain50 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(0);     // FilterNew6_impl::chain50_t<NV>
		auto& global_cable32 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew6_impl::global_cable32_t<NV>
                               getT(1).getT(2).getT(0).getT(0);
		auto& add32 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(0).getT(1);
		auto& chain51 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(1);     // FilterNew6_impl::chain51_t<NV>
		auto& global_cable33 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew6_impl::global_cable33_t<NV>
                               getT(1).getT(2).getT(1).getT(0);
		auto& add33 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(1).getT(1);
		auto& chain52 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(2);     // FilterNew6_impl::chain52_t<NV>
		auto& global_cable34 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew6_impl::global_cable34_t<NV>
                               getT(1).getT(2).getT(2).getT(0);
		auto& add34 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(2).getT(1);
		auto& chain53 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(3);     // FilterNew6_impl::chain53_t<NV>
		auto& global_cable35 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew6_impl::global_cable35_t<NV>
                               getT(1).getT(2).getT(3).getT(0);
		auto& add35 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(3).getT(1);
		auto& chain57 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(4);     // FilterNew6_impl::chain57_t<NV>
		auto& global_cable36 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew6_impl::global_cable36_t<NV>
                               getT(1).getT(2).getT(4).getT(0);
		auto& add36 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(4).getT(1);
		auto& chain58 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(5);     // FilterNew6_impl::chain58_t<NV>
		auto& global_cable37 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew6_impl::global_cable37_t<NV>
                               getT(1).getT(2).getT(5).getT(0);
		auto& add37 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(5).getT(1);
		auto& chain59 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(6);     // FilterNew6_impl::chain59_t<NV>
		auto& global_cable38 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew6_impl::global_cable38_t<NV>
                               getT(1).getT(2).getT(6).getT(0);
		auto& add38 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(6).getT(1);
		auto& chain60 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(7);     // FilterNew6_impl::chain60_t<NV>
		auto& global_cable39 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew6_impl::global_cable39_t<NV>
                               getT(1).getT(2).getT(7).getT(0);
		auto& add39 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(7).getT(1);
		auto& peak4 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(3);               // FilterNew6_impl::peak4_t<NV>
		auto& clear3 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(4);              // math::clear<NV>
		auto& input_toggle2 = this->getT(0).getT(0).getT(4).getT(1);                       // FilterNew6_impl::input_toggle2_t<NV>
		auto& pma9 = this->getT(1);                                                        // FilterNew6_impl::pma9_t<NV>
		auto& pma1 = this->getT(2);                                                        // FilterNew6_impl::pma1_t<NV>
		auto& xfader = this->getT(3);                                                      // FilterNew6_impl::xfader_t<NV>
		auto& softbypass_switch3 = this->getT(4);                                          // FilterNew6_impl::softbypass_switch3_t<NV>
		auto& switcher1 = this->getT(4).getT(0);                                           // FilterNew6_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(4).getT(1);                                       // FilterNew6_impl::sb_container1_t<NV>
		auto& sb5 = this->getT(4).getT(1).getT(0);                                         // FilterNew6_impl::sb5_t<NV>
		auto& split = this->getT(4).getT(1).getT(0).getT(0);                               // FilterNew6_impl::split_t<NV>
		auto& chain4 = this->getT(4).getT(1).getT(0).getT(0).getT(0);                      // FilterNew6_impl::chain4_t<NV>
		auto& smoothed_parameter = this->getT(4).getT(1).getT(0).getT(0).getT(0).getT(0);  // FilterNew6_impl::smoothed_parameter_t<NV>
		auto& smoothed_parameter1 = this->getT(4).getT(1).getT(0).getT(0).getT(0).getT(1); // FilterNew6_impl::smoothed_parameter1_t<NV>
		auto& split1 = this->getT(4).getT(1).getT(0).getT(0).getT(0).getT(2);              // FilterNew6_impl::split1_t<NV>
		auto& chain2 = this->getT(4).getT(1).getT(0).getT(0).getT(0).getT(2).getT(0);      // FilterNew6_impl::chain2_t<NV>
		auto& gain1 = this->getT(4).getT(1).getT(0).getT(0).                               // core::gain<NV>
                      getT(0).getT(2).getT(0).getT(0);
		auto& chain47 = this->getT(4).getT(1).getT(0).getT(0).getT(0).getT(2).getT(1);     // FilterNew6_impl::chain47_t<NV>
		auto& sub = this->getT(4).getT(1).getT(0).getT(0).                                 // math::sub<NV>
                    getT(0).getT(2).getT(1).getT(0);
		auto& expr2 = this->getT(4).getT(1).getT(0).getT(0).                               // math::expr<NV, custom::expr2>
                      getT(0).getT(2).getT(1).getT(1);
		auto& gain2 = this->getT(4).getT(1).getT(0).getT(0).                               // core::gain<NV>
                      getT(0).getT(2).getT(1).getT(2);
		auto& filter1 = this->getT(4).getT(1).getT(0).getT(0).getT(0).getT(3);             // FilterNew6_impl::filter1_t<NV>
		auto& dry_path = this->getT(4).getT(1).getT(0).getT(0).getT(0).getT(3).getT(0);    // FilterNew6_impl::dry_path_t<NV>
		auto& pma10 = this->getT(4).getT(1).getT(0).getT(0).                               // FilterNew6_impl::pma10_t<NV>
                      getT(0).getT(3).getT(0).getT(0);
		auto& xfader1 = this->getT(4).getT(1).getT(0).getT(0).                             // FilterNew6_impl::xfader1_t<NV>
                        getT(0).getT(3).getT(0).getT(1);
		auto& gain = this->getT(4).getT(1).getT(0).getT(0).                                // core::gain<NV>
                     getT(0).getT(3).getT(0).getT(2);
		auto& wet_path = this->getT(4).getT(1).getT(0).getT(0).getT(0).getT(3).getT(1);    // FilterNew6_impl::wet_path_t<NV>
		auto& softbypass_switch5 = this->getT(4).getT(1).getT(0).getT(0).                  // FilterNew6_impl::softbypass_switch5_t<NV>
                                   getT(0).getT(3).getT(1).getT(0);
		auto& switcher = this->getT(4).getT(1).getT(0).getT(0).                            // FilterNew6_impl::switcher_t<NV>
                         getT(0).getT(3).getT(1).getT(0).
                         getT(0);
		auto& sb_container = this->getT(4).getT(1).getT(0).getT(0).                        // FilterNew6_impl::sb_container_t<NV>
                             getT(0).getT(3).getT(1).getT(0).
                             getT(1);
		auto& sb1 = this->getT(4).getT(1).getT(0).getT(0).getT(0).                         // FilterNew6_impl::sb1_t<NV>
                    getT(3).getT(1).getT(0).getT(1).getT(0);
		auto& svf = this->getT(4).getT(1).getT(0).getT(0).getT(0).                         // filters::svf<NV>
                    getT(3).getT(1).getT(0).getT(1).getT(0).
                    getT(0);
		auto& sb2 = this->getT(4).getT(1).getT(0).getT(0).getT(0).                         // FilterNew6_impl::sb2_t<NV>
                    getT(3).getT(1).getT(0).getT(1).getT(1);
		auto& svf1 = this->getT(4).getT(1).getT(0).getT(0).getT(0).                        // filters::svf<NV>
                     getT(3).getT(1).getT(0).getT(1).getT(1).
                     getT(0);
		auto& sb3 = this->getT(4).getT(1).getT(0).getT(0).getT(0).                         // FilterNew6_impl::sb3_t<NV>
                    getT(3).getT(1).getT(0).getT(1).getT(2);
		auto& svf2 = this->getT(4).getT(1).getT(0).getT(0).getT(0).                        // filters::svf<NV>
                     getT(3).getT(1).getT(0).getT(1).getT(2).
                     getT(0);
		auto& soft_bypass = this->getT(4).getT(1).getT(0).getT(0).getT(0).                 // FilterNew6_impl::soft_bypass_t<NV>
                            getT(3).getT(1).getT(0).getT(1).getT(3);
		auto& allpass = this->getT(4).getT(1).getT(0).getT(0).getT(0).                     // filters::allpass<NV>
                        getT(3).getT(1).getT(0).getT(1).getT(3).
                        getT(0);
		auto& soft_bypass1 = this->getT(4).getT(1).getT(0).getT(0).getT(0).                // FilterNew6_impl::soft_bypass1_t<NV>
                             getT(3).getT(1).getT(0).getT(1).getT(4);
		auto& ring_mod = this->getT(4).getT(1).getT(0).getT(0).getT(0).                    // filters::ring_mod<NV>
                         getT(3).getT(1).getT(0).getT(1).getT(4).
                         getT(0);
		auto& sb4 = this->getT(4).getT(1).getT(0).getT(0).getT(0).                         // FilterNew6_impl::sb4_t
                    getT(3).getT(1).getT(0).getT(1).getT(5);
		auto& gain17 = this->getT(4).getT(1).getT(0).getT(0).                              // core::gain<NV>
                       getT(0).getT(3).getT(1).getT(1);
		auto& sb6 = this->getT(4).getT(1).getT(1);                                         // FilterNew6_impl::sb6_t<NV>
		auto& split11 = this->getT(4).getT(1).getT(1).getT(0);                             // FilterNew6_impl::split11_t<NV>
		auto& chain54 = this->getT(4).getT(1).getT(1).getT(0).getT(0);                     // FilterNew6_impl::chain54_t<NV>
		auto& filter4 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(0);             // FilterNew6_impl::filter4_t<NV>
		auto& dry_path3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);   // FilterNew6_impl::dry_path3_t<NV>
		auto& pma13 = this->getT(4).getT(1).getT(1).getT(0).                               // FilterNew6_impl::pma13_t<NV>
                      getT(0).getT(0).getT(0).getT(0);
		auto& xfader4 = this->getT(4).getT(1).getT(1).getT(0).                             // FilterNew6_impl::xfader4_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& gain11 = this->getT(4).getT(1).getT(1).getT(0).                              // core::gain<NV>
                       getT(0).getT(0).getT(0).getT(2);
		auto& wet_path3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(0).getT(1);   // FilterNew6_impl::wet_path3_t<NV>
		auto& softbypass_switch8 = this->getT(4).getT(1).getT(1).getT(0).                  // FilterNew6_impl::softbypass_switch8_t<NV>
                                   getT(0).getT(0).getT(1).getT(0);
		auto& switcher4 = this->getT(4).getT(1).getT(1).getT(0).                           // FilterNew6_impl::switcher4_t<NV>
                          getT(0).getT(0).getT(1).getT(0).
                          getT(0);
		auto& sb_container4 = this->getT(4).getT(1).getT(1).getT(0).                       // FilterNew6_impl::sb_container4_t<NV>
                              getT(0).getT(0).getT(1).getT(0).
                              getT(1);
		auto& sb15 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                        // FilterNew6_impl::sb15_t<NV>
                     getT(0).getT(1).getT(0).getT(1).getT(0);
		auto& svf9 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                        // filters::svf<NV>
                     getT(0).getT(1).getT(0).getT(1).getT(0).
                     getT(0);
		auto& sb16 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                        // FilterNew6_impl::sb16_t<NV>
                     getT(0).getT(1).getT(0).getT(1).getT(1);
		auto& svf10 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                       // filters::svf<NV>
                      getT(0).getT(1).getT(0).getT(1).getT(1).
                      getT(0);
		auto& sb17 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                        // FilterNew6_impl::sb17_t<NV>
                     getT(0).getT(1).getT(0).getT(1).getT(2);
		auto& svf11 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                       // filters::svf<NV>
                      getT(0).getT(1).getT(0).getT(1).getT(2).
                      getT(0);
		auto& soft_bypass6 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                // FilterNew6_impl::soft_bypass6_t<NV>
                             getT(0).getT(1).getT(0).getT(1).getT(3);
		auto& allpass3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                    // filters::allpass<NV>
                         getT(0).getT(1).getT(0).getT(1).getT(3).
                         getT(0);
		auto& soft_bypass7 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                // FilterNew6_impl::soft_bypass7_t<NV>
                             getT(0).getT(1).getT(0).getT(1).getT(4);
		auto& ring_mod3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                   // filters::ring_mod<NV>
                          getT(0).getT(1).getT(0).getT(1).getT(4).
                          getT(0);
		auto& sb18 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                        // FilterNew6_impl::sb18_t
                     getT(0).getT(1).getT(0).getT(1).getT(5);
		auto& gain20 = this->getT(4).getT(1).getT(1).getT(0).                              // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& smoothed_parameter6 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(1); // FilterNew6_impl::smoothed_parameter6_t<NV>
		auto& smoothed_parameter7 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(2); // FilterNew6_impl::smoothed_parameter7_t<NV>
		auto& split12 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3);             // FilterNew6_impl::split12_t<NV>
		auto& chain55 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3).getT(0);     // FilterNew6_impl::chain55_t<NV>
		auto& gain9 = this->getT(4).getT(1).getT(1).getT(0).                               // core::gain<NV>
                      getT(0).getT(3).getT(0).getT(0);
		auto& chain56 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3).getT(1); // FilterNew6_impl::chain56_t<NV>
		auto& sub3 = this->getT(4).getT(1).getT(1).getT(0).                            // math::sub<NV>
                     getT(0).getT(3).getT(1).getT(0);
		auto& expr5 = this->getT(4).getT(1).getT(1).getT(0).   // math::expr<NV, custom::expr5>
                      getT(0).getT(3).getT(1).getT(1);
		auto& gain10 = this->getT(4).getT(1).getT(1).getT(0).  // core::gain<NV>
                       getT(0).getT(3).getT(1).getT(2);
		auto& dummy1 = this->getT(4).getT(1).getT(1).getT(1); // math::mul<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma7); // MainParam -> pma7::Add
		
		auto& _2ndParam_p = this->getParameterT(1);
		_2ndParam_p.connectT(0, ring_mod);  // _2ndParam -> ring_mod::Q
		_2ndParam_p.connectT(1, allpass);   // _2ndParam -> allpass::Q
		_2ndParam_p.connectT(2, svf2);      // _2ndParam -> svf2::Q
		_2ndParam_p.connectT(3, svf1);      // _2ndParam -> svf1::Q
		_2ndParam_p.connectT(4, svf);       // _2ndParam -> svf::Q
		_2ndParam_p.connectT(5, svf9);      // _2ndParam -> svf9::Q
		_2ndParam_p.connectT(6, svf10);     // _2ndParam -> svf10::Q
		_2ndParam_p.connectT(7, svf11);     // _2ndParam -> svf11::Q
		_2ndParam_p.connectT(8, allpass3);  // _2ndParam -> allpass3::Q
		_2ndParam_p.connectT(9, ring_mod3); // _2ndParam -> ring_mod3::Q
		
		auto& _3rdParam_p = this->getParameterT(2);
		_3rdParam_p.connectT(0, event_data_reader6); // _3rdParam -> event_data_reader6::SlotIndex
		_3rdParam_p.connectT(1, cable_table9);       // _3rdParam -> cable_table9::Value
		_3rdParam_p.connectT(2, cable_table10);      // _3rdParam -> cable_table10::Value
		
		this->getParameterT(3).connectT(0, pma9); // _4thParam -> pma9::Multiply
		
		auto& _5thParam_p = this->getParameterT(4);
		_5thParam_p.connectT(0, switcher);  // _5thParam -> switcher::Value
		_5thParam_p.connectT(1, switcher4); // _5thParam -> switcher4::Value
		
		this->getParameterT(5).connectT(0, pma7); // Global -> pma7::Multiply
		
		auto& GlobalSrc_p = this->getParameterT(6);
		GlobalSrc_p.connectT(0, event_data_reader4); // GlobalSrc -> event_data_reader4::SlotIndex
		GlobalSrc_p.connectT(1, cable_table6);       // GlobalSrc -> cable_table6::Value
		GlobalSrc_p.connectT(2, cable_table5);       // GlobalSrc -> cable_table5::Value
		
		this->getParameterT(7).connectT(0, pma3); // Vel -> pma3::Multiply
		
		this->getParameterT(8).connectT(0, pma4); // Trk -> pma4::Multiply
		
		this->getParameterT(9).connectT(0, pma5); // MW -> pma5::Multiply
		
		this->getParameterT(10).connectT(0, pma6); // AT -> pma6::Multiply
		
		this->getParameterT(11).connectT(0, pma8); // StageMod -> pma8::Multiply
		
		auto& StageModSrc_p = this->getParameterT(12);
		StageModSrc_p.connectT(0, event_data_reader5); // StageModSrc -> event_data_reader5::SlotIndex
		StageModSrc_p.connectT(1, cable_table8);       // StageModSrc -> cable_table8::Value
		StageModSrc_p.connectT(2, cable_table7);       // StageModSrc -> cable_table7::Value
		
		auto& Stage1_p = this->getParameterT(13);
		Stage1_p.connectT(0, pma10); // Stage1 -> pma10::Add
		Stage1_p.connectT(1, pma13); // Stage1 -> pma13::Add
		
		auto& Stage2_p = this->getParameterT(14);
		Stage2_p.connectT(0, pma10); // Stage2 -> pma10::Multiply
		Stage2_p.connectT(1, pma13); // Stage2 -> pma13::Multiply
		
		auto& Stage3_p = this->getParameterT(15);
		Stage3_p.connectT(0, cable_table11);      // Stage3 -> cable_table11::Value
		Stage3_p.connectT(1, cable_table12);      // Stage3 -> cable_table12::Value
		Stage3_p.connectT(2, event_data_reader7); // Stage3 -> event_data_reader7::SlotIndex
		
		this->getParameterT(16).connectT(0, pma1); // FoldOffset -> pma1::Add
		
		this->getParameterT(17).connectT(0, pack_resizer1); // Unsused2 -> pack_resizer1::NumSliders
		
		this->getParameterT(18).connectT(0, pma9); // Fold -> pma9::Add
		
		auto& FoldSub_p = this->getParameterT(19);
		FoldSub_p.connectT(0, smoothed_parameter6); // FoldSub -> smoothed_parameter6::Value
		FoldSub_p.connectT(1, smoothed_parameter);  // FoldSub -> smoothed_parameter::Value
		
		this->getParameterT(20).connectT(0, switcher1); // FoldPos -> switcher1::Value
		
		this->getParameterT(21).connectT(0, pma1); // RangeMod -> pma1::Multiply
		
		auto& RangeSrx_p = this->getParameterT(22);
		RangeSrx_p.connectT(0, event_data_reader8); // RangeSrx -> event_data_reader8::SlotIndex
		RangeSrx_p.connectT(1, cable_table13);      // RangeSrx -> cable_table13::Value
		RangeSrx_p.connectT(2, cable_table14);      // RangeSrx -> cable_table14::Value
		
		auto& FoldSmooth_p = this->getParameterT(23);
		FoldSmooth_p.connectT(0, smoothed_parameter1); // FoldSmooth -> smoothed_parameter1::SmoothingTime
		FoldSmooth_p.connectT(1, smoothed_parameter7); // FoldSmooth -> smoothed_parameter7::SmoothingTime
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma8.getWrappedObject().getParameter().connectT(0, svf);       // pma8 -> svf::Frequency
		pma8.getWrappedObject().getParameter().connectT(1, svf1);      // pma8 -> svf1::Frequency
		pma8.getWrappedObject().getParameter().connectT(2, svf2);      // pma8 -> svf2::Frequency
		pma8.getWrappedObject().getParameter().connectT(3, allpass);   // pma8 -> allpass::Frequency
		pma8.getWrappedObject().getParameter().connectT(4, ring_mod);  // pma8 -> ring_mod::Frequency
		pma8.getWrappedObject().getParameter().connectT(5, svf9);      // pma8 -> svf9::Frequency
		pma8.getWrappedObject().getParameter().connectT(6, svf10);     // pma8 -> svf10::Frequency
		pma8.getWrappedObject().getParameter().connectT(7, svf11);     // pma8 -> svf11::Frequency
		pma8.getWrappedObject().getParameter().connectT(8, allpass3);  // pma8 -> allpass3::Frequency
		pma8.getWrappedObject().getParameter().connectT(9, ring_mod3); // pma8 -> ring_mod3::Frequency
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(5).connectT(0, pma8);                      // sliderbank -> pma8::Add
		pma.getWrappedObject().getParameter().connectT(0, sliderbank);        // pma -> sliderbank::Value
		pma3.getWrappedObject().getParameter().connectT(0, pma);              // pma3 -> pma::Add
		midi.getParameter().connectT(0, pma3);                                // midi -> pma3::Value
		pma4.getWrappedObject().getParameter().connectT(0, pma3);             // pma4 -> pma3::Add
		midi1.getParameter().connectT(0, pma4);                               // midi1 -> pma4::Value
		pma5.getWrappedObject().getParameter().connectT(0, pma4);             // pma5 -> pma4::Add
		midi_cc.getWrappedObject().getParameter().connectT(0, pma5);          // midi_cc -> pma5::Value
		pma6.getWrappedObject().getParameter().connectT(0, pma5);             // pma6 -> pma5::Add
		midi_cc1.getWrappedObject().getParameter().connectT(0, pma6);         // midi_cc1 -> pma6::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add8);    // global_cable8 -> add8::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add9);    // global_cable9 -> add9::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add10);  // global_cable10 -> add10::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add11);  // global_cable11 -> add11::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add12);  // global_cable12 -> add12::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add13);  // global_cable13 -> add13::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add14);  // global_cable14 -> add14::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add15);  // global_cable15 -> add15::Value
		cable_table11.getWrappedObject().getParameter().connectT(0, branch2); // cable_table11 -> branch2::Index
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain);                 // xfader1 -> gain::Gain
		xfader1_p.getParameterT(1).connectT(0, gain17);               // xfader1 -> gain17::Gain
		pma10.getWrappedObject().getParameter().connectT(0, xfader1); // pma10 -> xfader1::Value
		auto& xfader4_p = xfader4.getWrappedObject().getParameter();
		xfader4_p.getParameterT(0).connectT(0, gain11);                             // xfader4 -> gain11::Gain
		xfader4_p.getParameterT(1).connectT(0, gain20);                             // xfader4 -> gain20::Gain
		pma13.getWrappedObject().getParameter().connectT(0, xfader4);               // pma13 -> xfader4::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, pma10);         // input_toggle1 -> pma10::Value
		input_toggle1.getWrappedObject().getParameter().connectT(1, pma13);         // input_toggle1 -> pma13::Value
		cable_table12.getWrappedObject().getParameter().connectT(0, input_toggle1); // cable_table12 -> input_toggle1::Input
		event_data_reader7.getParameter().connectT(0, input_toggle1);               // event_data_reader7 -> input_toggle1::Value1
		peak1.getParameter().connectT(0, input_toggle1);                            // peak1 -> input_toggle1::Value2
		global_cable24.getWrappedObject().getParameter().connectT(0, add24);        // global_cable24 -> add24::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add25);        // global_cable25 -> add25::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add26);        // global_cable26 -> add26::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add27);        // global_cable27 -> add27::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add28);        // global_cable28 -> add28::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add29);        // global_cable29 -> add29::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add30);        // global_cable30 -> add30::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add31);        // global_cable31 -> add31::Value
		cable_table5.getWrappedObject().getParameter().connectT(0, branch4);        // cable_table5 -> branch4::Index
		pma7.getWrappedObject().getParameter().connectT(0, pma6);                   // pma7 -> pma6::Add
		input_toggle3.getWrappedObject().getParameter().connectT(0, pma7);          // input_toggle3 -> pma7::Value
		cable_table6.getWrappedObject().getParameter().connectT(0, input_toggle3);  // cable_table6 -> input_toggle3::Input
		event_data_reader4.getParameter().connectT(0, input_toggle3);               // event_data_reader4 -> input_toggle3::Value1
		peak3.getParameter().connectT(0, input_toggle3);                            // peak3 -> input_toggle3::Value2
		global_cable16.getWrappedObject().getParameter().connectT(0, add16);        // global_cable16 -> add16::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add17);        // global_cable17 -> add17::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add18);        // global_cable18 -> add18::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add19);        // global_cable19 -> add19::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add20);        // global_cable20 -> add20::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add21);        // global_cable21 -> add21::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add22);        // global_cable22 -> add22::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add23);        // global_cable23 -> add23::Value
		cable_table7.getWrappedObject().getParameter().connectT(0, branch3);        // cable_table7 -> branch3::Index
		input_toggle4.getWrappedObject().getParameter().connectT(0, pma8);          // input_toggle4 -> pma8::Value
		cable_table8.getWrappedObject().getParameter().connectT(0, input_toggle4);  // cable_table8 -> input_toggle4::Input
		event_data_reader5.getParameter().connectT(0, input_toggle4);               // event_data_reader5 -> input_toggle4::Value1
		peak2.getParameter().connectT(0, input_toggle4);                            // peak2 -> input_toggle4::Value2
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                               // xfader -> gain1::Gain
		xfader_p.getParameterT(0).connectT(1, gain9);                               // xfader -> gain9::Gain
		xfader_p.getParameterT(1).connectT(0, gain2);                               // xfader -> gain2::Gain
		xfader_p.getParameterT(1).connectT(1, gain10);                              // xfader -> gain10::Gain
		pma9.getWrappedObject().getParameter().connectT(0, xfader);                 // pma9 -> xfader::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, pma9);           // input_toggle -> pma9::Value
		event_data_reader6.getParameter().connectT(0, input_toggle);                // event_data_reader6 -> input_toggle::Value1
		global_cable.getWrappedObject().getParameter().connectT(0, add);            // global_cable -> add::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add1);          // global_cable1 -> add1::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);          // global_cable2 -> add2::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add3);          // global_cable3 -> add3::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add4);          // global_cable4 -> add4::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add5);          // global_cable5 -> add5::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add6);          // global_cable6 -> add6::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add7);          // global_cable7 -> add7::Value
		cable_table9.getWrappedObject().getParameter().connectT(0, branch1);        // cable_table9 -> branch1::Index
		cable_table10.getWrappedObject().getParameter().connectT(0, input_toggle);  // cable_table10 -> input_toggle::Input
		peak.getParameter().connectT(0, input_toggle);                              // peak -> input_toggle::Value2
		smoothed_parameter1.getParameter().connectT(0, expr2);                      // smoothed_parameter1 -> expr2::Value
		smoothed_parameter7.getParameter().connectT(0, expr5);                      // smoothed_parameter7 -> expr5::Value
		pma1.getWrappedObject().getParameter().connectT(0, smoothed_parameter1);    // pma1 -> smoothed_parameter1::Value
		pma1.getWrappedObject().getParameter().connectT(1, smoothed_parameter7);    // pma1 -> smoothed_parameter7::Value
		input_toggle2.getWrappedObject().getParameter().connectT(0, pma1);          // input_toggle2 -> pma1::Value
		event_data_reader8.getParameter().connectT(0, input_toggle2);               // event_data_reader8 -> input_toggle2::Value1
		global_cable32.getWrappedObject().getParameter().connectT(0, add32);        // global_cable32 -> add32::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add33);        // global_cable33 -> add33::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add34);        // global_cable34 -> add34::Value
		global_cable35.getWrappedObject().getParameter().connectT(0, add35);        // global_cable35 -> add35::Value
		global_cable36.getWrappedObject().getParameter().connectT(0, add36);        // global_cable36 -> add36::Value
		global_cable37.getWrappedObject().getParameter().connectT(0, add37);        // global_cable37 -> add37::Value
		global_cable38.getWrappedObject().getParameter().connectT(0, add38);        // global_cable38 -> add38::Value
		global_cable39.getWrappedObject().getParameter().connectT(0, add39);        // global_cable39 -> add39::Value
		cable_table13.getWrappedObject().getParameter().connectT(0, branch5);       // cable_table13 -> branch5::Index
		cable_table14.getWrappedObject().getParameter().connectT(0, input_toggle2); // cable_table14 -> input_toggle2::Input
		peak4.getParameter().connectT(0, input_toggle2);                            // peak4 -> input_toggle2::Value2
		smoothed_parameter.getParameter().connectT(0, sub);                         // smoothed_parameter -> sub::Value
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1);          // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2);          // switcher -> sb2::Bypassed
		switcher_p.getParameterT(2).connectT(0, sb3);          // switcher -> sb3::Bypassed
		switcher_p.getParameterT(3).connectT(0, soft_bypass);  // switcher -> soft_bypass::Bypassed
		switcher_p.getParameterT(4).connectT(0, soft_bypass1); // switcher -> soft_bypass1::Bypassed
		switcher_p.getParameterT(5).connectT(0, sb4);          // switcher -> sb4::Bypassed
		auto& switcher4_p = switcher4.getWrappedObject().getParameter();
		switcher4_p.getParameterT(0).connectT(0, sb15);         // switcher4 -> sb15::Bypassed
		switcher4_p.getParameterT(1).connectT(0, sb16);         // switcher4 -> sb16::Bypassed
		switcher4_p.getParameterT(2).connectT(0, sb17);         // switcher4 -> sb17::Bypassed
		switcher4_p.getParameterT(3).connectT(0, soft_bypass6); // switcher4 -> soft_bypass6::Bypassed
		switcher4_p.getParameterT(4).connectT(0, soft_bypass7); // switcher4 -> soft_bypass7::Bypassed
		switcher4_p.getParameterT(5).connectT(0, sb18);         // switcher4 -> sb18::Bypassed
		smoothed_parameter6.getParameter().connectT(0, sub3);   // smoothed_parameter6 -> sub3::Value
		auto& switcher1_p = switcher1.getWrappedObject().getParameter();
		switcher1_p.getParameterT(0).connectT(0, sb5); // switcher1 -> sb5::Bypassed
		switcher1_p.getParameterT(1).connectT(0, sb6); // switcher1 -> sb6::Bypassed
		
		// Default Values --------------------------------------------------------------------------
		
		pma.setParameterT(0, 0.); // control::pma::Value
		pma.setParameterT(1, 0.); // control::pma::Multiply
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
		
		; // branch2::Index is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // input_toggle1::Input is automated
		; // input_toggle1::Value1 is automated
		; // input_toggle1::Value2 is automated
		
		; // cable_table5::Value is automated
		
		; // cable_table6::Value is automated
		
		;                                        // event_data_reader4::SlotIndex is automated
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // branch4::Index is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add24::Value is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add25::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		; // input_toggle3::Input is automated
		; // input_toggle3::Value1 is automated
		; // input_toggle3::Value2 is automated
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		; // pack_resizer1::NumSliders is automated
		
		; // sliderbank::Value is automated
		
		; // cable_table7::Value is automated
		
		; // cable_table8::Value is automated
		
		;                                        // event_data_reader5::SlotIndex is automated
		event_data_reader5.setParameterT(1, 0.); // routing::event_data_reader::Static
		
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
		
		; // input_toggle4::Input is automated
		; // input_toggle4::Value1 is automated
		; // input_toggle4::Value2 is automated
		
		; // pma8::Value is automated
		; // pma8::Multiply is automated
		; // pma8::Add is automated
		
		;                                        // event_data_reader6::SlotIndex is automated
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // cable_table9::Value is automated
		
		; // cable_table10::Value is automated
		
		; // branch1::Index is automated
		
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
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		;                                        // event_data_reader8::SlotIndex is automated
		event_data_reader8.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // cable_table13::Value is automated
		
		; // cable_table14::Value is automated
		
		; // branch5::Index is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		global_cable34.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		global_cable35.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add35::Value is automated
		
		global_cable36.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add36::Value is automated
		
		global_cable37.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add37::Value is automated
		
		global_cable38.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add38::Value is automated
		
		global_cable39.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add39::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // input_toggle2::Input is automated
		; // input_toggle2::Value1 is automated
		; // input_toggle2::Value2 is automated
		
		; // pma9::Value is automated
		; // pma9::Multiply is automated
		; // pma9::Add is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // xfader::Value is automated
		
		; // switcher1::Value is automated
		
		;                                           // smoothed_parameter::Value is automated
		smoothed_parameter.setParameterT(1, 394.2); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter.setParameterT(2, 1.);    // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter1::Value is automated
		;                                         // smoothed_parameter1::SmoothingTime is automated
		smoothed_parameter1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                           // gain1::Gain is automated
		gain1.setParameterT(1, 0.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.); // core::gain::ResetValue
		
		; // sub::Value is automated
		
		; // expr2::Value is automated
		
		;                           // gain2::Gain is automated
		gain2.setParameterT(1, 0.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.); // core::gain::ResetValue
		
		; // pma10::Value is automated
		; // pma10::Multiply is automated
		; // pma10::Add is automated
		
		; // xfader1::Value is automated
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 20.);   // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // switcher::Value is automated
		
		;                            // svf::Frequency is automated
		;                            // svf::Q is automated
		svf.setParameterT(2, 1.791); // filters::svf::Gain
		svf.setParameterT(3, 0.01);  // filters::svf::Smoothing
		svf.setParameterT(4, 0.);    // filters::svf::Mode
		svf.setParameterT(5, 1.);    // filters::svf::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 1.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf2.setParameterT(4, 2.);   // filters::svf::Mode
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                  // allpass::Frequency is automated
		;                                  // allpass::Q is automated
		allpass.setParameterT(2, 1.30725); // filters::allpass::Gain
		allpass.setParameterT(3, 0.01);    // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);      // filters::allpass::Mode
		allpass.setParameterT(5, 1.);      // filters::allpass::Enabled
		
		;                                // ring_mod::Frequency is automated
		;                                // ring_mod::Q is automated
		ring_mod.setParameterT(2, 0.);   // filters::ring_mod::Gain
		ring_mod.setParameterT(3, 0.01); // filters::ring_mod::Smoothing
		ring_mod.setParameterT(4, 0.);   // filters::ring_mod::Mode
		ring_mod.setParameterT(5, 1.);   // filters::ring_mod::Enabled
		
		;                               // gain17::Gain is automated
		gain17.setParameterT(1, 20.);   // core::gain::Smoothing
		gain17.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // pma13::Value is automated
		; // pma13::Multiply is automated
		; // pma13::Add is automated
		
		; // xfader4::Value is automated
		
		;                               // gain11::Gain is automated
		gain11.setParameterT(1, 20.);   // core::gain::Smoothing
		gain11.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // switcher4::Value is automated
		
		;                             // svf9::Frequency is automated
		;                             // svf9::Q is automated
		svf9.setParameterT(2, 1.791); // filters::svf::Gain
		svf9.setParameterT(3, 0.01);  // filters::svf::Smoothing
		svf9.setParameterT(4, 0.);    // filters::svf::Mode
		svf9.setParameterT(5, 1.);    // filters::svf::Enabled
		
		;                             // svf10::Frequency is automated
		;                             // svf10::Q is automated
		svf10.setParameterT(2, 0.);   // filters::svf::Gain
		svf10.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf10.setParameterT(4, 1.);   // filters::svf::Mode
		svf10.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // svf11::Frequency is automated
		;                             // svf11::Q is automated
		svf11.setParameterT(2, 0.);   // filters::svf::Gain
		svf11.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf11.setParameterT(4, 2.);   // filters::svf::Mode
		svf11.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                   // allpass3::Frequency is automated
		;                                   // allpass3::Q is automated
		allpass3.setParameterT(2, 1.30725); // filters::allpass::Gain
		allpass3.setParameterT(3, 0.01);    // filters::allpass::Smoothing
		allpass3.setParameterT(4, 0.);      // filters::allpass::Mode
		allpass3.setParameterT(5, 1.);      // filters::allpass::Enabled
		
		;                                 // ring_mod3::Frequency is automated
		;                                 // ring_mod3::Q is automated
		ring_mod3.setParameterT(2, 0.);   // filters::ring_mod::Gain
		ring_mod3.setParameterT(3, 0.01); // filters::ring_mod::Smoothing
		ring_mod3.setParameterT(4, 0.);   // filters::ring_mod::Mode
		ring_mod3.setParameterT(5, 1.);   // filters::ring_mod::Enabled
		
		;                               // gain20::Gain is automated
		gain20.setParameterT(1, 20.);   // core::gain::Smoothing
		gain20.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                            // smoothed_parameter6::Value is automated
		smoothed_parameter6.setParameterT(1, 447.4); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter6.setParameterT(2, 1.);    // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter7::Value is automated
		;                                         // smoothed_parameter7::SmoothingTime is automated
		smoothed_parameter7.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain9::Gain is automated
		gain9.setParameterT(1, 0.);    // core::gain::Smoothing
		gain9.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // sub3::Value is automated
		
		; // expr5::Value is automated
		
		;                            // gain10::Gain is automated
		gain10.setParameterT(1, 0.); // core::gain::Smoothing
		gain10.setParameterT(2, 0.); // core::gain::ResetValue
		
		dummy1.setParameterT(0, 1.); // math::mul::Value
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.0572365);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.0578472);
		this->setParameterT(6, 7.3);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 0.060665);
		this->setParameterT(12, 9.2);
		this->setParameterT(13, 0.549376);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.385485);
		this->setParameterT(17, 8.);
		this->setParameterT(18, 0.132719);
		this->setParameterT(19, 0.554803);
		this->setParameterT(20, 0.297646);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 1.);
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
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew6_impl::global_cable8_t<NV>
        getT(2).getT(1).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew6_impl::global_cable9_t<NV>
        getT(2).getT(1).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew6_impl::global_cable10_t<NV>
        getT(2).getT(1).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew6_impl::global_cable11_t<NV>
        getT(2).getT(1).getT(0).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew6_impl::global_cable12_t<NV>
        getT(2).getT(1).getT(0).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew6_impl::global_cable13_t<NV>
        getT(2).getT(1).getT(0).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew6_impl::global_cable14_t<NV>
        getT(2).getT(1).getT(0).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew6_impl::global_cable15_t<NV>
        getT(2).getT(1).getT(0).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew6_impl::global_cable24_t<NV>
        getT(2).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew6_impl::global_cable25_t<NV>
        getT(2).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew6_impl::global_cable26_t<NV>
        getT(2).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew6_impl::global_cable27_t<NV>
        getT(2).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew6_impl::global_cable28_t<NV>
        getT(2).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew6_impl::global_cable29_t<NV>
        getT(2).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew6_impl::global_cable30_t<NV>
        getT(2).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew6_impl::global_cable31_t<NV>
        getT(2).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew6_impl::global_cable16_t<NV>
        getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew6_impl::global_cable17_t<NV>
        getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew6_impl::global_cable18_t<NV>
        getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew6_impl::global_cable19_t<NV>
        getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew6_impl::global_cable20_t<NV>
        getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew6_impl::global_cable21_t<NV>
        getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew6_impl::global_cable22_t<NV>
        getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew6_impl::global_cable23_t<NV>
        getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew6_impl::global_cable_t<NV>
        getT(1).getT(2).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew6_impl::global_cable1_t<NV>
        getT(1).getT(2).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew6_impl::global_cable2_t<NV>
        getT(1).getT(2).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew6_impl::global_cable3_t<NV>
        getT(1).getT(2).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew6_impl::global_cable4_t<NV>
        getT(1).getT(2).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew6_impl::global_cable5_t<NV>
        getT(1).getT(2).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew6_impl::global_cable6_t<NV>
        getT(1).getT(2).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew6_impl::global_cable7_t<NV>
        getT(1).getT(2).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew6_impl::global_cable32_t<NV>
        getT(1).getT(2).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew6_impl::global_cable33_t<NV>
        getT(1).getT(2).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew6_impl::global_cable34_t<NV>
        getT(1).getT(2).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew6_impl::global_cable35_t<NV>
        getT(1).getT(2).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew6_impl::global_cable36_t<NV>
        getT(1).getT(2).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew6_impl::global_cable37_t<NV>
        getT(1).getT(2).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew6_impl::global_cable38_t<NV>
        getT(1).getT(2).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew6_impl::global_cable39_t<NV>
        getT(1).getT(2).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(4).getT(0).setExternalData(b, index);                 // FilterNew6_impl::cable_table11_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).setExternalData(b, index);                 // FilterNew6_impl::cable_table12_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(1).setExternalData(b, index); // FilterNew6_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(0).setExternalData(b, index);         // FilterNew6_impl::cable_table5_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(1).setExternalData(b, index);         // FilterNew6_impl::cable_table6_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).                                                   // FilterNew6_impl::peak3_t<NV>
        getT(0).getT(2).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);                 // FilterNew6_impl::pack_resizer1_t
		this->getT(0).getT(0).getT(2).getT(1).setExternalData(b, index);                 // FilterNew6_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).setExternalData(b, index);                 // FilterNew6_impl::cable_table7_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).setExternalData(b, index);                 // FilterNew6_impl::cable_table8_t<NV>
		this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(1).setExternalData(b, index); // FilterNew6_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).setExternalData(b, index); // FilterNew6_impl::cable_table9_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).setExternalData(b, index); // FilterNew6_impl::cable_table10_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).setExternalData(b, index); // FilterNew6_impl::peak_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0).setExternalData(b, index); // FilterNew6_impl::cable_table13_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(1).setExternalData(b, index); // FilterNew6_impl::cable_table14_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(3).setExternalData(b, index); // FilterNew6_impl::peak4_t<NV>
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
using FilterNew6 = wrap::node<FilterNew6_impl::instance<NV>>;
}


