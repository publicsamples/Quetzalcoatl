namespace project
{

struct v48_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v48";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLqZa.alNSCCEElWDZTzC3.lMr..CZpmZqVXfz4.NcRr6TJj34I9OUf1ZrRxySV.RFOIZfgxkZAcPGzbah82S3H6HaMt87cjHi.+lZNT1SO9QBc2G0PnuXQTw8wlhGcvnIANLFiofovYQnYbxe9BUDn6m73NP+fvQI7XH9KxFvgksIk5l2XQy0xnYqkjXJULHgNVRjJ1PG+POZEPSIO6nRz+H9.FM6l2P0boVp01nIzcRw9QxbVXWMY7rnoBQmguaDm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

