#include <iostream>
#include "Operator.h"
#include "Register.h"

class Instruction {
	private:
		Operator op;
		virtual std::string getTailString();

	protected:
		Instruction();

	public:
		std::string toAssembledString();
};

class RFormatInstruction : public Instruction {
	private:
		Register rs;
		Register rp;
		Register rd;
		char shamt;
		char funct;
		std::string getTailString() {
			return "";
		};
};

class IFormatInstruction : public Instruction {
	private:
		Register rs;
		Register rt;
		int imm;
		std::string getTailString();
};

class JFormatInstruction : public Instruction {
	private:
		int jumpTarget;
		std::string getTailString();
};
