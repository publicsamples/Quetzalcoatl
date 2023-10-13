namespace project
{

struct MidiNote_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "MidiNote";
	}
	bool isModNode() const override
	{
		return true;
	}
	String getNetworkData() const override
	{
		return "379.nT6K8C12Az3B.XOEAMBLoha.SSqE5PmBsXD1I8rTqo+e2HAMfcCFXwluNc7XXXsLEXC.2.fM.nRj7zE7kTLClU61Ksq5z3z3vNr568HrcnHXLqR4uWh0k6mn7NWBskuj27HV.q9.wr5D3SQ1Ro8zwNzFTLxtEL.V8AZY0KWBaqGNUv8PBLrbPES.M1sWZYUGFypsNFYqKE5yYITMv94r78TrB1fxR9oR6rp9EJ6.rkcEC4Is8UIP4tGSqFDU+d+BYGAxMduKY2r8QpB6GUSoV9RrA51GwLnJaYCBIW8xYhGHDU3H0owgwddTgU2lHOWNeHy.HPlJtXmUzefsz4LbFu2lIlPwSvt4NDTUis6A2fsZs.BTf.3TJO.jN.Vmq1Gl2cCCvlUjmnLHxWZwPjZHPoaHSqLv.RvnT.vBmYATn80qhKZVf84kAqSv1Nf.KCHshFrliz2Rm18PkAd3TBAO3FaunKCHNFrUVlokXiKjSHvAPgQZ.HxVeB1oMC";
	}
};
}

