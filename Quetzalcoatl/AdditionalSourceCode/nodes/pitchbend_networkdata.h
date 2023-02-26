namespace project
{

struct pitchbend_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pitchbend";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "324.nT6K8CVWATcB.Xpj5LBLohS.bcW6ihX4QLNQ1gKhfuo3lJ1gBZ11VXfgn6YiZBKK8GC.v.vK.rIvjmY8iLeypY0nHx+51DjkbGkI+S60PRUtFhk14Rb1im.8DaR5.4YzfIOCv1RjeDPbcTr1Ayhgm0QK31IsqhRvmXV+.f7MJSdFOMsRUJ9qsPOKH+Za70OZA4ghKjJXGeBSgBkhp0IM0Xj4+FWFWXmTTu3mobqDEAjibzBWHmwVUyyZ7vuWuHy+oHWAtJ75V73F0QpDGR1tfhajJvQPQzrbZnEQhiQdy5.GMfKqi2rZTMeMGZ96XfdH+El8Zj4mf4AHvHj3Trd.20AZZXVG.HHG.6KDVXkjYgkzayZsYRCF.RWADlAKztARapoCUVbEo.mKvU1ptZHsYF69BzZN44Rjl6HmejlKf51ngHBy";
	}
};
}

