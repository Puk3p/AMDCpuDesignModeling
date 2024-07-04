#pragma once
#include "AccesMemory.h"

enum MemoryInstruction{
    LOAD = 1,
    STORE = 2
};

class CPUGenericMethod {
public:
    int request_to_memory(MemoryInstruction request, tipMemorie addr = 0, tipMemorie data = 0);
    // int receive_memory_data(tipMemorie addr = 0, tipMemorie data = 0);

};
