
#include "CPU.h"

void CPU::reset() {
    for (unsigned short &i : R) {
        i = 0;
    }
    flags.setZeroFlag(0);
    flags.setGreaterFlag(0);
    flags.setEqualFlag(0);
    IP = 0xFFF0;
}

CPU::CPU() {
    reset();
}
