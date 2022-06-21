#ifndef TOKEN_HPP
#define TOKEN_HPP

enum TokenType {

    // brace = {}, paren = (), bracket = []
    LEFT_BRACE, RIGHT_BRACE, LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACKET, RIGHT_BRACKET,

    // Arithmetic Operators
    PLUS, MINUS, STAR, SLASH, MOD, BIT_OR, BIT_AND, BIT_XOR, 
    BIT_NOT, LEFT_SHIFT, RIGHT_SHIFT,

    
    // Logical Operators
    LOGIC_NOT, LOGIC_AND, LOGIC_OR, 
    LOGIC_EQUAL, LOGIC_NEQUAL, 
    LESS, GREATER, LESS_EQUAL, GREATER_EQUAL, 

    // Assignment Operators
    ASSIGN,
    PLUS_EQUAL, MINUS_EQUAL, STAR_EQUAL, SLASH_EQUAL,
    MOD_EQUAL, AND_EQUAL, OR_EQUAL, 
    LSHIFT_EQUAL, RSHIFT_EQUAL,

    // Misc
    COMMA, DOT, COLON, SEMICOLON, ARROW, 

    // Keywords:

    // Types:
    INT_TYPE, CHAR_TYPE, FLOAT_TYPE, DOUBLE_TYPE, VOID_TYPE,
    STRUCT_TYPE, UNION_TYPE,

    // Switch Case:
    SWITCH_KEYWORD, CASE_KEYWORD, DEFAULT_KEYWORD,
    BREAK_KEYWORD, 
    
    // If-Else
    IF_KEYWORD, ELSE_KEYWORD,

    // Loops
    DO_KEYWORD, WHILE_KEYWORD, FOR_KEYWORD, CONTINUE_KEYWORD,
    
    // Return
    RETURN_KEYWORD
};


class Token{
public:
    Token();
    ~Token() = default;
    void printToken();
private:

};

#endif