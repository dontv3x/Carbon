#include <string>
#include <fstream>
#include <iostream>

std::string read_usage = "read <file>";
std::string read_file(std::string file, std::string path){
  std::string content;
  std::ifstream OpenFile(path + file);
  while (std::getline (OpenFile, content)) {
    std::cout << content << std::endl;
  }
  OpenFile.close();
  return content;
}