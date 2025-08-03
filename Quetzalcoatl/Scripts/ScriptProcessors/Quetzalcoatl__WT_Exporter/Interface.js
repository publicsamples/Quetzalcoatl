 Content.makeFrontInterface(380, 350);


//include("Wavetables.js");


//Synth.setUseUniformVoiceHandler("Quetzalcoatl", true);
const var rm = Engine.getGlobalRoutingManager();

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");
Engine.loadAudioFilesIntoPool();

const var laf = Engine.createGlobalScriptLookAndFeel();
Settings.setZoomLevel(1);
//Settings.setVoiceMultiplier(8);

laf.registerFunction("drawComboBox", function(g, obj)
{
  	g.setColour(obj.bgColour);
	g.fillRect(obj.area);
	g.setColour(obj.textColour);
//	g.drawAlignedText(obj.text, obj.area, "centred");

	g.setFont("Montserrat", 12.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");

});



laf.registerFunction("drawPresetBrowserListItem", function(g, obj)
{
	
	g.setFont("Montserrat",14);

	g.setColour(Colours.black);
	g.drawAlignedText("  "+ obj.text, obj.area, "left");
	
    if(obj.selected)
    {	
   	 g.setFont("FMontserrat",14);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
        g.fillRoundedRectangle(obj.area,4);
     //   g.setColour(presetOnColour);
        g.drawAlignedText("  " + obj.text, obj.area, "left");
    } 

});

laf.registerFunction("drawDialogButton", function(g, obj)
{

//g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
//  g.drawRoundedRectangle(obj.area, 3.0, 3.0);
  g.setColour(0xFF22251D);
 g.fillRoundedRectangle(obj.area,4);
 g.setFont("Montserrat", 18.0);
 

  var a = obj.area;
  g.setColour(0xFFCDB65B);
 g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");
});


const var preloadBar = Content.getComponent("preloadBar");
preloadBar.setPaintRoutine(function(g)
{
	g.fillAll(this.get("bgColour"));
	g.setColour(this.get("itemColour"));
	g.fillRect([0, 0, this.getWidth() * this.data.progress, this.getHeight()]);
});

preloadBar.setTimerCallback(function()
{
	this.data.progress = Engine.getPreloadProgress();
	this.repaint();	
});

preloadBar.setLoadingCallback(function(isPreloading)
{
    this.data.progress = 0.0;
    this.set("visible", isPreloading);
    
	if(isPreloading)
        this.startTimer(80);
    else
        this.stopTimer();
});

const var WavetableSynthesiser1 = Synth.getWavetableController("ImportWT");
const var WtOpt = WavetableSynthesiser1.getResynthesisOptions();

const var PhaseModes1 = {"PhaseMode": 1};
const var PhaseModes2 = {"PhaseMode": 2};
const var PhaseModes3 = {"PhaseMode": 3};

const var ForceResyn = 
{
			"ForceResynthesis": 1
	
};

 //SAVE
 
 const var UserWtFolder = FileSystem.getFolder(FileSystem.AudioFiles).getChildFile("UserWT");
 
 
 inline function onPhaseModeCbControl(component, value)
 {
 	WavetableSynthesiser1.setResynthesisOptions(PhaseModes1);
 };
 
 Content.getComponent("PhaseModeCb").setControlCallback(onPhaseModeCbControl);
 
 
 function save(file)
 {
     WavetableSynthesiser1.saveAsHwt(file);
 }
 
 
 inline function onSaveFileControl(component, value)
 {
 	if (value == 1)
 	{
 	FileSystem.browse(UserWtFolder, true, "*.hwt", save);
 	}
 if (value == 0){
 WavetableSynthesiser1.setEnableResynthesisCache(FileSystem.AudioFiles, 1);
 ImportWTable.setFile(0);
 }
 };
 
 Content.getComponent("SaveFile").setControlCallback(onSaveFileControl);
 
 //LOAD
 
 function load(file)
 {
     WavetableSynthesiser1.loadData(file, 44100, 0);
 }
 

 inline function onLoadFileControl(component, value)
 {
 	if (value == 1)

 	FileSystem.browse(FileSystem.Downloads, false, "*.wav, *.aif", load);


 };
 
 Content.getComponent("LoadFile").setControlCallback(onLoadFileControl);

 const var ScriptPanel1 = Content.getComponent("ScriptPanel1");
 
 

inline function onScriptButton1Control(component, value)
{
	ScriptPanel1.showControl(value);
};

Content.getComponent("ScriptButton1").setControlCallback(onScriptButton1Control);



inline function onReSynControl(component, value)
{
	WavetableSynthesiser1.setResynthesisOptions(ForceReSyn);
};

Content.getComponent("ReSyn").setControlCallback(onReSynControl);


function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 