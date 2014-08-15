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

#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QObject>
#include "mainwindow.h"
#include "qseekslider.h"
#include "playlistmodel.h"
#include "core/core.h"
#include "loggerdevice.h"

class MainApplication : public QObject, public IPlayerObserver
{
    Q_OBJECT
public:
    explicit MainApplication(QObject *parent = 0);
    void init();
    // TODO: rename playbackStopped to reachedEnd
    void update(bool playbackStopped, double position, double duration);

private:
    MainWindow window;
    Core core;
    PlaylistModel playlistModel;
    LoggerDevice logger;

    double duration_;

signals:
    void updatePosition(int timeInSeconds);
    void enableSeekSld(bool enable);
    void resetSeekSlider();
    void statusChanged();

public slots:
    void addFileToPlaylist();
    void play();
    void pause();
    void setVolume(double volumeInPower);
    void stop();
    void seek(int timeInSeconds);
    void openPlaylist();
    void savePlaylist();
};

#endif // MAINAPPLICATION_H
