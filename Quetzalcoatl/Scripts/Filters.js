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
       s.setAttribute(2, value);
};

Content.getComponent("ResSrc").setControlCallback(onResSrcControl);

const var FilterOff = Content.getComponent("FilterOff");
const var FoldExtra = Content.getComponent("FoldExtra");
const var CUTLABLE = Content.getComponent("CUTLABLE");
const var QLABEL = Content.getComponent("QLABEL");





inline function onFilterType1Control(component, value)
{
	if(value == 1)
	    	{

   for(s in Filters)
       s.setAttribute(4, 1);
    for(e in Filters)
        e.setBypassed(0);
       FilterOff.showControl(0);
       CUTLABLE.set("text", "freq");
       QLABEL.set("text", "q");
       FoldExtra.showControl(0);
       
       }
       
    if(value == 2)
        	{
    
       for(s in Filters)
           s.setAttribute(4, 2);
       for(e in Filters)
                            e.setBypassed(0);
           FilterOff.showControl(0);
           CUTLABLE.set("text", "freq");
                QLABEL.set("text", "q");
                FoldExtra.showControl(0);
           }   
           
      if(value == 3)
             	{
         
            for(s in Filters)
                s.setAttribute(4, 3);
            for(e in Filters)
                            e.setBypassed(0);
                FilterOff.showControl(0);
                CUTLABLE.set("text", "freq");
                     QLABEL.set("text", "q");
                     FoldExtra.showControl(0);
                }      
      if(value == 4)
                  	{
              
                 for(s in Filters)
                     s.setAttribute(4, 4);
                   for(e in Filters)
                            e.setBypassed(0);
                     FilterOff.showControl(0);
                     CUTLABLE.set("text", "freq");
                          QLABEL.set("text", "q");
                          FoldExtra.showControl(0);
                     }      
     if(value == 5)
                 	{
             
                for(s in Filters)
                    s.setAttribute(4, 5);
                    for(e in Filters)
                            e.setBypassed(0);
                    FilterOff.showControl(0);
                    CUTLABLE.set("text", "freq");
                         QLABEL.set("text", "q");
                         FoldExtra.showControl(0);
                    }   
     if(value == 6)
                      	{
                  
                     for(s in Filters)
                         s.setAttribute(4, 6);
                         for(e in Filters)
                            e.setBypassed(0);
                         FilterOff.showControl(0);
                         CUTLABLE.set("text", "fold");
                         QLABEL.set("text", "cut");
                         FoldExtra.showControl(1);
                         }   
    if(value == 7)
                         
                          	{
                      
                         for(s in Filters)
                             s.setAttribute(4, 8);
                         for(e in Filters)    
                             e.setBypassed(1);
                             FilterOff.showControl(1);
                             CUTLABLE.set("text", "off");
                             QLABEL.set("text", "off");
                             FoldExtra.showControl(0);
                             }                                                                                               
};

Content.getComponent("FilterType1").setControlCallback(onFilterType1Control);						


inline function onCutGlobalControl(component, value)
{
for(s in Filters)
       s.setAttribute(8, value);
};

Content.getComponent("CutGlobal").setControlCallback(onCutGlobalControl);

inline function onCutModSrc1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(9, value);
};

Content.getComponent("CutModSrc1").setControlCallback(onCutModSrc1Control);

inline function onFilterVelControl(component, value)
{
	for(s in Filters)
       s.setAttribute(10, value);
};

Content.getComponent("FilterVel").setControlCallback(onFilterVelControl);


inline function onFilterTrkControl(component, value)
{
	for(s in Filters)
       s.setAttribute(11, value);
};

Content.getComponent("FilterTrk").setControlCallback(onFilterTrkControl);


inline function onFilterAtControl(component, value)
{
	for(s in Filters)
       s.setAttribute(13, value);
};

Content.getComponent("FilterAt").setControlCallback(onFilterAtControl);


inline function onFoldRangeControl(component, value)
{
	for(s in Filters)
       s.setAttribute(34, value);
};

Content.getComponent("FoldRange").setControlCallback(onFoldRangeControl);

inline function onFoldQControl(component, value)
{
		for(s in Filters)
       s.setAttribute(35, value);
};

Content.getComponent("FoldQ").setControlCallback(onFoldQControl);


//Mix

inline function onFilterMix1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(31, value);
};

Content.getComponent("FilterMix1").setControlCallback(onFilterMix1Control);



inline function onMixModControl(component, value)
{
	for(s in Filters)
       s.setAttribute(32, value);
};

Content.getComponent("MixMod").setControlCallback(onMixModControl);

inline function onMixSrcControl(component, value)
{
	for(s in Filters)
       s.setAttribute(33, value);
};

Content.getComponent("MixSrc").setControlCallback(onMixSrcControl);


inline function onFmasterSp1Control(component, value)
{
	for(s in FspA1)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("FmasterSp1").setControlCallback(onFmasterSp1Control);




