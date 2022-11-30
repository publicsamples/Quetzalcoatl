namespace project
{

struct syncmod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "syncmod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "113.nT6K8CBgEM..hc7EY.XpMvHIhEF9FWtFDSOcFBjQqLGJz15tk9w+aNYYBjQj+2oZQF2Oki6praTQav0EljLbpKjoapH3dBCQZ7xRXgi6oZQ28i4XNE.20c0bd3pMQRacIvcBFLtif2ErDEP..DoHGhB";
	}
};
}

