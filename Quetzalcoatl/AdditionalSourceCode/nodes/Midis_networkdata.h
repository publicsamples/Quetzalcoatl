namespace project
{

struct Midis_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "Midis";
	}
	bool isModNode() const override
	{
		return true;
	}
	String getNetworkData() const override
	{
		return "373.nT6K8CFzAz0B.XPUAMBLoha.n8TNlrsOkHj0RenjQCWNdA.Og0qgBg587dY.A8mjAbC.1.fM.Dc+zVflShrz06iSLiEMa12P0rgogow8N70ORmcQyI28SptZujBeqkHgNyiVDZ9.snYBuWgX2HflsUiejLHHjaK1.z7ARQyKO95p+IYfo8OBblSsGTRmEfD1rughlM6hlrFB4pKEoy4ISLu14b.G4mE5VE0uHWDuN1T7ikR1Sgvj2fXUsCnICZpcteQrk7XGt2ibyh8QYdE8ou0OVAZ1GsGxbUhSjo9nUhGHmE3nrgoYWmGYPSkQhyiV+aMHRDKEWbqB5OuN1bFNi2YVIRXhkdMyaGjYB6FD1wpYFjBHvHDPYYOjN.Fmq1Gl2zFBvFrHKoLHhuztg.kPfx1PklLvvj.Qo.jENeATn88UwGMKz93Xv1NL9HsXrB8o4H8szgtGlAOLbJgfWChqayHKhumWBaKv6H3iPfSaM2UtHIq0d.";
	}
};
}

