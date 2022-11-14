//RR

// This button will control the behaviour:
// - ON: the sine generators will be cycled
// - OFF: all will be played each time
const var Enable = Content.getComponent("Enable");






// Grab a reference to the MIDI filters
const var Cfilters = [Synth.getMidiProcessor("ChanFilter1"),
                     Synth.getMidiProcessor("ChanFilter2"),
                     Synth.getMidiProcessor("ChanFilter3"),
                     Synth.getMidiProcessor("ChanFilter4"),
                     Synth.getMidiProcessor("ChanFilter5"),
                     Synth.getMidiProcessor("ChanFilter6")];
                     
const var Containers = [Synth.getChildSynth("Container2"),
                     Synth.getChildSynth("Container3"),
                    Synth.getChildSynth("Container4"),
                    Synth.getChildSynth("Container5"),                 
                    Synth.getChildSynth("Container6")];                                          

inline function bCallback(control, value)
{
    // Bypass all filters if its off
    for(f in Cfilters)
        f.setBypassed(!value);
        for(f in Containers)
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

