#pragma once

// FLAGS[0] = Z = Zero (the result of an operation is zero)
// FLAGS[1] = E = Equal (2 parameters are equal)
// FLAGS[2] = G = Greater (parameter 1 > parameter 2)

// L (parametru 1 < parametru 2) dedus din (not E && not G)


class Flags {
        bool zeroFlag = 0;
        bool greaterFlag = 0;
        bool equalFlag = 0;
    public:
        Flags()
        {
            zeroFlag = 0;
            greaterFlag = 0;
            equalFlag = 0;
        }
        void setZeroFlag(bool val);
        void setEqualFlag(bool val);
        void setGreaterFlag(bool val);
        bool getZeroFlag();
        bool getEqualFlag();
        bool getGreaterFlag();
};
