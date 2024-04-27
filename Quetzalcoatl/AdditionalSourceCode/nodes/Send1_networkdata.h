namespace project
{

struct Send1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "Send1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "448.nT6K8C1iDTaC.Xzj+TBDKca.7NRryssZ1CLQpETmG45n1i.DRmFIMA..30z++mLJ8HkBy.PM.LC.w20Nf2O0tJa9UWaIAut0mg4MRJ9O5z0rSM2K9ejYvu5gGBYXmrhdCsE7V4RBdAM+GpdlgdJQ9bf1kM.ZbioW8P8rqVJDNpOnj1Xj.H2C4rIB1qSifUZpEvRQvqjkSosLax9wEM83qqQywxcKMAlvZLaiW+B1ZhOLbjm3qd8S2gm674jBME7h4VwKzo2oy0jrFJouJLuaW6JXNTVTnY6PWigAaawF+W04w3SI6Umt7mUH30ADoFRjPEgxw75gOEDrhNcCr47POJdPsvioGTPJXA4BNAZj8Jy.vPAhzQw.fI..SclNC5jHeXz.MGUpEhXOHvL.zCJtiGwAhc9MlKORxNcEVKu2vNh+ArFZ8s.2xJQAB0kA3.GKWLRZ38kBaLnKK2P9UbUI48A.v0jIdL7uY50x.pA0qsEXdfBvmZCDshlYLh15LmAvV47GcLrXE.3QT8GJFfdlKoBO.xoi6DcM7BRR1f82G2RCkokCDdNbR3aKeFXGrhBMhEVzk49cdfpChTCjM.zqB.";
	}
};
}

