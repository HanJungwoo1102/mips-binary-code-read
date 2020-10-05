#include <iostream>
#include <fstream>

class FileManager {
	public:
		static void readBinFile(char* fileName, char* &buffer);
		static void writeTxtFile(char* fileName, char* text);
};
