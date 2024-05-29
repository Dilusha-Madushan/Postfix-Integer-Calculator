/**
 * @file Calculator.h
 * @author Your Name
 * @studentID Your Student ID
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "BigInt.h"
#include "Handler.h"
#include "AddHandler.h"
#include "MultiplyHandler.h"
#include "ExponentHandler.h"
#include "Utils.h"

class Calculator {
private:
    Handler* firstHandler;  // Start of the chain of handlers
    bool verbose;  // Verbose mode flag

public:
    Calculator();
    ~Calculator();
    void setVerbose(bool v) { verbose = v; }
    void run();

private:
    void processLine(const std::string& line);
    void initializeHandlers();
};

#endif // CALCULATOR_H
