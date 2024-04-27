//Xfade

const var Xfsync = Content.getComponent("Xfsync");
const var XfTempo = Content.getComponent("XfTempo");
const var XfTempo2 = Content.getComponent("XfTempo2");

const var Xfader = [Synth.getEffect("Xfade1"),
                     Synth.getEffect("Xfade2"),
                     Synth.getEffect("Xfade3"),
                     Synth.getEffect("Xfade4"),
                     Synth.getEffect("Xfade5"),
                     Synth.getEffect("Xfade6"),
                     Synth.getEffect("Xfade7"),
                     Synth.getEffect("Xfade8")];
                     
 const var Xfader2 = [Synth.getModulator("Xf1"),
                     Synth.getModulator("Xf2"),
                     Synth.getModulator("Xf3"),
                     Synth.getModulator("Xf4"),
                     Synth.getModulator("Xf5"),
                     Synth.getModulator("Xf6"),
                     Synth.getModulator("Xf7"),                     
                     Synth.getModulator("Xf8")];
                                          
const var Xf1 = Synth.getModulator("Xf1");

inline function onXfsel2Control(component, value)
{
for(s in Xfader)
       s.setAttribute(38, value);
for(s in Xfader2)
       s.setAttribute(1, value);  
	
};

Content.getComponent("Xfsel2").setControlCallback(onXfsel2Control);


inline function onXFsliderControl(component, value)
{

for(s in Xfader)
       s.setAttribute(30, value);
for(s in Xfader2)
       s.setAttribute(2, value);       
	
};

Content.getComponent("XFslider").setControlCallback(onXFsliderControl);


inline function onSmoothControl(component, value)
{	
	for(s in Xfader)
	       s.setAttribute(31, value);
	for(s in Xfader2)
	       s.setAttribute(0, value);   
};

Content.getComponent("Smooth").setControlCallback(onSmoothControl);


inline function onXfModControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(32, value);
	for(s in Xfader2)
	       s.setAttribute(3, value);  
};

Content.getComponent("XfMod").setControlCallback(onXfModControl);


inline function onXfselControl(component, value)
{
	
	if(value == 1)
	{

	for(s in Xfader)
	       s.setAttribute(33, 0);
	for(s in Xfader2)
	       s.setAttribute(4, 0);  
	for(s in Xfader)
		       s.setBypassed(0);
     for(s in Xfader2)
		       s.setBypassed(1);  
	}
	
  if(value == 2)
  {
  
  for(s in Xfader)
         s.setAttribute(33, 0);
  for(s in Xfader2)
         s.setAttribute(4, 0);  
  for(s in Xfader)
  	       s.setBypassed(1);
       for(s in Xfader2)
  	       s.setBypassed(0);  
  }
  if(value == 3)
  {
  
  for(s in Xfader)
         s.setAttribute(33, 0);
  for(s in Xfader2)
         s.setAttribute(4, 1);  
  for(s in Xfader)
  	       s.setBypassed(1);
       for(s in Xfader2)
  	       s.setBypassed(0);  
  }
  if(value == 4)
  {
  
  for(s in Xfader)
         s.setAttribute(33, 0);
  for(s in Xfader2)
         s.setAttribute(4, 2);  
  for(s in Xfader)
  	       s.setBypassed(1);
       for(s in Xfader2)
  	       s.setBypassed(0);  
  } 
  if(value == 5)
  {
  
  for(s in Xfader)
         s.setAttribute(33, 0);
  for(s in Xfader2)
         s.setAttribute(4, 3);  
  for(s in Xfader)
  	       s.setBypassed(1);
       for(s in Xfader2)
  	       s.setBypassed(0);  
  } 

};

Content.getComponent("Xfsel").setControlCallback(onXfselControl);


inline function onXfAtControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(37, value);
	for(s in Xfader2)
	       s.setAttribute(8, value);  

};

Content.getComponent("XfAt").setControlCallback(onXfAtControl);


inline function onXfMwControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(36, value);
	for(s in Xfader2)
	       s.setAttribute(7, value);  
	
};

Content.getComponent("XfMw").setControlCallback(onXfMwControl);


inline function onXfVelControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(34, value);
	for(s in Xfader2)
	       s.setAttribute(5, value);  

};

Content.getComponent("XfVel").setControlCallback(onXfVelControl);


inline function onXfTrkControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(35, value);
	for(s in Xfader2)
	       s.setAttribute(6, value);  

};

Content.getComponent("XfTrk").setControlCallback(onXfTrkControl);



inline function onXfTempoControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(4, value);
 
}

Content.getComponent("XfTempo").setControlCallback(onXfTempoControl);


inline function onXfDivControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(5, value);
};

Content.getComponent("XfDiv").setControlCallback(onXfDivControl);


inline function onXfTempo2Control(component, value)
{
for(s in Xfader)
	       s.setAttribute(9, value);
};

Content.getComponent("XfTempo2").setControlCallback(onXfTempo2Control);


inline function onXfTrigModeControl(component, value)
{
	if(value == 0)
	{
		
for(s in Xfader)
	       s.setAttribute(6, value);

	LoopLabel1.showControl(0);  
	     OneShtLabel1.showControl(1);   
	     }
	     
	     	if(value == 1)
	     {
for(s in Xfader)
	       s.setAttribute(6, value);


	LoopLabel1.showControl(1);  
	     OneShtLabel1.showControl(0);
	     }   

};

Content.getComponent("XfTrigMode").setControlCallback(onXfTrigModeControl);


inline function onXfsyncControl(component, value)
{
	if(value == 0)
	{
	
for(s in Xfader)
	       s.setAttribute(28, value);

	XfTempo.showControl(0);  
	XfTempo2.showControl(1);   
	synclabel1.showControl(0);  
	freelabel1.showControl(1);   
	 
	 }
	 
	 if(value == 1)
	 	{
for(s in Xfader)
	       s.setAttribute(28, value);

	XfTempo.showControl(1);  
	XfTempo2.showControl(0);   
	synclabel1.showControl(1);  
	freelabel1.showControl(0); 
	}

	 
};

Content.getComponent("Xfsync").setControlCallback(onXfsyncControl);


inline function onXfAControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(0, value);
};

Content.getComponent("XfA").setControlCallback(onXfAControl);


inline function onXfDDControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(1, value);
};

Content.getComponent("XfDD").setControlCallback(onXfDDControl);


inline function onXfSControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(2, value);
};

Content.getComponent("XfS").setControlCallback(onXfSControl);


inline function onXfRControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(3, value);
};

Content.getComponent("XfR").setControlCallback(onXfRControl);


inline function onLfoShapeXFControl(component, value)
{
	for(s in Xfader)
	      s.setAttribute(8, value);
};

Content.getComponent("LfoShapeXF").setControlCallback(onLfoShapeXFControl);


inline function onXfStg1Control(component, value)
{
	for(s in Xfader)
	       s.setAttribute(10, value);
};

Content.getComponent("XfStg1").setControlCallback(onXfStg1Control);



inline function onXfStg2Control(component, value)
{
	for(s in Xfader)
	       s.setAttribute(11, value);
};

Content.getComponent("XfStg2").setControlCallback(onXfStg2Control);

inline function onXfStg3Control(component, value)
{
	for(s in Xfader)
	       s.setAttribute(12, value);
};

Content.getComponent("XfStg3").setControlCallback(onXfStg3Control);

inline function onXfStg4Control(component, value)
{
		for(s in Xfader)
	       s.setAttribute(13, value);
};

Content.getComponent("XfStg4").setControlCallback(onXfStg4Control);

inline function onXfStg5Control(component, value)
{
		for(s in Xfader)
	       s.setAttribute(14, value);
};

Content.getComponent("XfStg5").setControlCallback(onXfStg5Control);

inline function onXfStg6Control(component, value)
{
		for(s in Xfader)
	       s.setAttribute(15, value);
};

Content.getComponent("XfStg6").setControlCallback(onXfStg6Control);


inline function onXfStg7Control(component, value)
{
		for(s in Xfader)
	       s.setAttribute(16, value);
};

Content.getComponent("XfStg7").setControlCallback(onXfStg7Control);


inline function onXfStg8Control(component, value)
{
		for(s in Xfader)
	       s.setAttribute(17, value);
};

Content.getComponent("XfStg8").setControlCallback(onXfStg8Control);

const var MODSEL1 = Content.getComponent("MODSEL1");

const var mods = [];

mods[0] = Content.getComponent("env1");
mods[1] = Content.getComponent("Table1");
mods[2] = Content.getComponent("8step1");
mods[3] = Content.getComponent("8Trig1");

inline function onMODSEL1Control(component, value)

{

	if(value == 1)
	{
	for(s in Xfader)
	       s.setAttribute(7, 0);
      mods[0].showControl(1);  
      mods[1].showControl(0);   
      mods[2].showControl(0);  
      mods[3].showControl(0);    
         
	}
	
		if(value == 2)
	{
for(s in Xfader)
	       s.setAttribute(7, 1.7);
      mods[0].showControl(0);  
      mods[1].showControl(1);   
      mods[2].showControl(0);  
      mods[3].showControl(0);  
	  
	}
	
	if(value == 3)
	{
	for(s in Xfader)
		       s.setAttribute(7, 2.70);
   mods[0].showControl(0);  
      mods[1].showControl(0);   
      mods[2].showControl(1);  
      mods[3].showControl(0);  
	  
	}
	
	if(value == 4)
	{
	for(s in Xfader)
			       s.setAttribute(7, 4);
   mods[0].showControl(0);  
      mods[1].showControl(0);   
      mods[2].showControl(0);  
      mods[3].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL1").setControlCallback(onMODSEL1Control);
