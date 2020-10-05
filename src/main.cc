#include <iostream>
#include "MIPSBinaryCodeDisassembler.h"
#include "FileManager.h"

int main(int argc, char **argv) {
    if (argc == 2) {
        char* binFileName = argv[1];
        char* binaryCode = NULL;
        char* disassembledText = NULL;

        try {
            FileManager::readBinFile(binFileName, binaryCode);
        } catch(int error) {
            std::cout << "Fail to read a file" << std::endl;
            return 0;
        }

        try {
            disassembledText = MIPSBinaryCodeDisassembler::disassemble(binaryCode);
        } catch(int error) {
            std::cout << "Fail to disassemble" << std::endl;
            return 0;
        }

        try {
            FileManager::writeTxtFile("test.txt", disassembledText);
        } catch(int error) {
            std::cout << "Fail to write a file" << std::endl;
            return 0;
        }
        
        std::cout << "Success!!" << std::endl;
    } else {
        std::cout << "Please input your file name" << std::endl;
    }
    return 0;
}
