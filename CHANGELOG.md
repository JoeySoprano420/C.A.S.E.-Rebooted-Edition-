# Changelog

All notable changes to the C.A.S.E. Programming Language will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Planned
- Full AST implementation
- Complete standard library mapping
- VS Code extension
- Self-hosted compiler
- Test suite expansion
- Language server protocol

## [1.0.0-alpha] - 2025-01-XX

### Added
- Initial repository structure
- Basic transpiler implementation
  - Lexer with keyword recognition
  - Code generator for C++ output
  - Main driver with CLI interface
- Core language features
  - `print` statements
  - Variable declarations with `let`
  - Basic functions (simplified)
  - Control flow (`if`, `else`, `while`)
  - Expressions with operators
  - `[end]` terminators
- Example programs
  - hello.case - Hello World
  - calculator.case - Basic calculator
  - factorial.case - Recursive factorial
  - fizzbuzz.case - FizzBuzz implementation
  - stdlib_demo.case - Standard library showcase
- Documentation
  - Comprehensive README.md
  - GETTING_STARTED.md guide
  - QUICKSTART.md for rapid setup
  - CONTRIBUTING.md guidelines
  - PROJECT_STATUS.md tracking
- Build system
  - build.sh for Linux/macOS
  - build.bat for Windows
  - test.sh/test.bat for testing
- Project infrastructure
  - .gitignore configuration
  - MIT License
  - GitHub repository setup

### Known Issues
- Function parameter parsing is simplified
- Standard library functions not yet fully mapped
- Complex expressions need better precedence handling
- Error messages are basic
- Type checking not implemented
- Some keywords (mutate, channel, thread, etc.) not yet implemented

## [0.9.0] - Design Phase

### Completed
- Language design and specification
- Keyword set definition (98+ keywords)
- Syntax design with `[end]` terminators
- Feature planning across 9 categories
- Documentation writing

## [0.1.0] - Concept

### Initial
- Language concept and philosophy
- Core design principles
- Target feature set identification

---

## Release Notes

### Version 1.0.0-alpha

This is the first alpha release of C.A.S.E., featuring a working transpiler that converts C.A.S.E. code to C++. While many advanced features are still in development, the core language functionality is operational and ready for experimentation.

**What Works:**
- Basic programs compile and run successfully
- Core syntax is functional
- Example programs demonstrate capabilities
- Build system works cross-platform

**What's Coming:**
- Enhanced error messages
- Complete standard library
- All 98+ keywords implemented
- VS Code extension
- Comprehensive test suite

**Try It Out:**
```bash
git clone https://github.com/JoeySoprano420/C.A.S.E.-Programming-Language-.git
cd C.A.S.E.-Programming-Language-
./build.sh  # or build.bat on Windows
./bin/case-transpiler examples/hello.case
g++ compiler.cpp -o hello
./hello
```

---

For more information, see:
- [README.md](README.md) - Complete documentation
- [QUICKSTART.md](QUICKSTART.md) - 5-minute setup
- [PROJECT_STATUS.md](PROJECT_STATUS.md) - Current status and roadmap
