namespace project
{

struct gater_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "gater";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "627.nT6K8ClKOzzD.XQFPQBDwMyDCxzZlUUlW+bS.wkI15UtF.iiiVmwNC.fgKWZLBV3+GvQ.XD.HAvzDUhiF5JNPvu8glsWG0AdWISmvA9lcnP7v6udkv8FxxdelvOEMSw3c1Z4Fw.zaszJQdnGonajF+YJFJA71AILdqA9dI+RDzJueKPTJrOQ7v6A7taHMM0xqes9VD8vFe0JYZB9qOPTbuaZl5vFOD.NDnKNgG7kJjZ3PkTEv3cOAfOg+7GQwzIWtUnzq5W2rETObV2QlSzT3BltkQ3y0ZXfrDoTP1UJ5yJA53ghzmoHYp.TDX+NtXHfjc9LtXIUAA7fwLPFgOWqa5lkoQ2rEFZlZ.1FzHR2Q1JBkqFzIew1qA9fQWaNcF.eQIqYNYt2awdQ2yImM4SNitYb1ZMuXatftlXiashMHBUIUI8j89jcdq8Fw8W.9AZPUclYFI.EjBQCA.o..FpLXG.BZrIE656CPSIyh9Qtj1chdzz3FPS.VoVYCAhJcnawrJCZO.k.N.8YSPSq.ThkLQZNHAZ.41XepIZSoHmwAHszcAkUFXfxtJCOnqqDqirY+E0o.br3NFr.KvSxChNCrBT.Y4cTlUH+PsxDgUnoLFDG2MnYU2ZQmMo3XFYmJETv5gjI6r7d7734oSoyBmGbx30IBUGuRXwjrbAY19.gNiOPz.oUIVWSdx6oHrfXG72xFRjilJM.IopMVjTcphZzcKQYD8JTSnUSJ5VANYybCx3QOZgugV8sxAh4UkT0AUfhJNZ3f2HosXt2PNBnfxhpBcWEna1ANxj105bULjnZZosjEKN0LUVIXwL2QmGf6AmyEX1C";
	}
};
}

