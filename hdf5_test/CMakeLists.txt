cmake_minimum_required(VERSION 3.15)

project(HDF5Test LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(HDF5 REQUIRED COMPONENTS C CXX)
find_package(MPI REQUIRED COMPONENTS C)

add_executable(writedata writedata.cpp)
target_link_libraries(writedata
    PRIVATE
        MPI::MPI_C
        hdf5::hdf5 hdf5::hdf5_cpp
)
