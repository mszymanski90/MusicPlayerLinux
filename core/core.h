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

#ifndef CORE_H
#define CORE_H

#include <string>
#include <sstream>
#include <memory>
#include "iplayerstate.h"
#include "bassplayer.h"
#include "stateidle.h"
#include "statepaused.h"
#include "stateplayback.h"
#include "loggerdevice.h"

class Core
{
public:
    Core(LoggerDevice &logger, std::function<void(double)> updatePositionProc);
    ~Core();
    void init();
    void loadFile(const char* filePath);
    void play();
    void pause();
    void stop();
    void setVolume(float volume);
    void seek(int timeInSeconds);
    void updatePosition(double timeInSeconds);

private:
    BASSPlayer player_;
    std::unique_ptr<IPlayerState> playerState_;
    LoggerDevice &logger_;
    // M:
    // czemu nie std::string albo QString?
    char filePath_[MAX_PATH];
    std::function<void(double)> updatePositionProc_;
};

#endif // CORE_H
