const var Wave1 = Content.getComponent("Wave1");

const var MenuBg = Content.getComponent("MenuBg");
const var LayerClose1 = Content.getComponent("LayerClose1");


const var WaveBoxes = [Content.getComponent("Wave8"),
                       Content.getComponent("Wave1"),
                       Content.getComponent("Wave2"),
                       Content.getComponent("Wave3"),
                       Content.getComponent("Wave4"),
                       Content.getComponent("Wave5"),
                       Content.getComponent("Wave6"),
                       Content.getComponent("Wave7"),
                       Content.getComponent("MenuBg"),
                       Content.getComponent("LayerClose1")];



const var WavePages =[];

for (i = 0; i < 8; i++)
{
    WavePages[i] = Content.getComponent("Wave"+(i+1));
//   WavePages[i].setControlCallback(EditButton);
}
 

inline function onEdit1Control(component, value)
{
	
	if (value == 0)
			{

	WavePages[0].showControl(1);
	WavePages[1].showControl(0);
	WavePages[2].showControl(0);
	WavePages[3].showControl(0);
	WavePages[4].showControl(0);
	WavePages[5].showControl(0);
	WavePages[6].showControl(0);
	WavePages[7].showControl(0);
	LayerClose1.showControl(1);
	MenuBg.showControl(1);
//	WtLoad1.getValue();
	
	}
	
	
};

Content.getComponent("Edit1").setControlCallback(onEdit1Control);

inline function onEdit2Control(component, value)
{
	if (value == 0)
			{

	WavePages[0].showControl(0);
	WavePages[1].showControl(1);
	WavePages[2].showControl(0);
	WavePages[3].showControl(0);
	WavePages[4].showControl(0);
	WavePages[5].showControl(0);
	WavePages[6].showControl(0);
	WavePages[7].showControl(0);
		LayerClose1.showControl(1);
	MenuBg.showControl(1);
	
	}
	
};

Content.getComponent("Edit2").setControlCallback(onEdit2Control);

inline function onEdit3Control(component, value)
{
	if (value == 0)
			{

	WavePages[0].showControl(0);
	WavePages[1].showControl(0);
	WavePages[2].showControl(1);
	WavePages[3].showControl(0);
	WavePages[4].showControl(0);
	WavePages[5].showControl(0);
	WavePages[6].showControl(0);
	WavePages[7].showControl(0);
	LayerClose1.showControl(1);
	MenuBg.showControl(1);
	}
	
};

Content.getComponent("Edit3").setControlCallback(onEdit3Control);

inline function onEdit4Control(component, value)
{
	if (value == 0)
			{

	WavePages[0].showControl(0);
	WavePages[1].showControl(0);
	WavePages[2].showControl(0);
	WavePages[3].showControl(1);
	WavePages[4].showControl(0);
	WavePages[5].showControl(0);
	WavePages[6].showControl(0);
	WavePages[7].showControl(0);
	LayerClose1.showControl(1);
	MenuBg.showControl(1);
	}
};

Content.getComponent("Edit4").setControlCallback(onEdit4Control);

inline function onEdit5Control(component, value)
{
	
	if (value == 0)
			{
	WavePages[0].showControl(0);
	WavePages[1].showControl(0);
	WavePages[2].showControl(0);
	WavePages[3].showControl(0);
	WavePages[4].showControl(1);
	WavePages[5].showControl(0);
	WavePages[6].showControl(0);
	WavePages[7].showControl(0);
	LayerClose1.showControl(1);
	MenuBg.showControl(1);
	}
};

Content.getComponent("Edit5").setControlCallback(onEdit5Control);

inline function onEdit6Control(component, value)
{
	if (value == 0)
			{

	WavePages[0].showControl(0);
	WavePages[1].showControl(0);
	WavePages[2].showControl(0);
	WavePages[3].showControl(0);
	WavePages[4].showControl(0);
	WavePages[5].showControl(1);
	WavePages[6].showControl(0);
	WavePages[7].showControl(0);
	LayerClose1.showControl(1);
	MenuBg.showControl(1);
	}
};

Content.getComponent("Edit6").setControlCallback(onEdit6Control);

inline function onEdit7Control(component, value)
{
	if (value == 0)
			{

	WavePages[0].showControl(0);
	WavePages[1].showControl(0);
	WavePages[2].showControl(0);
	WavePages[3].showControl(0);
	WavePages[4].showControl(0);
	WavePages[5].showControl(0);
	WavePages[6].showControl(1);
	WavePages[7].showControl(0);
	LayerClose1.showControl(1);
	MenuBg.showControl(1);
	}
};

Content.getComponent("Edit7").setControlCallback(onEdit7Control);

inline function onEdit8Control(component, value)
{
	if (value == 0)
			{

	WavePages[0].showControl(0);
	WavePages[1].showControl(0);
	WavePages[2].showControl(0);
	WavePages[3].showControl(0);
	WavePages[4].showControl(0);
	WavePages[5].showControl(0);
	WavePages[6].showControl(0);
	WavePages[7].showControl(1);
	LayerClose1.showControl(1);
	MenuBg.showControl(1);
	}
	
};

Content.getComponent("Edit8").setControlCallback(onEdit8Control);


inline function onLayerClose1Control(component, value)
{
	if(value == 1)
		{

  for(s in WaveBoxes)
	              s.showControl(0);
	              
	         }
};

Content.getComponent("LayerClose1").setControlCallback(onLayerClose1Control);

const var Wtbl = [Content.getComponent("Wt1"),
		Content.getComponent("Wt2"),
		Content.getComponent("Wt3"),
		Content.getComponent("Wt4"),
		Content.getComponent("Wt5"),
		Content.getComponent("Wt6"),
		Content.getComponent("Wt7"),
		Content.getComponent("Wt8")];

const var WtLoad = [Content.getComponent("WtLoad1"),
			Content.getComponent("WtLoad2"),
			Content.getComponent("WtLoad3"),
			Content.getComponent("WtLoad4"),
			Content.getComponent("WtLoad5"),
			Content.getComponent("WtLoad6"),
			Content.getComponent("WtLoad7"),
			Content.getComponent("WtLoad8")];

const var LpLoad = [Content.getComponent("LpLoad1"),
					Content.getComponent("LpLoad2"),
					Content.getComponent("LpLoad3"),
					Content.getComponent("LpLoad4"),
					Content.getComponent("LpLoad5"),
					Content.getComponent("LpLoad6"),
					Content.getComponent("LpLoad7"),
					Content.getComponent("LpLoad8"),
					Content.getComponent("LoadAllLoop")
					];

const var SfzLd = [Content.getComponent("Sfz1"),
			 Content.getComponent("Sfz2"),
			Content.getComponent("Sfz3"),
			Content.getComponent("Sfz4"),
			Content.getComponent("Sfz5"),
			Content.getComponent("Sfz6"),
			Content.getComponent("Sfz7"),
			Content.getComponent("Sfz8"),
			Content.getComponent("SfzAll")];

const var Wtbls = [Content.getComponent("Wt1"),
					Content.getComponent("Wt2"),
					Content.getComponent("Wt3"),
					Content.getComponent("Wt4"),
					Content.getComponent("Wt5"),
					Content.getComponent("Wt6"),
					Content.getComponent("Wt7"),
					Content.getComponent("Wt8"),
					Content.getComponent("WtAll")];

const var Samplers = [Synth.getChildSynth("SamplerA1"),
					Synth.getChildSynth("SamplerA2"),
					Synth.getChildSynth("SamplerA3"),
					Synth.getChildSynth("SamplerA4"),
					Synth.getChildSynth("SamplerA5"),
					Synth.getChildSynth("SamplerA6"),
					Synth.getChildSynth("SamplerA7"),
					Synth.getChildSynth("SamplerA8")];
				
const var loops = [
				Synth.getChildSynth("LoopA1"),
				Synth.getChildSynth("LoopA2"),
				Synth.getChildSynth("LoopA2"),
				Synth.getChildSynth("LoopA3"),
				Synth.getChildSynth("LoopA4"),
				Synth.getChildSynth("LoopA5"),
				Synth.getChildSynth("LoopA6"),
				Synth.getChildSynth("LoopA7"),
				Synth.getChildSynth("LoopA8")];		
			
const var SfZs = [Synth.getChildSynth("Sfz1"),
				Synth.getChildSynth("Sfz2"),
				Synth.getChildSynth("Sfz3"),
				Synth.getChildSynth("Sfz4"),
				Synth.getChildSynth("Sfz5"),
				Synth.getChildSynth("Sfz6"),
				Synth.getChildSynth("Sfz7"),
				Synth.getChildSynth("Sfz8")];	
				
const var Groups = [Synth.getChildSynth("Group1"),
				Synth.getChildSynth("Group2"),
				Synth.getChildSynth("Group3"),
				Synth.getChildSynth("Group4"),
				Synth.getChildSynth("Group5"),
				Synth.getChildSynth("Group6"),
				Synth.getChildSynth("Group7"),
				Synth.getChildSynth("Group8")];	
				
const var EditPages = [Content.getComponent("Wave8"),
                       Content.getComponent("Wave1"),
                       Content.getComponent("Wave2"),
                       Content.getComponent("Wave3"),
                       Content.getComponent("Wave4"),
                       Content.getComponent("Wave5"),
                       Content.getComponent("Wave6"),
                       Content.getComponent("Wave7")];

const var SamplerGroup = [Synth.getChildSynth("SamplerA1"),
				  Synth.getChildSynth("SamplerA2"),
				  Synth.getChildSynth("SamplerA3"),
				  Synth.getChildSynth("SamplerA4"),
				  Synth.getChildSynth("SamplerA5"),
				  Synth.getChildSynth("SamplerA6"),
				  Synth.getChildSynth("SamplerA7"),
				  Synth.getChildSynth("SamplerA8")];
				  
const var LoopGroup = [Synth.getChildSynth("LoopA1"),
				  Synth.getChildSynth("LoopA2"),
				  Synth.getChildSynth("LoopA3"),
				  Synth.getChildSynth("LoopA4"),
				  Synth.getChildSynth("LoopA5"),
				  Synth.getChildSynth("LoopA6"),
				  Synth.getChildSynth("LoopA7"),
				 Synth.getChildSynth("LoopA8")];   

const var Wtable = [Synth.getChildSynth("Wt1"),
			Synth.getChildSynth("Wt2"),
			Synth.getChildSynth("Wt3"),
			Synth.getChildSynth("Wt4"),
			Synth.getChildSynth("Wt5"),
			Synth.getChildSynth("Wt6"),
			Synth.getChildSynth("Wt7"),
			Synth.getChildSynth("Wt8")];				 				 				                

const var Banks = [Content.getComponent("BankA1"),
                    Content.getComponent("BankA2"),
                    Content.getComponent("BankA3"),
                    Content.getComponent("BankA4"),
                    Content.getComponent("BankA5"),
                    Content.getComponent("BankA6"),
                    Content.getComponent("BankA7"),
                    Content.getComponent("BankA8"),
                    Content.getComponent("BankA11")
                    ];

const var SampleControls = [Content.getComponent("Waves1"),
                            Content.getComponent("Waves2"),
                            Content.getComponent("Waves3"),
                            Content.getComponent("Waves4"),
                            Content.getComponent("Waves5"),
                            Content.getComponent("Waves6"),
                            Content.getComponent("Waves7"),
                            Content.getComponent("Waves8")];

const var LpControl = [Content.getComponent("LpControls8"),
                       Content.getComponent("LpControls7"),
                       Content.getComponent("LpControls6"),
                       Content.getComponent("LpControls5"),
                       Content.getComponent("LpControls4"),
                       Content.getComponent("LpControls3"),
                       Content.getComponent("LpControls2"),
                       Content.getComponent("LpControls1")];

const var SfzControls = [Content.getComponent("SfzLoad1"),
                         Content.getComponent("SfzLoad2"),
                         Content.getComponent("SfzLoad3"),
                         Content.getComponent("SfzLoad4"),
                         Content.getComponent("SfzLoad5"),
                         Content.getComponent("SfzLoad6"),
                         Content.getComponent("SfzLoad7"),
                         Content.getComponent("SfzLoad8")];


const var SampleMode1 = Content.getComponent("SampleMode1");



inline function onSampleMode1Control(component, value)
{


if(value == 1)
	{
		
	Engine.allNotesOff();
	
	for(s in Banks) s.showControl(1);
	for(s in SampleControls) s.showControl(1);  
	for(s in SamplerGroup) s.setBypassed(0); 
	
	for(s in SfzControls) s.showControl(0);
	for(s in SfzLd) s.showControl(0);  	      
	for(s in SfZs) s.setBypassed(1);
	       
	for(s in LpLoad) s.showControl(0);
    for(s in LpControl) s.showControl(0);  
	for(s in LoopGroup) s.setBypassed(1);

	for(s in Wtbls) s.showControl(0);
    for(s in WtLoad) s.showControl(0);  
	for(s in Wtable) s.setBypassed(1);
	
	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	
	for(s in Banks) s.showControl(0);
	for(s in SampleControls) s.showControl(0);  
	for(s in SamplerGroup) s.setBypassed(1); 
	       
	for(s in SfzControls) s.showControl(0);
	for(s in SfzLd) s.showControl(0);  	      
	for(s in SfZs) s.setBypassed(1);
	       
	for(s in LpLoad) s.showControl(1);
    for(s in LpControl) s.showControl(1);  
	for(s in LoopGroup) s.setBypassed(0);


	for(s in Wtbls) s.showControl(0);
    for(s in WtLoad) s.showControl(0);  
	for(s in Wtable) s.setBypassed(1);
	

	
	}
	
if(value == 3)
	{
	
	//sampler
	
	for(s in WavesFM) s.showControl(0);
	for(s in SfzLoadFm) s.showControl(0);
	for(s in LpControlsFm) s.showControl(0);
	for(s in WtFm) s.showControl(0);		       		       	       

	for(s in Groups) s.setAttribute(s.CarrierIndex, 0);
	for(s in Groups) s.setAttribute(s.ModulatorIndex, 0);
	for(s in Groups) s.setAttribute(s.EnableFM, 0);
	
	for(s in Banks) s.showControl(0);
	for(s in SampleControls) s.showControl(0);  
	for(s in SamplerGroup) s.setBypassed(1); 
	       
	for(s in SfzControls) s.showControl(1);
	for(s in SfzLd) s.showControl(1);  	      
	for(s in SfZs) s.setBypassed(0);

	       
	for(s in LpLoad) s.showControl(0);
    for(s in LpControl) s.showControl(0);  
	for(s in LoopGroup) s.setBypassed(1);

	for(s in Wtbls) s.showControl(0);
    for(s in WtLoad) s.showControl(0);  
	for(s in Wtable) s.setBypassed(1);
	

	}
	
	if(value == 4)
		{
	
	      
	
	for(s in Banks) s.showControl(0);
	for(s in SampleControls) s.showControl(0);  
	for(s in SamplerGroup) s.setBypassed(1); 
	       
	for(s in SfzControls) s.showControl(0);
	for(s in SfzLd) s.showControl(0);  	      
	for(s in SfZs) s.setBypassed(1);
	       
	for(s in LpLoad) s.showControl(0);
    for(s in LpControl) s.showControl(0);  
	for(s in LoopGroup) s.setBypassed(1);

	for(s in Wtbls) s.showControl(1);
    for(s in WtLoad) s.showControl(1);  
	for(s in Wtable) s.setBypassed(0);

	


		
		}
		
												

};

Content.getComponent("SampleMode1").setControlCallback(onSampleMode1Control);



