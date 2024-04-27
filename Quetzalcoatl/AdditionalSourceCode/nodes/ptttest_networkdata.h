namespace project
{

struct ptttest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "ptttest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "281.nT6K8ClGAzGB.H2yvLBHqZa.GoSTzgPV4Qy1RBlrf1ZGOCFHKCln.DhjfUnCqoZxe7GHOP9CwC4zLoVuv8DBYhkZwCZjuTqLarHHvi3+WHkHvuSQJk2XV6rsF+HUjg0tUhcSZv6ngAMNvACGLJHUf2MwQ7CkkFqmXWRv2nJpSCQZENxRJve6CKoA+hma68h5zIXXHF9JA.+y9dpTlDdioPNJ21XZ2Xmb.7PsNIiiaGcAD32GVBheoVpUl.eiYO2R48a6tkx.vq.jF7N3XL8JIvAHP.QHTwpCvrwdUDJqSLNbChNXisgvGgxiqLLHKWfpiMVC1Bui4kSCmKQYHOXFEPVBYv3N9CAfq5.GbH2cUwvhzamqkGoHCMC";
	}
};
}

