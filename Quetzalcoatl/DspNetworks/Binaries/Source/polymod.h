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

namespace polymod_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;

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
using cable_table4_t = wrap::data<control::cable_table<parameter::plain<cable_pack3_t<NV>, 0>>, 
                                  data::embedded::table<cable_table4_t_data>>;

template <int NV>
using cable_pack6_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<3>>;

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
using cable_table7_t = wrap::data<control::cable_table<parameter::plain<cable_pack6_t<NV>, 0>>, 
                                  data::embedded::table<cable_table7_t_data>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;
using cable_table8_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<1>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  parameter::plain<minmax_t<NV>, 0>, 
                                  parameter::plain<cable_table4_t<NV>, 0>, 
                                  parameter::plain<cable_table7_t<NV>, 0>, 
                                  parameter::plain<cable_pack_t<NV>, 0>, 
                                  parameter::plain<cable_table8_t, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using minmax1_t = control::minmax<NV, 
                                  parameter::plain<ramp_t<NV>, 2>>;

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
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, cable_table_t<NV>>, 
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
                                  cable_pack3_t<NV>, 
                                  math::add<NV>>;
using pack8_writer5_t = wrap::data<control::pack8_writer, 
                                   data::external::sliderpack<3>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table7_t<NV>>, 
                                   pack8_writer5_t, 
                                   cable_pack6_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain7_t<NV>>, 
                                  chain11_t<NV>>;

template <int NV>
using ahdsr1_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<wrap::no_process<math::add<NV>>, 0>>;

template <int NV>
using ahdsr1_t = wrap::no_data<envelope::ahdsr<NV, ahdsr1_multimod<NV>>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<ahdsr1_t<NV>, 8>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using no_midi1_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, ahdsr1_t<NV>>, 
                                     wrap::no_process<math::add<NV>>, 
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
                                          switcher_c3<NV>>;

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

using peak1_t = wrap::mod<parameter::plain<routing::public_mod, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  tempo_sync_t<NV>, 
                                  minmax1_t<NV>, 
                                  ramp_t<NV>, 
                                  math::clear<NV>, 
                                  softbypass_switch6_t<NV>, 
                                  peak1_t, 
                                  routing::public_mod>;

namespace polymod_t_parameters
{
// Parameter list for polymod_impl::polymod_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE(modsel_InputRange, 
                        0., 
                        4.);

template <int NV>
using modsel = parameter::chain<modsel_InputRange, 
                                parameter::plain<polymod_impl::cable_table1_t<NV>, 0>>;

template <int NV>
using attack1 = parameter::plain<polymod_impl::ahdsr3_t<NV>, 
                                 0>;
template <int NV>
using decay1 = parameter::plain<polymod_impl::ahdsr3_t<NV>, 
                                3>;
template <int NV>
using sus1 = parameter::plain<polymod_impl::ahdsr3_t<NV>, 
                              4>;
template <int NV>
using rel1 = parameter::plain<polymod_impl::ahdsr3_t<NV>, 
                              5>;
template <int NV>
using tempo = parameter::plain<polymod_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using mul = parameter::plain<polymod_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using one = parameter::plain<polymod_impl::ramp_t<NV>, 
                             1>;
template <int NV>
using etrig = parameter::plain<polymod_impl::input_toggle_t<NV>, 
                               0>;
template <int NV>
using inputpeak = parameter::plain<polymod_impl::minmax1_t<NV>, 
                                   3>;
using Step1 = parameter::plain<polymod_impl::pack8_writer_t, 
                               0>;
using Step2 = parameter::plain<polymod_impl::pack8_writer_t, 
                               1>;
using Step3 = parameter::plain<polymod_impl::pack8_writer_t, 
                               2>;
using Step4 = parameter::plain<polymod_impl::pack8_writer_t, 
                               3>;
using Step5 = parameter::plain<polymod_impl::pack8_writer_t, 
                               4>;
using Step6 = parameter::plain<polymod_impl::pack8_writer_t, 
                               5>;
using Step7 = parameter::plain<polymod_impl::pack8_writer_t, 
                               6>;
using Step8 = parameter::plain<polymod_impl::pack8_writer_t, 
                               7>;
using Gate1 = parameter::plain<polymod_impl::pack8_writer2_t, 
                               0>;
using Gate2 = parameter::plain<polymod_impl::pack8_writer2_t, 
                               2>;
using Gate3 = parameter::plain<polymod_impl::pack8_writer2_t, 
                               4>;
using Gate4 = parameter::plain<polymod_impl::pack8_writer2_t, 
                               6>;
using Gate5 = parameter::plain<polymod_impl::pack8_writer5_t, 
                               0>;
using Gate6 = parameter::plain<polymod_impl::pack8_writer5_t, 
                               2>;
using Gate7 = parameter::plain<polymod_impl::pack8_writer5_t, 
                               4>;
using Gate8 = parameter::plain<polymod_impl::pack8_writer5_t, 
                               6>;
template <int NV>
using A = parameter::plain<polymod_impl::ahdsr1_t<NV>, 
                           0>;
template <int NV>
using H = parameter::plain<polymod_impl::ahdsr1_t<NV>, 
                           2>;
template <int NV>
using D = parameter::plain<polymod_impl::ahdsr1_t<NV>, 
                           3>;
template <int NV>
using R = parameter::plain<polymod_impl::ahdsr1_t<NV>, 
                           5>;
template <int NV>
using polymod_t_plist = parameter::list<attack1<NV>, 
                                        decay1<NV>, 
                                        sus1<NV>, 
                                        rel1<NV>, 
                                        tempo<NV>, 
                                        mul<NV>, 
                                        one<NV>, 
                                        modsel<NV>, 
                                        etrig<NV>, 
                                        inputpeak<NV>, 
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
                                        D<NV>, 
                                        R<NV>>;
}

template <int NV>
using polymod_t_ = container::chain<polymod_t_parameters::polymod_t_plist<NV>, 
                                    wrap::fix<1, chain8_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance:  public polymod_impl::polymod_t_<NV>,
                                    public routing::public_mod_target
{
	
	struct metadata
	{
		static const int NumTables = 2;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(polymod);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(460)
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
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x055B, 0x0000, 
            0x6D00, 0x6C75, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0xC000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0006, 0x0000, 0x6E6F, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x6D00, 0x646F, 0x6573, 
            0x006C, 0x0000, 0x0000, 0x0000, 0x4080, 0x30B1, 0x4026, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 0x6500, 0x7274, 0x6769, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0xD63F, 0x0FAC, 
            0x0040, 0x0000, 0x5B00, 0x0009, 0x0000, 0x6E69, 0x7570, 0x7074, 
            0x6165, 0x006B, 0xCCCD, 0x3DCC, 0x0000, 0x4120, 0xF0A4, 0x3F0F, 
            0x004E, 0x3E94, 0x0000, 0x0000, 0x0A5B, 0x0000, 0x5300, 0x6574, 
            0x3170, 0x0000, 0x0000, 0x0000, 0x8000, 0x3B3F, 0xB5DF, 0x003E, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x000B, 0x0000, 0x7453, 0x7065, 
            0x0032, 0x0000, 0x0000, 0x0000, 0x3F80, 0x1AA0, 0x3EA9, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0C5B, 0x0000, 0x5300, 0x6574, 0x3370, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x3F3F, 0x6835, 0x003E, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000D, 0x0000, 0x7453, 0x7065, 0x0034, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0E5B, 0x0000, 0x5300, 0x6574, 0x3570, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x4A3F, 0x0C0C, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000F, 0x0000, 0x7453, 0x7065, 0x0036, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x105B, 0x0000, 0x5300, 0x6574, 0x3770, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x563F, 0x010E, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0011, 0x0000, 0x7453, 0x7065, 0x0038, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x125B, 0x0000, 0x4700, 0x7461, 0x3165, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0013, 0x0000, 0x6147, 0x6574, 0x0032, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x145B, 
            0x0000, 0x4700, 0x7461, 0x3365, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0015, 
            0x0000, 0x6147, 0x6574, 0x0034, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x165B, 0x0000, 
            0x4700, 0x7461, 0x3565, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0017, 0x0000, 
            0x6147, 0x6574, 0x0036, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x185B, 0x0000, 0x4700, 
            0x7461, 0x3765, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0019, 0x0000, 0x6147, 
            0x6574, 0x0038, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x1A5B, 0x0000, 0x4100, 0x0000, 
            0x0000, 0x0000, 0x1C40, 0x0046, 0x0000, 0x7200, 0x4A6A, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x001B, 0x0000, 0x0048, 0x0000, 0x0000, 0x4000, 
            0x461C, 0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x1C5B, 
            0x0000, 0x4400, 0x0000, 0x0000, 0x0000, 0x1C40, 0x3346, 0x7933, 
            0x7242, 0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x001D, 0x0000, 0x0052, 
            0x0000, 0x0000, 0x4000, 0x461C, 0xE000, 0x45B9, 0x6A72, 0x3E4A, 
            0xCCCD, 0x3DCC, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain8 = this->getT(0);                                                        // polymod_impl::chain8_t<NV>
		auto& clear = this->getT(0).getT(0);                                                 // math::clear<NV>
		auto& tempo_sync = this->getT(0).getT(1);                                            // polymod_impl::tempo_sync_t<NV>
		auto& minmax1 = this->getT(0).getT(2);                                               // polymod_impl::minmax1_t<NV>
		auto& ramp = this->getT(0).getT(3);                                                  // polymod_impl::ramp_t<NV>
		auto& clear6 = this->getT(0).getT(4);                                                // math::clear<NV>
		auto& softbypass_switch6 = this->getT(0).getT(5);                                    // polymod_impl::softbypass_switch6_t<NV>
		auto& cable_table1 = this->getT(0).getT(5).getT(0);                                  // polymod_impl::cable_table1_t<NV>
		auto& switcher = this->getT(0).getT(5).getT(1);                                      // polymod_impl::switcher_t<NV>
		auto& clear1 = this->getT(0).getT(5).getT(2);                                        // math::clear<NV>
		auto& sb_container = this->getT(0).getT(5).getT(3);                                  // polymod_impl::sb_container_t<NV>
		auto& sb1 = this->getT(0).getT(5).getT(3).getT(0);                                   // polymod_impl::sb1_t<NV>
		auto& minmax = this->getT(0).getT(5).getT(3).getT(0).getT(0);                        // polymod_impl::minmax_t<NV>
		auto& clear5 = this->getT(0).getT(5).getT(3).getT(0).getT(1);                        // math::clear<NV>
		auto& input_toggle = this->getT(0).getT(5).getT(3).getT(0).getT(2);                  // polymod_impl::input_toggle_t<NV>
		auto& ahdsr3 = this->getT(0).getT(5).getT(3).getT(0).getT(3);                        // polymod_impl::ahdsr3_t<NV>
		auto& add12 = this->getT(0).getT(5).getT(3).getT(0).getT(4);                         // math::add<NV>
		auto& sb2 = this->getT(0).getT(5).getT(3).getT(1);                                   // polymod_impl::sb2_t<NV>
		auto& cable_table = this->getT(0).getT(5).getT(3).getT(1).getT(0);                   // polymod_impl::cable_table_t<NV>
		auto& add1 = this->getT(0).getT(5).getT(3).getT(1).getT(1);                          // math::add<NV>
		auto& sb6 = this->getT(0).getT(5).getT(3).getT(2);                                   // polymod_impl::sb6_t<NV>
		auto& split2 = this->getT(0).getT(5).getT(3).getT(2).getT(0);                        // polymod_impl::split2_t<NV>
		auto& chain = this->getT(0).getT(5).getT(3).getT(2).getT(0).getT(0);                 // polymod_impl::chain_t<NV>
		auto& pack8_writer = this->getT(0).getT(5).getT(3).getT(2).getT(0).getT(0).getT(0);  // polymod_impl::pack8_writer_t
		auto& cable_table8 = this->getT(0).getT(5).getT(3).getT(2).getT(0).getT(0).getT(1);  // polymod_impl::cable_table8_t
		auto& clear4 = this->getT(0).getT(5).getT(3).getT(2).getT(0).getT(0).getT(2);        // math::clear<NV>
		auto& cable_pack = this->getT(0).getT(5).getT(3).getT(2).getT(0).getT(0).getT(3);    // polymod_impl::cable_pack_t<NV>
		auto& add8 = this->getT(0).getT(5).getT(3).getT(2).getT(1);                          // math::add<NV>
		auto& soft_bypass = this->getT(0).getT(5).getT(3).getT(3);                           // polymod_impl::soft_bypass_t<NV>
		auto& split6 = this->getT(0).getT(5).getT(3).getT(3).getT(0);                        // polymod_impl::split6_t<NV>
		auto& chain7 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(0);                // polymod_impl::chain7_t<NV>
		auto& cable_table4 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(0).getT(0);  // polymod_impl::cable_table4_t<NV>
		auto& pack8_writer2 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(0).getT(1); // polymod_impl::pack8_writer2_t
		auto& cable_pack3 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(0).getT(2);   // polymod_impl::cable_pack3_t<NV>
		auto& add7 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(0).getT(3);          // math::add<NV>
		auto& chain11 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(1);               // polymod_impl::chain11_t<NV>
		auto& cable_table7 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(1).getT(0);  // polymod_impl::cable_table7_t<NV>
		auto& pack8_writer5 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(1).getT(1); // polymod_impl::pack8_writer5_t
		auto& cable_pack6 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(1).getT(2);   // polymod_impl::cable_pack6_t<NV>
		auto& add10 = this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(1).getT(3);         // math::add<NV>
		auto& peak2 = this->getT(0).getT(5).getT(3).getT(3).getT(1);                         // polymod_impl::peak2_t<NV>
		auto& clear2 = this->getT(0).getT(5).getT(3).getT(3).getT(2);                        // math::clear<NV>
		auto& no_midi1 = this->getT(0).getT(5).getT(3).getT(3).getT(3);                      // polymod_impl::no_midi1_t<NV>
		auto& ahdsr1 = this->getT(0).getT(5).getT(3).getT(3).getT(3).getT(0);                // polymod_impl::ahdsr1_t<NV>
		auto& add2 = this->getT(0).getT(5).getT(3).getT(3).getT(3).getT(1);                  // wrap::no_process<math::add<NV>>
		auto& add13 = this->getT(0).getT(5).getT(3).getT(3).getT(3).getT(2);                 // math::add<NV>
		auto& peak1 = this->getT(0).getT(6);                                                 // polymod_impl::peak1_t
		auto& public_mod = this->getT(0).getT(7);                                            // routing::public_mod
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, ahdsr3); // attack1 -> ahdsr3::Attack
		
		this->getParameterT(1).connectT(0, ahdsr3); // decay1 -> ahdsr3::Decay
		
		this->getParameterT(2).connectT(0, ahdsr3); // sus1 -> ahdsr3::Sustain
		
		this->getParameterT(3).connectT(0, ahdsr3); // rel1 -> ahdsr3::Release
		
		this->getParameterT(4).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(5).connectT(0, tempo_sync); // mul -> tempo_sync::Multiplier
		
		this->getParameterT(6).connectT(0, ramp); // one -> ramp::LoopStart
		
		this->getParameterT(7).connectT(0, cable_table1); // modsel -> cable_table1::Value
		
		this->getParameterT(8).connectT(0, input_toggle); // etrig -> input_toggle::Input
		
		this->getParameterT(9).connectT(0, minmax1); // inputpeak -> minmax1::Skew
		
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
		
		this->getParameterT(26).connectT(0, ahdsr1); // A -> ahdsr1::Attack
		
		this->getParameterT(27).connectT(0, ahdsr1); // H -> ahdsr1::Hold
		
		this->getParameterT(28).connectT(0, ahdsr1); // D -> ahdsr1::Decay
		
		this->getParameterT(29).connectT(0, ahdsr1); // R -> ahdsr1::Release
		
		// Modulation Connections ------------------------------------------------------------------
		
		cable_table.getWrappedObject().getParameter().connectT(0, add1); // cable_table -> add1::Value
		auto& ahdsr3_p = ahdsr3.getWrappedObject().getParameter();
		ahdsr3_p.getParameterT(0).connectT(0, add12);                            // ahdsr3 -> add12::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, ahdsr3);      // input_toggle -> ahdsr3::Gate
		minmax.getWrappedObject().getParameter().connectT(0, input_toggle);      // minmax -> input_toggle::Value2
		cable_pack3.getWrappedObject().getParameter().connectT(0, add7);         // cable_pack3 -> add7::Value
		cable_table4.getWrappedObject().getParameter().connectT(0, cable_pack3); // cable_table4 -> cable_pack3::Value
		cable_pack6.getWrappedObject().getParameter().connectT(0, add10);        // cable_pack6 -> add10::Value
		cable_table7.getWrappedObject().getParameter().connectT(0, cable_pack6); // cable_table7 -> cable_pack6::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add8);          // cable_pack -> add8::Value
		ramp.getParameter().connectT(0, cable_table);                            // ramp -> cable_table::Value
		ramp.getParameter().connectT(1, minmax);                                 // ramp -> minmax::Value
		ramp.getParameter().connectT(2, cable_table4);                           // ramp -> cable_table4::Value
		ramp.getParameter().connectT(3, cable_table7);                           // ramp -> cable_table7::Value
		ramp.getParameter().connectT(4, cable_pack);                             // ramp -> cable_pack::Value
		ramp.getParameter().connectT(5, cable_table8);                           // ramp -> cable_table8::Value
		tempo_sync.getParameter().connectT(0, ramp);                             // tempo_sync -> ramp::PeriodTime
		minmax1.getWrappedObject().getParameter().connectT(0, ramp);             // minmax1 -> ramp::Gate
		auto& ahdsr1_p = ahdsr1.getWrappedObject().getParameter();
		ahdsr1_p.getParameterT(0).connectT(0, add13); // ahdsr1 -> add13::Value
		ahdsr1_p.getParameterT(1).connectT(0, add2);  // ahdsr1 -> add2::Value
		peak2.getParameter().connectT(0, ahdsr1);     // peak2 -> ahdsr1::Gate
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1);                         // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2);                         // switcher -> sb2::Bypassed
		switcher_p.getParameterT(2).connectT(0, sb6);                         // switcher -> sb6::Bypassed
		switcher_p.getParameterT(3).connectT(0, soft_bypass);                 // switcher -> soft_bypass::Bypassed
		cable_table1.getWrappedObject().getParameter().connectT(0, switcher); // cable_table1 -> switcher::Value
		peak1.getParameter().connectT(0, public_mod);                         // peak1 -> public_mod::Value
		
		// Public Mod Connection -------------------------------------------------------------------
		
		public_mod.connect(*this);
		
		// Default Values --------------------------------------------------------------------------
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // tempo_sync::Tempo is automated
		;                                   // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		minmax1.setParameterT(0, 1.); // control::minmax::Value
		minmax1.setParameterT(1, 0.); // control::minmax::Minimum
		minmax1.setParameterT(2, 1.); // control::minmax::Maximum
		;                             // minmax1::Skew is automated
		minmax1.setParameterT(4, 1.); // control::minmax::Step
		minmax1.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // ramp::PeriodTime is automated
		; // ramp::LoopStart is automated
		; // ramp::Gate is automated
		
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
		
		;                             // ahdsr3::Attack is automated
		ahdsr3.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		ahdsr3.setParameterT(2, 0.);  // envelope::ahdsr::Hold
		;                             // ahdsr3::Decay is automated
		;                             // ahdsr3::Sustain is automated
		;                             // ahdsr3::Release is automated
		ahdsr3.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr3.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		;                             // ahdsr3::Gate is automated
		
		; // add12::Value is automated
		
		; // cable_table::Value is automated
		
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
		
		; // cable_pack6::Value is automated
		
		; // add10::Value is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		;                            // ahdsr1::Attack is automated
		ahdsr1.setParameterT(1, 1.); // envelope::ahdsr::AttackLevel
		;                            // ahdsr1::Hold is automated
		;                            // ahdsr1::Decay is automated
		ahdsr1.setParameterT(4, 0.); // envelope::ahdsr::Sustain
		;                            // ahdsr1::Release is automated
		ahdsr1.setParameterT(6, 0.); // envelope::ahdsr::AttackCurve
		ahdsr1.setParameterT(7, 0.); // envelope::ahdsr::Retrigger
		;                            // ahdsr1::Gate is automated
		
		; // add2::Value is automated
		
		; // add13::Value is automated
		
		; // public_mod::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 10000.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 6.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 2.59672);
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
		this->setParameterT(26, 0.);
		this->setParameterT(27, 0.);
		this->setParameterT(28, 62.3);
		this->setParameterT(29, 5948.);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(3).setExternalData(b, index);                                         // polymod_impl::ramp_t<NV>
		this->getT(0).getT(5).getT(0).setExternalData(b, index);                                 // polymod_impl::cable_table1_t<NV>
		this->getT(0).getT(5).getT(3).getT(0).getT(3).setExternalData(b, index);                 // polymod_impl::ahdsr3_t<NV>
		this->getT(0).getT(5).getT(3).getT(1).getT(0).setExternalData(b, index);                 // polymod_impl::cable_table_t<NV>
		this->getT(0).getT(5).getT(3).getT(2).getT(0).getT(0).getT(0).setExternalData(b, index); // polymod_impl::pack8_writer_t
		this->getT(0).getT(5).getT(3).getT(2).getT(0).getT(0).getT(1).setExternalData(b, index); // polymod_impl::cable_table8_t
		this->getT(0).getT(5).getT(3).getT(2).getT(0).getT(0).getT(3).setExternalData(b, index); // polymod_impl::cable_pack_t<NV>
		this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(0).getT(0).setExternalData(b, index); // polymod_impl::cable_table4_t<NV>
		this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(0).getT(1).setExternalData(b, index); // polymod_impl::pack8_writer2_t
		this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(0).getT(2).setExternalData(b, index); // polymod_impl::cable_pack3_t<NV>
		this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(1).getT(0).setExternalData(b, index); // polymod_impl::cable_table7_t<NV>
		this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(1).getT(1).setExternalData(b, index); // polymod_impl::pack8_writer5_t
		this->getT(0).getT(5).getT(3).getT(3).getT(0).getT(1).getT(2).setExternalData(b, index); // polymod_impl::cable_pack6_t<NV>
		this->getT(0).getT(5).getT(3).getT(3).getT(1).setExternalData(b, index);                 // polymod_impl::peak2_t<NV>
		this->getT(0).getT(5).getT(3).getT(3).getT(3).getT(0).setExternalData(b, index);         // polymod_impl::ahdsr1_t<NV>
		this->getT(0).getT(6).setExternalData(b, index);                                         // polymod_impl::peak1_t
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
using polymod = wrap::node<polymod_impl::instance<NV>>;
}


