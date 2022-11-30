namespace project
{

struct noiseclock_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "noiseclock";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "485.nT6K8ClzDzsC.XI0BYBDuha.bvlvBoHtl8z4jaS.3uMOH+AC31CWy7H..HRV+w0SPhcjRYC.3.fN.zEv6lpiJi90mqhC+KLus9g2Wb9arxjOUmWJorQRMDuyOdQcMKm2Ke9U7mcDdgvxCubnempeI.0xHhwxqXXn0NvvMsNlzoYFmZdod0qbTGUj7oR12L6Zh2pxqM3cu.fWInec4rxbX27hn9L5py+EOv7tWUuBpKy7iUmDC9S6jFxqhYf9ThlflBslTCIzjHII05.VnKovMinerK0iRqXUhM0QlfPaWXyzArbTUCABcKDRo6LHsCZGOC3pr5tUcUeEiRCdWKbZkIWS8i1QF6QqmR8Xv1PTuR8KDfWnkmOmejEnQEjPJhlAXAZYA.F.lpphGjcNlevIm010rnS.wgxf6QhpAyrGOTCfxVpVD0qxzZKUoZaPKl5vOSn4hdTsLqCaTMBLGHDq4AHgtYUG+yRNrjEgMB0g.bDPwKU2Jz.3HVOR26hHQNB24Rj1SevH.UoK3MrRfjYPaEwaX4+PhcMZgB3.hfLEf5kCtEHfqa9kZeBfwoGDYk6tFz81fRfstpMiPK.jH5Rn.lIIfGqhEfvUv1u15SsH7K.H6oIQYbQ0fn7.Du44mBv4J.UDfeO";
	}
};
}

