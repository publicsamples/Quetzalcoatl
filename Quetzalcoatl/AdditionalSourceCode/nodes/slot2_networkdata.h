namespace project
{

struct slot2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "slot2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "320.nT6K8CFXATaB.XXD3LBLKhS.q6ZeXD0mEBhXEvKJyhBtNCA+1liKACLnvHCfRBKJ82B.s.vK.zQoMgk7Lqej4azk7RsWOQohqibncNFewrXVutQAYHeQrcTph7OPK4a.1ND4G0PkfytHqDCtMR6jnBjH+oXV+.Q9ktjmwTTKkJH7WamjXf7qswWKoCjeJtQUfUwZGWAUQdtxsP9qaQI985FOPHxWIaQHSogQK4cLX0bfiiyhBz.xCqZW2fQxqEqBuItS5XEijwVlo3NQA3A5OPMOrN9hYo5q4HQdUAji7jEtQmwVUyyfhrD3tv5Bg.B..A.oh4gYhTvwrABQu.JHXMk.+zgIlKyOVk3FNfMTj1mgXsBcszcPxA2PHL1gM2BDdEGlIu1r2qJ3tiq3OB.szANvgDhq9dAGVlXnaNFYUbB";
	}
};
}

