namespace project
{

struct vec7_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec7";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "322.nT6K8CFWATbB.Xdz4PBHKaS.OJsVHxt2onJZKIHfBvpykIUjb4MjAHfrXBXLVmgfR+vK.7B.w.vjwIzn205Hp9kyxYsIzG6GkzI4Oaid1K1SVx.aILMD53KXtKK.5ghZzyfrwLcQBzxsf+3fSX1BPdRCorCfP+obsNxA8qsQeyQQwVxfviOdh4HcwGOiMaIP+zjkxH6.UsFx+hKKB8tJHK4w9MYtXre.EcPeF8MkNKsTpQOiFqkAMTvPwAq.5kUMre3PI9lUA7mIWomUNzVicllbkM.nnCE8z.C4Km0twGDD52DR2zUgkrzaMdW8snoihjUfg8AHfHj.Uuc.lIEZKlMPH50OAAkoD3CNzvbY1wpX2P.rYQNeFB0J30R1gmGbqBAQNLHKDvUbm4dXqf7d91grBanCfvgD5a45gAN2ibFey.";
	}
};
}

