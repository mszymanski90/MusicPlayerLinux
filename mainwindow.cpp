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
#include <QSettings>

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

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue("MainWindowSize", size());
    emit savePlaylistOnClose(QString("playlist.m3u"));
    event->accept();
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

QVolumeSlider *MainWindow::getVolumeSld()
{
    return ui->volumeSld;
}

QSeekSlider *MainWindow::getSeekSld()
{
    return ui->seekSld;
}

QTableView *MainWindow::getPlaylist()
{
    return ui->playlist;
}

QAction *MainWindow::getAdd_fileAc()
{
    return ui->actionAdd_file;
}

QAction *MainWindow::getAdd_folderAc()
{
    return ui->actionAdd_folder;
}

QAction *MainWindow::getNew_playlistAc()
{
    return ui->actionClear_playlist;
}

QAction *MainWindow::getOpen_playlistAc()
{
    return ui->actionOpen_playlist;
}

QAction *MainWindow::getSave_playlistAc()
{
    return ui->actionSave_playlist;
}
