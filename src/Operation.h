// #include "iostream"

// const std::string addString = "add";

// class Operation {
//   private:
//     std::string name;
//     int opValue;
//   protected:
//     Operation();
//     Operation(std::string name, int opValue) {
//       this->name = name;
//       this->opValue = opValue;
//     };
//   public:
//     std::string getName() {
//       return this->name;
//     };
//     int getOpValue() {
//       return this->opValue;
//     }
// };

// class RFormatOperation : public Operation {
//   private:
//     int funct;
//   public:
//     RFormatOperation();
//     RFormatOperation(std::string name, int opValue, int funct): Operation(name, opValue) {
//       this->funct = funct;
//     }
// };

// class IFormatOperation : public Operation {
//   public:
//     IFormatOperation();
//     IFormatOperation(std::string name, int opValue): Operation(name, opValue) {};
// };

// class JFormatOperation : public Operation {
//   public:
//     JFormatOperation();
//     JFormatOperation(std::string name, int opValue): Operation(name, opValue) {};
// };

enum class OperationType {
  R_TYPE,
  I_TYPE,
  J_TYPE,
};

#include "iostream"

class Operation {
  private:
    std::string name;
    int opValue;
    int functValue;
    OperationType type;
    int mode;

  public:
    Operation() {};
    Operation(std::string name, int opValue, OperationType type, int mode) {
      this->name = name;
      this->opValue = opValue;
      this->type = type;
      this->mode = mode;
    };
    Operation(std::string name, int opValue, int functValue, OperationType type, int mode) {
      this->name = name;
      this->opValue = opValue;
      this->functValue = functValue;
      this->type = type;
      this->mode = mode;
    }
    std::string getName() {
      return this->name;
    };
    int getOpValue() {
      return this->opValue;
    }
    int getFunctValue() {
      return this->functValue;
    }
    OperationType getType() {
      return this->type;
    }
    int getMode() {
      return this->mode;
    }
};
