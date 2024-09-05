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
		return "534.nT6K8CVADTFD.XNFPYB7Rha.fZklgk0ybgN+ZqYpqprKt6xO8vuE8DxSjMCwP2rDqNLkBLD.EAvP.fvpXl8zF4Oq5IBXU25srqWEc3iJZgUzuvxnzF70Xf0UnOMVfUi+CS5YnNFfUqdwGy0F3Oo4gvGzXewRPgWsC4qY5VR7eyJOF+HjfBjU2ruozud4DjKRTCRPSfhXCVUl8vOhmKw2L6k7BpC2nqz.1a7vK7AJFj0yzVrbLr9ZCDJlpGoGe8L9Ub.67wi5xmTNvp5lclel8fiA1AxtOWXVbvGnr.NO5JLGeUBXUM1SLK8omok8jJ6KNXBV0hxzuHaLZXl0WQUmypdFryPC5zw7KXCftDeXl+mghKv0jHEMQRJRy0hvC3.4XfBoVDWzjHIRZRfffhdZfSXUMdGTpyAmqIE4ZNEZsAb.3wkeEWP70WTGlcQ.WAZPwLiAPEMX.BHrkCE.DScmAnzd.7mEC7vPR5VR7KXWYAZ0KLwfQQQqN.8r40jCsAi.7ASlJSbv3ALGfNRrfPCt6iw5s60rwmWXsb6s3X198o2uQY8fBvawhJahTLvMYlTQQp.T5Xm1R07mOY9jN.vchrlpxf0IsFkZ.BvGrHoEr2MWXgn20osoYI2AZLyktqA1stMNX6PjEhccCI3Ab79vOC7D.lui83g+JmooSI2ZNTOG.MH2rG3C2lbDnb4fBq.3yCTA.de.";
	}
};
}

