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

#include "iostream"

class Operation {
  private:
    std::string name;
    int opValue;
    int funct;
  public:
    Operation() {};
    Operation(std::string name, int opValue) {
      this->name = name;
      this->opValue = opValue;
    };
    Operation(std::string name, int opValue, int funct) {
      this->name = name;
      this->opValue = opValue;
      this->funct = funct;
    }
    std::string getName() {
      return this->name;
    };
    int getOpValue() {
      return this->opValue;
    }
};
