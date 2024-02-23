#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow),
    player1Time(0),
    player2Time(0),
    currentPlayer(1),
    gameTime(0),
    pQTimer(new QTimer(this))
{
    ui->setupUi(this);

    // Initialize the game time, player times, and QTimer
    connect(pQTimer, SIGNAL(timeout()), this, SLOT(timeout()));

    // Connect the buttons to their slots
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopGame()));
    connect(ui->time1, SIGNAL(clicked()), this, SLOT(twoMinutes()));
    connect(ui->time2, SIGNAL(clicked()), this, SLOT(fiveMinutes()));
    connect(ui->switch1, SIGNAL(clicked()), this, SLOT(switchPlayer2()));
    connect(ui->switch2, SIGNAL(clicked()), this, SLOT(switchPlayer1()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if (currentPlayer == 1) {
        player1Time--;
        if (player1Time <= 0) {
            // Player 1 ran out of time
            setGameInfoText("Player 2 WON!!", 12); 
        }
    } else {
        player2Time--;
        if (player2Time <= 0) {
            // Player 2 ran out of time
            setGameInfoText("Player 1 WON!", 12);   
        }
    }
    updateProgressBar();
}

void MainWindow::updateProgressBar()
{
    ui->progressBar1->setValue(player1Time * 100 / gameTime);
    ui->progressBar2->setValue(player2Time * 100 / gameTime);
}

void MainWindow::setGameInfoText(QString text, short fontSize)
{
    ui->label->setText(text);
    QFont font = ui->label->font();
    font.setBold(true);
    font.setPointSize(fontSize);
    ui->label->setFont(font);
}

void MainWindow::startGame()
{
    // Check if gameTime is not selected
    if(gameTime == 0) {
        return;
    }

    // Check if game time is not selected, set default game time to 10 seconds
    //For testing purposes
    /*if (gameTime == 0) {
        gameTime = 10; // Default game time
    }*/

    // Set the initial time for players according to the game time
    player1Time = gameTime;
    player2Time = gameTime;

    // Start Qtimer, which emits a timeout signal every second
    pQTimer->start(1000);

    currentPlayer = 1;

    updateProgressBar();
    setGameInfoText("Game ongoing", 12);
}

void MainWindow::stopGame()
{

    if (pQTimer->isActive()) {
        // Stop Qtimer
        pQTimer->stop();
    } else {
        return;
    }

    player1Time = 0;
    player2Time = 0;

    updateProgressBar();

    setGameInfoText("New game via start button", 12);
}

void MainWindow::twoMinutes()
{
    gameTime = 120;

    player1Time = gameTime;
    player2Time = gameTime;

    updateProgressBar();
    setGameInfoText("Ready to play", 12);
}

void MainWindow::fiveMinutes()
{
    gameTime = 300;

    player1Time = gameTime;
    player2Time = gameTime;

    updateProgressBar();
    setGameInfoText("Ready to play", 12);
}

void MainWindow::switchPlayer1()
{
    currentPlayer = 1;

    updateProgressBar();
    setGameInfoText("Players one's turn", 12);
}

void MainWindow::switchPlayer2()
{
    currentPlayer = 2;

    updateProgressBar();
    setGameInfoText("Player two's turn", 12);
}
