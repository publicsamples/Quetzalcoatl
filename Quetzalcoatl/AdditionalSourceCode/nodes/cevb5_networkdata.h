namespace project
{

struct cevb5_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "cevb5";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "297.nT6K8CVRAzOB.H8SxLBLKha.aikoEYUeVsjjjZ.nMbV5uQNX6pDSMofv.mUY7UaLkpKOGw+pC12iYPdNxBfFGswY4A9QarlD9jX0khY+cDdxQ56wOmumlrBbr54OpxH0vZsZWE4GpzguqkR2wZwjE9yVhOiTVkYgfFLFvn.FMVKVcV4Q2AaRB+JetFP6nD6VHxRdbZEPhUUp94PHVssTV80TTrjIHnRHCwwlsDxuzcKAVExyQSl963DTVseNztZi0XMoCol8CkQpg1sTrZiChUYX5N7MTDBH..D.jJlGlIRAGyFHD85mffyTB7SGdXtL+XUha3.1PYSeohEHzER2.HGLCwm5.RriHtAD7Jgg8aW9BIab67w5pkN6ANjPb02K3vxDFYVGYUxC";
	}
};
}

