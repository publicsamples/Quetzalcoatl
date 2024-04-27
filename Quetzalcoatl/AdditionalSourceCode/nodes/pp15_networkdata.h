namespace project
{

struct pp15_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pp15";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "315.nT6K8ClmAzXB.XAD0LBHMha.GXYpVVkOJJg8X.hzv1ZNBBf8a+MpCPPBnJXiUR6OIuB.q..K..coc.Mm77iJQ+kXFXzratCUS1hsXqilP2QEaHYzyzzBflKXrn4CQGhucDfqXIA59JOtDzuHrjCONh+jrBzrrNIU2bGKZxVFMaMEEOUYgD53IRqXCc7GQtA9U07FYF8rMZ1UOFRBc2K0PnqXSTw8wdxiOXz7.HVTAH.k.jAaBMiU9KvyyT7uRAs030jmorAjKX7DA2HYK1tPWiFMWmX+MENxOxVi2UyFiukDk.BPfnSs8.oCLiNWevFHF81mPPYTB9W.FhwweBJeCEvFJxYjgXsB8Z4c3oCtkPLDCCtEB9JXk8so7EHGdni+b.noNvAGRkKJXmXryEKKhftH5xFzvtcNLNlA";
	}
};
}

