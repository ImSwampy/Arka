cmake_minimum_required(VERSION 3.27)
project(my_own_programming_language)

set(
    CMAKE_CXX_STANDARD 23
    EXECUTABLE_OUTPUT_PATH /build
)

include_directories(src)

add_executable(my_own_programming_language
    src/Types.h 
    src/tokenizer/Tokenizer.cpp 
    src/tokenizer/Tokenizer.h 
    src/main.cpp
    src/utils/ReadFile.cpp
    src/utils/ReadFile.h
    src/parser/Parser.cpp
    src/parser/Parser.h
    src/parser/AST/AST.cpp
    src/parser/AST/AST.h
    src/parser/parser_types/Body/Body.h
    src/parser/parser_types/Body/Body.cpp
    src/parser/parser_types/Class/Class.h
    src/parser/parser_types/Class/Class.cpp
    src/parser/parser_types/Expression/Expression.h
    src/parser/parser_types/Expression/Expression.cpp
    src/parser/parser_types/Function/Function.h
    src/parser/parser_types/Function/Function.cpp
    src/parser/parser_types/Preprocess/Preprocess.h
    src/parser/parser_types/Preprocess/Preprocess.cpp
    src/parser/parser_types/Program/Program.h
    src/parser/parser_types/Program/Program.cpp
)
