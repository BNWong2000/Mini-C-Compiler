#include "main.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    int returnValue;
    if (argc < 2)
    {
        std::cerr << "ERROR: Missing arguments. Usage: ./main [file]" << std::endl;
        return 1;
    }
    else if (argc == 2)
    {
        Driver *fileDriver = new Driver();
        returnValue = fileDriver->runFile(argv[0]);
    }
    return returnValue;
}