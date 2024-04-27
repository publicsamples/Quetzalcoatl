namespace project
{

struct pan2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "366.nT6K8C1DBTxB.Xpj7PBHKiNeA225F41ISToz..fL4YzdAivd12CLC.H4.bDpQGXlTFPL.HC.y.PF7iU7BOZ1V+DUSoHoHoUgl92tfckbZezrp4OlWl6o17NmijgyuERSHQdz7A3uI1SBOht3sH1C2AZmEtxAGa4cW1EIbVE4Ua8SbzTZezzput3WlBo2XLUQv1abz+pU.MwDYpfyuLK.ZZEI1WfbCrCy5kjMliqj92hUs6+CHQbzLqEg86gTOZ1XpfFFj.CDXzXCPSH169fCigEJhFkWGobvl4Tj07QLGSDrPNZz6xJytHmffkjRQR65MIIzLclZWXGaMLjoRX6Au.BPfnCstC0gVY.bqQz+CCf6aLlRiKqi0KCgLQMgxgoGbhCY+lY5HI.fQPQocbmvz.RaG..2wx41bEV.gWv4Vpv1Ew.jYfAbkNVCCjZ8LTwxfGZ7mB.M1ANwgTAhB1IF6bwxJQPaDcaCZt6QNipY";
	}
};
}

