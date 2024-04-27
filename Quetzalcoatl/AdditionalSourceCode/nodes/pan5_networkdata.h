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
		return "366.nT6K8C1DBTxB.Xpj7PBHKiNeQ21yJIFKSToz..fL4YzdAivdNuBLC.H4.bDpQGXlTFPL.HC.y.PF7iUrBOZ1VOEUSoHoHoUgl92tfskbZezrp4elWl6od3ctGoCmeKjlQj7noCv+gXSIPhv3sH1C2AZ2EtpAGe4cX1EIbVE4Ua8TbzTZezzput3WVBo23LUQv1abz+pU.MyDYpfyOMK.ZZII1XfLCrCy5mjMlisj92hUs6OjHRbzLqEg86gTOZNwnfFNPfwALZrAnID6cefCagEJhVkWGqXvl4Tj27QrGSDrPNZz6xRytHmffmjRQR65sIIzLclZWXG6MLjoRX6Au.BPfnCstC0gVY.bqQz+CCf6aLlRiKqi0KCgLQMgxgoGbhCY+lY5HI.fQPQocbmvz.RaG..2wx41bEV.gWv4Vpv1Ew.jYfAbkNVCCjZ8LTwxfGZ7mB.M1ANwgTAhB1IF6bwxJQPaDcaCZt6QNipY";
	}
};
}

