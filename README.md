# CMake-tutorials
Learn CMake from CMake Cookbook
---
CMake is a build system generator. It can be used for C, C++, Fortran language.




---
## Chap 1 - From a Simple Executable to libraries

### Recipe-01-Compiling a single source file into an executable
- Config project by creating and stepping into a `build` directory
```
mkdir -p build 
cd build
cmake ..
```
or command with the same effect
```
cmake -H. -Bbuild
```

`-H` instructs CMake to search for the root CMakeLists.txt file in the current directory

`-Bbuild` tells CMake to generate all of its files in a directory called `build`


- Configuration for project has been generated in the build directory
```
cmake --build .
```