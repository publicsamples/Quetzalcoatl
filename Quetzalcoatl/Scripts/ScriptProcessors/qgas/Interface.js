Content.makeFrontInterface(885, 745);

include("waves.js");
include("rr.js");
include("presets.js");

include("xfade.js");
include("FMandPitch.js");
include("Filter.js");
include("modulators.js");
include("osc2.js");
include("mod.js");




var FactoryFiltered = ["2nsweep" ,"2nsweep2" ,"2nsweep3" ,"2nsweep4" ,"2nsweep5" ,"2nsweep6" ,"2nsweep7" ,"2nsweep8" ,"DFLP1" ,"DFLP2" ,"DFLP3" ,"DFLP4" ,"DFLP5" ,"DFLP6" ,"DFLP7" ,"DFLP8" ,"DFNotch1" ,"DFNotch2" ,"DFNotch3" ,"DFNotch4" ,"DFNotch5" ,"DFNotch6" ,"DFNotch7" ,"DFNotch8" ,"SawCinHP1" ,"SawCinHP2" ,"SawCinHP3" ,"SawCinHP4" ,"SawCinHP5" ,"SawCinHP6" ,"SawCinHP7" ,"SawCinHP8", "vibro1", 
"vibro2","vibro3", "esq-EP1", "esq-EP2", "esq-EP3", "esq-Scrd", "esq-fibre", "esq-hyp", "esq-mth", "esq-nsty1", "esq-nsty2", "esq-pswp", "esq-sawd", "esq-simr", "esq-slow","jx-Big", "jx-Brsy", "jx-Wet", "jx-Wob", "jx-fade", "jx-hsh", "jx-lil", "jx-pno", "jx-rise", "jx-s&h", "jx-slow", "jx-spml", "jx-tipsy", "jx-wine","FeedPW1", "FeedPW2", "FeedPW3", "FeedPW4", "FeedPW5", "FeedPW6", "FeedPW7", "FeedPW8", "CBS1", "CBS2", "CBS3", "CBS4", "CBS5", "CBS6", "CBS7", "CBS8", "Cy2OP1", "Cy2OP2", "Cy2OP3", "SqrNoise1", "SqrNoise2", "SqrNoise3", "SqrNoise4", "SqrNoise5", "SqrNoise6", "SqrNoise7", "SqrNoise8", "xMod1", "xMod2", "xMod3", "xMod4", "xMod5", "xMod6", "xMod7", "xMod8", "xModB1", "xModB2", "xModB3", "xModB4", "xModB5", "xModB6", "xModB7", "xModB8", "2NAM1", "2NAM2", "2NAM3", "2NAM4", "2NAM5", "2NAM6", "2NAM7", "2NAM8", "AM_a1", "AM_a2", "AM_a3", "AM_a4", "AM_a5", "AM_a6", "AM_a7", "AM_a8", "AM_b1", "AM_b2", "AM_b3", "AM_b4", "AM_b5", "AM_b6", "AM_b7", "AM_b8", "LIN1", "LIN2", "LIN3", "LIN4", "LIN5", "LIN6", "LIN7", "LIN8", "NRB1", "NRB2", "NRB3", "NRB4", "NRB5", "NRB6", "NRB7", "NRB8", "pmA1", "pmA2", "pmA3", "pmA4", "pmA5", "pmA6", "pmA7", "pmA8", "pmB1", "pmB2", "pmB3", "pmB4", "pmB5", "pmB6", "pmB7", "pmB8"];


const var BankA = Content.getComponent("BankA");
const var BankB = Content.getComponent("BankB");
const var BankC = Content.getComponent("BankC");
const var BankD = Content.getComponent("BankD");
const var BankE = Content.getComponent("BankE");
const var BankA2 = Content.getComponent("BankA2");
const var BankB2 = Content.getComponent("BankB2");
const var BankC2 = Content.getComponent("BankC2");
const var BankD2 = Content.getComponent("BankD2");
const var BankE2 = Content.getComponent("BankE2");
const var BankA3 = Content.getComponent("BankA3");
const var BankB3 = Content.getComponent("BankB3");
const var BankC3 = Content.getComponent("BankC3");
const var BankD3 = Content.getComponent("BankD3");
const var BankE3 = Content.getComponent("BankE3");
const var BankA4 = Content.getComponent("BankA4");
const var BankB4 = Content.getComponent("BankB4");
const var BankC4 = Content.getComponent("BankC4");
const var BankD4 = Content.getComponent("BankD4");
const var BankE4 = Content.getComponent("BankE4");
const var BankA5 = Content.getComponent("BankA5");
const var BankB5 = Content.getComponent("BankB5");
const var BankC5 = Content.getComponent("BankC5");
const var BankD5 = Content.getComponent("BankD5");
const var BankE5 = Content.getComponent("BankE5");
const var BankA6 = Content.getComponent("BankA6");
const var BankB6 = Content.getComponent("BankB6");
const var BankC6 = Content.getComponent("BankC6");
const var BankD6 = Content.getComponent("BankD6");
const var BankE6 = Content.getComponent("BankE6");
const var BankA7 = Content.getComponent("BankA7");
const var BankB7 = Content.getComponent("BankB7");
const var BankC7 = Content.getComponent("BankC7");
const var BankD7 = Content.getComponent("BankD7");
const var BankE7 = Content.getComponent("BankE7");
const var BankA8 = Content.getComponent("BankA8");
const var BankB8 = Content.getComponent("BankB8");
const var BankC8 = Content.getComponent("BankC8");
const var BankD8 = Content.getComponent("BankD8");
const var BankE8 = Content.getComponent("BankE8");






BankA.set("items", FactoryFiltered.join("\n"));

BankA2.set("items", FactoryFiltered.join("\n"));

BankA3.set("items", FactoryFiltered.join("\n"));

BankA4.set("items", FactoryFiltered.join("\n"));

BankA5.set("items", FactoryFiltered.join("\n"));

BankA6.set("items", FactoryFiltered.join("\n"));

BankA7.set("items", FactoryFiltered.join("\n"));

BankA8.set("items", FactoryFiltered.join("\n"));


inline function onBankAControl(component, value)
{
Sampler1.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler10.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler19.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler28.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler37.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler46.asSampler().loadSampleMap(FactoryFiltered[value-1]);



};

Content.getComponent("BankA").setControlCallback(onBankAControl);

inline function onBankBControl(component, value)
{
Sampler1.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler10.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler19.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler28.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler37.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler46.asSampler().loadSampleMap(FactoryFM[value-1]);
   

  };



Content.getComponent("BankB").setControlCallback(onBankBControl);

inline function onBankCControl(component, value)
{
Sampler1.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler10.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler19.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler28.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler37.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler46.asSampler().loadSampleMap(FactoryAM[value-1]);
   
  


};

Content.getComponent("BankC").setControlCallback(onBankCControl);

inline function onBankDControl(component, value)
{
Sampler1.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler10.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler19.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler28.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler37.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler46.asSampler().loadSampleMap(FactoryMisc[value-1]);
   
};
Content.getComponent("BankD").setControlCallback(onBankDControl);

inline function onBankEControl(component, value)
{
Sampler1.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler10.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler19.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler28.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler37.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler46.asSampler().loadSampleMap(FactoryNoise[value-1]);
   
};
Content.getComponent("BankE").setControlCallback(onBankEControl);

inline function onBankA2Control(component, value)
{
Sampler1.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler11.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler20.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler29.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler38.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler47.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   
  


};

inline function onBankA2Control(component, value)
{
Sampler2.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler11.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler20.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler29.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler38.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler47.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   
  


};

Content.getComponent("BankA2").setControlCallback(onBankA2Control);

inline function onBankB2Control(component, value)
{
Sampler2.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler11.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler20.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler29.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler38.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler47.asSampler().loadSampleMap(FactoryFM[value-1]);
   
  


};

Content.getComponent("BankB2").setControlCallback(onBankB2Control);

inline function onBankC2Control(component, value)
{
Sampler2.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler11.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler20.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler29.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler38.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler47.asSampler().loadSampleMap(FactoryAM[value-1]);
   
  


};

Content.getComponent("BankC2").setControlCallback(onBankC2Control);

inline function onBankD2Control(component, value)
{
Sampler2.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler11.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler20.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler29.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler38.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler47.asSampler().loadSampleMap(FactoryMisc[value-1]);
   
};
Content.getComponent("BankD2").setControlCallback(onBankD2Control);

inline function onBankE2Control(component, value)
{
Sampler2.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler11.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler20.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler29.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler38.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler47.asSampler().loadSampleMap(FactoryNoise[value-1]);
   
};
Content.getComponent("BankE2").setControlCallback(onBankE2Control);


inline function onBankA3Control(component, value)
{
Sampler3.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler12.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler21.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler30.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler39.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   
  


};

Content.getComponent("BankA3").setControlCallback(onBankA3Control);

inline function onBankB3Control(component, value)
{
Sampler3.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler12.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler21.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler30.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler39.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryFM[value-1]);
   
  


};

Content.getComponent("BankB3").setControlCallback(onBankB3Control);

inline function onBankC3Control(component, value)
{
Sampler3.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler12.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler21.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler30.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler39.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryAM[value-1]);
   
  


};

Content.getComponent("BankC3").setControlCallback(onBankC3Control);

inline function onBankD3Control(component, value)
{
Sampler3.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler12.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler21.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler30.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler39.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryMisc[value-1]);
   
};
Content.getComponent("BankD3").setControlCallback(onBankD3Control);

inline function onBankE3Control(component, value)
{
Sampler3.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler12.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler21.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler30.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler39.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryNoise[value-1]);
   
};
Content.getComponent("BankE3").setControlCallback(onBankE3Control);

inline function onBankA4Control(component, value)
{
Sampler4.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler13.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler22.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler31.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler40.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   

};

Content.getComponent("BankA4").setControlCallback(onBankA4Control);

inline function onBankB4Control(component, value)
{
Sampler4.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler13.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler22.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler31.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler40.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryFM[value-1]);
   

};

Content.getComponent("BankB4").setControlCallback(onBankB4Control);

inline function onBankC4Control(component, value)
{
Sampler4.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler13.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler22.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler31.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler40.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryAM[value-1]);


};

Content.getComponent("BankC4").setControlCallback(onBankC4Control);

inline function onBankD4Control(component, value)
{
Sampler4.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler13.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler22.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler31.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler40.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryMisc[value-1]);
   
};
Content.getComponent("BankD4").setControlCallback(onBankD4Control);

inline function onBankE4Control(component, value)
{
Sampler4.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler13.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler22.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler31.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler40.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler48.asSampler().loadSampleMap(FactoryNoise[value-1]);
   
};
Content.getComponent("BankE4").setControlCallback(onBankE4Control);

inline function onBankA5Control(component, value)
{
Sampler5.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler14.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler23.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler32.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler41.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler49.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   


};

Content.getComponent("BankA5").setControlCallback(onBankA5Control);

inline function onBankB5Control(component, value)
{
Sampler5.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler14.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler23.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler32.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler41.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler49.asSampler().loadSampleMap(FactoryFM[value-1]);
   
 

};

Content.getComponent("BankB5").setControlCallback(onBankB5Control);

inline function onBankC5Control(component, value)
{
Sampler5.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler14.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler23.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler32.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler41.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler49.asSampler().loadSampleMap(FactoryAM[value-1]);
 

};

Content.getComponent("BankC5").setControlCallback(onBankC5Control);

inline function onBankD5Control(component, value)
{
Sampler5.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler14.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler23.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler32.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler41.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler49.asSampler().loadSampleMap(FactoryMisc[value-1]);
   
};
Content.getComponent("BankD5").setControlCallback(onBankD5Control);

inline function onBankE5Control(component, value)
{
Sampler5.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler14.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler23.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler32.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler41.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler49.asSampler().loadSampleMap(FactoryNoise[value-1]);
   
};
Content.getComponent("BankE5").setControlCallback(onBankE5Control);

inline function onBankA6Control(component, value)
{
Sampler6.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler15.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler24.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler33.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler42.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler50.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   
  


};

Content.getComponent("BankA6").setControlCallback(onBankA6Control);

inline function onBankB6Control(component, value)
{
Sampler6.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler15.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler24.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler33.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler42.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler50.asSampler().loadSampleMap(FactoryFM[value-1]);
   
  


};

Content.getComponent("BankB6").setControlCallback(onBankB6Control);

inline function onBankC6Control(component, value)
{
Sampler6.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler15.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler24.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler33.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler42.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler50.asSampler().loadSampleMap(FactoryAM[value-1]);
   
  


};

Content.getComponent("BankC6").setControlCallback(onBankC6Control);

inline function onBankD6Control(component, value)
{
Sampler6.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler15.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler24.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler33.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler42.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler50.asSampler().loadSampleMap(FactoryMisc[value-1]);
   
};
Content.getComponent("BankD6").setControlCallback(onBankD6Control);

inline function onBankE6Control(component, value)
{
Sampler6.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler15.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler24.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler33.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler42.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler50.asSampler().loadSampleMap(FactoryNoise[value-1]);
   
};
Content.getComponent("BankE6").setControlCallback(onBankE6Control);

inline function onBankA7Control(component, value)
{
Sampler7.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler16.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler25.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler34.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler43.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler51.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   
  


};

Content.getComponent("BankA7").setControlCallback(onBankA7Control);

inline function onBankB7Control(component, value)
{
Sampler7.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler16.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler25.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler34.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler43.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler51.asSampler().loadSampleMap(FactoryFM[value-1]);
   


};

Content.getComponent("BankB7").setControlCallback(onBankB7Control);

inline function onBankC7Control(component, value)
{
Sampler7.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler16.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler25.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler34.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler43.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler51.asSampler().loadSampleMap(FactoryAM[value-1]);
   

};

Content.getComponent("BankC7").setControlCallback(onBankC7Control);

inline function onBankD7Control(component, value)
{
Sampler7.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler16.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler25.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler34.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler43.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler51.asSampler().loadSampleMap(FactoryMisc[value-1]);
   
};
Content.getComponent("BankD7").setControlCallback(onBankD7Control);

inline function onBankE7Control(component, value)
{
Sampler7.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler16.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler25.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler34.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler43.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler51.asSampler().loadSampleMap(FactoryNoise[value-1]);
   
};
Content.getComponent("BankE7").setControlCallback(onBankE7Control);

inline function onBankA8Control(component, value)
{
Sampler8.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler17.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler26.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler35.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler44.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   Sampler52.asSampler().loadSampleMap(FactoryFiltered[value-1]);
   

};

Content.getComponent("BankA8").setControlCallback(onBankA8Control);

inline function onBankB8Control(component, value)
{
Sampler8.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler17.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler26.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler35.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler44.asSampler().loadSampleMap(FactoryFM[value-1]);
   Sampler52.asSampler().loadSampleMap(FactoryFM[value-1]);
   

};

Content.getComponent("BankB8").setControlCallback(onBankB8Control);

inline function onBankC8Control(component, value)
{
Sampler8.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler17.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler26.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler35.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler44.asSampler().loadSampleMap(FactoryAM[value-1]);
   Sampler52.asSampler().loadSampleMap(FactoryAM[value-1]);
   


};

Content.getComponent("BankC8").setControlCallback(onBankC8Control);

inline function onBankD8Control(component, value)
{
Sampler8.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler17.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler26.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler35.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler44.asSampler().loadSampleMap(FactoryMisc[value-1]);
   Sampler52.asSampler().loadSampleMap(FactoryMisc[value-1]);
   
};
Content.getComponent("BankD8").setControlCallback(onBankD8Control);

inline function onBankE8Control(component, value)
{
Sampler8.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler17.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler26.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler35.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler44.asSampler().loadSampleMap(FactoryNoise[value-1]);
   Sampler52.asSampler().loadSampleMap(FactoryNoise[value-1]);
   
};
Content.getComponent("BankE8").setControlCallback(onBankE8Control);







//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
    g.setFont("Avenir", 16.0);
   
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});

laf.registerFunction("drawPresetBrowserListItem", function(g, obj)
{
    if(obj.selected)
    {
        g.setColour(0x22FFFFFF);
        g.fillRoundedRectangle(obj.area, 5.0);
        
       g.setFont("Avenir", 16.0);
    }
   
    g.setColour(obj.textColour);
    g.setFont("Avenir", 16.0);
    g.drawAlignedText(obj.text, obj.area, "centred");
});






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
 