#include "MIPSBinaryCodeDisassembler.h"

int MIPSBinaryCodeDisassembler::WORD_BIT_COUNT = 32;

char* MIPSBinaryCodeDisassembler::disassemble(char* binary) {
	int binaryLength = strlen(binary);
	int wordBitCount = WORD_BIT_COUNT;

	for (int instructionIndex = 0; instructionIndex * wordBitCount < binaryLength; instructionIndex++) {
	}
	return binary;
}