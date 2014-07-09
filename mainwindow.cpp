#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPushButton* MainWindow::getLoadFileBt()
{
    return ui->loadFileBt;
}

QPushButton* MainWindow::getPlayPauseBt()
{
    return ui->playPauseBt;
}

QPushButton* MainWindow::getStopBt()
{
    return ui->stopBt;
}
