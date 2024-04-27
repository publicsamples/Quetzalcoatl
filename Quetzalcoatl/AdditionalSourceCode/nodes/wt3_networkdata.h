namespace project
{

struct wt3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "wt3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "331.nT6K8C1rAzfB.XZT4PBDKiS.WoIcwH6kBJhHBSiLB1Qzh+.hK.1lpppt.4pCiMvZS+fK.7B.v.POsH3juw3IYdnGnGHEQdH6phMJOg5jexAYJLWOVJC+dN9hNip4iD4jmgHmoaSBbTKn8prSK71J7yhNvgFEwqZLdRSdH0IOqUUsXtdbnaoldhMnaaHOoDjmpWoqHG.K4ewiVAEf7Mq2R4P10SMHjgDIpI+kqiMLbTxIuBFML3fFJZnfgJP9nE+XHOVft1Zhduvskijw1GpdunA7HQIZXkbnGHUgNIGxqHhstcYiqzYrU07rntYItIrOKVPIf.DH5TrdP5.yjy0GrAhgd+KHHMKA+I.DmwwOAkZCAvFEYsyPrVgds7NDgA2RHJxgIYggbEz0dOsUrL3gM9i.PKcfCbHUWTytwXmKFVDgbQrkMfgcKtsILC";
	}
};
}

