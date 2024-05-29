/**
 * @file AddHandler.cpp
 * @author Your Name
 * @studentID Your Student ID
 */


#include "AddHandler.h"
#include <iostream>

bool AddHandler::handle(const std::string& token, std::stack<BigInt>& stack) {
    if (token == "+") {
        // Check if there are enough operands in the stack
        if (stack.size() < 2) {
            std::cerr << "Invalid argument: Not enough operands to execute add operation." << std::endl;
            return false;
        }

        // Pop the top two elements from the stack
        BigInt a = stack.top(); stack.pop();
        BigInt b = stack.top(); stack.pop();

        // Perform addition and push the result back on the stack
        stack.push(b + a);

        // Return true indicating the token has been handled
        return true;
    }
    // If the token is not "+", pass it to the next handler in the chain
    return nextHandler ? nextHandler->handle(token, stack) : false;
}
