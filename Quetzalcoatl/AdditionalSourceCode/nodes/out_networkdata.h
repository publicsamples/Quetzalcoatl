namespace project
{

struct out_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "out";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "286.nT6K8CVEATJB.XBjzPBHsZS.GfDKnYy6TqlHkAS3hfUyDL.nUmQxuB.ICDJS2zHszOPJ.nB.s.v4mdRleoVpkpH+qaQPlxYnM4YsWCcYx0NPzNWBOJ0plGRjl7O.aHh7jrNztJZ.Ix+H9omvjeoM4e3nn8xjB+0VHlBxu1FeMSEHOTbclfcjsKzjA75VjwuW+.RDl7SYKB4KMzgIeiBbXfCDbbPCBzE4gRsqenp7ZQoFpC7mGG0fK7kZkJn3ZQW.W1wtpXoXDwJ4K0R0WSRh7PNxVV357GaGCJ.4YI2R4gA.nM4goXn2NKLzyk48SpDEG9rxNddB1LX+u6XlkyatbKv3p68T1Jl7tM1dCtBX3NvnFHdgS0TgAV4VbaKXF.";
	}
};
}

