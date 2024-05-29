/**
 * @file Utils.cpp
 * @author Your Name
 * @studentID Your Student ID
 */

#include "Utils.h"

std::string Utils::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)
        return ""; // No non-whitespace characters

    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

std::vector<std::string> Utils::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    size_t start = 0, end = 0;

    while ((end = str.find(delimiter, start)) != std::string::npos) {
        token = str.substr(start, end - start);
        if (!token.empty()) {
            tokens.push_back(trim(token));  // Trim each token to remove extra spaces
        }
        start = end + 1;
    }
    token = str.substr(start); // Capture any text after the last delimiter
    if (!token.empty()) {
        tokens.push_back(trim(token));  // Trim the last token
    }
    return tokens;
}
