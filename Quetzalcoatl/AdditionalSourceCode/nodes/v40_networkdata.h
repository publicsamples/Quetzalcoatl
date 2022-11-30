namespace project
{

struct v40_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v40";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLqZa.alNSCCEElWDZTzC3HLa3bPO.JVXqVXfz4.NcRr6TJj34I9OUf1ZrRxySV.xFNIZfexkZAcOGzbah82S3H6HaMt47cjHi.+lZ9S1SO9QBc2G0PnyXQTw8wlhGcvnIi.FiwTvTrXQnYbxeNCUDn6m73NP+fvQI7XH9KxFvgksIk5lCsn4ZYzr0RRLkJFjPGKIREanienGsBnojmcTI5eDe.ilcygTMWpkZsMZBcmTrejqEKrqlMbVzTgnyv2PAm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

