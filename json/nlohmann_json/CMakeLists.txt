cmake_minimum_required(VERSION 3.15)

project(nlohmann_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(nlohmann_json REQUIRED)

add_executable(nlohmann_test
    nlohmann_test.cpp
)
target_link_libraries(nlohmann_test PRIVATE nlohmann_json::nlohmann_json)
