namespace project
{

struct mod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "mod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "424.nT6K8CF5CTOC.XWD3HBLIaa.q8J2wjcyC7iPqPCPdPdtYffy.vmmQDUtdQ8UPqkos.PK.3B.VjddsawuykVBzzxyQx77WhMvflsxgnZ9jXOnoyWvWOIUdaWMc7nQSEd9kugD52Ud7ANe8LKp7HG8oeHv3DbVkU.GGMSXilPvW+ciebjKtEIYh0QSUCg7TFFYbTGY7D2JZ0LgJXMnIlV4dnZBeMEJQFYX1Db4fe1AllM07FYpTKRtModH0Nm2HjJfxV5Ec3luK5MNfF8osHxvlVOKFsH.HM3rGTJt4g4uAdt4ebwd.Zgkjo9kn.S.PAZ34FZffJ.fD.jLPI.fxb1MGMEPM3lCUl+wPGa7Va+EHhbA55vfKWpoXR.5.LNKUv0axyecwkgAXGLhDQp.o.M1tAKwLfKg.VqEW.PXoxQckj4Tr1sBnjTACmFGrkxqfI95J82N1C4Bymzd4ZmoacEjXJbYXSJAE6GSPLefABPvE.PmpUUbwl.AW3vfnxE5UytfwxDNT4Rdpg0JMLix2VbRyPf2wNWHfcfKFvw+EsStYugXa04ApIfeU.";
	}
};
}

