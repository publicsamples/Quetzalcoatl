var MiscWaves = ["CS-Sine","CS-Pulse1","CS-Pulse2","CS-Pulse3","CS-Saw", "CS-Noise","CS-Noise2","CS-Noise3","4op Sin 1","4op Sin 3","4op Sin 3","4op Sin 4","4op Sin 5","4op Sin 6","4op Sin 7","4op Sin 8", "TriSaw FFM 1","TriSaw FFM 2","TriSaw FFM 3","TriSaw FFM 4","TriSaw FFM 5","TriSaw FFM 6","TriSaw FFM 7","TriSaw FFM 8", "CS-Noise4", "Cy2OP1","Cy2OP2","Cy2OP3","Cy2OP4","Cy2OP5","Cy2OP6","Cy2OP7","Cy2OP8","Dark BP 1","Dark BP 2","Dark BP 3","Dark BP 4", "Fold DF 1","Fold DF 2", "Fold DF 3","Fold DF 4","Fold DF 5","Fold DF 6","Fold DF 7","Fold DF 8","HR Sqr 1","HR Sqr 2","HR Sqr3","HR Sqr 4","HR Sqr 5","HR Sqr 6","HR Sqr 7","HR Sqr 8", "LP Square 1","LP Square 2","LP Square 3","LP Square 4","LP Square 5","LP Square 6","LP Square 7","LP Square 8","Shape B 1", "Shape B 2","Shape B 3","Shape B 4", "Shape B 5","Shape B 6","Shape B 7","Shape B 8","Shape C 1", "Shape C 2","Shape C 3","Shape C 4", "Shape C 5","Shape C 6","Shape C 7","Shape C 8","ZstringA", "ZstringB-ST", "RavST", "BlowyST", "CupCakeST", "GravelST", "DF1ST", "DF2ST", "CsShockST", "OgSlyST", "OgRadioST", "OgdfST", "GreatST", "CrunchyST"];

var GM = ["Piano" ,"BrightPiano" ,"HonkyTonkPiano" ,"ElectricPiano" ,"ElectricPiano" ,"Xylophone" ,"TubularBells" ,"DrawbarOrgan" ,"PercussiveOrgan" ,"RockOrgan" ,"ChurchOrgan" ,"GuitarNylon" ,"GuitarSteel" ,"ElectricGuitarJazz" ,"ElectricGuitarClean" ,"ElectricGuitarMuted" ,"DistortionGuitar" ,"ElectricBassFinger" ,"SynthBass" ,"SynthBass" ,"OrchestralHarp" ,"Timpani" ,"SynthStrings" ,"SynthStrings" ,"SynthBrass" ,"SynthBrass" ,"TenorSaxophone" ,"Clarinet" ,"Recorder" ,"Ocarina" ,"SynthSquare" ,"SynthCalliope" ,"SynthFifths" ,"SynthBassLead" ,"SynthNewAge" ,"SynthPadChoir" ,"SynthPadBowed" ,"SynthPadSweep" ,"SynthSoundtrack" ,"SynthCrystal" ,"SynthGoblins" ,"SynthSciFi" ,"Kalimba"  ,"Percussion"];


var cs30 = ["2nd Finger", "3rd Day", "Astonished", "Bargain", "Basic", "Brew", "Bumpy", "Busy", "Bypass", "Cream", "Curious", "Devistator", "Drama", "FM Rings", "Feed Fwd", "Grizzle", "Hell Cat", "K-Legs", "K30L", "LoopG", "Maybe Strings", "Messing Around", "Pseudo Sync", "RM", "Says Things", "Screamer", "Shakey Bass", "Spl Git", "Twinkle toes", "stix"];

var em25 = ["Brass 16", "Brass 4", "Brass 8", "Organ 16", "Organ 2", "Organ 4", "Organ 8", "String 16", "String 4", "String 8"];

var MiscRoland = ["101-bell1", "101-bell2", "101-bell3", "101-bell4", "101-pwm1", "101-pwm2", "101-pwm3", "101-pwm4", "101-string2", "101-string3", "101-string4", "DCOPianoST", "LfadeST", "Lil bass ST", "RoundST", "S&H-ST", "SimpleST", "Slow One ST", "T Sync ST", "W Brass ST", "WetST", "harshST", "MildBrassSH", "RiseSH", "SoftSH", "PlasticSH", "FsweepSH", "Jd800Space"];

var hybrids = ["1st", "Bell Source", "Belles", "BigST", "BigElectric", "DrugWaveST", "EP1", "EP2", "EP3", "Euro Organ", "GateAR", "Hard Bass", "LeapST", "Lingo", "More Bell", "Odd Keys", "Rousing", "Sad Ring", "Scrd", "Special K ST", "Spl Git", "Tinkly", "eggcelent", "fat organ", "mr clicky", "mth", "nsty1", "nsty2", "pswp", "pulserST", "sawd", "simr", "slowishST",  "walls"];

var kraftzwerg = ["BooBass", "CrazyLFO", "Gooey", "Log", "Magic Resin", "OChord", "organic"];

var Xpander = ["2 Fingers", "AV", "Another Time", "B Chord 1", "B Chord 2", "Bison1ST", "Bison2ST", "Boring Bass 1", "Boring Bass 2", "BugST", "E Kee 1", "E Kee 2", "Low Standards", "M Chord ST", "OChord", "Phase Pad", "StackST", "Thick Snappy 1", "Thick Snappy 2", "Thin Shine 1", "TubeS 1", "lose", "melomod", "osc mod", "FMThick1", "FMThick2", "FMThick3", "FMThick4","FmFilter1","FmFilter2","FmFilter3","FmFilter4","FmFilter5","FmFilter6","FmFilter7","FmFilter8","PW1","PW2","PW3","PW4","PW5","PW6","PW7","PW8","PW Filter 1","PW Filter 2","PW Filter 3","PW Filter 4","PW Filter 5","PW Filter 6","PW Filter 7","PW Filter 8", "FmDrama1ST", "FmDrama2ST"];

var Monopoly = ["2020", "Alley Cat", "Basic Lead", "Blood Organ", "Bumpkin 130", "Classy Strings", "Crab Rock", "Crab cake", "Crumb Flute", "DS", "Drink", "Fingers", "Lemon 90", "Lozange", "MP2xSaw1", "MP2xSaw3", "MP4xSaw1","MP4xSaw2", "MPSawA1 ", "MPSawA2", "MPSawA3", "MPSawA4", "MPSawB1", "MPSawB2", "MPSawB3", "MPSqr-1", "MPSqr-10", "MPSqr-2", "MPSqr-3", "MPSqr-4", "MPSqr-5", "MPSqr-6", "MPSqr-7", "MPSqr-8", "MPSqr-9", "MPTri", "Not", "Rodge", "Scratchy", "Space Raider", "SyncStack", "Twisting Mellow 1", "Twisting Mellow 2", "Vibe", "consider", "funny", "heart ache", "sale"];

var FmFilter = ["FmFilter1","FmFilter2","FmFilter3","FmFilter4","FmFilter5","FmFilter6","FmFilter7","FmFilter8"];

var FMThick = ["FMThick1", "FMThick2", "FMThick3", "FMThick4"];

var PW = ["PW1","PW2","PW3","PW4","PW5","PW6","PW7","PW8"];

var PWFilter = ["PW Filter 1","PW Filter 2","PW Filter 3","PW Filter 4","PW Filter 5","PW Filter 6","PW Filter 7","PW Filter 8"];

var CSBasics = ["CS-Sine","CS-Pulse1","CS-Pulse2","CS-Pulse3","CS-Saw"];

var Cy2OP = ["Cy2OP1","Cy2OP2","Cy2OP3","Cy2OP4","Cy2OP5","Cy2OP6","Cy2OP7","Cy2OP8"];

var op4Sin = ["4op Sin 1","4op Sin 3","4op Sin 3","4op Sin 4","4op Sin 5","4op Sin 6","4op Sin 7","4op Sin 8"];

var TriSaw = ["TriSaw FFM 1","TriSaw FFM 2","TriSaw FFM 3","TriSaw FFM 4","TriSaw FFM 5","TriSaw FFM 6","TriSaw FFM 7","TriSaw FFM 8"];

var DarkBP = ["Dark BP 1","Dark BP 2","Dark BP 3","Dark BP 4"];

var FoldDF = ["Fold DF 1","Fold DF 2", "Fold DF 3","Fold DF 4","Fold DF 5","Fold DF 6","Fold DF 7","Fold DF 8"];

var HRSqr = ["HR Sqr 1","HR Sqr 2","HR Sqr3","HR Sqr 4","HR Sqr 5","HR Sqr 6","HR Sqr 7","HR Sqr 8"];

var LpSqr = ["LP Square 1","LP Square 2","LP Square 3","LP Square 4","LP Square 5","LP Square 6","LP Square 7","LP Square 8"];

var ShapeB = ["Shape B 1", "Shape B 2","Shape B 3","Shape B 4", "Shape B 5","Shape B 6","Shape B 7","Shape B 8"];

var ShapeC = ["Shape C 1", "Shape C 2","Shape C 3","Shape C 4", "Shape C 5","Shape C 6","Shape C 7","Shape C 8"];


