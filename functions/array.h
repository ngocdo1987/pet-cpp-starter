// array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <string>
#include <map>

// Function to combine two vectors into a map (keys and values)
std::map<std::string, std::string> array_combine(const std::vector<std::string>& keys, const std::vector<std::string>& values);

// Function to count the occurrences of each value in a vector
std::map<std::string, int> array_count_values(const std::vector<std::string>& values);

#endif // ARRAY_H