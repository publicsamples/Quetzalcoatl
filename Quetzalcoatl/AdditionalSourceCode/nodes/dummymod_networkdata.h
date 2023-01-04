namespace project
{

struct dummymod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "dummymod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "394.nT6K8C1WCT.C.XbT4PBHKaS.GQjqpSQqOQspIIHH5j0ibIU31NcDBPBR.RMLHdJRL8iK.7B.u..C1XIrkVBzqQxVphsThUHgd1pqn5eZrJzC6FUjc4q9U8dy0tP+DJHz6Pr2HYUBsqk7jA1jyNtEblCCK0fiwztL6.N5OEB8PTQlj83HaYSqYg2XczuXTT7TUBWizSbB8qhyuoc0unHYYhLCrat5nylN9hThAgsjkQk1jQ1TGs3n2wAMf7vgAPb7XYnON+Kgy9wq9sA.oOucwWqH6V4lZR2LZW7CI4WKmQP..m0hQnOtNJfymPA5AN5KrE0OfFYOBQCMAwfRpaCPB.BCk0cfjCbtjIAjCgvMPen4YmAkLDhJ9pDzna4V6JvJfXrVCGNUGgcrTOQPzEhCqkWOVfB2jixh4Wlv9XpUDhiG9z.BDTGvcXEsACxoh9JTyQdXsvtx1WkCFBlbUPplYcui26vW4S4JCXAO.4ix431+3ZW0km45w4xffnrD3po4z5KqtTWAn5.9UA";
	}
};
}

