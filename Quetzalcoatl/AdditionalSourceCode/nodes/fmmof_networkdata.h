namespace project
{

struct fmmof_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "fmmof";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "330.nT6K8ClABTfB.XIT1LBHKaa.OoyQ4jv2zvjYESHDYFsWPPYSL6MEfP3hXKZiyiljArB.t.PK.vO19uFREHwK+JIi2Ozl.hD4UGISrQ0nZdMSx4IXT6bQphDc73PhX7lgmizi8SsqCvsJKDk1VoaVRbf.LPcqBEG1sdjF.JwqNxgDaTDItXIocgLHfO1dAR4AJrsoUCAQWjlHQdpsSvWydH985F5hLr24EZWBhDeX773XfyiSA5hD8ot0MTVBL900+zA4ZspK+5T.PGOXzvBAaTMp9XPRjnpv4mcquRv0ZUMw0ims3afJf.EH5TLOPX.ysy0OXCDhd6SPPYJAeU.TlwwbBJXCCvlKx4yPbsBds7c3wA2dHF5gAwBAeEri8ir7EXNbTi+T.n8NvwbHHSfOCLGVrD4gFWUjUN8.ZS.aigmAfSaMi.Whrv4A";
	}
};
}

