namespace project
{

struct filetest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "filetest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "388.nT6K8Cl4AT8B.Xp0IUB.SNOy5e.WTiL.Jcl2Tn2SZhY786lxKSWC0lUU0q12u2ehzl2o9.fO.7C.2IspQfwXttkqJ8V4SdX7CoUXL10bMWG.imzns9Yvu9gwUwIEi0kjZgCUJifu1+9x3G8.LlhKdXblJky8qDv6glJ3GCMDi67v4EPL19x3DZDtIBFiY+5Tz4kVZnSz9ZBb8uboUGEv1GRq..ic8Cigu05VWRvyniopU+YzCT4db4RKsAt1Kj3Eq+dgcsntattaFCwX1V+6qwqtEtiS42H8LlQJ765ZmL.h8Gwxo7RKM9EHffiMzPjdAF7gvvSb9LW3myMEQ4jnnbMH4fCsnVAZ75XzDHQ0RlhnldO7ZROD0EbUM+Mf70IWJEi9.myE0BD0RfdW2hVxi4GRojYHf.HHZNG.HlThNX.kfiA5YIzzhYYkY4q5qxzElkzMrb+hsgtlEjRgI8p5zm6f1OWNQydXVp23p7CYFtDEbfULWChcADi6XNV1ZEYqOA61lA";
	}
};
}

