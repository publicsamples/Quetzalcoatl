namespace project
{

struct wt2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "wt2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "331.nT6K8C1rAzfB.XZT4PBHqhS.mnIMirHeRDqHCAgSofm5Jw+ByPVJ..IGfMiCxQVc5GfK.7B.v.POsHvjuw3HYdmFmFGMQdH6phMI+QYxO4fLkkqGKcgeOFGpunZ9GQL4YHxW5Vj.bTKn8lrSK71I7ihN.hCZhW0XbjC4cTl7rVU0Z4pwgtkZpI1ftsg7jRPdpdkthb.C4+oQqfBP9l0akbH65oFDxNdDcH+kqiMKbThIOjhEFbvBnEPJTAxGs3G6ngBz0VwSuU31hQxXaCUuUz.9inmFVH2owQUnCBh7ZhXqaU13JcFaUMOKpaThaB6yhEPIf.DH5TrdP5.yjy0GrAhgd+KHHMKA+I.DmwwOAkZCAvFEYsyPrVgds7NDgA2RHJxgIYggbEz0dOsUrL3gM9i.PKcfCbHUWTytwXmKFVDgbQrkMfgcKtsILC";
	}
};
}

