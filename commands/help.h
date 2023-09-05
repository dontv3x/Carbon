#include <string>


std::string help_usage = "help | help <code>";
std::string help(){
  return bitwise_usage + '\n' + delete_usage + '\n' + create_usage + '\n' + read_usage + '\n' + mkdir_usage + '\n' + output_usage + '\n' + path_usage + '\n' + "edit <file> -<content>" + '\n' + "-1 or quit to exit";
}
std::string help(std::string command){
  if(command == "bitwise"){
    return bitwise_usage;
  } else if(command == "create"){
    return create_usage;
  } else if(command == "read"){
    return read_usage;
  } else if(command == "mkdir"){
    return mkdir_usage;
  } else if(command == "output"){
    return output_usage;
  } else if(command == "path"){
    return path_usage;
  } else if(command == "quit" || command == "-1"){
    return "-1 or quit to exit";
  } else if(command == "edit"){
    return "edit <file> -<content>";
  } else if(command == "delete"){
    return delete_usage;
    }else{
    return "Not a command";
  }
}