/** Autogenerated Main.cpp. */

#include <JuceHeader.h>
#include "includes.h"

// ================================| Project Factory |================================

namespace project
{

struct Factory: public scriptnode::dll::StaticLibraryHostFactory
{
	Factory()
	{
		TempoSyncer::initTempoData();
		// Node registrations -------------------------------------------------------
		
		registerDataNode<project::chorus_networkdata>();
		registerDataNode<project::filter_networkdata>();
		registerDataNode<project::filter2_networkdata>();
        registerDataNode<project::fm2_networkdata>();
		registerDataNode<project::FMIN_networkdata>();
		registerDataNode<project::FMIN2_networkdata>();
		registerDataNode<project::fmmof_networkdata>();
		registerDataNode<project::_networkdata>();
		registerDataNode<project::FMout_networkdata>();
		registerDataNode<project::FMOUT2_networkdata>();
        registerDataNode<project::mod_networkdata>();
		registerDataNode<project::mod2_networkdata>();
		registerDataNode<project::modulator_networkdata>();
		registerDataNode<project::v10_networkdata>();
		registerDataNode<project::v11_networkdata>();
		registerDataNode<project::v12_networkdata>();
		registerDataNode<project::v13_networkdata>();
		registerDataNode<project::v14_networkdata>();
		registerDataNode<project::v15_networkdata>();
		registerDataNode<project::v16_networkdata>();
		registerDataNode<project::v17_networkdata>();
		registerDataNode<project::v18_networkdata>();
		registerDataNode<project::v19_networkdata>();
		registerDataNode<project::v20_networkdata>();
		registerDataNode<project::v21_networkdata>();
		registerDataNode<project::v22_networkdata>();
		registerDataNode<project::v23_networkdata>();
		registerDataNode<project::v24_networkdata>();
		registerDataNode<project::v25_networkdata>();
		registerDataNode<project::v26_networkdata>();
		registerDataNode<project::v27_networkdata>();
		registerDataNode<project::v28_networkdata>();
		registerDataNode<project::v29_networkdata>();
		registerDataNode<project::v30_networkdata>();
		registerDataNode<project::v31_networkdata>();
		registerDataNode<project::v32_networkdata>();
		registerDataNode<project::v33_networkdata>();
		registerDataNode<project::v34_networkdata>();
		registerDataNode<project::v35_networkdata>();
		registerDataNode<project::v36_networkdata>();
		registerDataNode<project::v37_networkdata>();
		registerDataNode<project::v38_networkdata>();
		registerDataNode<project::v39_networkdata>();
		registerDataNode<project::v40_networkdata>();
		registerDataNode<project::v41_networkdata>();
		registerDataNode<project::v42_networkdata>();
		registerDataNode<project::v43_networkdata>();
		registerDataNode<project::v44_networkdata>();
		registerDataNode<project::v45_networkdata>();
		registerDataNode<project::v46_networkdata>();
		registerDataNode<project::v47_networkdata>();
		registerDataNode<project::v48_networkdata>();
		registerDataNode<project::v9_networkdata>();
		registerDataNode<project::vecb8_networkdata>();
		registerDataNode<project::vecb8_networkdata>();
		registerDataNode<project::vecb8_networkdata>();
		registerDataNode<project::vecb8_networkdata>();
		registerDataNode<project::vecb8_networkdata>();
		registerDataNode<project::vec1b_networkdata>();
		registerDataNode<project::vec2b_networkdata>();
		registerDataNode<project::vec3_networkdata>();
		registerDataNode<project::vec3b_networkdata>();
		registerDataNode<project::vec4_networkdata>();
		registerDataNode<project::vec5_networkdata>();
		registerDataNode<project::vec6_networkdata>();
		registerDataNode<project::vec7_networkdata>();
		registerDataNode<project::vec8_networkdata>();
		registerDataNode<project::vecb8_networkdata>();
		registerDataNode<project::_networkdata>();
		registerDataNode<project::vecb4_networkdata>();
		registerDataNode<project::vecb6_networkdata>();
		registerDataNode<project::vecb7_networkdata>();
		registerDataNode<project::vecb8_networkdata>();
		registerDataNode<project::vecfade_networkdata>();
		registerDataNode<project::vecfade2_networkdata>();
		registerDataNode<project::vecfade3_networkdata>();
		registerDataNode<project::vecfade4_networkdata>();
		registerDataNode<project::vecfade5_networkdata>();
		registerDataNode<project::vecfade6_networkdata>();
		registerDataNode<project::vec_out1_networkdata>();
		registerDataNode<project::vec_out2_networkdata>();
		
	}
};
}

scriptnode::dll::FactoryBase* hise::FrontendHostFactory::createStaticFactory()
{
	return new project::Factory();
}

