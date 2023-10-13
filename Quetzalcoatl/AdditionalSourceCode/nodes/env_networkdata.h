namespace project
{

struct env_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "env";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "532.nT6K8ClPETED.X9UMYB.wha.D.srzzj+6wmi1geenD+5Ca5vINTFHUZtz+utH9Eb7Mb1oDD..AfQ.30Zek8vZUIg5RX+xYEmPas9VSFc9UcDAzV+MyzZqDHFRakSXk5YrNtBJmVWYwoFOyXzxxgzYtsXnHf1xgN87dl.d7py7xtLj885GEU4D9UtTNu79FZigU0C8PsaDiE6L1J0euSSaMcvxvGj0fO0ulTMBHwulQGgkVeVMCYq.zVnW7uEdfIQSjhnL4bXx0vTCU73bnV2jyAUghagNfTW9SAAA43HeZKVVBs3Qair7yeOWiNPrNF3O9SVo9Faf8PVGupPL82X9Dv5lOlkVSRGl.+aI3GK02rAR+BXo04fhcYJRRhhzjHWkHGXEVu1dzuPB6uhQwQ1rtxwvPdw4D7ic8JLvwr.6xopCXEnQzSYTfBJJfAfEjCH..ggTFY.qQR0DKLE.IS19hVSp.4XNRsqxxuCHQRN.GRVRxsB6NcmRCfGWS.934xy5Iim+rxfw3HoSDDhWjznakdwZ5xrOSPbvjARIreXTqkhHGf9MPkpTqvn.BabXrEySh88JIY2LaC33zAev.y.9s.NJuvyZ5S1PEeDNCYaWPDXvPWPSSvPoYCfkItS5vrrcokD1AzgLLIoGYmFu3fNkraVVsK.Fllzs1HjBeJrEi4gB1LwSc.io19lXi2cApx.z8.tp.";
	}
};
}

