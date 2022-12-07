namespace project
{

struct modulatorscan_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "modulatorscan";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "1771.nT6K8Cl0rzvM.XqsodBvVTM.UBmFrzVVZruQ4nYQtwBBtLXBiBfskv1TTTrXDRUZi3yw1Ofl.zI.jBvEc2dbWZd643tQPI+bvxN5rkokro63+UkeX+z3CDMi+tKVSk4OqWJj9ta88v8tAQr2rizwfYA5jZ8.bnt8n3g+7akXolRtc1zSdDTOeOOY2GH5NaR3miJyb2M+.ntSVp4C9l2jTTAp+4UCHnF5QP8Fk61o6S8pojas9PKM4WfZtK0C+ezbxMO7MKqeyq0K.pk3hHnlD7sj7qQ.QR0KlJGxWEQt4D7YYEtkF+b3Pw4.bq98f+hH5VdO4WeN7913.TcMUYAiVVRTdBejauD9kY8Zgao6564wXfIIn6U5ljMYN+PSEorhUWvrKH1ElVIOIaZ3EDNoUAU3D5ltOuYZZB5.XhLi14nYXApAn84OmuH1IZnCdEn1jex4g+QF4ChOxZmGUBYVJgIesydivwzwuxgyMGR9qiiNCDvTUzyDYhzxQsNl.PnBDCkrWzkheMcVZGymyCL9jaBG.7SEHRAypnPGabe7B41Y+7b9f60NZt9kgmwx.QPosys.GHZxu3fkOmeuG6Yx53gZBORXTXmLc4d.iSVSWWXUQsKoo3km.ELJhqrJrzP8bTLBEUY9G7B5VbHoG2yqMjpTjakiKPDhI5BEFxR6M+8feApgQzrXCOQnIkU4S30wE9EtKMi.cTi5R6Zh5RhJRkUQMgUUMy2NNEpXj1mmDLc5d+cextkN6.fQUkoMu1LTVSVBzcx2q0ygYXVXZUCHsVIGq3EVV+U4Va6d.nLQyozcOM3eRqafTZZ3BKxt3CNvZedhYUXIoQxHUaPwTiFHQL+IfRDRxJ+51mLEKqWMdFqKMsHLKpYQQo0wqJHLypJlUcMokEg1OK0R2.TxXYdS28hgGDXxnFbNRlQFA...PR..ww..JFD5bv0.RhGCGJCD.J.ODCfADnHDCPfBPHDADBP.XrQpwBvTNE3+JcWroqvk7A2j.7RWlxRvnNDBEC10c+pHPKlff8.PXsGZsnoPG2MEc.Y.Ll9ZBKa3dW4M4d8m+ptzSMWXOfPUA2QimJCvuqWlaux+Zwx0neAew6Tmxe.EjRSYD5Iq9+fsOmxDXUojagYtxTGQfFxwQx2QHPqYHEFL.RwfSrI+CVsO2moEk3AFfoQ2SReuv.YYBAiybs6vEfgrK45n..MKOMc2ch3dCTLf5NwFwkm8cUypHZFnE978opwGpGkCHNbLk6WN0X.OmKx0dPkOzXWR8ARG9aDM4IXltcEAeNNpWRQ4MSKUpFRjHwHXheA3ZefYQDGLPma85HwOy4hJPvy0ASQxHQ+eY3JkkUzXukI4hZwF34wh7b.I8UEtp9B6K3yKtiM.8StmVNLhor7l.s0J32uxWa64VWpP2Wg1OLftCScTIilclwbNJtui9YvihUVi1YGbj9rjq6WyEmRdlTfBza1tZXdgDD6nIxVS7bo6KTIcS9qQ9.Aak9RpT3OCmY0JgK4afFgo+v1IlTCcgwDvdG3hwZpiBOLQxi7pN1eJaJNJYWUhwiWc6uj2HKMHRkXCTI2aXT.TVfSPGLyxTNknj4O9KGqUzv9aZF34fyfAMAqfNQmKIocAgJAdD7ivaB0iimRrSZiCM2MbUceg5YwRU9Ocop7fAVRg+N18pc94svA2nFwGJsRbbCmkH1RPLgrnfKW.go1CvwRpCXcD0vtsFQjjH1oO3uZlEjgA3hc9wEtqULQNoOSsRDggAnxdXT84l825qcArUxZmnymwt1.pXQ0Oaj575GFx7T5g7CoocbXiNvsPiuydcNZpY1cj3jzfgEYdHsD2hFTcTCGyw5B.KaFzpGyPJdmVXP9wG6qAsnQ2V39GXmf+rHVoASlE5gmi+qqOkYVtPpxAjVn1mk58nQAY1d4Yum3yzIk1tZPsARCfRvcSo0TyHiOQ.LdwF+nRjA33r+jsIlgNW6LpFPBeu4MzFMUMQAp34C3ea6XDCVgbQeDi25bFWLCISso13Bgg5YZSzpteZyvteYHMqAM3XHjQUnqBKry.aDFrvxFIaT1MzHBRaXDVg7VyJvZlBeHeuAyS95MB3MZH9B5ySZPp8PkCPTAintEOv6G64jwkyomPfsd20JCzHT+9pH1Whm9gvG4aSUQJW7gtnk3YyDC4dEc3BrtDMyF3ZxPkCq.RTqdh.lDijx2aXGNh3ppz1BHhGf0FleSO7TrYf5PHMnCF7HKfKIl9+AVp7bKwCDsWTHTy5NmL5ihjE.P3FP0Bz3VCYzWC29HVmbm4Wk6WPCSY+PcdsB3M908u0M5zcxBt6m9ZmdtX0rZqgget0YCaqzVeVROHYBg26xCTQmOPu.7WG.";
	}
};
}
