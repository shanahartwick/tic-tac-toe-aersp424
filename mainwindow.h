#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <string>

class MainWindow {
public:
    MainWindow(int width, int height, const std::string& title);
    ~MainWindow();

    void run();

private:
    GLFWwindow* window;
    int screenWidth, screenHeight;
    std::string title;
    GLuint boardTexture;

    void initOpenGL();
    void setupTextures();
    void render();
    GLuint loadTexture(const char* filename);
    void drawTexture(GLuint texture, float x, float y, float width, float height);
};

#endif // MAINWINDOW_H
