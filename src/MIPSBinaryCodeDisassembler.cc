#include "MIPSBinaryCodeDisassembler.h"

DisassembledData* MIPSBinaryCodeDisassembler::disassemble(BinaryCode* binaryCode) {
	std::vector<int>::iterator iterator = binaryCode->getInstructionIterator();
	std::vector<int>::iterator lastIterator = binaryCode->getLastInstructionIterator();

	int index = 0;

	std::string instructionString = "";

	for (; iterator != lastIterator ; ++iterator) {
		instructionString = instructionString + "inst " + std::to_string(index++) + ": ";

		int instruction = *iterator;

		std::string hexString = MIPSBinaryCodeDisassembler::getHexString(instruction);

		instructionString = instructionString + hexString + " ";
	
		std::string is = InstructionStringFactory::createInstructionString(instruction);

		instructionString = instructionString + is + "\n";

	}

	DisassembledData* disassembledData = new DisassembledData(instructionString);

	return disassembledData;
};
