/**
 * @file Utils.h
 * @author Your Name
 * @studentID Your Student ID
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

class Utils {
public:
    // Trims leading and trailing whitespace from a string
    static std::string trim(const std::string& str);

    // Splits a string into tokens by a delimiter
    static std::vector<std::string> split(const std::string& str, char delimiter);
};

#endif // UTILS_H
