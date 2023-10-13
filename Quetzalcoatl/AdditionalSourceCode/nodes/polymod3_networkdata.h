namespace project
{

struct polymod3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "polymod3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "3633.nT6K8CVgU1Sb.nNYXLQKfBYEM70CRGVCbvWIP0o8bo32sjSiViSgHxlr2+YqjjBvTITcurj3earOcDY.wD.IArR.ZY3O9.TCBcs9nUgwc6hwHXK2OQRap55hEhpQPFN+AG7mrENDLbSgm2.YQLRxRjh5NokqSoERABc9HWI3ZrJIPIx479hi9brUmN4MNaf9fUQkwFtS1siqEHprDbNuRjCCx5ZAGVtZaBigku.iLjD4BUskg+jyzLIxMev3r90O1YhbYfxV4Kj5fUsAJmgs73Nww55Q1pCEKQGiD5Vk0GsGb09x.nxW8CRNfiutYezST.mCxT1xCN0Qp9niXhSSRjVFdCecytZDI6YCEVS69ITCbXUWOSRYXrp6FVdpCPjyy1USnr71z8AThbXp7DhhbOqpaGZ2HrgAJeYgEFC654BrU0mq7EtmzS50VhbX4JsLrEbdOIxMUgk87QiHYKKKbPp7UHq7m9gHGFYzQNPxxhrgmPP1caymbViFhJHS2OYnQIhnkvYPDZqJ6Zk0zOzU5J+rJieMNe15ajq6BzUElJaWH..LVEZJLGzXxvUYdn2ME7UUGT4pLrlNymtx.nnrn6p2UBY8oZyBjD5GbFzUlD0wDVHMN4OW3sNyKyEaM8ba84tSgstSZXf3bu9zR77mOwBc+4O2Zq9De7c2+pz9Vn+Vq6XjS5lm5ibuvptZLes9S5IeEafA5TJBUnoRcNaEebQsBAoFaGKdiPjpw1AQTXJJrGWNPqiLlRV4LBHe9FmF.sDJq7C7LsUIhFCBcEgAwVhVRqyHrFyXcw5TsQSCOkyzzSf0tXKLGMFmCjo61lENOFcmJe+qTnCeQvfrw4S2e1n+7AzgpMevaadOuuTYBCZJQtQvTXYDgLoNk9+OALB5bBHW7mMrFliNiyMeU4SFoRGDOpMVsV3yeP6C5wZjRez++njro3cI56DAVkjVcJMJy3Qy64TLggAAgrRqQ3+SY7Ys+6aLNG7id0ep8guIUZiUpPQEU0EmLlSR1EiUowCuWebKPNRPVd6ZYUMokcNNfydvqQw2VBABOhK+KQlHZUpBHHxFZCpdgXkvNvajsQpg8hCc3XCrNn1tH1wtQiPRXCOvNnBAyfUFvrVPAIbCOBoQHMUXgLXoAo3r2vjX7aE3RpU5TFgWdZZxvTUVapxDgS0xO+lRGrJOa470ldBOVwFWTsffFZrtAbV2IKnkAGIbNQPmt9g2Csto3vckdxEnIzSHAJeYFl59wHy+BagTwCluYWgLb+fOYxwisOxZ8.nLurUHUTPH72bN+n.9bc4H+g074ObVqR0nUxQD9QHT5mMEXDAK5IUlxH7c2VoSojFkP36+IbKS46v2GmvH0syYs996Qs0J0FeORmS4CBYLBoQ.+2q+C9uTBaKz5z9Q4TRo1.LkAJqAfm78J7I.Duc6zOL+GD029jw57EeaL9dzZLNTZmTnOmSq0mRuEV6hyilEOKPqm3vOLVtamEnKIS378SoDzYwBm4bMPZTn5KN+VwJktDT4quSkVLNkF4iV.XfxWzXrxdnvtWsF.Tld78ckHqMBeLNbF4SnxWYfdFtSmprMHBICzEZf1D5NgwnsXkiPWAqQDvGJ+3zqSmNoV2wzR9JvHJR9C02yzn7b6K+ys.mPojl.CtNpxMzDglYF....JHfDhPPv.QQYYYkb7IFTPrH.T.XLjLPPLH.HL.XL.BPA.F....JihnPmcUP6HKUoF512t7Ipb5Q+0CBtLa+QXofaH4LEjAtqWNybCfnCiSHAAqNnuUWv9L6.gyxSpzpvJbXKXxfK.igVKX5zUhmkTTQliE3FZqNs4LLbtsf+TTzK2OQWKr1RASd4X4XRA9PfDmg6E1oiMWsOoeZrDtjVRJ7JVSv+RDCeB0hp4lCSWILwTHN6VApMbvmarI5QlJr8lsjhdAkycosBwp7qYu0SG.8wPBmT5CCDBNqFs7yXh.QWP3HpL9lgqwFOEuvNI8phtQ.I8jtdVP+5mPOjMpthvngE4pKnGE3hpCM9nOmINM.Ksy4WP.whbSrcCvB1hWY7mllnwuWNXQMpO7EHOKihHNcTEAa2+XLGHpMKopwaE1S6N0ur44Rj7i45tlrVBaJLDVmOMabAyeWlYEyjrtuq0DswByArKiu05p14L5pTSzSs.r4il.pwPFm6HVcWfPxImbMx.3wxcra337ZQCrPXfAwFykgAViQkS7ApGrwCp0UZiJsRdfTDB35bDBxfv.XI5Lly7VlU9tFU5Ez3Zv8Sp.L.P5hMICQUTRHbU7FAmTKFvngLx6+3Dc2GhamIiJ811Hcz8sAIYPyYJp3s4x1fUZu1i2vlFhpiy1vQfqpDWIXCLg57ldNJ8p5LR0FxrCoVvHL8ThVtREMGhjRPE3PCwGrkRgC94tIs2puA35eiqC36cNadTOCrnC8JyDljmQeRlfZWj0DcrMsXzZEzEdDZnXTz+crmOX5rUkmYZYP5wkuZcb6v0bmE9.TlxRZW8RLVmjNJsRz0ZnDoJEfHjhL8HJgrKgLFQa+ZXatcaP.Nt6JbfBNJdkCBgDJpSFmjDcjuPYaCxacs2.Vp87dVYgiBDc3uV0XhS57v0Vxw2It7Low.iSQFl+kGTobvA5fBNrIp5VkbW.KQ6rsYAwRiiIv1l8kbX8vmDnlXDgr4dGfVPauTCeDMfDfhekHJG+14L.en1uX8jtXeFSRLzUDBxxHx+ctDWPlxa8XcnmT52+pIF0SPciGOhXcc9c0MrGteQNX8siSGDpGvFqSbmXLXr7XX.lQstRaPhncaKaeeINu9XB2uhFMozw.YpfsIR7sG5okPBAGfFArnlsl4A8dKcdgE3EyJP9iYIrW2ebbtLlu.UewfoKx1V0yg7Qqq+Uu3VPa+E1y5YV+xwtR6MwcFkRLpz4WRvQ4XG10KbabRlGDz42lkUQLaeP.LQhbyChTZr5.zVxsT9ou4QJ.quRZK.sujtMGN4g48Ma2W2tg9H7WtMR4Bdr9QMT7Ml0ccZ3uBMcnrm1huwpcZ+qmx5h8vOFsMnjgIFIyZ8T4RMEgIg2bIY8yUAoCddFh1OGOPaEZOTJrZOI4KyT30CXgCx8WiZzubTo69Pzyv.V5Spf6SI0PZVUuJeEFKIHCldVt5f0LICKC3GTOtmPehe4Ofhqvv81ioXKat9McnflZgw+6ONzRM4N.1PU7IepkAmmshplEQ840L0x2S.Jqb3QZOLeVJn+p3tMed.oEODpHmr3n+VdjUQWHbwnJHoafToIf.iuDg2ZmKgVKa0KX2JDhX3gRzdtS3WhWsdHvSZsMV2XJtSjScWtx27RX3louSogkcN.i6zXrLMDOd+iRY1uggeJmvSq4uAk31UMbZd921eUI0m8cKP9I+Dq6XoHIzKR3VZKgHnEZhY5KGYRLgzhyzSIF8xYaULEBEwIM4EkBQUwTIRLubud3W1WfK6rj265JRAuzUfQK9tDad3LgHPQe.9BIOvBl400e8iMYWFiWIUnR4k5WojD34JmnqE+v1Zys3S5UU8x1fyH76nssbsTq7tjrbcwfqdrryUm7bfrMWf2OUzgHRWMXVTQvyQ6cVVUCEIlbU0Zv1699NfvnlYojwJ.RbrMOwoCGhQpytUaP8LruzHesjPG.xA.KpN82EIHiQIJUUkJCeFDYKoeXZnX+1UN+lFeqclkp0ngZrY4ApnsqUxYpSvQw4ARzl.FtLd304Cvi64i5sZfWE+8r1oeTYszWL2yKIXDzAU4+9WIg32W4NNz5hEEh5tootNJB.XyaBrrP.h4Svl8S7oXeM8k7BZ8zvGE5SITnKNsASxIo83WglDmRfS3WBgNxahh9TlWWkLYlcErgwE3vE7XdRGyum2v3E5zseLYW7FEjq8DyclZ+mvQIHZo3Z+kVAAb+rjTg91.sOdIG6P1CBWG4agtZhDIqXzU746BfDjeQU7BDRpvnvXNvWCFhHAVXv9O4MLcY.9EGLz6wVLqTy9csAndhaLD7J3oxJQ4rvkQV25BMKXnz0KD36xA+kjbDOM7d95xG9bgaAFsenRbTkwBP6FvS8ptgS30HH4Pe8c9ZfOnjJHsxERLMJtLZPFh9nVE9ZI8YpeikqIk2uWzOYmjRMdGcn6w8u8JRzBPGuq2Is3Vwolxwdpw1u5egfTtrfRtkztw7VPE4OHkJuk+v+ADPIWO1vHugP8euy5Nn.arFdCrc8.uf+kNj.+2Il7RHfjMQeyfkn6LTXh6kvnoo27wOl93TFEufVPvngxJPr0Tl1JorL.k+epm.xdgFfqYlnUFlhj5TAdbNjnLVyDZqsCVGDJymip1ZKQMfzXI+O0E.pXfDpQCGS2DYTkJgHpHIaj.BNk+Tmn.no3.7Lqmzuq7.ZceG2VEQVmAij+IkA.0h9mjGUYt7hAiXj28QGyh2cedmvChyGyguqfn+eSPpS.ZcU.890Y4C.K.HRQXLf0cJA0q+xFChr+tsBTLGsZ4eL5DQ54eJcIYkZK34vwckBzU00EsXbVmuBGm5DAiDG.AF1aUloGQ4WrjhHNbYXC.Of+g1DHTHeQb4qujZMAxR9v71qvE1y.33T9nTEnCkKU5jst9LgrvIpVO0fB40lC8jdnUZPSgraKDIPIXow3mG+QKAxlv7aWc9I8G1hTgvQAkOFLW+vh03uuFywF9TPeQZvRfsm5Pq.Dlx98SVS.sIDyGKrVK+nKWwIKwR.v7VoQWPpdrgJ3nW7eIz594qK9N3TyOH7ZKqLQOtkMfFuy5DXAqCMcOGGrgmJQra3fvUa2mpyL2pSud3JvXTbkySEL86B57yz8cpr7ktMLOK8saCgvK3l25zXTVYYjynXonpijsVcf5zfbzBWbmeLUZ8.";
	}
};
}

