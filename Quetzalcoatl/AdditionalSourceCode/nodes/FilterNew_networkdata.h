namespace project
{

struct FilterNew_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "FilterNew";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "2954.nT6K8CF06U.W.n4Rf4.KvxLaF7w75JCStzBb1N24DsTtbEezsu1eUTTTxo28mc1ApjDZ65vyLvuhcG.3.rM.VCflIVaLF03Me.YAdW4iLmPHsporENCmRnpsFik0NTQU8wgHcpjlFW2MZLUkUFEES3qqrkMti9l4JWsuVfnxWnnjv8FEde+j2fjnExBqZaA5hS4ivgz7HeG2KfrtYbUcQgHIqrtg6GL2a1eWYgk4ShdfJ+wo7Hp0xTHpEqD0vetVjowa7mq9hAGYOXZNegnFENK6hEJAsqpqmIIM9p5tuxSt.hZd1WLBoy6o6B7nFlJaQTTSx4QhZW4pLMNi16KD0lptxdvBYkwfirkkDMNvVnwaqpE3LD0lfhEhZZnybrwVDDfWiotb5vm39H++R4Soy4+j+C.mioIjlxZgz3qVeQuRTSCJaks7bfP+HvvJU9d36k++RojzO.8QMfGgCGPIHzsZhmDVOUsuaLtjc1By7cHtBuDoNWUaPYsi.Ml5h0Zt6Kkl8EdCr+.DBAFZwtgEB2ze.Da0oSdqYCB6pxAvbFYYVYfDCHfvBGIoK1PZBcYDElhRAsOB+QTVl69NQGXKrOYKsVGXpKJdT4OZrtaxVc7FJvVyCnKex4z9le7mDkxsEnKG7DtCMEfwEr0l6kBbFZVrLgJLX3MF36xooPeNnr9SaUx5D.JqzZD9dSYzYsu2DHKPJ6.V2oLxnPylnCZZ.9ZNkeCj4rJsZrSIloYylSNye.qB+wqAVq0gXbNkRGbtn0VqP1Y3LTV4NWUZmhk00m79VKzzEFjDvZNaj4NjZsFiQHLJkwXrVgTJkdAT5AcWURM5grJUonSICCL5LrViFSWLJaLGNkMNC6.uR605bU4YmyedG0FqVKz8NnKAh0A+XMRoN568hRRm.QMNvZfo8y+c1369GbNIPhhXf9RZL3p51QAOS6JNvzZ5K9ppBWRq8TXcFcRFjUjTn00.G307kQoQgy.c8foLBeu6mXqzYk2SgR9NaLzpzIqMTkuYrBtCEskGX4bERleDsDRdVXG7Yfv7XBOA7Aku37qymNo1+0XKALyohc1CF70EO3uQ0D0L1GbFOxLiDRHbweDcZny.svY3tbFmzXXfAtu.jBeXAd+FPpTomcbAMzsTWOZ6RL5Y+3OqVoYDtAbc0afNNiCmKdHsmvQHqwhwA7H9nN3i2CBe6y5d1m.u2ye7oJSqQMI9pxWMNoTCXcVpzWiLqub5fzuReZbBCLnanJ8NODMx.f.P..PP.HdFD.LTfRXfPL7.hhCEJC.HBJBFCFB.B.I.PALD....D....JCSYEoJi1DSmVhw6Te1rUG7OFTu.zHv.gNT5FOaWkk6psVLrUpeaPHeMxHAEiHOahw3Cbsnk0x0dg7JBwza9wu8OUmUmPcr171.ZCWyQy81tyIYujYTkg2pSqpMp4FoIfSEgqVI5mlFxpnneyeduIxSo4YeRXcfRCcchp9Obj3dBdlGTM4f5kkcZL1v3dzNOMM3MwVHOAEMnHESXYO1PJ8IGlNgoijWGczYed3UD3kY10SpHWA8OHEXuHhli7RFjcl+5XQM5ze6ur147zLVABylttR8cgqQFsMUCZV3kIh0scL1cv.SeHbuBP8lJj3tpnhKpCUXSKaNm9Wsf0EkWPL5S.Ku2sdQmwLJCCaNRjUyU8gEvlWiK.wZL9y3NiJAgjUThSHcCQg0Hcpvt5LfyVHhR02rQGCfvP8WYLEDvBpWf5I64zyn4ctquTPeDrpPvz2zmFWXIMLg6h7ri.4gKkifGWXEoz0zULTQpwCjivPEDf0GYiihkVzc3zvTAci8OgChe3XqFteQsf.R5GLlvsspY9g+lXGJPFu1vXg9fiCc2bzPBK3oe68.PJQ+doF.QyenZdpfNyMBy71bEyGYgQhaF1tZdRWki73hTNjvsdCjnGh+ImyRYM73YBAHaXRNUsfTPS7fzElND0nGE70RyAAbWr81..nyvji2dH05ms6Ymc7YIX91.r3eOTp7jtTDWBCv50S5izWMN14LFHPLQyRMbPT3OsUlqhAPDAbjfhMqkDcuz.eXoUby02DHY2QUW2XikljQMuIQNfvrjbYqXu9HTDJjeocytzEnO6C.fMqeSPnf3bfxqNxKwnFJBWQ0vwEP.ot44Fy1AOYH9DzrvJGiqFP.8ncw6d2Nl3YbYb610xypc8EE57nYHxFwiSx6mINvd5swgp9KetT074EOkUvMGFCRfyXipNeNNJ04SmXGuDWnNcjwH7tZgK3YVv.nqjyOv1NA9sJC63kEUZl5kL+Y.22WDMhJG7FEITaL8OBy.OzfHOetPfDkIe0LZ2icuI89UE+DccCd9083vXPinDz+YAZEwG+2RP.U2p.HuV98Z0YD5k.esn6wMTrVeP1VleYaJbdmBrMmpMqI6eGBKkzwpb4Vh7f5CmIGTPpATjDr1aAtkmxYEqB4qg2eGi9yeYuO3DziH.rWwDVuvAi29EOZm+MuZ86cWOnUh9V2XTlChM.Jq+y4Bw6VrXoH.nWcYdwvwEXGJYecKJlrMJPJGTeGDb7AAF7Ti.1k0j6Jj0lXurOUK6uL1KFa.NLaMoOFY8hRIsawZohfYaA9TJFa53tqtizcFy2Rfl4k6XNASBcnMHj.d3izmqprV3yVJtr50jnvaYLRNigh+oWRGYND3FrTl0cQ2D72wKAxsWxjT1W7WscNlBN6CCLuJysThxkRMuDJ9f8BCWT4lzgDN7aDFZGnIhjTN5exsRliIg8zZ6DUEQF50L4bFY1DHBoyBnVRB9qXX1bOq8d2RTlAHpJmLXpgIAoUICmUjgihnOYGifB1Yujwz8+30oBSh8V.OXE.mYzCBvdYxnPE3mO5LPLDFKE9VhHD1Um.a9UaK2Ff6Tkw8EyJglCrpcQ9z37BE7P1Xo+R.++xRDELtstGSqxPzdFmxgnbb+2yXV1zzSB+jwIj5atjOh3GvKbQC7fwNYYAx6dkJItPvUTcmbblbGPGIYBw5M3MPssjEPf8Cw7tebaVtpVJ2BTGEn5tI8x9E+uByHJVqWqjXT.vjRpcuGOl7bdLNaf9Lf8NIwvYOIWO2cGVCsXvoCp1I5lKPHWQwELANX8rFALDwT79pa3bZpWuTD35VBuyBRucTP4D8tjw6mfgMSFH2UyLLALB.NzsLSDiqdYnDVqBxMa+S2WhFE0K9Oxg6b34QT9yj09S5X8SRZoW.Ut.vm4HMsqpO6W20peScr2xxN+YvxJEdXpNztShwS3RPxLl6K47mSoRLOlzOK1KspLJJ+MxCYg97aJxSxXURErMXRrU7CmLvhp6BudZIqUuvekSkYZhPM1wLHhUukZGeH.FcA2VtfbLC7GayVmWMFEk7hjX3NofyuOfUlS2Xm1Je+VukwsoIfyu.s3NAIcpdMUu.dHTAURHjAeZ79RVGPAir2zVprSLD1YjyRyoyiAgVT8Iham8YtBMjf29kT0gaIUfmBx+Ch8MQIlEaFN0RK2JUMSm+LrPdQX8y7jOXx04Bh0+H.F3cbyB.O0wNWtE0PF63jLShso4cB4ZDTj+XJiJ2X5iHPT4M9m2VA0haJfCioWmqXJkJOM.7JbFC1k79dyGphkYNx+vcnE.vWtlLXU9vFHnrqTAfDTknxdcR+c+F7GFb1k5od5FQsz3PfVltb7h8mwkC2lM2B4L1KLT1ZkwL0Vuq20UBR3SCMUg4ihg1LeZKz3qGzGyjVsQqRB6lCHHLbEfCN..0wYVLBjnNElhT0xkwie9WCKAhysznR90vjNqMgPEN8Ne18K+SbsiLOY4Gn3cy5YZB.gzkAqbpZPgI4fQo07j2WUzWywXeqrGRnMl5N1j90770vEVOExSi2dDSRTegCbwpgsqmOjlly4ZBwCX0BqdxZ8LMRqUxKwxSxYWmRjGaDL5SAQ0Bc+3OCXQF8FjVbkn5ILwSmyWi4A";
	}
};
}

