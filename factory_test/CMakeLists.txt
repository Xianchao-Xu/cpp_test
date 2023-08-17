cmake_minimum_required(VERSION 3.15)

project(FactoryFunction LANGUAGES CXX)

# gtest需要c++14以上的版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译文件路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if(WIN32)
    add_definitions(-DWIN32)
    if(BUILD_SHARED_LIBS)
        add_definitions(-DWIN32DLL)
    endif()
else()
    add_definitions(-DLINUX)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}
)

add_subdirectory(Element)
add_subdirectory(Solver)

add_executable(main 
    main.cpp
    Model.cpp Model.h
)
target_link_libraries(main
    Element
    Solver
)
