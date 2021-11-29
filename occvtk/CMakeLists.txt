cmake_minimum_required(VERSION 3.15)

project(occvtk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VTK_DIR "C:\\Dev\\VTK\\lib\\cmake\\vtk-9.1")

find_package(VTK COMPONENTS 
 vtkCommonCore
 vtkFiltersCore
 vtkCommonDataModel
 vtkInteractionStyle
 vtkRenderingContextOpenGL2
 vtkRenderingCore
 vtkRenderingFreeType
 vtkRenderingGL2PSOpenGL2
 vtkRenderingOpenGL2
 QUIET
)

include_directories("C:\\Dev\\OCCT\\inc")
link_directories("C:\\Dev\\OCCT\\win64\\vc14\\lib")

add_executable(make_box make_box.cpp)
target_link_libraries(make_box TKPrim TKIVtk TKMath TKernel TKTopAlgo TKGeomAlgo TKV3d ${VTK_LIBRARIES})

add_executable(make_box2 make_box2.cpp)
target_link_libraries(make_box2 TKPrim TKIVtk TKMath TKernel TKTopAlgo TKGeomAlgo TKV3d ${VTK_LIBRARIES})

add_executable(import_step import_step.cpp)
target_link_libraries(import_step TKSTEP TKIVtk TKV3d TKGeomAlgo TKMath TKXSBase TKernel ${VTK_LIBRARIES})

add_executable(import_step2 import_step2.cpp)
target_link_libraries(import_step2 TKSTEP TKIVtk TKV3d TKGeomAlgo TKMath TKXSBase TKernel ${VTK_LIBRARIES})

add_executable(import_step3 import_step3.cpp)
target_link_libraries(import_step3 TKSTEP TKIVtk TKV3d TKGeomAlgo TKMath TKXSBase TKernel ${VTK_LIBRARIES})
vtk_module_autoinit(
    TARGETS import_step3
    MODULES ${VTK_LIBRARIES}
)
