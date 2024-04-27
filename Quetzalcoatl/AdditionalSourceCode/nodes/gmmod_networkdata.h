namespace project
{

struct gmmod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "gmmod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "220.nT6K8C1Z.ToA.HIynHBTItI.jos2WmByWLDlBIH.NgsvxMSzAdQslYhvhYZFKI8CWkTZfw3giLtJYfhF.zp3pjR07bj11vwTn4iry91E+JEn.jGhWtDYd3ic3HBhns8.YKY9uwcAhaON8AI9kPaUnaOzANjWMSRdkdH+hgv8IBwcrERS5wN1FcciRPdHwcQzqiMKBGxyqlIyqRpjx0L3ia7U637PEH+Rhj7K7ZFhLSPDf.gI05AZYnCGBwA.+bfPSY10wZPmYsJy9jTff678.n460BvI3lQfKQVg7.";
	}
};
}

