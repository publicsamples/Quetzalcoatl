namespace project
{

struct pp10_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pp10";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "315.nT6K8ClmAzXB.XAD0PBHMha.GXYpVVkOJJgVFLBpZNKZEABKfXp8WAfPHQJKah0cJEfJ.rB.r..zk1AzbxyPpD8WhWfQyt4OTMYK1hsNZBcGUrijrmooE.Mc.sn4CQGhuej2XIA59JOtDzOGXoFdrC9SxJPyx5jTcyernIaYzr0TT7TEERnimHshMzweQlA9U07nLYOailc0iijP28RMD5M1DUberm7HDFMWf.CCJfghCTrXSnYrxewyyT7uJAs030jmorAjNfdhfiR1hsKzE0n45D6uovQFR1Z7tZ1f9VR.k.BPfnSs8.oCLiNWevFHF81mPPYTB9W.FhwweBJeCEvFJxYjgXsB8Z4c3oCtkPLDCCtEB9JXk8so7EHGdni+b.noNvAGRkKJXmXryEKKhftH5xFzvtcNLNlA";
	}
};
}

