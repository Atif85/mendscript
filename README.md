# MendScript

MendScript is a statically typed, imperative scripting language inspired by the Lua programming language. It is designed to be a lightweight, embeddable language implemented in pure C.

## Core Features

* **Lua-Inspired Syntax**: Uses a clean, indentation-based structure for readability.
* **Static Typing**: Explicit type annotations with support for type inference to ensure safety at compile time.
* **Memory Management**: Uses deterministic **Reference Counting** for resource management (no garbage collector).
* **Custom Virtual Machine**: Compiles source code into bytecode for execution on a stack-based VM.
* **Object Orientation**: Support for classes and structs (in development).

## Project Status

> **Note**: This project is currently under active development and is incomplete. It is being developed as a **Final Year Project (FYP)** for a BS in Computer Science.

Currently implementation focuses on the core compiler toolchain:

* Handwritten Scanner (Lexer) and a Recursive Descent Parser (Pratt Parser for the expressions).
* Bytecode generation and VM execution engine.
* Manual memory management via reference counting logic.

## Repository Structure

* `src/`: Core implementation in C (Frontend & Backend).
* `examples/`: Sample `.mend` files demonstrating language syntax.
* `docs/`: Technical specifications and language grammar.
* `tests/`: Test suites for verifying language functionality.
* `extensions/`: Editor support (Syntax highlighting).

## Build Requirements

* A C compiler (GCC or Clang)
* Make

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.