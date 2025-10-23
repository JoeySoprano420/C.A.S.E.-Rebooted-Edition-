#ifndef CASE_TOKEN_HPP
#define CASE_TOKEN_HPP

#include <string>
#include <vector>

namespace Case {

enum class TokenType {
    // Keywords
    PRINT, LET, FN, CALL, RET, IF, ELSE, WHILE, LOOP, 
  BREAK, CONTINUE, SWITCH, CASE, DEFAULT, STRUCT,
    
    // Operators
    PLUS, MINUS, MULTIPLY, DIVIDE, MODULO,
    EQUAL, NOT_EQUAL, LESS, GREATER, LESS_EQUAL, GREATER_EQUAL,
    ASSIGN, LOGICAL_AND, LOGICAL_OR, LOGICAL_NOT,

    // Delimiters
    LPAREN, RPAREN, LBRACE, RBRACE, LBRACKET, RBRACKET,
    COMMA, SEMICOLON,
    
    // Literals
    IDENTIFIER, NUMBER, STRING,
    
    // Special
    END_MARKER,  // [end]
    END_OF_FILE,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string lexeme;
    int line;
    int column;
    
    Token(TokenType t, const std::string& lex, int ln, int col)
        : type(t), lexeme(lex), line(ln), column(col) {}
};

class Lexer {
public:
  explicit Lexer(const std::string& source);
    std::vector<Token> tokenize();
    
private:
    std::string source;
    size_t position;
    int line;
    int column;
    
    char currentChar();
 char peek(int offset = 1);
    void advance();
  void skipWhitespace();
    void skipComment();
    
    Token scanToken();
    Token makeIdentifierOrKeyword();
 Token makeNumber();
    Token makeString();
    Token makeOperator();
 
    bool isAtEnd() const;
  bool isAlpha(char c) const;
  bool isDigit(char c) const;
    bool isAlphaNumeric(char c) const;
};

} // namespace Case

#endif // CASE_TOKEN_HPP
