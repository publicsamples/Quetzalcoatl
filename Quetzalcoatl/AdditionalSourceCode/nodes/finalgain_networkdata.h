namespace project
{

struct finalgain_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "finalgain";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "352.nT6K8ClbBTqB.XZT5TBDsha.+pgPYH8HyJk8HRPfw+A8rYX+n+1zRk...foR4B0EhPJCu.vK.HC.yGjhGXUqoKQhHbR4Mvq9UPoc0l0rlCX0GzIi+D84bJV7mCBtwpL.QwpUhvLyWJfEexyEoY0EqtK6iM3F.T4WAkTrZSF+4e4QWRFn0ze4RZyKVs5kR+hDJXQwh+y4AL8K3DSBNnQsi1yiGHnFxww4gc.SvpY9JSZCgVqidZcqfIbSW94DyQ3Qzl0cy.lwpOl.ZEjJHp7AcSp+8fKr6pyW9OvBnZyZGtQo7bVSH7Zp0PQOOhhbzs1Q2MlAyZ0Gp.BX.Hfr65vrKHQdGvSRPbkr.YG5iGvmhSXpY.l6pcGL3GqFLXdZPhOBNDn3xInDZP.ORm.YjgUL1OxGD.9nICa7wCnAX.1iB3rIOhJNyY5qY1VrLAbCxEneXVrL7qtTCTFTNXDsGd.9L.";
	}
};
}

