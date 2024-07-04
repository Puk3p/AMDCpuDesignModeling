#pragma once

#include "CPUGenericMethod.h"
#include "../Utils.h"

class DecodeInstruction: CPUGenericMethod {
    public:
    DecodeInstruction();

        void decode_instruction(tipMemorie addr, int& opcode, tipMemorie& src1, tipMemorie& src2);
        void send_data_to_execute(); // Trimitem prin registri

};
