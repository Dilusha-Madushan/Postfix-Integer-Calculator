/**
 * @file AddHandler.h
 * @author Your Name
 * @studentID Your Student ID
 */

#ifndef ADD_HANDLER_H
#define ADD_HANDLER_H

#include "Handler.h"
#include "BigInt.h"
#include <stack>
#include <string>

class AddHandler : public Handler {
public:
    // Override the handle function to perform addition operation
    bool handle(const std::string& token, std::stack<BigInt>& stack) override;
};

#endif // ADD_HANDLER_H
