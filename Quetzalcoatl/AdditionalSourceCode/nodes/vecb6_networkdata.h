namespace project
{

struct vecb6_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vecb6";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "298.nT6K8CVRATPB.H8ixPBLKha.agIWCCIN1nljjZ.nMbV5uQNnZs5XhfAFTXTAwS0PYJfx7rD+qPXeOlE4YIK.bdTmGlGXHswZRHThUWJl82R3IKouG+d9FxjWfiUOGR0lIJq0pcUjenRG9tVJcGqEUV3O6I9TZY0FFBZTvALLfQi0hUmUdzcvfHgekOWCncbhcLD4IOBYEPhUUp94QHVssVV80TT7jJInRHGwwlsDxuzcKAVMxyRUl96XEVVsedztZi0XMoCol8CsYx0TVJV04AwpMLcG9NZHf..P.PpXdXlHEbLafPzqeBBNSIvOc3g4x7iUItgCXCkM8kJVfPWHcCfbvLDepCHwNh3FPvqDF1uc4KjrwsyGqqV5rG3PBwUeufCKSXjYcjUIO.";
	}
};
}

