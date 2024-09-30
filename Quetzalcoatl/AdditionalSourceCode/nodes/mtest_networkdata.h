namespace project
{

struct mtest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "mtest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "569.nT6K8CFEGzWD.XGECUBHIca.LnIWUmBY2iSJjg.9CXIlSujG2ptbC.HQZqsd0OeKssSA2.vM.jC.bc9UtCZKmJSkQ+ZEOAf11w2RqsP2g1V4ymyUl7o.8R4iU5MeGi1Y1JVWsbHZqDJGZaG5Cp1VBbsvPbEORNyzqzZRwH6bvDztRYpMZqt7BygPgGcqE9oSf1h3a4FXwhZsEaYewFCiuxfrbpjn8zibylGiKQ7qrqKJRQFIyqz95oTRxmZPa40.JfxsDhfKTGmTvnsFMdfjwtDtxRB0xKqORTSpoD.6vcvzDLFYFPGOGOEXzPZ5kfSgj+LorvFP3yAC3Ct38dSe7Z0iF7KWc8hym7dzyiNULEsit7xJYfw31sCf.BZzoLTQX1ffdn.P.PL0M2FjCVi1bOyFYBAmZpkN.tFo4yfDPazNtRjSKv39RCEOHSA9tO.HPMgj8oD8Ax3Mo.hkuhsOfXloHnnyCWKvw4LEK5mRPT8kdpRSCMtSMvLfn+G.pHMnCTv4.l2.a.bNTJVNvXvZhvRW7oNee3PIS4.EvaV7ZWlA+aB5ccgtVKlYrgBChmD6aQV7+BXDPtZtNtgFQK.1F99pZjk.3U9aoi7NMGoiM.f5fkcs3950sAFLmeQy5YlRtcFXAbMAqlG2njyzTBFQmsfB7F.o.00qKHqZXFlCtY3mnWREcvmBtf3UBGerIDJOL.jSpGUZLh4TrIEh.Ft9IX5nyPNQF6PmNf+b+EakNHGntBflgwnf4d.";
	}
};
}

