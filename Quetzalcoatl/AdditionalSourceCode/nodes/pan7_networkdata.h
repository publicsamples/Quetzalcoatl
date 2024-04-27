namespace project
{

struct pan7_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan7";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "366.nT6K8C1DBTxB.Xpj7PBHKiNeA225F41ISToz..fL4YzdAiv997JvL.fjCvQnFOpQxTPL.HC.y.PF7iU7BPZ1VeEUSoHoHocgl92tf8kbZgzrp4ulWl6o57NGj7.meqBMkLARyGfemXWIQhx3sH1C2AZGFtxAGi4cYVFId1E4Ua8UdzTZgzzput3WlBo2XMUQv1abz+pU.M0DYpfyuMK.ZZMI1YfbCrCy5ojMliuj92hUs6eDISdzLqEg86gTPZ9nQANdjPCDZ3XCPSH169fCigUQDMKuNZwfMyoHy4iXPlHXU7nQuKqMKibBBlRJEIsq2njPyzYpcgcr4vPlJgsGu.BPfnCstC0gVY.bqQz+CCf6aLlRiKqi0KCgLQMgxgoGbhCY+lY5HI.fQPQocbmvz.RaG..2wx41bEV.gWv4Vpv1Ew.jYfAbkNVCCjZ8LTwxfGZ7mB.M1ANwgTAhB1IF6bwxJQPaDcaCZt6QNipY";
	}
};
}

