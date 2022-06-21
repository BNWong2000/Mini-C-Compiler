#include "Scanner.hpp"

Scanner::Scanner(std::istream *input)
{
    currLine = 1;
    currCol = 0;
    inputStream = input;
    currChar = nextChar();
}

int Scanner::scan()
{
    return 0;
}

Token *Scanner::lex()
{
    while (isspace(currChar))
    {
        if (currChar == '\n')
        {
            currLine++;
            currCol = 0;
        }
        currChar = nextChar();
    }

    switch (currChar)
    {
    case EOF:
        return makeToken(EOF_TOKEN);
    case '{':
        return makeToken(LEFT_BRACE);
    case '}':
        return makeToken(RIGHT_BRACE);
    case '(':
        return makeToken(LEFT_PAREN);
    case ')':
        return makeToken(RIGHT_PAREN);
    case '[':
        return makeToken(LEFT_BRACKET);
    case ']':
        return makeToken(RIGHT_BRACKET);
    case '+':
        //
    case '-':
        //
    case '*':
        //
    case '/':
        //
    case '%':
        //
    case '|':
        //
    case '&':
        //
    case '^':
        //
    case '~':
        return makeToken(BIT_NOT);
    case '<':
        //
    case '>':
        //
    case '!':
        //
    case '=':
        //
    case ',':
        return makeToken(COMMA);
    case '.':
        return makeToken(DOT);
    case ':':
        return makeToken(COLON);
    case ';':
        return makeToken(SEMICOLON);
    case '\'':
        return makeToken(SINGLE_QUOTE);
    case '\"':
        return makeToken(DOUBLE_QUOTE);
    default:
        if (isNum(currChar))
        {
            return handleNumbers();
        }
        else if (isAlpha(currChar))
        {
            return handleKeywordAndIdentifier();
        }
        else
        {
            std::cerr << "ERROR: unknown character found on line " << currLine << std::endl;
            return nullptr;
        }
    }
    return nullptr;
}

// Currently returns an int, rather than a char, so that I can deal with eof
int Scanner::nextChar()
{
    currCol++;
    return inputStream->get();
}

bool isNum(int character)
{
    return character >= '0' && character <= '9';
}

bool isAlpha(int character)
{
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character == '_');
}

Token *Scanner::handleKeywordAndIdentifier()
{
}

Token *Scanner::handleNumbers()
{
    bool isFloat = false;
    std::string numberLexeme = "";
    while (currChar == '.' || isNum(currChar))
    {
        if (currChar == '.')
        {
            if (!isFloat)
            {
                isFloat = true;
            }
            else
            {
                // more than 1 '.' in the number, so error.
                std::cerr << "ERROR: More than 1 \'.\' in number on line " << currLine << std::endl;
                return nullptr;
            }
        }
        numberLexeme.push_back(currChar);
        currChar = nextChar();
    }
    TokenType token = isFloat ? FLOAT_LIT : INTEGER_LIT;
    return makeToken(token, numberLexeme);
}

Token *Scanner::makeToken(TokenType token)
{
    return new Token(token, "", currLine, currCol);
}

Token *Scanner::makeToken(TokenType token, std::string lexeme)
{
    return new Token(token, lexeme, currLine, currCol);
}
