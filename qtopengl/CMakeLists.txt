cmake_minimum_required(VERSION 3.15)

project(qtopengl LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(Qt5 COMPONENTS Gui Core Widgets REQUIRED)

add_executable(openglwindow
    main.cpp
    MainWindow.cpp MainWindow.h
    OpenGLWidget.cpp OpenGLWidget.h
)

target_link_libraries(openglwindow PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)
