namespace project
{

struct mtest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "mtest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "366.nT6K8ClDBTxB.X8T9TBDshS.uBLKKIBbsgUZGQ.vE.m0U4GHrnk7F...fVq6fQDhFoe.z.fL.XC.T6zkG+41JPqH+ba+fP5.4qz6jKQXCsJvjmaPIYd1hsXOniJxN7lhaIsQdmGE4iHBknYIAzHxMKswcxasU07sGH98fPx7mpYHhaCOnq2npFLxhbwQGeRZiJCl7mRQxRqjyzE4aLU.J.V1Hu4flFFBFzvZVLkf74hn4W7lBTl7V316IySE4Gdn5wkMZhx4j4+1qiENZRBB4mqhVGz.uWIXWkPlYqsqJ8JoA7y8tfx3cbaJSPHCpC1pQUlx7yRtFZPWjmnBj24YBGkItob1JnBHvH..NmtC5RGX5vRWHf13nKYcvJFBo2OTcj.gS.qmwc4vTSO.fZJRSm0X1AjaeBzfc.HfpPGvEVXbIFaJ6nhpycH35spKGRCl0VeE1Ju6tU+V1sF.2ybl9JLnIdpVr+VvHg0QVk7.";
	}
};
}

