#include <sstream>
#include <string>
#include <vector>

std::string output_usage = "output [Value to be outputed]";

std::string output_display(std::vector<std::string> param){
  std::string output = "";
  for(int i = 1; i < param.size(); i++){
    (i >= param.size()) ? output.append(param[i]) : output.append(param[i] + " ");
  }
  return output;
}