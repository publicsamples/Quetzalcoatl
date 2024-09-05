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

const var Wtbl1 = Content.getComponent("Wt1");
const var Wtbl2 = Content.getComponent("Wt2");
const var Wtbl3 = Content.getComponent("Wt3");
const var Wtbl4 = Content.getComponent("Wt4");
const var Wtbl5 = Content.getComponent("Wt5");
const var Wtbl6 = Content.getComponent("Wt6");
const var Wtbl7 = Content.getComponent("Wt7");
const var Wtbl8 = Content.getComponent("Wt8");

const var WtLoad1 = Content.getComponent("WtLoad1");
const var WtLoad2 = Content.getComponent("WtLoad2");
const var WtLoad3 = Content.getComponent("WtLoad3");
const var WtLoad4 = Content.getComponent("WtLoad4");
const var WtLoad5 = Content.getComponent("WtLoad5");
const var WtLoad6 = Content.getComponent("WtLoad6");
const var WtLoad7 = Content.getComponent("WtLoad7");
const var WtLoad8 = Content.getComponent("WtLoad8");

const var LpLoad1 = Content.getComponent("LpLoad1");
const var LpLoad2 = Content.getComponent("LpLoad2");
const var LpLoad3 = Content.getComponent("LpLoad3");
const var LpLoad4 = Content.getComponent("LpLoad4");
const var LpLoad5 = Content.getComponent("LpLoad5");
const var LpLoad6 = Content.getComponent("LpLoad6");
const var LpLoad7 = Content.getComponent("LpLoad7");
const var LpLoad8 = Content.getComponent("LpLoad8");

const var SfzLd1 = Content.getComponent("Sfz1");
const var SfzLd2 = Content.getComponent("Sfz2");
const var SfzLd3 = Content.getComponent("Sfz3");
const var SfzLd4 = Content.getComponent("Sfz4");
const var SfzLd5 = Content.getComponent("Sfz5");
const var SfzLd6 = Content.getComponent("Sfz6");
const var SfzLd7 = Content.getComponent("Sfz7");
const var SfzLd8 = Content.getComponent("Sfz8");

const var SampleModeB1 = Content.getComponent("SampleModeB1");
const var SampleModeB2 = Content.getComponent("SampleModeB2");
const var SampleModeB3 = Content.getComponent("SampleModeB3");
const var SampleModeB4 = Content.getComponent("SampleModeB4");
const var SampleModeB5 = Content.getComponent("SampleModeB5");
const var SampleModeB6 = Content.getComponent("SampleModeB6");
const var SampleModeB7 = Content.getComponent("SampleModeB7");
const var SampleModeB8 = Content.getComponent("SampleModeB8");

const var SampleMode1 = Content.getComponent("SampleMode1");
const var SampleMode2 = Content.getComponent("SampleMode2");
const var SampleMode3 = Content.getComponent("SampleMode3");
const var SampleMode4 = Content.getComponent("SampleMode4");
const var SampleMode5 = Content.getComponent("SampleMode5");
const var SampleMode6 = Content.getComponent("SampleMode6");
const var SampleMode7 = Content.getComponent("SampleMode7");
const var SampleMode8 = Content.getComponent("SampleMode8");

inline function onSampleMode1Control(component, value)
{
SampleModeB1.setValue(value);

if(value == 1)
	{
		
	Engine.allNotesOff();

	Sampler1.setBypassed(0);
	Waves1.showControl(1);
	BankA1.showControl(1);

	SfzLoad1.showControl(0);
	Sfz1.setBypassed(1);
	SfzLd1.showControl(0);

	
	loop1.setBypassed(1);
	LpLoad1.showControl(0);
	LpControls1.showControl(0);
	
	Wtbl1.showControl(0);
	Wt1.setBypassed(1);
	WtLoad1.showControl(0);
			
	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	
		Sampler1.setBypassed(1);
	Waves1.showControl(0);
	BankA1.showControl(0);
	
	SfzLoad1.showControl(0);
	Sfz1.setBypassed(1);
	SfzLd1.showControl(0);
	
	loop1.setBypassed(0);
	LpLoad1.showControl(1);
	LpControls1.showControl(1);
	
	Wtbl1.showControl(0);
	Wt1.setBypassed(1);
	WtLoad1.showControl(0);

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler1.setBypassed(1);
	Waves1.showControl(0);
	BankA1.showControl(0);
	
	SfzLoad1.showControl(1);
	Sfz1.setBypassed(0);
	SfzLd1.showControl(1);

	
	loop1.setBypassed(1);
	LpLoad1.showControl(0);
	LpControls1.showControl(0);
	
	Wtbl1.showControl(0);
	Wt1.setBypassed(1);
	WtLoad1.showControl(0);

	
	}
	
	if(value == 4)
		{
		
		//sampler
		
			Sampler1.setBypassed(1);
		Waves1.showControl(0);
		BankA1.showControl(0);
		
		SfzLoad1.showControl(0);
		Sfz1.setBypassed(1);
		SfzLd1.showControl(0);

		
		loop1.setBypassed(1);
		LpLoad1.showControl(0);
		LpControls1.showControl(0);
		
		Wtbl1.showControl(1);
		Wt1.setBypassed(0);
		WtLoad1.showControl(1);
	
		
		}

};

Content.getComponent("SampleMode1").setControlCallback(onSampleMode1Control);


inline function onSampleMode2Control(component, value)
{

SampleModeB2.setValue(value);

if(value == 1)
	{
	
	Engine.allNotesOff();
	

	Sampler2.setBypassed(0);
	Waves2.showControl(1);
	BankA2.showControl(1);
	

	SfzLoad2.showControl(0);
	Sfz2.setBypassed(1);
	SfzLd2.showControl(0);
	
	loop2.setBypassed(1);
	LpLoad2.showControl(0);
	LpControls2.showControl(0);
	
	Wtbl2.showControl(0);
	Wt2.setBypassed(1);
	WtLoad2.showControl(0);
	

	
		
	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler2.setBypassed(1);
	Waves2.showControl(0);
	BankA2.showControl(0);
	
	SfzLoad2.showControl(0);
	Sfz2.setBypassed(1);
	SfzLd2.showControl(0);
	
	loop2.setBypassed(0);
	LpLoad2.showControl(1);
	LpControls2.showControl(1);
	
	Wtbl2.showControl(0);
	Wt2.setBypassed(1);
	WtLoad2.showControl(0);

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler2.setBypassed(1);
	Waves2.showControl(0);
	BankA2.showControl(0);
	
	SfzLoad2.showControl(1);
	Sfz2.setBypassed(0);
	SfzLd2.showControl(1);
	
	loop2.setBypassed(1);
	LpLoad2.showControl(0);
	LpControls2.showControl(0);
	
	Wtbl2.showControl(0);
	Wt2.setBypassed(1);
	WtLoad2.showControl(0);

	
	}
	
	if(value == 4)
		{
		
		//sampler
		
			Sampler2.setBypassed(1);
		Waves2.showControl(0);
		BankA2.showControl(0);
		
		SfzLoad2.showControl(0);
		Sfz2.setBypassed(1);
		SfzLd2.showControl(0);
		
		loop2.setBypassed(1);
		LpLoad2.showControl(0);
		LpControls2.showControl(0);
		
		Wtbl2.showControl(1);
		Wt2.setBypassed(0);
		WtLoad2.showControl(1);
	
		
		}

};

Content.getComponent("SampleMode2").setControlCallback(onSampleMode2Control);


inline function onSampleMode3Control(component, value)
{

SampleModeB3.setValue(value);

if(value == 1)
	{
	
	Engine.allNotesOff();
	

	Sampler3.setBypassed(0);
	Waves3.showControl(1);
	BankA3.showControl(1);

	SfzLoad3.showControl(0);
	Sfz3.setBypassed(1);
	SfzLd3.showControl(0);
	
	loop3.setBypassed(1);
	LpLoad3.showControl(0);
	LpControls3.showControl(0);
	
	Wtbl3.showControl(0);
	Wt3.setBypassed(1);
	WtLoad3.showControl(0);
	

	
		
	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler3.setBypassed(1);
	Waves3.showControl(0);
	BankA3.showControl(0);
	
	SfzLoad3.showControl(0);
	Sfz3.setBypassed(1);
	SfzLd3.showControl(0);
	
	loop3.setBypassed(0);
	LpLoad3.showControl(1);
	LpControls3.showControl(1);
	
	Wtbl3.showControl(0);
	Wt3.setBypassed(1);
	WtLoad3.showControl(0);

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler3.setBypassed(1);
	Waves3.showControl(0);
	BankA3.showControl(0);
	
	SfzLoad3.showControl(1);
	Sfz3.setBypassed(0);
	SfzLd3.showControl(1);
	
	loop3.setBypassed(1);
	LpLoad3.showControl(0);
	LpControls3.showControl(0);
	
	Wtbl3.showControl(0);
	Wt3.setBypassed(1);
	WtLoad3.showControl(0);

	
	}
	
	if(value == 4)
		{
		
		//sampler
		
			Sampler3.setBypassed(1);
		Waves3.showControl(0);
		BankA3.showControl(0);
		
		SfzLoad3.showControl(0);
		Sfz3.setBypassed(1);
		SfzLd3.showControl(0);

		
		loop3.setBypassed(1);
		LpLoad3.showControl(0);
		LpControls3.showControl(0);
		
		Wtbl3.showControl(1);
		Wt3.setBypassed(0);
		WtLoad3.showControl(1);
	
		
		}

};

Content.getComponent("SampleMode3").setControlCallback(onSampleMode3Control);


inline function onSampleMode4Control(component, value)
{

SampleModeB4.setValue(value);

if(value == 1)
	{
	
	Engine.allNotesOff();
	

	Sampler4.setBypassed(0);
	Waves4.showControl(1);
	BankA4.showControl(1);

	SfzLoad4.showControl(0);
	Sfz4.setBypassed(1);
	SfzLd4.showControl(0);

	
	loop4.setBypassed(1);
	LpLoad4.showControl(0);
	LpControls4.showControl(0);
	
	Wtbl4.showControl(0);
	Wt4.setBypassed(1);
	WtLoad4.showControl(0);
	

	
		
	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler4.setBypassed(1);
	Waves4.showControl(0);
	BankA4.showControl(0);
	
	SfzLoad4.showControl(0);
	Sfz4.setBypassed(1);
	SfzLd4.showControl(0);

	
	loop4.setBypassed(0);
	LpLoad4.showControl(1);
	LpControls4.showControl(1);
	
	Wtbl4.showControl(0);
	Wt4.setBypassed(1);
	WtLoad4.showControl(0);

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler4.setBypassed(1);
	Waves4.showControl(0);
	BankA4.showControl(0);
	
	SfzLoad4.showControl(1);
	Sfz4.setBypassed(0);
	SfzLd4.showControl(1);

	
	loop4.setBypassed(1);
	LpLoad4.showControl(0);
	LpControls4.showControl(0);
	
	Wtbl4.showControl(0);
	Wt4.setBypassed(1);
	WtLoad4.showControl(0);

	
	}
	
	if(value == 4)
		{
		
		//sampler
		
			Sampler4.setBypassed(1);
		Waves4.showControl(0);
		BankA4.showControl(0);
		
		SfzLoad4.showControl(0);
		Sfz4.setBypassed(1);
		SfzLd4.showControl(0);

		
		loop4.setBypassed(1);
		LpLoad4.showControl(0);
		LpControls4.showControl(0);
		
		Wtbl4.showControl(1);
		Wt4.setBypassed(0);
		WtLoad4.showControl(1);
	
		
		}

};

Content.getComponent("SampleMode4").setControlCallback(onSampleMode4Control);


inline function onSampleMode5Control(component, value)
{

SampleModeB5.setValue(value);

if(value == 1)
	{
	
	Engine.allNotesOff();
	

	Sampler5.setBypassed(0);
	Waves5.showControl(1);
	BankA5.showControl(1);
	SfzLoad5.showControl(0);
	Sfz5.setBypassed(1);
	SfzLd5.showControl(0);

	
	loop5.setBypassed(1);
	LpLoad5.showControl(0);
	LpControls5.showControl(0);
	
	Wtbl5.showControl(0);
	Wt5.setBypassed(1);
	WtLoad5.showControl(0);
	

	
		
	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler5.setBypassed(1);
	Waves5.showControl(0);
	BankA5.showControl(0);
	
	SfzLoad5.showControl(0);
	Sfz5.setBypassed(1);
	SfzLd5.showControl(0);

	
	loop5.setBypassed(0);
	LpLoad5.showControl(1);
	LpControls5.showControl(1);
	
	Wtbl5.showControl(0);
	Wt5.setBypassed(1);
	WtLoad5.showControl(0);

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler5.setBypassed(1);
	Waves5.showControl(0);
	BankA5.showControl(0);
	
	SfzLoad5.showControl(1);
	Sfz5.setBypassed(0);
	SfzLd5.showControl(1);

	
	loop5.setBypassed(1);
	LpLoad5.showControl(0);
	LpControls5.showControl(0);
	
	Wtbl5.showControl(0);
	Wt5.setBypassed(1);
	WtLoad5.showControl(0);

	
	}
	
	if(value == 4)
		{
		
		//sampler
		
			Sampler5.setBypassed(1);
		Waves5.showControl(0);
		BankA5.showControl(0);
		
		SfzLoad5.showControl(0);
		Sfz5.setBypassed(1);
		SfzLd5.showControl(0);

		
		loop5.setBypassed(1);
		LpLoad5.showControl(0);
		LpControls5.showControl(0);
		
		Wtbl5.showControl(1);
		Wt5.setBypassed(0);
		WtLoad5.showControl(1);
	
		
		}

};

Content.getComponent("SampleMode5").setControlCallback(onSampleMode5Control);


inline function onSampleMode6Control(component, value)
{

SampleModeB6.setValue(value);

if(value == 1)
	{
	
	Engine.allNotesOff();
	

	Sampler6.setBypassed(0);
	Waves6.showControl(1);
	BankA6.showControl(1);
	

	SfzLoad6.showControl(0);
	Sfz6.setBypassed(1);
	SfzLd6.showControl(0);

	
	loop6.setBypassed(1);
	LpLoad6.showControl(0);
	LpControls6.showControl(0);
	
	Wtbl6.showControl(0);
	Wt6.setBypassed(1);
	WtLoad6.showControl(0);
	

	
		
	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler6.setBypassed(1);
	Waves6.showControl(0);
	BankA6.showControl(0);
	
	SfzLoad6.showControl(0);
	Sfz6.setBypassed(1);
	SfzLd6.showControl(0);

	
	loop6.setBypassed(0);
	LpLoad6.showControl(1);
	LpControls6.showControl(1);
	
	Wtbl6.showControl(0);
	Wt6.setBypassed(1);
	WtLoad6.showControl(0);

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler6.setBypassed(1);
	Waves6.showControl(0);
	BankA6.showControl(0);
	
	SfzLoad6.showControl(1);
	Sfz6.setBypassed(0);
	SfzLd6.showControl(1);

	
	loop6.setBypassed(1);
	LpLoad6.showControl(0);
	LpControls6.showControl(0);
	
	Wtbl6.showControl(0);
	Wt6.setBypassed(1);
	WtLoad6.showControl(0);
	

	
	}
	
	if(value == 4)
		{
		
		//sampler
		
			Sampler6.setBypassed(1);
		Waves6.showControl(0);
		BankA6.showControl(0);
		
		SfzLoad6.showControl(0);
		Sfz6.setBypassed(1);
		SfzLd6.showControl(0);

		
		loop6.setBypassed(1);
		LpLoad6.showControl(0);
		LpControls6.showControl(0);
		
		Wtbl6.showControl(1);
		Wt6.setBypassed(0);
		WtLoad6.showControl(1);
	
		
		}

};

Content.getComponent("SampleMode6").setControlCallback(onSampleMode6Control);


inline function onSampleMode7Control(component, value)
{
	
	SampleModeB7.setValue(value);



if(value == 1)
	{
	
	Engine.allNotesOff();
	

	Sampler7.setBypassed(0);
	Waves7.showControl(1);
	BankA7.showControl(1);

	SfzLoad7.showControl(0);
	Sfz7.setBypassed(1);
	SfzLd7.showControl(0);

	
	loop7.setBypassed(1);
	LpLoad7.showControl(0);
	LpControls7.showControl(0);
	
	Wtbl7.showControl(0);
	Wt7.setBypassed(1);
	WtLoad7.showControl(0);
	

	
		
	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler7.setBypassed(1);
	Waves7.showControl(0);
	BankA7.showControl(0);
	
	SfzLoad7.showControl(0);
	Sfz7.setBypassed(1);
	SfzLd7.showControl(0);

	
	loop7.setBypassed(0);
	LpLoad7.showControl(1);
	LpControls7.showControl(1);
	
	Wtbl7.showControl(0);
	Wt7.setBypassed(1);
	WtLoad7.showControl(0);

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler7.setBypassed(1);
	Waves7.showControl(0);
	BankA7.showControl(0);
	
	SfzLoad7.showControl(1);
	Sfz7.setBypassed(0);
	SfzLd7.showControl(1);

	
	loop7.setBypassed(1);
	LpLoad7.showControl(0);
	LpControls7.showControl(0);
	
	Wtbl7.showControl(0);
	Wt7.setBypassed(1);
	WtLoad7.showControl(0);
	

	
	}
	
	if(value == 4)
		{
		
		//sampler
		
			Sampler7.setBypassed(1);
		Waves7.showControl(0);
		BankA7.showControl(0);
		
		SfzLoad7.showControl(0);
		Sfz7.setBypassed(1);
		SfzLd7.showControl(0);

		
		loop7.setBypassed(1);
		LpLoad7.showControl(0);
		LpControls7.showControl(0);
		
		Wtbl7.showControl(1);
		Wt7.setBypassed(0);
		WtLoad7.showControl(1);
	
		
		}

};

Content.getComponent("SampleMode7").setControlCallback(onSampleMode7Control);


inline function onSampleMode8Control(component, value)
{

SampleModeB8.setValue(value);

if(value == 1)
	{
	
	Engine.allNotesOff();
	

	Sampler8.setBypassed(0);
	Waves8.showControl(1);
	BankA8.showControl(1);
	SfzLoad8.showControl(0);
	Sfz8.setBypassed(1);
	SfzLd8.showControl(0);

	
	loop8.setBypassed(1);
	LpLoad8.showControl(0);
	LpControls8.showControl(0);
	
	Wtbl8.showControl(0);
	Wt8.setBypassed(1);
	WtLoad8.showControl(0);
	

	
		
	
	}
	
if(value == 2)
	{
	
	Engine.allNotesOff();
	
	//sampler
	
		Sampler8.setBypassed(1);
	Waves8.showControl(0);
	BankA8.showControl(0);
	
	SfzLoad8.showControl(0);
	Sfz8.setBypassed(1);
	SfzLd8.showControl(0);

	
	loop8.setBypassed(0);
	LpLoad8.showControl(1);
	LpControls8.showControl(1);
	
	Wtbl8.showControl(0);
	Wt8.setBypassed(1);
	WtLoad8.showControl(0);

	
	}
	
if(value == 3)
	{
	
	//sampler
	
		Sampler8.setBypassed(1);
	Waves8.showControl(0);
	BankA8.showControl(0);
	
	SfzLoad8.showControl(1);
	Sfz8.setBypassed(0);
	SfzLd8.showControl(1);

	
	loop8.setBypassed(1);
	LpLoad8.showControl(0);
	LpControls8.showControl(0);
	
	Wtbl8.showControl(0);
	Wt8.setBypassed(1);
	WtLoad8.showControl(0);

	
	}
	
	if(value == 4)
		{
		
		//sampler
		
			Sampler8.setBypassed(1);
		Waves8.showControl(0);
		BankA8.showControl(0);
		
		SfzLoad8.showControl(0);
		Sfz8.setBypassed(1);
		SfzLd8.showControl(0);

		
		loop8.setBypassed(1);
		LpLoad8.showControl(0);
		LpControls8.showControl(0);
		
		Wtbl8.showControl(1);
		Wt8.setBypassed(0);
		WtLoad8.showControl(1);
	
		
		}

};

Content.getComponent("SampleMode8").setControlCallback(onSampleMode8Control);


inline function onSampleModeB1Control(component, value)
{
	SampleMode1.setValue(value);
	SampleMode1.changed();
};

Content.getComponent("SampleModeB1").setControlCallback(onSampleModeB1Control);


inline function onSampleModeB2Control(component, value)
{
	
	SampleMode2.setValue(value);
	SampleMode2.changed();
};

Content.getComponent("SampleModeB2").setControlCallback(onSampleModeB2Control);


inline function onSampleModeB3Control(component, value)
{
	SampleMode3.setValue(value);
	SampleMode3.changed();
};

Content.getComponent("SampleModeB3").setControlCallback(onSampleModeB3Control);


inline function onSampleModeB4Control(component, value)
{
	SampleMode4.setValue(value);
	SampleMode4.changed();
};

Content.getComponent("SampleModeB4").setControlCallback(onSampleModeB4Control);


inline function onSampleModeB5Control(component, value)
{
	SampleMode5.setValue(value);
	SampleMode5.changed();
};

Content.getComponent("SampleModeB5").setControlCallback(onSampleModeB5Control);


inline function onSampleModeB6Control(component, value)
{
	SampleMode6.setValue(value);
	SampleMode6.changed();
};

Content.getComponent("SampleModeB6").setControlCallback(onSampleModeB6Control);


inline function onSampleModeB7Control(component, value)
{
	SampleMode7.setValue(value);
	SampleMode7.changed();
};

Content.getComponent("SampleModeB7").setControlCallback(onSampleModeB7Control);


inline function onSampleModeB8Control(component, value)
{
	SampleMode8.setValue(value);
	SampleMode8.changed();
};

Content.getComponent("SampleModeB8").setControlCallback(onSampleModeB8Control);
