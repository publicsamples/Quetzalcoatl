namespace project
{

struct vec3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "322.nT6K8CFWATbB.Xdz4PBDKiS.esqc4H6kBRhrBSHhfcDcweBw.i.+ppppupAIQMvNR+vK.7B.w.PjZQnIOyZIY9GmGmGMQ9W2rf7jCoM4oZut5RFWOwP6bO9BJFiBP9Hol7K.aFhrjzPsfCwNJKkBtkR6pnCfH+sXVK4P9GsIOisr1KYN3u1VQ4.4WaiulRIHeUbmx.6.WrNx+BLJh77kam7W2hT760PhjNjOS1hP9RCmZxqngALZ3PgCELTAxCuZWCwoxqEuBbn3ZoiWORFacphqEMfHoGIA0vF4ONOp9ZQPjWS.4HaYg6zYrU07LoHWAtIrt7AHfHj.Uuc.lIEZKlMPH50OAAkoD3CNzvbY1wpX2P.rYQNeFB0J30R1gmGbqBAQNLHKDvUbm4dXqf7d91grBanCfvgD5a45gAN2ibFey.";
	}
};
}

