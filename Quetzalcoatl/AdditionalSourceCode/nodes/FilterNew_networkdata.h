namespace project
{

struct FilterNew_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "FilterNew";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "2994.nT6K8CFd7UTW.nOSb5.KvxLaF7w75JCStzBb1N24DsTtbEezsu1eUTTTxo28mc1ApjDZ65vyLvuhcGv3.7M.XCv6xoIMSr1XLpwa9.xB7txGYNgPZUSYKbFNkPUaMFKqcnhp5iCQ5TIMMttazXpJqLJJlvWWYKabG8MyUtZes.QkuPQIg6MJ799IuAIQKjEV01BzEmxGgCo4Q9NtW.Ycy3p5hBQRVYcC2OXt2r+txBKymD8.U9iS4QTqkoPTKVIpg+bsHSi23OW8ECNxdvzb9BQMJbV1EKTBZWUWOSRZ7U0cekmbAD07ruXDRm2S2E3QMLU1hnnljyiD0txUYZbFs2WHpMUck8fExJiAGYKKIZbfsPi2VUKvYHpMAEKD0zPm4XisHfuppvkzZOEBvqwTWNc3Sbej+eo7oz47ex+AfywzDRSYsPZ7UqunWIpoAksxVdNPneDXXkJeO78x+eoTR5Gf9nFvivgCnDD5VMwSBqmp12MFWxNagY9NDWgWhTmqpMnr1QfFScwZM28kRy9BuA1e.Bg.CsX2vBga5O.hs5zIu0rAgcU4.XNirLqLPhADPXgijzEaHMgtLhBSQof1Gg+HJKycemnCrE1mrkVqCL0EEOp7GMV2MYqNdCEXq4AzkO4bZeyO9ShR41BzkCdB2glBv3B1Zy8RANCMKVlPEFL7FCb8kSGj9U5SiSH84fx5OsUIqS.nrRqQ36MkQm09dSfr.orCXcmxHiBMahNnoA3q4T9MPlypzpwNkXllMaN4L+ArJ7GuFXsVGhw4TJcv4hVasBYmgyPYk6bUocJVVWex6asPSWXPR.q4rQl6Pp0ZLFgvnTFiwZERoT5EPoGzcUI0nGxpTkhNkLLvnyvZMZLcwnrwb3T13LrC7JsWqyUkmcN+4cTarZsP26ftDHVG7i0Hk5nu2KJIcBD03.qAl1O+2Yiu6ev4j.IJhA5KowfqpaGE7Lsq3.SqouQcFcRFjUjTn00.G307kQoQgy.c8foLBeu6mXqzYk2SgR9NaLzpzIqMTkuYrBtCEskGX4bERleDsDRdVXG7Yfv7XBOA7Aku37qymNo1+0XKALyohc1CF70EO3uQ0D0L1GbFOxLiDRHbweDcZny.svY3tbFmzXXfAtu.jBeXAd+FPpTomcbAMzsTWOZ6RL5Y+3OqVoYDtAbc0afNNiCmKdHsmvQHqwjz5LJk0OZiAHJR5iSYCHEhwA7H9nN3i2CBe6y5d1m.u2ye7oJSqQMI9pxWMNoTCXcVpzWiLOXdnJ8NODMx.f.P..PP.HfDD.LTfRVfPL7.xBihEA.DAEgigBAfAfD.n.DB....B....kgorhTEi1rOiVlw6Dja15o9G2Tu.7E.igNIcKPaW0H6RPK51J4M5jHuFYjbxajOOw3YLcsAjEx0yPdUeU5wA429mpCpynNVabaBsA0bzbWpabB2KYEUY3qxoIpMpEEoIiSEsr1B8S1ExZwTDJcduIwSoLZex8bfhgtNQV+GHRceFOS.plbHwx5OMFbXbAZmmlF7lnUjmfhFTjhfZYs1XhNjeoAY5HjAwNP1mD7JRoxXd0kJxsf9OfBzcDQqSdoD36I6NlZ6N8W9KqcLOczJec1v008mKbMxnsoZPyBuLPrtswhaG.rzGf6UXp2hBItmxl3B6PE1Hxlyw+ZpVWvewwnOGX4Iv50EFyXIxXy5RsZpnuQ.17Lbp3qw4Go6rpnFurhRNgzMDEVizoBqpC.NaQHFUSy9cL.BH0ekhofTdnd.pCiApOil+4tFRA8QvpDBl9l9DgK7ngg7qjycDnrXR4M73.KOkWmNrgJRsxfbDFv3CLvIa9UrTBuHBDlVn6ZGO3I7CGa0h+Kp8DPR+xXRuscL6T72DaPAx3YIFKBGLlTxycC4qInlu2Og8D86kZoDs3Jqs0n5P2HtuaIXsfTtZN5731Uyyb4vqGGj2PJ7FZfQeZ+DaxVJqmGOKHxLCrjSYFzfMwCntvzUfFnoPulbNH.DhQiMf.5bLsF+bpVQtcO6rCjKA67FfMD3CoJeyuEUnw.Tud1dfO8oXGx2ogiICGCwMNIQSQsC+AdgHSXP4rYUtSujie1rUbC.lYZh.G0wshM+5JyKbhCYCnkjxqOFzJQoioi4V3G1B.lmuo+QF01hNFKKZs2TbKfWTyTgtB6RIf9rO..1r9cAgBhyAJu5HuDqZnXZEUCGt.hM08i2X1t6cBAmfl2sbL9z.DnG1Bz06wfIhrKi32N0eVeWkQApG0cP1NdbtMSllF6w2BGh0egykpFOuNprBteswfz7qZT00mKRo9IcRWLMgBpwjLFQaUKRAexBF.QkbqPXa+yeqhztlrn0lo1Jyebxc8EEWT4fhihbjLFHGw3.O3IjL9bMjDESe0LZ2GcKldemkenuVCd508PLF5bTBt+rflfLf+HJHvsxR.DTK+dsBAgdIvWH5NtbKV6zH6b42+RgKDocalqZKax1WfvzIc0JWRkHOP8gyjCJH0.BjDDwaAtkmrYEQExWCu+NF8m+xeevI6Vp.vBMIrdfAC69EZaW7unZE9c2LnZhFslTtyAAIIk0+4Ug3cMKVJE.cTWlWObbT1gx2mshpZaiBcxA02AAGePfAO0HfcYM4tBYsI1K6SU69KiAqwFfCyVS9wuq8VJqcKFjUNx1sPToXrSi6NcIX2YLoWBL8Tt7KBLg1g0fCu87BoOe0fagugUbYAkQRb9xXO4LlJ9mdQbj4f.+4hyV+RcSvSFu9PtUI0P4xi8usy2O3rtafIZ.NSoJWJrYjPyG7WX3tJ2SGS3y+QXnc3lXRxbz+jekLGWBOo01rtJh+cqw4bFYzDHhSmEpVRH9qXD1biuUw2RVvHDU8P1AzvkfPlhohWj5PQTysicPg.rWJ2zsvwq2CSBxV.OTK.xYTHDfPiDFfb7Oenw.ArXVPGeDcQv55DXNVs67ePfSUFaWLqDxr3pV.1mF0KL8CY+r9KA7+lOgTv.151wrJDQ6c3Tp.ki4+dFFaCveF6mTNgjeyUeHD+ALkarjGL1SVVSdmpTHiKDVEUzAiyTaS24SpWVu.uA1skXADXeQLu6m2lvqRnx0g53Xpl8JU1G4+pvjhBkDdk0iR7lbv18d8wjm5iwIAzlArmKQLa1Sx0qsPAGfdL3ogocntWGVwezOgQfCVOrQ.CPLh2GcCSml5oEkyttk5hgfzCG0obhdKY7dPXXac.NtZ4iIHU.fScaxDwfpW.fv5tRtb6eZ9Rz1ldf+eNbmOOOZxelh12RGqkPRE2BncHv2LCRS6plY+5No52Ti8VfryeCVVIyCiJBs7jXvDtFRlQ+9RJ+4Xpi4wj+YYdoMJiZ4uo7P1.dFxEYlarN7BVRL4sJ9jiwrj1cgSOs3HpW2ekqxrvP.7FZFKQ0IQ6vpBvnY31xEjiPB+QPYqyUiQhRd0HlnSJXy6AXEwoE1osnueqWL31mDU3W.u3NegOsoNMO17.UeJGToAMP79pPEnXirW0VpDSLjL4Hclj.lGVBs..m39c1S3hdHml8YRkB2R1EOEj+G756AjXbro4zLsb9Tkwc9tgEvKBielP9JS1mqwV+i.af2xkBfN0wNWtE1PE1wI4PhQoY5DxwHHp+3yi50M8ADfp7F6yTqfZQZJfCiwqyU.kRkkF.1ANR.JC718lkFEKo4H+6zgVBPlJ0HCWkOlCB.4RSfDIUIvsWw0eEuGHBON6BXpOkQTKANHnkoKFuXFYbwvcYysVdi7BAwVrLlKzJ15UmRHaeZHNJrGTL73rcagveYJ93MoU4dUFX2rfffyUnSvwCDNmOSCOIpCzTbpFUYx5q7ZLVPbCjFoveFLIp0VQnxmd.mM.wWIt1SxSx4W07lWsfIAfS5xPfcpwDExpCFsCxSReUgeMGC5sxdHg1Xp3Xq6ai+WiKXMTHONdtRvBg+ENWhE.aGe9PTZN2AHDR.2SX0SHqOSSENkMIn9bpcpTLWrHZ0mtBpl.EO9yArTfdCRKtZS8Dl3oy8A77.";
	}
};
}
