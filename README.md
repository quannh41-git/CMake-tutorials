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
cmake .. ==> outputs a series of status messages to inform the configuration
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

**CMake structure:**
1. Makefile: the set of instructions that `make` will run to build the project
2. CMakeFiles: temp file, used for dectect OS, compiler
3. cmake_install.cmake: script handling install rules
4. CMakeCache.txt: filename suggests, this is used by CMake when re-running the configuration

- CMake does not enforce a specific name or location for build directory. We could use:
```
mkdir -p /tmp/someplace
cd /tmp/someplace
cmake /path-to-source
cmake --build .
```

- CMake generates more `targets` needed for building the executable itself:
1. all
2. clean
3. depend
4. depend: invoke CMake to generate the dependencies for the source files
5. rebuild_cache: to rebuild the CMakeCache.txt. This is needed in case new entries from the source need to be added
6. edit_cache: let you edit cache entries directly
7. test: run test suite with the help of CTest
8. install: execute the installation rules for the project
9. package: invoke **CPack** to generate a redistributable package for the project
```
cmake --build . --target <target-name>
```
### Recipe-02/03-Building and Linking Static and Shared Libraries

```
add_library(message STATIC Message.hpp Message.cpp)
```
- The first argument to `add_library` is the name of target, actual name will be form by CMake with prefix `lib`
- The library extension is determined based on the second argument **STATIC** or **SHARED** 

```
target_link_libraries(hello-world message)
```
- Links the library into the executable, this also guarantee that the `hello-world` executable properly depends on the `message` library.

### Recipe-04/05-Conditional and Present option

- Set variable
```
set(BUILD_SHARED_LIBS OFF)

or

list(APPEND _sources Message.hpp Message.cpp)
```

- Add option
```
option(USE_LIBRARY "Compile sources into a library?" OFF)
```
- When compile
```
cmake -D USE_LIBRARY=ON ..
```