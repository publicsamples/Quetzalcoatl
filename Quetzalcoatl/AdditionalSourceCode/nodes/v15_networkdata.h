namespace project
{

struct v15_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v15";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "302.nT6K8CVmATRB.HyyvLBHMha.uxjS4PBGNbg8X.hTyYTkQFj30AwUs.BH.QBvrDcmR07rD+qPPaMdE4YIK.YimlHXnjsXPGTBMWlX+sDNxRYqwsmugD4E3WUygxt5wNRn69oFBcFqhItO1N3QoEMOvw.GGmENKHXUnYrxeNiEDn6q73NP+dvSL73G9CxFPBkkIo5lGonIaWzr0TTrCSRHgNNxzJ1PG+PeZEPyHOKMI5+DqvhlcyiTMYK1hsLZBcGUrcjEz7vtZ13QQyFhNDeGEbBH.AhNEiGjNvb6b8C1.AnW+BBNSI3KAb3LN9InTaH.1nrocohEHzKj2.HLXVhO0AjXGQbCH3UXYMJHj.Mkk.yfGZ7GC.s0ANygTIQM6FictXXQDxEwV1.F1ciwlvL";
	}
};
}

