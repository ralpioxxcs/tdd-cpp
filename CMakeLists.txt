cmake_minimum_required(VERSION 3.10)

# Project setup
set(PROJECT_NAME tdd-cpp)
project(${PROJECT_NAME})

# Compiler flags
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 17)

# Library
file(GLOB LIB_SRC_FILES ${PROJECT_SOURCE_DIR}/*.cc)
add_library(${PROJECT_NAME} ${LIB_SRC_FILES})

# Executable
add_executable(${PROJECT_NAME}_main ${PROJECT_SOURCE_DIR}/main.cc)
target_link_libraries(${PROJECT_NAME}_main PRIVATE ${PROJECT_NAME})

# Testing
add_subdirectory(./googletest)
enable_testing()
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cc)
add_executable(${PROJECT_NAME}_test ${TEST_SRC_FILES})
target_include_directories(${PROJECT_NAME}_test PRIVATE 
    ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} 
    ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME} gtest)
add_test(unit-test ${PROJECT_NAME}_test)
