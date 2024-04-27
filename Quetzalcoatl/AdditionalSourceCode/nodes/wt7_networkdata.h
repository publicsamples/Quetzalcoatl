namespace project
{

struct wt7_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "wt7";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "331.nT6K8C1rAzfB.XZT4PBHqhS.mnIMirHeRDqHCAgSofm5Jw+inxao..jb.1LNHGY0oefK.7B.v.POsJvjuw3HYdmFmFGUQdH6phMI+QYxO4fLkkqGKcgeOFeQeQ07OhXx6PjuzsHAbTKn8lrSM71I7ihNPBDphW0XbDD4cTl7rVU0Z4pwgtkZpI1ftsg7jRPdpdkthb.C4eQilAEf7Mq2J4P10SMHjc7HBQ9KWGaV3nDSdHnmGCR.BAnCTAxGs3G6ngBz0VwSuU31hQxXaCUuUz.9inmGVH2owQUnCRh7phXqaU13JcFaUMOKpaTh6B6yhEPIf.DH5TrdP5.yjy0GrAhgd+KHHMKA+I.DmwwOAkZCAvFEYsyPrVgds7NDgA2RHJxgIYggbEz0dOsUrL3gM9i.PKcfCbHUWTytwXmKFVDgbQrkMfgcKtsILC";
	}
};
}

