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