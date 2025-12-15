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
		return "386.nT6K8CluBT7B.X7j+TBDoia.mRYuCwmyCH6Pf.C2c44NdSySp19K9...na9ZoSU5IRx.z.PM.XC.XVNsOBeynzhEXUr4iRGM4z5k.u5eIo1UaW6ZVwpQIbS6qnQ36RlWDZgYrZDIGVEiljy7oxvah1tt8F7hU+MYdUhvIJVEwp65dMFbB.zs+RRcXUeS6me1S6QgiDq5ydTZyHV8521dZ5bPNmKXlYyyxG45muL4biAJnSMjGAIRRpkdddhbN3AVkyioR8Gt2SQd6tlIX0uAXkleVos6w4DA5kjKI5VTBmVeLJQX2U+seANfl410O5kHDaJkYUdKMEAYZBp8Fp614ELmP0GMd2mfjbGct.BTBffQ4Pe.YufpO6.wRDjfYVf7Q8oAPcjghSD.laBvywfb215fA8XSgrx7SnCPdChXI4AzHiaFufRJHbrMKunDCxJi3+pNRrNSahW1qfLZzTG+7iVFmGAKNSa5aY11sLAbC3EndXVrLbWcoDnLRNXFZO7.0Y.";
	}
};
}

