# Postfix Integer Calculator

## Project Overview

This project implements a simple calculator that processes expressions written in postfix notation (also known as Reverse Polish Notation). The calculator supports operations for addition, multiplication, and exponentiation of arbitrarily large integers using a custom `BigInt` class.

## Files and Directories

- **src/**
    - **main.cpp**: Entry point of the application. It handles command-line arguments and initializes the calculator's interactive mode.
    - **Calculator.cpp/h**: Defines the `Calculator` class which orchestrates reading input, processing expressions using the Chain of Responsibility pattern, and outputting results.
    - **BigInt.cpp/h**: Implements the `BigInt` class for handling large integers beyond standard type limits.
    - **Handler.h**: Abstract base class for all handlers in the Chain of Responsibility pattern.
    - **AddHandler.cpp/h**, **MultiplyHandler.cpp/h**, **ExponentHandler.cpp/h**: Concrete handler classes that implement addition, multiplication, and exponentiation respectively.
    - **Utils.cpp/h**: Contains utility functions such as trimming strings and splitting strings into tokens.

- **include/**: Contains any additional library headers your project might use.

- **tests/**: (Optional) Contains unit tests for various components of the application.

- **docs/**: (Optional) Additional documentation like diagrams or detailed descriptions.

- **CMakeLists.txt**: Build configuration file.

## Building the Project

This project uses CMake for building. Ensure CMake and a suitable C++ compiler are installed on your system.

### Compilation Steps:

1. **Clone the Repository:**
   ```bash
   git clone [YourRepositoryURL]
   cd PostfixIntegerCalculator
   ```

2. **Create a Build Directory:**
   ```bash
   mkdir build
   cd build
   ```

3. **Generate Build Configuration:**
   ```bash
   cmake ..
   ```

4. **Compile the Project:**
   ```bash
   make
   ```

This will generate an executable named `PostfixIntegerCalculator` within the `build` directory.

## Running the Application

To run the calculator, you can use the following commands:

- **Interactive Mode:**
  ```bash
  ./PostfixIntegerCalculator
  ```
  Once started, you can enter expressions in postfix notation directly.

- **Using Command Line Arguments:**
    - `-h` to display help text.
    - `-v` to enable verbose output which provides detailed debug information.

  ```bash
  ./PostfixIntegerCalculator -v
  ```

- **Processing Input from a File:**
  ```bash
  ./PostfixIntegerCalculator < input.txt
  ```
  Ensure `input.txt` contains postfix expressions, one per line.

## Example Usage

```bash
# Interactive mode
./PostfixIntegerCalculator
Enter equations (postfix notation), or type 'quit' to exit:
12 3 + 
15
quit
```


