namespace project
{

struct oscin1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "oscin1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "324.nT6K8C1qATcB.XND2LBHKaa.OooQmjpIz6x1hIDhLi1KHnVYjG1eE.bE3v4XnnlIkwB.s.fK.DgNaGPSLQdxl2iLdgGM6lKQ0boVp0lPSn6j9lRBAcLIeAPyGPbzLy6NDaIA9uDzOKLqxis3uKHbJHyv7mkJPcD+MrBjRcyk3n4Zezr0RRrlMJjPGigo9F53uolGISn8Qyd5wTRn6hrFBcGqhMt32Z7exilLNXYPiFKPXAiUgl+j+bGpKPWbJ.E4HONkf1ZrBSji1.xGPfdfijK0ZWnKBBM2DeG6H94IYqw6pYCRru7LCbfIf.EH5PMdP5.ysy0OXCDhd4SPvXJA+R.SlwwbBJeCAvlEoryPnVgbszN3jA2THDZC6wB.4Jqw5Ho7EIGN5weL.zdG3PNjkYwmAlaKVp7XiKwcEjvxyMATxAKJ";
	}
};
}

