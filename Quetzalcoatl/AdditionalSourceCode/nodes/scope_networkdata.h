namespace project
{

struct scope_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "scope";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "458.nT6K8CVzETfC.X+DBYBDKid.MjJYZjFlU1h+CBD6WjyzwPMXZd4xOCWUUckIb8LDWdZYJXC.1.PN.T0C33qqiYqRuU9BJb7aQu3b7yaRi15mgg8cpQwRP9yoeM4kwLL5D9ynU1lgioTQgi4ToPb+KQk8Wpt63VdPC5FN90jdlYzhh5eeLu5Xbad9piM8BWB9FkY.3X1lvwOq2Z8rMI7U0S8mQ+NoAbe62PG.TuXyLdcoTLp1A7IMEEYZBxC9fzM5lYfmdPfQQhjjdRPPPQOGzObLDOGJFh.D9lhfOHAQDO+42Vuk0+.lBcdqYEMZzjr4xLajhecJcd4ya2j9z6BxnRYrxRaAdtZzZ+n5sbvh0NfLfMXlssDnwTCQHBnJPKPPRA.X.PH5rY.zAtypFBnM2.JfCQ.LD0.Wh33FkujgAXCFWKxb7favNHCXLgLF3ZxK3NOfg.OtTvXIfqxRRssXlFRDcaKNBQzHDF2uM1iVM.yEiNcQdcgDRWfqCfIuf6Vqe0NHYUfhZ4xgNydvyHNb7fFvA3QgpgYiS1pBXXcLMfNLAGHabpaLegRTngw3G4ns3qmVV6fsAmQJzbqsRrxE2MA1bPcNfRFfmd.";
	}
};
}

