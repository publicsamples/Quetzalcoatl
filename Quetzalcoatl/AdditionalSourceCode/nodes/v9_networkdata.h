namespace project
{

struct v9_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v9";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "294.nT6K8ClPATNB.H5ywLBLKha.aikoMgDG6VC+xBB3Fxm9gvOfpv81pEFHcNwKtXMlRkKdlh+UFnsFul7LkE.HNYyo03ly2SQNAn6d9U07mbSvVKdfeR1hsKz8vnYr+lBG4nrqdbjWpgP+wpnh59XyfGiVzroAALZ3nwQCiUglwJ+4OVSP2W4wcfreRXIEdrD+MsAvnYR0MGBglrcQyVSQwLT4fD53IRqXCc7CcoU.Mm7bTkn+RLBKZ1MGR0jsXK1lPSn6nhcjrfFVFMg3fPyEhtCeCE.Hf.BQ.g4j2wBQJbLarBzaeAAkIIPAGN3NlUfsCANZY8ECaDxB830xc.1FbebGSkS64Jp.5unb+Ti8Nm7EkrwuyGWWM6rm4P73prdvglELEErn";
	}
};
}

