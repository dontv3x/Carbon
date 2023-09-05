#include <string>
#include <cstdio>
std::string delete_usage = "delete <file>";

std::string delete_file(std::string path, std::string name){
  const char* filePath = (path + name).c_str();

  int result = std::remove(filePath);
  if (result == 0) {
    return "File deleted successfully.";
  } else {
    if (std::FILE* file = std::fopen(filePath, "r")) {
      std::fclose(file);
      return "Error deleting the file: Permission issue or file in use.";
    } else {
      return "Error deleting the file: File does not exist.";
  }
    }
}