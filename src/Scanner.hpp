#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <istream>
#include <unordered_map>

#include "Token.hpp"

bool isNum(int character);
bool isAlpha(int character);
bool isAlphaNum(int character);

class Scanner
{
public:
    Scanner(std::istream *input);
    ~Scanner() = default;

    int scan();
    Token *lex();

private:
    const std::unordered_map<std::string, TokenType> keyWords =
        {{"int", INT_TYPE},
         {"char", CHAR_TYPE},
         {"float", FLOAT_TYPE},
         {"double", DOUBLE_TYPE},
         {"void", VOID_TYPE},
         {"struct", STRUCT_TYPE},
         {"union", UNION_TYPE},
         {"switch", SWITCH_KEYWORD},
         {"case", CASE_KEYWORD},
         {"default", DEFAULT_KEYWORD},
         {"break", BREAK_KEYWORD},
         {"if", IF_KEYWORD},
         {"else", ELSE_KEYWORD},
         {"do", DO_KEYWORD},
         {"while", WHILE_KEYWORD},
         {"for", FOR_KEYWORD},
         {"continue", CONTINUE_KEYWORD},
         {"return", RETURN_KEYWORD}};
    std::istream *inputStream;
    int currLine;
    int currCol;

    int currChar;

    void nextChar();

    Token *handleKeywordAndIdentifier();
    Token *handleNumbers();

    Token *makeToken(TokenType token);
    Token *makeToken(TokenType token, std::string lexeme);
};

#endif