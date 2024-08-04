#include <iostream>
#include <string>
#include <curl/curl.h>
#include <httplib.h>
using namespace std;
using namespace httplib;

int main(void) {
    // HTTP
    Server svr;

    svr.Get("/", [&](const Request & /*req*/, Response &res) {
        res.set_content("Simple C++ server written by httplib (test deploy)", "text/html");
    });

    svr.Get("/test-crawl", [&](const Request & /*req*/, Response &res) {
        res.set_content("Find the way to use curl inside httplib function", "text/html");
    });

    svr.listen("localhost", 1234);
}