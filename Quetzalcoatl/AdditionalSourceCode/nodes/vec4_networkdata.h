namespace project
{

struct vec4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "338.nT6K8CFtATjB.Xij5LBHqha.eiQoNgNOiNxV5NaIly6mKSPkNpaH.IH1LNopfB5OICC.v.PL.7yVq.ypt6crq1vZXMLhUi+qR5OTGlY01K9SStfuTkGBUnOMmBCvpLhXVkA4WY5NBDoaPfcjGJgI3vhA5y8nf7QN.sxcuikUaXlUcdUUO4JAM95oFS5wWOieiKX0oYKcIqOT3Cq5Vv9gF+2r4w3ufQzxpWuozm7RIlUgbfdP.JAThGdfUkVO7WvjDeSqWxG33vfyro9okh04Z1zroXATFQNMzMzFVCywWiCqxHj9zoZYKoNWy7ptnoKQ1KzPK22PCXBH.I3ob7.jNv7yUKGrABQu9IHnLkfeHfEy3XNAksgBXCE47YHVqvuVdGdXvMNDD4vfrP.thaL2SaESFLRiCI.1RG.EGB1kpYxXmjVAwYfwcSG5J.zb2ibFPy.";
	}
};
}

