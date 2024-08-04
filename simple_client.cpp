#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
#include <iostream>
using namespace httplib;
using namespace std;

int main(void) {
    Client cli("https://google.com");

    auto res = cli.Get("/");
    // res->status;
    // res->body;

    cout << res->body;
}