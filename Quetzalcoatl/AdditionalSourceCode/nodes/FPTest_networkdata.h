namespace project
{

struct FPTest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "FPTest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "567.nT6K8ClmDzVD.XMVRcBzTTM.TnIUHGZ6tS8m8m5snZP3ps.FaOh.gi6gfq0C.A7xv6poe+iQ.PD.IAv70z7rNJZOWVvuk5Y68Btvq8jcqN7Me4ZB30+7lw60VhPAds8R0v+FsDdQsWOYc0q0masloyZuFVZfC7ZK1DvqGAe+j+LBvFJfjyqZ3q+spugkVQ40UZNj7XMPCve9wbra03uyqYe7UZHvCd8by0as2Jd4WDrqg8RydcadqrTuXEZNGyRwZM.dcLflKctkwytEbeMC6VgkGyPWlh850BVP2RJHIjvHijljjXBCUCPRQR4zkHnoHoH0DzmejnTRJiTQxnzANuw1vnDTBsS1m6HIgUjAsL6X27VloKXvPEeHJ5x9a46kCLgXb.HJe1w.VoZjKGDKHBPT5KZOmIs5iOdGYTdRlW4clXBO5fCSfP7l+b9ffcQKi.x8S6FsfgZb4NCMCo.DBHPJhADPHDKWMHWLQjXHRBhoYREKkpnxpPgNBRBIfjYF9e7hzdaQHYTCuCrCJBeyu8KFLTmFJiWmwbeYNpvQB0oqTBYYcTL3zzvP6IQD68Mt4GX+h2goor49Q8.iMR4D2LXw9XC9FDCthIxeIy.aj.v1pKoWjgNSPLGawrvADwX.zSnneKpejUaDkoJ5icsHELs2czOifAP3VseIctUKMnLwouYBNr+2lRopX2QPFAjFGGtb8fJLo8gOoFNGZD3LKLX4RO2duHRFYvnetBgGTjN9JEpVzsWE";
	}
};
}

