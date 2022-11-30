namespace project
{

struct v10_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v10";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "294.nT6K8CVQATNB.H8ywLBLKha.aikoEYUe1sE9kEDvMjO8CgGRYR50qfBhJVFfOwixTjKOGw+pCzViWSOGYAvQS1ZZMt07sTjU.5tmeUM2IWEr0xCrSxVLnyIglw96Hbjgxt5wORn69nFB8F6hIp6isDOBonYALFvvvvfgAA6BMiU9yarjftuxi6.Y+fvQK7XH9SZCHglIU27GDZxVEMaMEEKYBBIzwSQqXCc7C8nU.MmdFZRz+HNAEM6l+nZxVrEaUnIzcTw9QxVZXWMczfPSFhtCe+zGf.ADADlidG.KDo.X1XMnW+DBNij.UbXg3XVBaGB3ng0X.1JnE5wqk6.LN3+8NlJFGKUXA13hnKRH8yRXdG+1erBZtCbjC4yq1dAGdVzXrwhB";
	}
};
}

