#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick();

private:
    QGridLayout* gridLayout;
    QLabel* labels[3][3];
    QPushButton* buttons[3][3];
    char currentPlayer;
    bool gameOver;

    void checkWin(int row, int col);
    void declareWinner(const QString& winner);
    void switchPlayer();
};

#endif // MAINWINDOW_H
