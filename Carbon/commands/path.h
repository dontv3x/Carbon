#include <string>
#include <windows.h>

bool directoryExists(const std::string& path) {
    DWORD attributes = GetFileAttributesA(path.c_str());
    if (attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY)) {
        return true;
    }
    return false;
}
std::string path_usage = "path | path <- | path -> directory";

std::string path_update_front(std::string path, std::string name){
  if(directoryExists(path + name)){
    return path + name + "\\";
  } else {
    return path;
  }
}

std::string path_update_back(std::string path){
  if(path == "C:\\"){
    return path;
  } else {
    std::string output;
    std::string true_output;
    int indexOfLastSlash = path.find_last_of('\\');
    for(int i = 0; i < indexOfLastSlash; i++){
      output += path.at(i);
    }
    int trueIndexOfLastSlash = output.find_last_of('\\');
    for(int i = 0; i < trueIndexOfLastSlash; i++){
      true_output += output.at(i);
    }
    return true_output + "\\";
  }
}
std::string path_display(std::string path){
  return path;
}