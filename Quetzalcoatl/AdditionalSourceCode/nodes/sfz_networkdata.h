namespace project
{

struct sfz_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "sfz";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "523.nT6K8CFkCz.D.XBFPgB7Raa.nhYs3B6T3AEzxQjTbwPhenzes3zPPTXC+Sj5v0yMKpv4Uko.BAfP.TD.OmRasRSrivlLcIrqxGiWvsipsmRyuh0bj3V+8W3b6jId.2JeHc5YrTLFT9izJEeOj9XTyFhHJytcSm.bqGymT0uHa5ZuADOpk8Tr6mO7IG1fc5k5nFHOBEwH31WGLWJeJbUuiYig7g0Nt8dq.bS7499LPwNzG6fOXo.3nSu5Y8rGcsSAWRHAGangH7Ctm+ddnrJndDx4guMML3Z.9fYfdIWvxCPEB7RyqWVnXA.osX1s9VryPBsX2tTPvRbKH9S1w4V5zEIZaBJL0N6qaZpvToBSDVtbIyjC6V4BkLUnfwRkppoIYnDAyPILouU++CqvzDAURnpsEr.TqkGXcHObBULKYuP8OOnEHR8E0D0HZsUGPAZTwJkYfZFfvBCib.j..TJU8.UmFlxMBIF7rq7eBAev.AHFEb1UxORrVOycMEfYRdW.6hd+fAFpVASoItWIjfY8.BfnV+QfSZvPjfe6ZWITJma8bsYCbcI.rwG5icVwoww8nXsPVTztTvQLvmHQ1MUMNwyj8Ciu+bgYvCFfAm3KBU.Nk2wpkPENysMQfUmzluOsmB274JqSMrMCD64KKNQODuwhWSyLb.02qZsfEQCZTDXCtM67.p5.78.b0.";
	}
};
}

