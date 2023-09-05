#include <string>
#include <vector>
#include <sstream>
#include <chrono>
#include <iostream>
#include <functional>

bool CONDITION = true;
const double VERSION = 0.1;
std::string PATH = "C:\\";
std::string FORMAT = "Carbon >> ";

std::vector<std::string> turn_string_to_array(std::string inputString){
  std::istringstream iss(inputString);
  std::vector<std::string> words;
  std::string word;
  while (iss >> word) {
    words.push_back(word);
  }
  return words;
}

#include <iostream>
#include <string>


inline void parseCommand_create(const std::vector<std::string>& command, std::string& trueArgs, std::string& content) {
    std::string restOfArg;
    for (int i = 1; i < command.size(); i++) {
        restOfArg += command[i] + " ";
    }
    for (int j = 0; j < restOfArg.find_last_of('-') - 1; j++) {
        trueArgs += restOfArg.at(j);
    }
    for (int k = restOfArg.find_first_of('-') + 1; k < restOfArg.length(); k++) {
        content += restOfArg.at(k);
    }
}
inline void parseCommand_read(const std::vector<std::string>& command, std::string& trueArgs) {
    std::string restOfArg;
    for (int i = 1; i < command.size(); i++) {
      restOfArg += command[i] + " ";
    }
    for(int j = 0; j < restOfArg.find_last_of(' '); j++){
      trueArgs += restOfArg.at(j);
    }
}
void parseCommand_path(){

}