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

namespace Pitches_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable24_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>>;
using global_cable25_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>>;
using global_cable26_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>>;
using global_cable27_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>>;
using global_cable28_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   math::add<NV>>;
using global_cable29_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   math::add<NV>>;
using global_cable30_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable30_t<NV>>, 
                                   math::add<NV>>;
using global_cable31_t_index = runtime_target::indexers::fix_hash<104068263>;

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
using h1_sb1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>>;

template <int NV>
using h1_sb1_t = bypass::smoothed<20, h1_sb1_t_<NV>>;
template <int NV>
using h1_switcher_c0 = parameter::bypass<h1_sb1_t<NV>>;

template <int NV> using h1_sb2_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb2_t = bypass::smoothed<20, h1_sb2_t_<NV>>;
template <int NV>
using h1_switcher_c1 = parameter::bypass<h1_sb2_t<NV>>;

template <int NV> using h1_sb3_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb3_t = bypass::smoothed<20, h1_sb3_t_<NV>>;
template <int NV>
using h1_switcher_c2 = parameter::bypass<h1_sb3_t<NV>>;

template <int NV> using h1_sb4_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb4_t = bypass::smoothed<20, h1_sb4_t_<NV>>;
template <int NV>
using h1_switcher_c3 = parameter::bypass<h1_sb4_t<NV>>;

template <int NV> using h1_sb5_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb5_t = bypass::smoothed<20, h1_sb5_t_<NV>>;
template <int NV>
using h1_switcher_c4 = parameter::bypass<h1_sb5_t<NV>>;

template <int NV> using h1_sb6_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb6_t = bypass::smoothed<20, h1_sb6_t_<NV>>;
template <int NV>
using h1_switcher_c5 = parameter::bypass<h1_sb6_t<NV>>;

template <int NV> using h1_sb7_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb7_t = bypass::smoothed<20, h1_sb7_t_<NV>>;
template <int NV>
using h1_switcher_c6 = parameter::bypass<h1_sb7_t<NV>>;

template <int NV> using h1_sb8_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb8_t = bypass::smoothed<20, h1_sb8_t_<NV>>;
template <int NV>
using h1_switcher_c7 = parameter::bypass<h1_sb8_t<NV>>;

template <int NV>
using h1_switcher_multimod = parameter::list<h1_switcher_c0<NV>, 
                                             h1_switcher_c1<NV>, 
                                             h1_switcher_c2<NV>, 
                                             h1_switcher_c3<NV>, 
                                             h1_switcher_c4<NV>, 
                                             h1_switcher_c5<NV>, 
                                             h1_switcher_c6<NV>, 
                                             h1_switcher_c7<NV>>;

template <int NV>
using h1_switcher_t = control::xfader<h1_switcher_multimod<NV>, 
                                      faders::switcher>;

struct h1_cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using h1_cable_table1_t = wrap::data<control::cable_table<parameter::plain<h1_switcher_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table1_t_data>>;

template <int NV>
using h1_sb_container_t = container::chain<parameter::empty, 
                                           wrap::fix<1, h1_sb1_t<NV>>, 
                                           h1_sb2_t<NV>, 
                                           h1_sb3_t<NV>, 
                                           h1_sb4_t<NV>, 
                                           h1_sb5_t<NV>, 
                                           h1_sb6_t<NV>, 
                                           h1_sb7_t<NV>, 
                                           h1_sb8_t<NV>>;

template <int NV>
using h1_softbypass_switch9_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_cable_table1_t<NV>>, 
                                                 h1_switcher_t<NV>, 
                                                 h1_sb_container_t<NV>>;

template <int NV>
using h1_sb17_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch9_t<NV>>>;

template <int NV>
using h1_sb17_t = bypass::smoothed<20, h1_sb17_t_<NV>>;
template <int NV>
using h1_switcher2_c0 = parameter::bypass<h1_sb17_t<NV>>;

template <int NV> using h1_sb9_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb9_t = bypass::smoothed<20, h1_sb9_t_<NV>>;
template <int NV>
using h1_switcher1_c0 = parameter::bypass<h1_sb9_t<NV>>;

template <int NV> using h1_sb10_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb10_t = bypass::smoothed<20, h1_sb10_t_<NV>>;
template <int NV>
using h1_switcher1_c1 = parameter::bypass<h1_sb10_t<NV>>;

template <int NV> using h1_sb11_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb11_t = bypass::smoothed<20, h1_sb11_t_<NV>>;
template <int NV>
using h1_switcher1_c2 = parameter::bypass<h1_sb11_t<NV>>;

template <int NV> using h1_sb12_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb12_t = bypass::smoothed<20, h1_sb12_t_<NV>>;
template <int NV>
using h1_switcher1_c3 = parameter::bypass<h1_sb12_t<NV>>;

template <int NV> using h1_sb13_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb13_t = bypass::smoothed<20, h1_sb13_t_<NV>>;
template <int NV>
using h1_switcher1_c4 = parameter::bypass<h1_sb13_t<NV>>;

template <int NV> using h1_sb14_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb14_t = bypass::smoothed<20, h1_sb14_t_<NV>>;
template <int NV>
using h1_switcher1_c5 = parameter::bypass<h1_sb14_t<NV>>;

template <int NV> using h1_sb15_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb15_t = bypass::smoothed<20, h1_sb15_t_<NV>>;
template <int NV>
using h1_switcher1_c6 = parameter::bypass<h1_sb15_t<NV>>;

template <int NV> using h1_sb16_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb16_t = bypass::smoothed<20, h1_sb16_t_<NV>>;
template <int NV>
using h1_switcher1_c7 = parameter::bypass<h1_sb16_t<NV>>;

template <int NV>
using h1_switcher1_multimod = parameter::list<h1_switcher1_c0<NV>, 
                                              h1_switcher1_c1<NV>, 
                                              h1_switcher1_c2<NV>, 
                                              h1_switcher1_c3<NV>, 
                                              h1_switcher1_c4<NV>, 
                                              h1_switcher1_c5<NV>, 
                                              h1_switcher1_c6<NV>, 
                                              h1_switcher1_c7<NV>>;

template <int NV>
using h1_switcher1_t = control::xfader<h1_switcher1_multimod<NV>, 
                                       faders::switcher>;

struct h1_cable_table2_t_data
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
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table2_t = wrap::data<control::cable_table<parameter::plain<h1_switcher1_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table2_t_data>>;

template <int NV>
using h1_sb_container1_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb9_t<NV>>, 
                                            h1_sb10_t<NV>, 
                                            h1_sb11_t<NV>, 
                                            h1_sb12_t<NV>, 
                                            h1_sb13_t<NV>, 
                                            h1_sb14_t<NV>, 
                                            h1_sb15_t<NV>, 
                                            h1_sb16_t<NV>>;

template <int NV>
using h1_softbypass_switch10_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table2_t<NV>>, 
                                                  h1_switcher1_t<NV>, 
                                                  h1_sb_container1_t<NV>>;

template <int NV>
using h1_sb18_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch10_t<NV>>>;

template <int NV>
using h1_sb18_t = bypass::smoothed<20, h1_sb18_t_<NV>>;
template <int NV>
using h1_switcher2_c1 = parameter::bypass<h1_sb18_t<NV>>;

template <int NV>
using h1_switcher2_multimod = parameter::list<h1_switcher2_c0<NV>, h1_switcher2_c1<NV>>;

template <int NV>
using h1_switcher2_t = control::xfader<h1_switcher2_multimod<NV>, 
                                       faders::switcher>;

template <int NV> using h1_sb47_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb47_t = bypass::smoothed<20, h1_sb47_t_<NV>>;
template <int NV>
using h1_switcher8_c0 = parameter::bypass<h1_sb47_t<NV>>;

template <int NV> using h1_sb48_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb48_t = bypass::smoothed<20, h1_sb48_t_<NV>>;
template <int NV>
using h1_switcher8_c1 = parameter::bypass<h1_sb48_t<NV>>;

template <int NV> using h1_sb49_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb49_t = bypass::smoothed<20, h1_sb49_t_<NV>>;
template <int NV>
using h1_switcher8_c2 = parameter::bypass<h1_sb49_t<NV>>;

template <int NV> using h1_sb50_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb50_t = bypass::smoothed<20, h1_sb50_t_<NV>>;
template <int NV>
using h1_switcher8_c3 = parameter::bypass<h1_sb50_t<NV>>;

template <int NV> using h1_sb51_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb51_t = bypass::smoothed<20, h1_sb51_t_<NV>>;
template <int NV>
using h1_switcher8_c4 = parameter::bypass<h1_sb51_t<NV>>;

template <int NV> using h1_sb52_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb52_t = bypass::smoothed<20, h1_sb52_t_<NV>>;
template <int NV>
using h1_switcher8_c5 = parameter::bypass<h1_sb52_t<NV>>;

template <int NV> using h1_sb53_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb53_t = bypass::smoothed<20, h1_sb53_t_<NV>>;
template <int NV>
using h1_switcher8_c6 = parameter::bypass<h1_sb53_t<NV>>;

template <int NV> using h1_sb54_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb54_t = bypass::smoothed<20, h1_sb54_t_<NV>>;
template <int NV>
using h1_switcher8_c7 = parameter::bypass<h1_sb54_t<NV>>;

template <int NV>
using h1_switcher8_multimod = parameter::list<h1_switcher8_c0<NV>, 
                                              h1_switcher8_c1<NV>, 
                                              h1_switcher8_c2<NV>, 
                                              h1_switcher8_c3<NV>, 
                                              h1_switcher8_c4<NV>, 
                                              h1_switcher8_c5<NV>, 
                                              h1_switcher8_c6<NV>, 
                                              h1_switcher8_c7<NV>>;

template <int NV>
using h1_switcher8_t = control::xfader<h1_switcher8_multimod<NV>, 
                                       faders::switcher>;

struct h1_cable_table6_t_data
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
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table6_t = wrap::data<control::cable_table<parameter::plain<h1_switcher8_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table6_t_data>>;

template <int NV> using h1_sb38_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb38_t = bypass::smoothed<20, h1_sb38_t_<NV>>;
template <int NV>
using h1_switcher7_c0 = parameter::bypass<h1_sb38_t<NV>>;

template <int NV> using h1_sb39_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb39_t = bypass::smoothed<20, h1_sb39_t_<NV>>;
template <int NV>
using h1_switcher7_c1 = parameter::bypass<h1_sb39_t<NV>>;

template <int NV> using h1_sb40_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb40_t = bypass::smoothed<20, h1_sb40_t_<NV>>;
template <int NV>
using h1_switcher7_c2 = parameter::bypass<h1_sb40_t<NV>>;

template <int NV> using h1_sb41_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb41_t = bypass::smoothed<20, h1_sb41_t_<NV>>;
template <int NV>
using h1_switcher7_c3 = parameter::bypass<h1_sb41_t<NV>>;

template <int NV> using h1_sb42_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb42_t = bypass::smoothed<20, h1_sb42_t_<NV>>;
template <int NV>
using h1_switcher7_c4 = parameter::bypass<h1_sb42_t<NV>>;

template <int NV> using h1_sb43_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb43_t = bypass::smoothed<20, h1_sb43_t_<NV>>;
template <int NV>
using h1_switcher7_c5 = parameter::bypass<h1_sb43_t<NV>>;

template <int NV> using h1_sb44_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb44_t = bypass::smoothed<20, h1_sb44_t_<NV>>;
template <int NV>
using h1_switcher7_c6 = parameter::bypass<h1_sb44_t<NV>>;

template <int NV> using h1_sb45_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb45_t = bypass::smoothed<20, h1_sb45_t_<NV>>;
template <int NV>
using h1_switcher7_c7 = parameter::bypass<h1_sb45_t<NV>>;

template <int NV>
using h1_switcher7_multimod = parameter::list<h1_switcher7_c0<NV>, 
                                              h1_switcher7_c1<NV>, 
                                              h1_switcher7_c2<NV>, 
                                              h1_switcher7_c3<NV>, 
                                              h1_switcher7_c4<NV>, 
                                              h1_switcher7_c5<NV>, 
                                              h1_switcher7_c6<NV>, 
                                              h1_switcher7_c7<NV>>;

template <int NV>
using h1_switcher7_t = control::xfader<h1_switcher7_multimod<NV>, 
                                       faders::switcher>;

struct h1_cable_table5_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using h1_cable_table5_t = wrap::data<control::cable_table<parameter::plain<h1_switcher7_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table5_t_data>>;

template <int NV>
using h1_sb_container7_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb38_t<NV>>, 
                                            h1_sb39_t<NV>, 
                                            h1_sb40_t<NV>, 
                                            h1_sb41_t<NV>, 
                                            h1_sb42_t<NV>, 
                                            h1_sb43_t<NV>, 
                                            h1_sb44_t<NV>, 
                                            h1_sb45_t<NV>>;

template <int NV>
using h1_softbypass_switch13_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table5_t<NV>>, 
                                                  h1_switcher7_t<NV>, 
                                                  h1_sb_container7_t<NV>>;

template <int NV>
using h1_sb37_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch13_t<NV>>>;

template <int NV>
using h1_sb37_t = bypass::smoothed<20, h1_sb37_t_<NV>>;
template <int NV>
using h1_switcher6_c0 = parameter::bypass<h1_sb37_t<NV>>;

template <int NV>
using h1_sb_container8_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb47_t<NV>>, 
                                            h1_sb48_t<NV>, 
                                            h1_sb49_t<NV>, 
                                            h1_sb50_t<NV>, 
                                            h1_sb51_t<NV>, 
                                            h1_sb52_t<NV>, 
                                            h1_sb53_t<NV>, 
                                            h1_sb54_t<NV>>;

template <int NV>
using h1_softbypass_switch14_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table6_t<NV>>, 
                                                  h1_switcher8_t<NV>, 
                                                  h1_sb_container8_t<NV>>;

template <int NV>
using h1_sb46_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch14_t<NV>>>;

template <int NV>
using h1_sb46_t = bypass::smoothed<20, h1_sb46_t_<NV>>;
template <int NV>
using h1_switcher6_c1 = parameter::bypass<h1_sb46_t<NV>>;

template <int NV>
using h1_switcher6_multimod = parameter::list<h1_switcher6_c0<NV>, h1_switcher6_c1<NV>>;

template <int NV>
using h1_switcher6_t = control::xfader<h1_switcher6_multimod<NV>, 
                                       faders::switcher>;

template <int NV> using h1_sb56_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb56_t = bypass::smoothed<20, h1_sb56_t_<NV>>;
template <int NV>
using h1_switcher10_c0 = parameter::bypass<h1_sb56_t<NV>>;

template <int NV> using h1_sb57_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb57_t = bypass::smoothed<20, h1_sb57_t_<NV>>;
template <int NV>
using h1_switcher10_c1 = parameter::bypass<h1_sb57_t<NV>>;

template <int NV> using h1_sb58_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb58_t = bypass::smoothed<20, h1_sb58_t_<NV>>;
template <int NV>
using h1_switcher10_c2 = parameter::bypass<h1_sb58_t<NV>>;

template <int NV> using h1_sb59_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb59_t = bypass::smoothed<20, h1_sb59_t_<NV>>;
template <int NV>
using h1_switcher10_c3 = parameter::bypass<h1_sb59_t<NV>>;

template <int NV> using h1_sb60_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb60_t = bypass::smoothed<20, h1_sb60_t_<NV>>;
template <int NV>
using h1_switcher10_c4 = parameter::bypass<h1_sb60_t<NV>>;

template <int NV> using h1_sb61_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb61_t = bypass::smoothed<20, h1_sb61_t_<NV>>;
template <int NV>
using h1_switcher10_c5 = parameter::bypass<h1_sb61_t<NV>>;

template <int NV> using h1_sb62_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb62_t = bypass::smoothed<20, h1_sb62_t_<NV>>;
template <int NV>
using h1_switcher10_c6 = parameter::bypass<h1_sb62_t<NV>>;

template <int NV> using h1_sb63_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb63_t = bypass::smoothed<20, h1_sb63_t_<NV>>;
template <int NV>
using h1_switcher10_c7 = parameter::bypass<h1_sb63_t<NV>>;

template <int NV>
using h1_switcher10_multimod = parameter::list<h1_switcher10_c0<NV>, 
                                               h1_switcher10_c1<NV>, 
                                               h1_switcher10_c2<NV>, 
                                               h1_switcher10_c3<NV>, 
                                               h1_switcher10_c4<NV>, 
                                               h1_switcher10_c5<NV>, 
                                               h1_switcher10_c6<NV>, 
                                               h1_switcher10_c7<NV>>;

template <int NV>
using h1_switcher10_t = control::xfader<h1_switcher10_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table7_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using h1_cable_table7_t = wrap::data<control::cable_table<parameter::plain<h1_switcher10_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table7_t_data>>;

template <int NV>
using h1_sb_container10_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb56_t<NV>>, 
                                             h1_sb57_t<NV>, 
                                             h1_sb58_t<NV>, 
                                             h1_sb59_t<NV>, 
                                             h1_sb60_t<NV>, 
                                             h1_sb61_t<NV>, 
                                             h1_sb62_t<NV>, 
                                             h1_sb63_t<NV>>;

template <int NV>
using h1_softbypass_switch15_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table7_t<NV>>, 
                                                  h1_switcher10_t<NV>, 
                                                  h1_sb_container10_t<NV>>;

template <int NV>
using h1_sb55_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch15_t<NV>>>;

template <int NV>
using h1_sb55_t = bypass::smoothed<20, h1_sb55_t_<NV>>;
template <int NV>
using h1_switcher9_c0 = parameter::bypass<h1_sb55_t<NV>>;

template <int NV> using h1_sb65_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb65_t = bypass::smoothed<20, h1_sb65_t_<NV>>;
template <int NV>
using h1_switcher11_c0 = parameter::bypass<h1_sb65_t<NV>>;

template <int NV> using h1_sb66_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb66_t = bypass::smoothed<20, h1_sb66_t_<NV>>;
template <int NV>
using h1_switcher11_c1 = parameter::bypass<h1_sb66_t<NV>>;

template <int NV> using h1_sb67_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb67_t = bypass::smoothed<20, h1_sb67_t_<NV>>;
template <int NV>
using h1_switcher11_c2 = parameter::bypass<h1_sb67_t<NV>>;

template <int NV> using h1_sb68_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb68_t = bypass::smoothed<20, h1_sb68_t_<NV>>;
template <int NV>
using h1_switcher11_c3 = parameter::bypass<h1_sb68_t<NV>>;

template <int NV> using h1_sb69_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb69_t = bypass::smoothed<20, h1_sb69_t_<NV>>;
template <int NV>
using h1_switcher11_c4 = parameter::bypass<h1_sb69_t<NV>>;

template <int NV> using h1_sb70_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb70_t = bypass::smoothed<20, h1_sb70_t_<NV>>;
template <int NV>
using h1_switcher11_c5 = parameter::bypass<h1_sb70_t<NV>>;

template <int NV> using h1_sb71_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb71_t = bypass::smoothed<20, h1_sb71_t_<NV>>;
template <int NV>
using h1_switcher11_c6 = parameter::bypass<h1_sb71_t<NV>>;

template <int NV> using h1_sb72_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb72_t = bypass::smoothed<20, h1_sb72_t_<NV>>;
template <int NV>
using h1_switcher11_c7 = parameter::bypass<h1_sb72_t<NV>>;

template <int NV>
using h1_switcher11_multimod = parameter::list<h1_switcher11_c0<NV>, 
                                               h1_switcher11_c1<NV>, 
                                               h1_switcher11_c2<NV>, 
                                               h1_switcher11_c3<NV>, 
                                               h1_switcher11_c4<NV>, 
                                               h1_switcher11_c5<NV>, 
                                               h1_switcher11_c6<NV>, 
                                               h1_switcher11_c7<NV>>;

template <int NV>
using h1_switcher11_t = control::xfader<h1_switcher11_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table8_t_data
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
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table8_t = wrap::data<control::cable_table<parameter::plain<h1_switcher11_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table8_t_data>>;

template <int NV>
using h1_sb_container11_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb65_t<NV>>, 
                                             h1_sb66_t<NV>, 
                                             h1_sb67_t<NV>, 
                                             h1_sb68_t<NV>, 
                                             h1_sb69_t<NV>, 
                                             h1_sb70_t<NV>, 
                                             h1_sb71_t<NV>, 
                                             h1_sb72_t<NV>>;

template <int NV>
using h1_softbypass_switch16_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table8_t<NV>>, 
                                                  h1_switcher11_t<NV>, 
                                                  h1_sb_container11_t<NV>>;

template <int NV>
using h1_sb64_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch16_t<NV>>>;

template <int NV>
using h1_sb64_t = bypass::smoothed<20, h1_sb64_t_<NV>>;
template <int NV>
using h1_switcher9_c1 = parameter::bypass<h1_sb64_t<NV>>;

template <int NV>
using h1_switcher9_multimod = parameter::list<h1_switcher9_c0<NV>, h1_switcher9_c1<NV>>;

template <int NV>
using h1_switcher9_t = control::xfader<h1_switcher9_multimod<NV>, 
                                       faders::switcher>;

template <int NV> using h1_sb110_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb110_t = bypass::smoothed<20, h1_sb110_t_<NV>>;
template <int NV>
using h1_switcher19_c0 = parameter::bypass<h1_sb110_t<NV>>;

template <int NV> using h1_sb111_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb111_t = bypass::smoothed<20, h1_sb111_t_<NV>>;
template <int NV>
using h1_switcher19_c1 = parameter::bypass<h1_sb111_t<NV>>;

template <int NV> using h1_sb112_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb112_t = bypass::smoothed<20, h1_sb112_t_<NV>>;
template <int NV>
using h1_switcher19_c2 = parameter::bypass<h1_sb112_t<NV>>;

template <int NV> using h1_sb113_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb113_t = bypass::smoothed<20, h1_sb113_t_<NV>>;
template <int NV>
using h1_switcher19_c3 = parameter::bypass<h1_sb113_t<NV>>;

template <int NV> using h1_sb114_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb114_t = bypass::smoothed<20, h1_sb114_t_<NV>>;
template <int NV>
using h1_switcher19_c4 = parameter::bypass<h1_sb114_t<NV>>;

template <int NV> using h1_sb115_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb115_t = bypass::smoothed<20, h1_sb115_t_<NV>>;
template <int NV>
using h1_switcher19_c5 = parameter::bypass<h1_sb115_t<NV>>;

template <int NV> using h1_sb116_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb116_t = bypass::smoothed<20, h1_sb116_t_<NV>>;
template <int NV>
using h1_switcher19_c6 = parameter::bypass<h1_sb116_t<NV>>;

template <int NV> using h1_sb117_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb117_t = bypass::smoothed<20, h1_sb117_t_<NV>>;
template <int NV>
using h1_switcher19_c7 = parameter::bypass<h1_sb117_t<NV>>;

template <int NV>
using h1_switcher19_multimod = parameter::list<h1_switcher19_c0<NV>, 
                                               h1_switcher19_c1<NV>, 
                                               h1_switcher19_c2<NV>, 
                                               h1_switcher19_c3<NV>, 
                                               h1_switcher19_c4<NV>, 
                                               h1_switcher19_c5<NV>, 
                                               h1_switcher19_c6<NV>, 
                                               h1_switcher19_c7<NV>>;

template <int NV>
using h1_switcher19_t = control::xfader<h1_switcher19_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table13_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using h1_cable_table13_t = wrap::data<control::cable_table<parameter::plain<h1_switcher19_t<NV>, 0>>, 
                                      data::embedded::table<h1_cable_table13_t_data>>;

template <int NV>
using h1_sb_container19_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb110_t<NV>>, 
                                             h1_sb111_t<NV>, 
                                             h1_sb112_t<NV>, 
                                             h1_sb113_t<NV>, 
                                             h1_sb114_t<NV>, 
                                             h1_sb115_t<NV>, 
                                             h1_sb116_t<NV>, 
                                             h1_sb117_t<NV>>;

template <int NV>
using h1_softbypass_switch21_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table13_t<NV>>, 
                                                  h1_switcher19_t<NV>, 
                                                  h1_sb_container19_t<NV>>;

template <int NV>
using h1_sb109_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, h1_softbypass_switch21_t<NV>>>;

template <int NV>
using h1_sb109_t = bypass::smoothed<20, h1_sb109_t_<NV>>;
template <int NV>
using h1_switcher18_c0 = parameter::bypass<h1_sb109_t<NV>>;

template <int NV> using h1_sb119_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb119_t = bypass::smoothed<20, h1_sb119_t_<NV>>;
template <int NV>
using h1_switcher20_c0 = parameter::bypass<h1_sb119_t<NV>>;

template <int NV> using h1_sb120_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb120_t = bypass::smoothed<20, h1_sb120_t_<NV>>;
template <int NV>
using h1_switcher20_c1 = parameter::bypass<h1_sb120_t<NV>>;

template <int NV> using h1_sb121_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb121_t = bypass::smoothed<20, h1_sb121_t_<NV>>;
template <int NV>
using h1_switcher20_c2 = parameter::bypass<h1_sb121_t<NV>>;

template <int NV> using h1_sb122_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb122_t = bypass::smoothed<20, h1_sb122_t_<NV>>;
template <int NV>
using h1_switcher20_c3 = parameter::bypass<h1_sb122_t<NV>>;

template <int NV> using h1_sb123_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb123_t = bypass::smoothed<20, h1_sb123_t_<NV>>;
template <int NV>
using h1_switcher20_c4 = parameter::bypass<h1_sb123_t<NV>>;

template <int NV> using h1_sb124_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb124_t = bypass::smoothed<20, h1_sb124_t_<NV>>;
template <int NV>
using h1_switcher20_c5 = parameter::bypass<h1_sb124_t<NV>>;

template <int NV> using h1_sb125_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb125_t = bypass::smoothed<20, h1_sb125_t_<NV>>;
template <int NV>
using h1_switcher20_c6 = parameter::bypass<h1_sb125_t<NV>>;

template <int NV> using h1_sb126_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb126_t = bypass::smoothed<20, h1_sb126_t_<NV>>;
template <int NV>
using h1_switcher20_c7 = parameter::bypass<h1_sb126_t<NV>>;

template <int NV>
using h1_switcher20_multimod = parameter::list<h1_switcher20_c0<NV>, 
                                               h1_switcher20_c1<NV>, 
                                               h1_switcher20_c2<NV>, 
                                               h1_switcher20_c3<NV>, 
                                               h1_switcher20_c4<NV>, 
                                               h1_switcher20_c5<NV>, 
                                               h1_switcher20_c6<NV>, 
                                               h1_switcher20_c7<NV>>;

template <int NV>
using h1_switcher20_t = control::xfader<h1_switcher20_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table14_t_data
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
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table14_t = wrap::data<control::cable_table<parameter::plain<h1_switcher20_t<NV>, 0>>, 
                                      data::embedded::table<h1_cable_table14_t_data>>;

template <int NV>
using h1_sb_container20_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb119_t<NV>>, 
                                             h1_sb120_t<NV>, 
                                             h1_sb121_t<NV>, 
                                             h1_sb122_t<NV>, 
                                             h1_sb123_t<NV>, 
                                             h1_sb124_t<NV>, 
                                             h1_sb125_t<NV>, 
                                             h1_sb126_t<NV>>;

template <int NV>
using h1_softbypass_switch22_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table14_t<NV>>, 
                                                  h1_switcher20_t<NV>, 
                                                  h1_sb_container20_t<NV>>;

template <int NV>
using h1_sb118_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, h1_softbypass_switch22_t<NV>>>;

template <int NV>
using h1_sb118_t = bypass::smoothed<20, h1_sb118_t_<NV>>;
template <int NV>
using h1_switcher18_c1 = parameter::bypass<h1_sb118_t<NV>>;

template <int NV>
using h1_switcher18_multimod = parameter::list<h1_switcher18_c0<NV>, h1_switcher18_c1<NV>>;

template <int NV>
using h1_switcher18_t = control::xfader<h1_switcher18_multimod<NV>, 
                                        faders::switcher>;

template <int NV> using h1_sb74_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb74_t = bypass::smoothed<20, h1_sb74_t_<NV>>;
template <int NV>
using h1_switcher13_c0 = parameter::bypass<h1_sb74_t<NV>>;

template <int NV> using h1_sb75_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb75_t = bypass::smoothed<20, h1_sb75_t_<NV>>;
template <int NV>
using h1_switcher13_c1 = parameter::bypass<h1_sb75_t<NV>>;

template <int NV> using h1_sb76_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb76_t = bypass::smoothed<20, h1_sb76_t_<NV>>;
template <int NV>
using h1_switcher13_c2 = parameter::bypass<h1_sb76_t<NV>>;

template <int NV> using h1_sb77_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb77_t = bypass::smoothed<20, h1_sb77_t_<NV>>;
template <int NV>
using h1_switcher13_c3 = parameter::bypass<h1_sb77_t<NV>>;

template <int NV> using h1_sb78_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb78_t = bypass::smoothed<20, h1_sb78_t_<NV>>;
template <int NV>
using h1_switcher13_c4 = parameter::bypass<h1_sb78_t<NV>>;

template <int NV> using h1_sb79_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb79_t = bypass::smoothed<20, h1_sb79_t_<NV>>;
template <int NV>
using h1_switcher13_c5 = parameter::bypass<h1_sb79_t<NV>>;

template <int NV> using h1_sb80_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb80_t = bypass::smoothed<20, h1_sb80_t_<NV>>;
template <int NV>
using h1_switcher13_c6 = parameter::bypass<h1_sb80_t<NV>>;

template <int NV> using h1_sb81_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb81_t = bypass::smoothed<20, h1_sb81_t_<NV>>;
template <int NV>
using h1_switcher13_c7 = parameter::bypass<h1_sb81_t<NV>>;

template <int NV>
using h1_switcher13_multimod = parameter::list<h1_switcher13_c0<NV>, 
                                               h1_switcher13_c1<NV>, 
                                               h1_switcher13_c2<NV>, 
                                               h1_switcher13_c3<NV>, 
                                               h1_switcher13_c4<NV>, 
                                               h1_switcher13_c5<NV>, 
                                               h1_switcher13_c6<NV>, 
                                               h1_switcher13_c7<NV>>;

template <int NV>
using h1_switcher13_t = control::xfader<h1_switcher13_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table9_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00392926f, 0.00785851f, 0.0117877f, 0.015717f, 0.0196462f,
		0.0235755f, 0.0275047f, 0.0314339f, 0.0353632f, 0.0392925f, 0.0432217f,
		0.0471509f, 0.0510802f, 0.0550094f, 0.0589386f, 0.0628679f, 0.0667971f,
		0.0707264f, 0.0746557f, 0.0785848f, 0.0825141f, 0.0864434f, 0.0903726f,
		0.0943018f, 0.0982311f, 0.10216f, 0.10609f, 0.110019f, 0.113948f,
		0.117877f, 0.121807f, 0.125736f, 0.129665f, 0.133594f, 0.137524f,
		0.141453f, 0.145382f, 0.149311f, 0.15324f, 0.15717f, 0.161099f,
		0.165028f, 0.168957f, 0.172887f, 0.176816f, 0.180745f, 0.184674f,
		0.188604f, 0.192533f, 0.196462f, 0.200391f, 0.204321f, 0.20825f,
		0.212179f, 0.216108f, 0.220038f, 0.223967f, 0.227896f, 0.231825f,
		0.235755f, 0.239684f, 0.243613f, 0.247542f, 0.251472f, 0.255401f,
		0.25933f, 0.263259f, 0.267189f, 0.271118f, 0.275047f, 0.278976f,
		0.282905f, 0.286835f, 0.290764f, 0.294693f, 0.298622f, 0.302552f,
		0.306481f, 0.31041f, 0.314339f, 0.318269f, 0.322198f, 0.326127f,
		0.330056f, 0.333986f, 0.337915f, 0.341844f, 0.345773f, 0.349703f,
		0.353632f, 0.357561f, 0.36149f, 0.36542f, 0.369349f, 0.373278f,
		0.377207f, 0.381137f, 0.385066f, 0.388995f, 0.392924f, 0.396854f,
		0.400783f, 0.404712f, 0.408641f, 0.412571f, 0.4165f, 0.420429f,
		0.424358f, 0.428288f, 0.432217f, 0.436146f, 0.440075f, 0.444004f,
		0.447934f, 0.451863f, 0.455792f, 0.459721f, 0.463651f, 0.46758f,
		0.471509f, 0.475438f, 0.479368f, 0.483297f, 0.487226f, 0.491155f,
		0.495085f, 0.499014f, 0.502943f, 0.506872f, 0.510802f, 0.514731f,
		0.51866f, 0.522589f, 0.526519f, 0.530448f, 0.534377f, 0.538306f,
		0.542236f, 0.546165f, 0.550094f, 0.554023f, 0.557953f, 0.561882f,
		0.565811f, 0.56974f, 0.57367f, 0.577599f, 0.581528f, 0.585457f,
		0.589386f, 0.593316f, 0.597245f, 0.601174f, 0.605103f, 0.609033f,
		0.612962f, 0.616891f, 0.62082f, 0.62475f, 0.628679f, 0.632608f,
		0.636537f, 0.640467f, 0.644396f, 0.648325f, 0.652254f, 0.656184f,
		0.660113f, 0.664042f, 0.667971f, 0.671901f, 0.67583f, 0.679759f,
		0.683688f, 0.687618f, 0.691547f, 0.695476f, 0.699405f, 0.703335f,
		0.707264f, 0.711193f, 0.715122f, 0.719051f, 0.722981f, 0.72691f,
		0.730839f, 0.734769f, 0.738698f, 0.742627f, 0.746556f, 0.750485f,
		0.754415f, 0.758344f, 0.762273f, 0.766202f, 0.770132f, 0.774061f,
		0.77799f, 0.781919f, 0.785849f, 0.789778f, 0.793707f, 0.797636f,
		0.801566f, 0.805495f, 0.809424f, 0.813353f, 0.817283f, 0.821212f,
		0.825141f, 0.82907f, 0.833f, 0.836929f, 0.840858f, 0.844787f,
		0.848716f, 0.852646f, 0.856575f, 0.860504f, 0.864433f, 0.868363f,
		0.872292f, 0.876221f, 0.88015f, 0.88408f, 0.888009f, 0.891938f,
		0.895867f, 0.899797f, 0.903726f, 0.907655f, 0.911584f, 0.915514f,
		0.919443f, 0.923372f, 0.927301f, 0.931231f, 0.93516f, 0.939089f,
		0.943018f, 0.946948f, 0.950877f, 0.954806f, 0.958735f, 0.962665f,
		0.966594f, 0.970523f, 0.974452f, 0.978382f, 0.982311f, 0.98624f,
		0.990169f, 0.994098f, 0.998028f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using h1_cable_table9_t = wrap::data<control::cable_table<parameter::plain<h1_switcher13_t<NV>, 0>>, 
                                     data::embedded::table<h1_cable_table9_t_data>>;

template <int NV>
using h1_sb_container13_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb74_t<NV>>, 
                                             h1_sb75_t<NV>, 
                                             h1_sb76_t<NV>, 
                                             h1_sb77_t<NV>, 
                                             h1_sb78_t<NV>, 
                                             h1_sb79_t<NV>, 
                                             h1_sb80_t<NV>, 
                                             h1_sb81_t<NV>>;

template <int NV>
using h1_softbypass_switch17_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table9_t<NV>>, 
                                                  h1_switcher13_t<NV>, 
                                                  h1_sb_container13_t<NV>>;

template <int NV>
using h1_sb73_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch17_t<NV>>>;

template <int NV>
using h1_sb73_t = bypass::smoothed<20, h1_sb73_t_<NV>>;
template <int NV>
using h1_switcher12_c0 = parameter::bypass<h1_sb73_t<NV>>;

template <int NV> using h1_sb83_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb83_t = bypass::smoothed<20, h1_sb83_t_<NV>>;
template <int NV>
using h1_switcher14_c0 = parameter::bypass<h1_sb83_t<NV>>;

template <int NV> using h1_sb84_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb84_t = bypass::smoothed<20, h1_sb84_t_<NV>>;
template <int NV>
using h1_switcher14_c1 = parameter::bypass<h1_sb84_t<NV>>;

template <int NV> using h1_sb85_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb85_t = bypass::smoothed<20, h1_sb85_t_<NV>>;
template <int NV>
using h1_switcher14_c2 = parameter::bypass<h1_sb85_t<NV>>;

template <int NV> using h1_sb86_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb86_t = bypass::smoothed<20, h1_sb86_t_<NV>>;
template <int NV>
using h1_switcher14_c3 = parameter::bypass<h1_sb86_t<NV>>;

template <int NV> using h1_sb87_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb87_t = bypass::smoothed<20, h1_sb87_t_<NV>>;
template <int NV>
using h1_switcher14_c4 = parameter::bypass<h1_sb87_t<NV>>;

template <int NV> using h1_sb88_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb88_t = bypass::smoothed<20, h1_sb88_t_<NV>>;
template <int NV>
using h1_switcher14_c5 = parameter::bypass<h1_sb88_t<NV>>;

template <int NV> using h1_sb89_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb89_t = bypass::smoothed<20, h1_sb89_t_<NV>>;
template <int NV>
using h1_switcher14_c6 = parameter::bypass<h1_sb89_t<NV>>;

template <int NV> using h1_sb90_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb90_t = bypass::smoothed<20, h1_sb90_t_<NV>>;
template <int NV>
using h1_switcher14_c7 = parameter::bypass<h1_sb90_t<NV>>;

template <int NV>
using h1_switcher14_multimod = parameter::list<h1_switcher14_c0<NV>, 
                                               h1_switcher14_c1<NV>, 
                                               h1_switcher14_c2<NV>, 
                                               h1_switcher14_c3<NV>, 
                                               h1_switcher14_c4<NV>, 
                                               h1_switcher14_c5<NV>, 
                                               h1_switcher14_c6<NV>, 
                                               h1_switcher14_c7<NV>>;

template <int NV>
using h1_switcher14_t = control::xfader<h1_switcher14_multimod<NV>, 
                                        faders::switcher>;

struct h1_cable_table10_t_data
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
		0.f, 0.00201124f, 0.00598741f, 0.00996339f, 0.0139394f, 0.0179154f,
		0.0218914f, 0.0258674f, 0.0298434f, 0.0338194f, 0.0377955f, 0.0417715f,
		0.0457475f, 0.0497236f, 0.0536996f, 0.0576755f, 0.0616516f, 0.0656276f,
		0.0696037f, 0.0735797f, 0.0775557f, 0.0815317f, 0.0855077f, 0.0894837f,
		0.0934597f, 0.0974357f, 0.101412f, 0.105388f, 0.109364f, 0.11334f,
		0.117316f, 0.121292f, 0.125268f, 0.129244f, 0.13322f, 0.137196f,
		0.141172f, 0.145148f, 0.149124f, 0.1531f, 0.157076f, 0.161052f,
		0.165028f, 0.169004f, 0.17298f, 0.176956f, 0.180932f, 0.184908f,
		0.188884f, 0.19286f, 0.196836f, 0.200812f, 0.204788f, 0.208764f,
		0.21274f, 0.216716f, 0.220692f, 0.224668f, 0.228644f, 0.23262f,
		0.236596f, 0.240572f, 0.244548f, 0.248524f, 0.252501f, 0.256477f,
		0.260453f, 0.264429f, 0.268405f, 0.272381f, 0.276357f, 0.280333f,
		0.284309f, 0.288285f, 0.292261f, 0.296237f, 0.300213f, 0.304189f,
		0.308165f, 0.312141f, 0.316117f, 0.320093f, 0.324069f, 0.328045f,
		0.332021f, 0.335997f, 0.339973f, 0.343949f, 0.347925f, 0.351901f,
		0.355877f, 0.359853f, 0.363829f, 0.367805f, 0.371781f, 0.375757f,
		0.379733f, 0.383709f, 0.387685f, 0.391661f, 0.395637f, 0.399613f,
		0.403589f, 0.407565f, 0.411541f, 0.415517f, 0.419493f, 0.423469f,
		0.427445f, 0.431421f, 0.435397f, 0.439373f, 0.443349f, 0.447325f,
		0.451302f, 0.455278f, 0.459254f, 0.46323f, 0.467206f, 0.471182f,
		0.475158f, 0.479134f, 0.48311f, 0.487086f, 0.491062f, 0.495038f,
		0.499014f, 0.50299f, 0.506966f, 0.510942f, 0.514918f, 0.518894f,
		0.52287f, 0.526846f, 0.530822f, 0.534798f, 0.538774f, 0.54275f,
		0.546726f, 0.550702f, 0.554678f, 0.558654f, 0.56263f, 0.566606f,
		0.570582f, 0.574558f, 0.578534f, 0.58251f, 0.586486f, 0.590462f,
		0.594438f, 0.598414f, 0.60239f, 0.606366f, 0.610342f, 0.614318f,
		0.618294f, 0.62227f, 0.626246f, 0.630222f, 0.634198f, 0.638174f,
		0.642151f, 0.646127f, 0.650102f, 0.654078f, 0.658054f, 0.662031f,
		0.666007f, 0.669983f, 0.673959f, 0.677935f, 0.681911f, 0.685887f,
		0.689863f, 0.693839f, 0.697815f, 0.701791f, 0.705767f, 0.709743f,
		0.713719f, 0.717695f, 0.721671f, 0.725647f, 0.729623f, 0.733599f,
		0.737575f, 0.741551f, 0.745527f, 0.749503f, 0.753479f, 0.757455f,
		0.761431f, 0.765407f, 0.769383f, 0.773359f, 0.777335f, 0.781311f,
		0.785287f, 0.789263f, 0.793239f, 0.797215f, 0.801191f, 0.805167f,
		0.809143f, 0.813119f, 0.817095f, 0.821071f, 0.825047f, 0.829023f,
		0.832999f, 0.836975f, 0.840951f, 0.844927f, 0.848903f, 0.852879f,
		0.856855f, 0.860831f, 0.864808f, 0.868784f, 0.87276f, 0.876736f,
		0.880712f, 0.884688f, 0.888664f, 0.89264f, 0.896616f, 0.900592f,
		0.904568f, 0.908544f, 0.91252f, 0.916496f, 0.920472f, 0.924448f,
		0.928424f, 0.9324f, 0.936376f, 0.940352f, 0.944328f, 0.948304f,
		0.95228f, 0.956256f, 0.960232f, 0.964208f, 0.968184f, 0.97216f,
		0.976136f, 0.980112f, 0.984088f, 0.988064f, 0.99204f, 0.996016f,
		0.999992f, 1.f
	};
};

template <int NV>
using h1_cable_table10_t = wrap::data<control::cable_table<parameter::plain<h1_switcher14_t<NV>, 0>>, 
                                      data::embedded::table<h1_cable_table10_t_data>>;

template <int NV>
using h1_sb_container14_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb83_t<NV>>, 
                                             h1_sb84_t<NV>, 
                                             h1_sb85_t<NV>, 
                                             h1_sb86_t<NV>, 
                                             h1_sb87_t<NV>, 
                                             h1_sb88_t<NV>, 
                                             h1_sb89_t<NV>, 
                                             h1_sb90_t<NV>>;

template <int NV>
using h1_softbypass_switch18_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_cable_table10_t<NV>>, 
                                                  h1_switcher14_t<NV>, 
                                                  h1_sb_container14_t<NV>>;

template <int NV>
using h1_sb82_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, h1_softbypass_switch18_t<NV>>>;

template <int NV>
using h1_sb82_t = bypass::smoothed<20, h1_sb82_t_<NV>>;
template <int NV>
using h1_switcher12_c1 = parameter::bypass<h1_sb82_t<NV>>;

template <int NV>
using h1_switcher12_multimod = parameter::list<h1_switcher12_c0<NV>, h1_switcher12_c1<NV>>;

template <int NV>
using h1_switcher12_t = control::xfader<h1_switcher12_multimod<NV>, 
                                        faders::switcher>;

template <int NV> using h1_sb20_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb20_t = bypass::smoothed<20, h1_sb20_t_<NV>>;
template <int NV>
using h1_switcher4_c0 = parameter::bypass<h1_sb20_t<NV>>;

template <int NV> using h1_sb21_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb21_t = bypass::smoothed<20, h1_sb21_t_<NV>>;
template <int NV>
using h1_switcher4_c1 = parameter::bypass<h1_sb21_t<NV>>;

template <int NV> using h1_sb22_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb22_t = bypass::smoothed<20, h1_sb22_t_<NV>>;
template <int NV>
using h1_switcher4_c2 = parameter::bypass<h1_sb22_t<NV>>;

template <int NV> using h1_sb23_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb23_t = bypass::smoothed<20, h1_sb23_t_<NV>>;
template <int NV>
using h1_switcher4_c3 = parameter::bypass<h1_sb23_t<NV>>;

template <int NV> using h1_sb24_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb24_t = bypass::smoothed<20, h1_sb24_t_<NV>>;
template <int NV>
using h1_switcher4_c4 = parameter::bypass<h1_sb24_t<NV>>;

template <int NV> using h1_sb25_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb25_t = bypass::smoothed<20, h1_sb25_t_<NV>>;
template <int NV>
using h1_switcher4_c5 = parameter::bypass<h1_sb25_t<NV>>;

template <int NV> using h1_sb26_t_ = h1_sb1_t_<NV>;

template <int NV>
using h1_sb26_t = bypass::smoothed<20, h1_sb26_t_<NV>>;
template <int NV>
using h1_switcher4_c6 = parameter::bypass<h1_sb26_t<NV>>;

template <int NV>
using h1_switcher4_multimod = parameter::list<h1_switcher4_c0<NV>, 
                                              h1_switcher4_c1<NV>, 
                                              h1_switcher4_c2<NV>, 
                                              h1_switcher4_c3<NV>, 
                                              h1_switcher4_c4<NV>, 
                                              h1_switcher4_c5<NV>, 
                                              h1_switcher4_c6<NV>>;

template <int NV>
using h1_switcher4_t = control::xfader<h1_switcher4_multimod<NV>, 
                                       faders::switcher>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<h1_switcher2_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table1_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table2_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table6_t<NV>, 0>, 
                                  parameter::plain<h1_switcher6_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table5_t<NV>, 0>, 
                                  parameter::plain<h1_switcher9_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table7_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table8_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table13_t<NV>, 0>, 
                                  parameter::plain<h1_switcher18_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table14_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table9_t<NV>, 0>, 
                                  parameter::plain<h1_switcher12_t<NV>, 0>, 
                                  parameter::plain<h1_cable_table10_t<NV>, 0>, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<h1_switcher4_t<NV>, 0>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;
using global_cable40_t_index = runtime_target::indexers::fix_hash<545021411>;

template <int NV>
using global_cable40_t = routing::global_cable<global_cable40_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable40_t<NV>>, 
                                   math::add<NV>>;
using global_cable33_t_index = runtime_target::indexers::fix_hash<545021412>;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable33_t<NV>>, 
                                   math::add<NV>>;
using global_cable34_t_index = runtime_target::indexers::fix_hash<545021413>;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable34_t<NV>>, 
                                   math::add<NV>>;
using global_cable35_t_index = runtime_target::indexers::fix_hash<545021414>;

template <int NV>
using global_cable35_t = routing::global_cable<global_cable35_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable35_t<NV>>, 
                                   math::add<NV>>;
using global_cable36_t_index = runtime_target::indexers::fix_hash<545021415>;

template <int NV>
using global_cable36_t = routing::global_cable<global_cable36_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable36_t<NV>>, 
                                   math::add<NV>>;
using global_cable37_t_index = runtime_target::indexers::fix_hash<545021416>;

template <int NV>
using global_cable37_t = routing::global_cable<global_cable37_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable37_t<NV>>, 
                                   math::add<NV>>;
using global_cable38_t_index = runtime_target::indexers::fix_hash<545021417>;

template <int NV>
using global_cable38_t = routing::global_cable<global_cable38_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable38_t<NV>>, 
                                   math::add<NV>>;
using global_cable39_t_index = runtime_target::indexers::fix_hash<545021418>;

template <int NV>
using global_cable39_t = routing::global_cable<global_cable39_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable39_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain55_t<NV>>, 
                                    chain48_t<NV>, 
                                    chain49_t<NV>, 
                                    chain50_t<NV>, 
                                    chain51_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>, 
                                    chain54_t<NV>>;

DECLARE_PARAMETER_RANGE(peak_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using peak_mod = parameter::from0To1<pma2_t<NV>, 
                                     2, 
                                     peak_modRange>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, branch5_t<NV>>, 
                                 peak_t<NV>, 
                                 pma2_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>>;

template <int NV>
using h1_sb_container2_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb17_t<NV>>, 
                                            h1_sb18_t<NV>>;

template <int NV>
using h1_softbypass_switch3_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_switcher2_t<NV>>, 
                                                 h1_sb_container2_t<NV>>;

template <int NV>
using h1_harm_t = container::chain<parameter::empty, 
                                   wrap::fix<1, h1_softbypass_switch3_t<NV>>>;

template <int NV>
using h1_sb_container6_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb37_t<NV>>, 
                                            h1_sb46_t<NV>>;

template <int NV>
using h1_softbypass_switch5_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_switcher6_t<NV>>, 
                                                 h1_sb_container6_t<NV>>;

template <int NV>
using h1_chromatic_t = container::chain<parameter::empty, 
                                        wrap::fix<1, h1_softbypass_switch5_t<NV>>>;

template <int NV>
using h1_sb_container9_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb55_t<NV>>, 
                                            h1_sb64_t<NV>>;

template <int NV>
using h1_softbypass_switch6_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_switcher9_t<NV>>, 
                                                 h1_sb_container9_t<NV>>;

template <int NV>
using h1_min_t = container::chain<parameter::empty, 
                                  wrap::fix<1, h1_softbypass_switch6_t<NV>>>;

template <int NV>
using h1_sb_container18_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb109_t<NV>>, 
                                             h1_sb118_t<NV>>;

template <int NV>
using h1_softbypass_switch12_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_switcher18_t<NV>>, 
                                                  h1_sb_container18_t<NV>>;

template <int NV>
using h1_min1_t = container::chain<parameter::empty, 
                                   wrap::fix<1, h1_softbypass_switch12_t<NV>>>;

template <int NV>
using h1_sb_container12_t = container::chain<parameter::empty, 
                                             wrap::fix<1, h1_sb73_t<NV>>, 
                                             h1_sb82_t<NV>>;

template <int NV>
using h1_softbypass_switch7_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_switcher12_t<NV>>, 
                                                 h1_sb_container12_t<NV>>;

template <int NV>
using h1_Det_t = container::chain<parameter::empty, 
                                  wrap::fix<1, h1_softbypass_switch7_t<NV>>>;

template <int NV>
using h1_sb_container4_t = container::chain<parameter::empty, 
                                            wrap::fix<1, h1_sb20_t<NV>>, 
                                            h1_sb21_t<NV>, 
                                            h1_sb22_t<NV>, 
                                            h1_sb23_t<NV>, 
                                            h1_sb24_t<NV>, 
                                            h1_sb25_t<NV>, 
                                            h1_sb26_t<NV>>;

template <int NV>
using h1_softbypass_switch11_t = container::chain<parameter::empty, 
                                                  wrap::fix<1, h1_switcher4_t<NV>>, 
                                                  h1_sb_container4_t<NV>>;

template <int NV>
using h1_softbypass_switch4_t = container::chain<parameter::empty, 
                                                 wrap::fix<1, h1_softbypass_switch11_t<NV>>>;

template <int NV>
using h1_5ths_t = container::chain<parameter::empty, 
                                   wrap::fix<1, h1_softbypass_switch4_t<NV>>>;

template <int NV> using h1_free_t = h1_sb1_t_<NV>;
template <int NV>
using h1_branch_t = container::branch<parameter::empty, 
                                      wrap::fix<1, h1_harm_t<NV>>, 
                                      h1_chromatic_t<NV>, 
                                      h1_min_t<NV>, 
                                      h1_min1_t<NV>, 
                                      h1_Det_t<NV>, 
                                      h1_5ths_t<NV>, 
                                      h1_free_t<NV>>;

template <int NV>
using h1_peak3_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                             wrap::no_data<core::peak>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  h1_branch_t<NV>, 
                                  h1_peak3_t<NV>, 
                                  math::clear<NV>, 
                                  math::add<NV>, 
                                  core::smoother<NV>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch4_t<NV>>, 
                                   peak3_t<NV>, 
                                   math::clear<NV>, 
                                   split_t<NV>, 
                                   chain1_t<NV>>;

namespace Pitches_t_parameters
{
// Parameter list for Pitches_impl::Pitches_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(StageSrc_InputRange, 
                             0., 
                             8., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(StageSrc_0Range, 
                             0., 
                             7., 
                             1.);

template <int NV>
using StageSrc_0 = parameter::from0To1<Pitches_impl::branch4_t<NV>, 
                                       0, 
                                       StageSrc_0Range>;

template <int NV>
using StageSrc = parameter::chain<StageSrc_InputRange, StageSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(SliderInput_InputRange, 
                             1., 
                             8., 
                             1.);
template <int NV>
using SliderInput_0 = parameter::from0To1<Pitches_impl::branch5_t<NV>, 
                                          0, 
                                          StageSrc_0Range>;

template <int NV>
using SliderInput = parameter::chain<SliderInput_InputRange, SliderInput_0<NV>>;

template <int NV>
using StageMod = parameter::plain<Pitches_impl::pma2_t<NV>, 
                                  1>;
template <int NV>
using TuneMode = parameter::plain<Pitches_impl::h1_branch_t<NV>, 
                                  0>;
template <int NV>
using Smooth = parameter::plain<core::smoother<NV>, 0>;
template <int NV>
using Pitches_t_plist = parameter::list<StageMod<NV>, 
                                        StageSrc<NV>, 
                                        TuneMode<NV>, 
                                        Smooth<NV>, 
                                        SliderInput<NV>>;
}

template <int NV>
using Pitches_t_ = container::chain<Pitches_t_parameters::Pitches_t_plist<NV>, 
                                    wrap::fix<1, chain38_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Pitches_impl::Pitches_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Pitches);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(92)
		{
			0x005C, 0x0000, 0x0000, 0x7453, 0x6761, 0x4D65, 0x646F, 0x0000, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0001, 0x0000, 0x7453, 0x6761, 0x5365, 
            0x6372, 0x0000, 0x0000, 0x0000, 0x0000, 0x4100, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0002, 0x0000, 0x7554, 
            0x656E, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x0000, 0x0000, 0x40C0, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0003, 
            0x0000, 0x6D53, 0x6F6F, 0x6874, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x44FA, 0x0000, 0x0000, 0xEE69, 0x3E6C, 0xCCCD, 0x3DCC, 0x005C, 
            0x0004, 0x0000, 0x6C53, 0x6469, 0x7265, 0x6E49, 0x7570, 0x0074, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000
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
		
		auto& chain38 = this->getT(0);                                                          // Pitches_impl::chain38_t<NV>
		auto& branch4 = this->getT(0).getT(0);                                                  // Pitches_impl::branch4_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(0);                                          // Pitches_impl::chain39_t<NV>
		auto& global_cable24 = this->getT(0).getT(0).getT(0).getT(0);                           // Pitches_impl::global_cable24_t<NV>
		auto& add24 = this->getT(0).getT(0).getT(0).getT(1);                                    // math::add<NV>
		auto& chain40 = this->getT(0).getT(0).getT(1);                                          // Pitches_impl::chain40_t<NV>
		auto& global_cable25 = this->getT(0).getT(0).getT(1).getT(0);                           // Pitches_impl::global_cable25_t<NV>
		auto& add25 = this->getT(0).getT(0).getT(1).getT(1);                                    // math::add<NV>
		auto& chain41 = this->getT(0).getT(0).getT(2);                                          // Pitches_impl::chain41_t<NV>
		auto& global_cable26 = this->getT(0).getT(0).getT(2).getT(0);                           // Pitches_impl::global_cable26_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(2).getT(1);                                    // math::add<NV>
		auto& chain42 = this->getT(0).getT(0).getT(3);                                          // Pitches_impl::chain42_t<NV>
		auto& global_cable27 = this->getT(0).getT(0).getT(3).getT(0);                           // Pitches_impl::global_cable27_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(3).getT(1);                                    // math::add<NV>
		auto& chain43 = this->getT(0).getT(0).getT(4);                                          // Pitches_impl::chain43_t<NV>
		auto& global_cable28 = this->getT(0).getT(0).getT(4).getT(0);                           // Pitches_impl::global_cable28_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(4).getT(1);                                    // math::add<NV>
		auto& chain44 = this->getT(0).getT(0).getT(5);                                          // Pitches_impl::chain44_t<NV>
		auto& global_cable29 = this->getT(0).getT(0).getT(5).getT(0);                           // Pitches_impl::global_cable29_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(5).getT(1);                                    // math::add<NV>
		auto& chain45 = this->getT(0).getT(0).getT(6);                                          // Pitches_impl::chain45_t<NV>
		auto& global_cable30 = this->getT(0).getT(0).getT(6).getT(0);                           // Pitches_impl::global_cable30_t<NV>
		auto& add30 = this->getT(0).getT(0).getT(6).getT(1);                                    // math::add<NV>
		auto& chain46 = this->getT(0).getT(0).getT(7);                                          // Pitches_impl::chain46_t<NV>
		auto& global_cable31 = this->getT(0).getT(0).getT(7).getT(0);                           // Pitches_impl::global_cable31_t<NV>
		auto& add31 = this->getT(0).getT(0).getT(7).getT(1);                                    // math::add<NV>
		auto& peak3 = this->getT(0).getT(1);                                                    // Pitches_impl::peak3_t<NV>
		auto& clear1 = this->getT(0).getT(2);                                                   // math::clear<NV>
		auto& split = this->getT(0).getT(3);                                                    // Pitches_impl::split_t<NV>
		auto& chain = this->getT(0).getT(3).getT(0);                                            // Pitches_impl::chain_t<NV>
		auto& branch5 = this->getT(0).getT(3).getT(0).getT(0);                                  // Pitches_impl::branch5_t<NV>
		auto& chain55 = this->getT(0).getT(3).getT(0).getT(0).getT(0);                          // Pitches_impl::chain55_t<NV>
		auto& global_cable40 = this->getT(0).getT(3).getT(0).getT(0).getT(0).getT(0);           // Pitches_impl::global_cable40_t<NV>
		auto& add40 = this->getT(0).getT(3).getT(0).getT(0).getT(0).getT(1);                    // math::add<NV>
		auto& chain48 = this->getT(0).getT(3).getT(0).getT(0).getT(1);                          // Pitches_impl::chain48_t<NV>
		auto& global_cable33 = this->getT(0).getT(3).getT(0).getT(0).getT(1).getT(0);           // Pitches_impl::global_cable33_t<NV>
		auto& add33 = this->getT(0).getT(3).getT(0).getT(0).getT(1).getT(1);                    // math::add<NV>
		auto& chain49 = this->getT(0).getT(3).getT(0).getT(0).getT(2);                          // Pitches_impl::chain49_t<NV>
		auto& global_cable34 = this->getT(0).getT(3).getT(0).getT(0).getT(2).getT(0);           // Pitches_impl::global_cable34_t<NV>
		auto& add34 = this->getT(0).getT(3).getT(0).getT(0).getT(2).getT(1);                    // math::add<NV>
		auto& chain50 = this->getT(0).getT(3).getT(0).getT(0).getT(3);                          // Pitches_impl::chain50_t<NV>
		auto& global_cable35 = this->getT(0).getT(3).getT(0).getT(0).getT(3).getT(0);           // Pitches_impl::global_cable35_t<NV>
		auto& add35 = this->getT(0).getT(3).getT(0).getT(0).getT(3).getT(1);                    // math::add<NV>
		auto& chain51 = this->getT(0).getT(3).getT(0).getT(0).getT(4);                          // Pitches_impl::chain51_t<NV>
		auto& global_cable36 = this->getT(0).getT(3).getT(0).getT(0).getT(4).getT(0);           // Pitches_impl::global_cable36_t<NV>
		auto& add36 = this->getT(0).getT(3).getT(0).getT(0).getT(4).getT(1);                    // math::add<NV>
		auto& chain52 = this->getT(0).getT(3).getT(0).getT(0).getT(5);                          // Pitches_impl::chain52_t<NV>
		auto& global_cable37 = this->getT(0).getT(3).getT(0).getT(0).getT(5).getT(0);           // Pitches_impl::global_cable37_t<NV>
		auto& add37 = this->getT(0).getT(3).getT(0).getT(0).getT(5).getT(1);                    // math::add<NV>
		auto& chain53 = this->getT(0).getT(3).getT(0).getT(0).getT(6);                          // Pitches_impl::chain53_t<NV>
		auto& global_cable38 = this->getT(0).getT(3).getT(0).getT(0).getT(6).getT(0);           // Pitches_impl::global_cable38_t<NV>
		auto& add38 = this->getT(0).getT(3).getT(0).getT(0).getT(6).getT(1);                    // math::add<NV>
		auto& chain54 = this->getT(0).getT(3).getT(0).getT(0).getT(7);                          // Pitches_impl::chain54_t<NV>
		auto& global_cable39 = this->getT(0).getT(3).getT(0).getT(0).getT(7).getT(0);           // Pitches_impl::global_cable39_t<NV>
		auto& add39 = this->getT(0).getT(3).getT(0).getT(0).getT(7).getT(1);                    // math::add<NV>
		auto& peak = this->getT(0).getT(3).getT(0).getT(1);                                     // Pitches_impl::peak_t<NV>
		auto& pma2 = this->getT(0).getT(3).getT(0).getT(2);                                     // Pitches_impl::pma2_t<NV>
		auto& chain1 = this->getT(0).getT(4);                                                   // Pitches_impl::chain1_t<NV>
		auto& clear = this->getT(0).getT(4).getT(0);                                            // math::clear<NV>
		auto& h1_branch = this->getT(0).getT(4).getT(1);                                        // Pitches_impl::h1_branch_t<NV>
		auto& h1_harm = this->getT(0).getT(4).getT(1).getT(0);                                  // Pitches_impl::h1_harm_t<NV>
		auto& h1_softbypass_switch3 = this->getT(0).getT(4).getT(1).getT(0).getT(0);            // Pitches_impl::h1_softbypass_switch3_t<NV>
		auto& h1_switcher2 = this->getT(0).getT(4).getT(1).getT(0).getT(0).getT(0);             // Pitches_impl::h1_switcher2_t<NV>
		auto& h1_sb_container2 = this->getT(0).getT(4).getT(1).getT(0).getT(0).getT(1);         // Pitches_impl::h1_sb_container2_t<NV>
		auto& h1_sb17 = this->getT(0).getT(4).getT(1).getT(0).getT(0).getT(1).getT(0);          // Pitches_impl::h1_sb17_t<NV>
		auto& h1_softbypass_switch9 = this->getT(0).getT(4).getT(1).getT(0).                    // Pitches_impl::h1_softbypass_switch9_t<NV>
                                      getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table1 = this->getT(0).getT(4).getT(1).getT(0).                          // Pitches_impl::h1_cable_table1_t<NV>
                                getT(0).getT(1).getT(0).getT(0).
                                getT(0);
		auto& h1_switcher = this->getT(0).getT(4).getT(1).getT(0).                              // Pitches_impl::h1_switcher_t<NV>
                            getT(0).getT(1).getT(0).getT(0).
                            getT(1);
		auto& h1_sb_container = this->getT(0).getT(4).getT(1).getT(0).                          // Pitches_impl::h1_sb_container_t<NV>
                                getT(0).getT(1).getT(0).getT(0).
                                getT(2);
		auto& h1_sb1 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                           // Pitches_impl::h1_sb1_t<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add2 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // math::add<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(0).
                        getT(0);
		auto& h1_sb2 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                           // Pitches_impl::h1_sb2_t<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add4 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // math::add<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(1).
                        getT(0);
		auto& h1_sb3 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                           // Pitches_impl::h1_sb3_t<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add3 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // math::add<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(2).
                        getT(0);
		auto& h1_sb4 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                           // Pitches_impl::h1_sb4_t<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add6 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // math::add<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(3).
                        getT(0);
		auto& h1_sb5 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                           // Pitches_impl::h1_sb5_t<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add5 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // math::add<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(4).
                        getT(0);
		auto& h1_sb6 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                           // Pitches_impl::h1_sb6_t<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add8 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // math::add<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(5).
                        getT(0);
		auto& h1_sb7 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                           // Pitches_impl::h1_sb7_t<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add7 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // math::add<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(6).
                        getT(0);
		auto& h1_sb8 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                           // Pitches_impl::h1_sb8_t<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add9 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // math::add<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(7).
                        getT(0);
		auto& h1_sb18 = this->getT(0).getT(4).getT(1).getT(0).getT(0).getT(1).getT(1);          // Pitches_impl::h1_sb18_t<NV>
		auto& h1_softbypass_switch10 = this->getT(0).getT(4).getT(1).getT(0).                   // Pitches_impl::h1_softbypass_switch10_t<NV>
                                       getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table2 = this->getT(0).getT(4).getT(1).getT(0).                          // Pitches_impl::h1_cable_table2_t<NV>
                                getT(0).getT(1).getT(1).getT(0).
                                getT(0);
		auto& h1_switcher1 = this->getT(0).getT(4).getT(1).getT(0).                             // Pitches_impl::h1_switcher1_t<NV>
                             getT(0).getT(1).getT(1).getT(0).
                             getT(1);
		auto& h1_sb_container1 = this->getT(0).getT(4).getT(1).getT(0).                         // Pitches_impl::h1_sb_container1_t<NV>
                                 getT(0).getT(1).getT(1).getT(0).
                                 getT(2);
		auto& h1_sb9 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                           // Pitches_impl::h1_sb9_t<NV>
                       getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add10 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb10 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // Pitches_impl::h1_sb10_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add11 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb11 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // Pitches_impl::h1_sb11_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add12 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb12 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // Pitches_impl::h1_sb12_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add13 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb13 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // Pitches_impl::h1_sb13_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add14 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb14 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // Pitches_impl::h1_sb14_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add15 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb15 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // Pitches_impl::h1_sb15_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add16 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb16 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                          // Pitches_impl::h1_sb16_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add17 = this->getT(0).getT(4).getT(1).getT(0).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_chromatic = this->getT(0).getT(4).getT(1).getT(1);                             // Pitches_impl::h1_chromatic_t<NV>
		auto& h1_softbypass_switch5 = this->getT(0).getT(4).getT(1).getT(1).getT(0);            // Pitches_impl::h1_softbypass_switch5_t<NV>
		auto& h1_switcher6 = this->getT(0).getT(4).getT(1).getT(1).getT(0).getT(0);             // Pitches_impl::h1_switcher6_t<NV>
		auto& h1_sb_container6 = this->getT(0).getT(4).getT(1).getT(1).getT(0).getT(1);         // Pitches_impl::h1_sb_container6_t<NV>
		auto& h1_sb37 = this->getT(0).getT(4).getT(1).getT(1).getT(0).getT(1).getT(0);          // Pitches_impl::h1_sb37_t<NV>
		auto& h1_softbypass_switch13 = this->getT(0).getT(4).getT(1).getT(1).                   // Pitches_impl::h1_softbypass_switch13_t<NV>
                                       getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table5 = this->getT(0).getT(4).getT(1).getT(1).                          // Pitches_impl::h1_cable_table5_t<NV>
                                getT(0).getT(1).getT(0).getT(0).
                                getT(0);
		auto& h1_switcher7 = this->getT(0).getT(4).getT(1).getT(1).                             // Pitches_impl::h1_switcher7_t<NV>
                             getT(0).getT(1).getT(0).getT(0).
                             getT(1);
		auto& h1_sb_container7 = this->getT(0).getT(4).getT(1).getT(1).                         // Pitches_impl::h1_sb_container7_t<NV>
                                 getT(0).getT(1).getT(0).getT(0).
                                 getT(2);
		auto& h1_sb38 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb38_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add34 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb39 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb39_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add35 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb40 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb40_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add36 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb41 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb41_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add37 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb42 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb42_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add38 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb43 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb43_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add39 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb44 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb44_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add40 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb45 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb45_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add41 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_sb46 = this->getT(0).getT(4).getT(1).getT(1).getT(0).getT(1).getT(1);          // Pitches_impl::h1_sb46_t<NV>
		auto& h1_softbypass_switch14 = this->getT(0).getT(4).getT(1).getT(1).                   // Pitches_impl::h1_softbypass_switch14_t<NV>
                                       getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table6 = this->getT(0).getT(4).getT(1).getT(1).                          // Pitches_impl::h1_cable_table6_t<NV>
                                getT(0).getT(1).getT(1).getT(0).
                                getT(0);
		auto& h1_switcher8 = this->getT(0).getT(4).getT(1).getT(1).                             // Pitches_impl::h1_switcher8_t<NV>
                             getT(0).getT(1).getT(1).getT(0).
                             getT(1);
		auto& h1_sb_container8 = this->getT(0).getT(4).getT(1).getT(1).                         // Pitches_impl::h1_sb_container8_t<NV>
                                 getT(0).getT(1).getT(1).getT(0).
                                 getT(2);
		auto& h1_sb47 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb47_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add42 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb48 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb48_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add43 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb49 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb49_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add44 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb50 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb50_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add45 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb51 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb51_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add46 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb52 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb52_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add47 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb53 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb53_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add48 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb54 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                          // Pitches_impl::h1_sb54_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add49 = this->getT(0).getT(4).getT(1).getT(1).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_min = this->getT(0).getT(4).getT(1).getT(2);                                   // Pitches_impl::h1_min_t<NV>
		auto& h1_softbypass_switch6 = this->getT(0).getT(4).getT(1).getT(2).getT(0);            // Pitches_impl::h1_softbypass_switch6_t<NV>
		auto& h1_switcher9 = this->getT(0).getT(4).getT(1).getT(2).getT(0).getT(0);             // Pitches_impl::h1_switcher9_t<NV>
		auto& h1_sb_container9 = this->getT(0).getT(4).getT(1).getT(2).getT(0).getT(1);         // Pitches_impl::h1_sb_container9_t<NV>
		auto& h1_sb55 = this->getT(0).getT(4).getT(1).getT(2).getT(0).getT(1).getT(0);          // Pitches_impl::h1_sb55_t<NV>
		auto& h1_softbypass_switch15 = this->getT(0).getT(4).getT(1).getT(2).                   // Pitches_impl::h1_softbypass_switch15_t<NV>
                                       getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table7 = this->getT(0).getT(4).getT(1).getT(2).                          // Pitches_impl::h1_cable_table7_t<NV>
                                getT(0).getT(1).getT(0).getT(0).
                                getT(0);
		auto& h1_switcher10 = this->getT(0).getT(4).getT(1).getT(2).                            // Pitches_impl::h1_switcher10_t<NV>
                              getT(0).getT(1).getT(0).getT(0).
                              getT(1);
		auto& h1_sb_container10 = this->getT(0).getT(4).getT(1).getT(2).                        // Pitches_impl::h1_sb_container10_t<NV>
                                  getT(0).getT(1).getT(0).getT(0).
                                  getT(2);
		auto& h1_sb56 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb56_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add50 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb57 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb57_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add51 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb58 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb58_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add52 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb59 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb59_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add53 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb60 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb60_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add54 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb61 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb61_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add55 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb62 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb62_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add56 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb63 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb63_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add57 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_sb64 = this->getT(0).getT(4).getT(1).getT(2).getT(0).getT(1).getT(1);          // Pitches_impl::h1_sb64_t<NV>
		auto& h1_softbypass_switch16 = this->getT(0).getT(4).getT(1).getT(2).                   // Pitches_impl::h1_softbypass_switch16_t<NV>
                                       getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table8 = this->getT(0).getT(4).getT(1).getT(2).                          // Pitches_impl::h1_cable_table8_t<NV>
                                getT(0).getT(1).getT(1).getT(0).
                                getT(0);
		auto& h1_switcher11 = this->getT(0).getT(4).getT(1).getT(2).                            // Pitches_impl::h1_switcher11_t<NV>
                              getT(0).getT(1).getT(1).getT(0).
                              getT(1);
		auto& h1_sb_container11 = this->getT(0).getT(4).getT(1).getT(2).                        // Pitches_impl::h1_sb_container11_t<NV>
                                  getT(0).getT(1).getT(1).getT(0).
                                  getT(2);
		auto& h1_sb65 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb65_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add58 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb66 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb66_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add59 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb67 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb67_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add60 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb68 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb68_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add61 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb69 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb69_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add62 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb70 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb70_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add63 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb71 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb71_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add64 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb72 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                          // Pitches_impl::h1_sb72_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add65 = this->getT(0).getT(4).getT(1).getT(2).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_min1 = this->getT(0).getT(4).getT(1).getT(3);                                  // Pitches_impl::h1_min1_t<NV>
		auto& h1_softbypass_switch12 = this->getT(0).getT(4).getT(1).getT(3).getT(0);           // Pitches_impl::h1_softbypass_switch12_t<NV>
		auto& h1_switcher18 = this->getT(0).getT(4).getT(1).getT(3).getT(0).getT(0);            // Pitches_impl::h1_switcher18_t<NV>
		auto& h1_sb_container18 = this->getT(0).getT(4).getT(1).getT(3).getT(0).getT(1);        // Pitches_impl::h1_sb_container18_t<NV>
		auto& h1_sb109 = this->getT(0).getT(4).getT(1).getT(3).getT(0).getT(1).getT(0);         // Pitches_impl::h1_sb109_t<NV>
		auto& h1_softbypass_switch21 = this->getT(0).getT(4).getT(1).getT(3).                   // Pitches_impl::h1_softbypass_switch21_t<NV>
                                       getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table13 = this->getT(0).getT(4).getT(1).getT(3).                         // Pitches_impl::h1_cable_table13_t<NV>
                                 getT(0).getT(1).getT(0).getT(0).
                                 getT(0);
		auto& h1_switcher19 = this->getT(0).getT(4).getT(1).getT(3).                            // Pitches_impl::h1_switcher19_t<NV>
                              getT(0).getT(1).getT(0).getT(0).
                              getT(1);
		auto& h1_sb_container19 = this->getT(0).getT(4).getT(1).getT(3).                        // Pitches_impl::h1_sb_container19_t<NV>
                                  getT(0).getT(1).getT(0).getT(0).
                                  getT(2);
		auto& h1_sb110 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb110_t<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add99 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb111 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb111_t<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add100 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(0).getT(0).getT(2).getT(1).
                          getT(0);
		auto& h1_sb112 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb112_t<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add101 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(0).getT(0).getT(2).getT(2).
                          getT(0);
		auto& h1_sb113 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb113_t<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add102 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(0).getT(0).getT(2).getT(3).
                          getT(0);
		auto& h1_sb114 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb114_t<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add103 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(0).getT(0).getT(2).getT(4).
                          getT(0);
		auto& h1_sb115 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb115_t<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add104 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(0).getT(0).getT(2).getT(5).
                          getT(0);
		auto& h1_sb116 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb116_t<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add105 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(0).getT(0).getT(2).getT(6).
                          getT(0);
		auto& h1_sb117 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb117_t<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add106 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(0).getT(0).getT(2).getT(7).
                          getT(0);
		auto& h1_sb118 = this->getT(0).getT(4).getT(1).getT(3).getT(0).getT(1).getT(1);         // Pitches_impl::h1_sb118_t<NV>
		auto& h1_softbypass_switch22 = this->getT(0).getT(4).getT(1).getT(3).                   // Pitches_impl::h1_softbypass_switch22_t<NV>
                                       getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table14 = this->getT(0).getT(4).getT(1).getT(3).                         // Pitches_impl::h1_cable_table14_t<NV>
                                 getT(0).getT(1).getT(1).getT(0).
                                 getT(0);
		auto& h1_switcher20 = this->getT(0).getT(4).getT(1).getT(3).                            // Pitches_impl::h1_switcher20_t<NV>
                              getT(0).getT(1).getT(1).getT(0).
                              getT(1);
		auto& h1_sb_container20 = this->getT(0).getT(4).getT(1).getT(3).                        // Pitches_impl::h1_sb_container20_t<NV>
                                  getT(0).getT(1).getT(1).getT(0).
                                  getT(2);
		auto& h1_sb119 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb119_t<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add107 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(1).getT(0).getT(2).getT(0).
                          getT(0);
		auto& h1_sb120 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb120_t<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add108 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(1).getT(0).getT(2).getT(1).
                          getT(0);
		auto& h1_sb121 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb121_t<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add109 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(1).getT(0).getT(2).getT(2).
                          getT(0);
		auto& h1_sb122 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb122_t<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add110 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(1).getT(0).getT(2).getT(3).
                          getT(0);
		auto& h1_sb123 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb123_t<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add111 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(1).getT(0).getT(2).getT(4).
                          getT(0);
		auto& h1_sb124 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb124_t<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add112 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(1).getT(0).getT(2).getT(5).
                          getT(0);
		auto& h1_sb125 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb125_t<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add113 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(1).getT(0).getT(2).getT(6).
                          getT(0);
		auto& h1_sb126 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                         // Pitches_impl::h1_sb126_t<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add114 = this->getT(0).getT(4).getT(1).getT(3).getT(0).                        // math::add<NV>
                          getT(1).getT(1).getT(0).getT(2).getT(7).
                          getT(0);
		auto& h1_Det = this->getT(0).getT(4).getT(1).getT(4);                                   // Pitches_impl::h1_Det_t<NV>
		auto& h1_softbypass_switch7 = this->getT(0).getT(4).getT(1).getT(4).getT(0);            // Pitches_impl::h1_softbypass_switch7_t<NV>
		auto& h1_switcher12 = this->getT(0).getT(4).getT(1).getT(4).getT(0).getT(0);            // Pitches_impl::h1_switcher12_t<NV>
		auto& h1_sb_container12 = this->getT(0).getT(4).getT(1).getT(4).getT(0).getT(1);        // Pitches_impl::h1_sb_container12_t<NV>
		auto& h1_sb73 = this->getT(0).getT(4).getT(1).getT(4).getT(0).getT(1).getT(0);          // Pitches_impl::h1_sb73_t<NV>
		auto& h1_softbypass_switch17 = this->getT(0).getT(4).getT(1).getT(4).                   // Pitches_impl::h1_softbypass_switch17_t<NV>
                                       getT(0).getT(1).getT(0).getT(0);
		auto& h1_cable_table9 = this->getT(0).getT(4).getT(1).getT(4).                          // Pitches_impl::h1_cable_table9_t<NV>
                                getT(0).getT(1).getT(0).getT(0).
                                getT(0);
		auto& h1_switcher13 = this->getT(0).getT(4).getT(1).getT(4).                            // Pitches_impl::h1_switcher13_t<NV>
                              getT(0).getT(1).getT(0).getT(0).
                              getT(1);
		auto& h1_sb_container13 = this->getT(0).getT(4).getT(1).getT(4).                        // Pitches_impl::h1_sb_container13_t<NV>
                                  getT(0).getT(1).getT(0).getT(0).
                                  getT(2);
		auto& h1_sb74 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb74_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& h1_add66 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb75 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb75_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& h1_add67 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb76 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb76_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& h1_add68 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb77 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb77_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(3);
		auto& h1_add69 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb78 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb78_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(4);
		auto& h1_add70 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb79 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb79_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(5);
		auto& h1_add71 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb80 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb80_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(6);
		auto& h1_add72 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb81 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb81_t<NV>
                        getT(1).getT(0).getT(0).getT(2).getT(7);
		auto& h1_add73 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(0).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_sb82 = this->getT(0).getT(4).getT(1).getT(4).getT(0).getT(1).getT(1);          // Pitches_impl::h1_sb82_t<NV>
		auto& h1_softbypass_switch18 = this->getT(0).getT(4).getT(1).getT(4).                   // Pitches_impl::h1_softbypass_switch18_t<NV>
                                       getT(0).getT(1).getT(1).getT(0);
		auto& h1_cable_table10 = this->getT(0).getT(4).getT(1).getT(4).                         // Pitches_impl::h1_cable_table10_t<NV>
                                 getT(0).getT(1).getT(1).getT(0).
                                 getT(0);
		auto& h1_switcher14 = this->getT(0).getT(4).getT(1).getT(4).                            // Pitches_impl::h1_switcher14_t<NV>
                              getT(0).getT(1).getT(1).getT(0).
                              getT(1);
		auto& h1_sb_container14 = this->getT(0).getT(4).getT(1).getT(4).                        // Pitches_impl::h1_sb_container14_t<NV>
                                  getT(0).getT(1).getT(1).getT(0).
                                  getT(2);
		auto& h1_sb83 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb83_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& h1_add74 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(0).
                         getT(0);
		auto& h1_sb84 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb84_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& h1_add75 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(1).
                         getT(0);
		auto& h1_sb85 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb85_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(2);
		auto& h1_add76 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(2).
                         getT(0);
		auto& h1_sb86 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb86_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(3);
		auto& h1_add77 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(3).
                         getT(0);
		auto& h1_sb87 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb87_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(4);
		auto& h1_add78 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(4).
                         getT(0);
		auto& h1_sb88 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb88_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(5);
		auto& h1_add79 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(5).
                         getT(0);
		auto& h1_sb89 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb89_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(6);
		auto& h1_add80 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(6).
                         getT(0);
		auto& h1_sb90 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                          // Pitches_impl::h1_sb90_t<NV>
                        getT(1).getT(1).getT(0).getT(2).getT(7);
		auto& h1_add81 = this->getT(0).getT(4).getT(1).getT(4).getT(0).                         // math::add<NV>
                         getT(1).getT(1).getT(0).getT(2).getT(7).
                         getT(0);
		auto& h1_5ths = this->getT(0).getT(4).getT(1).getT(5);                                  // Pitches_impl::h1_5ths_t<NV>
		auto& h1_softbypass_switch4 = this->getT(0).getT(4).getT(1).getT(5).getT(0);            // Pitches_impl::h1_softbypass_switch4_t<NV>
		auto& h1_softbypass_switch11 = this->getT(0).getT(4).getT(1).getT(5).getT(0).getT(0);   // Pitches_impl::h1_softbypass_switch11_t<NV>
		auto& h1_switcher4 = this->getT(0).getT(4).getT(1).getT(5).getT(0).getT(0).getT(0);     // Pitches_impl::h1_switcher4_t<NV>
		auto& h1_sb_container4 = this->getT(0).getT(4).getT(1).getT(5).getT(0).getT(0).getT(1); // Pitches_impl::h1_sb_container4_t<NV>
		auto& h1_sb20 = this->getT(0).getT(4).getT(1).getT(5).                                  // Pitches_impl::h1_sb20_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& h1_add18 = this->getT(0).getT(4).getT(1).getT(5).         // math::add<NV>
                         getT(0).getT(0).getT(1).getT(0).
                         getT(0);
		auto& h1_sb21 = this->getT(0).getT(4).getT(1).getT(5).          // Pitches_impl::h1_sb21_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& h1_add19 = this->getT(0).getT(4).getT(1).getT(5).         // math::add<NV>
                         getT(0).getT(0).getT(1).getT(1).
                         getT(0);
		auto& h1_sb22 = this->getT(0).getT(4).getT(1).getT(5).          // Pitches_impl::h1_sb22_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& h1_add20 = this->getT(0).getT(4).getT(1).getT(5).         // math::add<NV>
                         getT(0).getT(0).getT(1).getT(2).
                         getT(0);
		auto& h1_sb23 = this->getT(0).getT(4).getT(1).getT(5).          // Pitches_impl::h1_sb23_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& h1_add21 = this->getT(0).getT(4).getT(1).getT(5).         // math::add<NV>
                         getT(0).getT(0).getT(1).getT(3).
                         getT(0);
		auto& h1_sb24 = this->getT(0).getT(4).getT(1).getT(5).          // Pitches_impl::h1_sb24_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& h1_add22 = this->getT(0).getT(4).getT(1).getT(5).         // math::add<NV>
                         getT(0).getT(0).getT(1).getT(4).
                         getT(0);
		auto& h1_sb25 = this->getT(0).getT(4).getT(1).getT(5).          // Pitches_impl::h1_sb25_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& h1_add23 = this->getT(0).getT(4).getT(1).getT(5).         // math::add<NV>
                         getT(0).getT(0).getT(1).getT(5).
                         getT(0);
		auto& h1_sb26 = this->getT(0).getT(4).getT(1).getT(5).          // Pitches_impl::h1_sb26_t<NV>
                        getT(0).getT(0).getT(1).getT(6);
		auto& h1_add24 = this->getT(0).getT(4).getT(1).getT(5).         // math::add<NV>
                         getT(0).getT(0).getT(1).getT(6).
                         getT(0);
		auto& h1_free = this->getT(0).getT(4).getT(1).getT(6);          // Pitches_impl::h1_free_t<NV>
		auto& h1_add82 = this->getT(0).getT(4).getT(1).getT(6).getT(0); // math::add<NV>
		auto& h1_peak3 = this->getT(0).getT(4).getT(2);                 // Pitches_impl::h1_peak3_t<NV>
		auto& h1_clear = this->getT(0).getT(4).getT(3);                 // math::clear<NV>
		auto& h1_add1 = this->getT(0).getT(4).getT(4);                  // math::add<NV>
		auto& smoother = this->getT(0).getT(4).getT(5);                 // core::smoother<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma2); // StageMod -> pma2::Multiply
		
		this->getParameterT(1).connectT(0, branch4); // StageSrc -> branch4::Index
		
		this->getParameterT(2).connectT(0, h1_branch); // TuneMode -> h1_branch::Index
		
		this->getParameterT(3).connectT(0, smoother); // Smooth -> smoother::SmoothingTime
		
		this->getParameterT(4).connectT(0, branch5); // SliderInput -> branch5::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable24.getWrappedObject().getParameter().connectT(0, add24); // global_cable24 -> add24::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add25); // global_cable25 -> add25::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add26); // global_cable26 -> add26::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add27); // global_cable27 -> add27::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add28); // global_cable28 -> add28::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add29); // global_cable29 -> add29::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add30); // global_cable30 -> add30::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add31); // global_cable31 -> add31::Value
		auto& h1_switcher_p = h1_switcher.getWrappedObject().getParameter();
		h1_switcher_p.getParameterT(0).connectT(0, h1_sb1);                         // h1_switcher -> h1_sb1::Bypassed
		h1_switcher_p.getParameterT(1).connectT(0, h1_sb2);                         // h1_switcher -> h1_sb2::Bypassed
		h1_switcher_p.getParameterT(2).connectT(0, h1_sb3);                         // h1_switcher -> h1_sb3::Bypassed
		h1_switcher_p.getParameterT(3).connectT(0, h1_sb4);                         // h1_switcher -> h1_sb4::Bypassed
		h1_switcher_p.getParameterT(4).connectT(0, h1_sb5);                         // h1_switcher -> h1_sb5::Bypassed
		h1_switcher_p.getParameterT(5).connectT(0, h1_sb6);                         // h1_switcher -> h1_sb6::Bypassed
		h1_switcher_p.getParameterT(6).connectT(0, h1_sb7);                         // h1_switcher -> h1_sb7::Bypassed
		h1_switcher_p.getParameterT(7).connectT(0, h1_sb8);                         // h1_switcher -> h1_sb8::Bypassed
		h1_cable_table1.getWrappedObject().getParameter().connectT(0, h1_switcher); // h1_cable_table1 -> h1_switcher::Value
		auto& h1_switcher1_p = h1_switcher1.getWrappedObject().getParameter();
		h1_switcher1_p.getParameterT(0).connectT(0, h1_sb9);                         // h1_switcher1 -> h1_sb9::Bypassed
		h1_switcher1_p.getParameterT(1).connectT(0, h1_sb10);                        // h1_switcher1 -> h1_sb10::Bypassed
		h1_switcher1_p.getParameterT(2).connectT(0, h1_sb11);                        // h1_switcher1 -> h1_sb11::Bypassed
		h1_switcher1_p.getParameterT(3).connectT(0, h1_sb12);                        // h1_switcher1 -> h1_sb12::Bypassed
		h1_switcher1_p.getParameterT(4).connectT(0, h1_sb13);                        // h1_switcher1 -> h1_sb13::Bypassed
		h1_switcher1_p.getParameterT(5).connectT(0, h1_sb14);                        // h1_switcher1 -> h1_sb14::Bypassed
		h1_switcher1_p.getParameterT(6).connectT(0, h1_sb15);                        // h1_switcher1 -> h1_sb15::Bypassed
		h1_switcher1_p.getParameterT(7).connectT(0, h1_sb16);                        // h1_switcher1 -> h1_sb16::Bypassed
		h1_cable_table2.getWrappedObject().getParameter().connectT(0, h1_switcher1); // h1_cable_table2 -> h1_switcher1::Value
		auto& h1_switcher2_p = h1_switcher2.getWrappedObject().getParameter();
		h1_switcher2_p.getParameterT(0).connectT(0, h1_sb17); // h1_switcher2 -> h1_sb17::Bypassed
		h1_switcher2_p.getParameterT(1).connectT(0, h1_sb18); // h1_switcher2 -> h1_sb18::Bypassed
		auto& h1_switcher8_p = h1_switcher8.getWrappedObject().getParameter();
		h1_switcher8_p.getParameterT(0).connectT(0, h1_sb47);                        // h1_switcher8 -> h1_sb47::Bypassed
		h1_switcher8_p.getParameterT(1).connectT(0, h1_sb48);                        // h1_switcher8 -> h1_sb48::Bypassed
		h1_switcher8_p.getParameterT(2).connectT(0, h1_sb49);                        // h1_switcher8 -> h1_sb49::Bypassed
		h1_switcher8_p.getParameterT(3).connectT(0, h1_sb50);                        // h1_switcher8 -> h1_sb50::Bypassed
		h1_switcher8_p.getParameterT(4).connectT(0, h1_sb51);                        // h1_switcher8 -> h1_sb51::Bypassed
		h1_switcher8_p.getParameterT(5).connectT(0, h1_sb52);                        // h1_switcher8 -> h1_sb52::Bypassed
		h1_switcher8_p.getParameterT(6).connectT(0, h1_sb53);                        // h1_switcher8 -> h1_sb53::Bypassed
		h1_switcher8_p.getParameterT(7).connectT(0, h1_sb54);                        // h1_switcher8 -> h1_sb54::Bypassed
		h1_cable_table6.getWrappedObject().getParameter().connectT(0, h1_switcher8); // h1_cable_table6 -> h1_switcher8::Value
		auto& h1_switcher7_p = h1_switcher7.getWrappedObject().getParameter();
		h1_switcher7_p.getParameterT(0).connectT(0, h1_sb38);                        // h1_switcher7 -> h1_sb38::Bypassed
		h1_switcher7_p.getParameterT(1).connectT(0, h1_sb39);                        // h1_switcher7 -> h1_sb39::Bypassed
		h1_switcher7_p.getParameterT(2).connectT(0, h1_sb40);                        // h1_switcher7 -> h1_sb40::Bypassed
		h1_switcher7_p.getParameterT(3).connectT(0, h1_sb41);                        // h1_switcher7 -> h1_sb41::Bypassed
		h1_switcher7_p.getParameterT(4).connectT(0, h1_sb42);                        // h1_switcher7 -> h1_sb42::Bypassed
		h1_switcher7_p.getParameterT(5).connectT(0, h1_sb43);                        // h1_switcher7 -> h1_sb43::Bypassed
		h1_switcher7_p.getParameterT(6).connectT(0, h1_sb44);                        // h1_switcher7 -> h1_sb44::Bypassed
		h1_switcher7_p.getParameterT(7).connectT(0, h1_sb45);                        // h1_switcher7 -> h1_sb45::Bypassed
		h1_cable_table5.getWrappedObject().getParameter().connectT(0, h1_switcher7); // h1_cable_table5 -> h1_switcher7::Value
		auto& h1_switcher6_p = h1_switcher6.getWrappedObject().getParameter();
		h1_switcher6_p.getParameterT(0).connectT(0, h1_sb37); // h1_switcher6 -> h1_sb37::Bypassed
		h1_switcher6_p.getParameterT(1).connectT(0, h1_sb46); // h1_switcher6 -> h1_sb46::Bypassed
		auto& h1_switcher10_p = h1_switcher10.getWrappedObject().getParameter();
		h1_switcher10_p.getParameterT(0).connectT(0, h1_sb56);                        // h1_switcher10 -> h1_sb56::Bypassed
		h1_switcher10_p.getParameterT(1).connectT(0, h1_sb57);                        // h1_switcher10 -> h1_sb57::Bypassed
		h1_switcher10_p.getParameterT(2).connectT(0, h1_sb58);                        // h1_switcher10 -> h1_sb58::Bypassed
		h1_switcher10_p.getParameterT(3).connectT(0, h1_sb59);                        // h1_switcher10 -> h1_sb59::Bypassed
		h1_switcher10_p.getParameterT(4).connectT(0, h1_sb60);                        // h1_switcher10 -> h1_sb60::Bypassed
		h1_switcher10_p.getParameterT(5).connectT(0, h1_sb61);                        // h1_switcher10 -> h1_sb61::Bypassed
		h1_switcher10_p.getParameterT(6).connectT(0, h1_sb62);                        // h1_switcher10 -> h1_sb62::Bypassed
		h1_switcher10_p.getParameterT(7).connectT(0, h1_sb63);                        // h1_switcher10 -> h1_sb63::Bypassed
		h1_cable_table7.getWrappedObject().getParameter().connectT(0, h1_switcher10); // h1_cable_table7 -> h1_switcher10::Value
		auto& h1_switcher11_p = h1_switcher11.getWrappedObject().getParameter();
		h1_switcher11_p.getParameterT(0).connectT(0, h1_sb65);                        // h1_switcher11 -> h1_sb65::Bypassed
		h1_switcher11_p.getParameterT(1).connectT(0, h1_sb66);                        // h1_switcher11 -> h1_sb66::Bypassed
		h1_switcher11_p.getParameterT(2).connectT(0, h1_sb67);                        // h1_switcher11 -> h1_sb67::Bypassed
		h1_switcher11_p.getParameterT(3).connectT(0, h1_sb68);                        // h1_switcher11 -> h1_sb68::Bypassed
		h1_switcher11_p.getParameterT(4).connectT(0, h1_sb69);                        // h1_switcher11 -> h1_sb69::Bypassed
		h1_switcher11_p.getParameterT(5).connectT(0, h1_sb70);                        // h1_switcher11 -> h1_sb70::Bypassed
		h1_switcher11_p.getParameterT(6).connectT(0, h1_sb71);                        // h1_switcher11 -> h1_sb71::Bypassed
		h1_switcher11_p.getParameterT(7).connectT(0, h1_sb72);                        // h1_switcher11 -> h1_sb72::Bypassed
		h1_cable_table8.getWrappedObject().getParameter().connectT(0, h1_switcher11); // h1_cable_table8 -> h1_switcher11::Value
		auto& h1_switcher9_p = h1_switcher9.getWrappedObject().getParameter();
		h1_switcher9_p.getParameterT(0).connectT(0, h1_sb55); // h1_switcher9 -> h1_sb55::Bypassed
		h1_switcher9_p.getParameterT(1).connectT(0, h1_sb64); // h1_switcher9 -> h1_sb64::Bypassed
		auto& h1_switcher19_p = h1_switcher19.getWrappedObject().getParameter();
		h1_switcher19_p.getParameterT(0).connectT(0, h1_sb110);                        // h1_switcher19 -> h1_sb110::Bypassed
		h1_switcher19_p.getParameterT(1).connectT(0, h1_sb111);                        // h1_switcher19 -> h1_sb111::Bypassed
		h1_switcher19_p.getParameterT(2).connectT(0, h1_sb112);                        // h1_switcher19 -> h1_sb112::Bypassed
		h1_switcher19_p.getParameterT(3).connectT(0, h1_sb113);                        // h1_switcher19 -> h1_sb113::Bypassed
		h1_switcher19_p.getParameterT(4).connectT(0, h1_sb114);                        // h1_switcher19 -> h1_sb114::Bypassed
		h1_switcher19_p.getParameterT(5).connectT(0, h1_sb115);                        // h1_switcher19 -> h1_sb115::Bypassed
		h1_switcher19_p.getParameterT(6).connectT(0, h1_sb116);                        // h1_switcher19 -> h1_sb116::Bypassed
		h1_switcher19_p.getParameterT(7).connectT(0, h1_sb117);                        // h1_switcher19 -> h1_sb117::Bypassed
		h1_cable_table13.getWrappedObject().getParameter().connectT(0, h1_switcher19); // h1_cable_table13 -> h1_switcher19::Value
		auto& h1_switcher20_p = h1_switcher20.getWrappedObject().getParameter();
		h1_switcher20_p.getParameterT(0).connectT(0, h1_sb119);                        // h1_switcher20 -> h1_sb119::Bypassed
		h1_switcher20_p.getParameterT(1).connectT(0, h1_sb120);                        // h1_switcher20 -> h1_sb120::Bypassed
		h1_switcher20_p.getParameterT(2).connectT(0, h1_sb121);                        // h1_switcher20 -> h1_sb121::Bypassed
		h1_switcher20_p.getParameterT(3).connectT(0, h1_sb122);                        // h1_switcher20 -> h1_sb122::Bypassed
		h1_switcher20_p.getParameterT(4).connectT(0, h1_sb123);                        // h1_switcher20 -> h1_sb123::Bypassed
		h1_switcher20_p.getParameterT(5).connectT(0, h1_sb124);                        // h1_switcher20 -> h1_sb124::Bypassed
		h1_switcher20_p.getParameterT(6).connectT(0, h1_sb125);                        // h1_switcher20 -> h1_sb125::Bypassed
		h1_switcher20_p.getParameterT(7).connectT(0, h1_sb126);                        // h1_switcher20 -> h1_sb126::Bypassed
		h1_cable_table14.getWrappedObject().getParameter().connectT(0, h1_switcher20); // h1_cable_table14 -> h1_switcher20::Value
		auto& h1_switcher18_p = h1_switcher18.getWrappedObject().getParameter();
		h1_switcher18_p.getParameterT(0).connectT(0, h1_sb109); // h1_switcher18 -> h1_sb109::Bypassed
		h1_switcher18_p.getParameterT(1).connectT(0, h1_sb118); // h1_switcher18 -> h1_sb118::Bypassed
		auto& h1_switcher13_p = h1_switcher13.getWrappedObject().getParameter();
		h1_switcher13_p.getParameterT(0).connectT(0, h1_sb74);                        // h1_switcher13 -> h1_sb74::Bypassed
		h1_switcher13_p.getParameterT(1).connectT(0, h1_sb75);                        // h1_switcher13 -> h1_sb75::Bypassed
		h1_switcher13_p.getParameterT(2).connectT(0, h1_sb76);                        // h1_switcher13 -> h1_sb76::Bypassed
		h1_switcher13_p.getParameterT(3).connectT(0, h1_sb77);                        // h1_switcher13 -> h1_sb77::Bypassed
		h1_switcher13_p.getParameterT(4).connectT(0, h1_sb78);                        // h1_switcher13 -> h1_sb78::Bypassed
		h1_switcher13_p.getParameterT(5).connectT(0, h1_sb79);                        // h1_switcher13 -> h1_sb79::Bypassed
		h1_switcher13_p.getParameterT(6).connectT(0, h1_sb80);                        // h1_switcher13 -> h1_sb80::Bypassed
		h1_switcher13_p.getParameterT(7).connectT(0, h1_sb81);                        // h1_switcher13 -> h1_sb81::Bypassed
		h1_cable_table9.getWrappedObject().getParameter().connectT(0, h1_switcher13); // h1_cable_table9 -> h1_switcher13::Value
		auto& h1_switcher14_p = h1_switcher14.getWrappedObject().getParameter();
		h1_switcher14_p.getParameterT(0).connectT(0, h1_sb83);                         // h1_switcher14 -> h1_sb83::Bypassed
		h1_switcher14_p.getParameterT(1).connectT(0, h1_sb84);                         // h1_switcher14 -> h1_sb84::Bypassed
		h1_switcher14_p.getParameterT(2).connectT(0, h1_sb85);                         // h1_switcher14 -> h1_sb85::Bypassed
		h1_switcher14_p.getParameterT(3).connectT(0, h1_sb86);                         // h1_switcher14 -> h1_sb86::Bypassed
		h1_switcher14_p.getParameterT(4).connectT(0, h1_sb87);                         // h1_switcher14 -> h1_sb87::Bypassed
		h1_switcher14_p.getParameterT(5).connectT(0, h1_sb88);                         // h1_switcher14 -> h1_sb88::Bypassed
		h1_switcher14_p.getParameterT(6).connectT(0, h1_sb89);                         // h1_switcher14 -> h1_sb89::Bypassed
		h1_switcher14_p.getParameterT(7).connectT(0, h1_sb90);                         // h1_switcher14 -> h1_sb90::Bypassed
		h1_cable_table10.getWrappedObject().getParameter().connectT(0, h1_switcher14); // h1_cable_table10 -> h1_switcher14::Value
		auto& h1_switcher12_p = h1_switcher12.getWrappedObject().getParameter();
		h1_switcher12_p.getParameterT(0).connectT(0, h1_sb73); // h1_switcher12 -> h1_sb73::Bypassed
		h1_switcher12_p.getParameterT(1).connectT(0, h1_sb82); // h1_switcher12 -> h1_sb82::Bypassed
		auto& h1_switcher4_p = h1_switcher4.getWrappedObject().getParameter();
		h1_switcher4_p.getParameterT(0).connectT(0, h1_sb20);                  // h1_switcher4 -> h1_sb20::Bypassed
		h1_switcher4_p.getParameterT(1).connectT(0, h1_sb21);                  // h1_switcher4 -> h1_sb21::Bypassed
		h1_switcher4_p.getParameterT(2).connectT(0, h1_sb22);                  // h1_switcher4 -> h1_sb22::Bypassed
		h1_switcher4_p.getParameterT(3).connectT(0, h1_sb23);                  // h1_switcher4 -> h1_sb23::Bypassed
		h1_switcher4_p.getParameterT(4).connectT(0, h1_sb24);                  // h1_switcher4 -> h1_sb24::Bypassed
		h1_switcher4_p.getParameterT(5).connectT(0, h1_sb25);                  // h1_switcher4 -> h1_sb25::Bypassed
		h1_switcher4_p.getParameterT(6).connectT(0, h1_sb26);                  // h1_switcher4 -> h1_sb26::Bypassed
		pma2.getWrappedObject().getParameter().connectT(0, h1_switcher2);      // pma2 -> h1_switcher2::Value
		pma2.getWrappedObject().getParameter().connectT(1, h1_cable_table1);   // pma2 -> h1_cable_table1::Value
		pma2.getWrappedObject().getParameter().connectT(2, h1_cable_table2);   // pma2 -> h1_cable_table2::Value
		pma2.getWrappedObject().getParameter().connectT(3, h1_cable_table6);   // pma2 -> h1_cable_table6::Value
		pma2.getWrappedObject().getParameter().connectT(4, h1_switcher6);      // pma2 -> h1_switcher6::Value
		pma2.getWrappedObject().getParameter().connectT(5, h1_cable_table5);   // pma2 -> h1_cable_table5::Value
		pma2.getWrappedObject().getParameter().connectT(6, h1_switcher9);      // pma2 -> h1_switcher9::Value
		pma2.getWrappedObject().getParameter().connectT(7, h1_cable_table7);   // pma2 -> h1_cable_table7::Value
		pma2.getWrappedObject().getParameter().connectT(8, h1_cable_table8);   // pma2 -> h1_cable_table8::Value
		pma2.getWrappedObject().getParameter().connectT(9, h1_cable_table13);  // pma2 -> h1_cable_table13::Value
		pma2.getWrappedObject().getParameter().connectT(10, h1_switcher18);    // pma2 -> h1_switcher18::Value
		pma2.getWrappedObject().getParameter().connectT(11, h1_cable_table14); // pma2 -> h1_cable_table14::Value
		pma2.getWrappedObject().getParameter().connectT(12, h1_cable_table9);  // pma2 -> h1_cable_table9::Value
		pma2.getWrappedObject().getParameter().connectT(13, h1_switcher12);    // pma2 -> h1_switcher12::Value
		pma2.getWrappedObject().getParameter().connectT(14, h1_cable_table10); // pma2 -> h1_cable_table10::Value
		pma2.getWrappedObject().getParameter().connectT(15, h1_add82);         // pma2 -> h1_add82::Value
		pma2.getWrappedObject().getParameter().connectT(16, h1_switcher4);     // pma2 -> h1_switcher4::Value
		peak3.getParameter().connectT(0, pma2);                                // peak3 -> pma2::Value
		global_cable40.getWrappedObject().getParameter().connectT(0, add40);   // global_cable40 -> add40::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add33);   // global_cable33 -> add33::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add34);   // global_cable34 -> add34::Value
		global_cable35.getWrappedObject().getParameter().connectT(0, add35);   // global_cable35 -> add35::Value
		global_cable36.getWrappedObject().getParameter().connectT(0, add36);   // global_cable36 -> add36::Value
		global_cable37.getWrappedObject().getParameter().connectT(0, add37);   // global_cable37 -> add37::Value
		global_cable38.getWrappedObject().getParameter().connectT(0, add38);   // global_cable38 -> add38::Value
		global_cable39.getWrappedObject().getParameter().connectT(0, add39);   // global_cable39 -> add39::Value
		peak.getParameter().connectT(0, pma2);                                 // peak -> pma2::Add
		h1_peak3.getParameter().connectT(0, h1_add1);                          // h1_peak3 -> h1_add1::Value
		
		// Default Values --------------------------------------------------------------------------
		
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
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // branch5::Index is automated
		
		global_cable40.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add40::Value is automated
		
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
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // h1_branch::Index is automated
		
		; // h1_switcher2::Value is automated
		
		; // h1_cable_table1::Value is automated
		
		; // h1_switcher::Value is automated
		
		h1_add2.setParameterT(0, 0.); // math::add::Value
		
		h1_add4.setParameterT(0, 0.25); // math::add::Value
		
		h1_add3.setParameterT(0, 0.39625); // math::add::Value
		
		h1_add6.setParameterT(0, 0.5); // math::add::Value
		
		h1_add5.setParameterT(0, 0.5805); // math::add::Value
		
		h1_add8.setParameterT(0, 0.646); // math::add::Value
		
		h1_add7.setParameterT(0, 0.702); // math::add::Value
		
		h1_add9.setParameterT(0, 0.75); // math::add::Value
		
		h1_softbypass_switch10.setParameterT(0, 1.); // container::chain::Switch
		
		; // h1_cable_table2::Value is automated
		
		; // h1_switcher1::Value is automated
		
		h1_add10.setParameterT(0, 0.792); // math::add::Value
		
		h1_add11.setParameterT(0, 0.8305); // math::add::Value
		
		h1_add12.setParameterT(0, 0.865); // math::add::Value
		
		h1_add13.setParameterT(0, 0.896); // math::add::Value
		
		h1_add14.setParameterT(0, 0.925); // math::add::Value
		
		h1_add15.setParameterT(0, 0.9515); // math::add::Value
		
		h1_add16.setParameterT(0, 0.975); // math::add::Value
		
		h1_add17.setParameterT(0, 1.); // math::add::Value
		
		; // h1_switcher6::Value is automated
		
		; // h1_cable_table5::Value is automated
		
		; // h1_switcher7::Value is automated
		
		h1_add34.setParameterT(0, 0.); // math::add::Value
		
		h1_add35.setParameterT(0, 0.0417); // math::add::Value
		
		h1_add36.setParameterT(0, 0.0833); // math::add::Value
		
		h1_add37.setParameterT(0, 0.104189); // math::add::Value
		
		h1_add38.setParameterT(0, 0.1459); // math::add::Value
		
		h1_add39.setParameterT(0, 0.1876); // math::add::Value
		
		h1_add40.setParameterT(0, 0.2292); // math::add::Value
		
		h1_add41.setParameterT(0, 0.25); // math::add::Value
		
		; // h1_cable_table6::Value is automated
		
		; // h1_switcher8::Value is automated
		
		h1_add42.setParameterT(0, 0.2916); // math::add::Value
		
		h1_add43.setParameterT(0, 0.3334); // math::add::Value
		
		h1_add44.setParameterT(0, 0.3541); // math::add::Value
		
		h1_add45.setParameterT(0, 0.3958); // math::add::Value
		
		h1_add46.setParameterT(0, 0.4376); // math::add::Value
		
		h1_add47.setParameterT(0, 0.4791); // math::add::Value
		
		h1_add48.setParameterT(0, 0.5); // math::add::Value
		
		h1_add49.setParameterT(0, 0.5417); // math::add::Value
		
		; // h1_switcher9::Value is automated
		
		; // h1_cable_table7::Value is automated
		
		; // h1_switcher10::Value is automated
		
		h1_add50.setParameterT(0, 0.); // math::add::Value
		
		h1_add51.setParameterT(0, 0.0626); // math::add::Value
		
		h1_add52.setParameterT(0, 0.1458); // math::add::Value
		
		h1_add53.setParameterT(0, 0.2084); // math::add::Value
		
		h1_add54.setParameterT(0, 0.2501); // math::add::Value
		
		h1_add55.setParameterT(0, 0.3124); // math::add::Value
		
		h1_add56.setParameterT(0, 0.395911); // math::add::Value
		
		h1_add57.setParameterT(0, 0.4584); // math::add::Value
		
		; // h1_cable_table8::Value is automated
		
		; // h1_switcher11::Value is automated
		
		h1_add58.setParameterT(0, 0.5); // math::add::Value
		
		h1_add59.setParameterT(0, 0.56244); // math::add::Value
		
		h1_add60.setParameterT(0, 0.6458); // math::add::Value
		
		h1_add61.setParameterT(0, 0.6875); // math::add::Value
		
		h1_add62.setParameterT(0, 0.75); // math::add::Value
		
		h1_add63.setParameterT(0, 0.8125); // math::add::Value
		
		h1_add64.setParameterT(0, 0.8958); // math::add::Value
		
		h1_add65.setParameterT(0, 1.); // math::add::Value
		
		; // h1_switcher18::Value is automated
		
		; // h1_cable_table13::Value is automated
		
		; // h1_switcher19::Value is automated
		
		h1_add99.setParameterT(0, 0.); // math::add::Value
		
		h1_add100.setParameterT(0, 0.0417); // math::add::Value
		
		h1_add101.setParameterT(0, 0.0626); // math::add::Value
		
		h1_add102.setParameterT(0, 0.1042); // math::add::Value
		
		h1_add103.setParameterT(0, 0.1458); // math::add::Value
		
		h1_add104.setParameterT(0, 0.1876); // math::add::Value
		
		h1_add105.setParameterT(0, 0.2291); // math::add::Value
		
		h1_add106.setParameterT(0, 0.25); // math::add::Value
		
		; // h1_cable_table14::Value is automated
		
		; // h1_switcher20::Value is automated
		
		h1_add107.setParameterT(0, 0.2916); // math::add::Value
		
		h1_add108.setParameterT(0, 0.3124); // math::add::Value
		
		h1_add109.setParameterT(0, 0.3542); // math::add::Value
		
		h1_add110.setParameterT(0, 0.3959); // math::add::Value
		
		h1_add111.setParameterT(0, 0.4376); // math::add::Value
		
		h1_add112.setParameterT(0, 0.4792); // math::add::Value
		
		h1_add113.setParameterT(0, 0.5); // math::add::Value
		
		h1_add114.setParameterT(0, 0.5); // math::add::Value
		
		; // h1_switcher12::Value is automated
		
		; // h1_cable_table9::Value is automated
		
		; // h1_switcher13::Value is automated
		
		h1_add66.setParameterT(0, 0.); // math::add::Value
		
		h1_add67.setParameterT(0, 0.00754482); // math::add::Value
		
		h1_add68.setParameterT(0, 0.0163417); // math::add::Value
		
		h1_add69.setParameterT(0, 0.0311212); // math::add::Value
		
		h1_add70.setParameterT(0, 0.0376708); // math::add::Value
		
		h1_add71.setParameterT(0, 0.048629); // math::add::Value
		
		h1_add72.setParameterT(0, 0.059939); // math::add::Value
		
		h1_add73.setParameterT(0, 0.0681339); // math::add::Value
		
		; // h1_cable_table10::Value is automated
		
		; // h1_switcher14::Value is automated
		
		h1_add74.setParameterT(0, 0.0842896); // math::add::Value
		
		h1_add75.setParameterT(0, 0.0857338); // math::add::Value
		
		h1_add76.setParameterT(0, 0.104119); // math::add::Value
		
		h1_add77.setParameterT(0, 0.114154); // math::add::Value
		
		h1_add78.setParameterT(0, 0.123716); // math::add::Value
		
		h1_add79.setParameterT(0, 0.131463); // math::add::Value
		
		h1_add80.setParameterT(0, 0.144165); // math::add::Value
		
		h1_add81.setParameterT(0, 0.143979); // math::add::Value
		
		; // h1_switcher4::Value is automated
		
		h1_add18.setParameterT(0, 0.); // math::add::Value
		
		h1_add19.setParameterT(0, 0.1459); // math::add::Value
		
		h1_add20.setParameterT(0, 0.2916); // math::add::Value
		
		h1_add21.setParameterT(0, 0.4375); // math::add::Value
		
		h1_add22.setParameterT(0, 0.5834); // math::add::Value
		
		h1_add23.setParameterT(0, 0.7291); // math::add::Value
		
		h1_add24.setParameterT(0, 0.875); // math::add::Value
		
		; // h1_add82::Value is automated
		
		h1_clear.setParameterT(0, 0.); // math::clear::Value
		
		; // h1_add1::Value is automated
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);                 // Pitches_impl::global_cable24_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);                 // Pitches_impl::global_cable25_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);                 // Pitches_impl::global_cable26_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);                 // Pitches_impl::global_cable27_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);                 // Pitches_impl::global_cable28_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);                 // Pitches_impl::global_cable29_t<NV>
		this->getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);                 // Pitches_impl::global_cable30_t<NV>
		this->getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);                 // Pitches_impl::global_cable31_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Pitches_impl::global_cable40_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Pitches_impl::global_cable33_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // Pitches_impl::global_cable34_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // Pitches_impl::global_cable35_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // Pitches_impl::global_cable36_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // Pitches_impl::global_cable37_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // Pitches_impl::global_cable38_t<NV>
		this->getT(0).getT(3).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // Pitches_impl::global_cable39_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(1).setExternalData(b, index);                 // Pitches_impl::peak3_t<NV>
		this->getT(0).getT(3).getT(0).getT(1).setExternalData(b, index); // Pitches_impl::peak_t<NV>
		this->getT(0).getT(4).getT(1).getT(0).                           // Pitches_impl::h1_cable_table1_t<NV>
        getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(1).getT(0).                   // Pitches_impl::h1_cable_table2_t<NV>
        getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(1).getT(1).                   // Pitches_impl::h1_cable_table5_t<NV>
        getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(1).getT(1).                   // Pitches_impl::h1_cable_table6_t<NV>
        getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(1).getT(2).                   // Pitches_impl::h1_cable_table7_t<NV>
        getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(1).getT(2).                   // Pitches_impl::h1_cable_table8_t<NV>
        getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(1).getT(3).                   // Pitches_impl::h1_cable_table13_t<NV>
        getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(1).getT(3).                   // Pitches_impl::h1_cable_table14_t<NV>
        getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(1).getT(4).                   // Pitches_impl::h1_cable_table9_t<NV>
        getT(0).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(1).getT(4).                   // Pitches_impl::h1_cable_table10_t<NV>
        getT(0).getT(1).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(4).getT(2).setExternalData(b, index); // Pitches_impl::h1_peak3_t<NV>
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
using Pitches = wrap::node<Pitches_impl::instance<NV>>;
}


