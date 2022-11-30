namespace project
{

struct v28_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v28";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLKha.aikoMgDGaTC+xBB3Axm9gvO7TtQMnfv.mUocQ6NkBn3YI9OYf1ZrJxyRV.RFNJdfexkZAcOHzbYh82R3H2HaMt47MjHm.+lZ9S1SO1QBc2G0PnuXSLw8wlAO1XQyBVLFi0vZHXSnYbxe9BEDn6m73NP+dvQJ73G9CxF.BkkIk5lCon4ZWzr0RRLCSNHgNNRjJ1PG+POZEPyHO2XRz+HFgEM6lCoZtTK0ZYzD5NoX6HYMMrqlLbTzbgn6v2PAm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

