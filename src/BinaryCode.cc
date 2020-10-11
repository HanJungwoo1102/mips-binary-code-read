#include "BinaryCode.h"
#include <iostream>
BinaryCode::BinaryCode() {

};

std::vector<int>::iterator BinaryCode::getInstructionIterator() {
    return this->binaryCode.begin();
}

std::vector<int>::iterator BinaryCode::getLastInstructionIterator() {
    return this->binaryCode.end();
}

void BinaryCode::pushInstruction(int instruction) {
    this->binaryCode.push_back(instruction);
}