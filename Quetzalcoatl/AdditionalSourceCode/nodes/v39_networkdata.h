namespace project
{

struct v39_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v39";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "302.nT6K8CVmATRB.HyyvLBHMha.uxjS4PBGNbg8X.hTyYTkQFjTa4MpAX.AnJH1bv+RYr3YI9Wgf1Z7JxyRV.xFOKhfgR1hAcPIzbYh82R3HKksF2d9FRjWfeUMGJ6pG6Hgt6mZHzYrJl39X6fGkVzzfFGGGmFmlBVEZFq7myXAA59JOtCzuG7DCO9g+frAjPYYRpt4QJZx1EMaMEE6vjDRniiLshMzwOzmVAzLxyRSh9OwJrnY27HUS1hsXKilP2QEaG4AD7vtZ13QQyFhNDeGEbBH.AhNEiGjNvb6b8C1.AnW+BBNSI3KAb3LN9InTaH.1nrocohEHzKj2.HLXVhO0AjXGQbCH3UXYMJHj.Mkk.yfGZ7GC.s0ANygTIQM6FictXXQDxEwV1.F1ciwlvL";
	}
};
}

