#include <string>
std::string bitwise_usage = "bitwise <first digit> <bitwise operator> <second digit>";

int bitwise(std::string n1, std::string op, std::string n2){
  //TODO: Learn how to turn string to integer
  try
  {
    int num1 = std::stoi(n1);
    int num2 = std::stoi(n2);
    if(op == "&"){
      return num1 & num2;
    } else if (op == "|"){
      return num1 | num2;
    } else if(op == "^"){
      return num1 ^ num2;
    } else if(op == ">>"){
      return num1 >> num2;
    } else if(op == "<<"){
      return num1 << num2;
    } else {
      return -1;
    } 
  }
  catch(const std::exception& e)
  {
    return -1;
  }
}
