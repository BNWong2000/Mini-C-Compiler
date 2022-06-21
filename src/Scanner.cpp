#include "Scanner.hpp"

Scanner::Scanner(std::istream *input) {
    currLine = 1;
    currCol = 1;
    inputStream = input;
}


int Scanner::scan(){
    
    return 0;
}

Token *Scanner::lex(){
    int currChar = nextChar();
    switch (currChar)
    {
    case EOF:

        break;
    case '(':
        /* code */
        break;
    
    default:
        break;
    }
}

// Currently returns an int, rather than a char, so that I can deal with eof
int Scanner::nextChar(){
    currCol++;
    return inputStream->get();
}
