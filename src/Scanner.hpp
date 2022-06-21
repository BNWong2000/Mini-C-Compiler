#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>


bool debug = true;

class Scanner
{
public:
    Scanner();
    ~Scanner() = default;

    int scan(std::ifstream &inputStream);
private:
    
};

#endif