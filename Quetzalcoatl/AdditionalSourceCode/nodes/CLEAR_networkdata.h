namespace project
{

struct CLEAR_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "CLEAR";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "172.nT6K8ClD.TQA.HUBe7ATQwI.On6wQQ3fNXJ0l0oxKdEEYiBYqHfvLGYGok7A+5pP.6x0kpT44HQqiqsDH+gMGYos2lbAEWI0f2KGwNjedLI4UkR9GFBWHSGtqsPrUyt1FcOlhPdn31L0uHaWnjmedLYdcoK08ZvlctCCJZfPIHeBFI4ezO.hLSPCf.g4Y7w0bBqCXX.9HOLTzBbYRDzbYzxodG.Nu0LRtDYcyC";
	}
};
}

