namespace project
{

struct xfade8_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "xfade8";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "2845.nT6K8C1zP1IV.nyRT4.Kv5ppF78SgPH..HiazlwdId8cntaidSvXWPH6729ZY+Gn0Rmf5mXKIqyiKaZ2.7M.XCvD5wCA5YstX0L5IW5vlw0sKF.1KaVCQ1SQw2gObUg+QClBz6pBqpl10RmqcvzLZWalh0ccubcMQ2dllcycS75.aylw5tzS7FzPd75H9G5kNLZFZ1KM.UA6hgfls08qxyVrMtVBjAttY8jGPuGWCP0L5Eb3ZtlQwTL3354pxwQ25vAOMK0iUEbUyRyZWqd.POOYJFcfuYKJDZnW85dADT0RqhYwnMgKs5FWGlmDlklgiJgWEoNBzS6Z4v0Ldd6.zyxpc8r0A1ECNtXXS7npWTNe5HnGEUzPOMvWNx0KBPwiU1xAmlMYNWtVCqK1FMTerb5GbHbgtm7FTepIIzenKc2kxJxFASvoCzQ3vUNb5bPGTKEvJUrkMSyX5n7ECyzaHcCdTCPU5nYycWbqfIb8hVwZnY5klrVciZa.GJQ8sTsQkDRytBe5z4l0j61zrs.fPHHKSpHHwPBIrvoRkIrQk42Rnq500CddC5GPbYnYJEepXaYWKu2m5kVEW2LMXzMWrNQ3dViUGfGRsDJmyJ3zitjnTlw5nbpTz.38.LtTw1P0dPS4YwRFrX1pYLu2RKKMRpphwHttIq6hZ9AOxLPjhxg+iwoooplk6Zoi9+QLFiPH7+XL9uGgv4DBcIeDPH7phocX.SKw8FBo7eD2i.F.2iQSQdDRdjG.PHrejqbUJzOPQpp5kboGRkz6Qp3zjzDDBiE.5wQUCLRQPffnDAMKsSUU0bBwfAbbs3RRMyloilESG4S2kphtjaf1mu2VFkBL.SqZVKZHVfzi47.wMMWUO46MiqSPCTTuHJGn7n0L.Y7gQsTZJqlphez.g+oenAAXTqL3pv0rgqkwWO42v4v68deV2Ec.ZP9uTBonfQb2E6ZgyGAfqcfD5uLV8USuOoHf7ANuVG2DJn2QtpbcZUnmx3CcIWRE0zTFenG0og35do1glwzS1.aIx18ZQzzifm.hUofy0g4gUkhG9RXb5TSeZNU4RRzHOAj+xwh70Clp1DfuugkBp6VVMSGYlYBoEtzOhRZfy7MzgmEFCkNBcD74a.QBmRQmJJg.Je2SNN6F+8DXbxkODJKvkFrmLQoYoWdDeYre0sNxj0NLFwGeS3f3eKkwXGiw3bN++gv+eozc3GiQrqGtJ1SllRLJkR4+uTJkRYLJiMXXnJzfMEZfQ.B...HARpA..hjnDDDwLcfbv.AiA.CAEfBBAfBfBfA.j.DAP...ff.BHDjgxTGgAnJTlLV3vwzSTrJGhrwXAJIqaFOeX6rmX8+iN34M7y0koVkAjA9ozYYTZOZUgbAKVKkJJhokJhzhqRVkhE5qUivuGNdOISCtcyi9hod4YA8rc9IkoVawYipWm+JbMYSainZqaYRN.zThlwxo07OL54e2akd6dLJRuflWgMjNKIVXkJJSjakaGOSunZxngzWCZSxUYpwwWyC8IhqEO6sFOoksGLdLwdTdi56qTpn06LLxVTnWuaamZFKcLOVnuHuOV3a7Z4gLXUrgOJmqwRqFdRwY1xRcGzzFEAMsAexxCLRTshFM.oVSLjb7fHgxhp2MBDre3QHw0ELx29hL12SXhXYz3x72P5wF1PycQUThmiDqk5tTggWNtzTBA+LVjoIYsB.ttQ9aM9d7ohNx4dKUvcPQJudUTif3Z8OLTZEdtDhqfJk5FhfUEKwE7ba9HLevRtEdcAgIZrLLU6BLPEu4nmYbjoErcFV.9VXbfiFPt+a.OWxWlGVnYcRUrs5LPI1ZAIY5xtJU.A3HYBcthi6H8Qw+Xr8DsQfyqlAafyfNX4K7ETk5o5PwrpXysQ.sGSU2OPtMOJS5R8mHOiozpQrfRvexkCSC8Cg8337Swt.OA6Mx2x0fKikuoBo5MqAffcJVsbdCRM7mvkUHvcbu06Yh.7BDnH09jD.7HeCOnL8kZQ+MDjaLOWuFeGwX3P66dLpCsgUczVdV5jzgX+qTw4BbKBm8lzEPNLMVXd6lfcHuksQOVj7RModCBxOl4XEr2d3Eih3L+R4RGeDdv46R4y4hiXuat34549NIn8IIhr+ZgcykZTU76suxEBvKI6rYq.GtL8VsodGDh3Hq4Tm0BfKyTsVzAAHJ.R1WoHkEk13EsUQGLM5Btcvs88m+YO7iCXOs40YOudATj2YerCH7CbPhZ+KiGm12Zmhau8GyBzMlqoJzeDg0pv1yVP.4.Hark+Pa+bZbbctt8jFCDk3dTd0kcCImYOo6cdJwsYub2mf13m2ij6dur72FDjKfXE+9u4Wkj58sEuKfOingL.wAE.oEh9daG0B+tKCr8d8Et0v64bHMRd6dRTH+v8Ir.EC+Jm0dW0ew9M5z5sHbXQ4cPLlauHJcwSFOnBKrRTn4dqLNjMQ9MFKOcHBA9VvrYlxrrb47x7tQ1.X7zizz8ueHrQQrRYiGKPx9VCZM9.hX..9BWZ4gXFI3tPP5pvjQ2JKdXksU1NAATvGVlQfkQfKT2owfoezAjlGFgE1xQiGAGpGIpoZAVzasimW4JCyZiXrq10KE2GPVnZL1FmtbwPLfTggbVa24ryHiUPDsPRGxQrbppyuF1KlfjPcakoP6FOoTnmF6EJ4ea4dORFmzGf8H7R7ii6BFBwzlYJhR+QSTjlMkemjkThvKnVp1sL7bfb2uYzi.6ilGDHKIXnMxIGjDKDIgfoYROkxrFEkHI1K8fm.mg7tlpeY+f.rPfnrTabhDrmNFU+CcBJqBIkUyxx5sk93eKDqMrW4+fKT.jlH2JoFm+mtMi00AlOfqbahHu0MMwdl2q0XWa3+XWUo.nPg.cgbHLQXgISQM9l0GbzEAREpyZM10lhQrdn.oErt2i0RxEeP3Tf.tNnpABPgeZN.GytO2ZH7RlhakQTCSY.trWpRUiUuZSys.M8iOxFne+bn2wF7KA3BNvBy80+pLAglpQt.D9p0.BEKifUbD4Pfcd5oGfkXm53nV3Hro+7JRr1q6ZEhhx7lktqfuBggc+QUmluLAX.MnFSRBS5or80DC0yM9La77TS6N6zHJJBmDEycbsz7ogm4rSlYvQSgVFkTqS7wluJ0XGGHFB.r5guKfke8CdNNDGPBRrxQGMK6CBe3b4B0E3C5azHMKDBr2DMj.vIc99JMd6pFfYUjqC851C8sBq+.1KkR3l5N.58bP0.Eho5CieBH1DGG53.tfAvLXzgOnuqrxkABAbJD3uDwzx4h+AdweTmC704Ran1EpapiHyx1euzGpgkQ9vtny+JWvVUi5QWJ3p6TfwIphEtnKykpGcEgtvNvh+d8gCfT2DRIK7jK2vIYeFO0TgFxgDHZ73eQ0V2ksGXOEMtXDFhEeRkLVbliF49CJUPXCPR3BlvqyCSaliNK6yW7mp5POBPwnWFCkOg7PfCWyBL4wWBf5En1ulbdD5jcYVpmXD65L5hISWNtXN83RPtmNu0A5LNvEsUviYqVCb8Z7dBQM+y93Izyhg.uiibnV2yXAvdrI+ceWtzAZflxsB.bOPaaBvfbF.NBMg2YtOjpinLVtmgCRPfbU1fB+urkctyFLSNUuGVEG+2.rZPvIVnfn.HMpmbOapWyYNbJo9KQCgvMidGEj7GLVQ7DOTHj0i20LRk6dxfbNzMiu9i8KfgZHmj9uw56aFmQ.Vjl1KF5vlJ0Y8Uvb5mPJ.RYXng7W.hWy8RUIjcTO2hUoIUCjYVrB5T0HlVeS2PQ0QqUj8b8oEBfCcWVbOvMZkU7+7.";
	}
};
}

