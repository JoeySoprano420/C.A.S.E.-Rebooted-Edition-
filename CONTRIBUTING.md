# Contributing to C.A.S.E.

Thank you for your interest in contributing to the C.A.S.E. Programming Language!

## How to Contribute

### Reporting Bugs

If you find a bug, please create an issue with:
- A clear description of the problem
- Steps to reproduce
- Expected vs actual behavior
- Your environment (OS, compiler version, etc.)

### Suggesting Features

We love new ideas! Please create an issue with:
- A clear description of the feature
- Use cases and examples
- Why it would be valuable

### Submitting Code

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/my-new-feature
   ```
3. **Make your changes**
4. **Test your changes**
   - Ensure the transpiler builds
   - Test with example programs
   - Add new test cases if needed
5. **Commit with clear messages**
   ```bash
   git commit -m "Add feature: description"
   ```
6. **Push to your fork**
   ```bash
   git push origin feature/my-new-feature
   ```
7. **Create a Pull Request**

## Code Style

### C++ Code
- Use consistent indentation (4 spaces)
- Follow C++14 standards
- Comment complex logic
- Keep functions focused and small

### C.A.S.E. Code
- Use `[end]` terminators consistently
- Follow naming conventions (CamelCase for functions)
- Add comments for complex logic
- Include examples in documentation

### Documentation
- Use clear, concise language
- Include code examples
- Keep README files up to date
- Add docstrings to functions

## Development Setup

### Prerequisites
- C++ compiler (GCC 7+, Clang 6+, or MSVC 2017+)
- Git
- Text editor or IDE

### Build from Source
```bash
git clone https://github.com/JoeySoprano420/C.A.S.E.-Programming-Language-.git
cd C.A.S.E.-Programming-Language-
./build.sh  # or build.bat on Windows
```

### Testing
```bash
# Run test suite (when available)
./test.sh

# Test specific example
./bin/case-transpiler examples/calculator.case
g++ compiler.cpp -o calculator
./calculator
```

## Areas for Contribution

### High Priority
- [ ] Complete transpiler implementation
- [ ] Error message improvements
- [ ] Standard library functions
- [ ] Test suite expansion
- [ ] Documentation improvements

### Medium Priority
- [ ] VS Code extension features
- [ ] Additional examples
- [ ] Performance optimizations
- [ ] Cross-platform testing

### Low Priority
- [ ] Language server protocol
- [ ] Debugger support
- [ ] Package manager
- [ ] Web playground

## Questions?

Feel free to open an issue with the "question" label, or start a discussion on GitHub Discussions.

## Code of Conduct

Be respectful, constructive, and welcoming to all contributors. We're building something great together!

---

Thank you for contributing to C.A.S.E.! ??
