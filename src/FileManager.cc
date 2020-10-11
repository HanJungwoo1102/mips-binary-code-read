#include "FileManager.h"

BinaryCode* FileManager::readBinFile(char* fileName) {
    std::ifstream inFile(fileName, std::ifstream::binary|std::ifstream::ate);
    int idx = 0;
    if (inFile.is_open()) {
        BinaryCode* binaryCode = new BinaryCode();

        char* buffer;
        long size = inFile.tellg();
        inFile.seekg(0, std::ifstream::beg);

        buffer = new char[size];

        inFile.read(buffer, size);
        inFile.close();

        for(int index = 0; index < size / 4; index++) {
            int instruction;

            char* is = (char *) &instruction;

            for (int i = 0; i < 4; i++) {
                is[3 - i] = buffer[index * 4 + i];
            }

            binaryCode->pushInstruction(instruction);
        }
        return binaryCode;
    } else {
        throw;
    }
}

void FileManager::writeTxtFile(char* fileName, DisassembledData* disassembledData) {
    std::string text = disassembledData->getDisassembledDataString();

    std::cout << text << std::endl;

    std::ofstream outFile(fileName);

    if (outFile.is_open()) {
        outFile.write(text.c_str(), text.length());
        outFile.close();
    } else {
        throw;
    }
}
