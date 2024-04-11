#include "MainWindow.h"
#include "Board.h"

MainWindow::MainWindow(int width, int height, const std::string& title)
    : screenWidth(width), screenHeight(height), title(title) {
    if (!glfwInit()) {
        // Handle error
        return;
    }

    window = glfwCreateWindow(screenWidth, screenHeight, title.c_str(), NULL, NULL);
    if (!window) {
        // Handle error
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);

    if (glewInit() != GLEW_OK) {
        // Handle error
        return;
    }

    initOpenGL();
    setupTextures();
}

MainWindow::~MainWindow() {
    glfwTerminate();
}

void MainWindow::run() {
    while (!glfwWindowShouldClose(window)) {
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void MainWindow::initOpenGL() {
    glViewport(0, 0, screenWidth, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, screenWidth, 0, screenHeight, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void MainWindow::setupTextures() {
    // Load textures here
}

void MainWindow::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Render game board and other elements
}
