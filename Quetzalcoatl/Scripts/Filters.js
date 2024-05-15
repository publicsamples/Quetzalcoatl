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
       s.setAttribute(24, value);
};

Content.getComponent("Cut1").setControlCallback(onCut1Control);



inline function onRes1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(25, value);
};

Content.getComponent("Res1").setControlCallback(onRes1Control);


inline function onFilterType1Control(component, value)
{	
		for(s in Filters)
       s.setAttribute(32, value);
};

Content.getComponent("FilterType1").setControlCallback(onFilterType1Control);



inline function onFilterMix1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(23, value);
};

Content.getComponent("FilterMix1").setControlCallback(onFilterMix1Control);



inline function onCutMod1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(26, value);

};

Content.getComponent("CutMod1").setControlCallback(onCutMod1Control);

inline function onCutGlobalControl(component, value)
{
for(s in Filters)
       s.setAttribute(18, value);
};

Content.getComponent("CutGlobal").setControlCallback(onCutGlobalControl);



inline function onFilterEnv1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(6, value);
};

Content.getComponent("FilterEnv1").setControlCallback(onFilterEnv1Control);


inline function onFilterEnv2Control(component, value)
{
for(s in Filters)
       s.setAttribute(7, value);
};

Content.getComponent("FilterEnv2").setControlCallback(onFilterEnv2Control);



inline function onFilterVelControl(component, value)
{
	for(s in Filters)
       s.setAttribute(28, value);
};

Content.getComponent("FilterVel").setControlCallback(onFilterVelControl);


inline function onFilterTrkControl(component, value)
{
for(s in Filters)
       s.setAttribute(29, value);
};

Content.getComponent("FilterTrk").setControlCallback(onFilterTrkControl);


inline function onFilterMwControl(component, value)
{
	for(s in Filters)
       s.setAttribute(30, value);
};

Content.getComponent("FilterMw").setControlCallback(onFilterMwControl);


inline function onFilterATControl(component, value)
{
	for(s in Filters)
       s.setAttribute(31, value);
};

Content.getComponent("FilterAT").setControlCallback(onFilterATControl);




inline function onCutModSrc1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(19, value);
};

Content.getComponent("CutModSrc1").setControlCallback(onCutModSrc1Control);




inline function onFmasterSp1Control(component, value)
{
	for(s in FspA1)
    		  s.setSliderAtIndex(value, component.getSliderValueAt(value));
};

Content.getComponent("FmasterSp1").setControlCallback(onFmasterSp1Control);




