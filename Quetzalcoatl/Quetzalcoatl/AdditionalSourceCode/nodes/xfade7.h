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

namespace xfade7_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(pma9_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using pma9_mod = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     pma9_modRange>;

template <int NV>
using pma9_t = control::pma<NV, pma9_mod<NV>>;
template <int NV>
using input_toggle16_t = control::input_toggle<NV, 
                                               parameter::plain<pma9_t<NV>, 2>>;
template <int NV>
using smoothed_parameter1_x4_t = wrap::mod<parameter::plain<input_toggle16_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter17_t = wrap::mod<parameter::plain<input_toggle16_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma8_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<smoothed_parameter1_x4_t<NV>, 0>, 
                                  parameter::plain<smoothed_parameter17_t<NV>, 0>>;

template <int NV>
using pma8_t = control::pma<NV, pma8_mod<NV>>;
DECLARE_PARAMETER_RANGE(xfader_x1_c6Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using xfader_x1_c6 = parameter::from0To1<pma8_t<NV>, 
                                         2, 
                                         xfader_x1_c6Range>;

template <int NV>
using xfader_x1_multimod = parameter::list<parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           parameter::empty, 
                                           xfader_x1_c6<NV>, 
                                           parameter::empty>;

template <int NV>
using xfader_x1_t = control::xfader<xfader_x1_multimod<NV>, faders::switcher>;

template <int NV> using pma11_mod = pma9_mod<NV>;

template <int NV>
using pma11_t = control::pma<NV, pma11_mod<NV>>;
template <int NV>
using input_toggle2_t = control::input_toggle<NV, 
                                              parameter::plain<pma11_t<NV>, 2>>;
template <int NV>
using smoothed_parameter1_t = wrap::mod<parameter::plain<input_toggle2_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using smoothed_parameter1_x1_t = wrap::mod<parameter::plain<input_toggle2_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using pma10_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter1_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter1_x1_t<NV>, 0>>;

template <int NV>
using pma10_t = control::pma<NV, pma10_mod<NV>>;
template <int NV>
using xfader2_x1_c6 = parameter::from0To1<pma10_t<NV>, 
                                          2, 
                                          xfader_x1_c6Range>;

template <int NV>
using xfader2_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader2_x1_c6<NV>, 
                                            parameter::empty>;

template <int NV>
using xfader2_x1_t = control::xfader<xfader2_x1_multimod<NV>, 
                                     faders::linear>;

template <int NV> using pma13_mod = pma9_mod<NV>;

template <int NV>
using pma13_t = control::pma<NV, pma13_mod<NV>>;
template <int NV>
using input_toggle4_t = control::input_toggle<NV, 
                                              parameter::plain<pma13_t<NV>, 2>>;
template <int NV>
using smoothed_parameter2_x1_t = wrap::mod<parameter::plain<input_toggle4_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter3_t = wrap::mod<parameter::plain<input_toggle4_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma12_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter2_x1_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter3_t<NV>, 0>>;

template <int NV>
using pma12_t = control::pma<NV, pma12_mod<NV>>;
template <int NV>
using xfader1_x1_c6 = parameter::from0To1<pma12_t<NV>, 
                                          2, 
                                          xfader_x1_c6Range>;

template <int NV>
using xfader1_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader1_x1_c6<NV>, 
                                            parameter::empty>;

template <int NV>
using xfader1_x1_t = control::xfader<xfader1_x1_multimod<NV>, 
                                     faders::squared>;

template <int NV> using pma15_mod = pma9_mod<NV>;

template <int NV>
using pma15_t = control::pma<NV, pma15_mod<NV>>;
template <int NV>
using input_toggle5_t = control::input_toggle<NV, 
                                              parameter::plain<pma15_t<NV>, 2>>;
template <int NV>
using smoothed_parameter4_x1_t = wrap::mod<parameter::plain<input_toggle5_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter4_t = wrap::mod<parameter::plain<input_toggle5_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma17_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter4_x1_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter4_t<NV>, 0>>;

template <int NV>
using pma17_t = control::pma<NV, pma17_mod<NV>>;
template <int NV>
using xfader3_x1_c6 = parameter::from0To1<pma17_t<NV>, 
                                          2, 
                                          xfader_x1_c6Range>;

template <int NV>
using xfader3_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader3_x1_c6<NV>, 
                                            parameter::empty>;

template <int NV>
using xfader3_x1_t = control::xfader<xfader3_x1_multimod<NV>, 
                                     faders::cosine>;

template <int NV> using pma16_mod = pma9_mod<NV>;

template <int NV>
using pma16_t = control::pma<NV, pma16_mod<NV>>;
template <int NV>
using input_toggle3_t = control::input_toggle<NV, 
                                              parameter::plain<pma16_t<NV>, 2>>;
template <int NV>
using smoothed_parameter3_x1_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter2_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 2>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma14_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter3_x1_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter2_t<NV>, 0>>;

template <int NV>
using pma14_t = control::pma<NV, pma14_mod<NV>>;
template <int NV>
using xfader4_x1_c6 = parameter::from0To1<pma14_t<NV>, 
                                          2, 
                                          xfader_x1_c6Range>;

template <int NV>
using xfader4_x1_multimod = parameter::list<parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            parameter::empty, 
                                            xfader4_x1_c6<NV>, 
                                            parameter::empty>;

template <int NV>
using xfader4_x1_t = control::xfader<xfader4_x1_multimod<NV>, 
                                     faders::threshold>;

struct cable_table3_t_data
{
	span<float, 512> data =
	{
		0.f, 0.0154147f, 0.0308294f, 0.0462441f, 0.0616589f, 0.0770736f,
		0.0924883f, 0.107903f, 0.123318f, 0.138732f, 0.154147f, 0.169562f,
		0.184977f, 0.200391f, 0.215806f, 0.231221f, 0.246636f, 0.26205f,
		0.277465f, 0.29288f, 0.308294f, 0.323709f, 0.339124f, 0.354539f,
		0.369953f, 0.385368f, 0.400783f, 0.416198f, 0.431612f, 0.447027f,
		0.462442f, 0.477856f, 0.493271f, 0.508686f, 0.524101f, 0.539515f,
		0.55493f, 0.570345f, 0.585759f, 0.601174f, 0.616589f, 0.632004f,
		0.647418f, 0.662833f, 0.678248f, 0.693663f, 0.709077f, 0.724492f,
		0.739907f, 0.755321f, 0.770736f, 0.786151f, 0.801566f, 0.81698f,
		0.832395f, 0.84781f, 0.863225f, 0.878639f, 0.894054f, 0.909469f,
		0.924883f, 0.940298f, 0.955713f, 0.971128f, 0.986542f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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

using cable_table3_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table3_t_data>>;

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
		0.f, 0.f, 0.f, 0.00190473f, 0.0173844f, 0.0328641f,
		0.0483437f, 0.0638235f, 0.0793031f, 0.0947828f, 0.110262f, 0.125742f,
		0.141222f, 0.156702f, 0.172181f, 0.187661f, 0.20314f, 0.21862f,
		0.2341f, 0.24958f, 0.265059f, 0.280539f, 0.296018f, 0.311498f,
		0.326978f, 0.342458f, 0.357937f, 0.373417f, 0.388897f, 0.404376f,
		0.419856f, 0.435336f, 0.450815f, 0.466295f, 0.481775f, 0.497254f,
		0.512734f, 0.528214f, 0.543693f, 0.559173f, 0.574653f, 0.590132f,
		0.605612f, 0.621092f, 0.636571f, 0.652051f, 0.667531f, 0.68301f,
		0.69849f, 0.71397f, 0.729449f, 0.744929f, 0.760409f, 0.775888f,
		0.791368f, 0.806848f, 0.822327f, 0.837807f, 0.853287f, 0.868766f,
		0.884246f, 0.899726f, 0.915205f, 0.930685f, 0.946165f, 0.961644f,
		0.977124f, 0.988771f, 0.988801f, 0.98883f, 0.988859f, 0.988888f,
		0.988918f, 0.988947f, 0.988976f, 0.989005f, 0.989034f, 0.989064f,
		0.989093f, 0.989122f, 0.989151f, 0.989181f, 0.98921f, 0.989239f,
		0.989268f, 0.989298f, 0.989327f, 0.989356f, 0.989385f, 0.989415f,
		0.989444f, 0.989473f, 0.989502f, 0.989532f, 0.989561f, 0.98959f,
		0.989619f, 0.989649f, 0.989678f, 0.989707f, 0.989736f, 0.989766f,
		0.989795f, 0.989824f, 0.989853f, 0.989882f, 0.989912f, 0.989941f,
		0.98997f, 0.989999f, 0.990029f, 0.990058f, 0.990087f, 0.990116f,
		0.990146f, 0.990175f, 0.990204f, 0.990233f, 0.990263f, 0.990292f,
		0.990321f, 0.99035f, 0.99038f, 0.990409f, 0.990438f, 0.990467f,
		0.990497f, 0.990526f, 0.990555f, 0.990584f, 0.990614f, 0.990643f,
		0.990672f, 0.990701f, 0.99073f, 0.99076f, 0.990789f, 0.990818f,
		0.990847f, 0.990877f, 0.990906f, 0.990935f, 0.990964f, 0.990994f,
		0.991023f, 0.991052f, 0.991081f, 0.991111f, 0.99114f, 0.991169f,
		0.991198f, 0.991228f, 0.991257f, 0.991286f, 0.991315f, 0.991345f,
		0.991374f, 0.991403f, 0.991432f, 0.991462f, 0.991491f, 0.99152f,
		0.991549f, 0.991578f, 0.991608f, 0.991637f, 0.991666f, 0.991695f,
		0.991725f, 0.991754f, 0.991783f, 0.991812f, 0.991842f, 0.991871f,
		0.9919f, 0.991929f, 0.991959f, 0.991988f, 0.992017f, 0.992046f,
		0.992076f, 0.992105f, 0.992134f, 0.992163f, 0.992193f, 0.992222f,
		0.992251f, 0.99228f, 0.99231f, 0.992339f, 0.992368f, 0.992397f,
		0.992426f, 0.992456f, 0.992485f, 0.992514f, 0.992543f, 0.992573f,
		0.992602f, 0.992631f, 0.99266f, 0.99269f, 0.992719f, 0.992748f,
		0.992777f, 0.992807f, 0.992836f, 0.992865f, 0.992894f, 0.992924f,
		0.992953f, 0.992982f, 0.993011f, 0.993041f, 0.99307f, 0.993099f,
		0.993128f, 0.993158f, 0.993187f, 0.993216f, 0.993245f, 0.993274f,
		0.993304f, 0.993333f, 0.993362f, 0.993391f, 0.993421f, 0.99345f,
		0.993479f, 0.993508f, 0.993538f, 0.993567f, 0.993596f, 0.993625f,
		0.993655f, 0.993684f, 0.993713f, 0.993742f, 0.993772f, 0.993801f,
		0.99383f, 0.993859f, 0.993889f, 0.993918f, 0.993947f, 0.993976f,
		0.994006f, 0.994035f, 0.994064f, 0.994093f, 0.994123f, 0.994152f,
		0.994181f, 0.99421f, 0.994239f, 0.994269f, 0.994298f, 0.994327f,
		0.994356f, 0.994386f, 0.994415f, 0.994444f, 0.994473f, 0.994503f,
		0.994532f, 0.994561f, 0.99459f, 0.99462f, 0.994649f, 0.994678f,
		0.994707f, 0.994737f, 0.994766f, 0.994795f, 0.994824f, 0.994853f,
		0.994883f, 0.994912f, 0.994941f, 0.994971f, 0.995f, 0.995029f,
		0.995058f, 0.995087f, 0.995117f, 0.995146f, 0.995175f, 0.995204f,
		0.995234f, 0.995263f, 0.995292f, 0.995321f, 0.995351f, 0.99538f,
		0.995409f, 0.995438f, 0.995468f, 0.995497f, 0.995526f, 0.995555f,
		0.995585f, 0.995614f, 0.995643f, 0.995672f, 0.995701f, 0.995731f,
		0.99576f, 0.995789f, 0.995818f, 0.995848f, 0.995877f, 0.995906f,
		0.995935f, 0.995965f, 0.995994f, 0.996023f, 0.996052f, 0.996082f,
		0.996111f, 0.99614f, 0.996169f, 0.996199f, 0.996228f, 0.996257f,
		0.996286f, 0.996316f, 0.996345f, 0.996374f, 0.996403f, 0.996433f,
		0.996462f, 0.996491f, 0.99652f, 0.996549f, 0.996579f, 0.996608f,
		0.996637f, 0.996666f, 0.996696f, 0.996725f, 0.996754f, 0.996783f,
		0.996813f, 0.996842f, 0.996871f, 0.9969f, 0.99693f, 0.996959f,
		0.996988f, 0.997017f, 0.997047f, 0.997076f, 0.997105f, 0.997134f,
		0.997164f, 0.997193f, 0.997222f, 0.997251f, 0.997281f, 0.99731f,
		0.997339f, 0.997368f, 0.997398f, 0.997427f, 0.997456f, 0.997485f,
		0.997514f, 0.997544f, 0.997573f, 0.997602f, 0.997631f, 0.997661f,
		0.99769f, 0.997719f, 0.997748f, 0.997778f, 0.997807f, 0.997836f,
		0.997865f, 0.997895f, 0.997924f, 0.997953f, 0.997982f, 0.998012f,
		0.998041f, 0.99807f, 0.998099f, 0.998129f, 0.998158f, 0.998187f,
		0.998216f, 0.998246f, 0.998275f, 0.998304f, 0.998333f, 0.998362f,
		0.998392f, 0.998421f, 0.99845f, 0.998479f, 0.998509f, 0.998538f,
		0.998567f, 0.998596f, 0.998626f, 0.998655f, 0.998684f, 0.998713f,
		0.998743f, 0.998772f, 0.998801f, 0.99883f, 0.99886f, 0.998889f,
		0.998918f, 0.998947f, 0.998977f, 0.999006f, 0.999035f, 0.999064f,
		0.999094f, 0.999123f, 0.999152f, 0.999181f, 0.99921f, 0.99924f,
		0.999269f, 0.999298f, 0.999327f, 0.999357f, 0.999386f, 0.999415f,
		0.999444f, 0.999474f, 0.999503f, 0.999532f, 0.999561f, 0.999591f,
		0.99962f, 0.999649f, 0.999678f, 0.999708f, 0.999737f, 0.999766f,
		0.999795f, 0.999825f, 0.999854f, 0.999883f, 0.999912f, 0.999942f,
		0.999971f, 1.f
	};
};

using cable_table5_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table5_t_data>>;

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
		0.f, 0.00394499f, 0.019849f, 0.035753f, 0.0516573f, 0.0675613f,
		0.0834653f, 0.0993693f, 0.115274f, 0.131178f, 0.147082f, 0.162986f,
		0.17889f, 0.194794f, 0.210698f, 0.226602f, 0.242506f, 0.25841f,
		0.274314f, 0.290218f, 0.306123f, 0.322027f, 0.337931f, 0.353835f,
		0.369739f, 0.385643f, 0.401547f, 0.417451f, 0.433355f, 0.449259f,
		0.465163f, 0.481067f, 0.496971f, 0.512875f, 0.52878f, 0.544684f,
		0.560588f, 0.576492f, 0.592396f, 0.6083f, 0.624204f, 0.640108f,
		0.656012f, 0.671916f, 0.68782f, 0.703724f, 0.719628f, 0.735532f,
		0.751437f, 0.767341f, 0.783245f, 0.799149f, 0.815053f, 0.830957f,
		0.846861f, 0.862765f, 0.878669f, 0.894573f, 0.910477f, 0.926381f,
		0.942286f, 0.95819f, 0.974094f, 0.989998f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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

using cable_table7_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table7_t_data>>;

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
		0.f, 0.f, 0.f, 0.f, 0.00572038f, 0.0211351f,
		0.0365497f, 0.0519644f, 0.0673793f, 0.082794f, 0.0982086f, 0.113623f,
		0.129038f, 0.144453f, 0.159868f, 0.175282f, 0.190697f, 0.206112f,
		0.221526f, 0.236941f, 0.252356f, 0.267771f, 0.283185f, 0.2986f,
		0.314015f, 0.32943f, 0.344844f, 0.360259f, 0.375674f, 0.391088f,
		0.406503f, 0.421918f, 0.437333f, 0.452747f, 0.468162f, 0.483577f,
		0.498992f, 0.514406f, 0.529821f, 0.545236f, 0.56065f, 0.576065f,
		0.59148f, 0.606894f, 0.622309f, 0.637724f, 0.653139f, 0.668553f,
		0.683968f, 0.699383f, 0.714798f, 0.730212f, 0.745627f, 0.761042f,
		0.776456f, 0.791871f, 0.807286f, 0.822701f, 0.838115f, 0.85353f,
		0.868945f, 0.884359f, 0.899774f, 0.915189f, 0.930604f, 0.946018f,
		0.961433f, 0.976848f, 0.992263f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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

using cable_table9_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table9_t_data>>;

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
		0.00841469f, 0.0251139f, 0.0418137f, 0.0585129f, 0.0752121f, 0.0919113f,
		0.108611f, 0.12531f, 0.142009f, 0.158708f, 0.175408f, 0.192107f,
		0.208806f, 0.225506f, 0.242205f, 0.258904f, 0.275603f, 0.292302f,
		0.309002f, 0.325701f, 0.342401f, 0.3591f, 0.375799f, 0.392498f,
		0.409198f, 0.425897f, 0.442596f, 0.459296f, 0.475995f, 0.492694f,
		0.509393f, 0.526093f, 0.542792f, 0.559491f, 0.576191f, 0.59289f,
		0.609589f, 0.626288f, 0.642988f, 0.659687f, 0.676386f, 0.693085f,
		0.709785f, 0.726484f, 0.743183f, 0.759883f, 0.776582f, 0.793281f,
		0.80998f, 0.826679f, 0.843379f, 0.860078f, 0.876778f, 0.893477f,
		0.910176f, 0.926875f, 0.943575f, 0.960274f, 0.976974f, 0.993673f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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

using cable_table11_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::embedded::table<cable_table11_t_data>>;

struct cable_table13_t_data
{
	span<float, 512> data =
	{
		0.f, 7.12276e-05f, 0.000142515f, 0.000213742f, 0.000285029f, 0.000356257f,
		0.000427544f, 0.000498772f, 0.000569999f, 0.000641286f, 0.000712514f, 0.000783801f,
		0.000855029f, 0.000926316f, 0.000997543f, 0.00106877f, 0.00114006f, 0.00121129f,
		0.00128257f, 0.0013538f, 0.00142503f, 0.00149632f, 0.00156754f, 0.00163883f,
		0.00171006f, 0.00178134f, 0.00185257f, 0.0019238f, 0.00199509f, 0.00206631f,
		0.0021376f, 0.00220883f, 0.00228012f, 0.00235134f, 0.00242257f, 0.00249386f,
		0.00256509f, 0.00263637f, 0.0027076f, 0.00277889f, 0.00285012f, 0.00292134f,
		0.00299263f, 0.00306386f, 0.00313514f, 0.00320637f, 0.0032776f, 0.00334889f,
		0.00342011f, 0.0034914f, 0.00356263f, 0.00363392f, 0.00370514f, 0.00377637f,
		0.00384766f, 0.00391889f, 0.00399017f, 0.0040614f, 0.00413269f, 0.00420392f,
		0.00427514f, 0.00434643f, 0.00441766f, 0.00448895f, 0.00456017f, 0.00463146f,
		0.00470269f, 0.00477391f, 0.0048452f, 0.00491643f, 0.00498772f, 0.00505894f,
		0.00513017f, 0.00520146f, 0.00527269f, 0.00534397f, 0.0054152f, 0.00548649f,
		0.00555772f, 0.00562894f, 0.00570023f, 0.00577146f, 0.00584275f, 0.00591397f,
		0.00598526f, 0.00605649f, 0.00612772f, 0.006199f, 0.00627023f, 0.00634152f,
		0.00641274f, 0.00648403f, 0.00655526f, 0.00662649f, 0.00669777f, 0.006769f,
		0.00684029f, 0.00691152f, 0.00698274f, 0.00705403f, 0.00712526f, 0.00719655f,
		0.00726777f, 0.00733906f, 0.00741029f, 0.00748152f, 0.0075528f, 0.00762403f,
		0.00769532f, 0.00776654f, 0.00783783f, 0.00790906f, 0.00798029f, 0.00805157f,
		0.0081228f, 0.00819409f, 0.00826532f, 0.0083366f, 0.00840783f, 0.00847906f,
		0.00855035f, 0.00862157f, 0.00869286f, 0.00876409f, 0.00883532f, 0.0089066f,
		0.00897783f, 0.00904912f, 0.00912035f, 0.00919163f, 0.00926286f, 0.00933409f,
		0.00940537f, 0.0094766f, 0.00954789f, 0.00961912f, 0.0096904f, 0.00976163f,
		0.00983286f, 0.00990415f, 0.00997537f, 0.0100467f, 0.0101179f, 0.0101892f,
		0.0102604f, 0.0103316f, 0.0104029f, 0.0104741f, 0.0105454f, 0.0106167f,
		0.0106879f, 0.0107592f, 0.0108304f, 0.0109017f, 0.0109729f, 0.0110442f,
		0.0111154f, 0.0111867f, 0.0112579f, 0.0113292f, 0.0114005f, 0.0114717f,
		0.011543f, 0.0116142f, 0.0116854f, 0.0117567f, 0.0118279f, 0.0118992f,
		0.0119705f, 0.0120417f, 0.012113f, 0.0121842f, 0.0122555f, 0.0123267f,
		0.012398f, 0.0124692f, 0.0125405f, 0.0126117f, 0.012683f, 0.0127543f,
		0.0128255f, 0.0128968f, 0.012968f, 0.0130392f, 0.0131105f, 0.0131817f,
		0.013253f, 0.0133243f, 0.0133955f, 0.0134668f, 0.013538f, 0.0136093f,
		0.0136805f, 0.0137518f, 0.013823f, 0.0138943f, 0.0139655f, 0.0140368f,
		0.0141081f, 0.0141793f, 0.0142506f, 0.0143218f, 0.0143931f, 0.0144643f,
		0.0145355f, 0.0146068f, 0.0146781f, 0.0147493f, 0.0148206f, 0.0148918f,
		0.0149631f, 0.0150343f, 0.0151056f, 0.0151768f, 0.0152481f, 0.0153193f,
		0.0153906f, 0.0154619f, 0.0155331f, 0.0156044f, 0.0156756f, 0.0157469f,
		0.0158181f, 0.0158893f, 0.0159606f, 0.0160319f, 0.0161031f, 0.0161744f,
		0.0162457f, 0.0163169f, 0.0163881f, 0.0164594f, 0.0165306f, 0.0166019f,
		0.0166731f, 0.0167444f, 0.0168157f, 0.0168869f, 0.0169582f, 0.0170294f,
		0.0171007f, 0.0171719f, 0.0172431f, 0.0173144f, 0.0173857f, 0.0174569f,
		0.0175282f, 0.0175995f, 0.0176707f, 0.0177419f, 0.0178132f, 0.0178844f,
		0.0179557f, 0.0180269f, 0.0180982f, 0.0181695f, 0.0182407f, 0.018312f,
		0.0183832f, 0.0184545f, 0.0185257f, 0.018597f, 0.0186682f, 0.0187395f,
		0.0188107f, 0.018882f, 0.0189533f, 0.0190245f, 0.0190957f, 0.019167f,
		0.0192382f, 0.0193095f, 0.0193807f, 0.019452f, 0.0195233f, 0.0195945f,
		0.0196658f, 0.019737f, 0.0198083f, 0.0198795f, 0.0199508f, 0.020022f,
		0.0200933f, 0.0201645f, 0.0202358f, 0.0203071f, 0.0203783f, 0.0204495f,
		0.0205208f, 0.020592f, 0.0206633f, 0.0207345f, 0.0208058f, 0.0208771f,
		0.0209483f, 0.0210196f, 0.0210908f, 0.0211621f, 0.0212333f, 0.0213046f,
		0.0213758f, 0.0214471f, 0.0215183f, 0.0215896f, 0.0216609f, 0.0217321f,
		0.0218034f, 0.0218746f, 0.0219458f, 0.0220171f, 0.0220883f, 0.0221596f,
		0.0222309f, 0.0223022f, 0.0223734f, 0.0224446f, 0.0313618f, 0.0457653f,
		0.0601687f, 0.0745723f, 0.0889757f, 0.103379f, 0.117783f, 0.132186f,
		0.14659f, 0.160994f, 0.175397f, 0.189801f, 0.204204f, 0.218608f,
		0.233011f, 0.247415f, 0.261818f, 0.276222f, 0.290625f, 0.305029f,
		0.319432f, 0.333836f, 0.348239f, 0.362643f, 0.377047f, 0.39145f,
		0.405854f, 0.420257f, 0.434661f, 0.449064f, 0.463468f, 0.477871f,
		0.492275f, 0.506679f, 0.521082f, 0.535486f, 0.549889f, 0.564293f,
		0.578696f, 0.5931f, 0.607504f, 0.621907f, 0.636311f, 0.650714f,
		0.665118f, 0.679521f, 0.693924f, 0.708328f, 0.722732f, 0.737135f,
		0.751539f, 0.765942f, 0.780346f, 0.794749f, 0.809153f, 0.823556f,
		0.83796f, 0.852364f, 0.866767f, 0.881171f, 0.895574f, 0.909978f,
		0.924381f, 0.938785f, 0.953189f, 0.967592f, 0.981996f, 0.996399f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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

using cable_table13_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::embedded::table<cable_table13_t_data>>;

template <int NV> using pma41_mod = pma9_mod<NV>;

template <int NV>
using pma41_t = control::pma<NV, pma41_mod<NV>>;
template <int NV>
using input_toggle18_t = control::input_toggle<NV, 
                                               parameter::plain<pma41_t<NV>, 2>>;
template <int NV>
using smoothed_parameter3_x5_t = wrap::mod<parameter::plain<input_toggle18_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter16_t = wrap::mod<parameter::plain<input_toggle18_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using pma40_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<smoothed_parameter3_x5_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter16_t<NV>, 0>>;

template <int NV>
using pma40_t = control::pma<NV, pma40_mod<NV>>;
template <int NV>
using cable_table17_mod = parameter::from0To1<pma40_t<NV>, 
                                              2, 
                                              xfader_x1_c6Range>;

template <int NV>
using cable_table17_t = wrap::data<control::cable_table<cable_table17_mod<NV>>, 
                                   data::external::table<0>>;

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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.0125244f, 0.0292236f, 0.0459229f, 0.0626221f, 0.0793218f, 0.0960211f,
		0.11272f, 0.129419f, 0.146119f, 0.162818f, 0.179517f, 0.196216f,
		0.212916f, 0.229615f, 0.246315f, 0.263014f, 0.279713f, 0.296412f,
		0.313111f, 0.329811f, 0.34651f, 0.36321f, 0.379909f, 0.396608f,
		0.413307f, 0.430006f, 0.446706f, 0.463405f, 0.480105f, 0.496804f,
		0.513503f, 0.530202f, 0.546901f, 0.563601f, 0.5803f, 0.596999f,
		0.613699f, 0.630398f, 0.647097f, 0.663797f, 0.680496f, 0.697195f,
		0.713894f, 0.730593f, 0.747293f, 0.763992f, 0.780692f, 0.797391f,
		0.81409f, 0.830789f, 0.847488f, 0.864188f, 0.880887f, 0.897587f,
		0.914286f, 0.930985f, 0.947684f, 0.964383f, 0.981083f, 0.997782f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
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
using cable_table15_t = wrap::data<control::cable_table<parameter::plain<cable_table17_t<NV>, 0>>, 
                                   data::embedded::table<cable_table15_t_data>>;
using cable_table16_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<7>>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table3_t, 0>, 
                                  parameter::plain<cable_table5_t, 0>, 
                                  parameter::plain<cable_table7_t, 0>, 
                                  parameter::plain<cable_table9_t, 0>, 
                                  parameter::plain<cable_table11_t, 0>, 
                                  parameter::plain<cable_table13_t, 0>, 
                                  parameter::plain<cable_table15_t<NV>, 0>, 
                                  parameter::plain<cable_table16_t, 0>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using pma_mod_5 = parameter::from0To1<pma2_t<NV>, 
                                      2, 
                                      xfader_x1_c6Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<xfader_x1_t<NV>, 0>, 
                                 parameter::plain<xfader2_x1_t<NV>, 0>, 
                                 parameter::plain<xfader1_x1_t<NV>, 0>, 
                                 parameter::plain<xfader3_x1_t<NV>, 0>, 
                                 parameter::plain<xfader4_x1_t<NV>, 0>, 
                                 pma_mod_5<NV>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

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

template <int NV>
using pma7_t = control::pma<NV, 
                            parameter::plain<pma6_t<NV>, 2>>;
template <int NV>
using event_data_reader7_t = wrap::mod<parameter::plain<pma7_t<NV>, 0>, 
                                       routing::event_data_reader<NV>>;
using global_cable16_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
using global_cable18_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>>;
using global_cable19_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;
using global_cable20_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = runtime_target::indexers::fix_hash<104068263>;

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
using peak2_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak2_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split21_t = container::split<parameter::empty, 
                                   wrap::fix<1, event_data_reader7_t<NV>>, 
                                   chain29_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split21_t<NV>>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain10_t<NV>>, 
                                   pma7_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain5_t<NV>>, 
                                  chain6_t<NV>, 
                                  chain9_t<NV>, 
                                  chain14_t<NV>, 
                                  chain25_t<NV>>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma_t<NV>>, 
                                   split7_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split19_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter1_x4_t<NV>>, 
                                   smoothed_parameter17_t<NV>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split20_t<NV>>, 
                                   input_toggle16_t<NV>, 
                                   pma9_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain1_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader_x1_t<NV>>, 
                                     pma8_t<NV>, 
                                     chain26_t<NV>>;

template <int NV>
using sb1_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain1_x1_t<NV>>>;

template <int NV>
using sb1_x1_t = bypass::smoothed<20, sb1_x1_t_<NV>>;
template <int NV>
using switcher_x1_c0 = parameter::bypass<sb1_x1_t<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter1_x1_t<NV>>, 
                                  smoothed_parameter1_t<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split4_t<NV>>, 
                                  input_toggle2_t<NV>, 
                                  pma11_t<NV>, 
                                  core::gain<NV>>;

template <int NV>
using chain3_x1_x1_t = container::chain<parameter::empty, 
                                        wrap::fix<2, xfader2_x1_t<NV>>, 
                                        pma10_t<NV>, 
                                        chain7_t<NV>>;

template <int NV>
using sb2_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain3_x1_x1_t<NV>>>;

template <int NV>
using sb2_x1_t = bypass::smoothed<20, sb2_x1_t_<NV>>;
template <int NV>
using switcher_x1_c1 = parameter::bypass<sb2_x1_t<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter2_x1_t<NV>>, 
                                  smoothed_parameter3_t<NV>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split6_t<NV>>, 
                                   input_toggle4_t<NV>>;

template <int NV>
using chain2_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader1_x1_t<NV>>, 
                                     pma12_t<NV>, 
                                     chain12_t<NV>, 
                                     pma13_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb3_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain2_x1_t<NV>>>;

template <int NV>
using sb3_x1_t = bypass::smoothed<20, sb3_x1_t_<NV>>;
template <int NV>
using switcher_x1_c2 = parameter::bypass<sb3_x1_t<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter4_x1_t<NV>>, 
                                  smoothed_parameter4_t<NV>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split8_t<NV>>, 
                                   input_toggle5_t<NV>, 
                                   pma15_t<NV>>;

template <int NV>
using chain4_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader3_x1_t<NV>>, 
                                     pma17_t<NV>, 
                                     chain13_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb4_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain4_x1_t<NV>>>;

template <int NV>
using sb4_x1_t = bypass::smoothed<20, sb4_x1_t_<NV>>;
template <int NV>
using switcher_x1_c3 = parameter::bypass<sb4_x1_t<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter3_x1_t<NV>>, 
                                  smoothed_parameter2_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split5_t<NV>>, 
                                   input_toggle3_t<NV>, 
                                   pma16_t<NV>>;

template <int NV>
using chain5_x1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, xfader4_x1_t<NV>>, 
                                     pma14_t<NV>, 
                                     chain11_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using sb5_x1_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, chain5_x1_t<NV>>>;

template <int NV>
using sb5_x1_t = bypass::smoothed<20, sb5_x1_t_<NV>>;
template <int NV>
using switcher_x1_c4 = parameter::bypass<sb5_x1_t<NV>>;

using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table3_t>>;

using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table5_t>>;

using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table7_t>>;

using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table9_t>>;

using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table11_t>>;

using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table13_t>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table15_t<NV>>>;

using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table16_t>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain28_t>, 
                                  chain38_t, 
                                  chain39_t, 
                                  chain40_t, 
                                  chain41_t, 
                                  chain42_t, 
                                  chain43_t<NV>, 
                                  chain44_t>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split1_t<NV>>, 
                                      cable_table17_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV>
using split23_t = container::split<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter3_x5_t<NV>>, 
                                   smoothed_parameter16_t<NV>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split23_t<NV>>, 
                                   input_toggle18_t<NV>, 
                                   pma41_t<NV>>;

template <int NV>
using chain5_x5_t = container::chain<parameter::empty, 
                                     wrap::fix<2, pma2_t<NV>>, 
                                     modchain2_t<NV>, 
                                     pma40_t<NV>, 
                                     chain45_t<NV>, 
                                     core::gain<NV>>;

template <int NV>
using soft_bypass3_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain5_x5_t<NV>>>;

template <int NV>
using soft_bypass3_t = bypass::smoothed<20, soft_bypass3_t_<NV>>;

template <int NV>
using sb5_x4_t_ = container::chain<parameter::empty, 
                                   wrap::fix<2, soft_bypass3_t<NV>>>;

template <int NV>
using sb5_x4_t = bypass::smoothed<20, sb5_x4_t_<NV>>;
template <int NV>
using switcher_x1_c5 = parameter::bypass<sb5_x4_t<NV>>;

template <int NV>
using switcher_x1_multimod = parameter::list<switcher_x1_c0<NV>, 
                                             switcher_x1_c1<NV>, 
                                             switcher_x1_c2<NV>, 
                                             switcher_x1_c3<NV>, 
                                             switcher_x1_c4<NV>, 
                                             switcher_x1_c5<NV>>;

template <int NV>
using switcher_x1_t = control::xfader<switcher_x1_multimod<NV>, 
                                      faders::switcher>;

template <int NV>
using sb_container_x1_t = container::chain<parameter::empty, 
                                           wrap::fix<2, sb1_x1_t<NV>>, 
                                           sb2_x1_t<NV>, 
                                           sb3_x1_t<NV>, 
                                           sb4_x1_t<NV>, 
                                           sb5_x1_t<NV>, 
                                           sb5_x4_t<NV>>;

template <int NV>
using x1_t = container::chain<parameter::empty, 
                              wrap::fix<2, switcher_x1_t<NV>>, 
                              sb_container_x1_t<NV>>;

template <int NV>
using sb3_t_ = container::chain<parameter::empty, wrap::fix<2, x1_t<NV>>>;

template <int NV>
using sb3_t = bypass::smoothed<20, sb3_t_<NV>>;
template <int NV>
using switcher1_c0 = parameter::bypass<sb3_t<NV>>;

using sb4_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, core::empty>>;

using sb4_t = bypass::smoothed<20, sb4_t_>;
using switcher1_c1 = parameter::bypass<sb4_t>;

using sb5_t_ = sb4_t_;

using sb5_t = bypass::smoothed<20, sb5_t_>;
using switcher1_c2 = parameter::bypass<sb5_t>;

template <int NV>
using switcher1_multimod = parameter::list<switcher1_c0<NV>, 
                                           switcher1_c1, 
                                           switcher1_c2>;

template <int NV>
using switcher1_t = control::xfader<switcher1_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb3_t<NV>>, 
                                         sb4_t, 
                                         sb5_t>;

template <int NV>
using softbypass_switch4_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher1_t<NV>>, 
                                              sb_container1_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, softbypass_switch4_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

namespace XF1_t_parameters
{
// Parameter list for xfade7_impl::XF1_t -----------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(smooth_x1_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE_STEP(smooth_x1_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth_x1_0 = parameter::from0To1<xfade7_impl::smoothed_parameter2_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_1 = parameter::from0To1<xfade7_impl::smoothed_parameter4_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_2 = parameter::from0To1<xfade7_impl::smoothed_parameter3_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_3 = parameter::from0To1<xfade7_impl::smoothed_parameter3_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_4 = parameter::from0To1<xfade7_impl::smoothed_parameter4_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_5 = parameter::from0To1<xfade7_impl::smoothed_parameter2_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_6 = parameter::from0To1<xfade7_impl::smoothed_parameter1_x4_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_7 = parameter::from0To1<xfade7_impl::smoothed_parameter17_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_8 = parameter::from0To1<xfade7_impl::smoothed_parameter1_x1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_9 = parameter::from0To1<xfade7_impl::smoothed_parameter1_t<NV>, 
                                        1, 
                                        smooth_x1_0Range>;

template <int NV>
using smooth_x1_10 = parameter::from0To1<xfade7_impl::smoothed_parameter3_x5_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1_11 = parameter::from0To1<xfade7_impl::smoothed_parameter16_t<NV>, 
                                         1, 
                                         smooth_x1_0Range>;

template <int NV>
using smooth_x1 = parameter::chain<smooth_x1_InputRange, 
                                   smooth_x1_0<NV>, 
                                   smooth_x1_1<NV>, 
                                   smooth_x1_2<NV>, 
                                   smooth_x1_3<NV>, 
                                   smooth_x1_4<NV>, 
                                   smooth_x1_5<NV>, 
                                   smooth_x1_6<NV>, 
                                   smooth_x1_7<NV>, 
                                   smooth_x1_8<NV>, 
                                   smooth_x1_9<NV>, 
                                   smooth_x1_10<NV>, 
                                   smooth_x1_11<NV>>;

DECLARE_PARAMETER_RANGE_STEP(SmoothType_0Range, 
                             0., 
                             1., 
                             1.);

template <int NV>
using SmoothType_0 = parameter::from0To1<xfade7_impl::input_toggle2_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_1 = parameter::from0To1<xfade7_impl::input_toggle4_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_2 = parameter::from0To1<xfade7_impl::input_toggle5_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_3 = parameter::from0To1<xfade7_impl::input_toggle3_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_4 = parameter::from0To1<xfade7_impl::input_toggle16_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType_5 = parameter::from0To1<xfade7_impl::input_toggle18_t<NV>, 
                                         0, 
                                         SmoothType_0Range>;

template <int NV>
using SmoothType = parameter::chain<ranges::Identity, 
                                    SmoothType_0<NV>, 
                                    SmoothType_1<NV>, 
                                    SmoothType_2<NV>, 
                                    SmoothType_3<NV>, 
                                    SmoothType_4<NV>, 
                                    SmoothType_5<NV>>;

template <int NV>
using XF1_t_plist = parameter::list<smooth_x1<NV>, SmoothType<NV>>;
}

template <int NV>
using XF1_t = container::chain<XF1_t_parameters::XF1_t_plist<NV>, 
                               wrap::fix<2, fix8_block_t<NV>>>;

namespace xfade7_t_parameters
{
// Parameter list for xfade7_impl::xfade7_t --------------------------------------------------------

DECLARE_PARAMETER_RANGE(MainParam_InputRange, 
                        1., 
                        8.);
template <int NV>
using MainParam_0 = parameter::from0To1<xfade7_impl::pma7_t<NV>, 
                                        2, 
                                        xfade7_impl::xfader_x1_c6Range>;

template <int NV>
using MainParam = parameter::chain<MainParam_InputRange, MainParam_0<NV>>;

DECLARE_PARAMETER_RANGE(_3rdParam_InputRange, 
                        0., 
                        7.);

template <int NV>
using _3rdParam = parameter::chain<_3rdParam_InputRange, 
                                   parameter::plain<xfade7_impl::switcher_x1_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(_5thParam_InputRange, 
                        0., 
                        3.);

template <int NV>
using _5thParam = parameter::chain<_5thParam_InputRange, 
                                   parameter::plain<xfade7_impl::switcher1_t<NV>, 0>>;

template <int NV>
using _2ndParam = parameter::plain<xfade7_impl::XF1_t<NV>, 0>;
template <int NV>
using _4thParam = parameter::plain<xfade7_impl::XF1_t<NV>, 1>;
template <int NV>
using Poly = parameter::plain<xfade7_impl::pma_t<NV>, 1>;
template <int NV>
using Global = parameter::plain<xfade7_impl::pma7_t<NV>, 
                                1>;
template <int NV>
using GlobalSrc = parameter::plain<xfade7_impl::event_data_reader7_t<NV>, 
                                   0>;
template <int NV>
using Vel = parameter::plain<xfade7_impl::pma3_t<NV>, 
                             1>;
template <int NV>
using Trk = parameter::plain<xfade7_impl::pma4_t<NV>, 
                             1>;
template <int NV>
using MW = parameter::plain<xfade7_impl::pma5_t<NV>, 
                            1>;
template <int NV>
using AT = parameter::plain<xfade7_impl::pma6_t<NV>, 
                            1>;
template <int NV>
using MonoSrc = parameter::plain<xfade7_impl::branch3_t<NV>, 
                                 0>;
template <int NV>
using xfade7_t_plist = parameter::list<MainParam<NV>, 
                                       _2ndParam<NV>, 
                                       _3rdParam<NV>, 
                                       _4thParam<NV>, 
                                       _5thParam<NV>, 
                                       Poly<NV>, 
                                       Global<NV>, 
                                       GlobalSrc<NV>, 
                                       Vel<NV>, 
                                       Trk<NV>, 
                                       MW<NV>, 
                                       AT<NV>, 
                                       MonoSrc<NV>>;
}

template <int NV>
using xfade7_t_ = container::chain<xfade7_t_parameters::xfade7_t_plist<NV>, 
                                   wrap::fix<2, modchain_t<NV>>, 
                                   XF1_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public xfade7_impl::xfade7_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 8;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(xfade7);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(224)
		{
			0x005C, 0x0000, 0x0000, 0x614D, 0x6E69, 0x6150, 0x6172, 0x006D, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0100, 0x0000, 0x5F00, 0x6E32, 0x5064, 
            0x7261, 0x6D61, 0x0000, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 
            0x3FC0, 0x209B, 0x3E9A, 0xCCCD, 0x3DCC, 0x005C, 0x0002, 0x0000, 
            0x335F, 0x6472, 0x6150, 0x6172, 0x006D, 0x0000, 0x0000, 0x0000, 
            0xE000, 0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0300, 0x0000, 0x5F00, 0x7434, 0x5068, 0x7261, 0x6D61, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x96E7, 0x3F7B, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0004, 0x0000, 0x355F, 0x6874, 0x6150, 
            0x6172, 0x006D, 0x0000, 0x0000, 0x0000, 0x4000, 0xF240, 0x0C52, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0500, 0x0000, 0x5000, 
            0x6C6F, 0x0079, 0x0000, 0x8000, 0x00BF, 0x8000, 0x483F, 0x1F73, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0600, 0x0000, 0x4700, 
            0x6F6C, 0x6162, 0x006C, 0x0000, 0x8000, 0x00BF, 0x8000, 0x3F3F, 
            0x8225, 0x00BD, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0700, 0x0000, 
            0x4700, 0x6F6C, 0x6162, 0x536C, 0x6372, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x4180, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0008, 0x0000, 0x6556, 0x006C, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0900, 0x0000, 0x5400, 0x6B72, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x000A, 0x0000, 0x574D, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000B, 
            0x0000, 0x5441, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000C, 0x0000, 
            0x6F4D, 0x6F6E, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 0xE000, 
            0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                                           // xfade7_impl::modchain_t<NV>
		auto& split19 = this->getT(0).getT(0);                                                    // xfade7_impl::split19_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0);                                                // xfade7_impl::pma_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(1);                                             // xfade7_impl::split7_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(1).getT(0);                                     // xfade7_impl::chain5_t<NV>
		auto& midi = this->getT(0).getT(0).getT(1).getT(0).getT(0);                               // xfade7_impl::midi_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                               // xfade7_impl::pma3_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(1);                                     // xfade7_impl::chain6_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                              // xfade7_impl::midi1_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                               // xfade7_impl::pma4_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(1).getT(2);                                     // xfade7_impl::chain9_t<NV>
		auto& midi_cc = this->getT(0).getT(0).getT(1).getT(2).getT(0);                            // xfade7_impl::midi_cc_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                               // xfade7_impl::pma5_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(3);                                    // xfade7_impl::chain14_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                           // xfade7_impl::midi_cc1_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                               // xfade7_impl::pma6_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(4);                                    // xfade7_impl::chain25_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                            // xfade7_impl::chain10_t<NV>
		auto& split21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0);                    // xfade7_impl::split21_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0).getT(0); // xfade7_impl::event_data_reader7_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(1).getT(4).getT(0).getT(0).getT(1);            // xfade7_impl::chain29_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(1).getT(4).                                    // xfade7_impl::branch3_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& chain30 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade7_impl::chain30_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(0);
		auto& global_cable16 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade7_impl::global_cable16_t<NV>
                               getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& chain31 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade7_impl::chain31_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(1);
		auto& global_cable17 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade7_impl::global_cable17_t<NV>
                               getT(0).getT(1).getT(0).getT(1).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(1).getT(1);
		auto& chain32 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade7_impl::chain32_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(2);
		auto& global_cable18 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade7_impl::global_cable18_t<NV>
                               getT(0).getT(1).getT(0).getT(2).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(2).getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade7_impl::chain33_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(3);
		auto& global_cable19 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade7_impl::global_cable19_t<NV>
                               getT(0).getT(1).getT(0).getT(3).getT(0);
		auto& add19 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(3).getT(1);
		auto& chain34 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade7_impl::chain34_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(4);
		auto& global_cable20 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade7_impl::global_cable20_t<NV>
                               getT(0).getT(1).getT(0).getT(4).getT(0);
		auto& add20 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(4).getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade7_impl::chain35_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(5);
		auto& global_cable21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade7_impl::global_cable21_t<NV>
                               getT(0).getT(1).getT(0).getT(5).getT(0);
		auto& add21 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(5).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade7_impl::chain36_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(6);
		auto& global_cable22 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade7_impl::global_cable22_t<NV>
                               getT(0).getT(1).getT(0).getT(6).getT(0);
		auto& add22 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(6).getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(1).getT(4).                                 // xfade7_impl::chain37_t<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(7);
		auto& global_cable23 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                  // xfade7_impl::global_cable23_t<NV>
                               getT(0).getT(1).getT(0).getT(7).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(1).getT(4).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(7).getT(1);
		auto& peak2 = this->getT(0).getT(0).getT(1).getT(4).                                   // xfade7_impl::peak2_t<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& clear = this->getT(0).getT(0).getT(1).getT(4).                                   // math::clear<NV>
                      getT(0).getT(0).getT(1).getT(2);
		auto& pma7 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                            // xfade7_impl::pma7_t<NV>
		auto& XF1 = this->getT(1);                                                             // xfade7_impl::XF1_t<NV>
		auto& fix8_block = this->getT(1).getT(0);                                              // xfade7_impl::fix8_block_t<NV>
		auto& softbypass_switch4 = this->getT(1).getT(0).getT(0);                              // xfade7_impl::softbypass_switch4_t<NV>
		auto& switcher1 = this->getT(1).getT(0).getT(0).getT(0);                               // xfade7_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(1).getT(0).getT(0).getT(1);                           // xfade7_impl::sb_container1_t<NV>
		auto& sb3 = this->getT(1).getT(0).getT(0).getT(1).getT(0);                             // xfade7_impl::sb3_t<NV>
		auto& x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0);                      // xfade7_impl::x1_t<NV>
		auto& switcher_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);     // xfade7_impl::switcher_x1_t<NV>
		auto& sb_container_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1); // xfade7_impl::sb_container_x1_t<NV>
		auto& sb1_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade7_impl::sb1_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(0);
		auto& chain1_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade7_impl::chain1_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(0).
                          getT(0);
		auto& xfader_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                       // xfade7_impl::xfader_x1_t<NV>
                          getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& pma8 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade7_impl::pma8_t<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& chain26 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade7_impl::chain26_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2);
		auto& split20 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade7_impl::split20_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).
                        getT(0);
		auto& smoothed_parameter1_x4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::smoothed_parameter1_x4_t<NV>
                                       getT(1).getT(0).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).    // xfade7_impl::smoothed_parameter17_t<NV>
                                     getT(1).getT(0).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                  // xfade7_impl::input_toggle16_t<NV>
                               getT(0).getT(1).getT(0).getT(0).getT(2).
                               getT(1);
		auto& pma9 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade7_impl::pma9_t<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(2).
                     getT(2);
		auto& gain16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).
                       getT(3);
		auto& sb2_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade7_impl::sb2_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& chain3_x1_x1 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade7_impl::chain3_x1_x1_t<NV>
                             getT(0).getT(0).getT(1).getT(1).
                             getT(0);
		auto& xfader2_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade7_impl::xfader2_x1_t<NV>
                           getT(0).getT(1).getT(1).getT(0).getT(0);
		auto& pma10 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade7_impl::pma10_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(1);
		auto& chain7 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade7_impl::chain7_t<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2);
		auto& split4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade7_impl::split4_t<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter1_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::smoothed_parameter1_x1_t<NV>
                                       getT(1).getT(1).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade7_impl::smoothed_parameter1_t<NV>
                                    getT(1).getT(1).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade7_impl::input_toggle2_t<NV>
                              getT(0).getT(1).getT(1).getT(0).getT(2).
                              getT(1);
		auto& pma11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade7_impl::pma11_t<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(2).
                      getT(2);
		auto& gain1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(1).getT(0).getT(2).
                      getT(3);
		auto& sb3_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade7_impl::sb3_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(2);
		auto& chain2_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade7_impl::chain2_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(2).
                          getT(0);
		auto& xfader1_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade7_impl::xfader1_x1_t<NV>
                           getT(0).getT(1).getT(2).getT(0).getT(0);
		auto& pma12 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade7_impl::pma12_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(1);
		auto& chain12 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade7_impl::chain12_t<NV>
                        getT(0).getT(1).getT(2).getT(0).getT(2);
		auto& split6 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade7_impl::split6_t<NV>
                       getT(0).getT(1).getT(2).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter2_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::smoothed_parameter2_x1_t<NV>
                                       getT(1).getT(2).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade7_impl::smoothed_parameter3_t<NV>
                                    getT(1).getT(2).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade7_impl::input_toggle4_t<NV>
                              getT(0).getT(1).getT(2).getT(0).getT(2).
                              getT(1);
		auto& pma13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade7_impl::pma13_t<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(3);
		auto& gain2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(2).getT(0).getT(4);
		auto& sb4_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade7_impl::sb4_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(3);
		auto& chain4_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade7_impl::chain4_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& xfader3_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade7_impl::xfader3_x1_t<NV>
                           getT(0).getT(1).getT(3).getT(0).getT(0);
		auto& pma17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade7_impl::pma17_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(1);
		auto& chain13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade7_impl::chain13_t<NV>
                        getT(0).getT(1).getT(3).getT(0).getT(2);
		auto& split8 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade7_impl::split8_t<NV>
                       getT(0).getT(1).getT(3).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter4_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::smoothed_parameter4_x1_t<NV>
                                       getT(1).getT(3).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade7_impl::smoothed_parameter4_t<NV>
                                    getT(1).getT(3).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade7_impl::input_toggle5_t<NV>
                              getT(0).getT(1).getT(3).getT(0).getT(2).
                              getT(1);
		auto& pma15 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade7_impl::pma15_t<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(2).
                      getT(2);
		auto& gain3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(3).getT(0).getT(3);
		auto& sb5_x1 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade7_impl::sb5_x1_t<NV>
                       getT(0).getT(0).getT(1).getT(4);
		auto& chain5_x1 = this->getT(1).getT(0).getT(0).getT(1).                               // xfade7_impl::chain5_x1_t<NV>
                          getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& xfader4_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                      // xfade7_impl::xfader4_x1_t<NV>
                           getT(0).getT(1).getT(4).getT(0).getT(0);
		auto& pma14 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade7_impl::pma14_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(1);
		auto& chain11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade7_impl::chain11_t<NV>
                        getT(0).getT(1).getT(4).getT(0).getT(2);
		auto& split5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // xfade7_impl::split5_t<NV>
                       getT(0).getT(1).getT(4).getT(0).getT(2).
                       getT(0);
		auto& smoothed_parameter3_x1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::smoothed_parameter3_x1_t<NV>
                                       getT(1).getT(4).getT(0).getT(2).getT(0).getT(0);
		auto& smoothed_parameter2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).     // xfade7_impl::smoothed_parameter2_t<NV>
                                    getT(1).getT(4).getT(0).getT(2).getT(0).getT(1);
		auto& input_toggle3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                   // xfade7_impl::input_toggle3_t<NV>
                              getT(0).getT(1).getT(4).getT(0).getT(2).
                              getT(1);
		auto& pma16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade7_impl::pma16_t<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(2).
                      getT(2);
		auto& gain4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                      getT(0).getT(1).getT(4).getT(0).getT(3);
		auto& sb5_x4 = this->getT(1).getT(0).getT(0).getT(1).                                  // xfade7_impl::sb5_x4_t<NV>
                       getT(0).getT(0).getT(1).getT(5);
		auto& soft_bypass3 = this->getT(1).getT(0).getT(0).getT(1).                            // xfade7_impl::soft_bypass3_t<NV>
                             getT(0).getT(0).getT(1).getT(5).
                             getT(0);
		auto& chain5_x5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                       // xfade7_impl::chain5_x5_t<NV>
                          getT(0).getT(1).getT(5).getT(0).getT(0);
		auto& pma2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                            // xfade7_impl::pma2_t<NV>
                     getT(0).getT(1).getT(5).getT(0).getT(0).
                     getT(0);
		auto& modchain2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                       // xfade7_impl::modchain2_t<NV>
                          getT(0).getT(1).getT(5).getT(0).getT(0).
                          getT(1);
		auto& split1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                  // xfade7_impl::split1_t<NV>
                       getT(1).getT(5).getT(0).getT(0).getT(1).getT(0);
		auto& chain28 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade7_impl::chain28_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(0);
		auto& cable_table3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).    // xfade7_impl::cable_table3_t
                             getT(5).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& chain38 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade7_impl::chain38_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(1);
		auto& cable_table5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).    // xfade7_impl::cable_table5_t
                             getT(5).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);
		auto& chain39 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade7_impl::chain39_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(2);
		auto& cable_table7 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).    // xfade7_impl::cable_table7_t
                             getT(5).getT(0).getT(0).getT(1).getT(0).getT(2).getT(0);
		auto& chain40 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade7_impl::chain40_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(3);
		auto& cable_table9 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).    // xfade7_impl::cable_table9_t
                             getT(5).getT(0).getT(0).getT(1).getT(0).getT(3).getT(0);
		auto& chain41 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade7_impl::chain41_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(4);
		auto& cable_table11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).   // xfade7_impl::cable_table11_t
                              getT(5).getT(0).getT(0).getT(1).getT(0).getT(4).getT(0);
		auto& chain42 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade7_impl::chain42_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(5);
		auto& cable_table13 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).   // xfade7_impl::cable_table13_t
                              getT(5).getT(0).getT(0).getT(1).getT(0).getT(5).getT(0);
		auto& chain43 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade7_impl::chain43_t<NV>
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(6);
		auto& cable_table15 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).   // xfade7_impl::cable_table15_t<NV>
                              getT(5).getT(0).getT(0).getT(1).getT(0).getT(6).getT(0);
		auto& chain44 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade7_impl::chain44_t
                        getT(1).getT(5).getT(0).getT(0).getT(1).getT(0).
                        getT(7);
		auto& cable_table16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).   // xfade7_impl::cable_table16_t
                              getT(5).getT(0).getT(0).getT(1).getT(0).getT(7).getT(0);
		auto& cable_table17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).           // xfade7_impl::cable_table17_t<NV>
                              getT(1).getT(5).getT(0).getT(0).getT(1).getT(1);
		auto& pma40 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                           // xfade7_impl::pma40_t<NV>
                      getT(0).getT(1).getT(5).getT(0).getT(0).
                      getT(2);
		auto& chain45 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // xfade7_impl::chain45_t<NV>
                        getT(0).getT(1).getT(5).getT(0).getT(0).
                        getT(3);
		auto& split23 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).                 // xfade7_impl::split23_t<NV>
                        getT(1).getT(5).getT(0).getT(0).getT(3).getT(0);
		auto& smoothed_parameter3_x5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::smoothed_parameter3_x5_t<NV>
                                       getT(1).getT(5).getT(0).getT(0).getT(3).getT(0).
                                       getT(0);
		auto& smoothed_parameter16 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::smoothed_parameter16_t<NV>
                                     getT(1).getT(5).getT(0).getT(0).getT(3).getT(0).
                                     getT(1);
		auto& input_toggle18 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::input_toggle18_t<NV>
                               getT(1).getT(5).getT(0).getT(0).getT(3).getT(1);
		auto& pma41 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::pma41_t<NV>
                      getT(1).getT(5).getT(0).getT(0).getT(3).getT(2);
		auto& gain17 = this->getT(1).getT(0).getT(0).getT(1).getT(0).  // core::gain<NV>
                       getT(0).getT(1).getT(5).getT(0).getT(0).
                       getT(4);
		auto& sb4 = this->getT(1).getT(0).getT(0).getT(1).getT(1); // xfade7_impl::sb4_t
		auto& sb5 = this->getT(1).getT(0).getT(0).getT(1).getT(2); // xfade7_impl::sb5_t
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& XF1_smooth_x1_p = XF1.getParameterT(0);
		XF1_smooth_x1_p.connectT(0, smoothed_parameter2_x1);  // smooth_x1 -> smoothed_parameter2_x1::SmoothingTime
		XF1_smooth_x1_p.connectT(1, smoothed_parameter4_x1);  // smooth_x1 -> smoothed_parameter4_x1::SmoothingTime
		XF1_smooth_x1_p.connectT(2, smoothed_parameter3_x1);  // smooth_x1 -> smoothed_parameter3_x1::SmoothingTime
		XF1_smooth_x1_p.connectT(3, smoothed_parameter3);     // smooth_x1 -> smoothed_parameter3::SmoothingTime
		XF1_smooth_x1_p.connectT(4, smoothed_parameter4);     // smooth_x1 -> smoothed_parameter4::SmoothingTime
		XF1_smooth_x1_p.connectT(5, smoothed_parameter2);     // smooth_x1 -> smoothed_parameter2::SmoothingTime
		XF1_smooth_x1_p.connectT(6, smoothed_parameter1_x4);  // smooth_x1 -> smoothed_parameter1_x4::SmoothingTime
		XF1_smooth_x1_p.connectT(7, smoothed_parameter17);    // smooth_x1 -> smoothed_parameter17::SmoothingTime
		XF1_smooth_x1_p.connectT(8, smoothed_parameter1_x1);  // smooth_x1 -> smoothed_parameter1_x1::SmoothingTime
		XF1_smooth_x1_p.connectT(9, smoothed_parameter1);     // smooth_x1 -> smoothed_parameter1::SmoothingTime
		XF1_smooth_x1_p.connectT(10, smoothed_parameter3_x5); // smooth_x1 -> smoothed_parameter3_x5::SmoothingTime
		XF1_smooth_x1_p.connectT(11, smoothed_parameter16);   // smooth_x1 -> smoothed_parameter16::SmoothingTime
		
		auto& XF1_SmoothType_p = XF1.getParameterT(1);
		XF1_SmoothType_p.connectT(0, input_toggle2);  // SmoothType -> input_toggle2::Input
		XF1_SmoothType_p.connectT(1, input_toggle4);  // SmoothType -> input_toggle4::Input
		XF1_SmoothType_p.connectT(2, input_toggle5);  // SmoothType -> input_toggle5::Input
		XF1_SmoothType_p.connectT(3, input_toggle3);  // SmoothType -> input_toggle3::Input
		XF1_SmoothType_p.connectT(4, input_toggle16); // SmoothType -> input_toggle16::Input
		XF1_SmoothType_p.connectT(5, input_toggle18); // SmoothType -> input_toggle18::Input
		this->getParameterT(0).connectT(0, pma7);     // MainParam -> pma7::Add
		
		this->getParameterT(1).connectT(0, XF1); // _2ndParam -> XF1::smooth_x1
		
		this->getParameterT(2).connectT(0, switcher_x1); // _3rdParam -> switcher_x1::Value
		
		this->getParameterT(3).connectT(0, XF1); // _4thParam -> XF1::SmoothType
		
		this->getParameterT(4).connectT(0, switcher1); // _5thParam -> switcher1::Value
		
		this->getParameterT(5).connectT(0, pma); // Poly -> pma::Multiply
		
		this->getParameterT(6).connectT(0, pma7); // Global -> pma7::Multiply
		
		this->getParameterT(7).connectT(0, event_data_reader7); // GlobalSrc -> event_data_reader7::SlotIndex
		
		this->getParameterT(8).connectT(0, pma3); // Vel -> pma3::Multiply
		
		this->getParameterT(9).connectT(0, pma4); // Trk -> pma4::Multiply
		
		this->getParameterT(10).connectT(0, pma5); // MW -> pma5::Multiply
		
		this->getParameterT(11).connectT(0, pma6); // AT -> pma6::Multiply
		
		this->getParameterT(12).connectT(0, branch3); // MonoSrc -> branch3::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma9.getWrappedObject().getParameter().connectT(0, gain16);                 // pma9 -> gain16::Gain
		input_toggle16.getWrappedObject().getParameter().connectT(0, pma9);         // input_toggle16 -> pma9::Add
		smoothed_parameter1_x4.getParameter().connectT(0, input_toggle16);          // smoothed_parameter1_x4 -> input_toggle16::Value1
		smoothed_parameter17.getParameter().connectT(0, input_toggle16);            // smoothed_parameter17 -> input_toggle16::Value2
		pma8.getWrappedObject().getParameter().connectT(0, smoothed_parameter1_x4); // pma8 -> smoothed_parameter1_x4::Value
		pma8.getWrappedObject().getParameter().connectT(1, smoothed_parameter17);   // pma8 -> smoothed_parameter17::Value
		auto& xfader_x1_p = xfader_x1.getWrappedObject().getParameter();
		xfader_x1_p.getParameterT(6).connectT(0, pma8);                              // xfader_x1 -> pma8::Add
		pma11.getWrappedObject().getParameter().connectT(0, gain1);                  // pma11 -> gain1::Gain
		input_toggle2.getWrappedObject().getParameter().connectT(0, pma11);          // input_toggle2 -> pma11::Add
		smoothed_parameter1.getParameter().connectT(0, input_toggle2);               // smoothed_parameter1 -> input_toggle2::Value2
		smoothed_parameter1_x1.getParameter().connectT(0, input_toggle2);            // smoothed_parameter1_x1 -> input_toggle2::Value1
		pma10.getWrappedObject().getParameter().connectT(0, smoothed_parameter1);    // pma10 -> smoothed_parameter1::Value
		pma10.getWrappedObject().getParameter().connectT(1, smoothed_parameter1_x1); // pma10 -> smoothed_parameter1_x1::Value
		auto& xfader2_x1_p = xfader2_x1.getWrappedObject().getParameter();
		xfader2_x1_p.getParameterT(6).connectT(0, pma10);                            // xfader2_x1 -> pma10::Add
		pma13.getWrappedObject().getParameter().connectT(0, gain2);                  // pma13 -> gain2::Gain
		input_toggle4.getWrappedObject().getParameter().connectT(0, pma13);          // input_toggle4 -> pma13::Add
		smoothed_parameter2_x1.getParameter().connectT(0, input_toggle4);            // smoothed_parameter2_x1 -> input_toggle4::Value1
		smoothed_parameter3.getParameter().connectT(0, input_toggle4);               // smoothed_parameter3 -> input_toggle4::Value2
		pma12.getWrappedObject().getParameter().connectT(0, smoothed_parameter2_x1); // pma12 -> smoothed_parameter2_x1::Value
		pma12.getWrappedObject().getParameter().connectT(1, smoothed_parameter3);    // pma12 -> smoothed_parameter3::Value
		auto& xfader1_x1_p = xfader1_x1.getWrappedObject().getParameter();
		xfader1_x1_p.getParameterT(6).connectT(0, pma12);                            // xfader1_x1 -> pma12::Add
		pma15.getWrappedObject().getParameter().connectT(0, gain3);                  // pma15 -> gain3::Gain
		input_toggle5.getWrappedObject().getParameter().connectT(0, pma15);          // input_toggle5 -> pma15::Add
		smoothed_parameter4_x1.getParameter().connectT(0, input_toggle5);            // smoothed_parameter4_x1 -> input_toggle5::Value1
		smoothed_parameter4.getParameter().connectT(0, input_toggle5);               // smoothed_parameter4 -> input_toggle5::Value2
		pma17.getWrappedObject().getParameter().connectT(0, smoothed_parameter4_x1); // pma17 -> smoothed_parameter4_x1::Value
		pma17.getWrappedObject().getParameter().connectT(1, smoothed_parameter4);    // pma17 -> smoothed_parameter4::Value
		auto& xfader3_x1_p = xfader3_x1.getWrappedObject().getParameter();
		xfader3_x1_p.getParameterT(6).connectT(0, pma17);                            // xfader3_x1 -> pma17::Add
		pma16.getWrappedObject().getParameter().connectT(0, gain4);                  // pma16 -> gain4::Gain
		input_toggle3.getWrappedObject().getParameter().connectT(0, pma16);          // input_toggle3 -> pma16::Add
		smoothed_parameter3_x1.getParameter().connectT(0, input_toggle3);            // smoothed_parameter3_x1 -> input_toggle3::Value1
		smoothed_parameter2.getParameter().connectT(0, input_toggle3);               // smoothed_parameter2 -> input_toggle3::Value2
		pma14.getWrappedObject().getParameter().connectT(0, smoothed_parameter3_x1); // pma14 -> smoothed_parameter3_x1::Value
		pma14.getWrappedObject().getParameter().connectT(1, smoothed_parameter2);    // pma14 -> smoothed_parameter2::Value
		auto& xfader4_x1_p = xfader4_x1.getWrappedObject().getParameter();
		xfader4_x1_p.getParameterT(6).connectT(0, pma14);                            // xfader4_x1 -> pma14::Add
		pma41.getWrappedObject().getParameter().connectT(0, gain17);                 // pma41 -> gain17::Gain
		input_toggle18.getWrappedObject().getParameter().connectT(0, pma41);         // input_toggle18 -> pma41::Add
		smoothed_parameter3_x5.getParameter().connectT(0, input_toggle18);           // smoothed_parameter3_x5 -> input_toggle18::Value1
		smoothed_parameter16.getParameter().connectT(0, input_toggle18);             // smoothed_parameter16 -> input_toggle18::Value2
		pma40.getWrappedObject().getParameter().connectT(0, smoothed_parameter3_x5); // pma40 -> smoothed_parameter3_x5::Value
		pma40.getWrappedObject().getParameter().connectT(1, smoothed_parameter16);   // pma40 -> smoothed_parameter16::Value
		cable_table17.getWrappedObject().getParameter().connectT(0, pma40);          // cable_table17 -> pma40::Add
		cable_table15.getWrappedObject().getParameter().connectT(0, cable_table17);  // cable_table15 -> cable_table17::Value
		pma2.getWrappedObject().getParameter().connectT(0, cable_table3);            // pma2 -> cable_table3::Value
		pma2.getWrappedObject().getParameter().connectT(1, cable_table5);            // pma2 -> cable_table5::Value
		pma2.getWrappedObject().getParameter().connectT(2, cable_table7);            // pma2 -> cable_table7::Value
		pma2.getWrappedObject().getParameter().connectT(3, cable_table9);            // pma2 -> cable_table9::Value
		pma2.getWrappedObject().getParameter().connectT(4, cable_table11);           // pma2 -> cable_table11::Value
		pma2.getWrappedObject().getParameter().connectT(5, cable_table13);           // pma2 -> cable_table13::Value
		pma2.getWrappedObject().getParameter().connectT(6, cable_table15);           // pma2 -> cable_table15::Value
		pma2.getWrappedObject().getParameter().connectT(7, cable_table16);           // pma2 -> cable_table16::Value
		pma.getWrappedObject().getParameter().connectT(0, xfader_x1);                // pma -> xfader_x1::Value
		pma.getWrappedObject().getParameter().connectT(1, xfader2_x1);               // pma -> xfader2_x1::Value
		pma.getWrappedObject().getParameter().connectT(2, xfader1_x1);               // pma -> xfader1_x1::Value
		pma.getWrappedObject().getParameter().connectT(3, xfader3_x1);               // pma -> xfader3_x1::Value
		pma.getWrappedObject().getParameter().connectT(4, xfader4_x1);               // pma -> xfader4_x1::Value
		pma.getWrappedObject().getParameter().connectT(5, pma2);                     // pma -> pma2::Add
		pma3.getWrappedObject().getParameter().connectT(0, pma);                     // pma3 -> pma::Add
		midi.getParameter().connectT(0, pma3);                                       // midi -> pma3::Value
		pma4.getWrappedObject().getParameter().connectT(0, pma3);                    // pma4 -> pma3::Add
		midi1.getParameter().connectT(0, pma4);                                      // midi1 -> pma4::Value
		pma5.getWrappedObject().getParameter().connectT(0, pma4);                    // pma5 -> pma4::Add
		midi_cc.getWrappedObject().getParameter().connectT(0, pma5);                 // midi_cc -> pma5::Value
		pma6.getWrappedObject().getParameter().connectT(0, pma5);                    // pma6 -> pma5::Add
		midi_cc1.getWrappedObject().getParameter().connectT(0, pma6);                // midi_cc1 -> pma6::Value
		pma7.getWrappedObject().getParameter().connectT(0, pma6);                    // pma7 -> pma6::Add
		event_data_reader7.getParameter().connectT(0, pma7);                         // event_data_reader7 -> pma7::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add16);         // global_cable16 -> add16::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add17);         // global_cable17 -> add17::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add18);         // global_cable18 -> add18::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add19);         // global_cable19 -> add19::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add20);         // global_cable20 -> add20::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add21);         // global_cable21 -> add21::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add22);         // global_cable22 -> add22::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add23);         // global_cable23 -> add23::Value
		peak2.getParameter().connectT(0, pma);                                       // peak2 -> pma::Value
		auto& switcher_x1_p = switcher_x1.getWrappedObject().getParameter();
		switcher_x1_p.getParameterT(0).connectT(0, sb1_x1); // switcher_x1 -> sb1_x1::Bypassed
		switcher_x1_p.getParameterT(1).connectT(0, sb2_x1); // switcher_x1 -> sb2_x1::Bypassed
		switcher_x1_p.getParameterT(2).connectT(0, sb3_x1); // switcher_x1 -> sb3_x1::Bypassed
		switcher_x1_p.getParameterT(3).connectT(0, sb4_x1); // switcher_x1 -> sb4_x1::Bypassed
		switcher_x1_p.getParameterT(4).connectT(0, sb5_x1); // switcher_x1 -> sb5_x1::Bypassed
		switcher_x1_p.getParameterT(5).connectT(0, sb5_x4); // switcher_x1 -> sb5_x4::Bypassed
		auto& switcher1_p = switcher1.getWrappedObject().getParameter();
		switcher1_p.getParameterT(0).connectT(0, sb3); // switcher1 -> sb3::Bypassed
		switcher1_p.getParameterT(1).connectT(0, sb4); // switcher1 -> sb4::Bypassed
		switcher1_p.getParameterT(2).connectT(0, sb5); // switcher1 -> sb5::Bypassed
		
		// Default Values --------------------------------------------------------------------------
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
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
		
		;                                        // event_data_reader7::SlotIndex is automated
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
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
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		; // XF1::smooth_x1 is automated
		; // XF1::SmoothType is automated
		
		; // switcher1::Value is automated
		
		x1.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher_x1::Value is automated
		
		; // xfader_x1::Value is automated
		
		pma8.setParameterT(0, 0.); // control::pma::Value
		pma8.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma8::Add is automated
		
		;                                            // smoothed_parameter1_x4::Value is automated
		;                                            // smoothed_parameter1_x4::SmoothingTime is automated
		smoothed_parameter1_x4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter17::Value is automated
		;                                          // smoothed_parameter17::SmoothingTime is automated
		smoothed_parameter17.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle16::Input is automated
		; // input_toggle16::Value1 is automated
		; // input_toggle16::Value2 is automated
		
		pma9.setParameterT(0, 0.); // control::pma::Value
		pma9.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma9::Add is automated
		
		;                               // gain16::Gain is automated
		gain16.setParameterT(1, 0.);    // core::gain::Smoothing
		gain16.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader2_x1::Value is automated
		
		pma10.setParameterT(0, 0.); // control::pma::Value
		pma10.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma10::Add is automated
		
		;                                            // smoothed_parameter1_x1::Value is automated
		;                                            // smoothed_parameter1_x1::SmoothingTime is automated
		smoothed_parameter1_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter1::Value is automated
		;                                         // smoothed_parameter1::SmoothingTime is automated
		smoothed_parameter1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle2::Input is automated
		; // input_toggle2::Value1 is automated
		; // input_toggle2::Value2 is automated
		
		pma11.setParameterT(0, 0.); // control::pma::Value
		pma11.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma11::Add is automated
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 0.);    // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader1_x1::Value is automated
		
		pma12.setParameterT(0, 0.); // control::pma::Value
		pma12.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma12::Add is automated
		
		;                                            // smoothed_parameter2_x1::Value is automated
		;                                            // smoothed_parameter2_x1::SmoothingTime is automated
		smoothed_parameter2_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter3::Value is automated
		;                                         // smoothed_parameter3::SmoothingTime is automated
		smoothed_parameter3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle4::Input is automated
		; // input_toggle4::Value1 is automated
		; // input_toggle4::Value2 is automated
		
		pma13.setParameterT(0, 0.); // control::pma::Value
		pma13.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma13::Add is automated
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 0.);    // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader3_x1::Value is automated
		
		pma17.setParameterT(0, 0.); // control::pma::Value
		pma17.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma17::Add is automated
		
		;                                            // smoothed_parameter4_x1::Value is automated
		;                                            // smoothed_parameter4_x1::SmoothingTime is automated
		smoothed_parameter4_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter4::Value is automated
		;                                         // smoothed_parameter4::SmoothingTime is automated
		smoothed_parameter4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle5::Input is automated
		; // input_toggle5::Value1 is automated
		; // input_toggle5::Value2 is automated
		
		pma15.setParameterT(0, 0.); // control::pma::Value
		pma15.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma15::Add is automated
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 0.);    // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader4_x1::Value is automated
		
		pma14.setParameterT(0, 0.); // control::pma::Value
		pma14.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma14::Add is automated
		
		;                                            // smoothed_parameter3_x1::Value is automated
		;                                            // smoothed_parameter3_x1::SmoothingTime is automated
		smoothed_parameter3_x1.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                         // smoothed_parameter2::Value is automated
		;                                         // smoothed_parameter2::SmoothingTime is automated
		smoothed_parameter2.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle3::Input is automated
		; // input_toggle3::Value1 is automated
		; // input_toggle3::Value2 is automated
		
		pma16.setParameterT(0, 0.); // control::pma::Value
		pma16.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma16::Add is automated
		
		;                              // gain4::Gain is automated
		gain4.setParameterT(1, 0.);    // core::gain::Smoothing
		gain4.setParameterT(2, -100.); // core::gain::ResetValue
		
		pma2.setParameterT(0, 0.); // control::pma::Value
		pma2.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma2::Add is automated
		
		; // cable_table3::Value is automated
		
		; // cable_table5::Value is automated
		
		; // cable_table7::Value is automated
		
		; // cable_table9::Value is automated
		
		; // cable_table11::Value is automated
		
		; // cable_table13::Value is automated
		
		; // cable_table15::Value is automated
		
		; // cable_table16::Value is automated
		
		; // cable_table17::Value is automated
		
		pma40.setParameterT(0, 0.); // control::pma::Value
		pma40.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma40::Add is automated
		
		;                                            // smoothed_parameter3_x5::Value is automated
		;                                            // smoothed_parameter3_x5::SmoothingTime is automated
		smoothed_parameter3_x5.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter16::Value is automated
		;                                          // smoothed_parameter16::SmoothingTime is automated
		smoothed_parameter16.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle18::Input is automated
		; // input_toggle18::Value1 is automated
		; // input_toggle18::Value2 is automated
		
		pma41.setParameterT(0, 0.); // control::pma::Value
		pma41.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma41::Add is automated
		
		;                               // gain17::Gain is automated
		gain17.setParameterT(1, 0.);    // core::gain::Smoothing
		gain17.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.5);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.982771);
		this->setParameterT(4, 0.548141);
		this->setParameterT(5, -0.622853);
		this->setParameterT(6, -0.0635476);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade7_impl::global_cable16_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade7_impl::global_cable17_t<NV>
        getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade7_impl::global_cable18_t<NV>
        getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade7_impl::global_cable19_t<NV>
        getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade7_impl::global_cable20_t<NV>
        getT(0).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade7_impl::global_cable21_t<NV>
        getT(0).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade7_impl::global_cable22_t<NV>
        getT(0).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(4).getT(0).  // xfade7_impl::global_cable23_t<NV>
        getT(0).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(4).                          // xfade7_impl::peak2_t<NV>
        getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade7_impl::cable_table3_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade7_impl::cable_table5_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade7_impl::cable_table7_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(2).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade7_impl::cable_table9_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade7_impl::cable_table11_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(4).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade7_impl::cable_table13_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(5).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade7_impl::cable_table15_t<NV>
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(6).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).  // xfade7_impl::cable_table16_t
        getT(5).getT(0).getT(0).getT(1).getT(0).getT(7).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).  // xfade7_impl::cable_table17_t<NV>
        getT(1).getT(5).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);
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
using xfade7 = wrap::node<xfade7_impl::instance<NV>>;
}


