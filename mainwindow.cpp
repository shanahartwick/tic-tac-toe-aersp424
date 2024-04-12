#include "MainWindow.h"
#include "Board.h"

MainWindow::MainWindow(int width, int height, const std::string& title)
    : screenWidth(width), screenHeight(height), title(title), boardTexture(0) {
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

GLuint MainWindow::loadTexture(const char* filename) {
    GLuint textureID = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (textureID == 0) {
        // Handle error
    }
    return textureID;
}

void MainWindow::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw game board
    drawTexture(boardTexture, 0, 0, screenWidth, screenHeight);

    // Render other elements
}

void MainWindow::drawTexture(GLuint texture, float x, float y, float width, float height) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2f(x, y);
    glTexCoord2f(1, 0); glVertex2f(x + width, y);
    glTexCoord2f(1, 1); glVertex2f(x + width, y + height);
    glTexCoord2f(0, 1); glVertex2f(x, y + height);
    glEnd();
}
