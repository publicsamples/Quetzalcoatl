namespace project
{

struct pitchin1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pitchin1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "369.nT6K8CFuBzyB.XqT7LBHmx1.H.hWA6U20FojyTVDqajAQRaAiyFfAf.IiXQUUkKkAHC.x.fL.H8FTX02j7wtpyDVUBFkTWaURHMYUEAZ6ZWyGVMJgYXOHpGgTRS3EmXUFMHrZDLo178HqqRhEf5SdqHzhQnY.jg8lOqG6gzjTQZyDVc5kk8WaEnQ3SI4vdQ3OiRIVfUolOzFlblZIwBh3.Xz0aFosqwYCNqp2LJtBlmlENJV7rv3Zd.9P67IuCscMyq9jT8PhPGEV0vpanpls9zz6nluEmXZ5YV0sID6qjPbhq2LhMvngpzr3tCyhhyRS+3nn8hzdi68yh29jOfKf.F..xNpGXKWvcTFXbqzADlYjiNahTgyhY+eLWP8hzYKLZYUfHBlpFTOC7sQ8C6gXFBtrLIGGQwaEczfmr.xgC2ngOXUuEaZNTebvYvnQ3IasLXdwcXRoEVFg0.GsGDbnttyvAGMx.1D0xfKY4SvtST.";
	}
};
}

