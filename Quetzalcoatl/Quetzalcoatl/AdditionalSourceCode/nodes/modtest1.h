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

namespace modtest1_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable1_t_index = runtime_target::indexers::fix_hash<3357039>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, global_cable1_t<NV>>, 
                                 math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<3357040>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<3357041>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable3_t<NV>>, 
                                  math::add<NV>>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<3357042>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable4_t<NV>>, 
                                  math::add<NV>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<3357043>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable5_t<NV>>, 
                                  math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<3357044>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable6_t<NV>>, 
                                  math::add<NV>>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<3357045>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable7_t<NV>>, 
                                  math::add<NV>>;
using global_cable8_t_index = runtime_target::indexers::fix_hash<3357046>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   math::add<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<3357047>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<104068257>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<104068258>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<104068259>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;
using global_cable14_t_index = runtime_target::indexers::fix_hash<104068260>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>>;
using global_cable15_t_index = runtime_target::indexers::fix_hash<104068261>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>>;
using global_cable16_t_index = runtime_target::indexers::fix_hash<104068262>;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = runtime_target::indexers::fix_hash<104068263>;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain_t<NV>>, 
                                    chain2_t<NV>, 
                                    chain3_t<NV>, 
                                    chain4_t<NV>, 
                                    chain6_t<NV>, 
                                    chain7_t<NV>, 
                                    chain9_t<NV>, 
                                    chain10_t<NV>, 
                                    chain14_t<NV>, 
                                    chain15_t<NV>, 
                                    chain25_t<NV>, 
                                    chain17_t<NV>, 
                                    chain18_t<NV>, 
                                    chain19_t<NV>, 
                                    chain21_t<NV>, 
                                    chain22_t<NV>>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  parameter::plain<cable_pack_t<NV>, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<ramp_t<NV>, 0>, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma1_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma1_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                     0, 
                                     pma1_modRange>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>>;
using global_cable19_t_index = global_cable1_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;
using global_cable20_t_index = global_cable2_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable3_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = global_cable4_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = global_cable5_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>>;
using global_cable24_t_index = global_cable6_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>>;
using global_cable25_t_index = global_cable7_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>>;
using global_cable26_t_index = global_cable8_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>>;
using global_cable27_t_index = global_cable10_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>>;
using global_cable28_t_index = global_cable11_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   math::add<NV>>;
using global_cable29_t_index = global_cable12_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   math::add<NV>>;
using global_cable30_t_index = global_cable13_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable30_t<NV>>, 
                                   math::add<NV>>;
using global_cable31_t_index = global_cable14_t_index;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable31_t<NV>>, 
                                   math::add<NV>>;
using global_cable32_t_index = global_cable15_t_index;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable32_t<NV>>, 
                                   math::add<NV>>;
using global_cable33_t_index = global_cable16_t_index;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable33_t<NV>>, 
                                   math::add<NV>>;
using global_cable34_t_index = global_cable17_t_index;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable34_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain28_t<NV>>, 
                                    chain30_t<NV>, 
                                    chain31_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>, 
                                    chain36_t<NV>, 
                                    chain37_t<NV>, 
                                    chain38_t<NV>, 
                                    chain39_t<NV>, 
                                    chain40_t<NV>, 
                                    chain42_t<NV>, 
                                    chain43_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>, 
                                    chain54_t<NV>, 
                                    chain55_t<NV>>;

namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 24.0 * value * input) * ((float)2 - Math.PI);;
	}
};
}

namespace custom
{

struct expr8
{
	static float op(float input, float value)
	{
		return input * Math.cos(Math.PI * 12.0 * value * input) * (1 - Math.PI);;
	}
};
}

DECLARE_PARAMETER_RANGE_STEP(cable_table1_modRange, 
                             0., 
                             16., 
                             0.1);

template <int NV>
using cable_table1_mod = parameter::from0To1<fx::bitcrush<NV>, 
                                             0, 
                                             cable_table1_modRange>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998109f, 0.996218f, 0.994327f, 0.992436f, 0.990545f,
		0.988654f, 0.986763f, 0.984872f, 0.982981f, 0.98109f, 0.979199f,
		0.977308f, 0.975417f, 0.973526f, 0.971635f, 0.969744f, 0.967853f,
		0.965962f, 0.964071f, 0.96218f, 0.960289f, 0.958398f, 0.956507f,
		0.954616f, 0.952725f, 0.950834f, 0.948943f, 0.947052f, 0.945162f,
		0.943271f, 0.94138f, 0.939489f, 0.937598f, 0.935707f, 0.933816f,
		0.931925f, 0.930034f, 0.928143f, 0.926252f, 0.924361f, 0.92247f,
		0.920579f, 0.918688f, 0.916797f, 0.914906f, 0.913015f, 0.911124f,
		0.909233f, 0.907342f, 0.905451f, 0.90356f, 0.901669f, 0.899778f,
		0.897887f, 0.895996f, 0.894105f, 0.892214f, 0.890323f, 0.888432f,
		0.886541f, 0.88465f, 0.882759f, 0.880868f, 0.878977f, 0.877086f,
		0.875195f, 0.873304f, 0.871413f, 0.869522f, 0.867631f, 0.86574f,
		0.863849f, 0.861958f, 0.860067f, 0.858176f, 0.856285f, 0.854394f,
		0.852503f, 0.850612f, 0.848721f, 0.84683f, 0.844939f, 0.843048f,
		0.841157f, 0.839266f, 0.837376f, 0.835485f, 0.833594f, 0.831703f,
		0.829812f, 0.827921f, 0.82603f, 0.824139f, 0.822248f, 0.820357f,
		0.818466f, 0.816575f, 0.814684f, 0.812793f, 0.810902f, 0.809011f,
		0.80712f, 0.805229f, 0.803338f, 0.801447f, 0.799556f, 0.797665f,
		0.795774f, 0.793883f, 0.791992f, 0.790101f, 0.78821f, 0.786319f,
		0.784428f, 0.782537f, 0.780646f, 0.778755f, 0.776864f, 0.774973f,
		0.773082f, 0.771191f, 0.7693f, 0.767409f, 0.765518f, 0.763627f,
		0.761736f, 0.759845f, 0.757954f, 0.756063f, 0.754172f, 0.752281f,
		0.75039f, 0.748499f, 0.746608f, 0.744717f, 0.742826f, 0.740935f,
		0.739044f, 0.737153f, 0.735262f, 0.733371f, 0.73148f, 0.729589f,
		0.727699f, 0.725808f, 0.723917f, 0.722026f, 0.720135f, 0.718244f,
		0.716353f, 0.714462f, 0.712571f, 0.71068f, 0.708789f, 0.706898f,
		0.705007f, 0.703116f, 0.701225f, 0.699334f, 0.697443f, 0.695552f,
		0.693661f, 0.69177f, 0.689879f, 0.687988f, 0.686097f, 0.684206f,
		0.682315f, 0.680424f, 0.678533f, 0.676642f, 0.674751f, 0.67286f,
		0.670969f, 0.669078f, 0.667187f, 0.665296f, 0.663405f, 0.661514f,
		0.659623f, 0.657732f, 0.655841f, 0.65395f, 0.652059f, 0.650168f,
		0.648277f, 0.646386f, 0.644495f, 0.642604f, 0.640713f, 0.638822f,
		0.636931f, 0.63504f, 0.633149f, 0.631258f, 0.629367f, 0.627476f,
		0.625585f, 0.623694f, 0.621803f, 0.619913f, 0.618021f, 0.61613f,
		0.61424f, 0.612349f, 0.610458f, 0.608567f, 0.606676f, 0.604785f,
		0.602894f, 0.601003f, 0.599112f, 0.597221f, 0.59533f, 0.593439f,
		0.591548f, 0.589657f, 0.587766f, 0.585875f, 0.583984f, 0.582093f,
		0.580202f, 0.578311f, 0.57642f, 0.574529f, 0.572638f, 0.570747f,
		0.568856f, 0.566965f, 0.565074f, 0.563183f, 0.561292f, 0.559401f,
		0.55751f, 0.555619f, 0.553728f, 0.551837f, 0.549946f, 0.548055f,
		0.546164f, 0.544273f, 0.542382f, 0.540491f, 0.5386f, 0.536709f,
		0.534818f, 0.532927f, 0.531036f, 0.529145f, 0.527254f, 0.525363f,
		0.523472f, 0.521581f, 0.51969f, 0.517799f, 0.515908f, 0.514017f,
		0.512126f, 0.510236f, 0.508344f, 0.506454f, 0.504562f, 0.502672f,
		0.500781f, 0.49889f, 0.496999f, 0.495108f, 0.493217f, 0.491326f,
		0.489435f, 0.487544f, 0.485653f, 0.483762f, 0.481871f, 0.47998f,
		0.478089f, 0.476198f, 0.474307f, 0.472416f, 0.470525f, 0.468634f,
		0.466743f, 0.464852f, 0.462961f, 0.46107f, 0.459179f, 0.457288f,
		0.455397f, 0.453506f, 0.451615f, 0.449724f, 0.447833f, 0.445942f,
		0.444051f, 0.44216f, 0.440269f, 0.438378f, 0.436487f, 0.434596f,
		0.432705f, 0.430814f, 0.428923f, 0.427032f, 0.425141f, 0.42325f,
		0.421359f, 0.419468f, 0.417577f, 0.415686f, 0.413795f, 0.411904f,
		0.410013f, 0.408122f, 0.406231f, 0.404341f, 0.402449f, 0.400558f,
		0.398668f, 0.396776f, 0.394886f, 0.392995f, 0.391104f, 0.389213f,
		0.387322f, 0.385431f, 0.38354f, 0.381649f, 0.379758f, 0.377867f,
		0.375976f, 0.374085f, 0.372194f, 0.370303f, 0.368412f, 0.366521f,
		0.36463f, 0.362739f, 0.360848f, 0.358957f, 0.357066f, 0.355175f,
		0.353284f, 0.351393f, 0.349502f, 0.347611f, 0.34572f, 0.343829f,
		0.341938f, 0.340047f, 0.338156f, 0.336265f, 0.334374f, 0.332483f,
		0.330592f, 0.328701f, 0.32681f, 0.324919f, 0.323028f, 0.321137f,
		0.319246f, 0.317355f, 0.315464f, 0.313573f, 0.311682f, 0.309791f,
		0.3079f, 0.306009f, 0.304118f, 0.302227f, 0.300336f, 0.298445f,
		0.296554f, 0.294663f, 0.292772f, 0.290882f, 0.28899f, 0.2871f,
		0.285209f, 0.283318f, 0.281427f, 0.279536f, 0.277645f, 0.275754f,
		0.273863f, 0.271972f, 0.270081f, 0.26819f, 0.266299f, 0.264408f,
		0.262517f, 0.260626f, 0.258735f, 0.256844f, 0.254953f, 0.253062f,
		0.251171f, 0.24928f, 0.247389f, 0.245498f, 0.243607f, 0.241716f,
		0.239825f, 0.237934f, 0.236043f, 0.234152f, 0.232261f, 0.23037f,
		0.228479f, 0.226588f, 0.224697f, 0.222806f, 0.220915f, 0.219024f,
		0.217133f, 0.215242f, 0.213351f, 0.21146f, 0.209569f, 0.207678f,
		0.205787f, 0.203896f, 0.202005f, 0.200114f, 0.198223f, 0.196332f,
		0.194441f, 0.19255f, 0.190659f, 0.188768f, 0.186877f, 0.184986f,
		0.183096f, 0.181205f, 0.179313f, 0.177423f, 0.175532f, 0.173641f,
		0.17175f, 0.169859f, 0.167968f, 0.166077f, 0.164186f, 0.162295f,
		0.160404f, 0.158513f, 0.156622f, 0.154731f, 0.15284f, 0.150949f,
		0.149058f, 0.147167f, 0.145276f, 0.143385f, 0.141494f, 0.139603f,
		0.137712f, 0.135821f, 0.13393f, 0.132039f, 0.130148f, 0.128257f,
		0.126366f, 0.124475f, 0.122584f, 0.120693f, 0.118802f, 0.116911f,
		0.11502f, 0.113129f, 0.111238f, 0.109347f, 0.107456f, 0.105565f,
		0.103674f, 0.101783f, 0.0998922f, 0.0980012f, 0.0961103f, 0.0942193f,
		0.0923284f, 0.0904373f, 0.0885464f, 0.0866554f, 0.0847644f, 0.0828734f,
		0.0809824f, 0.0790915f, 0.0772004f, 0.0753095f, 0.0734185f, 0.0715275f,
		0.0696365f, 0.0677455f, 0.0658546f, 0.0639635f, 0.0620726f, 0.0601816f,
		0.0582907f, 0.0563998f, 0.0545086f, 0.0526177f, 0.0507267f, 0.0488357f,
		0.0469447f, 0.0450538f, 0.0431628f, 0.0412717f, 0.0393808f, 0.0374898f,
		0.0355988f, 0.0337079f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::embedded::table<cable_table1_t_data>>;
DECLARE_PARAMETER_RANGE(pma_mod_0Range, 
                        0.01, 
                        1.);

template <int NV>
using pma_mod_0 = parameter::from0To1<math::expr<NV, custom::expr3>, 
                                      0, 
                                      pma_mod_0Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 parameter::plain<math::expr<NV, custom::expr8>, 0>, 
                                 parameter::plain<cable_table1_t<NV>, 0>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   peak4_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>>;

template <int NV>
using simple_ar_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                           parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod<NV>>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, simple_ar_t<NV>>, 
                                      math::add<NV>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;
using global_cable57_t_index = global_cable10_t_index;

template <int NV>
using global_cable57_t = routing::global_cable<global_cable57_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable57_t<NV>>, 
                                   math::add<NV>>;
using global_cable58_t_index = global_cable11_t_index;

template <int NV>
using global_cable58_t = routing::global_cable<global_cable58_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable58_t<NV>>, 
                                   math::add<NV>>;
using global_cable59_t_index = global_cable12_t_index;

template <int NV>
using global_cable59_t = routing::global_cable<global_cable59_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable59_t<NV>>, 
                                   math::add<NV>>;
using global_cable60_t_index = global_cable13_t_index;

template <int NV>
using global_cable60_t = routing::global_cable<global_cable60_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable60_t<NV>>, 
                                   math::add<NV>>;
using global_cable61_t_index = global_cable14_t_index;

template <int NV>
using global_cable61_t = routing::global_cable<global_cable61_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable61_t<NV>>, 
                                   math::add<NV>>;
using global_cable62_t_index = global_cable15_t_index;

template <int NV>
using global_cable62_t = routing::global_cable<global_cable62_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable62_t<NV>>, 
                                   math::add<NV>>;
using global_cable63_t_index = global_cable16_t_index;

template <int NV>
using global_cable63_t = routing::global_cable<global_cable63_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable63_t<NV>>, 
                                   math::add<NV>>;
using global_cable64_t_index = global_cable17_t_index;

template <int NV>
using global_cable64_t = routing::global_cable<global_cable64_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable64_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain11_t<NV>>, 
                                    midichain_t<NV>, 
                                    chain62_t<NV>, 
                                    chain63_t<NV>, 
                                    chain64_t<NV>, 
                                    chain65_t<NV>, 
                                    chain66_t<NV>, 
                                    chain67_t<NV>, 
                                    chain68_t<NV>, 
                                    chain70_t<NV>>;

template <int NV>
using input_toggle_t = control::input_toggle<NV, 
                                             parameter::plain<ramp_t<NV>, 2>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   wrap::no_process<math::mod2sig<NV>>, 
                                   wrap::no_process<math::add<NV>>, 
                                   peak6_t<NV>, 
                                   wrap::no_process<math::clear<NV>>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::pi<NV>>, 
                                   math::sin<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::rect<NV>>>;

using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;
using peak5_t = wrap::no_data<core::peak>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, wrap::no_process<math::clear<NV>>>, 
                                   math::sig2mod<NV>, 
                                   peak5_t>;
template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, oscillator_t<NV>>, 
                                   wrap::no_process<math::pi<NV>>, 
                                   fx::sampleandhold<NV>, 
                                   math::sig2mod<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_table_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_pack_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain23_t<NV>>, 
                                   chain8_t<NV>, 
                                   chain5_t, 
                                   chain41_t<NV>, 
                                   chain32_t<NV>, 
                                   chain20_t<NV>, 
                                   chain26_t<NV>>;
using peak_t = wrap::data<core::peak, 
                          data::external::displaybuffer<0>>;

using chain1_t = chain5_t;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr3>>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table1_t<NV>>, 
                                   fx::bitcrush<NV>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr8>>>;

using chain47_t = chain5_t;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain1_t>, 
                                    chain29_t<NV>, 
                                    chain35_t<NV>, 
                                    chain44_t<NV>, 
                                    chain47_t>;
using peak2_t = wrap::data<core::peak, 
                           data::external::displaybuffer<1>>;

using global_cable_t_index = global_cable10_t_index;
using peak3_mod = parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 
                                   0>;
using peak3_t = wrap::mod<peak3_mod, 
                          wrap::no_data<core::peak>>;

using chain13_t = container::chain<parameter::empty, wrap::fix<1, peak3_t>>;

using global_cable39_t_index = global_cable11_t_index;
using peak9_mod = parameter::plain<routing::global_cable<global_cable39_t_index, parameter::empty>, 
                                   0>;
using peak9_t = wrap::mod<peak9_mod, 
                          wrap::no_data<core::peak>>;

using chain16_t = container::chain<parameter::empty, wrap::fix<1, peak9_t>>;

using global_cable38_t_index = global_cable12_t_index;
using peak8_mod = parameter::plain<routing::global_cable<global_cable38_t_index, parameter::empty>, 
                                   0>;
using peak8_t = wrap::mod<peak8_mod, 
                          wrap::no_data<core::peak>>;

using chain24_t = container::chain<parameter::empty, wrap::fix<1, peak8_t>>;

using global_cable37_t_index = global_cable13_t_index;
using peak7_mod = parameter::plain<routing::global_cable<global_cable37_t_index, parameter::empty>, 
                                   0>;
using peak7_t = wrap::mod<peak7_mod, 
                          wrap::no_data<core::peak>>;

using chain50_t = container::chain<parameter::empty, wrap::fix<1, peak7_t>>;

using global_cable36_t_index = global_cable14_t_index;
using peak10_mod = parameter::plain<routing::global_cable<global_cable36_t_index, parameter::empty>, 
                                    0>;
using peak10_t = wrap::mod<peak10_mod, 
                           wrap::no_data<core::peak>>;

using chain51_t = container::chain<parameter::empty, wrap::fix<1, peak10_t>>;

using global_cable35_t_index = global_cable15_t_index;
using peak11_mod = parameter::plain<routing::global_cable<global_cable35_t_index, parameter::empty>, 
                                    0>;
using peak11_t = wrap::mod<peak11_mod, 
                           wrap::no_data<core::peak>>;

using chain59_t = container::chain<parameter::empty, wrap::fix<1, peak11_t>>;

using global_cable18_t_index = global_cable16_t_index;
using peak12_mod = parameter::plain<routing::global_cable<global_cable18_t_index, parameter::empty>, 
                                    0>;
using peak12_t = wrap::mod<peak12_mod, 
                           wrap::no_data<core::peak>>;

using chain60_t = container::chain<parameter::empty, wrap::fix<1, peak12_t>>;

using global_cable9_t_index = global_cable17_t_index;
using peak13_mod = parameter::plain<routing::global_cable<global_cable9_t_index, parameter::empty>, 
                                    0>;
using peak13_t = wrap::mod<peak13_mod, 
                           wrap::no_data<core::peak>>;

using chain69_t = container::chain<parameter::empty, wrap::fix<1, peak13_t>>;
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain13_t>, 
                                    chain16_t, 
                                    chain24_t, 
                                    chain50_t, 
                                    chain51_t, 
                                    chain59_t, 
                                    chain60_t, 
                                    chain69_t>;

using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, routing::global_cable<global_cable_t_index, parameter::empty>>, 
                                 routing::global_cable<global_cable39_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable38_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable37_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable36_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable35_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable18_t_index, parameter::empty>, 
                                 routing::global_cable<global_cable9_t_index, parameter::empty>>;

namespace modtest1_t_parameters
{
// Parameter list for modtest1_impl::modtest1_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE(Tempo_InputRange, 
                        0., 
                        18.);
DECLARE_PARAMETER_RANGE(Tempo_0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Tempo_0 = parameter::from0To1<modtest1_impl::pma1_t<NV>, 
                                    2, 
                                    Tempo_0Range>;

template <int NV>
using Tempo = parameter::chain<Tempo_InputRange, Tempo_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Shape_InputRange, 
                             0., 
                             7., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(Shape_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using Shape_0 = parameter::from0To1<modtest1_impl::branch_t<NV>, 
                                    0, 
                                    Shape_0Range>;

template <int NV>
using Shape = parameter::chain<Shape_InputRange, Shape_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Modifiers_InputRange, 
                             0., 
                             4., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(Modifiers_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using Modifiers_0 = parameter::from0To1<modtest1_impl::branch1_t<NV>, 
                                        0, 
                                        Modifiers_0Range>;

template <int NV>
using Modifiers = parameter::chain<Modifiers_InputRange, Modifiers_0<NV>>;

template <int NV>
using ModiferShape = parameter::from0To1<modtest1_impl::pma_t<NV>, 
                                         2, 
                                         Tempo_0Range>;

template <int NV>
using TempoMod = parameter::plain<modtest1_impl::pma1_t<NV>, 
                                  1>;
template <int NV>
using TempoSrc = parameter::plain<modtest1_impl::branch3_t<NV>, 
                                  0>;
template <int NV>
using Div = parameter::plain<modtest1_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using ModifierShapeMod = parameter::plain<modtest1_impl::pma_t<NV>, 
                                          1>;
template <int NV>
using ModifierShapeModSrc = parameter::plain<modtest1_impl::branch5_t<NV>, 
                                             0>;
using out = parameter::empty;
template <int NV>
using trigmode = parameter::plain<modtest1_impl::branch6_t<NV>, 
                                  0>;
template <int NV>
using oneshot = parameter::plain<modtest1_impl::ramp_t<NV>, 
                                 1>;
using OUTPUT = parameter::plain<modtest1_impl::branch2_t, 
                                0>;
template <int NV>
using rel = parameter::plain<modtest1_impl::simple_ar_t<NV>, 
                             1>;
template <int NV>
using modtest1_t_plist = parameter::list<Tempo<NV>, 
                                         TempoMod<NV>, 
                                         TempoSrc<NV>, 
                                         Div<NV>, 
                                         Shape<NV>, 
                                         Modifiers<NV>, 
                                         ModiferShape<NV>, 
                                         ModifierShapeMod<NV>, 
                                         ModifierShapeModSrc<NV>, 
                                         out, 
                                         trigmode<NV>, 
                                         oneshot<NV>, 
                                         OUTPUT, 
                                         rel<NV>>;
}

template <int NV>
using modtest1_t_ = container::chain<modtest1_t_parameters::modtest1_t_plist<NV>, 
                                     wrap::fix<1, chain12_t<NV>>, 
                                     chain27_t<NV>, 
                                     math::clear<NV>, 
                                     chain46_t<NV>, 
                                     math::clear<NV>, 
                                     pma1_t<NV>, 
                                     tempo_sync_t<NV>, 
                                     input_toggle_t<NV>, 
                                     ramp_t<NV>, 
                                     wrap::no_process<math::fmod<NV>>, 
                                     branch_t<NV>, 
                                     peak_t, 
                                     pma_t<NV>, 
                                     branch1_t<NV>, 
                                     peak2_t, 
                                     wrap::no_process<math::clear<NV>>, 
                                     branch2_t, 
                                     split_t>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public modtest1_impl::modtest1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 2;
		
		SNEX_METADATA_ID(modtest1);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(254)
		{
			0x005C, 0x0000, 0x0000, 0x6554, 0x706D, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x9000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x0100, 0x0000, 0x5400, 0x6D65, 0x6F70, 0x6F4D, 0x0064, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x253F, 0xF306, 0x003A, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0200, 0x0000, 0x5400, 0x6D65, 0x6F70, 
            0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 0x7000, 0x0041, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0300, 0x0000, 0x4400, 
            0x7669, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 0x4190, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0004, 0x0000, 0x6853, 
            0x7061, 0x0065, 0x0000, 0x0000, 0x0000, 0xE000, 0x0040, 0x0000, 
            0x0000, 0x8000, 0xCD3F, 0xCCCC, 0x5C3D, 0x0500, 0x0000, 0x4D00, 
            0x646F, 0x6669, 0x6569, 0x7372, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x4080, 0x3333, 0x4033, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 0x005C, 
            0x0006, 0x0000, 0x6F4D, 0x6964, 0x6566, 0x5372, 0x6168, 0x6570, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0xD8C4, 0x3F53, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0007, 0x0000, 0x6F4D, 0x6964, 
            0x6966, 0x7265, 0x6853, 0x7061, 0x4D65, 0x646F, 0x0000, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0312, 0x3BC6, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0008, 0x0000, 0x6F4D, 0x6964, 0x6966, 0x7265, 
            0x6853, 0x7061, 0x4D65, 0x646F, 0x7253, 0x0063, 0x0000, 0x0000, 
            0x0000, 0x7000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0900, 0x0000, 0x6F00, 0x7475, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x4180, 0x0C4A, 0x3F82, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x000A, 0x0000, 0x7274, 0x6769, 0x6F6D, 0x6564, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x4110, 0x0000, 0x4040, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x000B, 0x0000, 0x6E6F, 0x7365, 0x6F68, 
            0x0074, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x0C00, 0x0000, 0x4F00, 0x5455, 
            0x5550, 0x0054, 0x0000, 0x0000, 0x0000, 0xE000, 0x0040, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0D00, 0x0000, 0x7200, 
            0x6C65, 0x0000, 0x0000, 0x0000, 0x0000, 0x457A, 0xCCCD, 0x3ECC, 
            0x209B, 0x3E9A, 0xCCCD, 0x3DCC, 0x0000, 0x0000
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
		
		auto& chain12 = this->getT(0);                                 // modtest1_impl::chain12_t<NV>
		auto& branch3 = this->getT(0).getT(0);                         // modtest1_impl::branch3_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0);                   // modtest1_impl::chain_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(0);   // modtest1_impl::global_cable1_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain2 = this->getT(0).getT(0).getT(1);                  // modtest1_impl::chain2_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(1).getT(0);   // modtest1_impl::global_cable2_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(1);            // math::add<NV>
		auto& chain3 = this->getT(0).getT(0).getT(2);                  // modtest1_impl::chain3_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(2).getT(0);   // modtest1_impl::global_cable3_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& chain4 = this->getT(0).getT(0).getT(3);                  // modtest1_impl::chain4_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(3).getT(0);   // modtest1_impl::global_cable4_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(3).getT(1);            // math::add<NV>
		auto& chain6 = this->getT(0).getT(0).getT(4);                  // modtest1_impl::chain6_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(4).getT(0);   // modtest1_impl::global_cable5_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(4).getT(1);            // math::add<NV>
		auto& chain7 = this->getT(0).getT(0).getT(5);                  // modtest1_impl::chain7_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(5).getT(0);   // modtest1_impl::global_cable6_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(5).getT(1);            // math::add<NV>
		auto& chain9 = this->getT(0).getT(0).getT(6);                  // modtest1_impl::chain9_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(6).getT(0);   // modtest1_impl::global_cable7_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(6).getT(1);            // math::add<NV>
		auto& chain10 = this->getT(0).getT(0).getT(7);                 // modtest1_impl::chain10_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(7).getT(0);   // modtest1_impl::global_cable8_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(8);                 // modtest1_impl::chain14_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(8).getT(0);  // modtest1_impl::global_cable10_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain15 = this->getT(0).getT(0).getT(9);                 // modtest1_impl::chain15_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(9).getT(0);  // modtest1_impl::global_cable11_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain25 = this->getT(0).getT(0).getT(10);                // modtest1_impl::chain25_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(10).getT(0); // modtest1_impl::global_cable12_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain17 = this->getT(0).getT(0).getT(11);                // modtest1_impl::chain17_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(11).getT(0); // modtest1_impl::global_cable13_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(12);                // modtest1_impl::chain18_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(12).getT(0); // modtest1_impl::global_cable14_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain19 = this->getT(0).getT(0).getT(13);                // modtest1_impl::chain19_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(13).getT(0); // modtest1_impl::global_cable15_t<NV>
		auto& add17 = this->getT(0).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(14);                // modtest1_impl::chain21_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(14).getT(0); // modtest1_impl::global_cable16_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(15);                // modtest1_impl::chain22_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(15).getT(0); // modtest1_impl::global_cable17_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak1 = this->getT(0).getT(1);                           // modtest1_impl::peak1_t<NV>
		auto& clear = this->getT(0).getT(2);                           // math::clear<NV>
		auto& chain27 = this->getT(1);                                 // modtest1_impl::chain27_t<NV>
		auto& branch5 = this->getT(1).getT(0);                         // modtest1_impl::branch5_t<NV>
		auto& chain28 = this->getT(1).getT(0).getT(0);                 // modtest1_impl::chain28_t<NV>
		auto& global_cable19 = this->getT(1).getT(0).getT(0).getT(0);  // modtest1_impl::global_cable19_t<NV>
		auto& add21 = this->getT(1).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain30 = this->getT(1).getT(0).getT(1);                 // modtest1_impl::chain30_t<NV>
		auto& global_cable20 = this->getT(1).getT(0).getT(1).getT(0);  // modtest1_impl::global_cable20_t<NV>
		auto& add22 = this->getT(1).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain31 = this->getT(1).getT(0).getT(2);                 // modtest1_impl::chain31_t<NV>
		auto& global_cable21 = this->getT(1).getT(0).getT(2).getT(0);  // modtest1_impl::global_cable21_t<NV>
		auto& add23 = this->getT(1).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain33 = this->getT(1).getT(0).getT(3);                 // modtest1_impl::chain33_t<NV>
		auto& global_cable22 = this->getT(1).getT(0).getT(3).getT(0);  // modtest1_impl::global_cable22_t<NV>
		auto& add24 = this->getT(1).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain34 = this->getT(1).getT(0).getT(4);                 // modtest1_impl::chain34_t<NV>
		auto& global_cable23 = this->getT(1).getT(0).getT(4).getT(0);  // modtest1_impl::global_cable23_t<NV>
		auto& add25 = this->getT(1).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain36 = this->getT(1).getT(0).getT(5);                 // modtest1_impl::chain36_t<NV>
		auto& global_cable24 = this->getT(1).getT(0).getT(5).getT(0);  // modtest1_impl::global_cable24_t<NV>
		auto& add26 = this->getT(1).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain37 = this->getT(1).getT(0).getT(6);                 // modtest1_impl::chain37_t<NV>
		auto& global_cable25 = this->getT(1).getT(0).getT(6).getT(0);  // modtest1_impl::global_cable25_t<NV>
		auto& add27 = this->getT(1).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain38 = this->getT(1).getT(0).getT(7);                 // modtest1_impl::chain38_t<NV>
		auto& global_cable26 = this->getT(1).getT(0).getT(7).getT(0);  // modtest1_impl::global_cable26_t<NV>
		auto& add28 = this->getT(1).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain39 = this->getT(1).getT(0).getT(8);                 // modtest1_impl::chain39_t<NV>
		auto& global_cable27 = this->getT(1).getT(0).getT(8).getT(0);  // modtest1_impl::global_cable27_t<NV>
		auto& add29 = this->getT(1).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain40 = this->getT(1).getT(0).getT(9);                 // modtest1_impl::chain40_t<NV>
		auto& global_cable28 = this->getT(1).getT(0).getT(9).getT(0);  // modtest1_impl::global_cable28_t<NV>
		auto& add30 = this->getT(1).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain42 = this->getT(1).getT(0).getT(10);                // modtest1_impl::chain42_t<NV>
		auto& global_cable29 = this->getT(1).getT(0).getT(10).getT(0); // modtest1_impl::global_cable29_t<NV>
		auto& add31 = this->getT(1).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain43 = this->getT(1).getT(0).getT(11);                // modtest1_impl::chain43_t<NV>
		auto& global_cable30 = this->getT(1).getT(0).getT(11).getT(0); // modtest1_impl::global_cable30_t<NV>
		auto& add32 = this->getT(1).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain52 = this->getT(1).getT(0).getT(12);                // modtest1_impl::chain52_t<NV>
		auto& global_cable31 = this->getT(1).getT(0).getT(12).getT(0); // modtest1_impl::global_cable31_t<NV>
		auto& add33 = this->getT(1).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain53 = this->getT(1).getT(0).getT(13);                // modtest1_impl::chain53_t<NV>
		auto& global_cable32 = this->getT(1).getT(0).getT(13).getT(0); // modtest1_impl::global_cable32_t<NV>
		auto& add34 = this->getT(1).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain54 = this->getT(1).getT(0).getT(14);                // modtest1_impl::chain54_t<NV>
		auto& global_cable33 = this->getT(1).getT(0).getT(14).getT(0); // modtest1_impl::global_cable33_t<NV>
		auto& add35 = this->getT(1).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain55 = this->getT(1).getT(0).getT(15);                // modtest1_impl::chain55_t<NV>
		auto& global_cable34 = this->getT(1).getT(0).getT(15).getT(0); // modtest1_impl::global_cable34_t<NV>
		auto& add36 = this->getT(1).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak4 = this->getT(1).getT(1);                           // modtest1_impl::peak4_t<NV>
		auto& clear6 = this->getT(2);                                  // math::clear<NV>
		auto& chain46 = this->getT(3);                                 // modtest1_impl::chain46_t<NV>
		auto& branch6 = this->getT(3).getT(0);                         // modtest1_impl::branch6_t<NV>
		auto& chain11 = this->getT(3).getT(0).getT(0);                 // modtest1_impl::chain11_t<NV>
		auto& add11 = this->getT(3).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& midichain = this->getT(3).getT(0).getT(1);               // modtest1_impl::midichain_t<NV>
		auto& simple_ar = this->getT(3).getT(0).getT(1).getT(0);       // modtest1_impl::simple_ar_t<NV>
		auto& add20 = this->getT(3).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain62 = this->getT(3).getT(0).getT(2);                 // modtest1_impl::chain62_t<NV>
		auto& global_cable57 = this->getT(3).getT(0).getT(2).getT(0);  // modtest1_impl::global_cable57_t<NV>
		auto& add46 = this->getT(3).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain63 = this->getT(3).getT(0).getT(3);                 // modtest1_impl::chain63_t<NV>
		auto& global_cable58 = this->getT(3).getT(0).getT(3).getT(0);  // modtest1_impl::global_cable58_t<NV>
		auto& add47 = this->getT(3).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain64 = this->getT(3).getT(0).getT(4);                 // modtest1_impl::chain64_t<NV>
		auto& global_cable59 = this->getT(3).getT(0).getT(4).getT(0);  // modtest1_impl::global_cable59_t<NV>
		auto& add48 = this->getT(3).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain65 = this->getT(3).getT(0).getT(5);                 // modtest1_impl::chain65_t<NV>
		auto& global_cable60 = this->getT(3).getT(0).getT(5).getT(0);  // modtest1_impl::global_cable60_t<NV>
		auto& add49 = this->getT(3).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain66 = this->getT(3).getT(0).getT(6);                 // modtest1_impl::chain66_t<NV>
		auto& global_cable61 = this->getT(3).getT(0).getT(6).getT(0);  // modtest1_impl::global_cable61_t<NV>
		auto& add50 = this->getT(3).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain67 = this->getT(3).getT(0).getT(7);                 // modtest1_impl::chain67_t<NV>
		auto& global_cable62 = this->getT(3).getT(0).getT(7).getT(0);  // modtest1_impl::global_cable62_t<NV>
		auto& add51 = this->getT(3).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain68 = this->getT(3).getT(0).getT(8);                 // modtest1_impl::chain68_t<NV>
		auto& global_cable63 = this->getT(3).getT(0).getT(8).getT(0);  // modtest1_impl::global_cable63_t<NV>
		auto& add52 = this->getT(3).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain70 = this->getT(3).getT(0).getT(9);                 // modtest1_impl::chain70_t<NV>
		auto& global_cable64 = this->getT(3).getT(0).getT(9).getT(0);  // modtest1_impl::global_cable64_t<NV>
		auto& add53 = this->getT(3).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& mod2sig = this->getT(3).getT(1);                         // wrap::no_process<math::mod2sig<NV>>
		auto& add3 = this->getT(3).getT(2);                            // wrap::no_process<math::add<NV>>
		auto& peak6 = this->getT(3).getT(3);                           // modtest1_impl::peak6_t<NV>
		auto& clear7 = this->getT(3).getT(4);                          // wrap::no_process<math::clear<NV>>
		auto& clear2 = this->getT(4);                                  // math::clear<NV>
		auto& pma1 = this->getT(5);                                    // modtest1_impl::pma1_t<NV>
		auto& tempo_sync = this->getT(6);                              // modtest1_impl::tempo_sync_t<NV>
		auto& input_toggle = this->getT(7);                            // modtest1_impl::input_toggle_t<NV>
		auto& ramp = this->getT(8);                                    // modtest1_impl::ramp_t<NV>
		auto& fmod1 = this->getT(9);                                   // wrap::no_process<math::fmod<NV>>
		auto& branch = this->getT(10);                                 // modtest1_impl::branch_t<NV>
		auto& chain23 = this->getT(10).getT(0);                        // modtest1_impl::chain23_t<NV>
		auto& pi5 = this->getT(10).getT(0).getT(0);                    // math::pi<NV>
		auto& sin5 = this->getT(10).getT(0).getT(1);                   // math::sin<NV>
		auto& chain8 = this->getT(10).getT(1);                         // modtest1_impl::chain8_t<NV>
		auto& rect1 = this->getT(10).getT(1).getT(0);                  // math::rect<NV>
		auto& chain5 = this->getT(10).getT(2);                         // modtest1_impl::chain5_t
		auto& chain41 = this->getT(10).getT(3);                        // modtest1_impl::chain41_t<NV>
		auto& clear13 = this->getT(10).getT(3).getT(0);                // wrap::no_process<math::clear<NV>>
		auto& sig2mod9 = this->getT(10).getT(3).getT(1);               // math::sig2mod<NV>
		auto& peak5 = this->getT(10).getT(3).getT(2);                  // modtest1_impl::peak5_t
		auto& chain32 = this->getT(10).getT(4);                        // modtest1_impl::chain32_t<NV>
		auto& oscillator = this->getT(10).getT(4).getT(0);             // modtest1_impl::oscillator_t<NV>
		auto& pi = this->getT(10).getT(4).getT(1);                     // wrap::no_process<math::pi<NV>>
		auto& sampleandhold1 = this->getT(10).getT(4).getT(2);         // fx::sampleandhold<NV>
		auto& sig2mod7 = this->getT(10).getT(4).getT(3);               // math::sig2mod<NV>
		auto& chain20 = this->getT(10).getT(5);                        // modtest1_impl::chain20_t<NV>
		auto& clear15 = this->getT(10).getT(5).getT(0);                // math::clear<NV>
		auto& cable_table = this->getT(10).getT(5).getT(1);            // modtest1_impl::cable_table_t<NV>
		auto& add = this->getT(10).getT(5).getT(2);                    // math::add<NV>
		auto& chain26 = this->getT(10).getT(6);                        // modtest1_impl::chain26_t<NV>
		auto& clear5 = this->getT(10).getT(6).getT(0);                 // math::clear<NV>
		auto& cable_pack = this->getT(10).getT(6).getT(1);             // modtest1_impl::cable_pack_t<NV>
		auto& add1 = this->getT(10).getT(6).getT(2);                   // math::add<NV>
		auto& peak = this->getT(11);                                   // modtest1_impl::peak_t
		auto& pma = this->getT(12);                                    // modtest1_impl::pma_t<NV>
		auto& branch1 = this->getT(13);                                // modtest1_impl::branch1_t<NV>
		auto& chain1 = this->getT(13).getT(0);                         // modtest1_impl::chain1_t
		auto& chain29 = this->getT(13).getT(1);                        // modtest1_impl::chain29_t<NV>
		auto& expr3 = this->getT(13).getT(1).getT(0);                  // math::expr<NV, custom::expr3>
		auto& chain35 = this->getT(13).getT(2);                        // modtest1_impl::chain35_t<NV>
		auto& cable_table1 = this->getT(13).getT(2).getT(0);           // modtest1_impl::cable_table1_t<NV>
		auto& bitcrush = this->getT(13).getT(2).getT(1);               // fx::bitcrush<NV>
		auto& chain44 = this->getT(13).getT(3);                        // modtest1_impl::chain44_t<NV>
		auto& expr8 = this->getT(13).getT(3).getT(0);                  // math::expr<NV, custom::expr8>
		auto& chain47 = this->getT(13).getT(4);                        // modtest1_impl::chain47_t
		auto& peak2 = this->getT(14);                                  // modtest1_impl::peak2_t
		auto& clear3 = this->getT(15);                                 // wrap::no_process<math::clear<NV>>
		auto& branch2 = this->getT(16);                                // modtest1_impl::branch2_t
		auto& chain13 = this->getT(16).getT(0);                        // modtest1_impl::chain13_t
		auto& peak3 = this->getT(16).getT(0).getT(0);                  // modtest1_impl::peak3_t
		auto& chain16 = this->getT(16).getT(1);                        // modtest1_impl::chain16_t
		auto& peak9 = this->getT(16).getT(1).getT(0);                  // modtest1_impl::peak9_t
		auto& chain24 = this->getT(16).getT(2);                        // modtest1_impl::chain24_t
		auto& peak8 = this->getT(16).getT(2).getT(0);                  // modtest1_impl::peak8_t
		auto& chain50 = this->getT(16).getT(3);                        // modtest1_impl::chain50_t
		auto& peak7 = this->getT(16).getT(3).getT(0);                  // modtest1_impl::peak7_t
		auto& chain51 = this->getT(16).getT(4);                        // modtest1_impl::chain51_t
		auto& peak10 = this->getT(16).getT(4).getT(0);                 // modtest1_impl::peak10_t
		auto& chain59 = this->getT(16).getT(5);                        // modtest1_impl::chain59_t
		auto& peak11 = this->getT(16).getT(5).getT(0);                 // modtest1_impl::peak11_t
		auto& chain60 = this->getT(16).getT(6);                        // modtest1_impl::chain60_t
		auto& peak12 = this->getT(16).getT(6).getT(0);                 // modtest1_impl::peak12_t
		auto& chain69 = this->getT(16).getT(7);                        // modtest1_impl::chain69_t
		auto& peak13 = this->getT(16).getT(7).getT(0);                 // modtest1_impl::peak13_t
		auto& split = this->getT(17);                                  // modtest1_impl::split_t
		auto& global_cable = this->getT(17).getT(0);                   // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& global_cable39 = this->getT(17).getT(1);                 // routing::global_cable<global_cable39_t_index, parameter::empty>
		auto& global_cable38 = this->getT(17).getT(2);                 // routing::global_cable<global_cable38_t_index, parameter::empty>
		auto& global_cable37 = this->getT(17).getT(3);                 // routing::global_cable<global_cable37_t_index, parameter::empty>
		auto& global_cable36 = this->getT(17).getT(4);                 // routing::global_cable<global_cable36_t_index, parameter::empty>
		auto& global_cable35 = this->getT(17).getT(5);                 // routing::global_cable<global_cable35_t_index, parameter::empty>
		auto& global_cable18 = this->getT(17).getT(6);                 // routing::global_cable<global_cable18_t_index, parameter::empty>
		auto& global_cable9 = this->getT(17).getT(7);                  // routing::global_cable<global_cable9_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Tempo -> pma1::Add
		
		this->getParameterT(1).connectT(0, pma1); // TempoMod -> pma1::Multiply
		
		this->getParameterT(2).connectT(0, branch3); // TempoSrc -> branch3::Index
		
		this->getParameterT(3).connectT(0, tempo_sync); // Div -> tempo_sync::Multiplier
		
		this->getParameterT(4).connectT(0, branch); // Shape -> branch::Index
		
		this->getParameterT(5).connectT(0, branch1); // Modifiers -> branch1::Index
		
		this->getParameterT(6).connectT(0, pma); // ModiferShape -> pma::Add
		
		this->getParameterT(7).connectT(0, pma); // ModifierShapeMod -> pma::Multiply
		
		this->getParameterT(8).connectT(0, branch5); // ModifierShapeModSrc -> branch5::Index
		
		this->getParameterT(10).connectT(0, branch6); // trigmode -> branch6::Index
		
		this->getParameterT(11).connectT(0, ramp); // oneshot -> ramp::LoopStart
		
		this->getParameterT(12).connectT(0, branch2); // OUTPUT -> branch2::Index
		
		this->getParameterT(13).connectT(0, simple_ar); // rel -> simple_ar::Release
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable1.getWrappedObject().getParameter().connectT(0, add2);    // global_cable1 -> add2::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add4);    // global_cable2 -> add4::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add5);    // global_cable3 -> add5::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add6);    // global_cable4 -> add6::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add7);    // global_cable5 -> add7::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add8);    // global_cable6 -> add8::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add9);    // global_cable7 -> add9::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add10);   // global_cable8 -> add10::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add12);  // global_cable10 -> add12::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add13);  // global_cable11 -> add13::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add14);  // global_cable12 -> add14::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add15);  // global_cable13 -> add15::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add16);  // global_cable14 -> add16::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add17);  // global_cable15 -> add17::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add18);  // global_cable16 -> add18::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add19);  // global_cable17 -> add19::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add);       // cable_table -> add::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add1);       // cable_pack -> add1::Value
		ramp.getParameter().connectT(0, cable_table);                         // ramp -> cable_table::Value
		ramp.getParameter().connectT(1, cable_pack);                          // ramp -> cable_pack::Value
		tempo_sync.getParameter().connectT(0, ramp);                          // tempo_sync -> ramp::PeriodTime
		tempo_sync.getParameter().connectT(1, sampleandhold1);                // tempo_sync -> sampleandhold1::Counter
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync);       // pma1 -> tempo_sync::Tempo
		peak1.getParameter().connectT(0, pma1);                               // peak1 -> pma1::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add21);  // global_cable19 -> add21::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add22);  // global_cable20 -> add22::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add23);  // global_cable21 -> add23::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add24);  // global_cable22 -> add24::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add25);  // global_cable23 -> add25::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add26);  // global_cable24 -> add26::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add27);  // global_cable25 -> add27::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add28);  // global_cable26 -> add28::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add29);  // global_cable27 -> add29::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add30);  // global_cable28 -> add30::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add31);  // global_cable29 -> add31::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add32);  // global_cable30 -> add32::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add33);  // global_cable31 -> add33::Value
		global_cable32.getWrappedObject().getParameter().connectT(0, add34);  // global_cable32 -> add34::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add35);  // global_cable33 -> add35::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add36);  // global_cable34 -> add36::Value
		cable_table1.getWrappedObject().getParameter().connectT(0, bitcrush); // cable_table1 -> bitcrush::BitDepth
		pma.getWrappedObject().getParameter().connectT(0, expr3);             // pma -> expr3::Value
		pma.getWrappedObject().getParameter().connectT(1, expr8);             // pma -> expr8::Value
		pma.getWrappedObject().getParameter().connectT(2, cable_table1);      // pma -> cable_table1::Value
		peak4.getParameter().connectT(0, pma);                                // peak4 -> pma::Value
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(0).connectT(0, add20);                     // simple_ar -> add20::Value
		global_cable57.getWrappedObject().getParameter().connectT(0, add46); // global_cable57 -> add46::Value
		global_cable58.getWrappedObject().getParameter().connectT(0, add47); // global_cable58 -> add47::Value
		global_cable59.getWrappedObject().getParameter().connectT(0, add48); // global_cable59 -> add48::Value
		global_cable60.getWrappedObject().getParameter().connectT(0, add49); // global_cable60 -> add49::Value
		global_cable61.getWrappedObject().getParameter().connectT(0, add50); // global_cable61 -> add50::Value
		global_cable62.getWrappedObject().getParameter().connectT(0, add51); // global_cable62 -> add51::Value
		global_cable63.getWrappedObject().getParameter().connectT(0, add52); // global_cable63 -> add52::Value
		global_cable64.getWrappedObject().getParameter().connectT(0, add53); // global_cable64 -> add53::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, ramp);    // input_toggle -> ramp::Gate
		peak6.getParameter().connectT(0, input_toggle);                      // peak6 -> input_toggle::Input
		peak3.getParameter().connectT(0, global_cable);                      // peak3 -> global_cable::Value
		peak9.getParameter().connectT(0, global_cable39);                    // peak9 -> global_cable39::Value
		peak8.getParameter().connectT(0, global_cable38);                    // peak8 -> global_cable38::Value
		peak7.getParameter().connectT(0, global_cable37);                    // peak7 -> global_cable37::Value
		peak10.getParameter().connectT(0, global_cable36);                   // peak10 -> global_cable36::Value
		peak11.getParameter().connectT(0, global_cable35);                   // peak11 -> global_cable35::Value
		peak12.getParameter().connectT(0, global_cable18);                   // peak12 -> global_cable18::Value
		peak13.getParameter().connectT(0, global_cable9);                    // peak13 -> global_cable9::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch3::Index is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add17::Value is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch5::Index is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add22::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add23::Value is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add24::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add25::Value is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add35::Value is automated
		
		global_cable34.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add36::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // branch6::Index is automated
		
		add11.setParameterT(0, 1.); // math::add::Value
		
		simple_ar.setParameterT(0, 0.); // envelope::simple_ar::Attack
		;                               // simple_ar::Release is automated
		simple_ar.setParameterT(2, 0.); // envelope::simple_ar::Gate
		simple_ar.setParameterT(3, 0.); // envelope::simple_ar::AttackCurve
		
		; // add20::Value is automated
		
		global_cable57.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add46::Value is automated
		
		global_cable58.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add47::Value is automated
		
		global_cable59.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add48::Value is automated
		
		global_cable60.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add49::Value is automated
		
		global_cable61.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add50::Value is automated
		
		global_cable62.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add51::Value is automated
		
		global_cable63.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add52::Value is automated
		
		global_cable64.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add53::Value is automated
		
		mod2sig.setParameterT(0, 0.550391); // math::mod2sig::Value
		
		add3.setParameterT(0, 0.); // math::add::Value
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 0.); // control::input_toggle::Value1
		input_toggle.setParameterT(2, 1.); // control::input_toggle::Value2
		
		; // ramp::PeriodTime is automated
		; // ramp::LoopStart is automated
		; // ramp::Gate is automated
		
		fmod1.setParameterT(0, 0.614986); // math::fmod::Value
		
		; // branch::Index is automated
		
		pi5.setParameterT(0, 1.); // math::pi::Value
		
		sin5.setParameterT(0, 1.); // math::sin::Value
		
		rect1.setParameterT(0, 0.166743); // math::rect::Value
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		sig2mod9.setParameterT(0, 0.); // math::sig2mod::Value
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		; // sampleandhold1::Counter is automated
		
		sig2mod7.setParameterT(0, 0.); // math::sig2mod::Value
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table::Value is automated
		
		; // add::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack::Value is automated
		
		; // add1::Value is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // branch1::Index is automated
		
		; // expr3::Value is automated
		
		; // cable_table1::Value is automated
		
		;                              // bitcrush::BitDepth is automated
		bitcrush.setParameterT(1, 1.); // fx::bitcrush::Mode
		
		; // expr8::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // branch2::Index is automated
		
		; // global_cable::Value is automated
		
		; // global_cable39::Value is automated
		
		; // global_cable38::Value is automated
		
		; // global_cable37::Value is automated
		
		; // global_cable36::Value is automated
		
		; // global_cable35::Value is automated
		
		; // global_cable18::Value is automated
		
		; // global_cable9::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.00185413);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 18.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 2.8);
		this->setParameterT(6, 0.827526);
		this->setParameterT(7, 0.00604285);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 1.016);
		this->setParameterT(10, 3.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 0.);
		this->setParameterT(13, 0.4);
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
		
		this->getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable14_t<NV>
		this->getT(0).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable17_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable19_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable20_t<NV>
		this->getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable21_t<NV>
		this->getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable22_t<NV>
		this->getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable23_t<NV>
		this->getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable24_t<NV>
		this->getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable25_t<NV>
		this->getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable26_t<NV>
		this->getT(1).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable27_t<NV>
		this->getT(1).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable28_t<NV>
		this->getT(1).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable29_t<NV>
		this->getT(1).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable30_t<NV>
		this->getT(1).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable31_t<NV>
		this->getT(1).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable32_t<NV>
		this->getT(1).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable33_t<NV>
		this->getT(1).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // modtest1_impl::global_cable34_t<NV>
		this->getT(3).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable57_t<NV>
		this->getT(3).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable58_t<NV>
		this->getT(3).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable59_t<NV>
		this->getT(3).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable60_t<NV>
		this->getT(3).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable61_t<NV>
		this->getT(3).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable62_t<NV>
		this->getT(3).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable63_t<NV>
		this->getT(3).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // modtest1_impl::global_cable64_t<NV>
		this->getT(17).getT(0).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(17).getT(1).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable39_t_index, parameter::empty>
		this->getT(17).getT(2).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable38_t_index, parameter::empty>
		this->getT(17).getT(3).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable37_t_index, parameter::empty>
		this->getT(17).getT(4).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable36_t_index, parameter::empty>
		this->getT(17).getT(5).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable35_t_index, parameter::empty>
		this->getT(17).getT(6).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable18_t_index, parameter::empty>
		this->getT(17).getT(7).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable9_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(1).setExternalData(b, index);                 // modtest1_impl::peak1_t<NV>
		this->getT(1).getT(1).setExternalData(b, index);                 // modtest1_impl::peak4_t<NV>
		this->getT(3).getT(0).getT(1).getT(0).setExternalData(b, index); // modtest1_impl::simple_ar_t<NV>
		this->getT(3).getT(3).setExternalData(b, index);                 // modtest1_impl::peak6_t<NV>
		this->getT(8).setExternalData(b, index);                         // modtest1_impl::ramp_t<NV>
		this->getT(10).getT(3).getT(2).setExternalData(b, index);        // modtest1_impl::peak5_t
		this->getT(10).getT(4).getT(0).setExternalData(b, index);        // modtest1_impl::oscillator_t<NV>
		this->getT(10).getT(5).getT(1).setExternalData(b, index);        // modtest1_impl::cable_table_t<NV>
		this->getT(10).getT(6).getT(1).setExternalData(b, index);        // modtest1_impl::cable_pack_t<NV>
		this->getT(11).setExternalData(b, index);                        // modtest1_impl::peak_t
		this->getT(13).getT(2).getT(0).setExternalData(b, index);        // modtest1_impl::cable_table1_t<NV>
		this->getT(14).setExternalData(b, index);                        // modtest1_impl::peak2_t
		this->getT(16).getT(0).getT(0).setExternalData(b, index);        // modtest1_impl::peak3_t
		this->getT(16).getT(1).getT(0).setExternalData(b, index);        // modtest1_impl::peak9_t
		this->getT(16).getT(2).getT(0).setExternalData(b, index);        // modtest1_impl::peak8_t
		this->getT(16).getT(3).getT(0).setExternalData(b, index);        // modtest1_impl::peak7_t
		this->getT(16).getT(4).getT(0).setExternalData(b, index);        // modtest1_impl::peak10_t
		this->getT(16).getT(5).getT(0).setExternalData(b, index);        // modtest1_impl::peak11_t
		this->getT(16).getT(6).getT(0).setExternalData(b, index);        // modtest1_impl::peak12_t
		this->getT(16).getT(7).getT(0).setExternalData(b, index);        // modtest1_impl::peak13_t
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
using modtest1 = wrap::node<modtest1_impl::instance<NV>>;
}


