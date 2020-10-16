#include "InstructionStringFactory.h"

// rtype
/*
	mode9: rs rt rd shamt
	mode0: $3, $1, $2
	mode1: $3, $2, 4
	mode2: $1
	mode3: $1, $2
	mode4: $3
	mode5:
	mode6: $3, $2, $1
	mode7: $3, $1
*/

// itype
/* rs rt i
	mode0: $1, 3($2)
	mode1: $1, $2, 3
	mode2: $2, $1, 3
	mode3: $1, 3
*/

std::array<Operation, OPERATION_SIZE> InstructionStringFactory::operationArray = {
	Operation("add", 0, 0B100000, OperationType::R_TYPE, 0),
	Operation("addu", 0, 0B100001, OperationType::R_TYPE, 0),
	Operation("and", 0, 0B100100, OperationType::R_TYPE, 0),
	Operation("nor", 0, 0B100111, OperationType::R_TYPE, 0),
	Operation("or", 0, 0B100101, OperationType::R_TYPE, 0),
	Operation("xor", 0, 0B100110, OperationType::R_TYPE, 0),
	Operation("sub", 0, 0B100010, OperationType::R_TYPE, 0),
	Operation("subu", 0, 0B100011, OperationType::R_TYPE, 0),
	Operation("sll", 0, 0B000000, OperationType::R_TYPE, 1),
	Operation("slt", 0, 0B101010, OperationType::R_TYPE, 1),
	Operation("sltu", 0, 0B101011, OperationType::R_TYPE, 1),
	Operation("srl", 0, 0B000010, OperationType::R_TYPE, 1),
	Operation("jr", 0, 0B001000, OperationType::R_TYPE, 2),
	Operation("mfhi", 0, 0B010000, OperationType::R_TYPE, 2),
	Operation("mthi", 0, 0B010001, OperationType::R_TYPE, 2),
	Operation("div", 0, 0B011010, OperationType::R_TYPE, 3),
	Operation("divu", 0, 0B011011, OperationType::R_TYPE, 3),
	Operation("mult", 0, 0B011000, OperationType::R_TYPE, 3),
	Operation("multu", 0, 0B011001, OperationType::R_TYPE, 3),
	Operation("mflo", 0, 0B010010, OperationType::R_TYPE, 4),
	Operation("mtlo", 0, 0B010011, OperationType::R_TYPE, 4),
	Operation("syscall", 0, 0B001100, OperationType::R_TYPE, 5),
	Operation("sra", 0, 0B000011, OperationType::R_TYPE, 6),
	Operation("srav", 0, 0B000111, OperationType::R_TYPE, 6),
	Operation("srlv", 0, 0B000110, OperationType::R_TYPE, 6),
	Operation("jalr", 0, 0B001001, OperationType::R_TYPE, 7),
	Operation("sw", 0B101011, OperationType::I_TYPE, 0),
	Operation("sb", 0B101000, OperationType::I_TYPE, 0),
	Operation("lb", 0B100000, OperationType::I_TYPE, 0),
	Operation("lbu", 0B100100, OperationType::I_TYPE, 0),
	Operation("lh", 0B100001, OperationType::I_TYPE, 0),
	Operation("lhu", 0B100101, OperationType::I_TYPE, 0),
	Operation("lw", 0B100011, OperationType::I_TYPE, 0),
	Operation("sh", 0B101001, OperationType::I_TYPE, 0),
	Operation("addi", 0B001000, OperationType::I_TYPE, 1),
	Operation("addiu", 0B001001, OperationType::I_TYPE, 1),
	Operation("andi", 0B001100, OperationType::I_TYPE, 1),
	Operation("ori", 0B001101, OperationType::I_TYPE, 1),
	Operation("xori", 0B001110, OperationType::I_TYPE, 1),
	Operation("slti", 0B001010, OperationType::I_TYPE, 1),
	Operation("sltiu", 0B001011, OperationType::I_TYPE, 1),
	Operation("beq", 0B000100, OperationType::I_TYPE, 2),
	Operation("bne", 0B000101, OperationType::I_TYPE, 2),
	Operation("lui", 0B001111, OperationType::I_TYPE, 3),
	Operation("j", 0B000010, OperationType::J_TYPE, 0),
	Operation("jal", 0B000011, OperationType::J_TYPE, 0),
};

std::string InstructionStringFactory::createInstructionString(int instruction) {
	int op = InstructionStringFactory::getOp(instruction);
	int funct = InstructionStringFactory::getFunct(instruction);

	Operation* operation = NULL;
	int idx = InstructionStringFactory::getOperation(instruction);
	Operation* operationArray = InstructionStringFactory::operationArray.data();
	operation = &operationArray[idx];

	if (operation != NULL) {
		OperationType operationType = operation->getType();
		int mode = operation->getMode();
		std::string operationName = operation->getName();
		if (operationType == OperationType::R_TYPE) {
			int rs = InstructionStringFactory::getRs(instruction);
			int rt = InstructionStringFactory::getRt(instruction);
			int rd = InstructionStringFactory::getRd(instruction);
			int shamt = InstructionStringFactory::getShamt(instruction);
			if (mode == 0) {
				return InstructionStringFactory::getRFormatInstructionString0(operationName, rs, rt, rd, shamt);
			} else if (mode == 1) {
				return InstructionStringFactory::getRFormatInstructionString1(operationName, rs, rt, rd, shamt);
			} else if (mode == 2) {
				return InstructionStringFactory::getRFormatInstructionString2(operationName, rs, rt, rd, shamt);
			} else if (mode == 3) {
				return InstructionStringFactory::getRFormatInstructionString3(operationName, rs, rt, rd, shamt);
			} else if (mode == 4) {
				return InstructionStringFactory::getRFormatInstructionString4(operationName, rs, rt, rd, shamt);
			} else if (mode == 5) {
				return InstructionStringFactory::getRFormatInstructionString5(operationName, rs, rt, rd, shamt);
			} else if (mode == 6) {
				return InstructionStringFactory::getRFormatInstructionString6(operationName, rs, rt, rd, shamt);
			} else if (mode == 7) {
				return InstructionStringFactory::getRFormatInstructionString7(operationName, rs, rt, rd, shamt);
			} else {
				return InstructionStringFactory::getRFormatInstructionString(operationName, rs, rt, rd, shamt);
			}
		} else if (operationType == OperationType::I_TYPE) {
			int rs = InstructionStringFactory::getRs(instruction);
			int rt = InstructionStringFactory::getRt(instruction);
			int immediate = InstructionStringFactory::getImmediate(instruction);
			if (mode == 0) {
				return InstructionStringFactory::getIFormatInstructionString0(operationName, rs, rt, immediate);
			} else if (mode == 1) {
				return InstructionStringFactory::getIFormatInstructionString1(operationName, rs, rt, immediate);
			} else if (mode == 2) {
				return InstructionStringFactory::getIFormatInstructionString2(operationName, rs, rt, immediate);
			} else if (mode == 3) {
				return InstructionStringFactory::getIFormatInstructionString3(operationName, rs, rt, immediate);
			} else {
				return InstructionStringFactory::getIFormatInstructionString(operationName, rs, rt, immediate);
			}
		} else if (operationType == OperationType::J_TYPE) {
			int targetAddress = InstructionStringFactory::getTargetAddress(instruction);
			if (mode == 0) {
				return InstructionStringFactory::getJFormatInstructionString0(operationName, targetAddress);
			} else {
				return InstructionStringFactory::getJFormatInstructionString(operationName, targetAddress);
			}
		}
	}
	return "unknown instruction";
};

int InstructionStringFactory::getOperation(int instruction) {
	Operation* operationArray = InstructionStringFactory::operationArray.data();
	std::array<Operation, OPERATION_SIZE>::iterator iterator = InstructionStringFactory::operationArray.begin();
	std::array<Operation, OPERATION_SIZE>::iterator endIterator = InstructionStringFactory::operationArray.end();

	int index = 0;
	for(; iterator != endIterator; iterator++) {
		Operation operation = operationArray[index];
		if (operation.getOpValue() == InstructionStringFactory::getOp(instruction)) {
			if (operation.getType() == OperationType::R_TYPE) {
				if (operation.getFunctValue() == InstructionStringFactory::getFunct(instruction)) {
					return index;
				}
			} else {
				return index;
			}
		}
		index += 1;
	}
	return NULL;
}

std::string InstructionStringFactory::getRFormatInstructionString(std::string operationName, int rs, int rt, int rd, int shamt) {
	std::string instructionString =
		operationName
		+ " " + std::to_string(rs)
		+ " " + std::to_string(rt)
		+ " " + std::to_string(rd)
		+ " " + std::to_string(shamt);
	
	return instructionString;
};

std::string InstructionStringFactory::getRFormatInstructionString0(std::string operationName, int rs, int rt, int rd, int shamt) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rd)
		+ ", $" + std::to_string(rs)
		+ ", $" + std::to_string(rt);

	return instructionString;
};

std::string InstructionStringFactory::getRFormatInstructionString1(std::string operationName, int rs, int rt, int rd, int shamt) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rd)
		+ ", $" + std::to_string(rt)
		+ ", " + std::to_string(shamt);

	return instructionString;
};

std::string InstructionStringFactory::getRFormatInstructionString2(std::string operationName, int rs, int rt, int rd, int shamt) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rs);

	return instructionString;
};

std::string InstructionStringFactory::getRFormatInstructionString3(std::string operationName, int rs, int rt, int rd, int shamt) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rs)
		+ ", $" + std::to_string(rt);

	return instructionString;
};

std::string InstructionStringFactory::getRFormatInstructionString4(std::string operationName, int rs, int rt, int rd, int shamt) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rd);

	return instructionString;
};

std::string InstructionStringFactory::getRFormatInstructionString5(std::string operationName, int rs, int rt, int rd, int shamt) {
	std::string instructionString =
		operationName;

	return instructionString;
};

std::string InstructionStringFactory::getRFormatInstructionString6(std::string operationName, int rs, int rt, int rd, int shamt) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rd)
		+ ", $" + std::to_string(rt)
		+ ", $" + std::to_string(rs);

	return instructionString;
};

std::string InstructionStringFactory::getRFormatInstructionString7(std::string operationName, int rs, int rt, int rd, int shamt) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rd)
		+ ", $" + std::to_string(rs);

	return instructionString;
};

std::string InstructionStringFactory::getIFormatInstructionString(std::string operationName, int rs, int rt, int immediate) {
	std::string instructionString =
		operationName
		+ " " + std::to_string(rs)
		+ " " + std::to_string(rt)
		+ " " + std::to_string(immediate);

	return instructionString;
};

std::string InstructionStringFactory::getIFormatInstructionString0(std::string operationName, int rs, int rt, int immediate) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rt)
		+ ", " + std::to_string(immediate)
		+ "($" + std::to_string(rs)
		+ ")";

	return instructionString;
};

std::string InstructionStringFactory::getIFormatInstructionString1(std::string operationName, int rs, int rt, int immediate) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rt)
		+ ", $" + std::to_string(rs)
		+ ", " + std::to_string(immediate);

	return instructionString;
};

std::string InstructionStringFactory::getIFormatInstructionString2(std::string operationName, int rs, int rt, int immediate) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rs)
		+ ", $" + std::to_string(rt)
		+ ", " + std::to_string(immediate);

	return instructionString;
};

std::string InstructionStringFactory::getIFormatInstructionString3(std::string operationName, int rs, int rt, int immediate) {
	std::string instructionString =
		operationName
		+ " $" + std::to_string(rt)
		+ ", " + std::to_string(immediate);

	return instructionString;
};

std::string InstructionStringFactory::getJFormatInstructionString(std::string operationName, int targetAddress) {
	std::string instructionString =
		operationName
		+ " " + std::to_string(targetAddress);

	return instructionString;
};

std::string InstructionStringFactory::getJFormatInstructionString0(std::string operationName, int targetAddress) {
	std::string instructionString =
		operationName
		+ " " + std::to_string(targetAddress);

	return instructionString;
};

int InstructionStringFactory::getOp(int inst) {
	return ((inst & 0xFC000000) >> 26) & 0x0000003F;
};

int InstructionStringFactory::getRs(int inst) {
	return ((inst & 0x03E00000) >> 21) & 0x0000001F;
};

int InstructionStringFactory::getRt(int inst) {
	return ((inst & 0x001F0000) >> 16) & 0x0000001F;
};

int InstructionStringFactory::getRd(int inst) {
	return ((inst & 0x0000F800) >> 11) & 0x0000001F;
};

int InstructionStringFactory::getShamt(int inst) {
	return ((inst & 0x000007C0) >> 6) & 0x0000001F;
};

int InstructionStringFactory::getFunct(int inst) {
	return (inst & 0x0000003F) & 0x0000003F;
};

int InstructionStringFactory::getImmediate(int inst) {
	int a = ((inst & 0x0000FFFF) >> 0) & 0x0000FFFF;
	if (a > 32767) {
		return a - 65536;
	}
	return a;
};

int InstructionStringFactory::getTargetAddress(int inst) {
	return ((inst & 0x03FFFFFF) >> 0) & 0x03FFFFFF;
};
