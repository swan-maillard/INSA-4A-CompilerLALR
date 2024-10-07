# LALR Calculator

This project implements a simple LALR (Look-Ahead Left-to-right) calculator in C++. It includes a lexer and an automaton that processes a given input string, allowing for basic arithmetic operations and parentheses. The compiler reads expressions from the standard input, tokenizes them, and evaluates them.

## Features

- **Lexer**: Tokenizes input strings to identify symbols like numbers, parentheses, and arithmetic operators.
- **Automaton**: Implements the LALR parsing algorithm to evaluate expressions.
- **Interactive Console**: Allows users to input expressions and receive results interactively.
- **Error Handling**: Provides basic error detection for invalid expressions.

## Getting Started

### Prerequisites

To build and run this project, you need to have a C++ compiler (g++) and makefile to simplify compilation.

### Building the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/swan-maillard/INSA-4A-CalculatorLALR.git
   cd INSA-4A-CalculatorLALR
   ```

2. Compile the code:

   ```bash
   make
   ```

### Running the Compiler

After building the project, you can run the compiler:

```bash
make run
```

You will be prompted with `>>>`, where you can enter expressions like `3 + 4 * (2 - 1)` and receive the evaluated result. To exit the interactive session, type `q` or use `Ctrl+D`.

## Authors

- Alix Peigue (alix.peigue@insa-lyon.fr)
- Swan Maillard (maillard.swan@gmail.com)

## Licence

This project is licensed under the MIT License - see the `LICENSE` file for details.
