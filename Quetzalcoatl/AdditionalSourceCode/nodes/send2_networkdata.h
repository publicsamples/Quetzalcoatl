namespace project
{

struct send2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "send2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "435.nT6K8C1gDzTC.XmT7PBDqaa.cfdIx1pXfPEu0BfTQGFHfwggGH+spppyQIaaa2bQmcZL.HC.w.vd.S4L4oq2mMdRBl1TtEFSgZ.cm76KZz1bPmS754Se72yAUhB1xcASkPIAS679mYaICvcbAXYK78r8vOOoRHbLcunbYjPml+xf4gkSyRf1HZCPkHXZCpVJ43EDkSC5animPukEWQWl1UO9BzUgAsA5lU92O35V+QJrJXpUSAoH+VilJHW7KJcRXLU4IKwpeQOdDn9CPddteskgA5tPUIn6lsFB8HWt42Q+mZvQDCOjdH43q7mGAALONi+1rEnP6z3LTcOYEHpSfFYsBM.LzPj9X.l..LkY6LnShBiQVdN74NP+t5hy.HDrMmNRAYY7lKrDmH+jq0Z30DxQtiXa3t5PLosAkAhSCxBHRVlHZfN0HxVIrwflhbC4uhhjnW237ZO6kdxziUMHMoHZifyAf37ozvQRAyfg7VEi4.sUMyQmiE6..DhZ+gz37m3NW.Af9r3mvWCdYjf8vzywczndBxA5miKhYWwWCfCVVwFwJVzA4lcd.sChTCjM.zqB";
	}
};
}

