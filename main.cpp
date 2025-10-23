// C.A.S.E. Programming Language Transpiler
// Main Entry Point

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Forward declarations to avoid header dependencies in this simple version
namespace Case {
    class Lexer;
    class CodeGenerator;
    struct Token;
}

#include "token.cpp"
#include "codegen.cpp"

void printBanner() {
    std::cout << "?????????????????????????????????????????????????\n";
  std::cout << "?  C.A.S.E. Programming Language Transpiler     ?\n";
  std::cout << "?  Version 1.0.0             ?\n";
    std::cout << "?  Comprehensive Adaptive Syntax Engine         ?\n";
    std::cout << "?????????????????????????????????????????????????\n";
    std::cout << "\n";
}

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
std::cerr << "Error: Could not open file '" << filename << "'\n";
        return "";
    }
    
    std::string content;
  std::string line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }
    
    return content;
}

void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not write to file '" << filename << "'\n";
        return;
    }

    file << content;
    file.close();
}

int main(int argc, char* argv[]) {
    printBanner();
    
    if (argc < 2) {
  std::cout << "Usage: case-transpiler <input.case> [output.cpp]\n";
        std::cout << "\n";
        std::cout << "Options:\n";
        std::cout << "  --version    Show version information\n";
      std::cout << "  --help  Show this help message\n";
 return 1;
    }
    
    std::string inputFile = argv[1];
    std::string outputFile = argc >= 3 ? argv[2] : "compiler.cpp";
    
  if (inputFile == "--version") {
  std::cout << "C.A.S.E. Transpiler v1.0.0\n";
        return 0;
    }
    
    if (inputFile == "--help") {
   std::cout << "C.A.S.E. Programming Language Transpiler\n";
     std::cout << "\n";
        std::cout << "Transpiles C.A.S.E. code to C++\n";
    std::cout << "\n";
      std::cout << "Usage:\n";
        std::cout << "  case-transpiler input.case [output.cpp]\n";
   std::cout << "\n";
        std::cout << "Example:\n";
        std::cout << "  case-transpiler hello.case hello.cpp\n";
        std::cout << "  g++ hello.cpp -o hello\n";
        std::cout << "  ./hello\n";
        return 0;
    }
    
    std::cout << "Reading input file: " << inputFile << "\n";
    std::string source = readFile(inputFile);
    
  if (source.empty()) {
        return 1;
    }
 
std::cout << "Tokenizing...\n";
 Case::Lexer lexer(source);
    std::vector<Case::Token> tokens = lexer.tokenize();
    std::cout << "Found " << tokens.size() << " tokens\n";
    
    std::cout << "Generating C++ code...\n";
    Case::CodeGenerator codegen;
    std::string cppCode = codegen.generate(tokens);
    
    std::cout << "Writing output file: " << outputFile << "\n";
    writeFile(outputFile, cppCode);
    
    std::cout << "\n";
    std::cout << "? Transpilation successful!\n";
    std::cout << "\n";
    std::cout << "Next steps:\n";
    std::cout << "  1. Compile: g++ " << outputFile << " -o program\n";
    std::cout << "  2. Run: ./program\n";
    
  return 0;
}
