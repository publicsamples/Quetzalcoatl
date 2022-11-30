namespace project
{

struct testtt_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "testtt";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "552.nT6K8Cl0OTOD.XcUGUB.spa.HsNwZBUWA9ErSA1IRiLIuyb.deOew5+++ozMBgQgR.RY4.fO.rC.O2GcK1fUwdmkMo+VtFVrZe4U1UgDgarZzeSYeQa3EqZ8hNFlMnaIiCgIn++y9YGqxvjEqNgzy7ckTQMNNQPSNOr.qJ0bnufrubQPADnKKP17C.lx96LmzYIiiUoTXV+Ky7AH9H7Ie.CcBvpQt54zgYSAEyBhrigihxwGEFqNIEA8HwQ4GZCDSlW8ZxL5u2piQegcU0w2RHcNnZE6nubJb.pN0ZP2kLsJLAauW1XbokEqFTwqBS+URL0zjjTTDDzyiDINbzHNLirmCRDeXu6YULAMKDkiTD0CETKCRF+XKKS6ha7.BPm0k4DVf8gATtQCE0FnwTVMyLSPQQGD..o.PnwpwMvto6ATI4XxTpOYXaLetuNUrSAYGGEvx3ps.tKrR8TJoixgzoghCoRCkGRkFpGRIMTNPpo2BpFBhTzBcLgXRHOokTcc1LsfdGBEzOCG.JsfbxznYHEBc1wy4va3lR9rzMooA41rgt2uMPGf8oqvYGaucRaawHrsUfULfBn2jA1Nf0SBjfC.Me4IjPTaLS7hBcwWr1+P4C0C5GTdP8fZsxwLqplsALVw9KCStrT4lIzJCyakdKEh.4Xqst8rZa4bPi.Bya65oBDvBcasXYjNIX13WsV09pBM6eitfzhOWNCGPWHf24XtCCvmA72C";
	}
};
}

