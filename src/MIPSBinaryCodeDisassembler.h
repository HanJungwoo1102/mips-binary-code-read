#include <iostream>
#include <sstream>

#include "BinaryCode.h"
#include "DisassembledData.h"
#include "InstructionStringFactory.h"

class MIPSBinaryCodeDisassembler {
	private:
		static std::string getHexString(int i) {
			std::stringstream s;
			s << std::hex << i;
			return s.str();
		}

	public:
		static DisassembledData* disassemble(BinaryCode* fileName);
};
