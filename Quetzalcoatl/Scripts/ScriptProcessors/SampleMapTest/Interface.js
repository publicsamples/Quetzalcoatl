Content.makeFrontInterface(650, 560);

// This will be the table for the expansions
const var Panel1 = Content.getComponent("Panel1");

// This will be the table for the sample maps
const var Panel2 = Content.getComponent("Panel2");

// The sampler to load the sample map
const var Sampler1 = Synth.getSampler("Sampler1");

// The panels will not store anything, but we just store
// the loaded sample map ID in this label
// (for clarity it's not really hidden, but you can go that
//  last mile for yourself in a real project)
const var HiddenLabel = Content.getComponent("HiddenLabel");


Panel1.setPaintRoutine(function(g)
{
	g.fillAll(0x22000000);
});

Panel2.setPaintRoutine(function(g)
{
	g.fillAll(0x22000000);
});


// Create the expansion handler
const var expHandler = Engine.createExpansionHandler();

// fetch the expansion list
const var list = expHandler.getExpansionList();

// add "undefined" at the beginning.
// This will show the embedded samplemaps in the project
list.insert(0, undefined);

// Adds a row to the given panel.
// the obj is either a Expansion or a simple String
// depending on whether isCategory is true or false
// (root is either Panel1 or Panel2)
inline function addRow(root, obj, isCategory)
{
    local c = root.addChildPanel();
    
    c.data.isCategory = isCategory;
    
    if(isCategory)
    {
        c.data.expansion = obj;
    
        if(isDefined(obj))
        {
            // Fetch the name
            c.data.name = obj.getProperties().Name;
            // Store the list of available sample maps
            c.data.list = obj.getSampleMapList();
        }
        else
        {
            // this item will show the embedded sample maps
            c.data.name = "Root";
            
            // Fetch the list of embedded samplemaps
            c.data.list = Sampler.getSampleMapList();
        }
    }
    else
    {
        // obj will be the samplemap ID
        c.data.id = obj;
        c.data.name = obj;
        
        // truncate the expansion wildcard
        // for sample maps inside expansions
        // so that it looks nice
        if(c.data.name.indexOf("}") != -1)
            c.data.name = obj.split("}")[1];
    }
    
    // Let it react on mouse clicks
    c.setMouseCallback(mouseCallback);
    c.set("allowCallbacks", "Clicks & Hover");
    
    // Define a simple paint routine
    c.setPaintRoutine(function(g)
    {
        var a = [1, 1, this.getWidth()-2, this.getHeight()-2];
        
        if(this.data.hover)
        {
            g.setColour(0x05FFFFFF);
            g.fillRect(a);
        }
        
        if(this.data.active)
        {
            g.setColour(0x11FFFFFF);
            g.fillRect(a);
        }
        
        g.setColour(0x22FFFFFF);
        g.drawRect(a, 1.0);
        
        g.setColour(Colours.white);
        g.drawAlignedText(this.data.name, a, "centred");
    });
    
    // Put the child panel at the bottom of the list
    c.setPosition(0, root.get("height"), root.get("width"), 30);
    // and resize the root panel
    root.set("height", root.get("height") + c.get("height"));
}

/** Clears the given panel. */
inline function clearPanel(panelToClear)
{
    // Clear the samplemaps
    for(c in panelToClear.getChildPanelList())
        c.removeFromParent();
        
    // Reset the size so that it won't stack up 
    // to infinity
    panelToClear.set("height", 0);
}

// The mouse callback to use when clicking on the 
// expansion column
function mouseCallback(event)
{
    this.data.hover = event.hover;
    
    if(event.clicked)
    {
        if(this.data.isCategory)
        {
            // We'll forward this to a separate
            // function (which will also be called
            // when the label changes from outside).
            setCategory(this);
        }
        else
        {
            // This defers the actual loading
            // to the Labels callback so that it
            // can be stored in a preset.
            HiddenLabel.setValue(this.data.id);
            
            // Don't forget to trigger the label's
            // callback
            HiddenLabel.changed();
        }
    }
    
    this.repaint();
}

/** This will clear the right list and sets the active
    state for the given panel (cat). */
inline function setCategory(cat)
{
    clearPanel(Panel2);
            
    for(e in cat.data.list)
        addRow(Panel2, e, false);
                
    for(cp in Panel1.getChildPanelList())
    {
        cp.data.active = cp == cat;
        cp.repaint();
    }   
}

// Clear everything
clearPanel(Panel1);
clearPanel(Panel2);

// Initialise the left column with the available expansions
for(e in list)
    addRow(Panel1, e, true);

/** This is called when the label changes and causes the
    columns to update themselve in order to show the currently
    loaded sample map. */
inline function refreshActiveState()
{
    local value = HiddenLabel.getValue();
    
    for(cat in Panel1.getChildPanelList())
    {
        // Check whether the category should
        // be selected
        if(cat.data.list.contains(value))
            setCategory(cat);
        
        // repaint all panels
        cat.repaint();
    }
    
    
    for(ids in Panel2.getChildPanelList())
    {
        // check whether the sample map should
        // be selected
        ids.data.active = ids.data.id == value;
        ids.repaint();
    }
}

/** The hidden label's callback. It loads the given samplemap
    and refreshes the state. */
inline function onHiddenLabelControl(component, value)
{
    // The very first time it might be zero, so prevent
    // loading a bogus samplemap
    if(value != 0)
    {
        refreshActiveState();
        Sampler1.loadSampleMap(value);
    }
};

Content.getComponent("HiddenLabel").setControlCallback(onHiddenLabelControl);

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
 