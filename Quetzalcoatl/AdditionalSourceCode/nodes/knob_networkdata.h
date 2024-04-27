namespace project
{

struct knob_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "knob";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "112.nT6K8Che8L..xb3EZ.XpMvHIhE19MtrKCwzSmg.YzJygqiMtaoe.+u4rkIPFQ9emqMYbGYNtuxtQEKCtxvD0gSkgMcUFA2SZHxBuMEV33dt1zcGcPGjIvccYMmGNhUUL.tSvfwcEdWzxTD..NGFgn.";
	}
};
}

