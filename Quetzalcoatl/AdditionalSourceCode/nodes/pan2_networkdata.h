namespace project
{

struct pan2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "538.nT6K8ClaDTHD.XGlNQB7xhNtoaaSJ44r+HQZZx4ZfFgc2semP3ua.KxlHLx96SPJ.orP.LD.AAPlNvOVwRDQy15wnZW48yQ4UX48EVFUB8b7EXLE4CzFfl96vfMFYagnYky+MWcdelN92ygLx4qUhlQXY0jC32QrwDPD1WOLCDUpMQhgonJQRaAZBy92CwiF2Eyd3pP+zfqx3wZ7OMqA6FPDMSL.zlCiwpwv3qNOjti2T8.a2wQ+q1CzbSjCYKxb9XlCsEVIOWXVarFjMO3K65tKQzLcNytvN1bXHmIgs670F6.ZZYI1Zf7E7Ky5ujYOFizeWrpc+gHBK.nYG0UrwZK1BxHMtaS7eNTKAMHJSRUlll.0flHIZhInIMoJRTn.QIJJR5ggEAM6n4fJaMzZPSRMnVBPPBHAhlmFRflWlEe3nt5HUCaFbAZb4Jz.TMAg..BHR.E.fRcmGffP.qA8vOLJILupkXP+BKjZvjGpBsYOfFLbUlPbrE.rHFBrrM4pL1QiGbHP+Q9Fh.PrCFJ.QulArqB3EfoUFfmcgh2RwfevoaPxjg.vaXUkX7zGbmgWpqCE0y1MMxnCCXcT3oqmlb.HVqUKVmlFvXGnfcRM+SHbirXkD5VW1nZ1zxA4VbHGzzNsw1MwsDkfMn0wfHDf4SC.UxFGOTGgPYwE+dTX6DMg.NDxaicXyH51fWon8HE+0f6xQGnAoW.96.";
	}
};
}

