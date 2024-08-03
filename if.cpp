#include <iostream>
using namespace std;

int main() {
    // If
    int x = 20;
    int y = 18;

    if (x > y) {
        cout << "[if] x is greater than y" << endl;
    }

    // If else
    int time = 20;
    cout << "[if else] ";
    if (time < 18) {
        cout << "Good day." << endl;
    } else {
        cout << "Good evening." << endl;
    }

    // If elseif else
    time = 22;
    cout << "[if elseif else] ";
    if (time < 10) {
        cout << "Good morning." << endl;
    } else if (time < 20) {
        cout << "Good day." << endl;
    } else {
        cout << "Good evening." << endl;
    }

    // Short Hand If...Else
    time = 20;
    string result = (time < 18) ? "Good day." : "Good evening.";
    cout << "[short hand if...else] ";
    cout << result << endl;
}