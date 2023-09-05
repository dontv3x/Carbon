#include <string>
std::string bitwise_usage = "bitwise <first digit> <bitwise operator> <second digit>";

int bitwise(std::string n1, std::string op, std::string n2){
  //TODO: Learn how to turn string to integer
  try
  {
    if(op == "&"){
      return std::stoi(n1) & std::stoi(n2);;
    } else if (op == "|"){
      return std::stoi(n1) | std::stoi(n2);;
    } else if(op == "^"){
      return std::stoi(n1) ^ std::stoi(n2);;
    } else if(op == ">>"){
      return std::stoi(n1) >> std::stoi(n2);;
    } else if(op == "<<"){
      return std::stoi(n1) << std::stoi(n2);;
    } else {
      return -1;
    } 
  }
  catch(const std::exception& e)
  {
    return -1;
  }
}
