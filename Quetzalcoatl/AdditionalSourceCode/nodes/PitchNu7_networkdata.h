namespace project
{

struct PitchNu7_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "PitchNu7";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "3843.nT6K8CpxQD..8dG.Z1G4T3B.SNw.7+++q+YPqVrsCzFVztMK8YXBUwPLSpQjYlYl4TrR+67++c2Kzh7SDZ+CdF.SAPP.X7PRWnvIpLkIZDoLcvBGE66iO5ntFfiJyFIKRSPU.FfdX44CIKgrLvBiWBBr3NOUJJUldl5XIYRxRGKAfhJcLRzTG7stXUwIomDBlJSajxrdfmIB5IJiGOSOPdLgIhDQKEf3TEKingD+FfX7BDJ0YhPBQZxioMifox5.npfxfREgBlmLe.kAJQXvHMgonPx77ALRUldrrARhCk5ldtHMsIBKLNS7vgZ4nh1X4IDXpvA.bTNNJkBjIQ+CIpvAK.xFhXhOYJBerwGZOjYDhXiNjSfsbAMzgM3.yFSvvjIbfDSb6VovAJBBJ5iKUPcPXA.GkIhfvjgJbTZ9fiiR8L8PASDYwBG0MwhTl7l7HxxGOTVZX2cqUw3J.V.Io.HoKqLbVPEnJWVB..NJklJzjIZJ5xSlmNTBIQ5PcQWd1fxVV3nfhzn4YjSHAkHTljIBSkmILRTVGvQIxzSGNQFoIJOVX4nhfj1fii5VV3nlvrQ5RDrDgAyiHSHxRkQtHMA0DaggiBiTEMYhBgp2rAQnLUoCqLbTTHCV3nFQFoRLEsg.Zpt5GB59tL8LM0z9TaeM0z6VUUUM8t2MyLYl0j4coTY54hTFQnzqtYtYd2a+U0EeUyj+LQjw.wK869Ki+uiWMwy961XhHJ.h14.+h+cGst6tYkwvclMekr6tKypxeFfLybwKTEQbAfKU9PHXpHxjjzkNVZHQxAZd0DkHw6UY83EI3bsD3+kENdz.kkGJgPSF7.AKWsx39nBkpikDNVWnT3kMaXoQEatJ5fXBC.EAYQxB4GSfH0fKtj4QDArjzGDhRuW7R716tcmrqFbBKiTYxxFNVYbPXcghNDzSFF95oQdHv6eYFyDUBMdbhrJvANB.AEg0Ro5QVBP2TSUQMvShE3yECLfLOQVnrj33nzjIBDP1HgS7XYDMUn.dwjnLRTVBHGwSzHKL5kEq6X9XKsbsb+W2WcO8raTaj4K4aW6v.6T20TGG0ZxkUFHDzyZ.Pr6oHJnmdLx3l4t32Hp5cY96amcHh59+ctaX2+angLtnhIh3gF9FZngphneL288HtKyb6ptalphpcHl4gncB39++69u4US7r+eDb3gt6mcY3NF.lwFaWu6es8qua+2UPxIas0Mh+67wG6ryrwF2byepHuZ7OyLaqu7x2g80V+N2LyKetyrxJq91Yt34Xd28GXWjQVwa283isE0UWiMVcCyM2+0CWb80WF4aus2ds0Vd40tDjLxGa76au7ZmFcu6t69ux69OyWjru9pt5ttm48c2HxcpLemu+t1Z6oqp+qYlY5NeOpn1ZqtqId19t6NypxJq2sK9HZpopxs+el+pmmdhJFnbTRt3T2DSEgYyGV5RCKtVQISGJEjDGQg7L0A.blrr4AjHJrJf5T8tdwC8NuDKQzH5Pc7c1qmcJvLCWRtnBMhzbWbW.tJWh5.wnnLfrspLeO1Ytql9hHpnhGdXhIdOZngHh3e+c3g94mgFhgp3hJlHhGZHFsp2opFQl1Ge86OO+b6suSMwkOUM27+Y8x+c2cM4qSTAd2t44d50L+al+cpcM2qut2Y1quqp34ss66n5Zqc5oqp8u6sy95pmtd5omYtiN5d6Wytm44b1Ye944+KhlaNZ1ml8H650W++2l4VycZs0d6Mxld+c3co87yc2c6rZt1ml7s.2YNMy11OTQW0sMFzbyauMypl4Y96MuZl4+cmc1H5c.D9MpSQrAKcjgfQAAD.f.BLKZ.HTjHk3rrXhqxLFn.gDD.j.viAEFX..AACRL.v..EDD....jPAg.H.v..GHnwPAd4WYYmoP4BT9TC2G76zpLdSDNfFcLfym9GlNtoZQABVTn..FagR4qHbAPLRjfO6gvWteBHyNwi7gHXSmNjxDuyauEB97HIGhRoo2lP22oDt3BcqZbP5VSYzcCXSm1V7NE0w2W1qjUSBAYqNjxeSDVfKAU.9+I9Zt+qc8Zdf03fjD3uRSN.tFC82nRCgCg6NHB4WTOP0YpMJv3bEo6cTaedSKAqsB4de01Z3NOmcqFPjFvt7wcuiUsDsMkt2sjCJxyK6aVH3y3JCP26dNsXwQbBA.UQJvb9s.gBQIekA.ikSFcmAgJ6jstHqpATLzK0r2.W3VkRtTxOtqC9uSIvr0ScIv8ZxsDqPoH14jHC+lE9GcZTfipUdwT1Ro7xkvzeVncDDckcZ+BaC++YHsSvIhy3YD.Pf7k2+nJQF0FsbnTGXt.SzG8jPH.HbwxJDpyNAu4J9dCnpMgxD7Gw+WxfYBwsC4yGQhVLBCaRNIkcC4JCmWZM+3oYWlUkgA0vPoJlDqrVFXdMD9gJDgykrkS4KGAVyZrIXBpTzeoAzTbTIufCmVZNYnPWFVhjEAlGnzJXgfSQL9tC1CDBhHOyORdfEphBUJPaD4mXgcUhn9CZS+bba+iRaboP65RDld69JsHQNS814odspP4D5sJeBZzjfiag179gAPYvJJ51IRN1HlWil8nrGtfn6HkmvTGA0n3boDGmjo4G8.RoXRLCJgwBIyb+zzX6nk9ROOGTte.kI3ePzuTdCexMoMnEUCBx4X30hi2oX5KeVhIKUPKrmHDfLuqCxyR8RDzQDFfYN5I0e2OoOGfv8yhgeDExSPDPWOQx0wtdlnOj4OwzN+YLflqYloIHRJ9Oo+RillrB9wMwvIwhXIHByNonhv7othGSelNzgbL8Y95IEyrWROlWoR3H5B4nSrsVdL8QtSgqnqRmVmaw2UqpTGQLWqCCLYlkTOYoPMiuQzDJ9F3em3qMhTQT+zSOoDm9oM6TPQrRmdixyyWG7jE+6VQp4ULLmDfdo2.QsaqMHE.61lAJ0K4NQnZhamNaoHwixbaXrApU3UB6TNl3bcRnHxHvsNwm8R+n5jgsXo3PcJW.1NjM9YLRYkN0JyYwZ7P78QYavQgre4W5GRbPhGP0.GuIUJ22kqqAiauIDG2p0QGZzy8tcLivuRe4blz3myNniNi7agoESkKJ+AGbtahvcUQVFDKsYIaoT9Yc5QwDrvgHMfP1SXWPunWQBfWv8iRxb6lNZNLkKFgWul0ITOWI73Yr2EDoL9kuD5kKyDEe5s4Sz3MdhLBcXGplwEYP+UBSxuRY8NfaoaJoJybCGuZX03Rb5pgp5MNIAgUr3mmPDrFqVs3pGeOY0hZxuo+rsotLWy0X.XEMein1JIjhGVfInx+IlTsoyj+2lM2jBlO3zP0fASJ9ImkGhdBB2hArw0RHtyvPrSR.VrFijgzsi+WPHIggswwy1fst6vPryHUhTQE9vSCawmDNL7jyO7QhtQKCJHDqLrzj3V4PQ8kEMCXEL3hT5.QcffmTN3cTmLB25vgUxKD1dC8iXHMU7MQA.xQM0zkXgiKj1ZXlQumxCAH8.rcYZqUdIAITpK9y0IXZf1ZYBPh9TWMA3SQSF3Fff3Gv0hKo5GnabyFL2HF2SaWJwlxKBZGIhsJtNi8YWyjmLWkZrPNKTy0LgIj8gI1ogkZQj9O4IFdZlofEC.2ods3.ODUET0kJxdnnq3w8I3EssjjpBZVAG5uT8yqt56RHoNQnFc.JjDQeP1h32wGgL4HL7DpSV3lwgInqU9SyljsHaHoiSD9Mz03SVVy08UAnFcpVHvYkD0hPW35TybigdAitkOb+wsn+RrfFyLaj4GOilpI.DdXQsTjCISKhFAPR8uLD0Z+X.lZIrQ1gmECo1RIVYBM51PvJcvAWduJDR7S4vwWmBsab16RkNG3nCwYW8Jtw1HKS1CpvurQhlFXZqbxO.kIbAQAfGItl1xjdnJd2inYZlouxg9RBory.tW1tWgmottJqHwRRYg1nBqYNFUosy9xzXO..d4OdtOXB0w7zX3n3V4M.u39pm7LyRHjvhHtXFx7R332ihs6FS5kbz04WSlrMneEtGM4i78pNhS+HbUygSJ9zhTDXXLFQqefL8kPXAbhn50V2MEyeA+u7UI0m8X9ju3KNNab7RN0IrxHOM70TnZXEqH0VKZRMHSpxwYNqrIZXfO3yPkPBvZln0m6+kPSRnkKGvxUTzyxP.UJa8XeV9Vm1OwvV9twP0gzgPcxhzkbaRcWJszsicQsnkGHhsyWQ.Yv5SxS3bbtYCJE6dtFVP6yoDbPO8BbMVqIl33PiOJzPfxPMC.B+PXsH61cO2dM6rGQb6oWvtmee0yOdi6i4LLzeAYsLZxuJ9yMo3uApoYe1qfjm78LgzYllKCj6hRzHZ8bOrV5sVmK09b124twa7TXpaVW.nQE2ZlKDf0IlLD56gej1AnyXR8vZmqySiy+a11bBIIcUlLFVlmZTAVOjwz3sOQb52+h0ybsXvRxyAjzZ+I4.XxMxhDV7zXt5OOGTer6OjiC4id8P4kij7lgxhXEiHVoRxRtoEiXLUvGy1tg0mK9fP8VM2YYyldRwq189jwAEB5JqbTWagTH+bes8reg0OJxOq6PKsOObkyle4ZOc736Ns4JRic1wf5sJVMqoALqdIJTZMuK9KFwPEUjUKx+3f+WlsUhNCZO+y0sGkHwfVot.cOTKJO+rGt36QsP1ry4B8AndI2h+uXyqA00bK+dgeuFJWxoEmK++9RfJhuEwrJq5rc4YfxsWNPAUb1vNlVaXS.9.rC.HoJdJQnw3d5ERAa1AZxFblZRJJiQdn833vi.tTZ2.lXx0YJNnROPhyj0F70Lcq3Xy9nsUSYXQKMyT3efAjtvgGgLYd1O.9ffLH7fEgFL6a4ux+gFPfjeRRA1XHHLZGoKNxn+hS8sbpAmaNf0dKFqVB0j8uZBPcsNPU0J2.flEajvTieYD1B7qGYmR45G9J1oBVX3IDAmiGsEf.PiwF1wWUaJuSwubGa0Od9y+N1sHRCgfhBts8Coa0reZKN3PXllVTrjuGS9xf+n7TsN2Dmp9fZW+Eo9eKldruPT9KtL9sp1POgm09hjWJthOK5uAmn3ASS5QA3Q+oiHMFyflMR3YBvFDZ1okb1Oru9kdChday15ymvIKvPiSCfM6.Ul1M6Fl+iysftHz6b8I8mVPvOwGdYxzS90Pp8NF++9";
	}
};
}

