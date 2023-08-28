namespace project
{

struct qqq_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "qqq";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "126.nT6K8CRjsN..xgvFa.WZazAhxtCoQHAxke616ofLfhDppZgXVDJ8C7eWuucg1pw+c6Aq.fOkG7GqyoJMEdioHKTuMl9Z7JEfG4oFMM+V5gC98fUH9DJgRY.7Ml45MwGjG7KViQTZRXCFNIgvWVVxDuADG7JZl4spA.f31VHJ";
	}
};
}

