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

#include "mplcore.h"

MPLCore::MPLCore()
{
    _currentHStream = 0;
    _logger = NULL;
}

void MPLCore::init(LoggerDevice *logger)
{
    _logger = logger;

    if (!BASS_Init(-1,44100,0,0,NULL))
        _logger->log(std::string("Cannot initialize device"));
}

void MPLCore::loadFile(std::string filePath)
{
    HSTREAM str;
    char file[MAX_PATH]="";

    _logger->log(filePath);

    filePath.copy(file, MAX_PATH);

    if(str=BASS_StreamCreateFile(FALSE,file,0,0,0))
    {
        _currentHStream = str;
        _logger->log(std::string("File loaded succesfully."));
    }
    else
    {
        _logger->log(std::string("Error loading file."));
    }
}

void MPLCore::play()
{
    BASS_ChannelPlay(_currentHStream, TRUE);
    _logger->log(std::string("Play."));
}
