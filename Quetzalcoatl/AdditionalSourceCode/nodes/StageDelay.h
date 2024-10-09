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

namespace StageDelay_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable1_t_index = runtime_target::indexers::fix_hash<1534441889>;

using stereo_cable = cable::block<2>;
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<routing::receive<stereo_cable>, 0>>;

using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<1534848670>;

template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, core::fix_delay>, 
                                    jdsp::jdelay_thiran<NV>>;
template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<branch2_t<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<880780334>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<jdsp::jdelay_thiran<NV>, 0>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(global_cable3_modRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using global_cable3_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                              1, 
                                              global_cable3_modRange>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, global_cable3_mod<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable3_t<NV>>>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<1804752113>;

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter_mod_0Range, 
                             0., 
                             1000., 
                             0.30103);

template <int NV>
using smoothed_parameter_mod_0 = parameter::from0To1<jdsp::jdelay_thiran<NV>, 
                                                     1, 
                                                     smoothed_parameter_mod_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter_mod_1Range, 
                             0., 
                             1000., 
                             0.30103);

using smoothed_parameter_mod_1 = parameter::from0To1<core::fix_delay, 
                                                     0, 
                                                     smoothed_parameter_mod_1Range>;

template <int NV>
using smoothed_parameter_mod = parameter::chain<ranges::Identity, 
                                                smoothed_parameter_mod_0<NV>, 
                                                smoothed_parameter_mod_1>;

template <int NV>
using smoothed_parameter_t = wrap::mod<smoothed_parameter_mod<NV>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
DECLARE_PARAMETER_RANGE_STEP(global_cable4_modRange, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using global_cable4_mod = parameter::from0To1<smoothed_parameter_t<NV>, 
                                              1, 
                                              global_cable4_modRange>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, global_cable4_mod<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable4_t<NV>>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<1534630319>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<filters::one_pole<NV>, 4>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable5_t<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain4_t>, 
                                   chain5_t<NV>, 
                                   chain6_t<NV>, 
                                   chain7_t<NV>, 
                                   chain8_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch_t<NV>>>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<336114529>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>>;
using global_cable8_t_index = runtime_target::indexers::fix_hash<336114530>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   math::add<NV>>;
using global_cable9_t_index = runtime_target::indexers::fix_hash<336114531>;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable9_t<NV>>, 
                                   math::add<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<336114532>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<336114533>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<336114534>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable15_t_index = runtime_target::indexers::fix_hash<336114535>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<336114536>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain12_t<NV>>, 
                                    chain13_t<NV>, 
                                    chain14_t<NV>, 
                                    chain15_t<NV>, 
                                    chain16_t<NV>, 
                                    chain17_t<NV>, 
                                    chain20_t<NV>, 
                                    chain18_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma_mod_1Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma_mod_1 = parameter::from0To1<tempo_sync_t<NV>, 
                                      0, 
                                      pma_mod_1Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<smoothed_parameter_t<NV>, 0>, 
                                 pma_mod_1<NV>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
DECLARE_PARAMETER_RANGE(peak1_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using peak1_mod = parameter::from0To1<pma_t<NV>, 
                                      2, 
                                      peak1_modRange>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch1_t<NV>>, 
                                   peak1_t<NV>>;
using global_cable16_t_index = runtime_target::indexers::fix_hash<1534654808>;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = runtime_target::indexers::fix_hash<1534654809>;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
using global_cable18_t_index = runtime_target::indexers::fix_hash<1534654810>;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>>;
using global_cable19_t_index = runtime_target::indexers::fix_hash<1534654811>;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;
using global_cable20_t_index = runtime_target::indexers::fix_hash<1534654812>;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = runtime_target::indexers::fix_hash<1534654813>;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = runtime_target::indexers::fix_hash<1534654814>;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = runtime_target::indexers::fix_hash<1534654815>;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain22_t<NV>>, 
                                    chain23_t<NV>, 
                                    chain24_t<NV>, 
                                    chain25_t<NV>, 
                                    chain26_t<NV>, 
                                    chain27_t<NV>, 
                                    chain28_t<NV>, 
                                    chain29_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<xfader_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak2_t<NV>, 
                                   math::clear<NV>>;
using global_cable24_t_index = runtime_target::indexers::fix_hash<1534368306>;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>>;
using global_cable25_t_index = runtime_target::indexers::fix_hash<1534368307>;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>>;
using global_cable26_t_index = runtime_target::indexers::fix_hash<1534368308>;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>>;
using global_cable27_t_index = runtime_target::indexers::fix_hash<1534368309>;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>>;
using global_cable28_t_index = runtime_target::indexers::fix_hash<1534368310>;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   math::add<NV>>;
using global_cable29_t_index = runtime_target::indexers::fix_hash<1534368311>;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   math::add<NV>>;
using global_cable30_t_index = runtime_target::indexers::fix_hash<1534368312>;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable30_t<NV>>, 
                                   math::add<NV>>;
using global_cable31_t_index = runtime_target::indexers::fix_hash<1534368313>;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable31_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain31_t<NV>>, 
                                    chain32_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>, 
                                    chain37_t<NV>, 
                                    chain38_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(peak3_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using peak3_mod = parameter::from0To1<filters::one_pole<NV>, 
                                      0, 
                                      peak3_modRange>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch4_t<NV>>, 
                                   peak3_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, chain10_t<NV>>, 
                                     math::clear<NV>, 
                                     chain11_t<NV>, 
                                     math::clear<NV>, 
                                     chain21_t<NV>, 
                                     chain30_t<NV>, 
                                     pma_t<NV>, 
                                     tempo_sync_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, branch2_t<NV>>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, split1_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter_t<NV>>, 
                                  routing::receive<stereo_cable>, 
                                  fix8_block_t<NV>, 
                                  filters::one_pole<NV>, 
                                  routing::send<stereo_cable>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>, 
                                 chain2_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, modchain_t<NV>>, 
                                 xfader_t<NV>, 
                                 split_t<NV>>;

namespace StageDelay_t_parameters
{
// Parameter list for StageDelay_impl::StageDelay_t ------------------------------------------------

template <int NV>
using TimeIn = parameter::plain<StageDelay_impl::branch1_t<NV>, 
                                0>;
template <int NV>
using CutIn = parameter::plain<StageDelay_impl::branch4_t<NV>, 
                               0>;
template <int NV>
using mixin = parameter::plain<StageDelay_impl::branch3_t<NV>, 
                               0>;
template <int NV>
using StageDelay_t_plist = parameter::list<TimeIn<NV>, 
                                           CutIn<NV>, 
                                           mixin<NV>>;
}

template <int NV>
using StageDelay_t_ = container::chain<StageDelay_t_parameters::StageDelay_t_plist<NV>, 
                                       wrap::fix<2, chain_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public StageDelay_impl::StageDelay_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(StageDelay);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(48)
		{
			0x005B, 0x0000, 0x5400, 0x6D69, 0x4965, 0x006E, 0x0000, 0x0000, 
            0x0000, 0x40E0, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x015B, 0x0000, 0x4300, 0x7475, 0x6E49, 0x0000, 0x0000, 0x0000, 
            0xE000, 0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0002, 0x0000, 0x696D, 0x6978, 0x006E, 0x0000, 0x0000, 0x0000, 
            0x40E0, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain = this->getT(0);                                                         // StageDelay_impl::chain_t<NV>
		auto& modchain = this->getT(0).getT(0);                                              // StageDelay_impl::modchain_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0);                                       // StageDelay_impl::chain10_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0).getT(0);                                // StageDelay_impl::branch_t<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                        // StageDelay_impl::chain4_t
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);         // StageDelay_impl::global_cable1_t
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                        // StageDelay_impl::chain5_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);         // StageDelay_impl::global_cable2_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                        // StageDelay_impl::chain6_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);         // StageDelay_impl::global_cable3_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                        // StageDelay_impl::chain7_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0);         // StageDelay_impl::global_cable4_t<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(0).getT(4);                        // StageDelay_impl::chain8_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(0).getT(4).getT(0);         // StageDelay_impl::global_cable5_t<NV>
		auto& clear = this->getT(0).getT(0).getT(1);                                         // math::clear<NV>
		auto& chain11 = this->getT(0).getT(0).getT(2);                                       // StageDelay_impl::chain11_t<NV>
		auto& branch1 = this->getT(0).getT(0).getT(2).getT(0);                               // StageDelay_impl::branch1_t<NV>
		auto& chain12 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                       // StageDelay_impl::chain12_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0);         // StageDelay_impl::global_cable7_t<NV>
		auto& add = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);                   // math::add<NV>
		auto& chain13 = this->getT(0).getT(0).getT(2).getT(0).getT(1);                       // StageDelay_impl::chain13_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0);         // StageDelay_impl::global_cable8_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1);                  // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(2).getT(0).getT(2);                       // StageDelay_impl::chain14_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(0);         // StageDelay_impl::global_cable9_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(1);                  // math::add<NV>
		auto& chain15 = this->getT(0).getT(0).getT(2).getT(0).getT(3);                       // StageDelay_impl::chain15_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0);        // StageDelay_impl::global_cable10_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(1);                 // math::add<NV>
		auto& chain16 = this->getT(0).getT(0).getT(2).getT(0).getT(4);                       // StageDelay_impl::chain16_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(2).getT(0).getT(4).getT(0);        // StageDelay_impl::global_cable11_t<NV>
		auto& add11 = this->getT(0).getT(0).getT(2).getT(0).getT(4).getT(1);                 // math::add<NV>
		auto& chain17 = this->getT(0).getT(0).getT(2).getT(0).getT(5);                       // StageDelay_impl::chain17_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(2).getT(0).getT(5).getT(0);        // StageDelay_impl::global_cable12_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(2).getT(0).getT(5).getT(1);                 // math::add<NV>
		auto& chain20 = this->getT(0).getT(0).getT(2).getT(0).getT(6);                       // StageDelay_impl::chain20_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(2).getT(0).getT(6).getT(0);        // StageDelay_impl::global_cable15_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(2).getT(0).getT(6).getT(1);                 // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(2).getT(0).getT(7);                       // StageDelay_impl::chain18_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(2).getT(0).getT(7).getT(0);        // StageDelay_impl::global_cable13_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(2).getT(0).getT(7).getT(1);                 // math::add<NV>
		auto& peak1 = this->getT(0).getT(0).getT(2).getT(1);                                 // StageDelay_impl::peak1_t<NV>
		auto& clear3 = this->getT(0).getT(0).getT(3);                                        // math::clear<NV>
		auto& chain21 = this->getT(0).getT(0).getT(4);                                       // StageDelay_impl::chain21_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(4).getT(0);                               // StageDelay_impl::branch3_t<NV>
		auto& chain22 = this->getT(0).getT(0).getT(4).getT(0).getT(0);                       // StageDelay_impl::chain22_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0);        // StageDelay_impl::global_cable16_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(1);                 // math::add<NV>
		auto& chain23 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                       // StageDelay_impl::chain23_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0);        // StageDelay_impl::global_cable17_t<NV>
		auto& add17 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(1);                 // math::add<NV>
		auto& chain24 = this->getT(0).getT(0).getT(4).getT(0).getT(2);                       // StageDelay_impl::chain24_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(4).getT(0).getT(2).getT(0);        // StageDelay_impl::global_cable18_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(4).getT(0).getT(2).getT(1);                 // math::add<NV>
		auto& chain25 = this->getT(0).getT(0).getT(4).getT(0).getT(3);                       // StageDelay_impl::chain25_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(0);        // StageDelay_impl::global_cable19_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(1);                 // math::add<NV>
		auto& chain26 = this->getT(0).getT(0).getT(4).getT(0).getT(4);                       // StageDelay_impl::chain26_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(4).getT(0).getT(4).getT(0);        // StageDelay_impl::global_cable20_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(4).getT(0).getT(4).getT(1);                 // math::add<NV>
		auto& chain27 = this->getT(0).getT(0).getT(4).getT(0).getT(5);                       // StageDelay_impl::chain27_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(4).getT(0).getT(5).getT(0);        // StageDelay_impl::global_cable21_t<NV>
		auto& add21 = this->getT(0).getT(0).getT(4).getT(0).getT(5).getT(1);                 // math::add<NV>
		auto& chain28 = this->getT(0).getT(0).getT(4).getT(0).getT(6);                       // StageDelay_impl::chain28_t<NV>
		auto& global_cable22 = this->getT(0).getT(0).getT(4).getT(0).getT(6).getT(0);        // StageDelay_impl::global_cable22_t<NV>
		auto& add22 = this->getT(0).getT(0).getT(4).getT(0).getT(6).getT(1);                 // math::add<NV>
		auto& chain29 = this->getT(0).getT(0).getT(4).getT(0).getT(7);                       // StageDelay_impl::chain29_t<NV>
		auto& global_cable23 = this->getT(0).getT(0).getT(4).getT(0).getT(7).getT(0);        // StageDelay_impl::global_cable23_t<NV>
		auto& add23 = this->getT(0).getT(0).getT(4).getT(0).getT(7).getT(1);                 // math::add<NV>
		auto& peak2 = this->getT(0).getT(0).getT(4).getT(1);                                 // StageDelay_impl::peak2_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(4).getT(2);                                // math::clear<NV>
		auto& chain30 = this->getT(0).getT(0).getT(5);                                       // StageDelay_impl::chain30_t<NV>
		auto& branch4 = this->getT(0).getT(0).getT(5).getT(0);                               // StageDelay_impl::branch4_t<NV>
		auto& chain31 = this->getT(0).getT(0).getT(5).getT(0).getT(0);                       // StageDelay_impl::chain31_t<NV>
		auto& global_cable24 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(0);        // StageDelay_impl::global_cable24_t<NV>
		auto& add24 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(1);                 // math::add<NV>
		auto& chain32 = this->getT(0).getT(0).getT(5).getT(0).getT(1);                       // StageDelay_impl::chain32_t<NV>
		auto& global_cable25 = this->getT(0).getT(0).getT(5).getT(0).getT(1).getT(0);        // StageDelay_impl::global_cable25_t<NV>
		auto& add25 = this->getT(0).getT(0).getT(5).getT(0).getT(1).getT(1);                 // math::add<NV>
		auto& chain33 = this->getT(0).getT(0).getT(5).getT(0).getT(2);                       // StageDelay_impl::chain33_t<NV>
		auto& global_cable26 = this->getT(0).getT(0).getT(5).getT(0).getT(2).getT(0);        // StageDelay_impl::global_cable26_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(5).getT(0).getT(2).getT(1);                 // math::add<NV>
		auto& chain34 = this->getT(0).getT(0).getT(5).getT(0).getT(3);                       // StageDelay_impl::chain34_t<NV>
		auto& global_cable27 = this->getT(0).getT(0).getT(5).getT(0).getT(3).getT(0);        // StageDelay_impl::global_cable27_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(5).getT(0).getT(3).getT(1);                 // math::add<NV>
		auto& chain35 = this->getT(0).getT(0).getT(5).getT(0).getT(4);                       // StageDelay_impl::chain35_t<NV>
		auto& global_cable28 = this->getT(0).getT(0).getT(5).getT(0).getT(4).getT(0);        // StageDelay_impl::global_cable28_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(5).getT(0).getT(4).getT(1);                 // math::add<NV>
		auto& chain36 = this->getT(0).getT(0).getT(5).getT(0).getT(5);                       // StageDelay_impl::chain36_t<NV>
		auto& global_cable29 = this->getT(0).getT(0).getT(5).getT(0).getT(5).getT(0);        // StageDelay_impl::global_cable29_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(5).getT(0).getT(5).getT(1);                 // math::add<NV>
		auto& chain37 = this->getT(0).getT(0).getT(5).getT(0).getT(6);                       // StageDelay_impl::chain37_t<NV>
		auto& global_cable30 = this->getT(0).getT(0).getT(5).getT(0).getT(6).getT(0);        // StageDelay_impl::global_cable30_t<NV>
		auto& add30 = this->getT(0).getT(0).getT(5).getT(0).getT(6).getT(1);                 // math::add<NV>
		auto& chain38 = this->getT(0).getT(0).getT(5).getT(0).getT(7);                       // StageDelay_impl::chain38_t<NV>
		auto& global_cable31 = this->getT(0).getT(0).getT(5).getT(0).getT(7).getT(0);        // StageDelay_impl::global_cable31_t<NV>
		auto& add31 = this->getT(0).getT(0).getT(5).getT(0).getT(7).getT(1);                 // math::add<NV>
		auto& peak3 = this->getT(0).getT(0).getT(5).getT(1);                                 // StageDelay_impl::peak3_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(5).getT(2);                                // math::clear<NV>
		auto& pma = this->getT(0).getT(0).getT(6);                                           // StageDelay_impl::pma_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(7);                                    // StageDelay_impl::tempo_sync_t<NV>
		auto& xfader = this->getT(0).getT(1);                                                // StageDelay_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(2);                                                 // StageDelay_impl::split_t<NV>
		auto& chain1 = this->getT(0).getT(2).getT(0);                                        // StageDelay_impl::chain1_t<NV>
		auto& gain = this->getT(0).getT(2).getT(0).getT(0);                                  // core::gain<NV>
		auto& chain2 = this->getT(0).getT(2).getT(1);                                        // StageDelay_impl::chain2_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(2).getT(1).getT(0);                    // StageDelay_impl::smoothed_parameter_t<NV>
		auto& receive = this->getT(0).getT(2).getT(1).getT(1);                               // routing::receive<stereo_cable>
		auto& fix8_block = this->getT(0).getT(2).getT(1).getT(2);                            // StageDelay_impl::fix8_block_t<NV>
		auto& split1 = this->getT(0).getT(2).getT(1).getT(2).getT(0);                        // StageDelay_impl::split1_t<NV>
		auto& branch2 = this->getT(0).getT(2).getT(1).getT(2).getT(0).getT(0);               // StageDelay_impl::branch2_t<NV>
		auto& fix_delay = this->getT(0).getT(2).getT(1).getT(2).getT(0).getT(0).getT(0);     // core::fix_delay
		auto& jdelay_thiran = this->getT(0).getT(2).getT(1).getT(2).getT(0).getT(0).getT(1); // jdsp::jdelay_thiran<NV>
		auto& one_pole = this->getT(0).getT(2).getT(1).getT(3);                              // filters::one_pole<NV>
		auto& send = this->getT(0).getT(2).getT(1).getT(4);                                  // routing::send<stereo_cable>
		auto& gain1 = this->getT(0).getT(2).getT(1).getT(5);                                 // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch1); // TimeIn -> branch1::Index
		
		this->getParameterT(1).connectT(0, branch4); // CutIn -> branch4::Index
		
		this->getParameterT(2).connectT(0, branch3); // mixin -> branch3::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable1.getWrappedObject().getParameter().connectT(0, receive);            // global_cable1 -> receive::Feedback
		global_cable2.getWrappedObject().getParameter().connectT(0, branch2);            // global_cable2 -> branch2::Index
		tempo_sync.getParameter().connectT(0, jdelay_thiran);                            // tempo_sync -> jdelay_thiran::Limit
		global_cable3.getWrappedObject().getParameter().connectT(0, tempo_sync);         // global_cable3 -> tempo_sync::Multiplier
		smoothed_parameter.getParameter().connectT(0, jdelay_thiran);                    // smoothed_parameter -> jdelay_thiran::DelayTime
		smoothed_parameter.getParameter().connectT(1, fix_delay);                        // smoothed_parameter -> fix_delay::DelayTime
		global_cable4.getWrappedObject().getParameter().connectT(0, smoothed_parameter); // global_cable4 -> smoothed_parameter::SmoothingTime
		global_cable5.getWrappedObject().getParameter().connectT(0, one_pole);           // global_cable5 -> one_pole::Mode
		global_cable7.getWrappedObject().getParameter().connectT(0, add);                // global_cable7 -> add::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add8);               // global_cable8 -> add8::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add9);               // global_cable9 -> add9::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add10);             // global_cable10 -> add10::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add11);             // global_cable11 -> add11::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add12);             // global_cable12 -> add12::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add15);             // global_cable15 -> add15::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add13);             // global_cable13 -> add13::Value
		pma.getWrappedObject().getParameter().connectT(0, smoothed_parameter);           // pma -> smoothed_parameter::Value
		pma.getWrappedObject().getParameter().connectT(1, tempo_sync);                   // pma -> tempo_sync::Tempo
		peak1.getParameter().connectT(0, pma);                                           // peak1 -> pma::Add
		global_cable16.getWrappedObject().getParameter().connectT(0, add16);             // global_cable16 -> add16::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add17);             // global_cable17 -> add17::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add18);             // global_cable18 -> add18::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add19);             // global_cable19 -> add19::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add20);             // global_cable20 -> add20::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add21);             // global_cable21 -> add21::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add22);             // global_cable22 -> add22::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add23);             // global_cable23 -> add23::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                         // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                        // xfader -> gain1::Gain
		peak2.getParameter().connectT(0, xfader);                            // peak2 -> xfader::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add24); // global_cable24 -> add24::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add25); // global_cable25 -> add25::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add26); // global_cable26 -> add26::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add27); // global_cable27 -> add27::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add28); // global_cable28 -> add28::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add29); // global_cable29 -> add29::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add30); // global_cable30 -> add30::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add31); // global_cable31 -> add31::Value
		peak3.getParameter().connectT(0, one_pole);                          // peak3 -> one_pole::Frequency
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
		branch.setParameterT(0, 0.); // container::branch::Index
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch1::Index is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
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
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // branch4::Index is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add24::Value is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add25::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		pma.setParameterT(0, 0.); // control::pma::Value
		pma.setParameterT(1, 1.); // control::pma::Multiply
		;                         // pma::Add is automated
		
		;                                   // tempo_sync::Tempo is automated
		;                                   // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 106.1); // control::tempo_sync::UnsyncedTime
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // receive::Feedback is automated
		
		; // branch2::Index is automated
		
		;                                 // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 512.); // core::fix_delay::FadeTime
		
		; // jdelay_thiran::Limit is automated
		; // jdelay_thiran::DelayTime is automated
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		;                                // one_pole::Mode is automated
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable1_t
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable9_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable17_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable18_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable19_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable20_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable21_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable22_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable23_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable24_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable25_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable26_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable27_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable28_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable29_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable30_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // StageDelay_impl::global_cable31_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(2).getT(1).setExternalData(b, index); // StageDelay_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(4).getT(1).setExternalData(b, index); // StageDelay_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(5).getT(1).setExternalData(b, index); // StageDelay_impl::peak3_t<NV>
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
using StageDelay = wrap::node<StageDelay_impl::instance<NV>>;
}


