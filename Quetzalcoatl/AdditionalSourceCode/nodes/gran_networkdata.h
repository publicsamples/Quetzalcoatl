namespace project
{

struct gran_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "gran";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "421.nT6K8ClWBzMC.XBlNYB3xhd.I0KvaBKzl8v+.kKNc3v7sNIr4KO0JOaBqCy60URtX4p6THD.CAPQ..oZ.nwuNfFCeq0uxhfmQmiJW8mQ+NoUMBMliquIqRuU9k.Z7CoZZM94dtWKPimzns9YvSutQGowVv.Pi+ToebeMALeKrJpknOUwZjs9VLhZKZvGBeOVSvRRZnFCxCmXfZr8kwKzHDChViY+5V.4kWVTIbeMg5m4xqNuLpQWfBQXzpIfse.C0X1V+6a4UeCyOGnlPMoG.DOyiI8LlwLrG9GtGl5LyresC0jjjJMHQJ+HXPJwvfzjWj8kWVNmnq8u1XkJi7fUwMRQj8FaowqeAOUogoJTbfh5g2BLEJs.YUyGqiud4RoWzG7duodfoNBjz0oniHw7CoY9T4dxb4l1fmSJjHmq+xgetotcut6Vl.BX.HXP7F.ncXg.EttBvpiQ3AGQ.aIzILWDU9pL3ByV5NrrewpgtlErRgIdUhkyct8GLm7cOfWF+raC0l3bb0JbLUZZGEOCbgQ9akWXh.abcbB9mxM.z3tcNLXlA.";
	}
};
}

