#include "FileManager.h"

BinaryCode* FileManager::readBinFile(char* fileName) {
    std::ifstream inFile(fileName, std::ifstream::binary);

    if (inFile.is_open()) {
        BinaryCode* binaryCode = new BinaryCode();

        while(!inFile.eof()) {
            int instruction;
            inFile.read((char *) &instruction, sizeof(int));
            binaryCode->pushInstruction(instruction);
        }

        inFile.close();
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
