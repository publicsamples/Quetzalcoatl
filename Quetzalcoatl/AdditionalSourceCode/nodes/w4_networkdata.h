namespace project
{

struct w4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "w4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "330.nT6K8CVrATfB.XYD4PBHqhS.mTwlZVjOIFQ1AhzoTvSck3+AYbKE.fjCvlwA4nVR5GfK.7B.v.PGm1DXxyrFRl2owowQSj+0sJHG4OJS9o1qonb4ZoJsys3JpnHx6HhIuCvtRjgDVMTKfcMrSL31FZmDc.DKZhWwrFxRdGkIOiqpVJWL9qsTSMP9013qmTBxSEWoKX.qe7qfQbAEf7rkai7W2hS760MbDsj+pEgLkFJwjGB54w.DfN.RgJPdnU65FMRdsXvSbmzQqEIisMTwchFvcD87v93NMNp9ZOPjWS.4HOYgqzYrU07rnHKAtJrNqTBH.AhNEqGjNvL4b8AafXn2+BBRyRveB.wYb7SPo1P.rQQV6LDqUnWKuCQXvsDhhbXRVXHWAcs2SaEKCdXi+H.zRG3.GR0E0raL14hcEQ.WDYYCVX2gZEBy";
	}
};
}

