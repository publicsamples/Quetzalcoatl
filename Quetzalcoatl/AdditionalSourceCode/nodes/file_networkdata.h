namespace project
{

struct file_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "file";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "542.nT6K8ClNCTJD.XY1QYB.Qaa.vC85l6HHVcNxIEjm06BX7l0VEh.mepg9u2+6o4OtZFF6TPD.EA.R..+rT.Z6zyoz9JSx1wEMcIrqx2wKz1N01Ja9UWWweOlVail3AZq7gzoqYoXGT9ctxhuEnOFirdDxgczVJVBnsdlOnpiI+jcmHCeVgMX5U+SOaqc5Yc75BDZNWJ+IspiwroP9vZGw1c5a9fgwqOF9.+8UricYGK1Z1mk3DtfLXc5W+zRfn3OSXgu.RZhXwCJl7k7vS6SN+zAqjbPJVkjGGbJQmNsBI9R64uWDKUCbH+Iszh7ICb3fIgBo.q7vGVDOt1Z5OXLyF2zTvsc6ZSIjGu9Das+7UrHEL8vC7.YNoiU+eBVgoIBfHv50VB1A0tgSfZCXlKulARzDybaofvAHfPwDDpqjvpUiFTTVzwP1yZFKIGt7.1f5KRzNSjEpA0hTJ0XCB..gEDD..Q.CSgUGhHNjiDRpLHKZtrqV+LvYTBYH6sJ8j1hlvpitx1ql35RIvfJItYDtw+BLu3pMNgE75SQgC4cbEOnCPTXnOCb94AsIeJkxHPaJrMCUhBqDTZ0EpmuPcY5oFJZi7GSfugnFNoiNIZOTwrTyeDsdI.fh0+i1lrb4zLx1ZtbF.+8zpxY1OTniDiGP4Py4IfucaSzfczPdy32IvLACarGxUx2WYKByUGz0HwSLspYIGywadpvTuJBZzwC";
	}
};
}

