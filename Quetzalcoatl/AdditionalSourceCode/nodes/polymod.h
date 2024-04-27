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
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;
using cable_table8_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<1>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  parameter::plain<cable_pack_t<NV>, 0>, 
                                  parameter::plain<cable_table8_t, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync_t<NV>>, 
                                    ramp_t<NV>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, cable_table_t<NV>>, 
                                math::add<NV>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb2_t<NV>>;

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
using switcher_c1 = parameter::bypass<sb6_t<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0<NV>, switcher_c1<NV>>;

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
                                        wrap::fix<1, sb2_t<NV>>, 
                                        sb6_t<NV>>;

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
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, branch_t<NV>>>;

template <int NV>
using peak1_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<routing::public_mod, 0>>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

namespace polymod_t_parameters
{
// Parameter list for polymod_impl::polymod_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE(modsel_InputRange, 
                        0., 
                        4.);

template <int NV>
using modsel = parameter::chain<modsel_InputRange, 
                                parameter::plain<polymod_impl::cable_table1_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(XfModSrc_InputRange, 
                             0., 
                             3., 
                             0.1);

template <int NV>
using XfModSrc = parameter::chain<XfModSrc_InputRange, 
                                  parameter::plain<polymod_impl::branch_t<NV>, 0>>;

using attack1 = parameter::empty;
using decay1 = attack1;
using sus1 = attack1;
using rel1 = attack1;
template <int NV>
using tempo = parameter::plain<polymod_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using mul = parameter::plain<polymod_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using one = parameter::plain<polymod_impl::ramp_t<NV>, 
                             1>;
using LfoMode = attack1;
template <int NV>
using tempo2 = parameter::plain<polymod_impl::tempo_sync_t<NV>, 
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
using Gate1 = attack1;
using Gate2 = attack1;
using Gate3 = attack1;
using Gate4 = attack1;
using Gate5 = attack1;
using Gate6 = attack1;
using Gate7 = attack1;
using Gate8 = attack1;
using A = attack1;
using H = attack1;
template <int NV>
using D = parameter::plain<polymod_impl::tempo_sync_t<NV>, 
                           2>;
using R = attack1;
using XF = attack1;
using XFsmooth = attack1;
using XfMod = attack1;
using vel = attack1;
using trk = attack1;
using mw = attack1;
using aft = attack1;
using XfModer = attack1;
template <int NV>
using polymod_t_plist = parameter::list<attack1, 
                                        decay1, 
                                        sus1, 
                                        rel1, 
                                        tempo<NV>, 
                                        mul<NV>, 
                                        one<NV>, 
                                        modsel<NV>, 
                                        LfoMode, 
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
                                        A, 
                                        H, 
                                        D<NV>, 
                                        R, 
                                        XF, 
                                        XFsmooth, 
                                        XfMod, 
                                        XfModSrc<NV>, 
                                        vel, 
                                        trk, 
                                        mw, 
                                        aft, 
                                        XfModer>;
}

template <int NV>
using polymod_t_ = container::chain<polymod_t_parameters::polymod_t_plist<NV>, 
                                    wrap::fix<1, split_t<NV>>, 
                                    peak1_t<NV>, 
                                    math::clear<NV>, 
                                    math::add<NV>, 
                                    routing::public_mod>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance:  public polymod_impl::polymod_t_<NV>,
                                    public routing::public_mod_target
{
	
	struct metadata
	{
		static const int NumTables = 2;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(polymod);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(596)
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
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x055B, 0x0000, 
            0x6D00, 0x6C75, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0xC000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0006, 0x0000, 0x6E6F, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x6D00, 0x646F, 0x6573, 
            0x006C, 0x0000, 0x0000, 0x0000, 0x4080, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 0x4C00, 0x6F66, 0x6F4D, 
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
            0x0000, 0x0044, 0x0000, 0x0000, 0x0000, 0x3F80, 0x4000, 0x461C, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x1D5B, 0x0000, 0x5200, 0x0000, 
            0x0000, 0x0000, 0x9C40, 0x0046, 0x9CF0, 0x9B44, 0x9A20, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x001E, 0x0000, 0x4658, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x001F, 0x0000, 0x4658, 0x6D73, 0x6F6F, 0x6874, 0x0000, 0x0000, 
            0x0000, 0x7A00, 0x0044, 0x8000, 0x9B3F, 0x9A20, 0xCD3E, 0xCCCC, 
            0x5B3D, 0x0020, 0x0000, 0x6658, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x215B, 0x0000, 0x5800, 0x4D66, 0x646F, 0x7253, 0x0063, 0x0000, 
            0x0000, 0x0000, 0x4040, 0x0000, 0x0000, 0x0000, 0x3F80, 0xCCCD, 
            0x3DCC, 0x225B, 0x0000, 0x7600, 0x6C65, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0023, 0x0000, 0x7274, 0x006B, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x245B, 0x0000, 
            0x6D00, 0x0077, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x255B, 0x0000, 0x6100, 0x7466, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0026, 0x0000, 0x6658, 0x6F4D, 0x6564, 
            0x0072, 0x0000, 0x0000, 0x0000, 0x40A0, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0xCCCD, 0x3DCC, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split = this->getT(0);                                                       // polymod_impl::split_t<NV>
		auto& branch = this->getT(0).getT(0);                                              // polymod_impl::branch_t<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0);                                      // polymod_impl::chain8_t<NV>
		auto& clear = this->getT(0).getT(0).getT(0).getT(0);                               // math::clear<NV>
		auto& no_midi = this->getT(0).getT(0).getT(0).getT(1);                             // polymod_impl::no_midi_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(0).getT(1).getT(0);                  // polymod_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(0).getT(0).getT(0).getT(1).getT(1);                        // polymod_impl::ramp_t<NV>
		auto& clear6 = this->getT(0).getT(0).getT(0).getT(2);                              // math::clear<NV>
		auto& softbypass_switch6 = this->getT(0).getT(0).getT(0).getT(3);                  // polymod_impl::softbypass_switch6_t<NV>
		auto& cable_table1 = this->getT(0).getT(0).getT(0).getT(3).getT(0);                // polymod_impl::cable_table1_t<NV>
		auto& switcher = this->getT(0).getT(0).getT(0).getT(3).getT(1);                    // polymod_impl::switcher_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(0).getT(3).getT(2);                      // math::clear<NV>
		auto& sb_container = this->getT(0).getT(0).getT(0).getT(3).getT(3);                // polymod_impl::sb_container_t<NV>
		auto& sb2 = this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(0);                 // polymod_impl::sb2_t<NV>
		auto& cable_table = this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(0).getT(0); // polymod_impl::cable_table_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(0).getT(1);        // math::add<NV>
		auto& sb6 = this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(1);                 // polymod_impl::sb6_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(1).getT(0);      // polymod_impl::split2_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0).getT(3).                               // polymod_impl::chain_t<NV>
                      getT(3).getT(1).getT(0).getT(0);
		auto& pack8_writer = this->getT(0).getT(0).getT(0).getT(3).                 // polymod_impl::pack8_writer_t
                             getT(3).getT(1).getT(0).getT(0).
                             getT(0);
		auto& cable_table8 = this->getT(0).getT(0).getT(0).getT(3).                 // polymod_impl::cable_table8_t
                             getT(3).getT(1).getT(0).getT(0).
                             getT(1);
		auto& clear4 = this->getT(0).getT(0).getT(0).getT(3).                       // math::clear<NV>
                       getT(3).getT(1).getT(0).getT(0).
                       getT(2);
		auto& cable_pack = this->getT(0).getT(0).getT(0).getT(3).                   // polymod_impl::cable_pack_t<NV>
                           getT(3).getT(1).getT(0).getT(0).
                           getT(3);
		auto& add8 = this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(1).getT(1); // math::add<NV>
		auto& peak1 = this->getT(1);                                                // polymod_impl::peak1_t<NV>
		auto& clear3 = this->getT(2);                                               // math::clear<NV>
		auto& add11 = this->getT(3);                                                // math::add<NV>
		auto& public_mod = this->getT(4);                                           // routing::public_mod
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(4).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(5).connectT(0, tempo_sync); // mul -> tempo_sync::Multiplier
		
		this->getParameterT(6).connectT(0, ramp); // one -> ramp::LoopStart
		
		this->getParameterT(7).connectT(0, cable_table1); // modsel -> cable_table1::Value
		
		this->getParameterT(9).connectT(0, tempo_sync); // tempo2 -> tempo_sync::UnsyncedTime
		
		this->getParameterT(10).connectT(0, pack8_writer); // Step1 -> pack8_writer::Value1
		
		this->getParameterT(11).connectT(0, pack8_writer); // Step2 -> pack8_writer::Value2
		
		this->getParameterT(12).connectT(0, pack8_writer); // Step3 -> pack8_writer::Value3
		
		this->getParameterT(13).connectT(0, pack8_writer); // Step4 -> pack8_writer::Value4
		
		this->getParameterT(14).connectT(0, pack8_writer); // Step5 -> pack8_writer::Value5
		
		this->getParameterT(15).connectT(0, pack8_writer); // Step6 -> pack8_writer::Value6
		
		this->getParameterT(16).connectT(0, pack8_writer); // Step7 -> pack8_writer::Value7
		
		this->getParameterT(17).connectT(0, pack8_writer); // Step8 -> pack8_writer::Value8
		
		this->getParameterT(28).connectT(0, tempo_sync); // D -> tempo_sync::Enabled
		
		this->getParameterT(33).connectT(0, branch); // XfModSrc -> branch::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		cable_table.getWrappedObject().getParameter().connectT(0, add1); // cable_table -> add1::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add8);  // cable_pack -> add8::Value
		ramp.getParameter().connectT(0, cable_table);                    // ramp -> cable_table::Value
		ramp.getParameter().connectT(1, cable_pack);                     // ramp -> cable_pack::Value
		ramp.getParameter().connectT(2, cable_table8);                   // ramp -> cable_table8::Value
		tempo_sync.getParameter().connectT(0, ramp);                     // tempo_sync -> ramp::PeriodTime
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb2);                         // switcher -> sb2::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb6);                         // switcher -> sb6::Bypassed
		cable_table1.getWrappedObject().getParameter().connectT(0, switcher); // cable_table1 -> switcher::Value
		peak1.getParameter().connectT(0, add11);                              // peak1 -> add11::Value
		peak1.getParameter().connectT(1, public_mod);                         // peak1 -> public_mod::Value
		
		// Public Mod Connection -------------------------------------------------------------------
		
		public_mod.connect(*this);
		
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
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // add11::Value is automated
		
		; // public_mod::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 10000.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 6.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
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
		this->setParameterT(30, 1.);
		this->setParameterT(31, 1.);
		this->setParameterT(32, 1.);
		this->setParameterT(33, 0.);
		this->setParameterT(34, 1.);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 1.);
		this->setParameterT(37, 1.);
		this->setParameterT(38, 1.);
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
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);                 // polymod_impl::ramp_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).setExternalData(b, index);                 // polymod_impl::cable_table1_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(3).getT(0).getT(0).setExternalData(b, index); // polymod_impl::cable_table_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).                                                   // polymod_impl::pack8_writer_t
        getT(3).getT(1).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(3).   // polymod_impl::cable_table8_t
        getT(3).getT(1).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(3).   // polymod_impl::cable_pack_t<NV>
        getT(3).getT(1).getT(0).getT(0).
        getT(3).setExternalData(b, index);
		this->getT(1).setExternalData(b, index); // polymod_impl::peak1_t<NV>
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


