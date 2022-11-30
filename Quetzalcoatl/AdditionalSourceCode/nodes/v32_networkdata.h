namespace project
{

struct v32_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v32";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "300.nT6K8CVmATQB.HySvHBPqw81XYVSRfa1NgZg.BayYoZCp9Lk1oGGi4qL5uKQ2oT.JdFh+UFnsFud7LjEfjgihG3mjsXP2CBM2kX+MDNxQYqwMmumhbB7qp4OYW83FIzcuTCg9hMQD2GaF7XjhlLLMMMMLMLErIzLV4OewZB59JOtCzOGrjBO1g+l1.PjrKIU2bnDMYqhlslhhYHxAIzwOjVwF53G5Rq.Z934nHQ+kXDTzraNjpIawVrcQSn6nhcijgfF1USFNIZtPzc3anvIf.DH5TLdP5.ysy0OXCDfd8KH3LkfuDvgy33mfRsg.Xixl1kJVfPuPdCfvfYI9TGPhcDwMffWgk0nfPBzTVBLCdnweL.zVG3LGRkD0raL14hgEQHWDaYCXX2MFaBy";
	}
};
}

