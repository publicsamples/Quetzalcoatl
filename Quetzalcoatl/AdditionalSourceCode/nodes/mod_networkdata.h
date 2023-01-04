namespace project
{

struct mod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "mod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "429.nT6K8Cl5CzQC.XYj3HBLIaa.q8J2wjcyC7iPqPCPdPdtYffev9yuTPUVtU8KpYRYt.fK.7B.oEomW6V76boc.Ms7bjLO+kXCLnYqbHplOJVDZ57E70SRk21USGOZzTgme4aHA3Mzuq73Cb95YVT4QN5S+PfwI3rJa.NNZlvFMgfu96F+3HWbKRREqilpFB4oLLxd.CG0QFOwshVMSHBVCZhoUtGplvWSgRjQFlMAWN3mcfoYSMuQlJ0hjaSpGRsyEjPYK8hNby2E8FCPi9z1DYXSqmEi1DGRCNKBkhadX9Sfma9GWrHfVXIYpeIE.E.TfFdsgHHnB.HA.ICPB.PYN6L.HMERMNtCUVQjrMrRBx57uXHxZoqCCpbwlwr.1A.4fTiuWgkwUBOaVvtcDoQtfoDMztJK6b.HgHVqoWAHXoxQckzbJoVt.vDRICmFGrkx6.Pb1PtvcLhkoaBE1LOKMSKVPpYcmAspGPsejBe.gET.VRtFpfyTppXWrxRTEtFDUqPub1EPV1vQkK4oFVqzvLJeawYNCAdG6zhL6frZ.E+W2h3zdC5FqyCTS.+p";
	}
};
}

