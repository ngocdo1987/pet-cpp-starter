#include <iostream>
#include <string>
#include <curl/curl.h>
#include <httplib.h>
using namespace std;
using namespace httplib;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void) {
    // HTTP
    Server svr;

    svr.Get("/", [&](const Request & /*req*/, Response &res) {
        res.set_content("Simple C++ server written by httplib (test deploy)", "text/html");
    });

    svr.Get("/test-crawl", [&](const Request & /*req*/, Response &res) {
        CURL *curl;
        CURLcode curlRes;
        std::string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curlRes = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            // std::cout << readBuffer << std::endl;

            res.set_content(readBuffer, "text/html");
        } else {
            res.set_content("LOL", "text/html");
        }
    });

    svr.listen("localhost", 1234);
}