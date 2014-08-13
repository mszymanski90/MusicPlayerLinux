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

#include <string>
#include <QFileDialog>
#include <QTableView>
#include <QHeaderView>
#include <math.h>
#include "mainapplication.h"

MainApplication::MainApplication(QObject *parent) :
    QObject(parent),
    core(*this, logger),
    playlistModel(this)
{
}

void MainApplication::init()
{
    window.show();
    core.init();

    window.getPlaylist()->setModel(&playlistModel);
    window.getPlaylist()->verticalHeader()->setVisible(false);
    window.getPlaylist()->verticalHeader()->setDefaultSectionSize(20);

    window.getPlaylist()->setColumnWidth(0, 50);
    window.getPlaylist()->setColumnWidth(1, 190);
    window.getPlaylist()->setColumnWidth(2, 190);
    window.getPlaylist()->setColumnWidth(3, 60);
    window.getPlaylist()->setColumnWidth(4, 190);
    window.getPlaylist()->setColumnWidth(5, 60);


    // does this do anything ?
    window.getSeekSld()->setTracking(true);
    window.getSeekSld()->setDisabled(true);

    connect(window.getPlayBt(), SIGNAL(clicked()), this, SLOT(play()));
    connect(window.getPauseBt(), SIGNAL(clicked()), this, SLOT(pause()));
    connect(window.getStopBt(), SIGNAL(clicked()), this, SLOT(stop()));
    connect(window.getAddBt(), SIGNAL(clicked()), this, SLOT(addFileToPlaylist()));
    connect(window.getVolumeSld(), SIGNAL(volumeChanged(double)), this, SLOT(setVolume(double)));
    connect(window.getSeekSld(), SIGNAL(valueChangedByUser(int)), this, SLOT(seek(int)));
    connect(this, SIGNAL(updatePosition(int)), window.getSeekSld(), SLOT(updatePosition(int)));
    connect(this, SIGNAL(resetSeekSld()), window.getSeekSld(), SLOT(resetToStoppedPos()));
    connect(this, SIGNAL(enableSeekSld(bool)), window.getSeekSld(), SLOT(setEnabled(bool)));
}

void MainApplication::update(bool playbackStopped, double position, double duration)
{
    emit updatePosition(static_cast<int>(position*100/duration));
    emit enableSeekSld(!playbackStopped);
    duration_ = duration;

    if(playbackStopped)
    {
        emit resetSeekSld();
        playlistModel.next();
        play();
    }
}

void MainApplication::addFileToPlaylist()
{
    QString filePath = QFileDialog::getOpenFileName(&window,
             tr("Open file"), "/home/jana", tr("Sound files (*.mp3 *.ogg)"));

    if(QFile::exists(filePath))
    {
        playlistModel.appendFile(filePath);
    }
}

void MainApplication::play()
{
    if(playlistModel.isFileInQueue())
    {
        QString filePath = playlistModel.getCurrentFile();
        logger.log(std::string("MA load file"));
        QByteArray qtpath = filePath.toLocal8Bit();
        core.loadFile(qtpath.constData());
        core.play();
        playlistModel.displayPlay();
    }
    else
    {
        playlistModel.resetPlaylist();
        logger.log(std::string("Playlist reached end"));
    }
}

void MainApplication::pause()
{
    core.pause();
    playlistModel.displayPause();
}

void MainApplication::setVolume(double volumeInPower)
{
    core.setVolume(volumeInPower);
}

void MainApplication::stop()
{
    core.stop();
    emit resetSeekSld();
    playlistModel.displayStop();
}

void MainApplication::seek(int timeInSeconds)
{
    core.seek(ceil(timeInSeconds*duration_/100));
}
