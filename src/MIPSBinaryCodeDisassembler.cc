#include "MIPSBinaryCodeDisassembler.h"

DisassembledData* MIPSBinaryCodeDisassembler::disassemble(BinaryCode* binaryCode) {
	std::cout << std::endl;
	DisassembledData* disassembledData = NULL;

	int binaryLength = binaryCode->getLength();

	std::vector<int>::iterator iterator = binaryCode->getInstructionIterator();
	std::vector<int>::iterator lastIterator = binaryCode->getLastInstructionIterator();

	int index = 0;

	for (; iterator != lastIterator ; ++iterator) {
		std::string instructionString = "inst " + std::to_string(index) + ": ";

		int instruction = *iterator;

		std::string hexString = MIPSBinaryCodeDisassembler::getHexString(instruction);

		instructionString = instructionString + hexString + " ";
	
		std::string is = InstructionStringFactory::createInstructionString(instruction);

		std::cout << instructionString << std::endl;

		index++;
	}

	return disassembledData;
};
