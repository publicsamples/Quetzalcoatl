namespace project
{

struct modswitcher_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "modswitcher";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "310.nT6K8CVuCTVB.HWSrLBHMha.8UNQAE53f4P9RBLToEaM2OK3TJnCI.Pdad.iN7GYJnfZEXQievaPnTpBRXfbBVjW+QTR7irknwRbrGqleCwPtISEBa.ZJ0NNGQXOYhDMlXFC+LiT2dPNCKM7.GX3K0KAJ4yZu3pHi.nICmNF42Ti7Ys.aGiemu1EZ97byDz+E2fhlsiCQ0bgwpPSmyhvVRp1Ey4Ouol2D4s1BIreVOKJ53PqAZx3PQyHfdz2PBCHfI.DxxxCPfAzCkS5WTSfvHvwtEJd0.54jrjDIpzsKFhHlPDK2w3N+H3c.PO.J1.3BCf6nh1rE.7.7nRfix3I.fRymgA3KB7HfBgsM.bRRNDE.rL4IVYAvvXPGmyaH3B.1kqGBTu3kMBmV7nvi0MAH5.fc.d5A.";
	}
};
}

