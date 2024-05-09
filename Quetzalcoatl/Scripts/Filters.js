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
       s.setAttribute(2, value);
};

Content.getComponent("Res1").setControlCallback(onRes1Control);


inline function onFilterType1Control(component, value)
{	
		for(s in Filters)
       s.setAttribute(4, value);
};

Content.getComponent("FilterType1").setControlCallback(onFilterType1Control);



inline function onFilterMix1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(6, value);
};

Content.getComponent("FilterMix1").setControlCallback(onFilterMix1Control);



inline function onCutMod1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(8, value);

};

Content.getComponent("CutMod1").setControlCallback(onCutMod1Control);




inline function onFilterEnv1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(10, value);
};

Content.getComponent("FilterEnv1").setControlCallback(onFilterEnv1Control);


inline function onCutModSrc1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(12, value);
};

Content.getComponent("CutModSrc1").setControlCallback(onCutModSrc1Control);





inline function onFilterA1Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(15, value);
};

Content.getComponent("FilterA1").setControlCallback(onFilterA1Control);

inline function onFilterD1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(16, value);
};

Content.getComponent("FilterD1").setControlCallback(onFilterD1Control);


inline function onFilterS1Control(component, value)
{
for(s in Filters)
       s.setAttribute(17, value);
};

Content.getComponent("FilterS1").setControlCallback(onFilterS1Control);


inline function onFilterR1Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(18, value);
};

Content.getComponent("FilterR1").setControlCallback(onFilterR1Control);
	
	
	



inline function onFilterA2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(19, value);
};

Content.getComponent("FilterA2").setControlCallback(onFilterA2Control);



inline function onFilterD2Control(component, value)
{
	for(s in Filters)
	       s.setAttribute(20, value);
};

Content.getComponent("FilterD2").setControlCallback(onFilterD2Control);

inline function onFilterS2Control(component, value)
{
		for(s in Filters)
       s.setAttribute(21, value);
};


Content.getComponent("FilterS2").setControlCallback(onFilterS2Control);
				
inline function onFilterR2Control(component, value)
{
		for(s in Filters)
	       s.setAttribute(22, value);
};

Content.getComponent("FilterR2").setControlCallback(onFilterR2Control);



inline function onFmasterSp1Control(component, value)
{
	for(s in FspA1)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("FmasterSp1").setControlCallback(onFmasterSp1Control);







inline function onScriptButton45Control(component, value)
{
 Fenv1.showControl(value);
 FmasterSp1.showControl(1-value);
};

Content.getComponent("ScriptButton45").setControlCallback(onScriptButton45Control);



