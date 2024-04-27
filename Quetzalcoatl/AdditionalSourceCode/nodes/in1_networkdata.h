namespace project
{

struct in1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "in1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "252.nT6K8Clh.T4A.HwCvPBHMhS.ixVafh75VnjUN..VTa2tIX.PqZLtpEPn.BIvHiZIoev2ErEyDMHmsX6FePTnWxSNhlr87OaXCK.5YJXKxi8a53Xra33gh9p2TxRs7QQOCCZNnIgFDXTvFfdIUC6FKIw2jpkKAmk3wNV5.r8PCkrBn3SLT6nnmsK5g3oolT0BO9ZQtkjiu1L1tc.8Qy1SkrmtFCK5Yn1Q0yVrEaWnO1uIIG4L6hd2K1QRUv9YRCgJbl3aW8NdrnGBYOYxNIA.WAYfmbfMCl.5cLyx4MWtEXb08dJaESFLON9DF.d3NPRkQCC21zvESTZwssfY";
	}
};
}

