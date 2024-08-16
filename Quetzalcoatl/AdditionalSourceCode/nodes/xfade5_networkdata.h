namespace project
{

struct xfade5_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "xfade5";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "2857.nT6K8C1zP1OV.nkRz3PK.6phF78WwQlP1gVrHqzjuNPICmwCmX0zvjUteJaKUPPgVJoECP5eaarO+DY.ZCP2.bM.PHPNa00pVglBlNrYbM6hAfkZuZHwVRxC82CzJ7OavUfbzJppXX2Kct1AO0fcs4o0F8hgRmnaOOut4sIbcXkYyVaXZJNCZHObcD+yDyl0rBXVLM.Yw5hgXdk0sixyVqLsdBTAn2qlxCHmSqAn507BMbMWul3IFbb8PqZZyrNZfCyN8TYAWwryL1spG.jySdhQG3atZ9fFxUo2KffpUXUKaFLIPwpYZaYbQV1oFsYDbVh5HPNrqUCWqfyaGfbUVrqmrNrtXvw0xZBWrRmb9zRfbTTQC4z.e4HWuHf1lLxbtZPzn5ZkwloOVN8C9CtP2RNCpvIo3ygOO5tGiVh8AjdRFningqb3r0fNlVJdVp3JadlyzRxWqLRugzM3RZ.xRGLad6h6DHgqzYEuYlmzMYr5F0t.9ShJ7B0FTRDIaJ7oSmadSdKCy1B38fftHmfPDCIj3BGKVjvFVjvNBQqTpCbNC5GPZZl4IEepVYW2KN2mJEqB58Zi0LiqUmHbOuopCvinN9hRI0S5uO4iwr01jSkhF.NGfAlpUFSLGzUbWtjAalrZNCz6XU0lITT++3ZFWaWTyO3QjRnGATwrZ2KP3i+++8dP3+OD5+6IkumOAFw68nU7bCCY5It2uWEHLh6Q7Bf6uDIIdDQdDH.duW+HW0pSnenRDEELxifPnhf9O8RRQRu26I.jiipFYhj.ABpBDvryNTTTR4CiEvw0B5j5kUSGLalVhKcOh58Hu.sKctrq4DV.dVwrVzPnfnGRoA9rMzpm78do0HngoImjIGp7n2Lf3CeR5XjLRIQ8e1.g+oer4.VypJnUguICsN9tlBLCMGbNmCdscQGfFhPXL9lldOd6ZcuH.bsqPqTq6C7TksbDwG3.w1znL8lnUsMLJzx3CedjOgZRRFe3ykzogfdwT6LyYZJ3KY2qERjdD7DOq5DbssLOppT.ev36k9jzkjRTdzDMxS.AVoWLWNVjudxTwjvC5aXoX5lcU0zQjZlHZAL8iORCrFX+bvUgyTogPK447MfDexn2m9HDuHz8jeY2XXS48RdD9dQBPwdMEoIL6DyiGF+1Uy5Pyk+9HfuihFDG1w3+8++KkRHD9dPHLFc+A++stdzpXOZ5J+GiwHDBiwXLF+O9+zjCP3+RRRwflgpXC1Pz.i.D.B..IHnF..HRhRPPDyjAxACDHD.ECI.EEB.E.D.D.HAHD.....hAHv.PFKSgzL.PODWlon.0rHzow.HhFtEV.w+zlHaT.P3ePONb321.M.7ccArQ7LM.L9L3STynsf2qWwCIlfVJJCEeKiKYpNFgtVE27d538X9o01MQYL+iM+NVF8P0tbSwlcjHaHk01GCWy1z9AassJSJYfltzLF3zL6GJYdA8arM6N8dlWHgqvlM2RhSVoxxj3F41QXSOCtUnwgQvsSMoBZdtRhX26cgdry7x1SMbLF9qrQU6qzRoIWI2XKNojYdDdBFlkn8X4BQTJwg+HqsWKwZ4CnkPc04.d38Dmqki0UAHXjfpoQnIkR3NQqeXBA4kSL3Dd7wJ7E8TZTAXufgbhmGYq08OoXBH.UBNKJrYSCOgXXC6uKpxRzORdZpOBKL7lfPSYBVLvelIQFBf6aDX1.5qLvUpJmKMpfqGejUUW0KHHdc+yEj1OyUZqKnJRWz9TUjUtfGAiGOkGjcvAcEAgzCOQGUMO3YU7lq9n5ThRgozvjqOrwANQ2dbWCvaGqYpknl0YMicQe.JQUKpgoqzppglBM3ITyqXgDYfnnDCjZS7FAN8alOEmAcrZwfuf5tgEtKlu5Jw.0U8jxcqrbadzozEZeh3LS4qGUKPD8IwbXZBbHrVlPA7jKPZzNXznALNWF4JoLo5MrRSvNUhFLuAYD9yUYMlLHmF58bbfJMBJDMdRBNWL1fFbhNVMMOQ.wMlGp2yIPeneo8YOg2gFPQlcob5JLyPw9Ck3qxAZhCsKUu.gIxnUmO+IzCsAfMtAAHIUqCO2vzwlzqf8QG4PbvEyddRdGNAf5XuuS1o3bT30e85MtWa.KqEneVUj8KJbzbFMvieuzUtfA+BSlUYEpABnHnFGuaXMoomgcVS.tLSucrmC.QnXYO1VOZrZi.UREusCxOvgjtsOzc1ozAnPXOtYiSqe8ETrrydqEU0CPShZ+Ei4NWdYQJt8rOlO32HHlpHbDQcTgsmZECGgKdQKws19GHw4Gtt8nGiMm39kdk+cikb3mz817Eh0HIc2O9rFNuGLj8dI+uIHHtFKU76IwuJXq2yivt.9xitaBD6H0hM5Re+dIwaBbWar89OHz0v6UEgMRF6dtKT4v8F1Frpu.8ZueMtX2F8v5sUbXgziPb2beKsFzSFFoBKlGUngPqbXRUQtGYP4zYIiz2BvZdFoJGmddbpaPqAFr4hj0+mOrYTTGMCvXAX45ZE1H2IhREfu.+jzjAQt61IPWQgojsrXXxsXlCWMzjCsLBPlksK+zoQopuWlkoGhvNe4veivQqmWZZiqHcs+7BKDwvryHhnp8Op3KEHnJMFdimVlIFXPsvJI.2oN6.ZuBJR6j5XawyWU43UpdAzS7TJg0j6jQK0KzPB+l.8tS52aAiQ5CrEjOoc7Zu3gvu1JS2T5OmqrLsZJ6J+dJtvXEZahy3TKFV4NFM2LJTfqiF3DHKBLjXx4LHvIDuvD3YTvpYtjqRjU73k4U5YHBRSKyjOHqHjUW1qMtuFrGb5p+QDFkGBQQvLxX8FNk7.eFGVRq7zvgmm8HxWFZFurmKVAjqh2qazfZRW.ugH719zzhyzn1KVACuy1wBE7tVjuYygNeCJN0VW5aUeY7h5IUzUCFqXmZOiElJSpAi9cVq9T3mlLSrgy319MFh9McSPYd3beSwajIhqfi5+Wljo7kB8jYUj1TNKPv98WrAVGG8bIMzTdJqGH+zngjNhYUFtuK+BpzpEHLBWzG.fhkqfUihXZAOGQtuZCXWi3nt4nEA97pmV60PYAO0L4IH2Uzfgvvn9QUhxWLFLfAUiI5.SCCaobhIt4ZqLavx0DhmcDDBgvoixzDtlAbB7LG7rYpB5n1xLisUqdrrqR+cbyxwCfTT7coF9kPyyAGYOSniamFJP1sZ9.4xDpc0C5L4HcpJjT3HZhldlH9rGZH7qF3XEvtFzIZUz2Z4fCPRjGfaVy.ntKjz.XPARb7c0a3FkXgKFPJXAxfDmr28YhTtLwB.zdZoK4AHLD8G3G+iRcfuZWBB0dpVu5BPV1K7k9pMrG6C6FmEJfiaCMhdcQsst4bDmvKV3FMyEJWnOP0EFgj966WU.ssdDAVzKz.wI4JH5fI2MjCJPV7Xzi5erKOEn0CM1HhUQKnnbxXAYNdyZmpTAnK.AfKjg2k2.sYplrz1jve5oC0QfEZRYnA9DlgfVboIf1BqRzjdY33iCWgC8lcsL0MIh6kfDi2zUJWL9Ntdtcb6sV6ll.3vV.GyazBF0KAeOSPqO6mNg9lnG89hm4v5tftFhdzi+a7DX5DEfhYDh.tmGtkHPlNYLGbA3cS2GE0LIqp4auCB5Jtjavi8+lxlsRSoIopmAVE48YCVIR3LFnbI0YPpAt2r20LfBChweAngXGYDbv.c7fwbkmDUCwp8fpLi1DuOWMvU4vLruX9RdbMj4H3y148mBWKfwRCu.6crWXxKpWdNvHLH.uX3oQ5aJwFkc4HDidbO2SeAY8G3.jXSzImwGcPktHmJemVS64ZWKD3U0c4AefKoU1m+zC.";
	}
};
}
