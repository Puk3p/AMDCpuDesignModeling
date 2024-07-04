//
// Created by agaio on 27.04.2024.
//

#include "Cmp.h"
// #include "../Flags/Flags.h"
#include "GenericInstruction.h"

void Cmp::cmp(tipMemorie src1,tipMemorie src2)
{
    if(src1>src2) {
        flags.setGreaterFlag(1);
        flags.setZeroFlag(0);

        flags.setEqualFlag(0);
    }
    if(src1<src2) {
        flags.setGreaterFlag(0);
        flags.setZeroFlag(0);
        flags.setEqualFlag(0);
    }
    if(src1==src2) {
        flags.setGreaterFlag(0);
        flags.setZeroFlag(0);
        //setLessFlag(0);
        flags.setEqualFlag(1);
    }
    if(src1==src2 && src1==0) {
        flags.setGreaterFlag(0);
        flags.setZeroFlag(0);
        //setLessFlag(0);
        flags.setEqualFlag(1);
    }
}