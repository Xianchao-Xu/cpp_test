#include "MainWindow.h"
#include "OpenGLWidget.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    this->setup_ui(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setup_ui(QMainWindow* window)
{
    QWidget* central_widget = new QWidget(window);
    window->setCentralWidget(central_widget);

    QVBoxLayout* vertical_layout = new QVBoxLayout(central_widget);
    vertical_layout->setContentsMargins(0, 0, 0, 0);

    OpenGLWidget* opengl_widget = new OpenGLWidget(window);
    vertical_layout->addWidget(opengl_widget);
}
