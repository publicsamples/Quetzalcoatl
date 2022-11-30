namespace project
{

struct sfz_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "sfz";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "418.nT6K8CVUBTLC.X0UMcB3Rad.HVOUpTF1bamRahATPMTLOhSSD.CYY.IVfQLFCYiJYKNOuLEP.DD.DAvmJm8sl90pV0Hz3OWmJyVuUdFHM9kUNsF+bO2qEnwV0Il8sfgMjFWMspetxnUJQUJ0B2QFXc23KS.owZXqhtOmOFfvvPIcjFO5kVSDowXOcloNkgrzZL6W+xnmdApFg6sIX+LmdcwSmYzErvTNA0DvXurxAfF+ZHMV9XX9UFDr0ziG94hc6dc2MNRiYL6eePt0oXdJVQZRpGXju4CQcKrlaXNbQtJpPiCRnDgRhSRD4XvG7iNXtnghLWfQC0FKd7nanIeoL.mL8PbxDGrUnNudGNVYRrhzDEJO7XfkjZAxpr9Pa71L2ZsSev68h8.wNfHvqKQG.j4WV2nQkiQlSoZCdNXGSOW+MfBHvAffIww.PzAfLo4si7qvmUvPcLBGbjArkfmvvhnxqxjKLaoavh9EKCkZVPJEl+UyLO2Y6OHN4+d.uLd1E9L64+RT7.qZtFG6.P.C4m0uvXAz339D5NUS.focKtsQLC";
	}
};
}

