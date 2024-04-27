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

namespace xfade5_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using ahdsr3_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                        parameter::empty>;

template <int NV>
using ahdsr3_t = wrap::no_data<envelope::ahdsr<NV, ahdsr3_multimod<NV>>>;
template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<ahdsr3_t<NV>, 8>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<input_toggle_t<NV>, 2>>;

template <int NV>
using cable_pack3_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<2>>;
using cable_table2_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<2>>;

template <int NV>
using cable_table4_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<cable_pack3_t<NV>, 0>, 
                                          parameter::plain<cable_table2_t, 0>>;

struct cable_table4_t_data
{
	span<float, 512> data =
	{
		0.f, 7.7486e-06f, 0.0039838f, 0.00795978f, 0.0119358f, 0.0159118f,
		0.0198879f, 0.0238639f, 0.0278399f, 0.0318159f, 0.0357919f, 0.039768f,
		0.043744f, 0.04772f, 0.051696f, 0.055672f, 0.059648f, 0.0636241f,
		0.0676001f, 0.0715761f, 0.0755521f, 0.0795282f, 0.0835042f, 0.0874802f,
		0.0914562f, 0.0954322f, 0.0994083f, 0.103384f, 0.10736f, 0.111336f,
		0.115312f, 0.119288f, 0.123264f, 0.12724f, 0.131216f, 0.135192f,
		0.139168f, 0.143144f, 0.14712f, 0.151097f, 0.155073f, 0.159049f,
		0.163025f, 0.167001f, 0.170977f, 0.174953f, 0.178929f, 0.182905f,
		0.186881f, 0.190857f, 0.194833f, 0.198809f, 0.202785f, 0.206761f,
		0.210737f, 0.214713f, 0.218689f, 0.222665f, 0.226641f, 0.230617f,
		0.234593f, 0.238569f, 0.242545f, 0.246521f, 0.250497f, 0.254473f,
		0.258449f, 0.262425f, 0.266401f, 0.270377f, 0.274353f, 0.278329f,
		0.282305f, 0.286281f, 0.290257f, 0.294233f, 0.298209f, 0.302185f,
		0.306161f, 0.310137f, 0.314113f, 0.318089f, 0.322065f, 0.326041f,
		0.330017f, 0.333993f, 0.337969f, 0.341945f, 0.345921f, 0.349898f,
		0.353873f, 0.35785f, 0.361826f, 0.365802f, 0.369778f, 0.373754f,
		0.37773f, 0.381706f, 0.385682f, 0.389658f, 0.393634f, 0.39761f,
		0.401586f, 0.405562f, 0.409538f, 0.413514f, 0.41749f, 0.421466f,
		0.425442f, 0.429418f, 0.433394f, 0.43737f, 0.441346f, 0.445322f,
		0.449298f, 0.453274f, 0.45725f, 0.461226f, 0.465202f, 0.469178f,
		0.473154f, 0.47713f, 0.481106f, 0.485082f, 0.489058f, 0.493034f,
		0.49701f, 0.500986f, 0.504962f, 0.508938f, 0.512914f, 0.51689f,
		0.520866f, 0.524842f, 0.528818f, 0.532794f, 0.53677f, 0.540746f,
		0.544722f, 0.548698f, 0.552674f, 0.55665f, 0.560627f, 0.564603f,
		0.568579f, 0.572555f, 0.576531f, 0.580507f, 0.584483f, 0.588459f,
		0.592435f, 0.596411f, 0.600387f, 0.604363f, 0.608339f, 0.612315f,
		0.616291f, 0.620267f, 0.624243f, 0.628219f, 0.632195f, 0.636171f,
		0.640147f, 0.644123f, 0.648099f, 0.652075f, 0.656051f, 0.660027f,
		0.664003f, 0.667979f, 0.671955f, 0.675931f, 0.679907f, 0.683883f,
		0.687859f, 0.691835f, 0.695811f, 0.699787f, 0.703763f, 0.707739f,
		0.711715f, 0.715691f, 0.719667f, 0.723643f, 0.727619f, 0.731595f,
		0.735571f, 0.739547f, 0.743523f, 0.747499f, 0.751475f, 0.755452f,
		0.759427f, 0.763403f, 0.76738f, 0.771356f, 0.775332f, 0.779308f,
		0.783284f, 0.78726f, 0.791236f, 0.795212f, 0.799188f, 0.803164f,
		0.80714f, 0.811116f, 0.815092f, 0.819068f, 0.823044f, 0.82702f,
		0.830996f, 0.834972f, 0.838948f, 0.842924f, 0.8469f, 0.850876f,
		0.854852f, 0.858828f, 0.862804f, 0.86678f, 0.870756f, 0.874732f,
		0.878708f, 0.882684f, 0.88666f, 0.890636f, 0.894612f, 0.898588f,
		0.902564f, 0.90654f, 0.910516f, 0.914492f, 0.918468f, 0.922444f,
		0.92642f, 0.930396f, 0.934372f, 0.938348f, 0.942324f, 0.9463f,
		0.950276f, 0.954252f, 0.958228f, 0.962205f, 0.966181f, 0.970156f,
		0.974133f, 0.978109f, 0.982085f, 0.986061f, 0.990037f, 0.994013f,
		0.997989f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using cable_table4_t = wrap::data<control::cable_table<cable_table4_mod<NV>>, 
                                  data::embedded::table<cable_table4_t_data>>;

template <int NV>
using cable_pack6_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<3>>;
using cable_table3_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<3>>;

template <int NV>
using cable_table7_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<cable_pack6_t<NV>, 0>, 
                                          parameter::plain<cable_table3_t, 0>>;

struct cable_table7_t_data
{
	span<float, 512> data =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 0.833659f, 0.499674f, 0.16569f,
		0.00198776f, 0.00593245f, 0.00987726f, 0.013822f, 0.0177667f, 0.0217113f,
		0.025656f, 0.0296007f, 0.0335454f, 0.0374901f, 0.0414349f, 0.0453796f,
		0.0493243f, 0.053269f, 0.0572137f, 0.0611584f, 0.0651031f, 0.0690478f,
		0.0729926f, 0.0769373f, 0.080882f, 0.0848267f, 0.0887715f, 0.0927161f,
		0.0966609f, 0.100605f, 0.10455f, 0.108495f, 0.11244f, 0.116384f,
		0.120329f, 0.124274f, 0.128219f, 0.132163f, 0.136108f, 0.140053f,
		0.143997f, 0.147942f, 0.151887f, 0.155832f, 0.159776f, 0.163721f,
		0.167666f, 0.17161f, 0.175555f, 0.1795f, 0.183444f, 0.187389f,
		0.191334f, 0.195279f, 0.199223f, 0.203168f, 0.207113f, 0.211058f,
		0.215002f, 0.218947f, 0.222892f, 0.226836f, 0.230781f, 0.234726f,
		0.238671f, 0.242615f, 0.24656f, 0.250505f, 0.254449f, 0.258394f,
		0.262339f, 0.266284f, 0.270228f, 0.274173f, 0.278118f, 0.282062f,
		0.286007f, 0.289952f, 0.293897f, 0.297841f, 0.301786f, 0.305731f,
		0.309675f, 0.31362f, 0.317565f, 0.321509f, 0.325454f, 0.329399f,
		0.333344f, 0.337288f, 0.341233f, 0.345178f, 0.349122f, 0.353067f,
		0.357012f, 0.360957f, 0.364901f, 0.368846f, 0.372791f, 0.376735f,
		0.38068f, 0.384625f, 0.38857f, 0.392514f, 0.396459f, 0.400404f,
		0.404348f, 0.408293f, 0.412238f, 0.416183f, 0.420127f, 0.424072f,
		0.428017f, 0.431961f, 0.435906f, 0.439851f, 0.443796f, 0.44774f,
		0.451685f, 0.45563f, 0.459574f, 0.463519f, 0.467464f, 0.471408f,
		0.475353f, 0.479298f, 0.483243f, 0.487187f, 0.491132f, 0.495077f,
		0.499022f, 0.502966f, 0.506911f, 0.510856f, 0.5148f, 0.518745f,
		0.52269f, 0.526635f, 0.530579f, 0.534524f, 0.538469f, 0.542413f,
		0.546358f, 0.550303f, 0.554247f, 0.558192f, 0.562137f, 0.566082f,
		0.570026f, 0.573971f, 0.577916f, 0.58186f, 0.585805f, 0.58975f,
		0.593695f, 0.597639f, 0.601584f, 0.605529f, 0.609473f, 0.613418f,
		0.617363f, 0.621308f, 0.625252f, 0.629197f, 0.633142f, 0.637086f,
		0.641031f, 0.644976f, 0.648921f, 0.652865f, 0.65681f, 0.660755f,
		0.664699f, 0.668644f, 0.672589f, 0.676534f, 0.680478f, 0.684423f,
		0.688368f, 0.692312f, 0.696257f, 0.700202f, 0.704147f, 0.708091f,
		0.712036f, 0.715981f, 0.719925f, 0.72387f, 0.727815f, 0.731759f,
		0.735704f, 0.739649f, 0.743594f, 0.747538f, 0.751483f, 0.755428f,
		0.759372f, 0.763317f, 0.767262f, 0.771207f, 0.775151f, 0.779096f,
		0.783041f, 0.786985f, 0.79093f, 0.794875f, 0.79882f, 0.802764f,
		0.806709f, 0.810654f, 0.814598f, 0.818543f, 0.822488f, 0.826433f,
		0.830377f, 0.834322f, 0.838267f, 0.842212f, 0.846156f, 0.850101f,
		0.854046f, 0.85799f, 0.861935f, 0.86588f, 0.869825f, 0.873769f,
		0.877714f, 0.881659f, 0.885603f, 0.889548f, 0.893493f, 0.897438f,
		0.901382f, 0.905327f, 0.909272f, 0.913216f, 0.917161f, 0.921106f,
		0.92505f, 0.928995f, 0.93294f, 0.936885f, 0.940829f, 0.944774f,
		0.948719f, 0.952663f, 0.956608f, 0.960553f, 0.964498f, 0.968442f,
		0.972387f, 0.976332f, 0.980276f, 0.984221f, 0.988166f, 0.992111f,
		0.996055f, 1.f
	};
};

template <int NV>
using cable_table7_t = wrap::data<control::cable_table<cable_table7_mod<NV>>, 
                                  data::embedded::table<cable_table7_t_data>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;
using cable_table8_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<1>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<minmax_t<NV>, 0>, 
                                  parameter::plain<cable_table4_t<NV>, 0>, 
                                  parameter::plain<cable_table7_t<NV>, 0>, 
                                  parameter::plain<cable_pack_t<NV>, 0>, 
                                  parameter::plain<cable_table8_t, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using ramp1_t = wrap::no_data<core::ramp<NV, false>>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<ramp_t<NV>, 0>, 
                                        parameter::plain<ramp1_t<NV>, 0>, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync_t<NV>>, 
                                    ramp_t<NV>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, minmax_t<NV>>, 
                                math::clear<NV>, 
                                input_toggle_t<NV>, 
                                ahdsr3_t<NV>, 
                                math::add<NV>>;

template <int NV>
using sb1_t = bypass::smoothed<20, sb1_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb1_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::pi<NV>>, 
                                  math::sin<NV>, 
                                  math::sig2mod<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::pi<NV>>, 
                                  math::square<NV>, 
                                  wrap::no_process<math::sig2mod<NV>>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, wrap::no_process<math::sin<NV>>>>;
template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, wrap::no_process<math::clear<NV>>>, 
                                   oscillator_t<NV>, 
                                   fx::sampleandhold<NV>, 
                                   wrap::no_process<math::sig2mod<NV>>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain1_t<NV>>, 
                                    chain3_t<NV>, 
                                    chain2_t<NV>, 
                                    chain10_t<NV>>;

template <int NV>
using peak_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, ramp1_t<NV>>, 
                                branch1_t<NV>, 
                                peak_t<NV>, 
                                math::add<NV>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

using pack8_writer_t = wrap::data<control::pack8_writer, 
                                  data::external::sliderpack<0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, pack8_writer_t>, 
                                 cable_table8_t, 
                                 math::clear<NV>, 
                                 cable_pack_t<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain_t<NV>>>;

template <int NV>
using sb6_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, split2_t<NV>>, 
                                math::add<NV>>;

template <int NV>
using sb6_t = bypass::smoothed<20, sb6_t_<NV>>;
template <int NV>
using switcher_c2 = parameter::bypass<sb6_t<NV>>;

using pack8_writer2_t = wrap::data<control::pack8_writer, 
                                   data::external::sliderpack<2>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table4_t<NV>>, 
                                  pack8_writer2_t, 
                                  cable_table2_t, 
                                  cable_pack3_t<NV>, 
                                  math::add<NV>>;
using pack8_writer5_t = wrap::data<control::pack8_writer, 
                                   data::external::sliderpack<3>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table7_t<NV>>, 
                                   pack8_writer5_t, 
                                   cable_table3_t, 
                                   cable_pack6_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain7_t<NV>>, 
                                  chain11_t<NV>>;

template <int NV> using simple_ar_multimod = ahdsr3_multimod<NV>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod<NV>>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<simple_ar_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using no_midi1_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, simple_ar_t<NV>>, 
                                     math::add<NV>>;

template <int NV>
using no_midi1_t = wrap::no_midi<no_midi1_t_<NV>>;

template <int NV>
using soft_bypass_t_ = container::chain<parameter::empty, 
                                        wrap::fix<1, split6_t<NV>>, 
                                        peak2_t<NV>, 
                                        math::clear<NV>, 
                                        no_midi1_t<NV>>;

template <int NV>
using soft_bypass_t = bypass::smoothed<20, soft_bypass_t_<NV>>;
template <int NV>
using switcher_c3 = parameter::bypass<soft_bypass_t<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0<NV>, 
                                          switcher_c1<NV>, 
                                          switcher_c2<NV>, 
                                          switcher_c3<NV>, 
                                          parameter::empty>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 3.09944e-06f, 0.0016008f, 0.00319844f, 0.00479609f, 0.00639379f,
		0.00799143f, 0.00958908f, 0.0111868f, 0.0127844f, 0.0143821f, 0.0159798f,
		0.0175774f, 0.0191751f, 0.0207727f, 0.0223704f, 0.023968f, 0.0255657f,
		0.0271634f, 0.028761f, 0.0303587f, 0.0319564f, 0.033554f, 0.0351517f,
		0.0367494f, 0.038347f, 0.0399446f, 0.0415424f, 0.04314f, 0.0447376f,
		0.0463353f, 0.047933f, 0.0495306f, 0.0511283f, 0.052726f, 0.0543236f,
		0.0559213f, 0.057519f, 0.0591166f, 0.0607142f, 0.0623119f, 0.0639096f,
		0.0655073f, 0.0671049f, 0.0687026f, 0.0703002f, 0.0718979f, 0.0734956f,
		0.0750932f, 0.0766909f, 0.0782886f, 0.0798862f, 0.0814839f, 0.0830815f,
		0.0846792f, 0.0862769f, 0.0878745f, 0.0894722f, 0.0910699f, 0.0926675f,
		0.0942652f, 0.0958629f, 0.0974605f, 0.0990582f, 0.100656f, 0.102253f,
		0.103851f, 0.105449f, 0.107046f, 0.108644f, 0.110242f, 0.111839f,
		0.113437f, 0.115035f, 0.116632f, 0.11823f, 0.119828f, 0.121425f,
		0.123023f, 0.124621f, 0.126218f, 0.127816f, 0.129414f, 0.131011f,
		0.132609f, 0.134207f, 0.135804f, 0.137402f, 0.139f, 0.140597f,
		0.142195f, 0.143793f, 0.14539f, 0.146988f, 0.148586f, 0.150183f,
		0.151781f, 0.153379f, 0.154976f, 0.156574f, 0.158172f, 0.159769f,
		0.161367f, 0.162965f, 0.164562f, 0.16616f, 0.167758f, 0.169355f,
		0.170953f, 0.172551f, 0.174148f, 0.175746f, 0.177344f, 0.178941f,
		0.180539f, 0.182137f, 0.183734f, 0.185332f, 0.18693f, 0.188527f,
		0.190125f, 0.191723f, 0.19332f, 0.194918f, 0.196516f, 0.198113f,
		0.199711f, 0.201308f, 0.202906f, 0.204504f, 0.206102f, 0.207699f,
		0.209297f, 0.210894f, 0.212492f, 0.21409f, 0.215688f, 0.217285f,
		0.218883f, 0.22048f, 0.222078f, 0.223676f, 0.225273f, 0.226871f,
		0.228469f, 0.230066f, 0.231664f, 0.233262f, 0.234859f, 0.236457f,
		0.238055f, 0.239652f, 0.24125f, 0.242848f, 0.244445f, 0.246043f,
		0.247641f, 0.249238f, 0.250836f, 0.252434f, 0.254031f, 0.255629f,
		0.257227f, 0.258824f, 0.260422f, 0.26202f, 0.263617f, 0.265215f,
		0.266813f, 0.26841f, 0.270008f, 0.271606f, 0.273203f, 0.274801f,
		0.276399f, 0.277996f, 0.279594f, 0.281192f, 0.282789f, 0.284387f,
		0.285985f, 0.287582f, 0.28918f, 0.290778f, 0.292375f, 0.293973f,
		0.295571f, 0.297168f, 0.298766f, 0.300364f, 0.301961f, 0.303559f,
		0.305157f, 0.306754f, 0.308352f, 0.30995f, 0.311547f, 0.313145f,
		0.314743f, 0.31634f, 0.317938f, 0.319535f, 0.321133f, 0.322731f,
		0.324328f, 0.325926f, 0.327524f, 0.329121f, 0.330719f, 0.332317f,
		0.333915f, 0.335512f, 0.33711f, 0.338707f, 0.340305f, 0.341903f,
		0.3435f, 0.345098f, 0.346696f, 0.348293f, 0.349891f, 0.351489f,
		0.353086f, 0.354684f, 0.356282f, 0.357879f, 0.359477f, 0.361075f,
		0.362672f, 0.36427f, 0.365868f, 0.367465f, 0.369063f, 0.370661f,
		0.372258f, 0.373856f, 0.375454f, 0.377051f, 0.378649f, 0.380247f,
		0.381844f, 0.383442f, 0.38504f, 0.386637f, 0.388235f, 0.389833f,
		0.39143f, 0.393028f, 0.394626f, 0.396223f, 0.397821f, 0.399419f,
		0.401016f, 0.402614f, 0.404212f, 0.405809f, 0.407407f, 0.409005f,
		0.410602f, 0.4122f, 0.413798f, 0.415395f, 0.416993f, 0.418591f,
		0.420188f, 0.421786f, 0.423384f, 0.424981f, 0.426579f, 0.428177f,
		0.429774f, 0.431372f, 0.43297f, 0.434567f, 0.436165f, 0.437762f,
		0.43936f, 0.440958f, 0.442555f, 0.444153f, 0.445751f, 0.447348f,
		0.448946f, 0.450544f, 0.452142f, 0.453739f, 0.455337f, 0.456934f,
		0.458532f, 0.46013f, 0.461727f, 0.463325f, 0.464923f, 0.46652f,
		0.468118f, 0.469716f, 0.471313f, 0.472911f, 0.474509f, 0.476106f,
		0.477704f, 0.479302f, 0.480899f, 0.482497f, 0.484624f, 0.487114f,
		0.489604f, 0.492094f, 0.494583f, 0.497073f, 0.499563f, 0.502053f,
		0.504542f, 0.507032f, 0.509522f, 0.512011f, 0.514501f, 0.516991f,
		0.519481f, 0.52197f, 0.52446f, 0.52695f, 0.52944f, 0.531929f,
		0.534419f, 0.536909f, 0.539399f, 0.541888f, 0.544378f, 0.546868f,
		0.549358f, 0.551847f, 0.554337f, 0.556827f, 0.559317f, 0.561806f,
		0.564296f, 0.566786f, 0.569275f, 0.571765f, 0.574255f, 0.576745f,
		0.579234f, 0.581724f, 0.584214f, 0.586704f, 0.589193f, 0.591683f,
		0.594173f, 0.596663f, 0.599152f, 0.601642f, 0.604132f, 0.606622f,
		0.609111f, 0.611601f, 0.614091f, 0.61658f, 0.61907f, 0.62156f,
		0.62405f, 0.626539f, 0.629029f, 0.631519f, 0.634009f, 0.636498f,
		0.638988f, 0.641478f, 0.643968f, 0.646457f, 0.648947f, 0.651437f,
		0.653927f, 0.656416f, 0.658906f, 0.661396f, 0.663885f, 0.666375f,
		0.668865f, 0.671355f, 0.673844f, 0.676334f, 0.678824f, 0.681314f,
		0.683803f, 0.686293f, 0.688783f, 0.691273f, 0.693762f, 0.696252f,
		0.698742f, 0.701231f, 0.703721f, 0.706211f, 0.708701f, 0.71119f,
		0.71368f, 0.71617f, 0.71866f, 0.721149f, 0.723639f, 0.726129f,
		0.728619f, 0.731108f, 0.733598f, 0.736088f, 0.738578f, 0.741067f,
		0.743557f, 0.746047f, 0.748536f, 0.751026f, 0.753516f, 0.756006f,
		0.758496f, 0.760985f, 0.763475f, 0.765965f, 0.768454f, 0.770944f,
		0.773434f, 0.775924f, 0.778413f, 0.780903f, 0.783393f, 0.785883f,
		0.788372f, 0.790862f, 0.793352f, 0.795842f, 0.798331f, 0.800821f,
		0.803311f, 0.8058f, 0.80829f, 0.81078f, 0.81327f, 0.815759f,
		0.818249f, 0.820739f, 0.823229f, 0.825718f, 0.828208f, 0.830698f,
		0.833188f, 0.835677f, 0.838167f, 0.840657f, 0.843147f, 0.845636f,
		0.848126f, 0.850616f, 0.853106f, 0.855595f, 0.858085f, 0.860575f,
		0.863064f, 0.865554f, 0.868044f, 0.870534f, 0.873023f, 0.875513f,
		0.878003f, 0.880493f, 0.882982f, 0.885472f, 0.887962f, 0.890452f,
		0.892941f, 0.895431f, 0.897921f, 0.900411f, 0.9029f, 0.90539f,
		0.90788f, 0.910369f, 0.912859f, 0.915349f, 0.917839f, 0.920328f,
		0.922818f, 0.925308f, 0.927798f, 0.930287f, 0.932777f, 0.935267f,
		0.937757f, 0.940246f, 0.942736f, 0.945226f, 0.947716f, 0.950205f,
		0.952695f, 0.955185f, 0.957675f, 0.960164f, 0.962654f, 0.965144f,
		0.967633f, 0.970123f, 0.972613f, 0.975103f, 0.977592f, 0.980082f,
		0.982572f, 0.985062f, 0.987551f, 0.990041f, 0.992531f, 0.995021f,
		0.99751f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<switcher_t<NV>, 0>>, 
                                  data::embedded::table<cable_table1_t_data>>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<1, sb1_t<NV>>, 
                                        sb2_t<NV>, 
                                        sb6_t<NV>, 
                                        soft_bypass_t<NV>>;

template <int NV>
using softbypass_switch6_t = container::chain<parameter::empty, 
                                              wrap::fix<1, cable_table1_t<NV>>, 
                                              switcher_t<NV>, 
                                              math::clear<NV>, 
                                              sb_container_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  no_midi_t<NV>, 
                                  math::clear<NV>, 
                                  softbypass_switch6_t<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain8_t<NV>>>;

template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<math::add<NV>, 0>>;
template <int NV>
using midi_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                         control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_t<NV>>, 
                                  pma1_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma2_t = pma1_t<NV>;
template <int NV>
using midi1_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi1_t<NV>>, 
                                  pma2_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma3_t = pma1_t<NV>;
template <int NV>
using midi_cc_t = control::midi_cc<parameter::plain<pma3_t<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc_t<NV>>, 
                                  pma3_t<NV>, 
                                  math::add<NV>>;

template <int NV> using pma4_t = pma1_t<NV>;
template <int NV>
using midi_cc1_t = control::midi_cc<parameter::plain<pma4_t<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc1_t<NV>>, 
                                  pma4_t<NV>, 
                                  math::add<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain4_t<NV>>, 
                                  chain5_t<NV>, 
                                  chain6_t<NV>, 
                                  chain9_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, branch_t<NV>>, 
                                 split1_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter_x1_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using smoothed_parameter_x1_mod = parameter::from0To1<core::gain<NV>, 
                                                      0, 
                                                      smoothed_parameter_x1_modRange>;

template <int NV>
using smoothed_parameter_x1_t = wrap::mod<smoothed_parameter_x1_mod<NV>, 
                                          control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader_x1_multimod = parameter::list<parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::plain<smoothed_parameter_x1_t<NV>, 0>, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty>;

template <int NV>
using xfader_x1_t = control::xfader<xfader_x1_multimod<NV>, faders::switcher>;

template <int NV>
using smoothed_parameter1_x1_mod = smoothed_parameter_x1_mod<NV>;

template <int NV>
using smoothed_parameter1_x1_t = wrap::mod<smoothed_parameter1_x1_mod<NV>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader2_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::plain<smoothed_parameter1_x1_t<NV>, 0>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader2_x1_t = control::xfader<xfader2_x1_multimod<NV>, 
                                     faders::linear>;

template <int NV>
using smoothed_parameter2_x1_mod = smoothed_parameter_x1_mod<NV>;

template <int NV>
using smoothed_parameter2_x1_t = wrap::mod<smoothed_parameter2_x1_mod<NV>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader1_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::plain<smoothed_parameter2_x1_t<NV>, 0>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader1_x1_t = control::xfader<xfader1_x1_multimod<NV>, 
                                     faders::rms>;

template <int NV>
using smoothed_parameter4_x1_mod = smoothed_parameter_x1_mod<NV>;

template <int NV>
using smoothed_parameter4_x1_t = wrap::mod<smoothed_parameter4_x1_mod<NV>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader3_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::plain<smoothed_parameter4_x1_t<NV>, 0>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader3_x1_t = control::xfader<xfader3_x1_multimod<NV>, 
                                     faders::cosine_half>;

template <int NV>
using smoothed_parameter3_x1_mod = smoothed_parameter_x1_mod<NV>;

template <int NV>
using smoothed_parameter3_x1_t = wrap::mod<smoothed_parameter3_x1_mod<NV>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader4_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::plain<smoothed_parameter3_x1_t<NV>, 0>, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty>;

template <int NV>
using xfader4_x1_t = control::xfader<xfader4_x1_multimod<NV>, 
                                     faders::threshold>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<xfader_x1_t<NV>, 0>, 
                                 parameter::plain<xfader2_x1_t<NV>, 0>, 
                                 parameter::plain<xfader1_x1_t<NV>, 0>, 
                                 parameter::plain<xfader3_x1_t<NV>, 0>, 
                                 parameter::plain<xfader4_x1_t<NV>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split_t<NV>>, 
                                     peak1_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain1_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader_x1_t<NV>>, 
                                     smoothed_parameter_x1_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb1_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain1_x1_t<NV>>>;

template <int NV>
using sb1_x1_t = bypass::smoothed<20, sb1_x1_t_<NV>>;
template <int NV>
using switcher_x1_c0 = parameter::bypass<sb1_x1_t<NV>>;

template <int NV>
using chain3_x1_x1_t = container::chain<parameter::empty, 
                                        wrap::fix<2, xfader2_x1_t<NV>>, 
                                        smoothed_parameter1_x1_t<NV>, 
                                        core::gain<NV>>;

template <int NV>
using sb2_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain3_x1_x1_t<NV>>>;

template <int NV>
using sb2_x1_t = bypass::smoothed<20, sb2_x1_t_<NV>>;
template <int NV>
using switcher_x1_c1 = parameter::bypass<sb2_x1_t<NV>>;

template <int NV>
using chain2_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader1_x1_t<NV>>, 
                                     smoothed_parameter2_x1_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb3_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain2_x1_t<NV>>>;

template <int NV>
using sb3_x1_t = bypass::smoothed<20, sb3_x1_t_<NV>>;
template <int NV>
using switcher_x1_c2 = parameter::bypass<sb3_x1_t<NV>>;

template <int NV>
using chain4_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader3_x1_t<NV>>, 
                                     smoothed_parameter4_x1_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb4_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain4_x1_t<NV>>>;

template <int NV>
using sb4_x1_t = bypass::smoothed<20, sb4_x1_t_<NV>>;
template <int NV>
using switcher_x1_c3 = parameter::bypass<sb4_x1_t<NV>>;

template <int NV>
using chain5_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader4_x1_t<NV>>, 
                                     smoothed_parameter3_x1_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb5_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain5_x1_t<NV>>>;

template <int NV>
using sb5_x1_t = bypass::smoothed<20, sb5_x1_t_<NV>>;
template <int NV>
using switcher_x1_c4 = parameter::bypass<sb5_x1_t<NV>>;

template <int NV>
using switcher_x1_multimod = parameter::list<switcher_x1_c0<NV>, 
                                             switcher_x1_c1<NV>, 
                                             switcher_x1_c2<NV>, 
                                             switcher_x1_c3<NV>, 
                                             switcher_x1_c4<NV>>;

template <int NV>
using switcher_x1_t = control::xfader<switcher_x1_multimod<NV>, 
                                      faders::switcher>;

template <int NV>
using sb_container_x1_t = container::chain<parameter::empty, 
                                           wrap::fix<2, sb1_x1_t<NV>>, 
                                           sb2_x1_t<NV>, 
                                           sb3_x1_t<NV>, 
                                           sb4_x1_t<NV>, 
                                           sb5_x1_t<NV>>;

template <int NV>
using x1_t = container::chain<parameter::empty, 
                              wrap::fix<2, switcher_x1_t<NV>>, 
                              sb_container_x1_t<NV>>;

namespace XF1_t_parameters
{
// Parameter list for xfade5_impl::XF1_t -----------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(smooth_x1_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_STEP(smooth_x1_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth_x1_0 = parameter::from0To1<xfade5_impl::smoothed_parameter_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_1 = parameter::from0To1<xfade5_impl::smoothed_parameter1_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_2 = parameter::from0To1<xfade5_impl::smoothed_parameter2_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_3 = parameter::from0To1<xfade5_impl::smoothed_parameter4_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_4 = parameter::from0To1<xfade5_impl::smoothed_parameter3_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1 = parameter::chain<smooth_x1_InputRange, 
                                   smooth_x1_0<NV>, 
                                   smooth_x1_1<NV>, 
                                   smooth_x1_2<NV>, 
                                   smooth_x1_3<NV>, 
                                   smooth_x1_4<NV>>;

template <int NV>
using mode_x1 = parameter::plain<xfade5_impl::x1_t<NV>, 0>;
template <int NV>
using XF1_t_plist = parameter::list<smooth_x1<NV>, mode_x1<NV>>;
}

template <int NV>
using XF1_t = container::chain<XF1_t_parameters::XF1_t_plist<NV>, 
                               wrap::fix<2, x1_t<NV>>>;

namespace xfade5_t_parameters
{
// Parameter list for xfade5_impl::xfade5_t --------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW_INV(one_1Range, 
                                 0., 
                                 1., 
                                 2.24492);

template <int NV>
using one_1 = parameter::from0To1_inv<xfade5_impl::input_toggle_t<NV>, 
                                      0, 
                                      one_1Range>;

template <int NV>
using one = parameter::chain<ranges::Identity, 
                             parameter::plain<xfade5_impl::ramp_t<NV>, 1>, 
                             one_1<NV>>;

DECLARE_PARAMETER_RANGE(modsel_InputRange, 
                        0., 
                        4.);

template <int NV>
using modsel = parameter::chain<modsel_InputRange, 
                                parameter::plain<xfade5_impl::cable_table1_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(lfomode_InputRange, 
                             0., 
                             3., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(lfomode_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using lfomode_0 = parameter::from0To1<xfade5_impl::branch1_t<NV>, 
                                      0, 
                                      lfomode_0Range>;

template <int NV>
using lfomode = parameter::chain<lfomode_InputRange, lfomode_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(XfModSrc_InputRange, 
                             0., 
                             3., 
                             0.1);

template <int NV>
using XfModSrc = parameter::chain<XfModSrc_InputRange, 
                                  parameter::plain<xfade5_impl::branch_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(XfModer_InputRange, 
                             0., 
                             5., 
                             0.1);

template <int NV>
using XfModer = parameter::chain<XfModer_InputRange, 
                                 parameter::plain<xfade5_impl::switcher_x1_t<NV>, 0>>;

template <int NV>
using attack1 = parameter::plain<xfade5_impl::ahdsr3_t<NV>, 
                                 0>;
template <int NV>
using decay1 = parameter::plain<xfade5_impl::ahdsr3_t<NV>, 
                                3>;
template <int NV>
using sus1 = parameter::plain<xfade5_impl::ahdsr3_t<NV>, 
                              4>;
template <int NV>
using rel1 = parameter::plain<xfade5_impl::ahdsr3_t<NV>, 
                              5>;
template <int NV>
using tempo = parameter::plain<xfade5_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using mul = parameter::plain<xfade5_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using tempo2 = parameter::plain<xfade5_impl::tempo_sync_t<NV>, 
                                3>;
using Step1 = parameter::plain<xfade5_impl::pack8_writer_t, 
                               0>;
using Step2 = parameter::plain<xfade5_impl::pack8_writer_t, 
                               1>;
using Step3 = parameter::plain<xfade5_impl::pack8_writer_t, 
                               2>;
using Step4 = parameter::plain<xfade5_impl::pack8_writer_t, 
                               3>;
using Step5 = parameter::plain<xfade5_impl::pack8_writer_t, 
                               4>;
using Step6 = parameter::plain<xfade5_impl::pack8_writer_t, 
                               5>;
using Step7 = parameter::plain<xfade5_impl::pack8_writer_t, 
                               6>;
using Step8 = parameter::plain<xfade5_impl::pack8_writer_t, 
                               7>;
using Gate1 = parameter::plain<xfade5_impl::pack8_writer2_t, 
                               0>;
using Gate2 = parameter::plain<xfade5_impl::pack8_writer2_t, 
                               2>;
using Gate3 = parameter::plain<xfade5_impl::pack8_writer2_t, 
                               4>;
using Gate4 = parameter::plain<xfade5_impl::pack8_writer2_t, 
                               6>;
using Gate5 = parameter::plain<xfade5_impl::pack8_writer5_t, 
                               0>;
using Gate6 = parameter::plain<xfade5_impl::pack8_writer5_t, 
                               2>;
using Gate7 = parameter::plain<xfade5_impl::pack8_writer5_t, 
                               4>;
using Gate8 = parameter::plain<xfade5_impl::pack8_writer5_t, 
                               6>;
template <int NV>
using A = parameter::plain<xfade5_impl::simple_ar_t<NV>, 
                           0>;
template <int NV>
using H = parameter::plain<xfade5_impl::simple_ar_t<NV>, 
                           3>;
template <int NV>
using sync = parameter::plain<xfade5_impl::tempo_sync_t<NV>, 
                              2>;
template <int NV>
using R = parameter::plain<xfade5_impl::simple_ar_t<NV>, 
                           1>;
template <int NV>
using XF = parameter::plain<xfade5_impl::pma_t<NV>, 2>;
template <int NV>
using XFsmooth = parameter::plain<xfade5_impl::XF1_t<NV>, 0>;
template <int NV>
using XfMod = parameter::plain<xfade5_impl::pma_t<NV>, 1>;
template <int NV>
using vel = parameter::plain<xfade5_impl::pma1_t<NV>, 
                             1>;
template <int NV>
using trk = parameter::plain<xfade5_impl::pma2_t<NV>, 
                             1>;
template <int NV>
using mw = parameter::plain<xfade5_impl::pma3_t<NV>, 
                            1>;
template <int NV>
using aft = parameter::plain<xfade5_impl::pma4_t<NV>, 
                             1>;
template <int NV>
using xfade5_t_plist = parameter::list<attack1<NV>, 
                                       decay1<NV>, 
                                       sus1<NV>, 
                                       rel1<NV>, 
                                       tempo<NV>, 
                                       mul<NV>, 
                                       one<NV>, 
                                       modsel<NV>, 
                                       lfomode<NV>, 
                                       tempo2<NV>, 
                                       Step1, 
                                       Step2, 
                                       Step3, 
                                       Step4, 
                                       Step5, 
                                       Step6, 
                                       Step7, 
                                       Step8, 
                                       Gate1, 
                                       Gate2, 
                                       Gate3, 
                                       Gate4, 
                                       Gate5, 
                                       Gate6, 
                                       Gate7, 
                                       Gate8, 
                                       A<NV>, 
                                       H<NV>, 
                                       sync<NV>, 
                                       R<NV>, 
                                       XF<NV>, 
                                       XFsmooth<NV>, 
                                       XfMod<NV>, 
                                       XfModSrc<NV>, 
                                       vel<NV>, 
                                       trk<NV>, 
                                       mw<NV>, 
                                       aft<NV>, 
                                       XfModer<NV>>;
}

template <int NV>
using xfade5_t_ = container::chain<xfade5_t_parameters::xfade5_t_plist<NV>, 
                                   wrap::fix<2, modchain_t<NV>>, 
                                   pma_t<NV>, 
                                   XF1_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xfade5_impl::xfade5_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 4;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(xfade5);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(598)
		{
			0x005B, 0x0000, 0x6100, 0x7474, 0x6361, 0x316B, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0x0000, 0x7200, 0x4A6A, 0xCD3E, 0xCCCC, 
            0x5B3D, 0x0001, 0x0000, 0x6564, 0x6163, 0x3179, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0x0000, 0x7200, 0x4A6A, 0xCD3E, 0xCCCC, 
            0x5B3D, 0x0002, 0x0000, 0x7573, 0x3173, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0003, 0x0000, 0x6572, 0x316C, 0x0000, 0x0000, 0x0000, 0x1C40, 
            0x0046, 0x1C40, 0x7246, 0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x0004, 
            0x0000, 0x6574, 0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 0x4190, 
            0x0000, 0x4188, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x055B, 0x0000, 
            0x6D00, 0x6C75, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x7000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0006, 0x0000, 0x6E6F, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x6D00, 0x646F, 0x6573, 
            0x006C, 0x0000, 0x0000, 0x0000, 0x4080, 0x2C79, 0x3FBD, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 0x6C00, 0x6F66, 0x6F6D, 
            0x6564, 0x0000, 0x0000, 0x0000, 0x4000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0009, 0x0000, 0x6574, 0x706D, 
            0x326F, 0x0000, 0x0000, 0x0000, 0xC350, 0xA447, 0x0FF0, 0x003F, 
            0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x000A, 0x0000, 0x7453, 0x7065, 
            0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 0xDF3B, 0x3EB5, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0B5B, 0x0000, 0x5300, 0x6574, 0x3270, 
            0x0000, 0x0000, 0x0000, 0x8000, 0xA03F, 0xA91A, 0x003E, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000C, 0x0000, 0x7453, 0x7065, 0x0033, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x353F, 0x3E68, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0D5B, 0x0000, 0x5300, 0x6574, 0x3470, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000E, 0x0000, 0x7453, 0x7065, 0x0035, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0C4A, 0x3F0C, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0F5B, 0x0000, 0x5300, 0x6574, 0x3670, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0010, 0x0000, 0x7453, 0x7065, 0x0037, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0E56, 0x3F01, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x115B, 0x0000, 0x5300, 0x6574, 0x3870, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0012, 0x0000, 0x6147, 0x6574, 0x0031, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x135B, 
            0x0000, 0x4700, 0x7461, 0x3265, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0014, 
            0x0000, 0x6147, 0x6574, 0x0033, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x155B, 0x0000, 
            0x4700, 0x7461, 0x3465, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0016, 0x0000, 
            0x6147, 0x6574, 0x0035, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x175B, 0x0000, 0x4700, 
            0x7461, 0x3665, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0018, 0x0000, 0x6147, 
            0x6574, 0x0037, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x195B, 0x0000, 0x4700, 0x7461, 
            0x3865, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x001A, 0x0000, 0x0041, 0x0000, 
            0x0000, 0x4000, 0x469C, 0x81CD, 0x4698, 0x209B, 0x3E9A, 0xCCCD, 
            0x3DCC, 0x1B5B, 0x0000, 0x4800, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001C, 
            0x0000, 0x7973, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x1C40, 0x0046, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001D, 0x0000, 
            0x0052, 0x0000, 0x0000, 0x4000, 0x469C, 0xF000, 0x449C, 0x209B, 
            0x3E9A, 0xCCCD, 0x3DCC, 0x1E5B, 0x0000, 0x5800, 0x0046, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x1F5B, 0x0000, 0x5800, 0x7346, 0x6F6D, 0x746F, 0x0068, 
            0x0000, 0x0000, 0x0000, 0x447A, 0x6667, 0x422C, 0x209B, 0x3E9A, 
            0xCCCD, 0x3DCC, 0x205B, 0x0000, 0x5800, 0x4D66, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x683F, 0x9C31, 0x00BD, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0021, 0x0000, 0x6658, 0x6F4D, 0x5364, 0x6372, 
            0x0000, 0x0000, 0x0000, 0x4000, 0x0040, 0x0000, 0x0000, 0x8000, 
            0xCD3F, 0xCCCC, 0x5B3D, 0x0022, 0x0000, 0x6576, 0x006C, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x235B, 0x0000, 0x7400, 0x6B72, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0024, 0x0000, 0x776D, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0025, 0x0000, 
            0x6661, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x265B, 0x0000, 0x5800, 0x4D66, 
            0x646F, 0x7265, 0x0000, 0x0000, 0x0000, 0xA000, 0x0040, 0x0000, 
            0x0000, 0x8000, 0xCD3F, 0xCCCC, 0x003D, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                       // xfade5_impl::modchain_t<NV>
		auto& split = this->getT(0).getT(0);                                                  // xfade5_impl::split_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0);                                         // xfade5_impl::branch_t<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(0);                                 // xfade5_impl::chain8_t<NV>
		auto& clear = this->getT(0).getT(0).getT(0).getT(0).getT(0);                          // math::clear<NV>
		auto& no_midi = this->getT(0).getT(0).getT(0).getT(0).getT(1);                        // xfade5_impl::no_midi_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);             // xfade5_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);                   // xfade5_impl::ramp_t<NV>
		auto& clear6 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                         // math::clear<NV>
		auto& softbypass_switch6 = this->getT(0).getT(0).getT(0).getT(0).getT(3);             // xfade5_impl::softbypass_switch6_t<NV>
		auto& cable_table1 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0);           // xfade5_impl::cable_table1_t<NV>
		auto& switcher = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(1);               // xfade5_impl::switcher_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(2);                 // math::clear<NV>
		auto& sb_container = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(3);           // xfade5_impl::sb_container_t<NV>
		auto& sb1 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(3).getT(0);            // xfade5_impl::sb1_t<NV>
		auto& minmax = this->getT(0).getT(0).getT(0).getT(0).                                 // xfade5_impl::minmax_t<NV>
                       getT(3).getT(3).getT(0).getT(0);
		auto& clear5 = this->getT(0).getT(0).getT(0).getT(0).                                 // math::clear<NV>
                       getT(3).getT(3).getT(0).getT(1);
		auto& input_toggle = this->getT(0).getT(0).getT(0).getT(0).                           // xfade5_impl::input_toggle_t<NV>
                             getT(3).getT(3).getT(0).getT(2);
		auto& ahdsr3 = this->getT(0).getT(0).getT(0).getT(0).                                 // xfade5_impl::ahdsr3_t<NV>
                       getT(3).getT(3).getT(0).getT(3);
		auto& add12 = this->getT(0).getT(0).getT(0).getT(0).                                  // math::add<NV>
                      getT(3).getT(3).getT(0).getT(4);
		auto& sb2 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(3).getT(1);            // xfade5_impl::sb2_t<NV>
		auto& ramp1 = this->getT(0).getT(0).getT(0).getT(0).                                  // xfade5_impl::ramp1_t<NV>
                      getT(3).getT(3).getT(1).getT(0);
		auto& branch1 = this->getT(0).getT(0).getT(0).getT(0).                                // xfade5_impl::branch1_t<NV>
                        getT(3).getT(3).getT(1).getT(1);
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(0).                                 // xfade5_impl::chain1_t<NV>
                       getT(3).getT(3).getT(1).getT(1).
                       getT(0);
		auto& pi = this->getT(0).getT(0).getT(0).getT(0).getT(3).                             // math::pi<NV>
                   getT(3).getT(1).getT(1).getT(0).getT(0);
		auto& sin1 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                           // math::sin<NV>
                     getT(3).getT(1).getT(1).getT(0).getT(1);
		auto& sig2mod = this->getT(0).getT(0).getT(0).getT(0).getT(3).                        // math::sig2mod<NV>
                        getT(3).getT(1).getT(1).getT(0).getT(2);
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(0).                                 // xfade5_impl::chain3_t<NV>
                       getT(3).getT(3).getT(1).getT(1).
                       getT(1);
		auto& pi2 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                            // math::pi<NV>
                    getT(3).getT(1).getT(1).getT(1).getT(0);
		auto& square1 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                        // math::square<NV>
                        getT(3).getT(1).getT(1).getT(1).getT(1);
		auto& sig2mod2 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                       // wrap::no_process<math::sig2mod<NV>>
                         getT(3).getT(1).getT(1).getT(1).getT(2);
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(0).                                 // xfade5_impl::chain2_t<NV>
                       getT(3).getT(3).getT(1).getT(1).
                       getT(2);
		auto& sin2 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                           // wrap::no_process<math::sin<NV>>
                     getT(3).getT(1).getT(1).getT(2).getT(0);
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(0).                                // xfade5_impl::chain10_t<NV>
                        getT(3).getT(3).getT(1).getT(1).
                        getT(3);
		auto& clear7 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                         // wrap::no_process<math::clear<NV>>
                       getT(3).getT(1).getT(1).getT(3).getT(0);
		auto& oscillator = this->getT(0).getT(0).getT(0).getT(0).getT(3).                     // xfade5_impl::oscillator_t<NV>
                           getT(3).getT(1).getT(1).getT(3).getT(1);
		auto& sampleandhold = this->getT(0).getT(0).getT(0).getT(0).getT(3).                  // fx::sampleandhold<NV>
                              getT(3).getT(1).getT(1).getT(3).getT(2);
		auto& sig2mod1 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                       // wrap::no_process<math::sig2mod<NV>>
                         getT(3).getT(1).getT(1).getT(3).getT(3);
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).                                   // xfade5_impl::peak_t<NV>
                     getT(3).getT(3).getT(1).getT(2);
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).                                   // math::add<NV>
                     getT(3).getT(3).getT(1).getT(3);
		auto& sb6 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(3).getT(2);            // xfade5_impl::sb6_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0).getT(0).                                 // xfade5_impl::split2_t<NV>
                       getT(3).getT(3).getT(2).getT(0);
		auto& chain = this->getT(0).getT(0).getT(0).getT(0).                                  // xfade5_impl::chain_t<NV>
                      getT(3).getT(3).getT(2).getT(0).
                      getT(0);
		auto& pack8_writer = this->getT(0).getT(0).getT(0).getT(0).getT(3).                   // xfade5_impl::pack8_writer_t
                             getT(3).getT(2).getT(0).getT(0).getT(0);
		auto& cable_table8 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                   // xfade5_impl::cable_table8_t
                             getT(3).getT(2).getT(0).getT(0).getT(1);
		auto& clear4 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                         // math::clear<NV>
                       getT(3).getT(2).getT(0).getT(0).getT(2);
		auto& cable_pack = this->getT(0).getT(0).getT(0).getT(0).getT(3).                     // xfade5_impl::cable_pack_t<NV>
                           getT(3).getT(2).getT(0).getT(0).getT(3);
		auto& add8 = this->getT(0).getT(0).getT(0).getT(0).                                   // math::add<NV>
                     getT(3).getT(3).getT(2).getT(1);
		auto& soft_bypass = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(3).getT(3);    // xfade5_impl::soft_bypass_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(0).getT(0).                                 // xfade5_impl::split6_t<NV>
                       getT(3).getT(3).getT(3).getT(0);
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(0).                                 // xfade5_impl::chain7_t<NV>
                       getT(3).getT(3).getT(3).getT(0).
                       getT(0);
		auto& cable_table4 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                   // xfade5_impl::cable_table4_t<NV>
                             getT(3).getT(3).getT(0).getT(0).getT(0);
		auto& pack8_writer2 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                  // xfade5_impl::pack8_writer2_t
                              getT(3).getT(3).getT(0).getT(0).getT(1);
		auto& cable_table2 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                   // xfade5_impl::cable_table2_t
                             getT(3).getT(3).getT(0).getT(0).getT(2);
		auto& cable_pack3 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                    // xfade5_impl::cable_pack3_t<NV>
                            getT(3).getT(3).getT(0).getT(0).getT(3);
		auto& add7 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                           // math::add<NV>
                     getT(3).getT(3).getT(0).getT(0).getT(4);
		auto& chain11 = this->getT(0).getT(0).getT(0).getT(0).                                // xfade5_impl::chain11_t<NV>
                        getT(3).getT(3).getT(3).getT(0).
                        getT(1);
		auto& cable_table7 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                   // xfade5_impl::cable_table7_t<NV>
                             getT(3).getT(3).getT(0).getT(1).getT(0);
		auto& pack8_writer5 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                  // xfade5_impl::pack8_writer5_t
                              getT(3).getT(3).getT(0).getT(1).getT(1);
		auto& cable_table3 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                   // xfade5_impl::cable_table3_t
                             getT(3).getT(3).getT(0).getT(1).getT(2);
		auto& cable_pack6 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                    // xfade5_impl::cable_pack6_t<NV>
                            getT(3).getT(3).getT(0).getT(1).getT(3);
		auto& add10 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                          // math::add<NV>
                      getT(3).getT(3).getT(0).getT(1).getT(4);
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(0).                                  // xfade5_impl::peak2_t<NV>
                      getT(3).getT(3).getT(3).getT(1);
		auto& clear2 = this->getT(0).getT(0).getT(0).getT(0).                                 // math::clear<NV>
                       getT(3).getT(3).getT(3).getT(2);
		auto& no_midi1 = this->getT(0).getT(0).getT(0).getT(0).                               // xfade5_impl::no_midi1_t<NV>
                         getT(3).getT(3).getT(3).getT(3);
		auto& simple_ar = this->getT(0).getT(0).getT(0).getT(0).                              // xfade5_impl::simple_ar_t<NV>
                          getT(3).getT(3).getT(3).getT(3).
                          getT(0);
		auto& add13 = this->getT(0).getT(0).getT(0).getT(0).                                  // math::add<NV>
                      getT(3).getT(3).getT(3).getT(3).
                      getT(1);
		auto& split1 = this->getT(0).getT(0).getT(1);                                         // xfade5_impl::split1_t<NV>
		auto& chain4 = this->getT(0).getT(0).getT(1).getT(0);                                 // xfade5_impl::chain4_t<NV>
		auto& midi = this->getT(0).getT(0).getT(1).getT(0).getT(0);                           // xfade5_impl::midi_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                           // xfade5_impl::pma1_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                           // math::add<NV>
		auto& chain5 = this->getT(0).getT(0).getT(1).getT(1);                                 // xfade5_impl::chain5_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                          // xfade5_impl::midi1_t<NV>
		auto& pma2 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                           // xfade5_impl::pma2_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                           // math::add<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(2);                                 // xfade5_impl::chain6_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(1).getT(2).getT(0);                        // xfade5_impl::midi_cc_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                           // xfade5_impl::pma3_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(1).getT(2).getT(2);                           // math::add<NV>
		auto& chain9 = this->getT(0).getT(0).getT(1).getT(3);                                 // xfade5_impl::chain9_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                       // xfade5_impl::midi_cc1_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                           // xfade5_impl::pma4_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(1).getT(3).getT(2);                           // math::add<NV>
		auto& peak1 = this->getT(0).getT(1);                                                  // xfade5_impl::peak1_t<NV>
		auto& pma = this->getT(1);                                                            // xfade5_impl::pma_t<NV>
		auto& XF1 = this->getT(2);                                                            // xfade5_impl::XF1_t<NV>
		auto& x1 = this->getT(2).getT(0);                                                     // xfade5_impl::x1_t<NV>
		auto& switcher_x1 = this->getT(2).getT(0).getT(0);                                    // xfade5_impl::switcher_x1_t<NV>
		auto& sb_container_x1 = this->getT(2).getT(0).getT(1);                                // xfade5_impl::sb_container_x1_t<NV>
		auto& sb1_x1 = this->getT(2).getT(0).getT(1).getT(0);                                 // xfade5_impl::sb1_x1_t<NV>
		auto& chain1_x1 = this->getT(2).getT(0).getT(1).getT(0).getT(0);                      // xfade5_impl::chain1_x1_t<NV>
		auto& xfader_x1 = this->getT(2).getT(0).getT(1).getT(0).getT(0).getT(0);              // xfade5_impl::xfader_x1_t<NV>
		auto& smoothed_parameter_x1 = this->getT(2).getT(0).getT(1).getT(0).getT(0).getT(1);  // xfade5_impl::smoothed_parameter_x1_t<NV>
		auto& gain = this->getT(2).getT(0).getT(1).getT(0).getT(0).getT(2);                   // core::gain<NV>
		auto& sb2_x1 = this->getT(2).getT(0).getT(1).getT(1);                                 // xfade5_impl::sb2_x1_t<NV>
		auto& chain3_x1_x1 = this->getT(2).getT(0).getT(1).getT(1).getT(0);                   // xfade5_impl::chain3_x1_x1_t<NV>
		auto& xfader2_x1 = this->getT(2).getT(0).getT(1).getT(1).getT(0).getT(0);             // xfade5_impl::xfader2_x1_t<NV>
		auto& smoothed_parameter1_x1 = this->getT(2).getT(0).getT(1).getT(1).getT(0).getT(1); // xfade5_impl::smoothed_parameter1_x1_t<NV>
		auto& gain1 = this->getT(2).getT(0).getT(1).getT(1).getT(0).getT(2);                  // core::gain<NV>
		auto& sb3_x1 = this->getT(2).getT(0).getT(1).getT(2);                                 // xfade5_impl::sb3_x1_t<NV>
		auto& chain2_x1 = this->getT(2).getT(0).getT(1).getT(2).getT(0);                      // xfade5_impl::chain2_x1_t<NV>
		auto& xfader1_x1 = this->getT(2).getT(0).getT(1).getT(2).getT(0).getT(0);             // xfade5_impl::xfader1_x1_t<NV>
		auto& smoothed_parameter2_x1 = this->getT(2).getT(0).getT(1).getT(2).getT(0).getT(1); // xfade5_impl::smoothed_parameter2_x1_t<NV>
		auto& gain2 = this->getT(2).getT(0).getT(1).getT(2).getT(0).getT(2);                  // core::gain<NV>
		auto& sb4_x1 = this->getT(2).getT(0).getT(1).getT(3);                                 // xfade5_impl::sb4_x1_t<NV>
		auto& chain4_x1 = this->getT(2).getT(0).getT(1).getT(3).getT(0);                      // xfade5_impl::chain4_x1_t<NV>
		auto& xfader3_x1 = this->getT(2).getT(0).getT(1).getT(3).getT(0).getT(0);             // xfade5_impl::xfader3_x1_t<NV>
		auto& smoothed_parameter4_x1 = this->getT(2).getT(0).getT(1).getT(3).getT(0).getT(1); // xfade5_impl::smoothed_parameter4_x1_t<NV>
		auto& gain3 = this->getT(2).getT(0).getT(1).getT(3).getT(0).getT(2);                  // core::gain<NV>
		auto& sb5_x1 = this->getT(2).getT(0).getT(1).getT(4);                                 // xfade5_impl::sb5_x1_t<NV>
		auto& chain5_x1 = this->getT(2).getT(0).getT(1).getT(4).getT(0);                      // xfade5_impl::chain5_x1_t<NV>
		auto& xfader4_x1 = this->getT(2).getT(0).getT(1).getT(4).getT(0).getT(0);             // xfade5_impl::xfader4_x1_t<NV>
		auto& smoothed_parameter3_x1 = this->getT(2).getT(0).getT(1).getT(4).getT(0).getT(1); // xfade5_impl::smoothed_parameter3_x1_t<NV>
		auto& gain4 = this->getT(2).getT(0).getT(1).getT(4).getT(0).getT(2);                  // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& smooth_x1_p = XF1.getParameterT(0);
		smooth_x1_p.connectT(0, smoothed_parameter_x1);  // smooth_x1 -> smoothed_parameter_x1::SmoothingTime
		smooth_x1_p.connectT(1, smoothed_parameter1_x1); // smooth_x1 -> smoothed_parameter1_x1::SmoothingTime
		smooth_x1_p.connectT(2, smoothed_parameter2_x1); // smooth_x1 -> smoothed_parameter2_x1::SmoothingTime
		smooth_x1_p.connectT(3, smoothed_parameter4_x1); // smooth_x1 -> smoothed_parameter4_x1::SmoothingTime
		smooth_x1_p.connectT(4, smoothed_parameter3_x1); // smooth_x1 -> smoothed_parameter3_x1::SmoothingTime
		
		XF1.getParameterT(1).connectT(0, x1);       // mode_x1 -> x1::Switch
		this->getParameterT(0).connectT(0, ahdsr3); // attack1 -> ahdsr3::Attack
		
		this->getParameterT(1).connectT(0, ahdsr3); // decay1 -> ahdsr3::Decay
		
		this->getParameterT(2).connectT(0, ahdsr3); // sus1 -> ahdsr3::Sustain
		
		this->getParameterT(3).connectT(0, ahdsr3); // rel1 -> ahdsr3::Release
		
		this->getParameterT(4).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(5).connectT(0, tempo_sync); // mul -> tempo_sync::Multiplier
		
		auto& one_p = this->getParameterT(6);
		one_p.connectT(0, ramp);         // one -> ramp::LoopStart
		one_p.connectT(1, input_toggle); // one -> input_toggle::Input
		
		this->getParameterT(7).connectT(0, cable_table1); // modsel -> cable_table1::Value
		
		this->getParameterT(8).connectT(0, branch1); // lfomode -> branch1::Index
		
		this->getParameterT(9).connectT(0, tempo_sync); // tempo2 -> tempo_sync::UnsyncedTime
		
		this->getParameterT(10).connectT(0, pack8_writer); // Step1 -> pack8_writer::Value1
		
		this->getParameterT(11).connectT(0, pack8_writer); // Step2 -> pack8_writer::Value2
		
		this->getParameterT(12).connectT(0, pack8_writer); // Step3 -> pack8_writer::Value3
		
		this->getParameterT(13).connectT(0, pack8_writer); // Step4 -> pack8_writer::Value4
		
		this->getParameterT(14).connectT(0, pack8_writer); // Step5 -> pack8_writer::Value5
		
		this->getParameterT(15).connectT(0, pack8_writer); // Step6 -> pack8_writer::Value6
		
		this->getParameterT(16).connectT(0, pack8_writer); // Step7 -> pack8_writer::Value7
		
		this->getParameterT(17).connectT(0, pack8_writer); // Step8 -> pack8_writer::Value8
		
		this->getParameterT(18).connectT(0, pack8_writer2); // Gate1 -> pack8_writer2::Value1
		
		this->getParameterT(19).connectT(0, pack8_writer2); // Gate2 -> pack8_writer2::Value3
		
		this->getParameterT(20).connectT(0, pack8_writer2); // Gate3 -> pack8_writer2::Value5
		
		this->getParameterT(21).connectT(0, pack8_writer2); // Gate4 -> pack8_writer2::Value7
		
		this->getParameterT(22).connectT(0, pack8_writer5); // Gate5 -> pack8_writer5::Value1
		
		this->getParameterT(23).connectT(0, pack8_writer5); // Gate6 -> pack8_writer5::Value3
		
		this->getParameterT(24).connectT(0, pack8_writer5); // Gate7 -> pack8_writer5::Value5
		
		this->getParameterT(25).connectT(0, pack8_writer5); // Gate8 -> pack8_writer5::Value7
		
		this->getParameterT(26).connectT(0, simple_ar); // A -> simple_ar::Attack
		
		this->getParameterT(27).connectT(0, simple_ar); // H -> simple_ar::AttackCurve
		
		this->getParameterT(28).connectT(0, tempo_sync); // sync -> tempo_sync::Enabled
		
		this->getParameterT(29).connectT(0, simple_ar); // R -> simple_ar::Release
		
		this->getParameterT(30).connectT(0, pma); // XF -> pma::Add
		
		this->getParameterT(31).connectT(0, XF1); // XFsmooth -> XF1::smooth_x1
		
		this->getParameterT(32).connectT(0, pma); // XfMod -> pma::Multiply
		
		this->getParameterT(33).connectT(0, branch); // XfModSrc -> branch::Index
		
		this->getParameterT(34).connectT(0, pma1); // vel -> pma1::Multiply
		
		this->getParameterT(35).connectT(0, pma2); // trk -> pma2::Multiply
		
		this->getParameterT(36).connectT(0, pma3); // mw -> pma3::Multiply
		
		this->getParameterT(37).connectT(0, pma4); // aft -> pma4::Multiply
		
		this->getParameterT(38).connectT(0, switcher_x1); // XfModer -> switcher_x1::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& ahdsr3_p = ahdsr3.getWrappedObject().getParameter();
		ahdsr3_p.getParameterT(0).connectT(0, add12);                             // ahdsr3 -> add12::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, ahdsr3);       // input_toggle -> ahdsr3::Gate
		minmax.getWrappedObject().getParameter().connectT(0, input_toggle);       // minmax -> input_toggle::Value2
		cable_pack3.getWrappedObject().getParameter().connectT(0, add7);          // cable_pack3 -> add7::Value
		cable_table4.getWrappedObject().getParameter().connectT(0, cable_pack3);  // cable_table4 -> cable_pack3::Value
		cable_table4.getWrappedObject().getParameter().connectT(1, cable_table2); // cable_table4 -> cable_table2::Value
		cable_pack6.getWrappedObject().getParameter().connectT(0, add10);         // cable_pack6 -> add10::Value
		cable_table7.getWrappedObject().getParameter().connectT(0, cable_pack6);  // cable_table7 -> cable_pack6::Value
		cable_table7.getWrappedObject().getParameter().connectT(1, cable_table3); // cable_table7 -> cable_table3::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add8);           // cable_pack -> add8::Value
		ramp.getParameter().connectT(0, minmax);                                  // ramp -> minmax::Value
		ramp.getParameter().connectT(1, cable_table4);                            // ramp -> cable_table4::Value
		ramp.getParameter().connectT(2, cable_table7);                            // ramp -> cable_table7::Value
		ramp.getParameter().connectT(3, cable_pack);                              // ramp -> cable_pack::Value
		ramp.getParameter().connectT(4, cable_table8);                            // ramp -> cable_table8::Value
		tempo_sync.getParameter().connectT(0, ramp);                              // tempo_sync -> ramp::PeriodTime
		tempo_sync.getParameter().connectT(1, ramp1);                             // tempo_sync -> ramp1::PeriodTime
		tempo_sync.getParameter().connectT(2, sampleandhold);                     // tempo_sync -> sampleandhold::Counter
		peak.getParameter().connectT(0, add1);                                    // peak -> add1::Value
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(0).connectT(0, add13); // simple_ar -> add13::Value
		peak2.getParameter().connectT(0, simple_ar);     // peak2 -> simple_ar::Gate
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1);                         // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2);                         // switcher -> sb2::Bypassed
		switcher_p.getParameterT(2).connectT(0, sb6);                         // switcher -> sb6::Bypassed
		switcher_p.getParameterT(3).connectT(0, soft_bypass);                 // switcher -> soft_bypass::Bypassed
		cable_table1.getWrappedObject().getParameter().connectT(0, switcher); // cable_table1 -> switcher::Value
		pma1.getWrappedObject().getParameter().connectT(0, add4);             // pma1 -> add4::Value
		midi.getParameter().connectT(0, pma1);                                // midi -> pma1::Value
		pma2.getWrappedObject().getParameter().connectT(0, add5);             // pma2 -> add5::Value
		midi1.getParameter().connectT(0, pma2);                               // midi1 -> pma2::Value
		pma3.getWrappedObject().getParameter().connectT(0, add6);             // pma3 -> add6::Value
		midi_cc.getWrappedObject().getParameter().connectT(0, pma3);          // midi_cc -> pma3::Value
		pma4.getWrappedObject().getParameter().connectT(0, add9);             // pma4 -> add9::Value
		midi_cc1.getWrappedObject().getParameter().connectT(0, pma4);         // midi_cc1 -> pma4::Value
		smoothed_parameter_x1.getParameter().connectT(0, gain);               // smoothed_parameter_x1 -> gain::Gain
		auto& xfader_x1_p = xfader_x1.getWrappedObject().getParameter();
		xfader_x1_p.getParameterT(4).connectT(0, smoothed_parameter_x1); // xfader_x1 -> smoothed_parameter_x1::Value
		smoothed_parameter1_x1.getParameter().connectT(0, gain1);        // smoothed_parameter1_x1 -> gain1::Gain
		auto& xfader2_x1_p = xfader2_x1.getWrappedObject().getParameter();
		xfader2_x1_p.getParameterT(4).connectT(0, smoothed_parameter1_x1); // xfader2_x1 -> smoothed_parameter1_x1::Value
		smoothed_parameter2_x1.getParameter().connectT(0, gain2);          // smoothed_parameter2_x1 -> gain2::Gain
		auto& xfader1_x1_p = xfader1_x1.getWrappedObject().getParameter();
		xfader1_x1_p.getParameterT(4).connectT(0, smoothed_parameter2_x1); // xfader1_x1 -> smoothed_parameter2_x1::Value
		smoothed_parameter4_x1.getParameter().connectT(0, gain3);          // smoothed_parameter4_x1 -> gain3::Gain
		auto& xfader3_x1_p = xfader3_x1.getWrappedObject().getParameter();
		xfader3_x1_p.getParameterT(4).connectT(0, smoothed_parameter4_x1); // xfader3_x1 -> smoothed_parameter4_x1::Value
		smoothed_parameter3_x1.getParameter().connectT(0, gain4);          // smoothed_parameter3_x1 -> gain4::Gain
		auto& xfader4_x1_p = xfader4_x1.getWrappedObject().getParameter();
		xfader4_x1_p.getParameterT(4).connectT(0, smoothed_parameter3_x1); // xfader4_x1 -> smoothed_parameter3_x1::Value
		pma.getWrappedObject().getParameter().connectT(0, xfader_x1);      // pma -> xfader_x1::Value
		pma.getWrappedObject().getParameter().connectT(1, xfader2_x1);     // pma -> xfader2_x1::Value
		pma.getWrappedObject().getParameter().connectT(2, xfader1_x1);     // pma -> xfader1_x1::Value
		pma.getWrappedObject().getParameter().connectT(3, xfader3_x1);     // pma -> xfader3_x1::Value
		pma.getWrappedObject().getParameter().connectT(4, xfader4_x1);     // pma -> xfader4_x1::Value
		peak1.getParameter().connectT(0, pma);                             // peak1 -> pma::Value
		auto& switcher_x1_p = switcher_x1.getWrappedObject().getParameter();
		switcher_x1_p.getParameterT(0).connectT(0, sb1_x1); // switcher_x1 -> sb1_x1::Bypassed
		switcher_x1_p.getParameterT(1).connectT(0, sb2_x1); // switcher_x1 -> sb2_x1::Bypassed
		switcher_x1_p.getParameterT(2).connectT(0, sb3_x1); // switcher_x1 -> sb3_x1::Bypassed
		switcher_x1_p.getParameterT(3).connectT(0, sb4_x1); // switcher_x1 -> sb4_x1::Bypassed
		switcher_x1_p.getParameterT(4).connectT(0, sb5_x1); // switcher_x1 -> sb5_x1::Bypassed
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch::Index is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		softbypass_switch6.setParameterT(0, 0.); // container::chain::Switch
		
		; // cable_table1::Value is automated
		
		; // switcher::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		;                                  // minmax::Value is automated
		minmax.setParameterT(1, 0.);       // control::minmax::Minimum
		minmax.setParameterT(2, 1.);       // control::minmax::Maximum
		minmax.setParameterT(3, 0.110638); // control::minmax::Skew
		minmax.setParameterT(4, 1.);       // control::minmax::Step
		minmax.setParameterT(5, 0.);       // control::minmax::Polarity
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                  // input_toggle::Value2 is automated
		
		;                                  // ahdsr3::Attack is automated
		ahdsr3.setParameterT(1, 1.);       // envelope::ahdsr::AttackLevel
		ahdsr3.setParameterT(2, 0.);       // envelope::ahdsr::Hold
		;                                  // ahdsr3::Decay is automated
		;                                  // ahdsr3::Sustain is automated
		;                                  // ahdsr3::Release is automated
		ahdsr3.setParameterT(6, 0.500922); // envelope::ahdsr::AttackCurve
		ahdsr3.setParameterT(7, 0.);       // envelope::ahdsr::Retrigger
		;                                  // ahdsr3::Gate is automated
		
		; // add12::Value is automated
		
		;                           // ramp1::PeriodTime is automated
		ramp1.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp1.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch1::Index is automated
		
		pi.setParameterT(0, 2.); // math::pi::Value
		
		sin1.setParameterT(0, 2.); // math::sin::Value
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		pi2.setParameterT(0, 1.); // math::pi::Value
		
		square1.setParameterT(0, 1.); // math::square::Value
		
		sig2mod2.setParameterT(0, 0.); // math::sig2mod::Value
		
		sin2.setParameterT(0, 2.); // math::sin::Value
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		; // sampleandhold::Counter is automated
		
		sig2mod1.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // add1::Value is automated
		
		; // pack8_writer::Value1 is automated
		; // pack8_writer::Value2 is automated
		; // pack8_writer::Value3 is automated
		; // pack8_writer::Value4 is automated
		; // pack8_writer::Value5 is automated
		; // pack8_writer::Value6 is automated
		; // pack8_writer::Value7 is automated
		; // pack8_writer::Value8 is automated
		
		; // cable_table8::Value is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack::Value is automated
		
		; // add8::Value is automated
		
		; // cable_table4::Value is automated
		
		;                                   // pack8_writer2::Value1 is automated
		pack8_writer2.setParameterT(1, 0.); // control::pack8_writer::Value2
		;                                   // pack8_writer2::Value3 is automated
		pack8_writer2.setParameterT(3, 0.); // control::pack8_writer::Value4
		;                                   // pack8_writer2::Value5 is automated
		pack8_writer2.setParameterT(5, 0.); // control::pack8_writer::Value6
		;                                   // pack8_writer2::Value7 is automated
		pack8_writer2.setParameterT(7, 0.); // control::pack8_writer::Value8
		
		; // cable_table2::Value is automated
		
		; // cable_pack3::Value is automated
		
		; // add7::Value is automated
		
		; // cable_table7::Value is automated
		
		;                                   // pack8_writer5::Value1 is automated
		pack8_writer5.setParameterT(1, 0.); // control::pack8_writer::Value2
		;                                   // pack8_writer5::Value3 is automated
		pack8_writer5.setParameterT(3, 0.); // control::pack8_writer::Value4
		;                                   // pack8_writer5::Value5 is automated
		pack8_writer5.setParameterT(5, 0.); // control::pack8_writer::Value6
		;                                   // pack8_writer5::Value7 is automated
		pack8_writer5.setParameterT(7, 0.); // control::pack8_writer::Value8
		
		; // cable_table3::Value is automated
		
		; // cable_pack6::Value is automated
		
		; // add10::Value is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // simple_ar::Attack is automated
		; // simple_ar::Release is automated
		; // simple_ar::Gate is automated
		; // simple_ar::AttackCurve is automated
		
		; // add13::Value is automated
		
		;                          // pma1::Value is automated
		;                          // pma1::Multiply is automated
		pma1.setParameterT(2, 0.); // control::pma::Add
		
		; // add4::Value is automated
		
		;                          // pma2::Value is automated
		;                          // pma2::Multiply is automated
		pma2.setParameterT(2, 0.); // control::pma::Add
		
		; // add5::Value is automated
		
		midi_cc.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		;                          // pma3::Value is automated
		;                          // pma3::Multiply is automated
		pma3.setParameterT(2, 0.); // control::pma::Add
		
		; // add6::Value is automated
		
		midi_cc1.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc1.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc1.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		;                          // pma4::Value is automated
		;                          // pma4::Multiply is automated
		pma4.setParameterT(2, 0.); // control::pma::Add
		
		; // add9::Value is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                         // XF1::smooth_x1 is automated
		XF1.setParameterT(1, 0.); // container::chain::mode_x1
		
		; // x1::Switch is automated
		
		; // switcher_x1::Value is automated
		
		; // xfader_x1::Value is automated
		
		;                                           // smoothed_parameter_x1::Value is automated
		;                                           // smoothed_parameter_x1::SmoothingTime is automated
		smoothed_parameter_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 0.);    // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader2_x1::Value is automated
		
		;                                            // smoothed_parameter1_x1::Value is automated
		;                                            // smoothed_parameter1_x1::SmoothingTime is automated
		smoothed_parameter1_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 0.);    // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader1_x1::Value is automated
		
		;                                            // smoothed_parameter2_x1::Value is automated
		;                                            // smoothed_parameter2_x1::SmoothingTime is automated
		smoothed_parameter2_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 0.);    // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader3_x1::Value is automated
		
		;                                            // smoothed_parameter4_x1::Value is automated
		;                                            // smoothed_parameter4_x1::SmoothingTime is automated
		smoothed_parameter4_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 0.);    // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader4_x1::Value is automated
		
		;                                            // smoothed_parameter3_x1::Value is automated
		;                                            // smoothed_parameter3_x1::SmoothingTime is automated
		smoothed_parameter3_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                              // gain4::Gain is automated
		gain4.setParameterT(1, 0.);    // core::gain::Smoothing
		gain4.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 10000.);
		this->setParameterT(4, 17.);
		this->setParameterT(5, 15.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 1.47792);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 0.562266);
		this->setParameterT(10, 0.355219);
		this->setParameterT(11, 0.330281);
		this->setParameterT(12, 0.226766);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 0.547063);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.504125);
		this->setParameterT(17, 0.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 0.);
		this->setParameterT(20, 0.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 1.);
		this->setParameterT(23, 0.);
		this->setParameterT(24, 0.);
		this->setParameterT(25, 0.);
		this->setParameterT(26, 19520.9);
		this->setParameterT(27, 1.);
		this->setParameterT(28, 10000.);
		this->setParameterT(29, 1255.5);
		this->setParameterT(30, 0.);
		this->setParameterT(31, 43.1);
		this->setParameterT(32, -0.0762661);
		this->setParameterT(33, 0.);
		this->setParameterT(34, 0.);
		this->setParameterT(35, 0.);
		this->setParameterT(36, 0.);
		this->setParameterT(37, 0.);
		this->setParameterT(38, 0.);
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
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index); // xfade5_impl::ramp_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).setExternalData(b, index); // xfade5_impl::cable_table1_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).                                           // xfade5_impl::ahdsr3_t<NV>
        getT(3).getT(3).getT(0).getT(3).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).           // xfade5_impl::ramp1_t<NV>
        getT(3).getT(3).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::oscillator_t<NV>
        getT(3).getT(1).getT(1).getT(3).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).           // xfade5_impl::peak_t<NV>
        getT(3).getT(3).getT(1).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::pack8_writer_t
        getT(3).getT(2).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::cable_table8_t
        getT(3).getT(2).getT(0).getT(0).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::cable_pack_t<NV>
        getT(3).getT(2).getT(0).getT(0).getT(3).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::cable_table4_t<NV>
        getT(3).getT(3).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::pack8_writer2_t
        getT(3).getT(3).getT(0).getT(0).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::cable_table2_t
        getT(3).getT(3).getT(0).getT(0).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::cable_pack3_t<NV>
        getT(3).getT(3).getT(0).getT(0).getT(3).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::cable_table7_t<NV>
        getT(3).getT(3).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::pack8_writer5_t
        getT(3).getT(3).getT(0).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::cable_table3_t
        getT(3).getT(3).getT(0).getT(1).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).   // xfade5_impl::cable_pack6_t<NV>
        getT(3).getT(3).getT(0).getT(1).getT(3).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).           // xfade5_impl::peak2_t<NV>
        getT(3).getT(3).getT(3).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).           // xfade5_impl::simple_ar_t<NV>
        getT(3).getT(3).getT(3).getT(3).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(1).setExternalData(b, index); // xfade5_impl::peak1_t<NV>
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
using xfade5 = wrap::node<xfade5_impl::instance<NV>>;
}


