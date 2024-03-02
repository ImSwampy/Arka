cmake_minimum_required(VERSION 3.27)
project(my_own_programming_language)

set(
    CMAKE_CXX_STANDARD 23
    EXECUTABLE_OUTPUT_PATH /build
)

include_directories(src)

add_executable(my_own_programming_language
    src/Types.h 
    src/Tokenizer.cpp 
    src/Tokenizer.h 
    src/main.cpp
)
