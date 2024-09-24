const var Wave1 = Content.getComponent("Wave1");

const var WaveBoxes = [Content.getComponent("Wave8"),
                       Content.getComponent("Wave1"),
                       Content.getComponent("Wave2"),
                       Content.getComponent("Wave3"),
                       Content.getComponent("Wave4"),
                       Content.getComponent("Wave5"),
                       Content.getComponent("Wave6"),
                       Content.getComponent("Wave7")];


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
	VarMenu1.setValue(0);
	VarMenu1.changed();
	
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
	VarMenu1.setValue(0);
	VarMenu1.changed();

	
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
	VarMenu1.setValue(0);
	VarMenu1.changed();

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
	VarMenu1.setValue(0);
	VarMenu1.changed();

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
	VarMenu1.setValue(0);
	VarMenu1.changed();

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
	VarMenu1.setValue(0);
	VarMenu1.changed();

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
	VarMenu1.setValue(0);
	VarMenu1.changed();
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
	VarMenu1.setValue(0);
	VarMenu1.changed();

	}
	
};

Content.getComponent("Edit8").setControlCallback(onEdit8Control);


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
				 
const var UserLoop = [Synth.getChildSynth("User1"),
				  Synth.getChildSynth("User2"),
				  Synth.getChildSynth("User3"),
				  Synth.getChildSynth("User4"),
				  Synth.getChildSynth("User5"),
				  Synth.getChildSynth("User6"),
				  Synth.getChildSynth("User7"),
				 Synth.getChildSynth("User8")];   

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

const var Harm = [Content.getComponent("Harm1"),
				Content.getComponent("Harm2"),
				Content.getComponent("Harm3"),
				Content.getComponent("Harm4"),
				Content.getComponent("Harm5"),
				Content.getComponent("Harm6"),
				Content.getComponent("Harm7"),
				Content.getComponent("Harm8")];    

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
				
const var LabelWidth = [Content.getComponent("Sample1"),
                        Content.getComponent("Sample2"),
                        Content.getComponent("Sample3"),
                        Content.getComponent("Sample4"),
                        Content.getComponent("Sample5"),
                        Content.getComponent("Sample6"),
                        Content.getComponent("Sample7"),
                        Content.getComponent("Sample8")];

const var BankBs = [Content.getComponent("BankB8"),
                    Content.getComponent("BankB7"),
                    Content.getComponent("BankB6"),
                    Content.getComponent("BankB5"),
                    Content.getComponent("BankB4"),
                    Content.getComponent("BankB3"),
                    Content.getComponent("BankB2"),
                    Content.getComponent("BankB1")];

const var SampleMode1 = Content.getComponent("SampleMode1");
const var VariousLabel1 = Content.getComponent("VariousLabel1");
const var VarMenu = Content.getComponent("VarMenu");
const var VarMenu1 = Content.getComponent("VarMenu1");
const var EditPanels = Content.getComponent("EditPanels");
const var MetaSection = Content.getComponent("MetaSection");
const var CtrlAl = Content.getComponent("CtrlAl");
const var WtMaster = Content.getComponent("WtMaster");
const var Harm9 = Content.getComponent("Harm9");
const var Folder = Content.getComponent("Folder");


inline function onVarMenu1Control(component, value)
{
		if(value == 0)
	    	{

	MetaSection.showControl(1);
	CtrlAl.showControl(0);

}
if(value == 1)
    	{

	MetaSection.showControl(0);
	CtrlAl.showControl(1);
}



};

Content.getComponent("VarMenu1").setControlCallback(onVarMenu1Control);

const var MultiLabels = Content.getComponent("MultiLabels");
const var SfLabels = Content.getComponent("SfLabels");
const var WtLabels = Content.getComponent("WtLabels");
const var SampleUser = Content.getComponent("SampleUser");
const var FolderSelect = Content.getComponent("FolderSelect");
const var LoadAllUser = Content.getComponent("LoadAllUser");
const var SampleInternal = Content.getComponent("SampleInternal");


const var UserConts = [Content.getComponent("UserControls8"),
                       Content.getComponent("UserControls1"),
                       Content.getComponent("UserControls2"),
                       Content.getComponent("UserControls3"),
                       Content.getComponent("UserControls4"),
                       Content.getComponent("UserControls5"),
                       Content.getComponent("UserControls6"),
                       Content.getComponent("UserControls7")];



inline function onSampleMode1Control(component, value)
{

	
if(value == 1)
	{
	
	Engine.allNotesOff();
	
	
	for(s in Banks) s.showControl(0);
	for(s in SampleControls) s.showControl(0);  
	for(s in SamplerGroup) s.setBypassed(1); 
	       
	for(s in SfzControls) s.showControl(0);
	for(s in SfzLd) s.showControl(0);  	      
	for(s in SfZs) s.setBypassed(1);
	       

    for(s in LpControl) s.showControl(1);  
    for(s in UserConts) s.showControl(0); 
	for(s in LoopGroup) s.setBypassed(0);
	for(s in UserLoop) s.setBypassed(1);
	


	for(s in Wtbls) s.showControl(0);
    for(s in WtLoad) s.showControl(0);  
	for(s in Wtable) s.setBypassed(1);
	for(s in Harm) s.showControl(0);  

	

	VarMenu1.showControl(0);
	EditPanels.showControl(1);

MultiLabels.showControl(0);
SfLabels.showControl(0);
WtLabels.showControl(0);
SampleUser.showControl(0);
SampleInternal.showControl(1);
BankA11.showControl(0);
LoadAllUser.showControl(0);
LoadAllInternal.showControl(1);


FolderSelect.showControl(0);

for(s in LpLoadInternal) s.showControl(1); 
for(s in LpLoaders) s.showControl(0); 

VarMenu1.setValue(0);
VarMenu1.changed();


	
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
		       

	    for(s in LpControl) s.showControl(0);  
	    for(s in UserConts) s.showControl(1); 
		for(s in LoopGroup) s.setBypassed(1);
		for(s in UserLoop) s.setBypassed(0);
	
		for(s in Wtbls) s.showControl(0);
	    for(s in WtLoad) s.showControl(0);  
		for(s in Wtable) s.setBypassed(1);
		for(s in Harm) s.showControl(0);  


		
	
		VarMenu1.showControl(0);
		EditPanels.showControl(1);
	
	MultiLabels.showControl(0);
	SfLabels.showControl(0);
	WtLabels.showControl(0);
	SampleUser.showControl(1);
	SampleInternal.showControl(0);
	BankA11.showControl(0);
	LoadAllUser.showControl(1);
	LoadAllInternal.showControl(0);

	FolderSelect.showControl(1);
	
	for(s in LpLoadInternal) s.showControl(0); 
	for(s in LpLoaders) s.showControl(1); 
	
	VarMenu1.setValue(0);
	VarMenu1.changed();
	
	
		
		}
		
		if(value == 3)
			{
				
			Engine.allNotesOff();
			
			for(s in Banks) s.showControl(1);
			for(s in SampleControls) s.showControl(1);  
			for(s in SamplerGroup) s.setBypassed(0); 
			
			for(s in SfzControls) s.showControl(0);
			for(s in SfzLd) s.showControl(0);  	      
			for(s in SfZs) s.setBypassed(1);
			       

		    for(s in LpControl) s.showControl(0);  
		    for(s in UserConts) s.showControl(0); 
			for(s in LoopGroup) s.setBypassed(1);
			for(s in UserLoop) s.setBypassed(1);
		
			for(s in Wtbls) s.showControl(0);
		    for(s in WtLoad) s.showControl(0);  
			for(s in Wtable) s.setBypassed(1);
			
			for(s in Harm) s.showControl(0);  

			

		
		
			Folder.showControl(1);
		
			VarMenu1.showControl(0);
	
			EditPanels.showControl(1);
			
			MultiLabels.showControl(1);
			SfLabels.showControl(0);
			WtLabels.showControl(0);
			SampleUser.showControl(0);
			SampleInternal.showControl(0);
			
BankA11.showControl(1);
LoadAllUser.showControl(0);
LoadAllInternal.showControl(0);

			FolderSelect.showControl(0);
			
			for(s in LpLoadInternal) s.showControl(0); 
			for(s in LpLoaders) s.showControl(0); 
			
	VarMenu1.setValue(0);
	VarMenu1.changed();	
			
			}
	
if(value == 4)
	{
	
	//sfz
	

	
	for(s in Banks) s.showControl(0);
	for(s in SampleControls) s.showControl(0);  
	for(s in SamplerGroup) s.setBypassed(1); 
	       
	for(s in SfzControls) s.showControl(1);
	for(s in SfzLd) s.showControl(1);  	      
	for(s in SfZs) s.setBypassed(0);

	       

    for(s in LpControl) s.showControl(0);  
    for(s in UserConts) s.showControl(0); 
	for(s in LoopGroup) s.setBypassed(1);
	for(s in UserLoop) s.setBypassed(1);

	for(s in Wtbls) s.showControl(0);
    for(s in WtLoad) s.showControl(0);  
	for(s in Wtable) s.setBypassed(1);
	for(s in Harm) s.showControl(0);  

	

EditPanels.showControl(1);

	VarMenu1.showControl(0);


	MultiLabels.showControl(0);
	SfLabels.showControl(1);
	WtLabels.showControl(0);
	SampleUser.showControl(0);
	SampleInternal.showControl(0);
	
	BankA11.showControl(0);
	LoadAllUser.showControl(0);
	LoadAllInternal.showControl(0);

			FolderSelect.showControl(0);
			
			for(s in LpLoadInternal) s.showControl(0); 
			for(s in LpLoaders) s.showControl(0); 
			
			VarMenu1.setValue(0);
			VarMenu1.changed();

	}
	
	if(value == 5)
		{
	
	    //wt  
	
	for(s in Banks) s.showControl(0);
	for(s in SampleControls) s.showControl(0);  
	for(s in SamplerGroup) s.setBypassed(1); 
	       
	for(s in SfzControls) s.showControl(0);
	for(s in SfzLd) s.showControl(0);  	      
	for(s in SfZs) s.setBypassed(1);
	       

    for(s in LpControl) s.showControl(0);  
    for(s in UserConts) s.showControl(0); 
	for(s in LoopGroup) s.setBypassed(1);
	for(s in UserLoop) s.setBypassed(1);

	for(s in Wtbls) s.showControl(1);
    for(s in WtLoad) s.showControl(1);  
	for(s in Wtable) s.setBypassed(0);
	for(s in Harm) s.showControl(0);  

	



EditPanels.showControl(1);
WtMaster.showControl(1);
Harm9.showControl(0);

VarMenu1.setValue(0);
VarMenu1.changed();
	VarMenu1.showControl(1);
	
	MultiLabels.showControl(0);
	SfLabels.showControl(0);
	WtLabels.showControl(1);
	SampleUser.showControl(0);
	SampleInternal.showControl(0);
	
	BankA11.showControl(0);
	LoadAllUser.showControl(0);
	LoadAllInternal.showControl(0);
	

			FolderSelect.showControl(0);
			
			for(s in LpLoadInternal) s.showControl(0); 
			for(s in LpLoaders) s.showControl(0); 

		
		}
													

};

Content.getComponent("SampleMode1").setControlCallback(onSampleMode1Control);



