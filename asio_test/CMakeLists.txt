cmake_minimum_required(VERSION 3.14)

project(asio_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(asio CONFIG REQUIRED)

add_executable(server server.cpp)
# target_link_libraries(server PRIVATE asio::asio)

add_executable(client client.cpp)
# target_link_libraries(client PRIVATE asio::asio)
