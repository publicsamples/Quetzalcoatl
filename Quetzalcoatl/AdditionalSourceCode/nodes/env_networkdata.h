namespace project
{

struct env_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "env";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "567.nT6K8CVsEzVD.XXVRYB3vpF2FEoQVjaoqmImHNCBRFmIVAAlYIFfRQvXL5aXJ1cz95H+ATD.EAfR.fA30PxGiiacNzYXO2uNi4pEyS30Y4nktqMiEgHfW+Rak2qefbmWWsS78wngN1rZy15nVKZrTpjNS8c+0TlHfWi4Z0j+JQYyS2zrS51cZoL59qkSfq1YF6qU6j7e4FuHCKO0b0czyQiXz36mes3MZQiqheP2Le+M60himeyReDtXYVzcdLLkSMufNnPiAKlyRbAfDAYJRhBZQAqnphn4wb0PJHDJhDbgMlWae9BBBB5CrIVQ60YEOd8.sKeo7yP6gF1f630adYEeeMzfygtHcCOoDyw.PalSx6QyIn6F+4XD9i99WtLu4B7oHppJKBxb4l733SeKZL2U2EwdJtSDnEDqInJqGJHURRpUB+Q2zOySgAP2czQPUSSQdjjBgAZT4FiBbCI..Hfb.I..kZY3ezq0Pax.SmTAtpCXMg1fmTyNs3yAHTxAHQxGQ4lwBh6jTAwAXEPxOwMxDNPQGC3OzBfjEEeDbzqgYSJcu6H7E73.fthNPLmlZP5NnLisinYpE4nYXyBOE.akCimWgmgBFfNjlT+XMIXmQlcbtURKOHfBftFpojVgYI8MSn5uggAu0GdGbvTGjUazAyxo2TZw112xKNzYZxROmUJVHra082sthYAFmujNPi5IfoJE7klTi2Zfl.mw41o6MVHlizzFvFTsuo2957.U5.46A3UA";
	}
};
}

