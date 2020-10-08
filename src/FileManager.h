#include <iostream>
#include <fstream>

#include "BinaryCode.h"
#include "DisassembledData.h"

class FileManager {
	public:
		static BinaryCode* readBinFile(char* fileName);
		static void writeTxtFile(char* fileName, DisassembledData* disassembledData);
};
