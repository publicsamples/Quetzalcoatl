//presets


const var closepreset = Content.getComponent("closepreset");



const var Pbox = Content.getComponent("settings");
const var blank = Content.getComponent("blank1");


const var presets= Content.getComponent("presets");

inline function onpresetsControl(component, value)
{
     Pbox.showControl(value);
        blank.showControl(1-value); 
        closepreset.setValue(1);
};


Content.getComponent("presets").setControlCallback(onpresetsControl);


inline function onclosepresetControl(component, value)
{

       Pbox.showControl(value);
        blank.showControl(1-value); 
        presets.setValue(0);
};

Content.getComponent("closepreset").setControlCallback(onclosepresetControl);


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

const var Off = Content.getComponent("VoiceOffsets");
const var blank2 = Content.getComponent("blank2");
const var closeoffset = Content.getComponent("closeoffset");

const var offs= Content.getComponent("offset");

inline function onoffsetControl(component, value)
{
        Off.showControl(value);
        blank2.showControl(1-value); 
        closeoffset.setValue(0);
};


Content.getComponent("offset").setControlCallback(onoffsetControl);


inline function oncloseoffsetControl(component, value)
{
	 blank2.showControl(value);
        Off.showControl(1-value); 
        offs.setValue(0);
};

Content.getComponent("closeoffset").setControlCallback(oncloseoffsetControl);


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
