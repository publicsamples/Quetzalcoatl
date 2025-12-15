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

namespace p1_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(pma1_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using pma1_mod = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     pma1_modRange>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using input_toggle3_t = control::input_toggle<NV, 
                                              parameter::plain<pma1_t<NV>, 0>>;
template <int NV>
using event_data_reader10_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 1>, 
                                        routing::event_data_reader<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table1_modRange, 
                             0., 
                             16., 
                             1.);

template <int NV>
using cable_table1_mod = parameter::from0To1<event_data_reader10_t<NV>, 
                                             0, 
                                             cable_table1_modRange>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		9.23872e-05f, 0.00206363f, 0.00403488f, 0.00600612f, 0.00797737f, 0.00994855f,
		0.0119198f, 0.013891f, 0.0158623f, 0.0178335f, 0.0198048f, 0.021776f,
		0.0237472f, 0.0257185f, 0.0276897f, 0.0296609f, 0.0316322f, 0.0336034f,
		0.0355746f, 0.0375459f, 0.0395171f, 0.0414883f, 0.0434596f, 0.0454308f,
		0.047402f, 0.0493733f, 0.0513445f, 0.0533158f, 0.055287f, 0.0572582f,
		0.0592294f, 0.0612007f, 0.0631719f, 0.0651432f, 0.0671144f, 0.0690856f,
		0.0710568f, 0.0730281f, 0.0749993f, 0.0769706f, 0.0789418f, 0.0809131f,
		0.0828843f, 0.0848555f, 0.0868267f, 0.088798f, 0.0907692f, 0.0927405f,
		0.0947117f, 0.0966829f, 0.0986542f, 0.100625f, 0.102597f, 0.104568f,
		0.106539f, 0.10851f, 0.110482f, 0.112453f, 0.114424f, 0.116395f,
		0.118366f, 0.120338f, 0.122309f, 0.12428f, 0.126251f, 0.128223f,
		0.130194f, 0.132165f, 0.134136f, 0.136108f, 0.138079f, 0.14005f,
		0.142021f, 0.143993f, 0.145964f, 0.147935f, 0.149906f, 0.151878f,
		0.153849f, 0.15582f, 0.157791f, 0.159762f, 0.161734f, 0.163705f,
		0.165676f, 0.167647f, 0.169619f, 0.17159f, 0.173561f, 0.175532f,
		0.177504f, 0.179475f, 0.181446f, 0.183417f, 0.185389f, 0.18736f,
		0.189331f, 0.191302f, 0.193273f, 0.195245f, 0.197216f, 0.199187f,
		0.201158f, 0.20313f, 0.205101f, 0.207072f, 0.209043f, 0.211015f,
		0.212986f, 0.214957f, 0.216928f, 0.218899f, 0.220871f, 0.222842f,
		0.224813f, 0.226784f, 0.228756f, 0.230727f, 0.232698f, 0.234669f,
		0.236641f, 0.238612f, 0.240583f, 0.242554f, 0.244526f, 0.246497f,
		0.248468f, 0.250439f, 0.252411f, 0.254382f, 0.256353f, 0.258324f,
		0.260295f, 0.262267f, 0.264238f, 0.266209f, 0.26818f, 0.270152f,
		0.272123f, 0.274094f, 0.276065f, 0.278037f, 0.280008f, 0.281979f,
		0.28395f, 0.285921f, 0.287893f, 0.289864f, 0.291835f, 0.293806f,
		0.295778f, 0.297749f, 0.29972f, 0.301691f, 0.303663f, 0.305634f,
		0.307605f, 0.309576f, 0.311548f, 0.313519f, 0.31549f, 0.317461f,
		0.319432f, 0.321404f, 0.323375f, 0.325346f, 0.327317f, 0.329289f,
		0.33126f, 0.333231f, 0.335202f, 0.337174f, 0.339145f, 0.341116f,
		0.343087f, 0.345059f, 0.34703f, 0.349001f, 0.350972f, 0.352943f,
		0.354915f, 0.356886f, 0.358857f, 0.360828f, 0.3628f, 0.364771f,
		0.366742f, 0.368713f, 0.370685f, 0.372656f, 0.374627f, 0.376598f,
		0.37857f, 0.380541f, 0.382512f, 0.384483f, 0.386454f, 0.388426f,
		0.390397f, 0.392368f, 0.394339f, 0.396311f, 0.398282f, 0.400253f,
		0.402224f, 0.404196f, 0.406167f, 0.408138f, 0.410109f, 0.412081f,
		0.414052f, 0.416023f, 0.417994f, 0.419965f, 0.421937f, 0.423908f,
		0.425879f, 0.42785f, 0.429822f, 0.431793f, 0.433764f, 0.435735f,
		0.437707f, 0.439678f, 0.441649f, 0.44362f, 0.445592f, 0.447563f,
		0.449534f, 0.451505f, 0.453476f, 0.455448f, 0.457419f, 0.45939f,
		0.461361f, 0.463333f, 0.465304f, 0.467275f, 0.469246f, 0.471218f,
		0.473189f, 0.47516f, 0.477131f, 0.479102f, 0.481074f, 0.483045f,
		0.485016f, 0.486987f, 0.488959f, 0.49093f, 0.492901f, 0.494872f,
		0.496844f, 0.498815f, 0.500786f, 0.502757f, 0.504729f, 0.506795f,
		0.508939f, 0.511084f, 0.513228f, 0.515372f, 0.517517f, 0.519661f,
		0.521805f, 0.52395f, 0.526094f, 0.528239f, 0.530383f, 0.532527f,
		0.534672f, 0.536816f, 0.53896f, 0.541105f, 0.543249f, 0.545393f,
		0.547538f, 0.549682f, 0.551827f, 0.553971f, 0.556115f, 0.55826f,
		0.560404f, 0.562548f, 0.564693f, 0.566837f, 0.568982f, 0.571126f,
		0.57327f, 0.575415f, 0.577559f, 0.579703f, 0.581848f, 0.583992f,
		0.586137f, 0.588281f, 0.590425f, 0.59257f, 0.594714f, 0.596858f,
		0.599003f, 0.601147f, 0.603292f, 0.605436f, 0.60758f, 0.609725f,
		0.611869f, 0.614013f, 0.616158f, 0.618302f, 0.620447f, 0.622591f,
		0.624735f, 0.62688f, 0.629024f, 0.631168f, 0.633313f, 0.635457f,
		0.637601f, 0.639746f, 0.64189f, 0.644035f, 0.646179f, 0.648323f,
		0.650468f, 0.652612f, 0.654756f, 0.656901f, 0.659045f, 0.661189f,
		0.663334f, 0.665478f, 0.667623f, 0.669767f, 0.671911f, 0.674056f,
		0.6762f, 0.678344f, 0.680489f, 0.682633f, 0.684778f, 0.686922f,
		0.689066f, 0.691211f, 0.693355f, 0.695499f, 0.697644f, 0.699788f,
		0.701933f, 0.704077f, 0.706221f, 0.708366f, 0.71051f, 0.712654f,
		0.714799f, 0.716943f, 0.719088f, 0.721232f, 0.723376f, 0.725521f,
		0.727665f, 0.729809f, 0.731954f, 0.734098f, 0.736243f, 0.738387f,
		0.740531f, 0.742676f, 0.74482f, 0.746964f, 0.749109f, 0.751253f,
		0.753397f, 0.755542f, 0.757686f, 0.759831f, 0.761975f, 0.764119f,
		0.766264f, 0.768408f, 0.770552f, 0.772697f, 0.774841f, 0.776986f,
		0.77913f, 0.781274f, 0.783419f, 0.785563f, 0.787707f, 0.789852f,
		0.791996f, 0.79414f, 0.796285f, 0.798429f, 0.800574f, 0.802718f,
		0.804862f, 0.807007f, 0.809151f, 0.811295f, 0.81344f, 0.815584f,
		0.817729f, 0.819873f, 0.822017f, 0.824162f, 0.826306f, 0.82845f,
		0.830595f, 0.832739f, 0.834883f, 0.837028f, 0.839172f, 0.841317f,
		0.843461f, 0.845605f, 0.84775f, 0.849894f, 0.852038f, 0.854183f,
		0.856327f, 0.858472f, 0.860616f, 0.86276f, 0.864905f, 0.867049f,
		0.869193f, 0.871338f, 0.873482f, 0.875627f, 0.877771f, 0.879915f,
		0.88206f, 0.884204f, 0.886348f, 0.888493f, 0.890637f, 0.892781f,
		0.894926f, 0.89707f, 0.899215f, 0.901359f, 0.903503f, 0.905648f,
		0.907792f, 0.909936f, 0.912081f, 0.914225f, 0.91637f, 0.918514f,
		0.920658f, 0.922803f, 0.924947f, 0.927091f, 0.929236f, 0.93138f,
		0.933524f, 0.935669f, 0.937813f, 0.939958f, 0.942102f, 0.944246f,
		0.946391f, 0.948535f, 0.950679f, 0.952824f, 0.954968f, 0.957113f,
		0.959257f, 0.961401f, 0.963546f, 0.96569f, 0.967834f, 0.969979f,
		0.972123f, 0.974268f, 0.976412f, 0.978556f, 0.980701f, 0.982845f,
		0.984989f, 0.987134f, 0.989278f, 0.991422f, 0.993567f, 0.995711f,
		0.997856f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::embedded::table<cable_table1_t_data>>;

using global_cable7_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, global_cable7_t<NV>>, 
                                math::add<NV>>;

template <int NV>
using sb1_t = bypass::smoothed<20, sb1_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb1_t<NV>>;

using global_cable8_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, global_cable8_t<NV>>, 
                                math::add<NV>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

using global_cable28_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using sb3_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, global_cable28_t<NV>>, 
                                math::add<NV>>;

template <int NV>
using sb3_t = bypass::smoothed<20, sb3_t_<NV>>;
template <int NV>
using switcher_c2 = parameter::bypass<sb3_t<NV>>;

using global_cable29_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using sb4_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, global_cable29_t<NV>>, 
                                math::add<NV>>;

template <int NV>
using sb4_t = bypass::smoothed<20, sb4_t_<NV>>;
template <int NV>
using switcher_c3 = parameter::bypass<sb4_t<NV>>;

using global_cable30_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using sb5_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, global_cable30_t<NV>>, 
                                math::add<NV>>;

template <int NV>
using sb5_t = bypass::smoothed<20, sb5_t_<NV>>;
template <int NV>
using switcher_c4 = parameter::bypass<sb5_t<NV>>;

using global_cable31_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using sb6_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, global_cable31_t<NV>>, 
                                math::add<NV>>;

template <int NV>
using sb6_t = bypass::smoothed<20, sb6_t_<NV>>;
template <int NV>
using switcher_c5 = parameter::bypass<sb6_t<NV>>;

using global_cable32_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using sb7_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, global_cable32_t<NV>>, 
                                math::add<NV>>;

template <int NV>
using sb7_t = bypass::smoothed<20, sb7_t_<NV>>;
template <int NV>
using switcher_c6 = parameter::bypass<sb7_t<NV>>;

using global_cable33_t_index = runtime_target::indexers::fix_hash<104068263>;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using sb8_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, global_cable33_t<NV>>, 
                                math::add<NV>>;

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

namespace softbypass_switch9_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(Switch_InputRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using Switch = parameter::chain<Switch_InputRange, 
                                parameter::plain<p1_impl::switcher_t<NV>, 0>>;

}

template <int NV>
using softbypass_switch9_t = container::chain<softbypass_switch9_t_parameters::Switch<NV>, 
                                              wrap::fix<1, math::clear<NV>>, 
                                              switcher_t<NV>, 
                                              sb_container_t<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table15_modRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using cable_table15_mod = parameter::from0To1<softbypass_switch9_t<NV>, 
                                              0, 
                                              cable_table15_modRange>;

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
using cable_table15_t = wrap::data<control::cable_table<cable_table15_mod<NV>>, 
                                   data::embedded::table<cable_table15_t_data>>;

struct cable_table16_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using cable_table16_t = wrap::data<control::cable_table<parameter::plain<input_toggle3_t<NV>, 0>>, 
                                   data::embedded::table<cable_table16_t_data>>;

template <int NV>
using peak3_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, softbypass_switch9_t<NV>>, 
                                  peak3_t<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader10_t<NV>>, 
                                  chain1_t<NV>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table1_t<NV>>, 
                                   cable_table15_t<NV>, 
                                   cable_table16_t<NV>, 
                                   split9_t<NV>, 
                                   math::clear<NV>, 
                                   input_toggle3_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, chain30_t<NV>>>;
using global_cable9_t_index = runtime_target::indexers::fix_hash<3449326>;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable9_t<NV>>, 
                                  math::add<NV>>;
using global_cable17_t_index = runtime_target::indexers::fix_hash<3449327>;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
using global_cable16_t_index = runtime_target::indexers::fix_hash<3449328>;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable15_t_index = runtime_target::indexers::fix_hash<3449329>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable15_t<NV>>, 
                                  math::add<NV>>;
using global_cable14_t_index = runtime_target::indexers::fix_hash<3449330>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable14_t<NV>>, 
                                  math::add<NV>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<3449331>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable13_t<NV>>, 
                                  math::add<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<3449332>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable12_t<NV>>, 
                                  math::add<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<3449333>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable11_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain2_t<NV>>, 
                                   chain11_t<NV>, 
                                   chain10_t<NV>, 
                                   chain9_t<NV>, 
                                   chain8_t<NV>, 
                                   chain7_t<NV>, 
                                   chain6_t<NV>, 
                                   chain5_t<NV>>;

DECLARE_PARAMETER_RANGE(peak_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using peak_mod = parameter::from0To1<pma1_t<NV>, 
                                     2, 
                                     peak_modRange>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, branch_t<NV>>, 
                                  peak_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, chain_t<NV>>, 
                                     chain3_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma1_t<NV>>, 
                                   core::gain<NV>>;

namespace p1_t_parameters
{
// Parameter list for p1_impl::p1_t ----------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(ModSrc_InputRange, 
                             0., 
                             16., 
                             0.1);

template <int NV>
using ModSrc = parameter::chain<ModSrc_InputRange, 
                                parameter::plain<p1_impl::cable_table1_t<NV>, 0>, 
                                parameter::plain<p1_impl::cable_table15_t<NV>, 0>, 
                                parameter::plain<p1_impl::cable_table16_t<NV>, 0>>;

template <int NV>
using Snap = parameter::from0To1<core::gain<NV>, 
                                 2, 
                                 p1_impl::pma1_modRange>;

template <int NV>
using Mod = parameter::plain<p1_impl::pma1_t<NV>, 1>;
template <int NV>
using STAGE = parameter::plain<p1_impl::branch_t<NV>, 0>;
template <int NV>
using p1_t_plist = parameter::list<Mod<NV>, 
                                   ModSrc<NV>, 
                                   STAGE<NV>, 
                                   Snap<NV>>;
}

template <int NV>
using p1_t_ = container::chain<p1_t_parameters::p1_t_plist<NV>, 
                               wrap::fix<2, modchain_t<NV>>, 
                               chain40_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public p1_impl::p1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(p1);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(66)
		{
			0x005C, 0x0000, 0x0000, 0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0100, 0x0000, 0x4D00, 0x646F, 0x7253, 0x0063, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x0041, 0x0000, 0x0000, 0x8000, 0xCD3F, 0xCCCC, 
            0x5C3D, 0x0200, 0x0000, 0x5300, 0x4154, 0x4547, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x40E0, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0003, 0x0000, 0x6E53, 0x7061, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000
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
		
		auto& modchain = this->getT(0);                                                     // p1_impl::modchain_t<NV>
		auto& chain = this->getT(0).getT(0);                                                // p1_impl::chain_t<NV>
		auto& chain30 = this->getT(0).getT(0).getT(0);                                      // p1_impl::chain30_t<NV>
		auto& cable_table1 = this->getT(0).getT(0).getT(0).getT(0);                         // p1_impl::cable_table1_t<NV>
		auto& cable_table15 = this->getT(0).getT(0).getT(0).getT(1);                        // p1_impl::cable_table15_t<NV>
		auto& cable_table16 = this->getT(0).getT(0).getT(0).getT(2);                        // p1_impl::cable_table16_t<NV>
		auto& split9 = this->getT(0).getT(0).getT(0).getT(3);                               // p1_impl::split9_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(0).getT(3).getT(0);          // p1_impl::event_data_reader10_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(3).getT(1);                       // p1_impl::chain1_t<NV>
		auto& softbypass_switch9 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0);   // p1_impl::softbypass_switch9_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0).getT(0);       // math::clear<NV>
		auto& switcher = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0).getT(1);     // p1_impl::switcher_t<NV>
		auto& sb_container = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0).getT(2); // p1_impl::sb_container_t<NV>
		auto& sb1 = this->getT(0).getT(0).getT(0).getT(3).                                  // p1_impl::sb1_t<NV>
                    getT(1).getT(0).getT(2).getT(0);
		auto& global_cable7 = this->getT(0).getT(0).getT(0).getT(3).          // p1_impl::global_cable7_t<NV>
                              getT(1).getT(0).getT(2).getT(0).
                              getT(0);
		auto& add24 = this->getT(0).getT(0).getT(0).getT(3).                  // math::add<NV>
                      getT(1).getT(0).getT(2).getT(0).
                      getT(1);
		auto& sb2 = this->getT(0).getT(0).getT(0).getT(3).                    // p1_impl::sb2_t<NV>
                    getT(1).getT(0).getT(2).getT(1);
		auto& global_cable8 = this->getT(0).getT(0).getT(0).getT(3).          // p1_impl::global_cable8_t<NV>
                              getT(1).getT(0).getT(2).getT(1).
                              getT(0);
		auto& add25 = this->getT(0).getT(0).getT(0).getT(3).                  // math::add<NV>
                      getT(1).getT(0).getT(2).getT(1).
                      getT(1);
		auto& sb3 = this->getT(0).getT(0).getT(0).getT(3).                    // p1_impl::sb3_t<NV>
                    getT(1).getT(0).getT(2).getT(2);
		auto& global_cable28 = this->getT(0).getT(0).getT(0).getT(3).         // p1_impl::global_cable28_t<NV>
                               getT(1).getT(0).getT(2).getT(2).
                               getT(0);
		auto& add26 = this->getT(0).getT(0).getT(0).getT(3).                  // math::add<NV>
                      getT(1).getT(0).getT(2).getT(2).
                      getT(1);
		auto& sb4 = this->getT(0).getT(0).getT(0).getT(3).                    // p1_impl::sb4_t<NV>
                    getT(1).getT(0).getT(2).getT(3);
		auto& global_cable29 = this->getT(0).getT(0).getT(0).getT(3).         // p1_impl::global_cable29_t<NV>
                               getT(1).getT(0).getT(2).getT(3).
                               getT(0);
		auto& add27 = this->getT(0).getT(0).getT(0).getT(3).                  // math::add<NV>
                      getT(1).getT(0).getT(2).getT(3).
                      getT(1);
		auto& sb5 = this->getT(0).getT(0).getT(0).getT(3).                    // p1_impl::sb5_t<NV>
                    getT(1).getT(0).getT(2).getT(4);
		auto& global_cable30 = this->getT(0).getT(0).getT(0).getT(3).         // p1_impl::global_cable30_t<NV>
                               getT(1).getT(0).getT(2).getT(4).
                               getT(0);
		auto& add28 = this->getT(0).getT(0).getT(0).getT(3).                  // math::add<NV>
                      getT(1).getT(0).getT(2).getT(4).
                      getT(1);
		auto& sb6 = this->getT(0).getT(0).getT(0).getT(3).                    // p1_impl::sb6_t<NV>
                    getT(1).getT(0).getT(2).getT(5);
		auto& global_cable31 = this->getT(0).getT(0).getT(0).getT(3).         // p1_impl::global_cable31_t<NV>
                               getT(1).getT(0).getT(2).getT(5).
                               getT(0);
		auto& add29 = this->getT(0).getT(0).getT(0).getT(3).                  // math::add<NV>
                      getT(1).getT(0).getT(2).getT(5).
                      getT(1);
		auto& sb7 = this->getT(0).getT(0).getT(0).getT(3).                    // p1_impl::sb7_t<NV>
                    getT(1).getT(0).getT(2).getT(6);
		auto& global_cable32 = this->getT(0).getT(0).getT(0).getT(3).         // p1_impl::global_cable32_t<NV>
                               getT(1).getT(0).getT(2).getT(6).
                               getT(0);
		auto& add30 = this->getT(0).getT(0).getT(0).getT(3).                  // math::add<NV>
                      getT(1).getT(0).getT(2).getT(6).
                      getT(1);
		auto& sb8 = this->getT(0).getT(0).getT(0).getT(3).                    // p1_impl::sb8_t<NV>
                    getT(1).getT(0).getT(2).getT(7);
		auto& global_cable33 = this->getT(0).getT(0).getT(0).getT(3).         // p1_impl::global_cable33_t<NV>
                               getT(1).getT(0).getT(2).getT(7).
                               getT(0);
		auto& add31 = this->getT(0).getT(0).getT(0).getT(3).                  // math::add<NV>
                      getT(1).getT(0).getT(2).getT(7).
                      getT(1);
		auto& peak3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1);  // p1_impl::peak3_t<NV>
		auto& clear = this->getT(0).getT(0).getT(0).getT(4);                  // math::clear<NV>
		auto& input_toggle3 = this->getT(0).getT(0).getT(0).getT(5);          // p1_impl::input_toggle3_t<NV>
		auto& chain3 = this->getT(0).getT(1);                                 // p1_impl::chain3_t<NV>
		auto& branch = this->getT(0).getT(1).getT(0);                         // p1_impl::branch_t<NV>
		auto& chain2 = this->getT(0).getT(1).getT(0).getT(0);                 // p1_impl::chain2_t<NV>
		auto& global_cable9 = this->getT(0).getT(1).getT(0).getT(0).getT(0);  // p1_impl::global_cable9_t<NV>
		auto& add = this->getT(0).getT(1).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain11 = this->getT(0).getT(1).getT(0).getT(1);                // p1_impl::chain11_t<NV>
		auto& global_cable17 = this->getT(0).getT(1).getT(0).getT(1).getT(0); // p1_impl::global_cable17_t<NV>
		auto& add8 = this->getT(0).getT(1).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain10 = this->getT(0).getT(1).getT(0).getT(2);                // p1_impl::chain10_t<NV>
		auto& global_cable16 = this->getT(0).getT(1).getT(0).getT(2).getT(0); // p1_impl::global_cable16_t<NV>
		auto& add7 = this->getT(0).getT(1).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain9 = this->getT(0).getT(1).getT(0).getT(3);                 // p1_impl::chain9_t<NV>
		auto& global_cable15 = this->getT(0).getT(1).getT(0).getT(3).getT(0); // p1_impl::global_cable15_t<NV>
		auto& add6 = this->getT(0).getT(1).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain8 = this->getT(0).getT(1).getT(0).getT(4);                 // p1_impl::chain8_t<NV>
		auto& global_cable14 = this->getT(0).getT(1).getT(0).getT(4).getT(0); // p1_impl::global_cable14_t<NV>
		auto& add5 = this->getT(0).getT(1).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain7 = this->getT(0).getT(1).getT(0).getT(5);                 // p1_impl::chain7_t<NV>
		auto& global_cable13 = this->getT(0).getT(1).getT(0).getT(5).getT(0); // p1_impl::global_cable13_t<NV>
		auto& add4 = this->getT(0).getT(1).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain6 = this->getT(0).getT(1).getT(0).getT(6);                 // p1_impl::chain6_t<NV>
		auto& global_cable12 = this->getT(0).getT(1).getT(0).getT(6).getT(0); // p1_impl::global_cable12_t<NV>
		auto& add3 = this->getT(0).getT(1).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain5 = this->getT(0).getT(1).getT(0).getT(7);                 // p1_impl::chain5_t<NV>
		auto& global_cable11 = this->getT(0).getT(1).getT(0).getT(7).getT(0); // p1_impl::global_cable11_t<NV>
		auto& add2 = this->getT(0).getT(1).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& peak = this->getT(0).getT(1).getT(1);                           // p1_impl::peak_t<NV>
		auto& chain40 = this->getT(1);                                        // p1_impl::chain40_t<NV>
		auto& pma1 = this->getT(1).getT(0);                                   // p1_impl::pma1_t<NV>
		auto& gain1 = this->getT(1).getT(1);                                  // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		softbypass_switch9.getParameterT(0).connectT(0, switcher); // Switch -> switcher::Value
		softbypass_switch9.getParameterT(0).connectT(0, switcher); // Switch -> switcher::Value
		this->getParameterT(0).connectT(0, pma1);                  // Mod -> pma1::Multiply
		
		auto& ModSrc_p = this->getParameterT(1);
		ModSrc_p.connectT(0, cable_table1);  // ModSrc -> cable_table1::Value
		ModSrc_p.connectT(1, cable_table15); // ModSrc -> cable_table15::Value
		ModSrc_p.connectT(2, cable_table16); // ModSrc -> cable_table16::Value
		
		this->getParameterT(2).connectT(0, branch); // STAGE -> branch::Index
		
		this->getParameterT(3).connectT(0, gain1); // Snap -> gain1::ResetValue
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma1.getWrappedObject().getParameter().connectT(0, gain1);                       // pma1 -> gain1::Gain
		input_toggle3.getWrappedObject().getParameter().connectT(0, pma1);               // input_toggle3 -> pma1::Value
		event_data_reader10.getParameter().connectT(0, input_toggle3);                   // event_data_reader10 -> input_toggle3::Value1
		cable_table1.getWrappedObject().getParameter().connectT(0, event_data_reader10); // cable_table1 -> event_data_reader10::SlotIndex
		global_cable7.getWrappedObject().getParameter().connectT(0, add24);              // global_cable7 -> add24::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add25);              // global_cable8 -> add25::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add26);             // global_cable28 -> add26::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add27);             // global_cable29 -> add27::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add28);             // global_cable30 -> add28::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add29);             // global_cable31 -> add29::Value
		global_cable32.getWrappedObject().getParameter().connectT(0, add30);             // global_cable32 -> add30::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add31);             // global_cable33 -> add31::Value
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1);                                    // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2);                                    // switcher -> sb2::Bypassed
		switcher_p.getParameterT(2).connectT(0, sb3);                                    // switcher -> sb3::Bypassed
		switcher_p.getParameterT(3).connectT(0, sb4);                                    // switcher -> sb4::Bypassed
		switcher_p.getParameterT(4).connectT(0, sb5);                                    // switcher -> sb5::Bypassed
		switcher_p.getParameterT(5).connectT(0, sb6);                                    // switcher -> sb6::Bypassed
		switcher_p.getParameterT(6).connectT(0, sb7);                                    // switcher -> sb7::Bypassed
		switcher_p.getParameterT(7).connectT(0, sb8);                                    // switcher -> sb8::Bypassed
		cable_table15.getWrappedObject().getParameter().connectT(0, softbypass_switch9); // cable_table15 -> softbypass_switch9::Switch
		cable_table16.getWrappedObject().getParameter().connectT(0, input_toggle3);      // cable_table16 -> input_toggle3::Input
		peak3.getParameter().connectT(0, input_toggle3);                                 // peak3 -> input_toggle3::Value2
		global_cable9.getWrappedObject().getParameter().connectT(0, add);                // global_cable9 -> add::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add8);              // global_cable17 -> add8::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add7);              // global_cable16 -> add7::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add6);              // global_cable15 -> add6::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add5);              // global_cable14 -> add5::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add4);              // global_cable13 -> add4::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add3);              // global_cable12 -> add3::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add2);              // global_cable11 -> add2::Value
		peak.getParameter().connectT(0, pma1);                                           // peak -> pma1::Add
		
		// Default Values --------------------------------------------------------------------------
		
		; // cable_table1::Value is automated
		
		; // cable_table15::Value is automated
		
		; // cable_table16::Value is automated
		
		;                                         // event_data_reader10::SlotIndex is automated
		event_data_reader10.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // softbypass_switch9::Switch is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // switcher::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add24::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add25::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // input_toggle3::Input is automated
		; // input_toggle3::Value1 is automated
		; // input_toggle3::Value2 is automated
		
		; // branch::Index is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add3::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 0.9); // core::gain::Smoothing
		;                            // gain1::ResetValue is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(3).                                                  // p1_impl::global_cable7_t<NV>
        getT(1).getT(0).getT(2).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).                                                  // p1_impl::global_cable8_t<NV>
        getT(1).getT(0).getT(2).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).                                                  // p1_impl::global_cable28_t<NV>
        getT(1).getT(0).getT(2).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).                                                  // p1_impl::global_cable29_t<NV>
        getT(1).getT(0).getT(2).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).                                                  // p1_impl::global_cable30_t<NV>
        getT(1).getT(0).getT(2).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).                                                  // p1_impl::global_cable31_t<NV>
        getT(1).getT(0).getT(2).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).                                                  // p1_impl::global_cable32_t<NV>
        getT(1).getT(0).getT(2).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).                                                  // p1_impl::global_cable33_t<NV>
        getT(1).getT(0).getT(2).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // p1_impl::global_cable9_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // p1_impl::global_cable17_t<NV>
		this->getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // p1_impl::global_cable16_t<NV>
		this->getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // p1_impl::global_cable15_t<NV>
		this->getT(0).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // p1_impl::global_cable14_t<NV>
		this->getT(0).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // p1_impl::global_cable13_t<NV>
		this->getT(0).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // p1_impl::global_cable12_t<NV>
		this->getT(0).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // p1_impl::global_cable11_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);                 // p1_impl::cable_table1_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);                 // p1_impl::cable_table15_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);                 // p1_impl::cable_table16_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1).setExternalData(b, index); // p1_impl::peak3_t<NV>
		this->getT(0).getT(1).getT(1).setExternalData(b, index);                         // p1_impl::peak_t<NV>
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
using p1 = wrap::node<p1_impl::instance<NV>>;
}


