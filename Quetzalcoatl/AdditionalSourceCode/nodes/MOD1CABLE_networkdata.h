namespace project
{

struct MOD1CABLE_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "MOD1CABLE";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "311.nT6K8ClTAzVB.XLz1PBDKiS.eUwtbDqbYejUXBQz.lZsihGP.7iaH...pH2h2gCGizeK.vB.s.fRP9LwsxFXGmVDRjmaMkLOyg4vzE4esyBxV9AIHIxjGHEjTAxCEgHeCv1gHS4DGLOW7pgZAmotrSLPsWZJL5.JxeKt0TPjmoIx2XKqUyFI+41LSNP9413qmtvRc0Zo+mVWo.jmunVK+0t3D+d8DkwlzEgrlFVIQ9GLCb7.RCHMbnLxCuZpN7m3V0wqHYqsNYhakF.TzghddXkNygo5yIoHut.xQtZgak2Zqp4aQQFCb+AHfPDPfHGOlIRgCyFHD89mffzTB7CGxXtL+XUzaH.1rHqICwZE90x6PDCt8PTzFljEF3JpQ6Wm7ER1304i0Uac1SbHk+pSZvgxDSLH5n.";
	}
};
}

