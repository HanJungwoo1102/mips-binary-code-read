#ifndef BINARY_CODE_HEADER
#define BINARY_CODE_HEADER

#include <vector>

class BinaryCode {
    private:
        std::vector<int> binaryCode;
    public:
        BinaryCode();
        std::vector<int>::iterator getInstructionIterator();
        std::vector<int>::iterator getLastInstructionIterator();
        int getLength();
        void pushInstruction(int instruction);
};

#endif