const var Wave1 = Content.getComponent("Wave1");


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
					Content.getComponent("LpLoad8")
					
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
				


const var SamplerGroup = [Synth.getChildSynth("SamplerA1"),
				  Synth.getChildSynth("SamplerA2"),
				  Synth.getChildSynth("SamplerA3"),
				  Synth.getChildSynth("SamplerA4"),
				  Synth.getChildSynth("SamplerA5"),
				  Synth.getChildSynth("SamplerA6"),
				  Synth.getChildSynth("SamplerA7"),
				  Synth.getChildSynth("SamplerA8")];

				  
const var SamplerClear = [Synth.getSampler("SamplerA1"),
				  Synth.getSampler("SamplerA2"),
				  Synth.getSampler("SamplerA3"),
				  Synth.getSampler("SamplerA4"),
				  Synth.getSampler("SamplerA5"),
				  Synth.getSampler("SamplerA6"),
				  Synth.getSampler("SamplerA7"),
				  Synth.getSampler("SamplerA8")];
				  
const var SfzClear = [Synth.getSampler("SamplerA1"),
				  Synth.getSampler("SamplerA2"),
				  Synth.getSampler("SamplerA3"),
				  Synth.getSampler("SamplerA4"),
				  Synth.getSampler("SamplerA5"),
				  Synth.getSampler("SamplerA6"),
				  Synth.getSampler("SamplerA7"),
				  Synth.getSampler("SamplerA8")];
				  
				  
				  
				  
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
				 
const var LoopA1 = Synth.getAudioSampleProcessor("LoopA1");

const var LoopClear = [Synth.getAudioSampleProcessor("LoopA1"),
				  Synth.getAudioSampleProcessor("LoopA2"),
				  Synth.getAudioSampleProcessor("LoopA3"),
				  Synth.getAudioSampleProcessor("LoopA4"),
				  Synth.getAudioSampleProcessor("LoopA5"),
				  Synth.getAudioSampleProcessor("LoopA6"),
				  Synth.getAudioSampleProcessor("LoopA7"),
				 Synth.getAudioSampleProcessor("LoopA8")];   
				 
const var UserClear = [Synth.getAudioSampleProcessor("User1"),
				  Synth.getAudioSampleProcessor("User2"),
				  Synth.getAudioSampleProcessor("User3"),
				  Synth.getAudioSampleProcessor("User4"),
				  Synth.getAudioSampleProcessor("User5"),
				  Synth.getAudioSampleProcessor("User6"),
				  Synth.getAudioSampleProcessor("User7"),
				 Synth.getAudioSampleProcessor("User8")];  

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


				
const var LabelWidth = [Content.getComponent("Sample1"),
                        Content.getComponent("Sample2"),
                        Content.getComponent("Sample3"),
                        Content.getComponent("Sample4"),
                        Content.getComponent("Sample5"),
                        Content.getComponent("Sample6"),
                        Content.getComponent("Sample7"),
                        Content.getComponent("Sample8")];



const var SampleMode1 = Content.getComponent("SampleMode1");
const var EditPanels = Content.getComponent("EditPanels");
const var CtrlAl = Content.getComponent("CtrlAl");
const var WtMaster = Content.getComponent("WtMaster");
const var Folder = Content.getComponent("Folder");


const var MultiLabels = Content.getComponent("MultiLabels");
const var SfLabels = Content.getComponent("SfLabels");
const var WtLabels = Content.getComponent("WtLabels");
const var SampleUser = Content.getComponent("SampleUser");
const var FolderSelect = Content.getComponent("FolderSelect");
const var LoadAllUser = Content.getComponent("LoadAllUser");
const var SampleInternal = Content.getComponent("SampleInternal");
const var LpControls1 = Content.getComponent("LpControls1");

const var LpControls2 = Content.getComponent("LpControls2");

const var WaveMetaLabel = Content.getComponent("WaveMetaLabel");

const var SCOPES = Content.getComponent("SCOPES");

const var Multi = [Content.getComponent("Sample1"),
                   Content.getComponent("Sample2"),
                   Content.getComponent("Sample3"),
                   Content.getComponent("Sample4"),
                   Content.getComponent("Sample5"),
                   Content.getComponent("Sample6"),
                   Content.getComponent("Sample7"),
                   Content.getComponent("Sample8")];

const var SfLabel = [Content.getComponent("SampleSfz1"),
                      Content.getComponent("SampleSfz2"),
                      Content.getComponent("SampleSfz3"),
                      Content.getComponent("SampleSfz4"),
                      Content.getComponent("SampleSfz5"),
                      Content.getComponent("SampleSfz6"),
                      Content.getComponent("SampleSfz7"),
                      Content.getComponent("SampleSfz8")];



inline function onSampleMode1Control(component, value)
{

	
if(value == 1)
	{
	
	Engine.allNotesOff();
	
	WaveMetaLabel.setValue("BANK");
	
	for(s in Banks) s.showControl(0);
	for(s in SamplerGroup) s.setBypassed(1); 
	for(s in SfzLd) s.showControl(0);  	      
	for(s in SfZs) s.setBypassed(1);
	for(s in LoopGroup) s.setBypassed(0);
	for(s in UserLoop) s.setBypassed(1);
    for(s in WtLoad) s.showControl(0);  
	for(s in Wtable) s.setBypassed(1);



	EditPanels.showControl(1);

SfLabels.showControl(0);

BankA11.showControl(0);
LoadAllUser.showControl(0);
LoadAllInternal.showControl(1);

LpControls1.showControl(1);
LpControls2.showControl(0);
Wave1.showControl(0);
SfzLoad1.showControl(0);
WtMaster.showControl(0);

LpBank1.showControl(1);
WtBank.showControl(0);
WtLabels.showControl(0);
SampleInternal.showControl(1);
ExpansionSelector.showControl(0);

FolderSelect.showControl(0);

for(s in LpLoadInternal) s.showControl(1); 
for(s in LpLoaders) s.showControl(0); 

SCOPES.showControl(1);

WtAll.showControl(0);

MultiLabels.showControl(0);

for(s in SamplerClear) s.clearSampleMap();
for(s in SfzClear) s.clearSampleMap();
for(s in Multi) s.setValue("Empty");
for(s in SfLabel) s.setValue("Empty");


	
	}
	
	if(value == 2)
		{
		
		Engine.allNotesOff();
		WaveMetaLabel.setValue("SET FOLDER");
		
		
		for(s in Banks) s.showControl(0);

		for(s in SamplerGroup) s.setBypassed(1); 
		       
		for(s in SfzLd) s.showControl(0);  	      
		for(s in SfZs) s.setBypassed(1);
		       
		for(s in LoopGroup) s.setBypassed(1);
		for(s in UserLoop) s.setBypassed(0);
	    for(s in WtLoad) s.showControl(0);  
		for(s in Wtable) s.setBypassed(1);
	


		
	

		EditPanels.showControl(1);
	

	SfLabels.showControl(0);
	BankA11.showControl(0);
	LoadAllUser.showControl(1);
	LoadAllInternal.showControl(0);

	FolderSelect.showControl(1);
	
	for(s in LpLoadInternal) s.showControl(0); 
	for(s in LpLoaders) s.showControl(1); 
   WtAll.showControl(0);
   
   LpControls1.showControl(0);
   LpControls2.showControl(1);
   Wave1.showControl(0);
   SfzLoad1.showControl(0);
   WtMaster.showControl(0);
   
   LpBank1.showControl(0);
   WtBank.showControl(0);
   WtLabels.showControl(0);
   SampleInternal.showControl(0);
   ExpansionSelector.showControl(0);
   MultiLabels.showControl(0);
   
   for(s in SamplerClear) s.clearSampleMap();
   for(s in SfzClear) s.clearSampleMap();
   for(s in Multi) s.setValue("Empty");
   for(s in SfLabel) s.setValue("Empty");
  		
		}
		
		if(value == 3)
			{
				
			Engine.allNotesOff();
			WaveMetaLabel.setValue("BANK");
			
			for(s in Banks) s.showControl(1);

			for(s in SamplerGroup) s.setBypassed(0); 
			

			for(s in SfzLd) s.showControl(0);  	      
			for(s in SfZs) s.setBypassed(1);
			       
			for(s in LoopGroup) s.setBypassed(1);
			for(s in UserLoop) s.setBypassed(1);
		

		    for(s in WtLoad) s.showControl(0);  
			for(s in Wtable) s.setBypassed(1);
				

		
		
			Folder.showControl(1);
		

	
			EditPanels.showControl(1);
			

			SfLabels.showControl(0);
	
			
BankA11.showControl(1);
LoadAllUser.showControl(0);
LoadAllInternal.showControl(0);
 WtAll.showControl(0);
			FolderSelect.showControl(0);
			
			for(s in LpLoadInternal) s.showControl(0); 
			for(s in LpLoaders) s.showControl(0); 
			
			LpControls1.showControl(0);
			LpControls2.showControl(0);
			Wave1.showControl(1);
			SfzLoad1.showControl(0);
			WtMaster.showControl(0);
			
			LpBank1.showControl(0);
			WtBank.showControl(0);
			WtLabels.showControl(0);
			SampleInternal.showControl(0);
			ExpansionSelector.showControl(1);
			
			SCOPES.showControl(1);

			MultiLabels.showControl(1);
			
		
			for(s in SfzClear) s.clearSampleMap();
			for(s in SfLabel) s.setValue("Empty");

			
			
			}
	
if(value == 4)
	{
	
	//sfz
	

	
	for(s in Banks) s.showControl(0);
	WaveMetaLabel.setValue("");

	for(s in SamplerGroup) s.setBypassed(1); 
	       

	for(s in SfzLd) s.showControl(1);  	      
	for(s in SfZs) s.setBypassed(0);

	       



	for(s in LoopGroup) s.setBypassed(1);
	for(s in UserLoop) s.setBypassed(1);


    for(s in WtLoad) s.showControl(0);  
	for(s in Wtable) s.setBypassed(1);


	

EditPanels.showControl(1);


	SfLabels.showControl(1);
	WtAll.showControl(0);
	BankA11.showControl(0);
	LoadAllUser.showControl(0);
	LoadAllInternal.showControl(0);

			FolderSelect.showControl(0);
			
			for(s in LpLoadInternal) s.showControl(0); 
			for(s in LpLoaders) s.showControl(0); 
			
			LpControls1.showControl(0);
			LpControls2.showControl(0);
			Wave1.showControl(0);
			SfzLoad1.showControl(1);
			WtMaster.showControl(0);
			
			LpBank1.showControl(0);
					WtBank.showControl(0);
					WtLabels.showControl(0);
					SampleInternal.showControl(0);
					ExpansionSelector.showControl(0);
					
					SCOPES.showControl(1);
					MultiLabels.showControl(0);
					
					for(s in SamplerClear) s.clearSampleMap();
  for(s in Multi) s.setValue("Empty");
					
		
			
	
	}
	
	if(value == 5)
		{
	
	    //wt  
	
	for(s in Banks) s.showControl(0);
	WaveMetaLabel.setValue("BANK");

	for(s in SamplerGroup) s.setBypassed(1); 
	       
	for(s in SfzLd) s.showControl(0);  	      
	for(s in SfZs) s.setBypassed(1);

	for(s in LoopGroup) s.setBypassed(1);
	for(s in UserLoop) s.setBypassed(1);

    for(s in WtLoad) s.showControl(1);  
	for(s in Wtable) s.setBypassed(0);


	



EditPanels.showControl(1);
WtMaster.showControl(1);
LoadAllInternal.showControl(0);

WtAll.showControl(1);
	

	SfLabels.showControl(0);


	BankA11.showControl(0);


			FolderSelect.showControl(0);
			
			for(s in LpLoadInternal) s.showControl(0); 
			for(s in LpLoaders) s.showControl(0); 
			
			
			LpControls1.showControl(0);
			LpControls2.showControl(0);
			Wave1.showControl(0);
			SfzLoad1.showControl(0);
			WtMaster.showControl(1);
			
			LpBank1.showControl(0);
					WtBank.showControl(1);
					WtLabels.showControl(1);
					SampleInternal.showControl(0);
ExpansionSelector.showControl(0);

SCOPES.showControl(0);
MultiLabels.showControl(0);

for(s in SamplerClear) s.clearSampleMap();
for(s in SfzClear) s.clearSampleMap();
  for(s in Multi) s.setValue("Empty");
  for(s in SfLabel) s.setValue("Empty");
		
		}
													

};

Content.getComponent("SampleMode1").setControlCallback(onSampleMode1Control);



