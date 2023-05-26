#include "FileExtensions.h"
#include <fstream>
#include <iostream>

std::string FileExtensions::ReadEntireFileText(const char* fileName)
{
    std::ifstream infile(fileName);
    infile.ignore(std::numeric_limits<std::streamsize>::max());
    std::streamsize size = infile.gcount();
    infile.clear();
    infile.seekg(0, infile.beg);
    std::string contents(size, ' ');
    infile.read(&contents[0], size);
    return contents;
}
