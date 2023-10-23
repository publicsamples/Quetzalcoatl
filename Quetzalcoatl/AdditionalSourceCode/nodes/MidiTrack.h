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

namespace MidiTrack_impl
{
// ====================| Node & Parameter type declarations |====================

template <int NV>
using midi_t = wrap::mod<parameter::plain<routing::public_mod, 0>, 
                         control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using MidiTrack_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, midi_t<NV>>, 
                                      routing::public_mod>;

// ========================| Root node initialiser class |========================

template <int NV> struct instance:  public MidiTrack_impl::MidiTrack_t_<NV>,
                                    public routing::public_mod_target
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(MidiTrack);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(2)
		{
			0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ------------------------------------------------------
		
		auto& midi = this->getT(0);       // MidiTrack_impl::midi_t<NV>
		auto& public_mod = this->getT(1); // routing::public_mod
		
		// Modulation Connections -----------------------------------------------
		
		midi.getParameter().connectT(0, public_mod); // midi -> public_mod::Value
		
		// Public Mod Connection ------------------------------------------------
		
		public_mod.connect(*this);
		
		// Default Values -------------------------------------------------------
		
		; // public_mod::Value is automated
		
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// =============================| Public Definition |=============================

namespace project
{
// polyphonic template declaration

template <int NV>
using MidiTrack = wrap::node<MidiTrack_impl::instance<NV>>;
}


