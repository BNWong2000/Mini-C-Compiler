#include "Token.hpp"

Token::Token(){};

Token::Token(TokenType type, std::string lexeme, int line, int col)
{
    theType = type;
    theLexeme = lexeme;
    lineNumber = line;
    colNumber = col;
}

void Token::setTheType(TokenType token){
    theType = token;
}

TokenType Token::getTheType(){
    return theType;
}

void Token::setTheLexeme(std::string lexeme){
    theLexeme = lexeme;
}

std::string Token::getTheLexeme(){
    return theLexeme;
}

void Token::setLocation(int line, int col){
    lineNumber = line;
    colNumber = col;
}

std::pair<int, int> Token::getLocation(){
    return {lineNumber, colNumber};
}

void Token::printToken()
{
    std::cout << "Token: "
              << getTokenString(theType) << " " << theLexeme << "\n";
}

std::string getTokenString(TokenType token)
{
    switch (token)
    {
    case LEFT_BRACE:
        return "\'{\'";
    case RIGHT_BRACE:
        return "\'}\'";
    case LEFT_PAREN:
        return "\'(\'";
    case RIGHT_PAREN:
        return "\')\'";
    case LEFT_BRACKET:
        return "\'[\'";
    case RIGHT_BRACKET:
        return "\']\'";
    case PLUS:
        return "\'+\'";
    case MINUS:
        return "\'-\'";
    case STAR:
        return "\'*\'";
    case SLASH:
        return "\'/\'";
    case MOD:
        return "\'%\'";
    case BIT_OR:
        return "\'|\'";
    case BIT_AND:
        return "\'&\'";
    case BIT_XOR:
        return "\'^\'";
    case BIT_NOT:
        return "\'~\'";
    case LEFT_SHIFT:
        return "\"<<\"";
    case RIGHT_SHIFT:
        return "\">>\"";
    case LOGIC_NOT:
        return "\'!\'";
    case LOGIC_AND:
        return "\"&&\"";
    case LOGIC_OR:
        return "\"||\"";
    case LOGIC_EQUAL:
        return "\"==\"";
    case LOGIC_NEQUAL:
        return "\"!=\"";
    case LESS:
        return "\'<\'";
    case GREATER:
        return "\'>\'";
    case LESS_EQUAL:
        return "\"<=\"";
    case GREATER_EQUAL:
        return "\">=\"";
    case ASSIGN:
        return "\'=\'";
    case PLUS_EQUAL:
        return "\"+=\"";
    case MINUS_EQUAL:
        return "\"-=\"";
    case STAR_EQUAL:
        return "\"*=\"";
    case SLASH_EQUAL:
        return "\"/=\"";
    case MOD_EQUAL:
        return "\"%=\"";
    case AND_EQUAL:
        return "\"\"";
    case OR_EQUAL:
        return "\"|=\"";
    case LSHIFT_EQUAL:
        return "\"<<=\"";
    case RSHIFT_EQUAL:
        return "\">>=\"";
    case COMMA:
        return "\',\'";
    case DOT:
        return "\'.\'";
    case COLON:
        return "\':\'";
    case SEMICOLON:
        return "\';\'";
    case ARROW:
        return "\"->\"";
    case SINGLE_QUOTE:
        return "\'\'\'";
    case DOUBLE_QUOTE:
        return "\'\"\'";
    case INT_TYPE:
        return "int";
    case CHAR_TYPE:
        return "char";
    case FLOAT_TYPE:
        return "float";
    case DOUBLE_TYPE:
        return "double";
    case VOID_TYPE:
        return "void";
    case STRUCT_TYPE:
        return "struct";
    case UNION_TYPE:
        return "union";
    case SWITCH_KEYWORD:
        return "switch";
    case CASE_KEYWORD:
        return "case";
    case DEFAULT_KEYWORD:
        return "default";
    case BREAK_KEYWORD:
        return "break";
    case IF_KEYWORD:
        return "if";
    case ELSE_KEYWORD:
        return "else";
    case DO_KEYWORD:
        return "do";
    case WHILE_KEYWORD:
        return "while";
    case FOR_KEYWORD:
        return "for";
    case CONTINUE_KEYWORD:
        return "continue";
    case RETURN_KEYWORD:
        return "return";
    case INTEGER_LIT:
        return "integer literal";
    case FLOAT_LIT:
        return "floating point literal";
    case CHAR_LIT:
        return "character literal";
    case STRING_LIT:
        return "string literal";
    case IDENTIFIER:
        return "identifier";
    case EOF_TOKEN:
        return "EOF";
    default:
        break;
    }
    return "";
}
