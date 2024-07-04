#include "AccesMemory.h"

Memory memory;

void AccesMemory::store(tipMemorie addr, tipMemorie val){
    memory.getMemory()[addr] = val;
}

tipMemorie AccesMemory::load(tipMemorie addr) {
    return memory.getMemory()[addr];
}

tipMemorieInstr AccesMemory::loadInstruction(tipMemorie addr){
    return memory.getMemory()[addr];
}
