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

const var XfWaves = [];

XfWaves[0] = Content.getComponent("Wave1");
XfWaves[1] = Content.getComponent("Wave2");
XfWaves[2] = Content.getComponent("Wave3");
XfWaves[3] = Content.getComponent("Wave4");
XfWaves[4] = Content.getComponent("Wave5");
XfWaves[5] = Content.getComponent("Wave6");
XfWaves[6] = Content.getComponent("Wave7");
XfWaves[7] = Content.getComponent("Wave8");

const var StageSelect = Content.getComponent("StageSelect");


inline function onXFsliderControl(component, value)
{


       
  for (i = 0; i < XfWaves.length; i++)
               XfWaves[i].showControl(value - 1 == i);

for(s in Xfader)
       s.setAttribute(30, value);
for(s in Xfader2)
       s.setAttribute(1, value);   
       
       StageSelect.setValue(value);


          
	
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


inline function onXfVelControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(34, value);
	for(s in Xfader2)
	       s.setAttribute(3, value);  
};

Content.getComponent("XfVel").setControlCallback(onXfVelControl);


inline function onXfTrkControl(component, value)
{
		for(s in Xfader)
	       s.setAttribute(35, value);
	for(s in Xfader2)
	       s.setAttribute(3, value);  
};

Content.getComponent("XfTrk").setControlCallback(onXfTrkControl);

inline function onXfMwControl(component, value)
{
	for(s in Xfader)
	       s.setAttribute(36, value);
	for(s in Xfader2)
	       s.setAttribute(3, value);  
};

Content.getComponent("XfMw").setControlCallback(onXfMwControl);


inline function onXfAtControl(component, value)
{
for(s in Xfader)
	       s.setAttribute(37, value);
	for(s in Xfader2)
	       s.setAttribute(3, value);  
};

Content.getComponent("XfAt").setControlCallback(onXfAtControl);




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
  
  if(value == 5)
   {
   
   for(s in Xfader)
          s.setAttribute(33, 0);
   for(s in Xfader2)
          s.setAttribute(4, 4);  
   for(s in Xfader)
   	       s.setBypassed(1);
        for(s in Xfader2)
   	       s.setBypassed(0);  
   } 
if(value == 6)
 {
 
 for(s in Xfader)
        s.setAttribute(33, 0);
 for(s in Xfader2)
        s.setAttribute(4, 6);  
 for(s in Xfader)
 	       s.setBypassed(1);
      for(s in Xfader2)
 	       s.setBypassed(0);  
 } 
 
 if(value == 7)
  {
  
  for(s in Xfader)
         s.setAttribute(33, 0);
  for(s in Xfader2)
         s.setAttribute(4, 6);  
  for(s in Xfader)
  	       s.setBypassed(1);
       for(s in Xfader2)
  	       s.setBypassed(0);  
  } 
  
  if(value == 8)
   {
   
   for(s in Xfader)
          s.setAttribute(33, 0);
   for(s in Xfader2)
          s.setAttribute(4, 7);  
   for(s in Xfader)
   	       s.setBypassed(1);
        for(s in Xfader2)
   	       s.setBypassed(0);  
   } 
   
   if(value == 9)
    {
    
    for(s in Xfader)
           s.setAttribute(33, 0);
    for(s in Xfader2)
           s.setAttribute(4, 8);  
    for(s in Xfader)
    	       s.setBypassed(1);
         for(s in Xfader2)
    	       s.setBypassed(0);  
    } 
    
    if(value == 10)
     {
     
     for(s in Xfader)
            s.setAttribute(33, 0);
     for(s in Xfader2)
            s.setAttribute(4, 9);  
     for(s in Xfader)
     	       s.setBypassed(1);
          for(s in Xfader2)
     	       s.setBypassed(0);  
     } 
     
     if(value == 11)
          {
          
          for(s in Xfader)
                 s.setAttribute(33, 0);
          for(s in Xfader2)
                 s.setAttribute(4, 10);  
          for(s in Xfader)
          	       s.setBypassed(1);
               for(s in Xfader2)
          	       s.setBypassed(0);  
          } 
          
          if(value == 12)
               {
               
               for(s in Xfader)
                      s.setAttribute(33, 0);
               for(s in Xfader2)
                      s.setAttribute(4, 11);  
               for(s in Xfader)
               	       s.setBypassed(1);
                    for(s in Xfader2)
               	       s.setBypassed(0);  
               } 
};

Content.getComponent("Xfsel").setControlCallback(onXfselControl);



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
 
         
	}
	
		if(value == 2)
	{
for(s in Xfader)
	       s.setAttribute(7, 1.7);
      mods[0].showControl(0);  
      mods[1].showControl(1);   
      mods[2].showControl(0);  
 
	  
	}
	
	if(value == 3)
	{
	for(s in Xfader)
		       s.setAttribute(7, 2.70);
   mods[0].showControl(0);  
      mods[1].showControl(0);   
      mods[2].showControl(1);  
     
	  
	}

};


Content.getComponent("MODSEL1").setControlCallback(onMODSEL1Control);

const var XfDiv1 = Content.getComponent("XfDiv1");
const var XfEnv1 = Content.getComponent("XfEnv1");
const var XfEnv2 = Content.getComponent("XfEnv2");





inline function onXfsync1Control(component, value)
{
		for(s in Xfader)
	       s.setAttribute(41, value);
	       XfEnv1.showControl(value);  
	       XfEnv2.showControl(1-value);  
	       XfDiv1.showControl(1-value);  
	       	       
};

Content.getComponent("Xfsync1").setControlCallback(onXfsync1Control);



inline function onXfDiv1Control(component, value)
{
		for(s in Xfader)
	      s.setAttribute(40, value);
};

Content.getComponent("XfDiv1").setControlCallback(onXfDiv1Control);


inline function onXfA1Control(component, value)
{
		for(s in Xfader)
	       s.setAttribute(42, value);
};

Content.getComponent("XfA1").setControlCallback(onXfA1Control);



inline function onXfDD1Control(component, value)
{
		for(s in Xfader)
	       s.setAttribute(43, value);
};

Content.getComponent("XfDD1").setControlCallback(onXfDD1Control);


inline function onXfS1Control(component, value)
{
	for(s in Xfader)
	       s.setAttribute(27, value);
};

Content.getComponent("XfS1").setControlCallback(onXfS1Control);


inline function onXfR1Control(component, value)
{
	for(s in Xfader)
	       s.setAttribute(44, value);
};

Content.getComponent("XfR1").setControlCallback(onXfR1Control);


const var XfSp = Content.getComponent("XfSp");




