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
#include <memory>
#include "mpl_abstractstate.h"
#include "mpl_bassdevice.h"
#include "mpl_stateidle.h"
#include "mpl_statepaused.h"
#include "mpl_stateplayback.h"
#include "loggerdevice.h"

class MPLCore
{
public:
    MPLCore();
    ~MPLCore();
    void init(LoggerDevice* logger);
    void loadFile(const char* filePath, int size);
    void play();
    void pause();
    void stop();
    void setVolume();

private:
    MPL_BASSDevice playbackDevice;
    std::unique_ptr<MPL_AbstractState> playerState;
    LoggerDevice* _logger;
    char* _filePath;
};

#endif // MPLCORE_H
