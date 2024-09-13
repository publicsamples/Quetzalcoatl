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

namespace PreSliders2_impl
{
// ==============================| Node & Parameter type declarations |==============================

using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<4>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<3449326>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<3449327>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<3449328>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<3449329>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<3449330>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<3449331>;
using global_cable8_t_index = runtime_target::indexers::fix_hash<3449332>;
using global_cable9_t_index = runtime_target::indexers::fix_hash<3449333>;
using sliderbank_multimod = parameter::list<parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable3_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable4_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable5_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable6_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable7_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable8_t_index, parameter::empty>, 0>, 
                                            parameter::plain<routing::global_cable<global_cable9_t_index, parameter::empty>, 0>>;

using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod>, 
                                data::external::sliderpack<4>>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<sliderbank_t, 0>>;
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

using global_cable1_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable11_t<NV>>, 
                                  math::add<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable10_t<NV>>, 
                                  math::add<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable12_t<NV>>, 
                                  math::add<NV>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable13_t<NV>>, 
                                  math::add<NV>>;
using global_cable14_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable14_t<NV>>, 
                                  math::add<NV>>;
using global_cable15_t_index = runtime_target::indexers::fix_hash<104068263>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable15_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain2_t<NV>>, 
                                   chain3_t<NV>, 
                                   chain5_t<NV>, 
                                   chain4_t<NV>, 
                                   chain6_t<NV>, 
                                   chain7_t<NV>, 
                                   chain8_t<NV>, 
                                   chain9_t<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table11_modRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using cable_table11_mod = parameter::from0To1<branch_t<NV>, 
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
		0.999991f, 0.494382f
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
using peak_t = wrap::mod<parameter::plain<input_toggle1_t<NV>, 2>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, branch_t<NV>>, 
                                  peak_t<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, event_data_reader7_t<NV>>, 
                                  chain1_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table_t<NV>>, 
                                   cable_table11_t<NV>, 
                                   cable_table12_t<NV>, 
                                   split6_t<NV>, 
                                   input_toggle1_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, chain10_t<NV>>, 
                                 pma_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, chain_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, routing::global_cable<global_cable_t_index, parameter::empty>>, 
                                 routing::global_cable<global_cable3_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable4_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable5_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable6_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable7_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable8_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable9_t_index, parameter::empty>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, pack_resizer_t>, 
                                     fix8_block_t<NV>, 
                                     sliderbank_t, 
                                     split_t>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

namespace PreSliders2_t_parameters
{
// Parameter list for PreSliders2_impl::PreSliders2_t ----------------------------------------------

DECLARE_PARAMETER_RANGE(OffsetRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Offset = parameter::from0To1<PreSliders2_impl::pma_t<NV>, 
                                   2, 
                                   OffsetRange>;

DECLARE_PARAMETER_RANGE(modsrc_InputRange, 
                        0., 
                        16.);

template <int NV>
using modsrc = parameter::chain<modsrc_InputRange, 
                                parameter::plain<PreSliders2_impl::cable_table_t<NV>, 0>, 
                                parameter::plain<PreSliders2_impl::cable_table11_t<NV>, 0>, 
                                parameter::plain<PreSliders2_impl::cable_table12_t<NV>, 0>>;

using Pack = parameter::plain<PreSliders2_impl::pack_resizer_t, 
                              0>;
template <int NV>
using mod = parameter::plain<PreSliders2_impl::pma_t<NV>, 
                             1>;
template <int NV>
using PreSliders2_t_plist = parameter::list<Offset<NV>, 
                                            Pack, 
                                            mod<NV>, 
                                            modsrc<NV>>;
}

template <int NV>
using PreSliders2_t_ = container::chain<PreSliders2_t_parameters::PreSliders2_t_plist<NV>, 
                                        wrap::fix<2, modchain_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public PreSliders2_impl::PreSliders2_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 5;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(PreSliders2);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(62)
		{
			0x005B, 0x0000, 0x4F00, 0x6666, 0x6573, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x5000, 0x6361, 0x006B, 0x0000, 0x0000, 0x0000, 
            0x4300, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 
            0x0000, 0x6D00, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 
            0x6F6D, 0x7364, 0x6372, 0x0000, 0x0000, 0x0000, 0x8000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                   // PreSliders2_impl::modchain_t<NV>
		auto& pack_resizer = this->getT(0).getT(0);                                       // PreSliders2_impl::pack_resizer_t
		auto& fix8_block = this->getT(0).getT(1);                                         // PreSliders2_impl::fix8_block_t<NV>
		auto& chain = this->getT(0).getT(1).getT(0);                                      // PreSliders2_impl::chain_t<NV>
		auto& chain10 = this->getT(0).getT(1).getT(0).getT(0);                            // PreSliders2_impl::chain10_t<NV>
		auto& cable_table = this->getT(0).getT(1).getT(0).getT(0).getT(0);                // PreSliders2_impl::cable_table_t<NV>
		auto& cable_table11 = this->getT(0).getT(1).getT(0).getT(0).getT(1);              // PreSliders2_impl::cable_table11_t<NV>
		auto& cable_table12 = this->getT(0).getT(1).getT(0).getT(0).getT(2);              // PreSliders2_impl::cable_table12_t<NV>
		auto& split6 = this->getT(0).getT(1).getT(0).getT(0).getT(3);                     // PreSliders2_impl::split6_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(1).getT(0).getT(0).getT(3).getT(0); // PreSliders2_impl::event_data_reader7_t<NV>
		auto& chain1 = this->getT(0).getT(1).getT(0).getT(0).getT(3).getT(1);             // PreSliders2_impl::chain1_t<NV>
		auto& branch = this->getT(0).getT(1).getT(0).getT(0).getT(3).getT(1).getT(0);     // PreSliders2_impl::branch_t<NV>
		auto& chain2 = this->getT(0).getT(1).getT(0).getT(0).                             // PreSliders2_impl::chain2_t<NV>
                       getT(3).getT(1).getT(0).getT(0);
		auto& global_cable1 = this->getT(0).getT(1).getT(0).getT(0).                // PreSliders2_impl::global_cable1_t<NV>
                              getT(3).getT(1).getT(0).getT(0).
                              getT(0);
		auto& add = this->getT(0).getT(1).getT(0).getT(0).                          // math::add<NV>
                    getT(3).getT(1).getT(0).getT(0).
                    getT(1);
		auto& chain3 = this->getT(0).getT(1).getT(0).getT(0).                       // PreSliders2_impl::chain3_t<NV>
                       getT(3).getT(1).getT(0).getT(1);
		auto& global_cable2 = this->getT(0).getT(1).getT(0).getT(0).                // PreSliders2_impl::global_cable2_t<NV>
                              getT(3).getT(1).getT(0).getT(1).
                              getT(0);
		auto& add1 = this->getT(0).getT(1).getT(0).getT(0).                         // math::add<NV>
                     getT(3).getT(1).getT(0).getT(1).
                     getT(1);
		auto& chain5 = this->getT(0).getT(1).getT(0).getT(0).                       // PreSliders2_impl::chain5_t<NV>
                       getT(3).getT(1).getT(0).getT(2);
		auto& global_cable11 = this->getT(0).getT(1).getT(0).getT(0).               // PreSliders2_impl::global_cable11_t<NV>
                               getT(3).getT(1).getT(0).getT(2).
                               getT(0);
		auto& add3 = this->getT(0).getT(1).getT(0).getT(0).                         // math::add<NV>
                     getT(3).getT(1).getT(0).getT(2).
                     getT(1);
		auto& chain4 = this->getT(0).getT(1).getT(0).getT(0).                       // PreSliders2_impl::chain4_t<NV>
                       getT(3).getT(1).getT(0).getT(3);
		auto& global_cable10 = this->getT(0).getT(1).getT(0).getT(0).               // PreSliders2_impl::global_cable10_t<NV>
                               getT(3).getT(1).getT(0).getT(3).
                               getT(0);
		auto& add2 = this->getT(0).getT(1).getT(0).getT(0).                         // math::add<NV>
                     getT(3).getT(1).getT(0).getT(3).
                     getT(1);
		auto& chain6 = this->getT(0).getT(1).getT(0).getT(0).                       // PreSliders2_impl::chain6_t<NV>
                       getT(3).getT(1).getT(0).getT(4);
		auto& global_cable12 = this->getT(0).getT(1).getT(0).getT(0).               // PreSliders2_impl::global_cable12_t<NV>
                               getT(3).getT(1).getT(0).getT(4).
                               getT(0);
		auto& add4 = this->getT(0).getT(1).getT(0).getT(0).                         // math::add<NV>
                     getT(3).getT(1).getT(0).getT(4).
                     getT(1);
		auto& chain7 = this->getT(0).getT(1).getT(0).getT(0).                       // PreSliders2_impl::chain7_t<NV>
                       getT(3).getT(1).getT(0).getT(5);
		auto& global_cable13 = this->getT(0).getT(1).getT(0).getT(0).               // PreSliders2_impl::global_cable13_t<NV>
                               getT(3).getT(1).getT(0).getT(5).
                               getT(0);
		auto& add5 = this->getT(0).getT(1).getT(0).getT(0).                         // math::add<NV>
                     getT(3).getT(1).getT(0).getT(5).
                     getT(1);
		auto& chain8 = this->getT(0).getT(1).getT(0).getT(0).                       // PreSliders2_impl::chain8_t<NV>
                       getT(3).getT(1).getT(0).getT(6);
		auto& global_cable14 = this->getT(0).getT(1).getT(0).getT(0).               // PreSliders2_impl::global_cable14_t<NV>
                               getT(3).getT(1).getT(0).getT(6).
                               getT(0);
		auto& add6 = this->getT(0).getT(1).getT(0).getT(0).                         // math::add<NV>
                     getT(3).getT(1).getT(0).getT(6).
                     getT(1);
		auto& chain9 = this->getT(0).getT(1).getT(0).getT(0).                       // PreSliders2_impl::chain9_t<NV>
                       getT(3).getT(1).getT(0).getT(7);
		auto& global_cable15 = this->getT(0).getT(1).getT(0).getT(0).               // PreSliders2_impl::global_cable15_t<NV>
                               getT(3).getT(1).getT(0).getT(7).
                               getT(0);
		auto& add7 = this->getT(0).getT(1).getT(0).getT(0).                         // math::add<NV>
                     getT(3).getT(1).getT(0).getT(7).
                     getT(1);
		auto& peak = this->getT(0).getT(1).getT(0).getT(0).getT(3).getT(1).getT(1); // PreSliders2_impl::peak_t<NV>
		auto& input_toggle1 = this->getT(0).getT(1).getT(0).getT(0).getT(4);        // PreSliders2_impl::input_toggle1_t<NV>
		auto& pma = this->getT(0).getT(1).getT(0).getT(1);                          // PreSliders2_impl::pma_t<NV>
		auto& sliderbank = this->getT(0).getT(2);                                   // PreSliders2_impl::sliderbank_t
		auto& split = this->getT(0).getT(3);                                        // PreSliders2_impl::split_t
		auto& global_cable = this->getT(0).getT(3).getT(0);                         // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& global_cable3 = this->getT(0).getT(3).getT(1);                        // routing::global_cable<global_cable3_t_index, parameter::empty>
		auto& global_cable4 = this->getT(0).getT(3).getT(2);                        // routing::global_cable<global_cable4_t_index, parameter::empty>
		auto& global_cable5 = this->getT(0).getT(3).getT(3);                        // routing::global_cable<global_cable5_t_index, parameter::empty>
		auto& global_cable6 = this->getT(0).getT(3).getT(4);                        // routing::global_cable<global_cable6_t_index, parameter::empty>
		auto& global_cable7 = this->getT(0).getT(3).getT(5);                        // routing::global_cable<global_cable7_t_index, parameter::empty>
		auto& global_cable8 = this->getT(0).getT(3).getT(6);                        // routing::global_cable<global_cable8_t_index, parameter::empty>
		auto& global_cable9 = this->getT(0).getT(3).getT(7);                        // routing::global_cable<global_cable9_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma); // Offset -> pma::Add
		
		this->getParameterT(1).connectT(0, pack_resizer); // Pack -> pack_resizer::NumSliders
		
		this->getParameterT(2).connectT(0, pma); // mod -> pma::Multiply
		
		auto& modsrc_p = this->getParameterT(3);
		modsrc_p.connectT(0, cable_table);   // modsrc -> cable_table::Value
		modsrc_p.connectT(1, cable_table11); // modsrc -> cable_table11::Value
		modsrc_p.connectT(2, cable_table12); // modsrc -> cable_table12::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, global_cable);                       // sliderbank -> global_cable::Value
		sliderbank_p.getParameterT(1).connectT(0, global_cable3);                      // sliderbank -> global_cable3::Value
		sliderbank_p.getParameterT(2).connectT(0, global_cable4);                      // sliderbank -> global_cable4::Value
		sliderbank_p.getParameterT(3).connectT(0, global_cable5);                      // sliderbank -> global_cable5::Value
		sliderbank_p.getParameterT(4).connectT(0, global_cable6);                      // sliderbank -> global_cable6::Value
		sliderbank_p.getParameterT(5).connectT(0, global_cable7);                      // sliderbank -> global_cable7::Value
		sliderbank_p.getParameterT(6).connectT(0, global_cable8);                      // sliderbank -> global_cable8::Value
		sliderbank_p.getParameterT(7).connectT(0, global_cable9);                      // sliderbank -> global_cable9::Value
		pma.getWrappedObject().getParameter().connectT(0, sliderbank);                 // pma -> sliderbank::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, pma);              // input_toggle1 -> pma::Value
		event_data_reader7.getParameter().connectT(0, input_toggle1);                  // event_data_reader7 -> input_toggle1::Value1
		cable_table.getWrappedObject().getParameter().connectT(0, event_data_reader7); // cable_table -> event_data_reader7::SlotIndex
		global_cable1.getWrappedObject().getParameter().connectT(0, add);              // global_cable1 -> add::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add1);             // global_cable2 -> add1::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add3);            // global_cable11 -> add3::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add2);            // global_cable10 -> add2::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add4);            // global_cable12 -> add4::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add5);            // global_cable13 -> add5::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add6);            // global_cable14 -> add6::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add7);            // global_cable15 -> add7::Value
		cable_table11.getWrappedObject().getParameter().connectT(0, branch);           // cable_table11 -> branch::Index
		cable_table12.getWrappedObject().getParameter().connectT(0, input_toggle1);    // cable_table12 -> input_toggle1::Input
		peak.getParameter().connectT(0, input_toggle1);                                // peak -> input_toggle1::Value2
		
		// Default Values --------------------------------------------------------------------------
		
		; // pack_resizer::NumSliders is automated
		
		; // cable_table::Value is automated
		
		; // cable_table11::Value is automated
		
		; // cable_table12::Value is automated
		
		;                                        // event_data_reader7::SlotIndex is automated
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // branch::Index is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add1::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add3::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		; // input_toggle1::Input is automated
		; // input_toggle1::Value1 is automated
		; // input_toggle1::Value2 is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // sliderbank::Value is automated
		
		; // global_cable::Value is automated
		
		; // global_cable3::Value is automated
		
		; // global_cable4::Value is automated
		
		; // global_cable5::Value is automated
		
		; // global_cable6::Value is automated
		
		; // global_cable7::Value is automated
		
		; // global_cable8::Value is automated
		
		; // global_cable9::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
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
		
		this->getT(0).getT(1).getT(0).getT(0).                                  // PreSliders2_impl::global_cable1_t<NV>
        getT(3).getT(1).getT(0).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).                                  // PreSliders2_impl::global_cable2_t<NV>
        getT(3).getT(1).getT(0).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).                                  // PreSliders2_impl::global_cable11_t<NV>
        getT(3).getT(1).getT(0).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).                                  // PreSliders2_impl::global_cable10_t<NV>
        getT(3).getT(1).getT(0).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).                                  // PreSliders2_impl::global_cable12_t<NV>
        getT(3).getT(1).getT(0).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).                                  // PreSliders2_impl::global_cable13_t<NV>
        getT(3).getT(1).getT(0).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).                                  // PreSliders2_impl::global_cable14_t<NV>
        getT(3).getT(1).getT(0).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(1).getT(0).getT(0).                                  // PreSliders2_impl::global_cable15_t<NV>
        getT(3).getT(1).getT(0).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(0).getT(3).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable3_t_index, parameter::empty>
		this->getT(0).getT(3).getT(2).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable4_t_index, parameter::empty>
		this->getT(0).getT(3).getT(3).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable5_t_index, parameter::empty>
		this->getT(0).getT(3).getT(4).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable6_t_index, parameter::empty>
		this->getT(0).getT(3).getT(5).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable7_t_index, parameter::empty>
		this->getT(0).getT(3).getT(6).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable8_t_index, parameter::empty>
		this->getT(0).getT(3).getT(7).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable9_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).setExternalData(b, index);                                         // PreSliders2_impl::pack_resizer_t
		this->getT(0).getT(1).getT(0).getT(0).getT(0).setExternalData(b, index);                 // PreSliders2_impl::cable_table_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);                 // PreSliders2_impl::cable_table11_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(2).setExternalData(b, index);                 // PreSliders2_impl::cable_table12_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(3).getT(1).getT(1).setExternalData(b, index); // PreSliders2_impl::peak_t<NV>
		this->getT(0).getT(2).setExternalData(b, index);                                         // PreSliders2_impl::sliderbank_t
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
using PreSliders2 = wrap::node<PreSliders2_impl::instance<NV>>;
}


