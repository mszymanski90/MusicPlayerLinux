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

#ifndef LOGGERDEVICE_H
#define LOGGERDEVICE_H

// M:
// Po co include <iostream>?
#include <iostream>
#include <string>
#include <QObject>

class LoggerDevice : public QObject
{
    Q_OBJECT
public:
    explicit LoggerDevice(QObject *parent = 0);

signals:

public slots:
    void log(std::string message);

};

#endif // LOGGERDEVICE_H
