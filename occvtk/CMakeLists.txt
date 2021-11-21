cmake_minimum_required(VERSION 3.15)

project(occvtk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("C:\\Dev\\opencascade\\OCCT\\inc")
include_directories("C:\\Dev\\vcpkg\\installed\\x64-windows\\include\\vtk-9.0")
link_directories("C:\\Dev\\opencascade\\OCCT\\win64\\vc14\\lib")

add_executable(make_box make_box.cpp)
target_link_libraries(make_box TKBREP TKIVtk TKPrim Tkernel TKTopAlgo TKV3d)

add_executable(import_step import_step.cpp)
target_link_libraries(import_step TKBRep TKIVtk TKSTEP  TKernel TKV3d TKXSBase)
