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

namespace chain26_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using input_toggle16_t = control::input_toggle<parameter::plain<routing::event_data_writer<NV>, 1>>;
template <int NV>
using smoothed_parameter1_x4_t = wrap::mod<parameter::plain<input_toggle16_t<NV>, 1>, 
                                           control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter17_t = wrap::mod<parameter::plain<input_toggle16_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, smoothed_parameter1_x4_t<NV>>, 
                                 smoothed_parameter17_t<NV>, 
                                 input_toggle16_t<NV>, 
                                 routing::event_data_writer<NV>>;

template <int NV> using input_toggle_t = input_toggle16_t<NV>;
template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 1>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter15_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 2>, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, smoothed_parameter_t<NV>>, 
                                  smoothed_parameter15_t<NV>, 
                                  input_toggle_t<NV>, 
                                  routing::event_data_writer<NV>>;

template <int NV> using input_toggle1_t = input_toggle16_t<NV>;
template <int NV>
using smoothed_parameter1_t = wrap::mod<parameter::plain<input_toggle1_t<NV>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter16_t = wrap::mod<parameter::plain<input_toggle1_t<NV>, 1>, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, smoothed_parameter1_t<NV>>, 
                                   smoothed_parameter16_t<NV>, 
                                   input_toggle1_t<NV>, 
                                   routing::event_data_writer<NV>>;

template <int NV> using input_toggle2_t = input_toggle16_t<NV>;
template <int NV>
using smoothed_parameter2_t = wrap::mod<parameter::plain<input_toggle2_t<NV>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter19_t = wrap::mod<parameter::plain<input_toggle2_t<NV>, 1>, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, smoothed_parameter2_t<NV>>, 
                                   smoothed_parameter19_t<NV>, 
                                   input_toggle2_t<NV>, 
                                   routing::event_data_writer<NV>>;

template <int NV> using input_toggle3_t = input_toggle16_t<NV>;
template <int NV>
using smoothed_parameter3_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter20_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 1>, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, smoothed_parameter3_t<NV>>, 
                                   smoothed_parameter20_t<NV>, 
                                   input_toggle3_t<NV>, 
                                   routing::event_data_writer<NV>>;

template <int NV> using input_toggle4_t = input_toggle16_t<NV>;
template <int NV>
using smoothed_parameter4_t = wrap::mod<parameter::plain<input_toggle4_t<NV>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using smoothed_parameter21_t = wrap::mod<parameter::plain<input_toggle4_t<NV>, 1>, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, smoothed_parameter4_t<NV>>, 
                                   smoothed_parameter21_t<NV>, 
                                   input_toggle4_t<NV>, 
                                   routing::event_data_writer<NV>>;

using smoothed_parameter5_mod = parameter::plain<control::input_toggle<parameter::empty>, 
                                                 0>;
template <int NV>
using smoothed_parameter5_t = wrap::mod<smoothed_parameter5_mod, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using smoothed_parameter22_mod = parameter::plain<control::input_toggle<parameter::empty>, 
                                                  1>;
template <int NV>
using smoothed_parameter22_t = wrap::mod<smoothed_parameter22_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, smoothed_parameter5_t<NV>>, 
                                   smoothed_parameter22_t<NV>, 
                                   control::input_toggle<parameter::empty>, 
                                   routing::event_data_writer<NV>>;

using smoothed_parameter6_mod = smoothed_parameter5_mod;
template <int NV>
using smoothed_parameter6_t = wrap::mod<smoothed_parameter6_mod, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using smoothed_parameter23_mod = smoothed_parameter22_mod;
template <int NV>
using smoothed_parameter23_t = wrap::mod<smoothed_parameter23_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, smoothed_parameter6_t<NV>>, 
                                   smoothed_parameter23_t<NV>, 
                                   control::input_toggle<parameter::empty>, 
                                   routing::event_data_writer<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>, 
                                 chain1_t<NV>, 
                                 chain11_t<NV>, 
                                 chain12_t<NV>, 
                                 chain13_t<NV>, 
                                 chain15_t<NV>, 
                                 chain16_t<NV>, 
                                 chain17_t<NV>>;

namespace chain26_t_parameters
{
// Parameter list for chain26_impl::chain26_t ------------------------------------------------------

template <int NV>
using Smooth = parameter::chain<ranges::Identity, 
                                parameter::plain<chain26_impl::smoothed_parameter1_x4_t<NV>, 1>, 
                                parameter::plain<chain26_impl::smoothed_parameter17_t<NV>, 1>, 
                                parameter::plain<chain26_impl::smoothed_parameter_t<NV>, 1>, 
                                parameter::plain<chain26_impl::smoothed_parameter15_t<NV>, 1>, 
                                parameter::plain<chain26_impl::smoothed_parameter16_t<NV>, 1>, 
                                parameter::plain<chain26_impl::smoothed_parameter19_t<NV>, 1>, 
                                parameter::plain<chain26_impl::smoothed_parameter20_t<NV>, 1>, 
                                parameter::plain<chain26_impl::smoothed_parameter21_t<NV>, 1>, 
                                parameter::plain<chain26_impl::smoothed_parameter22_t<NV>, 1>, 
                                parameter::plain<chain26_impl::smoothed_parameter23_t<NV>, 1>>;

template <int NV>
using SmoothType = parameter::chain<ranges::Identity, 
                                    parameter::plain<chain26_impl::input_toggle16_t<NV>, 0>, 
                                    parameter::plain<chain26_impl::input_toggle_t<NV>, 0>>;

template <int NV>
using in1 = parameter::chain<ranges::Identity, 
                             parameter::plain<chain26_impl::smoothed_parameter1_x4_t<NV>, 0>, 
                             parameter::plain<chain26_impl::smoothed_parameter17_t<NV>, 0>>;

template <int NV>
using in2 = parameter::chain<ranges::Identity, 
                             parameter::plain<chain26_impl::smoothed_parameter_t<NV>, 0>, 
                             parameter::plain<chain26_impl::smoothed_parameter15_t<NV>, 0>>;

template <int NV>
using in3 = parameter::chain<ranges::Identity, 
                             parameter::plain<chain26_impl::smoothed_parameter1_t<NV>, 0>, 
                             parameter::plain<chain26_impl::smoothed_parameter16_t<NV>, 0>>;

template <int NV>
using in4 = parameter::chain<ranges::Identity, 
                             parameter::plain<chain26_impl::smoothed_parameter2_t<NV>, 0>, 
                             parameter::plain<chain26_impl::smoothed_parameter19_t<NV>, 0>>;

template <int NV>
using in5 = parameter::chain<ranges::Identity, 
                             parameter::plain<chain26_impl::smoothed_parameter3_t<NV>, 0>, 
                             parameter::plain<chain26_impl::smoothed_parameter20_t<NV>, 0>>;

template <int NV>
using in6 = parameter::chain<ranges::Identity, 
                             parameter::plain<chain26_impl::smoothed_parameter4_t<NV>, 0>, 
                             parameter::plain<chain26_impl::smoothed_parameter21_t<NV>, 0>>;

template <int NV>
using in7 = parameter::chain<ranges::Identity, 
                             parameter::plain<chain26_impl::smoothed_parameter5_t<NV>, 0>, 
                             parameter::plain<chain26_impl::smoothed_parameter22_t<NV>, 0>>;

template <int NV>
using in8 = parameter::chain<ranges::Identity, 
                             parameter::plain<chain26_impl::smoothed_parameter6_t<NV>, 0>, 
                             parameter::plain<chain26_impl::smoothed_parameter23_t<NV>, 0>>;

template <int NV>
using chain26_t_plist = parameter::list<Smooth<NV>, 
                                        SmoothType<NV>, 
                                        in1<NV>, 
                                        in2<NV>, 
                                        in3<NV>, 
                                        in4<NV>, 
                                        in5<NV>, 
                                        in6<NV>, 
                                        in7<NV>, 
                                        in8<NV>>;
}

template <int NV>
using chain26_t_ = container::chain<chain26_t_parameters::chain26_t_plist<NV>, 
                                    wrap::fix<1, split_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public chain26_impl::chain26_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(chain26);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(152)
		{
			0x005B, 0x0000, 0x5300, 0x6F6D, 0x746F, 0x0068, 0xCCCD, 0x3DCC, 
            0x0000, 0x447A, 0x0000, 0x3F80, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 
            0x015B, 0x0000, 0x5300, 0x6F6D, 0x746F, 0x5468, 0x7079, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x025B, 0x0000, 0x6900, 0x316E, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0003, 0x0000, 0x6E69, 0x0032, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 
            0x0000, 0x6900, 0x336E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 
            0x6E69, 0x0034, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x065B, 0x0000, 0x6900, 0x356E, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 0x6E69, 0x0036, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x085B, 0x0000, 0x6900, 0x376E, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0009, 0x0000, 0x6E69, 0x0038, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split = this->getT(0);                                  // chain26_impl::split_t<NV>
		auto& chain = this->getT(0).getT(0);                          // chain26_impl::chain_t<NV>
		auto& smoothed_parameter1_x4 = this->getT(0).getT(0).getT(0); // chain26_impl::smoothed_parameter1_x4_t<NV>
		auto& smoothed_parameter17 = this->getT(0).getT(0).getT(1);   // chain26_impl::smoothed_parameter17_t<NV>
		auto& input_toggle16 = this->getT(0).getT(0).getT(2);         // chain26_impl::input_toggle16_t<NV>
		auto& event_data_writer = this->getT(0).getT(0).getT(3);      // routing::event_data_writer<NV>
		auto& chain1 = this->getT(0).getT(1);                         // chain26_impl::chain1_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(1).getT(0);     // chain26_impl::smoothed_parameter_t<NV>
		auto& smoothed_parameter15 = this->getT(0).getT(1).getT(1);   // chain26_impl::smoothed_parameter15_t<NV>
		auto& input_toggle = this->getT(0).getT(1).getT(2);           // chain26_impl::input_toggle_t<NV>
		auto& event_data_writer1 = this->getT(0).getT(1).getT(3);     // routing::event_data_writer<NV>
		auto& chain11 = this->getT(0).getT(2);                        // chain26_impl::chain11_t<NV>
		auto& smoothed_parameter1 = this->getT(0).getT(2).getT(0);    // chain26_impl::smoothed_parameter1_t<NV>
		auto& smoothed_parameter16 = this->getT(0).getT(2).getT(1);   // chain26_impl::smoothed_parameter16_t<NV>
		auto& input_toggle1 = this->getT(0).getT(2).getT(2);          // chain26_impl::input_toggle1_t<NV>
		auto& event_data_writer3 = this->getT(0).getT(2).getT(3);     // routing::event_data_writer<NV>
		auto& chain12 = this->getT(0).getT(3);                        // chain26_impl::chain12_t<NV>
		auto& smoothed_parameter2 = this->getT(0).getT(3).getT(0);    // chain26_impl::smoothed_parameter2_t<NV>
		auto& smoothed_parameter19 = this->getT(0).getT(3).getT(1);   // chain26_impl::smoothed_parameter19_t<NV>
		auto& input_toggle2 = this->getT(0).getT(3).getT(2);          // chain26_impl::input_toggle2_t<NV>
		auto& event_data_writer4 = this->getT(0).getT(3).getT(3);     // routing::event_data_writer<NV>
		auto& chain13 = this->getT(0).getT(4);                        // chain26_impl::chain13_t<NV>
		auto& smoothed_parameter3 = this->getT(0).getT(4).getT(0);    // chain26_impl::smoothed_parameter3_t<NV>
		auto& smoothed_parameter20 = this->getT(0).getT(4).getT(1);   // chain26_impl::smoothed_parameter20_t<NV>
		auto& input_toggle3 = this->getT(0).getT(4).getT(2);          // chain26_impl::input_toggle3_t<NV>
		auto& event_data_writer5 = this->getT(0).getT(4).getT(3);     // routing::event_data_writer<NV>
		auto& chain15 = this->getT(0).getT(5);                        // chain26_impl::chain15_t<NV>
		auto& smoothed_parameter4 = this->getT(0).getT(5).getT(0);    // chain26_impl::smoothed_parameter4_t<NV>
		auto& smoothed_parameter21 = this->getT(0).getT(5).getT(1);   // chain26_impl::smoothed_parameter21_t<NV>
		auto& input_toggle4 = this->getT(0).getT(5).getT(2);          // chain26_impl::input_toggle4_t<NV>
		auto& event_data_writer6 = this->getT(0).getT(5).getT(3);     // routing::event_data_writer<NV>
		auto& chain16 = this->getT(0).getT(6);                        // chain26_impl::chain16_t<NV>
		auto& smoothed_parameter5 = this->getT(0).getT(6).getT(0);    // chain26_impl::smoothed_parameter5_t<NV>
		auto& smoothed_parameter22 = this->getT(0).getT(6).getT(1);   // chain26_impl::smoothed_parameter22_t<NV>
		auto& input_toggle5 = this->getT(0).getT(6).getT(2);          // control::input_toggle<parameter::empty>
		auto& event_data_writer7 = this->getT(0).getT(6).getT(3);     // routing::event_data_writer<NV>
		auto& chain17 = this->getT(0).getT(7);                        // chain26_impl::chain17_t<NV>
		auto& smoothed_parameter6 = this->getT(0).getT(7).getT(0);    // chain26_impl::smoothed_parameter6_t<NV>
		auto& smoothed_parameter23 = this->getT(0).getT(7).getT(1);   // chain26_impl::smoothed_parameter23_t<NV>
		auto& input_toggle6 = this->getT(0).getT(7).getT(2);          // control::input_toggle<parameter::empty>
		auto& event_data_writer8 = this->getT(0).getT(7).getT(3);     // routing::event_data_writer<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& Smooth_p = this->getParameterT(0);
		Smooth_p.connectT(0, smoothed_parameter1_x4); // Smooth -> smoothed_parameter1_x4::SmoothingTime
		Smooth_p.connectT(1, smoothed_parameter17);   // Smooth -> smoothed_parameter17::SmoothingTime
		Smooth_p.connectT(2, smoothed_parameter);     // Smooth -> smoothed_parameter::SmoothingTime
		Smooth_p.connectT(3, smoothed_parameter15);   // Smooth -> smoothed_parameter15::SmoothingTime
		Smooth_p.connectT(4, smoothed_parameter16);   // Smooth -> smoothed_parameter16::SmoothingTime
		Smooth_p.connectT(5, smoothed_parameter19);   // Smooth -> smoothed_parameter19::SmoothingTime
		Smooth_p.connectT(6, smoothed_parameter20);   // Smooth -> smoothed_parameter20::SmoothingTime
		Smooth_p.connectT(7, smoothed_parameter21);   // Smooth -> smoothed_parameter21::SmoothingTime
		Smooth_p.connectT(8, smoothed_parameter22);   // Smooth -> smoothed_parameter22::SmoothingTime
		Smooth_p.connectT(9, smoothed_parameter23);   // Smooth -> smoothed_parameter23::SmoothingTime
		
		auto& SmoothType_p = this->getParameterT(1);
		SmoothType_p.connectT(0, input_toggle16); // SmoothType -> input_toggle16::Input
		SmoothType_p.connectT(1, input_toggle);   // SmoothType -> input_toggle::Input
		
		auto& in1_p = this->getParameterT(2);
		in1_p.connectT(0, smoothed_parameter1_x4); // in1 -> smoothed_parameter1_x4::Value
		in1_p.connectT(1, smoothed_parameter17);   // in1 -> smoothed_parameter17::Value
		
		auto& in2_p = this->getParameterT(3);
		in2_p.connectT(0, smoothed_parameter);   // in2 -> smoothed_parameter::Value
		in2_p.connectT(1, smoothed_parameter15); // in2 -> smoothed_parameter15::Value
		
		auto& in3_p = this->getParameterT(4);
		in3_p.connectT(0, smoothed_parameter1);  // in3 -> smoothed_parameter1::Value
		in3_p.connectT(1, smoothed_parameter16); // in3 -> smoothed_parameter16::Value
		
		auto& in4_p = this->getParameterT(5);
		in4_p.connectT(0, smoothed_parameter2);  // in4 -> smoothed_parameter2::Value
		in4_p.connectT(1, smoothed_parameter19); // in4 -> smoothed_parameter19::Value
		
		auto& in5_p = this->getParameterT(6);
		in5_p.connectT(0, smoothed_parameter3);  // in5 -> smoothed_parameter3::Value
		in5_p.connectT(1, smoothed_parameter20); // in5 -> smoothed_parameter20::Value
		
		auto& in6_p = this->getParameterT(7);
		in6_p.connectT(0, smoothed_parameter4);  // in6 -> smoothed_parameter4::Value
		in6_p.connectT(1, smoothed_parameter21); // in6 -> smoothed_parameter21::Value
		
		auto& in7_p = this->getParameterT(8);
		in7_p.connectT(0, smoothed_parameter5);  // in7 -> smoothed_parameter5::Value
		in7_p.connectT(1, smoothed_parameter22); // in7 -> smoothed_parameter22::Value
		
		auto& in8_p = this->getParameterT(9);
		in8_p.connectT(0, smoothed_parameter6);  // in8 -> smoothed_parameter6::Value
		in8_p.connectT(1, smoothed_parameter23); // in8 -> smoothed_parameter23::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		input_toggle16.getWrappedObject().getParameter().connectT(0, event_data_writer); // input_toggle16 -> event_data_writer::Value
		smoothed_parameter1_x4.getParameter().connectT(0, input_toggle16);               // smoothed_parameter1_x4 -> input_toggle16::Value1
		smoothed_parameter17.getParameter().connectT(0, input_toggle16);                 // smoothed_parameter17 -> input_toggle16::Value2
		input_toggle.getWrappedObject().getParameter().connectT(0, event_data_writer1);  // input_toggle -> event_data_writer1::Value
		smoothed_parameter.getParameter().connectT(0, input_toggle);                     // smoothed_parameter -> input_toggle::Value1
		smoothed_parameter15.getParameter().connectT(0, input_toggle);                   // smoothed_parameter15 -> input_toggle::Value2
		input_toggle1.getWrappedObject().getParameter().connectT(0, event_data_writer3); // input_toggle1 -> event_data_writer3::Value
		smoothed_parameter1.getParameter().connectT(0, input_toggle1);                   // smoothed_parameter1 -> input_toggle1::Input
		smoothed_parameter16.getParameter().connectT(0, input_toggle1);                  // smoothed_parameter16 -> input_toggle1::Value1
		input_toggle2.getWrappedObject().getParameter().connectT(0, event_data_writer4); // input_toggle2 -> event_data_writer4::Value
		smoothed_parameter2.getParameter().connectT(0, input_toggle2);                   // smoothed_parameter2 -> input_toggle2::Input
		smoothed_parameter19.getParameter().connectT(0, input_toggle2);                  // smoothed_parameter19 -> input_toggle2::Value1
		input_toggle3.getWrappedObject().getParameter().connectT(0, event_data_writer5); // input_toggle3 -> event_data_writer5::Value
		smoothed_parameter3.getParameter().connectT(0, input_toggle3);                   // smoothed_parameter3 -> input_toggle3::Input
		smoothed_parameter20.getParameter().connectT(0, input_toggle3);                  // smoothed_parameter20 -> input_toggle3::Value1
		input_toggle4.getWrappedObject().getParameter().connectT(0, event_data_writer6); // input_toggle4 -> event_data_writer6::Value
		smoothed_parameter4.getParameter().connectT(0, input_toggle4);                   // smoothed_parameter4 -> input_toggle4::Input
		smoothed_parameter21.getParameter().connectT(0, input_toggle4);                  // smoothed_parameter21 -> input_toggle4::Value1
		smoothed_parameter5.getParameter().connectT(0, input_toggle5);                   // smoothed_parameter5 -> input_toggle5::Input
		smoothed_parameter22.getParameter().connectT(0, input_toggle5);                  // smoothed_parameter22 -> input_toggle5::Value1
		smoothed_parameter6.getParameter().connectT(0, input_toggle6);                   // smoothed_parameter6 -> input_toggle6::Input
		smoothed_parameter23.getParameter().connectT(0, input_toggle6);                  // smoothed_parameter23 -> input_toggle6::Value1
		
		// Default Values --------------------------------------------------------------------------
		
		;                                            // smoothed_parameter1_x4::Value is automated
		;                                            // smoothed_parameter1_x4::SmoothingTime is automated
		smoothed_parameter1_x4.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter17::Value is automated
		;                                          // smoothed_parameter17::SmoothingTime is automated
		smoothed_parameter17.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle16::Input is automated
		; // input_toggle16::Value1 is automated
		; // input_toggle16::Value2 is automated
		
		event_data_writer.setParameterT(0, 8.); // routing::event_data_writer::SlotIndex
		;                                       // event_data_writer::Value is automated
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter15::Value is automated
		;                                          // smoothed_parameter15::SmoothingTime is automated
		smoothed_parameter15.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		event_data_writer1.setParameterT(0, 9.); // routing::event_data_writer::SlotIndex
		;                                        // event_data_writer1::Value is automated
		
		;                                           // smoothed_parameter1::Value is automated
		smoothed_parameter1.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter1.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter16::Value is automated
		;                                          // smoothed_parameter16::SmoothingTime is automated
		smoothed_parameter16.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                   // input_toggle1::Input is automated
		;                                   // input_toggle1::Value1 is automated
		input_toggle1.setParameterT(2, 0.); // control::input_toggle::Value2
		
		event_data_writer3.setParameterT(0, 10.); // routing::event_data_writer::SlotIndex
		;                                         // event_data_writer3::Value is automated
		
		;                                           // smoothed_parameter2::Value is automated
		smoothed_parameter2.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter2.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter19::Value is automated
		;                                          // smoothed_parameter19::SmoothingTime is automated
		smoothed_parameter19.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                   // input_toggle2::Input is automated
		;                                   // input_toggle2::Value1 is automated
		input_toggle2.setParameterT(2, 0.); // control::input_toggle::Value2
		
		event_data_writer4.setParameterT(0, 11.); // routing::event_data_writer::SlotIndex
		;                                         // event_data_writer4::Value is automated
		
		;                                           // smoothed_parameter3::Value is automated
		smoothed_parameter3.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter3.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter20::Value is automated
		;                                          // smoothed_parameter20::SmoothingTime is automated
		smoothed_parameter20.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                   // input_toggle3::Input is automated
		;                                   // input_toggle3::Value1 is automated
		input_toggle3.setParameterT(2, 0.); // control::input_toggle::Value2
		
		event_data_writer5.setParameterT(0, 12.); // routing::event_data_writer::SlotIndex
		;                                         // event_data_writer5::Value is automated
		
		;                                           // smoothed_parameter4::Value is automated
		smoothed_parameter4.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter4.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter21::Value is automated
		;                                          // smoothed_parameter21::SmoothingTime is automated
		smoothed_parameter21.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                   // input_toggle4::Input is automated
		;                                   // input_toggle4::Value1 is automated
		input_toggle4.setParameterT(2, 0.); // control::input_toggle::Value2
		
		event_data_writer6.setParameterT(0, 13.); // routing::event_data_writer::SlotIndex
		;                                         // event_data_writer6::Value is automated
		
		;                                           // smoothed_parameter5::Value is automated
		smoothed_parameter5.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter5.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter22::Value is automated
		;                                          // smoothed_parameter22::SmoothingTime is automated
		smoothed_parameter22.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                   // input_toggle5::Input is automated
		;                                   // input_toggle5::Value1 is automated
		input_toggle5.setParameterT(2, 0.); // control::input_toggle::Value2
		
		event_data_writer7.setParameterT(0, 14.); // routing::event_data_writer::SlotIndex
		event_data_writer7.setParameterT(1, 0.);  // routing::event_data_writer::Value
		
		;                                           // smoothed_parameter6::Value is automated
		smoothed_parameter6.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter6.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		;                                          // smoothed_parameter23::Value is automated
		;                                          // smoothed_parameter23::SmoothingTime is automated
		smoothed_parameter23.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		;                                   // input_toggle6::Input is automated
		;                                   // input_toggle6::Value1 is automated
		input_toggle6.setParameterT(2, 0.); // control::input_toggle::Value2
		
		event_data_writer8.setParameterT(0, 15.); // routing::event_data_writer::SlotIndex
		event_data_writer8.setParameterT(1, 0.);  // routing::event_data_writer::Value
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
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
using chain26 = wrap::node<chain26_impl::instance<NV>>;
}


