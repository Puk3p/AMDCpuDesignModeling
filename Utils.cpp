#include "Utils.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "CPU/AccesMemory.h"

Memory memory;

int hexadecimalToDecimal(std::string hexVal)
{
    int len = hexVal.size();
    int base = 1;

    int dec_val = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (int(hexVal[i]) - 48) * base;
            base = base * 16;
        } else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (int(hexVal[i]) - 55) * base;
            base = base * 16;
        }

    }
    return dec_val;
}



//std::vector<std::string> writeMemory(const std::string& fileName) {
//    std::vector<std::string> vector;
//    std::string line;
//    std::ifstream file(fileName);
//
//    if (file.is_open()) {
//        while (std::getline(file, line)) {
//            if (!line.empty()) { // && line[0] != '#'
//            vector.push_back(line);
//            }
//        }
//    }
//
//    return vector;
//}

int opcodeDecoder(int val) {
    return val >> 10;
}

int src1Decoder(int val) {
    return (val&0x03E0) >> 5;
}

int src2Decoder(int val)
{
    return (val&0x001F);
}


void writeMemory(const std::string& fileName) {
    std::vector<std::string> vector;
    std::string line;
    std::ifstream file(fileName);

    int CURRENT_INDEX = 0;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (!line.empty()) {
                if (line[0] == '#') {
                    CURRENT_INDEX = hexadecimalToDecimal(line.substr(1, line.size() - 1));
                } else {
                    AccesMemory::store(CURRENT_INDEX, hexadecimalToDecimal(line));
                    CURRENT_INDEX += 0xF;
                }
            }
        }
    }
}