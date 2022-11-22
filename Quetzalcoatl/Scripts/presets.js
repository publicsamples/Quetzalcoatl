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
