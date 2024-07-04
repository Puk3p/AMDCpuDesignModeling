#include <iostream>
#pragma once

typedef u_int16_t tipMemorie;

class Memory {
    private:
        tipMemorie MEMORY[65536];

    public:
        Memory();

        tipMemorie* getMemory();
        void setMemory(tipMemorie addr, tipMemorie val);
};

