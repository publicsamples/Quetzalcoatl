namespace project
{

struct EventOut_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "EventOut";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "379.nT6K8ClLBz3B.XJEAQBHoaa.8yVhlVHaBhWLqDngAtBjpGTyB.Iw.IPHiuEPUQtgxTvM.bC.1.PlmmbE8OhS.glsjKQ0rwZr1pPSn6phckDZezLxA8LTWOeBG+8XjukBOr2fvBflOf7nolny4aIAP287yRxi7nbSw53Bto1DGHH0D4OFr.0Sb7xFPVcP6IVR11GMk5pJl5pQBcblHVrgN9gdzJflATE6KWrZbwOpJ2CUyje9Qm9QM4NxrsdbkUQr+dhi7jL1uKxwB+rjkG1a5c.MkfD0Pn63aLQdg77j+VLPju+nrKZLnFbTn5mR1XG.sI5vQxFqsqBcQVMOnpxv.cukG2BxLqRHCVDZ1okfPTMCq.BPBRLsa.UGLSRvSCah4FZDAvddFyAerjsSwI+FHpoF5PjAtDr.K.GRkJwAJAvbFumCX.Jf5JDWZq5ZCIDLpsbK1pvYDwUlkqTJ.2T10MbbCiA4n0OHcNrwU8qFHrDssLX0HbXOA6pQA.";
	}
};
}

