#include <iostream>

#include "BinaryCode.h"
#include "DisassembledData.h"
#include "InstructionStringFactory.h"

class MIPSBinaryCodeDisassembler {
	private:

	public:
		static DisassembledData* disassemble(BinaryCode* fileName);
};
