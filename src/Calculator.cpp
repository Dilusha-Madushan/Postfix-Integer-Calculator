/**
 * @file Calculator.cpp
 * @author Your Name
 * @studentID Your Student ID
 */

#include "Calculator.h"

Calculator::Calculator() : verbose(false) {
    initializeHandlers();
}

Calculator::~Calculator() {
    delete firstHandler;  // This will cascade delete through the chain
}

void Calculator::initializeHandlers() {
    firstHandler = new AddHandler();
    Handler* multiplyHandler = new MultiplyHandler();
    Handler* exponentHandler = new ExponentHandler();

    firstHandler->setNextHandler(multiplyHandler);
    multiplyHandler->setNextHandler(exponentHandler);
    exponentHandler->setNextHandler(nullptr);  // End of the chain
}

void Calculator::run() {
    std::string line;
    std::cout << "Enter equations (postfix notation), or type 'quit' to exit:" << std::endl;

    while (std::getline(std::cin, line)) {
        if (line == "quit") break;
        line = Utils::trim(line);  // Trim leading and trailing whitespaces
        if (!line.empty() && line[0] != '#') {  // Ignore comments and empty lines
            processLine(line);
        }
    }
}


//void Calculator::processLine(const std::string& line) {
//    std::vector<std::string> tokens = Utils::split(line, ' ');
//    std::stack<BigInt> stack;
//
//    for (const std::string& token : tokens) {
//        if (isdigit(token[0]) || token[0] == '-' && token.size() > 1) {  // Check if token is a number
//            stack.push(BigInt(token));  // Push number onto stack
//        } else {
//            if (!firstHandler->handle(token, stack) && verbose) {
//                std::cerr << "Unhandled token or insufficient operands: " << token << std::endl;
//            }
//        }
//    }
//
//    if (!stack.empty()) {
//        BigInt result = stack.top();
//        stack.pop();
//        std::cout << line << " = " << result << std::endl;
//        if (verbose && !stack.empty()) {
//            std::cerr << "Error: Stack is not empty after processing. Remaining items may indicate an error." << std::endl;
//        }
//    } else {
//        std::cerr << "No result for the expression: " << line << std::endl;
//    }
//}

void Calculator::processLine(const std::string& line) {
    std::vector<std::string> tokens = Utils::split(line, ' ');
    std::stack<BigInt> stack;
    bool errorOccurred = false;

    for (const std::string& token : tokens) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {  // Check if the token is a number
            if (!errorOccurred) {
                stack.push(BigInt(token));  // Only push if no previous error has occurred
            }
        } else {  // It's an operator
            if (stack.size() < 2) {
                std::cerr << "Invalid operation: Not enough operands for '" << token << "' operation." << std::endl;
                errorOccurred = true;
                break;  // Stop processing this line due to error
            }
            if (!firstHandler->handle(token, stack)) {
                std::cerr << "Unhandled token or insufficient operands: " << token << std::endl;
                errorOccurred = true;
                break;  // Stop processing this line due to error
            }
        }
    }

    if (!errorOccurred && !stack.empty()) {
        BigInt result = stack.top();
        stack.pop();
        std::cout << line << " = " << result << std::endl;
    }

    // Check if there are any remaining items in the stack after processing
    if (!stack.empty() || errorOccurred) {
        std::cerr << "Error: Stack is not empty after processing or errors occurred. Clearing stack. Remaining items may indicate an error: ";
        while (!stack.empty()) {
            std::cerr << stack.top() << " ";
            stack.pop();
        }
        std::cerr << std::endl;
    }

    // Clear the stack at the end of processing to ensure no state is carried over
    while (!stack.empty()) {
        stack.pop();
    }
}




