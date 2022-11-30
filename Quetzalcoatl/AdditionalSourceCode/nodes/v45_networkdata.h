namespace project
{

struct v45_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v45";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLKha.aikoEYUeVnD9kEDvCjO8CgGFyNLQv.CJLpf8i9sLEz7bD+qJPaMdA44HK.4BnlF3njsXPWzAMWlX+cDNxLxViaPe+HxHvuplGkc0iajP28SMD5JVDSberk3QFKZ137777j3IgyhPyXk+bEqGP2W4wcf94fmR3wN72iMfCJKSR0MWRQS1tnYqonXISLHgNFxzJ1PG+PeZEPSHOyXRz+I9fEM6lKoZxVrEaYzD5NpX2HIvYgc0bAjhlJDcF9VJm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

