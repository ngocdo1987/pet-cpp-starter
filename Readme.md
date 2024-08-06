# How to compile C++
```bash
g++ helloworld.cpp -o build/helloworld
./build/helloworld
```
- How to call on a function found on another file? => https://stackoverflow.com/questions/15891781/how-to-call-on-a-function-found-on-another-file
# Exercises
- https://www.learncpp.com/
- https://www.w3resource.com/cpp-exercises/
- https://github.com/codecrafters-io/build-your-own-x
# cpp-httplib
Install (after install => /usr/local/include/httplib.h) 
```bash
git clone git@github.com:yhirose/cpp-httplib.git
cd cpp-httplib
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
sudo cmake --build . --target install
```
Compile
```bash
g++ server.cpp -o build/server -lpthread
```
* undefined reference to `pthread_create'
https://stackoverflow.com/questions/17264984/undefined-reference-to-pthread-
# Drogon
Drogon: A C++14/17/20 based HTTP web application framework running on Linux/macOS/Unix/Windows
```bash
sudo apt install git
sudo apt install gcc
sudo apt install g++
sudo apt install cmake
sudo apt install libjsoncpp-dev
sudo apt install uuid-dev
sudo apt install zlib1g-dev
sudo apt install openssl
sudo apt install libssl-dev
git clone https://github.com/drogonframework/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake ..
make && sudo make install
```
# oatpp
🌱Light and powerful C++ web framework for highly scalable and resource-efficient web application. It's zero-dependency and easy-portable.
```bash
git clone git@github.com:oatpp/oatpp.git
cd oatpp
mkdir build && cd build
cmake ..
sudo make install
```
- A complete example of a "CRUD" service (UserService) built with Oat++. => https://github.com/oatpp/example-crud
- OpenApi 3.0.0 docs + Swagger UI for oatpp services => https://github.com/oatpp/oatpp-swagger
# restc-cpp
Modern C++ REST Client library => https://github.com/jgaa/restc-cpp
# ngrest
Fast and easy C++ RESTful WebServices framework => https://github.com/loentar/ngrest
# JSON
JSON for Modern C++
- https://github.com/nlohmann/json
- Copy "single_include/nlohmann" folder to "/user/local/include"
- C/C++ JSON parser/generator benchmark => https://github.com/miloyip/nativejson-benchmark#parsing-time
# rapidjson
A fast JSON parser/generator for C++ with both SAX/DOM style API
- Install => RapidJSON is a header-only C++ library. Just copy the include/rapidjson folder to system or project's include path.
- https://github.com/Tencent/rapidjson
- https://rapidjson.org/
# HTML -> PDF
- https://wkhtmltopdf.org/
- https://github.com/wkhtmltopdf/wkhtmltopdf
# Nginx link function
It is a NGINX module that provides dynamic linking to your application in server context and call the function of your application in location directive
- https://github.com/Taymindis/nginx-link-function
- https://nginx-link-function.github.io/
# C++ chat app
A chat room application developed in C++ using the concepts of multi-threading and socket programming.
- https://github.com/cjchirag7/chatroom-cpp
# POCO
The POCO C++ Libraries are powerful cross-platform C++ libraries for building network- and internet-based applications that run on desktop, server, mobile, IoT, and embedded systems.
- https://github.com/pocoproject/poco
- https://pocoproject.org/
# Mongoose
A Premium Embedded Web Server for electronic devices in a single file
- https://mongoose.ws/
