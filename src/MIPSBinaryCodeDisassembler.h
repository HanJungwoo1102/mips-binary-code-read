#include <iostream>

#include "BinaryCode.h"
#include "DisassembledData.h"

class MIPSBinaryCodeDisassembler {
	public:
		static DisassembledData* disassemble(BinaryCode* fileName);
};
