namespace project
{

struct pan4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "402.nT6K8ClcBTDC.XAU.QBDqiN+R212J41gAyfUCnS.H96X4nI.K7NYRS..fBKly.oASofM.TC.2.P6ZT9BVd+tvnxHWiybwJjQPQPQaCM8ucAaMozpPypl+cdYte5g24ljQb9sLzrhkUSGf+CwFSPD6gq.saCW0fi27NN6isQdkP6OLFq95heYHjdi6TAAauwQ+q1.zrSjmxferhSXgls0iQ0txu.nokkXyAxYXGl0eIwbrlz+Vrpc+orNzrhkDZl0hv98vIEpDIBhTvAPj.Ix5PSH16dJs0CwwagCigkQDMpWGoLXyTJxe9H1DoAVFITE5cY4YejRPvWxHnnc81kEZlNOsKri8GFxSIrcmedB2.BL.AfSk2ATGZkAvuH5r5vNv8dFSQiK0w5tgPJsltxE0NX2aAq7AuyrmRB.bDZUZG2ILM.FyA.vcrbtOWwEPfK3ZKUssVO.IFXnWoi0zFrmvr0rC3XmfAVnQEB3HGx3kJDDGPE.WLfuLXqOvLA3fHtw1vWbTrXuBQ6AG+2Tb8XEBAln";
	}
};
}

