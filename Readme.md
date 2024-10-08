# How to compile C++
```bash
g++ helloworld.cpp -o build/helloworld
./build/helloworld
```
- How to call on a function found on another file? => https://stackoverflow.com/questions/15891781/how-to-call-on-a-function-found-on-another-file
- How to install C++20 on Ubuntu => https://gasparri.org/2020/07/30/installing-c17-and-c20-on-ubuntu-and-amazon-linux/
```bash
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt install gcc-10 gcc-10-base gcc-10-doc g++-10
sudo apt install libstdc++-10-dev libstdc++-10-doc
```
# Exercises
- https://www.learncpp.com/
- https://www.w3resource.com/cpp-exercises/
- https://github.com/codecrafters-io/build-your-own-x
# jwt-cpp
- https://github.com/Thalhammer/jwt-cpp
```bash
git clone https://github.com/Thalhammer/jwt-cpp.git
cd jwt-cpp
mkdir build
cd build
cmake .. && make
sudo make install
```
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
# Cinatra
Cinatra is a high-performance, easy-to-use http framework developed in Modern C++ (C++20) with the goal of making it easy and quick to develop web applications using the C++ programming language: https://github.com/qicosmos/cinatra
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
# restinio
Cross-platform, efficient, customizable, and robust asynchronous HTTP(S)/WebSocket server C++ library with the right balance between performance and ease of use
- https://github.com/Stiffstream/restinio
- https://stiffstream.com/en/docs/restinio/0.7/
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
# HTTPRequest
Single-header C++ HTTP request class
- https://github.com/elnormous/HTTPRequest
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
- https://github.com/cesanta/mongoose
# Emscripten
Emscripten is a complete compiler toolchain to WebAssembly, using LLVM, with a special focus on speed, size, and the Web platform.
- PORTING: Compile your existing projects written in C or C++ — or any language that uses LLVM — to browsers, Node.js, or wasm runtimes.
- APIs: Emscripten converts OpenGL into WebGL, and has support for familiar APIs like SDL, pthreads, and POSIX, as well as Web APIs and JavaScript.
- FAST: Thanks to the combination of LLVM, Emscripten, Binaryen, and WebAssembly, the output is compact and runs at near-native speed.
URLs
- https://github.com/emscripten-core/emscripten
- https://emscripten.org/
- https://www.codeproject.com/Articles/5250727/Introduction-to-Web-Assembly-with-C-Cplusplus
# Good repo based on Drogon C++
- Gaboot E-Commerce Backend Server: https://github.com/skript023/Gaboot
- Libre Blog - A blog system powered by Drogon.
- -> Libre Blog Backend: https://github.com/fansuregrin/libre-blog
- -> Libre Blog Frontend: https://github.com/fansuregrin/libre-blog-frontend
# Another good repos
- Fast and simple blog system based on SQLite 3 and BBCode written in C++: https://github.com/vldr/LightBlog
- Simple Content Management System by Gradeyard: https://gradeyard.com/index.cgi?page=cmsExample
- C++ Ecommerce CLI system: https://github.com/AtharIbrahim/ECommerce-Cpp
# C++ Web Programming
- https://www.tutorialspoint.com/cplusplus/cpp_web_programming.htm
# Redis
- https://github.com/sewenew/redis-plus-plus
- https://github.com/tdv/redis-cpp
# ElasticSearch
- https://github.com/seznam/elasticlient
# Kafka
- https://github.com/morganstanley/modern-cpp-kafka
- https://github.com/confluentinc/librdkafka
# RabbitMQ
- https://github.com/CopernicaMarketingSoftware/AMQP-CPP