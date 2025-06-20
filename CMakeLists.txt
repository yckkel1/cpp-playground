cmake_minimum_required(VERSION 3.15)
project(Cpp20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Include headers
include_directories(include)

# 2. Glob all source files under src/
file(GLOB SRC_FILES src/*.cpp)

# 3. Define executable using main.cpp + all src files
add_executable(main main.cpp ${SRC_FILES})
