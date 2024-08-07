namespace project
{

struct pan_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "531.nT6K8CVADzDD.XOFPYB7Rha.fZklgk0ybgN+ZqYpqprKt6xO8vuE8DxSjMCwP2rDqNLkBLD.EAvP.fvpXl8zF4Oq5IBXU25srqWEc3iJZgUzuvxnzF70Xf0UnOMVfUi+CS5YnNFfUqdwGy0F3Oo4gvGzXewRPgWsC4qY5VR7eyJOF+HjfBjU2ruozud4DjKRTCRPSfhXCVUl8vOhmKw2L6k7BpC2nqz.1a7vK7AJFj0yzVrbLr9ZCDJlpGoGe8L9Ub.67wi5xmTNvp5lclel8fiA1AxtOWXVbvGnr.NO5JLGeUBXUM1SLK8omok8jJ6KNXBV0hxzuHaLZXl0WQUmypdFryPC5zw7KXCTnKwGl4+Yn3BbMIRQSjjhzbsH7.NPNFnPpEwEMIRhjlDHHnnmF3DVUi2Ak5bv4ZRQtlSgVa.G.db4WwEDe8E1AlcQUAZD0LiwnTzfAHfvVN.X.PLzwCfR6Afe.d3GFJMbrlErvyBDfLHw.PAQVcArr60jyrIC.6fKSkQOZ7.FAHGDCHC.eWFWuctjM98JqEsO4geEdYeHBzaXcEX1zG6lrQpnPJNpdrSapp9vaY+TmADKDwRpIatiYOVxAFXOXMRUntOSbIQt6ocnYc1AN1xIcsA1ttMNH6PzkgNuQEF.Gou7mgdFPSny53w+JGnYy4zZc3eNnZP3rG0GtY3FP0UyDVA6mGPE.S+.";
	}
};
}

