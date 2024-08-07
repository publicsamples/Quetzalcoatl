namespace project
{

struct xfade4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "xfade4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "3391.nT6K8CVcl2ZZ.ndU3+.K.6Jad78ewVnZDS0BYz1qTXixyAZFsG+OlqPXRlKtAEEX.EfZOT3c7iJYpFo.A7O.hCPFzqFvNztbICUYBUuYbM+3vYCk47+GqlAHQVTuVK3GZIPnjKhTqhi0phAWoCopKVMjEC.UTUf3HONNo8209CsdzFLGh.m50k8RK6V8fQ0bYqtTKQTVLTTTvbq0WJH6UDEsNrBUcsDggqzKfizXI8HJFQVTLtpvzfjEKKFDTPgXtM6akUnLlhTDTVPbEHRsVVCRUPTKxvp2JHJF8BNrenpYYzPcvf1UE8CGKX0qJ58xxgGfT6ykdQGX1KGpCXoVkxZgjTkyU0pJy0DntpgxDkoMYUQ0jQgPyxDKQpcYqxvpXzZ9gTiS0k8SnNrrWvg0xhh1WoncFwSjZUDAVpoAlkia0hvD4CH7lA7dmOgeSv2LN+QafnGwP1X.KJGLxhPuIiL98MthKirGsVq4.IxBN.M7bt2ykR+wDYsrW5LR.XU1gObtUbjsIiaGaFqAGqUFajip5vOzN3BLG6ETcx3yam2ut62yxiMPziEfkjgU6zQDC5fVUgaohwo5RuY3IWqUFXyQ3F5IMHYwyU0UjEiQ.VkhVw1PuTpM2q5FUNh1mn5tL2XNwDjqvHOdr2MWQgtpXA3tzEn7AuKlXhKcrXYBaXA53mDUkhpAsdALDoLMzKshQUqPfrWZsQUpqHPYAswhlg0xCCgD8cCGN.PllZ94OHb5v9aJ+6csDQ6TqfAPqAWfoZkC4c+g6NGbZxiwHDF8teOnDxV1N6t6u2aNmP36MmOCzd6sC4cOh6t6t6t6t69+7++CgPmy4ty4dutc2+uk8SVE6iF1g+eu2y4bu268d++9WJe3b+Giw5UUl8hyA4++c2ct+emqe2gP2aJNIb2opXTQXHCSoa1cmSR2R3An6eRbRKwTKwA.2cFxslUo.+fCSyoapmbQlSt9keLNEc2eBH03npQloIQjjb3AWUTOy4DB8KT.GVIPQoBpRSFdRC6dZ98TGA2vVKDHJET.FsdUIAFhDLAABKvGZCU8y0ZAkwGnAorEuG53tDkUQRUyDcUAF9dm2SMkoLBeuy6IdXHnrXpdn2LbkMvtHIj0JgIvVBFEtUkBclnLP3Tqv4tm+vVB6HLN6IJsFWJh3pTVL1NR3Z+jodMA20aTUgzFBTUCKApghmEvvP9IMvz3rpXvr+nwAKiC7C3Idq2HxygSeK+GD9y0etuCYFywU7O1Om6OBPc4bkn7phhAxCmxHz89VkVMTGZ.0+zcYD5O+kv8sHhzN98lyYLFmllyoV.Nmy8PJcSIfPnCwc2coT59bNkx4+t+HFeQYGgNXL1SCP5++Nj2c2cOFiNoTFiR261gAPnOnNs81xTjPBTXH.TPBLkU...CM33zT8b4H6vz.hBTJ.Pw.G.PPn..D.VHXv.GA3f.....B.EGB.BDGEdOKQj0C.2ygq6RTDAGBT+AAoo9axlOnKXIbcXcvOpqwpaFFUWJsQijQdHMRixynY5ZaICDOQRFWfEHYHIqhhQDqkgZ2as2iMSNhcaJ8hoQwYC+rcKOkDVNBYiuVOOV3Zzh1z1ZLbjwLj2rYM97vk09PQvC62WuZ2GzMbg0Rnroaxq3pqD7ZIBXb12omR7EzXZocNsDnoZd3BeODbwdV1o39ehVGCRwxEil3WoPHKSmBaKTaGNecJfw2K2icytE4Cpk0gH+U0gLyI.kuMHeLVc8XXFZIBLhts77xDd.DN5sKeuBDWsMQM7XsBomdcVi36mohkazbFfKbjZgvxvAATQV2RFeIXFTRImABUWozxXqyUJpND1ZnFklncfWTvgkjJ1wBswUcCru2W1oDZb38j0IbbFrVlcFyO9GD8Mw73I7NDWiJWJC.0ZSoa3Qp5nk1PQEnGR6OzRZGtY.Do+cYnwTDOXBkd7tdcO2DQCwvxr5V7KZBSvJu7Oe8pu7wC34MGYMtBIjtDY5cuC+3pVryGOzt5taKr2mrPDInIQDDniJwZd3wgnxcVFvBQNRkPFuhSEabvw9dV1pXfXPxd9yN1189QneoKLsFTPt3nXzV+zB9p8rA6lcOd+dxou22gA2D5bE.4TFLh1TUF1Sd6EJDklZZ7wSWgf48Q02gTOCOqZjRoG+GhhHfj.NAE6AwF5fPGTQzXsee7pL3qCfhjw94Zs5baJCobgd2Q.jeqtaSEFLrPwlU5qg.7bbRd6eYte5bMTSvSjy5BI2HtHOfnZUS4WIP7XrqHyCXJWr8dhXCZ.5.Eb3p9lwXQCah0xC0HODZ+8xzPlMkiKyhsihuHfDRvwmL7Dvz3bT0LYTfkEHL3GIoZ4eDvAIEBc6ntbiLfzvyy9e2iiwmwM8EPrQZWJbYHcKLydAFYAVa9yy6GOD8e80QLLJo11YTJH3LNLIjMLDhjwL6tBIDWGA8Ejhm76ELa1fRgTnengOBH0Z+R.NFKQpzbJg0AojDDcUOSt.QgWWOBZvcgljXwvLb8PoAfYyHUyuRakoDgqcH8EKw.cYLksIifkffJfhRXBpKbS2HVJTzm0YdnLj5A+sKpkP8IB8IvGpqkPQKkfZIKA76.abFuEAJn2ErGAU.lFGg.D3flU3oTQQNRsdCfnNUcpQJiWBx3BvMJhzHivoLHChAYLr1JYgKL46eIXmlLf4M3ngeUWVWi2wgXumvTnaPPM.bBFpMgMdHhrQskekfQi0plLNfIDKi1GKj6nUXvuIg34L8kD62x4ysuIisqyufZx.7j79NAD1CxM9.NQqZKej.QGKrqf8HyCHAKCbIgSGXCw5Xuw7IdHWIw50qe7V0j0Kisy8EY+ag0imFNvuu.Ut.9ufslcTgTXFEq1nep.xpMhTcViwtLS6lqgLjQsH628FjnztDidEWZRcBbcua6uVkwWk1HA6MmCqoe8Mo9.lm8Z23DIp8rN9OeClaJt8nOlWJtQhmpXqJBEVgseV.hCkKdzVBn198bbjIW29kGCQk3dPtfgJFxeOo6EUeRxgGe2Sk6B38NBZuu8+SABx8Dq32qb7q8h89AhdC3q4zEQ.whHdJJR66oocOb6tF616uRgwg2mfRZjo288RA2g6cUvQ3dMQsGYae0ca825oB4vXT2ASt4BD0nBmLnmJLDnTnwPrxTxzGIYwPDoCV8l2RsuY+iQYI5yCLkMrFAF+NQJz6uWdEZQONe.gElseqqmFS3hXX.9BN2zNFae6tcFz0QATWkEiE3VY5bDQPqV3lCKieWfBmFep+l7jlmT.a7JGSzHr35w.1TvqEsR6ddEz6Ky.F1HiHyPMUWJyJ.SatFIdj+YA.UIPpvD00J24rE2wJxFpsK88FQiupv+af4ECXTjcoLA9LSOov4ZrWp3SbiO1gghv2jvA4SvPjbsY.7PY+kjToYM9673kTFZTVSzqTO7pl.gTxA7lgPAY7HBDHCDXjDxbePrr.8DRTlgnTFXa4K2IRXdw03AtYHIllzB1cPdL7GTVqebgNXQN2p+gPPAkHKMMycqWKV02QNdd9qb6wAYp.Qjm6zMd+OjDOVmIYdftouct4sBo4dMyjRyXUY3zXGrPAUFExH3mCQYKfyDNJiuS22b00lnhFM055sMs3XcUAR5zneasbnGdbrtoC3T8U8+fz5ulcCAyAcRYDF8BF2JYn0eJLCI6zJaMVyoAijJ3I5h2VCXp+btqisRVBLSMvDL296KPBhQUM0HDdLbA5LVV2VCODLULyQ.6G3.rGqxtqFK8t+B17VM3MRfHjIwsX2Uq9.dor8nJN3KO.CHoZLcovXHYKOIlCN29FyFSrlhVrim3xDNYUlQeMReSpu4n+LivhFfZ4LGsRrG6Upblc7EwDXXT652EOzu2OOGgMifDLp3iC.k8j.9PfuFpijAci4fbOKjFXQzRu26EeRHMtPqFr3JZsduHzLG59R7LS.8xwDkjYF.MwRQ4WdmThCQPxp7z+MHj.RAMfw5oQl6KPKWVpoHL1.jkjuQSmP76B+ihHHsvOrKnC8pW8IUZayxP5V5Gge3i5TsByaaCQNDJP.Ul93SCECP8cc.r95cv9aYPoP.HJsjxVnI7c3j75D+Na7FxGM.Z732ipN36FD.f.MdnOTyhrlhL1qBHUr4REJBAPgbTX3I8LIZ1RAK0mf3ux7PSX.L4UY.Densg.i5ZH.LFrTn1ds2wGvDJgZYWMg5Phnn3Plu8zEhGWz4slystD4I7twVGeLmWK1TOFug53H+OPZO3BhJA5zxJtBHUb8nOheFkpcxsXbGYfsDhhuEPCyRbvgO2ii8rKW+9.cW+7LC.uasBkhPbqpJnp+aUhTGU7Ekf98194qq+..5Zfx7kttTDOTx7iVQ2ZbVkQXwbea3TcJ4V3Ki.d+P4heyefojIph3JBNFcIGg7pT+VfMuS4bmX2xfbzRU+PT17fhHuIk7zyauG6rHSXZ1zvhhsYv9p.dPbyQXj.L8vEDwD8IdTAUpFw4il9MUWxjXBvEWDRwois2zCUJQvo2yoYl9ywmnQfF02055JnvL5LL9O+.";
	}
};
}

