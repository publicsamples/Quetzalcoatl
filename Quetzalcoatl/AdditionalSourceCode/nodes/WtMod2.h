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

namespace WtMod2_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable16_t_index = runtime_target::indexers::fix_hash<87252>;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = runtime_target::indexers::fix_hash<87253>;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable23_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = runtime_target::indexers::fix_hash<87254>;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = runtime_target::indexers::fix_hash<87255>;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable20_t_index = runtime_target::indexers::fix_hash<87256>;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable19_t_index = runtime_target::indexers::fix_hash<87257>;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable19_t<NV>>, 
                                   math::add<NV>>;
using global_cable18_t_index = runtime_target::indexers::fix_hash<87258>;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable18_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = runtime_target::indexers::fix_hash<87259>;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable17_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain17_t<NV>>, 
                                    chain24_t<NV>, 
                                    chain23_t<NV>, 
                                    chain22_t<NV>, 
                                    chain21_t<NV>, 
                                    chain20_t<NV>, 
                                    chain19_t<NV>, 
                                    chain18_t<NV>>;

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
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, branch1_t<NV>>, 
                                 peak1_t<NV>, 
                                 math::clear<NV>>;

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
using peak_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, smoothed_parameter_t<NV>>, 
                                 smoothed_parameter1_t<NV>>;

namespace softbypass_switch9_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(Switch_InputRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using Switch = parameter::chain<Switch_InputRange, 
                                parameter::plain<WtMod2_impl::switcher_t<NV>, 0>>;

}

template <int NV>
using softbypass_switch9_t = container::chain<softbypass_switch9_t_parameters::Switch<NV>, 
                                              wrap::fix<2, chain_t<NV>>, 
                                              switcher_t<NV>, 
                                              sb_container_t<NV>, 
                                              peak_t<NV>, 
                                              pma_t<NV>, 
                                              split_t<NV>, 
                                              math::clear<NV>, 
                                              input_toggle_t<NV>, 
                                              math::add<NV>>;

namespace WtMod2_t_parameters
{
// Parameter list for WtMod2_impl::WtMod2_t --------------------------------------------------------

DECLARE_PARAMETER_RANGE(modsrc_InputRange, 
                        0., 
                        8.);
DECLARE_PARAMETER_RANGE_STEP(modsrc_0Range, 
                             0., 
                             7., 
                             1.);

template <int NV>
using modsrc_0 = parameter::from0To1<WtMod2_impl::softbypass_switch9_t<NV>, 
                                     0, 
                                     modsrc_0Range>;

template <int NV>
using modsrc = parameter::chain<modsrc_InputRange, modsrc_0<NV>>;

DECLARE_PARAMETER_RANGE(PosMod_InputRange, 
                        -0.99, 
                        0.99);
DECLARE_PARAMETER_RANGE(PosMod_0Range, 
                        -1., 
                        1.);

template <int NV>
using PosMod_0 = parameter::from0To1<WtMod2_impl::pma_t<NV>, 
                                     1, 
                                     PosMod_0Range>;

template <int NV>
using PosMod = parameter::chain<PosMod_InputRange, PosMod_0<NV>>;

template <int NV>
using Smooth = parameter::chain<ranges::Identity, 
                                parameter::plain<WtMod2_impl::smoothed_parameter_t<NV>, 1>, 
                                parameter::plain<WtMod2_impl::smoothed_parameter1_t<NV>, 1>>;

template <int NV>
using SmoothMode = parameter::plain<WtMod2_impl::input_toggle_t<NV>, 
                                    0>;
template <int NV>
using STAGE = parameter::plain<WtMod2_impl::branch1_t<NV>, 
                               0>;
template <int NV>
using WtMod2_t_plist = parameter::list<modsrc<NV>, 
                                       PosMod<NV>, 
                                       Smooth<NV>, 
                                       SmoothMode<NV>, 
                                       STAGE<NV>>;
}

template <int NV>
using WtMod2_t_ = container::chain<WtMod2_t_parameters::WtMod2_t_plist<NV>, 
                                   wrap::fix<2, softbypass_switch9_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public WtMod2_impl::WtMod2_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(WtMod2);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(82)
		{
			0x005B, 0x0000, 0x6D00, 0x646F, 0x7273, 0x0063, 0x0000, 0x0000, 
            0x0000, 0x4100, 0x6C8B, 0x4126, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x5000, 0x736F, 0x6F4D, 0x0064, 0x70A4, 0xBF7D, 
            0x70A4, 0x3F7D, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x025B, 0x0000, 0x5300, 0x6F6D, 0x746F, 0x0068, 0xCCCD, 0x3DCC, 
            0x0000, 0x447A, 0xCCCD, 0x3DCC, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 
            0x035B, 0x0000, 0x5300, 0x6F6D, 0x746F, 0x4D68, 0x646F, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x045B, 0x0000, 0x5300, 0x4154, 0x4547, 0x0000, 
            0x0000, 0x0000, 0xE000, 0x0040, 0xE000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& softbypass_switch9 = this->getT(0);                             // WtMod2_impl::softbypass_switch9_t<NV>
		auto& chain = this->getT(0).getT(0);                                  // WtMod2_impl::chain_t<NV>
		auto& branch1 = this->getT(0).getT(0).getT(0);                        // WtMod2_impl::branch1_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(0).getT(0);                // WtMod2_impl::chain17_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(0).getT(0).getT(0); // WtMod2_impl::global_cable16_t<NV>
		auto& add17 = this->getT(0).getT(0).getT(0).getT(0).getT(1);          // math::add<NV>
		auto& chain24 = this->getT(0).getT(0).getT(0).getT(1);                // WtMod2_impl::chain24_t<NV>
		auto& global_cable23 = this->getT(0).getT(0).getT(0).getT(1).getT(0); // WtMod2_impl::global_cable23_t<NV>
		auto& add24 = this->getT(0).getT(0).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain23 = this->getT(0).getT(0).getT(0).getT(2);                // WtMod2_impl::chain23_t<NV>
		auto& global_cable22 = this->getT(0).getT(0).getT(0).getT(2).getT(0); // WtMod2_impl::global_cable22_t<NV>
		auto& add23 = this->getT(0).getT(0).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(0).getT(3);                // WtMod2_impl::chain22_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(0).getT(3).getT(0); // WtMod2_impl::global_cable21_t<NV>
		auto& add22 = this->getT(0).getT(0).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(0).getT(4);                // WtMod2_impl::chain21_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(0).getT(4).getT(0); // WtMod2_impl::global_cable20_t<NV>
		auto& add21 = this->getT(0).getT(0).getT(0).getT(4).getT(1);          // math::add<NV>
		auto& chain20 = this->getT(0).getT(0).getT(0).getT(5);                // WtMod2_impl::chain20_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(0).getT(5).getT(0); // WtMod2_impl::global_cable19_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(0).getT(5).getT(1);          // math::add<NV>
		auto& chain19 = this->getT(0).getT(0).getT(0).getT(6);                // WtMod2_impl::chain19_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(0).getT(6).getT(0); // WtMod2_impl::global_cable18_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(0).getT(6).getT(1);          // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(0).getT(7);                // WtMod2_impl::chain18_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(0).getT(7).getT(0); // WtMod2_impl::global_cable17_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(0).getT(7).getT(1);          // math::add<NV>
		auto& peak1 = this->getT(0).getT(0).getT(1);                          // WtMod2_impl::peak1_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(2);                         // math::clear<NV>
		auto& switcher = this->getT(0).getT(1);                               // WtMod2_impl::switcher_t<NV>
		auto& sb_container = this->getT(0).getT(2);                           // WtMod2_impl::sb_container_t<NV>
		auto& sb1 = this->getT(0).getT(2).getT(0);                            // WtMod2_impl::sb1_t<NV>
		auto& chain1 = this->getT(0).getT(2).getT(0).getT(0);                 // WtMod2_impl::chain1_t<NV>
		auto& global_cable = this->getT(0).getT(2).getT(0).getT(0).getT(0);   // WtMod2_impl::global_cable_t<NV>
		auto& add1 = this->getT(0).getT(2).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& sb2 = this->getT(0).getT(2).getT(1);                            // WtMod2_impl::sb2_t<NV>
		auto& chain2 = this->getT(0).getT(2).getT(1).getT(0);                 // WtMod2_impl::chain2_t<NV>
		auto& global_cable2 = this->getT(0).getT(2).getT(1).getT(0).getT(0);  // WtMod2_impl::global_cable2_t<NV>
		auto& add2 = this->getT(0).getT(2).getT(1).getT(0).getT(1);           // math::add<NV>
		auto& sb3 = this->getT(0).getT(2).getT(2);                            // WtMod2_impl::sb3_t<NV>
		auto& chain3 = this->getT(0).getT(2).getT(2).getT(0);                 // WtMod2_impl::chain3_t<NV>
		auto& global_cable3 = this->getT(0).getT(2).getT(2).getT(0).getT(0);  // WtMod2_impl::global_cable3_t<NV>
		auto& add3 = this->getT(0).getT(2).getT(2).getT(0).getT(1);           // math::add<NV>
		auto& sb4 = this->getT(0).getT(2).getT(3);                            // WtMod2_impl::sb4_t<NV>
		auto& chain4 = this->getT(0).getT(2).getT(3).getT(0);                 // WtMod2_impl::chain4_t<NV>
		auto& global_cable4 = this->getT(0).getT(2).getT(3).getT(0).getT(0);  // WtMod2_impl::global_cable4_t<NV>
		auto& add4 = this->getT(0).getT(2).getT(3).getT(0).getT(1);           // math::add<NV>
		auto& sb5 = this->getT(0).getT(2).getT(4);                            // WtMod2_impl::sb5_t<NV>
		auto& chain5 = this->getT(0).getT(2).getT(4).getT(0);                 // WtMod2_impl::chain5_t<NV>
		auto& global_cable5 = this->getT(0).getT(2).getT(4).getT(0).getT(0);  // WtMod2_impl::global_cable5_t<NV>
		auto& add5 = this->getT(0).getT(2).getT(4).getT(0).getT(1);           // math::add<NV>
		auto& sb6 = this->getT(0).getT(2).getT(5);                            // WtMod2_impl::sb6_t<NV>
		auto& chain6 = this->getT(0).getT(2).getT(5).getT(0);                 // WtMod2_impl::chain6_t<NV>
		auto& global_cable6 = this->getT(0).getT(2).getT(5).getT(0).getT(0);  // WtMod2_impl::global_cable6_t<NV>
		auto& add6 = this->getT(0).getT(2).getT(5).getT(0).getT(1);           // math::add<NV>
		auto& sb7 = this->getT(0).getT(2).getT(6);                            // WtMod2_impl::sb7_t<NV>
		auto& chain7 = this->getT(0).getT(2).getT(6).getT(0);                 // WtMod2_impl::chain7_t<NV>
		auto& global_cable7 = this->getT(0).getT(2).getT(6).getT(0).getT(0);  // WtMod2_impl::global_cable7_t<NV>
		auto& add7 = this->getT(0).getT(2).getT(6).getT(0).getT(1);           // math::add<NV>
		auto& sb8 = this->getT(0).getT(2).getT(7);                            // WtMod2_impl::sb8_t<NV>
		auto& chain8 = this->getT(0).getT(2).getT(7).getT(0);                 // WtMod2_impl::chain8_t<NV>
		auto& global_cable8 = this->getT(0).getT(2).getT(7).getT(0).getT(0);  // WtMod2_impl::global_cable8_t<NV>
		auto& add8 = this->getT(0).getT(2).getT(7).getT(0).getT(1);           // math::add<NV>
		auto& peak = this->getT(0).getT(3);                                   // WtMod2_impl::peak_t<NV>
		auto& pma = this->getT(0).getT(4);                                    // WtMod2_impl::pma_t<NV>
		auto& split = this->getT(0).getT(5);                                  // WtMod2_impl::split_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(5).getT(0);             // WtMod2_impl::smoothed_parameter_t<NV>
		auto& smoothed_parameter1 = this->getT(0).getT(5).getT(1);            // WtMod2_impl::smoothed_parameter1_t<NV>
		auto& clear = this->getT(0).getT(6);                                  // math::clear<NV>
		auto& input_toggle = this->getT(0).getT(7);                           // WtMod2_impl::input_toggle_t<NV>
		auto& add = this->getT(0).getT(8);                                    // math::add<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		softbypass_switch9.getParameterT(0).connectT(0, switcher); // Switch -> switcher::Value
		this->getParameterT(0).connectT(0, softbypass_switch9);    // modsrc -> softbypass_switch9::Switch
		
		this->getParameterT(1).connectT(0, pma); // PosMod -> pma::Multiply
		
		auto& Smooth_p = this->getParameterT(2);
		Smooth_p.connectT(0, smoothed_parameter);  // Smooth -> smoothed_parameter::SmoothingTime
		Smooth_p.connectT(1, smoothed_parameter1); // Smooth -> smoothed_parameter1::SmoothingTime
		
		this->getParameterT(3).connectT(0, input_toggle); // SmoothMode -> input_toggle::Input
		
		this->getParameterT(4).connectT(0, branch1); // STAGE -> branch1::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable16.getWrappedObject().getParameter().connectT(0, add17);    // global_cable16 -> add17::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add24);    // global_cable23 -> add24::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add23);    // global_cable22 -> add23::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add22);    // global_cable21 -> add22::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add21);    // global_cable20 -> add21::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add20);    // global_cable19 -> add20::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add19);    // global_cable18 -> add19::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add18);    // global_cable17 -> add18::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, add);        // input_toggle -> add::Value
		smoothed_parameter.getParameter().connectT(0, input_toggle);            // smoothed_parameter -> input_toggle::Value1
		smoothed_parameter1.getParameter().connectT(0, input_toggle);           // smoothed_parameter1 -> input_toggle::Value2
		pma.getWrappedObject().getParameter().connectT(0, smoothed_parameter);  // pma -> smoothed_parameter::Value
		pma.getWrappedObject().getParameter().connectT(1, smoothed_parameter1); // pma -> smoothed_parameter1::Value
		peak1.getParameter().connectT(0, pma);                                  // peak1 -> pma::Add
		global_cable.getWrappedObject().getParameter().connectT(0, add1);       // global_cable -> add1::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);      // global_cable2 -> add2::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add3);      // global_cable3 -> add3::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add4);      // global_cable4 -> add4::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add5);      // global_cable5 -> add5::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add6);      // global_cable6 -> add6::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add7);      // global_cable7 -> add7::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add8);      // global_cable8 -> add8::Value
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1); // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2); // switcher -> sb2::Bypassed
		switcher_p.getParameterT(2).connectT(0, sb3); // switcher -> sb3::Bypassed
		switcher_p.getParameterT(3).connectT(0, sb4); // switcher -> sb4::Bypassed
		switcher_p.getParameterT(4).connectT(0, sb5); // switcher -> sb5::Bypassed
		switcher_p.getParameterT(5).connectT(0, sb6); // switcher -> sb6::Bypassed
		switcher_p.getParameterT(6).connectT(0, sb7); // switcher -> sb7::Bypassed
		switcher_p.getParameterT(7).connectT(0, sb8); // switcher -> sb8::Bypassed
		peak.getParameter().connectT(0, pma);         // peak -> pma::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // softbypass_switch9::Switch is automated
		
		; // branch1::Index is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add17::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add24::Value is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add23::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add22::Value is automated
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add20::Value is automated
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
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
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.1);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 7.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable23_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable22_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable21_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable20_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable19_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable18_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable17_t<NV>
		this->getT(0).getT(2).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable2_t<NV>
		this->getT(0).getT(2).getT(2).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable3_t<NV>
		this->getT(0).getT(2).getT(3).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable4_t<NV>
		this->getT(0).getT(2).getT(4).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable5_t<NV>
		this->getT(0).getT(2).getT(5).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable6_t<NV>
		this->getT(0).getT(2).getT(6).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable7_t<NV>
		this->getT(0).getT(2).getT(7).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // WtMod2_impl::global_cable8_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).setExternalData(b, index); // WtMod2_impl::peak1_t<NV>
		this->getT(0).getT(3).setExternalData(b, index);         // WtMod2_impl::peak_t<NV>
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
using WtMod2 = wrap::node<WtMod2_impl::instance<NV>>;
}


