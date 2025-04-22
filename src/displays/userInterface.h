#pragma once


struct ColourWay {
    int red;
    int green;
    int blue;
};

struct KnobState {
    bool changed;
    
    ColourWay rawValues;
    int master;
    ColourWay muxedValues;
};

class UserInterface {
    public:
        void begin();
        KnobState loop();
};
