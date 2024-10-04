namespace project
{

struct pan8_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan8";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "474.nT6K8CFGDTnC.X7TBcB.sia.OMJWGEwf1zHirDrzUOOn8HItO9yps3+q4jIQGVFvCxsnTJPM.bC.1.Pjiy2BwvB5RhFmRuN+qt.dAU8Mgne8xcfAuQ3qg4UZpcv67kbznm0Z5acCdufYAuRP+IpQMAIjrRiaOcSDuTnTnRREJKppFBuztO6sHgMk0tm1GDyhvu9j4Q7YX8.cji80OVtEbTy0rScDuvvT9PKP2PJ6oHrWv7nvyz8TlgA2N1rzXMp4Te6CLBp9uFWGgWHlZDi5c7rN3mY6xbO0q3b9V5vxwrjVG.b1PCPEpJqmkjITjdUUsAZxNXSImlfJjb1hUN8i2j2apR0a5E4Ucsu1sPDD5cuo4Pj.0igTfFYqzLyPCPBHQACLB.DDSV2.PctACTxL8sZCjP97xAPyAPhjKybyLDvGRshtX+.GVARfnmjZQl35DEG7aEUfsck.AVskI7CdfkrIT.YyLqyCpbhxTjPs0LoRZGH.nkMrxWsgORK+iqsyl7F5icwVliT7Mc.0TY0SnQnYQWNxFx2GjSES.vZhi4fLKOnK5YQbvVVVr+LlGKK+4lHKfRcQ826QN+wUHvN3cZz+gb7oSD5HxaCP6kQy1vorCuwuyATU.+p.";
	}
};
}

