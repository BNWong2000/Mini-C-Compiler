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

    int currChar;

    int nextChar();

    bool isNum(int character);
    bool isAlpha(int character);

    Token *handleKeywordAndIdentifier();
    Token *handleNumbers();

    Token *makeToken(TokenType token);
    Token *makeToken(TokenType token, std::string lexeme);
};

#endif