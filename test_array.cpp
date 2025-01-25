// main.cpp
#include <iostream>
#include "functions/array.h"

int main() {
    // 1/ Demo for array_combine function
    std::vector<std::string> keys = {"name", "age", "city"};
    std::vector<std::string> values = {"John", "30", "New York"};

    try {
        // Combine the keys and values into a map
        std::map<std::string, std::string> result = array_combine(keys, values);

        // Output the result
        std::cout << "Combined array:" << std::endl;
        for (const auto& pair : result) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // =========================

    // 2/ Demo for array_count_values function
    std::vector<std::string> values = {"apple", "banana", "apple", "orange", "banana", "apple"};

    // Count the occurrences of each value
    std::map<std::string, int> result = array_count_values(values);

    // Output the result
    std::cout << "Value counts:" << std::endl;
    for (const auto& pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // =========================

    return 0;
}