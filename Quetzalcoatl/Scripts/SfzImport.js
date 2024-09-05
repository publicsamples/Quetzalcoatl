const var Sz1 = Synth.getSampler("Sfz1");
const var Sz2 = Synth.getSampler("Sfz2");
const var Sz3 = Synth.getSampler("Sfz3");
const var Sz4 = Synth.getSampler("Sfz4");
const var Sz5 = Synth.getSampler("Sfz5");
const var Sz6 = Synth.getSampler("Sfz6");
const var Sz7 = Synth.getSampler("Sfz7");
const var Sz8 = Synth.getSampler("Sfz8");


const var Sfz1 = Synth.getChildSynth("Sfz1");
const var Sfz2 = Synth.getChildSynth("Sfz2");
const var Sfz3 = Synth.getChildSynth("Sfz3");
const var Sfz4 = Synth.getChildSynth("Sfz4");
const var Sfz5 = Synth.getChildSynth("Sfz5");
const var Sfz6 = Synth.getChildSynth("Sfz6");
const var Sfz7 = Synth.getChildSynth("Sfz7");
const var Sfz8 = Synth.getChildSynth("Sfz8");

const var SfzLoad1 = Content.getComponent("SfzLoad1");
const var SfzLoad2 = Content.getComponent("SfzLoad2");
const var SfzLoad3 = Content.getComponent("SfzLoad3");
const var SfzLoad4 = Content.getComponent("SfzLoad4");
const var SfzLoad5 = Content.getComponent("SfzLoad5");
const var SfzLoad6 = Content.getComponent("SfzLoad6");
const var SfzLoad7 = Content.getComponent("SfzLoad7");
const var SfzLoad8 = Content.getComponent("SfzLoad8");

const var LabelsSfz1 = [];

LabelsSfz1[0] = Content.getComponent("SfzLabelStore1");
LabelsSfz1[1] = Content.getComponent("SfzLabelStore2");
LabelsSfz1[2] = Content.getComponent("SfzLabelStore3");
LabelsSfz1[3] = Content.getComponent("SfzLabelStore4");
LabelsSfz1[4] = Content.getComponent("SfzLabelStore5");
LabelsSfz1[5] = Content.getComponent("SfzLabelStore6");
LabelsSfz1[6] = Content.getComponent("SfzLabelStore7");
LabelsSfz1[7] = Content.getComponent("SfzLabelStore8");

const var Sf1 = Synth.getSampler("Sfz1");
const var Sf2 = Synth.getSampler("Sfz2");
const var Sf3 = Synth.getSampler("Sfz3");
const var Sf4 = Synth.getSampler("Sfz4");
const var Sf5 = Synth.getSampler("Sfz5");
const var Sf6 = Synth.getSampler("Sfz6");
const var Sf7 = Synth.getSampler("Sfz7");
const var Sf8 = Synth.getSampler("Sfz8");

///SFZ

const var SfzLabelStore1 = Content.getComponent("SfzLabelStore1");
const var SfzLabelStore2 = Content.getComponent("SfzLabelStore2");
const var SfzLabelStore3 = Content.getComponent("SfzLabelStore3");
const var SfzLabelStore4 = Content.getComponent("SfzLabelStore4");
const var SfzLabelStore5 = Content.getComponent("SfzLabelStore5");
const var SfzLabelStore6 = Content.getComponent("SfzLabelStore6");
const var SfzLabelStore7 = Content.getComponent("SfzLabelStore7");
const var SfzLabelStore8 = Content.getComponent("SfzLabelStore8");


Sf1.loadSfzFile(SfzLabelStore1.get("text"));
Sf2.loadSfzFile(SfzLabelStore2.get("text"));
Sf3.loadSfzFile(SfzLabelStore3.get("text"));
Sf4.loadSfzFile(SfzLabelStore4.get("text"));
Sf5.loadSfzFile(SfzLabelStore5.get("text"));
Sf6.loadSfzFile(SfzLabelStore6.get("text"));
Sf7.loadSfzFile(SfzLabelStore7.get("text"));
Sf8.loadSfzFile(SfzLabelStore8.get("text"));


inline function onSfzAllControl(component, value)
{
	
 for(s in AllMenus)
             s.setValue(3);
             
             for(s in AllMenus)
                    s.changed();    
	    

//Sampler1.setBypassed(1); Sampler2.setBypassed(1); Sampler3.setBypassed(1); 	Sampler4.setBypassed(1); Sampler5.setBypassed(1); Sampler6.setBypassed(1); 	Sampler7.setBypassed(1); Sampler8.setBypassed(1); 	
		
//Sfz1.setBypassed(0); Sfz2.setBypassed(0); Sfz3.setBypassed(0); Sfz4.setBypassed(0); Sfz5.setBypassed(0); Sfz6.setBypassed(0); Sfz7.setBypassed(0); Sfz8.setBypassed(0);
	
//loop1.setBypassed(1); loop2.setBypassed(1); loop3.setBypassed(1); loop4.setBypassed(1); loop5.setBypassed(1); loop6.setBypassed(1); loop7.setBypassed(1); loop8.setBypassed(1);            
	              

		if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

Sf1.loadSfzFile(f.toString(File.FullPath));
	
		LabelsSfz1[0].set("text", f.toString(f.FullPath));
	
		Sf2.loadSfzFile(f.toString(File.FullPath));

		    		LabelsSfz1[1].set("text", f.toString(f.FullPath));	
		    	
		    		Sf3.loadSfzFile(f.toString(File.FullPath));

		    		     		LabelsSfz1[2].set("text", f.toString(f.FullPath));

		    		     		Sf4.loadSfzFile(f.toString(File.FullPath));

		    		     		      		LabelsSfz1[3].set("text", f.toString(f.FullPath));

		    		     		      		Sf5.loadSfzFile(f.toString(File.FullPath));


		    		     		      		       		LabelsSfz1[4].set("text", f.toString(f.FullPath));	
Sf6.loadSfzFile(f.toString(File.FullPath));

        		LabelsSfz1[5].set("text", f.toString(f.FullPath));

Sf7.loadSfzFile(f.toString(File.FullPath));

         		LabelsSfz1[6].set("text", f.toString(f.FullPath));

 
 Sf8.loadSfzFile(f.toString(File.FullPath));

           		LabelsSfz1[7].set("text", f.toString(f.FullPath));

Sample1.set("text", f.toString(f.NoExtension));
Sample2.set("text", f.toString(f.NoExtension));
Sample3.set("text", f.toString(f.NoExtension));
Sample4.set("text", f.toString(f.NoExtension));
Sample5.set("text", f.toString(f.NoExtension));
Sample6.set("text", f.toString(f.NoExtension));
Sample7.set("text", f.toString(f.NoExtension));
Sample8.set("text", f.toString(f.NoExtension));

		    		     		      		       			    		     		      		       		
		    				
	});	

}

};

Content.getComponent("SfzAll").setControlCallback(onSfzAllControl);

inline function onSfz1Control(component, value)
{
		if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

Sf1.loadSfzFile(f.toString(File.FullPath));
	
		LabelsSfz1[0].set("text", f.toString(f.FullPath));

		Sample1.set("text", f.toString(f.NoExtension));		
	});	

}

};

Content.getComponent("Sfz1").setControlCallback(onSfz1Control);

inline function onSfzLabelStore1Control(component, value)
{
	
Sf1.loadSfzFile(value);
};

Content.getComponent("SfzLabelStore1").setControlCallback(onSfzLabelStore1Control);


    
    inline function onSfz2Control(component, value)
    {
    		if (value)
    		{
    		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
    	{
    		
    
    		Sf2.loadSfzFile(f.toString(File.FullPath));
    	Sample2.set("text", f.toString(f.NoExtension));
    		LabelsSfz1[1].set("text", f.toString(f.FullPath));	

    	});	
    
    }
    
    };
    
    Content.getComponent("Sfz2").setControlCallback(onSfz2Control);
    
    inline function onSfzLabelStore2Control(component, value)
    {
    	
    Sf2.loadSfzFile(value);
    };
    
    Content.getComponent("SfzLabelStore2").setControlCallback(onSfzLabelStore2Control);
    
    
    
    inline function onSfz3Control(component, value)
     {
     		if (value)
     		{
     		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
     	{
     		
     
     		Sf3.loadSfzFile(f.toString(File.FullPath));
     		Sample3.set("text", f.toString(f.NoExtension));	
     		LabelsSfz1[2].set("text", f.toString(f.FullPath));

     	});	
     
     }
     
     };
     
     Content.getComponent("Sfz3").setControlCallback(onSfz3Control);
    	
  
  inline function onSfzLabelStore3Control(component, value)
  {
  	
  Sf3.loadSfzFile(value);
  };
  
  Content.getComponent("SfzLabelStore3").setControlCallback(onSfzLabelStore3Control);
  
  
  
  
  
     inline function onSfz4Control(component, value)
      {
      		if (value)
      		{
      		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
      	{
     		
    
      		Sf4.loadSfzFile(f.toString(File.FullPath));
      		Sample4.set("text", f.toString(f.NoExtension));	
      		LabelsSfz1[3].set("text", f.toString(f.FullPath));

      	});	
     
      }
     
      };
     
      Content.getComponent("Sfz4").setControlCallback(onSfz4Control);
      
      
      inline function onSfzLabelStore4Control(component, value)
      {
      	
      Sf4.loadSfzFile(value);
      };
      
      Content.getComponent("SfzLabelStore4").setControlCallback(onSfzLabelStore4Control);
      
     
    	 
      inline function onSfz5Control(component, value)
       {
       		if (value)
       		{
       		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
       	{
     		
     
       		Sf5.loadSfzFile(f.toString(File.FullPath));
       		Sample5.set("text", f.toString(f.NoExtension));
       		SfzLabel5.set("text", f.toString(f.NoExtension));	

       	});	
     
       }
     
       };
     
       Content.getComponent("Sfz5").setControlCallback(onSfz5Control);
       
       inline function onSfzLabelStore5Control(component, value)
       {
       	
       Sf5.loadSfzFile(value);
       };
       
       Content.getComponent("SfzLabelStore5").setControlCallback(onSfzLabelStore5Control);
       
       
    	  
       inline function onSfz6Control(component, value)
        {
        		if (value)
        		{
        		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
        	{
     		
     
        		Sf6.loadSfzFile(f.toString(File.FullPath));
        		Sample6.set("text", f.toString(f.NoExtension));
        		LabelsSfz1[5].set("text", f.toString(f.FullPath));

        	});	
     
        }
     
        };
     
        Content.getComponent("Sfz6").setControlCallback(onSfz6Control);
    	   
    	   inline function onSfzLabelStore6Control(component, value)
    	   {
    	   	
    	   Sf6.loadSfzFile(value);
    	   };
    	   
    	   Content.getComponent("SfzLabelStore6").setControlCallback(onSfzLabelStore6Control);
    	   
    	   
    	   
        inline function onSfz7Control(component, value)
         {
         		if (value)
         		{
         		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
         	{
     		
     
         		Sf7.loadSfzFile(f.toString(File.FullPath));
         		Sample7.set("text", f.toString(f.NoExtension));
         		LabelsSfz1[6].set("text", f.toString(f.FullPath));

         	});	
     
         }
     
         };
     
         Content.getComponent("Sfz7").setControlCallback(onSfz7Control);
         
           inline function onSfzLabelStore7Control(component, value)
           {
           	
           Sf7.loadSfzFile(value);
           };
           
           Content.getComponent("SfzLabelStore7").setControlCallback(onSfzLabelStore7Control);
           
           
    		
         inline function onSfz8Control(component, value)
          {
          		if (value)
          		{
          		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
          	{
     		
     
          		Sf8.loadSfzFile(f.toString(File.FullPath));
          		Sample8.set("text", f.toString(f.NoExtension));
          		LabelsSfz1[7].set("text", f.toString(f.FullPath));

          	});	
     
          }
     
          };
     
          Content.getComponent("Sfz8").setControlCallback(onSfz8Control);
          
          inline function onSfzLabelStore8Control(component, value)
          {
          	
          Sf8.loadSfzFile(value);
          };
          
          Content.getComponent("SfzLabelStore8").setControlCallback(onSfzLabelStore8Control);
 