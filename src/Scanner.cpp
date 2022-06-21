#include "Scanner.hpp"

Scanner::Scanner(std::istream *input)
{
    currLine = 1;
    currCol = 0;
    inputStream = input;
    nextChar();
}

int Scanner::scan()
{
    Token *currentToken = lex();
    while (currentToken && currentToken->getTheType() != EOF_TOKEN)
    {
        currentToken->printToken();
        currentToken = lex();
    }
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
        nextChar();
    }

    switch (currChar)
    {
    case EOF:
        return makeToken(EOF_TOKEN);
    case '{':
        nextChar();
        return makeToken(LEFT_BRACE);
    case '}':
        nextChar();
        return makeToken(RIGHT_BRACE);
    case '(':
        nextChar();
        return makeToken(LEFT_PAREN);
    case ')':
        nextChar();
        return makeToken(RIGHT_PAREN);
    case '[':
        nextChar();
        return makeToken(LEFT_BRACKET);
    case ']':
        nextChar();
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
        nextChar();
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
        nextChar();
        return makeToken(COMMA);
    case '.':
        nextChar();
        return makeToken(DOT);
    case ':':
        nextChar();
        return makeToken(COLON);
    case ';':
        nextChar();
        return makeToken(SEMICOLON);
    case '\'':
        nextChar();
        if (currChar == '\\')
        {
            //
        }
        else
        {
        }
        return makeToken(CHAR_LIT);
    case '\"':
    {
        nextChar();
        std::string stringLexeme = "\"";
        while (currChar != '\"')
        {
            if(currChar == '\\'){
                stringLexeme.push_back(currChar);
                nextChar();
            }
            if(currChar == '\n')
            {
                // Error
                std::cerr << "ERROR: Newline in String " << std::endl;
                return nullptr;
            }
            else if (currChar == EOF)
            {
                // Error
                std::cerr << "ERROR: Unterminated String " << std::endl;
                return nullptr;
            }
            stringLexeme.push_back(currChar);
            nextChar();
        }
        stringLexeme.push_back(currChar);
        nextChar();
        return makeToken(STRING_LIT, stringLexeme);
    }
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
void Scanner::nextChar()
{
    currCol++;
    currChar = inputStream->get();
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

    return nullptr;
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
        nextChar();
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
