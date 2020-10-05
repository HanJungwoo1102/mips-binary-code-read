#include <iostream>
#include "InstructionFactory.h"

class MIPSBinaryCodeDisassembler {
	private:
		static int WORD_BIT_COUNT;
	public:
		static char* disassemble(char* fileName);
};
