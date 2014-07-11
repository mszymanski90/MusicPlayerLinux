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

#include "mainapplication.h"

MainApplication::MainApplication(QObject *parent) :
    QObject(parent)
{

}

void MainApplication::init()
{
    window.show();
    core.init(&logger);

    connect(window.getLoadFileBt(), SIGNAL(clicked()), this, SLOT(loadFile()));
    connect(window.getPlayPauseBt(), SIGNAL(clicked()), this, SLOT(play()));
    connect(window.getStopBt(), SIGNAL(clicked()), this, SLOT(stop()));
}

std::string MainApplication::getPathFromFileDialog()
{
    QString fileName = QFileDialog::getOpenFileName(&window,
         tr("Open file"), "/home/jana", tr("Image Files (*.mp3 *.m4a *.ogg)"));

    //return fileName.toStdString();
    return std::string("./test_mp3.mp3");
}

void MainApplication::loadFile()
{
    core.loadFile(getPathFromFileDialog());
}

void MainApplication::play()
{
    core.play();
}

void MainApplication::stop()
{
    core.stop();
}
