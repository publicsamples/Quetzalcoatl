namespace project
{

struct eventin_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "eventin";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "434.nT6K8CF1CTTC.XMD4TB7taa.OfQtAEMVTbBVcdItSgI8MPgIXC3siDGtcrMlVwynQaYJr.vK.3B.N9gt0VflcdFynn+VrDMzra9EUyIp0glP2cE6LIz8vthdgnYDUjzzSzs36KwGxiqBwtwcTC+bSiAI3wxeazvhTrCHgfq49rBjWRZ+gujTKCMa80ECZzCYGqoXC+pXW3p.0e0D1BfH1BzYI6PONy5H1OiIaMd2JVMD5P7MmHOAzcO+B0bKR5DGnKPDIMvnXPXOnjDYhjIK3.CGjbGPOJLlddj.X+1v7ODkFppSe1.rbO+U6iLE0MXk2aEnw1anBlYXAZVy.I..DypLP6vCCcuNF6nyKvrQJAChkxAsw.NlYBnXNyQTzPOOakAx.AFJpBeK2l1dELxqNaZXjK3SZqSXDp2wIDxYMCwEI2I6NCnsIUsE1Sii1NcVZfUdetA8fzx..KxuBhAvTxtPlAX3wVXDXzRRbOIuhUK6CqaDnKHGHMittMJnkOsgs2j8j0NXhUiIYbG8TNpAac4vc.aD8yFLZVOi2pA3GXTyAGHf1wUsvB3RQKa67.pFvWM";
	}
};
}

