namespace project
{

struct v33_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v33";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLKha.aikoEYUeVnD9kEDvMjO8CgG1vfY+CJfgxMG1kn6TJj34H9WUf1Z7BxyQV.RFOIZfgR1hAcPGzbYh82Q3HKksF2d99QjQfeUMGJ6pG2Hgt6mZHzWrHl39XKwiRKZ1z3333z3zPvhPyXk+7EqGP2W4wcf94fmR3wN72iMfCJKSR0MORQS1tnYqonXISLHgNFxzJ1PG+PeZEPSHOKMI5+DevhlcyiTMYK1hsLZBcGUrajJTrvtZx3QQSEhNCeGEm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

