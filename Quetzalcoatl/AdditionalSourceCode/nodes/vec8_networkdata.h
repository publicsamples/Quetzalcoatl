namespace project
{

struct vec8_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec8";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "321.nT6K8CFWAzaB.Xdj4PBHqhS.+SEapYQ9jXDYGBvjTXq8SjhngUSsBAvfQfqz3Y1Q5GvK.7B.v.PjZQfIOyZHYdmFmFGMQ9W2rfbj+nL4oZutpxEWOwP6bMNDEaQAHejDS9EfMCQFRzPsf+vNIKkBtUR6lnCfH+sXVC4PdGkIOisr1JWN3u1VQ0.4WaiulRIHeUbmt.6.Wr9wOjEEQd9xsQ9qaQJ98ZGQRGxeIaQHWogSL4Y3XvBFPJfTrPEHO7pcsilIuV7J+ItT53Uijw1lp3RQCHR5QROMrOtSiipu1CD40DPNxTV3NcFaUMOSJxSfaBqKe.BHBIP0aGfYRg1hYCDhd8SPPYJA9fCMLWlcrJ1MD.aVjymgPsBdsjc34A2pPPjCCxBAbE2YtG1JHumucHqvF5.HbHg9VtdXfy8Hmw2L";
	}
};
}

