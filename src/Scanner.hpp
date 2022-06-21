#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <istream>
#include "Token.hpp"

bool isNum(int character);
bool isAlpha(int character);

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

    int currChar;

    int nextChar();

    Token *handleKeywordAndIdentifier();
    Token *handleNumbers();

    Token *makeToken(TokenType token);
    Token *makeToken(TokenType token, std::string lexeme);
};

#endif