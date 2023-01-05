namespace project
{

struct beef_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "beef";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "179.nT6K8CVP.zTA.Hhhf7AXEsJ.gPjllaaGqYRaGD9Zwd.Rt.ClBB1UGSa5MJ8C+wlqApG+G1abYV8JISaa371aDhfeLiR3vUgQDjWon7JKDtZdT7WasvR89Zq3iYZg7KwUxSyQ1hAJ+pvHYdURkT5Q9G2f8BvOnn7r1iWZdbbhC6bIt.6FfNH+hFn7CzrSbQRC..yDzPsizCDBU.7xVbYggVEPfgxX.fqu3nGLY.V4djyHXF.";
	}
};
}

