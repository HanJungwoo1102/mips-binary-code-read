#include "Instruction.h"

std::string Instruction::toAssembledString() {
    return this->op.getName() + this->getTailString(); 
};
