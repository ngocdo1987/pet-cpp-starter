// main.cpp
#include <iostream>
#include <string>
#include "functions/validation.h"

int main() {
    std::string email, number, ip, url, color, jsonStr, inputStr;
    size_t minLength, maxLength;

    // Test email validation
    std::cout << "Enter an email address: ";
    std::getline(std::cin, email);

    if (isValidEmail(email)) {
        std::cout << "The email address is valid." << std::endl;
    } else {
        std::cout << "The email address is invalid." << std::endl;
    }

    // Test number validation
    std::cout << "Enter a number: ";
    std::getline(std::cin, number);

    if (isValidNumber(number)) {
        std::cout << "The number is valid." << std::endl;
    } else {
        std::cout << "The number is invalid." << std::endl;
    }

    // Test IPv4 validation
    std::cout << "Enter an IPv4 address: ";
    std::getline(std::cin, ip);

    if (isValidIPv4(ip)) {
        std::cout << "The IPv4 address is valid." << std::endl;
    } else {
        std::cout << "The IPv4 address is invalid." << std::endl;
    }

    // Test URL validation
    std::cout << "Enter a URL: ";
    std::getline(std::cin, url);

    if (isValidURL(url)) {
        std::cout << "The URL is valid." << std::endl;
    } else {
        std::cout << "The URL is invalid." << std::endl;
    }

    // Test hexadecimal color validation
    std::cout << "Enter a hexadecimal color value: ";
    std::getline(std::cin, color);

    if (isValidHexColor(color)) {
        std::cout << "The hexadecimal color value is valid." << std::endl;
    } else {
        std::cout << "The hexadecimal color value is invalid." << std::endl;
    }

    // Test JSON validation
    std::cout << "Enter a JSON string: ";
    std::getline(std::cin, jsonStr);

    if (isValidJSON(jsonStr)) {
        std::cout << "The JSON string is valid." << std::endl;
    } else {
        std::cout << "The JSON string is invalid." << std::endl;
    }

    // Test minimum length validation
    std::cout << "Enter a string to check its minimum length: ";
    std::getline(std::cin, inputStr);
    std::cout << "Enter the minimum required length: ";
    std::cin >> minLength;
    std::cin.ignore(); // Ignore the newline character left in the input buffer

    if (isValidMinLength(inputStr, minLength)) {
        std::cout << "The string meets the minimum length requirement." << std::endl;
    } else {
        std::cout << "The string does not meet the minimum length requirement." << std::endl;
    }

    // Test maximum length validation
    std::cout << "Enter a string to check its maximum length: ";
    std::getline(std::cin, inputStr);
    std::cout << "Enter the maximum allowed length: ";
    std::cin >> maxLength;
    std::cin.ignore(); // Ignore the newline character left in the input buffer

    if (isValidMaxLength(inputStr, maxLength)) {
        std::cout << "The string meets the maximum length requirement." << std::endl;
    } else {
        std::cout << "The string does not meet the maximum length requirement." << std::endl;
    }

    // Test alphabetic validation
    std::cout << "Enter a string to check if it contains only alphabetic characters: ";
    std::getline(std::cin, inputStr);

    if (isValidAlphabet(inputStr)) {
        std::cout << "The string contains only alphabetic characters." << std::endl;
    } else {
        std::cout << "The string contains non-alphabetic characters." << std::endl;
    }

    return 0;
}