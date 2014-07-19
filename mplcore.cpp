/*
    Copyright (c) 2014 Maciej SzymaÅ„ski, Volodymyr Tsiesielski

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

#include "mplcore.h"

MPLCore::MPLCore()
{
    // M:
    // U¿ywaj listy inicjalizacyjnej
    _logger = NULL;
    playerState.reset(new MPL_StateIdle(playbackDevice));
}

MPLCore::~MPLCore()
{
}

void MPLCore::init(LoggerDevice *logger)
{
    _logger = logger;
    playbackDevice.init();
}

void MPLCore::loadFile(const char *filePath, int size)
{
    strcpy(_filePath, filePath);
}

void MPLCore::play()
{
    playerState.reset(playerState->play(_filePath));
}

void MPLCore::pause()
{
    playerState.reset(playerState->pause());
}

void MPLCore::stop()
{
    playerState.reset(playerState->stop());
}


