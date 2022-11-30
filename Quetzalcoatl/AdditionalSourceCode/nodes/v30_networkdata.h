namespace project
{

struct v30_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v30";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "300.nT6K8CVmATQB.HySvHBPqw81XYVSRfaJdgdpEBZySxxS9+Hp0HNNpAJbfLWhtSo.LOCw+JCzViWOdFxBPt3g4AFJYKFzAgPycI1eCgirT1Zb64aGQNA9U0bnrqdLiD5tepgPWwlHh6iMCdTRQSlFGGGmFmlB1DZFq7mqX4.59JOtCzuF7jBOtg+brAfHYWRpt4QIZxVEMaMEEyPjCRnieLshMzwOzmVAz7wyRQh9OwHnnY27HUS1hsX6hlP2QEaFIifF1UyEOIZtPzc36nvIf.DH5TLdP5.ysy0OXCDfd8KH3LkfuDvgy33mfRsg.Xixl1kJVfPuPdCfvfYI9TGPhcDwMffWgk0nfPBzTVBLCdnweL.zVG3LGRkD0raL14hgEQHWDaYCXX2MFaBy";
	}
};
}

