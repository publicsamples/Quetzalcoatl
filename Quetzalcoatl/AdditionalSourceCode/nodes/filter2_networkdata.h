namespace project
{

struct filter2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "filter2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "131.nT6K8CRlUO..xhDGc.VPaCvOxrZI8+psXlDHr1yF37eGRDx2kIhTRnjO++wZqAjbh7+mlrGAvqPG7I56kKMHtikJqDqNV1tcgHfWoSjFd6Up3fWS1CDuJoRJj.7tk8XkwKfN3WL2przzVDls0NbCr1MVCz.7IVbvC.uLsdT..X9IGhB";
	}
};
}

