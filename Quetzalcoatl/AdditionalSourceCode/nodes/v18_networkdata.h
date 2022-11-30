namespace project
{

struct v18_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v18";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLKha.aikoEYUeVnD9kEDvMjO8CgeX8Qw0qfBhJVFzOw2xTz7bD+qNPaMdA44HK.IimlGXnjsXPGDBMWlX+cDNxRYqwsmueDYE3WUygxt5wMRn69oFB8EahItO1R7nzhlMFTfiiiBGEDrIzLV4Oew5Az8UdbGneN3oEdrC+8XC.gxxjTcyiTzjsKZ1ZJJVxDDRnigLshMzwOzmVAzDxyRSh9OwIrnY27HUS1hsXKilP2QE6FoSSC6pIiGEMYH5N7cTm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

