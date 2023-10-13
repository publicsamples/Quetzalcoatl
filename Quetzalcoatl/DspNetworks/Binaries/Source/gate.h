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

namespace gate_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using cable_pack2_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<0>>;

struct cable_table5_t_data
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
using cable_table5_t = wrap::data<control::cable_table<parameter::plain<cable_pack2_t<NV>, 0>>, 
                                  data::embedded::table<cable_table5_t_data>>;

template <int NV>
using cable_pack1_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<1>>;

struct cable_table9_t_data
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
using cable_table9_t = wrap::data<control::cable_table<parameter::plain<cable_pack1_t<NV>, 0>>, 
                                  data::embedded::table<cable_table9_t_data>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table5_t<NV>, 0>, 
                                  parameter::plain<cable_table9_t<NV>, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using simple_ar_multimod = parameter::list<parameter::empty, 
                                           parameter::plain<ramp_t<NV>, 2>>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod<NV>>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, simple_ar_t<NV>>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table5_t<NV>>, 
                                   math::clear<NV>, 
                                   cable_pack2_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table9_t<NV>>, 
                                   math::clear<NV>, 
                                   cable_pack1_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain33_t<NV>>, 
                                   chain83_t<NV>>;
using peak14_t = wrap::no_data<core::peak>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, tempo_sync_t<NV>>, 
                                  midichain_t<NV>, 
                                  ramp_t<NV>, 
                                  math::clear<NV>, 
                                  split10_t<NV>, 
                                  peak14_t>;

namespace gate_t_parameters
{
// Parameter list for gate_impl::gate_t ------------------------------------------------------------

template <int NV>
using tempo = parameter::plain<gate_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using mul = parameter::plain<gate_impl::tempo_sync_t<NV>, 
                             1>;
using _1 = parameter::empty;
using _2 = _1;
using _3 = _1;
using _4 = _1;
using _5 = _1;
using _6 = _1;
using _7 = _1;
using _8 = _1;
template <int NV>
using gate_t_plist = parameter::list<tempo<NV>, 
                                     mul<NV>, 
                                     _1, 
                                     _2, 
                                     _3, 
                                     _4, 
                                     _5, 
                                     _6, 
                                     _7, 
                                     _8>;
}

template <int NV>
using gate_t_ = container::chain<gate_t_parameters::gate_t_plist<NV>, 
                                 wrap::fix<1, chain6_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public gate_impl::gate_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 2;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(gate);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(144)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x756D, 0x006C, 0x0000, 0x3F80, 0x0000, 0x4180, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 0x0000, 
            0x5F00, 0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x035B, 0x0000, 0x5F00, 0x0032, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x045B, 0x0000, 0x5F00, 0x0033, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x055B, 0x0000, 0x5F00, 0x0034, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x065B, 0x0000, 
            0x5F00, 0x0035, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x5F00, 0x0036, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x085B, 0x0000, 0x5F00, 0x0037, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x095B, 0x0000, 0x5F00, 0x0038, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain6 = this->getT(0);                               // gate_impl::chain6_t<NV>
		auto& tempo_sync = this->getT(0).getT(0);                   // gate_impl::tempo_sync_t<NV>
		auto& midichain = this->getT(0).getT(1);                    // gate_impl::midichain_t<NV>
		auto& simple_ar = this->getT(0).getT(1).getT(0);            // gate_impl::simple_ar_t<NV>
		auto& ramp = this->getT(0).getT(2);                         // gate_impl::ramp_t<NV>
		auto& clear17 = this->getT(0).getT(3);                      // math::clear<NV>
		auto& split10 = this->getT(0).getT(4);                      // gate_impl::split10_t<NV>
		auto& chain33 = this->getT(0).getT(4).getT(0);              // gate_impl::chain33_t<NV>
		auto& cable_table5 = this->getT(0).getT(4).getT(0).getT(0); // gate_impl::cable_table5_t<NV>
		auto& clear14 = this->getT(0).getT(4).getT(0).getT(1);      // math::clear<NV>
		auto& cable_pack2 = this->getT(0).getT(4).getT(0).getT(2);  // gate_impl::cable_pack2_t<NV>
		auto& add57 = this->getT(0).getT(4).getT(0).getT(3);        // math::add<NV>
		auto& chain83 = this->getT(0).getT(4).getT(1);              // gate_impl::chain83_t<NV>
		auto& cable_table9 = this->getT(0).getT(4).getT(1).getT(0); // gate_impl::cable_table9_t<NV>
		auto& clear16 = this->getT(0).getT(4).getT(1).getT(1);      // math::clear<NV>
		auto& cable_pack1 = this->getT(0).getT(4).getT(1).getT(2);  // gate_impl::cable_pack1_t<NV>
		auto& add58 = this->getT(0).getT(4).getT(1).getT(3);        // math::add<NV>
		auto& peak14 = this->getT(0).getT(5);                       // gate_impl::peak14_t
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync); // mul -> tempo_sync::Multiplier
		
		// Modulation Connections ------------------------------------------------------------------
		
		cable_pack2.getWrappedObject().getParameter().connectT(0, add57);        // cable_pack2 -> add57::Value
		cable_table5.getWrappedObject().getParameter().connectT(0, cable_pack2); // cable_table5 -> cable_pack2::Value
		cable_pack1.getWrappedObject().getParameter().connectT(0, add58);        // cable_pack1 -> add58::Value
		cable_table9.getWrappedObject().getParameter().connectT(0, cable_pack1); // cable_table9 -> cable_pack1::Value
		ramp.getParameter().connectT(0, cable_table5);                           // ramp -> cable_table5::Value
		ramp.getParameter().connectT(1, cable_table9);                           // ramp -> cable_table9::Value
		tempo_sync.getParameter().connectT(0, ramp);                             // tempo_sync -> ramp::PeriodTime
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(1).connectT(0, ramp); // simple_ar -> ramp::Gate
		
		// Default Values --------------------------------------------------------------------------
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		simple_ar.setParameterT(0, 97.6); // envelope::simple_ar::Attack
		simple_ar.setParameterT(1, 10.);  // envelope::simple_ar::Release
		simple_ar.setParameterT(2, 0.);   // envelope::simple_ar::Gate
		simple_ar.setParameterT(3, 0.);   // envelope::simple_ar::AttackCurve
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		;                          // ramp::Gate is automated
		
		clear17.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table5::Value is automated
		
		clear14.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack2::Value is automated
		
		; // add57::Value is automated
		
		; // cable_table9::Value is automated
		
		clear16.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack1::Value is automated
		
		; // add58::Value is automated
		
		this->setParameterT(0, 2.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(1).getT(0).setExternalData(b, index);         // gate_impl::simple_ar_t<NV>
		this->getT(0).getT(2).setExternalData(b, index);                 // gate_impl::ramp_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).setExternalData(b, index); // gate_impl::cable_table5_t<NV>
		this->getT(0).getT(4).getT(0).getT(2).setExternalData(b, index); // gate_impl::cable_pack2_t<NV>
		this->getT(0).getT(4).getT(1).getT(0).setExternalData(b, index); // gate_impl::cable_table9_t<NV>
		this->getT(0).getT(4).getT(1).getT(2).setExternalData(b, index); // gate_impl::cable_pack1_t<NV>
		this->getT(0).getT(5).setExternalData(b, index);                 // gate_impl::peak14_t
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
using gate = wrap::node<gate_impl::instance<NV>>;
}


