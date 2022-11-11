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


