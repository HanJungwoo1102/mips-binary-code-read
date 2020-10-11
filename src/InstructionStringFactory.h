#include <iostream>
#include <array>
#include "Operation.h"

const int R_FORMAT_OPERATION_SIZE = 26;
const int I_FORMAT_OPERATION_SIZE = 11;
const int J_FORMAT_OPERATION_SIZE = 2;

class InstructionStringFactory {
  private:
    static std::array<Operation, R_FORMAT_OPERATION_SIZE> rFormatOperationArray;
		static std::array<Operation, I_FORMAT_OPERATION_SIZE> iFormatOperationArray;
		static std::array<Operation, J_FORMAT_OPERATION_SIZE> jFormatOperationArray;

    static bool isRFormatInstuction(int op);
		static bool isIFormatInstuction(int op);
		static bool isJFormatInstuction(int op);

    static std::string getRFormatInstructionString(int instruction);
    static std::string getIFormatInstructionString(int instruction);
    static std::string getJFormatInstructionString(int instruction);

    static int getOp(int instruction);
    static int getRs(int instruction);
    static int getRt(int instruction);
    static int getRd(int instruction);
    static int getShamt(int instruction);
    static int getFunct(int instruction);
    static int getImmediate(int instruction);
    static int getTargetAddress(int instruction);

    static std::string getRFormatOperationName(int op);
    static std::string getIFormatOperationName(int op);
    static std::string getJFormatOperationName(int op);

  public:
    static std::string createInstructionString(int instruction) {
      std::string instructionString;
      
      int op = InstructionStringFactory::getOp(instruction);

      if (InstructionStringFactory::isRFormatInstuction(op)) {
        instructionString = InstructionStringFactory::getRFormatInstructionString(instruction);
      } else if (InstructionStringFactory::isIFormatInstuction(op)) {
        instructionString = InstructionStringFactory::getIFormatInstructionString(instruction);
      } else if (InstructionStringFactory::isJFormatInstuction(op)) {
        instructionString = InstructionStringFactory::getJFormatInstructionString(instruction);
      } else {
        instructionString = instructionString + "unknown instruction";
      }
      return instructionString;
    };
};
