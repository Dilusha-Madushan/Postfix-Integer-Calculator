/**
 * @file Handler.h
 * @author Your Name
 * @studentID Your Student ID
 */

#ifndef HANDLER_H
#define HANDLER_H

#include <string>
#include <stack>
#include "BigInt.h"

// Abstract base class for all handlers in the Chain of Responsibility
class Handler {
protected:
    Handler* nextHandler;  // Pointer to the next handler in the chain

public:
    // Constructor initializes the next handler to nullptr
    Handler() : nextHandler(nullptr) {}

    // Virtual destructor to ensure proper cleanup of derived handlers
    virtual ~Handler() {
        delete nextHandler;  // Clean up the next handler in the chain
    }

    // Set the next handler in the chain
    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

    // Abstract handle function that must be implemented by concrete handlers
    virtual bool handle(const std::string& token, std::stack<BigInt>& stack) = 0;
};

#endif // HANDLER_H
