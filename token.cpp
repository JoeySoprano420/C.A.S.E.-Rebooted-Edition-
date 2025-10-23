#include "../include/token.hpp"
#include <cctype>
#include <unordered_map>

namespace Case {

static std::unordered_map<std::string, TokenType> keywords = {
    {"print", TokenType::PRINT}, {"Print", TokenType::PRINT},
    {"let", TokenType::LET},
    {"Fn", TokenType::FN}, {"fn", TokenType::FN},
    {"call", TokenType::CALL},
    {"ret", TokenType::RET},
    {"if", TokenType::IF},
    {"else", TokenType::ELSE},
    {"while", TokenType::WHILE},
    {"loop", TokenType::LOOP},
    {"break", TokenType::BREAK},
    {"continue", TokenType::CONTINUE},
    {"switch", TokenType::SWITCH},
{"case", TokenType::CASE},
    {"default", TokenType::DEFAULT},
    {"struct", TokenType::STRUCT}
};

Lexer::Lexer(const std::string& src) 
    : source(src), position(0), line(1), column(1) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    
    while (!isAtEnd()) {
        skipWhitespace();
     if (isAtEnd()) break;
   
        Token tok = scanToken();
        if (tok.type != TokenType::UNKNOWN) {
            tokens.push_back(tok);
        }
    }
    
    tokens.push_back(Token(TokenType::END_OF_FILE, "", line, column));
    return tokens;
}

char Lexer::currentChar() {
    if (isAtEnd()) return '\0';
    return source[position];
}

char Lexer::peek(int offset) {
 if (position + offset >= source.length()) return '\0';
    return source[position + offset];
}

void Lexer::advance() {
 if (!isAtEnd()) {
   if (source[position] == '\n') {
          line++;
        column = 1;
     } else {
            column++;
        }
        position++;
    }
}

void Lexer::skipWhitespace() {
    while (!isAtEnd()) {
     char c = currentChar();
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
            advance();
        } else if (c == '#') {
    skipComment();
        } else {
            break;
    }
    }
}

void Lexer::skipComment() {
    while (!isAtEnd() && currentChar() != '\n') {
      advance();
    }
}

Token Lexer::scanToken() {
    int startLine = line;
    int startCol = column;
    char c = currentChar();
    
    // Identifiers and keywords
    if (isAlpha(c)) {
   return makeIdentifierOrKeyword();
    }
    
    // Numbers
    if (isDigit(c)) {
        return makeNumber();
    }
    
    // Strings
 if (c == '"') {
        return makeString();
    }
    
    // [end] marker
    if (c == '[') {
 std::string marker;
 int savedPos = position;
        int savedLine = line;
   int savedCol = column;
        
        advance();
        while (!isAtEnd() && currentChar() != ']') {
            marker += currentChar();
  advance();
        }
        
     if (currentChar() == ']') {
            advance();
        if (marker == "end") {
      return Token(TokenType::END_MARKER, "[end]", savedLine, savedCol);
            }
        }
     
    // Not [end], backtrack
 position = savedPos;
      line = savedLine;
        column = savedCol;
        advance();
      return Token(TokenType::LBRACKET, "[", startLine, startCol);
    }
    
    // Operators and delimiters
    return makeOperator();
}

Token Lexer::makeIdentifierOrKeyword() {
    int startLine = line;
    int startCol = column;
    std::string text;
    
    while (!isAtEnd() && isAlphaNumeric(currentChar())) {
        text += currentChar();
        advance();
    }
    
    auto it = keywords.find(text);
    if (it != keywords.end()) {
        return Token(it->second, text, startLine, startCol);
    }
    
    return Token(TokenType::IDENTIFIER, text, startLine, startCol);
}

Token Lexer::makeNumber() {
    int startLine = line;
    int startCol = column;
 std::string number;
    
 while (!isAtEnd() && (isDigit(currentChar()) || currentChar() == '.')) {
        number += currentChar();
        advance();
 }
    
    return Token(TokenType::NUMBER, number, startLine, startCol);
}

Token Lexer::makeString() {
    int startLine = line;
  int startCol = column;
    std::string text = "\"";
    advance(); // Skip opening quote
    
    while (!isAtEnd() && currentChar() != '"') {
        text += currentChar();
      advance();
    }
 
    if (!isAtEnd()) {
  text += '"';
        advance(); // Skip closing quote
    }
    
    return Token(TokenType::STRING, text, startLine, startCol);
}

Token Lexer::makeOperator() {
    int startLine = line;
    int startCol = column;
    char c = currentChar();
    advance();
    
    switch (c) {
 case '+': return Token(TokenType::PLUS, "+", startLine, startCol);
        case '-': return Token(TokenType::MINUS, "-", startLine, startCol);
      case '*': return Token(TokenType::MULTIPLY, "*", startLine, startCol);
 case '/': return Token(TokenType::DIVIDE, "/", startLine, startCol);
        case '%': return Token(TokenType::MODULO, "%", startLine, startCol);
        case '(': return Token(TokenType::LPAREN, "(", startLine, startCol);
        case ')': return Token(TokenType::RPAREN, ")", startLine, startCol);
    case '{': return Token(TokenType::LBRACE, "{", startLine, startCol);
        case '}': return Token(TokenType::RBRACE, "}", startLine, startCol);
        case '[': return Token(TokenType::LBRACKET, "[", startLine, startCol);
        case ']': return Token(TokenType::RBRACKET, "]", startLine, startCol);
        case ',': return Token(TokenType::COMMA, ",", startLine, startCol);
        case ';': return Token(TokenType::SEMICOLON, ";", startLine, startCol);
        case '=':
            if (currentChar() == '=') {
      advance();
     return Token(TokenType::EQUAL, "==", startLine, startCol);
            }
  return Token(TokenType::ASSIGN, "=", startLine, startCol);
        case '!':
            if (currentChar() == '=') {
         advance();
     return Token(TokenType::NOT_EQUAL, "!=", startLine, startCol);
            }
            return Token(TokenType::LOGICAL_NOT, "!", startLine, startCol);
        case '<':
       if (currentChar() == '=') {
     advance();
     return Token(TokenType::LESS_EQUAL, "<=", startLine, startCol);
     }
            return Token(TokenType::LESS, "<", startLine, startCol);
        case '>':
            if (currentChar() == '=') {
     advance();
    return Token(TokenType::GREATER_EQUAL, ">=", startLine, startCol);
            }
        return Token(TokenType::GREATER, ">", startLine, startCol);
        case '&':
  if (currentChar() == '&') {
              advance();
 return Token(TokenType::LOGICAL_AND, "&&", startLine, startCol);
  }
        break;
        case '|':
    if (currentChar() == '|') {
         advance();
           return Token(TokenType::LOGICAL_OR, "||", startLine, startCol);
         }
     break;
}
    
    return Token(TokenType::UNKNOWN, std::string(1, c), startLine, startCol);
}

bool Lexer::isAtEnd() const {
    return position >= source.length();
}

bool Lexer::isAlpha(char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Lexer::isDigit(char c) const {
    return c >= '0' && c <= '9';
}

bool Lexer::isAlphaNumeric(char c) const {
    return isAlpha(c) || isDigit(c);
}

} // namespace Case
