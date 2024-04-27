namespace project
{

struct pan_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "362.nT6K8CVtATvB.X5D+TBHKiJ.2DTVTjHmNPQHcO..HSaCaqjI6T7eKU..vVPJI63waT5Gy..M.TC.OSbo5.6X0tvSd1poj4ifhfhTF4ecCCxVtj9jup85LWcbMEm14f72doZdISO4e.1bhLk.Z.4gYsqi.g40hYMTG3r6xV4fauzNLZCE4OFa0TRjORexawXX6UGE9qsYpff7qswWWoBjA.42auzn.j2ZJxXfaCqKypm7K81KcQdNysV9qawJ985HRlRjuS1hP9pgTO4cHUvCCRvABNdD2kwftHhVkKNV4.8WJta5XFDIBzEIRnKLKMZCISWYDAIAwN4QPQp9ZSTj+ukRUHG4MKbodbBHv.D.PjdGsfC3Nhn+G1AtuvXJLtrLVuLDxX0zUNL7fSTj8wLSmj..VDQLWl8XsYvH0cLVN2mqvBH9Bt1RUaWzFfTCL3UPW681Vw4c7a+4JnkcfibHe5psWvglEhaazn.";
	}
};
}

