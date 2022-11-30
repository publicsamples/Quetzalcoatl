namespace project
{

struct file_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "file";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "384.nT6K8C15AT6B.XeUHYB7TxMo4dHrBkFBB7DsZXG6gr+HGbMBCg.CQPHvy.kgJCgNQvJRorC.7.PO.3UroUi.uapd0FcVsbLO79vYFlWWjKx0AvK1LpQ+L1W+vqUDatIaSNqDYJkQruL9QOgWJt3gWPnSQpelWUrOJMDucdH1EP7p8xHlYDxIBl20qNEcdY10bhnmlvR+MWl0QAq1CmY.fWW+vK70z7rMIVrnuwJh9Xw.QMYeUy5hj5Nx0cyKDuqF8q+kS8pckp7ldWj5A53TOGomAVjZkppfRHZeIYN0KytbMP.AGanAIMCL7gv2irOKStFpL4fK50JLiUGil.oKUjt3vjEKO3VX2MKrmSHOEScNwnOv4bRs.R8DnW0snm718gSJPrbO1bYUafK5MRfHf.H.BFriADYRyabYRGOv0s6AO3PBXSgNENQKlyJYKGgOcF1LdpkfTdMoqpibtCsegbBP6Q2x3Y2fYHy+kn3AVwbMH1Af3ii8XGVqF6djy.ZF";
	}
};
}

