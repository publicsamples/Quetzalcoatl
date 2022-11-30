namespace project
{

struct v20_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v20";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "299.nT6K8CVmAzPB.HyCvHBLKha.aikoMgDG6VC+xBB3Fxm9gvCagZTCJHLvYUZWztSoIdFh+UDnsFud7LjEfjgShF3mjsXP2yAM2kX+MDNxQYqwMmumh7A7qp4OYW83FIzcuTCg9hEQD2GaE7XjhlJXMMMMLMLJVDZFq7muXMAcekG2A5mCVBgG6veSa.GR1kjpaNThlrUQyVSQwJDofD53GRqXCc7CcoU.Me7bTjn+RrAJZ1MGR0jsXK1tnIzcTwtQxXVXWMY3jnYBQmgugdBH.AhNEiGjNvb6b8C1.AnW+BBNSI3KAb3LN9InTaH.1nrocohEHzKj2.HLXVhO0AjXGQbCH3UXYMJHj.Mkk.yfGZ7GC.s0ANygTIQM6FictXXQDxEwV1.F1ciwlvL";
	}
};
}

