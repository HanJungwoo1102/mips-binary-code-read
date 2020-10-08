#include "MIPSBinaryCodeDisassembler.h"

DisassembledData* MIPSBinaryCodeDisassembler::disassemble(BinaryCode* binaryCode) {
	std::cout << std::endl;
	DisassembledData* disassembledData = NULL;

	int binaryLength = binaryCode->getLength();

	std::vector<int>::iterator iterator = binaryCode->getInstructionIterator();
	std::vector<int>::iterator lastIterator = binaryCode->getLastInstructionIterator();


	for (; iterator != lastIterator ; ++iterator){
        std::cout << std::hex << *iterator << std::endl;
    }

	return disassembledData;
};