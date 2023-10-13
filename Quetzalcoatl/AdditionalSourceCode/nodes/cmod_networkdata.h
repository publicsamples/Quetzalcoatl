namespace project
{

struct cmod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "cmod";
	}
	bool isModNode() const override
	{
		return true;
	}
	String getNetworkData() const override
	{
		return "532.nT6K8CVnGTED.Xb0EMBLuMeCEM2IiLDV5UjRuf6+kIPyPBeMle17CERjyNhObNh6TnC.5..O.He8KcFifZi9VxD0eVGQ.p00bITpkogEPsR+UoNJ1E2PsrmzilSPWBEGBgrMOx3E0BQjFpECpS4cRDPDlSJ8GTu6BZOgzeeCkZNDCzoJzbvlUkRUzwIev1r9GbVYB1J.pJ08tXSaIT7nIaSyUq8bxgMhwPcAGToixWjGn0fvbFuIS2O4YwK7NAmuGJAwErVfW1c8czeIHPDYUogVVIePAn1FqSB1TvBTA6AsPZxFn1V.6z8UdoRyZNh8u4FocDqTLWHeujS4D1o+QanKgKfWb73rVOXvwwCmmlFd3fhCil0yZ0zfypYkPkNJEeDrDLFngm5HzHCEjBfXcD.P..HjYlQ2o.n3nRMnTkS2XzFObKcnbD45JyY9oF9MJbt0LpxiGVA8o8saIX2iPbExf4Sfc3YjEbfJ9vCKiHjx2drHG8gyvBGkHx.evQiTWwk.6vru16T41rUUfQXAraMbFy1PB9VpDwXMf.Pf4P7n45r7fLIPfZQKMZ2MJN3mYHwJEvgTbezRW1XLomgczi3AjYxUYNanCfONhI05KSQN83TnsBfNpp7Pn4fCGUSxfmc0xV9kLANbsSAJKBUqbzblBK2VeIhPrFokHWn300Mv7ylEa1gTGUEChyXrz0A5u.77A.";
	}
};
}

