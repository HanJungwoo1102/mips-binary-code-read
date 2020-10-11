#include "InstructionStringFactory.h"

std::array<Operation, R_FORMAT_OPERATION_SIZE> InstructionStringFactory::rFormatOperationArray = {
	Operation("add", 0, 0B100000),
	Operation("addu", 0, 0B100001),
	Operation("and", 0, 0B100100),
	Operation("nor", 0, 0B100111),
	Operation("or", 0, 0B100101),
	Operation("sll", 0, 0B000000),
	Operation("slt", 0, 0B101010),
	Operation("sltu", 0, 0B101011),
	Operation("srl", 0, 0B000010),
	Operation("sub", 0, 0B100010),
	Operation("subu", 0, 0B100011),
	Operation("div", 0, 0B100111),
	Operation("divu", 0, 0B011011),
	Operation("jr", 0, 0B001000),
	Operation("jalr", 0, 0B001001),
	Operation("mfhi", 0, 0B010000),
	Operation("mthi", 0, 0B010001),
	Operation("mflo", 0, 0B010010),
	Operation("mtlo", 0, 0B010011),
	Operation("mult", 0, 0B011000),
	Operation("multu", 0, 0B011001),
	Operation("sra", 0, 0B000011),
	Operation("srav", 0, 0B000111),
	Operation("srlv", 0, 0B000110),
	Operation("syscall", 0, 0B001100),
	Operation("xor", 0, 0B100110),
};

std::array<Operation, I_FORMAT_OPERATION_SIZE> InstructionStringFactory::iFormatOperationArray = {
	Operation("addi", 0B001000),
	Operation("addiu", 0B001001),
	Operation("andi", 0B001100),
	Operation("beq", 0B000100),
	Operation("bne", 0B000101),
	Operation("lui", 0B001111),
	Operation("lw", 0B100011),
	Operation("ori", 0B001101),
	Operation("slti", 0B001010),
	Operation("sltiu", 0B001011),
	Operation("sw", 0B101011),
};

std::array<Operation, J_FORMAT_OPERATION_SIZE> InstructionStringFactory::jFormatOperationArray = {
	Operation("j", 0B000010),
	Operation("jal", 0B000011),
};

bool InstructionStringFactory::isRFormatInstuction(int op) {
	if (op == 0) return true;
	else return false;
};

bool InstructionStringFactory::isIFormatInstuction(int op) {
	std::array<Operation, I_FORMAT_OPERATION_SIZE>::iterator iterator = InstructionStringFactory::iFormatOperationArray.begin();
	std::array<Operation, I_FORMAT_OPERATION_SIZE>::iterator endIterator = InstructionStringFactory::iFormatOperationArray.end();

	for(; iterator != endIterator; iterator++) {
		Operation operation = *iterator;

		int opValue = operation.getOpValue();
		if (op == opValue) {
			return true;
		}
	}
	return false;
};

bool InstructionStringFactory::isJFormatInstuction(int op) {
	std::array<Operation, J_FORMAT_OPERATION_SIZE>::iterator iterator = InstructionStringFactory::jFormatOperationArray.begin();
	std::array<Operation, J_FORMAT_OPERATION_SIZE>::iterator endIterator = InstructionStringFactory::jFormatOperationArray.end();

	for(; iterator != endIterator; iterator++) {
		Operation operation = *iterator;

		int opValue = operation.getOpValue();

		if (op == opValue) {
			return true;
		}
	}
	return false;
};

std::string InstructionStringFactory::getRFormatInstructionString(int instruction) {
	int op = InstructionStringFactory::getOp(instruction);
	int rs = InstructionStringFactory::getRs(instruction);
	int rt = InstructionStringFactory::getRt(instruction);
	int rd = InstructionStringFactory::getRd(instruction);
	int shampt = InstructionStringFactory::getShamt(instruction);
	int funct = InstructionStringFactory::getFunct(instruction);
	std::string operationName = InstructionStringFactory::getRFormatOperationName(funct);

	std::string instructionString =
		operationName
		+ " $" + std::to_string(rd)
		+ " $" + std::to_string(rs)
		+ " $" + std::to_string(rt)
		+ " " + std::to_string(shampt);

	return instructionString;
};

std::string InstructionStringFactory::getIFormatInstructionString(int instruction) {
	int op = InstructionStringFactory::getOp(instruction);
	int rs = InstructionStringFactory::getRs(instruction);
	int rt = InstructionStringFactory::getRt(instruction);
	int immediate = InstructionStringFactory::getImmediate(instruction);
	std::string operationName = InstructionStringFactory::getIFormatOperationName(op);

	std::string instructionString =
		operationName
		+ " $" + std::to_string(rs)
		+ " $" + std::to_string(rt)
		+ " " + std::to_string(immediate);

	return instructionString;
};

std::string InstructionStringFactory::getJFormatInstructionString(int instruction) {
	int op = InstructionStringFactory::getOp(instruction);
	int tartgetAddress = InstructionStringFactory::getTargetAddress(instruction);

	std::string operationName = InstructionStringFactory::getJFormatOperationName(op);

	std::string instructionString =
		operationName
		+ " " + std::to_string(tartgetAddress);

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
	return ((inst & 0x0000FFFF) >> 0) & 0x0000FFFF;
};

int InstructionStringFactory::getTargetAddress(int inst) {
	return ((inst & 0x03FFFFFF) >> 0) & 0x03FFFFFF;
};

std::string InstructionStringFactory::getRFormatOperationName(int funct) {
	std::array<Operation, R_FORMAT_OPERATION_SIZE>::iterator iterator = InstructionStringFactory::rFormatOperationArray.begin();
	std::array<Operation, R_FORMAT_OPERATION_SIZE>::iterator endIterator = InstructionStringFactory::rFormatOperationArray.end();

	for(; iterator != endIterator; iterator++) {
		Operation operation = *iterator;

		int functValue = operation.getFunctValue();

		if (funct == functValue) {
			return operation.getName();
		}
	}
};

std::string InstructionStringFactory::getIFormatOperationName(int op) {
	std::array<Operation, I_FORMAT_OPERATION_SIZE>::iterator iterator = InstructionStringFactory::iFormatOperationArray.begin();
	std::array<Operation, I_FORMAT_OPERATION_SIZE>::iterator endIterator = InstructionStringFactory::iFormatOperationArray.end();

	for(; iterator != endIterator; iterator++) {
		Operation operation = *iterator;

		int opValue = operation.getOpValue();

		if (op == opValue) {
			return operation.getName();
		}
	}
};

std::string InstructionStringFactory::getJFormatOperationName(int op) {
	std::array<Operation, J_FORMAT_OPERATION_SIZE>::iterator iterator = InstructionStringFactory::jFormatOperationArray.begin();
	std::array<Operation, J_FORMAT_OPERATION_SIZE>::iterator endIterator = InstructionStringFactory::jFormatOperationArray.end();

	for(; iterator != endIterator; iterator++) {
		Operation operation = *iterator;

		int opValue = operation.getOpValue();

		if (op == opValue) {
			return operation.getName();
		}
	}
};
