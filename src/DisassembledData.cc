#include "DisassembledData.h"

DisassembledData::DisassembledData(std::string str) {
    this->disassembledDataString = str;
}

std::string DisassembledData::getDisassembledDataString() {
    return this->disassembledDataString;
};