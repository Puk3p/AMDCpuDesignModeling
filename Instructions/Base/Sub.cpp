//
// Created by agaio on 27.04.2024.
//

#include "Sub.h"
#include "/home/agaio/CLionProjects/ITMARATHON_AMD/CPU/CPU.h"


void Sub::sub(tipMemorie src2,tipMemorie &dest)
{
    dest=dest-src2;
    if(dest==0)
        flags.setZeroFlag(1);
        // Flags::setZeroFlag(1);
    else
        flags.setZeroFlag(0);
        // Flags::setZeroFlag(0);
    //to do: chestiile ilegale
}