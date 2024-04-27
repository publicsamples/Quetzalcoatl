namespace project
{

struct wt6_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "wt6";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "331.nT6K8C1rAzfB.XZT4PBHqhS.mnIMirHeRDqHCDoSofm5Jw+B6EQF.AjEiLCxvQsjzOfK.7B.v.POsGzjuwXIY9GmGmGEQdH6phsIOg1jexAYJKWOV5B+dMNTeQ07PhZxyPjuzMIAbTKn8VXmT3sKvOJ5.GXTDupwXIL4ezl7rVU0Z4xwgtkZxI1ftsg7jRPdpdkthb.G4GxQmfBP9l0ambH65oFDxOfDwj+x0wlENJ0jGhwhEPLTvPgAp.4iV7ie3PA5ZqPhdqvsUijwVGpdqnAbHQIZXi7GmGUgtHGxqHhstUYiqzYrU07rntQItHrOKVPIf.DH5TrdP5.yjy0GrAhgd+KHHMKA+I.DmwwOAkZCAvFEYsyPrVgds7NDgA2RHJxgIYggbEz0dOsUrL3gM9i.PKcfCbHUWTytwXmKFVDgbQrkMfgcKtsILC";
	}
};
}

