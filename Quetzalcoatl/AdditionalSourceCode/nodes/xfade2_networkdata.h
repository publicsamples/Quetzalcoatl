namespace project
{

struct xfade2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "xfade2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "3931.nT6K8CpE7D..8oG.5GFuQvBvvx1FaOJEzuV8Z3PMXz13NUXs7gFaca.hr6cJkAqrrTsg4lvpum2x5DLH6fR.mD.6.Tq1XmnBNaCmkBIRR75Z26I6G+7CuykUEZ1gdwBf1Cx.CsRio0C1HZWtzApLfnYYbdcb3r4Ao7++hpwmPXPypXrRvTdunIQMJN0JJFVH9fJ6hBpdA.pIpO6D2Bq3b+N2RzXO1bEQTaZBbnVV0KTjQ23ZpwpRkMqBMUwLMYwtsFmM+TyBYQ6iJPTYUgvrPvMXmzVJrGSLgplXvhBCjHKU0qIle.saSxYTUfv1GhHvT8yBgjnVCCRD8yDCrKZF8y7ZlQGUOSTLrInObPyhZ5gikKpE0LypxYEPTyS1LiOtpYblPXiZzoJFQQTNVzJpLVUXxhBBKTllTE0TC1TBMKRKknlUkB6hhgFuQhZbnrpd.8QUMiNpUUVzZ5zriGakn1ESXiZa3p1QFEi.PIX28OfnVGzMjQpxjnnHhfE0bCoT9dcFKniJEldf9gRSlsB+XVR9rDSfkesFnOSKrfqI0hhB6DIPRx6UfGzlIpmrZ8C1d.HwXkXDI6FA3du4JqS54jP46wlIXOVIaLP0jCFvl.uQCr08sEBWCrHsVq4eBgwRADm6NWGi8eEpVUuDfK5FgGNYTcfsQirNUrcCbpUZrI5AUmUBFBZXWH2.pGgtl8lcLyNmE2Z.XCKvRA6h1oSHG7wj5h1B8hCU1LKyVIqVk4w6jEBWARjkMrnxBUuVDbQmlzqMyr4zlLKJGzk.by.peQxgjARu8BdrwF0rMYg.YQsAn6nKuXDbYv.FboiEKUfCKOecQSzooGz3FrRhvzLylW3AsBzm5kVyC5j0Dlpe1TM0H3t6tKIIwUZuclY1+WhKPLFgzt6t6t6t6t6t6bRoDBgRRRoDG.2cORL5xJduW2c2wXraoTFix+6NBD5fQF97GDxRBH1++sju6t6FBgdLFgvX2L2sj2qk7cGoa2eRRMDBeOXyLDm6UQjibuc2sy4jR464bRoy.byM2R9tmzc2c2c2c2c++9++u2ycua2cmi41++qpdvnWdzrQ7uy4bt6Nmy4b+69OFi39+PHjZQgUu3tj++u618+e24u62qa9Auht6I50LDGxrOv71s6TXthlBl+JvJbERLEG.c2qjLJF0BqDQHIktDK4SjRN+wGFNI53VgvfH17RYhhEx5B6y8dyR7CxH74du4JarSLUwP2XlkYgfiqKT.UqTnxiobYQWQs.iEJiDNzK71c8+33igOnjkdXCYVLwoSUL0NTHq5IC0pBsybPcwFqf9P0rTdZrvkALqjWZCWZ7JJF1kabtxDwVM0nVEgsxGU0L5FywDW+jdN9tIZmydxduaQhd6d4KD8CYm2sa.SV8BALtKaQMwH4et2aVFgO28MJZTPen4CC+28ua1kcGgu10eE92TvD122cm6e2iwt61kjj.MqtnbTA2c2+++28+gv2c24la2g3dD2898buaN.c+dRsT2N24NGByc6NC8lY2crikrKkxFRWgcf5f1bMSQ.IffP.PPBvPGA..Lr3xBijCkitaiBGTHhB.PLfA.DDJ.3.fC.L..R.JH.f....Ln.hAfAgChNSMUJpO.TNb7RhRzxgfi7DvgLyleyGzS1kXsqnN39AcMWWWs2IOZm5AYnAiVUnsSHIVoQpkrvJshjoHw5XsfK38192Smf9ra+newdenLeY1NsNMBEDKa110sRCWCOn8rWsjsLZDxNDVCgA7znOzX7+3M3p187egK3mmiMLceYVeEjQZhoA5yhN8HbDfFiZIhOCSsilGzoLFyZZvYLMqKfe7XJRCYoQ46Wog0FV8SrEyZ.cL.K.LxYN8XqfQD7MrAAc34A75ylvJZTuCjrRkn2iYB3NSzrlApzPep1IIacvTH11yR.BCF0vVL3wHvFzMaKzLKEjFD3hXNWvUbmM.kAuEfBK6kIyn3.njQ5aHqo5IOMSni.FZLsf.jx4qRReHaBqRRMU+qcgGjeVmINjU7yNd3KmhQXaNWMl8r3Y1TQdsuAbtrYhBgdO55l5NkYFMlyjwCEGGq8KAmcxw0CT.M5SM.FcclBcI5jD.8f9ZCJfDjhV.iJ.+AmgjhD+7tt9reeMPdk99fDBVq3iogwakbViLVPqULCh5b8oPdUkq1VBCYDUuEDvygiDb+pbODUYiD2hmb1JL6UDoWUYkYZ3XG5AEOlD7sNLpA37v9lrvuXxrHYh+S81RbHeY+hIigxYKQcFESIdmH3aHOLvtU9CqSuDzAfmCYPABK0UhDXSfWL6lj+k1uz6cmGybqeThqjiCdb2WAgEhWGwhGDgF7gQj2AwtP6Zkav+SPzUvvQ1UmvJBIhqGInzDVDaU3yyP9EtDLYAO8NtDlnXf+6bN6Fx6EBmIH1OtabTg2vlg1NI7T7K3dQxLjAgemsXhEZWAJFUS4J5hnXJfyQGYcjEBeSQBWCj12eFtdzPabCyNqMuRfuZv0hyYeStNg3G8ZJ1xP7ebUkuggDUEvMlUDjHdlV0zusP3BXHqzsEuquE.EFElZ3PKPP2JdRwfJXctvb5uvlEUD2w3wlv2lCxULVgeR506DBtFqgR3syVZZadQDlvv3KJIB0dUXuHa1TObvmu3jZUBVvaQy.5hRK0bg5xbQPfQAscPPMtn2Iy7HbVvhcRV4FR.ZSvBuEo50anoL1VnlE0DoqQdbri899y0k0yPFBqTIE2vyQmwN1NmlpvwxmvLDeocsXE98vcL2JbP8G.+S.+r6IgKFCYtGGGh78vaQGIGFQRHBJEDUyk+.uoNMwzvCoNSYc1GEqsSaFWYbT1hHpXEFBkjBqwZ1biIwNjW8w+gDBBHI3I6PdzaPDD50JnvZ+9X6x.ppPefw94WCblFBvKb.tLcfTozcaOLknwbsM9J84sVc.lXfJeKSC0D3DVhFRai3hvfFUp1MuMvZLvU4Y.egSvHh6mBM.8gGCdcpPLVTci7asgZDoooL3P1stXtVgZ6n7ifRX.d9juRP4iyQ4opQAgEHFCcDrZlelvks7gtczxv3FMGdNr+uELL9LNnpbhMR0MbBW1UQZvZE+7bnyRPOYpY8QTRzi9BEH3lWrvDOLDhnP1tpPBwTPPORo3899RQLK.o.l6GZDiHTSiWMvNlgpz7Rgfo6RBh3xsf.ux8kGAMlNnIIL1xNk1wD0R686XEQZWDmH8R63uXIYxquorgEBpgAW.wIAEllP.OLqJEpZWclmAKjwOY5hZo2WC3vs6g5ZIyHkflYlMxuiY6bQU.JHZI1C1UvbFGUQBfZe0hkE9kirjTBRcZZikzVFKs+kmZ7PG.gizUDEqv1rRpS5ERBsGB1opFXdCvO32vxplu63RZumwMX9HXEBmbvX+a.i9Db0L8Lgiw1TWC6HBX4z9tAsCv.nc1YK0DnjX+SocCemkmWDbARZCR1yuQBv3MlMZHgVoFnWYPbLmuB1mmNw.Fh4HCeGpP43XuZRsPjEpIud82KL9yi6F2JDYuovp.Qir322BkKPGd4HyBVAMjPKpA5IA0AEK76r95tLSW26rA7.xd.pcmbhyhR6WkTEowDwLfC7tsOrzVnYwHXuw7tN7qey40ce123BgHQse5wFwZSfSwsWfwbu+M1zoJVShHhJr8QQ3EhNH6.KcosmuItFiqa+hDijIt2Auj4tgBg4Ic+xZHmSO+tOSBCf2eeb8dT8WMHHAJQE+d.wuJo06IkX2.9yf1DBHN8PivZm36a0WzrtqH1dutE7I79OUjFqytuSKV5v8qiOvmqUq1C0TtbuMg35QH6vge1AUbm4uo8nNY34UPkXSgbpvJ67biHy.CfX5DOl7sLcyXgpKqg64ov7FS.fg4xHc89ynUaVDY6r1BKLI+VWoFwiDoO.7EVYYUwHum2EpQ5pyAwFYAgisU1FHLc3sKXmvx1cQP3zvWsu5XSySQw.txQ6Fgs6NjhMcU2hlkSOuR59xdFCqrFwJnFcWJghBDmEs5cMO0RFgFPpv3rmr6bH5arBHs17oWQ3HvWUN4ao+Bifrt+UljaO2SoPJH1aOziF0qGB1Bg+04Q4tfgLi01E.LT5+JUklcWyH8ujREzCFAvnbHBfR.KG0D69MiYFntL1MABhAi5ij0NHWQf4BeHmwkoLYp7ICIRH64Kf2.ICg7zzES7Gj7G56kkfab8FvdMQW+CkVwSJDejQ2q2nZ1MqTseekiFNjAnHQdwJw3D3CmHi0wWymnKxrUl7Fvo4JXlcZWwF8vugcPNEr1UHXR8b3T1v1ld003qP+PI5prUEdn0xf8MAHwF.EHQs3CdsVPB9UGdCDvEJTMGSHw+ZNh1lS8bmfvLFG3VDCEFmRu7l0brZi0uqIqaJXh9iC9MzcrMVjj52wuhk.yuCiFygx9nBA.XqpkGP3BhFvZvxAX0CBYxDm6IK569NrqoIyitHCdnKMoywzJ.LH8LE41cWEMBOpu7QU3.eIyv.JSio9DlFRY6AQLhXtNfYisolrS1QwRgCmzNF6tyIfRbl4fGMCeAs5a48ks17O1yTo16Xw5AUZfZtuKZJ+J77bsO48PXLBAzHTYGqlOBrggZe0f916fAXHjOiinGBm1B7UEzf5WMP9UZm5Fdf140+WhqrGXPdpWsJm.nwAyz0wH09ebUQFZUV5gIDPgbEfWmmNi88sxkZ.JRfDItVDpQayB9oiuweDf4fuCtl.5UI0IUWO3V587Kc7fODGjilJspsQC5GqJBL9qF+jTL2O4eCveVu.DWUf9Am.UTcLYwQslDmj4znXSuxPFXANiGSsQs0XuU.v.DM1bdhYwSNWF+aB1cCbkJXSC.N4p9fcp2f1LFMrT7Xl+F1E5O.fACWFbjOE7Pvwc8F.637QhQnWQv+viQRfN6RSTWWDGIFpFhoKj63JXsssbqXssfsM1B3Cyq0pD0SRJyzg0uFdZdNhtJCChLOLLDi4heejboaDXqVTP86UUzfHdJR0v9POPLcVRKJrw8kTrIysVwYHBe7PnX7Z4j7fpN3GDAsZgr7TXc1dTr4X3+0Amy0VEhdQBch1.EXleHQ5x3z1PK.s5CznpNkYUbiYUl9JzMEgmToeoE4BGkodr1n6DM37t9j9vUkHBMXrmqzJmHzio62pAed234Y2Ql3I7IaOjm.EHl+QiDENOwpsrNxeivbjQH..TTCa6jKrWhEgnkdPHOiz39csjXyFnAfH5rLIUPSWlRWjJ5lhzdM94VotHvct2E7yOnyV2r5929.";
	}
};
}
