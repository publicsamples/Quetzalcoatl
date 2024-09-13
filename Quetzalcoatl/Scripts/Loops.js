const var root1 = Content.getComponent("root1");
const var root2 = Content.getComponent("root2");
const var root3 = Content.getComponent("root3");
const var root4 = Content.getComponent("root4");
const var root5 = Content.getComponent("root5");
const var root6 = Content.getComponent("root6");
const var root7 = Content.getComponent("root7");
const var root8 = Content.getComponent("root8");

//Loops

const var LoopA1 = Synth.getAudioSampleProcessor("LoopA1");
const var LoopA2 = Synth.getAudioSampleProcessor("LoopA2");
const var LoopA3 = Synth.getAudioSampleProcessor("LoopA3");
const var LoopA4 = Synth.getAudioSampleProcessor("LoopA4");
const var LoopA5 = Synth.getAudioSampleProcessor("LoopA5");
const var LoopA6 = Synth.getAudioSampleProcessor("LoopA6");
const var LoopA7 = Synth.getAudioSampleProcessor("LoopA7");
const var LoopA8 = Synth.getAudioSampleProcessor("LoopA8");

inline function onLpLoad1Control(component, value)
{
	
	

if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA1.setFile((f.toString(File.FullPath)));
				Sample1.set("text", f.toString(f.NoExtension));	
				root1.setValue(64); 
				root1.changed();
				
	});	

}
};

Content.getComponent("LpLoad1").setControlCallback(onLpLoad1Control);

inline function onLpLoad2Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA2.setFile( (f.toString(File.FullPath)));
				Sample2.set("text", f.toString(f.NoExtension));	
	    		root2.setValue(64); 
				root2.changed();		
	});	
	

}
};

Content.getComponent("LpLoad2").setControlCallback(onLpLoad2Control);

inline function onLpLoad3Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA3.setFile( (f.toString(File.FullPath)));
				Sample3.set("text", f.toString(f.NoExtension));	
				root3.setValue(64); 
				root3.changed();				
	});	
	

}
};

Content.getComponent("LpLoad3").setControlCallback(onLpLoad3Control);

inline function onLpLoad4Control(component, value)
{
	
	

if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA4.setFile( (f.toString(File.FullPath)));
				Sample4.set("text", f.toString(f.NoExtension));	
				root4.setValue(64); 
				root4.changed();
	});	

}
};

Content.getComponent("LpLoad4").setControlCallback(onLpLoad4Control);

inline function onLpLoad5Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA5.setFile( (f.toString(File.FullPath)));
				Sample5.set("text", f.toString(f.NoExtension));
				root5.setValue(64); 
				root5.changed();
	});	
	

}
};

Content.getComponent("LpLoad5").setControlCallback(onLpLoad5Control);

inline function onLpLoad6Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA6.setFile( (f.toString(File.FullPath)));
				Sample6.set("text", f.toString(f.NoExtension));	
				root6.setValue(64); 
				root6.changed();
	});	

}
};

Content.getComponent("LpLoad6").setControlCallback(onLpLoad6Control);

inline function onLpLoad7Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA7.setFile( (f.toString(File.FullPath)));
				Sample7.set("text", f.toString(f.NoExtension));	
				root7.setValue(64); 
				root7.changed();
	});	

}
};

Content.getComponent("LpLoad7").setControlCallback(onLpLoad7Control);

inline function onLpLoad8Control(component, value)
{
if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
				LoopA8.setFile( (f.toString(File.FullPath)));
				Sample8.set("text", f.toString(f.NoExtension));	
				root8.setValue(64); 
				root8.changed();
	});	

}
};

Content.getComponent("LpLoad8").setControlCallback(onLpLoad8Control);

const var Roots = [Content.getComponent("root1"),
                     Content.getComponent("root2"),
                     Content.getComponent("root3"),
                     Content.getComponent("root4"),
                     Content.getComponent("root5"),
                     Content.getComponent("root6"),
                     Content.getComponent("root7"),
                     Content.getComponent("root8")];

inline function onLoadAllLoopControl(component, value)
{
	

                     
   for(s in Roots)
                s.setValue(64);
                
                for(s in Roots)
                       s.changed();                         
	      
            

if (value)
		{
		FileSystem.browse (FileSystem.AudioFiles, false, "*.wav,*.aif ", function (f) 
	{
	
	

	
LoopA1.setFile((f.toString(File.FullPath)));
	
LoopA2.setFile( (f.toString(File.FullPath)));

LoopA3.setFile( (f.toString(File.FullPath)));

LoopA4.setFile( (f.toString(File.FullPath)));

LoopA5.setFile( (f.toString(File.FullPath)));

LoopA6.setFile( (f.toString(File.FullPath)));

LoopA7.setFile( (f.toString(File.FullPath)));

LoopA8.setFile( (f.toString(File.FullPath)));

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


Content.getComponent("LoadAllLoop").setControlCallback(onLoadAllLoopControl);
