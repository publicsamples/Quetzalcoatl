namespace project
{

struct Fm_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "Fm";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "2757.nT6K8CF6D1cU.ngTT8PKvBY0Lft3CRMirgixERaqngRkXXVluY+w0rtaxd+m2A9+flMXxVu0UUaeTKkB1Cf3.LN.d9zN7gjBdydBsVH+ZwAG37lLHOXUs.9u0TfcLgYy3PgwzECCaQ9xQlUBX3pr0BDENSKauvYPUzT7P1Ls10tfrrT.qJyDWy4ZsVmKVHcgJvhNWt.gOtTicCbTWJpKmqFzbJ5ItVnKEFFQbsORv4ZMa1dQnqkmKrERbWrvYEv87lqEG6TGwjITWJKb64sCQ8DT3q1R6ZsOQbext46kMypAH3NzburYzdsDWi594i0SHLngUY6X5R1EqxlwvSsDtVGYqFgjgySVLsqcovY3bsKulhqggq9jcoPyaIt1TEFtCOgXg0.DrkUEsKL8DW6BLj3ZdjgAIeyHVpcLkq.4yFN4N3O8DsGEqDcnCc3L9fO3CJiRRRwXsVgQ5Se5+w4O+46Q4Ke4+hwO9wWJVg02kHFgz2qHwd4oa.jYuVextc5.hAgXs77o5hO5xMCO0O7dXudZJzVRCgyIj9u7mtGkt78uG99njzGkf0pCqOk9bJOEFkTu4bce4psLcJJaSQhBecQHU4rqGblFRbsYUJ8Re8iM.bsLPXKrEPXf4zFKKGrEGs.n7fU7AHQ5aSUYaVSWIiszzOjgJMdtYMSui5HdkHtKbfUkAgy5DPytT1a1Fa1RsIic+31S3etxJT8f24uEBDRtJyZg0nsz5n1OitWkwuFmOo5Cx0im6S2eRQ+4SDx1t.cU4PM1QxZ0eRozOoy+gvKdGAyY2OdHBBlvVb17cZHjt85ZYm9fAZSDTTUzM0o3BqT46v2kt6R4EYefPr7Tks.kosDIIhK.Tm5NsCYuvpt5JTZkJUqyIcVoTobFoQIcNiQY0e5KNkRHLBkw3+vOBgQeTReOhJ++9dxUkD5HiwWZ5H5ViLlETD5.77Gj9lP3j31bftYYmnvGL1.QWoSYD9s1hy4SkVSSWgBmoiZs5EnL5HhHIkn9b1Ij.tc.N7R5k2sCklA4ICB2vWZJIeS5DumtRMBc+idu9UH0m9e4QQKAE95q3Qe6kzrXCMsKfPlLXjO3hfQQnCSYzyfAyF7XyX0rfEbAKTAMzFXRKAFfOB4+e994tQCfVyeToX8A6JQXUROnGqQJ8Q++iWjMAduJQN2GwAgSgck3bp6ESawueTcmtYsknCgPXURoOCLc4T5kRIBDisPlvtfxX7FuJ2rGSVNZzP78jP1OXvUTfpX.Spzk+L9O3+O28VaCLbyvzOjc2bspd+832QwmhlxCgSQ9SoKqTI5+hRD4fNBqxxQSIRl8hEvfGfp.i0QzLi.j...DD.frZ..v.oIQoTJzCHENPjL.j.TLnPT.L.X.L.LBL.A.fwHv..D.v3PFkz4.IOex4M4Wds.ZDovkgBOOb0mJLwSwNNbai0Afpfb6jd8WJo84bB70tVaP5wFoTLEakxw+Z3DJWimmXf2nHZvb+E65ZfvXMr7qgLH4kPZPXXPz+iubmzQClkoXF9+L7jkQvZmccNzRDMd9gRb+mluxTnTXmmbLJrrLmqsiXI3kHHl3oTL8pIGkCfx4gHhtVQrMdQl1AotofSg9rX5Fz9AXXP8wyOYq.SNnjM2jE9URfn4d5B+V4sIrpKYRAnk8B3+fewJ72PljHx1AIp5T5xVMSXqspmwFBRupXvePRJ8st1vutKo4fdpYe3hE7rkEOPebqhoMol5sAQRfsEaXac4CWu4JqThEZegDDMPfmvSwyHW3TL2BC83SCNQJBh.iowUdgKCLf+plagjnvnNbmlNTm2t.DW713KnNPbXOVQLX7dampMM4KnuooapCi83SGMOjSYrsZOotJusY0ZClgmaBXg2375MB7ATpYomlE.6HT1AM4P0fQuPMuvt1j7cXJzRlGvjQlOJOnlArEFkbb5lXc3i7Ey4hjYVaItL2OiuN421CiiodAnoCyfWhr+gNrbbZXFTMZ4wDLgxU2VkZwtXREj3W.EktPaVinWDPFj4OFQMgBtHikdAFmyTvJ9oFctKk33BrEdRCcLT8BiX3K.sa1P8w8wIoH9fmtDupdRlRfcyyLAXpcD+ozPuvWsvXE+USxSA0xRDOHXw3K2EZGWbiFKIbXTRzAJyEZDtXC9jMvEfRLPH+CZGipwOXG9+YoqCi9yzuRpK1CZKuFz.lRqzmwUodUCc+JiGarxbkqw3mXo36K8xtEQfk3XmhfHwCNs69P.ukd7OmS6ylPH.TrhtJbTIqIYycwGDxMDrulFy7ELmWIFUYFvjpe9k9gWHYFOOI014ozxxFq7S01s3PnpTdxHSzpvBQF8MVvZNK+.ZDvqF+nC.J.UELJ8LqGIoUjxiyzGrKTKaAA3H+f.XtZqnJpcFgySQD3G74C006FFYcygyBPWXFTi+wTRTsV9ttBFxcQeN3wN6bfxuedfoYNs9.z2Sr1d0CuWrn.vJOxbDTLt6woxPo5nVKAjmXTd9UBbVXf19gB9kBGGexe2WcLSkj8l3aXu0FfFzaXMuWd+xQ83osdO8+JsYxouXgva4q.gHreEk2UWiPf1b.MTumNqzwPICpi76InkbstGVAufNuH2Nh1QWq2EWTCh5I0RKwsjq06gInAvcN5pmPcxs0cXYwJBcFJ61HPG4ZcGbBcrSdsD1R4dcFq2OMon5EHZTmqmjW7vCfvzdd2lvvJtnqxfBlIJm7M.K73sD45FeyImIPjJ0wkBwcsMEzdbNCHOx4hCFYqgfv69eS6rMR9LoEmQbWCCA9MAsrwkdONXSDkDTjCjyi2nbeZa6Uwn3G3.nevVnTYrEWR+3OLO3OruX+wUKpw80PJWT9HNvpIfNOCp.tm2M9C8cjnY6RbrLTuqWHpl1aLNWfv5lxr7FtoyeFxnR46rh+BVxlY3l.n5n8oZGp59wGYyJkPSrYIIObp00Lq.bYMidrUExDyJjrv3krVsANMQLuk78FxS84EUhRG7IBxXUZa+ImPG1GS9VK8S6NlvjpqC+jAGOyj50N+Txw9HxuMRmxyONc0rr4.m5IHXEefZd4qEUBWFE4ujaZtZi6.sXpTaYGDnVjZaoswb0pL4icTqKNJhwAPLeR79H4FBPdnyO3U3WUKK209P4rzUWldLuWeVoCgzVeM8QttKwNWl1RZT18zYspRdo.w5dIRbT2+HdQ7PJUDq6w+3WLGyUUnIecb7clPuB0TYdFxEbcTT5kWXAuVdjqJTS.6oh4R+VBpcyD1PukMvWiBY1mi5Z3Cbpnjl+WlKQ6GFF7HmU2BlHC7LBD9Fz2AwYZH.m4PShBfG.nJICRoyPuoC1S9f8ZAafTM.PxzYOECGL+Qu8tM.gPZByQnJ+IkkXoZkAW0zHUQYgd5XfJc4+JyI.nBaahDHGjPafwaKqlnqtzE1tPLXbSYC5eeom6O.6gQBH7LRV6Kj6naztGR.RtywW5oQQX0.+U0kZ07bCG9s1B.0pcHPfqAK4cIlB.i9xA0Fvpmy5mqgHKuWnswFPryvsZbrmMapeIxDzWlTnXPCxqJZXT6WXb7zBpj0S5e0lNNLxBhQMgwo87w0HHKgdtMw23z6dv+QaT.c8fW3hIkkm+EXgHEUjgnOgX4hHQE.XixlR7VjKWeWctCKqbXwVlmABSdVSKLC97.QZq3VBUD5NNL3BYiHeb27QaeqdEf+zC";
	}
};
}

