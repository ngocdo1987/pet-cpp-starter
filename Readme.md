# How to compile C++
```bash
g++ helloworld.cpp -o build/helloworld
./build/helloworld
```
# cpp-httplib
Install 
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