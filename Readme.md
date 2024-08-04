# How to compile C++
```bash
g++ helloworld.cpp -o build/helloworld
./build/helloworld
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
https://stackoverflow.com/questions/17264984/undefined-reference-to-pthread-create
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