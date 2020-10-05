#include "FileManager.h"

void FileManager::readBinFile(char* fileName, char* &buffer) {
    std::ifstream inFile(fileName, std::ifstream::in | std::ifstream::binary);

    if (inFile.is_open()) {
        inFile.seekg(0, std::ifstream::end);
        size_t length = inFile.tellg();
        inFile.seekg(0, std::ifstream::beg);
        buffer = new char[length];
        inFile.read(buffer, length);
        inFile.close();
    } else {
        throw;
    }
}

void FileManager::writeTxtFile(char* fileName, char* text) {
    std::cout << text << std::endl;

    std::ofstream outFile(fileName);

    if (outFile.is_open()) {
        outFile.write(text, strlen(text));
        outFile.close();
    } else {
        throw;
    }
}
