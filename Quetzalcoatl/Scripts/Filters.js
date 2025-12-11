//FILTER



const var Filters = [Synth.getEffect("F1"),
					Synth.getEffect("F2"),
					Synth.getEffect("F3"),
					Synth.getEffect("F4"),
					Synth.getEffect("F5"),
					Synth.getEffect("F6"),
					Synth.getEffect("F7"),
					Synth.getEffect("F8")];
					

inline function onCut1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(0, value);
};

Content.getComponent("Cut1").setControlCallback(onCut1Control);



inline function onRes1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(1, value);
};

Content.getComponent("Res1").setControlCallback(onRes1Control);


inline function onResModControl(component, value)
{
	for(s in Filters)
       s.setAttribute(3, value);
};

Content.getComponent("ResMod").setControlCallback(onResModControl);


inline function onResSrcControl(component, value)
{
	for(s in Filters)
       s.setAttribute(2, value-1);
};

Content.getComponent("ResSrc").setControlCallback(onResSrcControl);

const var FilterOff = Content.getComponent("FilterOff");


inline function onFilterType1Control(component, value)
{
	if(value == 1)
	    	{

   for(s in Filters)
       s.setAttribute(4, 1);
    for(e in Filters)
        e.setBypassed(0);
       FilterOff.showControl(0);
      

       
       }
       
    if(value == 2)
        	{
    
       for(s in Filters)
           s.setAttribute(4, 2);
       for(e in Filters)
                            e.setBypassed(0);
           FilterOff.showControl(0);
         

           }   
           
      if(value == 3)
             	{
         
            for(s in Filters)
                s.setAttribute(4, 3);
            for(e in Filters)
                            e.setBypassed(0);
                FilterOff.showControl(0);
               
                }      
      if(value == 4)
                  	{
              
                 for(s in Filters)
                     s.setAttribute(4, 4);
                   for(e in Filters)
                            e.setBypassed(0);
                     FilterOff.showControl(0);
                  

                     }      
     if(value == 5)
                 	{
             
                for(s in Filters)
                    s.setAttribute(4, 5);
                    for(e in Filters)
                            e.setBypassed(0);
                    FilterOff.showControl(0);
                

                    }   
     
    if(value == 6)
                         
                          	{
                      
                         for(s in Filters)
                             s.setAttribute(4, 8);
                         for(e in Filters)    
                             e.setBypassed(1);
                             FilterOff.showControl(1);
                          
                         
                             }                                                                                               
};

Content.getComponent("FilterType1").setControlCallback(onFilterType1Control);						


inline function onCutGlobalControl(component, value)
{
for(s in Filters)
       s.setAttribute(s.Global, value);
};

Content.getComponent("CutGlobal").setControlCallback(onCutGlobalControl);


inline function onCutGlobal1Control(component, value)
{
	
for(s in Filters)
       s.setAttribute(s.CutMonoMod, value);
};

Content.getComponent("CutGlobal1").setControlCallback(onCutGlobal1Control);



inline function onCutModSrc1Control(component, value)
{


	for(s in Filters)
       s.setAttribute(s.GlobalSrc, value-1);
};

Content.getComponent("CutModSrc1").setControlCallback(onCutModSrc1Control);


inline function onCutModSrc3Control(component, value)
{
	for(s in Filters)
       s.setAttribute(s.CutMonoSrc, value-1);
};

Content.getComponent("CutModSrc3").setControlCallback(onCutModSrc3Control);

inline function onFilterVelControl(component, value)
{
	for(s in Filters)
       s.setAttribute(s.Vel, value);
};

Content.getComponent("FilterVel").setControlCallback(onFilterVelControl);


inline function onFilterTrkControl(component, value)
{
	for(s in Filters)
       s.setAttribute(s.Trk, value);
};

Content.getComponent("FilterTrk").setControlCallback(onFilterTrkControl);


inline function onFilterAtControl(component, value)
{
	for(s in Filters)
       s.setAttribute(s.AT, value);
};

Content.getComponent("FilterAt").setControlCallback(onFilterAtControl);


inline function onFoldRangeControl(component, value)
{
	for(s in Filters)
       s.setAttribute(s.FoldOffset, value);
};

Content.getComponent("FoldRange").setControlCallback(onFoldRangeControl);

inline function onFoldControl(component, value)
{
		for(s in Filters)
       s.setAttribute(s.Fold, value);
};

Content.getComponent("Fold").setControlCallback(onFoldControl);


inline function onFoldModControl(component, value)
{
	for(s in Filters)
       s.setAttribute(s.RangeMod, value);
};

Content.getComponent("FoldMod").setControlCallback(onFoldModControl);



inline function onFoldModSrcControl(component, value)
{
	for(s in Filters)
	       s.setAttribute(s.RangeSrx, value);
};

Content.getComponent("FoldModSrc").setControlCallback(onFoldModSrcControl);


inline function onFoldSmoothControl(component, value)
{
		for(s in Filters)
	       s.setAttribute(s.FoldSmooth, value);
};

Content.getComponent("FoldSmooth").setControlCallback(onFoldSmoothControl);


const var PreLabel = Content.getComponent("PreLabel");


inline function onFoldPreControl(component, value)
{
	
	 if(value == 0)
	 {

for(s in Filters)
       s.setAttribute(s.FoldPos, 0);
       PreLabel.setValue("post filter");
   
       }
       
       if(value == 1)
       	 {
       
       for(s in Filters)
             s.setAttribute(s.FoldPos, 1);
             PreLabel.setValue("pre filter");
    
             }
};

Content.getComponent("FoldPre").setControlCallback(onFoldPreControl);



//Mix

inline function onFilterMix1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(s.Stage1, value);
};

Content.getComponent("FilterMix1").setControlCallback(onFilterMix1Control);



inline function onMixModControl(component, value)
{
	for(s in Filters)
       s.setAttribute(s.Stage2, value);
};

Content.getComponent("MixMod").setControlCallback(onMixModControl);

inline function onMixSrcControl(component, value)
{
	for(s in Filters)
       s.setAttribute(s.Stage3, value);
};

Content.getComponent("MixSrc").setControlCallback(onMixSrcControl);



inline function onFmasterSp1Control(component, value)
{
	for(s in FspA1)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("FmasterSp1").setControlCallback(onFmasterSp1Control);



inline function onFoldSwitchControl(component, value)
{
	if(value == 0)
	 {
	
	Folder.showControl(0);
	FmasterSp1.showControl(1);
	}
	
	if(value == 1)
		 {
		
		Folder.showControl(1);
		FmasterSp1.showControl(0);
		}

};

Content.getComponent("FoldSwitch").setControlCallback(onFoldSwitchControl);


const var FoldLabel = Content.getComponent("FoldLabel");

const var SmoothLabel = Content.getComponent("SmoothLabel");


const var FileFmControls = [Content.getComponent("FmFile"),
                            Content.getComponent("FoldQlabel1"),
                            Content.getComponent("FoldQlabel2"),
                            Content.getComponent("FmRel"),
                            Content.getComponent("FmAttk")];


inline function onFilterType2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(s.FoldSub, value);

if(value == 1)
	 {
	
	for(s in FileFmControls)
	    s.showControl(0);
	FoldLabel.setValue("fold");
	SmoothLabel.setValue("smooth");
	}
	
if(value == 2)
	 {
	
	for(s in FileFmControls)
	    s.showControl(0);
	FoldLabel.setValue("fold");
	SmoothLabel.setValue("smooth");
	}	
if(value == 3)
	 {
	
	for(s in FileFmControls)
	    s.showControl(0);
	FoldLabel.setValue("fold");
	SmoothLabel.setValue("smooth");
	}	
	
if(value == 4)
	 {
	
	for(s in FileFmControls)
	    s.showControl(0);
	FoldLabel.setValue("FM");
	SmoothLabel.setValue("ratio");
	}
	
	if(value == 5)
		 {
		
		for(s in FileFmControls)
		    s.showControl(0);
		FoldLabel.setValue("FM");
		SmoothLabel.setValue("ratio");
		}
	
	if(value == 6)
		 {
		
		for(s in FileFmControls)
		    s.showControl(1);
		FoldLabel.setValue("FM");
		SmoothLabel.setValue("AM");
		}	
		
	
};

Content.getComponent("FilterType2").setControlCallback(onFilterType2Control);

const var Fs1 = Synth.getAudioSampleProcessor("F1");
const var Fs2 = Synth.getAudioSampleProcessor("F2");
const var Fs3 = Synth.getAudioSampleProcessor("F3");
const var Fs4 = Synth.getAudioSampleProcessor("F4");
const var Fs5 = Synth.getAudioSampleProcessor("F5");
const var Fs6 = Synth.getAudioSampleProcessor("F6");
const var Fs7 = Synth.getAudioSampleProcessor("F7");
const var Fs8 = Synth.getAudioSampleProcessor("F8");

const slot1 = Fs1.getAudioFile(0);
const slot2 = Fs2.getAudioFile(0);
const slot3 = Fs3.getAudioFile(0);
const slot4 = Fs4.getAudioFile(0);
const slot5 = Fs5.getAudioFile(0);
const slot6 = Fs6.getAudioFile(0);
const slot7 = Fs7.getAudioFile(0);
const slot8 = Fs8.getAudioFile(0);
		    
inline function onFmFileControl(component, value)
{
	slot1.loadFile("{XYZ::SampleMap}" + component.getItemText());
	slot2.loadFile("{XYZ::SampleMap}" + component.getItemText());
	slot3.loadFile("{XYZ::SampleMap}" + component.getItemText());
	slot4.loadFile("{XYZ::SampleMap}" + component.getItemText());
	slot5.loadFile("{XYZ::SampleMap}" + component.getItemText());
	slot6.loadFile("{XYZ::SampleMap}" + component.getItemText());
	slot7.loadFile("{XYZ::SampleMap}" + component.getItemText());
	slot8.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

Content.getComponent("FmFile").setControlCallback(onFmFileControl);


inline function onFmAttkControl(component, value)
{
	for(s in Filters)
	       s.setAttribute(s.fmAtk, value);
};

Content.getComponent("FmAttk").setControlCallback(onFmAttkControl);


inline function onFmRelControl(component, value)
{
	for(s in Filters)
	       s.setAttribute(s.FmRel, value);
};

Content.getComponent("FmRel").setControlCallback(onFmRelControl);

