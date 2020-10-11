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
			std::string hexString = s.str();

			while(hexString.size() < 8) {
				hexString = "0" + hexString;
			}

			return hexString;
		}

	public:
		static DisassembledData* disassemble(BinaryCode* fileName);
};
