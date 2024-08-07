namespace project
{

struct finalgain_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "finalgain";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "408.nT6K8C1DETGC.XVD5TBDKia.OEnz5tZFWsnGQIhqSIAsNASseHeytRD..Aes9+jTPKSAu..L.7B.OeBiV7.qdMcIajwokq.u5SIFYW8owIVEFeYxehBedkKN70.uX0Dd3rpEYTy7iDvm4hOA9fr6yKWvHbz27RFLNQ.Zlypcl7mOlKcIZhWUOlGQaL.qR4yxbLaN3x5Q9v.yp1SGKNyXvBJUKpcSNIolDDDj6oASvpZdKUZ6n6FkqacAO7pv7yJlcvgzZFrhUqTd3.iuo0CgQD1UmjbSN5oIpFL1s04m8LvBnPLBsB7cMiQrptIQ4lnnhZcKhUzPfFZKUAP.MAj.P.nF.AFAD6NNUSIeoXpIBFoKKhrBcDeYw34HseQwVfBLZJPeB5C81vDXy.q.GXjfsDay8mpj6UXkNB1CTSC5oQYFlEz3c87qa5AIu.61uesIhLyXEfhCdvCvG2Y3AoCy.6AaRnMkPHMKKDXTgA.7GLuVDFi5CvskzvXRTtE4UCMRDeIHnkYGBNJlWi+DB1MnbLhkxwf5CfWE";
	}
};
}

