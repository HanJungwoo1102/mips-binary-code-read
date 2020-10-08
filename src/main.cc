#include <iostream>

#include "MIPSBinaryCodeDisassembler.h"
#include "FileManager.h"

int main(int argc, char **argv) {
    if (argc == 2) {
        char* binFileName = argv[1];
        BinaryCode* binaryCode = NULL;
        DisassembledData* disassembledData = NULL;

        std::cout << "[1] Read: " << binFileName;
        try {
            binaryCode = FileManager::readBinFile(binFileName);
            std::cout << " - (success)" << std::endl;
        } catch(int error) {
            std::cout << " - (fail)" << std::endl;
            return 0;
        }
        std::cout << "[2] Disassemble";
        try {
            disassembledData = MIPSBinaryCodeDisassembler::disassemble(binaryCode);
            std::cout << " - (success)" << std::endl;
        } catch(int error) {
            std::cout << " - (fail)" << std::endl;
            return 0;
        }
        std::cout << "[3] Write a file" << std::endl;
        try {
            FileManager::writeTxtFile("test.txt", disassembledData);
            std::cout << " - (success)" << std::endl;
        } catch(int error) {
            std::cout << " - (fail)" << std::endl;
            return 0;
        }
        
        std::cout << "Success!!" << std::endl;
    } else {
        std::cout << "Please input your file name" << std::endl;
    }
    return 0;
}
