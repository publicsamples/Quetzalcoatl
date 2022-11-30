namespace project
{

struct ffh_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "ffh";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "251.nT6K8Cl8.z3A.HXiqLBHswM.3PQRYY86.8P.NA.An1vbQ8PnYdhBPHJHWSxPBiwzO7qPP5BYiE.+RqiaH.IwRJPErGQ66wWJCbjLnPU9R4HSGSIwmz6agzVY92FDNk0MjAfeknoP95vJIiI1q2HtYTMtK3a6Aswg0wslbfKsN7xB7qLAuyJIoQSGbGSeZT85X5ywMIA3edJyTyuFUgD7qCuf3WpkZkMv6XlTuP9SjHYhOAFVfOhlm3sKAnAHPQDYR9P9jArb0RzAXAAVLzgmnaGN6CCQrjrx.HTqFym4IWotS2CuyjuXNzYfwbFLIRKb48oMA.l6twXSaF.";
	}
};
}

