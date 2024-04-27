namespace project
{

struct pan6_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan6";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "365.nT6K8C1DBzwB.XpT7LBDqiNiB226lTyyfYvpAzo6gNNvnIfa7frKA..Pogv04AlIkEC.x.vL.jA+XEm.jls0WQ0TJRJRZUno+sKXeImVHMqZ9q4k4dpNuyAIe37aSnojIPZ1.76D6JQjnLdKh8vcf1ggqXvwXdWlcAhmUQd0VekGMkVHMs5qK9kgP5MVSUDr8FG8uZEPSMQlJ37ayBflVShcFHu.6vrdJYi43Ko+sXU69GQxjGMyZQX+dHEjlMXzvQAGvv.FN1.zDh8tO3vTXS7PyxqiVdrYNEYNeDCxDAahGM5cYsYWjSNvTRoHoc8FEDZlNSsKriMGFxTIr8vKf.DH5Pq6PcnUF.2ZD8+v.39Fioz3x5X8xPHSTSnbX5Am3P1uYlNRB.XDTTZG2ILMfz1A.vcrbtMWgEP3EbtkJrcQL.YFX.Woi0v.oVOCUrL3gF+o.PicfSbHUfnfchwNWrrRDzFQ21fl6djynZF";
	}
};
}

