#include <httplib.h>
using namespace httplib;

int main(void) {
    // HTTP
    Server svr;

    svr.Get("/", [&](const Request & /*req*/, Response &res) {
        res.set_content("Simple C++ server", "text/html");
    });

    svr.listen("localhost", 1234);
}