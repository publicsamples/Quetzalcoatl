namespace project
{

struct snextext_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "snextext";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "227.nT6K8CVg.zrA.HGCn.BTIR2xVJ.IaK9OfxZB..vYxzRFHTE2My3hyCq6FHlRA75S1YSiFQIlRFjuJs9rcYW3cEYvCmro00xN3tyUlBIBp7SEIkA8vJtHVx3VKbOYJTALseqPb2b.QzlfVBCbtATeRlKQc.uk5dBMk3Za5vAo01leicTEfmiOalZ9cxED3oKlAwKAIAIQA.dMd8VYbuj9RZyUBfmxBC38n4EdkIfEf.lQvbrdfICsiuEJ9NFU.Cfje1U5Jegb.0ALHNPjOH3hQfSlKTOPGOn0JxhyvBS3QPZoKFE";
	}
};
}

