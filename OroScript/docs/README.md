# OromoScript Programming Language

A modern, statically-typed programming language designed with Oromo language syntax and semantics.

## Overview

OromoScript is a new programming language that brings the beauty and expressiveness of the Oromo language to programming. It features:

- **Oromo Language Syntax**: Keywords and constructs use Oromo language words
- **Static Type System**: Strong, static typing with type inference
- **Modern Features**: First-class functions, pattern matching, and more
- **C++ Implementation**: High-performance compiler and runtime

## Quick Start

### Prerequisites
- CMake 3.15+
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2019+)

### Building
```bash
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

### Running
```bash
./OroScript examples/hello.oro
```

## Language Features

- **Variables**: `tokko x = 10;`
- **Functions**: `taasis foo(x) { ... }`
- **Conditionals**: `yoo ... fi`
- **Loops**: `walin ... irratti`
- **Data Types**: `tokko` (int), `lakkofsa` (float), `jechi` (string), `dhugaa` (bool)

## Project Structure

```
OroScript/
├── src/           # Source code
├── include/       # Header files
├── tests/         # Unit tests
├── examples/      # Sample programs
├── docs/          # Documentation
└── build/         # Build artifacts
```

## Contributing
Contributions are welcome! Please read our contributing guidelines before submitting PRs.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
