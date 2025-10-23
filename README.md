# C.A.S.E. Transpiler Source Code

This directory contains the implementation of the C.A.S.E. transpiler.

## Directory Structure

```
src/transpiler/
??? include/
? ??? token.hpp# Token definitions and Lexer interface
?   ??? codegen.hpp      # Code generator interface
??? main.cpp             # Main entry point and CLI
??? token.cpp            # Lexer implementation
??? codegen.cpp     # Code generator implementation
```

## Components

### Lexer (`token.hpp` / `token.cpp`)

**Purpose**: Converts C.A.S.E. source code into a stream of tokens.

**Key Classes**:
- `Token` - Represents a single token with type, lexeme, and position
- `Lexer` - Tokenizes source code

**Supported Tokens**:
- Keywords: `print`, `let`, `Fn`, `if`, `else`, `while`, etc.
- Operators: `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`, etc.
- Literals: Numbers, strings, identifiers
- Special: `[end]` terminators

**Example**:
```cpp
Case::Lexer lexer("print(\"Hello\") [end]");
std::vector<Case::Token> tokens = lexer.tokenize();
// tokens: [PRINT, LPAREN, STRING("Hello"), RPAREN, END_MARKER, EOF]
```

### Code Generator (`codegen.hpp` / `codegen.cpp`)

**Purpose**: Generates C++ code from tokens.

**Key Class**:
- `CodeGenerator` - Converts token stream to C++ source code

**Generates**:
- C++ headers (`#include <iostream>`, etc.)
- `main()` function
- Statement translations
- Expression handling
- Proper indentation

**Example**:
```cpp
Case::CodeGenerator codegen;
std::string cppCode = codegen.generate(tokens);
// Output: C++ code ready to compile
```

### Main Driver (`main.cpp`)

**Purpose**: CLI interface and compilation orchestration.

**Features**:
- File I/O (read .case files, write .cpp files)
- Command-line argument parsing
- Banner display
- Error handling
- Version/help commands

**Usage**:
```bash
case-transpiler input.case [output.cpp]
case-transpiler --version
case-transpiler --help
```

## Compilation

### Single Command (Recommended)
```bash
g++ -std=c++14 src/transpiler/main.cpp -o bin/case-transpiler -I src/transpiler/include -O2
```

### Or use the build scripts
```bash
./build.sh      # Linux/macOS
build.bat   # Windows
```

## Architecture

```
Source Code (.case)
?
[Lexer]
    ?
Tokens
    ?
[Code Generator]
  ?
C++ Code (.cpp)
    ?
[g++]
?
Executable
```

## Implementation Notes

### Current Design
- **Simple and Direct**: Token-based code generation without full AST
- **Single Pass**: Lexing and code generation in one pass through pipeline
- **Modular**: Separate concerns (lexing, code gen, main driver)

### Future Enhancements
- **Full AST**: Build complete abstract syntax tree
- **Semantic Analysis**: Type checking, scope analysis
- **Optimization**: Constant folding, dead code elimination
- **Better Error Recovery**: Continue parsing after errors
- **More Keywords**: Implement all 98+ keywords

## Development

### Adding a New Keyword

1. **Add to token.hpp**
   ```cpp
   enum class TokenType {
       // ... existing ...
       MY_NEW_KEYWORD,
   };
   ```

2. **Add to token.cpp keywords map**
   ```cpp
   static std::unordered_map<std::string, TokenType> keywords = {
       // ... existing ...
       {"mynewkeyword", TokenType::MY_NEW_KEYWORD},
   };
   ```

3. **Handle in codegen.cpp**
   ```cpp
   case TokenType::MY_NEW_KEYWORD:
       // Generate C++ code
       break;
   ```

### Adding a New Operator

1. **Add to TokenType enum**
2. **Handle in `makeOperator()` in token.cpp**
3. **Handle in `emitExpression()` in codegen.cpp**

### Testing Your Changes

```bash
# Rebuild
./build.sh

# Test with example
./bin/case-transpiler examples/hello.case
g++ compiler.cpp -o hello
./hello
```

## Code Style

- **Indentation**: 4 spaces
- **Naming**: 
  - Classes: `PascalCase`
  - Functions: `camelCase`
  - Variables: `camelCase`
  - Constants: `UPPER_CASE`
- **Comments**: Explain "why", not "what"
- **Includes**: Standard library first, then project headers

## Performance

Current implementation is optimized for:
- **Simplicity**: Easy to understand and modify
- **Correctness**: Generates valid C++ code
- **Build Speed**: Fast compilation

Future optimizations could include:
- String pool for identifiers
- Token caching
- Incremental compilation
- Parallel processing

## Dependencies

- **STL Only**: No external dependencies
- **C++14**: Standard library features
- **Portable**: Works on Windows, Linux, macOS

## Testing

See `test.sh` / `test.bat` in the root directory for automated tests.

Manual testing:
```bash
# Create test file
echo 'print("test") [end]' > test.case

# Compile
./bin/case-transpiler test.case

# Check output
cat compiler.cpp

# Compile and run
g++ compiler.cpp -o test && ./test
```

## Contributing

See [CONTRIBUTING.md](../../CONTRIBUTING.md) in the root directory.

## License

MIT License - see [LICENSE](../../LICENSE) in the root directory.

---

For more information, see the main [README.md](../../README.md).
