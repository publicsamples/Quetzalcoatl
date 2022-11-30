namespace project
{

struct pin_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pin";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "325.nT6K8ClpAzcB.XLT2LBHKaa.+tNi9Yu9gfE1J4LIsQ96f.ubJC6uB.tBb3DBD0LoLrB.u.PK.33G5rU.Mu7rjMQ+YLBOZ1MOhp4RsTqEglP2IE6IIzoYWMc7vQSLQmguiDvjG2A5WElQ4wU7mkCNDjXX9qBEFEnnAmBa.oT27HNZt1GMasjDqYyAIzwWXpXCCL0bHYBsvdPyd5wSRn6dVCgdiMwF2GaMdTxilQPQKXDoHRwhMglwI+4MTVftO.8bF+mLPaMVc44LK.oiGPMvPxkZsKzA4flKhX+cFNxRxVi2Uy1iusD4D3W.l.BTfnC03AoCL2NW+fMPH5sOAAkoD7KAPYFGyIn7MD.aVjyNCgZEx0R6vSFbSgXnMLHKDjqfM1WHkuH4vQO9iAf16.GxgrLK9LvbawRkGab8sqZDVXtEMFarn.";
	}
};
}

