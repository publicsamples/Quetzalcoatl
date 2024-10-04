namespace project
{

struct pan6_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan6";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "472.nT6K8C1FDTmC.XwT.YB7rba.KMiPcKjeiLjzZpcpT8IM+Lru8i0uwbXtErFC7kYxbDgTFPC.1..M.n0YkZPIYMI8Hrmw2hMXURytSI4Os5GZrp+dN6pST7iUiOTS5fzJwNicrZFMKVUB4Owz4D.FFRI3T5YuryDISpnbQhEIULjUka+0iYZTDN2dIifeIpsBc0h9qQLALC9gpsXcrliRwLV84ZQDBAO.6X55kInYz3nn2vbDtowxO5nRe5XsryB8bRy+wz3Hq9zL8Qx9Ses89M51UCZZ4w3G6NgwB7hNvAbQRkEmEJUVXxUUwGfA+3gKnBnmLe5gAvUw4ntT4nbQbyF6maLv38Zlyv5HTP1dUAZroPzL.M.IfDDDC.i..Awj0M.jT1w7fgjYlTqVFRHoKOnNGHIRpLCqyP1eHU.5L8iQXkR.hTRZ.YhUDcBzn3xukrBnsqDHPnsLge3CrjMfBLalZcdPkSUlhLpslAURq.APsroUTnMjDZk33tb1j0PJpKJxbthu8C.lpmdBNBMO5xHaT9NfbVLgLqILlCxLjAc+dV4FrPjEqMiYhkGl6.EqPjGP4YnmbcfqerkcLNFWL3sv1IMW3ig2YAMWFIqC+hNnFzNGfRA7UC";
	}
};
}

