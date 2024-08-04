// https://www.geeksforgeeks.org/how-to-validate-user-input-in-cpp/
#include <iostream>
#include <limits>
#include <string>
#include <regex>
using namespace std;

bool isValidPassword(const string& password) {
    if (password.length() < 8) return false;
    bool hasLower = false, hasUpper = false, hasDigit = false;
    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        if (isupper(ch)) hasUpper = true;
        if (isdigit(ch)) hasDigit = true;
    }
    return hasLower && hasUpper && hasDigit;
}

int main() {
    int number;
    cout << "Enter an integer: ";
    while (!(cin >> number)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "You entered: " << number << endl;

    // ======================================

    string email;
    regex email_pattern(R"((\w+)(\.{1}\w+)*@(\w+)(\.{1}\w+)+)");

    cout << "Enter an email address: ";
    getline(cin, email);

    if (!regex_match(email, email_pattern)) {
        cerr << "Invalid email format." << endl;
    } else {
        cout << "Valid email: " << email << endl;
    }

    // ======================================

    string password;
    cout << "Enter a password (at least 8 characters, including uppercase, lowercase, and a digit): ";
    cin >> password;
    while (!isValidPassword(password)) {
        cout << "Invalid password. Please enter a valid password: ";
        cin >> password;
    }
    cout << "You entered a valid password." << endl;

    return 0;
}