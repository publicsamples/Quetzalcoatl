namespace project
{

struct FMOUT2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "FMOUT2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "413.nT6K8CFyBzIC.XTEFUBDw0MFCH2UjiP2+KzLAASlzAiG7BPJleu1M...veFpBNHnYSo.6.vN.nC.cA7lUiTWne0JBQCu90Kg4043bbc.7Ne4F0uXecCuVx4mQ4h1SY40zXXgUXwDQfngv6CRzv6Fz2R0kDvyijjjDTBB0CvKsxq8N3fMk0JOsQ3Z5aXnEy30vZB.foCX27qWBCuttg2KeaKR4RC6TFyrbn9TFqy2J30J2KgFxiFFywoBf0O1GGwHqywMkQ.fWpW8IQZjZW3DM5lWuhV7hc9xpkOmuCOHACuWjUpS4oTL7FvtU8Mmhd.X+.aJyp+OopE34hlfjlldbO2iy8ZHaD6j64AIAEE4hfPHjiBsA7Zw2nZeK7dtInm6cPGxJJwLf.IABnxtC.tC8.PHB1CCRfHQLfL4WzEWfRVAAfHMiYGJ.2o8EEtl0nggd74AD.FC6XPnRH0MSCQhOt3XBYfqOYN+j3i6SXd.dv.Dvcdw3VkBJf14duzVgYvAy3ML.vdGXz.gJ4mwLl37BrYAfGDgwF7fstz6fYF";
	}
};
}

