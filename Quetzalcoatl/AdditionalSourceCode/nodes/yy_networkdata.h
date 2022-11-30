namespace project
{

struct yy_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "yy";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "298.nT6K8ClzATPB.XRD2LBLqRU.EjwhPjr3V7VRKfAPSywtLBmGNWUocjQjfUl1xjnM82B.s..K.DaGimt2yNf9KSVRT7MeXETnuWuHpdURkTKC8tGSF6JOJZWn+AjD5cH9fX1QBfwQD2fR1CU+4I+HS2fPuDRc7PHNxfCOu1y13xd8hjPuZUne0RICibbGiu7jBvPkZhfMA1yIWkNnYAHC6bURsq9FSiq3XNq9c1Pbjk72PvtPeld4fn5kw1hk+W1OvlOrCxFPAuWOmdxK3BaiF6ZfM4QYsPXEnY2GaVCxlMLNaCCZ9ePnlxlFf.lvRh+M.Qpu7xDDO7K.EvC7+y0ya9.3W.oaOqYhHZCd65304FHtoLw0Q5amFZUm8ol.AvCbOOCKXQXyTnwLC.";
	}
};
}

