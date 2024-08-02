namespace project
{

struct pan_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "391.nT6K8CVCBz9B.XQ0BQBDqi9Yw11xlTyyfYvpAzI.D+aX+tof+Qpox6ppt.4I2PhQSxvM.jC.4.fpsk2tVkyvk2OrrpLx03KX7BYDTDTz1PS+aXvFSJsJzzp4+l2G2S44cNIoyuc0jxzp4Cv2SrsDteRe8PZ7VL6gq.Y6xvVN33LuSy9HwRncG1xUigwuOIjdi2XAAauwQ+s1.zbSjo9.+nEqvBM6q2R.7iyBflWSwVCjuvtrquRlRN+VFZ1YNFS5eKZ0t+SVGZRYJglezVD1uGRoPgHQPjBP.xAPhrNzDl8AoKqgkQDspWGqLXyTJxc9XlDoAVFITE5gcwYePYJ2FQPRPvUxHnnc8VkEZlNSsKricGFxTIrcOzBHvHD.U5c.sfC3ODc1dX.buiwT13RcrtaHjRqoqbQwC18VnpeviY1SIA.rHlZtL6wZyfSq6XrbtOWgEP7Ebskp1VqGfDCLvUTusDHEMnEGOA+UnMKB3.GxJmhlNu3Y6IaqgjyZvgO2E2O1fPvKJ.";
	}
};
}

