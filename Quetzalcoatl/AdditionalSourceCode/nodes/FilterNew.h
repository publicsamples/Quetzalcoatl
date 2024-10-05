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

namespace FilterNew_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using sliderbank_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                            parameter::plain<math::add<NV>, 0>, 
                                            parameter::plain<math::add<NV>, 0>, 
                                            parameter::plain<math::add<NV>, 0>, 
                                            parameter::plain<math::add<NV>, 0>, 
                                            parameter::plain<math::add<NV>, 0>, 
                                            parameter::plain<math::add<NV>, 0>, 
                                            parameter::plain<math::add<NV>, 0>>;

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

using cable_table6_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table6_t_data>>;

template <int NV>
using pma7_t = control::pma<NV, 
                            parameter::plain<pma6_t<NV>, 2>>;
template <int NV>
using event_data_reader4_t = wrap::mod<parameter::plain<pma7_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader4_t<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table6_t>, 
                                  split3_t<NV>>;

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

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>>;

template <int NV> using chain93_t = chain67_t<NV>;

template <int NV> using chain92_t = chain67_t<NV>;

template <int NV> using chain91_t = chain67_t<NV>;

template <int NV> using chain90_t = chain67_t<NV>;

template <int NV> using chain89_t = chain67_t<NV>;

template <int NV> using chain88_t = chain67_t<NV>;

template <int NV> using chain79_t = chain67_t<NV>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain67_t<NV>>, 
                                    chain93_t<NV>, 
                                    chain92_t<NV>, 
                                    chain91_t<NV>, 
                                    chain90_t<NV>, 
                                    chain89_t<NV>, 
                                    chain88_t<NV>, 
                                    chain79_t<NV>>;

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
DECLARE_PARAMETER_RANGE(peak5_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using peak5_mod = parameter::from0To1<pma8_t<NV>, 
                                      2, 
                                      peak5_modRange>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch7_t<NV>>, 
                                   peak5_t<NV>>;

template <int NV>
using event_data_reader5_t = wrap::mod<parameter::plain<pma8_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader5_t<NV>>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, pack_resizer1_t>, 
                                  sliderbank_t<NV>, 
                                  chain74_t<NV>, 
                                  split4_t<NV>, 
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
using event_data_reader6_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader6_t<NV>>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, split5_t<NV>>>;

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
using event_data_reader8_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader8_t<NV>>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split8_t<NV>>>;

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

namespace FilterNew_t_parameters
{
// Parameter list for FilterNew_impl::FilterNew_t --------------------------------------------------

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

DECLARE_PARAMETER_RANGE_STEP(_5thParam_InputRange, 
                             1., 
                             7., 
                             1.);

template <int NV>
using _5thParam = parameter::chain<_5thParam_InputRange, 
                                   parameter::plain<FilterNew_impl::switcher_t<NV>, 0>, 
                                   parameter::plain<FilterNew_impl::switcher4_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(GlobalSrc_InputRange, 
                             0., 
                             17., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(GlobalSrc_0Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using GlobalSrc_0 = parameter::from0To1<FilterNew_impl::event_data_reader4_t<NV>, 
                                        0, 
                                        GlobalSrc_0Range>;

template <int NV>
using GlobalSrc = parameter::chain<GlobalSrc_InputRange, 
                                   GlobalSrc_0<NV>, 
                                   parameter::plain<FilterNew_impl::cable_table6_t, 0>>;

template <int NV>
using Stage1 = parameter::chain<ranges::Identity, 
                                parameter::plain<FilterNew_impl::pma10_t<NV>, 2>, 
                                parameter::plain<FilterNew_impl::pma13_t<NV>, 2>>;

template <int NV>
using Stage2 = parameter::chain<ranges::Identity, 
                                parameter::plain<FilterNew_impl::pma10_t<NV>, 1>, 
                                parameter::plain<FilterNew_impl::pma13_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(Stage3_InputRange, 
                             0., 
                             16., 
                             1.);
template <int NV>
using Stage3_2 = parameter::from0To1<FilterNew_impl::event_data_reader7_t<NV>, 
                                     0, 
                                     GlobalSrc_0Range>;

template <int NV>
using Stage3 = parameter::chain<Stage3_InputRange, 
                                parameter::plain<FilterNew_impl::cable_table11_t<NV>, 0>, 
                                parameter::plain<FilterNew_impl::cable_table12_t<NV>, 0>, 
                                Stage3_2<NV>>;

template <int NV>
using FoldSub = parameter::chain<ranges::Identity, 
                                 parameter::plain<FilterNew_impl::branch_t<NV>, 0>, 
                                 parameter::plain<FilterNew_impl::branch6_t<NV>, 0>>;

template <int NV>
using FoldSmooth = parameter::chain<ranges::Identity, 
                                    parameter::plain<FilterNew_impl::smoothed_parameter_t<NV>, 1>, 
                                    parameter::plain<FilterNew_impl::smoothed_parameter6_t<NV>, 1>>;

template <int NV>
using MainParam = parameter::plain<FilterNew_impl::pma7_t<NV>, 
                                   2>;
template <int NV>
using _3rdParam = parameter::plain<FilterNew_impl::event_data_reader6_t<NV>, 
                                   0>;
template <int NV>
using _4thParam = parameter::plain<FilterNew_impl::pma9_t<NV>, 
                                   1>;
template <int NV>
using Global = parameter::plain<FilterNew_impl::pma7_t<NV>, 
                                1>;
template <int NV>
using Vel = parameter::plain<FilterNew_impl::pma3_t<NV>, 
                             1>;
template <int NV>
using Trk = parameter::plain<FilterNew_impl::pma4_t<NV>, 
                             1>;
template <int NV>
using MW = parameter::plain<FilterNew_impl::pma5_t<NV>, 
                            1>;
template <int NV>
using AT = parameter::plain<FilterNew_impl::pma6_t<NV>, 
                            1>;
template <int NV>
using StageMod = parameter::plain<FilterNew_impl::pma8_t<NV>, 
                                  1>;
template <int NV>
using StageModSrc = parameter::plain<FilterNew_impl::event_data_reader5_t<NV>, 
                                     0>;
template <int NV>
using FoldOffset = parameter::plain<FilterNew_impl::pma1_t<NV>, 
                                    2>;
using NumSliders = parameter::plain<FilterNew_impl::pack_resizer1_t, 
                                    0>;
template <int NV>
using Fold = parameter::plain<FilterNew_impl::pma9_t<NV>, 
                              2>;
template <int NV>
using FoldPos = parameter::plain<FilterNew_impl::switcher1_t<NV>, 
                                 0>;
template <int NV>
using RangeMod = parameter::plain<FilterNew_impl::pma1_t<NV>, 
                                  1>;
template <int NV>
using RangeSrx = parameter::plain<FilterNew_impl::event_data_reader8_t<NV>, 
                                  0>;
template <int NV>
using FreqSteps = parameter::plain<FilterNew_impl::minmax2_t<NV>, 
                                   4>;
template <int NV>
using STAGE = parameter::plain<FilterNew_impl::branch7_t<NV>, 
                               0>;
using CutMonoMod = parameter::empty;
using CutMonoSrc = CutMonoMod;
template <int NV>
using FilterNew_t_plist = parameter::list<MainParam<NV>, 
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
                                          FreqSteps<NV>, 
                                          STAGE<NV>, 
                                          CutMonoMod, 
                                          CutMonoSrc>;
}

template <int NV>
using FilterNew_t_ = container::chain<FilterNew_t_parameters::FilterNew_t_plist<NV>, 
                                      wrap::fix<2, modchain_t<NV>>, 
                                      pma9_t<NV>, 
                                      minmax2_t<NV>, 
                                      pma1_t<NV>, 
                                      xfader_t<NV>, 
                                      softbypass_switch3_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public FilterNew_impl::FilterNew_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(FilterNew);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(468)
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
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0xD70A, 0x3D23, 0x195B, 
            0x0000, 0x5300, 0x4154, 0x4547, 0x0000, 0x0000, 0x0000, 0xE000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001A, 
            0x0000, 0x7543, 0x4D74, 0x6E6F, 0x4D6F, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x001B, 0x0000, 0x7543, 0x4D74, 0x6E6F, 0x536F, 0x6372, 
            0x0000, 0x0000, 0x0000, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                           // FilterNew_impl::modchain_t<NV>
		auto& split19 = this->getT(0).getT(0);                                                    // FilterNew_impl::split19_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0);                                                // FilterNew_impl::pma_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(1);                                             // FilterNew_impl::split7_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(1).getT(0);                                     // FilterNew_impl::chain5_t<NV>
		auto& midi = this->getT(0).getT(0).getT(1).getT(0).getT(0);                               // FilterNew_impl::midi_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                               // FilterNew_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(1);                                     // FilterNew_impl::chain6_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                              // FilterNew_impl::midi1_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                               // FilterNew_impl::pma4_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(1).getT(2);                                     // FilterNew_impl::chain9_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(1).getT(2).getT(0);                            // FilterNew_impl::midi_cc_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                               // FilterNew_impl::pma5_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(3);                                    // FilterNew_impl::chain14_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                           // FilterNew_impl::midi_cc1_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                               // FilterNew_impl::pma6_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(1).getT(4);                                    // FilterNew_impl::chain10_t<NV>
		auto& cable_table11 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                      // FilterNew_impl::cable_table11_t<NV>
		auto& cable_table12 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                      // FilterNew_impl::cable_table12_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(1).getT(4).getT(2);                             // FilterNew_impl::split6_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(0);         // FilterNew_impl::event_data_reader7_t<NV>
		auto& chain19 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1);                    // FilterNew_impl::chain19_t<NV>
		auto& branch2 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(0);            // FilterNew_impl::branch2_t<NV>
		auto& chain20 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew_impl::chain20_t<NV>
                        getT(2).getT(1).getT(0).getT(0);
		auto& global_cable8 = this->getT(0).getT(0).getT(1).getT(4).                              // FilterNew_impl::global_cable8_t<NV>
                              getT(2).getT(1).getT(0).getT(0).
                              getT(0);
		auto& add8 = this->getT(0).getT(0).getT(1).getT(4).                                       // math::add<NV>
                     getT(2).getT(1).getT(0).getT(0).
                     getT(1);
		auto& chain21 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew_impl::chain21_t<NV>
                        getT(2).getT(1).getT(0).getT(1);
		auto& global_cable9 = this->getT(0).getT(0).getT(1).getT(4).                              // FilterNew_impl::global_cable9_t<NV>
                              getT(2).getT(1).getT(0).getT(1).
                              getT(0);
		auto& add9 = this->getT(0).getT(0).getT(1).getT(4).                                       // math::add<NV>
                     getT(2).getT(1).getT(0).getT(1).
                     getT(1);
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew_impl::chain22_t<NV>
                        getT(2).getT(1).getT(0).getT(2);
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew_impl::global_cable10_t<NV>
                               getT(2).getT(1).getT(0).getT(2).
                               getT(0);
		auto& add10 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(2).
                      getT(1);
		auto& chain23 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew_impl::chain23_t<NV>
                        getT(2).getT(1).getT(0).getT(3);
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew_impl::global_cable11_t<NV>
                               getT(2).getT(1).getT(0).getT(3).
                               getT(0);
		auto& add11 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(3).
                      getT(1);
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew_impl::chain24_t<NV>
                        getT(2).getT(1).getT(0).getT(4);
		auto& global_cable12 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew_impl::global_cable12_t<NV>
                               getT(2).getT(1).getT(0).getT(4).
                               getT(0);
		auto& add12 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(4).
                      getT(1);
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew_impl::chain26_t<NV>
                        getT(2).getT(1).getT(0).getT(5);
		auto& global_cable13 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew_impl::global_cable13_t<NV>
                               getT(2).getT(1).getT(0).getT(5).
                               getT(0);
		auto& add13 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(5).
                      getT(1);
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew_impl::chain27_t<NV>
                        getT(2).getT(1).getT(0).getT(6);
		auto& global_cable14 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew_impl::global_cable14_t<NV>
                               getT(2).getT(1).getT(0).getT(6).
                               getT(0);
		auto& add14 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(6).
                      getT(1);
		auto& chain28 = this->getT(0).getT(0).getT(1).getT(4).                                    // FilterNew_impl::chain28_t<NV>
                        getT(2).getT(1).getT(0).getT(7);
		auto& global_cable15 = this->getT(0).getT(0).getT(1).getT(4).                             // FilterNew_impl::global_cable15_t<NV>
                               getT(2).getT(1).getT(0).getT(7).
                               getT(0);
		auto& add15 = this->getT(0).getT(0).getT(1).getT(4).                                      // math::add<NV>
                      getT(2).getT(1).getT(0).getT(7).
                      getT(1);
		auto& peak1 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(1);              // FilterNew_impl::peak1_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(2);             // math::clear<NV>
		auto& input_toggle1 = this->getT(0).getT(0).getT(1).getT(4).getT(3);                      // FilterNew_impl::input_toggle1_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(5);                                    // FilterNew_impl::chain25_t<NV>
		auto& chain3 = this->getT(0).getT(0).getT(1).getT(5).getT(0);                             // FilterNew_impl::chain3_t<NV>
		auto& cable_table6 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(0);               // FilterNew_impl::cable_table6_t
		auto& split3 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(1);                     // FilterNew_impl::split3_t<NV>
		auto& event_data_reader4 = this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(1).getT(0); // FilterNew_impl::event_data_reader4_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                               // FilterNew_impl::pma7_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(2);                                             // FilterNew_impl::chain7_t<NV>
		auto& pack_resizer1 = this->getT(0).getT(0).getT(2).getT(0);                              // FilterNew_impl::pack_resizer1_t
		auto& sliderbank = this->getT(0).getT(0).getT(2).getT(1);                                 // FilterNew_impl::sliderbank_t<NV>
		auto& chain74 = this->getT(0).getT(0).getT(2).getT(2);                                    // FilterNew_impl::chain74_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(2).getT(2).getT(0);                            // FilterNew_impl::branch7_t<NV>
		auto& chain67 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(0);                    // FilterNew_impl::chain67_t<NV>
		auto& add40 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(0).getT(0);              // math::add<NV>
		auto& chain93 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(1);                    // FilterNew_impl::chain93_t<NV>
		auto& add47 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(1).getT(0);              // math::add<NV>
		auto& chain92 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(2);                    // FilterNew_impl::chain92_t<NV>
		auto& add46 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(2).getT(0);              // math::add<NV>
		auto& chain91 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(3);                    // FilterNew_impl::chain91_t<NV>
		auto& add45 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(3).getT(0);              // math::add<NV>
		auto& chain90 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(4);                    // FilterNew_impl::chain90_t<NV>
		auto& add44 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(4).getT(0);              // math::add<NV>
		auto& chain89 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(5);                    // FilterNew_impl::chain89_t<NV>
		auto& add43 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(5).getT(0);              // math::add<NV>
		auto& chain88 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(6);                    // FilterNew_impl::chain88_t<NV>
		auto& add42 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(6).getT(0);              // math::add<NV>
		auto& chain79 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(7);                    // FilterNew_impl::chain79_t<NV>
		auto& add41 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(7).getT(0);              // math::add<NV>
		auto& peak5 = this->getT(0).getT(0).getT(2).getT(2).getT(1);                              // FilterNew_impl::peak5_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(2).getT(3);                                     // FilterNew_impl::split4_t<NV>
		auto& event_data_reader5 = this->getT(0).getT(0).getT(2).getT(3).getT(0);                 // FilterNew_impl::event_data_reader5_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(2).getT(4);                                       // FilterNew_impl::pma8_t<NV>
		auto& chain8 = this->getT(0).getT(0).getT(3);                                             // FilterNew_impl::chain8_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(3).getT(0);                                     // FilterNew_impl::split5_t<NV>
		auto& event_data_reader6 = this->getT(0).getT(0).getT(3).getT(0).getT(0);                 // FilterNew_impl::event_data_reader6_t<NV>
		auto& chain48 = this->getT(0).getT(0).getT(4);                                            // FilterNew_impl::chain48_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(4).getT(0);                                     // FilterNew_impl::split8_t<NV>
		auto& event_data_reader8 = this->getT(0).getT(0).getT(4).getT(0).getT(0);                 // FilterNew_impl::event_data_reader8_t<NV>
		auto& pma9 = this->getT(1);                                                               // FilterNew_impl::pma9_t<NV>
		auto& minmax2 = this->getT(2);                                                            // FilterNew_impl::minmax2_t<NV>
		auto& pma1 = this->getT(3);                                                               // FilterNew_impl::pma1_t<NV>
		auto& xfader = this->getT(4);                                                             // FilterNew_impl::xfader_t<NV>
		auto& softbypass_switch3 = this->getT(5);                                                 // FilterNew_impl::softbypass_switch3_t<NV>
		auto& switcher1 = this->getT(5).getT(0);                                                  // FilterNew_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(5).getT(1);                                              // FilterNew_impl::sb_container1_t<NV>
		auto& sb5 = this->getT(5).getT(1).getT(0);                                                // FilterNew_impl::sb5_t<NV>
		auto& split = this->getT(5).getT(1).getT(0).getT(0);                                      // FilterNew_impl::split_t<NV>
		auto& chain4 = this->getT(5).getT(1).getT(0).getT(0).getT(0);                             // FilterNew_impl::chain4_t<NV>
		auto& smoothed_parameter = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(0);         // FilterNew_impl::smoothed_parameter_t<NV>
		auto& split1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(1);                     // FilterNew_impl::split1_t<NV>
		auto& chain2 = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(1).getT(0);             // FilterNew_impl::chain2_t<NV>
		auto& gain1 = this->getT(5).getT(1).getT(0).getT(0).                                      // core::gain<NV>
                      getT(0).getT(1).getT(0).getT(0);
		auto& chain62 = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(1).getT(1);     // FilterNew_impl::chain62_t<NV>
		auto& branch = this->getT(5).getT(1).getT(0).getT(0).                              // FilterNew_impl::branch_t<NV>
                       getT(0).getT(1).getT(1).getT(0);
		auto& chain47 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain47_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(0);
		auto& expr2 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr2>
                      getT(1).getT(1).getT(0).getT(0).getT(0);
		auto& chain61 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain61_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(1);
		auto& expr = this->getT(5).getT(1).getT(0).getT(0).getT(0).                        // math::expr<NV, custom::expr>
                     getT(1).getT(1).getT(0).getT(1).getT(0);
		auto& chain63 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain63_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(2);
		auto& expr1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr1>
                      getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& chain64 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain64_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(3);
		auto& expr3 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr3>
                      getT(1).getT(1).getT(0).getT(3).getT(0);
		auto& chain65 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain65_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(4);
		auto& expr4 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr4>
                      getT(1).getT(1).getT(0).getT(4).getT(0);
		auto& chain66 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain66_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(5);
		auto& expr6 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr6>
                      getT(1).getT(1).getT(0).getT(5).getT(0);
		auto& chain71 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain71_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(6);
		auto& expr11 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr11>
                       getT(1).getT(1).getT(0).getT(6).getT(0);
		auto& chain70 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain70_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(7);
		auto& expr10 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr10>
                       getT(1).getT(1).getT(0).getT(7).getT(0);
		auto& chain73 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain73_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(8);
		auto& expr13 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr13>
                       getT(1).getT(1).getT(0).getT(8).getT(0);
		auto& chain72 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain72_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(9);
		auto& expr12 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr12>
                       getT(1).getT(1).getT(0).getT(9).getT(0);
		auto& chain69 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain69_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(10);
		auto& expr9 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr9>
                      getT(1).getT(1).getT(0).getT(10).getT(0);
		auto& chain68 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::chain68_t<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(11);
		auto& expr8 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr8>
                      getT(1).getT(1).getT(0).getT(11).getT(0);
		auto& gain2 = this->getT(5).getT(1).getT(0).getT(0).                               // core::gain<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& filter1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(2);             // FilterNew_impl::filter1_t<NV>
		auto& dry_path = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(2).getT(0);    // FilterNew_impl::dry_path_t<NV>
		auto& pma10 = this->getT(5).getT(1).getT(0).getT(0).                               // FilterNew_impl::pma10_t<NV>
                      getT(0).getT(2).getT(0).getT(0);
		auto& xfader1 = this->getT(5).getT(1).getT(0).getT(0).                             // FilterNew_impl::xfader1_t<NV>
                        getT(0).getT(2).getT(0).getT(1);
		auto& gain = this->getT(5).getT(1).getT(0).getT(0).                                // core::gain<NV>
                     getT(0).getT(2).getT(0).getT(2);
		auto& wet_path = this->getT(5).getT(1).getT(0).getT(0).getT(0).getT(2).getT(1);    // FilterNew_impl::wet_path_t<NV>
		auto& softbypass_switch5 = this->getT(5).getT(1).getT(0).getT(0).                  // FilterNew_impl::softbypass_switch5_t<NV>
                                   getT(0).getT(2).getT(1).getT(0);
		auto& pma12 = this->getT(5).getT(1).getT(0).getT(0).                               // FilterNew_impl::pma12_t<NV>
                      getT(0).getT(2).getT(1).getT(0).
                      getT(0);
		auto& switcher = this->getT(5).getT(1).getT(0).getT(0).                            // FilterNew_impl::switcher_t<NV>
                         getT(0).getT(2).getT(1).getT(0).
                         getT(1);
		auto& sb_container = this->getT(5).getT(1).getT(0).getT(0).                        // FilterNew_impl::sb_container_t<NV>
                             getT(0).getT(2).getT(1).getT(0).
                             getT(2);
		auto& sb1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // FilterNew_impl::sb1_t<NV>
                    getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& svf = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // filters::svf<NV>
                    getT(2).getT(1).getT(0).getT(2).getT(0).
                    getT(0);
		auto& sb2 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // FilterNew_impl::sb2_t<NV>
                    getT(2).getT(1).getT(0).getT(2).getT(1);
		auto& svf1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                        // filters::svf<NV>
                     getT(2).getT(1).getT(0).getT(2).getT(1).
                     getT(0);
		auto& sb3 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // FilterNew_impl::sb3_t<NV>
                    getT(2).getT(1).getT(0).getT(2).getT(2);
		auto& svf2 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                        // filters::svf<NV>
                     getT(2).getT(1).getT(0).getT(2).getT(2).
                     getT(0);
		auto& soft_bypass = this->getT(5).getT(1).getT(0).getT(0).getT(0).                 // FilterNew_impl::soft_bypass_t<NV>
                            getT(2).getT(1).getT(0).getT(2).getT(3);
		auto& allpass = this->getT(5).getT(1).getT(0).getT(0).getT(0).                     // filters::allpass<NV>
                        getT(2).getT(1).getT(0).getT(2).getT(3).
                        getT(0);
		auto& soft_bypass1 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                // FilterNew_impl::soft_bypass1_t<NV>
                             getT(2).getT(1).getT(0).getT(2).getT(4);
		auto& ring_mod = this->getT(5).getT(1).getT(0).getT(0).getT(0).                    // filters::ring_mod<NV>
                         getT(2).getT(1).getT(0).getT(2).getT(4).
                         getT(0);
		auto& sb4 = this->getT(5).getT(1).getT(0).getT(0).getT(0).                         // FilterNew_impl::sb4_t
                    getT(2).getT(1).getT(0).getT(2).getT(5);
		auto& gain17 = this->getT(5).getT(1).getT(0).getT(0).                              // core::gain<NV>
                       getT(0).getT(2).getT(1).getT(1);
		auto& sb6 = this->getT(5).getT(1).getT(1);                                         // FilterNew_impl::sb6_t<NV>
		auto& split11 = this->getT(5).getT(1).getT(1).getT(0);                             // FilterNew_impl::split11_t<NV>
		auto& chain54 = this->getT(5).getT(1).getT(1).getT(0).getT(0);                     // FilterNew_impl::chain54_t<NV>
		auto& filter4 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(0);             // FilterNew_impl::filter4_t<NV>
		auto& dry_path3 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);   // FilterNew_impl::dry_path3_t<NV>
		auto& pma13 = this->getT(5).getT(1).getT(1).getT(0).                               // FilterNew_impl::pma13_t<NV>
                      getT(0).getT(0).getT(0).getT(0);
		auto& xfader4 = this->getT(5).getT(1).getT(1).getT(0).                             // FilterNew_impl::xfader4_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& gain11 = this->getT(5).getT(1).getT(1).getT(0).                              // core::gain<NV>
                       getT(0).getT(0).getT(0).getT(2);
		auto& wet_path3 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(0).getT(1);   // FilterNew_impl::wet_path3_t<NV>
		auto& softbypass_switch8 = this->getT(5).getT(1).getT(1).getT(0).                  // FilterNew_impl::softbypass_switch8_t<NV>
                                   getT(0).getT(0).getT(1).getT(0);
		auto& pma14 = this->getT(5).getT(1).getT(1).getT(0).                               // FilterNew_impl::pma14_t<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(0);
		auto& switcher4 = this->getT(5).getT(1).getT(1).getT(0).                           // FilterNew_impl::switcher4_t<NV>
                          getT(0).getT(0).getT(1).getT(0).
                          getT(1);
		auto& sb_container4 = this->getT(5).getT(1).getT(1).getT(0).                       // FilterNew_impl::sb_container4_t<NV>
                              getT(0).getT(0).getT(1).getT(0).
                              getT(2);
		auto& sb15 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // FilterNew_impl::sb15_t<NV>
                     getT(0).getT(1).getT(0).getT(2).getT(0);
		auto& svf9 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // filters::svf<NV>
                     getT(0).getT(1).getT(0).getT(2).getT(0).
                     getT(0);
		auto& sb16 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // FilterNew_impl::sb16_t<NV>
                     getT(0).getT(1).getT(0).getT(2).getT(1);
		auto& svf10 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                       // filters::svf<NV>
                      getT(0).getT(1).getT(0).getT(2).getT(1).
                      getT(0);
		auto& sb17 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // FilterNew_impl::sb17_t<NV>
                     getT(0).getT(1).getT(0).getT(2).getT(2);
		auto& svf11 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                       // filters::svf<NV>
                      getT(0).getT(1).getT(0).getT(2).getT(2).
                      getT(0);
		auto& soft_bypass6 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                // FilterNew_impl::soft_bypass6_t<NV>
                             getT(0).getT(1).getT(0).getT(2).getT(3);
		auto& allpass3 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                    // filters::allpass<NV>
                         getT(0).getT(1).getT(0).getT(2).getT(3).
                         getT(0);
		auto& soft_bypass7 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                // FilterNew_impl::soft_bypass7_t<NV>
                             getT(0).getT(1).getT(0).getT(2).getT(4);
		auto& ring_mod3 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                   // filters::ring_mod<NV>
                          getT(0).getT(1).getT(0).getT(2).getT(4).
                          getT(0);
		auto& sb18 = this->getT(5).getT(1).getT(1).getT(0).getT(0).                        // FilterNew_impl::sb18_t
                     getT(0).getT(1).getT(0).getT(2).getT(5);
		auto& gain20 = this->getT(5).getT(1).getT(1).getT(0).                              // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& smoothed_parameter6 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(1); // FilterNew_impl::smoothed_parameter6_t<NV>
		auto& split12 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(2);             // FilterNew_impl::split12_t<NV>
		auto& chain55 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(2).getT(0);     // FilterNew_impl::chain55_t<NV>
		auto& gain9 = this->getT(5).getT(1).getT(1).getT(0).                               // core::gain<NV>
                      getT(0).getT(2).getT(0).getT(0);
		auto& chain56 = this->getT(5).getT(1).getT(1).getT(0).getT(0).getT(2).getT(1); // FilterNew_impl::chain56_t<NV>
		auto& branch6 = this->getT(5).getT(1).getT(1).getT(0).                         // FilterNew_impl::branch6_t<NV>
                        getT(0).getT(2).getT(1).getT(0);
		auto& chain75 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain75_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(0);
		auto& expr14 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr14>
                       getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& chain76 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain76_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(1);
		auto& expr15 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr15>
                       getT(2).getT(1).getT(0).getT(1).getT(0);
		auto& chain77 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain77_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(2);
		auto& expr16 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr16>
                       getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& chain78 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain78_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(3);
		auto& expr17 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr17>
                       getT(2).getT(1).getT(0).getT(3).getT(0);
		auto& chain87 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain87_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(4);
		auto& expr26 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr26>
                       getT(2).getT(1).getT(0).getT(4).getT(0);
		auto& chain80 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain80_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(5);
		auto& expr19 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr19>
                       getT(2).getT(1).getT(0).getT(5).getT(0);
		auto& chain81 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain81_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(6);
		auto& expr20 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr20>
                       getT(2).getT(1).getT(0).getT(6).getT(0);
		auto& chain82 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain82_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(7);
		auto& expr21 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr21>
                       getT(2).getT(1).getT(0).getT(7).getT(0);
		auto& chain83 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain83_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(8);
		auto& expr22 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr22>
                       getT(2).getT(1).getT(0).getT(8).getT(0);
		auto& chain84 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain84_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(9);
		auto& expr23 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr23>
                       getT(2).getT(1).getT(0).getT(9).getT(0);
		auto& chain85 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain85_t<NV>
                        getT(0).getT(2).getT(1).getT(0).
                        getT(10);
		auto& expr24 = this->getT(5).getT(1).getT(1).getT(0).getT(0).  // math::expr<NV, custom::expr24>
                       getT(2).getT(1).getT(0).getT(10).getT(0);
		auto& chain86 = this->getT(5).getT(1).getT(1).getT(0).         // FilterNew_impl::chain86_t<NV>
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
		
		this->getParameterT(2).connectT(0, event_data_reader6); // _3rdParam -> event_data_reader6::SlotIndex
		
		this->getParameterT(3).connectT(0, pma9); // _4thParam -> pma9::Multiply
		
		auto& _5thParam_p = this->getParameterT(4);
		_5thParam_p.connectT(0, switcher);  // _5thParam -> switcher::Value
		_5thParam_p.connectT(1, switcher4); // _5thParam -> switcher4::Value
		
		this->getParameterT(5).connectT(0, pma7); // Global -> pma7::Multiply
		
		auto& GlobalSrc_p = this->getParameterT(6);
		GlobalSrc_p.connectT(0, event_data_reader4); // GlobalSrc -> event_data_reader4::SlotIndex
		GlobalSrc_p.connectT(1, cable_table6);       // GlobalSrc -> cable_table6::Value
		
		this->getParameterT(7).connectT(0, pma3); // Vel -> pma3::Multiply
		
		this->getParameterT(8).connectT(0, pma4); // Trk -> pma4::Multiply
		
		this->getParameterT(9).connectT(0, pma5); // MW -> pma5::Multiply
		
		this->getParameterT(10).connectT(0, pma6); // AT -> pma6::Multiply
		
		this->getParameterT(11).connectT(0, pma8); // StageMod -> pma8::Multiply
		
		this->getParameterT(12).connectT(0, event_data_reader5); // StageModSrc -> event_data_reader5::SlotIndex
		
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
		
		this->getParameterT(22).connectT(0, event_data_reader8); // RangeSrx -> event_data_reader8::SlotIndex
		
		auto& FoldSmooth_p = this->getParameterT(23);
		FoldSmooth_p.connectT(0, smoothed_parameter);  // FoldSmooth -> smoothed_parameter::SmoothingTime
		FoldSmooth_p.connectT(1, smoothed_parameter6); // FoldSmooth -> smoothed_parameter6::SmoothingTime
		
		this->getParameterT(24).connectT(0, minmax2); // FreqSteps -> minmax2::Step
		
		this->getParameterT(25).connectT(0, branch7); // STAGE -> branch7::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, add40);                     // sliderbank -> add40::Value
		sliderbank_p.getParameterT(1).connectT(0, add47);                     // sliderbank -> add47::Value
		sliderbank_p.getParameterT(2).connectT(0, add46);                     // sliderbank -> add46::Value
		sliderbank_p.getParameterT(3).connectT(0, add45);                     // sliderbank -> add45::Value
		sliderbank_p.getParameterT(4).connectT(0, add44);                     // sliderbank -> add44::Value
		sliderbank_p.getParameterT(5).connectT(0, add43);                     // sliderbank -> add43::Value
		sliderbank_p.getParameterT(6).connectT(0, add42);                     // sliderbank -> add42::Value
		sliderbank_p.getParameterT(7).connectT(0, add41);                     // sliderbank -> add41::Value
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
		pma7.getWrappedObject().getParameter().connectT(0, pma6);                   // pma7 -> pma6::Add
		event_data_reader4.getParameter().connectT(0, pma7);                        // event_data_reader4 -> pma7::Value
		pma12.getWrappedObject().getParameter().connectT(0, svf);                   // pma12 -> svf::Frequency
		pma12.getWrappedObject().getParameter().connectT(1, allpass);               // pma12 -> allpass::Frequency
		pma12.getWrappedObject().getParameter().connectT(2, ring_mod);              // pma12 -> ring_mod::Frequency
		pma12.getWrappedObject().getParameter().connectT(3, svf2);                  // pma12 -> svf2::Frequency
		pma12.getWrappedObject().getParameter().connectT(4, svf1);                  // pma12 -> svf1::Frequency
		pma14.getWrappedObject().getParameter().connectT(0, svf9);                  // pma14 -> svf9::Frequency
		pma14.getWrappedObject().getParameter().connectT(1, svf10);                 // pma14 -> svf10::Frequency
		pma14.getWrappedObject().getParameter().connectT(2, svf11);                 // pma14 -> svf11::Frequency
		pma14.getWrappedObject().getParameter().connectT(3, allpass3);              // pma14 -> allpass3::Frequency
		pma14.getWrappedObject().getParameter().connectT(4, ring_mod3);             // pma14 -> ring_mod3::Frequency
		minmax2.getWrappedObject().getParameter().connectT(0, pma12);               // minmax2 -> pma12::Add
		minmax2.getWrappedObject().getParameter().connectT(1, pma14);               // minmax2 -> pma14::Add
		pma8.getWrappedObject().getParameter().connectT(0, minmax2);                // pma8 -> minmax2::Value
		peak5.getParameter().connectT(0, pma8);                                     // peak5 -> pma8::Add
		event_data_reader5.getParameter().connectT(0, pma8);                        // event_data_reader5 -> pma8::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                            // xfader -> gain1::Gain
		xfader_p.getParameterT(0).connectT(1, gain9);                            // xfader -> gain9::Gain
		xfader_p.getParameterT(1).connectT(0, gain2);                            // xfader -> gain2::Gain
		xfader_p.getParameterT(1).connectT(1, gain10);                           // xfader -> gain10::Gain
		pma9.getWrappedObject().getParameter().connectT(0, xfader);              // pma9 -> xfader::Value
		event_data_reader6.getParameter().connectT(0, pma9);                     // event_data_reader6 -> pma9::Value
		smoothed_parameter.getParameter().connectT(0, expr2);                    // smoothed_parameter -> expr2::Value
		smoothed_parameter.getParameter().connectT(1, expr);                     // smoothed_parameter -> expr::Value
		smoothed_parameter.getParameter().connectT(2, expr1);                    // smoothed_parameter -> expr1::Value
		smoothed_parameter.getParameter().connectT(3, expr3);                    // smoothed_parameter -> expr3::Value
		smoothed_parameter.getParameter().connectT(4, expr4);                    // smoothed_parameter -> expr4::Value
		smoothed_parameter.getParameter().connectT(5, expr6);                    // smoothed_parameter -> expr6::Value
		smoothed_parameter.getParameter().connectT(6, expr11);                   // smoothed_parameter -> expr11::Value
		smoothed_parameter.getParameter().connectT(7, expr10);                   // smoothed_parameter -> expr10::Value
		smoothed_parameter.getParameter().connectT(8, expr13);                   // smoothed_parameter -> expr13::Value
		smoothed_parameter.getParameter().connectT(9, expr12);                   // smoothed_parameter -> expr12::Value
		smoothed_parameter.getParameter().connectT(10, expr9);                   // smoothed_parameter -> expr9::Value
		smoothed_parameter.getParameter().connectT(11, expr8);                   // smoothed_parameter -> expr8::Value
		smoothed_parameter6.getParameter().connectT(0, expr14);                  // smoothed_parameter6 -> expr14::Value
		smoothed_parameter6.getParameter().connectT(1, expr15);                  // smoothed_parameter6 -> expr15::Value
		smoothed_parameter6.getParameter().connectT(2, expr16);                  // smoothed_parameter6 -> expr16::Value
		smoothed_parameter6.getParameter().connectT(3, expr17);                  // smoothed_parameter6 -> expr17::Value
		smoothed_parameter6.getParameter().connectT(4, expr19);                  // smoothed_parameter6 -> expr19::Value
		smoothed_parameter6.getParameter().connectT(5, expr20);                  // smoothed_parameter6 -> expr20::Value
		smoothed_parameter6.getParameter().connectT(6, expr21);                  // smoothed_parameter6 -> expr21::Value
		smoothed_parameter6.getParameter().connectT(7, expr22);                  // smoothed_parameter6 -> expr22::Value
		smoothed_parameter6.getParameter().connectT(8, expr23);                  // smoothed_parameter6 -> expr23::Value
		smoothed_parameter6.getParameter().connectT(9, expr24);                  // smoothed_parameter6 -> expr24::Value
		smoothed_parameter6.getParameter().connectT(10, expr25);                 // smoothed_parameter6 -> expr25::Value
		smoothed_parameter6.getParameter().connectT(11, expr26);                 // smoothed_parameter6 -> expr26::Value
		pma1.getWrappedObject().getParameter().connectT(0, smoothed_parameter);  // pma1 -> smoothed_parameter::Value
		pma1.getWrappedObject().getParameter().connectT(1, smoothed_parameter6); // pma1 -> smoothed_parameter6::Value
		event_data_reader8.getParameter().connectT(0, pma1);                     // event_data_reader8 -> pma1::Value
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
		
		pma.setParameterT(0, 0.);         // control::pma::Value
		pma.setParameterT(1, 0.00457422); // control::pma::Multiply
		;                                 // pma::Add is automated
		
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
		
		; // cable_table6::Value is automated
		
		;                                        // event_data_reader4::SlotIndex is automated
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		; // pack_resizer1::NumSliders is automated
		
		; // sliderbank::Value is automated
		
		; // branch7::Index is automated
		
		; // add40::Value is automated
		
		; // add47::Value is automated
		
		; // add46::Value is automated
		
		; // add45::Value is automated
		
		; // add44::Value is automated
		
		; // add43::Value is automated
		
		; // add42::Value is automated
		
		; // add41::Value is automated
		
		;                                        // event_data_reader5::SlotIndex is automated
		event_data_reader5.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // pma8::Value is automated
		; // pma8::Multiply is automated
		; // pma8::Add is automated
		
		;                                        // event_data_reader6::SlotIndex is automated
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		;                                        // event_data_reader8::SlotIndex is automated
		event_data_reader8.setParameterT(1, 0.); // routing::event_data_reader::Static
		
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
		this->setParameterT(25, 1.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 1.);
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
		
		this->getT(0).getT(0).getT(1).getT(4).  // FilterNew_impl::global_cable8_t<NV>
        getT(2).getT(1).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).  // FilterNew_impl::global_cable9_t<NV>
        getT(2).getT(1).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).  // FilterNew_impl::global_cable10_t<NV>
        getT(2).getT(1).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).  // FilterNew_impl::global_cable11_t<NV>
        getT(2).getT(1).getT(0).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).  // FilterNew_impl::global_cable12_t<NV>
        getT(2).getT(1).getT(0).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).  // FilterNew_impl::global_cable13_t<NV>
        getT(2).getT(1).getT(0).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).  // FilterNew_impl::global_cable14_t<NV>
        getT(2).getT(1).getT(0).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).  // FilterNew_impl::global_cable15_t<NV>
        getT(2).getT(1).getT(0).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(4).getT(0).setExternalData(b, index);                 // FilterNew_impl::cable_table11_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).setExternalData(b, index);                 // FilterNew_impl::cable_table12_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(2).getT(1).getT(1).setExternalData(b, index); // FilterNew_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(0).getT(0).setExternalData(b, index);         // FilterNew_impl::cable_table6_t
		this->getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);                         // FilterNew_impl::pack_resizer1_t
		this->getT(0).getT(0).getT(2).getT(1).setExternalData(b, index);                         // FilterNew_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(1).setExternalData(b, index);                 // FilterNew_impl::peak5_t<NV>
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
using FilterNew = wrap::node<FilterNew_impl::instance<NV>>;
}


