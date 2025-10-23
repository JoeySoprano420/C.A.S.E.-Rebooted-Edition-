# Quick Start - C.A.S.E. Programming Language

Get up and running with C.A.S.E. in 5 minutes!

## Step 1: Clone and Build (2 minutes)

### Windows
```cmd
git clone https://github.com/JoeySoprano420/C.A.S.E.-Programming-Language-.git
cd C.A.S.E.-Programming-Language-
build.bat
```

### Linux/macOS
```bash
git clone https://github.com/JoeySoprano420/C.A.S.E.-Programming-Language-.git
cd C.A.S.E.-Programming-Language-
chmod +x build.sh
./build.sh
```

## Step 2: Write Your First Program (30 seconds)

Create `myprogram.case`:

```case
print("Hello from C.A.S.E.!") [end]

let name = "Developer" [end]
print(name) [end]

let x = 42 [end]
let y = 58 [end]
let sum = x + y [end]

print("The answer is:") [end]
print(sum) [end]
```

## Step 3: Compile and Run (30 seconds)

### Windows
```cmd
bin\case-transpiler.exe myprogram.case
g++ compiler.cpp -o myprogram.exe
myprogram.exe
```

### Linux/macOS
```bash
./bin/case-transpiler myprogram.case
g++ compiler.cpp -o myprogram
./myprogram
```

**Output:**
```
Hello from C.A.S.E.!
Developer
The answer is:
100
```

## Step 4: Try the Examples (2 minutes)

```bash
# Run the examples
./bin/case-transpiler examples/hello.case && g++ compiler.cpp -o hello && ./hello
./bin/case-transpiler examples/calculator.case && g++ compiler.cpp -o calc && ./calc
./bin/case-transpiler examples/fizzbuzz.case && g++ compiler.cpp -o fizz && ./fizz
```

## Step 5: Learn More

- **[Full Documentation](README.md)** - Complete language reference
- **[Getting Started Guide](GETTING_STARTED.md)** - Detailed tutorial
- **[Examples](examples/)** - More example programs
- **[Contributing](CONTRIBUTING.md)** - How to contribute

## Common Commands

```bash
# Transpile only
./bin/case-transpiler input.case output.cpp

# Full workflow
./bin/case-transpiler input.case && g++ compiler.cpp -o program && ./program

# Show version
./bin/case-transpiler --version

# Show help
./bin/case-transpiler --help

# Run tests
./test.sh  # or test.bat on Windows
```

## Next Steps

1. **Learn the Syntax**: Read the [Getting Started Guide](GETTING_STARTED.md)
2. **Explore Examples**: Check out the `examples/` directory
3. **Build Something**: Create your own C.A.S.E. program
4. **Contribute**: Help improve C.A.S.E.!

## Need Help?

- ?? **Documentation**: See README.md
- ?? **Bug Reports**: Open an issue on GitHub
- ?? **Questions**: Start a discussion on GitHub
- ?? **Contributing**: See CONTRIBUTING.md

---

**Welcome to C.A.S.E.!** ??

You're now ready to start programming in C.A.S.E. Have fun!
