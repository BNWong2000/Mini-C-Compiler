#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>
#include "Token.hpp"


class Scanner
{
public:
    Scanner(std::istream *input);
    ~Scanner() = default;

    int scan();
    Token *lex();

private:
    std::istream *inputStream;
    int currLine;
    int currCol;

    char nextChar();
};

#endif