#include "../include/codegen.hpp"
#include <iostream>

namespace Case {

CodeGenerator::CodeGenerator() : indentLevel(0), position(0) {}

std::string CodeGenerator::generate(const std::vector<Token>& toks) {
    tokens = toks;
    position = 0;
    output.str("");
    indentLevel = 0;
    
    emitHeaders();
    emitMain();
    
    return output.str();
}

void CodeGenerator::emitHeaders() {
    emitLine("#include <iostream>");
    emitLine("#include <string>");
    emitLine("#include <cmath>");
    emitLine("#include <algorithm>");
emitLine("#include <vector>");
    emitLine("");
    emitLine("using namespace std;");
  emitLine("");
}

void CodeGenerator::emitMain() {
    emitLine("int main() {");
    indentLevel++;
    
    while (!isAtEnd()) {
        emitStatement();
    }
    
    indent();
    emitLine("return 0;");
    indentLevel--;
    emitLine("}");
}

void CodeGenerator::emitStatement() {
    if (isAtEnd()) return;
    
    Token tok = current();
    
    switch (tok.type) {
    case TokenType::PRINT: {
     advance(); // skip 'Print'
  indent();
   emit("std::cout << ");
            
            if (!isAtEnd() && current().type != TokenType::END_MARKER) {
            emitExpression();
    }
       
       emit(" << std::endl;");
    output << "\n";
         
            // Consume [end] if present
  if (match(TokenType::END_MARKER)) {
     // Already consumed
      }
            break;
        }
        
        case TokenType::LET: {
            advance(); // skip 'let'
            indent();
       emit("auto ");
         
  if (match(TokenType::IDENTIFIER)) {
          Token name = tokens[position - 1];
    emit(name.lexeme);
                
      if (match(TokenType::ASSIGN)) {
          emit(" = ");
              emitExpression();
 }
            }
       
            emit(";");
         output << "\n";
            
if (match(TokenType::END_MARKER)) {
   // Already consumed
        }
            break;
        }
   
      case TokenType::FN: {
      advance(); // skip 'Fn'
 
            // Function name
            Token funcName = current();
       advance();
   
  indent();
      emit("auto " + funcName.lexeme + "(");
     
     // Parameters (skip for now - simplified)
        while (!isAtEnd() && current().type != TokenType::LPAREN) {
     advance();
  }
            
            if (match(TokenType::LPAREN)) {
         // Parameters
    emit(")");
          
   // Body
        if (match(TokenType::LPAREN)) {
         output << " {\n";
          indentLevel++;
       
       while (!isAtEnd() && current().type != TokenType::RPAREN) {
           emitStatement();
       }
    
       if (match(TokenType::RPAREN)) {
     // End of function
       }
    
        indentLevel--;
         indent();
               emit("}\n");
     }
            }
            
            if (match(TokenType::END_MARKER)) {
            // Already consumed
    }
            break;
        }
        
        case TokenType::IF: {
 advance(); // skip 'if'
          indent();
            emit("if (");
            emitExpression();
    emit(") ");
            
     if (match(TokenType::LBRACE)) {
       output << "{\n";
              indentLevel++;
                
       while (!isAtEnd() && current().type != TokenType::RBRACE) {
            emitStatement();
      }
       
       if (match(TokenType::RBRACE)) {
     // End of if body
       }
  
          indentLevel--;
   indent();
          emit("}");
          
      // Check for else
   if (check(TokenType::ELSE)) {
    emit(" ");
     }
             output << "\n";
     }
       
            if (match(TokenType::END_MARKER)) {
      // Already consumed
         }
            break;
        }
 
        case TokenType::ELSE: {
            advance(); // skip 'else'
   indent();
    emit("else ");
            
         if (match(TokenType::LBRACE)) {
                output << "{\n";
   indentLevel++;
   
  while (!isAtEnd() && current().type != TokenType::RBRACE) {
  emitStatement();
     }
            
      if (match(TokenType::RBRACE)) {
        // End of else body
                }
         
      indentLevel--;
           indent();
     emit("}\n");
    }
  
       if (match(TokenType::END_MARKER)) {
            // Already consumed
    }
     break;
 }
        
      case TokenType::WHILE: {
            advance(); // skip 'while'
   indent();
            emit("while (");
 emitExpression();
        emit(") ");
      
     if (match(TokenType::LBRACE)) {
        output << "{\n";
                indentLevel++;
    
      while (!isAtEnd() && current().type != TokenType::RBRACE) {
        emitStatement();
         }
 
          if (match(TokenType::RBRACE)) {
          // End of while body
         }

       indentLevel--;
    indent();
    emit("}\n");
    }
       
 if (match(TokenType::END_MARKER)) {
       // Already consumed
       }
         break;
        }
        
        case TokenType::IDENTIFIER: {
 // Could be assignment or function call
            Token id = current();
    advance();
   
       if (match(TokenType::ASSIGN)) {
  indent();
                emit(id.lexeme + " = ");
                emitExpression();
   emit(";\n");
                
     if (match(TokenType::END_MARKER)) {
     // Already consumed
     }
            }
            break;
        }
        
    case TokenType::END_MARKER:
  advance();
       break;
  
        default:
     advance();
    break;
    }
}

void CodeGenerator::emitExpression() {
    if (isAtEnd()) return;
    
    Token tok = current();
    
    switch (tok.type) {
        case TokenType::NUMBER:
    case TokenType::STRING:
        case TokenType::IDENTIFIER:
   emit(tok.lexeme);
    advance();
            
      // Handle binary operators
            while (!isAtEnd() && 
   (current().type == TokenType::PLUS ||
  current().type == TokenType::MINUS ||
  current().type == TokenType::MULTIPLY ||
          current().type == TokenType::DIVIDE ||
        current().type == TokenType::MODULO ||
          current().type == TokenType::EQUAL ||
               current().type == TokenType::NOT_EQUAL ||
    current().type == TokenType::LESS ||
current().type == TokenType::GREATER ||
  current().type == TokenType::LESS_EQUAL ||
    current().type == TokenType::GREATER_EQUAL ||
       current().type == TokenType::LOGICAL_AND ||
      current().type == TokenType::LOGICAL_OR)) {
            emit(" " + current().lexeme + " ");
                advance();
    emitExpression();
         break;
            }
   break;
            
        case TokenType::LPAREN:
    emit("(");
            advance();
         emitExpression();
if (match(TokenType::RPAREN)) {
      emit(")");
 }
        break;
            
    default:
      advance();
         break;
    }
}

void CodeGenerator::indent() {
    for (int i = 0; i < indentLevel; i++) {
        output << "    ";
    }
}

void CodeGenerator::emit(const std::string& code) {
    output << code;
}

void CodeGenerator::emitLine(const std::string& code) {
    output << code << "\n";
}

Token CodeGenerator::current() const {
    if (isAtEnd()) {
        return tokens.back();
    }
    return tokens[position];
}

Token CodeGenerator::peek(int offset) const {
    if (position + offset >= tokens.size()) {
 return tokens.back();
    }
    return tokens[position + offset];
}

void CodeGenerator::advance() {
    if (!isAtEnd()) {
        position++;
    }
}

bool CodeGenerator::match(TokenType type) {
    if (check(type)) {
     advance();
        return true;
    }
    return false;
}

bool CodeGenerator::check(TokenType type) const {
    if (isAtEnd()) return false;
    return current().type == type;
}

bool CodeGenerator::isAtEnd() const {
    return position >= tokens.size() || current().type == TokenType::END_OF_FILE;
}

} // namespace Case
