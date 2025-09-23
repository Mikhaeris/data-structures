# Build library
create folder
```
mkdir build
cd build
```
build library
```
cmake -S .. -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
sudo cmake --install build
sudo ldconfig
```
