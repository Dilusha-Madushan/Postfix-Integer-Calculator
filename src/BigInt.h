/**
 * @file BigInt.h
 * @author Your Name
 * @studentID Your Student ID
 */

#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class BigInt {
private:
    std::string value;  // digits stored in reverse order for easier arithmetic
    bool isNegative;  // true if the number is negative

public:
    BigInt(const std::string& str = "0");
    BigInt(long long num);

    // Utility functions
    bool isNegativeNumber() const;
    unsigned long toUnsignedLong() const;

    // Arithmetic operations
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator^(unsigned int exponent) const;

    // Additional methods
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const BigInt& bi);
};

#endif // BIGINT_H
