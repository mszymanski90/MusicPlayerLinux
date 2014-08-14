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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QListWidget>
#include <QTableView>
#include <QCloseEvent>
#include "qseekslider.h"
#include "qvolumeslider.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent* event);

    QPushButton* getPlayBt();
    QPushButton* getPauseBt();
    QPushButton* getStopBt();
    QPushButton* getAddBt();
    QPushButton* getSavePlaylistBt();
    QVolumeSlider *getVolumeSld();
    QSeekSlider* getSeekSld();
    QTableView* getPlaylist();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
