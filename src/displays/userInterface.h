#pragma once
#include "channelDisplay.h"


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
        UserInterface();
        void begin();
        KnobState loop();
    private:
        ChannelDisplay redDisplay;
        ChannelDisplay greenDisplay;
        ChannelDisplay blueDisplay;
};
