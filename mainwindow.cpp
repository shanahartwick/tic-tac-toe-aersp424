#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    // Set up the main window
    setWindowTitle("Tic Tac Toe");
    resize(300, 300);

    // Initialize variables
    currentPlayer = 'X';
    gameOver = false;

    // Set up the grid layout
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    gridLayout = new QGridLayout(centralWidget);

    // Load images for X and O
    QPixmap xPixmap(":/x.png");
    QPixmap oPixmap(":/o.png");

    // Populate the grid layout with labels and buttons
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            labels[row][col] = new QLabel(this);
            labels[row][col]->setFixedSize(100, 100);
            gridLayout->addWidget(labels[row][col], row, col);

            buttons[row][col] = new QPushButton("", this);
            buttons[row][col]->setFixedSize(100, 100);
            gridLayout->addWidget(buttons[row][col], row, col);
            connect(buttons[row][col], &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        }
    }

    // Set up images for the labels
    labels[0][0]->setPixmap(QPixmap(":/tictactoeboard.png"));
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            labels[row][col]->setScaledContents(true);
        }
    }
}

MainWindow::~MainWindow()
{
}

void MainWindow::handleButtonClick()
{
    if (gameOver)
        return;

    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (buttons[row][col] == clickedButton) {
                if (labels[row][col]->text().isEmpty()) {
                    if (currentPlayer == 'X') {
                        labels[row][col]->setPixmap(QPixmap(":/x.png"));
                    }
                    else {
                        labels[row][col]->setPixmap(QPixmap(":/o.png"));
                    }
                    checkWin(row, col);
                    switchPlayer();
                }
                return;
            }
        }
    }
}

void MainWindow::checkWin(int row, int col)
{
    // Check for a win
    // Implement your logic here
}

void MainWindow::declareWinner(const QString& winner)
{
    QMessageBox::information(this, "Game Over", winner + " wins!");
    gameOver = true;
}

void MainWindow::switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
