namespace project
{

struct MidiVel_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "MidiVel";
	}
	bool isModNode() const override
	{
		return true;
	}
	String getNetworkData() const override
	{
		return "360.nT6K8C1dATuB.XNk.MBLKhS.q60tnHdcBXbjcnATZLyCQXHzRw.Zn.5mnQqwBhN8CXC.0.PM.jORTepdcLRejjeYMjL+hxhxxZQdWyv2BcFqj7QrqiLU05GG5VqwaKDyXmE.4YZRx2vqcHtPB3rT7uPjeoZJzYMPn1bfHeEGe6T+dRnz52.WZo3vk0PPjeYkjmsPnNUYvcrFIR4sNVitNZQP+ZTYdXaSRsiuV713JoO84rVJgHto.0zRf7rln04ZGY9CiKCOEAWyQsQwZm+pHG0sEZEvx5.inJ0QpFLMLdPc9hxxZ4XmD4SEFbbjpeqBVXAJCpz1DjYdarwO3GMynZzPj97VF2N3+vsofhvJCPBH.IzHQnc.vnKzvv7ta3.1vhrDyfX9RSFBTKBTzFpDx.iKAhVA.V37EPQ6aqhKZVn8wwfseX7QZOJ6ijDkG6g.Nxfb3wCmxH3SPdca0ACf2vxVjYs4m7vL";
	}
};
}

