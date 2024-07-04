#pragma once
#include <fstream>
#include <iostream>
#include <vector>

void writeMemory(const std::string& fileName);
int hexadecimalToDecimal(std::string hexVal);
int opcodeDecoder(int val);
int src1Decoder(int val);
int src2Decoder(int val);

