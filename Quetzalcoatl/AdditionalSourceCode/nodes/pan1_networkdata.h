namespace project
{

struct pan1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "471.nT6K8C1FDzlC.XwD.YB3tia.a5S4YxV+KpgmX.gkO9DrsPAHICK6+NLFSBVgkuleU8voTLC.1..M.n0YibPEYII8Hrmw2hMXUQylyH4OsZHbrp+9M6pRSLjUiOTS5eTWry3GqhICiUoP9UL8McgiLBNkd1K4P4VnZhEpJTUbjUka+0eQJTDN2dIifeMQaA5pm3uBwDvMXHpFi0w5M5D2X0mqEDgQvCvOjtdYBJlLNKZMLGgZbrLDNpzmNVK6LPOWz7eLMVxpuLSOjr8zWauWitc0elVdL9wtRXr.u3Cb.Vnpp3pLgBCRtpJ9.LnmNbAW.6j4yNL.NJN2jkJ2jSha1X+bqgFuWybFVKgBx1SUfFaJDMCPCPBHAAw.vH.PPLYcC.IkcLOXHYlI0pkgDR5xCpyARhjJyv5Lj8GREfNS+XDVoDfHkjFPlXEQm.MJt7aIq.Z6JABDZKS3G9.KYCn.yloVmGT4TkoHiZqYPkzJP.TKaZEEZCIgVINtKmMYMjh5hhLmq3a+.fo5omfiPyitLxFkuCHmESHyZBi4fLCYP2umUtAKDYwZyXlX4g4NPwJD4ATdF5IWG35GaYGiiwECdKrcRyE9X3cVPykQx5vunCpAsyAnT.e0";
	}
};
}

