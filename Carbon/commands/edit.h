#include <string>
#include <fstream>
#include <iostream>

std::string edit_usage = "edit <file> -<content>";

int edit_file(std::string file, std::string path, std::string contentToBeChangedTo) {
    std::ofstream fileStream(path + file);
    if (!fileStream.is_open()) {
        return -1;
    }
    fileStream << contentToBeChangedTo;
    fileStream.close();
    
    return 0;
}
