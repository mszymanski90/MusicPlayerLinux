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
#include <sstream>
#include "bass.h"
#include "loggerdevice.h"


#ifndef _WIN32
    // fix this value later
    #define MAX_PATH 100
#endif

class MPLCore
{
private:
    HSTREAM _currentHStream;
    char _file[MAX_PATH];
    LoggerDevice* _logger;
    bool _fileNameLoaded;
    bool _streamLoaded;

    void openStream();

public:
    MPLCore();
    ~MPLCore();
    void init(LoggerDevice* logger);
    void loadFile(const char* filePath, int size);
    void play();
    void pause();
    void stop();
    void setVolume();
};

#endif // MPLCORE_H
