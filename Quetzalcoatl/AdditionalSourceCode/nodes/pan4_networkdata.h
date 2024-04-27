namespace project
{

struct pan4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "366.nT6K8C1DBTxB.Xpj7PBHKiNeQ21yJIFKSToz..fL4YzdAiPO1wAKJ.IHAH.pwlYsLEPL.HC.y.PF7iUrBOZ1VOEUSoHoHoUgl92tfskbZezrp4elWl6od3ctGYCmeKjlQj7noCv+gXSIPhv3sH1C2AZ2EtpAGe4cX1EIbVE4Ua8TbzTZezzput3WVBo23LUQv1abz+pU.MyDYpfyOMK.ZZII1XfLCrCy5mjMlisj92hUs6OjHRbzLqEg86gTOZ5XpfFFf.CGLZrAnID6cefCagEJhVkWGqbvl4Tj27QrGSDrPNZz6xRytHmffmjRQR65sIIzLclZWXG6MLjoRX6Au.BPfnCstC0gVY.bqQz+CCf6aLlRiKqi0KCgLQMgxgoGbhCY+lY5HI.fQPQocbmvz.RaG..2wx41bEV.gWv4Vpv1Ew.jYfAbkNVCCjZ8LTwxfGZ7mB.M1ANwgTAhB1IF6bwxJQPaDcaCZt6QNipY";
	}
};
}

