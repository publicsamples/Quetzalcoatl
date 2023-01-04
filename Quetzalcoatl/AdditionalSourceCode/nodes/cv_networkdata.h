namespace project
{

struct cv_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "cv";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "506.nT6K8C11DT3C.XzkLYB.Mqa.eRau96eFBjxM6uYHLN0cNQhqkK7XElco++MJNiN7mLHYJDD..AvP.PctNKrXVOyeK50MoEWvawptkNSY0xaXwa+KYk2aeZFf2tIiz4eYgrUbShw0ISZYiLKSgUBKlwamPs3sZlxM0uR.cOD0r.P0Oyzi.ypF2Ts6Rme807oaQqqBSvtTSnnDo+tL+xdQkw.GPGEw574jSKKd94.KrR6bLriFucoJdae8z.AAE8DgM3sadMUKLAHrmhZ3DwJtuV0PDXGMV7XK5Y3FvNhjDHTTzjzAPNNkk2hTX712iFKv0ky7CUK4Eole.PsiqF.i2x4u1nnyGCltE53Ybz3j2aWu5S37YbZRFTnwet5SeH3AfxrEwpRoVE+.1RSQRllfzvFR2P1w5vN0PfQRhjjZo.EnwDDXPJyTy.D.nHX.PY.yYLd.fQFHsb2F.GBbY4Y.me.Ve6djGbGBLfiQSFIkdD.FBounsWARj.CSjnnRJDRMdTf1rF4LbzSY4+FxFrNRC42pQgrfsUdE1DTx7QeQ9qXAHeVCGdQCKXN8B34fR.YGjW1F+EBaCPmBXG4AgmvxIO3kgaB6oBNuX1RElS9BOkrsYejfkIFfINHG33I541U.JbeM.ILNOPSgxZgsXBV0thXW.PUGPKGXoF.";
	}
};
}

