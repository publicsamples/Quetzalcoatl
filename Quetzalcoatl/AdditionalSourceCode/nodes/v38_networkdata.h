namespace project
{

struct v38_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v38";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "300.nT6K8CVmATQB.HySvHBPKt8loyrhruBKLR1Sgm22r7zOPtEVM6ton.9Jeu9YzVRFJddh+SGnsFqj77jEfjwihGXnboVPGDBM2lX+8DNxNxViaOeGIxJvuolCk8ziejP28QMD5K1DUbero3QGLZZfCiwXNLmB1DZFm7muPEA59IOtCzOHbzBOFh+hrAfXYaRot4MVzbsLZ1ZIIlREDRnikDohMzwOziVAzTxyNpD8OhSfQyt4MTMWpkZsMZBcmTrejLBZXWMY7rnICQ2guazIf.DH5TLdP5.ysy0OXCDfd8KH3LkfuDvgy33mfRsg.Xixl1kJVfPuPdCfvfYI9TGPhcDwMffWgk0nfPBzTVBLCdnweL.zVG3LGRkD0raL14hgEQHWDaYCXX2MFaBy";
	}
};
}

