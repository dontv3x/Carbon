#include <string>
#include <fstream>
#include <iostream>

std::string read_usage = "read <file>";
void read_file(std::string file, std::string path){
  std::string content;
  std::ifstream OpenFile(path + file);
  if(OpenFile.is_open()){
    while (std::getline (OpenFile, content)) {
      std::cout << content << std::endl;
    }
    OpenFile.close();
  } else{
    std::cout << "No such file" << std::endl;
  }
}