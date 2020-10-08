#include "BinaryCode.h"

BinaryCode::BinaryCode() {

};

std::vector<int>::iterator BinaryCode::getInstructionIterator() {
    return this->binaryCode.begin();
}

std::vector<int>::iterator BinaryCode::getLastInstructionIterator() {
    return this->binaryCode.end();
}

int BinaryCode::getLength() {
    return this->binaryCode.size();
}

void BinaryCode::pushInstruction(int instruction) {
    this->binaryCode.push_back(instruction);
}