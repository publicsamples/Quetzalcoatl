namespace project
{

struct v41_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v41";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "302.nT6K8CVmATRB.HyyvLBLKha.aikoMgDGaTC+xBB3Fxm9gvOrYTXhfAFTXTA6G8aYJz7rD+qLPaMdE4YIK.YimlGXnjsXPGDBMWlX+sDNxRYqwsmugD4D3WUygxt5wNRn69oFBcFahItO1L3QoEMKf.GGGGENJVrIzLV4OmwBBz8UdbGneO3IEd7C+AYC.gxxjTcyiTzjsKZ1ZJJlgIGjPGGYZEanienOsBnYjmklD8ehQXQyt4QplrEawVFMgtiJ1NxlEMrqlMdTzbgn6v2QAbBH.AhNEiGjNvb6b8C1.AnW+BBNSI3KAb3LN9InTaH.1nrocohEHzKj2.HLXVhO0AjXGQbCH3UXYMJHj.Mkk.yfGZ7GC.s0ANygTIQM6FictXXQDxEwV1.F1ciwlvL";
	}
};
}

