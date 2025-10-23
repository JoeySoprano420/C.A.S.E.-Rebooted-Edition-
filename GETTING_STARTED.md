# C.A.S.E. Programming Language - Getting Started

Welcome to C.A.S.E. (Comprehensive Adaptive Syntax Engine)!

## Quick Start Guide

### Prerequisites

- C++ compiler (GCC, Clang, or MSVC)
- Git (for cloning the repository)
- A text editor (VS Code recommended)

### Installation

#### Windows

```bash
# Clone the repository
git clone https://github.com/JoeySoprano420/C.A.S.E.-Programming-Language-.git
cd C.A.S.E.-Programming-Language-

# Build the transpiler
build.bat

# Run your first program
bin\case-transpiler.exe examples\hello.case
g++ compiler.cpp -o hello.exe
hello.exe
```

#### Linux/macOS

```bash
# Clone the repository
git clone https://github.com/JoeySoprano420/C.A.S.E.-Programming-Language-.git
cd C.A.S.E.-Programming-Language-

# Make build script executable
chmod +x build.sh

# Build the transpiler
./build.sh

# Run your first program
./bin/case-transpiler examples/hello.case
g++ compiler.cpp -o hello
./hello
```

### Your First Program

Create a file called `hello.case`:

```case
print("Hello, World!") [end]
```

Compile and run:

```bash
# Transpile to C++
case-transpiler hello.case

# Compile C++
g++ compiler.cpp -o hello

# Run
./hello
```

## Basic Syntax

### Variables

```case
let x = 42 [end]
let name = "Alice" [end]
let pi = 3.14159 [end]
```

### Functions

```case
Fn greet "name" (
    Print "Hello, " + name [end]
) [end]

call greet "World" [end]
```

### Control Flow

```case
# If-else
if x > 10 {
    Print "Greater than 10" [end]
} else {
    Print "Less than or equal to 10" [end]
} [end]

# While loop
let count = 0
while count < 5 {
    Print count [end]
    mutate count count + 1 [end]
}
```

### Mathematical Operations

```case
let sum = 5 + 3 [end]
let product = 4 * 7 [end]
let root = sqrt 16 [end]
let power = pow 2 10 [end]
```

## Next Steps

1. **Explore Examples** - Check out the `examples/` directory for more programs
2. **Read the Language Reference** - See `docs/LANGUAGE_REFERENCE.md`
3. **Try the Tutorials** - Follow `docs/TUTORIALS.md`
4. **Install VS Code Extension** - Get syntax highlighting and more

## Need Help?

- ?? **Documentation**: See the `docs/` folder
- ?? **Issues**: Report bugs on GitHub
- ?? **Discussions**: Ask questions on GitHub Discussions

## Contributing

We welcome contributions! See `CONTRIBUTING.md` for guidelines.

---

**Happy coding with C.A.S.E.!** ??
