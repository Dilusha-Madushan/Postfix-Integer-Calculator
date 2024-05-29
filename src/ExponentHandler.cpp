/**
 * @file ExponentHandler.cpp
 * @author Your Name
 * @studentID Your Student ID
 */

#include "ExponentHandler.h"
#include <iostream>

bool ExponentHandler::handle(const std::string& token, std::stack<BigInt>& stack) {
    if (token == "^") {
        // Check if there are enough operands in the stack
        if (stack.size() < 2) {
            std::cerr << "Invalid argument: Not enough operands to execute exponentiation operation." << std::endl;
            return false;
        }

        // Pop the top two elements from the stack
        BigInt exponent = stack.top(); stack.pop();
        BigInt base = stack.top(); stack.pop();

        // Check for negative exponents, which are not handled by this simple implementation
        if (exponent.isNegativeNumber()) {
            std::cerr << "Exponent cannot be negative in this calculator." << std::endl;
            return false;
        }

        try {
            // Convert exponent to an unsigned long, if possible
            unsigned long exp_value = exponent.toUnsignedLong();

            // Perform exponentiation and push the result back on the stack
            stack.push(base ^ exp_value);
        } catch (const std::exception& e) {
            std::cerr << "Error in exponentiation: " << e.what() << std::endl;
            return false;
        }

        // Return true indicating the token has been handled
        return true;
    }
    // If the token is not "^", pass it to the next handler in the chain
    return nextHandler ? nextHandler->handle(token, stack) : false;
}
