#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>//shell command c.str()

#include "commands/output.h"
#include "commands/path.h"
#include "commands/bitwise.h"
#include "commands/mkdir.h"
#include "commands/read.h"
#include "commands/create.h"
#include "commands/help.h"
#include "commands/global.h"
#include "commands/edit.h"
#include "commands/delete.h"




inline void validate(std::vector<std::string> command){
  if(command[0] == "output"){
    (command.size() == 1) ? std::cout << output_usage << std::endl: std::cout << output_display(command) << std::endl;
  } else if(command[0] == "quit" || command[0] == "-1"){
    CONDITION = false;
  } else if(command[0] == "path"){
    if(command.size() == 1){
      std::cout << path_display(PATH) << std::endl;
    } else if (command.size() == 2 && command[1] != "<-"){
      std::cout << path_usage << std::endl;
    } else if (command.size() == 2 && command[1] == "<-"){ 
      PATH = path_update_back(PATH); 
      std::cout << PATH << std::endl;
    } else if (command.size() == 3 && command[1] != "->"){
      std::cout << path_usage << std::endl;
    } else if (command.size() >= 3 && command[1] == "->"){
      std::string restOfArg;
      std::string trueArgs;
      for(int i = 2; i < command.size(); i++){
        restOfArg+=command[i] + " ";
      }
      for(int j = 0; j < restOfArg.find_last_of(' '); j++){
        trueArgs+=restOfArg.at(j);
      }
      PATH = path_update_front(PATH, trueArgs);
      std::cout << PATH << std::endl;
    } else {
      std::cout << path_usage << std::endl;
    }
  } else if(command[0] == "mkdir"){
    if(command.size() != 2){
      std::cout << mkdir_usage << std::endl;
    }else{
      std::string args;
      std::string trueArgs;
      for(int i = 1; i < command.size(); i++){
        args+= command[i] + " ";
      }
      for(int j = 0; j < args.find_last_of(' '); j++){
        trueArgs+=args.at(j);
      }
      std::cout << mkdir(PATH, trueArgs) << std::endl;
      }
  } else if(command[0] == "bitwise"){
    if(command.size() != 4){
      std::cout << bitwise_usage << std::endl;
    } else {
      if(bitwise(command[1], command[2], command[3]) == -1){
        std::cerr << bitwise_usage << std::endl;
      } else {
        std::cout << bitwise(command[1], command[2], command[3]) << std::endl;
      }
    }
  } else if(command[0] == "help"){
    if(command.size() > 2){
      std::cout << help_usage << std::endl;
    } else {
      if(command.size() == 1){
        std::cout << help() << std::endl;
      } else {
        std::cout << help(command[1]) << std::endl;
      }
    }
  } else if(command[0] == "read"){
    if(command.size() < 2){
      std::cout << read_usage << std::endl;
    } else{
    std::string trueArgs;
    parseCommand_read(command, trueArgs);
    read_file(trueArgs ,PATH);
    }
  } else if(command[0] == "version"){
    std::cout << VERSION << std::endl;
  } else if(command[0] == "create"){
    if(command.size() <= 2){
      std::cout << create_usage << std::endl;
    } else {
      try{
        std::string trueArgs;
        std::string content;
        parseCommand_create(command, trueArgs, content);
        create_file(PATH, trueArgs, content);
      }
      catch(const std::exception& e){
        std::cout << create_usage << std::endl;
      }
      
    }
  } else if(command[0] == "edit"){
    if(command.size() <= 2){
      std::cout << edit_usage << std::endl;
    } else {
      try{
        std::string trueArgs;
        std::string content;
        parseCommand_create(command, trueArgs, content);
        if(edit_file(trueArgs, PATH, content) == -1){
          std::cout << "Error" << std::endl;
        } else {
          std::cout << "Successfully changed to " << content << std::endl;
        }
      }
      catch(const std::exception& e){
        std::cout << edit_usage << std::endl;
      }
    }
  }else if(command[0] == "delete"){
    std::string trueArgs;
    parseCommand_read(command, trueArgs);
    std::cout << delete_file(PATH, trueArgs) << std::endl;
  } else{
    std::cout << command[0] << " is not a system recognized program" << std::endl;
  }
  
}
int main(int argc, char* argv[]){
  do{
    std::string command;
    std::cout << FORMAT;
    std::getline(std::cin >> std::ws, command);
    validate(turn_string_to_array(command));
  }while(CONDITION);
  return 0;
}