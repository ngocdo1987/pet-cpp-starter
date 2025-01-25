// main.cpp
#include <iostream>
#include <string>
#include "functions/validation.h"

int main() {
    std::string email, number, ip, url, color, jsonStr;

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

    return 0;
}