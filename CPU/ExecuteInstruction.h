#pragma once

#include "CPUGenericMethod.h"
#include "../Instructions/OPCODES.h"

class ExecuteInstruction: CPUGenericMethod {
    public:
        ExecuteInstruction();

    static int execute_instruction(int opcode, tipMemorie src1, tipMemorie src2);
};
