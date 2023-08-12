add_executable(openglwindow2
    main.cpp
    MainWindow.cpp MainWindow.h MainWindow.ui
    OpenGLWidget.cpp OpenGLWidget.h
)

target_link_libraries(openglwindow2 PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)