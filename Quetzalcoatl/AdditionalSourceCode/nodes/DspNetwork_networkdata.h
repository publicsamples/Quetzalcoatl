namespace project
{

struct DspNetwork_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "DspNetwork";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "130.nT6K8CxmMO..xgzFa.WZazAJ4VHTgUHSjS2NOkoAzkPUUWAHADJ8C7+l0mtH473+shrK.3UnCdDs6bowvcsLgkX00xmaYnA3Sd4QCuOVd3fWQ1EhWkTIEJ.d21ZVSbBnCdVysIKMJ6AypnTXszFHA3MPbvqfWlmtBH..NhgYj4NYB.";
	}
};
}

