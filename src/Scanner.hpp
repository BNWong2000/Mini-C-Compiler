#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>
#include "Token.hpp"


class Scanner
{
public:
    Scanner();
    ~Scanner() = default;

    int scan(std::ifstream &inputStream);
private:

};

#endif