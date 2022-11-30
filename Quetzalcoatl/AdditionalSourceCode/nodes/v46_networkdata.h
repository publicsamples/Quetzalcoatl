namespace project
{

struct v46_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v46";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLKha.aikoEYUeVnD9kEDvCjO8CgGZ5UiZPAgANqR6h1cJEj34H9WUf1Z7BxyQV.xEPIZfiR1hAcQGzbYh82Q3HyHaMtA88iHi.+pZdT1UOtQBc2O0PnqXQLw8wVhGYrnYiyyyySySiyhPyXk+bEqGP2W4wcf94fmR3wN72iMfCJKSR0MWRQS1tnYqonXISLHgNFxzJ1PG+PeZEPSHOyXRz+I9fEM6lKoZxVrEaYzD5NpX2HIvYgc0bAjhlJDcF9VJm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

