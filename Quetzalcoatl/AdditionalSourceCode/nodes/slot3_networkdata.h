namespace project
{

struct slot3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "slot3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "320.nT6K8CFXATaB.XXD3LBHqhS.uTwlZVjOIFQ1g.LlVZq8SjJxv2oPAHDIAqpgbfEk90B.s.vK.zwnMgk7Lqgj4WnK4iZuVpRkqgbnctFewrXVutMA4HufX6lTE4cdVx2.rcHxP1PkfyNIaDCtUR6lnBjH+mXVCAQ9ktjmwSSakJD9qsRQLP9013qizAxKEWnJXPw5GWAUQdlxsQ9qawH98ZGNOHxWksHjqzPnk7LVMqCZZZXXfFPdHU6ZGLSdsHU.eQbozQpFIisLRwkhBfyycdV7v93Klkpu1iD4UEPNxTV3BcFaUMO6IxSf6BqKg.B..A.oh4gYhTvwrABQu.JHXMk.+zgIlKyOVk3FNfMTj1mgXsBcszcPxA2PHL1gM2BDdEGlIu1r2qJ3tiq3OB.szANvgDhq9dAGVlXnaNFYUbB";
	}
};
}

