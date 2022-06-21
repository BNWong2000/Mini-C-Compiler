#include "Driver.hpp"

Driver::Driver()
{
    syntaxAnalyzer = new Parser();
}

/**
 * A function that attempts to open the file,
 * and starts the compilation process.
 */
int Driver::runFile(std::string filePath)
{
    std::ifstream inputStream;
    inputStream.open(filePath);

    // Check file stream
    if (!inputStream.is_open())
    {
        std::cerr << "ERROR: Unable to open file" << std::endl;
        return 1;
    }
    else if (inputStream.bad())
    {
        std::cerr << "ERROR: Error trying to read file" << std::endl;
        return 1;
    }
    tokenScanner = new Scanner(&inputStream);
    // start compiling
    return run();
}

/**
 * A function that takes the file input stream and compiles it.
 */ 
int Driver::run()
{
    int scanStatus = tokenScanner->scan();
    return scanStatus;
}