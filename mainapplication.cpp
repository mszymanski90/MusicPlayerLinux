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
#include <math.h>
#include "mainapplication.h"

MainApplication::MainApplication(QObject *parent) :
    QObject(parent),
    core(*this, logger)
{
}

void MainApplication::init()
{
    window.show();
    core.init();

    // does this do anything ?
    window.getSeekSld()->setTracking(true);
    window.getSeekSld()->setDisabled(true);

    connect(window.getPlayBt(), SIGNAL(clicked()), this, SLOT(play()));
    connect(window.getPauseBt(), SIGNAL(clicked()), this, SLOT(pause()));
    connect(window.getStopBt(), SIGNAL(clicked()), this, SLOT(stop()));
    connect(window.getAddBt(), SIGNAL(clicked()), window.getPlaylist(), SLOT(addSong()));
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
        window.getPlaylist()->setNextSong();
        play();
    }
}

void MainApplication::play()
{
    if(window.getPlaylist()->songInQueue())
    {
        QString filePath = window.getPlaylist()->getSong();
        logger.log(std::string("MA load file"));
        QByteArray qtpath = filePath.toLocal8Bit();
        core.loadFile(qtpath.constData());
        core.play();
    }
    else
    {
        window.getPlaylist()->resetPlaylist();
        logger.log(std::string("Playlist reached end"));
    }
}

void MainApplication::pause()
{
    core.pause();
}

void MainApplication::setVolume(double volumeInPower)
{
    core.setVolume(volumeInPower);
}

void MainApplication::stop()
{
    core.stop();
    emit resetSeekSld();
}

void MainApplication::seek(int timeInSeconds)
{
    core.seek(ceil(timeInSeconds*duration_/100));
}
