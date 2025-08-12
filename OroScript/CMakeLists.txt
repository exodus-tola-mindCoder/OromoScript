# cmake_minimum_required(VERSION 3.15)
# project(OroScript VERSION 1.0.0 LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Set output directories
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# # Include directories
# include_directories(${CMAKE_SOURCE_DIR}/include)

# # Source files
# set(SOURCES
#     src/main.cpp
#     src/lexer/Lexer.cpp
#     src/parser/Parser.cpp
#     src/ast/Node.cpp
#     src/ast/Visitor.cpp
#     src/evaluator/Evaluator.cpp
#     src/semantic/SemanticAnalyzer.cpp
#     src/utils/Errors.cpp
#     src/utils/SymbolTable.cpp
# )

# # Header files
# set(HEADERS
#     include/lexer/Lexer.h
#     include/parser/Parser.h
#     include/ast/Node.h
#     include/ast/Visitor.h
#     include/evaluator/Evaluator.h
#     include/semantic/SemanticAnalyzer.h
#     include/utils/Errors.h
#     include/utils/SymbolTable.h
# )

# # Create executable
# add_executable(OroScript ${SOURCES})

# # Link directories
# target_include_directories(OroScript PRIVATE ${CMAKE_SOURCE_DIR}/include)

# # Enable testing
# enable_testing()
# add_subdirectory(tests)


cmake_minimum_required(VERSION 3.10)
project(AfaanCodeInterpreter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(afaancode
    src/main.cpp
    src/ast/Node.cpp
    src/ast/Visitor.cpp
    src/evaluator/Evaluator.cpp
    src/lexer/Lexer.cpp
    src/parser/Parser.cpp
    src/semantic/SemanticAnalyzer.cpp
    src/utils/Errors.cpp
    src/utils/SymbolTable.cpp
)

# For tests (add Catch2 or similar later)
add_subdirectory(tests)
