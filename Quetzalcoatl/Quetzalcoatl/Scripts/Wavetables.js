const var WavetableSynthesiser1 = Synth.getWavetableController("ImportWT");

 //SAVE
 
 const var UserWtFolder = FileSystem.getFolder(FileSystem.AudioFiles).getChildFile("UserWT");
 
 
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
 
// const var Group5 = Synth.getChildSynth("Group5");

const var SynthGroups =[];

for (i = 0; i < 8; i++)
{
    SynthGroups[i] = Synth.getChildSynth("Group"+(i+1));

} 
 
const var ImportWT = Synth.getChildSynth("ImportWT");
const var WtImportOverLay = Content.getComponent("WtImportOverLay");
 const var WtImporter = Content.getComponent("WtImporter");
 const var ImportWTable = Synth.getAudioSampleProcessor("ImportWT");
inline function onWtImporterControl(component, value)
{
	if (value == 0)
	{
		for(s in SynthGroups)
	s.setBypassed(0);
	
		ImportWT.setBypassed(1);
		WtImportOverLay.showControl(0);
//		WavetableSynthesiser1.
	}
	
	if (value == 1)
	{

	for(s in SynthGroups)
	s.setBypassed(1);

		ImportWT.setBypassed(0);
		WtImportOverLay.showControl(1);
	}
};

Content.getComponent("WtImporter").setControlCallback(onWtImporterControl);


inline function onCloseWtImpControl(component, value)
{
	WtImporter.setValue(0);
	WtImporter.changed();
	WavetableSynthesiser1.setEnableResynthesisCache(FileSystem.AudioFiles, 1);
	ImportWTable.setFile(0);
	
};

Content.getComponent("CloseWtImp").setControlCallback(onCloseWtImpControl);


