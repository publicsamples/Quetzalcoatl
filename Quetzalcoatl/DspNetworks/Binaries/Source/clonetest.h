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

namespace clonetest_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using file_player1_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<0>>;
DECLARE_PARAMETER_RANGE(pma11_modRange, 
                        0., 
                        2.);

template <int NV>
using pma11_mod = parameter::from0To1<file_player1_t<NV>, 
                                      3, 
                                      pma11_modRange>;

template <int NV>
using pma11_t = control::pma<NV, pma11_mod<NV>>;

template <int NV>
using osc_fm_route1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, pma11_t<NV>>>;

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<1>>;
DECLARE_PARAMETER_RANGE_STEP(pma13_modRange, 
                             0., 
                             2., 
                             0.01);

template <int NV>
using pma13_mod = parameter::from0To1<file_player_t<NV>, 
                                      3, 
                                      pma13_modRange>;

template <int NV>
using pma13_t = control::pma<NV, pma13_mod<NV>>;

template <int NV>
using osc_fm_route3_t = container::chain<parameter::empty, 
                                         wrap::fix<2, pma13_t<NV>>>;

DECLARE_PARAMETER_RANGE_SKEW(pma10_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma10_mod = parameter::from0To1<filters::svf<NV>, 
                                      0, 
                                      pma10_modRange>;

template <int NV>
using pma10_t = control::pma<NV, pma10_mod<NV>>;

template <int NV>
using cut_fm_route_t = container::chain<parameter::empty, 
                                        wrap::fix<2, pma10_t<NV>>>;

DECLARE_PARAMETER_RANGE(pma15_modRange, 
                        0., 
                        20000.);

template <int NV>
using pma15_mod = parameter::from0To1<fx::phase_delay<NV>, 
                                      0, 
                                      pma15_modRange>;

template <int NV>
using pma15_t = control::pma<NV, pma15_mod<NV>>;

template <int NV>
using cut_fm_route1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, pma15_t<NV>>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, control::pma<NV, parameter::empty>>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, osc_fm_route1_t<NV>>, 
                                  osc_fm_route3_t<NV>, 
                                  cut_fm_route_t<NV>, 
                                  cut_fm_route1_t<NV>, 
                                  chain7_t<NV>>;

using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma13_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak1_t<NV>>, 
                                   math::clear<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain11_t>, 
                                  chain12_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

using xfader_c0 = parameter::from0To1<core::gain, 
                                      0, 
                                      xfader_c0Range>;

using xfader_c1 = xfader_c0;

using xfader_multimod = parameter::list<xfader_c0, xfader_c1>;

using xfader_t = control::xfader<xfader_multimod, faders::linear>;

using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain>>;

template <int NV>
using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, core::gain>, 
                                core::gain, 
                                filters::one_pole<NV>>;

template <int NV>
using sb1_t = bypass::smoothed<20, sb1_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb1_t<NV>>;

using sb2_t_ = chain11_t;

using sb2_t = bypass::smoothed<20, sb2_t_>;
using switcher_c1_0 = parameter::bypass<sb2_t>;

DECLARE_PARAMETER_RANGE_STEP(switcher_c1_1Range, 
                             1., 
                             2., 
                             1.);

template <int NV>
using switcher_c1_1 = parameter::from0To1<file_player_t<NV>, 
                                          0, 
                                          switcher_c1_1Range>;

template <int NV>
using switcher_c1 = parameter::chain<ranges::Identity, 
                                     switcher_c1_0, 
                                     switcher_c1_1<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0<NV>, switcher_c1<NV>>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<2, sb1_t<NV>>, 
                                        sb2_t>;

template <int NV>
using softbypass_switch3_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher_t<NV>>, 
                                              sb_container_t<NV>>;

using chain15_t = chain11_t;

template <int NV>
using peak3_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma11_t<NV>, 0>, 
                                   parameter::plain<control::pma<NV, parameter::empty>, 0>, 
                                   parameter::plain<pma10_t<NV>, 0>, 
                                   parameter::plain<pma15_t<NV>, 0>>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak3_t<NV>>, 
                                   math::clear<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain15_t>, 
                                  chain16_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, softbypass_switch3_t<NV>>, 
                                  file_player_t<NV>, 
                                  split7_t<NV>, 
                                  core::gain>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t>, 
                                 chain1_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split_t<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, file_player1_t<NV>>, 
                                  split5_t<NV>, 
                                  xfader_t, 
                                  chain4_t<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain3_t<NV>>>;

template <int NV>
using framex_block_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, split8_t<NV>>, 
                                         split1_t<NV>, 
                                         filters::svf<NV>, 
                                         fx::phase_delay<NV>>;

template <int NV>
using framex_block_t = wrap::frame<2, framex_block_t_<NV>>;

namespace clonetest_t_parameters
{
// Parameter list for clonetest_impl::clonetest_t --------------------------------------------------

DECLARE_PARAMETER_RANGE(type_InputRange, 
                        0., 
                        4.);
DECLARE_PARAMETER_RANGE_STEP(type_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using type_0 = parameter::from0To1<filters::svf<NV>, 
                                   4, 
                                   type_0Range>;

template <int NV>
using type = parameter::chain<type_InputRange, type_0<NV>>;

DECLARE_PARAMETER_RANGE(amp_fm_InputRange, 
                        -1., 
                        1.);
DECLARE_PARAMETER_RANGE(amp_fm_0Range, 
                        -1., 
                        1.);

template <int NV>
using amp_fm_0 = parameter::from0To1<clonetest_impl::pma15_t<NV>, 
                                     1, 
                                     amp_fm_0Range>;

DECLARE_PARAMETER_RANGE_INV(amp_fm_1Range, 
                            0., 
                            1.);

template <int NV>
using amp_fm_1 = parameter::from0To1_inv<clonetest_impl::pma15_t<NV>, 
                                         2, 
                                         amp_fm_1Range>;

template <int NV>
using amp_fm = parameter::chain<amp_fm_InputRange, 
                                amp_fm_0<NV>, 
                                amp_fm_1<NV>>;

using g1 = parameter::from0To1<core::gain, 
                               0, 
                               clonetest_impl::xfader_c0Range>;

template <int NV>
using f1 = parameter::from0To1<filters::one_pole<NV>, 
                               0, 
                               clonetest_impl::pma10_modRange>;

template <int NV>
using osc1_fm = parameter::plain<clonetest_impl::pma11_t<NV>, 
                                 1>;
template <int NV>
using osc_fm_3 = parameter::plain<clonetest_impl::pma13_t<NV>, 
                                  1>;
template <int NV>
using cut = parameter::plain<clonetest_impl::pma10_t<NV>, 
                             2>;
template <int NV>
using res = parameter::plain<filters::svf<NV>, 1>;
template <int NV>
using cut_fm = parameter::plain<clonetest_impl::pma10_t<NV>, 
                                1>;
using ABmix = parameter::plain<clonetest_impl::xfader_t, 
                               0>;
template <int NV>
using shaper1 = parameter::plain<clonetest_impl::switcher_t<NV>, 
                                 0>;
template <int NV>
using p1 = parameter::plain<clonetest_impl::pma11_t<NV>, 
                            2>;
template <int NV>
using p2 = parameter::plain<clonetest_impl::pma13_t<NV>, 
                            2>;
template <int NV>
using clonetest_t_plist = parameter::list<osc1_fm<NV>, 
                                          osc_fm_3<NV>, 
                                          cut<NV>, 
                                          res<NV>, 
                                          type<NV>, 
                                          cut_fm<NV>, 
                                          amp_fm<NV>, 
                                          ABmix, 
                                          shaper1<NV>, 
                                          g1, 
                                          f1<NV>, 
                                          p1<NV>, 
                                          p2<NV>>;
}

template <int NV>
using clonetest_t_ = container::chain<clonetest_t_parameters::clonetest_t_plist<NV>, 
                                      wrap::fix<2, framex_block_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public clonetest_impl::clonetest_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(clonetest);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(198)
		{
			0x005B, 0x0000, 0x6F00, 0x6373, 0x5F31, 0x6D66, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0xE93F, 0xE286, 0x003C, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0001, 0x0000, 0x736F, 0x5F63, 0x6D66, 0x335F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x233F, 0x0FB7, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0002, 0x0000, 0x7563, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x442F, 0x3ED2, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x035B, 0x0000, 0x7200, 0x7365, 0x9A00, 0x9999, 0x663E, 0x1E66, 
            0x2241, 0xD583, 0x1840, 0x8789, 0x003E, 0x0000, 0x5B00, 0x0004, 
            0x0000, 0x7974, 0x6570, 0x0000, 0x0000, 0x0000, 0x8000, 0xAC40, 
            0x021C, 0x003B, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 
            0x7563, 0x5F74, 0x6D66, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 
            0x6D61, 0x5F70, 0x6D66, 0x0000, 0x8000, 0x00BF, 0x8000, 0xFA3F, 
            0x0144, 0x00BF, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 
            0x4241, 0x696D, 0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x1789, 
            0x3EF6, 0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 0x7300, 
            0x6168, 0x6570, 0x3172, 0x0000, 0x0000, 0x0000, 0x8000, 0x8F3F, 
            0x79A0, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0009, 0x0000, 
            0x3167, 0x0000, 0x0000, 0x0000, 0x8000, 0xB93F, 0x213D, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x000A, 0x0000, 0x3166, 0x0000, 
            0x0000, 0x0000, 0x8000, 0xBB3F, 0xF2EF, 0x003E, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000B, 0x0000, 0x3170, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x1B3F, 0x0A37, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x000C, 0x0000, 0x3270, 0x0000, 0x0000, 0x0000, 0x8000, 0x7F3F, 
            0x0C82, 0x003F, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& framex_block = this->getT(0);                                                       // clonetest_impl::framex_block_t<NV>
		auto& split8 = this->getT(0).getT(0);                                                     // clonetest_impl::split8_t<NV>
		auto& osc_fm_route1 = this->getT(0).getT(0).getT(0);                                      // clonetest_impl::osc_fm_route1_t<NV>
		auto& pma11 = this->getT(0).getT(0).getT(0).getT(0);                                      // clonetest_impl::pma11_t<NV>
		auto& osc_fm_route3 = this->getT(0).getT(0).getT(1);                                      // clonetest_impl::osc_fm_route3_t<NV>
		auto& pma13 = this->getT(0).getT(0).getT(1).getT(0);                                      // clonetest_impl::pma13_t<NV>
		auto& cut_fm_route = this->getT(0).getT(0).getT(2);                                       // clonetest_impl::cut_fm_route_t<NV>
		auto& pma10 = this->getT(0).getT(0).getT(2).getT(0);                                      // clonetest_impl::pma10_t<NV>
		auto& cut_fm_route1 = this->getT(0).getT(0).getT(3);                                      // clonetest_impl::cut_fm_route1_t<NV>
		auto& pma15 = this->getT(0).getT(0).getT(3).getT(0);                                      // clonetest_impl::pma15_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(4);                                             // clonetest_impl::chain7_t<NV>
		auto& pma = this->getT(0).getT(0).getT(4).getT(0);                                        // control::pma<NV, parameter::empty>
		auto& split1 = this->getT(0).getT(1);                                                     // clonetest_impl::split1_t<NV>
		auto& chain3 = this->getT(0).getT(1).getT(0);                                             // clonetest_impl::chain3_t<NV>
		auto& file_player1 = this->getT(0).getT(1).getT(0).getT(0);                               // clonetest_impl::file_player1_t<NV>
		auto& split5 = this->getT(0).getT(1).getT(0).getT(1);                                     // clonetest_impl::split5_t<NV>
		auto& chain11 = this->getT(0).getT(1).getT(0).getT(1).getT(0);                            // clonetest_impl::chain11_t
		auto& chain12 = this->getT(0).getT(1).getT(0).getT(1).getT(1);                            // clonetest_impl::chain12_t<NV>
		auto& peak1 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0);                      // clonetest_impl::peak1_t<NV>
		auto& clear3 = this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(1);                     // math::clear<NV>
		auto& xfader = this->getT(0).getT(1).getT(0).getT(2);                                     // clonetest_impl::xfader_t
		auto& chain4 = this->getT(0).getT(1).getT(0).getT(3);                                     // clonetest_impl::chain4_t<NV>
		auto& split = this->getT(0).getT(1).getT(0).getT(3).getT(0);                              // clonetest_impl::split_t<NV>
		auto& chain = this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(0);                      // clonetest_impl::chain_t
		auto& gain2 = this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(0).getT(0);              // core::gain
		auto& chain1 = this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(1);                     // clonetest_impl::chain1_t<NV>
		auto& softbypass_switch3 = this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(1).getT(0); // clonetest_impl::softbypass_switch3_t<NV>
		auto& switcher = this->getT(0).getT(1).getT(0).getT(3).                                   // clonetest_impl::switcher_t<NV>
                         getT(0).getT(1).getT(0).getT(0);
		auto& sb_container = this->getT(0).getT(1).getT(0).getT(3).                        // clonetest_impl::sb_container_t<NV>
                             getT(0).getT(1).getT(0).getT(1);
		auto& sb1 = this->getT(0).getT(1).getT(0).getT(3).                                 // clonetest_impl::sb1_t<NV>
                    getT(0).getT(1).getT(0).getT(1).
                    getT(0);
		auto& gain3 = this->getT(0).getT(1).getT(0).getT(3).getT(0).                       // core::gain
                      getT(1).getT(0).getT(1).getT(0).getT(0);
		auto& gain = this->getT(0).getT(1).getT(0).getT(3).getT(0).                        // core::gain
                     getT(1).getT(0).getT(1).getT(0).getT(1);
		auto& one_pole = this->getT(0).getT(1).getT(0).getT(3).getT(0).                    // filters::one_pole<NV>
                         getT(1).getT(0).getT(1).getT(0).getT(2);
		auto& sb2 = this->getT(0).getT(1).getT(0).getT(3).                                 // clonetest_impl::sb2_t
                    getT(0).getT(1).getT(0).getT(1).
                    getT(1);
		auto& file_player = this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(1).getT(1); // clonetest_impl::file_player_t<NV>
		auto& split7 = this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(1).getT(2);      // clonetest_impl::split7_t<NV>
		auto& chain15 = this->getT(0).getT(1).getT(0).getT(3).                             // clonetest_impl::chain15_t
                        getT(0).getT(1).getT(2).getT(0);
		auto& chain16 = this->getT(0).getT(1).getT(0).getT(3).                       // clonetest_impl::chain16_t<NV>
                        getT(0).getT(1).getT(2).getT(1);
		auto& peak3 = this->getT(0).getT(1).getT(0).getT(3).                         // clonetest_impl::peak3_t<NV>
                      getT(0).getT(1).getT(2).getT(1).
                      getT(0);
		auto& clear5 = this->getT(0).getT(1).getT(0).getT(3).                        // math::clear<NV>
                       getT(0).getT(1).getT(2).getT(1).
                       getT(1);
		auto& gain1 = this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(1).getT(3); // core::gain
		auto& svf = this->getT(0).getT(2);                                           // filters::svf<NV>
		auto& phase_delay = this->getT(0).getT(3);                                   // fx::phase_delay<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma11); // osc1_fm -> pma11::Multiply
		
		this->getParameterT(1).connectT(0, pma13); // osc_fm_3 -> pma13::Multiply
		
		this->getParameterT(2).connectT(0, pma10); // cut -> pma10::Add
		
		this->getParameterT(3).connectT(0, svf); // res -> svf::Q
		
		this->getParameterT(4).connectT(0, svf); // type -> svf::Mode
		
		this->getParameterT(5).connectT(0, pma10); // cut_fm -> pma10::Multiply
		
		auto& amp_fm_p = this->getParameterT(6);
		amp_fm_p.connectT(0, pma15); // amp_fm -> pma15::Multiply
		amp_fm_p.connectT(1, pma15); // amp_fm -> pma15::Add
		
		this->getParameterT(7).connectT(0, xfader); // ABmix -> xfader::Value
		
		this->getParameterT(8).connectT(0, switcher); // shaper1 -> switcher::Value
		
		this->getParameterT(9).connectT(0, gain); // g1 -> gain::Gain
		
		this->getParameterT(10).connectT(0, one_pole); // f1 -> one_pole::Frequency
		
		this->getParameterT(11).connectT(0, pma11); // p1 -> pma11::Add
		
		this->getParameterT(12).connectT(0, pma13); // p2 -> pma13::Add
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma11.getWrappedObject().getParameter().connectT(0, file_player1); // pma11 -> file_player1::FreqRatio
		pma13.getWrappedObject().getParameter().connectT(0, file_player);  // pma13 -> file_player::FreqRatio
		pma10.getWrappedObject().getParameter().connectT(0, svf);          // pma10 -> svf::Frequency
		pma15.getWrappedObject().getParameter().connectT(0, phase_delay);  // pma15 -> phase_delay::Frequency
		peak1.getParameter().connectT(0, pma13);                           // peak1 -> pma13::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain2); // xfader -> gain2::Gain
		xfader_p.getParameterT(1).connectT(0, gain1); // xfader -> gain1::Gain
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1);         // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2);         // switcher -> sb2::Bypassed
		switcher_p.getParameterT(1).connectT(1, file_player); // switcher -> file_player::PlaybackMode
		peak3.getParameter().connectT(0, pma11);              // peak3 -> pma11::Value
		peak3.getParameter().connectT(1, pma);                // peak3 -> pma::Value
		peak3.getParameter().connectT(2, pma10);              // peak3 -> pma10::Value
		peak3.getParameter().connectT(3, pma15);              // peak3 -> pma15::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // pma11::Value is automated
		; // pma11::Multiply is automated
		; // pma11::Add is automated
		
		; // pma13::Value is automated
		; // pma13::Multiply is automated
		; // pma13::Add is automated
		
		; // pma10::Value is automated
		; // pma10::Multiply is automated
		; // pma10::Add is automated
		
		; // pma15::Value is automated
		; // pma15::Multiply is automated
		; // pma15::Add is automated
		
		;                         // pma::Value is automated
		pma.setParameterT(1, 0.); // control::pma::Multiply
		pma.setParameterT(2, 0.); // control::pma::Add
		
		file_player1.setParameterT(0, 2.);      // core::file_player::PlaybackMode
		file_player1.setParameterT(1, 1.);      // core::file_player::Gate
		file_player1.setParameterT(2, 443.295); // core::file_player::RootFrequency
		;                                       // file_player1::FreqRatio is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // xfader::Value is automated
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 8.4);   // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // switcher::Value is automated
		
		gain3.setParameterT(0, -9.9);  // core::gain::Gain
		gain3.setParameterT(1, 0.);    // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 6.6);   // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                    // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);       // filters::one_pole::Q
		one_pole.setParameterT(2, 6.92439);  // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.111342); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);       // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);       // filters::one_pole::Enabled
		
		;                                      // file_player::PlaybackMode is automated
		file_player.setParameterT(1, 1.);      // core::file_player::Gate
		file_player.setParameterT(2, 744.739); // core::file_player::RootFrequency
		;                                      // file_player::FreqRatio is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 10.6);  // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                           // svf::Mode is automated
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		; // phase_delay::Frequency is automated
		
		this->setParameterT(0, 0.0276522);
		this->setParameterT(1, 0.561388);
		this->setParameterT(2, 0.410676);
		this->setParameterT(3, 6.67226);
		this->setParameterT(4, 0.00198535);
		this->setParameterT(5, 1.);
		this->setParameterT(6, -0.504959);
		this->setParameterT(7, 0.480648);
		this->setParameterT(8, 0.975106);
		this->setParameterT(9, 0.629848);
		this->setParameterT(10, 0.474485);
		this->setParameterT(11, 0.539903);
		this->setParameterT(12, 0.548866);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);                         // clonetest_impl::file_player1_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).setExternalData(b, index);         // clonetest_impl::peak1_t<NV>
		this->getT(0).getT(1).getT(0).getT(3).getT(0).getT(1).getT(1).setExternalData(b, index); // clonetest_impl::file_player_t<NV>
		this->getT(0).getT(1).getT(0).getT(3).                                                   // clonetest_impl::peak3_t<NV>
        getT(0).getT(1).getT(2).getT(1).
        getT(0).setExternalData(b, index);
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
using clonetest = wrap::node<clonetest_impl::instance<NV>>;
}


