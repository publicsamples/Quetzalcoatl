namespace project
{

struct pan2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pan2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "402.nT6K8ClcBTDC.XAU.QBDqiNiB226lTyyfYvpAzI.D+crbzDv6N9T4cUUWf7jaHwnIYfM.TC.2.P6ZTNCVd+tvnxHWiwbwKjQPQPQaCM8ucA6LozpPypl+bdYte5y6bRRHN+VFZRoxp4Cv+SruDPD6gq.sSCW4fi07tM6isQdkPaO7Eq95heYIjdi4TAAauwQ+q1.zjSjmxferhUXgls0eQ0txu.noUkXuAxXXGl0aIwbblz+Vrpc+mrNzjRkDZl0hv98vIEZDIBhT.BPN.Rj0glPr28SZqGZi2hCqgkQDMpWGoLXyTJxd9HlDoAVFITE5cY0YejRPvVxHnnc8lkEZlNOsKrisGFxSIrcmecB2.BL.AfSk2ATGZkAvuH5r5vNv8dFSQiK0w5tgPJsltxE0NX2aAq7AuyrmRB.bDZUZG2ILM.FyA.vcrbtOWwEPfK3ZKUssVO.IFXnWoi0zFrmvr0rC3XmfAVnQEB3HGx3kJDDGPE.WLfuLXqOvLA3fHtw1vWbTrXuBQ6AG+2Tb8XEBAln";
	}
};
}

