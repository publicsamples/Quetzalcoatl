namespace project
{

struct NOISEMOD_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "NOISEMOD";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "400.nT6K8CVJCTCC.XZD6TB.Mia.uYT5V1mKTOgVJUhNBd.QJw.sVPmFTf9+atAabPEoMlRAv.fL.3B.d70y3SwErplYWIS9SplAmUc2OYWEZAKvpw+cIcKpDJSKzfDkI7ypRjRr5F4CwzmDOZLZHwd3GAJS7MwdoCwzTWfMlGlgI..mCzMTODykVDuGXE5UhUWvNq57qq1JSAUCEjrjzmdUK6JZWYw7pNoomQ1NzPL2Oope89niAaKSJOF+Hrhr2T5VurhypsDZvn0B50BUwOpyAg4ENXD0Z33gAZFz5MgXS7SDBb.pFM6pehAww4ZH3KGPkHEEQOob7M4B.AZn4lhDRFETXJnX4.kgHlAKC.1sgYipAdG10l0X4K.4zCELuLQlAa3xG.5NN.2+Yclp+Eqb.og5OiljxFyCFzbCw3tVSm9M2IyV1CVgaE.Lsd2BfcynuAiKB8R9lTCZhCdp4muAAZi+KpskBkkHgaTWbSg+RpAsbcujiWanQXFhcKNZOFLw6JMzidaffUVpcot.P0AnpB";
	}
};
}

