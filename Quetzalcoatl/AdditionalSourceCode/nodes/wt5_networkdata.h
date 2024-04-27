namespace project
{

struct wt5_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "wt5";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "331.nT6K8C1rAzfB.XZT4PBHKaS.GAkT.ir2onJpMPjsfhcfaBODVnA0G.fER4Wn3oHwzOfK.7B.v.PGsGzjuwXJYdmkyxQSjGxtoXqxUnM4ibPVBS0igxvu2i2nynZdIOM4YHxY5Fk.bTKn8VXiT3sKvOK5.HNnI9TiwTNj2QaxyZSSKlJHG5VonUrAcaC4Hkf7R8BUE4.O4uAjNAEf7Mp2V4P10QMHjiH44P9JWGaX3HTS9ELbzv.GKbrfgJP9HE+3HKKPWSkhduvM0ijw1kTuWz.tjGEMrStyxQUnaBh7ZhXqaW13BcFaUMO6oaVhKB6ihEPIf.DH5TrdP5.yjy0GrAhgd+KHHMKA+I.DmwwOAkZCAvFEYsyPrVgds7NDgA2RHJxgIYggbEz0dOsUrL3gM9i.PKcfCbHUWTytwXmKFVDgbQrkMfgcKtsILC";
	}
};
}

