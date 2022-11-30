namespace project
{

struct v44_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v44";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "300.nT6K8CVmATQB.HySvHBLKha.aikoMgDGaTC+xBB3Fxm9gvCalvTSJHLvYUZWztSoLOCw+JBzViWOdFxBPt3goAFJYKFzAcPycI1eCgirT1Zb64aGQ9.9U0bnrqdLiD5tepgPWwhHh6isBdTRQSlFGGGmDNIZVDZFq7mqX4.59JOtCzuF7DBOtg+brAbHYWRpt4QIZxVEMaMEEqPjBRnieLshMzwOzmVAz7wyRQh9OwFnnY27HUS1hsX6hlP2QEaFYSyB6p4hmDMSH5L7cTvIf.DH5TLdP5.ysy0OXCDfd8KH3LkfuDvgy33mfRsg.Xixl1kJVfPuPdCfvfYI9TGPhcDwMffWgk0nfPBzTVBLCdnweL.zVG3LGRkD0raL14hgEQHWDaYCXX2MFaBy";
	}
};
}

