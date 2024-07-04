#pragma once
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include "/home/agaio/CLionProjects/ITMARATHON_AMD/CPU/Memory.h"
#include "/home/agaio/CLionProjects/ITMARATHON_AMD/Instructions/Base/Pop.h"
#include "Base/Add.h"
#include "Base/Sub.h"
#include "Base/Mov.h"
#include "Base/Mul.h"
#include "Base/Div.h"
#include "Base/Cmp.h"
#include "Base/Jmp.h"
#include "Base/Je.h"
#include "Base/Jl.h"
#include "Base/Jg.h"
#include "Base/Jz.h"
#include "Base/Call.h"
#include "Base/Ret.h"
#include "Base/End_sim.h"
#include "Base/Push.h"

using tipMemorie = u_int16_t;

class OPCODES {
    public:
        OPCODES();
        int toInt(std::string opcode);
        //Add addObject;
        Mul mulObject;
        Div divObject;
        Cmp cmpObject;
        Jmp jmpObject;
        Je jeObject;
        Jl jlObject;
        Jg jgObject;
        Jz jzObject;
        Push pushObject;
        Sub subObject;
        Mov movObject;
        Pop popObject;
        Call callObject;

        std::map<int, std::function<void(tipMemorie, tipMemorie&)>> INSTRUCTIONS_12P_1DEST = {
                //{1, std::bind(&Add::add, &addObject, std::placeholders::_1, std::placeholders::_2)},
                {2, std::bind(&Sub::sub, &subObject, std::placeholders::_1, std::placeholders::_2)},
                {3, std::bind(&Mov::mov, &movObject, std::placeholders::_1, std::placeholders::_2)}
        };

        std::map<int, std::function<void(tipMemorie, tipMemorie)>> INSTRUCTIONS_2P_0DEST = {
                {4, std::bind(&Mul::mul, &mulObject, std::placeholders::_1, std::placeholders::_2)},
                {5, std::bind(&Div::div, &divObject, std::placeholders::_1, std::placeholders::_2)},
                {6, std::bind(&Cmp::cmp, &cmpObject, std::placeholders::_1, std::placeholders::_2)}
        };

        std::map<int, std::function<void(tipMemorie)>> INSTRUCTIONS_1P = {
                {7, std::bind(&Jmp::jmp, &jmpObject, std::placeholders::_1)},
                {9, std::bind(&Je::je, &jeObject, std::placeholders::_1)},
                {10, std::bind(&Jl::jl, &jlObject, std::placeholders::_1)},
                {11, std::bind(&Jg::jg, &jgObject, std::placeholders::_1)},
                {12, std::bind(&Jz::jz, &jzObject, std::placeholders::_1)},
                {16, std::bind(&Push::push, &pushObject, std::placeholders::_1)},
                {13, std::bind(&Call::call, &callObject, std::placeholders::_1)},
                {17, std::bind(&Pop::pop, &popObject, std::placeholders::_1)}
        };
};