#ifndef DISASSEMBLED_DATA_HEADER
#define DISASSEMBLED_DATA_HEADER

#include <iostream>

class DisassembledData {
    private:
        std::string disassembledDataString;

    public:
        DisassembledData(std::string disassembledDataString);
        std::string getDisassembledDataString();
};

#endif