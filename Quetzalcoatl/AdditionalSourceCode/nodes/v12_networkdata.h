namespace project
{

struct v12_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "v12";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "301.nT6K8CVmAzQB.HyivLBLKha.aikoEYUeVnD9kEDvCjO8CgGx1pY+iHhfiMS8S7sLEz7bD+qJPaMdA44HK.4BnlF3njsXPWzAMWlX+cDNxLxViaPe+HxHvuplGkc0iajP28SMD5JVDSberk3QFKZl3IwyyiyiCAKBMiU9yUrd.cekG2A5mCdJgG6veO1.NnrLIU2bIEMY6hlslhhkLwfD5XHSqXCc7C8oU.Mg7LiIQ+m3CVzratjpIawVrkQSn6nhcizoYgc0bAjhlJDcF9VJm.BPfnSw3AoCL2NW+fMP.50uffyTB9R.GNiieBJ0FBfMJaZWpXAB8B4M.BClk3Sc.I1QD2.BdEVViBBIPSYIvL3gF+w.PacfybHURTytwXmKFVDgbQrkMfgc2XrILC";
	}
};
}

