#include <iostream>
#include <string>
#include <curl/curl.h>
#include <httplib.h>
using namespace std;
using namespace httplib;

int main(void) {
    // HTTP
    Server svr;

    svr.Get("/", [](const Request& req, Response& res) {
        res.set_content("Simple C++ server written by httplib (test deploy)", "text/html");
    });

    // Match the request path against a regular expression
    // and extract its captures
    svr.Get(R"(/numbers/(\d+))", [&](const Request& req, Response& res) {
        auto numbers = req.matches[1];
        res.set_content(numbers, "text/html");
    });

    // Capture the second segment of the request path as "id" path param
    svr.Get("/users/:id", [&](const Request& req, Response& res) {
        auto user_id = req.path_params.at("id");
        res.set_content(user_id, "text/html");
    });

    // Extract values from HTTP headers and URL query params
    svr.Get("/body-header-param", [](const Request& req, Response& res) {
        if (req.has_header("Content-Length")) {
            auto val = req.get_header_value("Content-Length");
        }
        if (req.has_param("key")) {
            auto val = req.get_param_value("key");
        }
        res.set_content(req.body, "text/plain");
    });


    // ================================================================================

    svr.Get("/test-crawl", [&](const Request & /*req*/, Response &res) {
        res.set_content("Find the way to use curl inside httplib function", "text/html");
    });

    svr.listen("localhost", 1234);
}