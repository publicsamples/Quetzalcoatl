namespace project
{

struct vec2b_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec2b";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "320.nT6K8CVWATaB.XZj3LBHqhS.+SEapYQ9jXDYGBvjTXq8SjJ3WUpPAHDIAqpgbfEk94B.t.vK..6nzh.Sdl0Px7JTl7RsWOU4hqiXnctFe0rZVutQA4HWhiDaQSj+AhI+BvlgHCYrpgJAmcRVIEbqj1MQE.Q9SwrFxg7KkIOion1JWN3u1NI0.4WaiuVRGH+TbitDtJV+32whhHOW41H+0snD+dsiGnC4ujsHjqzvHl7KXrVEvvYgiAZ.4gUsqczL40xUDWJcrpQxXayTbon.7.8GHEMrO9pYo5q8.QdMAjiLkEtQmwVUyyfh7D3lvF.Hf.BQ.QpZ6XlHENLafTzaeKBJSIvOcng4xriUwtg.XyhblLDqU3qkrCOL3lFhgbXPVHnq3dy81Vg7Nts+bEzbG3.GR3u5SDbnLwP2bLxh6D.";
	}
};
}

