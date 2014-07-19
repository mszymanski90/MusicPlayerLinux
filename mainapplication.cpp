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
    connect(window.getPlayBt(), SIGNAL(clicked()), this, SLOT(play()));
    connect(window.getPauseBt(), SIGNAL(clicked()), this, SLOT(pause()));
    connect(window.getStopBt(), SIGNAL(clicked()), this, SLOT(stop()));
}

QByteArray MainApplication::getPathFromFileDialog()
{
    QString fileName = QFileDialog::getOpenFileName(&window,
         tr("Open file"), "/home/jana", tr("Image Files (*.mp3 *.m4a *.ogg)"));

    return fileName.toUtf8();
}

void MainApplication::loadFile()
{
    QByteArray qtpath = getPathFromFileDialog();
    core.loadFile(qtpath.constData(), qtpath.size());
}

void MainApplication::play()
{
    core.play();
}

void MainApplication::pause()
{
    core.pause();
}

void MainApplication::stop()
{
    core.stop();
}
