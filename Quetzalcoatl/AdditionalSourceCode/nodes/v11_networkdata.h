namespace project
{

struct v11_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v11";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "292.nT6K8CVQATMB.H2CwLBLKha.aikoEYUeVsD9kEDvMjO8WgGx1ZX+iHhfiMS3S7nLEjKOGw+pBzViWPdNxBPiS13rz.+jrEC5dPn4lH1eGgibT1Zby46oHi.+pZ9S1UO1QBc2K0Pn2XULQcerk3wHEMYvvfggYAyBBVEZFq7m2XMAcekG2Ax98fkR3wO72zF.BMSpt4PGzjsJZ1ZJJVxDCRnigHshMzwOzkVAzDxyQSh9KwGnnY2bHUS1hsXaBMgtiJ1NxkkE1UyFmCZpPzY3anPHf..P..pX8XlHELlMPLzqeAAmYIveNrv4xriUAtgGvFkMMkJt.guPZCfzfYH9zDPhbDwFPfqv2ZnqjPZxRXdGW6OsBZqCbxg7gq1dAGVVzXrwhB";
	}
};
}

