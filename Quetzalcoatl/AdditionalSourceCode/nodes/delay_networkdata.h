namespace project
{

struct delay_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "delay";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "391.nT6K8ClPDz9B.XaD5PBDqSc.OXtDr3g5sB21k1hCGK.vvtyFX.h7tpptP1Y60v5gSovK.7B.v.vmEzoVjzgu9gwFWvpSeW4iL9sNhhUcWjxtZjBFeSoeQ+zO3NdwpPjfX0LxXm2oDLQ4UcNOzWfuIJVkWc2nMSGFl.cxQFmZX3.RnSDqtlR+cMsrqzINYQUbhUc9b1aBNXLkRIoVJoHEavpc7LV3LstAm6QXAVGvPS+FGBuXwrpqu0DeNJ.wkOzevCnV7BOcpmmFl8ukN2cfgbRzIL99lCgwG6pMjXHgfhwXrRXsVNXPuw.34MgY+aFXnkpAiQPNfFdDCAQCEzhJiBO.B..GQk6.oiL3rfzLnOpRYw4ofLZIBNsoAocPejTFQgIAH2Qr25FpsxhmxKPW8PDpnIy3gyxvkNGI.NK4HU3rqttzp0Did6.RLEasLUX5y4ndlYLpIVpHQ3dO8qEcN+8UdlJseXNFcqOrzOMLrN7lcf8PCCRjxxP3bBTHXNktNPkgMJnnF.";
	}
};
}

