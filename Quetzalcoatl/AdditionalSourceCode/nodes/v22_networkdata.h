namespace project
{

struct v22_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v22";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "300.nT6K8CVmATQB.HySvHBPqw81XYVSRfa1NgZg.BayYoZCp9hE2oGGi4qL5uKQ2oT.JdFh+UFnsFud7LjEfjgihG3mjsXP2CBM2kX+MDNxQYqwMmumhbB7qp4OYW83FIzcuTCg9hMQD2GaF7XjhlEvZZZZXZXHXSnYrxe9h0Dz8UdbGneNXIEdrC+MsAfHYWRpt4PIZxVEMaMEEyPjCRnieHshMzwOzkVAz7wyQQh9KwHnnY2bHUS1hsX6hlP2QE6FICSC6pICmDMWH5N7MTvIf.DH5TLdP5.ysy0OXCDfd8KH3LkfuDvgy33mfRsg.Xixl1kJVfPuPdCfvfYI9TGPhcDwMffWgk0nfPBzTVBLCdnweL.zVG3LGRkD0raL14hgEQHWDaYCXX2MFaBy";
	}
};
}

