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