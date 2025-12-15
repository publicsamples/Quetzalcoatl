namespace project
{

struct menv_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "menv";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "312.nT6K8CVcATWB.XATzLBDKaa.+tNyp4VvG1RZIAf31OzgvbjehwTH...JLmhFVDGoenB.p.vJ.33mb.7YZsxlG2O5AIvuLlBheoVpUp.uiaRu0xWvsQI.3k3b.uBOlgdoDvQTXbsdheIAegtnOI.oWXHLo.I9Kc.2HkxWIB7rURR0rwf6ZZlG0acMsifBMw3I+K31LwuSPpk63V+rNGGIWrAa8a0vuJHv+.xiFNfz3QCG4B7uIF5YzZD2SEfHiopLsFkAHw4RbXzfN4K0x0lj.ep3s8FoOsxYLk4zKlmFj.B.BAPFiGfbRgYhYFN.g0fE3geHRj.e5PT0k4OVkyFd.aT1zTp3BD9BoM.RClQ7oX.yhQDa.AtR3a+FLewkranSxVWkc1o9Bm4PZ8pabvQyVD1F+h04vXDE";
	}
};
}

