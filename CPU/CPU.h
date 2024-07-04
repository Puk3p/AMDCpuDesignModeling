#pragma once

#include "InstructionFetch.h"
#include "DecodeInstruction.h"
#include "ExecuteInstruction.h"
#include "LoadStoreData.h"
#include "AccesMemory.h"
#include "../Instructions/Flags/Flags.h"

#define REGISTRY_COUNT 8
#define FLAGS_COUNT 3

Memory memory;
extern Flags flags = Flags();

class CPU {
    private:
        tipMemorie R[REGISTRY_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0};
        // bool FLAG[FLAGS_COUNT] = {0, 0, 0}; // Z, E, G
        Flags flags = flags;
        tipMemorie IP = 0xFFF0; // Instruction Pointer
         // tipMemorie SP = 0xFFF0; // Stack Pointer
         // tipMemorie BP = 0xFFF0; // Base Pointer


        Memory memory = memory;

    public:
            CPU();
            void reset();

           InstructionFetch instructionFetch = InstructionFetch();
           DecodeInstruction decodeInstruction = DecodeInstruction();
           // ExecuteInstruction executeInstruction = ExecuteInstruction();
           LoadStoreData loadStoreData = LoadStoreData();

           void setRegistry(int index, tipMemorie value) {
               R[index] = value;
           };

           tipMemorie getRegistry(int index) {
                  return R[index];
           };

//           void setFlag(int index, bool value) {
//                 FLAG[index] = value;
//           };
//
//           bool getFlag(int index) {
//               return FLAG[index];
//           };

            tipMemorie getIP()
            {
                return IP;
            }
            void setIP(tipMemorie val)
            {
                IP = val;
            }
};


