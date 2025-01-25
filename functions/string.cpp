// string.cpp
#include "string.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <locale>

// Function to replace all occurrences of 'search' with 'replace' in 'subject'
std::string str_replace(const std::string& search, const std::string& replace, const std::string& subject) {
    std::string result = subject;
    size_t pos = 0;

    // Loop through the string and replace all occurrences of 'search' with 'replace'
    while ((pos = result.find(search, pos)) != std::string::npos) {
        result.replace(pos, search.length(), replace);
        pos += replace.length(); // Move past the replaced string
    }

    return result;
}

// Function to add backslashes before characters that need to be escaped
std::string addslashes(const std::string& str) {
    std::string result;
    for (char ch : str) {
        switch (ch) {
            case '\'':
            case '\"':
            case '\\':
            case '\0':
                result += '\\'; // Add a backslash before the character
                result += ch;   // Add the character itself
                break;
            default:
                result += ch;   // Add the character as is
                break;
        }
    }
    return result;
}

// Function to split a string into a vector of strings based on a delimiter
std::vector<std::string> explode(const std::string& delimiter, const std::string& str) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);

    // Loop through the string and split it based on the delimiter
    while (end != std::string::npos) {
        result.push_back(str.substr(start, end - start)); // Add the substring to the result
        start = end + delimiter.length(); // Move the start position
        end = str.find(delimiter, start); // Find the next delimiter
    }

    // Add the last substring
    result.push_back(str.substr(start));

    return result;
}

// Function to join a vector of strings into a single string using a delimiter
std::string implode(const std::string& delimiter, const std::vector<std::string>& parts) {
    std::string result;
    for (size_t i = 0; i < parts.size(); ++i) {
        result += parts[i]; // Add the current part
        if (i < parts.size() - 1) {
            result += delimiter; // Add the delimiter if it's not the last part
        }
    }
    return result;
}

// Function to remove specified characters from the beginning and end of a string
std::string trim(const std::string& str, const std::string& characters) {
    // Find the first character not in the list of characters to trim
    size_t start = str.find_first_not_of(characters);
    if (start == std::string::npos) {
        return ""; // If all characters are to be trimmed, return an empty string
    }

    // Find the last character not in the list of characters to trim
    size_t end = str.find_last_not_of(characters);

    // Return the substring from start to end
    return str.substr(start, end - start + 1);
}

// Function to format a number as a currency string
std::string money_format(double amount, const std::string& format) {
    // Buffer to hold the formatted string
    char buffer[100];

    // Use snprintf to format the amount according to the format string
    int result = snprintf(buffer, sizeof(buffer), format.c_str(), amount);

    // Check for errors in formatting
    if (result < 0 || result >= sizeof(buffer)) {
        throw std::runtime_error("Error formatting money value");
    }

    return std::string(buffer);
}

// Function to format a number with grouped thousands and optional decimal places
std::string number_format(double number, int decimals, const std::string& decimal_point, const std::string& thousands_separator) {
    // Handle negative numbers
    bool isNegative = number < 0;
    number = std::abs(number);

    // Split the number into integer and fractional parts
    double integerPart;
    double fractionalPart = std::modf(number, &integerPart);

    // Format the integer part with thousands separators
    std::stringstream integerStream;
    integerStream.imbue(std::locale("")); // Use the system locale for thousands separators
    integerStream << std::fixed << std::setprecision(0) << integerPart;
    std::string integerStr = integerStream.str();

    // Replace the system's thousands separator with the specified one
    if (thousands_separator != ",") {
        size_t pos = 0;
        while ((pos = integerStr.find(",", pos)) != std::string::npos) {
            integerStr.replace(pos, 1, thousands_separator);
            pos += thousands_separator.length();
        }
    }

    // Format the fractional part
    std::string fractionalStr;
    if (decimals > 0) {
        std::stringstream fractionalStream;
        fractionalStream << std::fixed << std::setprecision(decimals) << fractionalPart;
        fractionalStr = fractionalStream.str().substr(1); // Remove the "0" before the decimal point
    }

    // Combine the integer and fractional parts
    std::string result = integerStr + fractionalStr;

    // Add the decimal point if necessary
    if (decimals > 0) {
        result.insert(result.length() - decimals, decimal_point);
    }

    // Add the negative sign if necessary
    if (isNegative) {
        result.insert(0, "-");
    }

    return result;
}

// Function to calculate the similarity between two strings
int similar_text(const std::string& str1, const std::string& str2, double& percent) {
    int len1 = str1.length();
    int len2 = str2.length();
    int maxLen = std::max(len1, len2);

    if (maxLen == 0) {
        percent = 100.0;
        return 0;
    }

    // Create a 2D vector to store the lengths of common substrings
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the longest common substring
    int commonLength = dp[len1][len2];

    // Calculate the similarity percentage
    percent = (commonLength * 200.0) / (len1 + len2);

    return commonLength;
}

// Function to convert a string to lowercase using the default locale
std::string strtolower(const std::string& str) {
    std::string result = str; // Create a copy of the input string
    std::transform(result.begin(), result.end(), result.begin(), ::tolower); // Convert to lowercase
    return result;
}

// Function to convert a string to lowercase using a specified locale
std::string strtolower_locale(const std::string& str, const std::locale& loc) {
    std::string result = str; // Create a copy of the input string
    std::transform(result.begin(), result.end(), result.begin(), [&loc](char ch) {
        return std::tolower(ch, loc); // Convert to lowercase using the specified locale
    });
    return result;
}

// Function to convert a string to uppercase using the default locale
std::string strtoupper(const std::string& str) {
    std::string result = str; // Create a copy of the input string
    std::transform(result.begin(), result.end(), result.begin(), ::toupper); // Convert to uppercase
    return result;
}

// Function to convert a string to uppercase using a specified locale
std::string strtoupper_locale(const std::string& str, const std::locale& loc) {
    std::string result = str; // Create a copy of the input string
    std::transform(result.begin(), result.end(), result.begin(), [&loc](char ch) {
        return std::toupper(ch, loc); // Convert to uppercase using the specified locale
    });
    return result;
}