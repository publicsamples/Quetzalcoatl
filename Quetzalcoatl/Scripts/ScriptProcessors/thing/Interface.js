Content.makeFrontInterface(600, 500);

const var Combobox = Content.getComponent("Combobox");

const var samplemaps = [["A", "B", "C", "D", "E", "F", "G"],
                        ["H", "I", "J", "K", "L", "M", "N"]];

const var SampleSet = [Content.getComponent("SampleSet1"),
                       Content.getComponent("SampleSet2")];

Sampler.getSampleMapList();


// Select Category
inline function SampleSetCB(control, value)
{
    Combobox.set("items", "");
        
    if (SampleSet[0].getValue()){           // IF SampleSet1 seleted
        
        Combobox.set("items", samplemaps[0].join("\n"));
        
    } else {                                // IF SampleSet2 selected
        
        Combobox.set("items", samplemaps[1].join("\n"));
    }
}
for (s in SampleSet) s.setControlCallback(SampleSetCB);



// Load SampleMap
inline function onComboboxControl(component, value)
{
    if (SampleSet[0].getValue()){           // IF SampleSet1 seleted
        
        Sampler.loadSampleMap(samplemaps[0][Combobox.getValue() - 1]);
        
    } else {                                // IF SampleSet2 selected
        
        Sampler.loadSampleMap(samplemaps[1][Combobox.getValue() - 1]);
    }
};
Combobox.setControlCallback(onComboboxControl);


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
 