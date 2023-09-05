#include <iostream>
#include <windows.h>
#include <string>

std::string mkdir_usage = "mkdir <name>";

std::string mkdir(const std::string& path, const std::string& dirName) {
    const std::string directoryPath = path + dirName; // Use "\\" to separate the path and directory name
    if (CreateDirectoryA(directoryPath.c_str(), NULL)) {
        return "Created successfully";
    } else {
        DWORD error = GetLastError();
        if (error == ERROR_ALREADY_EXISTS) {
            return "Directory already exists";
        } else {
            return "Failed to create Directory";
        }
    }
}