//
// Created by agaio on 27.04.2024.
//

#include "DecodeInstruction.h"
void DecodeInstruction::decode_instruction(tipMemorie addr, int &opcode, tipMemorie &src1, tipMemorie &src2) {
    int aux = DecodeInstruction::request_to_memory(LOAD, addr);
    opcode = opcodeDecoder(aux);
    src1 = src1Decoder(aux);
    src2 = src2Decoder(aux);
}

DecodeInstruction::DecodeInstruction() {
    return;
}

void DecodeInstruction::send_data_to_execute() {


}
