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

inline function onFilterType1Control(component, value)
{	
		for(s in Filters)
       s.setAttribute(4, value);
};

Content.getComponent("FilterType1").setControlCallback(onFilterType1Control);

inline function onFilterEnv1Control(component, value)
{
		for(s in Filters)
       s.setAttribute(5, value);
};

Content.getComponent("FilterEnv1").setControlCallback(onFilterEnv1Control);


inline function onFilterEnv2Control(component, value)
{
for(s in Filters)
       s.setAttribute(6, value);
};

Content.getComponent("FilterEnv2").setControlCallback(onFilterEnv2Control);


inline function onCutMod1Control(component, value)
{
	for(s in Filters)
       s.setAttribute(7, value);

};

Content.getComponent("CutMod1").setControlCallback(onCutMod1Control);

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


inline function onFilterMwControl(component, value)
{
	for(s in Filters)
       s.setAttribute(12, value);
};

Content.getComponent("FilterMw").setControlCallback(onFilterMwControl);


inline function onFilterATControl(component, value)
{
	for(s in Filters)
       s.setAttribute(13, value);
};

Content.getComponent("FilterAT").setControlCallback(onFilterATControl);


inline function onFilterTempoControl(component, value)
{
	for(s in Filters)
       s.setAttribute(14, value);
};

Content.getComponent("FilterTempo").setControlCallback(onFilterTempoControl);


inline function onFilterDivControl(component, value)
{
		for(s in Filters)
       s.setAttribute(15, value);
};

Content.getComponent("FilterDiv").setControlCallback(onFilterDivControl);


inline function onFilterTrigControl(component, value)
{
		for(s in Filters)
       s.setAttribute(16, value);
};

Content.getComponent("FilterTrig").setControlCallback(onFilterTrigControl);


inline function onFilterLFOShpControl(component, value)
{
		for(s in Filters)
       s.setAttribute(17, value);
};

Content.getComponent("FilterLFOShp").setControlCallback(onFilterLFOShpControl);


inline function onFilterAControl(component, value)
{
		for(s in Filters)
       s.setAttribute(18, value);
};

Content.getComponent("FilterA").setControlCallback(onFilterAControl);


inline function onFilterDControl(component, value)
{
		for(s in Filters)
       s.setAttribute(19, value);
};

Content.getComponent("FilterD").setControlCallback(onFilterDControl);

inline function onFilterSControl(component, value)
{
	for(s in Filters)
       s.setAttribute(20, value);
};

Content.getComponent("FilterS").setControlCallback(onFilterSControl);

inline function onFilterRControl(component, value)
{
		for(s in Filters)
       s.setAttribute(21, value);
};

Content.getComponent("FilterR").setControlCallback(onFilterRControl);

inline function onFilterA2Control(component, value)
{
for(s in Filters)
       s.setAttribute(22, value);
};

Content.getComponent("FilterA2").setControlCallback(onFilterA2Control);

inline function onFilterR2Control(component, value)
{
for(s in Filters)
       s.setAttribute(23, value);
};

Content.getComponent("FilterR2").setControlCallback(onFilterR2Control);


inline function onXfTempo6Control(component, value)
{
for(s in Filters)
       s.setAttribute(24, value);	
};

Content.getComponent("XfTempo6").setControlCallback(onXfTempo6Control);

inline function onFilterDiv2Control(component, value)
{
	for(s in Filters)
       s.setAttribute(25, value);
};

Content.getComponent("FilterDiv2").setControlCallback(onFilterDiv2Control);

inline function onFilterArTrigControl(component, value)
{
	for(s in Filters)
       s.setAttribute(26, value);
};

Content.getComponent("FilterArTrig").setControlCallback(onFilterArTrigControl);

inline function onFilterCrvControl(component, value)
{
		for(s in Filters)
       s.setAttribute(27, value);
};

Content.getComponent("FilterCrv").setControlCallback(onFilterCrvControl);

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




