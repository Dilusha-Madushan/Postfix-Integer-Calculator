/**
 * @file BigInt.cpp
 * @author Your Name
 * @studentID Your Student ID
 */

#include "BigInt.h"

BigInt::BigInt(const std::string& str) {
    isNegative = (str[0] == '-');
    value = str.substr(isNegative ? 1 : 0);
    std::reverse(value.begin(), value.end());
    while (value.length() > 1 && value.back() == '0') {
        value.pop_back();  // Remove leading zeros
    }
}

BigInt::BigInt(long long num) {
    isNegative = (num < 0);
    if (isNegative) num = -num;

    do {
        value.push_back('0' + (num % 10));
        num /= 10;
    } while (num != 0);
}

bool BigInt::isNegativeNumber() const {
    return isNegative && value != "0";
}

unsigned long BigInt::toUnsignedLong() const {
    if (isNegative) throw std::invalid_argument("Negative value not allowed.");
    unsigned long result = 0;
    for (int i = value.size() - 1; i >= 0; --i) {
        result = result * 10 + (value[i] - '0');
    }
    return result;
}

BigInt BigInt::operator+(const BigInt& other) const {
    if (isNegative == other.isNegative) {
        std::string result;
        int carry = 0;
        size_t maxLength = std::max(value.length(), other.value.length());

        for (size_t i = 0; i < maxLength || carry; ++i) {
            int digit1 = i < value.length() ? value[i] - '0' : 0;
            int digit2 = i < other.value.length() ? other.value[i] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        if (isNegative) result.push_back('-');
        std::reverse(result.begin(), result.end());
        return BigInt(result);
    } else {
        // Handle subtraction if signs differ
        // Placeholder - Implement this properly
        return BigInt("0");
    }
}

BigInt BigInt::operator*(const BigInt& other) const {
    std::string result(value.length() + other.value.length(), '0');

    for (int i = 0; i < value.length(); ++i) {
        int carry = 0;
        for (int j = 0; j < other.value.length() || carry; ++j) {
            int sum = result[i + j] - '0' +
                      (value[i] - '0') * (j < other.value.length() ? other.value[j] - '0' : 0) + carry;
            result[i + j] = (sum % 10) + '0';
            carry = sum / 10;
        }
    }

    if ((isNegative != other.isNegative) && result != "0") result.push_back('-');
    std::reverse(result.begin(), result.end());
    return BigInt(result);
}

BigInt BigInt::operator^(unsigned int exponent) const {
    BigInt result("1");
    BigInt base = *this;

    while (exponent != 0) {
        if (exponent % 2 == 1) result = result * base;
        base = base * base;
        exponent >>= 1;
    }

    return result;
}

std::string BigInt::toString() const {
    std::string str = value;
    std::reverse(str.begin(), str.end());
    return isNegative ? "-" + str : str;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bi) {
    return os << bi.toString();
}
