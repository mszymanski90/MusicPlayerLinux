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

#ifndef MPLCORE_H
#define MPLCORE_H

#include <string>
#include "bass.h"
#include "loggerdevice.h"

// fix that later
#define MAX_PATH 100

class MPLCore
{
private:
    HSTREAM _currentHStream;
    LoggerDevice* _logger;

public:
    MPLCore();
    void init(LoggerDevice* logger);
    void loadFile(std::string filePath);
    void play();
    void stop();
    void pause();
    void setVolume();
};

#endif // MPLCORE_H
