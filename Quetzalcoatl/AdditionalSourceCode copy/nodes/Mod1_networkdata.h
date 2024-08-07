namespace project
{

struct Mod1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "Mod1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "1826.nT6K8CFBoTLN.XC9sdBzTUG.SaXJeS23SP4tHABoBt4Q.yg0kihKodIfWvAYF3cLYQcpH4um.DJ.oBvFNlIkraYl1cygRzeHKop88YMLoWgD5FtG6OzRCwqtgG6IQI6Euvl2HPN2utO6X.fxjaoRravIwuixAH9yeGES2H59g6AAoeiln8pzOaR32qRyd2MGgX+IS2LBeyazK7X+bWNhwsp28y2H6cinq0JQK+Mu2V075fy6+.C05ImRrsU5GfzLZoI2Rr8tUP7GRK4ta3UhcEZ7XCBeEkeNBjYIytvlU3vq8RwyQ6PxAuOvjI0msbUDHmQxctf9BcLFk5bLX5a2bK8moX3UxXZV66d0vu.vT0zGHBGfXSxy4oAD+c5DNwHp8CrVQL1MMSqfj290UwwQ8JYBZ2BnM5GmMGCEJQoGeouU7uww70QwbZ1dOuKEw76AS+v6VyTaH2cit+t5GbuGHdAxLR4TVkbRtvzzjzCvNB0yBWfI7Wse0rMLzbVBpIk0rJiDKi7JyUlnGjlzEnh.9jITR+209g7dY.SMXPtOT2hL.OdtYN4vOupWfDD8+tfqprXYMmYTTVDZCDZx.SSHdfyBCMwvvRJCTGJp53BtMYhzQHo4k+feLYXRUULNPTFAwjQBhNRUbOG2ORmEfavOW0p0PIUvGywKHgOadT7Hd.QNNz8jktEBnlHmBlsOfbDP2mzsV+cOcJcgb3FLplw+2EmMCz9jN2JgvaetnptljUUYXPrJKKoLixRZlYxkcgcMMcgkIQgY4JzTmROoy2Oy9+FkstnpvptpnjpbBtjQ7TXWVSI0TZIkRKKIK2gttIHluVM+xDob3E6OPwc7mqXQbnYJGmr2G5cEpHkQo.VrxlWYxpxrgcxQccgbyoCfGu5m781oQQ032imJNe4CgCo3Aou88.LTaDc6qvsvYuY3UdMH.zV.ANNpgliLxHy..f..B.PjH..hogNXYFffvwPxB.g.yvRQQ.FfgBL.hQ.Q..i..L.Qn1lDpq53+rjzXUh9UfH5AOkuPfCne3OADPZQtbYXEfuXPYvoEjXxAek124BkL8DZWUguoHSf3DlfvIudf.rfw.A8n1qC5EMBOCTVshGGitcMc5zqUHDbwsvkEdVEmFkrVGA0MVHJANM5fJdqQHhiW0LMIzW3HoCPAHSJ.O1ghSpaOgGE.dNoWVTdBNflqHo9opD3O8WMxC7nXFfoBjVXhA3wVJNgKe5gML0qVfEZdWiAZfKRE73PKPLz.znA59IYf.kc.5onxgFFnKv9cxznlqDfgv5mB2+p9bEczVsgblisnPPaWJVyCFTNnqg.F3cxqwNG9.5enQKXj.Zc8qrkVZcpUlrM9ZcvjonuzPkIpRK4HtzHQYCRFi1lfWPEYOKK9vNcfcNJFbqLgEz3PzcFMJcNPrik1RijmJaklfrYpCG3IyPWdibSLu1NOxYP81+QCgNPMpkgLEUFsGps28VdM2clBcrPfCDmnXrM56+0v0XwYRgiacxtKAAzoUASfizQGj4C5hTR6YkdBAYyXXNMqUZNdupMfibqVw44s.lYBlm6l2IJAVBiBTEtOGNnsp.HR79w6N4B8K+6nL9VfzVkIuiPWvB5DJBCX5cCVH7uOwKI7M+SoOZvp85CbfxqsDwDgXVTFmyHkcCNnIJTxx8PlthQ5gBF.qGpLn4OrfL.x9ugdeft3DsmG+xiiIm.3xAPmtnRKmanTjvbx8kUncvIvzpC1touz8NtUxQP7WLT0Uzd7tXpGUA3L53c1hAE9qfWMYjJ17wqjjcvUe0Pws84AoHZO4lgE53xQukgjs.XH.Jr9sTcZl.DPr0QhHlm2pNjK2CmXoY.oHwL8Qiw3yRl.T5k3nQprozD2JLsAlQja3h9j32Jgu6x5djVHg8FdNfd2ZnPXNvFVG8Wx5VzvX87qyJnSI2Go40qdI3ybr25lWv6q6xDb94B2Ug.J8jaTdLnF7LJ.Hm9Xx0s7GMbaMZKJcKWt4KQfMHiKnQorlg7BS.PIXjky0fmS4WZhX9yWPNFgWCJ26xong3.NLjKasDZ+ttEgCcfLlbtr6lFMqfHPmo5OED1Iz8qMaWIfjzuVw.EO6Ywk7eKsV08qCqkCAH80SGfwkd4biOTfhHib67EWq9eFZyQ61lWmnHtVhfOLlVkGUgPhdaiobuPLe+NyklChgwEX.y05VpeFChJ5EEGg.lLta.jLP1y4UA.rbHxRkr5LlLtR+1U9G+EJd1665i0a+57JOBW87uXnqDon3COR.kwAfPGGxLNGbVw5HCGVJ7Bf2nepVhkq7R6COm1DTwGab7715afnC5aBSAFOl+raZD0byV3dt2n+7BgJh049TDRnnrNiWSNYuQpmCrDZynAIabvWEDNEj0mD9nfWk1ZV56wni11n+AscSjRZTJsOwltewp3uq4nCxMGzZ0me5.";
	}
};
}

