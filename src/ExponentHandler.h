/**
 * @file ExponentHandler.h
 * @author Your Name
 * @studentID Your Student ID
 */

#ifndef EXPONENT_HANDLER_H
#define EXPONENT_HANDLER_H

#include "Handler.h"
#include "BigInt.h"
#include <stack>
#include <string>

class ExponentHandler : public Handler {
public:
    // Override the handle function to perform exponentiation operation
    bool handle(const std::string& token, std::stack<BigInt>& stack) override;
};

#endif // EXPONENT_HANDLER_H
