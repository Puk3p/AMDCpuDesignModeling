#include <iostream>
#include "Add.h"


void Add::add(tipMemorie src2,tipMemorie &dest)
{
    dest=dest+src2;
    if(!dest) {
        flags.setZeroFlag(1); //todo:setZeroFlag/getZeroFl
        // Flags::setZeroFlag(1); //todo:setZeroFlag/getZeroFl
    }
    else
    {
        std::cout << "0";
        flags.setZeroFlag(0);
        // Flags::setZeroFlag(0);
    }
    //todo:ILEGAL CHESTIE
}

//Add::Add() {}
