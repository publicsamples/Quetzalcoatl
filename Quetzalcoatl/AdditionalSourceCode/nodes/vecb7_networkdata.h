namespace project
{

struct vecb7_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vecb7";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "305.nT6K8CFRAzSB.XBzzLBDqSa.ehlbKFwqG7RqEl.wjHutwCHurQbW....grgHaxPxenB.q..K.zz1wPo.3yzZkNOtgTDPfeYLED+RsTKG2jdqk63BzxIUfWxyA7K7XF5kRLwQbDEFWqm3WNv2nKJjBQ5ENBSFPB7WZYLkC3WIB7rURR2z4f6ZZFH0acwh4oInQSLdxuCNYB76TjZ4Nt0PqywQxEcvV+1M7qBB7OfrVD.owiFEjKv+BbFspg6ICPFSUYZUSBfjmK4gQC5juTqLcsIIvmJdauZzmV4LllId1SGHf.BQ.QhZ7XlHENLafPzaeBBJSIvOcng4xriUotg.XyhblLDpUvqkrCOO3VCwvNLXVHfqf01uc4KjrwsymqqV0YO4PB0q9VAGJSXjYcjEOO.";
	}
};
}

