#include <string>
#include <fstream>

std::string create_usage = "create <file name + extension> -<content>";

void create_file(std::string path, std::string name, std::string content){
  std::ofstream File(path + name);
  File << content;
  File.close();
}