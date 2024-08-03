#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

int main() {
    // Read JSON string -> JSON object
    std::ifstream f("example.json");
    json data = json::parse(f);

    cout << "pi: ";
    cout << data["pi"] << endl;
    cout << "happy: ";
    cout << data["happy"] << endl;
    cout << data["none"] << endl;

    
}