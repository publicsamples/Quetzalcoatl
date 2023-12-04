const var UserA = [];

UserA[0] = Content.getComponent("UserA1");
UserA[1] = Content.getComponent("UserA2");
UserA[2] = Content.getComponent("UserA3");
UserA[3] = Content.getComponent("UserA4");
UserA[4] = Content.getComponent("UserA5");
UserA[5] = Content.getComponent("UserA6");
UserA[6] = Content.getComponent("UserA7");
UserA[7] = Content.getComponent("UserA8");

const var SFZ1 = Content.getComponent("SFZ1");
const var SFZlabel1 = Content.getComponent("SFZlabel1");
const var Factorylabel1 = Content.getComponent("Factorylabel1");

const var Labels1 = [];

Labels1[0] = Content.getComponent("XlAble1");
Labels1[1] = Content.getComponent("XlAble2");
Labels1[2] = Content.getComponent("XlAble3");
Labels1[3] = Content.getComponent("XlAble4");
Labels1[4] = Content.getComponent("XlAble5");
Labels1[5] = Content.getComponent("XlAble6");
Labels1[6] = Content.getComponent("XlAble7");
Labels1[7] = Content.getComponent("XlAble8");

const var LabelsSfz1 = [];

LabelsSfz1[0] = Content.getComponent("SfzLabelStore1");
LabelsSfz1[1] = Content.getComponent("SfzLabelStore2");
LabelsSfz1[2] = Content.getComponent("SfzLabelStore3");
LabelsSfz1[3] = Content.getComponent("SfzLabelStore4");
LabelsSfz1[4] = Content.getComponent("SfzLabelStore5");
LabelsSfz1[5] = Content.getComponent("SfzLabelStore6");
LabelsSfz1[6] = Content.getComponent("SfzLabelStore7");
LabelsSfz1[7] = Content.getComponent("SfzLabelStore8");

const var SfzLabelStore1 = Content.getComponent("SfzLabelStore1");



inline function onSFZ1Control(component, value)
{
	
	if(value == 0)
	{


       for (i = 0; i < Labels1.length; i++)
       Labels1[i].showControl(1);
	for (i = 0; i < LabelsSfz1.length; i++)
	LabelsSfz1[i].showControl(0);
	HARMONIC.setAttribute(HARMONIC.sfz1, 0);
	UserA1.showControl(0); 
	UserA2.showControl(0); 
	UserA3.showControl(0); 
	UserA4.showControl(0);    
	UserA5.showControl(0); 
	UserA6.showControl(0); 
	UserA7.showControl(0); 
	UserA8.showControl(0); 
	SFZlabel1.showControl(1); 
	 Factorylabel1.showControl(0);          
	}
	
		if(value == 1)
	{


	 HARMONIC.setAttribute(HARMONIC.sfz1, 1);
	
	  for (i = 0; i < Labels1.length; i++)
	         Labels1[i].showControl(0);
	         for (i = 0; i < LabelsSfz1.length; i++)
	         LabelsSfz1[i].showControl(1);
       UserA1.showControl(1);     
       UserA2.showControl(1);
       UserA3.showControl(1);  
       UserA4.showControl(1); 
       UserA5.showControl(1);
       UserA6.showControl(1);
        UserA7.showControl(1);
        UserA8.showControl(1);
        SFZlabel1.showControl(0); 
         Factorylabel1.showControl(1);          
	  
	}


};

Content.getComponent("SFZ1").setControlCallback(onSFZ1Control);


const var UserA1 = Content.getComponent("UserA1");


inline function onUserA1Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		LabelsSfz1[0].set("text", f.toString(f.NoExtension));


	
	});	

}
};

Content.getComponent("UserA1").setControlCallback(onUserA1Control);

const var UserA2 = Content.getComponent("UserA2");

	
inline function onUserA2Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC1.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		LabelsSfz1[1].set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA2").setControlCallback(onUserA2Control);

const var UserA3 = Content.getComponent("UserA3");

	
inline function onUserA3Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC2.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		LabelsSfz1[2].set("text", f.toString(f.NoExtension));
	
	});	

}
};

Content.getComponent("UserA3").setControlCallback(onUserA3Control);

const var UserA4 = Content.getComponent("UserA4");

	
inline function onUserA4Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC3.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
			LabelsSfz1[3].set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA4").setControlCallback(onUserA4Control);

const var UserA5 = Content.getComponent("UserA5");

	
inline function onUserA5Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC4.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		LabelsSfz1[4].set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA5").setControlCallback(onUserA5Control);

const var UserA6 = Content.getComponent("UserA6");

	
inline function onUserA6Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC5.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		LabelsSfz1[5].set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA6").setControlCallback(onUserA6Control);

const var UserA7 = Content.getComponent("UserA7");

	
inline function onUserA7Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC6.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		LabelsSfz1[6].set("text", f.toString(f.NoExtension));
	
	});	

}
};

Content.getComponent("UserA7").setControlCallback(onUserA7Control);


const var UserA8 = Content.getComponent("UserA8");

	
inline function onUserA8Control(component, value)

{
if (value)
		{
		FileSystem.browse (FileSystem.Desktop, false, "*.sfz", function (f) 
	{
		

		slotC7.loadFile("{XYZ::SFZ}" + (f.toString(File.FullPath)));
		LabelsSfz1[7].set("text", f.toString(f.NoExtension));

	
	});	

}
};

Content.getComponent("UserA8").setControlCallback(onUserA8Control);



for (i = 0; i < LabelsSfz1.length; i++)
LabelsSfz1[i].set("text", "Load SFZ");

