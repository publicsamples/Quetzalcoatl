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

namespace pan_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable_t_index = runtime_target::indexers::fix_hash<3433268>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable_t<NV>>, 
                                  math::add<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<3433269>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<3433270>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<3433271>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable3_t<NV>>, 
                                  math::add<NV>>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<3433272>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable4_t<NV>>, 
                                  math::add<NV>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<3433273>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable5_t<NV>>, 
                                  math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<3433274>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable6_t<NV>>, 
                                  math::add<NV>>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<3433275>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable7_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain1_t<NV>>, 
                                   chain2_t<NV>, 
                                   chain3_t<NV>, 
                                   chain4_t<NV>, 
                                   chain5_t<NV>, 
                                   chain6_t<NV>, 
                                   chain7_t<NV>, 
                                   chain8_t<NV>>;

DECLARE_PARAMETER_RANGE(peak1_modRange, 
                        -1., 
                        1.);

template <int NV>
using peak1_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                      0, 
                                      peak1_modRange>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, branch_t<NV>>, 
                                 peak1_t<NV>, 
                                 math::clear<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, chain_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

namespace pan_t_parameters
{
}

template <int NV>
using pan_t_ = container::chain<parameter::plain<pan_impl::branch_t<NV>, 0>, 
                                wrap::fix<2, modchain_t<NV>>, 
                                jdsp::jpanner<NV>, 
                                wrap::no_process<core::gain<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public pan_impl::pan_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(pan);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(16)
		{
			0x005B, 0x0000, 0x4900, 0x504E, 0x5455, 0x0000, 0x0000, 0x0000, 
            0xE000, 0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                      // pan_impl::modchain_t<NV>
		auto& chain = this->getT(0).getT(0);                                 // pan_impl::chain_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0);                        // pan_impl::branch_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(0);                // pan_impl::chain1_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(0).getT(0);  // pan_impl::global_cable_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(1);                // pan_impl::chain2_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(1).getT(0); // pan_impl::global_cable1_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(2);                // pan_impl::chain3_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(2).getT(0); // pan_impl::global_cable2_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(3);                // pan_impl::chain4_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(3).getT(0); // pan_impl::global_cable3_t<NV>
		auto& add3 = this->getT(0).getT(0).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(4);                // pan_impl::chain5_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(4).getT(0); // pan_impl::global_cable4_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(0).getT(4).getT(1);          // math::add<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(5);                // pan_impl::chain6_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(5).getT(0); // pan_impl::global_cable5_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(0).getT(5).getT(1);          // math::add<NV>
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(6);                // pan_impl::chain7_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(6).getT(0); // pan_impl::global_cable6_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(0).getT(6).getT(1);          // math::add<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(7);                // pan_impl::chain8_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(0).getT(7).getT(0); // pan_impl::global_cable7_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(0).getT(7).getT(1);          // math::add<NV>
		auto& peak1 = this->getT(0).getT(0).getT(1);                         // pan_impl::peak1_t<NV>
		auto& clear = this->getT(0).getT(0).getT(2);                         // math::clear<NV>
		auto& jpanner = this->getT(1);                                       // jdsp::jpanner<NV>
		auto& gain = this->getT(2);                                          // wrap::no_process<core::gain<NV>>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch); // INPUT -> branch::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable.getWrappedObject().getParameter().connectT(0, add);   // global_cable -> add::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add1); // global_cable1 -> add1::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2); // global_cable2 -> add2::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add3); // global_cable3 -> add3::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add4); // global_cable4 -> add4::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add5); // global_cable5 -> add5::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add6); // global_cable6 -> add6::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add7); // global_cable7 -> add7::Value
		peak1.getParameter().connectT(0, jpanner);                         // peak1 -> jpanner::Pan
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch::Index is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
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
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 4.); // jdsp::jpanner::Rule
		
		gain.setParameterT(0, -12.);  // core::gain::Gain
		gain.setParameterT(1, 0.);    // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // pan_impl::global_cable_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // pan_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // pan_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // pan_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // pan_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // pan_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // pan_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // pan_impl::global_cable7_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).setExternalData(b, index); // pan_impl::peak1_t<NV>
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
using pan = wrap::node<pan_impl::instance<NV>>;
}


