namespace project
{

struct v21_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v21";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "300.nT6K8CVmATQB.HySvHBPqw81XYVSRfaJdgdpEBZySxxS9+lE2IsmgyIFXuKQ2oT.LOCw+JCzViWOdFxBPt3g4AFJYKFzAgPycI1eCgirT1Zb64aGQNA9U0bnrqdLiD5tepgPWwlHh6iMCdTRQyBXNNNNMNMDrIzLV4OWwxAz8UdbGneM3IEdbC+4XC.QxtjTcyiRzjsJZ1ZJJlgHGjPG+XZEanienOsBn4imkhD8ehQPQyt4QplrEaw1EMgtiJ1LRllF1UyEOIZtPzc36nvIf.DH5TLdP5.ysy0OXCDfd8KH3LkfuDvgy33mfRsg.Xixl1kJVfPuPdCfvfYI9TGPhcDwMffWgk0nfPBzTVBLCdnweL.zVG3LGRkD0raL14hgEQHWDaYCXX2MFaBy";
	}
};
}

