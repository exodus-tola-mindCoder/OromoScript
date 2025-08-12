cmake_minimum_required(VERSION 3.15)

# Find required packages
find_package(GTest REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Test source files
set(TEST_SOURCES
    test_lexer.cpp
    test_parser.cpp
    test_ast.cpp
    test_semantic.cpp
    test_evaluator.cpp
)

# Create test executable
add_executable(OroScriptTests ${TEST_SOURCES})

# Link libraries
target_link_libraries(OroScriptTests OroScript GTest::gtest GTest::gtest_main)

# Add tests
add_test(NAME OroScriptTests COMMAND OroScriptTests)
