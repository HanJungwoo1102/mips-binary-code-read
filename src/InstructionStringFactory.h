#include <iostream>
#include <array>
#include "Operation.h"

const int OPERATION_SIZE = 50;

class InstructionStringFactory {
  private:
    static std::array<Operation, OPERATION_SIZE> operationArray;

    static int getOperation(int instruction);

    static std::string getRFormatInstructionString(std::string operationName, int rs, int rt, int rd, int shamt);
    static std::string getRFormatInstructionString0(std::string operationName, int rs, int rt, int rd, int shamt);
    static std::string getRFormatInstructionString1(std::string operationName, int rs, int rt, int rd, int shamt);
    static std::string getRFormatInstructionString2(std::string operationName, int rs, int rt, int rd, int shamt);
    static std::string getRFormatInstructionString3(std::string operationName, int rs, int rt, int rd, int shamt);
    static std::string getRFormatInstructionString4(std::string operationName, int rs, int rt, int rd, int shamt);
    static std::string getRFormatInstructionString5(std::string operationName, int rs, int rt, int rd, int shamt);
    static std::string getRFormatInstructionString6(std::string operationName, int rs, int rt, int rd, int shamt);

    static std::string getIFormatInstructionString(std::string operationName, int rs, int rt, int immediate);
    static std::string getIFormatInstructionString0(std::string operationName, int rs, int rt, int immediate);
    static std::string getIFormatInstructionString1(std::string operationName, int rs, int rt, int immediate);
    static std::string getIFormatInstructionString2(std::string operationName, int rs, int rt, int immediate);
    static std::string getIFormatInstructionString3(std::string operationName, int rs, int rt, int immediate);

    static std::string getJFormatInstructionString(std::string operationName, int targetAddress);
    static std::string getJFormatInstructionString0(std::string operationName, int targetAddress);

    static int getOp(int instruction);
    static int getRs(int instruction);
    static int getRt(int instruction);
    static int getRd(int instruction);
    static int getShamt(int instruction);
    static int getFunct(int instruction);
    static int getImmediate(int instruction);
    static int getTargetAddress(int instruction);

  public:
    static std::string createInstructionString(int instruction);
};
