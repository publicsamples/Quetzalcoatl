//Filter

const var Filters = [Synth.getEffect("Filter1"),
					Synth.getEffect("Filter2"),
					Synth.getEffect("Filter3"),
					Synth.getEffect("Filter4"),
					Synth.getEffect("Filter5"),
					Synth.getEffect("Filter6"),
					Synth.getEffect("Filter7"),
					Synth.getEffect("Filter8"),
					Synth.getEffect("FilterB"),
					];


const var fmod = [Synth.getModulator("fmod1"),
					Synth.getModulator("fmod2"),
					Synth.getModulator("fmod3"),
					Synth.getModulator("fmod4"),
					Synth.getModulator("fmod5"),
					Synth.getModulator("fmod6"),
					Synth.getModulator("fmod7"),
					Synth.getModulator("fmod8"),
					Synth.getModulator("fmod9"),
					];

inline function onCutModControl(component, value)
{
	for(s in fmod)
        s.setAttribute(34, value);
};

Content.getComponent("CutMod").setControlCallback(onCutModControl);


inline function onCutModSrcControl(component, value)
{
	for(s in Filters)
        s.setAttribute(29, value);
};

Content.getComponent("CutModSrc").setControlCallback(onCutModSrcControl);

const var Fslliders = Synth.getModulator("Fslliders");


inline function onFilterCutControl(component, value)
{


for(s in Filters)
        s.setAttribute(1, value);
       
};

Content.getComponent("FilterCut").setControlCallback(onFilterCutControl);


inline function onResControl(component, value)
{
	for(s in Filters)
        s.setAttribute(2, value);
};

Content.getComponent("Res").setControlCallback(onResControl);


inline function onFilterTypeControl(component, value)
{

  if(value == 1)
  
        {
	for(s in Filters)
	        s.setAttribute(3, 6);
	        }

if(value == 2)

      {
	for(s in Filters)
	        s.setAttribute(3, 7);
	        }
	        
	  if(value == 3)
	  
	        {
	  	for(s in Filters)
	  	        s.setAttribute(3, 12);
	  	        }
	  if(value == 4)
	  	  
	  	        {
	  	  	for(s in Filters)
	  	  	        s.setAttribute(3, 13);
	  	  	        }	        
	 if(value == 5)
	 	  	  
	 	  	        {
	 	  	  	for(s in Filters)
	 	  	  	        s.setAttribute(3, 2);
	 	  	  	        }	  	        	        
	        
	 if(value == 6)
	 	 	  	  
	 	 	  	        {
	 	 	  	  	for(s in Filters)
	 	 	  	  	        s.setAttribute(3, 3);
	 	 	  	  	        }
	 	 	  	  	        
	if(value == 7)
		 	  	  
		 	  	        {
		 	  	  	for(s in Filters)
		 	  	  	        s.setAttribute(3, 4);
		 	  	  	        }	  	 
		 	  	  	        
	if(value == 8)
		 	  	  
		 	  	        {
		 	  	  	for(s in Filters)
		 	  	  	        s.setAttribute(3, 8);
		 	  	  	        }	
		 	  	  	        
	if(value == 9)
		 	  	  
		 	  	        {
		 	  	  	for(s in Filters)
		 	  	  	        s.setAttribute(3, 9);
		 	  	  	        }	
		 	  	  	        
	if(value == 10)
		 	  	  
		 	  	        {
		 	  	  	for(s in Filters)
		 	  	  	        s.setAttribute(3, 10);
		 	  	  	        }	
		 	  	  	        
	if(value == 11)
		 	  	  
		 	  	        {
		 	  	  	for(s in Filters)
		 	  	  	        s.setAttribute(3, 14);
		 	  	  	        }		 	  	  	        	 	  	  	        	 	  	  	        	 	  	  	          	 	  	  	     	  	  

	if(value == 12)
	 	  	  
	 	  	        {
	 	  	  	for(s in Filters)
	 	  	  	        s.setAttribute(3, 15);
	 	  	  	        }	
	 	  	  	        
	 if(value == 13)
	  	  	  
	  	  	        {
	  	  	  	for(s in Filters)
	  	  	  	        s.setAttribute(3, 17);
	  	  	  	        }	
	  	  	  	        
	  	  	  	        	  	  	        
};

Content.getComponent("FilterType").setControlCallback(onFilterTypeControl);




inline function onFtempo1Control(component, value)
{
for(s in Filters)
	       s.setAttribute(6, value);

for(s in Pitches)
	       s.setAttribute(6, value);	     
	       


 
}

Content.getComponent("Ftempo1").setControlCallback(onFtempo1Control);


inline function onXfDiv2Control(component, value)
{
for(s in Filters)
	       s.setAttribute(7, value);
for(s in Pitches)
	       s.setAttribute(7, value);	


	    
};

Content.getComponent("XfDiv2").setControlCallback(onXfDiv2Control);


inline function onFtempo2Control(component, value)
{
for(s in Filters)
	       s.setAttribute(10, value);
	       for(s in Pitches)
	       	       s.setAttribute(10, value);

};

Content.getComponent("Ftempo2").setControlCallback(onFtempo1Control);


const var Ftempo1 = Content.getComponent("Ftempo1");
const var Ftempo2 = Content.getComponent("Ftempo2");



const var synclabel7 = Content.getComponent("synclabel7");

const var freelabel7 = Content.getComponent("freelabel7");


inline function onXfsync2Control(component, value)
{
	if(value == 0)
	{
	
for(s in Filters)
	       s.setAttribute(30, value);
	       for(s in Pitches)
	       	       s.setAttribute(30, value);

	
	Ftempo1.showControl(0);  
	Ftempo2.showControl(1);   
	synclabel7.showControl(0);  
	freelabel7.showControl(1);   
	 
	 }
	 
	 if(value == 1)
	 	{
for(s in Filters)
	       s.setAttribute(30, value);
	       for(s in Pitches)
	       	       s.setAttribute(30, value);


	Ftempo1.showControl(1);  
	Ftempo2.showControl(0);   
	synclabel7.showControl(1);  
	freelabel7.showControl(0); 
	}
};

Content.getComponent("Xfsync2").setControlCallback(onXfsync2Control);


inline function onXfA2Control(component, value)
{
for(s in Filters)
	       s.setAttribute(2, value);
	       for(s in Pitches)
	       	       s.setAttribute(2, value);

};

Content.getComponent("XfA2").setControlCallback(onXfA2Control);


inline function onXfDD2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(3, value);
	       for(s in Pitches)
	       	       s.setAttribute(3, value);

};

Content.getComponent("XfDD2").setControlCallback(onXfDD2Control);


inline function onXfS2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(4, value);
	       for(s in Pitches)
	       	       s.setAttribute(4, value);

};

Content.getComponent("XfS2").setControlCallback(onXfS2Control);


inline function onXfR2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(5, value);
	       for(s in Pitches)
	       	       s.setAttribute(5, value);

};

Content.getComponent("XfR2").setControlCallback(onXfR2Control);


inline function onLfoShapeXF2Control(component, value)
{
	for(s in Filters)
	      s.setAttribute(5, value);
	      for(s in Pitches)
	      	       s.setAttribute(10, value);

};

Content.getComponent("LfoShapeXF2").setControlCallback(onLfoShapeXF2Control);



inline function onXfStg17Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(12, value);
	       for(s in Pitches)
	       	       s.setAttribute(12, value);
};

Content.getComponent("XfStg17").setControlCallback(onXfStg17Control);



inline function onXfStg18Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(13, value);
	       for(s in Pitches)
	       	       s.setAttribute(13, value);
};

Content.getComponent("XfStg18").setControlCallback(onXfStg18Control);

inline function onXfStg19Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(14, value);
	       for(s in Pitches)
	       	       s.setAttribute(14, value);
};

Content.getComponent("XfStg19").setControlCallback(onXfStg19Control);

inline function onXfStg20Control(component, value)
{
		for(s in Filters)
	       s.setAttribute(15, value);
	       for(s in Pitches)
	       	       s.setAttribute(15, value);
};

Content.getComponent("XfStg20").setControlCallback(onXfStg20Control);

inline function onXfStg21Control(component, value)
{
		for(s in Filters)
	       s.setAttribute(16, value);
	       for(s in Pitches)
	       	       s.setAttribute(16, value);
};

Content.getComponent("XfStg21").setControlCallback(onXfStg21Control);

inline function onXfStg22Control(component, value)
{
		for(s in Filters)
	       s.setAttribute(17, value);
	       for(s in Pitches)
	       	       s.setAttribute(17, value);
};

Content.getComponent("XfStg22").setControlCallback(onXfStg22Control);


inline function onXfStg23Control(component, value)
{
		for(s in Filters)
	       s.setAttribute(18, value);
	       for(s in Pitches)
	       	       s.setAttribute(18, value);
};

Content.getComponent("XfStg23").setControlCallback(onXfStg23Control);


inline function onXfStg24Control(component, value)
{
		for(s in Filters)
	       s.setAttribute(19, value);
	       for(s in Pitches)
	       	       s.setAttribute(19, value);
};

Content.getComponent("XfStg24").setControlCallback(onXfStg24Control);

const var MODSEL7 = Content.getComponent("MODSEL7");

const var modsF = [];

modsF[0] = Content.getComponent("env4");
modsF[1] = Content.getComponent("Table7");
modsF[2] = Content.getComponent("8step7");
modsF[3] = Content.getComponent("8Trig7");

inline function onMODSEL7Control(component, value)

{

	if(value == 1)
	{
	for(s in Filters)
	       s.setAttribute(9, 0);
	       for(s in Pitches)
	       	       s.setAttribute(9, 0);
      modsF[0].showControl(1);  
      modsF[1].showControl(0);   
      modsF[2].showControl(0);  
      modsF[3].showControl(0);    
         
	}
	
		if(value == 2)
	{
for(s in Filters)
	       s.setAttribute(9, 1.7);
	       for(s in Pitches)
	       	       s.setAttribute(9, 1.7);
      modsF[0].showControl(0);  
      modsF[1].showControl(1);   
      modsF[2].showControl(0);  
      modsF[3].showControl(0);  
	  
	}
	
	if(value == 3)
	{
	for(s in Filters)
		       s.setAttribute(9, 2.70);
	for(s in Pitches)
		       	       s.setAttribute(9, 2.7);	       
   modsF[0].showControl(0);  
      modsF[1].showControl(0);   
      modsF[2].showControl(1);  
      modsF[3].showControl(0);  
	  
	}
	
	if(value == 4)
	{
	for(s in Filters)
			       s.setAttribute(9, 4);
			       for(s in Pitches)
			       	       	       s.setAttribute(9, 4);
   modsF[0].showControl(0);  
      modsF[1].showControl(0);   
      modsF[2].showControl(0);  
      modsF[3].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL7").setControlCallback(onMODSEL7Control);

const var OneShtLabel3 = Content.getComponent("OneShtLabel3");
const var LoopLabel3 = Content.getComponent("LoopLabel3");


inline function onXfTrigMode2Control(component, value)
{
	if(value == 0)
	{
		
for(s in Filters)
	       s.setAttribute(8, value);
	       for(s in Pitches)
	       	       	       s.setAttribute(8, value);

	LoopLabel3.showControl(0);  
	     OneShtLabel3.showControl(1);   
	     }
	     
	     	if(value == 1)
	     {
for(s in Filters)
	       s.setAttribute(8, value);
for(s in Pitches)
s.setAttribute(8, value);

	LoopLabel3.showControl(1);  
	     OneShtLabel3.showControl(0);
	     }  
};

Content.getComponent("XfTrigMode2").setControlCallback(onXfTrigMode2Control);


Content.getComponent("XfTrigMode2").setControlCallback(onXfTrigMode2Control);