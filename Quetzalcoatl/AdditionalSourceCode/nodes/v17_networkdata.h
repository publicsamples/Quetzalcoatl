namespace project
{

struct v17_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v17";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLKha.aikoMgDGaTC+xBB3Fxm9gvOrs0v9GQDAGal5m3aYJz7rD+qLPaMdE4YIK.YimlGXnjsXPGDBMWlX+sDNxRYqwsmugD4D3WUygxt5wNRn69oFBcFahItO1L3QoEMYErvwwQgiBB1DZFq7myXAA59JOtCzuG7jBO9g+frAfPYYRpt4QJZx1EMaMEEyvjCRniiLshMzwOzmVAzLxyRSh9OwHrnY27HUS1hsXKilP2QEaG4hlF1UyFOJZtPzc36nm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

