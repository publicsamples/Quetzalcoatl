namespace project
{

struct modtest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "modtest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "284.nT6K8CFeATIB.H+CxPBLMtI.3t16zqrkepID4IGN2XDNZtBMrqkcPAUAwkhhTACa5Gv+gaAJSyVUb5lVDr4fNfBhRsHXfZUoUer6pTAb5GH31BZCkp+ud8.shORDQc.Q86fXcEkYSpJVTf5HkuoCTZ.TvQ9lVUy2R7vVZqHZdF4O70wlwOdRloG26waZQvGbPrNpNNbQ1LVxWEf7NMDxPQI71huzjdcawwlqQIH+kHOI54hMLCLx2NNIY9MsoUYx2bK3qs7HriNNl1HuBMrHeDO2DwVRb.BTDRvX1G.MIg7mpcI3LGJ4ntIH3FiiGpm19bIviu0LHh1f2NNt3cCDpoLpqIpsFO.y+fRWZ6Ur6CND.s3qsvBwEhTjEQA";
	}
};
}

