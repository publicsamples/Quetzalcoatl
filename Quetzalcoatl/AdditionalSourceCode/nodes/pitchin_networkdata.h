namespace project
{

struct pitchin_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pitchin";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "306.nT6K8C1SATTB.XED0LB.Maa.Oqy3Z1k3vXtVr5VDMMJjb.0tE3RnpppHdDrAazvR+nB.q.PK.7jCfGp0Jadb+nLn.+xXJH9kZoVIC7NtI8VK20fd5llD.7RbRf+gGCQuTFQgw05I9kD7M5h93PjdgivjBr.+kVFSIA9Up.OakjTMaV3tlB8ndqqosiyh4oMnQSLdxOC76TjZ4Nt0OqywQxFavV+VM7qhB7HbfAqGOfjPAPxF3eSbDGvczZFtmT.YLUA0ZlL.INWhiiHzIeoVY5ZSVfOY71dynOsxYLMS7LmNf.BHDADHp0iYhT3X1.wPu.FDrlk.+6vE0kYNVkyFBfMKRaxPPsBeszNHkA2RHLxgMwBDeEuVdebvwIegjMdc9bc0hN6AGxXb0nI3PYhHEYeT";
	}
};
}

