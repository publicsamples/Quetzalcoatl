namespace project
{

struct x1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "x1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "186.nT6K8ClE.TXA.H1Rj7ATosJ.gTgYIIB29gbOzw2VOss0NQmB2LK7D+XoInzOSVwFWk+CBPF5YX16fpWFYDHRvPy5fxFhp+6bQXXGTQaPhiB7DKCQ.bIy5jB5UnidFKkKrwvescYkh7qsyWuPCneYtJMwdt1CN5YVmn5UIURgBP+qaxHivOPG8q1qWfMtVYQ6bE7CFjgdjCG8Ih8hImjB..yFzorZUyrefG.OYG.3ZENioAfkX2gZEAy.";
	}
};
}

