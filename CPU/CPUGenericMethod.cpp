#include "CPUGenericMethod.h"

int CPUGenericMethod::request_to_memory(MemoryInstruction request, tipMemorie addr, tipMemorie data) {
    switch (request) {
        case LOAD:
            AccesMemory::load(addr);
            break;

        case STORE:
            AccesMemory::store(addr, data);
            break;

    }
    return 0;
}
