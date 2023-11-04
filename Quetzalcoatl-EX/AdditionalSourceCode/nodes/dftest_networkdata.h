namespace project
{

struct dftest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "dftest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "333.nT6K8CVrAzgB.XlT7TB.saa.8RPipVz3jZRZiUg9glR4GGHg3gYWW+++N+u03dHeWIY.v.PL..C.yodBzpd6qrqxVrEiYrJ7cxnmQiXnUmbveCU06sHw+dQzozmZZbiUk3.zpbhuDSuRe7GUmmgkGMPidU+ndveNMr.pzaeE.VkwPq1boropVPgtdyzJ5PWOg+DWvpalskp3G7rvCvVQS3vP4SLJaIw7hwLuphUUYzmdmN1VzOs640YfNJe7FT5O2j207DYWU6YKInpJe2ruvAHAAAIHNR3wCEXGnNbvLplftmH73j4+WXBXLlD2PhWnHZ1MvKhT0aOENSMDUcPHf.G.BFTyBCzvVX5p3fGbHArkPmvbQT8qxzElEoCXQ+hMCcMKHkBS7pMHm6X6mOmn4dfR0YZeNlMoaGDJdLULsCFO.tB4THAfGaco2AzL";
	}
};
}

