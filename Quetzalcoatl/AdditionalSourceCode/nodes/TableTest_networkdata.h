namespace project
{

struct TableTest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "TableTest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "219.nT6K8C1Z.znA.HGimDBPqsM.QwI0sPo5.W5R0RjX6EvBQ0ifibVFPBzsPjqGoevyCIDBGcwSnTl32FXZi1ZQ.3cauNTmpbmcoo.w+P7WaMgyxZbvHfXrqf2JnxA9aW3D.vmRD7K66oMOG71RYTH21VZ2XUR.dlVUdbbqzDPvuKbBhOgRnTd.eiWO213HRD7pUiYZdXrxClwL38aYrrETFo.3Sn.AOCN9QuIAS.BThJlbObcGXZ.FF72cGFV53BT3hhbvUEaftJrlKChoBLRehr.aLSB.Rt0ngHey";
	}
};
}

