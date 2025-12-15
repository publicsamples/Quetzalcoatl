namespace project
{

struct env_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "env";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "494.nT6K8C1mDTxC.Xw0KcB7vhC.TLaJ3JwLoY0Gw2Vvn7pI6Fv.D9pBkJpdXwgyeym3Q7jZxGvO.7C.DA.ms4vuplL6HjqQY0hf6WUdy1TVqXHd3daI03beBzFw8nDRmMF+sUvn7JaCSt4iDCqguQr208LSDf6clxO0VS.W4LbzXYdjXdTBqUcLJw.Ps4L4KtppvOT+QsFFiwoytN4MdzzrFrAqy4lGtIclDqO3Sp0EuQNE.W6g0bHqlRSsgU.JQTrDUQ5wfzaRZ5xmtC0eRuGzkJOE5.Rk0UJHHn2JgCthuQXEPbWh6+qUaY0Y34g+VXe3NGsUTCMzbXiwxnvLA7eZkiXgLaNbfy5.qkMlZXZJ2XsEqDKQOJPQSUHfpQsRjrb4BCTjhlldaBeiq5LaDnHKLoDKj+lhBd693uSEWqDHvH..LG0F9YQemRgT9vNAv88ItZYvgeevdfGYhIE8LUWJ6.vYQx94NPebF4NLzfmwqMVJFFDXPVE0tzSXGLqSPSJJwBLNvf8bXLKFNYp0sHQdstz77HRCfCBbOXNEJSkjpwdQRtDrLrUiwC.CLhPNvJwf9gGbfGnHSD5mDDj70GqtDq9MvjEDzAbg4.3Ci1.pyFjgDD5J5VWxONeHfcwOxhaoB0AdSrw57.Dc.vd.GY.";
	}
};
}

