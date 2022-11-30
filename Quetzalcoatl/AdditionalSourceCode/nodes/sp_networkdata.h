namespace project
{

struct sp_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "sp";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "428.nT6K8CVZBTQC.Xf1RYB3tpJ.yssRiLJwb7wpZDd.DULcxU7fFE.fK5IgYXdXexCD0WWIeXD.HA.R.zVabKyBeJiYWuZOkw6jdwH3d1MVkoRuWQGX3diQo3bG9fOH6v8IUZqsDGByv8K4jlskQiVggpoov2rbC2k.AC2qToXtMk.cyhr4RZuLooxkr1XqsMhFdxg0XX8DVZ3PdvMb2hFaBQC2sslzApD6hBN2e7FkXQqsYgxvqquRuQsKyXkB1faaLJE.bGxLbG6ilnjfhdh.8f7AeRkWokVwD.ePX9AYtg6A39s091Vh0X0uCjDUzCKfEwI8EsnDS4jWQDyyJBJ8.R5wCCOj0KTis01rDsZxt0v+s87xskbrXW2rXAlfhndPdfLWoc1R3AbjfPRPdONO8ERqoLVefK.BoXGNb.+YWWYE6XJxDTDEjRZJhSD3izCxI3NlthkSD+PHf.FHZLq6.qnvSPC2AOd3Sv6EDIB..8qs2mxz7Pd1YkqCGWcdadkABf6GrRApLV+wMGJgWf77G6Atx3yt.GXhywUqviYxoU.7.GmmkEr.rC0zVlA";
	}
};
}

