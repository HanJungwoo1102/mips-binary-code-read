#include "InstructionStringFactory.h"


std::array<Operation, R_FORMAT_OPERATION_SIZE> InstructionStringFactory::rFormatOperationArray = {
	Operation("add", 0, 2),
	Operation("add", 0, 2),
	Operation("add", 0, 2),
	Operation("add", 0, 2),
};

std::array<Operation, I_FORMAT_OPERATION_SIZE> InstructionStringFactory::iFormatOperationArray = {
	Operation("add", 4),
};

std::array<Operation, J_FORMAT_OPERATION_SIZE> InstructionStringFactory::jFormatOperationArray = {
	Operation("add", 1),
};

int InstructionStringFactory::getOp(int inst) {
	return ((inst & 0xF8000000) >> 27) & 0x0000001F;
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

};

std::string InstructionStringFactory::getIFormatInstructionString(int instruction) {

};

std::string InstructionStringFactory::getJFormatInstructionString(int instruction) {

};
