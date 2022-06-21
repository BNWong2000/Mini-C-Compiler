#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "Scanner.hpp"
#include "Parser.hpp"

#include <string>
#include <fstream>
#include <iostream>

class Driver
{
public:
    Driver();
    ~Driver() = default;

    int runFile(std::string filePath);

private:
    Scanner *tokenScanner;
    Parser *syntaxAnalyzer;

    int run(std::ifstream &inputStream);

};

#endif