## Usage

- Ref :: [fmt documentation](https://hackingcpp.com/cpp/libs/fmt.html#nav-roota)

```cpp
// hello.cpp
#include <fmt/core.h> 
int main () {
  int x = 10;
  int y = 20;
  fmt::print("Hello, World!\n");
  fmt::println("Hello, World {}\n", x);
  fmt::println("Hello, World {1} {0}\n", x, y);
}
```

## Configuration

### 1. As a submodule

- Clone as a subdirectory
```shell
# From the root of your project -> Clone this as a subdirectory of your project
git clone https://github.com/fmtlib/fmt.git
```

- Use the below CMakeLists.txt
```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10) 
project(FmtDemo) 
add_subdirectory(fmt)
add_executable(greet hello.cpp)                                                                                                                                                                                                                                                              
# set to C++17 (not required)
set_property(TARGET greet PROPERTY CXX_STANDARD 17)
target_link_libraries(greet fmt::fmt)
```

- Build the project
```shell
cd fmt_demo  # Base dir
mkdir build  # directory for build output
cd build
cmake ..     # generate build scripts
make 
./greet 
```

## 2. Separate Build, Install

- Build `fmt` library separately

```shell
# Clone this outside your project at any location
git clone https://github.com/fmtlib/fmt.git
cd fmt
mkdir build   # directory for build output
cd build
cmake ..      # generate build scripts
make

sudo make install # installation
```

- Use the below CMakeLists.txt

```cmake
# below CMakeLists.txt
cmake_minimum_required(VERSION 3.10) 
project(FmtDemo) 
find_package(fmt)
add_executable(greet hello.cpp)                                                                                                                                                                                                          # set to C++17 (not required)
set_property(TARGET greet PROPERTY CXX_STANDARD 17)
target_link_libraries(greet fmt::fmt)
```

- Build your project
```shell
cd fmt_demo      # project directory
mkdir build  # directory for build output
cd build
cmake ..     # generate build scripts
make

./greet      # Execute it
```