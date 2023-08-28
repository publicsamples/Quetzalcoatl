namespace project
{

struct fausttest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "fausttest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "446.nT6K8C1fBTZC.Xi1TcB.uhd.6UFIsxVnc+waTfT3U9pfPghXxlcgucQx90cynja.iGiNoTvQ.bD.KA.iceZ5ToW3igml+K5CcemazLJxeNeXUdYTKiVgi7FMCiSJlVGIUCGpTRgcPNHm6n4IMZq+D7092qc6YgOPyVv7z7lJky8eHLw7zr8kQFnwqMJcy769rfwK0xnU.ng95Ab867jZTfAue8ZcBZvV.Za8ue1q9zvghYwNuQyWu09z5r.OiOLHT8mw2cRgdAc.QKs+ZwNnH2gbt6M6MyrTjHTRSt.X7x7ax2DyXF9hGGH5jlgPj6gaJ5gCNbYgHrf.i1sLP1.iUH15ak.hmPe8WWeEYW3nG9SyX7WALCmcr1.oxJ9.xJdyKt.LiAuQMtCoHO.onGtimJ2zjaJJRB0DG0TEEMdeP7YwHplTo.kDmjHUSjl3lh.4bCZlyuQhh4+9ZvCnYKXxHTBHPYDUps21jA.xkgFPAdHNqbHoaeIuXcIT6QuwzqCdErtgb7rxsrzLN3dvvjsX0i2PwO.bxm1CrL5+FTlGTfOv4d0N3XdQm0P4Qf682dT3ZRg6d.ycvg8hJT8vKJ.";
	}
};
}

