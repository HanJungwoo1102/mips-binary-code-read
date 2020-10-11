#include <iostream>
#include <array>
#include "Operation.h"

const int R_FORMAT_OPERATION_SIZE = 5;
const int I_FORMAT_OPERATION_SIZE = 5;
const int J_FORMAT_OPERATION_SIZE = 2;

class InstructionStringFactory {
  private:
    static std::array<Operation, R_FORMAT_OPERATION_SIZE> rFormatOperationArray;
		static std::array<Operation, I_FORMAT_OPERATION_SIZE> iFormatOperationArray;
		static std::array<Operation, J_FORMAT_OPERATION_SIZE> jFormatOperationArray;

    static int getOp(int instruction);
    static int getRs(int instruction);
    static int getRt(int instruction);
    static int getRd(int instruction);

    static std::string getRFormatInstructionString(int instruction);
    static std::string getIFormatInstructionString(int instruction);
    static std::string getJFormatInstructionString(int instruction);

    static bool isRFormatInstuction(int op);
		static bool isIFormatInstuction(int op);
		static bool isJFormatInstuction(int op);

  public:
    static std::string createInstructionString(int instruction) {
      std::string instructionString = "";
      
      int op = InstructionStringFactory::getOp(instruction);

      if (InstructionStringFactory::isRFormatInstuction(op)) {
        std::cout << "r" << std::endl;
      } else if (InstructionStringFactory::isJFormatInstuction(op)) {
        std::cout << "j" << std::endl;
      } else if (InstructionStringFactory::isIFormatInstuction(op)) {
        std::cout << "i" << std::endl;
      } else {
        instructionString = instructionString + "unknown instruction";
      }

      return instructionString;
    };
};
