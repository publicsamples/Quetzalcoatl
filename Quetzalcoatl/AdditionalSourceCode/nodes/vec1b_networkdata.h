namespace project
{

struct vec1b_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec1b";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "298.nT6K8CVRATPB.H9ixLBHqiI.OZ+rxThyWHQJoL.Tn47eFJ.X4Rs+K..gTqRDJhN4C7V0vcjAYqopLspIAfjmK4gQC5juTKnaRh7IEwsWMZTq7VSaO8hIpInunFO4GBDNoT9M5oVNjcMagPNRZQmz0wcCGqfHuiFNdP.jFEz3QZQ9XD+3HmgBCz0QbLMv22EkovSuvOLo.Rj+PaiobH+JgHeagfzMcN3PmlgohKzoMjYIAxmo0JchbyTDPjeaLkL+RsTKH6fhqkegAa4jTjWxyg7KDYF5kRPHf..P.PpXdXlHAbWafPzqeBBNSIvOc3g4x7iUItgCXCkM8kJVfPWHcCfbvLDepCHwNh3FPvqDF1uc4KjrwsyOVasbXOvgDhq9dAGVlvHy5HqRd.";
	}
};
}

