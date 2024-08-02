namespace project
{

struct pan8_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan8";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "403.nT6K8ClcBzDC.XAk.QBHqa9CQusiMolmAuLZBXwHKv4X5w.5aabcKDffDgvIOpPUoLfM.XC.2.P6ZUNCWd+vxpRIWiyfwKjRQRQRaCM8ugAaM4zpPSql+cdgbOEn24ljRb9sLzrhkUyGfOnXiIPL6gq.saCa4fi27NN6isQhkP6OLlqFCiegRH8F2wJB1dii9asAnYmHSEB9QKVgEZ1WOFUaKOvBflWVhMGHmgcYW+kLywZR+aQq18mx5PyJVRnYnVD1uGRoPO.BAQJ.AHRfDYcnIL6cOk95i33strFVFQzpdcrxfMyoH+4iYSlFXYjP0nG1km8QNAAeIkhj10aWVnY5L0tvN1eXHSkv1c94IbCHv.D.NUdGPcnUF.+hnypC6.26YLEMtTGq6FBozZ5JWT6fcuErxG7NydJI.vQnUocbmvz.XLG..2wx49bEW.AtfqsT01Z8.jXfgdkNVSavdByVyNficBFXgFUHfibHiWpPPb.U.bw.9xfs9.yDfCh3FaCewQwh8JDsGb7eSw0iUHDXhB";
	}
};
}

