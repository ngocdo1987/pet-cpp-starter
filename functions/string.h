// string.h
#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>
#include <locale>

std::string str_replace(const std::string& search, const std::string& replace, const std::string& subject);

std::string addslashes(const std::string& str);

std::vector<std::string> explode(const std::string& delimiter, const std::string& str);

std::string implode(const std::string& delimiter, const std::vector<std::string>& parts);

std::string trim(const std::string& str, const std::string& characters = " \t\n\r\v\f");

std::string money_format(double amount, const std::string& format = "$%.2f");

std::string number_format(double number, int decimals = 0, const std::string& decimal_point = ".", const std::string& thousands_separator = ",");

int similar_text(const std::string& str1, const std::string& str2, double& percent);

// Function to convert a string to lowercase using the default locale
std::string strtolower(const std::string& str);

// Function to convert a string to lowercase using a specified locale
std::string strtolower_locale(const std::string& str, const std::locale& loc = std::locale());

// Function to convert a string to uppercase using the default locale
std::string strtoupper(const std::string& str);

// Function to convert a string to uppercase using a specified locale
std::string strtoupper_locale(const std::string& str, const std::locale& loc = std::locale());

#endif // STRING_H