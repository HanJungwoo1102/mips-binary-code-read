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

        std::string binFileNameString = std::string(binFileName);
        int extensionIndex = binFileNameString.find(".bin");
        std::string txtFileNameString = binFileNameString.replace(extensionIndex, 4, ".txt");
        char * txtFileName = new char[txtFileNameString.size() + 1];
        std::copy(txtFileNameString.begin(), txtFileNameString.end(), txtFileName);
        txtFileName[txtFileNameString.size()] = '\0'; // 스트링 끝에 0을 추가해주는 거 잊지 마세요

        std::cout << "[3] Write: " << txtFileName << std::endl;

        try {
            FileManager::writeTxtFile(txtFileName, disassembledData);
            std::cout << " - (success)" << std::endl;
        } catch(int error) {
            std::cout << " - (fail)" << std::endl;
            return 0;
        }

        delete[] txtFileName;
        
        std::cout << "Success!!" << std::endl;
    } else {
        std::cout << "Please input your file name" << std::endl;
    }
    return 0;
}
