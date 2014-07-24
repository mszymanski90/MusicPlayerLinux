/*
    Copyright (c) 2014 Maciej Szymański, Volodymyr Tsiesielski

    This file is part of Music Player Linux.

    Music Player Linux is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Music Player Linux is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Music Player Linux; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

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

QPushButton *MainWindow::getPlayBt()
{
    return ui->playBt;
}

QPushButton* MainWindow::getPauseBt()
{
    return ui->pauseBt;
}

QPushButton* MainWindow::getStopBt()
{
    return ui->stopBt;
}

QSlider *MainWindow::getVolumeSld()
{
    return ui->volumeSld;
}

QSlider *MainWindow::getSeekSld()
{
    return ui->seekSld;
}
