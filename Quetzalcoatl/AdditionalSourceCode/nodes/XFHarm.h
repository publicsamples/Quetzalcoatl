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

namespace XFHarm_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using ahdsr_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                       parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;
template <int NV>
using input_toggle8_t = control::input_toggle<parameter::plain<ahdsr_t<NV>, 8>>;

template <int NV>
using cable_pack2_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<8>>;

struct cable_table5_t_data
{
	span<float, 512> data =
	{
		0.f, 7.689e-06f, 0.00393695f, 0.00786614f, 0.0117954f, 0.0157247f,
		0.0196539f, 0.0235831f, 0.0275124f, 0.0314416f, 0.0353709f, 0.0393001f,
		0.0432293f, 0.0471586f, 0.0510879f, 0.0550171f, 0.0589463f, 0.0628756f,
		0.0668048f, 0.070734f, 0.0746633f, 0.0785925f, 0.0825218f, 0.086451f,
		0.0903803f, 0.0943095f, 0.0982388f, 0.102168f, 0.106097f, 0.110026f,
		0.113956f, 0.117885f, 0.121814f, 0.125743f, 0.129673f, 0.133602f,
		0.137531f, 0.14146f, 0.14539f, 0.149319f, 0.153248f, 0.157177f,
		0.161107f, 0.165036f, 0.168965f, 0.172894f, 0.176824f, 0.180753f,
		0.184682f, 0.188611f, 0.192541f, 0.19647f, 0.200399f, 0.204328f,
		0.208258f, 0.212187f, 0.216116f, 0.220045f, 0.223975f, 0.227904f,
		0.231833f, 0.235762f, 0.239691f, 0.243621f, 0.24755f, 0.251479f,
		0.255408f, 0.259338f, 0.263267f, 0.267196f, 0.271125f, 0.275055f,
		0.278984f, 0.282913f, 0.286842f, 0.290772f, 0.294701f, 0.29863f,
		0.302559f, 0.306489f, 0.310418f, 0.314347f, 0.318276f, 0.322206f,
		0.326135f, 0.330064f, 0.333993f, 0.337923f, 0.341852f, 0.345781f,
		0.34971f, 0.35364f, 0.357569f, 0.361498f, 0.365427f, 0.369357f,
		0.373286f, 0.377215f, 0.381144f, 0.385074f, 0.389003f, 0.392932f,
		0.396861f, 0.40079f, 0.40472f, 0.408649f, 0.412578f, 0.416507f,
		0.420437f, 0.424366f, 0.428295f, 0.432224f, 0.436154f, 0.440083f,
		0.444012f, 0.447941f, 0.451871f, 0.4558f, 0.459729f, 0.463658f,
		0.467588f, 0.471517f, 0.475446f, 0.479375f, 0.483305f, 0.487234f,
		0.491163f, 0.495092f, 0.499022f, 0.502951f, 0.50688f, 0.510809f,
		0.514739f, 0.518668f, 0.522597f, 0.526526f, 0.530455f, 0.534385f,
		0.538314f, 0.542243f, 0.546172f, 0.550102f, 0.554031f, 0.55796f,
		0.561889f, 0.565819f, 0.569748f, 0.573677f, 0.577606f, 0.581536f,
		0.585465f, 0.589394f, 0.593323f, 0.597253f, 0.601182f, 0.605111f,
		0.60904f, 0.61297f, 0.616899f, 0.620828f, 0.624757f, 0.628687f,
		0.632616f, 0.636545f, 0.640474f, 0.644404f, 0.648333f, 0.652262f,
		0.656191f, 0.66012f, 0.66405f, 0.667979f, 0.671908f, 0.675837f,
		0.679767f, 0.683696f, 0.687625f, 0.691554f, 0.695484f, 0.699413f,
		0.703342f, 0.707271f, 0.711201f, 0.71513f, 0.719059f, 0.722988f,
		0.726918f, 0.730847f, 0.734776f, 0.738705f, 0.742635f, 0.746564f,
		0.750493f, 0.754422f, 0.758352f, 0.762281f, 0.76621f, 0.770139f,
		0.774069f, 0.777998f, 0.781927f, 0.785856f, 0.789786f, 0.793715f,
		0.797644f, 0.801573f, 0.805503f, 0.809432f, 0.813361f, 0.81729f,
		0.82122f, 0.825149f, 0.829078f, 0.833007f, 0.836936f, 0.840866f,
		0.844795f, 0.848724f, 0.852653f, 0.856583f, 0.860512f, 0.864441f,
		0.86837f, 0.8723f, 0.876229f, 0.880158f, 0.884087f, 0.888017f,
		0.891946f, 0.895875f, 0.899804f, 0.903734f, 0.907663f, 0.911592f,
		0.915521f, 0.919451f, 0.92338f, 0.927309f, 0.931238f, 0.935167f,
		0.939097f, 0.943026f, 0.946955f, 0.950885f, 0.954814f, 0.958743f,
		0.962672f, 0.966601f, 0.970531f, 0.97446f, 0.978389f, 0.982318f,
		0.986248f, 0.990177f, 0.994106f, 0.998035f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using cable_table5_t = wrap::data<control::cable_table<parameter::plain<cable_pack2_t<NV>, 0>>, 
                                  data::embedded::table<cable_table5_t_data>>;

template <int NV>
using cable_pack1_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<9>>;

struct cable_table10_t_data
{
	span<float, 512> data =
	{
		1.f, 0.999957f, 0.999913f, 0.99987f, 0.999826f, 0.999783f,
		0.999739f, 0.999696f, 0.999652f, 0.999609f, 0.999565f, 0.999522f,
		0.999478f, 0.999435f, 0.999391f, 0.999348f, 0.999305f, 0.999261f,
		0.999218f, 0.999174f, 0.999131f, 0.999087f, 0.999044f, 0.999f,
		0.998957f, 0.998913f, 0.99887f, 0.998826f, 0.998783f, 0.998739f,
		0.998696f, 0.998653f, 0.998609f, 0.998566f, 0.998522f, 0.998479f,
		0.998435f, 0.998392f, 0.998348f, 0.998305f, 0.998261f, 0.998218f,
		0.998174f, 0.998131f, 0.998087f, 0.998044f, 0.998001f, 0.997957f,
		0.997914f, 0.99787f, 0.997827f, 0.997783f, 0.99774f, 0.997696f,
		0.997653f, 0.997609f, 0.997566f, 0.997522f, 0.997479f, 0.997435f,
		0.997392f, 0.997348f, 0.997305f, 0.997262f, 0.997218f, 0.997175f,
		0.997131f, 0.997088f, 0.997044f, 0.997001f, 0.996957f, 0.996914f,
		0.99687f, 0.996827f, 0.996783f, 0.99674f, 0.996697f, 0.996653f,
		0.99661f, 0.996566f, 0.996523f, 0.996479f, 0.996436f, 0.996392f,
		0.996349f, 0.996305f, 0.996262f, 0.996218f, 0.996175f, 0.996131f,
		0.996088f, 0.996045f, 0.996001f, 0.995958f, 0.995914f, 0.995871f,
		0.995827f, 0.995784f, 0.99574f, 0.995697f, 0.995653f, 0.99561f,
		0.995566f, 0.995523f, 0.995479f, 0.995436f, 0.995393f, 0.995349f,
		0.995306f, 0.995262f, 0.995219f, 0.995175f, 0.995132f, 0.995088f,
		0.995045f, 0.995001f, 0.994958f, 0.994914f, 0.994871f, 0.994827f,
		0.994784f, 0.99474f, 0.994697f, 0.994654f, 0.99461f, 0.994567f,
		0.994523f, 0.99448f, 0.994436f, 0.994393f, 0.994349f, 0.994306f,
		0.994262f, 0.994219f, 0.994175f, 0.994132f, 0.994088f, 0.994045f,
		0.994002f, 0.993958f, 0.993915f, 0.993871f, 0.993828f, 0.993784f,
		0.993741f, 0.993697f, 0.993654f, 0.99361f, 0.993567f, 0.993523f,
		0.99348f, 0.993437f, 0.993393f, 0.99335f, 0.993306f, 0.993263f,
		0.993219f, 0.993176f, 0.993132f, 0.993089f, 0.993045f, 0.993002f,
		0.992958f, 0.992915f, 0.992871f, 0.992828f, 0.992785f, 0.992741f,
		0.992698f, 0.992654f, 0.992611f, 0.992567f, 0.992524f, 0.99248f,
		0.992437f, 0.992393f, 0.99235f, 0.992306f, 0.992263f, 0.992219f,
		0.992176f, 0.992132f, 0.992089f, 0.992046f, 0.992002f, 0.991959f,
		0.991915f, 0.991872f, 0.991828f, 0.991785f, 0.991741f, 0.991698f,
		0.991654f, 0.991611f, 0.991567f, 0.991524f, 0.99148f, 0.991437f,
		0.991394f, 0.99135f, 0.991307f, 0.991263f, 0.99122f, 0.991176f,
		0.991133f, 0.991089f, 0.991046f, 0.991002f, 0.990959f, 0.990915f,
		0.990872f, 0.990828f, 0.990785f, 0.990742f, 0.990698f, 0.990655f,
		0.990611f, 0.990568f, 0.990524f, 0.990481f, 0.990437f, 0.990394f,
		0.99035f, 0.990307f, 0.990263f, 0.99022f, 0.990176f, 0.990133f,
		0.99009f, 0.990046f, 0.990003f, 0.989959f, 0.989916f, 0.989872f,
		0.989829f, 0.989785f, 0.989742f, 0.989698f, 0.989655f, 0.989611f,
		0.989568f, 0.989524f, 0.989481f, 0.989438f, 0.989394f, 0.989351f,
		0.989307f, 0.989264f, 0.98922f, 0.989177f, 0.989133f, 0.98909f,
		0.989046f, 0.989003f, 0.988959f, 0.988916f, 0.988872f, 0.988829f,
		0.988786f, 0.00200331f, 0.00596374f, 0.00992399f, 0.0138843f, 0.0178446f,
		0.0218049f, 0.0257652f, 0.0297254f, 0.0336857f, 0.0376462f, 0.0416064f,
		0.0455667f, 0.049527f, 0.0534873f, 0.0574476f, 0.0614079f, 0.0653682f,
		0.0693285f, 0.0732889f, 0.0772492f, 0.0812094f, 0.0851697f, 0.08913f,
		0.0930903f, 0.0970506f, 0.101011f, 0.104971f, 0.108932f, 0.112892f,
		0.116852f, 0.120812f, 0.124773f, 0.128733f, 0.132693f, 0.136654f,
		0.140614f, 0.144574f, 0.148535f, 0.152495f, 0.156455f, 0.160415f,
		0.164376f, 0.168336f, 0.172296f, 0.176257f, 0.180217f, 0.184177f,
		0.188138f, 0.192098f, 0.196058f, 0.200019f, 0.203979f, 0.207939f,
		0.211899f, 0.21586f, 0.21982f, 0.22378f, 0.227741f, 0.231701f,
		0.235661f, 0.239622f, 0.243582f, 0.247542f, 0.251503f, 0.255463f,
		0.259423f, 0.263384f, 0.267344f, 0.271304f, 0.275264f, 0.279225f,
		0.283185f, 0.287145f, 0.291106f, 0.295066f, 0.299026f, 0.302987f,
		0.306947f, 0.310907f, 0.314867f, 0.318828f, 0.322788f, 0.326748f,
		0.330709f, 0.334669f, 0.338629f, 0.342589f, 0.34655f, 0.35051f,
		0.35447f, 0.358431f, 0.362391f, 0.366351f, 0.370312f, 0.374272f,
		0.378232f, 0.382192f, 0.386153f, 0.390113f, 0.394073f, 0.398034f,
		0.401994f, 0.405954f, 0.409915f, 0.413875f, 0.417835f, 0.421796f,
		0.425756f, 0.429716f, 0.433676f, 0.437637f, 0.441597f, 0.445557f,
		0.449518f, 0.453478f, 0.457438f, 0.461399f, 0.465359f, 0.469319f,
		0.47328f, 0.47724f, 0.4812f, 0.485161f, 0.489121f, 0.493081f,
		0.497041f, 0.501002f, 0.504962f, 0.508922f, 0.512883f, 0.516843f,
		0.520803f, 0.524764f, 0.528724f, 0.532684f, 0.536644f, 0.540605f,
		0.544565f, 0.548525f, 0.552486f, 0.556446f, 0.560406f, 0.564367f,
		0.568327f, 0.572287f, 0.576248f, 0.580208f, 0.584168f, 0.588128f,
		0.592089f, 0.596049f, 0.600009f, 0.60397f, 0.60793f, 0.61189f,
		0.615851f, 0.619811f, 0.623771f, 0.627731f, 0.631692f, 0.635652f,
		0.639612f, 0.643573f, 0.647533f, 0.651493f, 0.655454f, 0.659414f,
		0.663374f, 0.667334f, 0.671295f, 0.675255f, 0.679215f, 0.683176f,
		0.687136f, 0.691096f, 0.695057f, 0.699017f, 0.702977f, 0.706938f,
		0.710898f, 0.714858f, 0.718818f, 0.722779f, 0.726739f, 0.730699f,
		0.73466f, 0.73862f, 0.74258f, 0.746541f, 0.750501f, 0.754461f,
		0.758421f, 0.762382f, 0.766342f, 0.770302f, 0.774263f, 0.778223f,
		0.782183f, 0.786144f, 0.790104f, 0.794064f, 0.798025f, 0.801985f,
		0.805945f, 0.809905f, 0.813866f, 0.817826f, 0.821786f, 0.825747f,
		0.829707f, 0.833667f, 0.837628f, 0.841588f, 0.845548f, 0.849508f,
		0.853469f, 0.857429f, 0.861389f, 0.86535f, 0.86931f, 0.87327f,
		0.877231f, 0.881191f, 0.885151f, 0.889111f, 0.893072f, 0.897032f,
		0.900992f, 0.904953f, 0.908913f, 0.912873f, 0.916834f, 0.920794f,
		0.924754f, 0.928715f, 0.932675f, 0.936635f, 0.940595f, 0.944556f,
		0.948516f, 0.952476f, 0.956437f, 0.960397f, 0.964357f, 0.968318f,
		0.972278f, 0.976238f, 0.980198f, 0.984159f, 0.988119f, 0.992079f,
		0.99604f, 1.f
	};
};

template <int NV>
using cable_table10_t = wrap::data<control::cable_table<parameter::plain<cable_pack1_t<NV>, 0>>, 
                                   data::embedded::table<cable_table10_t_data>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<input_toggle8_t<NV>, 2>, 
                                  parameter::plain<cable_table5_t<NV>, 0>, 
                                  parameter::plain<cable_table10_t<NV>, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, ramp_t<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using sb33_t_ = container::chain<parameter::empty, 
                                 wrap::fix<1, input_toggle8_t<NV>>, 
                                 math::clear<NV>, 
                                 ahdsr_t<NV>, 
                                 math::add<NV>>;

template <int NV>
using sb33_t = bypass::smoothed<20, sb33_t_<NV>>;
template <int NV>
using switcher16_c0 = parameter::bypass<sb33_t<NV>>;

using pack8_writer_t = wrap::data<control::pack8_writer, 
                                  data::external::sliderpack<8>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pack8_writer_t>, 
                                   cable_table5_t<NV>, 
                                   math::clear<NV>, 
                                   cable_pack2_t<NV>, 
                                   math::add<NV>>;
using pack8_writer1_t = wrap::data<control::pack8_writer, 
                                   data::external::sliderpack<9>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pack8_writer1_t>, 
                                   cable_table10_t<NV>, 
                                   math::clear<NV>, 
                                   cable_pack1_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain33_t<NV>>, 
                                   chain83_t<NV>>;

template <int NV> using simple_ar2_multimod = ahdsr_multimod<NV>;

template <int NV>
using simple_ar2_t = wrap::no_data<envelope::simple_ar<NV, simple_ar2_multimod<NV>>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<simple_ar2_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   split10_t<NV>, 
                                   peak2_t<NV>, 
                                   math::clear<NV>, 
                                   simple_ar2_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using fix8_block_t = container::chain<parameter::empty, 
                                      wrap::fix<1, chain21_t<NV>>>;

template <int NV>
using sb37_t_ = container::chain<parameter::empty, 
                                 wrap::fix<1, fix8_block_t<NV>>>;

template <int NV>
using sb37_t = bypass::smoothed<20, sb37_t_<NV>>;
template <int NV>
using switcher16_c1 = parameter::bypass<sb37_t<NV>>;

template <int NV>
using switcher16_multimod = parameter::list<switcher16_c0<NV>, switcher16_c1<NV>>;

template <int NV>
using switcher16_t = control::xfader<switcher16_multimod<NV>, 
                                     faders::switcher>;

template <int NV>
using sb_container16_t = container::chain<parameter::empty, 
                                          wrap::fix<1, sb33_t<NV>>, 
                                          sb37_t<NV>>;

template <int NV>
using softbypass_switch20_t = container::chain<parameter::empty, 
                                               wrap::fix<1, switcher16_t<NV>>, 
                                               sb_container16_t<NV>>;

template <int NV>
using pma9_t = control::pma<NV, 
                            parameter::plain<math::add<NV>, 0>>;
template <int NV>
using midi_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                         control::midi<midi_logic::velocity<NV>>>;

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter1_modRange, 
                             -100., 
                             0., 
                             5.42227);

using smoothed_parameter1_mod = parameter::from0To1<core::gain, 
                                                    0, 
                                                    smoothed_parameter1_modRange>;

template <int NV>
using smoothed_parameter1_t = wrap::mod<smoothed_parameter1_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<smoothed_parameter1_t<NV>, 0>>;
template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<pma_t<NV>, 2>>;

using smoothed_parameter2_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter2_t = wrap::mod<smoothed_parameter2_mod, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using pma2_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter2_t<NV>, 0>>;
template <int NV>
using input_toggle1_t = control::input_toggle<parameter::plain<pma2_t<NV>, 2>>;

using smoothed_parameter3_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter3_t = wrap::mod<smoothed_parameter3_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma3_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter3_t<NV>, 0>>;
template <int NV>
using input_toggle2_t = control::input_toggle<parameter::plain<pma3_t<NV>, 2>>;

using smoothed_parameter4_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter4_t = wrap::mod<smoothed_parameter4_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma4_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter4_t<NV>, 0>>;
template <int NV>
using input_toggle3_t = control::input_toggle<parameter::plain<pma4_t<NV>, 2>>;

using smoothed_parameter_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter_t = wrap::mod<smoothed_parameter_mod, 
                                       control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma5_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter_t<NV>, 0>>;
template <int NV>
using input_toggle4_t = control::input_toggle<parameter::plain<pma5_t<NV>, 2>>;

using smoothed_parameter5_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter5_t = wrap::mod<smoothed_parameter5_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma6_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter5_t<NV>, 0>>;
template <int NV>
using input_toggle5_t = control::input_toggle<parameter::plain<pma6_t<NV>, 2>>;

using smoothed_parameter6_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter6_t = wrap::mod<smoothed_parameter6_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter6_t<NV>, 0>>;
template <int NV>
using input_toggle7_t = control::input_toggle<parameter::plain<pma1_t<NV>, 2>>;
template <int NV>
using xfader_multimod = parameter::list<parameter::plain<input_toggle_t<NV>, 1>, 
                                        parameter::plain<input_toggle1_t<NV>, 1>, 
                                        parameter::plain<input_toggle2_t<NV>, 1>, 
                                        parameter::plain<input_toggle3_t<NV>, 1>, 
                                        parameter::plain<input_toggle4_t<NV>, 1>, 
                                        parameter::plain<input_toggle5_t<NV>, 1>, 
                                        parameter::plain<input_toggle7_t<NV>, 1>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::threshold>;

using smoothed_parameter7_mod = smoothed_parameter1_mod;

template <int NV>
using smoothed_parameter7_t = wrap::mod<smoothed_parameter7_mod, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma7_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter7_t<NV>, 0>>;
template <int NV>
using input_toggle6_t = control::input_toggle<parameter::plain<pma7_t<NV>, 2>>;
template <int NV>
using xfader3_multimod = parameter::list<parameter::plain<input_toggle_t<NV>, 2>, 
                                         parameter::plain<input_toggle1_t<NV>, 2>, 
                                         parameter::plain<input_toggle2_t<NV>, 2>, 
                                         parameter::plain<input_toggle3_t<NV>, 2>, 
                                         parameter::plain<input_toggle4_t<NV>, 2>, 
                                         parameter::plain<input_toggle5_t<NV>, 2>, 
                                         parameter::plain<input_toggle6_t<NV>, 2>, 
                                         parameter::plain<input_toggle7_t<NV>, 2>>;

template <int NV>
using xfader3_t = control::xfader<xfader3_multimod<NV>, faders::rms>;
using cable_table_t = wrap::data<control::cable_table<parameter::empty>, 
                                 data::external::table<2>>;

template <int NV>
using pma8_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<xfader_t<NV>, 0>, 
                                  parameter::plain<xfader3_t<NV>, 0>, 
                                  parameter::plain<cable_table_t, 0>>;

template <int NV>
using pma8_t = control::pma<NV, pma8_mod<NV>>;
template <int NV>
using pma11_t = control::pma<NV, 
                             parameter::plain<pma8_t<NV>, 2>>;
template <int NV>
using pma19_t = control::pma<NV, 
                             parameter::plain<pma11_t<NV>, 2>>;

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;
template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, 
                                             parameter::plain<file_player_t<NV>, 3>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled_t<NV>, 2>>;

template <int NV>
using file_player7_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;
template <int NV>
using file_player10_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<9>>;

template <int NV>
using pma_unscaled7_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player7_t<NV>, 3>, 
                                           parameter::plain<file_player10_t<NV>, 3>>;

template <int NV>
using pma_unscaled7_t = control::pma_unscaled<NV, pma_unscaled7_mod<NV>>;
template <int NV>
using minmax7_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled7_t<NV>, 2>>;

template <int NV>
using file_player6_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<2>>;
template <int NV>
using file_player11_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<10>>;

template <int NV>
using pma_unscaled6_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player6_t<NV>, 3>, 
                                           parameter::plain<file_player11_t<NV>, 3>>;

template <int NV>
using pma_unscaled6_t = control::pma_unscaled<NV, pma_unscaled6_mod<NV>>;
template <int NV>
using minmax6_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled6_t<NV>, 2>>;

template <int NV>
using file_player5_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<3>>;
template <int NV>
using file_player12_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<11>>;

template <int NV>
using pma_unscaled5_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player5_t<NV>, 3>, 
                                           parameter::plain<file_player12_t<NV>, 3>>;

template <int NV>
using pma_unscaled5_t = control::pma_unscaled<NV, pma_unscaled5_mod<NV>>;
template <int NV>
using minmax5_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled5_t<NV>, 2>>;

template <int NV>
using file_player4_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<4>>;
template <int NV>
using file_player13_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<12>>;

template <int NV>
using pma_unscaled4_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player4_t<NV>, 3>, 
                                           parameter::plain<file_player13_t<NV>, 3>>;

template <int NV>
using pma_unscaled4_t = control::pma_unscaled<NV, pma_unscaled4_mod<NV>>;
template <int NV>
using minmax4_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled4_t<NV>, 2>>;

template <int NV>
using file_player3_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<5>>;
template <int NV>
using file_player14_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<13>>;

template <int NV>
using pma_unscaled3_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player3_t<NV>, 3>, 
                                           parameter::plain<file_player14_t<NV>, 3>>;

template <int NV>
using pma_unscaled3_t = control::pma_unscaled<NV, pma_unscaled3_mod<NV>>;
template <int NV>
using minmax3_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled3_t<NV>, 2>>;

template <int NV>
using file_player2_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<6>>;
template <int NV>
using file_player15_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<14>>;

template <int NV>
using pma_unscaled2_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player2_t<NV>, 3>, 
                                           parameter::plain<file_player15_t<NV>, 3>>;

template <int NV>
using pma_unscaled2_t = control::pma_unscaled<NV, pma_unscaled2_mod<NV>>;
template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled2_t<NV>, 2>>;

template <int NV>
using file_player1_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<7>>;
template <int NV>
using file_player8_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<15>>;

template <int NV>
using pma_unscaled1_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<file_player1_t<NV>, 3>, 
                                           parameter::plain<file_player8_t<NV>, 3>>;

template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, pma_unscaled1_mod<NV>>;
template <int NV>
using minmax1_t = control::minmax<NV, 
                                  parameter::plain<pma_unscaled1_t<NV>, 2>>;
template <int NV>
using harm_multimod = parameter::list<parameter::plain<minmax_t<NV>, 0>, 
                                      parameter::plain<minmax7_t<NV>, 0>, 
                                      parameter::plain<minmax6_t<NV>, 0>, 
                                      parameter::plain<minmax5_t<NV>, 0>, 
                                      parameter::plain<minmax4_t<NV>, 0>, 
                                      parameter::plain<minmax3_t<NV>, 0>, 
                                      parameter::plain<minmax2_t<NV>, 0>, 
                                      parameter::plain<minmax1_t<NV>, 0>>;

template <int NV>
using harm_t = wrap::data<control::sliderbank<harm_multimod<NV>>, 
                          data::external::sliderpack<0>>;
template <int NV>
using pma17_t = control::pma<NV, 
                             parameter::plain<harm_t<NV>, 0>>;
template <int NV>
using pma_unscaled8_t = control::pma_unscaled<NV, 
                                              parameter::plain<pma17_t<NV>, 2>>;
template <int NV>
using pma14_t = control::pma<NV, 
                             parameter::plain<pma_unscaled8_t<NV>, 2>>;
template <int NV>
using pma22_t = control::pma<NV, 
                             parameter::plain<pma14_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_SKEW(cut_c0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using cut_c0 = parameter::from0To1<filters::svf<NV>, 
                                   0, 
                                   cut_c0Range>;

template <int NV> using cut_c1 = cut_c0<NV>;

template <int NV> using cut_c2 = cut_c0<NV>;

template <int NV> using cut_c3 = cut_c0<NV>;

template <int NV> using cut_c4 = cut_c0<NV>;

template <int NV> using cut_c5 = cut_c0<NV>;

template <int NV> using cut_c6 = cut_c0<NV>;

template <int NV> using cut_c7 = cut_c0<NV>;

template <int NV>
using cut_multimod = parameter::list<cut_c0<NV>, 
                                     cut_c1<NV>, 
                                     cut_c2<NV>, 
                                     cut_c3<NV>, 
                                     cut_c4<NV>, 
                                     cut_c5<NV>, 
                                     cut_c6<NV>, 
                                     cut_c7<NV>>;

template <int NV>
using cut_t = wrap::data<control::sliderbank<cut_multimod<NV>>, 
                         data::external::sliderpack<1>>;
template <int NV>
using pma16_t = control::pma<NV, 
                             parameter::plain<cut_t<NV>, 0>>;
template <int NV>
using pma26_t = control::pma<NV, 
                             parameter::plain<pma16_t<NV>, 2>>;
template <int NV>
using pma23_t = control::pma<NV, 
                             parameter::plain<pma26_t<NV>, 2>>;

using vol_c0 = smoothed_parameter1_mod;

using vol_c1 = smoothed_parameter1_mod;

using vol_c2 = smoothed_parameter1_mod;

using vol_c3 = smoothed_parameter1_mod;

using vol_c4 = smoothed_parameter1_mod;

using vol_c5 = smoothed_parameter1_mod;

using vol_c6 = smoothed_parameter1_mod;

using vol_c7 = smoothed_parameter1_mod;

using vol_multimod = parameter::list<vol_c0, 
                                     vol_c1, 
                                     vol_c2, 
                                     vol_c3, 
                                     vol_c4, 
                                     vol_c5, 
                                     vol_c6, 
                                     vol_c7>;

using vol_t = wrap::data<control::sliderbank<vol_multimod>, 
                         data::external::sliderpack<3>>;
template <int NV>
using pma15_t = control::pma<NV, 
                             parameter::plain<vol_t, 0>>;
template <int NV>
using pma27_t = control::pma<NV, 
                             parameter::plain<pma15_t<NV>, 2>>;
template <int NV>
using pma24_t = control::pma<NV, 
                             parameter::plain<pma27_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(pan_c0Range, 
                        -1., 
                        1.);

template <int NV>
using pan_c0 = parameter::from0To1<jdsp::jpanner<NV>, 
                                   0, 
                                   pan_c0Range>;

template <int NV> using pan_c1 = pan_c0<NV>;

template <int NV> using pan_c2 = pan_c0<NV>;

template <int NV> using pan_c3 = pan_c0<NV>;

template <int NV> using pan_c4 = pan_c0<NV>;

template <int NV> using pan_c5 = pan_c0<NV>;

template <int NV> using pan_c6 = pan_c0<NV>;

template <int NV> using pan_c7 = pan_c0<NV>;

template <int NV>
using pan_multimod = parameter::list<pan_c0<NV>, 
                                     pan_c1<NV>, 
                                     pan_c2<NV>, 
                                     pan_c3<NV>, 
                                     pan_c4<NV>, 
                                     pan_c5<NV>, 
                                     pan_c6<NV>, 
                                     pan_c7<NV>>;

template <int NV>
using pan_t = wrap::data<control::sliderbank<pan_multimod<NV>>, 
                         data::external::sliderpack<2>>;
template <int NV>
using pma18_t = control::pma<NV, 
                             parameter::plain<pan_t<NV>, 0>>;

template <int NV>
using pma20_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma18_t<NV>, 2>, 
                                   parameter::plain<control::pma<NV, parameter::empty>, 2>>;

template <int NV>
using pma20_t = control::pma<NV, pma20_mod<NV>>;

template <int NV>
using pitch_multimod = parameter::list<parameter::plain<pma_unscaled_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled7_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled6_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled5_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled4_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled3_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled2_t<NV>, 0>, 
                                       parameter::plain<pma_unscaled1_t<NV>, 0>>;

template <int NV>
using pitch_t = wrap::data<control::sliderbank<pitch_multimod<NV>>, 
                           data::external::sliderpack<4>>;
template <int NV>
using pma10_t = control::pma<NV, 
                             parameter::plain<pitch_t<NV>, 0>>;
template <int NV>
using pma13_t = control::pma<NV, 
                             parameter::plain<pma10_t<NV>, 2>>;
template <int NV>
using pma21_t = control::pma<NV, 
                             parameter::plain<pma13_t<NV>, 2>>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma19_t<NV>, 0>, 
                                  parameter::plain<pma22_t<NV>, 0>, 
                                  parameter::plain<pma23_t<NV>, 0>, 
                                  parameter::plain<pma24_t<NV>, 0>, 
                                  parameter::plain<pma20_t<NV>, 0>, 
                                  parameter::plain<pma21_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, tempo_sync_t<NV>>, 
                                     no_midi_t<NV>, 
                                     softbypass_switch20_t<NV>, 
                                     midi_t<NV>, 
                                     pma9_t<NV>, 
                                     math::add<NV>, 
                                     peak_t<NV>, 
                                     math::clear<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<0>>;

template <int NV>
using steppack1_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                               data::external::sliderpack<12>>;

template <int NV>
using ramp2_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table1_t<NV>, 0>, 
                                   parameter::plain<steppack1_t<NV>, 0>>;

template <int NV>
using ramp2_t = wrap::mod<ramp2_mod<NV>, 
                          wrap::no_data<core::ramp<NV, false>>>;

template <int NV>
using oscillator1_t = wrap::no_data<core::oscillator<NV>>;
template <int NV>
using converter1_t = control::converter<parameter::plain<oscillator1_t<NV>, 1>, 
                                        conversion_logic::ms2freq>;

template <int NV>
using tempo_sync2_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<ramp2_t<NV>, 0>, 
                                         parameter::plain<converter1_t<NV>, 0>>;

template <int NV>
using tempo_sync2_t = wrap::mod<tempo_sync2_mod<NV>, 
                                control::tempo_sync<NV>>;

template <int NV>
using no_midi1_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, ramp2_t<NV>>>;

template <int NV>
using no_midi1_t = wrap::no_midi<no_midi1_t_<NV>>;

template <int NV>
using sb39_t_ = container::chain<parameter::empty, 
                                 wrap::fix<1, converter1_t<NV>>, 
                                 oscillator1_t<NV>, 
                                 math::sig2mod<NV>>;

template <int NV>
using sb39_t = bypass::smoothed<20, sb39_t_<NV>>;
template <int NV>
using switcher17_c0 = parameter::bypass<sb39_t<NV>>;

template <int NV>
using sb40_t_ = container::chain<parameter::empty, 
                                 wrap::fix<1, cable_table1_t<NV>>, 
                                 math::add<NV>>;

template <int NV>
using sb40_t = bypass::smoothed<20, sb40_t_<NV>>;
template <int NV>
using switcher17_c1 = parameter::bypass<sb40_t<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   steppack1_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using sb41_t_ = container::chain<parameter::empty, 
                                 wrap::fix<1, chain24_t<NV>>>;

template <int NV>
using sb41_t = bypass::smoothed<20, sb41_t_<NV>>;
template <int NV>
using switcher17_c2 = parameter::bypass<sb41_t<NV>>;

template <int NV>
using switcher17_multimod = parameter::list<switcher17_c0<NV>, 
                                            switcher17_c1<NV>, 
                                            switcher17_c2<NV>>;

template <int NV>
using switcher17_t = control::xfader<switcher17_multimod<NV>, 
                                     faders::switcher>;

template <int NV>
using sb_container17_t = container::chain<parameter::empty, 
                                          wrap::fix<1, sb39_t<NV>>, 
                                          sb40_t<NV>, 
                                          sb41_t<NV>>;

template <int NV>
using softbypass_switch21_t = container::chain<parameter::empty, 
                                               wrap::fix<1, switcher17_t<NV>>, 
                                               sb_container17_t<NV>>;

template <int NV> using pma25_t = pma9_t<NV>;
template <int NV>
using midi1_t = wrap::mod<parameter::plain<pma25_t<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using peak1_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma8_t<NV>, 0>, 
                                   parameter::plain<pma10_t<NV>, 0>, 
                                   parameter::plain<pma17_t<NV>, 0>, 
                                   parameter::plain<pma16_t<NV>, 0>, 
                                   parameter::plain<pma15_t<NV>, 0>, 
                                   parameter::plain<pma18_t<NV>, 0>>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, tempo_sync2_t<NV>>, 
                                      no_midi1_t<NV>, 
                                      softbypass_switch21_t<NV>, 
                                      midi1_t<NV>, 
                                      pma25_t<NV>, 
                                      math::add<NV>, 
                                      peak1_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<1>>;

template <int NV>
using steppack2_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                               data::external::sliderpack<13>>;

template <int NV>
using ramp3_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table2_t<NV>, 0>, 
                                   parameter::plain<steppack2_t<NV>, 0>>;

template <int NV>
using ramp3_t = wrap::mod<ramp3_mod<NV>, 
                          wrap::no_data<core::ramp<NV, false>>>;

template <int NV> using oscillator2_t = oscillator1_t<NV>;
template <int NV>
using converter2_t = control::converter<parameter::plain<oscillator2_t<NV>, 1>, 
                                        conversion_logic::ms2freq>;

template <int NV>
using tempo_sync3_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<ramp3_t<NV>, 0>, 
                                         parameter::plain<converter2_t<NV>, 0>>;

template <int NV>
using tempo_sync3_t = wrap::mod<tempo_sync3_mod<NV>, 
                                control::tempo_sync<NV>>;

template <int NV>
using no_midi2_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, ramp3_t<NV>>>;

template <int NV>
using no_midi2_t = wrap::no_midi<no_midi2_t_<NV>>;

template <int NV>
using sb42_t_ = container::chain<parameter::empty, 
                                 wrap::fix<1, converter2_t<NV>>, 
                                 oscillator2_t<NV>, 
                                 math::sig2mod<NV>>;

template <int NV>
using sb42_t = bypass::smoothed<20, sb42_t_<NV>>;
template <int NV>
using switcher18_c0 = parameter::bypass<sb42_t<NV>>;

template <int NV>
using sb43_t_ = container::chain<parameter::empty, 
                                 wrap::fix<1, cable_table2_t<NV>>, 
                                 math::add<NV>>;

template <int NV>
using sb43_t = bypass::smoothed<20, sb43_t_<NV>>;
template <int NV>
using switcher18_c1 = parameter::bypass<sb43_t<NV>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   steppack2_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using sb44_t_ = container::chain<parameter::empty, 
                                 wrap::fix<1, chain25_t<NV>>>;

template <int NV>
using sb44_t = bypass::smoothed<20, sb44_t_<NV>>;
template <int NV>
using switcher18_c2 = parameter::bypass<sb44_t<NV>>;

template <int NV>
using switcher18_multimod = parameter::list<switcher18_c0<NV>, 
                                            switcher18_c1<NV>, 
                                            switcher18_c2<NV>>;

template <int NV>
using switcher18_t = control::xfader<switcher18_multimod<NV>, 
                                     faders::switcher>;

template <int NV>
using sb_container18_t = container::chain<parameter::empty, 
                                          wrap::fix<1, sb42_t<NV>>, 
                                          sb43_t<NV>, 
                                          sb44_t<NV>>;

template <int NV>
using softbypass_switch22_t = container::chain<parameter::empty, 
                                               wrap::fix<1, switcher18_t<NV>>, 
                                               sb_container18_t<NV>>;

template <int NV> using pma28_t = pma9_t<NV>;
template <int NV>
using midi2_t = wrap::mod<parameter::plain<pma28_t<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using peak3_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma11_t<NV>, 0>, 
                                   parameter::plain<pma13_t<NV>, 0>, 
                                   parameter::plain<pma14_t<NV>, 0>, 
                                   parameter::plain<pma26_t<NV>, 0>, 
                                   parameter::plain<pma27_t<NV>, 0>, 
                                   parameter::plain<control::pma<NV, parameter::empty>, 0>>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, tempo_sync3_t<NV>>, 
                                      no_midi2_t<NV>, 
                                      softbypass_switch22_t<NV>, 
                                      midi2_t<NV>, 
                                      pma28_t<NV>, 
                                      math::add<NV>, 
                                      peak3_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  modchain1_t<NV>, 
                                  modchain2_t<NV>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma19_t<NV>>, 
                                   pma11_t<NV>, 
                                   pma8_t<NV>, 
                                   cable_table_t>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma21_t<NV>>, 
                                   pma13_t<NV>, 
                                   pma10_t<NV>>;

template <int NV>
using midi_cc_t = control::midi_cc<parameter::plain<pma_unscaled8_t<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma22_t<NV>>, 
                                   pma14_t<NV>, 
                                   pma_unscaled8_t<NV>, 
                                   midi_cc_t<NV>, 
                                   pma17_t<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma23_t<NV>>, 
                                   pma26_t<NV>, 
                                   pma16_t<NV>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma24_t<NV>>, 
                                   pma27_t<NV>, 
                                   pma15_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma20_t<NV>>, 
                                   control::pma<NV, parameter::empty>, 
                                   pma18_t<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain12_t<NV>>, 
                                  chain13_t<NV>, 
                                  chain22_t<NV>, 
                                  chain19_t<NV>, 
                                  chain18_t<NV>, 
                                  chain23_t<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  xfader3_t<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, input_toggle_t<NV>>, 
                                  input_toggle1_t<NV>, 
                                  input_toggle2_t<NV>, 
                                  input_toggle3_t<NV>, 
                                  input_toggle4_t<NV>, 
                                  input_toggle5_t<NV>, 
                                  input_toggle6_t<NV>, 
                                  input_toggle7_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split1_t<NV>>, 
                                   split4_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain11_t<NV>>>;

using dry_wet_mixer7_c0 = smoothed_parameter1_mod;

using dry_wet_mixer7_c1 = smoothed_parameter1_mod;

using dry_wet_mixer7_multimod = parameter::list<dry_wet_mixer7_c0, dry_wet_mixer7_c1>;

using dry_wet_mixer7_t = control::xfader<dry_wet_mixer7_multimod, 
                                         faders::linear>;

using dry_wet_mixer4_c0 = smoothed_parameter1_mod;

using dry_wet_mixer4_c1 = smoothed_parameter1_mod;

using dry_wet_mixer4_multimod = parameter::list<dry_wet_mixer4_c0, dry_wet_mixer4_c1>;

using dry_wet_mixer4_t = control::xfader<dry_wet_mixer4_multimod, 
                                         faders::linear>;

using dry_wet_mixer5_c0 = smoothed_parameter1_mod;

using dry_wet_mixer5_c1 = smoothed_parameter1_mod;

using dry_wet_mixer5_multimod = parameter::list<dry_wet_mixer5_c0, dry_wet_mixer5_c1>;

using dry_wet_mixer5_t = control::xfader<dry_wet_mixer5_multimod, 
                                         faders::linear>;

using dry_wet_mixer6_c0 = smoothed_parameter1_mod;

using dry_wet_mixer6_c1 = smoothed_parameter1_mod;

using dry_wet_mixer6_multimod = parameter::list<dry_wet_mixer6_c0, dry_wet_mixer6_c1>;

using dry_wet_mixer6_t = control::xfader<dry_wet_mixer6_multimod, 
                                         faders::linear>;

using dry_wet_mixer3_c0 = smoothed_parameter1_mod;

using dry_wet_mixer3_c1 = smoothed_parameter1_mod;

using dry_wet_mixer3_multimod = parameter::list<dry_wet_mixer3_c0, dry_wet_mixer3_c1>;

using dry_wet_mixer3_t = control::xfader<dry_wet_mixer3_multimod, 
                                         faders::linear>;

using dry_wet_mixer2_c0 = smoothed_parameter1_mod;

using dry_wet_mixer2_c1 = smoothed_parameter1_mod;

using dry_wet_mixer2_multimod = parameter::list<dry_wet_mixer2_c0, dry_wet_mixer2_c1>;

using dry_wet_mixer2_t = control::xfader<dry_wet_mixer2_multimod, 
                                         faders::linear>;

using dry_wet_mixer_c0 = smoothed_parameter1_mod;

using dry_wet_mixer_c1 = smoothed_parameter1_mod;

using dry_wet_mixer_multimod = parameter::list<dry_wet_mixer_c0, dry_wet_mixer_c1>;

using dry_wet_mixer_t = control::xfader<dry_wet_mixer_multimod, faders::linear>;

using dry_wet_mixer1_c0 = smoothed_parameter1_mod;

using dry_wet_mixer1_c1 = smoothed_parameter1_mod;

using dry_wet_mixer1_multimod = parameter::list<dry_wet_mixer1_c0, dry_wet_mixer1_c1>;

using dry_wet_mixer1_t = control::xfader<dry_wet_mixer1_multimod, 
                                         faders::linear>;

using cutmix_c0 = parameter::chain<ranges::Identity, 
                                   parameter::plain<dry_wet_mixer7_t, 0>, 
                                   parameter::plain<dry_wet_mixer4_t, 0>, 
                                   parameter::plain<dry_wet_mixer5_t, 0>, 
                                   parameter::plain<dry_wet_mixer6_t, 0>, 
                                   parameter::plain<dry_wet_mixer3_t, 0>, 
                                   parameter::plain<dry_wet_mixer2_t, 0>, 
                                   parameter::plain<dry_wet_mixer_t, 0>, 
                                   parameter::plain<dry_wet_mixer1_t, 0>>;

using cutmix_multimod = parameter::list<cutmix_c0, parameter::empty>;

using cutmix_t = wrap::data<control::sliderbank<cutmix_multimod>, 
                            data::external::sliderpack<6>>;

template <int NV>
using sb6_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player_t<NV>>>;

template <int NV>
using sb6_t = bypass::smoothed<20, sb6_t_<NV>>;
template <int NV>
using switcher2_c0 = parameter::bypass<sb6_t<NV>>;

template <int NV>
using file_player9_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<8>>;

template <int NV>
using sb7_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player9_t<NV>>>;

template <int NV>
using sb7_t = bypass::smoothed<20, sb7_t_<NV>>;
template <int NV>
using switcher2_c1 = parameter::bypass<sb7_t<NV>>;

template <int NV>
using switcher2_multimod = parameter::list<switcher2_c0<NV>, switcher2_c1<NV>>;

template <int NV>
using switcher2_t = control::xfader<switcher2_multimod<NV>, faders::switcher>;

template <int NV>
using sb8_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player7_t<NV>>>;

template <int NV>
using sb8_t = bypass::smoothed<20, sb8_t_<NV>>;
template <int NV>
using switcher3_c0 = parameter::bypass<sb8_t<NV>>;

template <int NV>
using sb9_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player10_t<NV>>>;

template <int NV>
using sb9_t = bypass::smoothed<20, sb9_t_<NV>>;
template <int NV>
using switcher3_c1 = parameter::bypass<sb9_t<NV>>;

template <int NV>
using switcher3_multimod = parameter::list<switcher3_c0<NV>, switcher3_c1<NV>>;

template <int NV>
using switcher3_t = control::xfader<switcher3_multimod<NV>, faders::switcher>;

template <int NV>
using sb10_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player6_t<NV>>>;

template <int NV>
using sb10_t = bypass::smoothed<20, sb10_t_<NV>>;
template <int NV>
using switcher4_c0 = parameter::bypass<sb10_t<NV>>;

template <int NV>
using sb11_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player11_t<NV>>>;

template <int NV>
using sb11_t = bypass::smoothed<20, sb11_t_<NV>>;
template <int NV>
using switcher4_c1 = parameter::bypass<sb11_t<NV>>;

template <int NV>
using switcher4_multimod = parameter::list<switcher4_c0<NV>, switcher4_c1<NV>>;

template <int NV>
using switcher4_t = control::xfader<switcher4_multimod<NV>, faders::switcher>;

template <int NV>
using sb12_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player5_t<NV>>>;

template <int NV>
using sb12_t = bypass::smoothed<20, sb12_t_<NV>>;
template <int NV>
using switcher5_c0 = parameter::bypass<sb12_t<NV>>;

template <int NV>
using sb13_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player12_t<NV>>>;

template <int NV>
using sb13_t = bypass::smoothed<20, sb13_t_<NV>>;
template <int NV>
using switcher5_c1 = parameter::bypass<sb13_t<NV>>;

template <int NV>
using switcher5_multimod = parameter::list<switcher5_c0<NV>, switcher5_c1<NV>>;

template <int NV>
using switcher5_t = control::xfader<switcher5_multimod<NV>, faders::switcher>;

template <int NV>
using sb14_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player4_t<NV>>>;

template <int NV>
using sb14_t = bypass::smoothed<20, sb14_t_<NV>>;
template <int NV>
using switcher6_c0 = parameter::bypass<sb14_t<NV>>;

template <int NV>
using sb15_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player13_t<NV>>>;

template <int NV>
using sb15_t = bypass::smoothed<20, sb15_t_<NV>>;
template <int NV>
using switcher6_c1 = parameter::bypass<sb15_t<NV>>;

template <int NV>
using switcher6_multimod = parameter::list<switcher6_c0<NV>, switcher6_c1<NV>>;

template <int NV>
using switcher6_t = control::xfader<switcher6_multimod<NV>, faders::switcher>;

template <int NV>
using sb16_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player3_t<NV>>>;

template <int NV>
using sb16_t = bypass::smoothed<20, sb16_t_<NV>>;
template <int NV>
using switcher7_c0 = parameter::bypass<sb16_t<NV>>;

template <int NV>
using sb17_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player14_t<NV>>>;

template <int NV>
using sb17_t = bypass::smoothed<20, sb17_t_<NV>>;
template <int NV>
using switcher7_c1 = parameter::bypass<sb17_t<NV>>;

template <int NV>
using switcher7_multimod = parameter::list<switcher7_c0<NV>, switcher7_c1<NV>>;

template <int NV>
using switcher7_t = control::xfader<switcher7_multimod<NV>, faders::switcher>;

template <int NV>
using sb18_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player2_t<NV>>>;

template <int NV>
using sb18_t = bypass::smoothed<20, sb18_t_<NV>>;
template <int NV>
using switcher8_c0 = parameter::bypass<sb18_t<NV>>;

template <int NV>
using sb19_t_ = container::chain<parameter::empty, 
                                 wrap::fix<2, file_player15_t<NV>>>;

template <int NV>
using sb19_t = bypass::smoothed<20, sb19_t_<NV>>;
template <int NV>
using switcher8_c1 = parameter::bypass<sb19_t<NV>>;

template <int NV>
using switcher8_multimod = parameter::list<switcher8_c0<NV>, switcher8_c1<NV>>;

template <int NV>
using switcher8_t = control::xfader<switcher8_multimod<NV>, faders::switcher>;

template <int NV>
using sb4_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player1_t<NV>>>;

template <int NV>
using sb4_t = bypass::smoothed<20, sb4_t_<NV>>;
template <int NV>
using switcher1_c0 = parameter::bypass<sb4_t<NV>>;

template <int NV>
using sb5_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, file_player8_t<NV>>>;

template <int NV>
using sb5_t = bypass::smoothed<20, sb5_t_<NV>>;
template <int NV>
using switcher1_c1 = parameter::bypass<sb5_t<NV>>;

template <int NV>
using switcher1_multimod = parameter::list<switcher1_c0<NV>, switcher1_c1<NV>>;

template <int NV>
using switcher1_t = control::xfader<switcher1_multimod<NV>, faders::switcher>;
template <int NV>
using SFZ_multimod = parameter::list<parameter::plain<switcher2_t<NV>, 0>, 
                                     parameter::plain<switcher3_t<NV>, 0>, 
                                     parameter::plain<switcher4_t<NV>, 0>, 
                                     parameter::plain<switcher5_t<NV>, 0>, 
                                     parameter::plain<switcher6_t<NV>, 0>, 
                                     parameter::plain<switcher7_t<NV>, 0>, 
                                     parameter::plain<switcher8_t<NV>, 0>, 
                                     parameter::plain<switcher1_t<NV>, 0>>;

template <int NV>
using SFZ_t = wrap::data<control::sliderbank<SFZ_multimod<NV>>, 
                         data::external::sliderpack<11>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, harm_t<NV>>, 
                                  cut_t<NV>, 
                                  pan_t<NV>, 
                                  vol_t, 
                                  pitch_t<NV>, 
                                  cutmix_t, 
                                  SFZ_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain10_t<NV>>, 
                                  split2_t<NV>, 
                                  math::clear<NV>>;

template <int NV>
using sb_container2_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb6_t<NV>>, 
                                         sb7_t<NV>>;

template <int NV>
using softbypass_switch5_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher2_t<NV>>, 
                                              sb_container2_t<NV>>;

using dry_path1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer1_t>, 
                                     core::gain>;

template <int NV>
using wet_path1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, filters::svf<NV>>, 
                                     core::gain>;

template <int NV>
using dry_wet2_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path1_t>, 
                                    wet_path1_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, minmax_t<NV>>, 
                                 pma_unscaled_t<NV>, 
                                 softbypass_switch5_t<NV>, 
                                 dry_wet2_t<NV>, 
                                 pma_t<NV>, 
                                 jdsp::jpanner<NV>, 
                                 core::gain, 
                                 smoothed_parameter1_t<NV>, 
                                 core::gain>;

template <int NV>
using sb_container3_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb8_t<NV>>, 
                                         sb9_t<NV>>;

template <int NV>
using softbypass_switch6_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher3_t<NV>>, 
                                              sb_container3_t<NV>>;

using dry_path2_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer2_t>, 
                                     core::gain>;

template <int NV> using wet_path2_t = wet_path1_t<NV>;

template <int NV>
using dry_wet3_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path2_t>, 
                                    wet_path2_t<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax7_t<NV>>, 
                                  pma_unscaled7_t<NV>, 
                                  softbypass_switch6_t<NV>, 
                                  dry_wet3_t<NV>, 
                                  pma2_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter2_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container4_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb10_t<NV>>, 
                                         sb11_t<NV>>;

template <int NV>
using softbypass_switch7_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher4_t<NV>>, 
                                              sb_container4_t<NV>>;

using dry_path3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer3_t>, 
                                     core::gain>;

template <int NV> using wet_path3_t = wet_path1_t<NV>;

template <int NV>
using dry_wet4_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path3_t>, 
                                    wet_path3_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax6_t<NV>>, 
                                  pma_unscaled6_t<NV>, 
                                  softbypass_switch7_t<NV>, 
                                  dry_wet4_t<NV>, 
                                  pma3_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter3_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container5_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb12_t<NV>>, 
                                         sb13_t<NV>>;

template <int NV>
using softbypass_switch8_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher5_t<NV>>, 
                                              sb_container5_t<NV>>;

using dry_path7_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer7_t>, 
                                     core::gain>;

template <int NV> using wet_path7_t = wet_path1_t<NV>;

template <int NV>
using dry_wet8_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path7_t>, 
                                    wet_path7_t<NV>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax5_t<NV>>, 
                                  pma_unscaled5_t<NV>, 
                                  softbypass_switch8_t<NV>, 
                                  dry_wet8_t<NV>, 
                                  pma4_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter4_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container6_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb14_t<NV>>, 
                                         sb15_t<NV>>;

template <int NV>
using softbypass_switch9_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher6_t<NV>>, 
                                              sb_container6_t<NV>>;

using dry_path4_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer4_t>, 
                                     core::gain>;

template <int NV> using wet_path4_t = wet_path1_t<NV>;

template <int NV>
using dry_wet5_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path4_t>, 
                                    wet_path4_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax4_t<NV>>, 
                                  pma_unscaled4_t<NV>, 
                                  softbypass_switch9_t<NV>, 
                                  dry_wet5_t<NV>, 
                                  pma5_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container7_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb16_t<NV>>, 
                                         sb17_t<NV>>;

template <int NV>
using softbypass_switch10_t = container::chain<parameter::empty, 
                                               wrap::fix<2, switcher7_t<NV>>, 
                                               sb_container7_t<NV>>;

using dry_path5_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer5_t>, 
                                     core::gain>;

template <int NV> using wet_path5_t = wet_path1_t<NV>;

template <int NV>
using dry_wet6_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path5_t>, 
                                    wet_path5_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax3_t<NV>>, 
                                  pma_unscaled3_t<NV>, 
                                  softbypass_switch10_t<NV>, 
                                  dry_wet6_t<NV>, 
                                  pma6_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  core::gain, 
                                  smoothed_parameter5_t<NV>, 
                                  core::gain>;

template <int NV>
using sb_container8_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb18_t<NV>>, 
                                         sb19_t<NV>>;

template <int NV>
using softbypass_switch11_t = container::chain<parameter::empty, 
                                               wrap::fix<2, switcher8_t<NV>>, 
                                               sb_container8_t<NV>>;

using dry_path6_t = container::chain<parameter::empty, 
                                     wrap::fix<2, dry_wet_mixer6_t>, 
                                     core::gain>;

template <int NV> using wet_path6_t = wet_path1_t<NV>;

template <int NV>
using dry_wet7_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path6_t>, 
                                    wet_path6_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax2_t<NV>>, 
                                  pma_unscaled2_t<NV>, 
                                  softbypass_switch11_t<NV>, 
                                  dry_wet7_t<NV>, 
                                  pma7_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  smoothed_parameter7_t<NV>, 
                                  core::gain, 
                                  core::gain>;

template <int NV>
using sb_container1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb4_t<NV>>, 
                                         sb5_t<NV>>;

template <int NV>
using softbypass_switch3_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher1_t<NV>>, 
                                              sb_container1_t<NV>>;

using dry_path_t = container::chain<parameter::empty, 
                                    wrap::fix<2, dry_wet_mixer_t>, 
                                    core::gain>;

template <int NV> using wet_path_t = wet_path1_t<NV>;

template <int NV>
using dry_wet1_t = container::split<parameter::empty, 
                                    wrap::fix<2, dry_path_t>, 
                                    wet_path_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax1_t<NV>>, 
                                  pma_unscaled1_t<NV>, 
                                  softbypass_switch3_t<NV>, 
                                  dry_wet1_t<NV>, 
                                  pma1_t<NV>, 
                                  jdsp::jpanner<NV>, 
                                  smoothed_parameter6_t<NV>, 
                                  core::gain, 
                                  core::gain>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain7_t<NV>, 
                                 chain6_t<NV>, 
                                 chain5_t<NV>, 
                                 chain4_t<NV>, 
                                 chain3_t<NV>, 
                                 chain2_t<NV>, 
                                 chain1_t<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain8_t<NV>>, 
                                  split_t<NV>>;

template <int NV>
using HarmFade_t = container::chain<parameter::empty, 
                                    wrap::fix<2, chain9_t<NV>>>;

namespace XFHarm_t_parameters
{
// Parameter list for XFHarm_impl::XFHarm_t --------------------------------------------------------

template <int NV>
using XfIN = parameter::chain<ranges::Identity, 
                              parameter::plain<XFHarm_impl::input_toggle_t<NV>, 0>, 
                              parameter::plain<XFHarm_impl::input_toggle1_t<NV>, 0>, 
                              parameter::plain<XFHarm_impl::input_toggle3_t<NV>, 0>, 
                              parameter::plain<XFHarm_impl::input_toggle4_t<NV>, 0>, 
                              parameter::plain<XFHarm_impl::input_toggle5_t<NV>, 0>, 
                              parameter::plain<XFHarm_impl::input_toggle6_t<NV>, 0>, 
                              parameter::plain<XFHarm_impl::input_toggle7_t<NV>, 0>, 
                              parameter::plain<XFHarm_impl::input_toggle2_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(smooth_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_STEP(smooth_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth_0 = parameter::from0To1<XFHarm_impl::smoothed_parameter1_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_1 = parameter::from0To1<XFHarm_impl::smoothed_parameter2_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_2 = parameter::from0To1<XFHarm_impl::smoothed_parameter3_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_3 = parameter::from0To1<XFHarm_impl::smoothed_parameter4_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_4 = parameter::from0To1<XFHarm_impl::smoothed_parameter_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_5 = parameter::from0To1<XFHarm_impl::smoothed_parameter5_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_6 = parameter::from0To1<XFHarm_impl::smoothed_parameter7_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_7 = parameter::from0To1<XFHarm_impl::smoothed_parameter6_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth = parameter::chain<smooth_InputRange, 
                                smooth_0<NV>, 
                                smooth_1<NV>, 
                                smooth_2<NV>, 
                                smooth_3<NV>, 
                                smooth_4<NV>, 
                                smooth_5<NV>, 
                                smooth_6<NV>, 
                                smooth_7<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Min_InputRange, 
                             1., 
                             16., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Min_0Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using Min_0 = parameter::from0To1<XFHarm_impl::minmax_t<NV>, 
                                  1, 
                                  Min_0Range>;

template <int NV>
using Min_1 = parameter::from0To1<XFHarm_impl::minmax7_t<NV>, 
                                  1, 
                                  Min_0Range>;

template <int NV>
using Min_2 = parameter::from0To1<XFHarm_impl::minmax6_t<NV>, 
                                  1, 
                                  Min_0Range>;

template <int NV>
using Min_3 = parameter::from0To1<XFHarm_impl::minmax5_t<NV>, 
                                  1, 
                                  Min_0Range>;

template <int NV>
using Min_4 = parameter::from0To1<XFHarm_impl::minmax4_t<NV>, 
                                  1, 
                                  Min_0Range>;

template <int NV>
using Min_5 = parameter::from0To1<XFHarm_impl::minmax3_t<NV>, 
                                  1, 
                                  Min_0Range>;

DECLARE_PARAMETER_RANGE_STEP(Min_6Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using Min_6 = parameter::from0To1<XFHarm_impl::minmax2_t<NV>, 
                                  1, 
                                  Min_6Range>;

template <int NV>
using Min_7 = parameter::from0To1<XFHarm_impl::minmax1_t<NV>, 
                                  1, 
                                  Min_0Range>;

template <int NV>
using Min = parameter::chain<Min_InputRange, 
                             Min_0<NV>, 
                             Min_1<NV>, 
                             Min_2<NV>, 
                             Min_3<NV>, 
                             Min_4<NV>, 
                             Min_5<NV>, 
                             Min_6<NV>, 
                             Min_7<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Max_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using Max_0 = parameter::from0To1<XFHarm_impl::minmax_t<NV>, 
                                  2, 
                                  Min_0Range>;

template <int NV>
using Max_1 = parameter::from0To1<XFHarm_impl::minmax7_t<NV>, 
                                  2, 
                                  Min_0Range>;

template <int NV>
using Max_2 = parameter::from0To1<XFHarm_impl::minmax6_t<NV>, 
                                  2, 
                                  Min_0Range>;

template <int NV>
using Max_3 = parameter::from0To1<XFHarm_impl::minmax5_t<NV>, 
                                  2, 
                                  Min_0Range>;

template <int NV>
using Max_4 = parameter::from0To1<XFHarm_impl::minmax4_t<NV>, 
                                  2, 
                                  Min_0Range>;

template <int NV>
using Max_5 = parameter::from0To1<XFHarm_impl::minmax3_t<NV>, 
                                  2, 
                                  Min_0Range>;

template <int NV>
using Max_6 = parameter::from0To1<XFHarm_impl::minmax2_t<NV>, 
                                  2, 
                                  Min_6Range>;

template <int NV>
using Max_7 = parameter::from0To1<XFHarm_impl::minmax1_t<NV>, 
                                  2, 
                                  Min_0Range>;

template <int NV>
using Max = parameter::chain<Max_InputRange, 
                             Max_0<NV>, 
                             Max_1<NV>, 
                             Max_2<NV>, 
                             Max_3<NV>, 
                             Max_4<NV>, 
                             Max_5<NV>, 
                             Max_6<NV>, 
                             Max_7<NV>>;

template <int NV>
using Step = parameter::chain<ranges::Identity, 
                              parameter::plain<XFHarm_impl::minmax_t<NV>, 4>, 
                              parameter::plain<XFHarm_impl::minmax7_t<NV>, 4>, 
                              parameter::plain<XFHarm_impl::minmax6_t<NV>, 4>, 
                              parameter::plain<XFHarm_impl::minmax5_t<NV>, 4>, 
                              parameter::plain<XFHarm_impl::minmax4_t<NV>, 4>, 
                              parameter::plain<XFHarm_impl::minmax3_t<NV>, 4>, 
                              parameter::plain<XFHarm_impl::minmax2_t<NV>, 4>, 
                              parameter::plain<XFHarm_impl::minmax1_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE_SKEW(ftpye_InputRange, 
                             0., 
                             5., 
                             0.968275);
DECLARE_PARAMETER_RANGE_STEP(ftpye_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using ftpye_0 = parameter::from0To1<filters::svf<NV>, 
                                    4, 
                                    ftpye_0Range>;

template <int NV> using ftpye_1 = ftpye_0<NV>;

template <int NV> using ftpye_2 = ftpye_0<NV>;

template <int NV> using ftpye_3 = ftpye_0<NV>;

template <int NV> using ftpye_4 = ftpye_0<NV>;

template <int NV> using ftpye_5 = ftpye_0<NV>;

template <int NV> using ftpye_6 = ftpye_0<NV>;

template <int NV> using ftpye_7 = ftpye_0<NV>;

template <int NV>
using ftpye = parameter::chain<ftpye_InputRange, 
                               ftpye_0<NV>, 
                               ftpye_1<NV>, 
                               ftpye_2<NV>, 
                               ftpye_3<NV>, 
                               ftpye_4<NV>, 
                               ftpye_5<NV>, 
                               ftpye_6<NV>, 
                               ftpye_7<NV>>;

template <int NV>
using Res = parameter::chain<ranges::Identity, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>, 
                             parameter::plain<filters::svf<NV>, 1>>;

DECLARE_PARAMETER_RANGE(Tempo3_InputRange, 
                        0., 
                        18.);
DECLARE_PARAMETER_RANGE_STEP(Tempo3_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using Tempo3_0 = parameter::from0To1<XFHarm_impl::tempo_sync3_t<NV>, 
                                     0, 
                                     Tempo3_0Range>;

template <int NV>
using Tempo3 = parameter::chain<Tempo3_InputRange, Tempo3_0<NV>>;

DECLARE_PARAMETER_RANGE(Div3_InputRange, 
                        1., 
                        16.);
template <int NV>
using Div3_0 = parameter::from0To1<XFHarm_impl::tempo_sync3_t<NV>, 
                                   1, 
                                   Min_0Range>;

template <int NV>
using Div3 = parameter::chain<Div3_InputRange, Div3_0<NV>>;

template <int NV>
using Xfade = parameter::plain<XFHarm_impl::pma19_t<NV>, 
                               2>;
template <int NV>
using XfMod1 = parameter::plain<XFHarm_impl::pma19_t<NV>, 
                                1>;
template <int NV>
using XfMod2 = parameter::plain<XFHarm_impl::pma8_t<NV>, 
                                1>;
template <int NV>
using Harm = parameter::plain<XFHarm_impl::pma22_t<NV>, 
                              2>;
template <int NV>
using HarmMod1 = parameter::plain<XFHarm_impl::pma22_t<NV>, 
                                  1>;
template <int NV>
using HarmMod2 = parameter::plain<XFHarm_impl::pma17_t<NV>, 
                                  1>;
template <int NV>
using Cut = parameter::plain<XFHarm_impl::pma23_t<NV>, 
                             2>;
template <int NV>
using CutMod1 = parameter::plain<XFHarm_impl::pma23_t<NV>, 
                                 1>;
template <int NV>
using CutMod2 = parameter::plain<XFHarm_impl::pma16_t<NV>, 
                                 1>;
template <int NV>
using pitch = parameter::plain<XFHarm_impl::pma21_t<NV>, 
                               2>;
template <int NV>
using PitchMod1 = parameter::plain<XFHarm_impl::pma21_t<NV>, 
                                   1>;
template <int NV>
using PitchMod2 = parameter::plain<XFHarm_impl::pma10_t<NV>, 
                                   1>;
template <int NV>
using Vol = parameter::plain<XFHarm_impl::pma24_t<NV>, 
                             2>;
template <int NV>
using VolMod1 = parameter::plain<XFHarm_impl::pma24_t<NV>, 
                                 1>;
template <int NV>
using VolMod2 = parameter::plain<XFHarm_impl::pma15_t<NV>, 
                                 1>;
template <int NV>
using Pan = parameter::plain<XFHarm_impl::pma20_t<NV>, 
                             2>;
template <int NV>
using PanMod1 = parameter::plain<XFHarm_impl::pma20_t<NV>, 
                                 1>;
template <int NV>
using PanMod2 = parameter::plain<XFHarm_impl::pma18_t<NV>, 
                                 1>;
template <int NV>
using Tempo1 = parameter::plain<XFHarm_impl::tempo_sync_t<NV>, 
                                0>;
template <int NV>
using Div1 = parameter::plain<XFHarm_impl::tempo_sync_t<NV>, 
                              1>;
template <int NV>
using Once1 = parameter::plain<XFHarm_impl::ramp_t<NV>, 
                               1>;
template <int NV>
using Attack = parameter::plain<XFHarm_impl::ahdsr_t<NV>, 
                                0>;
template <int NV>
using Decay = parameter::plain<XFHarm_impl::ahdsr_t<NV>, 
                               3>;
template <int NV>
using Sus = parameter::plain<XFHarm_impl::ahdsr_t<NV>, 
                             4>;
template <int NV>
using rel = parameter::plain<XFHarm_impl::ahdsr_t<NV>, 
                             5>;
using gate1 = parameter::plain<XFHarm_impl::pack8_writer_t, 
                               0>;
using gate2 = parameter::plain<XFHarm_impl::pack8_writer_t, 
                               2>;
using gate3 = parameter::plain<XFHarm_impl::pack8_writer_t, 
                               4>;
using gate4 = parameter::plain<XFHarm_impl::pack8_writer_t, 
                               6>;
using gate5 = parameter::plain<XFHarm_impl::pack8_writer1_t, 
                               0>;
using gate6 = parameter::plain<XFHarm_impl::pack8_writer1_t, 
                               2>;
using gate7 = parameter::plain<XFHarm_impl::pack8_writer1_t, 
                               4>;
using gate8 = parameter::plain<XFHarm_impl::pack8_writer1_t, 
                               6>;
template <int NV>
using gateAtk = parameter::plain<XFHarm_impl::simple_ar2_t<NV>, 
                                 0>;
template <int NV>
using gateRel = parameter::plain<XFHarm_impl::simple_ar2_t<NV>, 
                                 1>;
template <int NV>
using tempo2 = parameter::plain<XFHarm_impl::tempo_sync2_t<NV>, 
                                0>;
template <int NV>
using div2 = parameter::plain<XFHarm_impl::tempo_sync2_t<NV>, 
                              1>;
template <int NV>
using once2 = parameter::plain<XFHarm_impl::ramp2_t<NV>, 
                               1>;
template <int NV>
using LFOmode = parameter::plain<XFHarm_impl::oscillator1_t<NV>, 
                                 0>;
template <int NV>
using SFZ = parameter::plain<XFHarm_impl::SFZ_t<NV>, 0>;
template <int NV>
using modmode1 = parameter::plain<XFHarm_impl::switcher16_t<NV>, 
                                  0>;
template <int NV>
using modmode2 = parameter::plain<XFHarm_impl::switcher17_t<NV>, 
                                  0>;
template <int NV>
using env_trig = parameter::plain<XFHarm_impl::input_toggle8_t<NV>, 
                                  0>;
template <int NV>
using vel1 = parameter::plain<XFHarm_impl::pma9_t<NV>, 
                              1>;
template <int NV>
using vel2 = parameter::plain<XFHarm_impl::pma25_t<NV>, 
                              1>;
using fmix = parameter::plain<XFHarm_impl::cutmix_t, 0>;
template <int NV>
using Xfmod3 = parameter::plain<XFHarm_impl::pma11_t<NV>, 
                                1>;
template <int NV>
using Harmmod3 = parameter::plain<XFHarm_impl::pma14_t<NV>, 
                                  1>;
template <int NV>
using Pitchmod3 = parameter::plain<XFHarm_impl::pma13_t<NV>, 
                                   1>;
template <int NV>
using Cutmod3 = parameter::plain<XFHarm_impl::pma26_t<NV>, 
                                 1>;
template <int NV>
using Panmod3 = parameter::plain<control::pma<NV, parameter::empty>, 
                                 1>;
template <int NV>
using Volmod3 = parameter::plain<XFHarm_impl::pma27_t<NV>, 
                                 1>;
template <int NV>
using ModMode3 = parameter::plain<XFHarm_impl::switcher18_t<NV>, 
                                  0>;
template <int NV>
using Once3 = parameter::plain<XFHarm_impl::ramp3_t<NV>, 
                               1>;
template <int NV>
using LFOShape2 = parameter::plain<XFHarm_impl::oscillator2_t<NV>, 
                                   0>;
template <int NV>
using XFHarm_t_plist = parameter::list<XfIN<NV>, 
                                       Xfade<NV>, 
                                       XfMod1<NV>, 
                                       XfMod2<NV>, 
                                       smooth<NV>, 
                                       Harm<NV>, 
                                       HarmMod1<NV>, 
                                       HarmMod2<NV>, 
                                       Cut<NV>, 
                                       CutMod1<NV>, 
                                       CutMod2<NV>, 
                                       Min<NV>, 
                                       Max<NV>, 
                                       Step<NV>, 
                                       pitch<NV>, 
                                       PitchMod1<NV>, 
                                       PitchMod2<NV>, 
                                       ftpye<NV>, 
                                       Vol<NV>, 
                                       VolMod1<NV>, 
                                       VolMod2<NV>, 
                                       Pan<NV>, 
                                       PanMod1<NV>, 
                                       PanMod2<NV>, 
                                       Res<NV>, 
                                       Tempo1<NV>, 
                                       Div1<NV>, 
                                       Once1<NV>, 
                                       Attack<NV>, 
                                       Decay<NV>, 
                                       Sus<NV>, 
                                       rel<NV>, 
                                       gate1, 
                                       gate2, 
                                       gate3, 
                                       gate4, 
                                       gate5, 
                                       gate6, 
                                       gate7, 
                                       gate8, 
                                       gateAtk<NV>, 
                                       gateRel<NV>, 
                                       tempo2<NV>, 
                                       div2<NV>, 
                                       once2<NV>, 
                                       LFOmode<NV>, 
                                       SFZ<NV>, 
                                       modmode1<NV>, 
                                       modmode2<NV>, 
                                       env_trig<NV>, 
                                       vel1<NV>, 
                                       vel2<NV>, 
                                       fmix, 
                                       Xfmod3<NV>, 
                                       Harmmod3<NV>, 
                                       Pitchmod3<NV>, 
                                       Cutmod3<NV>, 
                                       Panmod3<NV>, 
                                       Volmod3<NV>, 
                                       Tempo3<NV>, 
                                       Div3<NV>, 
                                       ModMode3<NV>, 
                                       Once3<NV>, 
                                       LFOShape2<NV>>;
}

template <int NV>
using XFHarm_t_ = container::chain<XFHarm_t_parameters::XFHarm_t_plist<NV>, 
                                   wrap::fix<2, split3_t<NV>>, 
                                   split5_t<NV>, 
                                   HarmFade_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public XFHarm_impl::XFHarm_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 3;
		static const int NumSliderPacks = 14;
		static const int NumAudioFiles = 16;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(XFHarm);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(1014)
		{
			0x005B, 0x0000, 0x5800, 0x4966, 0x004E, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x015B, 
            0x0000, 0x5800, 0x6166, 0x6564, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 
            0x0000, 0x6658, 0x6F4D, 0x3164, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0xC33F, 0x531B, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 
            0x0000, 0x6658, 0x6F4D, 0x3264, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 
            0x0000, 0x6D73, 0x6F6F, 0x6874, 0x0000, 0x0000, 0x0000, 0x7A00, 
            0x0044, 0x8000, 0x9B3F, 0x9A20, 0xCD3E, 0xCCCC, 0x5B3D, 0x0005, 
            0x0000, 0x6148, 0x6D72, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 
            0x6148, 0x6D72, 0x6F4D, 0x3164, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 
            0x0000, 0x6148, 0x6D72, 0x6F4D, 0x3264, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0008, 0x0000, 0x7543, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 
            0x4300, 0x7475, 0x6F4D, 0x3164, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000A, 
            0x0000, 0x7543, 0x4D74, 0x646F, 0x0032, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0B5B, 
            0x0000, 0x4D00, 0x6E69, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000C, 0x0000, 
            0x614D, 0x0078, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x4180, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0D5B, 0x0000, 0x5300, 0x6574, 
            0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0E5B, 0x0000, 0x7000, 0x7469, 0x6863, 
            0x0000, 0x0000, 0x0000, 0x8000, 0xB63F, 0x11FA, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000F, 0x0000, 0x6950, 0x6374, 0x4D68, 
            0x646F, 0x0031, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x105B, 0x0000, 0x5000, 0x7469, 
            0x6863, 0x6F4D, 0x3264, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0011, 0x0000, 
            0x7466, 0x7970, 0x0065, 0x0000, 0x0000, 0x0000, 0x40A0, 0x0000, 
            0x0000, 0xE0D9, 0x3F77, 0x0000, 0x0000, 0x125B, 0x0000, 0x5600, 
            0x6C6F, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0013, 0x0000, 0x6F56, 0x4D6C, 
            0x646F, 0x0031, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x145B, 0x0000, 0x5600, 0x6C6F, 
            0x6F4D, 0x3264, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0015, 0x0000, 0x6150, 
            0x006E, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x165B, 0x0000, 0x5000, 0x6E61, 0x6F4D, 
            0x3164, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0017, 0x0000, 0x6150, 0x4D6E, 
            0x646F, 0x0032, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x185B, 0x0000, 0x5200, 0x7365, 
            0x9A00, 0x9999, 0x663E, 0x1E66, 0x0041, 0x8000, 0x183F, 0x8789, 
            0x003E, 0x0000, 0x5B00, 0x0019, 0x0000, 0x6554, 0x706D, 0x316F, 
            0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x001A, 0x0000, 0x6944, 0x3176, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x001B, 0x0000, 0x6E4F, 0x6563, 0x0031, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x1C5B, 0x0000, 0x4100, 0x7474, 0x6361, 0x006B, 0x0000, 
            0x0000, 0x4000, 0x461C, 0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 
            0x3DCC, 0x1D5B, 0x0000, 0x4400, 0x6365, 0x7961, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0x8000, 0x723F, 0x4A6A, 0xCD3E, 0xCCCC, 
            0x5B3D, 0x001E, 0x0000, 0x7553, 0x0073, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x5C35, 0x3E00, 0x0000, 0x3F80, 0x0000, 0x0000, 0x1F5B, 
            0x0000, 0x7200, 0x6C65, 0x0000, 0x0000, 0x0000, 0x1C40, 0x3346, 
            0x09CB, 0x7245, 0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x0020, 0x0000, 
            0x6167, 0x6574, 0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x215B, 0x0000, 0x6700, 
            0x7461, 0x3265, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0022, 0x0000, 0x6167, 
            0x6574, 0x0033, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x235B, 0x0000, 0x6700, 0x7461, 
            0x3465, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0024, 0x0000, 0x6167, 0x6574, 
            0x0035, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x255B, 0x0000, 0x6700, 0x7461, 0x3665, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0026, 0x0000, 0x6167, 0x6574, 0x0037, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x275B, 0x0000, 0x6700, 0x7461, 0x3865, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0028, 0x0000, 0x6167, 0x6574, 0x7441, 0x006B, 
            0x0000, 0x0000, 0x4000, 0x461C, 0xACCD, 0x44F2, 0x209B, 0x3E9A, 
            0xCCCD, 0x3DCC, 0x295B, 0x0000, 0x6700, 0x7461, 0x5265, 0x6C65, 
            0x0000, 0x0000, 0x0000, 0x1C40, 0x0046, 0x1C40, 0x9B46, 0x9A20, 
            0xCD3E, 0xCCCC, 0x5B3D, 0x002A, 0x0000, 0x6574, 0x706D, 0x326F, 
            0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x002B, 0x0000, 0x6964, 0x3276, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x002C, 0x0000, 0x6E6F, 0x6563, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x2D5B, 0x0000, 0x4C00, 0x4F46, 0x6F6D, 0x6564, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x002E, 0x0000, 0x4653, 0x005A, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x2F5B, 0x0000, 0x6D00, 0x646F, 0x6F6D, 0x6564, 0x0031, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x305B, 0x0000, 0x6D00, 0x646F, 0x6F6D, 0x6564, 0x0032, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x315B, 0x0000, 0x6500, 0x766E, 0x745F, 0x6972, 
            0x0067, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x325B, 0x0000, 0x7600, 0x6C65, 0x0031, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x578D, 0x3BCE, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x335B, 0x0000, 0x7600, 0x6C65, 0x0032, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x39FC, 0x3CAC, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x345B, 0x0000, 0x6600, 0x696D, 0x0078, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x355B, 0x0000, 0x5800, 0x6D66, 0x646F, 0x0033, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0xB9DB, 0xBD9F, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x365B, 0x0000, 0x4800, 0x7261, 0x6D6D, 0x646F, 0x0033, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x54DD, 0x3D8C, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x375B, 0x0000, 0x5000, 0x7469, 0x6863, 0x6F6D, 0x3364, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x5C3F, 0x228F, 0x003D, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0038, 0x0000, 0x7543, 0x6D74, 0x646F, 
            0x0033, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x199A, 0xBC73, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x395B, 0x0000, 0x5000, 0x6E61, 0x6F6D, 
            0x3364, 0x0000, 0x8000, 0x00BF, 0x8000, 0x1D3F, 0x3DFA, 0x00BD, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x003A, 0x0000, 0x6F56, 0x6D6C, 
            0x646F, 0x0033, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x7AE1, 0x3C64, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x3B5B, 0x0000, 0x5400, 0x6D65, 
            0x6F70, 0x0033, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x3C5B, 0x0000, 0x4400, 0x7669, 
            0x0033, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x3D5B, 0x0000, 0x4D00, 0x646F, 0x6F4D, 
            0x6564, 0x0033, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x3E5B, 0x0000, 0x4F00, 0x636E, 
            0x3365, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x003F, 0x0000, 0x464C, 0x534F, 
            0x6168, 0x6570, 0x0032, 0x0000, 0x0000, 0x0000, 0x4080, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split3 = this->getT(0);                                                         // XFHarm_impl::split3_t<NV>
		auto& modchain = this->getT(0).getT(0);                                               // XFHarm_impl::modchain_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(0);                                     // XFHarm_impl::tempo_sync_t<NV>
		auto& no_midi = this->getT(0).getT(0).getT(1);                                        // XFHarm_impl::no_midi_t<NV>
		auto& ramp = this->getT(0).getT(0).getT(1).getT(0);                                   // XFHarm_impl::ramp_t<NV>
		auto& softbypass_switch20 = this->getT(0).getT(0).getT(2);                            // XFHarm_impl::softbypass_switch20_t<NV>
		auto& switcher16 = this->getT(0).getT(0).getT(2).getT(0);                             // XFHarm_impl::switcher16_t<NV>
		auto& sb_container16 = this->getT(0).getT(0).getT(2).getT(1);                         // XFHarm_impl::sb_container16_t<NV>
		auto& sb33 = this->getT(0).getT(0).getT(2).getT(1).getT(0);                           // XFHarm_impl::sb33_t<NV>
		auto& input_toggle8 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);          // XFHarm_impl::input_toggle8_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);                 // math::clear<NV>
		auto& ahdsr = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);                  // XFHarm_impl::ahdsr_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(3);                   // math::add<NV>
		auto& sb37 = this->getT(0).getT(0).getT(2).getT(1).getT(1);                           // XFHarm_impl::sb37_t<NV>
		auto& fix8_block = this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(0);             // XFHarm_impl::fix8_block_t<NV>
		auto& chain21 = this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(0).getT(0);        // XFHarm_impl::chain21_t<NV>
		auto& clear17 = this->getT(0).getT(0).getT(2).getT(1).                                // math::clear<NV>
                        getT(1).getT(0).getT(0).getT(0);
		auto& split10 = this->getT(0).getT(0).getT(2).getT(1).                                // XFHarm_impl::split10_t<NV>
                        getT(1).getT(0).getT(0).getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(2).getT(1).                                // XFHarm_impl::chain33_t<NV>
                        getT(1).getT(0).getT(0).getT(1).
                        getT(0);
		auto& pack8_writer = this->getT(0).getT(0).getT(2).getT(1).getT(1).                   // XFHarm_impl::pack8_writer_t
                             getT(0).getT(0).getT(1).getT(0).getT(0);
		auto& cable_table5 = this->getT(0).getT(0).getT(2).getT(1).getT(1).                   // XFHarm_impl::cable_table5_t<NV>
                             getT(0).getT(0).getT(1).getT(0).getT(1);
		auto& clear14 = this->getT(0).getT(0).getT(2).getT(1).getT(1).                        // math::clear<NV>
                        getT(0).getT(0).getT(1).getT(0).getT(2);
		auto& cable_pack2 = this->getT(0).getT(0).getT(2).getT(1).getT(1).                    // XFHarm_impl::cable_pack2_t<NV>
                            getT(0).getT(0).getT(1).getT(0).getT(3);
		auto& add57 = this->getT(0).getT(0).getT(2).getT(1).getT(1).                          // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(4);
		auto& chain83 = this->getT(0).getT(0).getT(2).getT(1).                                // XFHarm_impl::chain83_t<NV>
                        getT(1).getT(0).getT(0).getT(1).
                        getT(1);
		auto& pack8_writer1 = this->getT(0).getT(0).getT(2).getT(1).getT(1).                  // XFHarm_impl::pack8_writer1_t
                              getT(0).getT(0).getT(1).getT(1).getT(0);
		auto& cable_table10 = this->getT(0).getT(0).getT(2).getT(1).getT(1).                  // XFHarm_impl::cable_table10_t<NV>
                              getT(0).getT(0).getT(1).getT(1).getT(1);
		auto& clear16 = this->getT(0).getT(0).getT(2).getT(1).getT(1).                        // math::clear<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(2);
		auto& cable_pack1 = this->getT(0).getT(0).getT(2).getT(1).getT(1).                    // XFHarm_impl::cable_pack1_t<NV>
                            getT(0).getT(0).getT(1).getT(1).getT(3);
		auto& add58 = this->getT(0).getT(0).getT(2).getT(1).getT(1).                          // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).getT(4);
		auto& peak2 = this->getT(0).getT(0).getT(2).getT(1).                                  // XFHarm_impl::peak2_t<NV>
                      getT(1).getT(0).getT(0).getT(2);
		auto& clear1 = this->getT(0).getT(0).getT(2).getT(1).                                 // math::clear<NV>
                       getT(1).getT(0).getT(0).getT(3);
		auto& simple_ar2 = this->getT(0).getT(0).getT(2).getT(1).                             // XFHarm_impl::simple_ar2_t<NV>
                           getT(1).getT(0).getT(0).getT(4);
		auto& add7 = this->getT(0).getT(0).getT(2).getT(1).                                   // math::add<NV>
                     getT(1).getT(0).getT(0).getT(5);
		auto& midi = this->getT(0).getT(0).getT(3);                                           // XFHarm_impl::midi_t<NV>
		auto& pma9 = this->getT(0).getT(0).getT(4);                                           // XFHarm_impl::pma9_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(5);                                           // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(6);                                           // XFHarm_impl::peak_t<NV>
		auto& clear3 = this->getT(0).getT(0).getT(7);                                         // math::clear<NV>
		auto& modchain1 = this->getT(0).getT(1);                                              // XFHarm_impl::modchain1_t<NV>
		auto& tempo_sync2 = this->getT(0).getT(1).getT(0);                                    // XFHarm_impl::tempo_sync2_t<NV>
		auto& no_midi1 = this->getT(0).getT(1).getT(1);                                       // XFHarm_impl::no_midi1_t<NV>
		auto& ramp2 = this->getT(0).getT(1).getT(1).getT(0);                                  // XFHarm_impl::ramp2_t<NV>
		auto& softbypass_switch21 = this->getT(0).getT(1).getT(2);                            // XFHarm_impl::softbypass_switch21_t<NV>
		auto& switcher17 = this->getT(0).getT(1).getT(2).getT(0);                             // XFHarm_impl::switcher17_t<NV>
		auto& sb_container17 = this->getT(0).getT(1).getT(2).getT(1);                         // XFHarm_impl::sb_container17_t<NV>
		auto& sb39 = this->getT(0).getT(1).getT(2).getT(1).getT(0);                           // XFHarm_impl::sb39_t<NV>
		auto& converter1 = this->getT(0).getT(1).getT(2).getT(1).getT(0).getT(0);             // XFHarm_impl::converter1_t<NV>
		auto& oscillator1 = this->getT(0).getT(1).getT(2).getT(1).getT(0).getT(1);            // XFHarm_impl::oscillator1_t<NV>
		auto& sig2mod1 = this->getT(0).getT(1).getT(2).getT(1).getT(0).getT(2);               // math::sig2mod<NV>
		auto& sb40 = this->getT(0).getT(1).getT(2).getT(1).getT(1);                           // XFHarm_impl::sb40_t<NV>
		auto& cable_table1 = this->getT(0).getT(1).getT(2).getT(1).getT(1).getT(0);           // XFHarm_impl::cable_table1_t<NV>
		auto& add = this->getT(0).getT(1).getT(2).getT(1).getT(1).getT(1);                    // math::add<NV>
		auto& sb41 = this->getT(0).getT(1).getT(2).getT(1).getT(2);                           // XFHarm_impl::sb41_t<NV>
		auto& chain24 = this->getT(0).getT(1).getT(2).getT(1).getT(2).getT(0);                // XFHarm_impl::chain24_t<NV>
		auto& clear8 = this->getT(0).getT(1).getT(2).getT(1).getT(2).getT(0).getT(0);         // math::clear<NV>
		auto& steppack1 = this->getT(0).getT(1).getT(2).getT(1).getT(2).getT(0).getT(1);      // XFHarm_impl::steppack1_t<NV>
		auto& add1 = this->getT(0).getT(1).getT(2).getT(1).getT(2).getT(0).getT(2);           // math::add<NV>
		auto& midi1 = this->getT(0).getT(1).getT(3);                                          // XFHarm_impl::midi1_t<NV>
		auto& pma25 = this->getT(0).getT(1).getT(4);                                          // XFHarm_impl::pma25_t<NV>
		auto& add3 = this->getT(0).getT(1).getT(5);                                           // math::add<NV>
		auto& peak1 = this->getT(0).getT(1).getT(6);                                          // XFHarm_impl::peak1_t<NV>
		auto& modchain2 = this->getT(0).getT(2);                                              // XFHarm_impl::modchain2_t<NV>
		auto& tempo_sync3 = this->getT(0).getT(2).getT(0);                                    // XFHarm_impl::tempo_sync3_t<NV>
		auto& no_midi2 = this->getT(0).getT(2).getT(1);                                       // XFHarm_impl::no_midi2_t<NV>
		auto& ramp3 = this->getT(0).getT(2).getT(1).getT(0);                                  // XFHarm_impl::ramp3_t<NV>
		auto& softbypass_switch22 = this->getT(0).getT(2).getT(2);                            // XFHarm_impl::softbypass_switch22_t<NV>
		auto& switcher18 = this->getT(0).getT(2).getT(2).getT(0);                             // XFHarm_impl::switcher18_t<NV>
		auto& sb_container18 = this->getT(0).getT(2).getT(2).getT(1);                         // XFHarm_impl::sb_container18_t<NV>
		auto& sb42 = this->getT(0).getT(2).getT(2).getT(1).getT(0);                           // XFHarm_impl::sb42_t<NV>
		auto& converter2 = this->getT(0).getT(2).getT(2).getT(1).getT(0).getT(0);             // XFHarm_impl::converter2_t<NV>
		auto& oscillator2 = this->getT(0).getT(2).getT(2).getT(1).getT(0).getT(1);            // XFHarm_impl::oscillator2_t<NV>
		auto& sig2mod2 = this->getT(0).getT(2).getT(2).getT(1).getT(0).getT(2);               // math::sig2mod<NV>
		auto& sb43 = this->getT(0).getT(2).getT(2).getT(1).getT(1);                           // XFHarm_impl::sb43_t<NV>
		auto& cable_table2 = this->getT(0).getT(2).getT(2).getT(1).getT(1).getT(0);           // XFHarm_impl::cable_table2_t<NV>
		auto& add4 = this->getT(0).getT(2).getT(2).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& sb44 = this->getT(0).getT(2).getT(2).getT(1).getT(2);                           // XFHarm_impl::sb44_t<NV>
		auto& chain25 = this->getT(0).getT(2).getT(2).getT(1).getT(2).getT(0);                // XFHarm_impl::chain25_t<NV>
		auto& clear9 = this->getT(0).getT(2).getT(2).getT(1).getT(2).getT(0).getT(0);         // math::clear<NV>
		auto& steppack2 = this->getT(0).getT(2).getT(2).getT(1).getT(2).getT(0).getT(1);      // XFHarm_impl::steppack2_t<NV>
		auto& add5 = this->getT(0).getT(2).getT(2).getT(1).getT(2).getT(0).getT(2);           // math::add<NV>
		auto& midi2 = this->getT(0).getT(2).getT(3);                                          // XFHarm_impl::midi2_t<NV>
		auto& pma28 = this->getT(0).getT(2).getT(4);                                          // XFHarm_impl::pma28_t<NV>
		auto& add6 = this->getT(0).getT(2).getT(5);                                           // math::add<NV>
		auto& peak3 = this->getT(0).getT(2).getT(6);                                          // XFHarm_impl::peak3_t<NV>
		auto& split5 = this->getT(1);                                                         // XFHarm_impl::split5_t<NV>
		auto& chain12 = this->getT(1).getT(0);                                                // XFHarm_impl::chain12_t<NV>
		auto& pma19 = this->getT(1).getT(0).getT(0);                                          // XFHarm_impl::pma19_t<NV>
		auto& pma11 = this->getT(1).getT(0).getT(1);                                          // XFHarm_impl::pma11_t<NV>
		auto& pma8 = this->getT(1).getT(0).getT(2);                                           // XFHarm_impl::pma8_t<NV>
		auto& cable_table = this->getT(1).getT(0).getT(3);                                    // XFHarm_impl::cable_table_t
		auto& chain13 = this->getT(1).getT(1);                                                // XFHarm_impl::chain13_t<NV>
		auto& pma21 = this->getT(1).getT(1).getT(0);                                          // XFHarm_impl::pma21_t<NV>
		auto& pma13 = this->getT(1).getT(1).getT(1);                                          // XFHarm_impl::pma13_t<NV>
		auto& pma10 = this->getT(1).getT(1).getT(2);                                          // XFHarm_impl::pma10_t<NV>
		auto& chain22 = this->getT(1).getT(2);                                                // XFHarm_impl::chain22_t<NV>
		auto& pma22 = this->getT(1).getT(2).getT(0);                                          // XFHarm_impl::pma22_t<NV>
		auto& pma14 = this->getT(1).getT(2).getT(1);                                          // XFHarm_impl::pma14_t<NV>
		auto& pma_unscaled8 = this->getT(1).getT(2).getT(2);                                  // XFHarm_impl::pma_unscaled8_t<NV>
		auto& midi_cc = this->getT(1).getT(2).getT(3);                                        // XFHarm_impl::midi_cc_t<NV>
		auto& pma17 = this->getT(1).getT(2).getT(4);                                          // XFHarm_impl::pma17_t<NV>
		auto& chain19 = this->getT(1).getT(3);                                                // XFHarm_impl::chain19_t<NV>
		auto& pma23 = this->getT(1).getT(3).getT(0);                                          // XFHarm_impl::pma23_t<NV>
		auto& pma26 = this->getT(1).getT(3).getT(1);                                          // XFHarm_impl::pma26_t<NV>
		auto& pma16 = this->getT(1).getT(3).getT(2);                                          // XFHarm_impl::pma16_t<NV>
		auto& chain18 = this->getT(1).getT(4);                                                // XFHarm_impl::chain18_t<NV>
		auto& pma24 = this->getT(1).getT(4).getT(0);                                          // XFHarm_impl::pma24_t<NV>
		auto& pma27 = this->getT(1).getT(4).getT(1);                                          // XFHarm_impl::pma27_t<NV>
		auto& pma15 = this->getT(1).getT(4).getT(2);                                          // XFHarm_impl::pma15_t<NV>
		auto& chain23 = this->getT(1).getT(5);                                                // XFHarm_impl::chain23_t<NV>
		auto& pma20 = this->getT(1).getT(5).getT(0);                                          // XFHarm_impl::pma20_t<NV>
		auto& pma12 = this->getT(1).getT(5).getT(1);                                          // control::pma<NV, parameter::empty>
		auto& pma18 = this->getT(1).getT(5).getT(2);                                          // XFHarm_impl::pma18_t<NV>
		auto& HarmFade = this->getT(2);                                                       // XFHarm_impl::HarmFade_t<NV>
		auto& chain9 = this->getT(2).getT(0);                                                 // XFHarm_impl::chain9_t<NV>
		auto& chain8 = this->getT(2).getT(0).getT(0);                                         // XFHarm_impl::chain8_t<NV>
		auto& chain10 = this->getT(2).getT(0).getT(0).getT(0);                                // XFHarm_impl::chain10_t<NV>
		auto& chain11 = this->getT(2).getT(0).getT(0).getT(0).getT(0);                        // XFHarm_impl::chain11_t<NV>
		auto& split1 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(0);                 // XFHarm_impl::split1_t<NV>
		auto& xfader = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);         // XFHarm_impl::xfader_t<NV>
		auto& xfader3 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);        // XFHarm_impl::xfader3_t<NV>
		auto& split4 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(1);                 // XFHarm_impl::split4_t<NV>
		auto& input_toggle = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);   // XFHarm_impl::input_toggle_t<NV>
		auto& input_toggle1 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);  // XFHarm_impl::input_toggle1_t<NV>
		auto& input_toggle2 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);  // XFHarm_impl::input_toggle2_t<NV>
		auto& input_toggle3 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);  // XFHarm_impl::input_toggle3_t<NV>
		auto& input_toggle4 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(1).getT(4);  // XFHarm_impl::input_toggle4_t<NV>
		auto& input_toggle5 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(1).getT(5);  // XFHarm_impl::input_toggle5_t<NV>
		auto& input_toggle6 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(1).getT(6);  // XFHarm_impl::input_toggle6_t<NV>
		auto& input_toggle7 = this->getT(2).getT(0).getT(0).getT(0).getT(0).getT(1).getT(7);  // XFHarm_impl::input_toggle7_t<NV>
		auto& split2 = this->getT(2).getT(0).getT(0).getT(1);                                 // XFHarm_impl::split2_t<NV>
		auto& harm = this->getT(2).getT(0).getT(0).getT(1).getT(0);                           // XFHarm_impl::harm_t<NV>
		auto& cut = this->getT(2).getT(0).getT(0).getT(1).getT(1);                            // XFHarm_impl::cut_t<NV>
		auto& pan = this->getT(2).getT(0).getT(0).getT(1).getT(2);                            // XFHarm_impl::pan_t<NV>
		auto& vol = this->getT(2).getT(0).getT(0).getT(1).getT(3);                            // XFHarm_impl::vol_t
		auto& pitch = this->getT(2).getT(0).getT(0).getT(1).getT(4);                          // XFHarm_impl::pitch_t<NV>
		auto& cutmix = this->getT(2).getT(0).getT(0).getT(1).getT(5);                         // XFHarm_impl::cutmix_t
		auto& SFZ = this->getT(2).getT(0).getT(0).getT(1).getT(6);                            // XFHarm_impl::SFZ_t<NV>
		auto& clear = this->getT(2).getT(0).getT(0).getT(2);                                  // math::clear<NV>
		auto& split = this->getT(2).getT(0).getT(1);                                          // XFHarm_impl::split_t<NV>
		auto& chain = this->getT(2).getT(0).getT(1).getT(0);                                  // XFHarm_impl::chain_t<NV>
		auto& minmax = this->getT(2).getT(0).getT(1).getT(0).getT(0);                         // XFHarm_impl::minmax_t<NV>
		auto& pma_unscaled = this->getT(2).getT(0).getT(1).getT(0).getT(1);                   // XFHarm_impl::pma_unscaled_t<NV>
		auto& softbypass_switch5 = this->getT(2).getT(0).getT(1).getT(0).getT(2);             // XFHarm_impl::softbypass_switch5_t<NV>
		auto& switcher2 = this->getT(2).getT(0).getT(1).getT(0).getT(2).getT(0);              // XFHarm_impl::switcher2_t<NV>
		auto& sb_container2 = this->getT(2).getT(0).getT(1).getT(0).getT(2).getT(1);          // XFHarm_impl::sb_container2_t<NV>
		auto& sb6 = this->getT(2).getT(0).getT(1).getT(0).getT(2).getT(1).getT(0);            // XFHarm_impl::sb6_t<NV>
		auto& file_player = this->getT(2).getT(0).getT(1).getT(0).                            // XFHarm_impl::file_player_t<NV>
                            getT(2).getT(1).getT(0).getT(0);
		auto& sb7 = this->getT(2).getT(0).getT(1).getT(0).getT(2).getT(1).getT(1);            // XFHarm_impl::sb7_t<NV>
		auto& file_player9 = this->getT(2).getT(0).getT(1).getT(0).                           // XFHarm_impl::file_player9_t<NV>
                             getT(2).getT(1).getT(1).getT(0);
		auto& dry_wet2 = this->getT(2).getT(0).getT(1).getT(0).getT(3);                       // XFHarm_impl::dry_wet2_t<NV>
		auto& dry_path1 = this->getT(2).getT(0).getT(1).getT(0).getT(3).getT(0);              // XFHarm_impl::dry_path1_t
		auto& dry_wet_mixer1 = this->getT(2).getT(0).getT(1).getT(0).getT(3).getT(0).getT(0); // XFHarm_impl::dry_wet_mixer1_t
		auto& dry_gain1 = this->getT(2).getT(0).getT(1).getT(0).getT(3).getT(0).getT(1);      // core::gain
		auto& wet_path1 = this->getT(2).getT(0).getT(1).getT(0).getT(3).getT(1);              // XFHarm_impl::wet_path1_t<NV>
		auto& svf = this->getT(2).getT(0).getT(1).getT(0).getT(3).getT(1).getT(0);            // filters::svf<NV>
		auto& wet_gain1 = this->getT(2).getT(0).getT(1).getT(0).getT(3).getT(1).getT(1);      // core::gain
		auto& pma = this->getT(2).getT(0).getT(1).getT(0).getT(4);                            // XFHarm_impl::pma_t<NV>
		auto& jpanner1 = this->getT(2).getT(0).getT(1).getT(0).getT(5);                       // jdsp::jpanner<NV>
		auto& gain8 = this->getT(2).getT(0).getT(1).getT(0).getT(6);                          // core::gain
		auto& smoothed_parameter1 = this->getT(2).getT(0).getT(1).getT(0).getT(7);            // XFHarm_impl::smoothed_parameter1_t<NV>
		auto& gain = this->getT(2).getT(0).getT(1).getT(0).getT(8);                           // core::gain
		auto& chain7 = this->getT(2).getT(0).getT(1).getT(1);                                 // XFHarm_impl::chain7_t<NV>
		auto& minmax7 = this->getT(2).getT(0).getT(1).getT(1).getT(0);                        // XFHarm_impl::minmax7_t<NV>
		auto& pma_unscaled7 = this->getT(2).getT(0).getT(1).getT(1).getT(1);                  // XFHarm_impl::pma_unscaled7_t<NV>
		auto& softbypass_switch6 = this->getT(2).getT(0).getT(1).getT(1).getT(2);             // XFHarm_impl::softbypass_switch6_t<NV>
		auto& switcher3 = this->getT(2).getT(0).getT(1).getT(1).getT(2).getT(0);              // XFHarm_impl::switcher3_t<NV>
		auto& sb_container3 = this->getT(2).getT(0).getT(1).getT(1).getT(2).getT(1);          // XFHarm_impl::sb_container3_t<NV>
		auto& sb8 = this->getT(2).getT(0).getT(1).getT(1).getT(2).getT(1).getT(0);            // XFHarm_impl::sb8_t<NV>
		auto& file_player7 = this->getT(2).getT(0).getT(1).getT(1).                           // XFHarm_impl::file_player7_t<NV>
                             getT(2).getT(1).getT(0).getT(0);
		auto& sb9 = this->getT(2).getT(0).getT(1).getT(1).getT(2).getT(1).getT(1);            // XFHarm_impl::sb9_t<NV>
		auto& file_player10 = this->getT(2).getT(0).getT(1).getT(1).                          // XFHarm_impl::file_player10_t<NV>
                              getT(2).getT(1).getT(1).getT(0);
		auto& dry_wet3 = this->getT(2).getT(0).getT(1).getT(1).getT(3);                       // XFHarm_impl::dry_wet3_t<NV>
		auto& dry_path2 = this->getT(2).getT(0).getT(1).getT(1).getT(3).getT(0);              // XFHarm_impl::dry_path2_t
		auto& dry_wet_mixer2 = this->getT(2).getT(0).getT(1).getT(1).getT(3).getT(0).getT(0); // XFHarm_impl::dry_wet_mixer2_t
		auto& dry_gain2 = this->getT(2).getT(0).getT(1).getT(1).getT(3).getT(0).getT(1);      // core::gain
		auto& wet_path2 = this->getT(2).getT(0).getT(1).getT(1).getT(3).getT(1);              // XFHarm_impl::wet_path2_t<NV>
		auto& svf7 = this->getT(2).getT(0).getT(1).getT(1).getT(3).getT(1).getT(0);           // filters::svf<NV>
		auto& wet_gain2 = this->getT(2).getT(0).getT(1).getT(1).getT(3).getT(1).getT(1);      // core::gain
		auto& pma2 = this->getT(2).getT(0).getT(1).getT(1).getT(4);                           // XFHarm_impl::pma2_t<NV>
		auto& jpanner2 = this->getT(2).getT(0).getT(1).getT(1).getT(5);                       // jdsp::jpanner<NV>
		auto& gain9 = this->getT(2).getT(0).getT(1).getT(1).getT(6);                          // core::gain
		auto& smoothed_parameter2 = this->getT(2).getT(0).getT(1).getT(1).getT(7);            // XFHarm_impl::smoothed_parameter2_t<NV>
		auto& gain7 = this->getT(2).getT(0).getT(1).getT(1).getT(8);                          // core::gain
		auto& chain6 = this->getT(2).getT(0).getT(1).getT(2);                                 // XFHarm_impl::chain6_t<NV>
		auto& minmax6 = this->getT(2).getT(0).getT(1).getT(2).getT(0);                        // XFHarm_impl::minmax6_t<NV>
		auto& pma_unscaled6 = this->getT(2).getT(0).getT(1).getT(2).getT(1);                  // XFHarm_impl::pma_unscaled6_t<NV>
		auto& softbypass_switch7 = this->getT(2).getT(0).getT(1).getT(2).getT(2);             // XFHarm_impl::softbypass_switch7_t<NV>
		auto& switcher4 = this->getT(2).getT(0).getT(1).getT(2).getT(2).getT(0);              // XFHarm_impl::switcher4_t<NV>
		auto& sb_container4 = this->getT(2).getT(0).getT(1).getT(2).getT(2).getT(1);          // XFHarm_impl::sb_container4_t<NV>
		auto& sb10 = this->getT(2).getT(0).getT(1).getT(2).getT(2).getT(1).getT(0);           // XFHarm_impl::sb10_t<NV>
		auto& file_player6 = this->getT(2).getT(0).getT(1).getT(2).                           // XFHarm_impl::file_player6_t<NV>
                             getT(2).getT(1).getT(0).getT(0);
		auto& sb11 = this->getT(2).getT(0).getT(1).getT(2).getT(2).getT(1).getT(1);           // XFHarm_impl::sb11_t<NV>
		auto& file_player11 = this->getT(2).getT(0).getT(1).getT(2).                          // XFHarm_impl::file_player11_t<NV>
                              getT(2).getT(1).getT(1).getT(0);
		auto& dry_wet4 = this->getT(2).getT(0).getT(1).getT(2).getT(3);                       // XFHarm_impl::dry_wet4_t<NV>
		auto& dry_path3 = this->getT(2).getT(0).getT(1).getT(2).getT(3).getT(0);              // XFHarm_impl::dry_path3_t
		auto& dry_wet_mixer3 = this->getT(2).getT(0).getT(1).getT(2).getT(3).getT(0).getT(0); // XFHarm_impl::dry_wet_mixer3_t
		auto& dry_gain3 = this->getT(2).getT(0).getT(1).getT(2).getT(3).getT(0).getT(1);      // core::gain
		auto& wet_path3 = this->getT(2).getT(0).getT(1).getT(2).getT(3).getT(1);              // XFHarm_impl::wet_path3_t<NV>
		auto& svf6 = this->getT(2).getT(0).getT(1).getT(2).getT(3).getT(1).getT(0);           // filters::svf<NV>
		auto& wet_gain3 = this->getT(2).getT(0).getT(1).getT(2).getT(3).getT(1).getT(1);      // core::gain
		auto& pma3 = this->getT(2).getT(0).getT(1).getT(2).getT(4);                           // XFHarm_impl::pma3_t<NV>
		auto& jpanner3 = this->getT(2).getT(0).getT(1).getT(2).getT(5);                       // jdsp::jpanner<NV>
		auto& gain10 = this->getT(2).getT(0).getT(1).getT(2).getT(6);                         // core::gain
		auto& smoothed_parameter3 = this->getT(2).getT(0).getT(1).getT(2).getT(7);            // XFHarm_impl::smoothed_parameter3_t<NV>
		auto& gain6 = this->getT(2).getT(0).getT(1).getT(2).getT(8);                          // core::gain
		auto& chain5 = this->getT(2).getT(0).getT(1).getT(3);                                 // XFHarm_impl::chain5_t<NV>
		auto& minmax5 = this->getT(2).getT(0).getT(1).getT(3).getT(0);                        // XFHarm_impl::minmax5_t<NV>
		auto& pma_unscaled5 = this->getT(2).getT(0).getT(1).getT(3).getT(1);                  // XFHarm_impl::pma_unscaled5_t<NV>
		auto& softbypass_switch8 = this->getT(2).getT(0).getT(1).getT(3).getT(2);             // XFHarm_impl::softbypass_switch8_t<NV>
		auto& switcher5 = this->getT(2).getT(0).getT(1).getT(3).getT(2).getT(0);              // XFHarm_impl::switcher5_t<NV>
		auto& sb_container5 = this->getT(2).getT(0).getT(1).getT(3).getT(2).getT(1);          // XFHarm_impl::sb_container5_t<NV>
		auto& sb12 = this->getT(2).getT(0).getT(1).getT(3).getT(2).getT(1).getT(0);           // XFHarm_impl::sb12_t<NV>
		auto& file_player5 = this->getT(2).getT(0).getT(1).getT(3).                           // XFHarm_impl::file_player5_t<NV>
                             getT(2).getT(1).getT(0).getT(0);
		auto& sb13 = this->getT(2).getT(0).getT(1).getT(3).getT(2).getT(1).getT(1);           // XFHarm_impl::sb13_t<NV>
		auto& file_player12 = this->getT(2).getT(0).getT(1).getT(3).                          // XFHarm_impl::file_player12_t<NV>
                              getT(2).getT(1).getT(1).getT(0);
		auto& dry_wet8 = this->getT(2).getT(0).getT(1).getT(3).getT(3);                       // XFHarm_impl::dry_wet8_t<NV>
		auto& dry_path7 = this->getT(2).getT(0).getT(1).getT(3).getT(3).getT(0);              // XFHarm_impl::dry_path7_t
		auto& dry_wet_mixer7 = this->getT(2).getT(0).getT(1).getT(3).getT(3).getT(0).getT(0); // XFHarm_impl::dry_wet_mixer7_t
		auto& dry_gain7 = this->getT(2).getT(0).getT(1).getT(3).getT(3).getT(0).getT(1);      // core::gain
		auto& wet_path7 = this->getT(2).getT(0).getT(1).getT(3).getT(3).getT(1);              // XFHarm_impl::wet_path7_t<NV>
		auto& svf5 = this->getT(2).getT(0).getT(1).getT(3).getT(3).getT(1).getT(0);           // filters::svf<NV>
		auto& wet_gain7 = this->getT(2).getT(0).getT(1).getT(3).getT(3).getT(1).getT(1);      // core::gain
		auto& pma4 = this->getT(2).getT(0).getT(1).getT(3).getT(4);                           // XFHarm_impl::pma4_t<NV>
		auto& jpanner4 = this->getT(2).getT(0).getT(1).getT(3).getT(5);                       // jdsp::jpanner<NV>
		auto& gain11 = this->getT(2).getT(0).getT(1).getT(3).getT(6);                         // core::gain
		auto& smoothed_parameter4 = this->getT(2).getT(0).getT(1).getT(3).getT(7);            // XFHarm_impl::smoothed_parameter4_t<NV>
		auto& gain5 = this->getT(2).getT(0).getT(1).getT(3).getT(8);                          // core::gain
		auto& chain4 = this->getT(2).getT(0).getT(1).getT(4);                                 // XFHarm_impl::chain4_t<NV>
		auto& minmax4 = this->getT(2).getT(0).getT(1).getT(4).getT(0);                        // XFHarm_impl::minmax4_t<NV>
		auto& pma_unscaled4 = this->getT(2).getT(0).getT(1).getT(4).getT(1);                  // XFHarm_impl::pma_unscaled4_t<NV>
		auto& softbypass_switch9 = this->getT(2).getT(0).getT(1).getT(4).getT(2);             // XFHarm_impl::softbypass_switch9_t<NV>
		auto& switcher6 = this->getT(2).getT(0).getT(1).getT(4).getT(2).getT(0);              // XFHarm_impl::switcher6_t<NV>
		auto& sb_container6 = this->getT(2).getT(0).getT(1).getT(4).getT(2).getT(1);          // XFHarm_impl::sb_container6_t<NV>
		auto& sb14 = this->getT(2).getT(0).getT(1).getT(4).getT(2).getT(1).getT(0);           // XFHarm_impl::sb14_t<NV>
		auto& file_player4 = this->getT(2).getT(0).getT(1).getT(4).                           // XFHarm_impl::file_player4_t<NV>
                             getT(2).getT(1).getT(0).getT(0);
		auto& sb15 = this->getT(2).getT(0).getT(1).getT(4).getT(2).getT(1).getT(1);           // XFHarm_impl::sb15_t<NV>
		auto& file_player13 = this->getT(2).getT(0).getT(1).getT(4).                          // XFHarm_impl::file_player13_t<NV>
                              getT(2).getT(1).getT(1).getT(0);
		auto& dry_wet5 = this->getT(2).getT(0).getT(1).getT(4).getT(3);                       // XFHarm_impl::dry_wet5_t<NV>
		auto& dry_path4 = this->getT(2).getT(0).getT(1).getT(4).getT(3).getT(0);              // XFHarm_impl::dry_path4_t
		auto& dry_wet_mixer4 = this->getT(2).getT(0).getT(1).getT(4).getT(3).getT(0).getT(0); // XFHarm_impl::dry_wet_mixer4_t
		auto& dry_gain4 = this->getT(2).getT(0).getT(1).getT(4).getT(3).getT(0).getT(1);      // core::gain
		auto& wet_path4 = this->getT(2).getT(0).getT(1).getT(4).getT(3).getT(1);              // XFHarm_impl::wet_path4_t<NV>
		auto& svf4 = this->getT(2).getT(0).getT(1).getT(4).getT(3).getT(1).getT(0);           // filters::svf<NV>
		auto& wet_gain4 = this->getT(2).getT(0).getT(1).getT(4).getT(3).getT(1).getT(1);      // core::gain
		auto& pma5 = this->getT(2).getT(0).getT(1).getT(4).getT(4);                           // XFHarm_impl::pma5_t<NV>
		auto& jpanner5 = this->getT(2).getT(0).getT(1).getT(4).getT(5);                       // jdsp::jpanner<NV>
		auto& gain12 = this->getT(2).getT(0).getT(1).getT(4).getT(6);                         // core::gain
		auto& smoothed_parameter = this->getT(2).getT(0).getT(1).getT(4).getT(7);             // XFHarm_impl::smoothed_parameter_t<NV>
		auto& gain4 = this->getT(2).getT(0).getT(1).getT(4).getT(8);                          // core::gain
		auto& chain3 = this->getT(2).getT(0).getT(1).getT(5);                                 // XFHarm_impl::chain3_t<NV>
		auto& minmax3 = this->getT(2).getT(0).getT(1).getT(5).getT(0);                        // XFHarm_impl::minmax3_t<NV>
		auto& pma_unscaled3 = this->getT(2).getT(0).getT(1).getT(5).getT(1);                  // XFHarm_impl::pma_unscaled3_t<NV>
		auto& softbypass_switch10 = this->getT(2).getT(0).getT(1).getT(5).getT(2);            // XFHarm_impl::softbypass_switch10_t<NV>
		auto& switcher7 = this->getT(2).getT(0).getT(1).getT(5).getT(2).getT(0);              // XFHarm_impl::switcher7_t<NV>
		auto& sb_container7 = this->getT(2).getT(0).getT(1).getT(5).getT(2).getT(1);          // XFHarm_impl::sb_container7_t<NV>
		auto& sb16 = this->getT(2).getT(0).getT(1).getT(5).getT(2).getT(1).getT(0);           // XFHarm_impl::sb16_t<NV>
		auto& file_player3 = this->getT(2).getT(0).getT(1).getT(5).                           // XFHarm_impl::file_player3_t<NV>
                             getT(2).getT(1).getT(0).getT(0);
		auto& sb17 = this->getT(2).getT(0).getT(1).getT(5).getT(2).getT(1).getT(1);           // XFHarm_impl::sb17_t<NV>
		auto& file_player14 = this->getT(2).getT(0).getT(1).getT(5).                          // XFHarm_impl::file_player14_t<NV>
                              getT(2).getT(1).getT(1).getT(0);
		auto& dry_wet6 = this->getT(2).getT(0).getT(1).getT(5).getT(3);                       // XFHarm_impl::dry_wet6_t<NV>
		auto& dry_path5 = this->getT(2).getT(0).getT(1).getT(5).getT(3).getT(0);              // XFHarm_impl::dry_path5_t
		auto& dry_wet_mixer5 = this->getT(2).getT(0).getT(1).getT(5).getT(3).getT(0).getT(0); // XFHarm_impl::dry_wet_mixer5_t
		auto& dry_gain5 = this->getT(2).getT(0).getT(1).getT(5).getT(3).getT(0).getT(1);      // core::gain
		auto& wet_path5 = this->getT(2).getT(0).getT(1).getT(5).getT(3).getT(1);              // XFHarm_impl::wet_path5_t<NV>
		auto& svf3 = this->getT(2).getT(0).getT(1).getT(5).getT(3).getT(1).getT(0);           // filters::svf<NV>
		auto& wet_gain5 = this->getT(2).getT(0).getT(1).getT(5).getT(3).getT(1).getT(1);      // core::gain
		auto& pma6 = this->getT(2).getT(0).getT(1).getT(5).getT(4);                           // XFHarm_impl::pma6_t<NV>
		auto& jpanner6 = this->getT(2).getT(0).getT(1).getT(5).getT(5);                       // jdsp::jpanner<NV>
		auto& gain13 = this->getT(2).getT(0).getT(1).getT(5).getT(6);                         // core::gain
		auto& smoothed_parameter5 = this->getT(2).getT(0).getT(1).getT(5).getT(7);            // XFHarm_impl::smoothed_parameter5_t<NV>
		auto& gain3 = this->getT(2).getT(0).getT(1).getT(5).getT(8);                          // core::gain
		auto& chain2 = this->getT(2).getT(0).getT(1).getT(6);                                 // XFHarm_impl::chain2_t<NV>
		auto& minmax2 = this->getT(2).getT(0).getT(1).getT(6).getT(0);                        // XFHarm_impl::minmax2_t<NV>
		auto& pma_unscaled2 = this->getT(2).getT(0).getT(1).getT(6).getT(1);                  // XFHarm_impl::pma_unscaled2_t<NV>
		auto& softbypass_switch11 = this->getT(2).getT(0).getT(1).getT(6).getT(2);            // XFHarm_impl::softbypass_switch11_t<NV>
		auto& switcher8 = this->getT(2).getT(0).getT(1).getT(6).getT(2).getT(0);              // XFHarm_impl::switcher8_t<NV>
		auto& sb_container8 = this->getT(2).getT(0).getT(1).getT(6).getT(2).getT(1);          // XFHarm_impl::sb_container8_t<NV>
		auto& sb18 = this->getT(2).getT(0).getT(1).getT(6).getT(2).getT(1).getT(0);           // XFHarm_impl::sb18_t<NV>
		auto& file_player2 = this->getT(2).getT(0).getT(1).getT(6).                           // XFHarm_impl::file_player2_t<NV>
                             getT(2).getT(1).getT(0).getT(0);
		auto& sb19 = this->getT(2).getT(0).getT(1).getT(6).getT(2).getT(1).getT(1);           // XFHarm_impl::sb19_t<NV>
		auto& file_player15 = this->getT(2).getT(0).getT(1).getT(6).                          // XFHarm_impl::file_player15_t<NV>
                              getT(2).getT(1).getT(1).getT(0);
		auto& dry_wet7 = this->getT(2).getT(0).getT(1).getT(6).getT(3);                       // XFHarm_impl::dry_wet7_t<NV>
		auto& dry_path6 = this->getT(2).getT(0).getT(1).getT(6).getT(3).getT(0);              // XFHarm_impl::dry_path6_t
		auto& dry_wet_mixer6 = this->getT(2).getT(0).getT(1).getT(6).getT(3).getT(0).getT(0); // XFHarm_impl::dry_wet_mixer6_t
		auto& dry_gain6 = this->getT(2).getT(0).getT(1).getT(6).getT(3).getT(0).getT(1);      // core::gain
		auto& wet_path6 = this->getT(2).getT(0).getT(1).getT(6).getT(3).getT(1);              // XFHarm_impl::wet_path6_t<NV>
		auto& svf2 = this->getT(2).getT(0).getT(1).getT(6).getT(3).getT(1).getT(0);           // filters::svf<NV>
		auto& wet_gain6 = this->getT(2).getT(0).getT(1).getT(6).getT(3).getT(1).getT(1);      // core::gain
		auto& pma7 = this->getT(2).getT(0).getT(1).getT(6).getT(4);                           // XFHarm_impl::pma7_t<NV>
		auto& jpanner7 = this->getT(2).getT(0).getT(1).getT(6).getT(5);                       // jdsp::jpanner<NV>
		auto& smoothed_parameter7 = this->getT(2).getT(0).getT(1).getT(6).getT(6);            // XFHarm_impl::smoothed_parameter7_t<NV>
		auto& gain14 = this->getT(2).getT(0).getT(1).getT(6).getT(7);                         // core::gain
		auto& gain2 = this->getT(2).getT(0).getT(1).getT(6).getT(8);                          // core::gain
		auto& chain1 = this->getT(2).getT(0).getT(1).getT(7);                                 // XFHarm_impl::chain1_t<NV>
		auto& minmax1 = this->getT(2).getT(0).getT(1).getT(7).getT(0);                        // XFHarm_impl::minmax1_t<NV>
		auto& pma_unscaled1 = this->getT(2).getT(0).getT(1).getT(7).getT(1);                  // XFHarm_impl::pma_unscaled1_t<NV>
		auto& softbypass_switch3 = this->getT(2).getT(0).getT(1).getT(7).getT(2);             // XFHarm_impl::softbypass_switch3_t<NV>
		auto& switcher1 = this->getT(2).getT(0).getT(1).getT(7).getT(2).getT(0);              // XFHarm_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(2).getT(0).getT(1).getT(7).getT(2).getT(1);          // XFHarm_impl::sb_container1_t<NV>
		auto& sb4 = this->getT(2).getT(0).getT(1).getT(7).getT(2).getT(1).getT(0);            // XFHarm_impl::sb4_t<NV>
		auto& file_player1 = this->getT(2).getT(0).getT(1).getT(7).                           // XFHarm_impl::file_player1_t<NV>
                             getT(2).getT(1).getT(0).getT(0);
		auto& sb5 = this->getT(2).getT(0).getT(1).getT(7).getT(2).getT(1).getT(1);           // XFHarm_impl::sb5_t<NV>
		auto& file_player8 = this->getT(2).getT(0).getT(1).getT(7).                          // XFHarm_impl::file_player8_t<NV>
                             getT(2).getT(1).getT(1).getT(0);
		auto& dry_wet1 = this->getT(2).getT(0).getT(1).getT(7).getT(3);                      // XFHarm_impl::dry_wet1_t<NV>
		auto& dry_path = this->getT(2).getT(0).getT(1).getT(7).getT(3).getT(0);              // XFHarm_impl::dry_path_t
		auto& dry_wet_mixer = this->getT(2).getT(0).getT(1).getT(7).getT(3).getT(0).getT(0); // XFHarm_impl::dry_wet_mixer_t
		auto& dry_gain = this->getT(2).getT(0).getT(1).getT(7).getT(3).getT(0).getT(1);      // core::gain
		auto& wet_path = this->getT(2).getT(0).getT(1).getT(7).getT(3).getT(1);              // XFHarm_impl::wet_path_t<NV>
		auto& svf1 = this->getT(2).getT(0).getT(1).getT(7).getT(3).getT(1).getT(0);          // filters::svf<NV>
		auto& wet_gain = this->getT(2).getT(0).getT(1).getT(7).getT(3).getT(1).getT(1);      // core::gain
		auto& pma1 = this->getT(2).getT(0).getT(1).getT(7).getT(4);                          // XFHarm_impl::pma1_t<NV>
		auto& jpanner = this->getT(2).getT(0).getT(1).getT(7).getT(5);                       // jdsp::jpanner<NV>
		auto& smoothed_parameter6 = this->getT(2).getT(0).getT(1).getT(7).getT(6);           // XFHarm_impl::smoothed_parameter6_t<NV>
		auto& gain15 = this->getT(2).getT(0).getT(1).getT(7).getT(7);                        // core::gain
		auto& gain1 = this->getT(2).getT(0).getT(1).getT(7).getT(8);                         // core::gain
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& XfIN_p = this->getParameterT(0);
		XfIN_p.connectT(0, input_toggle);  // XfIN -> input_toggle::Input
		XfIN_p.connectT(1, input_toggle1); // XfIN -> input_toggle1::Input
		XfIN_p.connectT(2, input_toggle3); // XfIN -> input_toggle3::Input
		XfIN_p.connectT(3, input_toggle4); // XfIN -> input_toggle4::Input
		XfIN_p.connectT(4, input_toggle5); // XfIN -> input_toggle5::Input
		XfIN_p.connectT(5, input_toggle6); // XfIN -> input_toggle6::Input
		XfIN_p.connectT(6, input_toggle7); // XfIN -> input_toggle7::Input
		XfIN_p.connectT(7, input_toggle2); // XfIN -> input_toggle2::Input
		
		this->getParameterT(1).connectT(0, pma19); // Xfade -> pma19::Add
		
		this->getParameterT(2).connectT(0, pma19); // XfMod1 -> pma19::Multiply
		
		this->getParameterT(3).connectT(0, pma8); // XfMod2 -> pma8::Multiply
		
		auto& smooth_p = this->getParameterT(4);
		smooth_p.connectT(0, smoothed_parameter1); // smooth -> smoothed_parameter1::SmoothingTime
		smooth_p.connectT(1, smoothed_parameter2); // smooth -> smoothed_parameter2::SmoothingTime
		smooth_p.connectT(2, smoothed_parameter3); // smooth -> smoothed_parameter3::SmoothingTime
		smooth_p.connectT(3, smoothed_parameter4); // smooth -> smoothed_parameter4::SmoothingTime
		smooth_p.connectT(4, smoothed_parameter);  // smooth -> smoothed_parameter::SmoothingTime
		smooth_p.connectT(5, smoothed_parameter5); // smooth -> smoothed_parameter5::SmoothingTime
		smooth_p.connectT(6, smoothed_parameter7); // smooth -> smoothed_parameter7::SmoothingTime
		smooth_p.connectT(7, smoothed_parameter6); // smooth -> smoothed_parameter6::SmoothingTime
		
		this->getParameterT(5).connectT(0, pma22); // Harm -> pma22::Add
		
		this->getParameterT(6).connectT(0, pma22); // HarmMod1 -> pma22::Multiply
		
		this->getParameterT(7).connectT(0, pma17); // HarmMod2 -> pma17::Multiply
		
		this->getParameterT(8).connectT(0, pma23); // Cut -> pma23::Add
		
		this->getParameterT(9).connectT(0, pma23); // CutMod1 -> pma23::Multiply
		
		this->getParameterT(10).connectT(0, pma16); // CutMod2 -> pma16::Multiply
		
		auto& Min_p = this->getParameterT(11);
		Min_p.connectT(0, minmax);  // Min -> minmax::Minimum
		Min_p.connectT(1, minmax7); // Min -> minmax7::Minimum
		Min_p.connectT(2, minmax6); // Min -> minmax6::Minimum
		Min_p.connectT(3, minmax5); // Min -> minmax5::Minimum
		Min_p.connectT(4, minmax4); // Min -> minmax4::Minimum
		Min_p.connectT(5, minmax3); // Min -> minmax3::Minimum
		Min_p.connectT(6, minmax2); // Min -> minmax2::Minimum
		Min_p.connectT(7, minmax1); // Min -> minmax1::Minimum
		
		auto& Max_p = this->getParameterT(12);
		Max_p.connectT(0, minmax);  // Max -> minmax::Maximum
		Max_p.connectT(1, minmax7); // Max -> minmax7::Maximum
		Max_p.connectT(2, minmax6); // Max -> minmax6::Maximum
		Max_p.connectT(3, minmax5); // Max -> minmax5::Maximum
		Max_p.connectT(4, minmax4); // Max -> minmax4::Maximum
		Max_p.connectT(5, minmax3); // Max -> minmax3::Maximum
		Max_p.connectT(6, minmax2); // Max -> minmax2::Maximum
		Max_p.connectT(7, minmax1); // Max -> minmax1::Maximum
		
		auto& Step_p = this->getParameterT(13);
		Step_p.connectT(0, minmax);  // Step -> minmax::Step
		Step_p.connectT(1, minmax7); // Step -> minmax7::Step
		Step_p.connectT(2, minmax6); // Step -> minmax6::Step
		Step_p.connectT(3, minmax5); // Step -> minmax5::Step
		Step_p.connectT(4, minmax4); // Step -> minmax4::Step
		Step_p.connectT(5, minmax3); // Step -> minmax3::Step
		Step_p.connectT(6, minmax2); // Step -> minmax2::Step
		Step_p.connectT(7, minmax1); // Step -> minmax1::Step
		
		this->getParameterT(14).connectT(0, pma21); // pitch -> pma21::Add
		
		this->getParameterT(15).connectT(0, pma21); // PitchMod1 -> pma21::Multiply
		
		this->getParameterT(16).connectT(0, pma10); // PitchMod2 -> pma10::Multiply
		
		auto& ftpye_p = this->getParameterT(17);
		ftpye_p.connectT(0, svf);  // ftpye -> svf::Mode
		ftpye_p.connectT(1, svf7); // ftpye -> svf7::Mode
		ftpye_p.connectT(2, svf6); // ftpye -> svf6::Mode
		ftpye_p.connectT(3, svf5); // ftpye -> svf5::Mode
		ftpye_p.connectT(4, svf4); // ftpye -> svf4::Mode
		ftpye_p.connectT(5, svf3); // ftpye -> svf3::Mode
		ftpye_p.connectT(6, svf2); // ftpye -> svf2::Mode
		ftpye_p.connectT(7, svf1); // ftpye -> svf1::Mode
		
		this->getParameterT(18).connectT(0, pma24); // Vol -> pma24::Add
		
		this->getParameterT(19).connectT(0, pma24); // VolMod1 -> pma24::Multiply
		
		this->getParameterT(20).connectT(0, pma15); // VolMod2 -> pma15::Multiply
		
		this->getParameterT(21).connectT(0, pma20); // Pan -> pma20::Add
		
		this->getParameterT(22).connectT(0, pma20); // PanMod1 -> pma20::Multiply
		
		this->getParameterT(23).connectT(0, pma18); // PanMod2 -> pma18::Multiply
		
		auto& Res_p = this->getParameterT(24);
		Res_p.connectT(0, svf);  // Res -> svf::Q
		Res_p.connectT(1, svf7); // Res -> svf7::Q
		Res_p.connectT(2, svf6); // Res -> svf6::Q
		Res_p.connectT(3, svf5); // Res -> svf5::Q
		Res_p.connectT(4, svf4); // Res -> svf4::Q
		Res_p.connectT(5, svf3); // Res -> svf3::Q
		Res_p.connectT(6, svf2); // Res -> svf2::Q
		Res_p.connectT(7, svf1); // Res -> svf1::Q
		
		this->getParameterT(25).connectT(0, tempo_sync); // Tempo1 -> tempo_sync::Tempo
		
		this->getParameterT(26).connectT(0, tempo_sync); // Div1 -> tempo_sync::Multiplier
		
		this->getParameterT(27).connectT(0, ramp); // Once1 -> ramp::LoopStart
		
		this->getParameterT(28).connectT(0, ahdsr); // Attack -> ahdsr::Attack
		
		this->getParameterT(29).connectT(0, ahdsr); // Decay -> ahdsr::Decay
		
		this->getParameterT(30).connectT(0, ahdsr); // Sus -> ahdsr::Sustain
		
		this->getParameterT(31).connectT(0, ahdsr); // rel -> ahdsr::Release
		
		this->getParameterT(32).connectT(0, pack8_writer); // gate1 -> pack8_writer::Value1
		
		this->getParameterT(33).connectT(0, pack8_writer); // gate2 -> pack8_writer::Value3
		
		this->getParameterT(34).connectT(0, pack8_writer); // gate3 -> pack8_writer::Value5
		
		this->getParameterT(35).connectT(0, pack8_writer); // gate4 -> pack8_writer::Value7
		
		this->getParameterT(36).connectT(0, pack8_writer1); // gate5 -> pack8_writer1::Value1
		
		this->getParameterT(37).connectT(0, pack8_writer1); // gate6 -> pack8_writer1::Value3
		
		this->getParameterT(38).connectT(0, pack8_writer1); // gate7 -> pack8_writer1::Value5
		
		this->getParameterT(39).connectT(0, pack8_writer1); // gate8 -> pack8_writer1::Value7
		
		this->getParameterT(40).connectT(0, simple_ar2); // gateAtk -> simple_ar2::Attack
		
		this->getParameterT(41).connectT(0, simple_ar2); // gateRel -> simple_ar2::Release
		
		this->getParameterT(42).connectT(0, tempo_sync2); // tempo2 -> tempo_sync2::Tempo
		
		this->getParameterT(43).connectT(0, tempo_sync2); // div2 -> tempo_sync2::Multiplier
		
		this->getParameterT(44).connectT(0, ramp2); // once2 -> ramp2::LoopStart
		
		this->getParameterT(45).connectT(0, oscillator1); // LFOmode -> oscillator1::Mode
		
		this->getParameterT(46).connectT(0, SFZ); // SFZ -> SFZ::Value
		
		this->getParameterT(47).connectT(0, switcher16); // modmode1 -> switcher16::Value
		
		this->getParameterT(48).connectT(0, switcher17); // modmode2 -> switcher17::Value
		
		this->getParameterT(49).connectT(0, input_toggle8); // env_trig -> input_toggle8::Input
		
		this->getParameterT(50).connectT(0, pma9); // vel1 -> pma9::Multiply
		
		this->getParameterT(51).connectT(0, pma25); // vel2 -> pma25::Multiply
		
		this->getParameterT(52).connectT(0, cutmix); // fmix -> cutmix::Value
		
		this->getParameterT(53).connectT(0, pma11); // Xfmod3 -> pma11::Multiply
		
		this->getParameterT(54).connectT(0, pma14); // Harmmod3 -> pma14::Multiply
		
		this->getParameterT(55).connectT(0, pma13); // Pitchmod3 -> pma13::Multiply
		
		this->getParameterT(56).connectT(0, pma26); // Cutmod3 -> pma26::Multiply
		
		this->getParameterT(57).connectT(0, pma12); // Panmod3 -> pma12::Multiply
		
		this->getParameterT(58).connectT(0, pma27); // Volmod3 -> pma27::Multiply
		
		this->getParameterT(59).connectT(0, tempo_sync3); // Tempo3 -> tempo_sync3::Tempo
		
		this->getParameterT(60).connectT(0, tempo_sync3); // Div3 -> tempo_sync3::Multiplier
		
		this->getParameterT(61).connectT(0, switcher18); // ModMode3 -> switcher18::Value
		
		this->getParameterT(62).connectT(0, ramp3); // Once3 -> ramp3::LoopStart
		
		this->getParameterT(63).connectT(0, oscillator2); // LFOShape2 -> oscillator2::Mode
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, add9);                               // ahdsr -> add9::Value
		input_toggle8.getWrappedObject().getParameter().connectT(0, ahdsr);       // input_toggle8 -> ahdsr::Gate
		cable_pack2.getWrappedObject().getParameter().connectT(0, add57);         // cable_pack2 -> add57::Value
		cable_table5.getWrappedObject().getParameter().connectT(0, cable_pack2);  // cable_table5 -> cable_pack2::Value
		cable_pack1.getWrappedObject().getParameter().connectT(0, add58);         // cable_pack1 -> add58::Value
		cable_table10.getWrappedObject().getParameter().connectT(0, cable_pack1); // cable_table10 -> cable_pack1::Value
		ramp.getParameter().connectT(0, input_toggle8);                           // ramp -> input_toggle8::Value2
		ramp.getParameter().connectT(1, cable_table5);                            // ramp -> cable_table5::Value
		ramp.getParameter().connectT(2, cable_table10);                           // ramp -> cable_table10::Value
		tempo_sync.getParameter().connectT(0, ramp);                              // tempo_sync -> ramp::PeriodTime
		auto& simple_ar2_p = simple_ar2.getWrappedObject().getParameter();
		simple_ar2_p.getParameterT(0).connectT(0, add7); // simple_ar2 -> add7::Value
		peak2.getParameter().connectT(0, simple_ar2);    // peak2 -> simple_ar2::Gate
		auto& switcher16_p = switcher16.getWrappedObject().getParameter();
		switcher16_p.getParameterT(0).connectT(0, sb33);                         // switcher16 -> sb33::Bypassed
		switcher16_p.getParameterT(1).connectT(0, sb37);                         // switcher16 -> sb37::Bypassed
		pma9.getWrappedObject().getParameter().connectT(0, add2);                // pma9 -> add2::Value
		midi.getParameter().connectT(0, pma9);                                   // midi -> pma9::Value
		smoothed_parameter1.getParameter().connectT(0, gain);                    // smoothed_parameter1 -> gain::Gain
		pma.getWrappedObject().getParameter().connectT(0, smoothed_parameter1);  // pma -> smoothed_parameter1::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, pma);         // input_toggle -> pma::Add
		smoothed_parameter2.getParameter().connectT(0, gain7);                   // smoothed_parameter2 -> gain7::Gain
		pma2.getWrappedObject().getParameter().connectT(0, smoothed_parameter2); // pma2 -> smoothed_parameter2::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, pma2);       // input_toggle1 -> pma2::Add
		smoothed_parameter3.getParameter().connectT(0, gain6);                   // smoothed_parameter3 -> gain6::Gain
		pma3.getWrappedObject().getParameter().connectT(0, smoothed_parameter3); // pma3 -> smoothed_parameter3::Value
		input_toggle2.getWrappedObject().getParameter().connectT(0, pma3);       // input_toggle2 -> pma3::Add
		smoothed_parameter4.getParameter().connectT(0, gain5);                   // smoothed_parameter4 -> gain5::Gain
		pma4.getWrappedObject().getParameter().connectT(0, smoothed_parameter4); // pma4 -> smoothed_parameter4::Value
		input_toggle3.getWrappedObject().getParameter().connectT(0, pma4);       // input_toggle3 -> pma4::Add
		smoothed_parameter.getParameter().connectT(0, gain4);                    // smoothed_parameter -> gain4::Gain
		pma5.getWrappedObject().getParameter().connectT(0, smoothed_parameter);  // pma5 -> smoothed_parameter::Value
		input_toggle4.getWrappedObject().getParameter().connectT(0, pma5);       // input_toggle4 -> pma5::Add
		smoothed_parameter5.getParameter().connectT(0, gain3);                   // smoothed_parameter5 -> gain3::Gain
		pma6.getWrappedObject().getParameter().connectT(0, smoothed_parameter5); // pma6 -> smoothed_parameter5::Value
		input_toggle5.getWrappedObject().getParameter().connectT(0, pma6);       // input_toggle5 -> pma6::Add
		smoothed_parameter6.getParameter().connectT(0, gain1);                   // smoothed_parameter6 -> gain1::Gain
		pma1.getWrappedObject().getParameter().connectT(0, smoothed_parameter6); // pma1 -> smoothed_parameter6::Value
		input_toggle7.getWrappedObject().getParameter().connectT(0, pma1);       // input_toggle7 -> pma1::Add
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, input_toggle);                     // xfader -> input_toggle::Value1
		xfader_p.getParameterT(1).connectT(0, input_toggle1);                    // xfader -> input_toggle1::Value1
		xfader_p.getParameterT(2).connectT(0, input_toggle2);                    // xfader -> input_toggle2::Value1
		xfader_p.getParameterT(3).connectT(0, input_toggle3);                    // xfader -> input_toggle3::Value1
		xfader_p.getParameterT(4).connectT(0, input_toggle4);                    // xfader -> input_toggle4::Value1
		xfader_p.getParameterT(5).connectT(0, input_toggle5);                    // xfader -> input_toggle5::Value1
		xfader_p.getParameterT(6).connectT(0, input_toggle7);                    // xfader -> input_toggle7::Value1
		smoothed_parameter7.getParameter().connectT(0, gain2);                   // smoothed_parameter7 -> gain2::Gain
		pma7.getWrappedObject().getParameter().connectT(0, smoothed_parameter7); // pma7 -> smoothed_parameter7::Value
		input_toggle6.getWrappedObject().getParameter().connectT(0, pma7);       // input_toggle6 -> pma7::Add
		auto& xfader3_p = xfader3.getWrappedObject().getParameter();
		xfader3_p.getParameterT(0).connectT(0, input_toggle);                       // xfader3 -> input_toggle::Value2
		xfader3_p.getParameterT(1).connectT(0, input_toggle1);                      // xfader3 -> input_toggle1::Value2
		xfader3_p.getParameterT(2).connectT(0, input_toggle2);                      // xfader3 -> input_toggle2::Value2
		xfader3_p.getParameterT(3).connectT(0, input_toggle3);                      // xfader3 -> input_toggle3::Value2
		xfader3_p.getParameterT(4).connectT(0, input_toggle4);                      // xfader3 -> input_toggle4::Value2
		xfader3_p.getParameterT(5).connectT(0, input_toggle5);                      // xfader3 -> input_toggle5::Value2
		xfader3_p.getParameterT(6).connectT(0, input_toggle6);                      // xfader3 -> input_toggle6::Value2
		xfader3_p.getParameterT(7).connectT(0, input_toggle7);                      // xfader3 -> input_toggle7::Value2
		pma8.getWrappedObject().getParameter().connectT(0, xfader);                 // pma8 -> xfader::Value
		pma8.getWrappedObject().getParameter().connectT(1, xfader3);                // pma8 -> xfader3::Value
		pma8.getWrappedObject().getParameter().connectT(2, cable_table);            // pma8 -> cable_table::Value
		pma11.getWrappedObject().getParameter().connectT(0, pma8);                  // pma11 -> pma8::Add
		pma19.getWrappedObject().getParameter().connectT(0, pma11);                 // pma19 -> pma11::Add
		pma_unscaled.getWrappedObject().getParameter().connectT(0, file_player);    // pma_unscaled -> file_player::FreqRatio
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled);         // minmax -> pma_unscaled::Add
		pma_unscaled7.getWrappedObject().getParameter().connectT(0, file_player7);  // pma_unscaled7 -> file_player7::FreqRatio
		pma_unscaled7.getWrappedObject().getParameter().connectT(1, file_player10); // pma_unscaled7 -> file_player10::FreqRatio
		minmax7.getWrappedObject().getParameter().connectT(0, pma_unscaled7);       // minmax7 -> pma_unscaled7::Add
		pma_unscaled6.getWrappedObject().getParameter().connectT(0, file_player6);  // pma_unscaled6 -> file_player6::FreqRatio
		pma_unscaled6.getWrappedObject().getParameter().connectT(1, file_player11); // pma_unscaled6 -> file_player11::FreqRatio
		minmax6.getWrappedObject().getParameter().connectT(0, pma_unscaled6);       // minmax6 -> pma_unscaled6::Add
		pma_unscaled5.getWrappedObject().getParameter().connectT(0, file_player5);  // pma_unscaled5 -> file_player5::FreqRatio
		pma_unscaled5.getWrappedObject().getParameter().connectT(1, file_player12); // pma_unscaled5 -> file_player12::FreqRatio
		minmax5.getWrappedObject().getParameter().connectT(0, pma_unscaled5);       // minmax5 -> pma_unscaled5::Add
		pma_unscaled4.getWrappedObject().getParameter().connectT(0, file_player4);  // pma_unscaled4 -> file_player4::FreqRatio
		pma_unscaled4.getWrappedObject().getParameter().connectT(1, file_player13); // pma_unscaled4 -> file_player13::FreqRatio
		minmax4.getWrappedObject().getParameter().connectT(0, pma_unscaled4);       // minmax4 -> pma_unscaled4::Add
		pma_unscaled3.getWrappedObject().getParameter().connectT(0, file_player3);  // pma_unscaled3 -> file_player3::FreqRatio
		pma_unscaled3.getWrappedObject().getParameter().connectT(1, file_player14); // pma_unscaled3 -> file_player14::FreqRatio
		minmax3.getWrappedObject().getParameter().connectT(0, pma_unscaled3);       // minmax3 -> pma_unscaled3::Add
		pma_unscaled2.getWrappedObject().getParameter().connectT(0, file_player2);  // pma_unscaled2 -> file_player2::FreqRatio
		pma_unscaled2.getWrappedObject().getParameter().connectT(1, file_player15); // pma_unscaled2 -> file_player15::FreqRatio
		minmax2.getWrappedObject().getParameter().connectT(0, pma_unscaled2);       // minmax2 -> pma_unscaled2::Add
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, file_player1);  // pma_unscaled1 -> file_player1::FreqRatio
		pma_unscaled1.getWrappedObject().getParameter().connectT(1, file_player8);  // pma_unscaled1 -> file_player8::FreqRatio
		minmax1.getWrappedObject().getParameter().connectT(0, pma_unscaled1);       // minmax1 -> pma_unscaled1::Add
		auto& harm_p = harm.getWrappedObject().getParameter();
		harm_p.getParameterT(0).connectT(0, minmax);                        // harm -> minmax::Value
		harm_p.getParameterT(1).connectT(0, minmax7);                       // harm -> minmax7::Value
		harm_p.getParameterT(2).connectT(0, minmax6);                       // harm -> minmax6::Value
		harm_p.getParameterT(3).connectT(0, minmax5);                       // harm -> minmax5::Value
		harm_p.getParameterT(4).connectT(0, minmax4);                       // harm -> minmax4::Value
		harm_p.getParameterT(5).connectT(0, minmax3);                       // harm -> minmax3::Value
		harm_p.getParameterT(6).connectT(0, minmax2);                       // harm -> minmax2::Value
		harm_p.getParameterT(7).connectT(0, minmax1);                       // harm -> minmax1::Value
		pma17.getWrappedObject().getParameter().connectT(0, harm);          // pma17 -> harm::Value
		pma_unscaled8.getWrappedObject().getParameter().connectT(0, pma17); // pma_unscaled8 -> pma17::Add
		pma14.getWrappedObject().getParameter().connectT(0, pma_unscaled8); // pma14 -> pma_unscaled8::Add
		pma22.getWrappedObject().getParameter().connectT(0, pma14);         // pma22 -> pma14::Add
		auto& cut_p = cut.getWrappedObject().getParameter();
		cut_p.getParameterT(0).connectT(0, svf);                    // cut -> svf::Frequency
		cut_p.getParameterT(1).connectT(0, svf7);                   // cut -> svf7::Frequency
		cut_p.getParameterT(2).connectT(0, svf6);                   // cut -> svf6::Frequency
		cut_p.getParameterT(3).connectT(0, svf5);                   // cut -> svf5::Frequency
		cut_p.getParameterT(4).connectT(0, svf4);                   // cut -> svf4::Frequency
		cut_p.getParameterT(5).connectT(0, svf3);                   // cut -> svf3::Frequency
		cut_p.getParameterT(6).connectT(0, svf2);                   // cut -> svf2::Frequency
		cut_p.getParameterT(7).connectT(0, svf1);                   // cut -> svf1::Frequency
		pma16.getWrappedObject().getParameter().connectT(0, cut);   // pma16 -> cut::Value
		pma26.getWrappedObject().getParameter().connectT(0, pma16); // pma26 -> pma16::Add
		pma23.getWrappedObject().getParameter().connectT(0, pma26); // pma23 -> pma26::Add
		auto& vol_p = vol.getWrappedObject().getParameter();
		vol_p.getParameterT(0).connectT(0, gain8);                  // vol -> gain8::Gain
		vol_p.getParameterT(1).connectT(0, gain9);                  // vol -> gain9::Gain
		vol_p.getParameterT(2).connectT(0, gain10);                 // vol -> gain10::Gain
		vol_p.getParameterT(3).connectT(0, gain11);                 // vol -> gain11::Gain
		vol_p.getParameterT(4).connectT(0, gain12);                 // vol -> gain12::Gain
		vol_p.getParameterT(5).connectT(0, gain13);                 // vol -> gain13::Gain
		vol_p.getParameterT(6).connectT(0, gain14);                 // vol -> gain14::Gain
		vol_p.getParameterT(7).connectT(0, gain15);                 // vol -> gain15::Gain
		pma15.getWrappedObject().getParameter().connectT(0, vol);   // pma15 -> vol::Value
		pma27.getWrappedObject().getParameter().connectT(0, pma15); // pma27 -> pma15::Add
		pma24.getWrappedObject().getParameter().connectT(0, pma27); // pma24 -> pma27::Add
		auto& pan_p = pan.getWrappedObject().getParameter();
		pan_p.getParameterT(0).connectT(0, jpanner1);               // pan -> jpanner1::Pan
		pan_p.getParameterT(1).connectT(0, jpanner2);               // pan -> jpanner2::Pan
		pan_p.getParameterT(2).connectT(0, jpanner3);               // pan -> jpanner3::Pan
		pan_p.getParameterT(3).connectT(0, jpanner4);               // pan -> jpanner4::Pan
		pan_p.getParameterT(4).connectT(0, jpanner5);               // pan -> jpanner5::Pan
		pan_p.getParameterT(5).connectT(0, jpanner6);               // pan -> jpanner6::Pan
		pan_p.getParameterT(6).connectT(0, jpanner7);               // pan -> jpanner7::Pan
		pan_p.getParameterT(7).connectT(0, jpanner);                // pan -> jpanner::Pan
		pma18.getWrappedObject().getParameter().connectT(0, pan);   // pma18 -> pan::Value
		pma20.getWrappedObject().getParameter().connectT(0, pma18); // pma20 -> pma18::Add
		pma20.getWrappedObject().getParameter().connectT(1, pma12); // pma20 -> pma12::Add
		auto& pitch_p = pitch.getWrappedObject().getParameter();
		pitch_p.getParameterT(0).connectT(0, pma_unscaled);                    // pitch -> pma_unscaled::Value
		pitch_p.getParameterT(1).connectT(0, pma_unscaled7);                   // pitch -> pma_unscaled7::Value
		pitch_p.getParameterT(2).connectT(0, pma_unscaled6);                   // pitch -> pma_unscaled6::Value
		pitch_p.getParameterT(3).connectT(0, pma_unscaled5);                   // pitch -> pma_unscaled5::Value
		pitch_p.getParameterT(4).connectT(0, pma_unscaled4);                   // pitch -> pma_unscaled4::Value
		pitch_p.getParameterT(5).connectT(0, pma_unscaled3);                   // pitch -> pma_unscaled3::Value
		pitch_p.getParameterT(6).connectT(0, pma_unscaled2);                   // pitch -> pma_unscaled2::Value
		pitch_p.getParameterT(7).connectT(0, pma_unscaled1);                   // pitch -> pma_unscaled1::Value
		pma10.getWrappedObject().getParameter().connectT(0, pitch);            // pma10 -> pitch::Value
		pma13.getWrappedObject().getParameter().connectT(0, pma10);            // pma13 -> pma10::Add
		pma21.getWrappedObject().getParameter().connectT(0, pma13);            // pma21 -> pma13::Add
		peak.getParameter().connectT(0, pma19);                                // peak -> pma19::Value
		peak.getParameter().connectT(1, pma22);                                // peak -> pma22::Value
		peak.getParameter().connectT(2, pma23);                                // peak -> pma23::Value
		peak.getParameter().connectT(3, pma24);                                // peak -> pma24::Value
		peak.getParameter().connectT(4, pma20);                                // peak -> pma20::Value
		peak.getParameter().connectT(5, pma21);                                // peak -> pma21::Value
		cable_table1.getWrappedObject().getParameter().connectT(0, add);       // cable_table1 -> add::Value
		steppack1.getWrappedObject().getParameter().connectT(0, add1);         // steppack1 -> add1::Value
		ramp2.getParameter().connectT(0, cable_table1);                        // ramp2 -> cable_table1::Value
		ramp2.getParameter().connectT(1, steppack1);                           // ramp2 -> steppack1::Value
		converter1.getWrappedObject().getParameter().connectT(0, oscillator1); // converter1 -> oscillator1::Frequency
		tempo_sync2.getParameter().connectT(0, ramp2);                         // tempo_sync2 -> ramp2::PeriodTime
		tempo_sync2.getParameter().connectT(1, converter1);                    // tempo_sync2 -> converter1::Value
		auto& switcher17_p = switcher17.getWrappedObject().getParameter();
		switcher17_p.getParameterT(0).connectT(0, sb39);                       // switcher17 -> sb39::Bypassed
		switcher17_p.getParameterT(1).connectT(0, sb40);                       // switcher17 -> sb40::Bypassed
		switcher17_p.getParameterT(2).connectT(0, sb41);                       // switcher17 -> sb41::Bypassed
		pma25.getWrappedObject().getParameter().connectT(0, add3);             // pma25 -> add3::Value
		midi1.getParameter().connectT(0, pma25);                               // midi1 -> pma25::Value
		peak1.getParameter().connectT(0, pma8);                                // peak1 -> pma8::Value
		peak1.getParameter().connectT(1, pma10);                               // peak1 -> pma10::Value
		peak1.getParameter().connectT(2, pma17);                               // peak1 -> pma17::Value
		peak1.getParameter().connectT(3, pma16);                               // peak1 -> pma16::Value
		peak1.getParameter().connectT(4, pma15);                               // peak1 -> pma15::Value
		peak1.getParameter().connectT(5, pma18);                               // peak1 -> pma18::Value
		cable_table2.getWrappedObject().getParameter().connectT(0, add4);      // cable_table2 -> add4::Value
		steppack2.getWrappedObject().getParameter().connectT(0, add5);         // steppack2 -> add5::Value
		ramp3.getParameter().connectT(0, cable_table2);                        // ramp3 -> cable_table2::Value
		ramp3.getParameter().connectT(1, steppack2);                           // ramp3 -> steppack2::Value
		converter2.getWrappedObject().getParameter().connectT(0, oscillator2); // converter2 -> oscillator2::Frequency
		tempo_sync3.getParameter().connectT(0, ramp3);                         // tempo_sync3 -> ramp3::PeriodTime
		tempo_sync3.getParameter().connectT(1, converter2);                    // tempo_sync3 -> converter2::Value
		auto& switcher18_p = switcher18.getWrappedObject().getParameter();
		switcher18_p.getParameterT(0).connectT(0, sb42);                      // switcher18 -> sb42::Bypassed
		switcher18_p.getParameterT(1).connectT(0, sb43);                      // switcher18 -> sb43::Bypassed
		switcher18_p.getParameterT(2).connectT(0, sb44);                      // switcher18 -> sb44::Bypassed
		pma28.getWrappedObject().getParameter().connectT(0, add6);            // pma28 -> add6::Value
		midi2.getParameter().connectT(0, pma28);                              // midi2 -> pma28::Value
		peak3.getParameter().connectT(0, pma11);                              // peak3 -> pma11::Value
		peak3.getParameter().connectT(1, pma13);                              // peak3 -> pma13::Value
		peak3.getParameter().connectT(2, pma14);                              // peak3 -> pma14::Value
		peak3.getParameter().connectT(3, pma26);                              // peak3 -> pma26::Value
		peak3.getParameter().connectT(4, pma27);                              // peak3 -> pma27::Value
		peak3.getParameter().connectT(5, pma12);                              // peak3 -> pma12::Value
		midi_cc.getWrappedObject().getParameter().connectT(0, pma_unscaled8); // midi_cc -> pma_unscaled8::Value
		auto& dry_wet_mixer7_p = dry_wet_mixer7.getWrappedObject().getParameter();
		dry_wet_mixer7_p.getParameterT(0).connectT(0, dry_gain7); // dry_wet_mixer7 -> dry_gain7::Gain
		dry_wet_mixer7_p.getParameterT(1).connectT(0, wet_gain7); // dry_wet_mixer7 -> wet_gain7::Gain
		auto& dry_wet_mixer4_p = dry_wet_mixer4.getWrappedObject().getParameter();
		dry_wet_mixer4_p.getParameterT(0).connectT(0, dry_gain4); // dry_wet_mixer4 -> dry_gain4::Gain
		dry_wet_mixer4_p.getParameterT(1).connectT(0, wet_gain4); // dry_wet_mixer4 -> wet_gain4::Gain
		auto& dry_wet_mixer5_p = dry_wet_mixer5.getWrappedObject().getParameter();
		dry_wet_mixer5_p.getParameterT(0).connectT(0, dry_gain5); // dry_wet_mixer5 -> dry_gain5::Gain
		dry_wet_mixer5_p.getParameterT(1).connectT(0, wet_gain5); // dry_wet_mixer5 -> wet_gain5::Gain
		auto& dry_wet_mixer6_p = dry_wet_mixer6.getWrappedObject().getParameter();
		dry_wet_mixer6_p.getParameterT(0).connectT(0, dry_gain6); // dry_wet_mixer6 -> dry_gain6::Gain
		dry_wet_mixer6_p.getParameterT(1).connectT(0, wet_gain6); // dry_wet_mixer6 -> wet_gain6::Gain
		auto& dry_wet_mixer3_p = dry_wet_mixer3.getWrappedObject().getParameter();
		dry_wet_mixer3_p.getParameterT(0).connectT(0, dry_gain3); // dry_wet_mixer3 -> dry_gain3::Gain
		dry_wet_mixer3_p.getParameterT(1).connectT(0, wet_gain3); // dry_wet_mixer3 -> wet_gain3::Gain
		auto& dry_wet_mixer2_p = dry_wet_mixer2.getWrappedObject().getParameter();
		dry_wet_mixer2_p.getParameterT(0).connectT(0, dry_gain2); // dry_wet_mixer2 -> dry_gain2::Gain
		dry_wet_mixer2_p.getParameterT(1).connectT(0, wet_gain2); // dry_wet_mixer2 -> wet_gain2::Gain
		auto& dry_wet_mixer_p = dry_wet_mixer.getWrappedObject().getParameter();
		dry_wet_mixer_p.getParameterT(0).connectT(0, dry_gain); // dry_wet_mixer -> dry_gain::Gain
		dry_wet_mixer_p.getParameterT(1).connectT(0, wet_gain); // dry_wet_mixer -> wet_gain::Gain
		auto& dry_wet_mixer1_p = dry_wet_mixer1.getWrappedObject().getParameter();
		dry_wet_mixer1_p.getParameterT(0).connectT(0, dry_gain1); // dry_wet_mixer1 -> dry_gain1::Gain
		dry_wet_mixer1_p.getParameterT(1).connectT(0, wet_gain1); // dry_wet_mixer1 -> wet_gain1::Gain
		auto& cutmix_p = cutmix.getWrappedObject().getParameter();
		cutmix_p.getParameterT(0).connectT(0, dry_wet_mixer7); // cutmix -> dry_wet_mixer7::Value
		cutmix_p.getParameterT(0).connectT(1, dry_wet_mixer4); // cutmix -> dry_wet_mixer4::Value
		cutmix_p.getParameterT(0).connectT(2, dry_wet_mixer5); // cutmix -> dry_wet_mixer5::Value
		cutmix_p.getParameterT(0).connectT(3, dry_wet_mixer6); // cutmix -> dry_wet_mixer6::Value
		cutmix_p.getParameterT(0).connectT(4, dry_wet_mixer3); // cutmix -> dry_wet_mixer3::Value
		cutmix_p.getParameterT(0).connectT(5, dry_wet_mixer2); // cutmix -> dry_wet_mixer2::Value
		cutmix_p.getParameterT(0).connectT(6, dry_wet_mixer);  // cutmix -> dry_wet_mixer::Value
		cutmix_p.getParameterT(0).connectT(7, dry_wet_mixer1); // cutmix -> dry_wet_mixer1::Value
		auto& switcher2_p = switcher2.getWrappedObject().getParameter();
		switcher2_p.getParameterT(0).connectT(0, sb6); // switcher2 -> sb6::Bypassed
		switcher2_p.getParameterT(1).connectT(0, sb7); // switcher2 -> sb7::Bypassed
		auto& switcher3_p = switcher3.getWrappedObject().getParameter();
		switcher3_p.getParameterT(0).connectT(0, sb8); // switcher3 -> sb8::Bypassed
		switcher3_p.getParameterT(1).connectT(0, sb9); // switcher3 -> sb9::Bypassed
		auto& switcher4_p = switcher4.getWrappedObject().getParameter();
		switcher4_p.getParameterT(0).connectT(0, sb10); // switcher4 -> sb10::Bypassed
		switcher4_p.getParameterT(1).connectT(0, sb11); // switcher4 -> sb11::Bypassed
		auto& switcher5_p = switcher5.getWrappedObject().getParameter();
		switcher5_p.getParameterT(0).connectT(0, sb12); // switcher5 -> sb12::Bypassed
		switcher5_p.getParameterT(1).connectT(0, sb13); // switcher5 -> sb13::Bypassed
		auto& switcher6_p = switcher6.getWrappedObject().getParameter();
		switcher6_p.getParameterT(0).connectT(0, sb14); // switcher6 -> sb14::Bypassed
		switcher6_p.getParameterT(1).connectT(0, sb15); // switcher6 -> sb15::Bypassed
		auto& switcher7_p = switcher7.getWrappedObject().getParameter();
		switcher7_p.getParameterT(0).connectT(0, sb16); // switcher7 -> sb16::Bypassed
		switcher7_p.getParameterT(1).connectT(0, sb17); // switcher7 -> sb17::Bypassed
		auto& switcher8_p = switcher8.getWrappedObject().getParameter();
		switcher8_p.getParameterT(0).connectT(0, sb18); // switcher8 -> sb18::Bypassed
		switcher8_p.getParameterT(1).connectT(0, sb19); // switcher8 -> sb19::Bypassed
		auto& switcher1_p = switcher1.getWrappedObject().getParameter();
		switcher1_p.getParameterT(0).connectT(0, sb4); // switcher1 -> sb4::Bypassed
		switcher1_p.getParameterT(1).connectT(0, sb5); // switcher1 -> sb5::Bypassed
		auto& SFZ_p = SFZ.getWrappedObject().getParameter();
		SFZ_p.getParameterT(0).connectT(0, switcher2); // SFZ -> switcher2::Value
		SFZ_p.getParameterT(1).connectT(0, switcher3); // SFZ -> switcher3::Value
		SFZ_p.getParameterT(2).connectT(0, switcher4); // SFZ -> switcher4::Value
		SFZ_p.getParameterT(3).connectT(0, switcher5); // SFZ -> switcher5::Value
		SFZ_p.getParameterT(4).connectT(0, switcher6); // SFZ -> switcher6::Value
		SFZ_p.getParameterT(5).connectT(0, switcher7); // SFZ -> switcher7::Value
		SFZ_p.getParameterT(6).connectT(0, switcher8); // SFZ -> switcher8::Value
		SFZ_p.getParameterT(7).connectT(0, switcher1); // SFZ -> switcher1::Value
		
		// Default Values --------------------------------------------------------------------------
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		softbypass_switch20.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher16::Value is automated
		
		;                                   // input_toggle8::Input is automated
		input_toggle8.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle8::Value2 is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		;                                 // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);       // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 20.);      // envelope::ahdsr::Hold
		;                                 // ahdsr::Decay is automated
		;                                 // ahdsr::Sustain is automated
		;                                 // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.465632); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);       // envelope::ahdsr::Retrigger
		;                                 // ahdsr::Gate is automated
		
		; // add9::Value is automated
		
		clear17.setParameterT(0, 0.); // math::clear::Value
		
		;                                  // pack8_writer::Value1 is automated
		pack8_writer.setParameterT(1, 0.); // control::pack8_writer::Value2
		;                                  // pack8_writer::Value3 is automated
		pack8_writer.setParameterT(3, 0.); // control::pack8_writer::Value4
		;                                  // pack8_writer::Value5 is automated
		pack8_writer.setParameterT(5, 0.); // control::pack8_writer::Value6
		;                                  // pack8_writer::Value7 is automated
		pack8_writer.setParameterT(7, 0.); // control::pack8_writer::Value8
		
		; // cable_table5::Value is automated
		
		clear14.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack2::Value is automated
		
		; // add57::Value is automated
		
		;                                   // pack8_writer1::Value1 is automated
		pack8_writer1.setParameterT(1, 0.); // control::pack8_writer::Value2
		;                                   // pack8_writer1::Value3 is automated
		pack8_writer1.setParameterT(3, 0.); // control::pack8_writer::Value4
		;                                   // pack8_writer1::Value5 is automated
		pack8_writer1.setParameterT(5, 0.); // control::pack8_writer::Value6
		;                                   // pack8_writer1::Value7 is automated
		pack8_writer1.setParameterT(7, 0.); // control::pack8_writer::Value8
		
		; // cable_table10::Value is automated
		
		clear16.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack1::Value is automated
		
		; // add58::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		;                                      // simple_ar2::Attack is automated
		;                                      // simple_ar2::Release is automated
		;                                      // simple_ar2::Gate is automated
		simple_ar2.setParameterT(3, 0.563867); // envelope::simple_ar::AttackCurve
		
		; // add7::Value is automated
		
		;                          // pma9::Value is automated
		;                          // pma9::Multiply is automated
		pma9.setParameterT(2, 0.); // control::pma::Add
		
		; // add2::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // tempo_sync2::Tempo is automated
		;                                   // tempo_sync2::Multiplier is automated
		tempo_sync2.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp2::PeriodTime is automated
		;                           // ramp2::LoopStart is automated
		ramp2.setParameterT(2, 1.); // core::ramp::Gate
		
		softbypass_switch21.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher17::Value is automated
		
		; // converter1::Value is automated
		
		;                                 // oscillator1::Mode is automated
		;                                 // oscillator1::Frequency is automated
		oscillator1.setParameterT(2, 1.); // core::oscillator::FreqRatio
		oscillator1.setParameterT(3, 1.); // core::oscillator::Gate
		oscillator1.setParameterT(4, 0.); // core::oscillator::Phase
		oscillator1.setParameterT(5, 1.); // core::oscillator::Gain
		
		sig2mod1.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // cable_table1::Value is automated
		
		; // add::Value is automated
		
		clear8.setParameterT(0, 0.); // math::clear::Value
		
		; // steppack1::Value is automated
		
		; // add1::Value is automated
		
		;                           // pma25::Value is automated
		;                           // pma25::Multiply is automated
		pma25.setParameterT(2, 0.); // control::pma::Add
		
		; // add3::Value is automated
		
		;                                   // tempo_sync3::Tempo is automated
		;                                   // tempo_sync3::Multiplier is automated
		tempo_sync3.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync3.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp3::PeriodTime is automated
		;                           // ramp3::LoopStart is automated
		ramp3.setParameterT(2, 1.); // core::ramp::Gate
		
		softbypass_switch22.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher18::Value is automated
		
		; // converter2::Value is automated
		
		;                                 // oscillator2::Mode is automated
		;                                 // oscillator2::Frequency is automated
		oscillator2.setParameterT(2, 1.); // core::oscillator::FreqRatio
		oscillator2.setParameterT(3, 1.); // core::oscillator::Gate
		oscillator2.setParameterT(4, 0.); // core::oscillator::Phase
		oscillator2.setParameterT(5, 1.); // core::oscillator::Gain
		
		sig2mod2.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // cable_table2::Value is automated
		
		; // add4::Value is automated
		
		clear9.setParameterT(0, 0.); // math::clear::Value
		
		; // steppack2::Value is automated
		
		; // add5::Value is automated
		
		;                           // pma28::Value is automated
		pma28.setParameterT(1, 0.); // control::pma::Multiply
		pma28.setParameterT(2, 0.); // control::pma::Add
		
		; // add6::Value is automated
		
		; // pma19::Value is automated
		; // pma19::Multiply is automated
		; // pma19::Add is automated
		
		; // pma11::Value is automated
		; // pma11::Multiply is automated
		; // pma11::Add is automated
		
		; // pma8::Value is automated
		; // pma8::Multiply is automated
		; // pma8::Add is automated
		
		; // cable_table::Value is automated
		
		; // pma21::Value is automated
		; // pma21::Multiply is automated
		; // pma21::Add is automated
		
		; // pma13::Value is automated
		; // pma13::Multiply is automated
		; // pma13::Add is automated
		
		; // pma10::Value is automated
		; // pma10::Multiply is automated
		; // pma10::Add is automated
		
		; // pma22::Value is automated
		; // pma22::Multiply is automated
		; // pma22::Add is automated
		
		; // pma14::Value is automated
		; // pma14::Multiply is automated
		; // pma14::Add is automated
		
		;                                   // pma_unscaled8::Value is automated
		pma_unscaled8.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled8::Add is automated
		
		midi_cc.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // pma17::Value is automated
		; // pma17::Multiply is automated
		; // pma17::Add is automated
		
		; // pma23::Value is automated
		; // pma23::Multiply is automated
		; // pma23::Add is automated
		
		; // pma26::Value is automated
		; // pma26::Multiply is automated
		; // pma26::Add is automated
		
		; // pma16::Value is automated
		; // pma16::Multiply is automated
		; // pma16::Add is automated
		
		; // pma24::Value is automated
		; // pma24::Multiply is automated
		; // pma24::Add is automated
		
		; // pma27::Value is automated
		; // pma27::Multiply is automated
		; // pma27::Add is automated
		
		; // pma15::Value is automated
		; // pma15::Multiply is automated
		; // pma15::Add is automated
		
		; // pma20::Value is automated
		; // pma20::Multiply is automated
		; // pma20::Add is automated
		
		; // pma12::Value is automated
		; // pma12::Multiply is automated
		; // pma12::Add is automated
		
		; // pma18::Value is automated
		; // pma18::Multiply is automated
		; // pma18::Add is automated
		
		; // xfader::Value is automated
		
		; // xfader3::Value is automated
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		; // input_toggle1::Input is automated
		; // input_toggle1::Value1 is automated
		; // input_toggle1::Value2 is automated
		
		; // input_toggle2::Input is automated
		; // input_toggle2::Value1 is automated
		; // input_toggle2::Value2 is automated
		
		; // input_toggle3::Input is automated
		; // input_toggle3::Value1 is automated
		; // input_toggle3::Value2 is automated
		
		; // input_toggle4::Input is automated
		; // input_toggle4::Value1 is automated
		; // input_toggle4::Value2 is automated
		
		; // input_toggle5::Input is automated
		; // input_toggle5::Value1 is automated
		; // input_toggle5::Value2 is automated
		
		;                                   // input_toggle6::Input is automated
		input_toggle6.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle6::Value2 is automated
		
		; // input_toggle7::Input is automated
		; // input_toggle7::Value1 is automated
		; // input_toggle7::Value2 is automated
		
		; // harm::Value is automated
		
		; // cut::Value is automated
		
		; // pan::Value is automated
		
		; // vol::Value is automated
		
		; // pitch::Value is automated
		
		; // cutmix::Value is automated
		
		; // SFZ::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                            // minmax::Value is automated
		;                            // minmax::Minimum is automated
		;                            // minmax::Maximum is automated
		minmax.setParameterT(3, 1.); // control::minmax::Skew
		;                            // minmax::Step is automated
		minmax.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                  // pma_unscaled::Value is automated
		pma_unscaled.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                  // pma_unscaled::Add is automated
		
		softbypass_switch5.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher2::Value is automated
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		file_player9.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player9.setParameterT(1, 0.);   // core::file_player::Gate
		file_player9.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player9.setParameterT(3, 0.);   // core::file_player::FreqRatio
		
		dry_wet2.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer1::Value is automated
		
		;                                 // dry_gain1::Gain is automated
		dry_gain1.setParameterT(1, 20.);  // core::gain::Smoothing
		dry_gain1.setParameterT(2, -24.); // core::gain::ResetValue
		
		;                                // svf::Frequency is automated
		;                                // svf::Q is automated
		svf.setParameterT(2, 0.);        // filters::svf::Gain
		svf.setParameterT(3, 0.0042172); // filters::svf::Smoothing
		;                                // svf::Mode is automated
		svf.setParameterT(5, 1.);        // filters::svf::Enabled
		
		;                                 // wet_gain1::Gain is automated
		wet_gain1.setParameterT(1, 20.);  // core::gain::Smoothing
		wet_gain1.setParameterT(2, -24.); // core::gain::ResetValue
		
		pma.setParameterT(0, 0.); // control::pma::Value
		pma.setParameterT(1, 1.); // control::pma::Multiply
		;                         // pma::Add is automated
		
		;                              // jpanner1::Pan is automated
		jpanner1.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                              // gain8::Gain is automated
		gain8.setParameterT(1, 22.);   // core::gain::Smoothing
		gain8.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter1::Value is automated
		;                                         // smoothed_parameter1::SmoothingTime is automated
		smoothed_parameter1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 0.);    // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax7::Value is automated
		;                             // minmax7::Minimum is automated
		;                             // minmax7::Maximum is automated
		minmax7.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax7::Step is automated
		minmax7.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled7::Value is automated
		pma_unscaled7.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled7::Add is automated
		
		softbypass_switch6.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher3::Value is automated
		
		file_player7.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player7.setParameterT(1, 0.);   // core::file_player::Gate
		file_player7.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player7::FreqRatio is automated
		
		file_player10.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player10.setParameterT(1, 0.);   // core::file_player::Gate
		file_player10.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player10::FreqRatio is automated
		
		dry_wet3.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer2::Value is automated
		
		;                                 // dry_gain2::Gain is automated
		dry_gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		dry_gain2.setParameterT(2, -24.); // core::gain::ResetValue
		
		;                                  // svf7::Frequency is automated
		;                                  // svf7::Q is automated
		svf7.setParameterT(2, 0.);         // filters::svf::Gain
		svf7.setParameterT(3, 0.00697763); // filters::svf::Smoothing
		;                                  // svf7::Mode is automated
		svf7.setParameterT(5, 1.);         // filters::svf::Enabled
		
		;                                 // wet_gain2::Gain is automated
		wet_gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		wet_gain2.setParameterT(2, -24.); // core::gain::ResetValue
		
		pma2.setParameterT(0, 0.); // control::pma::Value
		pma2.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma2::Add is automated
		
		;                              // jpanner2::Pan is automated
		jpanner2.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                              // gain9::Gain is automated
		gain9.setParameterT(1, 12.);   // core::gain::Smoothing
		gain9.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter2::Value is automated
		;                                         // smoothed_parameter2::SmoothingTime is automated
		smoothed_parameter2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain7::Gain is automated
		gain7.setParameterT(1, 0.);    // core::gain::Smoothing
		gain7.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax6::Value is automated
		;                             // minmax6::Minimum is automated
		;                             // minmax6::Maximum is automated
		minmax6.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax6::Step is automated
		minmax6.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled6::Value is automated
		pma_unscaled6.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled6::Add is automated
		
		softbypass_switch7.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher4::Value is automated
		
		file_player6.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player6.setParameterT(1, 0.);   // core::file_player::Gate
		file_player6.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player6::FreqRatio is automated
		
		file_player11.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player11.setParameterT(1, 0.);   // core::file_player::Gate
		file_player11.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player11::FreqRatio is automated
		
		dry_wet4.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer3::Value is automated
		
		;                                 // dry_gain3::Gain is automated
		dry_gain3.setParameterT(1, 20.);  // core::gain::Smoothing
		dry_gain3.setParameterT(2, -24.); // core::gain::ResetValue
		
		;                                  // svf6::Frequency is automated
		;                                  // svf6::Q is automated
		svf6.setParameterT(2, 0.);         // filters::svf::Gain
		svf6.setParameterT(3, 0.00592377); // filters::svf::Smoothing
		;                                  // svf6::Mode is automated
		svf6.setParameterT(5, 1.);         // filters::svf::Enabled
		
		;                                 // wet_gain3::Gain is automated
		wet_gain3.setParameterT(1, 20.);  // core::gain::Smoothing
		wet_gain3.setParameterT(2, -24.); // core::gain::ResetValue
		
		pma3.setParameterT(0, 0.); // control::pma::Value
		pma3.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma3::Add is automated
		
		;                              // jpanner3::Pan is automated
		jpanner3.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                               // gain10::Gain is automated
		gain10.setParameterT(1, 20.);   // core::gain::Smoothing
		gain10.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter3::Value is automated
		;                                         // smoothed_parameter3::SmoothingTime is automated
		smoothed_parameter3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain6::Gain is automated
		gain6.setParameterT(1, 0.1);   // core::gain::Smoothing
		gain6.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax5::Value is automated
		;                             // minmax5::Minimum is automated
		;                             // minmax5::Maximum is automated
		minmax5.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax5::Step is automated
		minmax5.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled5::Value is automated
		pma_unscaled5.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled5::Add is automated
		
		softbypass_switch8.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher5::Value is automated
		
		file_player5.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player5.setParameterT(1, 0.);   // core::file_player::Gate
		file_player5.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player5::FreqRatio is automated
		
		file_player12.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player12.setParameterT(1, 0.);   // core::file_player::Gate
		file_player12.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player12::FreqRatio is automated
		
		dry_wet8.setParameterT(0, 0.); // container::split::DryWet
		
		; // dry_wet_mixer7::Value is automated
		
		;                                 // dry_gain7::Gain is automated
		dry_gain7.setParameterT(1, 20.);  // core::gain::Smoothing
		dry_gain7.setParameterT(2, -24.); // core::gain::ResetValue
		
		;                                  // svf5::Frequency is automated
		;                                  // svf5::Q is automated
		svf5.setParameterT(2, 0.);         // filters::svf::Gain
		svf5.setParameterT(3, 0.00785126); // filters::svf::Smoothing
		;                                  // svf5::Mode is automated
		svf5.setParameterT(5, 1.);         // filters::svf::Enabled
		
		;                                 // wet_gain7::Gain is automated
		wet_gain7.setParameterT(1, 20.);  // core::gain::Smoothing
		wet_gain7.setParameterT(2, -24.); // core::gain::ResetValue
		
		pma4.setParameterT(0, 0.); // control::pma::Value
		pma4.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma4::Add is automated
		
		;                              // jpanner4::Pan is automated
		jpanner4.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                               // gain11::Gain is automated
		gain11.setParameterT(1, 20.);   // core::gain::Smoothing
		gain11.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter4::Value is automated
		;                                         // smoothed_parameter4::SmoothingTime is automated
		smoothed_parameter4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain5::Gain is automated
		gain5.setParameterT(1, 0.);    // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax4::Value is automated
		;                             // minmax4::Minimum is automated
		;                             // minmax4::Maximum is automated
		minmax4.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax4::Step is automated
		minmax4.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled4::Value is automated
		pma_unscaled4.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled4::Add is automated
		
		softbypass_switch9.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher6::Value is automated
		
		file_player4.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player4.setParameterT(1, 0.);   // core::file_player::Gate
		file_player4.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player4::FreqRatio is automated
		
		file_player13.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player13.setParameterT(1, 0.);   // core::file_player::Gate
		file_player13.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player13::FreqRatio is automated
		
		dry_wet5.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer4::Value is automated
		
		;                                 // dry_gain4::Gain is automated
		dry_gain4.setParameterT(1, 20.);  // core::gain::Smoothing
		dry_gain4.setParameterT(2, -24.); // core::gain::ResetValue
		
		;                                 // svf4::Frequency is automated
		;                                 // svf4::Q is automated
		svf4.setParameterT(2, 0.);        // filters::svf::Gain
		svf4.setParameterT(3, 0.0100619); // filters::svf::Smoothing
		;                                 // svf4::Mode is automated
		svf4.setParameterT(5, 1.);        // filters::svf::Enabled
		
		;                                 // wet_gain4::Gain is automated
		wet_gain4.setParameterT(1, 20.);  // core::gain::Smoothing
		wet_gain4.setParameterT(2, -24.); // core::gain::ResetValue
		
		pma5.setParameterT(0, 0.); // control::pma::Value
		pma5.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma5::Add is automated
		
		;                              // jpanner5::Pan is automated
		jpanner5.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                               // gain12::Gain is automated
		gain12.setParameterT(1, 20.);   // core::gain::Smoothing
		gain12.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain4::Gain is automated
		gain4.setParameterT(1, 0.);    // core::gain::Smoothing
		gain4.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax3::Value is automated
		;                             // minmax3::Minimum is automated
		;                             // minmax3::Maximum is automated
		minmax3.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax3::Step is automated
		minmax3.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled3::Value is automated
		pma_unscaled3.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled3::Add is automated
		
		softbypass_switch10.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher7::Value is automated
		
		file_player3.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player3.setParameterT(1, 0.);   // core::file_player::Gate
		file_player3.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player3::FreqRatio is automated
		
		file_player14.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player14.setParameterT(1, 0.);   // core::file_player::Gate
		file_player14.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player14::FreqRatio is automated
		
		dry_wet6.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer5::Value is automated
		
		;                                 // dry_gain5::Gain is automated
		dry_gain5.setParameterT(1, 20.);  // core::gain::Smoothing
		dry_gain5.setParameterT(2, -24.); // core::gain::ResetValue
		
		;                                 // svf3::Frequency is automated
		;                                 // svf3::Q is automated
		svf3.setParameterT(2, 0.);        // filters::svf::Gain
		svf3.setParameterT(3, 0.0049525); // filters::svf::Smoothing
		;                                 // svf3::Mode is automated
		svf3.setParameterT(5, 1.);        // filters::svf::Enabled
		
		;                                 // wet_gain5::Gain is automated
		wet_gain5.setParameterT(1, 20.);  // core::gain::Smoothing
		wet_gain5.setParameterT(2, -24.); // core::gain::ResetValue
		
		pma6.setParameterT(0, 0.); // control::pma::Value
		pma6.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma6::Add is automated
		
		;                              // jpanner6::Pan is automated
		jpanner6.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                               // gain13::Gain is automated
		gain13.setParameterT(1, 20.);   // core::gain::Smoothing
		gain13.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter5::Value is automated
		;                                         // smoothed_parameter5::SmoothingTime is automated
		smoothed_parameter5.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 0.);    // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax2::Value is automated
		;                             // minmax2::Minimum is automated
		;                             // minmax2::Maximum is automated
		minmax2.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax2::Step is automated
		minmax2.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled2::Value is automated
		pma_unscaled2.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled2::Add is automated
		
		softbypass_switch11.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher8::Value is automated
		
		file_player2.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player2.setParameterT(1, 0.);   // core::file_player::Gate
		file_player2.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player2::FreqRatio is automated
		
		file_player15.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player15.setParameterT(1, 0.);   // core::file_player::Gate
		file_player15.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                     // file_player15::FreqRatio is automated
		
		dry_wet7.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer6::Value is automated
		
		;                                 // dry_gain6::Gain is automated
		dry_gain6.setParameterT(1, 20.);  // core::gain::Smoothing
		dry_gain6.setParameterT(2, -24.); // core::gain::ResetValue
		
		;                                 // svf2::Frequency is automated
		;                                 // svf2::Q is automated
		svf2.setParameterT(2, 0.);        // filters::svf::Gain
		svf2.setParameterT(3, 0.0110101); // filters::svf::Smoothing
		;                                 // svf2::Mode is automated
		svf2.setParameterT(5, 1.);        // filters::svf::Enabled
		
		;                                 // wet_gain6::Gain is automated
		wet_gain6.setParameterT(1, 20.);  // core::gain::Smoothing
		wet_gain6.setParameterT(2, -24.); // core::gain::ResetValue
		
		pma7.setParameterT(0, 0.); // control::pma::Value
		pma7.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma7::Add is automated
		
		;                              // jpanner7::Pan is automated
		jpanner7.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                         // smoothed_parameter7::Value is automated
		;                                         // smoothed_parameter7::SmoothingTime is automated
		smoothed_parameter7.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                               // gain14::Gain is automated
		gain14.setParameterT(1, 20.);   // core::gain::Smoothing
		gain14.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 0.);    // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // minmax1::Value is automated
		;                             // minmax1::Minimum is automated
		;                             // minmax1::Maximum is automated
		minmax1.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax1::Step is automated
		minmax1.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // pma_unscaled1::Value is automated
		pma_unscaled1.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled1::Add is automated
		
		softbypass_switch3.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher1::Value is automated
		
		file_player1.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player1.setParameterT(1, 0.);   // core::file_player::Gate
		file_player1.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player1::FreqRatio is automated
		
		file_player8.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player8.setParameterT(1, 0.);   // core::file_player::Gate
		file_player8.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                    // file_player8::FreqRatio is automated
		
		dry_wet1.setParameterT(0, 0.526073); // container::split::DryWet
		
		; // dry_wet_mixer::Value is automated
		
		;                                // dry_gain::Gain is automated
		dry_gain.setParameterT(1, 20.);  // core::gain::Smoothing
		dry_gain.setParameterT(2, -24.); // core::gain::ResetValue
		
		;                                  // svf1::Frequency is automated
		;                                  // svf1::Q is automated
		svf1.setParameterT(2, 0.);         // filters::svf::Gain
		svf1.setParameterT(3, 0.00680795); // filters::svf::Smoothing
		;                                  // svf1::Mode is automated
		svf1.setParameterT(5, 1.);         // filters::svf::Enabled
		
		;                                // wet_gain::Gain is automated
		wet_gain.setParameterT(1, 20.);  // core::gain::Smoothing
		wet_gain.setParameterT(2, -24.); // core::gain::ResetValue
		
		pma1.setParameterT(0, 0.); // control::pma::Value
		pma1.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma1::Add is automated
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                                         // smoothed_parameter6::Value is automated
		;                                         // smoothed_parameter6::SmoothingTime is automated
		smoothed_parameter6.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                               // gain15::Gain is automated
		gain15.setParameterT(1, 20.);   // core::gain::Smoothing
		gain15.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 0.);    // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.824642);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 16.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 0.570232);
		this->setParameterT(15, 0.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 0.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 0.);
		this->setParameterT(20, 0.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 0.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 1.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 0.);
		this->setParameterT(28, 0.);
		this->setParameterT(29, 1.);
		this->setParameterT(30, 0.125352);
		this->setParameterT(31, 2204.7);
		this->setParameterT(32, 0.);
		this->setParameterT(33, 1.);
		this->setParameterT(34, 1.);
		this->setParameterT(35, 0.);
		this->setParameterT(36, 1.);
		this->setParameterT(37, 1.);
		this->setParameterT(38, 1.);
		this->setParameterT(39, 1.);
		this->setParameterT(40, 1941.4);
		this->setParameterT(41, 10000.);
		this->setParameterT(42, 0.);
		this->setParameterT(43, 0.);
		this->setParameterT(44, 0.);
		this->setParameterT(45, 0.);
		this->setParameterT(46, 0.);
		this->setParameterT(47, 0.);
		this->setParameterT(48, 1.);
		this->setParameterT(49, 0.);
		this->setParameterT(50, 0.00629706);
		this->setParameterT(51, 0.0210237);
		this->setParameterT(52, 1.);
		this->setParameterT(53, -0.0779912);
		this->setParameterT(54, 0.0685212);
		this->setParameterT(55, 0.0396875);
		this->setParameterT(56, -0.0148376);
		this->setParameterT(57, -0.0463811);
		this->setParameterT(58, 0.0139453);
		this->setParameterT(59, 1.);
		this->setParameterT(60, 1.);
		this->setParameterT(61, 1.);
		this->setParameterT(62, 0.);
		this->setParameterT(63, 0.);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                         // XFHarm_impl::ramp_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2).setExternalData(b, index);         // XFHarm_impl::ahdsr_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(1).                                           // XFHarm_impl::pack8_writer_t
        getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(1).getT(1).                                           // XFHarm_impl::cable_table5_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(1).getT(1).                                           // XFHarm_impl::cable_pack2_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(3).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(1).getT(1).                                           // XFHarm_impl::pack8_writer1_t
        getT(0).getT(0).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(1).getT(1).                                           // XFHarm_impl::cable_table10_t<NV>
        getT(0).getT(0).getT(1).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(1).getT(1).                                           // XFHarm_impl::cable_pack1_t<NV>
        getT(0).getT(0).getT(1).getT(1).getT(3).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(1).                                                   // XFHarm_impl::peak2_t<NV>
        getT(1).getT(0).getT(0).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(1).                                                   // XFHarm_impl::simple_ar2_t<NV>
        getT(1).getT(0).getT(0).getT(4).setExternalData(b, index);
		this->getT(0).getT(0).getT(6).setExternalData(b, index);                                 // XFHarm_impl::peak_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).setExternalData(b, index);                         // XFHarm_impl::ramp2_t<NV>
		this->getT(0).getT(1).getT(2).getT(1).getT(0).getT(1).setExternalData(b, index);         // XFHarm_impl::oscillator1_t<NV>
		this->getT(0).getT(1).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);         // XFHarm_impl::cable_table1_t<NV>
		this->getT(0).getT(1).getT(2).getT(1).getT(2).getT(0).getT(1).setExternalData(b, index); // XFHarm_impl::steppack1_t<NV>
		this->getT(0).getT(1).getT(6).setExternalData(b, index);                                 // XFHarm_impl::peak1_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).setExternalData(b, index);                         // XFHarm_impl::ramp3_t<NV>
		this->getT(0).getT(2).getT(2).getT(1).getT(0).getT(1).setExternalData(b, index);         // XFHarm_impl::oscillator2_t<NV>
		this->getT(0).getT(2).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);         // XFHarm_impl::cable_table2_t<NV>
		this->getT(0).getT(2).getT(2).getT(1).getT(2).getT(0).getT(1).setExternalData(b, index); // XFHarm_impl::steppack2_t<NV>
		this->getT(0).getT(2).getT(6).setExternalData(b, index);                                 // XFHarm_impl::peak3_t<NV>
		this->getT(1).getT(0).getT(3).setExternalData(b, index);                                 // XFHarm_impl::cable_table_t
		this->getT(2).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                 // XFHarm_impl::harm_t<NV>
		this->getT(2).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);                 // XFHarm_impl::cut_t<NV>
		this->getT(2).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index);                 // XFHarm_impl::pan_t<NV>
		this->getT(2).getT(0).getT(0).getT(1).getT(3).setExternalData(b, index);                 // XFHarm_impl::vol_t
		this->getT(2).getT(0).getT(0).getT(1).getT(4).setExternalData(b, index);                 // XFHarm_impl::pitch_t<NV>
		this->getT(2).getT(0).getT(0).getT(1).getT(5).setExternalData(b, index);                 // XFHarm_impl::cutmix_t
		this->getT(2).getT(0).getT(0).getT(1).getT(6).setExternalData(b, index);                 // XFHarm_impl::SFZ_t<NV>
		this->getT(2).getT(0).getT(1).getT(0).                                                   // XFHarm_impl::file_player_t<NV>
        getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(0).  // XFHarm_impl::file_player9_t<NV>
        getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(1).  // XFHarm_impl::file_player7_t<NV>
        getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(1).  // XFHarm_impl::file_player10_t<NV>
        getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(2).  // XFHarm_impl::file_player6_t<NV>
        getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(2).  // XFHarm_impl::file_player11_t<NV>
        getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(3).  // XFHarm_impl::file_player5_t<NV>
        getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(3).  // XFHarm_impl::file_player12_t<NV>
        getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(4).  // XFHarm_impl::file_player4_t<NV>
        getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(4).  // XFHarm_impl::file_player13_t<NV>
        getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(5).  // XFHarm_impl::file_player3_t<NV>
        getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(5).  // XFHarm_impl::file_player14_t<NV>
        getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(6).  // XFHarm_impl::file_player2_t<NV>
        getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(6).  // XFHarm_impl::file_player15_t<NV>
        getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(7).  // XFHarm_impl::file_player1_t<NV>
        getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(2).getT(0).getT(1).getT(7).  // XFHarm_impl::file_player8_t<NV>
        getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);
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
using XFHarm = wrap::node<XFHarm_impl::instance<NV>>;
}


