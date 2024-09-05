const var rm = Engine.getGlobalRoutingManager();

const cable1 = rm.getCable("trig1");
const cable2 = rm.getCable("velo1");
const cable3 = rm.getCable("note1");

cable3.setRange(0, 127);
cable2.setRange(-100, 0);
const eventdata = rm.getEventData(0, 0);

inline function onSync(value)
 {
 
 local note = cable3.getValue()-1;
 local vel = cable2.getValue()-1;
 	
 	if (value == 0.5){
 	 //	 Synth.playNote(55, 127);
 	 	 Synth.playNote(1+note, 100+vel);
 	 Console.print("on"); 
 	 	}		
 	 	else{	
 	 	//	Console.print("off"); 
 	 	
 		Engine.allNotesOff();
 	 	} 
 };

cable1.registerCallback(onSync, SyncNotification);  function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 