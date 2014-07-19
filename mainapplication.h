/*
    Copyright (c) 2014 Maciej Szyma≈Ñski, Volodymyr Tsiesielski

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

// M:
// Po co include <string> i <QFileDialog>?
#include <string>
#include <QObject>
#include <QFileDialog>
#include "mainwindow.h"
#include "mplcore.h"
#include "loggerdevice.h"

class MainApplication : public QObject
{
    Q_OBJECT
public:
    explicit MainApplication(QObject *parent = 0);
    void init();

private:
    MainWindow window;
    MPLCore core;
    LoggerDevice logger;

    // M:
    // Czemu nie std::string lub QString?
    QByteArray getPathFromFileDialog();

signals:

    // M:
    // te sloty powinny byÊ przeniesione do klasy MPLCore bo w tej chwili mamy ≥aÒcuch:
    // MainApplication::play() -> MPLCore::play() -> MPLAbstractState::play()
    // -> MPLBassDevice::play()
public slots:
    void loadFile();
    void play();
    void pause();
    void stop();
};

#endif // MAINAPPLICATION_H
