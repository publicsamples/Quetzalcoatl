namespace project
{

struct finalgain_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "finalgain";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "445.nT6K8ClHRzYC.XmT8TBDqad.m9BeiT+fQj6B.3feGJ3ECHR2r6RDa...ffgzFLECQoT.x..M.DC.SYrNoR8.7doFmzghVkhJz79UnRXd8ku7VAuSprh5orSYzRl3T1Pyf2DfffWLTTN0WRf6rF8uISjxTFg40SwnSrXk0LalZEArUH3kUQ80eJREmvgdI5mhRVuAf2JeUUTSmCtHsn9.PmybWun6cY03DstwfEVn6XuGOHHGp0Zu0SS.ubdLQKyAi4vGyYE7fLRyWi51gXj0WA0buGGaEHKlTYU5mSJBLuNn6A9.BsfsFLC0buGGrs9UOCs.aqSrVlxKUJcJh4Pv2CX.NAZPIgH.FhB.gQQPG.F.BHyNR..J6h1h1GsEsOpUSTtMKldpPK4xRwVYwA6RwBalzVSUKkXR.CFv+BvG7sg4fICsZbAJIIOi2bqx8n58Ss6Ss6uZ2W0t2+nkrbEqzif33z3fOMTpgbAMdWO+3NAH4E7tsar1DK6LRAnzfAP.0HmAMDdXCHAnQAQCYbX.bwfgJdHv+pwqEkwVC.1p.Mlwh4XbuZS2jvKFgrmwfvubdS7mVvtgxxTT6gGXvC";
	}
};
}

