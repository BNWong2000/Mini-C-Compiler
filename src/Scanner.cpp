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
    char currChar;
    while(inputStream->get(currChar)){
        // Keeps going into eof
        
    }
}


