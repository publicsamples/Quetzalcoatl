namespace project
{

struct vec6_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec6";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "320.nT6K8CFWATaB.XdT4LBLohS.bXE6oYQeFMDYGtHh0pgHLgGnYZZuTPQHKqtGMwFS+7B.u..L.Do1CXxyr9Ql2owowQQj+0MKHC4OJSdp1qqnbw0SVZmiwWPwUT.xGIwjWAXaIxOBMTK3OrKxRkfaizNI5.GxeKl0OLj2QYxyXKqkxEC9qsUTMP9013qoTBxWE2oKvNvEqc7unhdHOe4VH+0sHE+dciHIC4ujsHjozvIl7POPJV.k.JgBUf7vq10MZj7Zwqveh6jNdwHYrsoJtSz.hjdjzyBqi6z3n5q43PdEAji7jEtSmwVUyyjhrD3hv5xGf.hPBT81AXlTnsX1.gnW+DDTlRfO3PCykYGqhcCAvlE47YHTqfWKYGddvsJDD4vfrP.Wwcl6gsBx64aGxJrgN.BGRnukqGF3bOxY7MC";
	}
};
}

