namespace project
{

struct v16_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v16";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "302.nT6K8CVmATRB.HyyvLBHMha.uxjS4PBGNbg8X.hTyYTkQFjXewXBBPBBfJPXrf9Sxz7rD+qPPaMdE4YIK.YimlHXnjsXPGTBMWlX+sDNxRYqwsmugD4E3WUygxt5wNRn69oFBcFqhItO1N3QoEMYGXfiiyBmEDrJzLV4OmwBBz8UdbGneO3IFd7C+AYCHgxxjTcyiTzjsKZ1ZJJ1gIIjPGGYZEanienOsBnYjmklD8ehUXQyt4QplrEawVFMgtiJ1NxBZdXWMa7nnYCQGhuiBbBH.AhNEiGjNvb6b8C1.AnW+BBNSI3KAb3LN9InTaH.1nrocohEHzKj2.HLXVhO0AjXGQbCH3UXYMJHj.Mkk.yfGZ7GC.s0ANygTIQM6FictXXQDxEwV1.F1ciwlvL";
	}
};
}

