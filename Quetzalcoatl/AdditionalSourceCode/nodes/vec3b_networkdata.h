namespace project
{

struct vec3b_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec3b";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "297.nT6K8CVRAzOB.H8SxLBLKha.aikoEYUeVnjjjZ.nMbV5uQNXs+ESMofv.mUY7UaLkpKOGw+pC12iYPdNxB.mG04Y4AFRarlDBkX0khY+cDdxR56wumueLYE3X0ygTkYpg0Z0tJxNToCeWKkdi0hIK7msDeJorZyBSCAFvn.FMqEqNq7n2f8PB+JetFP63D6VHxSd7wJfDqpT8yiPrZaor5qonXISPPkPFhiMaIjeo6VBrJjmklL82wInrZ+7nc0FqwZRGRMaG5DiqaXoXUmGDqxvzc36nDBH..D.jJlGlIRAGyFHD85mffyTB7SGdXtL+XUha3.1PYSeohEHzER2.HGLCwm5.RriHtAD7Jgg8aW9BIab67w5pkN6ANjPb02K3vxDFYVGYUxC";
	}
};
}

