// validation.cpp
#include "validation.h"
#include <regex>
#include <nlohmann/json.hpp> // Include the nlohmann/json library

using json = nlohmann::json;

// Function to validate an email address
bool isValidEmail(const std::string& email) {
    const std::regex pattern(R"((^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$))");
    return std::regex_match(email, pattern);
}

// Function to validate a number (integer or floating-point)
bool isValidNumber(const std::string& number) {
    const std::regex pattern(R"(^-?\d+(\.\d+)?$)");
    return std::regex_match(number, pattern);
}

// Function to validate an IPv4 address
bool isValidIPv4(const std::string& ip) {
    const std::regex pattern(R"(^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)");
    return std::regex_match(ip, pattern);
}

// Function to validate a URL
bool isValidURL(const std::string& url) {
    const std::regex pattern(R"(^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$)");
    return std::regex_match(url, pattern);
}

// Function to validate a hexadecimal color value
bool isValidHexColor(const std::string& color) {
    const std::regex pattern(R"(^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$)");
    return std::regex_match(color, pattern);
}

// Function to validate a JSON string using nlohmann/json
bool isValidJSON(const std::string& jsonStr) {
    try {
        // Attempt to parse the JSON string
        json parsedJson = json::parse(jsonStr);
        return true; // If parsing succeeds, the JSON is valid
    } catch (const json::parse_error& e) {
        // If parsing fails, the JSON is invalid
        return false;
    }
}

// Function to validate minimum length of a string
bool isValidMinLength(const std::string& str, size_t minLength) {
    return str.length() >= minLength;
}

// Function to validate maximum length of a string
bool isValidMaxLength(const std::string& str, size_t maxLength) {
    return str.length() <= maxLength;
}

// Function to validate if a string contains only alphabetic characters
bool isValidAlphabet(const std::string& str) {
    for (char ch : str) {
        if (!std::isalpha(ch)) {
            return false; // Return false if any character is not alphabetic
        }
    }
    return true; // Return true if all characters are alphabetic
}