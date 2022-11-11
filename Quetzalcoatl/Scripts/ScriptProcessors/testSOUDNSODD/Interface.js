Content.makeFrontInterface(885, 745);

include("waves.js");

//RR

// This button will control the behaviour:
// - ON: the sine generators will be cycled
// - OFF: all will be played each time
const var Enable = Content.getComponent("Enable");

// Grab a reference to the MIDI filters
const var filters = [Synth.getMidiProcessor("ChanFilter1"),
                     Synth.getMidiProcessor("ChanFilter2"),
                     Synth.getMidiProcessor("ChanFilter3"),
                     Synth.getMidiProcessor("ChanFilter4"),
                     Synth.getMidiProcessor("ChanFilter5"),
                     Synth.getMidiProcessor("ChanFilter6")];

inline function bCallback(control, value)
{
    // Bypass all filters if its off
    for(f in filters)
        f.setBypassed(!value);
}

Enable.setControlCallback(bCallback);

/** This is a data structure that can be used for
    storing any kind of information with the event
    ID as hash key.
    
    In order to use it, pass an array into the 
    init() function, then use the functions 
    
    push() and pop() to add or return values
    using the event ID as hash key.
    
    For performance reasons, it will not sort entries
    but just pick the first idle slot when you push new
    data.
*/
namespace EventIdStack
{
    // Should be enough, but you can add more if you want...
    const var MAX_SIZE = 128;
    
    /** Call this function to initialise the data
        array with the internal data structure.
    */
    inline function init(data)
    {
        data.reserve(MAX_SIZE);
        
        for(i = 0; i < MAX_SIZE; i++)
        {
            data[i] = [-1, undefined];
        }
    }
    
    /** This adds the given value to the data array
        using the event ID as hash key.
    */
    inline function push(data, eventId, value)
    {
        for(d in data)
        {
            if(d[0] == -1)
            {
                d[0] = eventId;
                d[1] = value;
                return;
            }
        }
        
        // Full...
        Console.assertTrue(false);
    }
    
    /** Returns the value for the given eventID and
        removes the data from the slot. 
    */
    inline function pop(data, eventId)
    {
        for(d in data)
        {
            if(d[0] == eventId)
            {
                d[0] = -1;
                return d[1];
            }
        }
        
        // Can't find it...
        Console.assertTrue(false);
    }
}


// We need to store the MIDI channels for each note number
const var noteOnChannels = [];

// Let's use that fancy data structure for our problem...
EventIdStack.init(noteOnChannels);



// the RR counter
reg rrIndex = 0;



 



//presets

const var Pbox = [];

Pbox[0] = Content.getComponent("settings");
Pbox[1] = Content.getComponent("blank1");
Pbox[2] = Content.getComponent("blank2");

const var pre= Content.getComponent("presets");

inline function onpresetsControl(component, value)
{
    for (i = 0; i < Pbox.length; i++)
        Pbox[i].showControl(value - 1 == i);
};


Content.getComponent("presets").setControlCallback(onpresetsControl);

function onControl(number, value)
{
    if(number == widget1)
    {
        Module1.setAttribute(Module1.Parameter, value);
    }
    else if (number == widget2)
    {
        Module2.setAttribute(Module2.Parameter, value);
    }
}

const var Sampler1 = Synth.getSampler("Sampler1");
const var Sampler2 = Synth.getSampler("Sampler2");
const var Sampler3 = Synth.getSampler("Sampler3");
const var Sampler4 = Synth.getSampler("Sampler4");
const var Sampler5 = Synth.getSampler("Sampler5");
const var Sampler6 = Synth.getSampler("Sampler6");
const var Sampler7 = Synth.getSampler("Sampler7");
const var Sampler8 = Synth.getSampler("Sampler8");
const var Sampler9 = Synth.getSampler("Sampler9");
const var Sampler10 = Synth.getSampler("Sampler10");
const var Sampler11 = Synth.getSampler("Sampler11");
const var Sampler12 = Synth.getSampler("Sampler12");
const var Sampler13 = Synth.getSampler("Sampler13");
const var Sampler14 = Synth.getSampler("Sampler14");
const var Sampler15 = Synth.getSampler("Sampler15");
const var Sampler16 = Synth.getSampler("Sampler16");
const var Sampler17 = Synth.getSampler("Sampler17");
const var Sampler18 = Synth.getSampler("Sampler18");
const var Sampler19 = Synth.getSampler("Sampler19");
const var Sampler20 = Synth.getSampler("Sampler20");
const var Sampler21 = Synth.getSampler("Sampler21");
const var Sampler22 = Synth.getSampler("Sampler22");
const var Sampler23 = Synth.getSampler("Sampler23");
const var Sampler24 = Synth.getSampler("Sampler24");
const var Sampler25 = Synth.getSampler("Sampler25");
const var Sampler26 = Synth.getSampler("Sampler26");
const var Sampler27 = Synth.getSampler("Sampler27");
const var Sampler28 = Synth.getSampler("Sampler28");
const var Sampler29 = Synth.getSampler("Sampler29");
const var Sampler30 = Synth.getSampler("Sampler30");
const var Sampler31 = Synth.getSampler("Sampler31");
const var Sampler32 = Synth.getSampler("Sampler32");
const var Sampler33 = Synth.getSampler("Sampler33");
const var Sampler34 = Synth.getSampler("Sampler34");
const var Sampler35 = Synth.getSampler("Sampler35");
const var Sampler36 = Synth.getSampler("Sampler36");
const var Sampler37 = Synth.getSampler("Sampler37");
const var Sampler38 = Synth.getSampler("Sampler38");
const var Sampler39 = Synth.getSampler("Sampler39");
const var Sampler40 = Synth.getSampler("Sampler40");
const var Sampler41 = Synth.getSampler("Sampler41");
const var Sampler42 = Synth.getSampler("Sampler42");
const var Sampler43 = Synth.getSampler("Sampler43");
const var Sampler44 = Synth.getSampler("Sampler44");
const var Sampler45 = Synth.getSampler("Sampler45");
const var Sampler46 = Synth.getSampler("Sampler46");
const var Sampler47 = Synth.getSampler("Sampler47");
const var Sampler48 = Synth.getSampler("Sampler48");
const var Sampler49 = Synth.getSampler("Sampler49");
const var Sampler50 = Synth.getSampler("Sampler50");
const var Sampler51 = Synth.getSampler("Sampler51");
const var Sampler52 = Synth.getSampler("Sampler52");
const var Sampler53 = Synth.getSampler("Sampler53");
const var Sampler54 = Synth.getSampler("Sampler54");
const var sampleMaps = Sampler.getSampleMapList();

//sample menus

const var Shape = Content.getComponent("Shape");
const var ShapeLabel = Content.getComponent("ShapeLabel");

  Content.setPropertiesFromJSON("Shape", {

	"popupMenuItems": "AMwaves" > 1 ? AMwaves.join("\n") : "",

	});

inline function onShapeControl(component, value)
{
	ShapeLabel.set("text",Shape.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FilMod::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX::","").replace("sys::",""));




    Sampler1.loadSampleMap(sampleMaps[value-1]);
    Sampler10.loadSampleMap(sampleMaps[value-1]);
    Sampler19.loadSampleMap(sampleMaps[value-1]);
    Sampler28.loadSampleMap(sampleMaps[value-1]);
    Sampler37.loadSampleMap(sampleMaps[value-1]);
    Sampler46.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape").setControlCallback(onShapeControl);

Shape.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape2 = Content.getComponent("Shape2");
const var ShapeLabel2 = Content.getComponent("ShapeLabel2");


  Content.setPropertiesFromJSON("Shape2", {

	"popupMenuItems": "AMwaves" > 1 ? AMwaves.join("\n") : "",

	});

inline function onShape2Control(component, value)
{
	ShapeLabel2.set("text",Shape2.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FilMod::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX::","").replace("sys::",""));



    Sampler2.loadSampleMap(sampleMaps[value-1]);
    Sampler11.loadSampleMap(sampleMaps[value-1]);
    Sampler20.loadSampleMap(sampleMaps[value-1]);
    Sampler29.loadSampleMap(sampleMaps[value-1]);
    Sampler38.loadSampleMap(sampleMaps[value-1]);
    Sampler47.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape2").setControlCallback(onShape2Control);

Shape2.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape3 = Content.getComponent("Shape3");
const var ShapeLabel3 = Content.getComponent("ShapeLabel3");


  Content.setPropertiesFromJSON("Shape3", {

	"popupMenuItems": "AMwaves" > 1 ? AMwaves.join("\n") : "",

	});

inline function onShape3Control(component, value)
{
	ShapeLabel3.set("text",Shape3.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FilMod::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX::","").replace("sys::",""));


    Sampler3.loadSampleMap(sampleMaps[value-1]);
    Sampler12.loadSampleMap(sampleMaps[value-1]);
    Sampler21.loadSampleMap(sampleMaps[value-1]);
       Sampler30.loadSampleMap(sampleMaps[value-1]);
       Sampler39.loadSampleMap(sampleMaps[value-1]);
       Sampler48.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape3").setControlCallback(onShape3Control);

Shape3.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape4 = Content.getComponent("Shape4");
const var ShapeLabel4 = Content.getComponent("ShapeLabel4");


  Content.setPropertiesFromJSON("Shape4", {

	"popupMenuItems": "AMwaves" > 1 ? AMwaves.join("\n") : "",

	});

inline function onShape4Control(component, value)
{
	ShapeLabel4.set("text",Shape4.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FilMod::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX::","").replace("sys::",""));



    Sampler4.loadSampleMap(sampleMaps[value-1]);
    Sampler13.loadSampleMap(sampleMaps[value-1]);
    Sampler22.loadSampleMap(sampleMaps[value-1]);
    Sampler31.loadSampleMap(sampleMaps[value-1]);
    Sampler40.loadSampleMap(sampleMaps[value-1]);
    Sampler49.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape4").setControlCallback(onShape4Control);

Shape4.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape5 = Content.getComponent("Shape5");
const var ShapeLabel5 = Content.getComponent("ShapeLabel5");


  Content.setPropertiesFromJSON("Shape5", {

	"popupMenuItems": "AMwaves" > 1 ? AMwaves.join("\n") : "",

	});

inline function onShape5Control(component, value)
{
	ShapeLabel5.set("text",Shape5.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FilMod::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX::","").replace("sys::",""));



    Sampler5.loadSampleMap(sampleMaps[value-1]);
    Sampler14.loadSampleMap(sampleMaps[value-1]);
        Sampler23.loadSampleMap(sampleMaps[value-1]);
        Sampler32.loadSampleMap(sampleMaps[value-1]);
        Sampler41.loadSampleMap(sampleMaps[value-1]);
        Sampler50.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape5").setControlCallback(onShape5Control);

Shape5.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape6 = Content.getComponent("Shape6");
const var ShapeLabel6 = Content.getComponent("ShapeLabel6");

  Content.setPropertiesFromJSON("Shape6", {

	"popupMenuItems": "AMwaves" > 1 ? AMwaves.join("\n") : "",

	});

inline function onShape6Control(component, value)
{
	ShapeLabel6.set("text",Shape6.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FilMod::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX::","").replace("sys::",""));

    Sampler6.loadSampleMap(sampleMaps[value-1]);
    Sampler15.loadSampleMap(sampleMaps[value-1]);
           Sampler24.loadSampleMap(sampleMaps[value-1]);
           Sampler33.loadSampleMap(sampleMaps[value-1]);
           Sampler42.loadSampleMap(sampleMaps[value-1]);
           Sampler51.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape6").setControlCallback(onShape6Control);

Shape6.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape7 = Content.getComponent("Shape7");
const var ShapeLabel7 = Content.getComponent("ShapeLabel7");

  Content.setPropertiesFromJSON("Shape7", {

	"popupMenuItems": "AMwaves" > 1 ? AMwaves.join("\n") : "",

	});
inline function onShape7Control(component, value)
{
	ShapeLabel7.set("text",Shape7.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FilMod::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX::","").replace("sys::",""));

    Sampler7.loadSampleMap(sampleMaps[value-1]);
    Sampler16.loadSampleMap(sampleMaps[value-1]);
               Sampler25.loadSampleMap(sampleMaps[value-1]);
               Sampler34.loadSampleMap(sampleMaps[value-1]);
               Sampler43.loadSampleMap(sampleMaps[value-1]);
               Sampler52.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape7").setControlCallback(onShape7Control);

Shape7.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape8 = Content.getComponent("Shape8");
const var ShapeLabel8 = Content.getComponent("ShapeLabel8");


  Content.setPropertiesFromJSON("Shape8", {

	"popupMenuItems": "AMwaves" > 1 ? AMwaves.join("\n") : "",

	});

inline function onShape8Control(component, value)
{
	ShapeLabel8.set("text",Shape8.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FilMod::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX::","").replace("sys::",""));

    Sampler8.loadSampleMap(sampleMaps[value-1]);
    Sampler17.loadSampleMap(sampleMaps[value-1]);
                   Sampler26.loadSampleMap(sampleMaps[value-1]);
                   Sampler35.loadSampleMap(sampleMaps[value-1]);
                   Sampler44.loadSampleMap(sampleMaps[value-1]);
                   Sampler53.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape8").setControlCallback(onShape8Control);

Shape8.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});

const var Shape9 = Content.getComponent("Shape9");
const var ShapeLabel9 = Content.getComponent("ShapeLabel9");

Content.setPropertiesFromJSON("Shape9", {

	"popupMenuItems": "AMwaves" > 1 ? AMwaves.join("\n") : "",

	});

inline function onShape9Control(component, value)
{
	ShapeLabel9.set("text",Shape9.get("popupMenuItems").split("\n")[value-1].replace("FM::","").replace("AM::","").replace("filter::","").replace("FilMod::","").replace("shape::","").replace("noise::","").replace("PM::","").replace("Misc::","").replace("JX::","").replace("sys::",""));

    Sampler9.loadSampleMap(sampleMaps[value-1]);
    Sampler18.loadSampleMap(sampleMaps[value-1]);
    Sampler27.loadSampleMap(sampleMaps[value-1]);
    Sampler36.loadSampleMap(sampleMaps[value-1]);
   Sampler45.loadSampleMap(sampleMaps[value-1]);
   Sampler54.loadSampleMap(sampleMaps[value-1]);
}
Content.getComponent("Shape9").setControlCallback(onShape9Control);

Shape9.setMouseCallback(function(event)
{
	this.setValue(event.result);
	this.changed();
    
});



//controls

const var Group1 = Synth.getChildSynth("Group1");
const var Group2 = Synth.getChildSynth("Group2");
const var Group3 = Synth.getChildSynth("Group3");
const var Group4 = Synth.getChildSynth("Group4");
const var Group5 = Synth.getChildSynth("Group5");
const var Group6 = Synth.getChildSynth("Group6");
const var Group7 = Synth.getChildSynth("Group7");
const var Group8 = Synth.getChildSynth("Group8");



Content.getComponent("PitB").setControlCallback(onPitBControl);


const var vecxfade = Synth.getModulator("vecxfade");
const var vecxfade2 = Synth.getModulator("vecxfade2");
const var vecxfade3 = Synth.getModulator("vecxfade3");
const var vecxfade4 = Synth.getModulator("vecxfade4");
const var vecxfade5 = Synth.getModulator("vecxfade5");
const var vecxfade6 = Synth.getModulator("vecxfade6");
const var Smooth = Content.getComponent("Smooth");
const var posmod = Content.getComponent("posmod");
const var xfadetype = Content.getComponent("xfadetype");

const var XFADE = Content.getComponent("XFADE");


inline function onXFADEControl(component, value)
{
vecxfade.setAttribute(vecxfade.scan, value);
   vecxfade2.setAttribute(vecxfade2.scan, value);
   vecxfade3.setAttribute(vecxfade3.scan, value);
   vecxfade4.setAttribute(vecxfade4.scan, value);
   vecxfade5.setAttribute(vecxfade5.scan, value);
   vecxfade6.setAttribute(vecxfade6.scan, value);
};

Content.getComponent("XFADE").setControlCallback(onXFADEControl);



inline function onSmoothControl(component, value)
{
 vecxfade.setAttribute(vecxfade.smooth, value);
 vecxfade2.setAttribute(vecxfade2.smooth, value);
   vecxfade3.setAttribute(vecxfade3.smooth, value);
   vecxfade4.setAttribute(vecxfade4.smooth, value);
   vecxfade5.setAttribute(vecxfade5.smooth, value);
   vecxfade6.setAttribute(vecxfade6.smooth, value);

};

Content.getComponent("Smooth").setControlCallback(onSmoothControl);


inline function onposmodControl(component, value)
{
	vecxfade.setAttribute(vecxfade.modamount, value);
   vecxfade2.setAttribute(vecxfade2.modamount, value);
   vecxfade3.setAttribute(vecxfade3.modamount, value);
   vecxfade4.setAttribute(vecxfade4.modamount, value);
   vecxfade5.setAttribute(vecxfade5.modamount, value);
   vecxfade6.setAttribute(vecxfade6.modamount, value);
};

Content.getComponent("posmod").setControlCallback(onposmodControl);


inline function onxfadetypeControl(component, value)
{
		vecxfade.setAttribute(vecxfade.modamount, value);
 vecxfade2.setAttribute(vecxfade2.modamount, value);
   vecxfade3.setAttribute(vecxfade3.modamount, value);
   vecxfade4.setAttribute(vecxfade4.modamount, value);
   vecxfade5.setAttribute(vecxfade5.modamount, value);
   vecxfade6.setAttribute(vecxfade6.modamount, value);
};

Content.getComponent("xfadetype").setControlCallback(onxfadetypeControl);

const var PitchB1 = Synth.getModulator("PitchB1");

const var fmin1 = Synth.getChildSynth("fmin1");
const var fmin2 = Synth.getChildSynth("fmin2");
const var fmin3 = Synth.getChildSynth("fmin3");
const var fmin4 = Synth.getChildSynth("fmin4");
const var fmin5 = Synth.getChildSynth("fmin5");
const var fmin6 = Synth.getChildSynth("fmin6");
const var fmin7 = Synth.getChildSynth("fmin7");
const var fmin8 = Synth.getChildSynth("fmin8");
const var fmin9 = Synth.getChildSynth("fmin9");
const var fmin10 = Synth.getChildSynth("fmin10");
const var fmin11 = Synth.getChildSynth("fmin11");
const var fmin12 = Synth.getChildSynth("fmin12");
const var fmin13 = Synth.getChildSynth("fmin13");
const var fmin14 = Synth.getChildSynth("fmin14");
const var fmin15 = Synth.getChildSynth("fmin15");
const var fmin16 = Synth.getChildSynth("fmin16");
const var fmin17 = Synth.getChildSynth("fmin17");
const var fmin18 = Synth.getChildSynth("fmin18");
const var fmin19 = Synth.getChildSynth("fmin19");
const var fmin20 = Synth.getChildSynth("fmin20");
const var fmin21 = Synth.getChildSynth("fmin21");
const var fmin22 = Synth.getChildSynth("fmin22");
const var fmin23 = Synth.getChildSynth("fmin23");
const var fmin24 = Synth.getChildSynth("fmin24");
const var fmin25 = Synth.getChildSynth("fmin25");
const var fmin26 = Synth.getChildSynth("fmin26");
const var fmin27 = Synth.getChildSynth("fmin27");
const var fmin28 = Synth.getChildSynth("fmin28");
const var fmin29 = Synth.getChildSynth("fmin29");
const var fmin30 = Synth.getChildSynth("fmin30");
const var fmin31 = Synth.getChildSynth("fmin31");
const var fmin32 = Synth.getChildSynth("fmin32");
const var fmin33 = Synth.getChildSynth("fmin33");
const var fmin34 = Synth.getChildSynth("fmin34");
const var fmin35 = Synth.getChildSynth("fmin35");
const var fmin36 = Synth.getChildSynth("fmin36");
const var fmin37 = Synth.getChildSynth("fmin37");
const var fmin38 = Synth.getChildSynth("fmin38");
const var fmin39 = Synth.getChildSynth("fmin39");
const var fmin40 = Synth.getChildSynth("fmin40");
const var fmin41 = Synth.getChildSynth("fmin41");
const var fmin42 = Synth.getChildSynth("fmin42");
const var fmin43 = Synth.getChildSynth("fmin43");
const var fmin44 = Synth.getChildSynth("fmin44");
const var fmin45 = Synth.getChildSynth("fmin45");
const var fmin46 = Synth.getChildSynth("fmin46");
const var fmin47 = Synth.getChildSynth("fmin47");
const var fmin48 = Synth.getChildSynth("fmin48");


const var FMLevel = Content.getComponent("FMLevel");

inline function onFMLevelControl(component, value)
{
 	fmin1.setAttribute(0, value);
	fmin2.setAttribute(0, value);
	fmin3.setAttribute(0, value);
	fmin4.setAttribute(0, value);
	fmin5.setAttribute(0, value);
	fmin6.setAttribute(0, value);
	fmin7.setAttribute(0, value);
	fmin8.setAttribute(0, value);
	fmin9.setAttribute(0, value);
	fmin10.setAttribute(0, value);
	fmin11.setAttribute(0, value);
	fmin12.setAttribute(0, value);
	fmin13.setAttribute(0, value);
	fmin14.setAttribute(0, value);
	fmin15.setAttribute(0, value);
	fmin16.setAttribute(0, value);
	fmin17.setAttribute(0, value);
	fmin18.setAttribute(0, value);
	fmin19.setAttribute(0, value);
	fmin20.setAttribute(0, value);
	fmin21.setAttribute(0, value);
	fmin22.setAttribute(0, value);
	fmin23.setAttribute(0, value);
	fmin24.setAttribute(0, value);
	fmin25.setAttribute(0, value);
	fmin26.setAttribute(0, value);
	fmin27.setAttribute(0, value);
	fmin28.setAttribute(0, value);
	fmin29.setAttribute(0, value);
	fmin30.setAttribute(0, value);
	fmin31.setAttribute(0, value);
	fmin32.setAttribute(0, value);
	fmin33.setAttribute(0, value);
	fmin34.setAttribute(0, value);
	fmin35.setAttribute(0, value);
	fmin36.setAttribute(0, value);
	fmin37.setAttribute(0, value);
	fmin38.setAttribute(0, value);
	fmin39.setAttribute(0, value);
	fmin40.setAttribute(0, value);
	fmin41.setAttribute(0, value);
	fmin42.setAttribute(0, value);
	fmin43.setAttribute(0, value);
	fmin44.setAttribute(0, value);
	fmin45.setAttribute(0, value);
	fmin46.setAttribute(0, value);
	fmin47.setAttribute(0, value);
	fmin48.setAttribute(0, value);
	
	
};

Content.getComponent("FMLevel").setControlCallback(onFMLevelControl);

const var Feedback = Content.getComponent("Feedback");

inline function onFeedbackControl(component, value)
{
  fmin1.setAttribute(fmin1.feedback, value);
fmin2.setAttribute(fmin2.feedback, value);
fmin3.setAttribute(fmin3.feedback, value);
fmin4.setAttribute(fmin4.feedback, value);
fmin5.setAttribute(fmin5.feedback, value);
fmin6.setAttribute(fmin6.feedback, value);
fmin7.setAttribute(fmin7.feedback, value);
fmin8.setAttribute(fmin8.feedback, value);
fmin9.setAttribute(fmin9.feedback, value);
fmin10.setAttribute(fmin10.feedback, value);
fmin11.setAttribute(fmin11.feedback, value);
fmin12.setAttribute(fmin12.feedback, value);
fmin13.setAttribute(fmin13.feedback, value);
fmin14.setAttribute(fmin14.feedback, value);
fmin15.setAttribute(fmin15.feedback, value);
fmin16.setAttribute(fmin16.feedback, value);
fmin17.setAttribute(fmin17.feedback, value);
fmin18.setAttribute(fmin18.feedback, value);
fmin19.setAttribute(fmin19.feedback, value);
fmin20.setAttribute(fmin20.feedback, value);
fmin21.setAttribute(fmin21.feedback, value);
fmin22.setAttribute(fmin22.feedback, value);
fmin23.setAttribute(fmin23.feedback, value);
fmin24.setAttribute(fmin24.feedback, value);
fmin25.setAttribute(fmin25.feedback, value);
fmin26.setAttribute(fmin26.feedback, value);
fmin27.setAttribute(fmin27.feedback, value);
fmin28.setAttribute(fmin28.feedback, value);
fmin19.setAttribute(fmin29.feedback, value);
fmin30.setAttribute(fmin30.feedback, value);
fmin31.setAttribute(fmin31.feedback, value);
fmin32.setAttribute(fmin32.feedback, value);
fmin33.setAttribute(fmin33.feedback, value);
fmin34.setAttribute(fmin34.feedback, value);
fmin35.setAttribute(fmin35.feedback, value);
fmin36.setAttribute(fmin36.feedback, value);
fmin37.setAttribute(fmin37.feedback, value);
fmin38.setAttribute(fmin38.feedback, value);
fmin39.setAttribute(fmin39.feedback, value);
fmin40.setAttribute(fmin40.feedback, value);
fmin41.setAttribute(fmin41.feedback, value);
fmin42.setAttribute(fmin42.feedback, value);
fmin43.setAttribute(fmin43.feedback, value);
fmin44.setAttribute(fmin44.feedback, value);
fmin45.setAttribute(fmin45.feedback, value);
fmin46.setAttribute(fmin46.feedback, value);
fmin47.setAttribute(fmin47.feedback, value);
fmin48.setAttribute(fmin48.feedback, value);
    
     
     
};

Content.getComponent("Feedback").setControlCallback(onFeedbackControl);

const var FMmod1 = Content.getComponent("FMmod1");
{
	
}

inline function onFMmod1Control(component, value)
{
fmin1.setAttribute(fmin1.fmod, value);
fmin2.setAttribute(fmin2.fmod, value);
fmin3.setAttribute(fmin3.fmod, value);
fmin4.setAttribute(fmin4.fmod, value);
fmin5.setAttribute(fmin5.fmod, value);
fmin6.setAttribute(fmin6.fmod, value);
fmin7.setAttribute(fmin7.fmod, value);
fmin8.setAttribute(fmin8.fmod, value);
fmin9.setAttribute(fmin9.fmod, value);
fmin10.setAttribute(fmin10.fmod, value);
fmin11.setAttribute(fmin11.fmod, value);
fmin12.setAttribute(fmin12.fmod, value);
fmin13.setAttribute(fmin13.fmod, value);
fmin14.setAttribute(fmin14.fmod, value);
fmin15.setAttribute(fmin15.fmod, value);
fmin16.setAttribute(fmin16.fmod, value);
fmin17.setAttribute(fmin17.fmod, value);
fmin18.setAttribute(fmin18.fmod, value);
fmin19.setAttribute(fmin19.fmod, value);
fmin20.setAttribute(fmin20.fmod, value);
fmin21.setAttribute(fmin21.fmod, value);
fmin22.setAttribute(fmin22.fmod, value);
fmin23.setAttribute(fmin23.fmod, value);
fmin24.setAttribute(fmin24.fmod, value);
fmin25.setAttribute(fmin25.fmod, value);
fmin26.setAttribute(fmin26.fmod, value);
fmin27.setAttribute(fmin27.fmod, value);
fmin28.setAttribute(fmin28.fmod, value);
fmin19.setAttribute(fmin29.fmod, value);
fmin30.setAttribute(fmin30.fmod, value);
fmin31.setAttribute(fmin31.fmod, value);
fmin32.setAttribute(fmin32.fmod, value);
fmin33.setAttribute(fmin33.fmod, value);
fmin34.setAttribute(fmin34.fmod, value);
fmin35.setAttribute(fmin35.fmod, value);
fmin36.setAttribute(fmin36.fmod, value);
fmin37.setAttribute(fmin37.fmod, value);
fmin38.setAttribute(fmin38.fmod, value);
fmin39.setAttribute(fmin39.fmod, value);
fmin40.setAttribute(fmin40.fmod, value);
fmin41.setAttribute(fmin41.fmod, value);
fmin42.setAttribute(fmin42.fmod, value);
fmin43.setAttribute(fmin43.fmod, value);
fmin44.setAttribute(fmin44.fmod, value);
fmin45.setAttribute(fmin45.fmod, value);
fmin46.setAttribute(fmin46.fmod, value);
fmin47.setAttribute(fmin47.fmod, value);
fmin48.setAttribute(fmin48.fmod, value);
    
     
     

};

Content.getComponent("FMmod1").setControlCallback(onFMmod1Control);



const var FMmodSel1 = Content.getComponent("FMmodSel1");

inline function onFMmodSel1Control(component, value)
{
fmin1.setAttribute(fmin1.fmdest, value);
fmin2.setAttribute(fmin2.fmdest, value);
fmin3.setAttribute(fmin3.fmdest, value);
fmin4.setAttribute(fmin4.fmdest, value);
fmin5.setAttribute(fmin5.fmdest, value);
fmin6.setAttribute(fmin6.fmdest, value);
fmin7.setAttribute(fmin7.fmdest, value);
fmin8.setAttribute(fmin8.fmdest, value);
fmin9.setAttribute(fmin9.fmdest, value);
fmin10.setAttribute(fmin10.fmdest, value);
fmin11.setAttribute(fmin11.fmdest, value);
fmin12.setAttribute(fmin12.fmdest, value);
fmin13.setAttribute(fmin13.fmdest, value);
fmin14.setAttribute(fmin14.fmdest, value);
fmin15.setAttribute(fmin15.fmdest, value);
fmin16.setAttribute(fmin16.fmdest, value);
fmin17.setAttribute(fmin17.fmdest, value);
fmin18.setAttribute(fmin18.fmdest, value);
fmin19.setAttribute(fmin19.fmdest, value);
fmin20.setAttribute(fmin20.fmdest, value);
fmin21.setAttribute(fmin21.fmdest, value);
fmin22.setAttribute(fmin22.fmdest, value);
fmin23.setAttribute(fmin23.fmdest, value);
fmin24.setAttribute(fmin24.fmdest, value);
fmin25.setAttribute(fmin25.fmdest, value);
fmin26.setAttribute(fmin26.fmdest, value);
fmin27.setAttribute(fmin27.fmdest, value);
fmin28.setAttribute(fmin28.fmdest, value);
fmin19.setAttribute(fmin29.fmdest, value);
fmin30.setAttribute(fmin30.fmdest, value);
fmin31.setAttribute(fmin31.fmdest, value);
fmin32.setAttribute(fmin32.fmdest, value);
fmin33.setAttribute(fmin33.fmdest, value);
fmin34.setAttribute(fmin34.fmdest, value);
fmin35.setAttribute(fmin35.fmdest, value);
fmin36.setAttribute(fmin36.fmdest, value);
fmin37.setAttribute(fmin37.fmdest, value);
fmin38.setAttribute(fmin38.fmdest, value);
fmin39.setAttribute(fmin39.fmdest, value);
fmin40.setAttribute(fmin40.fmdest, value);
fmin41.setAttribute(fmin41.fmdest, value);
fmin42.setAttribute(fmin42.fmdest, value);
fmin43.setAttribute(fmin43.fmdest, value);
fmin44.setAttribute(fmin44.fmdest, value);
fmin45.setAttribute(fmin45.fmdest, value);
fmin46.setAttribute(fmin46.fmdest, value);
fmin47.setAttribute(fmin47.fmdest, value);
fmin48.setAttribute(fmin48.fmdest, value);
    
     
     

};

Content.getComponent("FMmodSel1").setControlCallback(onFMmodSel1Control);


const var FeedMod1 = Content.getComponent("FeedMod1");

inline function onFeedMod1Control(component, value)
{
fmin1.setAttribute(fmin1.feedmod, value);
fmin2.setAttribute(fmin2.feedmod, value);
fmin3.setAttribute(fmin3.feedmod, value);
fmin4.setAttribute(fmin4.feedmod, value);
fmin5.setAttribute(fmin5.feedmod, value);
fmin6.setAttribute(fmin6.feedmod, value);
fmin7.setAttribute(fmin7.feedmod, value);
fmin8.setAttribute(fmin8.feedmod, value);
fmin9.setAttribute(fmin9.feedmod, value);
fmin10.setAttribute(fmin10.feedmod, value);
fmin11.setAttribute(fmin11.feedmod, value);
fmin12.setAttribute(fmin12.feedmod, value);
fmin13.setAttribute(fmin13.feedmod, value);
fmin14.setAttribute(fmin14.feedmod, value);
fmin15.setAttribute(fmin15.feedmod, value);
fmin16.setAttribute(fmin16.feedmod, value);
fmin17.setAttribute(fmin17.feedmod, value);
fmin18.setAttribute(fmin18.feedmod, value);
fmin19.setAttribute(fmin19.feedmod, value);
fmin20.setAttribute(fmin20.feedmod, value);
fmin21.setAttribute(fmin21.feedmod, value);
fmin22.setAttribute(fmin22.feedmod, value);
fmin23.setAttribute(fmin23.feedmod, value);
fmin24.setAttribute(fmin24.feedmod, value);
fmin25.setAttribute(fmin25.feedmod, value);
fmin26.setAttribute(fmin26.feedmod, value);
fmin27.setAttribute(fmin27.feedmod, value);
fmin28.setAttribute(fmin28.feedmod, value);
fmin19.setAttribute(fmin29.feedmod, value);
fmin30.setAttribute(fmin30.feedmod, value);
fmin31.setAttribute(fmin31.feedmod, value);
fmin32.setAttribute(fmin32.feedmod, value);
fmin33.setAttribute(fmin33.feedmod, value);
fmin34.setAttribute(fmin34.feedmod, value);
fmin35.setAttribute(fmin35.feedmod, value);
fmin36.setAttribute(fmin36.feedmod, value);
fmin37.setAttribute(fmin37.feedmod, value);
fmin38.setAttribute(fmin38.feedmod, value);
fmin39.setAttribute(fmin39.feedmod, value);
fmin40.setAttribute(fmin40.feedmod, value);
fmin41.setAttribute(fmin41.feedmod, value);
fmin42.setAttribute(fmin42.feedmod, value);
fmin43.setAttribute(fmin43.feedmod, value);
fmin44.setAttribute(fmin44.feedmod, value);
fmin45.setAttribute(fmin45.feedmod, value);
fmin46.setAttribute(fmin46.feedmod, value);
fmin47.setAttribute(fmin47.feedmod, value);
fmin48.setAttribute(fmin48.feedmod, value);

};

Content.getComponent("FeedMod1").setControlCallback(onFeedMod1Control);

const var FeedModSel1 = Content.getComponent("FeedModSel1");


inline function onFeedModSel1Control(component, value)
{
fmin1.setAttribute(fmin1.feeddest, value);
fmin2.setAttribute(fmin2.feeddest, value);
fmin3.setAttribute(fmin3.feeddest, value);
fmin4.setAttribute(fmin4.feeddest, value);
fmin5.setAttribute(fmin5.feeddest, value);
fmin6.setAttribute(fmin6.feeddest, value);
fmin7.setAttribute(fmin7.feeddest, value);
fmin8.setAttribute(fmin8.feeddest, value);
fmin9.setAttribute(fmin9.feeddest, value);
fmin10.setAttribute(fmin10.feeddest, value);
fmin11.setAttribute(fmin11.feeddest, value);
fmin12.setAttribute(fmin12.feeddest, value);
fmin13.setAttribute(fmin13.feeddest, value);
fmin14.setAttribute(fmin14.feeddest, value);
fmin15.setAttribute(fmin15.feeddest, value);
fmin16.setAttribute(fmin16.feeddest, value);
fmin17.setAttribute(fmin17.feeddest, value);
fmin18.setAttribute(fmin18.feeddest, value);
fmin19.setAttribute(fmin19.feeddest, value);
fmin20.setAttribute(fmin20.feeddest, value);
fmin21.setAttribute(fmin21.feeddest, value);
fmin22.setAttribute(fmin22.feeddest, value);
fmin23.setAttribute(fmin23.feeddest, value);
fmin24.setAttribute(fmin24.feeddest, value);
fmin25.setAttribute(fmin25.feeddest, value);
fmin26.setAttribute(fmin26.feeddest, value);
fmin27.setAttribute(fmin27.feeddest, value);
fmin28.setAttribute(fmin28.feeddest, value);
fmin19.setAttribute(fmin29.feeddest, value);
fmin30.setAttribute(fmin30.feeddest, value);
fmin31.setAttribute(fmin31.feeddest, value);
fmin32.setAttribute(fmin32.feeddest, value);
fmin33.setAttribute(fmin33.feeddest, value);
fmin34.setAttribute(fmin34.feeddest, value);
fmin35.setAttribute(fmin35.feeddest, value);
fmin36.setAttribute(fmin36.feeddest, value);
fmin37.setAttribute(fmin37.feeddest, value);
fmin38.setAttribute(fmin38.feeddest, value);
fmin39.setAttribute(fmin39.feeddest, value);
fmin40.setAttribute(fmin40.feeddest, value);
fmin41.setAttribute(fmin41.feeddest, value);
fmin42.setAttribute(fmin42.feeddest, value);
fmin43.setAttribute(fmin43.feeddest, value);
fmin44.setAttribute(fmin44.feeddest, value);
fmin45.setAttribute(fmin45.feeddest, value);
fmin46.setAttribute(fmin46.feeddest, value);
fmin47.setAttribute(fmin47.feeddest, value);
fmin48.setAttribute(fmin48.feeddest, value);

};

Content.getComponent("FeedModSel1").setControlCallback(onFeedModSel1Control);


const var Envelope1 = Synth.getModulator("Envelope1");
const var Envelope2 = Synth.getModulator("Envelope2");
const var Envelope3 = Synth.getModulator("Envelope3");
const var Envelope4 = Synth.getModulator("Envelope4");
const var Envelope5 = Synth.getModulator("Envelope5");
const var Envelope6 = Synth.getModulator("Envelope6");
const var Envelope7 = Synth.getModulator("Envelope7");
const var Envelope8 = Synth.getModulator("Envelope8");

const var Envelope10 = Synth.getModulator("Envelope10");
const var Envelope11 = Synth.getModulator("Envelope11");
const var Envelope12 = Synth.getModulator("Envelope12");
const var Envelope13 = Synth.getModulator("Envelope13");
const var Envelope14 = Synth.getModulator("Envelope14");
const var Envelope15 = Synth.getModulator("Envelope15");
const var Envelope16 = Synth.getModulator("Envelope16");
const var Envelope17 = Synth.getModulator("Envelope17");
const var Envelope18 = Synth.getModulator("Envelope18");
const var Envelope19 = Synth.getModulator("Envelope19");
const var Envelope20 = Synth.getModulator("Envelope20");
const var Envelope21 = Synth.getModulator("Envelope21");
const var Envelope22 = Synth.getModulator("Envelope22");
const var Envelope23 = Synth.getModulator("Envelope23");
const var Envelope24 = Synth.getModulator("Envelope24");
const var Envelope25 = Synth.getModulator("Envelope25");
const var Envelope26 = Synth.getModulator("Envelope26");
const var Envelope27 = Synth.getModulator("Envelope27");
const var Envelope28 = Synth.getModulator("Envelope28");
const var Envelope29 = Synth.getModulator("Envelope29");
const var Envelope30 = Synth.getModulator("Envelope30");
const var Envelope31 = Synth.getModulator("Envelope31");
const var Envelope32 = Synth.getModulator("Envelope32");
const var Envelope33 = Synth.getModulator("Envelope33");
const var Envelope34 = Synth.getModulator("Envelope34");
const var Envelope35 = Synth.getModulator("Envelope35");
const var Envelope36 = Synth.getModulator("Envelope36");
const var Envelope37 = Synth.getModulator("Envelope37");
const var Envelope38 = Synth.getModulator("Envelope38");
const var Envelope39 = Synth.getModulator("Envelope39");
const var Envelope40 = Synth.getModulator("Envelope40");
const var Envelope41 = Synth.getModulator("Envelope41");
const var Envelope42 = Synth.getModulator("Envelope42");
const var Envelope43 = Synth.getModulator("Envelope43");
const var Envelope44 = Synth.getModulator("Envelope44");
const var Envelope45 = Synth.getModulator("Envelope45");
const var Envelope46 = Synth.getModulator("Envelope46");
const var Envelope47 = Synth.getModulator("Envelope47");
const var Envelope48 = Synth.getModulator("Envelope48");
const var Envelope49 = Synth.getModulator("Envelope49");
const var Envelope50 = Synth.getModulator("Envelope50");
const var Envelope51 = Synth.getModulator("Envelope51");
const var Envelope52 = Synth.getModulator("Envelope52");
const var Envelope53 = Synth.getModulator("Envelope53");
const var Envelope54 = Synth.getModulator("Envelope54");

const var Envelope9 = Synth.getModulator("Envelope9");


const var VecAttack = Content.getComponent("VecAttack");


inline function onVecAttackControl(component, value)
{
	Envelope1.setAttribute(2, value);
	Envelope2.setAttribute(2, value);
	Envelope3.setAttribute(2, value);
	Envelope4.setAttribute(2, value);
	Envelope5.setAttribute(2, value);
	Envelope6.setAttribute(2, value);
	Envelope7.setAttribute(2, value);
	Envelope8.setAttribute(2, value);
	Envelope10.setAttribute(2, value);
	Envelope11.setAttribute(2, value);
	Envelope12.setAttribute(2, value);
	Envelope13.setAttribute(2, value);
	Envelope14.setAttribute(2, value);
	Envelope15.setAttribute(2, value);
	Envelope16.setAttribute(2, value);
	Envelope17.setAttribute(2, value);
	Envelope19.setAttribute(2, value);
	Envelope20.setAttribute(2, value);
	Envelope21.setAttribute(2, value);
	Envelope22.setAttribute(2, value);
	Envelope23.setAttribute(2, value);
	Envelope24.setAttribute(2, value);
	Envelope25.setAttribute(2, value);
	Envelope26.setAttribute(2, value);
	Envelope28.setAttribute(2, value);
	Envelope29.setAttribute(2, value);
	Envelope30.setAttribute(2, value);
	Envelope31.setAttribute(2, value);
	Envelope32.setAttribute(2, value);
	Envelope33.setAttribute(2, value);
	Envelope34.setAttribute(2, value);
	Envelope35.setAttribute(2, value);
	Envelope37.setAttribute(2, value);
	Envelope38.setAttribute(2, value);
	Envelope39.setAttribute(2, value);
	Envelope40.setAttribute(2, value);
	Envelope41.setAttribute(2, value);
	Envelope42.setAttribute(2, value);
	Envelope43.setAttribute(2, value);
	Envelope44.setAttribute(2, value);
	Envelope46.setAttribute(2, value);
	Envelope47.setAttribute(2, value);
	Envelope48.setAttribute(2, value);
	Envelope49.setAttribute(2, value);
	Envelope50.setAttribute(2, value);
	Envelope51.setAttribute(2, value);
	Envelope52.setAttribute(2, value);
	Envelope53.setAttribute(2, value);
	
	
	
};

Content.getComponent("VecAttack").setControlCallback(onVecAttackControl);

const var VecDecay = Content.getComponent("VecDecay");


inline function onVecDecayControl(component, value)
{
			Envelope1.setAttribute(5, value);
	Envelope2.setAttribute(5, value);
	Envelope3.setAttribute(5, value);
	Envelope4.setAttribute(5, value);
	Envelope5.setAttribute(5, value);
	Envelope6.setAttribute(5, value);
	Envelope7.setAttribute(5, value);
	Envelope8.setAttribute(5, value);
	Envelope10.setAttribute(5, value);
	Envelope11.setAttribute(5, value);
	Envelope12.setAttribute(5, value);
	Envelope13.setAttribute(5, value);
	Envelope14.setAttribute(5, value);
	Envelope15.setAttribute(5, value);
	Envelope16.setAttribute(5, value);
	Envelope17.setAttribute(5, value);
	Envelope19.setAttribute(5, value);
	Envelope20.setAttribute(5, value);
	Envelope21.setAttribute(5, value);
	Envelope22.setAttribute(5, value);
	Envelope23.setAttribute(5, value);
	Envelope24.setAttribute(5, value);
	Envelope25.setAttribute(5, value);
	Envelope26.setAttribute(5, value);
	Envelope28.setAttribute(5, value);
	Envelope29.setAttribute(5, value);
	Envelope30.setAttribute(5, value);
	Envelope31.setAttribute(5, value);
	Envelope32.setAttribute(5, value);
	Envelope33.setAttribute(5, value);
	Envelope34.setAttribute(5, value);
	Envelope35.setAttribute(5, value);
	Envelope37.setAttribute(5, value);
	Envelope38.setAttribute(5, value);
	Envelope39.setAttribute(5, value);
	Envelope40.setAttribute(5, value);
	Envelope41.setAttribute(5, value);
	Envelope42.setAttribute(5, value);
	Envelope43.setAttribute(5, value);
	Envelope44.setAttribute(5, value);
	Envelope46.setAttribute(5, value);
	Envelope47.setAttribute(5, value);
	Envelope48.setAttribute(5, value);
	Envelope49.setAttribute(5, value);
	Envelope50.setAttribute(5, value);
	Envelope51.setAttribute(5, value);
	Envelope52.setAttribute(5, value);
	Envelope53.setAttribute(5, value);
	
	
};

Content.getComponent("VecDecay").setControlCallback(onVecDecayControl);

const var VecSustan = Content.getComponent("VecSustan");



inline function onVecSustanControl(component, value)
{
	Envelope1.setAttribute(6, value);
	Envelope2.setAttribute(6, value);
	Envelope3.setAttribute(6, value);
	Envelope4.setAttribute(6, value);
	Envelope5.setAttribute(6, value);
	Envelope6.setAttribute(6, value);
	Envelope7.setAttribute(6, value);
	Envelope8.setAttribute(6, value);
	Envelope10.setAttribute(6, value);
	Envelope11.setAttribute(6, value);
	Envelope12.setAttribute(6, value);
	Envelope13.setAttribute(6, value);
	Envelope14.setAttribute(6, value);
	Envelope15.setAttribute(6, value);
	Envelope16.setAttribute(6, value);
	Envelope17.setAttribute(6, value);
	Envelope19.setAttribute(6, value);
	Envelope20.setAttribute(6, value);
	Envelope21.setAttribute(6, value);
	Envelope22.setAttribute(6, value);
	Envelope23.setAttribute(6, value);
	Envelope24.setAttribute(6, value);
	Envelope25.setAttribute(6, value);
	Envelope26.setAttribute(6, value);
	Envelope28.setAttribute(6, value);
	Envelope29.setAttribute(6, value);
	Envelope30.setAttribute(6, value);
	Envelope31.setAttribute(6, value);
	Envelope32.setAttribute(6, value);
	Envelope33.setAttribute(6, value);
	Envelope34.setAttribute(6, value);
	Envelope35.setAttribute(6, value);
	Envelope37.setAttribute(6, value);
	Envelope38.setAttribute(6, value);
	Envelope39.setAttribute(6, value);
	Envelope40.setAttribute(6, value);
	Envelope41.setAttribute(6, value);
	Envelope42.setAttribute(6, value);
	Envelope43.setAttribute(6, value);
	Envelope44.setAttribute(6, value);
	Envelope46.setAttribute(6, value);
	Envelope47.setAttribute(6, value);
	Envelope48.setAttribute(6, value);
	Envelope49.setAttribute(6, value);
	Envelope50.setAttribute(6, value);
	Envelope51.setAttribute(6, value);
	Envelope52.setAttribute(6, value);
	Envelope53.setAttribute(6, value);
	
};

Content.getComponent("VecSustan").setControlCallback(onVecSustanControl);

const var VecRelease = Content.getComponent("VecRelease");


inline function onVecReleaseControl(component, value)
{
	Envelope1.setAttribute(7, value);
	Envelope2.setAttribute(7, value);
	Envelope3.setAttribute(7, value);
	Envelope4.setAttribute(7, value);
	Envelope5.setAttribute(7, value);
	Envelope6.setAttribute(7, value);
	Envelope7.setAttribute(7, value);
	Envelope8.setAttribute(7, value);
	Envelope10.setAttribute(7, value);
	Envelope11.setAttribute(7, value);
	Envelope12.setAttribute(7, value);
	Envelope13.setAttribute(7, value);
	Envelope14.setAttribute(7, value);
	Envelope15.setAttribute(7, value);
	Envelope16.setAttribute(7, value);
	Envelope17.setAttribute(7, value);
	Envelope19.setAttribute(7, value);
	Envelope20.setAttribute(7, value);
	Envelope21.setAttribute(7, value);
	Envelope22.setAttribute(7, value);
	Envelope23.setAttribute(7, value);
	Envelope24.setAttribute(7, value);
	Envelope25.setAttribute(7, value);
	Envelope26.setAttribute(7, value);
	Envelope28.setAttribute(7, value);
	Envelope29.setAttribute(7, value);
	Envelope30.setAttribute(7, value);
	Envelope31.setAttribute(7, value);
	Envelope32.setAttribute(7, value);
	Envelope33.setAttribute(7, value);
	Envelope34.setAttribute(7, value);
	Envelope35.setAttribute(7, value);
	Envelope37.setAttribute(7, value);
	Envelope38.setAttribute(7, value);
	Envelope39.setAttribute(7, value);
	Envelope40.setAttribute(7, value);
	Envelope41.setAttribute(7, value);
	Envelope42.setAttribute(7, value);
	Envelope43.setAttribute(7, value);
	Envelope44.setAttribute(7, value);
	Envelope46.setAttribute(7, value);
	Envelope47.setAttribute(7, value);
	Envelope48.setAttribute(7, value);
	Envelope49.setAttribute(7, value);
	Envelope50.setAttribute(7, value);
	Envelope51.setAttribute(7, value);
	Envelope52.setAttribute(7, value);
	Envelope53.setAttribute(7, value);
	
	
};

Content.getComponent("VecRelease").setControlCallback(onVecReleaseControl);

const var Ampvel = Content.getComponent("Ampvel");
const var Ampvel1 = Synth.getModulator("Ampvel1");
const var Ampvel2 = Synth.getModulator("Ampvel2");
const var Ampvel3 = Synth.getModulator("Ampvel3");
const var Ampvel4 = Synth.getModulator("Ampvel4");
const var Ampvel5 = Synth.getModulator("Ampvel5");
const var Ampvel6 = Synth.getModulator("Ampvel6");
const var Ampvel7 = Synth.getModulator("Ampvel7");
const var Ampvel8 = Synth.getModulator("Ampvel8");
const var Ampvel9 = Synth.getModulator("Ampvel9");

inline function onAmpvelControl(component, value)
{
	Ampvel1.setIntensity(value);
	Ampvel2.setIntensity(value);
	Ampvel3.setIntensity(value);
	Ampvel4.setIntensity(value);
	Ampvel5.setIntensity(value);
	Ampvel6.setIntensity(value);
	Ampvel7.setIntensity(value);
	Ampvel8.setIntensity(value);
	Ampvel9.setIntensity(value);
};

Content.getComponent("Ampvel").setControlCallback(onAmpvelControl);





const var FMenvelope1 = Synth.getModulator("FMenvelope1");
const var FMenvelope2 = Synth.getModulator("FMenvelope2");
const var FMenvelope3 = Synth.getModulator("FMenvelope3");
const var FMenvelope4 = Synth.getModulator("FMenvelope4");
const var FMenvelope5 = Synth.getModulator("FMenvelope5");
const var FMenvelope6 = Synth.getModulator("FMenvelope6");
const var FMenvelope7 = Synth.getModulator("FMenvelope7");
const var FMenvelope8 = Synth.getModulator("FMenvelope8");
const var FMenvelope9 = Synth.getModulator("FMenvelope9");
const var FMenvelope10 = Synth.getModulator("FMenvelope10");
const var FMenvelope11 = Synth.getModulator("FMenvelope11");
const var FMenvelope12 = Synth.getModulator("FMenvelope12");
const var FMenvelope13 = Synth.getModulator("FMenvelope13");
const var FMenvelope14 = Synth.getModulator("FMenvelope14");
const var FMenvelope15 = Synth.getModulator("FMenvelope15");
const var FMenvelope16 = Synth.getModulator("FMenvelope16");
const var FMenvelope17 = Synth.getModulator("FMenvelope17");
const var FMenvelope18 = Synth.getModulator("FMenvelope18");
const var FMenvelope19 = Synth.getModulator("FMenvelope19");
const var FMenvelope20 = Synth.getModulator("FMenvelope20");
const var FMenvelope21 = Synth.getModulator("FMenvelope21");
const var FMenvelope22 = Synth.getModulator("FMenvelope22");
const var FMenvelope23 = Synth.getModulator("FMenvelope23");
const var FMenvelope24 = Synth.getModulator("FMenvelope24");
const var FMenvelope25 = Synth.getModulator("FMenvelope25");
const var FMenvelope26 = Synth.getModulator("FMenvelope26");
const var FMenvelope27 = Synth.getModulator("FMenvelope27");
const var FMenvelope28 = Synth.getModulator("FMenvelope28");
const var FMenvelope29 = Synth.getModulator("FMenvelope29");
const var FMenvelope30 = Synth.getModulator("FMenvelope30");
const var FMenvelope31 = Synth.getModulator("FMenvelope31");
const var FMenvelope32 = Synth.getModulator("FMenvelope32");
const var FMenvelope33 = Synth.getModulator("FMenvelope33");
const var FMenvelope34 = Synth.getModulator("FMenvelope34");
const var FMenvelope35 = Synth.getModulator("FMenvelope35");
const var FMenvelope36 = Synth.getModulator("FMenvelope36");
const var FMenvelope37 = Synth.getModulator("FMenvelope37");
const var FMenvelope38 = Synth.getModulator("FMenvelope38");
const var FMenvelope39 = Synth.getModulator("FMenvelope39");
const var FMenvelope40 = Synth.getModulator("FMenvelope40");
const var FMenvelope41 = Synth.getModulator("FMenvelope41");
const var FMenvelope42 = Synth.getModulator("FMenvelope42");
const var FMenvelope43 = Synth.getModulator("FMenvelope43");
const var FMenvelope44 = Synth.getModulator("FMenvelope44");
const var FMenvelope45 = Synth.getModulator("FMenvelope45");
const var FMenvelope46 = Synth.getModulator("FMenvelope46");
const var FMenvelope47 = Synth.getModulator("FMenvelope47");
const var FMenvelope48 = Synth.getModulator("FMenvelope48");


const var FMAttack = Content.getComponent("FMAttack");




inline function onFMAttackControl(component, value)
{
		FMenvelope1.setAttribute(2, value);
	FMenvelope2.setAttribute(2, value);
	FMenvelope3.setAttribute(2, value);
	FMenvelope4.setAttribute(2, value);
	FMenvelope5.setAttribute(2, value);
	FMenvelope6.setAttribute(2, value);
	FMenvelope7.setAttribute(2, value);
	FMenvelope8.setAttribute(2, value);
	FMenvelope9.setAttribute(2, value);
	FMenvelope10.setAttribute(2, value);
	FMenvelope11.setAttribute(2, value);
	FMenvelope12.setAttribute(2, value);
	FMenvelope13.setAttribute(2, value);
	FMenvelope14.setAttribute(2, value);
	FMenvelope15.setAttribute(2, value);
	FMenvelope16.setAttribute(2, value);
	FMenvelope17.setAttribute(2, value);
	FMenvelope18.setAttribute(2, value);
	FMenvelope19.setAttribute(2, value);
	FMenvelope20.setAttribute(2, value);
	FMenvelope21.setAttribute(2, value);
	FMenvelope22.setAttribute(2, value);
	FMenvelope23.setAttribute(2, value);
	FMenvelope24.setAttribute(2, value);
	FMenvelope25.setAttribute(2, value);
	FMenvelope26.setAttribute(2, value);
	FMenvelope27.setAttribute(2, value);
	FMenvelope28.setAttribute(2, value);
	FMenvelope29.setAttribute(2, value);
	FMenvelope30.setAttribute(2, value);
	FMenvelope31.setAttribute(2, value);
	FMenvelope32.setAttribute(2, value);
	FMenvelope33.setAttribute(2, value);
	FMenvelope34.setAttribute(2, value);
	FMenvelope35.setAttribute(2, value);
	FMenvelope36.setAttribute(2, value);
	FMenvelope37.setAttribute(2, value);
	FMenvelope38.setAttribute(2, value);
	FMenvelope39.setAttribute(2, value);
	FMenvelope40.setAttribute(2, value);
	FMenvelope41.setAttribute(2, value);
	FMenvelope42.setAttribute(2, value);
	FMenvelope43.setAttribute(2, value);
	FMenvelope44.setAttribute(2, value);
	FMenvelope45.setAttribute(2, value);
	FMenvelope46.setAttribute(2, value);
	FMenvelope47.setAttribute(2, value);
	FMenvelope48.setAttribute(2, value);
	Envelope9.setAttribute(2, value);
	Envelope18.setAttribute(2, value);
	Envelope27.setAttribute(2, value);
	Envelope36.setAttribute(2, value);
	Envelope45.setAttribute(2, value);
	Envelope54.setAttribute(2, value);
	
};

Content.getComponent("FMAttack").setControlCallback(onFMAttackControl);

const var FMDecay = Content.getComponent("FMDecay");


inline function onFMDecayControl(component, value)
{
			FMenvelope1.setAttribute(5, value);
	FMenvelope2.setAttribute(5, value);
	FMenvelope3.setAttribute(5, value);
	FMenvelope4.setAttribute(5, value);
	FMenvelope5.setAttribute(5, value);
	FMenvelope6.setAttribute(5, value);
	FMenvelope7.setAttribute(5, value);
	FMenvelope8.setAttribute(5, value);
	FMenvelope9.setAttribute(5, value);
	FMenvelope10.setAttribute(5, value);
	FMenvelope11.setAttribute(5, value);
	FMenvelope12.setAttribute(5, value);
	FMenvelope13.setAttribute(5, value);
	FMenvelope14.setAttribute(5, value);
	FMenvelope15.setAttribute(5, value);
	FMenvelope16.setAttribute(5, value);
	FMenvelope17.setAttribute(5, value);
	FMenvelope18.setAttribute(5, value);
	FMenvelope19.setAttribute(5, value);
	FMenvelope20.setAttribute(5, value);
	FMenvelope21.setAttribute(5, value);
	FMenvelope22.setAttribute(5, value);
	FMenvelope23.setAttribute(5, value);
	FMenvelope24.setAttribute(5, value);
	FMenvelope25.setAttribute(5, value);
	FMenvelope26.setAttribute(5, value);
	FMenvelope27.setAttribute(5, value);
	FMenvelope28.setAttribute(5, value);
	FMenvelope29.setAttribute(5, value);
	FMenvelope30.setAttribute(5, value);
	FMenvelope31.setAttribute(5, value);
	FMenvelope32.setAttribute(5, value);
	FMenvelope33.setAttribute(5, value);
	FMenvelope34.setAttribute(5, value);
	FMenvelope35.setAttribute(5, value);
	FMenvelope36.setAttribute(5, value);
	FMenvelope37.setAttribute(5, value);
	FMenvelope38.setAttribute(5, value);
	FMenvelope39.setAttribute(5, value);
	FMenvelope40.setAttribute(5, value);
	FMenvelope41.setAttribute(5, value);
	FMenvelope42.setAttribute(5, value);
	FMenvelope43.setAttribute(5, value);
	FMenvelope44.setAttribute(5, value);
	FMenvelope45.setAttribute(5, value);
	FMenvelope46.setAttribute(5, value);
	FMenvelope47.setAttribute(5, value);
	FMenvelope48.setAttribute(5, value);
	Envelope9.setAttribute(5, value);
	Envelope18.setAttribute(5, value);
	Envelope27.setAttribute(5, value);
	Envelope36.setAttribute(5, value);
	Envelope45.setAttribute(5, value);
	Envelope54.setAttribute(5, value);
	
	
};

Content.getComponent("FMDecay").setControlCallback(onFMDecayControl);

const var FMSustain = Content.getComponent("FMSustain");


inline function onFMSustainControl(component, value)
{
	FMenvelope1.setAttribute(6, value);
	FMenvelope2.setAttribute(6, value);
	FMenvelope3.setAttribute(6, value);
	FMenvelope4.setAttribute(6, value);
	FMenvelope5.setAttribute(6, value);
	FMenvelope6.setAttribute(6, value);
	FMenvelope7.setAttribute(6, value);
	FMenvelope8.setAttribute(6, value);
	FMenvelope9.setAttribute(6, value);
	FMenvelope10.setAttribute(6, value);
	FMenvelope11.setAttribute(6, value);
	FMenvelope12.setAttribute(6, value);
	FMenvelope13.setAttribute(6, value);
	FMenvelope14.setAttribute(6, value);
	FMenvelope15.setAttribute(6, value);
	FMenvelope16.setAttribute(6, value);
	FMenvelope17.setAttribute(6, value);
	FMenvelope18.setAttribute(6, value);
	FMenvelope19.setAttribute(6, value);
	FMenvelope20.setAttribute(6, value);
	FMenvelope21.setAttribute(6, value);
	FMenvelope22.setAttribute(6, value);
	FMenvelope23.setAttribute(6, value);
	FMenvelope24.setAttribute(6, value);
	FMenvelope25.setAttribute(6, value);
	FMenvelope26.setAttribute(6, value);
	FMenvelope27.setAttribute(6, value);
	FMenvelope28.setAttribute(6, value);
	FMenvelope29.setAttribute(6, value);
	FMenvelope30.setAttribute(6, value);
	FMenvelope31.setAttribute(6, value);
	FMenvelope32.setAttribute(6, value);
	FMenvelope33.setAttribute(6, value);
	FMenvelope34.setAttribute(6, value);
	FMenvelope35.setAttribute(6, value);
	FMenvelope36.setAttribute(6, value);
	FMenvelope37.setAttribute(6, value);
	FMenvelope38.setAttribute(6, value);
	FMenvelope39.setAttribute(6, value);
	FMenvelope40.setAttribute(6, value);
	FMenvelope41.setAttribute(6, value);
	FMenvelope42.setAttribute(6, value);
	FMenvelope43.setAttribute(6, value);
	FMenvelope44.setAttribute(6, value);
	FMenvelope45.setAttribute(6, value);
	FMenvelope46.setAttribute(6, value);
	FMenvelope47.setAttribute(6, value);
	FMenvelope48.setAttribute(6, value);
	Envelope9.setAttribute(6, value);
	Envelope18.setAttribute(6, value);
	Envelope27.setAttribute(6, value);
	Envelope36.setAttribute(6, value);
	Envelope45.setAttribute(6, value);
	Envelope54.setAttribute(6, value);
	
};

Content.getComponent("FMSustain").setControlCallback(onFMSustainControl);

const var FMRelease = Content.getComponent("FMRelease");


inline function onFMReleaseControl(component, value)
{
		FMenvelope1.setAttribute(7, value);
	FMenvelope2.setAttribute(7, value);
	FMenvelope3.setAttribute(7, value);
	FMenvelope4.setAttribute(7, value);
	FMenvelope5.setAttribute(7, value);
	FMenvelope6.setAttribute(7, value);
	FMenvelope7.setAttribute(7, value);
	FMenvelope8.setAttribute(7, value);
	FMenvelope9.setAttribute(7, value);
	FMenvelope10.setAttribute(7, value);
	FMenvelope11.setAttribute(7, value);
	FMenvelope12.setAttribute(7, value);
	FMenvelope13.setAttribute(7, value);
	FMenvelope14.setAttribute(7, value);
	FMenvelope15.setAttribute(7, value);
	FMenvelope16.setAttribute(7, value);
	FMenvelope17.setAttribute(7, value);
	FMenvelope18.setAttribute(7, value);
	FMenvelope19.setAttribute(7, value);
	FMenvelope20.setAttribute(7, value);
	FMenvelope21.setAttribute(7, value);
	FMenvelope22.setAttribute(7, value);
	FMenvelope23.setAttribute(7, value);
	FMenvelope24.setAttribute(7, value);
	FMenvelope25.setAttribute(7, value);
	FMenvelope26.setAttribute(7, value);
	FMenvelope27.setAttribute(7, value);
	FMenvelope28.setAttribute(7, value);
	FMenvelope29.setAttribute(7, value);
	FMenvelope30.setAttribute(7, value);
	FMenvelope31.setAttribute(7, value);
	FMenvelope32.setAttribute(7, value);
	FMenvelope33.setAttribute(7, value);
	FMenvelope34.setAttribute(7, value);
	FMenvelope35.setAttribute(7, value);
	FMenvelope36.setAttribute(7, value);
	FMenvelope37.setAttribute(7, value);
	FMenvelope38.setAttribute(7, value);
	FMenvelope39.setAttribute(7, value);
	FMenvelope40.setAttribute(7, value);
	FMenvelope41.setAttribute(7, value);
	FMenvelope42.setAttribute(7, value);
	FMenvelope43.setAttribute(7, value);
	FMenvelope44.setAttribute(7, value);
	FMenvelope45.setAttribute(7, value);
	FMenvelope46.setAttribute(7, value);
	FMenvelope47.setAttribute(7, value);
	FMenvelope48.setAttribute(7, value);
	Envelope9.setAttribute(7, value);
	Envelope18.setAttribute(7, value);
	Envelope27.setAttribute(7, value);
	Envelope36.setAttribute(7, value);
	Envelope45.setAttribute(7, value);
	Envelope54.setAttribute(7, value);
	
};

Content.getComponent("FMRelease").setControlCallback(onFMReleaseControl);


const var Filter1 = Synth.getEffect("Filter1");
const var Filter2 = Synth.getEffect("Filter2");
const var Filter3 = Synth.getEffect("Filter3");
const var Filter4 = Synth.getEffect("Filter4");
const var Filter5 = Synth.getEffect("Filter5");
const var Filter6 = Synth.getEffect("Filter6");
const var Filter7 = Synth.getEffect("Filter7");
const var Filter8 = Synth.getEffect("Filter8");
const var Filter9 = Synth.getEffect("Filter9");

const var Ftype = Content.getComponent("Ftype");

inline function onFtypeControl(component, value)
{
	Filter1.setAttribute(3, value);
	Filter2.setAttribute(3, value);
	Filter3.setAttribute(3, value);
	Filter4.setAttribute(3, value);
	Filter5.setAttribute(3, value);
	Filter6.setAttribute(3, value);
	Filter7.setAttribute(3, value);
	Filter8.setAttribute(3, value);
	Filter9.setAttribute(3, value);

}

Content.getComponent("Ftype").setControlCallback(onFtypeControl);




const var Cutoff = Content.getComponent("Cutoff");


inline function onCutoffControl(component, value)
{
	Filter1.setAttribute(1, value);
	Filter2.setAttribute(1, value);
	Filter3.setAttribute(1, value);
	Filter4.setAttribute(1, value);
	Filter5.setAttribute(1, value);
	Filter6.setAttribute(1, value);
	Filter7.setAttribute(1, value);
	Filter8.setAttribute(1, value);
	Filter9.setAttribute(1, value);
};

Content.getComponent("Cutoff").setControlCallback(onCutoffControl);

const var Resonance = Content.getComponent("Resonance");

inline function onResonanceControl(component, value)
{
	Filter1.setAttribute(2, value);
	Filter2.setAttribute(2, value);
	Filter3.setAttribute(2, value);
	Filter4.setAttribute(2, value);
	Filter5.setAttribute(2, value);
	Filter6.setAttribute(2, value);
	Filter7.setAttribute(2, value);
	Filter8.setAttribute(2, value);
	Filter9.setAttribute(2, value);
};

Content.getComponent("Resonance").setControlCallback(onResonanceControl);

inline function onResonanceControl(component, value)
{
	Filter1.setAttribute(2, value);
	Filter2.setAttribute(2, value);
	Filter3.setAttribute(2, value);
	Filter4.setAttribute(2, value);
	Filter5.setAttribute(2, value);
	Filter6.setAttribute(2, value);
	Filter7.setAttribute(2, value);
	Filter8.setAttribute(2, value);
	Filter9.setAttribute(2, value);
};

Content.getComponent("Resonance").setControlCallback(onResonanceControl);


const var FilterAttack = Content.getComponent("FilterAttack");


inline function onFilterAttackControl(component, value)
{
	FilterEnvelope1.setAttribute(2, value);
	FilterEnvelope2.setAttribute(2, value);
	FilterEnvelope3.setAttribute(2, value);
	FilterEnvelope4.setAttribute(2, value);
	FilterEnvelope5.setAttribute(2, value);
	FilterEnvelope6.setAttribute(2, value);
	FilterEnvelope7.setAttribute(2, value);
	FilterEnvelope8.setAttribute(2, value);
	FilterEnvelope9.setAttribute(2, value);
};

Content.getComponent("FilterAttack").setControlCallback(onFilterAttackControl);

const var FilterDecay = Content.getComponent("FilterDecay");


inline function onFilterDecayControl(component, value)
{
		FilterEnvelope1.setAttribute(5, value);
		FilterEnvelope2.setAttribute(5, value);
		FilterEnvelope3.setAttribute(5, value);
		FilterEnvelope4.setAttribute(5, value);
		FilterEnvelope5.setAttribute(5, value);
		FilterEnvelope6.setAttribute(5, value);
		FilterEnvelope7.setAttribute(5, value);
		FilterEnvelope8.setAttribute(5, value);
		FilterEnvelope9.setAttribute(5, value);
	
};

Content.getComponent("FilterDecay").setControlCallback(onFilterDecayControl);

const var FilterSustain = Content.getComponent("FilterSustain");


inline function onFilterSustainControl(component, value)
{
	FilterEnvelope1.setAttribute(6, value);
	FilterEnvelope2.setAttribute(6, value);
	FilterEnvelope3.setAttribute(6, value);
	FilterEnvelope4.setAttribute(6, value);
	FilterEnvelope5.setAttribute(6, value);
	FilterEnvelope6.setAttribute(6, value);
	FilterEnvelope7.setAttribute(6, value);
	FilterEnvelope8.setAttribute(6, value);
	FilterEnvelope9.setAttribute(6, value);
};

Content.getComponent("FilterSustain").setControlCallback(onFilterSustainControl);

const var FilterRelease = Content.getComponent("FilterRelease");


inline function onFilterReleaseControl(component, value)
{
	FilterEnvelope1.setAttribute(7, value);
	FilterEnvelope2.setAttribute(7, value);
	FilterEnvelope3.setAttribute(7, value);
	FilterEnvelope4.setAttribute(7, value);
	FilterEnvelope5.setAttribute(7, value);
	FilterEnvelope6.setAttribute(7, value);
	FilterEnvelope7.setAttribute(7, value);
	FilterEnvelope8.setAttribute(7, value);
	FilterEnvelope9.setAttribute(7, value);
};

Content.getComponent("FilterRelease").setControlCallback(onFilterReleaseControl);

const var FEnvMod = Content.getComponent("FEnvMod");

inline function onFEnvModControl(component, value)
{
	FilterEnvelope1.setIntensity(value);
	FilterEnvelope2.setIntensity(value);
	FilterEnvelope3.setIntensity(value);
	FilterEnvelope4.setIntensity(value);
	FilterEnvelope5.setIntensity(value);
	FilterEnvelope6.setIntensity(value);
	FilterEnvelope7.setIntensity(value);
	FilterEnvelope8.setIntensity(value);
	FilterEnvelope9.setIntensity(value);
};

Content.getComponent("FEnvMod").setControlCallback(onFEnvModControl);

const var FModA = Content.getComponent("FModA");


inline function onFModAControl(component, value)
{
	FilterModA1.setIntensity(value);
	FilterModA2.setIntensity(value);
	FilterModA3.setIntensity(value);
	FilterModA4.setIntensity(value);
	FilterModA5.setIntensity(value);
	FilterModA6.setIntensity(value);
	FilterModA7.setIntensity(value);
	FilterModA8.setIntensity(value);
	FilterModA9.setIntensity(value);
};

Content.getComponent("FModA").setControlCallback(onFModAControl);




const var FilterVEL = Content.getComponent("FilterVEL");






//show hide mod params

const var button1 = Content.getComponent("seqtype1");
const var table1 = Content.getComponent("ScriptTable1");
const var step1 = Content.getComponent("SliderPack1");
const var s1 = Synth.getModulator("s1");

inline function onseqtype1Control(number, value)
{
        step1.showControl(value);
        table1.showControl(1-value); 
        s1.setAttribute(s1.type, 1-value);
        s2.setAttribute(s2.type, 0);
}







button1.setControlCallback(onseqtype1Control);






const var button2 = Content.getComponent("seqtype2");
const var table2 = Content.getComponent("ScriptTable2");
const var step2 = Content.getComponent("SliderPack2");
const var s2 = Synth.getModulator("s2");

inline function onseqtype2Control(number, value)
{
        step2.showControl(value);
        table2.showControl(1-value); 
        s2.setAttribute(s2.type, 0);
        s2.setAttribute(s2.type, 1-value);
}


button2.setControlCallback(onseqtype2Control);



const var button3 = Content.getComponent("seqtype3");
const var table3 = Content.getComponent("ScriptTable3");
const var step3 = Content.getComponent("SliderPack3");
const var s3 = Synth.getModulator("s3");

inline function onseqtype3Control(number, value)
{
        step3.showControl(value);
        table3.showControl(1-value); 
        s3.setAttribute(s3.type, 0);
        s3.setAttribute(s3.type, 1-value);
}


button3.setControlCallback(onseqtype3Control);



const var button4 = Content.getComponent("seqtype4");
const var table4 = Content.getComponent("ScriptTable4");
const var step4 = Content.getComponent("SliderPack4");
const var s4 = Synth.getModulator("s4");

inline function onseqtype4Control(number, value)
{
        step4.showControl(value);
        table4.showControl(1-value); 
        s4.setAttribute(s4.type, 0);
        s4.setAttribute(s4.type, 1-value);
}


button4.setControlCallback(onseqtype4Control);


 function onNoteOn()
{
	// the index is zero based like everything else in good
	// programming, so we need to add one to get the actual
	// channel number
	local d = rrIndex+1;
	
	// Store the value in the MIDIList for the note on
	EventIdStack.push(noteOnChannels, Message.getEventId(), d);
	Console.print(d);
	Message.setChannel(d);
	
	// Cycle through the round robin amount
	if(rrIndex++ >= 6)
	    rrIndex = 1;
}
 
function onNoteOff()
{
    local c = EventIdStack.pop(noteOnChannels, Message.getEventId());
	Message.setChannel(c);
    
}function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 