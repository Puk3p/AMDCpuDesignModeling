#pragma once
#include <iostream>
#include "Memory.h"

typedef u_int16_t tipMemorie;
typedef u_int64_t tipMemorieInstr;

extern Memory memory;

class AccesMemory {

public:
    static void store(tipMemorie addr, tipMemorie val);
    static tipMemorie load(tipMemorie addr);
    static tipMemorieInstr loadInstruction(tipMemorie addr);
};

