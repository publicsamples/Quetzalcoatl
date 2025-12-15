namespace project
{

struct pan5_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan5";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "472.nT6K8C1FDTmC.XwT.YB3tia.a5S4YxV+KpgmX.gkO9DrsPAHICK6+NLFSBVgkuleU8voTPC.1..M.n0YibPEYII8Hrmw2hMXUQylyH4OsZHbrp+9M6pRSLjUiOTS5ezIwNierJlLLVkB4Wwz2DvENxH3T5YujiiZgpIVnpPUwQVUt8W+EoPQ3b6kLB90DsEnqdh+JDS.2fgnZLVGq2nSbiUetVPDFAO.+P55kInXx3rn0vbDpwwxP3nRe5Xsry.8bQy+wzXIq9xL8Px1Ses8dM51U+YZ4w3G6JgwB7hOvAXgpphqxDJLH4pp3Cvfd5vEbArSlO6v.3n3bSVpbSNItYi8ysFZ7dMyYXsDJHaOUAZroPzL.M.IfDDDC.i..Awj0M.jT1w7fgjYlTqVFRHoKOnNGHIRpLCqyP1eHU.5L8iQXkR.hTRZ.YhUDcBzn3xukrBnsqDHPnsLge3CrjMfBLalZcdPkSUlhLpslAURq.APsroUTnMjDZk33tb1j0PJpKJxbthu8C.lpmdBNBMO5xHaT9NfbVLgLqILlCxLjAc+dV4FrPjEqMiYhkGl6.EqPjGP4YnmbcfqerkcLNFWL3sv1IMW3ig2YAMWFIqC+hNnFzNGfRA7UC";
	}
};
}

