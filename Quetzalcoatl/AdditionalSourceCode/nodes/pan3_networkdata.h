namespace project
{

struct pan3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "403.nT6K8ClcBzDC.XAk.QBDKc9wBsskMYV8YrDRRP4hql+cdcPxcyDZoI..PgEyksGiLEfM.XC.2.P6ZUtBWd+vxpRIWiyfwIjRQRQRKCM8ugAaM4zlPSql+cdgbOEn24ljPb9sKzrhkUyFfOnXiIPL6gq.saCawfi27NNqikQhgP6OLlqFCiegNH8F2wJB1dii9asAnYmHSEB9QKFAEZ1WOFUaKOvBflWVhMGHmgcYW+kLywZR+aQq18mx1PyJVPnYnVD1uGRkPkLAIBAF7nfGQ1FZByd2Sou9HNdKtrE1EOzpdcrRxl4Tj+7wrISCrKPnZzC6xy5HmbfujRQR65sKJzLclZWXG6OLjoRX6N+7DbCHv.D.NUdGPcnUF.+hnypC6.26YLEMtTGq6FBozZ5JWT6fcuErxG7NydJI.vQnUocbmvz.XLG..2wx49bEW.AtfqsT01Z8.jXfgdkNVSavdByVyNficBFXgFUHfibHiWpPPb.U.bw.9xfs9.yDfCh3FaCewQwh8JDsGb7eSw0iUHDXhB";
	}
};
}

