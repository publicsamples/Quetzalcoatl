namespace project
{

struct xfader_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "xfader";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "273.nT6K8CVkAzCB.H8CxPBHuwI.I.E6iRAZVGOIW0gHei0tVn.MizuhZADP3qXYPJ21R+vU3fFrDZvvfvhsCrKXKlJZMmsXvWC.5U8+WB62zwPX6fxP+kSdhXKhH27QA4GRCD6xPcyFv+B7DoVjKi7jkzhsGISbVBz63gh9Jk2LxSc7YYI0wBNi.WxPsihd1tnGhkx1TUCG9ZQtUjgu1D1t0.8Qy1SUrmt1CK5Yn1Q0yVrEaWnG1OYjiblcQu6A6noJo9gpkjX3QFpIQEKC8NdrnmhXSMYmW.vWP97zErIhIfnMdZyKzRIlx7C0.3YPQUu.KnIGWTDPmpc0U1bLofB2ddUBttcgCBRFpVqmXqK8NBlA";
	}
};
}

