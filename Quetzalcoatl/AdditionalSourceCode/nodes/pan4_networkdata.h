namespace project
{

struct pan4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "471.nT6K8C1FDzlC.XwD.YB3tia.a5S4YxV+KpgmX.gkO9DrsPAXbFN21NLFSBVgkuleU8voTLC.1..M.n0YibPEYII8Hrmw2hMXUQylyH4OsZHbrp+9M6pRSLjUiOTS5eTpXmwOVESFFqRg7qX5adgiLBNkd1K4T4VfhhkIUSn3HqJ29q+hTnHbt8RFA+Zh1BzUOweEhIfavPTMFqi0azItwpOWKDgQvCvOjtdYBJlLNKZMLGgZbrLDNpzmNVK6LPOWz7eLMVxpuLSOjr8zWauWitc0elVdL9wtRXr.u3Cb.VlPU4pnTgAIGEEe.FzSGtfKfcx7YGF.WEmaxBkaxIwMaret0Pi2qYNCqkPAY6QUfFaJDMCPCPBHAAw.vH.PPLYcC.IkcLOXHYlI0pkgDR5xCpyARhjJyv5Lj8GREfNS+XDVoDfHkjFPlXEQm.MJt7aIq.Z6JABDZKS3G9.KYCn.yloVmGT4TkoHiZqYPkzJP.TKaZEEZCIgVINtKmMYMjh5hhLmq3a+.fo5omfiPyitLxFkuCHmESHyZBi4fLCYP2umUtAKDYwZyXlX4g4NPwJD4ATdF5IWG35GaYGiiwECdKrcRyE9X3cVPykQx5vunCpAsyAnT.e0";
	}
};
}

