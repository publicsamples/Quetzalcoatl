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

namespace FilterNew5_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(pma12_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma12_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                        0, 
                                        pma12_mod_0Range>;

template <int NV>
using pma12_mod_1 = parameter::from0To1<filters::allpass<NV>, 
                                        0, 
                                        pma12_mod_0Range>;

template <int NV>
using pma12_mod_2 = parameter::from0To1<filters::ring_mod<NV>, 
                                        0, 
                                        pma12_mod_0Range>;

template <int NV> using pma12_mod_3 = pma12_mod_0<NV>;

template <int NV> using pma12_mod_4 = pma12_mod_0<NV>;

template <int NV>
using pma12_mod = parameter::chain<ranges::Identity, 
                                   pma12_mod_0<NV>, 
                                   pma12_mod_1<NV>, 
                                   pma12_mod_2<NV>, 
                                   pma12_mod_3<NV>, 
                                   pma12_mod_4<NV>>;

template <int NV>
using pma12_t = control::pma<NV, pma12_mod<NV>>;

template <int NV> using pma14_mod_0 = pma12_mod_0<NV>;

template <int NV> using pma14_mod_1 = pma12_mod_0<NV>;

template <int NV> using pma14_mod_2 = pma12_mod_0<NV>;

template <int NV> using pma14_mod_3 = pma12_mod_1<NV>;

template <int NV> using pma14_mod_4 = pma12_mod_2<NV>;

template <int NV>
using pma14_mod = parameter::chain<ranges::Identity, 
                                   pma14_mod_0<NV>, 
                                   pma14_mod_1<NV>, 
                                   pma14_mod_2<NV>, 
                                   pma14_mod_3<NV>, 
                                   pma14_mod_4<NV>>;

template <int NV>
using pma14_t = control::pma<NV, pma14_mod<NV>>;

template <int NV>
using minmax2_mod = parameter::chain<ranges::Identity, 
                                     parameter::plain<pma12_t<NV>, 2>, 
                                     parameter::plain<pma14_t<NV>, 2>>;

template <int NV>
using minmax2_t = control::minmax<NV, minmax2_mod<NV>>;
template <int NV>
using pma8_t = control::pma<NV, 
                            parameter::plain<minmax2_t<NV>, 0>>;
DECLARE_PARAMETER_RANGE(sliderbank_c4Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using sliderbank_c4 = parameter::from0To1<pma8_t<NV>, 
                                          2, 
                                          sliderbank_c4Range>;

template <int NV>
using sliderbank_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            sliderbank_c4<NV>, 
                                            parameter::empty, 
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
		0.f, 0.f, 0.00225914f, 0.00692308f, 0.0115871f, 0.0162511f,
		0.0209152f, 0.0255791f, 0.0302432f, 0.0349072f, 0.0395712f, 0.0442352f,
		0.0488991f, 0.0535631f, 0.0582272f, 0.0628912f, 0.0675552f, 0.0722192f,
		0.0768832f, 0.0815472f, 0.0862112f, 0.0908751f, 0.0955393f, 0.100203f,
		0.104867f, 0.109531f, 0.114195f, 0.118859f, 0.123523f, 0.128187f,
		0.132851f, 0.137515f, 0.142179f, 0.146843f, 0.151507f, 0.156171f,
		0.160835f, 0.165499f, 0.170163f, 0.174827f, 0.179491f, 0.184155f,
		0.188819f, 0.193483f, 0.198147f, 0.202811f, 0.207475f, 0.212139f,
		0.216803f, 0.221467f, 0.226131f, 0.230795f, 0.235459f, 0.240123f,
		0.244787f, 0.249451f, 0.254115f, 0.258779f, 0.263443f, 0.268107f,
		0.272771f, 0.277435f, 0.282099f, 0.286763f, 0.291427f, 0.296091f,
		0.300755f, 0.305419f, 0.310083f, 0.314747f, 0.319412f, 0.324075f,
		0.328839f, 0.333664f, 0.338489f, 0.343314f, 0.348139f, 0.352963f,
		0.357788f, 0.362613f, 0.367438f, 0.372263f, 0.377088f, 0.381912f,
		0.386737f, 0.391562f, 0.396387f, 0.401212f, 0.406037f, 0.410861f,
		0.415686f, 0.420511f, 0.425336f, 0.430161f, 0.434986f, 0.439811f,
		0.444635f, 0.44946f, 0.454285f, 0.45911f, 0.463935f, 0.468759f,
		0.473584f, 0.478409f, 0.483234f, 0.488059f, 0.492884f, 0.497708f,
		0.502533f, 0.507358f, 0.512183f, 0.517008f, 0.521833f, 0.526657f,
		0.531482f, 0.536307f, 0.541132f, 0.545957f, 0.550782f, 0.555607f,
		0.560431f, 0.565256f, 0.570081f, 0.574906f, 0.579731f, 0.584555f,
		0.58938f, 0.594205f, 0.59903f, 0.603855f, 0.60868f, 0.613504f,
		0.618329f, 0.623154f, 0.627979f, 0.632307f, 0.636464f, 0.64062f,
		0.644777f, 0.648934f, 0.653091f, 0.657247f, 0.661404f, 0.665561f,
		0.669718f, 0.673874f, 0.678031f, 0.682188f, 0.686345f, 0.690502f,
		0.694658f, 0.698815f, 0.702972f, 0.707129f, 0.711285f, 0.715442f,
		0.719599f, 0.723756f, 0.727913f, 0.732069f, 0.736226f, 0.740383f,
		0.74454f, 0.748697f, 0.752853f, 0.75701f, 0.761167f, 0.765324f,
		0.76948f, 0.773637f, 0.777794f, 0.781951f, 0.786107f, 0.790264f,
		0.794421f, 0.798578f, 0.802735f, 0.806891f, 0.811048f, 0.815205f,
		0.819362f, 0.823519f, 0.827675f, 0.831832f, 0.835989f, 0.840146f,
		0.844302f, 0.848459f, 0.852616f, 0.856773f, 0.86093f, 0.865086f,
		0.869243f, 0.8734f, 0.877557f, 0.881714f, 0.88587f, 0.890027f,
		0.894184f, 0.898341f, 0.901551f, 0.904621f, 0.907692f, 0.910762f,
		0.913832f, 0.916903f, 0.919973f, 0.923043f, 0.926114f, 0.929184f,
		0.932254f, 0.935325f, 0.938395f, 0.941465f, 0.944536f, 0.947606f,
		0.950677f, 0.953747f, 0.956817f, 0.959888f, 0.962958f, 0.966028f,
		0.969099f, 0.972169f, 0.975239f, 0.97831f, 0.98138f, 0.98445f,
		0.987521f, 0.990591f, 0.993661f, 0.996732f, 0.999802f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
		0.f, 0.f, 0.f, 0.00214845f, 0.00646228f, 0.010776f,
		0.0150898f, 0.0194036f, 0.0237175f, 0.0280312f, 0.0323451f, 0.0366588f,
		0.0409726f, 0.0452864f, 0.0496001f, 0.0539139f, 0.0582278f, 0.0625416f,
		0.0668554f, 0.0711691f, 0.0754829f, 0.0797967f, 0.0841104f, 0.0884242f,
		0.0927382f, 0.0970519f, 0.101366f, 0.105679f, 0.109993f, 0.114307f,
		0.118621f, 0.122935f, 0.127248f, 0.131562f, 0.135876f, 0.14019f,
		0.144504f, 0.148817f, 0.153131f, 0.157445f, 0.161759f, 0.166073f,
		0.170386f, 0.1747f, 0.179014f, 0.183328f, 0.187641f, 0.191955f,
		0.196269f, 0.200583f, 0.204897f, 0.20921f, 0.213524f, 0.217838f,
		0.222152f, 0.226466f, 0.230779f, 0.235093f, 0.239407f, 0.243721f,
		0.248035f, 0.252348f, 0.256662f, 0.260976f, 0.26529f, 0.269604f,
		0.273917f, 0.278231f, 0.282545f, 0.286859f, 0.291172f, 0.295486f,
		0.2998f, 0.304114f, 0.308428f, 0.312741f, 0.317055f, 0.321369f,
		0.325683f, 0.329997f, 0.33431f, 0.338624f, 0.342938f, 0.347252f,
		0.351566f, 0.355879f, 0.360193f, 0.364507f, 0.368821f, 0.373135f,
		0.377448f, 0.381762f, 0.386076f, 0.39039f, 0.394703f, 0.399017f,
		0.403331f, 0.407645f, 0.411959f, 0.416272f, 0.420586f, 0.4249f,
		0.429214f, 0.433528f, 0.437841f, 0.442155f, 0.446469f, 0.450783f,
		0.455097f, 0.45941f, 0.463429f, 0.467326f, 0.471223f, 0.47512f,
		0.479017f, 0.482914f, 0.486811f, 0.490708f, 0.494605f, 0.498502f,
		0.502399f, 0.506296f, 0.510193f, 0.51409f, 0.517987f, 0.521884f,
		0.525781f, 0.529678f, 0.533575f, 0.537472f, 0.541369f, 0.545266f,
		0.549163f, 0.55306f, 0.556957f, 0.560854f, 0.56553f, 0.570456f,
		0.575381f, 0.580306f, 0.585232f, 0.590157f, 0.595082f, 0.600008f,
		0.604933f, 0.609858f, 0.614784f, 0.619709f, 0.624634f, 0.62956f,
		0.634485f, 0.63941f, 0.644336f, 0.649261f, 0.654187f, 0.659112f,
		0.664037f, 0.668963f, 0.673888f, 0.678813f, 0.683739f, 0.688664f,
		0.693589f, 0.698515f, 0.70344f, 0.708365f, 0.713291f, 0.718216f,
		0.723719f, 0.729348f, 0.734977f, 0.740606f, 0.746235f, 0.751863f,
		0.757492f, 0.763121f, 0.76875f, 0.774379f, 0.780008f, 0.785637f,
		0.791266f, 0.796895f, 0.802524f, 0.808153f, 0.813782f, 0.819411f,
		0.82504f, 0.830669f, 0.836298f, 0.841927f, 0.847556f, 0.853185f,
		0.858814f, 0.864443f, 0.870072f, 0.875701f, 0.88133f, 0.886959f,
		0.891305f, 0.895475f, 0.899644f, 0.903814f, 0.907984f, 0.912153f,
		0.916323f, 0.920492f, 0.924662f, 0.928832f, 0.933001f, 0.937171f,
		0.94134f, 0.94551f, 0.94968f, 0.953849f, 0.958019f, 0.962188f,
		0.966358f, 0.970528f, 0.974697f, 0.978867f, 0.983037f, 0.987206f,
		0.991376f, 0.995545f, 0.999715f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.506836f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
		0.f, 0.f, 0.248535f, 0.749512f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
		return input * Math.sin(Math.PI * 4.0 * value * input) * (1 - Math.PI);
		;
	}
};
}

namespace custom
{

struct expr
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 8.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr1
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 16.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 64.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr4
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 46.0 * value * input) * (1.0f - Math.PI);;
	}
};
}

namespace custom
{

struct expr6
{
	static float op(float input, float value)
	{
		return input * Math.acos(Math.PI * 1.0f * value * input) + Math.sin(Math.PI * 32.0 * value - input) * (1.0f - Math.PI);
		;
	}
};
}

namespace custom
{

struct expr11
{
	static float op(float input, float value)
	{
		return input * Math.acos(Math.PI * 1.0f * value * input) + Math.sin(Math.PI * 32.0 * value - input) * (1.0f - Math.PI);
		;
	}
};
}

namespace custom
{

struct expr10
{
	static float op(float input, float value)
	{
		return input * Math.acos(Math.PI * 1.0f * value * input) + Math.sin(Math.PI * 32.0 * value - input) * (1.0f - Math.PI);;
	}
};
}

namespace custom
{

struct expr13
{
	static float op(float input, float value)
	{
		return input * Math.round(Math.PI * 1.0f * value * input) * (12 - Math.PI) * Math.sin(Math.PI * Math.PI) * (0.5 *  Math.PI);;
	}
};
}

namespace custom
{

struct expr12
{
	static float op(float input, float value)
	{
		return input * Math.round(Math.PI * 1.0f * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr9
{
	static float op(float input, float value)
	{
		return input * Math.acos(Math.PI * 1.0f * value * input) * (1 - Math.PI);
		;
	}
};
}

namespace custom
{

struct expr8
{
	static float op(float input, float value)
	{
		return (1.0f - value) * Math.PI + value * Math.asin(Math.PI * 1.0f * value * input);
		;
	}
};
}

template <int NV>
using smoothed_parameter_mod = parameter::chain<ranges::Identity, 
                                                parameter::plain<math::expr<NV, custom::expr2>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr1>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr3>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr4>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr6>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr11>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr10>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr13>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr12>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr9>, 0>, 
                                                parameter::plain<math::expr<NV, custom::expr8>, 0>>;

template <int NV>
using smoothed_parameter_t = wrap::mod<smoothed_parameter_mod<NV>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

namespace custom
{

struct expr14
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 4.0 * value * input) * (1 - Math.PI);
		;
	}
};
}

namespace custom
{

struct expr15
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 8.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr16
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 16.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr17
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 64.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr19
{
	static float op(float input, float value)
	{
		return input * Math.acos(Math.PI * 1.0f * value * input) + Math.sin(Math.PI * 32.0 * value - input) * (1.0f - Math.PI);
		;
	}
};
}

namespace custom
{

struct expr20
{
	static float op(float input, float value)
	{
		return input * Math.acos(Math.PI * 1.0f * value * input) + Math.sin(Math.PI * 32.0 * value - input) * (1.0f - Math.PI);
		;
	}
};
}

namespace custom
{

struct expr21
{
	static float op(float input, float value)
	{
		return input * Math.acos(Math.PI * 1.0f * value * input) + Math.sin(Math.PI * 32.0 * value - input) * (1.0f - Math.PI);;
	}
};
}

namespace custom
{

struct expr22
{
	static float op(float input, float value)
	{
		return input * Math.round(Math.PI * 1.0f * value * input) * (12 - Math.PI) * Math.sin(Math.PI * Math.PI) * (0.5 *  Math.PI);;
	}
};
}

namespace custom
{

struct expr23
{
	static float op(float input, float value)
	{
		return input * Math.round(Math.PI * 1.0f * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr24
{
	static float op(float input, float value)
	{
		return input * Math.acos(Math.PI * 1.0f * value * input) * (1 - Math.PI);
		;
	}
};
}

namespace custom
{

struct expr25
{
	static float op(float input, float value)
	{
		return (1.0f - value) * Math.PI + value * Math.asin(Math.PI * 1.0f * value * input);
		;
	}
};
}

namespace custom
{

struct expr26
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 48.0 * value * input) * (1.0f - Math.PI);;
	}
};
}

template <int NV>
using smoothed_parameter6_mod = parameter::chain<ranges::Identity, 
                                                 parameter::plain<math::expr<NV, custom::expr14>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr15>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr16>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr17>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr19>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr20>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr21>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr22>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr23>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr24>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr25>, 0>, 
                                                 parameter::plain<math::expr<NV, custom::expr26>, 0>>;

template <int NV>
using smoothed_parameter6_t = wrap::mod<smoothed_parameter6_mod<NV>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<smoothed_parameter_t<NV>, 0>, 
                                  parameter::plain<smoothed_parameter6_t<NV>, 0>>;

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
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr2>>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr>>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr1>>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr3>>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr4>>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr6>>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr11>>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr10>>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr13>>>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr12>>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr9>>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr8>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain47_t<NV>>, 
                                   chain61_t<NV>, 
                                   chain63_t<NV>, 
                                   chain64_t<NV>, 
                                   chain65_t<NV>, 
                                   chain66_t<NV>, 
                                   chain71_t<NV>, 
                                   chain70_t<NV>, 
                                   chain73_t<NV>, 
                                   chain72_t<NV>, 
                                   chain69_t<NV>, 
                                   chain68_t<NV>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain2_t<NV>>, 
                                  chain62_t<NV>>;

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
                                              wrap::fix<2, pma12_t<NV>>, 
                                              switcher_t<NV>, 
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
                                              wrap::fix<2, pma14_t<NV>>, 
                                              switcher4_t<NV>, 
                                              sb_container4_t<NV>>;

template <int NV>
using wet_path3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, softbypass_switch8_t<NV>>, 
                                     core::gain<NV>>;

template <int NV>
using filter4_t = container::split<parameter::empty, 
                                   wrap::fix<2, dry_path3_t<NV>>, 
                                   wet_path3_t<NV>>;

template <int NV> using chain55_t = chain2_t<NV>;

template <int NV>
using chain75_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr14>>>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr15>>>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr16>>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr17>>>;

template <int NV>
using chain87_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr26>>>;

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr19>>>;

template <int NV>
using chain81_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr20>>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr21>>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr22>>>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr23>>>;

template <int NV>
using chain85_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr24>>>;

template <int NV>
using chain86_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr25>>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain75_t<NV>>, 
                                    chain76_t<NV>, 
                                    chain77_t<NV>, 
                                    chain78_t<NV>, 
                                    chain87_t<NV>, 
                                    chain80_t<NV>, 
                                    chain81_t<NV>, 
                                    chain82_t<NV>, 
                                    chain83_t<NV>, 
                                    chain84_t<NV>, 
                                    chain85_t<NV>, 
                                    chain86_t<NV>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch6_t<NV>>, 
                                   core::gain<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain55_t<NV>>, 
                                   chain56_t<NV>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filter4_t<NV>>, 
                                   smoothed_parameter6_t<NV>, 
                                   split12_t<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain54_t<NV>>>;

template <int NV>
using sb6_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, split11_t<NV>>>;

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

namespace FilterNew5_t_parameters
{
// Parameter list for FilterNew5_impl::FilterNew5_t ------------------------------------------------

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
                             1.);
DECLARE_PARAMETER_RANGE_STEP(_3rdParam_0Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using _3rdParam_0 = parameter::from0To1<FilterNew5_impl::event_data_reader6_t<NV>, 
                                        0, 
                                        _3rdParam_0Range>;

template <int NV>
using _3rdParam = parameter::chain<_3rdParam_InputRange, 
                                   _3rdParam_0<NV>, 
                                   parameter::plain<FilterNew5_impl::cable_table9_t<NV>, 0>, 
                                   parameter::plain<FilterNew5_impl::cable_table10_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(_5thParam_InputRange, 
                             1., 
                             7., 
                             1.);

template <int NV>
using _5thParam = parameter::chain<_5thParam_InputRange, 
                                   parameter::plain<FilterNew5_impl::switcher_t<NV>, 0>, 
                                   parameter::plain<FilterNew5_impl::switcher4_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(GlobalSrc_InputRange, 
                             0., 
                             17., 
                             1.);
template <int NV>
using GlobalSrc_0 = parameter::from0To1<FilterNew5_impl::event_data_reader4_t<NV>, 
                                        0, 
                                        _3rdParam_0Range>;

template <int NV>
using GlobalSrc = parameter::chain<GlobalSrc_InputRange, 
                                   GlobalSrc_0<NV>, 
                                   parameter::plain<FilterNew5_impl::cable_table6_t<NV>, 0>, 
                                   parameter::plain<FilterNew5_impl::cable_table5_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(StageModSrc_InputRange, 
                             0., 
                             16., 
                             1.);
template <int NV>
using StageModSrc_0 = parameter::from0To1<FilterNew5_impl::event_data_reader5_t<NV>, 
                                          0, 
                                          _3rdParam_0Range>;

template <int NV>
using StageModSrc = parameter::chain<StageModSrc_InputRange, 
                                     StageModSrc_0<NV>, 
                                     parameter::plain<FilterNew5_impl::cable_table7_t<NV>, 0>, 
                                     parameter::plain<FilterNew5_impl::cable_table8_t<NV>, 0>>;

template <int NV>
using Stage1 = parameter::chain<ranges::Identity, 
                                parameter::plain<FilterNew5_impl::pma10_t<NV>, 2>, 
                                parameter::plain<FilterNew5_impl::pma13_t<NV>, 2>>;

template <int NV>
using Stage2 = parameter::chain<ranges::Identity, 
                                parameter::plain<FilterNew5_impl::pma10_t<NV>, 1>, 
                                parameter::plain<FilterNew5_impl::pma13_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(Stage3_InputRange, 
                             0., 
                             16., 
                             1.);
template <int NV>
using Stage3_2 = parameter::from0To1<FilterNew5_impl::event_data_reader7_t<NV>, 
                                     0, 
                                     _3rdParam_0Range>;

template <int NV>
using Stage3 = parameter::chain<Stage3_InputRange, 
                                parameter::plain<FilterNew5_impl::cable_table11_t<NV>, 0>, 
                                parameter::plain<FilterNew5_impl::cable_table12_t<NV>, 0>, 
                                Stage3_2<NV>>;

template <int NV>
using FoldSub = parameter::chain<ranges::Identity, 
                                 parameter::plain<FilterNew5_impl::branch_t<NV>, 0>, 
                                 parameter::plain<FilterNew5_impl::branch6_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(RangeSrx_InputRange, 
                             0., 
                             16., 
                             1.);
template <int NV>
using RangeSrx_0 = parameter::from0To1<FilterNew5_impl::event_data_reader8_t<NV>, 
                                       0, 
                                       _3rdParam_0Range>;

template <int NV>
using RangeSrx = parameter::chain<RangeSrx_InputRange, 
                                  RangeSrx_0<NV>, 
                                  parameter::plain<FilterNew5_impl::cable_table13_t<NV>, 0>, 
                                  parameter::plain<FilterNew5_impl::cable_table14_t<NV>, 0>>;

template <int NV>
using FoldSmooth = parameter::chain<ranges::Identity, 
                                    parameter::plain<FilterNew5_impl::smoothed_parameter_t<NV>, 1>, 
                                    parameter::plain<FilterNew5_impl::smoothed_parameter6_t<NV>, 1>>;

template <int NV>
using MainParam = parameter::plain<FilterNew5_impl::pma7_t<NV>, 
                                   2>;
template <int NV>
using _4thParam = parameter::plain<FilterNew5_impl::pma9_t<NV>, 
                                   1>;
template <int NV>
using Global = parameter::plain<FilterNew5_impl::pma7_t<NV>, 
                                1>;
template <int NV>
using Vel = parameter::plain<FilterNew5_impl::pma3_t<NV>, 
                             1>;
template <int NV>
using Trk = parameter::plain<FilterNew5_impl::pma4_t<NV>, 
                             1>;
template <int NV>
using MW = parameter::plain<FilterNew5_impl::pma5_t<NV>, 
                            1>;
template <int NV>
using AT = parameter::plain<FilterNew5_impl::pma6_t<NV>, 
                            1>;
template <int NV>
using StageMod = parameter::plain<FilterNew5_impl::pma8_t<NV>, 
                                  1>;
template <int NV>
using FoldOffset = parameter::plain<FilterNew5_impl::pma1_t<NV>, 
                                    2>;
using NumSliders = parameter::plain<FilterNew5_impl::pack_resizer1_t, 
                                    0>;
template <int NV>
using Fold = parameter::plain<FilterNew5_impl::pma9_t<NV>, 
                              2>;
template <int NV>
using FoldPos = parameter::plain<FilterNew5_impl::switcher1_t<NV>, 
                                 0>;
template <int NV>
using RangeMod = parameter::plain<FilterNew5_impl::pma1_t<NV>, 
                                  1>;
template <int NV>
using FreqSteps = parameter::plain<FilterNew5_impl::minmax2_t<NV>, 
                                   4>;
template <int NV>
using FilterNew5_t_plist = parameter::list<MainParam<NV>, 
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
                                           NumSliders, 
                                           Fold<NV>, 
                                           FoldSub<NV>, 
                                           FoldPos<NV>, 
                                           RangeMod<NV>, 
                                           RangeSrx<NV>, 
                                           FoldSmooth<NV>, 
                                           FreqSteps<NV>>;
}

template <int NV>
using FilterNew5_t_ = container::chain<FilterNew5_t_parameters::FilterNew5_t_plist<NV>, 
                                       wrap::fix<2, modchain_t<NV>>, 
                                       pma9_t<NV>, 
                                       minmax2_t<NV>, 
                                       pma1_t<NV>, 
                                       xfader_t<NV>, 
                                       softbypass_switch3_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public FilterNew5_impl::FilterNew5_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(FilterNew5);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(416)
		{
			0x005B, 0x0000, 0x4D00, 0x6961, 0x506E, 0x7261, 0x6D61, 0x0000, 
            0x8000, 0x0024, 0x8000, 0x333F, 0x0C0D, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0001, 0x0000, 0x325F, 0x646E, 0x6150, 0x6172, 
            0x006D, 0x0000, 0x2480, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x5F00, 0x7233, 0x5064, 
            0x7261, 0x6D61, 0x0000, 0x0000, 0x0000, 0x8000, 0x0041, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 0x0000, 0x345F, 
            0x6874, 0x6150, 0x6172, 0x006D, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x6D50, 0x3D19, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 
            0x5F00, 0x7435, 0x5068, 0x7261, 0x6D61, 0x0000, 0x8000, 0x003F, 
            0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0005, 0x0000, 0x6C47, 0x626F, 0x6C61, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x523F, 0xA238, 0x003C, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0006, 0x0000, 0x6C47, 0x626F, 0x6C61, 0x7253, 0x0063, 0x0000, 
            0x0000, 0x0000, 0x4188, 0x999A, 0x40E9, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x075B, 0x0000, 0x5600, 0x6C65, 0x0000, 0x0000, 0x0000, 
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
            0x1333, 0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000D, 0x0000, 
            0x7453, 0x6761, 0x3165, 0x0000, 0x8000, 0x0024, 0x8000, 0xCD3F, 
            0x0CCC, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000E, 0x0000, 
            0x7453, 0x6761, 0x3265, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000F, 0x0000, 
            0x7453, 0x6761, 0x3365, 0x0000, 0x0000, 0x0000, 0x8000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0010, 0x0000, 
            0x6F46, 0x646C, 0x664F, 0x7366, 0x7465, 0x0000, 0x8000, 0x0024, 
            0x8000, 0x353F, 0xA5CA, 0x003D, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0011, 0x0000, 0x754E, 0x536D, 0x696C, 0x6564, 0x7372, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x0043, 0x0000, 0x0041, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0012, 0x0000, 0x6F46, 0x646C, 0x0000, 0x8000, 
            0x0024, 0x8000, 0x003F, 0x8000, 0x0024, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0013, 0x0000, 0x6F46, 0x646C, 0x7553, 0x0062, 0x0000, 
            0x0000, 0x0000, 0x4130, 0x0000, 0x40A0, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x145B, 0x0000, 0x4600, 0x6C6F, 0x5064, 0x736F, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0015, 0x0000, 0x6152, 0x676E, 0x4D65, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0016, 0x0000, 0x6152, 0x676E, 0x5365, 
            0x7872, 0x0000, 0x0000, 0x0000, 0x8000, 0x0041, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0017, 0x0000, 0x6F46, 0x646C, 
            0x6D53, 0x6F6F, 0x6874, 0xCD00, 0xCCCC, 0x003D, 0x7A00, 0xCD44, 
            0xCCCC, 0x003D, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0018, 0x0000, 
            0x7246, 0x7165, 0x7453, 0x7065, 0x0073, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0xD70A, 0x3D23, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                           // FilterNew5_impl::modchain_t<NV>
		auto& split19 = this->getT(0).getT(0);                                                    // FilterNew5_impl::split19_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0);                                                // FilterNew5_impl::pma_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(1);                                             // FilterNew5_impl::split7_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(1).getT(0);                                     // FilterNew5_impl::chain5_t<NV>
		auto& midi = this->getT(0).getT(0).getT(1).getT(0).getT(0);                               // FilterNew5_impl::midi_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                               // FilterNew5_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(1);                                     // FilterNew5_impl::chain6_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                              // FilterNew5_impl::midi1_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                               // FilterNew5_impl::pma4_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(1).getT(2);                                     // FilterNew5_impl::chain9_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(1).getT(2).getT(0);                            // FilterNew5_impl::midi_cc_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                               // FilterNew5_impl::pma5_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(3);                                    // FilterNew5_impl::chain14_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                           // FilterNew5_impl::midi_cc1_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                               // FilterNew5_impl::pma6_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(1).getT(4);                                    // FilterNew5_impl::chain10_t<NV>
		auto& cable_table11 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                      // FilterNew5_impl::cable_table11_t<NV>
		auto& cable_table12 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                      // FilterNew5_impl::cable_table12_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(1).getT(4).getT(2);                             // FilterNew5_impl::split6_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(0);         // FilterNew5_impl::event_data_reader7_t<NV>
		auto& chain19 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1);                    // FilterNew5_impl::chain19_t<NV>
		auto& branch2 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(0);            // FilterNew5_impl::branch2_t<NV>
		auto& chain20 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew5_impl::chain20_t<NV>
                        getT(2).getT(1).getT(0).getT(0);
		auto& global_cable8 = this->getT(0).getT(0).getT(1).getT(4).                              // FilterNew5_impl::global_cable8_t<NV>
                              getT(2).getT(1).getT(0).getT(0).
                              getT(0);
		auto& add8 = this->getT(0).getT(0).getT(1).getT(4).                                       // math::add<NV>
                     getT(2).getT(1).getT(0).getT(0).
                     getT(1);
		auto& chain21 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew5_impl::chain21_t<NV>
                        getT(2).getT(1).getT(0).getT(1);
		auto& global_cable9 = this->getT(0).getT(0).getT(1).getT(4).                              // FilterNew5_impl::global_cable9_t<NV>
                              getT(2).getT(1).getT(0).getT(1).
                              getT(0);
		auto& add9 = this->getT(0).getT(0).getT(1).getT(4).                                       // math::add<NV>
                     getT(2).getT(1).getT(0).getT(1).
                     getT(1);
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew5_impl::chain22_t<NV>
                        getT(2).getT(1).getT(0).getT(2);
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew5_impl::global_cable10_t<NV>
                               getT(2).getT(1).getT(0).getT(2).
                               getT(0);
		auto& add10 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(2).
                      getT(1);
		auto& chain23 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew5_impl::chain23_t<NV>
                        getT(2).getT(1).getT(0).getT(3);
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew5_impl::global_cable11_t<NV>
                               getT(2).getT(1).getT(0).getT(3).
                               getT(0);
		auto& add11 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(3).
                      getT(1);
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew5_impl::chain24_t<NV>
                        getT(2).getT(1).getT(0).getT(4);
		auto& global_cable12 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew5_impl::global_cable12_t<NV>
                               getT(2).getT(1).getT(0).getT(4).
                               getT(0);
		auto& add12 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(4).
                      getT(1);
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew5_impl::chain26_t<NV>
                        getT(2).getT(1).getT(0).getT(5);
		auto& global_cable13 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew5_impl::global_cable13_t<NV>
                               getT(2).getT(1).getT(0).getT(5).
                               getT(0);
		auto& add13 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(5).
                      getT(1);
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew5_impl::chain27_t<NV>
                        getT(2).getT(1).getT(0).getT(6);
		auto& global_cable14 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew5_impl::global_cable14_t<NV>
                               getT(2).getT(1).getT(0).getT(6).
                               getT(0);
		auto& add14 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(6).
                      getT(1);
		auto& chain28 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew5_impl::chain28_t<NV>
                        getT(2).getT(1).getT(0).getT(7);
		auto& global_cable15 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew5_impl::global_cable15_t<NV>
                               getT(2).getT(1).getT(0).getT(7).
                               getT(0);
		auto& add15 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(7).
                      getT(1);
		auto& peak1 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(1);              // FilterNew5_impl::peak1_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(2);             // math::clear<NV>
		auto& input_toggle1 = this->getT(0).getT(0).getT(1).getT(4).getT(3);                      // FilterNew5_impl::input_toggle1_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(5);                                    // FilterNew5_impl::chain25_t<NV>
		auto& chain3 = this->getT(0).getT(0).getT(1).getT(5).getT(0);                             // FilterNew5_impl::chain3_t<NV>
		auto& cable_table5 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(0);               // FilterNew5_impl::cable_table5_t<NV>
		auto& cable_table6 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(1);               // FilterNew5_impl::cable_table6_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(2);                     // FilterNew5_impl::split3_t<NV>
		auto& event_data_reader4 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(2).getT(0); // FilterNew5_impl::event_data_reader4_t<NV>
		auto& chain38 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(2).getT(1);            // FilterNew5_impl::chain38_t<NV>
		auto& branch4 = this->getT(0).getT(0).getT(1).getT(5).                                    // FilterNew5_impl::branch4_t<NV>
                        getT(0).getT(2).getT(1).getT(0);
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew5_impl::chain39_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(0);
		auto& global_cable24 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew5_impl::global_cable24_t<NV>
                               getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& add24 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(0).getT(1);
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew5_impl::chain40_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(1);
		auto& global_cable25 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew5_impl::global_cable25_t<NV>
                               getT(2).getT(1).getT(0).getT(1).getT(0);
		auto& add25 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(1).getT(1);
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew5_impl::chain41_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(2);
		auto& global_cable26 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew5_impl::global_cable26_t<NV>
                               getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& add26 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(2).getT(1);
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew5_impl::chain42_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(3);
		auto& global_cable27 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew5_impl::global_cable27_t<NV>
                               getT(2).getT(1).getT(0).getT(3).getT(0);
		auto& add27 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(3).getT(1);
		auto& chain43 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew5_impl::chain43_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(4);
		auto& global_cable28 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew5_impl::global_cable28_t<NV>
                               getT(2).getT(1).getT(0).getT(4).getT(0);
		auto& add28 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(4).getT(1);
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew5_impl::chain44_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(5);
		auto& global_cable29 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew5_impl::global_cable29_t<NV>
                               getT(2).getT(1).getT(0).getT(5).getT(0);
		auto& add29 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(5).getT(1);
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew5_impl::chain45_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(6);
		auto& global_cable30 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew5_impl::global_cable30_t<NV>
                               getT(2).getT(1).getT(0).getT(6).getT(0);
		auto& add30 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(6).getT(1);
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(5).                             // FilterNew5_impl::chain46_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(7);
		auto& global_cable31 = this->getT(0).getT(0).getT(1).getT(5).getT(0).              // FilterNew5_impl::global_cable31_t<NV>
                               getT(2).getT(1).getT(0).getT(7).getT(0);
		auto& add31 = this->getT(0).getT(0).getT(1).getT(5).getT(0).                       // math::add<NV>
                      getT(2).getT(1).getT(0).getT(7).getT(1);
		auto& peak3 = this->getT(0).getT(0).getT(1).getT(5).                               // FilterNew5_impl::peak3_t<NV>
                      getT(0).getT(2).getT(1).getT(1);
		auto& input_toggle3 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(3);       // FilterNew5_impl::input_toggle3_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                        // FilterNew5_impl::pma7_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(2);                                      // FilterNew5_impl::chain7_t<NV>
		auto& pack_resizer1 = this->getT(0).getT(0).getT(2).getT(0);                       // FilterNew5_impl::pack_resizer1_t
		auto& sliderbank = this->getT(0).getT(0).getT(2).getT(1);                          // FilterNew5_impl::sliderbank_t<NV>
		auto& cable_table7 = this->getT(0).getT(0).getT(2).getT(2);                        // FilterNew5_impl::cable_table7_t<NV>
		auto& cable_table8 = this->getT(0).getT(0).getT(2).getT(3);                        // FilterNew5_impl::cable_table8_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(2).getT(4);                              // FilterNew5_impl::split4_t<NV>
		auto& event_data_reader5 = this->getT(0).getT(0).getT(2).getT(4).getT(0);          // FilterNew5_impl::event_data_reader5_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(2).getT(4).getT(1);                     // FilterNew5_impl::chain29_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0);             // FilterNew5_impl::branch3_t<NV>
		auto& chain30 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(0);     // FilterNew5_impl::chain30_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew5_impl::global_cable16_t<NV>
                               getT(1).getT(0).getT(0).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1);
		auto& chain31 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(1);     // FilterNew5_impl::chain31_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew5_impl::global_cable17_t<NV>
                               getT(1).getT(0).getT(1).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(1).getT(1);
		auto& chain32 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(2);     // FilterNew5_impl::chain32_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew5_impl::global_cable18_t<NV>
                               getT(1).getT(0).getT(2).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(2).getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(3);     // FilterNew5_impl::chain33_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew5_impl::global_cable19_t<NV>
                               getT(1).getT(0).getT(3).getT(0);
		auto& add19 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(3).getT(1);
		auto& chain34 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(4);     // FilterNew5_impl::chain34_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew5_impl::global_cable20_t<NV>
                               getT(1).getT(0).getT(4).getT(0);
		auto& add20 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(4).getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(5);     // FilterNew5_impl::chain35_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew5_impl::global_cable21_t<NV>
                               getT(1).getT(0).getT(5).getT(0);
		auto& add21 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(5).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(6);     // FilterNew5_impl::chain36_t<NV>
		auto& global_cable22 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew5_impl::global_cable22_t<NV>
                               getT(1).getT(0).getT(6).getT(0);
		auto& add22 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(6).getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).getT(7);     // FilterNew5_impl::chain37_t<NV>
		auto& global_cable23 = this->getT(0).getT(0).getT(2).getT(4).                      // FilterNew5_impl::global_cable23_t<NV>
                               getT(1).getT(0).getT(7).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(2).getT(4).                               // math::add<NV>
                      getT(1).getT(0).getT(7).getT(1);
		auto& peak2 = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(1);               // FilterNew5_impl::peak2_t<NV>
		auto& clear = this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(2);               // math::clear<NV>
		auto& input_toggle4 = this->getT(0).getT(0).getT(2).getT(5);                       // FilterNew5_impl::input_toggle4_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(2).getT(6);                                // FilterNew5_impl::pma8_t<NV>
		auto& chain8 = this->getT(0).getT(0).getT(3);                                      // FilterNew5_impl::chain8_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(3).getT(0);                              // FilterNew5_impl::split5_t<NV>
		auto& event_data_reader6 = this->getT(0).getT(0).getT(3).getT(0).getT(0);          // FilterNew5_impl::event_data_reader6_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(3).getT(0).getT(1);                     // FilterNew5_impl::chain11_t<NV>
		auto& cable_table9 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0);        // FilterNew5_impl::cable_table9_t<NV>
		auto& cable_table10 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1);       // FilterNew5_impl::cable_table10_t<NV>
		auto& branch1 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2);             // FilterNew5_impl::branch1_t<NV>
		auto& chain = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(0);       // FilterNew5_impl::chain_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(3).getT(0).                        // FilterNew5_impl::global_cable_t<NV>
                             getT(1).getT(2).getT(0).getT(0);
		auto& add = this->getT(0).getT(0).getT(3).getT(0).                                 // math::add<NV>
                    getT(1).getT(2).getT(0).getT(1);
		auto& chain1 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(1);      // FilterNew5_impl::chain1_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew5_impl::global_cable1_t<NV>
                              getT(1).getT(2).getT(1).getT(0);
		auto& add1 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(1).getT(1);
		auto& chain12 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(2);     // FilterNew5_impl::chain12_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew5_impl::global_cable2_t<NV>
                              getT(1).getT(2).getT(2).getT(0);
		auto& add2 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(2).getT(1);
		auto& chain13 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(3);     // FilterNew5_impl::chain13_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew5_impl::global_cable3_t<NV>
                              getT(1).getT(2).getT(3).getT(0);
		auto& add3 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(3).getT(1);
		auto& chain15 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(4);     // FilterNew5_impl::chain15_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew5_impl::global_cable4_t<NV>
                              getT(1).getT(2).getT(4).getT(0);
		auto& add4 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(4).getT(1);
		auto& chain16 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(5);     // FilterNew5_impl::chain16_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew5_impl::global_cable5_t<NV>
                              getT(1).getT(2).getT(5).getT(0);
		auto& add5 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(5).getT(1);
		auto& chain17 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(6);     // FilterNew5_impl::chain17_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew5_impl::global_cable6_t<NV>
                              getT(1).getT(2).getT(6).getT(0);
		auto& add6 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(6).getT(1);
		auto& chain18 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(2).getT(7);     // FilterNew5_impl::chain18_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(3).getT(0).                       // FilterNew5_impl::global_cable7_t<NV>
                              getT(1).getT(2).getT(7).getT(0);
		auto& add7 = this->getT(0).getT(0).getT(3).getT(0).                                // math::add<NV>
                     getT(1).getT(2).getT(7).getT(1);
		auto& peak = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3);                // FilterNew5_impl::peak_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(4);              // math::clear<NV>
		auto& input_toggle = this->getT(0).getT(0).getT(3).getT(1);                        // FilterNew5_impl::input_toggle_t<NV>
		auto& chain48 = this->getT(0).getT(0).getT(4);                                     // FilterNew5_impl::chain48_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(4).getT(0);                              // FilterNew5_impl::split8_t<NV>
		auto& event_data_reader8 = this->getT(0).getT(0).getT(4).getT(0).getT(0);          // FilterNew5_impl::event_data_reader8_t<NV>
		auto& chain49 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                     // FilterNew5_impl::chain49_t<NV>
		auto& cable_table13 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0);       // FilterNew5_impl::cable_table13_t<NV>
		auto& cable_table14 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(1);       // FilterNew5_impl::cable_table14_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2);             // FilterNew5_impl::branch5_t<NV>
		auto& chain50 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(0);     // FilterNew5_impl::chain50_t<NV>
		auto& global_cable32 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew5_impl::global_cable32_t<NV>
                               getT(1).getT(2).getT(0).getT(0);
		auto& add32 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(0).getT(1);
		auto& chain51 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(1);     // FilterNew5_impl::chain51_t<NV>
		auto& global_cable33 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew5_impl::global_cable33_t<NV>
                               getT(1).getT(2).getT(1).getT(0);
		auto& add33 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(1).getT(1);
		auto& chain52 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(2);     // FilterNew5_impl::chain52_t<NV>
		auto& global_cable34 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew5_impl::global_cable34_t<NV>
                               getT(1).getT(2).getT(2).getT(0);
		auto& add34 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(2).getT(1);
		auto& chain53 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(3);     // FilterNew5_impl::chain53_t<NV>
		auto& global_cable35 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew5_impl::global_cable35_t<NV>
                               getT(1).getT(2).getT(3).getT(0);
		auto& add35 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(3).getT(1);
		auto& chain57 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(4);     // FilterNew5_impl::chain57_t<NV>
		auto& global_cable36 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew5_impl::global_cable36_t<NV>
                               getT(1).getT(2).getT(4).getT(0);
		auto& add36 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(4).getT(1);
		auto& chain58 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(5);     // FilterNew5_impl::chain58_t<NV>
		auto& global_cable37 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew5_impl::global_cable37_t<NV>
                               getT(1).getT(2).getT(5).getT(0);
		auto& add37 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(5).getT(1);
		auto& chain59 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(6);     // FilterNew5_impl::chain59_t<NV>
		auto& global_cable38 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew5_impl::global_cable38_t<NV>
                               getT(1).getT(2).getT(6).getT(0);
		auto& add38 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(6).getT(1);
		auto& chain60 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(2).getT(7);     // FilterNew5_impl::chain60_t<NV>
		auto& global_cable39 = this->getT(0).getT(0).getT(4).getT(0).                      // FilterNew5_impl::global_cable39_t<NV>
                               getT(1).getT(2).getT(7).getT(0);
		auto& add39 = this->getT(0).getT(0).getT(4).getT(0).                               // math::add<NV>
                      getT(1).getT(2).getT(7).getT(1);
		auto& peak4 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(3);               // FilterNew5_impl::peak4_t<NV>
		auto& clear3 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(4);              // math::clear<NV>
		auto& input_toggle2 = this->getT(0).getT(0).getT(4).getT(1);                       // FilterNew5_impl::input_toggle2_t<NV>
		auto& pma9 = this->getT(1);                                                        // FilterNew5_impl::pma9_t<NV>
		auto& minmax2 = this->getT(2);                                                     // FilterNew5_impl::minmax2_t<NV>
		auto& pma1 = this->getT(3);                                                        // FilterNew5_impl::pma1_t<NV>
		auto& xfader = this->getT(4);                                                      // FilterNew5_impl::xfader_t<NV>
		auto& softbypass_switch3 = this->getT(5);                                          // FilterNew5_impl::softbypass_switch3_t<NV>
		auto& switcher1 = this->getT(5).getT(0);                                           // FilterNew5_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(5).getT(1);                                       // FilterNew5_impl::sb_container1_t<NV>
		auto& sb5 = this->getT(5).getT(1).getT(0);                                         // FilterNew5_impl::sb5_t<NV>
		auto& split = this->getT(5).getT(1).getT(0).getT(0);                               // FilterNew5_impl::split_t<NV>
		auto& chain4 = this->getT(5).getT(1).getT(0).getT(0).getT(0);                      // FilterNew5_impl::chain4_t<NV>
		auto& smoothed_parameter = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(0);  // FilterNew5_impl::smoothed_parameter_t<NV>
		auto& split1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(1);              // FilterNew5_impl::split1_t<NV>
		auto& chain2 = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(1).getT(0);      // FilterNew5_impl::chain2_t<NV>
		auto& gain1 = this->getT(5).getT(1).getT(0).getT(0).                               // core::gain<NV>
                      getT(0).getT(1).getT(0).getT(0);
		auto& chain62 = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(1).getT(1);     // FilterNew5_impl::chain62_t<NV>
		auto& branch = this->getT(5).getT(1).getT(0).getT(0).                              // FilterNew5_impl::branch_t<NV>
                       getT(0).getT(1).getT(1).getT(0);
		auto& chain47 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain47_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(0);
		auto& expr2 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr2>
                      getT(1).getT(1).getT(0).getT(0).getT(0);
		auto& chain61 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain61_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(1);
		auto& expr = this->getT(5).getT(1).getT(0).getT(0).getT(0).                        // math::expr<NV, custom::expr>
                     getT(1).getT(1).getT(0).getT(1).getT(0);
		auto& chain63 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain63_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(2);
		auto& expr1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr1>
                      getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& chain64 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain64_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(3);
		auto& expr3 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr3>
                      getT(1).getT(1).getT(0).getT(3).getT(0);
		auto& chain65 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain65_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(4);
		auto& expr4 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr4>
                      getT(1).getT(1).getT(0).getT(4).getT(0);
		auto& chain66 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain66_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(5);
		auto& expr6 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr6>
                      getT(1).getT(1).getT(0).getT(5).getT(0);
		auto& chain71 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain71_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(6);
		auto& expr11 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr11>
                       getT(1).getT(1).getT(0).getT(6).getT(0);
		auto& chain70 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain70_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(7);
		auto& expr10 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr10>
                       getT(1).getT(1).getT(0).getT(7).getT(0);
		auto& chain73 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain73_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(8);
		auto& expr13 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr13>
                       getT(1).getT(1).getT(0).getT(8).getT(0);
		auto& chain72 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain72_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(9);
		auto& expr12 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr12>
                       getT(1).getT(1).getT(0).getT(9).getT(0);
		auto& chain69 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain69_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(10);
		auto& expr9 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr9>
                      getT(1).getT(1).getT(0).getT(10).getT(0);
		auto& chain68 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::chain68_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(11);
		auto& expr8 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr8>
                      getT(1).getT(1).getT(0).getT(11).getT(0);
		auto& gain2 = this->getT(5).getT(1).getT(0).getT(0).                               // core::gain<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& filter1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(2);             // FilterNew5_impl::filter1_t<NV>
		auto& dry_path = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(2).getT(0);    // FilterNew5_impl::dry_path_t<NV>
		auto& pma10 = this->getT(5).getT(1).getT(0).getT(0).                               // FilterNew5_impl::pma10_t<NV>
                      getT(0).getT(2).getT(0).getT(0);
		auto& xfader1 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew5_impl::xfader1_t<NV>
                        getT(0).getT(2).getT(0).getT(1);
		auto& gain = this->getT(5).getT(1).getT(0).getT(0).                                // core::gain<NV>
                     getT(0).getT(2).getT(0).getT(2);
		auto& wet_path = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(2).getT(1);    // FilterNew5_impl::wet_path_t<NV>
		auto& softbypass_switch5 = this->getT(5).getT(1).getT(0).getT(0).                  // FilterNew5_impl::softbypass_switch5_t<NV>
                                   getT(0).getT(2).getT(1).getT(0);
		auto& pma12 = this->getT(5).getT(1).getT(0).getT(0).                               // FilterNew5_impl::pma12_t<NV>
                      getT(0).getT(2).getT(1).getT(0).
                      getT(0);
		auto& switcher = this->getT(5).getT(1).getT(0).getT(0).                            // FilterNew5_impl::switcher_t<NV>
                         getT(0).getT(2).getT(1).getT(0).
                         getT(1);
		auto& sb_container = this->getT(5).getT(1).getT(0).getT(0).                        // FilterNew5_impl::sb_container_t<NV>
                             getT(0).getT(2).getT(1).getT(0).
                             getT(2);
		auto& sb1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // FilterNew5_impl::sb1_t<NV>
                    getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& svf = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // filters::svf<NV>
                    getT(2).getT(1).getT(0).getT(2).getT(0).
                    getT(0);
		auto& sb2 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // FilterNew5_impl::sb2_t<NV>
                    getT(2).getT(1).getT(0).getT(2).getT(1);
		auto& svf1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                        // filters::svf<NV>
                     getT(2).getT(1).getT(0).getT(2).getT(1).
                     getT(0);
		auto& sb3 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // FilterNew5_impl::sb3_t<NV>
                    getT(2).getT(1).getT(0).getT(2).getT(2);
		auto& svf2 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                        // filters::svf<NV>
                     getT(2).getT(1).getT(0).getT(2).getT(2).
                     getT(0);
		auto& soft_bypass = this->getT(5).getT(1).getT(0).getT(0).getT(0).                 // FilterNew5_impl::soft_bypass_t<NV>
                            getT(2).getT(1).getT(0).getT(2).getT(3);
		auto& allpass = this->getT(5).getT(1).getT(0).getT(0).getT(0).                     // filters::allpass<NV>
                        getT(2).getT(1).getT(0).getT(2).getT(3).
                        getT(0);
		auto& soft_bypass1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                // FilterNew5_impl::soft_bypass1_t<NV>
                             getT(2).getT(1).getT(0).getT(2).getT(4);
		auto& ring_mod = this->getT(5).getT(1).getT(0).getT(0).getT(0).                    // filters::ring_mod<NV>
                         getT(2).getT(1).getT(0).getT(2).getT(4).
                         getT(0);
		auto& sb4 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // FilterNew5_impl::sb4_t
                    getT(2).getT(1).getT(0).getT(2).getT(5);
		auto& gain17 = this->getT(5).getT(1).getT(0).getT(0).                              // core::gain<NV>
                       getT(0).getT(2).getT(1).getT(1);
		auto& sb6 = this->getT(5).getT(1).getT(1);                                         // FilterNew5_impl::sb6_t<NV>
		auto& split11 = this->getT(5).getT(1).getT(1).getT(0);                             // FilterNew5_impl::split11_t<NV>
		auto& chain54 = this->getT(5).getT(1).getT(1).getT(0).getT(0);                     // FilterNew5_impl::chain54_t<NV>
		auto& filter4 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(0);             // FilterNew5_impl::filter4_t<NV>
		auto& dry_path3 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);   // FilterNew5_impl::dry_path3_t<NV>
		auto& pma13 = this->getT(5).getT(1).getT(1).getT(0).                               // FilterNew5_impl::pma13_t<NV>
                      getT(0).getT(0).getT(0).getT(0);
		auto& xfader4 = this->getT(5).getT(1).getT(1).getT(0).                             // FilterNew5_impl::xfader4_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& gain11 = this->getT(5).getT(1).getT(1).getT(0).                              // core::gain<NV>
                       getT(0).getT(0).getT(0).getT(2);
		auto& wet_path3 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(0).getT(1);   // FilterNew5_impl::wet_path3_t<NV>
		auto& softbypass_switch8 = this->getT(5).getT(1).getT(1).getT(0).                  // FilterNew5_impl::softbypass_switch8_t<NV>
                                   getT(0).getT(0).getT(1).getT(0);
		auto& pma14 = this->getT(5).getT(1).getT(1).getT(0).                               // FilterNew5_impl::pma14_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(0);
		auto& switcher4 = this->getT(5).getT(1).getT(1).getT(0).                           // FilterNew5_impl::switcher4_t<NV>
                          getT(0).getT(0).getT(1).getT(0).
                          getT(1);
		auto& sb_container4 = this->getT(5).getT(1).getT(1).getT(0).                       // FilterNew5_impl::sb_container4_t<NV>
                              getT(0).getT(0).getT(1).getT(0).
                              getT(2);
		auto& sb15 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // FilterNew5_impl::sb15_t<NV>
                     getT(0).getT(1).getT(0).getT(2).getT(0);
		auto& svf9 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // filters::svf<NV>
                     getT(0).getT(1).getT(0).getT(2).getT(0).
                     getT(0);
		auto& sb16 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // FilterNew5_impl::sb16_t<NV>
                     getT(0).getT(1).getT(0).getT(2).getT(1);
		auto& svf10 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                       // filters::svf<NV>
                      getT(0).getT(1).getT(0).getT(2).getT(1).
                      getT(0);
		auto& sb17 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // FilterNew5_impl::sb17_t<NV>
                     getT(0).getT(1).getT(0).getT(2).getT(2);
		auto& svf11 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                       // filters::svf<NV>
                      getT(0).getT(1).getT(0).getT(2).getT(2).
                      getT(0);
		auto& soft_bypass6 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                // FilterNew5_impl::soft_bypass6_t<NV>
                             getT(0).getT(1).getT(0).getT(2).getT(3);
		auto& allpass3 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                    // filters::allpass<NV>
                         getT(0).getT(1).getT(0).getT(2).getT(3).
                         getT(0);
		auto& soft_bypass7 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                // FilterNew5_impl::soft_bypass7_t<NV>
                             getT(0).getT(1).getT(0).getT(2).getT(4);
		auto& ring_mod3 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                   // filters::ring_mod<NV>
                          getT(0).getT(1).getT(0).getT(2).getT(4).
                          getT(0);
		auto& sb18 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // FilterNew5_impl::sb18_t
                     getT(0).getT(1).getT(0).getT(2).getT(5);
		auto& gain20 = this->getT(5).getT(1).getT(1).getT(0).                              // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& smoothed_parameter6 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(1); // FilterNew5_impl::smoothed_parameter6_t<NV>
		auto& split12 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(2);             // FilterNew5_impl::split12_t<NV>
		auto& chain55 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(2).getT(0);     // FilterNew5_impl::chain55_t<NV>
		auto& gain9 = this->getT(5).getT(1).getT(1).getT(0).                               // core::gain<NV>
                      getT(0).getT(2).getT(0).getT(0);
		auto& chain56 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(2).getT(1); // FilterNew5_impl::chain56_t<NV>
		auto& branch6 = this->getT(5).getT(1).getT(1).getT(0).                         // FilterNew5_impl::branch6_t<NV>
                        getT(0).getT(2).getT(1).getT(0);
		auto& chain75 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain75_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(0);
		auto& expr14 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr14>
                       getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& chain76 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain76_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(1);
		auto& expr15 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr15>
                       getT(2).getT(1).getT(0).getT(1).getT(0);
		auto& chain77 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain77_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(2);
		auto& expr16 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr16>
                       getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& chain78 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain78_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(3);
		auto& expr17 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr17>
                       getT(2).getT(1).getT(0).getT(3).getT(0);
		auto& chain87 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain87_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(4);
		auto& expr26 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr26>
                       getT(2).getT(1).getT(0).getT(4).getT(0);
		auto& chain80 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain80_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(5);
		auto& expr19 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr19>
                       getT(2).getT(1).getT(0).getT(5).getT(0);
		auto& chain81 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain81_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(6);
		auto& expr20 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr20>
                       getT(2).getT(1).getT(0).getT(6).getT(0);
		auto& chain82 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain82_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(7);
		auto& expr21 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr21>
                       getT(2).getT(1).getT(0).getT(7).getT(0);
		auto& chain83 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain83_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(8);
		auto& expr22 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr22>
                       getT(2).getT(1).getT(0).getT(8).getT(0);
		auto& chain84 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain84_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(9);
		auto& expr23 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr23>
                       getT(2).getT(1).getT(0).getT(9).getT(0);
		auto& chain85 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain85_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(10);
		auto& expr24 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr24>
                       getT(2).getT(1).getT(0).getT(10).getT(0);
		auto& chain86 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew5_impl::chain86_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(11);
		auto& expr25 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr25>
                       getT(2).getT(1).getT(0).getT(11).getT(0);
		auto& gain3 = this->getT(5).getT(1).getT(1).getT(0).   // core::gain<NV>
                      getT(0).getT(2).getT(1).getT(1);
		auto& gain10 = this->getT(5).getT(1).getT(1).getT(0).  // core::gain<NV>
                       getT(0).getT(2).getT(1).getT(2);
		
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
		StageModSrc_p.connectT(1, cable_table7);       // StageModSrc -> cable_table7::Value
		StageModSrc_p.connectT(2, cable_table8);       // StageModSrc -> cable_table8::Value
		
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
		
		this->getParameterT(17).connectT(0, pack_resizer1); // NumSliders -> pack_resizer1::NumSliders
		
		this->getParameterT(18).connectT(0, pma9); // Fold -> pma9::Add
		
		auto& FoldSub_p = this->getParameterT(19);
		FoldSub_p.connectT(0, branch);  // FoldSub -> branch::Index
		FoldSub_p.connectT(1, branch6); // FoldSub -> branch6::Index
		
		this->getParameterT(20).connectT(0, switcher1); // FoldPos -> switcher1::Value
		
		this->getParameterT(21).connectT(0, pma1); // RangeMod -> pma1::Multiply
		
		auto& RangeSrx_p = this->getParameterT(22);
		RangeSrx_p.connectT(0, event_data_reader8); // RangeSrx -> event_data_reader8::SlotIndex
		RangeSrx_p.connectT(1, cable_table13);      // RangeSrx -> cable_table13::Value
		RangeSrx_p.connectT(2, cable_table14);      // RangeSrx -> cable_table14::Value
		
		auto& FoldSmooth_p = this->getParameterT(23);
		FoldSmooth_p.connectT(0, smoothed_parameter);  // FoldSmooth -> smoothed_parameter::SmoothingTime
		FoldSmooth_p.connectT(1, smoothed_parameter6); // FoldSmooth -> smoothed_parameter6::SmoothingTime
		
		this->getParameterT(24).connectT(0, minmax2); // FreqSteps -> minmax2::Step
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma12.getWrappedObject().getParameter().connectT(0, svf);       // pma12 -> svf::Frequency
		pma12.getWrappedObject().getParameter().connectT(1, allpass);   // pma12 -> allpass::Frequency
		pma12.getWrappedObject().getParameter().connectT(2, ring_mod);  // pma12 -> ring_mod::Frequency
		pma12.getWrappedObject().getParameter().connectT(3, svf2);      // pma12 -> svf2::Frequency
		pma12.getWrappedObject().getParameter().connectT(4, svf1);      // pma12 -> svf1::Frequency
		pma14.getWrappedObject().getParameter().connectT(0, svf9);      // pma14 -> svf9::Frequency
		pma14.getWrappedObject().getParameter().connectT(1, svf10);     // pma14 -> svf10::Frequency
		pma14.getWrappedObject().getParameter().connectT(2, svf11);     // pma14 -> svf11::Frequency
		pma14.getWrappedObject().getParameter().connectT(3, allpass3);  // pma14 -> allpass3::Frequency
		pma14.getWrappedObject().getParameter().connectT(4, ring_mod3); // pma14 -> ring_mod3::Frequency
		minmax2.getWrappedObject().getParameter().connectT(0, pma12);   // minmax2 -> pma12::Add
		minmax2.getWrappedObject().getParameter().connectT(1, pma14);   // minmax2 -> pma14::Add
		pma8.getWrappedObject().getParameter().connectT(0, minmax2);    // pma8 -> minmax2::Value
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(4).connectT(0, pma8);                      // sliderbank -> pma8::Add
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
		smoothed_parameter.getParameter().connectT(0, expr2);                       // smoothed_parameter -> expr2::Value
		smoothed_parameter.getParameter().connectT(1, expr);                        // smoothed_parameter -> expr::Value
		smoothed_parameter.getParameter().connectT(2, expr1);                       // smoothed_parameter -> expr1::Value
		smoothed_parameter.getParameter().connectT(3, expr3);                       // smoothed_parameter -> expr3::Value
		smoothed_parameter.getParameter().connectT(4, expr4);                       // smoothed_parameter -> expr4::Value
		smoothed_parameter.getParameter().connectT(5, expr6);                       // smoothed_parameter -> expr6::Value
		smoothed_parameter.getParameter().connectT(6, expr11);                      // smoothed_parameter -> expr11::Value
		smoothed_parameter.getParameter().connectT(7, expr10);                      // smoothed_parameter -> expr10::Value
		smoothed_parameter.getParameter().connectT(8, expr13);                      // smoothed_parameter -> expr13::Value
		smoothed_parameter.getParameter().connectT(9, expr12);                      // smoothed_parameter -> expr12::Value
		smoothed_parameter.getParameter().connectT(10, expr9);                      // smoothed_parameter -> expr9::Value
		smoothed_parameter.getParameter().connectT(11, expr8);                      // smoothed_parameter -> expr8::Value
		smoothed_parameter6.getParameter().connectT(0, expr14);                     // smoothed_parameter6 -> expr14::Value
		smoothed_parameter6.getParameter().connectT(1, expr15);                     // smoothed_parameter6 -> expr15::Value
		smoothed_parameter6.getParameter().connectT(2, expr16);                     // smoothed_parameter6 -> expr16::Value
		smoothed_parameter6.getParameter().connectT(3, expr17);                     // smoothed_parameter6 -> expr17::Value
		smoothed_parameter6.getParameter().connectT(4, expr19);                     // smoothed_parameter6 -> expr19::Value
		smoothed_parameter6.getParameter().connectT(5, expr20);                     // smoothed_parameter6 -> expr20::Value
		smoothed_parameter6.getParameter().connectT(6, expr21);                     // smoothed_parameter6 -> expr21::Value
		smoothed_parameter6.getParameter().connectT(7, expr22);                     // smoothed_parameter6 -> expr22::Value
		smoothed_parameter6.getParameter().connectT(8, expr23);                     // smoothed_parameter6 -> expr23::Value
		smoothed_parameter6.getParameter().connectT(9, expr24);                     // smoothed_parameter6 -> expr24::Value
		smoothed_parameter6.getParameter().connectT(10, expr25);                    // smoothed_parameter6 -> expr25::Value
		smoothed_parameter6.getParameter().connectT(11, expr26);                    // smoothed_parameter6 -> expr26::Value
		pma1.getWrappedObject().getParameter().connectT(0, smoothed_parameter);     // pma1 -> smoothed_parameter::Value
		pma1.getWrappedObject().getParameter().connectT(1, smoothed_parameter6);    // pma1 -> smoothed_parameter6::Value
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
		
		;                             // minmax2::Value is automated
		minmax2.setParameterT(1, 0.); // control::minmax::Minimum
		minmax2.setParameterT(2, 1.); // control::minmax::Maximum
		minmax2.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax2::Step is automated
		minmax2.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // xfader::Value is automated
		
		; // switcher1::Value is automated
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                           // gain1::Gain is automated
		gain1.setParameterT(1, 0.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.); // core::gain::ResetValue
		
		; // branch::Index is automated
		
		; // expr2::Value is automated
		
		; // expr::Value is automated
		
		; // expr1::Value is automated
		
		; // expr3::Value is automated
		
		; // expr4::Value is automated
		
		; // expr6::Value is automated
		
		; // expr11::Value is automated
		
		; // expr10::Value is automated
		
		; // expr13::Value is automated
		
		; // expr12::Value is automated
		
		; // expr9::Value is automated
		
		; // expr8::Value is automated
		
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
		
		pma12.setParameterT(0, 0.); // control::pma::Value
		pma12.setParameterT(1, 0.); // control::pma::Multiply
		;                           // pma12::Add is automated
		
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
		
		pma14.setParameterT(0, 0.); // control::pma::Value
		pma14.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma14::Add is automated
		
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
		
		;                                         // smoothed_parameter6::Value is automated
		;                                         // smoothed_parameter6::SmoothingTime is automated
		smoothed_parameter6.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain9::Gain is automated
		gain9.setParameterT(1, 0.);    // core::gain::Smoothing
		gain9.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch6::Index is automated
		
		; // expr14::Value is automated
		
		; // expr15::Value is automated
		
		; // expr16::Value is automated
		
		; // expr17::Value is automated
		
		; // expr26::Value is automated
		
		; // expr19::Value is automated
		
		; // expr20::Value is automated
		
		; // expr21::Value is automated
		
		; // expr22::Value is automated
		
		; // expr23::Value is automated
		
		; // expr24::Value is automated
		
		; // expr25::Value is automated
		
		gain3.setParameterT(0, -8.2); // core::gain::Gain
		gain3.setParameterT(1, 0.);   // core::gain::Smoothing
		gain3.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                               // gain10::Gain is automated
		gain10.setParameterT(1, 0.);    // core::gain::Smoothing
		gain10.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.547076);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.0374578);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.0198022);
		this->setParameterT(6, 7.3);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 0.060665);
		this->setParameterT(12, 9.2);
		this->setParameterT(13, 0.55);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.0809521);
		this->setParameterT(17, 8.);
		this->setParameterT(18, 5.55112e-17);
		this->setParameterT(19, 5.);
		this->setParameterT(20, 0.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 0.1);
		this->setParameterT(24, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew5_impl::global_cable8_t<NV>
        getT(2).getT(1).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew5_impl::global_cable9_t<NV>
        getT(2).getT(1).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew5_impl::global_cable10_t<NV>
        getT(2).getT(1).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew5_impl::global_cable11_t<NV>
        getT(2).getT(1).getT(0).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew5_impl::global_cable12_t<NV>
        getT(2).getT(1).getT(0).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew5_impl::global_cable13_t<NV>
        getT(2).getT(1).getT(0).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew5_impl::global_cable14_t<NV>
        getT(2).getT(1).getT(0).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).          // FilterNew5_impl::global_cable15_t<NV>
        getT(2).getT(1).getT(0).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew5_impl::global_cable24_t<NV>
        getT(2).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew5_impl::global_cable25_t<NV>
        getT(2).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew5_impl::global_cable26_t<NV>
        getT(2).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew5_impl::global_cable27_t<NV>
        getT(2).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew5_impl::global_cable28_t<NV>
        getT(2).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew5_impl::global_cable29_t<NV>
        getT(2).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew5_impl::global_cable30_t<NV>
        getT(2).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(5).getT(0).  // FilterNew5_impl::global_cable31_t<NV>
        getT(2).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew5_impl::global_cable16_t<NV>
        getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew5_impl::global_cable17_t<NV>
        getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew5_impl::global_cable18_t<NV>
        getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew5_impl::global_cable19_t<NV>
        getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew5_impl::global_cable20_t<NV>
        getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew5_impl::global_cable21_t<NV>
        getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew5_impl::global_cable22_t<NV>
        getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(4).  // FilterNew5_impl::global_cable23_t<NV>
        getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew5_impl::global_cable_t<NV>
        getT(1).getT(2).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew5_impl::global_cable1_t<NV>
        getT(1).getT(2).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew5_impl::global_cable2_t<NV>
        getT(1).getT(2).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew5_impl::global_cable3_t<NV>
        getT(1).getT(2).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew5_impl::global_cable4_t<NV>
        getT(1).getT(2).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew5_impl::global_cable5_t<NV>
        getT(1).getT(2).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew5_impl::global_cable6_t<NV>
        getT(1).getT(2).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).  // FilterNew5_impl::global_cable7_t<NV>
        getT(1).getT(2).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew5_impl::global_cable32_t<NV>
        getT(1).getT(2).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew5_impl::global_cable33_t<NV>
        getT(1).getT(2).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew5_impl::global_cable34_t<NV>
        getT(1).getT(2).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew5_impl::global_cable35_t<NV>
        getT(1).getT(2).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew5_impl::global_cable36_t<NV>
        getT(1).getT(2).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew5_impl::global_cable37_t<NV>
        getT(1).getT(2).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew5_impl::global_cable38_t<NV>
        getT(1).getT(2).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).  // FilterNew5_impl::global_cable39_t<NV>
        getT(1).getT(2).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(4).getT(0).setExternalData(b, index);                 // FilterNew5_impl::cable_table11_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).setExternalData(b, index);                 // FilterNew5_impl::cable_table12_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(1).setExternalData(b, index); // FilterNew5_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(0).setExternalData(b, index);         // FilterNew5_impl::cable_table5_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(1).setExternalData(b, index);         // FilterNew5_impl::cable_table6_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).                                                   // FilterNew5_impl::peak3_t<NV>
        getT(0).getT(2).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);                 // FilterNew5_impl::pack_resizer1_t
		this->getT(0).getT(0).getT(2).getT(1).setExternalData(b, index);                 // FilterNew5_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).setExternalData(b, index);                 // FilterNew5_impl::cable_table7_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).setExternalData(b, index);                 // FilterNew5_impl::cable_table8_t<NV>
		this->getT(0).getT(0).getT(2).getT(4).getT(1).getT(1).setExternalData(b, index); // FilterNew5_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).setExternalData(b, index); // FilterNew5_impl::cable_table9_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(1).setExternalData(b, index); // FilterNew5_impl::cable_table10_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).getT(3).setExternalData(b, index); // FilterNew5_impl::peak_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0).setExternalData(b, index); // FilterNew5_impl::cable_table13_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(1).setExternalData(b, index); // FilterNew5_impl::cable_table14_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(3).setExternalData(b, index); // FilterNew5_impl::peak4_t<NV>
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
using FilterNew5 = wrap::node<FilterNew5_impl::instance<NV>>;
}


