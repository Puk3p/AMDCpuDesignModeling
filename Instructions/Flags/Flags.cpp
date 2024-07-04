#include "Flags.h"

void Flags::setZeroFlag(bool val)
{
    zeroFlag = val;//de revazut
}

void Flags::setEqualFlag(bool val)
{
    equalFlag = val;
}

void Flags::setGreaterFlag(bool val)
{
    greaterFlag = val;
}

bool Flags::getZeroFlag()
{
    return zeroFlag;
}

bool Flags::getEqualFlag()
{
    return equalFlag;
}

bool Flags::getGreaterFlag()
{
    return greaterFlag;
}