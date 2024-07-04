#include "OPCODES.h"

int OPCODES::toInt(std::string opcode) {
    int result = 0;
    for (char c: opcode) {
        if (isdigit(c)) {
            result = result * 10 + (c - '0');
        }
    }
    return result;
}

OPCODES::OPCODES() {
    return;
}
