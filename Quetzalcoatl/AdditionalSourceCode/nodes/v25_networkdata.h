namespace project
{

struct v25_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v25";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLKha.aikoEYUeVnD9kEDvMjO8CgGx40lsZgARmS7rKQ2oTn34H9Wcf1Z7BxyQV.RFOJdfgR1hAcPHzbYh82Q3HKksF2d99QjUfeUMGJ6pG2Hgt6mZHzWrIl39XKwiRKZZ.ywwwowogfMglwJ+4KVOftuxi6.8yAOsvic3uGa.HTVljpadjhlrcQyVSQwRlfPBcLjoUrgN9g9zJflPdVZRz+INgEM6lGoZxVrEaYzD5NpX2HKnogc0jwihlLDcG9NJm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

