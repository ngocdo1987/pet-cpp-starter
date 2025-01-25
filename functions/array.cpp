// array.cpp
#include "array.h"
#include <map>
#include <stdexcept>

// Function to combine two vectors into a map (keys and values)
std::map<std::string, std::string> array_combine(const std::vector<std::string>& keys, const std::vector<std::string>& values) {
    // Check if the sizes of the keys and values vectors are the same
    if (keys.size() != values.size()) {
        throw std::invalid_argument("The number of keys and values must be the same.");
    }

    // Create a map to store the combined keys and values
    std::map<std::string, std::string> result;

    // Iterate through the keys and values and add them to the map
    for (size_t i = 0; i < keys.size(); ++i) {
        result[keys[i]] = values[i];
    }

    return result;
}

// Function to count the occurrences of each value in a vector
std::map<std::string, int> array_count_values(const std::vector<std::string>& values) {
    std::map<std::string, int> result;

    // Iterate through the vector and count occurrences of each value
    for (const std::string& value : values) {
        result[value]++; // Increment the count for the current value
    }

    return result;
}