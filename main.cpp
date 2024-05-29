/**
 * @file main.cpp
 * @author Your Name
 * @studentID Your Student ID
 */

#include "src/Calculator.h"
#include <cstring> // for strcmp

int main(int argc, char* argv[]) {
    Calculator calc;
    bool verbose = false;

    // Parse command line arguments
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0) {
            std::cout << "Usage: ./calc [-h] [-v]\n"
                         "Options:\n"
                         "  -h   Show help\n"
                         "  -v   Enable verbose output\n"
                         "Enter 'quit' to exit the program.\n";
            return 0; // Exit after showing help
        } else if (strcmp(argv[i], "-v") == 0) {
            verbose = true;
        }
    }

    // Set the verbose mode based on the command line argument
    calc.setVerbose(verbose);
    calc.run();

    return 0;
}