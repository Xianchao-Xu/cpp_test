cmake_minimum_required(VERSION 3.14)

project(matplotplusplus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(matplot++ CONFIG REQUIRED)

add_executable(matplotxx_test matplotxx_test.cpp)
target_link_libraries(matplotxx_test PRIVATE Matplot++::cimg std::filesystem Matplot++::matplot Matplot++::nodesoup)
