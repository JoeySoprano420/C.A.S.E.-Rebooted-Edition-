#!/bin/bash

# C.A.S.E. Programming Language - Build Script
# Builds the transpiler from source

echo "Building C.A.S.E. Transpiler..."

# Check for compiler
if command -v g++ &> /dev/null; then
    COMPILER="g++"
elif command -v clang++ &> /dev/null; then
    COMPILER="clang++"
else
    echo "Error: No C++ compiler found. Please install g++ or clang++."
    exit 1
fi

# Create bin directory
mkdir -p bin

# Compile the transpiler (single translation unit)
echo "Compiling with $COMPILER..."
$COMPILER -std=c++14 src/transpiler/main.cpp \
    -o bin/case-transpiler \
    -I src/transpiler/include \
    -O2

if [ $? -eq 0 ]; then
    echo "? Build successful! Transpiler created at: bin/case-transpiler"
    echo ""
    echo "Usage:"
    echo "  ./bin/case-transpiler <input.case> [output.cpp]"
    echo ""
    echo "Try:"
    echo "  ./bin/case-transpiler examples/hello.case"
    echo "  g++ compiler.cpp -o hello"
    echo "  ./hello"
else
    echo "? Build failed!"
    exit 1
fi
