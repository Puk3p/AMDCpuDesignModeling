#include "Memory.h"

Memory::Memory() {
    for (int i = 0; i < 65536; ++i){
        MEMORY[i] = 0;
    }
}

tipMemorie* Memory::getMemory() {
    return MEMORY;
}

void Memory::setMemory(tipMemorie addr, tipMemorie val) {
    MEMORY[addr] = val;
}
