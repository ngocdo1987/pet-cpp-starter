// validation.h
#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

bool isValidEmail(const std::string& email);       // Validate email address
bool isValidNumber(const std::string& number);     // Validate number (integer or floating-point)
bool isValidIPv4(const std::string& ip);           // Validate IPv4 address
bool isValidURL(const std::string& url);           // Validate URL format
bool isValidHexColor(const std::string& color);    // Validate hexadecimal color value
bool isValidJSON(const std::string& json);         // Validate JSON string
bool isValidMinLength(const std::string& str, size_t minLength); // Validate minimum length
bool isValidMaxLength(const std::string& str, size_t maxLength); // Validate maximum length
bool isValidAlphabet(const std::string& str);         // Validate if string contains only alphabetic characters

#endif // VALIDATION_H