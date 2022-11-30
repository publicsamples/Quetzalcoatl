namespace project
{

struct v26_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v26";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLKha.aikoMgDGaTC+xBB3Axm9gvCq4pQMnfv.mUocQ6NkBn3YI9OYf1ZrJxyRV.RFNJdfexkZAcOHzbYh82R3H2HaMt47MjHm.+lZ9S1SO1QBc2G0PnuXSLw8wlAO1XQS1hwXrFVCAaBMiS9yWnf.c+jG2A52CNRgG+veP1.PnrLoT2bHEMW6hlsVRhYXxAIzwQhTwF53G5Qq.ZF44FSh9GwHrnY2bHUykZoVKilP2IEaGYAMMrqlLbTzbgn6v2PAm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

