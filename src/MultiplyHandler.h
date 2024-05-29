/**
 * @file MultiplyHandler.h
 * @author Your Name
 * @studentID Your Student ID
 */

#ifndef MULTIPLY_HANDLER_H
#define MULTIPLY_HANDLER_H

#include "Handler.h"
#include "BigInt.h"
#include <stack>
#include <string>

class MultiplyHandler : public Handler {
public:
    // Override the handle function to perform multiplication operation
    bool handle(const std::string& token, std::stack<BigInt>& stack) override;
};

#endif // MULTIPLY_HANDLER_H
