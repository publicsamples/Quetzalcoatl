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

namespace WtMod1_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<math::add<NV>, 0>>;
template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 1>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter1_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<smoothed_parameter_t<NV>, 0>, 
                                 parameter::plain<smoothed_parameter1_t<NV>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using input_toggle1_t = control::input_toggle<parameter::plain<pma_t<NV>, 0>>;
template <int NV>
using event_data_reader7_t = wrap::mod<parameter::plain<input_toggle1_t<NV>, 1>, 
                                       routing::event_data_reader<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table_modRange, 
                             0., 
                             16., 
                             1.);

template <int NV>
using cable_table_mod = parameter::from0To1<event_data_reader7_t<NV>, 
                                            0, 
                                            cable_table_modRange>;

struct cable_table_t_data
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
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::embedded::table<cable_table_t_data>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain1_t<NV>>>;

template <int NV>
using sb1_t = bypass::smoothed<20, sb1_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb1_t<NV>>;

using global_cable2_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable2_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain2_t<NV>>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

using global_cable3_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable3_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb3_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain3_t<NV>>>;

template <int NV>
using sb3_t = bypass::smoothed<20, sb3_t_<NV>>;
template <int NV>
using switcher_c2 = parameter::bypass<sb3_t<NV>>;

using global_cable4_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable4_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb4_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain4_t<NV>>>;

template <int NV>
using sb4_t = bypass::smoothed<20, sb4_t_<NV>>;
template <int NV>
using switcher_c3 = parameter::bypass<sb4_t<NV>>;

using global_cable5_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable5_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb5_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain5_t<NV>>>;

template <int NV>
using sb5_t = bypass::smoothed<20, sb5_t_<NV>>;
template <int NV>
using switcher_c4 = parameter::bypass<sb5_t<NV>>;

using global_cable6_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable6_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb6_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain6_t<NV>>>;

template <int NV>
using sb6_t = bypass::smoothed<20, sb6_t_<NV>>;
template <int NV>
using switcher_c5 = parameter::bypass<sb6_t<NV>>;

using global_cable7_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable7_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb7_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain7_t<NV>>>;

template <int NV>
using sb7_t = bypass::smoothed<20, sb7_t_<NV>>;
template <int NV>
using switcher_c6 = parameter::bypass<sb7_t<NV>>;

using global_cable8_t_index = runtime_target::indexers::fix_hash<104068263>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable8_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using sb8_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain8_t<NV>>>;

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
                                        wrap::fix<2, sb1_t<NV>>, 
                                        sb2_t<NV>, 
                                        sb3_t<NV>, 
                                        sb4_t<NV>, 
                                        sb5_t<NV>, 
                                        sb6_t<NV>, 
                                        sb7_t<NV>, 
                                        sb8_t<NV>>;

template <int NV>
using peak_t = wrap::mod<parameter::plain<input_toggle1_t<NV>, 2>, 
                         wrap::no_data<core::peak>>;

namespace softbypass_switch9_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(Switch_InputRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using Switch = parameter::chain<Switch_InputRange, 
                                parameter::plain<WtMod1_impl::switcher_t<NV>, 0>>;

}

template <int NV>
using softbypass_switch9_t = container::chain<softbypass_switch9_t_parameters::Switch<NV>, 
                                              wrap::fix<2, switcher_t<NV>>, 
                                              sb_container_t<NV>, 
                                              peak_t<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table11_modRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using cable_table11_mod = parameter::from0To1<softbypass_switch9_t<NV>, 
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
using cable_table11_t = wrap::data<control::cable_table<cable_table11_mod<NV>>, 
                                   data::embedded::table<cable_table11_t_data>>;

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
using cable_table12_t = wrap::data<control::cable_table<parameter::plain<input_toggle1_t<NV>, 0>>, 
                                   data::embedded::table<cable_table12_t_data>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, event_data_reader7_t<NV>>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, softbypass_switch9_t<NV>>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, midichain_t<NV>>, 
                                  chain9_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table_t<NV>>, 
                                   cable_table11_t<NV>, 
                                   cable_table12_t<NV>, 
                                   split6_t<NV>, 
                                   input_toggle1_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, smoothed_parameter_t<NV>>, 
                                 smoothed_parameter1_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, chain10_t<NV>>, 
                                 pma_t<NV>, 
                                 split_t<NV>, 
                                 math::clear<NV>, 
                                 input_toggle_t<NV>, 
                                 math::add<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, chain_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

namespace WtMod1_t_parameters
{
// Parameter list for WtMod1_impl::WtMod1_t --------------------------------------------------------

DECLARE_PARAMETER_RANGE(modsrc_InputRange, 
                        0., 
                        16.);

template <int NV>
using modsrc = parameter::chain<modsrc_InputRange, 
                                parameter::plain<WtMod1_impl::cable_table11_t<NV>, 0>, 
                                parameter::plain<WtMod1_impl::cable_table12_t<NV>, 0>, 
                                parameter::plain<WtMod1_impl::cable_table_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(Pos_InputRange, 
                        5.55112e-17, 
                        0.99);
DECLARE_PARAMETER_RANGE(Pos_0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Pos_0 = parameter::from0To1<WtMod1_impl::pma_t<NV>, 
                                  2, 
                                  Pos_0Range>;

template <int NV>
using Pos = parameter::chain<Pos_InputRange, Pos_0<NV>>;

DECLARE_PARAMETER_RANGE(PosMod_InputRange, 
                        -0.99, 
                        0.99);
DECLARE_PARAMETER_RANGE(PosMod_0Range, 
                        -1., 
                        1.);

template <int NV>
using PosMod_0 = parameter::from0To1<WtMod1_impl::pma_t<NV>, 
                                     1, 
                                     PosMod_0Range>;

template <int NV>
using PosMod = parameter::chain<PosMod_InputRange, PosMod_0<NV>>;

template <int NV>
using Smooth = parameter::chain<ranges::Identity, 
                                parameter::plain<WtMod1_impl::smoothed_parameter_t<NV>, 1>, 
                                parameter::plain<WtMod1_impl::smoothed_parameter1_t<NV>, 1>>;

template <int NV>
using SmoothMode = parameter::plain<WtMod1_impl::input_toggle_t<NV>, 
                                    0>;
template <int NV>
using WtMod1_t_plist = parameter::list<modsrc<NV>, 
                                       Pos<NV>, 
                                       PosMod<NV>, 
                                       Smooth<NV>, 
                                       SmoothMode<NV>>;
}

template <int NV>
using WtMod1_t_ = container::chain<WtMod1_t_parameters::WtMod1_t_plist<NV>, 
                                   wrap::fix<2, fix8_block_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public WtMod1_impl::WtMod1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(WtMod1);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(82)
		{
			0x005B, 0x0000, 0x6D00, 0x646F, 0x7273, 0x0063, 0x0000, 0x0000, 
            0x0000, 0x4180, 0x6C8B, 0x4126, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x5000, 0x736F, 0x0000, 0x8000, 0xA424, 0x7D70, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 
            0x0000, 0x6F50, 0x4D73, 0x646F, 0xA400, 0x7D70, 0xA4BF, 0x7D70, 
            0xA43F, 0x7D70, 0x00BF, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 
            0x0000, 0x6D53, 0x6F6F, 0x6874, 0xCD00, 0xCCCC, 0x003D, 0x7A00, 
            0xCD44, 0xCCCC, 0x003D, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0004, 
            0x0000, 0x6D53, 0x6F6F, 0x6874, 0x6F4D, 0x6564, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);                                                   // WtMod1_impl::fix8_block_t<NV>
		auto& chain = this->getT(0).getT(0);                                                // WtMod1_impl::chain_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0);                                      // WtMod1_impl::chain10_t<NV>
		auto& cable_table = this->getT(0).getT(0).getT(0).getT(0);                          // WtMod1_impl::cable_table_t<NV>
		auto& cable_table11 = this->getT(0).getT(0).getT(0).getT(1);                        // WtMod1_impl::cable_table11_t<NV>
		auto& cable_table12 = this->getT(0).getT(0).getT(0).getT(2);                        // WtMod1_impl::cable_table12_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(0).getT(3);                               // WtMod1_impl::split6_t<NV>
		auto& midichain = this->getT(0).getT(0).getT(0).getT(3).getT(0);                    // WtMod1_impl::midichain_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);   // WtMod1_impl::event_data_reader7_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(3).getT(1);                       // WtMod1_impl::chain9_t<NV>
		auto& softbypass_switch9 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0);   // WtMod1_impl::softbypass_switch9_t<NV>
		auto& switcher = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0).getT(0);     // WtMod1_impl::switcher_t<NV>
		auto& sb_container = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0).getT(1); // WtMod1_impl::sb_container_t<NV>
		auto& sb1 = this->getT(0).getT(0).getT(0).getT(3).                                  // WtMod1_impl::sb1_t<NV>
                    getT(1).getT(0).getT(1).getT(0);
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(3).                       // WtMod1_impl::chain1_t<NV>
                       getT(1).getT(0).getT(1).getT(0).
                       getT(0);
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(3).getT(1).         // WtMod1_impl::global_cable_t<NV>
                             getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& add1 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // math::add<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& sb2 = this->getT(0).getT(0).getT(0).getT(3).                          // WtMod1_impl::sb2_t<NV>
                    getT(1).getT(0).getT(1).getT(1);
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(3).                       // WtMod1_impl::chain2_t<NV>
                       getT(1).getT(0).getT(1).getT(1).
                       getT(0);
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(3).getT(1).        // WtMod1_impl::global_cable2_t<NV>
                              getT(0).getT(1).getT(1).getT(0).getT(0);
		auto& add2 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // math::add<NV>
                     getT(0).getT(1).getT(1).getT(0).getT(1);
		auto& sb3 = this->getT(0).getT(0).getT(0).getT(3).                          // WtMod1_impl::sb3_t<NV>
                    getT(1).getT(0).getT(1).getT(2);
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(3).                       // WtMod1_impl::chain3_t<NV>
                       getT(1).getT(0).getT(1).getT(2).
                       getT(0);
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).        // WtMod1_impl::global_cable3_t<NV>
                              getT(0).getT(1).getT(2).getT(0).getT(0);
		auto& add3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // math::add<NV>
                     getT(0).getT(1).getT(2).getT(0).getT(1);
		auto& sb4 = this->getT(0).getT(0).getT(0).getT(3).                          // WtMod1_impl::sb4_t<NV>
                    getT(1).getT(0).getT(1).getT(3);
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(3).                       // WtMod1_impl::chain4_t<NV>
                       getT(1).getT(0).getT(1).getT(3).
                       getT(0);
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(3).getT(1).        // WtMod1_impl::global_cable4_t<NV>
                              getT(0).getT(1).getT(3).getT(0).getT(0);
		auto& add4 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // math::add<NV>
                     getT(0).getT(1).getT(3).getT(0).getT(1);
		auto& sb5 = this->getT(0).getT(0).getT(0).getT(3).                          // WtMod1_impl::sb5_t<NV>
                    getT(1).getT(0).getT(1).getT(4);
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(3).                       // WtMod1_impl::chain5_t<NV>
                       getT(1).getT(0).getT(1).getT(4).
                       getT(0);
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(3).getT(1).        // WtMod1_impl::global_cable5_t<NV>
                              getT(0).getT(1).getT(4).getT(0).getT(0);
		auto& add5 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // math::add<NV>
                     getT(0).getT(1).getT(4).getT(0).getT(1);
		auto& sb6 = this->getT(0).getT(0).getT(0).getT(3).                          // WtMod1_impl::sb6_t<NV>
                    getT(1).getT(0).getT(1).getT(5);
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(3).                       // WtMod1_impl::chain6_t<NV>
                       getT(1).getT(0).getT(1).getT(5).
                       getT(0);
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(3).getT(1).        // WtMod1_impl::global_cable6_t<NV>
                              getT(0).getT(1).getT(5).getT(0).getT(0);
		auto& add6 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // math::add<NV>
                     getT(0).getT(1).getT(5).getT(0).getT(1);
		auto& sb7 = this->getT(0).getT(0).getT(0).getT(3).                          // WtMod1_impl::sb7_t<NV>
                    getT(1).getT(0).getT(1).getT(6);
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(3).                       // WtMod1_impl::chain7_t<NV>
                       getT(1).getT(0).getT(1).getT(6).
                       getT(0);
		auto& global_cable7 = this->getT(0).getT(0).getT(0).getT(3).getT(1).        // WtMod1_impl::global_cable7_t<NV>
                              getT(0).getT(1).getT(6).getT(0).getT(0);
		auto& add7 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // math::add<NV>
                     getT(0).getT(1).getT(6).getT(0).getT(1);
		auto& sb8 = this->getT(0).getT(0).getT(0).getT(3).                          // WtMod1_impl::sb8_t<NV>
                    getT(1).getT(0).getT(1).getT(7);
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(3).                       // WtMod1_impl::chain8_t<NV>
                       getT(1).getT(0).getT(1).getT(7).
                       getT(0);
		auto& global_cable8 = this->getT(0).getT(0).getT(0).getT(3).getT(1).        // WtMod1_impl::global_cable8_t<NV>
                              getT(0).getT(1).getT(7).getT(0).getT(0);
		auto& add8 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // math::add<NV>
                     getT(0).getT(1).getT(7).getT(0).getT(1);
		auto& peak = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0).getT(2); // WtMod1_impl::peak_t<NV>
		auto& input_toggle1 = this->getT(0).getT(0).getT(0).getT(4);                // WtMod1_impl::input_toggle1_t<NV>
		auto& pma = this->getT(0).getT(0).getT(1);                                  // WtMod1_impl::pma_t<NV>
		auto& split = this->getT(0).getT(0).getT(2);                                // WtMod1_impl::split_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(0).getT(2).getT(0);           // WtMod1_impl::smoothed_parameter_t<NV>
		auto& smoothed_parameter1 = this->getT(0).getT(0).getT(2).getT(1);          // WtMod1_impl::smoothed_parameter1_t<NV>
		auto& clear = this->getT(0).getT(0).getT(3);                                // math::clear<NV>
		auto& input_toggle = this->getT(0).getT(0).getT(4);                         // WtMod1_impl::input_toggle_t<NV>
		auto& add = this->getT(0).getT(0).getT(5);                                  // math::add<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		softbypass_switch9.getParameterT(0).connectT(0, switcher); // Switch -> switcher::Value
		softbypass_switch9.getParameterT(0).connectT(0, switcher); // Switch -> switcher::Value
		auto& modsrc_p = this->getParameterT(0);
		modsrc_p.connectT(0, cable_table11); // modsrc -> cable_table11::Value
		modsrc_p.connectT(1, cable_table12); // modsrc -> cable_table12::Value
		modsrc_p.connectT(2, cable_table);   // modsrc -> cable_table::Value
		
		this->getParameterT(1).connectT(0, pma); // Pos -> pma::Add
		
		this->getParameterT(2).connectT(0, pma); // PosMod -> pma::Multiply
		
		auto& Smooth_p = this->getParameterT(3);
		Smooth_p.connectT(0, smoothed_parameter);  // Smooth -> smoothed_parameter::SmoothingTime
		Smooth_p.connectT(1, smoothed_parameter1); // Smooth -> smoothed_parameter1::SmoothingTime
		
		this->getParameterT(4).connectT(0, input_toggle); // SmoothMode -> input_toggle::Input
		
		// Modulation Connections ------------------------------------------------------------------
		
		input_toggle.getWrappedObject().getParameter().connectT(0, add);               // input_toggle -> add::Value
		smoothed_parameter.getParameter().connectT(0, input_toggle);                   // smoothed_parameter -> input_toggle::Value1
		smoothed_parameter1.getParameter().connectT(0, input_toggle);                  // smoothed_parameter1 -> input_toggle::Value2
		pma.getWrappedObject().getParameter().connectT(0, smoothed_parameter);         // pma -> smoothed_parameter::Value
		pma.getWrappedObject().getParameter().connectT(1, smoothed_parameter1);        // pma -> smoothed_parameter1::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, pma);              // input_toggle1 -> pma::Value
		event_data_reader7.getParameter().connectT(0, input_toggle1);                  // event_data_reader7 -> input_toggle1::Value1
		cable_table.getWrappedObject().getParameter().connectT(0, event_data_reader7); // cable_table -> event_data_reader7::SlotIndex
		global_cable.getWrappedObject().getParameter().connectT(0, add1);              // global_cable -> add1::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);             // global_cable2 -> add2::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add3);             // global_cable3 -> add3::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add4);             // global_cable4 -> add4::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add5);             // global_cable5 -> add5::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add6);             // global_cable6 -> add6::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add7);             // global_cable7 -> add7::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add8);             // global_cable8 -> add8::Value
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1);                                    // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2);                                    // switcher -> sb2::Bypassed
		switcher_p.getParameterT(2).connectT(0, sb3);                                    // switcher -> sb3::Bypassed
		switcher_p.getParameterT(3).connectT(0, sb4);                                    // switcher -> sb4::Bypassed
		switcher_p.getParameterT(4).connectT(0, sb5);                                    // switcher -> sb5::Bypassed
		switcher_p.getParameterT(5).connectT(0, sb6);                                    // switcher -> sb6::Bypassed
		switcher_p.getParameterT(6).connectT(0, sb7);                                    // switcher -> sb7::Bypassed
		switcher_p.getParameterT(7).connectT(0, sb8);                                    // switcher -> sb8::Bypassed
		peak.getParameter().connectT(0, input_toggle1);                                  // peak -> input_toggle1::Value2
		cable_table11.getWrappedObject().getParameter().connectT(0, softbypass_switch9); // cable_table11 -> softbypass_switch9::Switch
		cable_table12.getWrappedObject().getParameter().connectT(0, input_toggle1);      // cable_table12 -> input_toggle1::Input
		
		// Default Values --------------------------------------------------------------------------
		
		; // cable_table::Value is automated
		
		; // cable_table11::Value is automated
		
		; // cable_table12::Value is automated
		
		;                                        // event_data_reader7::SlotIndex is automated
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // softbypass_switch9::Switch is automated
		
		; // switcher::Value is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
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
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		; // input_toggle1::Input is automated
		; // input_toggle1::Value1 is automated
		; // input_toggle1::Value2 is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter1::Value is automated
		;                                         // smoothed_parameter1::SmoothingTime is automated
		smoothed_parameter1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		; // add::Value is automated
		
		this->setParameterT(0, 10.4015);
		this->setParameterT(1, 1.);
		this->setParameterT(2, -0.99);
		this->setParameterT(3, 0.1);
		this->setParameterT(4, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(3).getT(1).  // WtMod1_impl::global_cable_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).getT(1).  // WtMod1_impl::global_cable2_t<NV>
        getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).getT(1).  // WtMod1_impl::global_cable3_t<NV>
        getT(0).getT(1).getT(2).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).getT(1).  // WtMod1_impl::global_cable4_t<NV>
        getT(0).getT(1).getT(3).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).getT(1).  // WtMod1_impl::global_cable5_t<NV>
        getT(0).getT(1).getT(4).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).getT(1).  // WtMod1_impl::global_cable6_t<NV>
        getT(0).getT(1).getT(5).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).getT(1).  // WtMod1_impl::global_cable7_t<NV>
        getT(0).getT(1).getT(6).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(3).getT(1).  // WtMod1_impl::global_cable8_t<NV>
        getT(0).getT(1).getT(7).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);                         // WtMod1_impl::cable_table_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);                         // WtMod1_impl::cable_table11_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);                         // WtMod1_impl::cable_table12_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0).getT(2).setExternalData(b, index); // WtMod1_impl::peak_t<NV>
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
using WtMod1 = wrap::node<WtMod1_impl::instance<NV>>;
}


