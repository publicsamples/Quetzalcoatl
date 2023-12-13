namespace project
{

struct fff_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "fff";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "426.nT6K8CVHBTPC.XaFSYB7Pad.0uJPr6ZPOPSZmyAccmlJUGEqymJwpsFB7XfEsk6ePmVVlZD.GA.R.XcrrH3Yz8X4p+L52I0pQnwdtdlrJ8Z4Udz3GRwzZ7y8buVfFOoQa8yfk5GM1JNodvxjzLgnRIDbmNc5twTr7nwepzP2GSvEHKJknOVwZjs9VLhZKZvGBeNWSvRQZHMliGNs.ow1WFqPiPPPzZL6WmBGuD6hJg6qIv0OykXadYrSW.aeHEC.M90OZL7sAzc2XHMls0+9Wd0yv7SREUEUO.G9kGjzyXFuva3gbOLsYlY+5lpIoHSbHhT9QvfTZgAIpWj8kXWtlnq8u1XkJi3.phajhH6c9wTTRldTRMLox8ZEnwqeQSvzDGllzfjppGdKvbl07AowWqbozK5Cdu2TOvTG.DoqSQGfDyOjd4ikyIykYZCdNoNhZv9qF94l518Bg.Bb.HXPMKYxSbrFRGKv006AO3PBXSgNENQKlyJYKmAe5LLLdTKAUdMTWEN4bGs+.4je1CJkwe1sgpSbVtZEOlJl1AiG.WdbZi..icKtsAMC";
	}
};
}

