namespace project
{

struct v13_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v13";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "300.nT6K8CVmATQB.HySvHBPKt8loyrhruBKLR1Sgm22r7zOPtEZMXR6Y3bhNq9YzVRFNOOw+oCzViURddxBPx3w4AFJWpEzAgPysI1eOgirir031y2QhrB7ap4PYO83GIzceTCg9hMQE2GaJdzAilLlALFSASQAaBMiS9yWnh.c+jG2A5GDNZgGCweQ1.PrrMoT27FKZtVFMasjDSoBBIzwRhTwF53G5Qq.ZJ4YGUh9GwIvnY27FplK0Rs1FMgtSJ1ORBbZXWMY7rnICQ2guazIf.DH5TLdP5.ysy0OXCDfd8KH3LkfuDvgy33mfRsg.Xixl1kJVfPuPdCfvfYI9TGPhcDwMffWgk0nfPBzTVBLCdnweL.zVG3LGRkD0raL14hgEQHWDaYCXX2MFaBy";
	}
};
}

