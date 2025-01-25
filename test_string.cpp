#include <iostream>
#include "functions/string.h"
#include <locale>

int main() {
    // 1/ str_replace demo
    std::string subject = "Hello, world! Hello, everyone!";
    std::string search = "Hello";
    std::string replace = "Hi";

    // Perform the replacement
    std::string result = str_replace(search, replace, subject);

    // Output the result
    std::cout << "Original string: " << subject << std::endl;
    std::cout << "After replacement: " << result << std::endl;

    // =========================

    // 2/ addslashes demo
    std::string input = "This is a 'test' string with \"quotes\" and a backslash (\\) and a null byte (\0).";

    // Perform the addslashes operation
    std::string result = addslashes(input);

    // Output the result
    std::cout << "Original string: " << input << std::endl;
    std::cout << "After addslashes: " << result << std::endl;

    // =========================

    // 3/ explode demo
    std::string input = "apple,banana,cherry,date";
    std::string delimiter = ",";

    // Perform the explode operation
    std::vector<std::string> result = explode(delimiter, input);

    // Output the result
    std::cout << "Original string: " << input << std::endl;
    std::cout << "After explode: " << std::endl;
    for (const std::string& part : result) {
        std::cout << part << std::endl;
    }

    // =========================

    // 4/ implode demo
    std::vector<std::string> parts = {"apple", "banana", "cherry", "date"};
    std::string delimiter = ",";

    // Perform the implode operation
    std::string result = implode(delimiter, parts);

    // Output the result
    std::cout << "Parts: ";
    for (const std::string& part : parts) {
        std::cout << part << " ";
    }
    std::cout << std::endl;
    std::cout << "After implode: " << result << std::endl;

    // =========================

    // 5/ trim demo
    std::string input = "  \t\n  Hello, World!  \t\n  ";
    std::string characters = " \t\n"; // Characters to trim (whitespace by default)

    // Perform the trim operation
    std::string result = trim(input, characters);

    // Output the result
    std::cout << "Original string: '" << input << "'" << std::endl;
    std::cout << "After trim: '" << result << "'" << std::endl;

    // =========================

    // 6/ money_format demo
    double amount = 1234.5678;

    // Default format: $1234.57
    std::string formatted = money_format(amount);
    std::cout << "Default format: " << formatted << std::endl;

    // Custom format: €1,234.57
    formatted = money_format(amount, "€%.2f");
    std::cout << "Custom format (€): " << formatted << std::endl;

    // Custom format with thousands separator: $1,234.57
    formatted = money_format(amount, "$%'.2f");
    std::cout << "Custom format (thousands separator): " << formatted << std::endl;

    // =========================

    // 7/ number_format demo
    double number = 1234567.891234;

    // Default format: 1,234,568
    std::string formatted = number_format(number);
    std::cout << "Default format: " << formatted << std::endl;

    // Format with 2 decimal places: 1,234,567.89
    formatted = number_format(number, 2);
    std::cout << "With 2 decimal places: " << formatted << std::endl;

    // Custom decimal point and thousands separator: 1.234.567,89
    formatted = number_format(number, 2, ",", ".");
    std::cout << "Custom separators: " << formatted << std::endl;

    // Negative number: -1,234,567.89
    formatted = number_format(-number, 2);
    std::cout << "Negative number: " << formatted << std::endl;

    // =========================

    // 8/ similar_text demo
    std::string str1 = "Hello, World!";
    std::string str2 = "Hello, C++!";
    double percent;

    // Calculate the similarity between the two strings
    int commonLength = similar_text(str1, str2, percent);

    // Output the result
    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;
    std::cout << "Common length: " << commonLength << std::endl;
    std::cout << "Similarity percentage: " << percent << "%" << std::endl;

    // =========================
    // 9/ strtolower demo
    std::string input = "HELLO, WÖRLD! 123";

    // Convert the string to lowercase using the default locale
    std::string result_default = strtolower(input);
    std::cout << "Lowercase (default locale): " << result_default << std::endl;

    // Convert the string to lowercase using a specific locale (e.g., German)
    std::string result_locale = strtolower_locale(input, std::locale("de_DE.UTF-8"));
    std::cout << "Lowercase (German locale): " << result_locale << std::endl;

    // =========================
    // 10/ strtoupper demo
    std::string input = "hello, wörld! 123";

    // Convert the string to uppercase using the default locale
    std::string result_default = strtoupper(input);
    std::cout << "Uppercase (default locale): " << result_default << std::endl;

    // Convert the string to uppercase using a specific locale (e.g., German)
    std::string result_locale = strtoupper_locale(input, std::locale("de_DE.UTF-8"));
    std::cout << "Uppercase (German locale): " << result_locale << std::endl;

    return 0;
}