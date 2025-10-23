#ifndef CASE_CODEGEN_HPP
#define CASE_CODEGEN_HPP

#include <string>
#include <sstream>
#include "token.hpp"

namespace Case {

class CodeGenerator {
public:
    CodeGenerator();
    
    std::string generate(const std::vector<Token>& tokens);
 
private:
  std::stringstream output;
    int indentLevel;
    size_t position;
    std::vector<Token> tokens;
    
    void emitHeaders();
    void emitMain();
    void emitStatement();
    void emitExpression();
    
    void indent();
    void emit(const std::string& code);
    void emitLine(const std::string& code);
    
    Token current() const;
  Token peek(int offset = 1) const;
    void advance();
    bool match(TokenType type);
    bool check(TokenType type) const;
    bool isAtEnd() const;
};

} // namespace Case

#endif // CASE_CODEGEN_HPP
