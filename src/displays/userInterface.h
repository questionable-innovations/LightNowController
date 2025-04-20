#pragma once

class UserInterface {
    public:
        void begin();
        KnobState loop();
};


struct KnobState {
    bool changed;
    
    ColourWay rawValues;
    int master;
    ColourWay muxedValues;
};

struct ColourWay {
    int red;
    int green;
    int blue;
};