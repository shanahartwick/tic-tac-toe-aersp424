#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
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

    void initOpenGL();
    void setupTextures();
    void render();
};

#endif // MAINWINDOW_H
